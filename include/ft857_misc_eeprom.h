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

#ifndef FT857_MISC_EEPROM_H
#define FT857_MISC_EEPROM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <yaesu_cat.h>

	struct CAT_eeprom_block* FT857_get_full_eeprom(
		struct CAT_device* dev,
		void (*progress_callback)(float, void*),
		void* callback_args);

	struct CAT_eeprom_block* FT857_get_checksum(struct CAT_device* dev);

	struct CAT_eeprom_block* FT857_get_jumpers(struct CAT_device* dev);
	
	struct CAT_eeprom_block* FT857_get_raw_settings_block(struct CAT_device* dev);


#ifdef __cplusplus
}
#endif

#endif /* FT857_MISC_EEPROM_H */

