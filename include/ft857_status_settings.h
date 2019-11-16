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

#ifndef FT857_STATUS_SETTINGS_H
#define FT857_STATUS_SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <yaesu_cat.h>
#include "ft857_global_status.h"

	/* 
	 * Band enum type
	 * This version is used in the channel struct
	 */
	enum FT857_band_extend {
		FT857_BAND_EXT_ERR = -1,
		FT857_BAND_EXT_HF,
		FT857_BAND_EXT_6M,
		FT857_BAND_EXT_WFMBCB,
		FT857_BAND_EXT_AIR,
		FT857_BAND_EXT_VHF,
		FT857_BAND_EXT_UHF
	};

	enum FT857_lock {
		FT857_ERR = -1,
		FT857_UNLOCKED,
		FT857_LOCKED
	};
	
	const char* FT857_vfo_to_str(enum FT857_vfo mode);
	const char* FT857_band_to_str(enum FT857_band band);
	const char* FT857_band_ext_to_str(enum FT857_band_extend band);
	const char* FT857_subband_to_str(enum FT857_subband sband);
	const char* FT857_lock_to_str(enum FT857_lock status);


	enum FT857_vfo FT857_get_vfo(struct CAT_device* dev);

	/**
	 * @brief Get Band
	 * @return Band enum type (index) (HF, M6, VHF, UHF)
	 */
	enum FT857_band
	FT857_get_band(struct CAT_device * dev);

	/**
	 * @brief Get Subband
	 * @return Subband enum type (VFO channels index) (wavelength)
	 */
	enum FT857_subband FT857_get_subband_a(struct CAT_device* dev);
	enum FT857_subband FT857_get_subband_b(struct CAT_device* dev);
	
	enum FT857_lock FT857_get_lock(struct CAT_device* dev);

	/**
	 * 
	 * @param dev
	 * @param vfo
	 * @param vfo_subindex
	 * @return unit: khz * 100
	 */
	CAT_decahertz
	FT857_get_clarifier_frequency(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex);


#ifdef __cplusplus
}
#endif

#endif /* FT857_STATUS_SETTINGS_H */

