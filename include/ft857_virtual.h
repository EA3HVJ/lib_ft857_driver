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

#ifndef FT857_VIRTUAL_H
#define FT857_VIRTUAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <yaesu_cat.h>

#include "../include/ft857_menu_settings.h"

	/**
	 * @brief CAT Virtual channel struct
	 */
	struct FT857_virt_chan {
		CAT_decahertz frequency;
		enum CAT_op_mode mode;
		enum CAT_repeater_shift repeater_shift;
		CAT_decahertz repeater_offset;
		enum CAT_selective_call selective_call;
		int code_tone_tx;
		int code_tone_rx;
		char name[9];
	};

	struct FT857_virt_settings {
		enum FT857_n06_am_step am_step;
		enum FT857_n52_fm_step fm_step;
		enum FT857_n82_ssb_step ssb_step;
	};

	struct FT857_virt_scope {
		CAT_decahertz center_frequency;
		CAT_decahertz bandwidth;
		CAT_decahertz samplestep;
		size_t n_samples;
		enum FT857_smeter* samples;
	};

	bool FT857_set_virtual_channel(struct CAT_device* dev, struct FT857_virt_chan* channel);
	bool FT857_add_frequency_steps(struct CAT_device* dev, struct FT857_virt_settings* sett, int n_steps);

	struct FT857_virt_scope*
	FT857_get_virt_scope(
		struct CAT_device* dev,
		CAT_decahertz center_freq,
		CAT_decahertz bandwidth,
		CAT_decahertz samplestep);

	void
	FT857_virt_scope_to_callback(
		struct CAT_device* dev,
		CAT_decahertz center_freq,
		CAT_decahertz bandwidth,
		CAT_decahertz samplestep,
		void (*callback)(CAT_decahertz, enum FT857_smeter, void*),
		void* callback_args);

	void FT857_free_virt_scope(struct FT857_virt_scope* src);


#ifdef __cplusplus
}
#endif

#endif /* FT857_VIRTUAL_H */

