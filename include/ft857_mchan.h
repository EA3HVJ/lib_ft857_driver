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

#ifndef FT857_MCHAN_H
#define FT857_MCHAN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <yaesu_cat.h>
#include "ft857_status_settings.h"
#include "ft857_menu_settings.h"
#include "ft857_mf_settings.h"

	/* Channel struct memory allocation */
	struct __attribute__((__packed__)) FT857_eeprom_channel
	{
		/* Byte 0 */
		uint8_t mode_rx : 3; /**< cast it to enum op_mode */
		uint8_t unknown1 : 2;
		bool antenna : 1; /**< 0 = V/UHF, 1 = HF/6M o potser 1 < 6M */
		bool tag_not_valid : 1;
		bool show_tag : 1;
		/* Byte 1 */
		uint8_t band_rx : 3; /**< cast it to enum band */
		bool fm_narrow : 1;
		bool cw_narrow : 1;
		bool shift : 1; /**< 0 = simplex, 1 = Repeater shift (see shiftMode) */
		uint8_t repeater_shift_mode : 2; /**< cast it to enum shift_repeater 0 = split frequency (bytes 16-19), 1 = Negative, 2 = Positive */
		/* Byte 2 */
		uint8_t unknown2 : 3;
		bool nar : 1; /**< Only for 29Mhz */
		bool att : 1;
		bool ipo : 1;
		bool unknown3 : 1;
		bool skip : 1;
		/* Byte 3 */
		uint8_t fm_step : 3; /**< cast it to enum fm_step */
		uint8_t am_step : 3; /**< cast it to enum am_step */
		uint8_t ssb_step : 2; /**< cast it to enum ssb_step */
		/* Byte 4 */
		uint8_t ctcss_dcs_dec : 2; /**< 0 = 0ff, 1 = CTCSS, 2 = DCS (MFe-A) */
		uint8_t ctcss_dcs_enc : 2; /**< 0 = 0ff, 1 = CTCSS, 2 = DCS (MFe-A) */
		bool split_tone : 1; /**< menu 79 */
		uint8_t unknown4 : 3;
		/* Byte 5 */
		uint8_t band_tx : 3; /**< cast it to enum band */
		uint8_t mode_tx : 3;
		uint8_t unknown6 : 2;
		/* Byte 6 */
		uint8_t ctcss_tone_tx : 8; /**< cast it to enum ctcss_tone */
		/* Byte 7 */
		uint8_t ctcss_tone_rx : 8; /**< cast it to enum ctcss_tone */
		/* Byte 8 */
		uint8_t dcs_code_tx : 8; /**< cast it to enum dcs_code */
		/* Byte 9 */
		uint8_t dcs_code_rx : 8; /**< cast it to enum dcs_code */
		/* Bytes 10-11 */
		uint16_t clarifier_rit : 16; /**< RIT frequency big-endian stored */
		/* Bytes 12-15 */
		uint32_t frequency_rx_qrg : 32; /**< QRG / Split mode (Rx) big-endian stored */
		/* Bytes 16-19 */
		uint32_t frequency_tx : 32; /**< Repeater shift / Split mode (Tx) big-endian stored */
		/* Bytes 20-27 */
		uint8_t tag[8];
	};

	struct FT857_mchan {
		uint8_t channel_no;
		struct FT857_eeprom_channel* raw;
	};

	struct FT857_mchan* FT857_get_mchan(
		struct CAT_device* dev,
		int num,
		void (*progress_callback)(float, void*),
		void* callback_args);

	void
	FT857_free_mchan(struct FT857_mchan* src);

	struct CAT_eeprom_block* FT857_get_mchan_status(
		struct CAT_device* dev,
		void (*progress_callback)(float, void*),
		void* callback_args);

	enum CAT_op_mode FT857_mchan_get_op_mode_rx(struct FT857_mchan* src);
	enum CAT_op_mode FT857_mchan_get_op_mode_tx(struct FT857_mchan* src);
	enum FT857_band_extend FT857_mchan_get_band_rx(struct FT857_mchan* src);
	enum FT857_band_extend FT857_mchan_get_band_tx(struct FT857_mchan* src);
	enum FT857_n83_tone_freq FT857_mchan_get_ctcss_tone_rx(struct FT857_mchan* src);
	enum FT857_n83_tone_freq FT857_mchan_get_ctcss_tone_tx(struct FT857_mchan* src);
	enum FT857_n33_dcs_code FT857_mchan_get_dcs_code_rx(struct FT857_mchan* src);
	enum FT857_n33_dcs_code FT857_mchan_get_dcs_code_tx(struct FT857_mchan* src);
	CAT_decahertz FT857_mchan_get_frequency_rx(struct FT857_mchan* src);
	CAT_decahertz FT857_mchan_get_frequency_tx(struct FT857_mchan* src);
	enum FT857_n06_am_step FT857_mchan_get_am_step(struct FT857_mchan* src);
	enum FT857_n52_fm_step FT857_mchan_get_fm_step(struct FT857_mchan* src);
	enum FT857_n82_ssb_step FT857_mchan_get_ssb_step(struct FT857_mchan* src);
	enum FT857_MFd_A_rpt FT857_mchan_get_repeater_shift(struct FT857_mchan* src);
	char* FT857_mchan_get_tag(struct FT857_mchan* src);


#ifdef __cplusplus
}
#endif

#endif /* FT857_MEM_CHAN_H */

