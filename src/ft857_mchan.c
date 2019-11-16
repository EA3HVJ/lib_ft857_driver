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

#include "../include/ft857_mchan.h"

#include <stdlib.h>
#include <string.h>
#include "eeprom_codec.h"
#include "eeprom_map.h"
#include "endianess.h"
#include "debug.h"

struct CAT_eeprom_block* FT857_get_mchan_status(
	struct CAT_device* dev,
	void (*progress_callback)(float, void*),
	void* callback_args)
{
	return CAT_read_eeprom_block(dev, ADR_CHAN_BITMASK,
		SIZE_CHAN_BITMASK, progress_callback, callback_args);
}

struct FT857_mchan* FT857_get_mchan(
	struct CAT_device* dev,
	int num,
	void (*progress_callback)(float, void*),
	void* callback_args)
{
	if (num > 0 && num <= 200) {
		struct CAT_eeprom_block* tmp;
		struct FT857_mchan* ret;

		ret = malloc(1 * sizeof(struct FT857_mchan));
		if (ret == NULL) return NULL;

		/* NOTE: size + 1 to append tag NULL terminator */
		tmp = CAT_read_eeprom_block(dev, ADR_CHAN(num), SIZE_CHAN_STRUCT,
			progress_callback, callback_args);
		if (tmp != NULL) {
			ret->channel_no = num;
			ret->raw = (struct FT857_eeprom_channel*) tmp->data;
			/* NOTE: Free tmp keeping data pointer.
			 * Don't free_eeprom_block() */
			free(tmp);
			return ret;
		} else {
			return NULL;
		}

	} else {
		return NULL;
	}
}

void
FT857_free_mchan(struct FT857_mchan* src)
{
	if (src != NULL) {
		free(src->raw);
		free(src);
		src = NULL;
	}
}

/* user channel getters */
enum CAT_op_mode FT857_mchan_get_op_mode_rx(struct FT857_mchan* src)
{
	return(enum CAT_op_mode) src->raw->mode_rx;
}

enum CAT_op_mode FT857_mchan_get_op_mode_tx(struct FT857_mchan* src)
{
	return(enum CAT_op_mode) src->raw->mode_tx;
}

enum FT857_band_extend FT857_mchan_get_band_rx(struct FT857_mchan* src)
{
	return(enum FT857_band_extend) src->raw->band_rx;
}

enum FT857_band_extend FT857_mchan_get_band_tx(struct FT857_mchan* src)
{
	return(enum FT857_band_extend) src->raw->band_tx;
}

enum FT857_n83_tone_freq FT857_mchan_get_ctcss_tone_rx(struct FT857_mchan* src)
{
	return(enum FT857_n83_tone_freq) src->raw->ctcss_tone_rx;
}

enum FT857_n83_tone_freq FT857_mchan_get_ctcss_tone_tx(struct FT857_mchan* src)
{
	return(enum FT857_n83_tone_freq) src->raw->ctcss_tone_tx;
}

enum FT857_n33_dcs_code FT857_mchan_get_dcs_code_rx(struct FT857_mchan* src)
{
	return(enum FT857_n33_dcs_code) src->raw->dcs_code_rx;
}

enum FT857_n33_dcs_code FT857_mchan_get_dcs_code_tx(struct FT857_mchan* src)
{
	return(enum FT857_n33_dcs_code) src->raw->dcs_code_tx;
}

CAT_decahertz FT857_mchan_get_frequency_rx(struct FT857_mchan* src)
{
	CAT_decahertz ret = src->raw->frequency_rx_qrg;
#ifdef SWAP_ENDIAN
	ret = __bswap_32(ret);
#endif
	return ret;
}

CAT_decahertz FT857_mchan_get_frequency_tx(struct FT857_mchan* src)
{
	CAT_decahertz ret = src->raw->frequency_tx;
#ifdef SWAP_ENDIAN
	ret = __bswap_32(ret);
#endif
	return ret;
}

enum FT857_n06_am_step FT857_mchan_get_am_step(struct FT857_mchan* src)
{
	return(enum FT857_n06_am_step) src->raw->am_step;
}

enum FT857_n52_fm_step FT857_mchan_get_fm_step(struct FT857_mchan* src)
{
	return(enum FT857_n52_fm_step) src->raw->fm_step;
}

enum FT857_n82_ssb_step FT857_mchan_get_ssb_step(struct FT857_mchan* src)
{
	return(enum FT857_n82_ssb_step) src->raw->ssb_step;
}

enum FT857_MFd_A_rpt FT857_mchan_get_repeater_shift(struct FT857_mchan* src)
{
	return(enum FT857_MFd_A_rpt) src->raw->repeater_shift_mode;
}

char* FT857_mchan_get_tag(struct FT857_mchan* src)
{
	static char* tag[SIZE_N56_MEM_TAG + 1];
	tag[SIZE_N56_MEM_TAG] = '\0';
	memcpy(tag, src->raw->tag, SIZE_N56_MEM_TAG);
	return *tag;
}

/* Check correct size of struct at compiling-time */
static void never_executed(void)
{
	BUILD_BUG_ON(sizeof(struct FT857_eeprom_channel) != SIZE_CHAN_STRUCT);
}