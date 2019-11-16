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

#ifndef FT857_CLONE_H
#define FT857_CLONE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <yaesu_cat.h>
#include <stdbool.h>
#include <stdint.h>
#include "../include/ft857_mchan.h"

#define FT857_CLONE_SIZE 7445

	/*
	 * memsize = 7341
    # block 9 (140 Bytes long) is to be repeted 40 times
    # should be 42 times but this way I can use original 817 functions
    _block_lengths = [2, 82, 252, 196, 252, 196, 212, 55, 140, 140, 140, 38, 176]*/

	/* CLONE MODE *
	struct FT857_clone_img {
		uint8_t img[FT857_CLONE_SIZE];
	};*/

	struct __attribute__((__packed__)) FT857_eeprom_settings
	{
		uint8_t n[69];
	};

	struct __attribute__((__packed__)) FT857_clone_img
	{
		/* Bytes 0 - 1 */
		uint8_t radio_config[2];
		/* Bytes 2 - 70*/
		struct FT857_eeprom_settings settings;
		/* Bytes 71 - 83 */
		uint8_t unknown1[13];
		/* Bytes 84 - 1175 */
		struct FT857_eeprom_channel vfo_a[16];
		struct FT857_eeprom_channel vfo_b[16];
		struct FT857_eeprom_channel home[4];
		struct FT857_eeprom_channel qmb;
		struct FT857_eeprom_channel mtqmb;
		struct FT857_eeprom_channel mtune;
		/* Bytes 1176 - 1992 */
		uint8_t unknown2[17];
		/* Bytes 1193 - 7126 */
		uint8_t user_chan_visible[25];
		uint8_t pms_visible[2];
		uint8_t user_chan_filled[25];
		uint8_t pms_filled[2];
		struct FT857_eeprom_channel user[200];
		struct FT857_eeprom_channel pms[10];
		/* Bytes 7127 - 7154*/
		//uint8_t unknown3[28];
		struct FT857_eeprom_channel unknown3;
		/*Bytes 7155 - 7300 */
		uint8_t arts_idw[10];
		uint8_t beacon_text_1[40];
		uint8_t beacon_text_2[40];
		uint8_t beacon_text_3[40];
		uint32_t xvtr_a;
		uint32_t xvtr_b;
		uint8_t op_filter1_name[4];
		uint8_t op_filter2_name[4];
		uint8_t unknown4[40];
		//struct FT857_eeprom_channel m60[5];
	};

	/* CLONE MODE (Don't work with MIC CAT)*/
	struct FT857_clone_img* FT857_clone_rcv(struct CAT_device* dev,
		void(*progress_callback)(float, void*),
		void* callback_args);

	bool FT857_clone_snd(struct CAT_device* dev,
		struct FT857_clone_img* img,
		void(*progress_callback)(float, void*),
		void* callback_args);


#ifdef __cplusplus
}
#endif

#endif /* FT857_CLONE_H */

