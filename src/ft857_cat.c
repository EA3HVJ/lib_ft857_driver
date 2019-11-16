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

#include "../include/ft857_cat.h"
#include "strings/strings.h"

const char* FT857_smeter_to_str(enum FT857_smeter src)
{
	switch (src) {
	case FT857_SMETER_S0: return STR_SMETER_0;
	case FT857_SMETER_S1: return STR_SMETER_1;
	case FT857_SMETER_S2: return STR_SMETER_2;
	case FT857_SMETER_S3: return STR_SMETER_3;
	case FT857_SMETER_S4: return STR_SMETER_4;
	case FT857_SMETER_S5: return STR_SMETER_5;
	case FT857_SMETER_S6: return STR_SMETER_6;
	case FT857_SMETER_S7: return STR_SMETER_7;
	case FT857_SMETER_S8: return STR_SMETER_8;
	case FT857_SMETER_S9: return STR_SMETER_9;
	case FT857_SMETER_S9_10_DB: return STR_SMETER_A;
	case FT857_SMETER_S9_20_DB: return STR_SMETER_B;
	case FT857_SMETER_S9_30_DB: return STR_SMETER_C;
	case FT857_SMETER_S9_40_DB: return STR_SMETER_D;
	case FT857_SMETER_S9_50_DB: return STR_SMETER_E;
	case FT857_SMETER_S9_60_DB: return STR_SMETER_F;
	default: return NULL;
	}
}

int FT857_set_clar_frequency(struct CAT_device* dev, CAT_decahertz frequency)
{
	struct CAT_request* req = CAT_set_clarifier_frequency_request(frequency);
	if (!req) return -1;
	struct CAT_response resp = CAT_transaction(dev, req);
	return CAT_check_response(&resp);
}

int FT857_set_clar(struct CAT_device* dev, bool on_off)
{
	struct CAT_response resp = CAT_transaction(dev,
		CAT_switch_clarifier_request(on_off));
	return CAT_check_response(&resp);
}

int FT857_set_selective_call(struct CAT_device* dev, enum CAT_selective_call mode)
{
	struct CAT_request* req = CAT_set_ctcss_dcs_mode_request(mode);
	if (!req) return -1;
	struct CAT_response resp = CAT_transaction(dev, req);
	return CAT_check_response(&resp);
}

int FT857_set_ctcss_tone(struct CAT_device* dev, CAT_decihertz tx, CAT_decihertz rx)
{
	struct CAT_request* req = CAT_set_ctcss_tone_request(tx, rx);
	if (!req) return -1;
	struct CAT_response resp = CAT_transaction(dev, req);
	return CAT_check_response(&resp);
}

int FT857_set_dcs_code(struct CAT_device* dev, int tx, int rx)
{
	struct CAT_request* req = CAT_set_dcs_code_request(tx, rx);
	if (!req) return -1;
	struct CAT_response resp = CAT_transaction(dev, req);
	return CAT_check_response(&resp);
}

int FT857_set_lock(struct CAT_device* dev, bool on_off)
{
	struct CAT_response resp = CAT_transaction(dev,
		CAT_switch_lock_request(on_off));
	return CAT_check_response(&resp);
}

int FT857_set_ptt(struct CAT_device* dev, bool on_off)
{
	struct CAT_response resp = CAT_transaction(dev,
		CAT_switch_ptt_request(on_off));
	return CAT_check_response(&resp);
}

int FT857_set_repeater(struct CAT_device* dev, enum CAT_repeater_shift shift, CAT_hertz offset)
{
	struct CAT_response resp;
	struct CAT_request* req = CAT_set_repeater_shift_request(shift);

	if (!req) return -1;
	resp = CAT_transaction(dev, req);
	int ok = CAT_check_response(&resp);
	if (ok < 1) return ok;

	req = CAT_set_repeater_offset_request(offset);
	if (!req) return -1;
	resp = CAT_transaction(dev, req);
	return CAT_check_response(&resp);
}

int FT857_set_repeater_shift(struct CAT_device* dev, enum CAT_repeater_shift shift)
{
	struct CAT_response resp;
	struct CAT_request* req = CAT_set_repeater_shift_request(shift);
	if (!req) return -1;
	resp = CAT_transaction(dev, req);
	return CAT_check_response(&resp);
}

int FT857_set_repeater_offset(struct CAT_device* dev, CAT_hertz offset)
{
	struct CAT_response resp;
	struct CAT_request* req = CAT_set_repeater_offset_request(offset);
	if (!req) return -1;
	resp = CAT_transaction(dev, req);
	return CAT_check_response(&resp);
}

int FT857_set_frequency(struct CAT_device* dev, CAT_decahertz frequency)
{
	struct CAT_request* req = CAT_set_frequency_request(frequency);
	if (!req) return -1;
	struct CAT_response resp = CAT_transaction(dev, req);
	return CAT_check_response(&resp);
}

int FT857_set_mode(struct CAT_device* dev, enum CAT_op_mode mode)
{
	struct CAT_request* req = CAT_set_mode_request(mode);
	if (!req) return -1;
	struct CAT_response resp = CAT_transaction(dev, req);
	return CAT_check_response(&resp);
}

int FT857_set_split(struct CAT_device* dev, bool on_off)
{
	struct CAT_response resp = CAT_transaction(dev,
		CAT_switch_split_request(on_off));
	return CAT_check_response(&resp);
}

int FT857_toogle_vfo(struct CAT_device* dev)
{
	struct CAT_response resp = CAT_transaction(dev,
		CAT_toggle_vfo_request());
	return CAT_check_response(&resp);
}

CAT_decahertz FT857_get_frequency(struct CAT_device* dev)
{
	struct CAT_response resp = CAT_transaction(dev,
		CAT_get_frequency_mode_request());
	int ok = CAT_check_response(&resp);
	if (ok < 1) {
		return ok;
	} else {
		return CAT_decode_frequency_response(&resp);
	}
}

enum CAT_op_mode FT857_get_mode(struct CAT_device* dev)
{
	struct CAT_response resp = CAT_transaction(dev,
		CAT_get_frequency_mode_request());
	int ok = CAT_check_response(&resp);
	if (ok < 1) {
		return CAT_OP_MODE_ERR;
	} else {
		return CAT_decode_mode_response(&resp);
	}
}

struct CAT_status_rx* FT857_get_status_rx(struct CAT_device* dev, struct CAT_status_rx* status)
{

}

enum FT857_smeter FT857_get_smeter(struct CAT_device* dev)
{
	struct CAT_status_rx srx;
	struct CAT_response resp = CAT_transaction(dev,
		CAT_get_status_rx_request());
	int ok = CAT_check_response(&resp);
	if (ok < 1) {
		return FT857_SMETER_ERR;
	} else {
		srx = CAT_decode_status_rx_response(&resp);
		return (enum FT857_smeter) srx.smeter;
	}
}

struct CAT_status_tx* FT857_get_status_tx(struct CAT_device* dev)
{

}

struct FT857_tx_meters FT857_get_tx_meters(struct CAT_device* dev)
{
	struct FT857_tx_meters ret;
	struct CAT_response resp = CAT_transaction(dev,
		CAT_get_tx_meters_request());
	int ok = CAT_check_response(&resp);
	if (ok < 1) {
		ret.pwr = FT857_PWR_ERR;
		ret.alc = FT857_ALC_ERR;
		ret.mod = FT857_MOD_ERR;
		ret.vswr = FT857_VSWR_ERR;
	} else {
		struct CAT_tx_meters txm = CAT_decode_tx_meters_response(&resp);
		ret.pwr = txm.PWR;
		ret.alc = txm.ALC;
		ret.mod = txm.MOD;
		ret.vswr = txm.VSWR;
	}
	return ret;
}

struct CAT_eeprom_byte* FT857_read_eeprom(struct CAT_device* dev, uint16_t adress, struct CAT_eeprom_byte* dest)
{
	struct CAT_eeprom_byte byte;
	struct CAT_response resp = CAT_transaction(
		dev, CAT_read_eeprom_request(adress));
	if (CAT_check_response(&resp) > 1) return NULL;

	dest->adress = adress;
	dest->data = resp.frame[0];
	dest->data_next = resp.frame[1];
	return dest;
}

int FT857_write_eeprom(struct CAT_device* dev, struct CAT_eeprom_byte* byte)
{
	struct CAT_response resp = CAT_transaction(dev, CAT_write_eeprom_request(
		byte->adress, byte->data, byte->data_next));
	return CAT_check_response(&resp);
}

int FT857_factory_reset(struct CAT_device* dev)
{
	struct CAT_response resp = CAT_transaction(dev,
		CAT_factory_reset_request());
	return CAT_check_response(&resp);
}

/*************************/

enum FT857_trx_status FT857_get_trx_status(struct CAT_device* dev)
{
	struct CAT_response resp;
	struct CAT_status_tx stx;
	struct CAT_status_rx srx;

	resp = CAT_transaction(dev, CAT_get_status_tx_request());
	if (CAT_check_response(&resp) < 1) return FT857_TRX_ERR;

	stx = CAT_decode_status_tx_response(&resp);
	if (stx.ptt_is_off == true) return FT857_TX;

	resp = CAT_transaction(dev, CAT_get_status_rx_request());
	if (CAT_check_response(&resp) < 1) return FT857_TRX_ERR;

	srx = CAT_decode_status_rx_response(&resp);
	if (srx.squelch == false) {
		return FT857_RX;
	} else return FT857_SQL;
}