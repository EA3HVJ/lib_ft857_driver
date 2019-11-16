/*
 * Copyright (C) 2019 Joan Planella Costa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * CLONE MODE:
 * 
 * Clone mode uses always the default CAT/LIN/TUN port, never MIC CAT
 * Speed i always at 9600 bps
 * Don't matter rig settings, will not affect clone mode
 * 
 * There are 52 frames
 * Frame [1 Byte frame num][N bytes DATA][1 Byte checksum]
 * 
 */
#include "../include/ft857_clone.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "debug.h"

#define CLONE_RATE      9600
#define CLONE_TIMEOUT   5000 //milliseconds
#define CLONE_SIZE      7445
#define CLONE_DATA_SIZE 7341
#define CLONE_N_FRAMES  52
#define CLONE_ACK       0x06

static uint8_t clone_checksum(uint8_t *packet, size_t size);

/* Sizes not including Header byte and checksum byte */
static const size_t CLONE_FRAME_SIZE[CLONE_N_FRAMES] = {
	2, 82, 252, 196, 252, 196, 212, 55, 140, 140,
	140, 140, 140, 140, 140, 140, 140, 140, 140, 140,
	140, 140, 140, 140, 140, 140, 140, 140, 140, 140,
	140, 140, 140, 140, 140, 140, 140, 140, 140, 140,
	140, 140, 140, 140, 140, 140, 140, 140, 140, 140,
	38, 176
};

struct FT857_clone_img* FT857_clone_rcv(struct CAT_device* dev,
	void(*progress_callback)(float, void*),
	void* callback_args)
{
	DEBUG_PLACE;

	uint8_t ack = CLONE_ACK;
	uint8_t frame_i, r_frame_i;
	uint8_t checksum, r_checksum;
	bool error = false;

	uint8_t* cloned = malloc(CLONE_DATA_SIZE);
	if (!cloned) {
		g_cat_errno = CAT_ERR_MALLOC;
		DEBUG_PRINT("%s", CAT_errno_to_str(g_cat_errno));
		return NULL;
	}
	uint8_t* pkt = cloned;

	/* Set TTY: Clone tio settings */
	int old_speed = CAT_change_device_rate(dev, CLONE_RATE);
	int old_timeout = CAT_change_transaction_timeout(dev, CLONE_TIMEOUT);

	for (frame_i = 0; frame_i < CLONE_N_FRAMES; frame_i++) {
		if (CAT_read_bytes(dev, &r_frame_i, 1) != 1) {
			error = true;
			break;
		}
		if (CAT_read_bytes(dev, pkt, CLONE_FRAME_SIZE[frame_i])
			!= CLONE_FRAME_SIZE[frame_i]) {
			error = true;
			break;
		}
		if (CAT_read_bytes(dev, &r_checksum, 1) != 1) {
			error = true;
			break;
		}
		/*
		 * 1 Byte: packet number +
		 * N Bytes: EEPROM data +
		 * 1 Byte EEPROM data checksum 8 modulo 256
		 */
		if (frame_i != r_frame_i) {
			error = true;
			DEBUG_PRINT("Error: frame lost");
			break;
		}
		checksum = clone_checksum(pkt, CLONE_FRAME_SIZE[frame_i]);
		if (checksum != r_checksum) {
			error = true;
			DEBUG_PRINT("Wrong checksum");
			break;
		}

		bool ok = CAT_write_bytes(dev, &ack, 1);
		if (ok == false) {
			error = true;
			break;
		}
		pkt += CLONE_FRAME_SIZE[frame_i];
		if (progress_callback != NULL) {
			progress_callback((float) frame_i /
				CLONE_N_FRAMES, callback_args);
		}

	}
	sleep(1);
	/* Reset TTY: Set CAT tio settings */
	CAT_change_device_rate(dev, old_speed);
	CAT_change_transaction_timeout(dev, old_timeout);

	if (error == false) {
		return(struct FT857_clone_img*) cloned;
	} else {
		free(cloned);
		return NULL;
	}
}

bool FT857_clone_snd(struct CAT_device* dev,
	struct FT857_clone_img* img,
	void(*progress_callback)(float, void*),
	void* callback_args)
{
	bool error = false;
	uint8_t frame_i, checksum, ack;
	uint8_t* frame = (uint8_t*) img;

	/* Set TTY: Clone tio settings */
	int old_speed = CAT_change_device_rate(dev, CLONE_RATE);
	int old_timeout = CAT_change_transaction_timeout(dev, CLONE_TIMEOUT);

	for (frame_i = 0; frame_i < CLONE_N_FRAMES; frame_i++) {
		checksum = clone_checksum(frame, CLONE_FRAME_SIZE[frame_i]);

		/* Frame header */
		if (CAT_write_bytes(dev, &frame_i, 1) == false) {
			error = true;
			break;
		}
		/* Frame data */
		if (CAT_write_bytes(dev, frame, CLONE_FRAME_SIZE[frame_i]) == false) {
			error = true;
			break;
		}
		/* Frame checksum */
		if (CAT_write_bytes(dev, &checksum, 1) == false) {
			error = true;
			break;
		}
		/* Get ACK */
		if (CAT_read_bytes(dev, &ack, 1) < 1 || ack != CLONE_ACK) {
			error = true;
			break;
		}
		/* Progress callback */
		if (progress_callback != NULL) {
			progress_callback((float) frame_i /
				CLONE_N_FRAMES, callback_args);
		}

		frame += CLONE_FRAME_SIZE[frame_i];
	}
	sleep(1);
	/* Reset TTY: Set CAT tio settings */
	CAT_change_device_rate(dev, old_speed);
	CAT_change_transaction_timeout(dev, old_timeout);

	return !error;
}

static uint8_t clone_checksum(uint8_t *packet, size_t size)
{
	uint8_t checksum = 0x00;
	int i;
	for (i = 0; i < size; i++) {
		checksum = checksum + packet[i];
	}
	return checksum % 256;
}

/* Check correct size of struct at compiling-time */
static void never_executed(void)
{
	BUILD_BUG_ON(sizeof(struct FT857_eeprom_settings) != 69);
	BUILD_BUG_ON(sizeof(struct FT857_clone_img) != CLONE_SIZE - (CLONE_N_FRAMES * 2));
}