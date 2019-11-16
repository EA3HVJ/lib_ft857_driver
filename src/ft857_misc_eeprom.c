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

#include "../include/ft857_misc_eeprom.h"

#include "eeprom_codec.h"
#include "eeprom_map.h"

struct CAT_eeprom_block* FT857_get_full_eeprom(
	struct CAT_device* dev,
	void (*progress_callback)(float, void*),
	void* callback_args)
{
	return CAT_read_eeprom_block(dev, 0, EEPROM_SIZE,
		progress_callback, callback_args);
}

struct CAT_eeprom_block* FT857_get_checksum(struct CAT_device* dev)
{
	return CAT_read_eeprom_block(dev, ADR_EEPROM_CHECKSUM, SIZE_EEPROM_CHECKSUM,
		NULL, NULL);
}

struct CAT_eeprom_block* FT857_get_jumpers(struct CAT_device* dev)
{
	return CAT_read_eeprom_block(dev, ADR_JUMPERS, SIZE_JUMPERS,
		NULL, NULL);
}

struct CAT_eeprom_block* FT857_get_raw_settings_block(struct CAT_device* dev) {
	return CAT_read_eeprom_block(dev, ADR_SETTINGS, SIZE_SETTINGS,
		NULL, NULL);
}