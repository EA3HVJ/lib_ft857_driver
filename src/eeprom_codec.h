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

#ifndef EEPROM_CODEC_H
#define EEPROM_CODEC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <yaesu_cat.h>
#include "../include/ft857_global_status.h"

	enum FT857_vfo get_vfo(struct CAT_device* dev);
	enum FT857_band get_band(struct CAT_device* dev);
	enum FT857_subband get_subband_a(struct CAT_device* dev);
	enum FT857_subband get_subband_b(struct CAT_device* dev);

	uint16_t get_value(struct CAT_device* dev, uint16_t adr, uint8_t mask);
	uint32_t get_value_block(struct CAT_device* dev, uint16_t adr, size_t size);
	char* get_string(struct CAT_device* dev, uint16_t adress, size_t size, char (*charset_to_ascii)(uint8_t));
	int set_value(struct CAT_device* dev, uint16_t adr, uint8_t mask, int value);
	uint16_t get_channel_value(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex, int pos, uint8_t mask);
	struct CAT_eeprom_block* get_channel_block(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex, int pos, size_t size);
	uint32_t get_channel_value_block(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex, int pos, size_t size);
	char* get_channel_string(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex, int pos, size_t size, char (*charset_to_ascii)(uint8_t));


#ifdef __cplusplus
}
#endif

#endif /* EEPROM_CODEC_H */

