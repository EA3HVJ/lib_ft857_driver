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

#include "../include/ft857_virtual.h"

#include <unistd.h>
#include "../include/ft857_cat.h"

#define SCOPE_WAIT_USEC 100000

bool
FT857_set_virtual_channel(struct CAT_device* dev, struct FT857_virt_chan * channel)
{
	struct CAT_response resp;
	bool ret = true;

	resp = CAT_transaction(dev, CAT_set_frequency_request(
		channel->frequency));
	if (CAT_check_response(&resp) < 1) ret = false;

	resp = CAT_transaction(dev, CAT_set_mode_request(
		channel->mode));
	if (CAT_check_response(&resp) < 1) ret = false;

	resp = CAT_transaction(dev, CAT_set_repeater_shift_request(
		channel->repeater_shift));
	if (CAT_check_response(&resp) < 1) ret = false;

	resp = CAT_transaction(dev, CAT_set_repeater_offset_request(
		channel->repeater_offset));
	if (CAT_check_response(&resp) < 1) ret = false;

	resp = CAT_transaction(dev, CAT_set_ctcss_dcs_mode_request(
		channel->selective_call));
	if (CAT_check_response(&resp) < 1) ret = false;

	switch (channel->selective_call) {
	case CAT_SELEC_CALL_OFF:
		break;
	case CAT_SELEC_CALL_CTCSS:
	case CAT_SELEC_CALL_CTCSS_ENC:
	case CAT_SELEC_CALL_CTCSS_DEC:
		resp = CAT_transaction(dev, CAT_set_ctcss_tone_request(
			channel->code_tone_tx, channel->code_tone_rx));
		if (CAT_check_response(&resp) < 1) ret = false;
		break;
	case CAT_SELEC_CALL_DCS:
	case CAT_SELEC_CALL_DCS_ENC:
	case CAT_SELEC_CALL_DCS_DEC:
		resp = CAT_transaction(dev, CAT_set_dcs_code_request(
			channel->code_tone_tx, channel->code_tone_rx));
		if (CAT_check_response(&resp) < 1) ret = false;
		break;
	}
	return ret;
}

bool FT857_add_frequency_steps(struct CAT_device* dev, struct FT857_virt_settings* sett, int n_steps)
{
	struct CAT_response resp;
	CAT_decahertz frequency, step;
	enum CAT_op_mode mode;

	resp = CAT_transaction(dev, CAT_get_frequency_mode_request());
	int ok = CAT_check_response(&resp);
	if (ok < 1) {
		return ok;
	} else {
		frequency = CAT_decode_frequency_response(&resp);
		mode = CAT_decode_mode_response(&resp);
	}

	switch (mode) {
	case CAT_OP_MODE_AM:
		step = FT857_n06_am_step_to_int(sett->am_step);
		break;
	case CAT_OP_MODE_FM:
	case CAT_OP_MODE_NFM:
	case CAT_OP_MODE_WFM:
	case CAT_OP_MODE_PKT:
		step = FT857_n52_fm_step_to_int(sett->fm_step);
		break;
	case CAT_OP_MODE_LSB:
	case CAT_OP_MODE_USB:
	case CAT_OP_MODE_DIG:
	case CAT_OP_MODE_CW:
	case CAT_OP_MODE_CWN:
	case CAT_OP_MODE_CWR:
		step = FT857_n82_ssb_step_to_int(sett->ssb_step);
		break;
	default:
		return -1;
	}

	frequency = frequency + (step * n_steps);
	return FT857_set_frequency(dev, frequency);
}

struct FT857_virt_scope* FT857_get_virt_scope(struct CAT_device* dev,
	CAT_decahertz center_freq, CAT_decahertz bandwidth, CAT_decahertz samplestep)
{
	struct FT857_virt_scope* scope = malloc(sizeof(struct FT857_virt_scope));
	if (!scope) return NULL;
	scope->n_samples = (bandwidth / samplestep) + 1;
	scope->center_frequency = center_freq;
	scope->bandwidth = bandwidth;
	scope->samplestep = samplestep;
	scope->samples = malloc(sizeof(enum FT857_smeter) * scope->n_samples);
	if (!scope->samples) {
		free(scope);
		return NULL;
	}

	CAT_decahertz f = center_freq - (bandwidth / 2);

	int i;
	for (i = 0; i < scope->n_samples; i++) {
		FT857_set_frequency(dev, f);
		usleep(SCOPE_WAIT_USEC);
		scope->samples[i] = FT857_get_smeter(dev);
		f += samplestep;
	}
	return scope;
}

void FT857_virt_scope_to_callback(struct CAT_device* dev,
	CAT_decahertz center_freq,
	CAT_decahertz bandwidth,
	CAT_decahertz samplestep,
	void (*callback)(CAT_decahertz, enum FT857_smeter, void*),
		void* callback_args)
{
	enum FT857_smeter signal;
	CAT_decahertz f = center_freq - (bandwidth / 2);
	int n_samples = (bandwidth / samplestep) + 1;
	int i;
	for (i = 0; i < n_samples; i++) {
		FT857_set_frequency(dev, f);
		usleep(SCOPE_WAIT_USEC);
		signal = FT857_get_smeter(dev);
		callback(f, signal, callback_args);
		f += samplestep;
	}
	return;
}

void FT857_free_virt_scope(struct FT857_virt_scope* src)
{
	free(src->samples);
	free(src);
	src = NULL;
}