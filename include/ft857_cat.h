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

#ifndef FT857_CAT_H
#define FT857_CAT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <yaesu_cat.h>
#include "../include/ft857_global_status.h"
	
	struct FT857_status_rx {
		
	};
	
	struct FT857_tx_meters {
		enum FT857_pwr_meter pwr;
		enum FT857_alc_meter alc;
		enum FT857_mod_meter mod;
		enum FT857_vswr_meter vswr;
	};
	
	const char* FT857_smeter_to_str(enum FT857_smeter src);

	int FT857_set_clar_frequency(struct CAT_device* dev, CAT_decahertz frequency);
	int FT857_set_clar(struct CAT_device* dev, bool on_off);
	int FT857_set_selective_call(struct CAT_device* dev, enum CAT_selective_call mode);
	int FT857_set_ctcss_tone(struct CAT_device* dev, CAT_decihertz tx, CAT_decihertz rx);
	int FT857_set_dcs_code(struct CAT_device* dev, int tx, int rx);
	int FT857_set_lock(struct CAT_device* dev, bool on_off);
	int FT857_set_ptt(struct CAT_device* dev, bool on_off);
	int FT857_set_repeater(struct CAT_device* dev, enum CAT_repeater_shift shift, CAT_hertz offset);
	int FT857_set_repeater_shift(struct CAT_device* dev, enum CAT_repeater_shift shift);
	int FT857_set_repeater_offset(struct CAT_device* dev, CAT_hertz offset);
	int FT857_set_frequency(struct CAT_device* dev, CAT_decahertz frequency);
	int FT857_set_mode(struct CAT_device* dev, enum CAT_op_mode mode);
	int FT857_set_split(struct CAT_device* dev, bool on_off);

	int FT857_toogle_vfo(struct CAT_device* dev);

	CAT_decahertz FT857_get_frequency(struct CAT_device* dev);
	enum CAT_op_mode FT857_get_mode(struct CAT_device* dev);

	struct CAT_status_rx* FT857_get_status_rx(struct CAT_device* dev, struct CAT_status_rx* status);
	enum FT857_smeter FT857_get_smeter(struct CAT_device* dev);
	struct CAT_status_tx* FT857_get_status_tx(struct CAT_device* dev);
	struct FT857_tx_meters FT857_get_tx_meters(struct CAT_device* dev);

	struct CAT_eeprom_byte* FT857_read_eeprom(struct CAT_device* dev, uint16_t adress, struct CAT_eeprom_byte* dest);
	int FT857_write_eeprom(struct CAT_device* dev, struct CAT_eeprom_byte* byte);
	int FT857_factory_reset(struct CAT_device* dev);
	//get radio conf
	enum FT857_trx_status FT857_get_trx_status(struct CAT_device* dev);

#ifdef __cplusplus
}
#endif

#endif /* FT857_CAT_H */