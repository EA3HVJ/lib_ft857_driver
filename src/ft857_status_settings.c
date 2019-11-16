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

#include "../include/ft857_status_settings.h"

#include <stdlib.h>
#include <stdbool.h>
#include "eeprom_codec.h"
#include "eeprom_map.h"
#include "strings/strings.h"

const char* FT857_lock_to_str(enum FT857_lock status)
{
	switch (status) {
	case FT857_UNLOCKED: return STR_UNLOCKED;
	case FT857_LOCKED: return STR_LOCKED;
	default: return NULL;
	}
}

const char* FT857_vfo_to_str(enum FT857_vfo mode)
{
	switch (mode) {
	case FT857_VFO_A: return STR_VFO_A;
	case FT857_VFO_B: return STR_VFO_B;
	case FT857_VFO_MTQMB: return STR_VFO_MTQMB;
	case FT857_VFO_QMB: return STR_VFO_QMB;
	case FT857_VFO_PMS: return STR_VFO_PMS;
	case FT857_VFO_HOME: return STR_VFO_HOME;
	case FT857_VFO_MTUNE: return STR_VFO_MTUNE;
	case FT857_VFO_MCHAN: return STR_VFO_MCHAN;
	default: return NULL;
	}
}

const char* FT857_band_to_str(enum FT857_band band)
{
	switch (band) {
	case FT857_BAND_HF: return STR_BAND_HF;
	case FT857_BAND_6M: return STR_BAND_6M;
	case FT857_BAND_VHF: return STR_BAND_VHF;
	case FT857_BAND_UHF: return STR_BAND_UHF;
	default: return NULL;
	}
}

const char* FT857_band_ext_to_str(enum FT857_band_extend band)
{
	switch (band) {
	case FT857_BAND_EXT_HF: return STR_BAND_EXT_HF;
	case FT857_BAND_EXT_6M: return STR_BAND_EXT_6M;
	case FT857_BAND_EXT_WFMBCB: return STR_BAND_EXT_WFMBCB;
	case FT857_BAND_EXT_AIR: return STR_BAND_EXT_AIR;
	case FT857_BAND_EXT_VHF: return STR_BAND_EXT_VHF;
	case FT857_BAND_EXT_UHF: return STR_BAND_EXT_UHF;
	default: return NULL;
	}
}

const char* FT857_subband_to_str(enum FT857_subband sband)
{
	switch (sband) {
	case FT857_SBAND_160M: return STR_SUBBAND_160M;
	case FT857_SBAND_80M: return STR_SUBBAND_80M;
	case FT857_SBAND_60M: return STR_SUBBAND_60M;
	case FT857_SBAND_40M: return STR_SUBBAND_40M;
	case FT857_SBAND_30M: return STR_SUBBAND_30M;
	case FT857_SBAND_20M: return STR_SUBBAND_20M;
	case FT857_SBAND_17M: return STR_SUBBAND_17M;
	case FT857_SBAND_15M: return STR_SUBBAND_15M;
	case FT857_SBAND_12M: return STR_SUBBAND_12M;
	case FT857_SBAND_10M: return STR_SUBBAND_10M;
	case FT857_SBAND_6M: return STR_SUBBAND_6M;
	case FT857_SBAND_3M: return STR_SUBBAND_3M;
	case FT857_SBAND_250CM: return STR_SUBBAND_250CM;
	case FT857_SBAND_2M: return STR_SUBBAND_2M;
	case FT857_SBAND_70CM: return STR_SUBBAND_70CM;
	case FT857_SBAND_PHANTOM: return STR_SUBBAND_PHANTOM;
	default: return NULL;
	}
}

enum FT857_vfo
FT857_get_vfo(struct CAT_device* dev)
{
	return get_vfo(dev);
}

enum FT857_band
FT857_get_band(struct CAT_device* dev)
{
	return get_band(dev);
}

enum FT857_subband
FT857_get_subband_a(struct CAT_device* dev)
{
	return get_subband_a(dev);
}

enum FT857_subband
FT857_get_subband_b(struct CAT_device* dev)
{
	return get_subband_b(dev);
}

enum FT857_lock FT857_get_lock(struct CAT_device* dev)
{
	return(enum FT857_lock) get_value(dev, ADR_LOCK, MASK_LOCK);
}

CAT_decahertz
FT857_get_clarifier_frequency(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex)
{
	return get_channel_value_block(dev, vfo, vfo_subindex,
		POS_CLARIFIER_FREQ, SIZE_CLARIFIER_FREQ);
}