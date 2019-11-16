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

#include "eeprom_codec.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "eeprom_map.h"

/* VFO Channel adresses */
static const uint16_t ADR_VFO_A[] = {
	ADR_VFO_A_160M,
	ADR_VFO_A_80M,
	ADR_VFO_A_60M,
	ADR_VFO_A_40M,
	ADR_VFO_A_30M,
	ADR_VFO_A_20M,
	ADR_VFO_A_17M,
	ADR_VFO_A_15M,
	ADR_VFO_A_12M,
	ADR_VFO_A_10M,
	ADR_VFO_A_6M,
	ADR_VFO_A_WFM_BCB,
	ADR_VFO_A_AIR,
	ADR_VFO_A_2M,
	ADR_VFO_A_70CM
};

static const uint16_t ADR_VFO_B[] = {
	ADR_VFO_B_160M,
	ADR_VFO_B_80M,
	ADR_VFO_A_60M,
	ADR_VFO_B_40M,
	ADR_VFO_B_30M,
	ADR_VFO_B_20M,
	ADR_VFO_B_17M,
	ADR_VFO_A_15M,
	ADR_VFO_B_12M,
	ADR_VFO_B_10M,
	ADR_VFO_B_6M,
	ADR_VFO_B_WFM_BCB,
	ADR_VFO_B_AIR,
	ADR_VFO_B_2M,
	ADR_VFO_B_70CM
};

static const uint16_t ADR_HOME[] = {
	ADR_HOME_HF,
	ADR_HOME_6M,
	ADR_HOME_VHF,
	ADR_HOME_UHF
};

static const uint16_t ADR_PMS[] = {
	ADR_PMS1L,
	ADR_PMS1U,
	ADR_PMS2L,
	ADR_PMS2U,
	ADR_PMS3L,
	ADR_PMS3U,
	ADR_PMS4L,
	ADR_PMS4U,
	ADR_PMS5L,
	ADR_PMS5U
};


static bool* bits_to_array(uint8_t* src, size_t src_len);
static uint8_t decode_eeprom(uint8_t byte, uint8_t bitmask);
static int encode_eeprom(uint8_t* byte, uint8_t bitmask, uint8_t data);
static int mask_offset(int mask);
static uint16_t seek_adress(enum FT857_vfo d, int i, int byte);

static uint8_t get_vfo_flags(struct CAT_device* dev);
static enum FT857_vfo get_vfo_from_flags(uint8_t flags);
static int get_vfo_subindex(struct CAT_device* dev, enum FT857_vfo vfo);

enum FT857_vfo
get_vfo(struct CAT_device* dev)
{
	uint8_t flags = get_value(dev, ADR_VFO_FLAGS, MASK_VFO_FLAGS);
	return get_vfo_from_flags(flags);
}

enum FT857_band
get_band(struct CAT_device* dev)
{
	return(enum FT857_band) get_value(dev, ADR_BAND, MASK_BAND);
}

enum FT857_subband
get_subband_a(struct CAT_device* dev)
{
	return(enum FT857_subband) get_value(dev, ADR_SUBBAND_A, MASK_SUBBAND_A);
}

enum FT857_subband
get_subband_b(struct CAT_device* dev)
{
	return(enum FT857_subband) get_value(dev, ADR_SUBBAND_B, MASK_SUBBAND_B);
}

/* 
 * Get data from a single byte, bitmask and an absolute adress
 * Return uint16 for error code (0xFFFF != 0xFF)
 */
uint16_t
get_value(struct CAT_device* dev, uint16_t adr, uint8_t mask)
{
	uint16_t ret;
	struct CAT_response resp;
	resp = CAT_transaction(dev, CAT_read_eeprom_request(adr));
	if (CAT_check_response(&resp) < 1) {
		return -1; //Error
	}
	ret = decode_eeprom(resp.frame[0], mask);
	return ret;
}

uint32_t
get_value_block(struct CAT_device* dev, uint16_t adr, size_t size)
{
	struct CAT_response resp;
	uint32_t ret = 0;

	if (size == sizeof(uint16_t)) {
		resp = CAT_transaction(dev, CAT_read_eeprom_request(adr));
		if (CAT_check_response(&resp) < 1) {
			return -1; //Error
		}
		ret = (resp.frame[0] << 8) | resp.frame[1];
		return ret;
		
	} else if (size == sizeof(uint32_t)) {
		resp = CAT_transaction(dev, CAT_read_eeprom_request(adr));
		if (CAT_check_response(&resp) < 1) {
			return -1; //Error
		}
		ret = (resp.frame[0] << 24) | (resp.frame[1] << 16);
		
		resp = CAT_transaction(dev, CAT_read_eeprom_request(adr+2));
		if (CAT_check_response(&resp) < 1) {
			return -1; //Error
		}
		ret = ret | (resp.frame[0] << 8) | resp.frame[1];
		return ret;
		
	} else {
		//WRONG SIZE
		return -1;
	}
}

char*
get_string(struct CAT_device* dev, uint16_t adress, size_t size, char (*charset_to_ascii)(uint8_t))
{
	char* string;
	struct CAT_eeprom_block* block = CAT_read_eeprom_block(
		dev, adress, size, NULL, NULL);
	if (block == NULL) {
		return NULL;
	}
	string = realloc(block->data, size + 1);
	if (string == NULL) {
		CAT_free_eeprom_block(block);
		return NULL;
	}
	string[size] = '\0';
	/* NOTE: Free tmp keeping data pointer.
	 * Don't free_eeprom_block() */
	free(block);

	int i;
	if (charset_to_ascii != NULL) {
		for (i = 0; i < size; i++) {
			string[i] = charset_to_ascii(block->data[i]);
		}
	}
	return string;
}

/* 
 * Get data from a single byte, bitmask and an relative adress from a channel struct
 * Return uint16 for error code (0xFFFF != 0xFF)
 */
uint16_t
get_channel_value(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex, int pos, uint8_t mask)
{
	uint16_t ret;
	uint16_t adr;
	struct CAT_response resp;

	if (vfo == FT857_OPT_GET_VFO) {
		vfo = get_vfo(dev);
	}
	if (vfo_subindex == FT857_OPT_GET_SUBINDEX) {
		vfo_subindex = get_vfo_subindex(dev, vfo);
	}

	adr = seek_adress(vfo, vfo_subindex, pos);

	resp = CAT_transaction(dev, CAT_read_eeprom_request(adr));
	if (CAT_check_response(&resp) < 1) {
		return -1; //Error
	}
	ret = decode_eeprom(resp.frame[0], mask);
	return ret;
}

/* Get data from multiple bytes and an relative adress from a channel struct */
struct CAT_eeprom_block*
get_channel_block(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex, int pos, size_t size)
{
	uint16_t adr;
	if (vfo == FT857_OPT_GET_VFO) {
		vfo = get_vfo(dev);
	}
	if (vfo_subindex == FT857_OPT_GET_SUBINDEX) {
		vfo_subindex = get_vfo_subindex(dev, vfo);
	}
	adr = seek_adress(vfo, vfo_subindex, pos);
	return CAT_read_eeprom_block(dev, adr, size, NULL, NULL);
}

/*  */
uint32_t
get_channel_value_block(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex, int pos, size_t size)
{
	uint16_t adr;
	if (vfo == FT857_OPT_GET_VFO) {
		vfo = get_vfo(dev);
	}
	if (vfo_subindex == FT857_OPT_GET_SUBINDEX) {
		vfo_subindex = get_vfo_subindex(dev, vfo);
	}
	adr = seek_adress(vfo, vfo_subindex, pos);
	return get_value_block(dev, adr, size);
}

char* get_channel_string(struct CAT_device* dev,
	enum FT857_vfo vfo, int vfo_subindex, int pos, size_t size,
	char (*charset_to_ascii)(uint8_t))
{
	uint16_t adr;
	if (vfo == FT857_OPT_GET_VFO) {
		vfo = get_vfo(dev);
	}
	if (vfo_subindex == FT857_OPT_GET_SUBINDEX) {
		vfo_subindex = get_vfo_subindex(dev, vfo);
	}
	adr = seek_adress(vfo, vfo_subindex, pos);
	return get_string(dev, adr, size, charset_to_ascii);
}

/********************
 * STATIC FUNCTIONS *
 ********************/

static uint8_t
get_vfo_flags(struct CAT_device* dev)
{
	return get_value(dev, ADR_VFO_FLAGS, MASK_VFO_FLAGS);
}

static enum FT857_vfo get_vfo_from_flags(uint8_t flags)
{
	switch (flags) {
	case FT857_VFO_FLAG_MODE_VFO | FT857_VFO_FLAG_VFO_A: return FT857_VFO_A;
	case FT857_VFO_FLAG_MODE_VFO | FT857_VFO_FLAG_VFO_B: return FT857_VFO_B;
	case FT857_VFO_FLAG_MODE_MEM | FT857_VFO_FLAG_VFO_A: return FT857_VFO_MCHAN;
	case FT857_VFO_FLAG_MODE_MEM | FT857_VFO_FLAG_VFO_B: return FT857_VFO_MCHAN;
	}
	/* Ignore dial mode and vfo a/b */
	flags = flags & ~(FT857_VFO_FLAG_MODE_VFO | FT857_VFO_FLAG_MODE_MEM | FT857_VFO_FLAG_VFO_B);

	switch (flags) {
	case FT857_VFO_FLAG_MTUNE: return FT857_VFO_MTUNE;
	case FT857_VFO_FLAG_HOME: return FT857_VFO_HOME;
	case FT857_VFO_FLAG_PMS: return FT857_VFO_PMS;
	case FT857_VFO_FLAG_QMB: return FT857_VFO_QMB;
	case FT857_VFO_FLAG_QMB | FT857_VFO_FLAG_MTUNE: return FT857_VFO_QMB;
	case FT857_VFO_FLAG_MTQMB: return FT857_VFO_MTQMB;
	case FT857_VFO_FLAG_MTQMB | FT857_VFO_FLAG_QMB: return FT857_VFO_MTQMB;
	case FT857_VFO_FLAG_MTQMB | FT857_VFO_FLAG_QMB | FT857_VFO_FLAG_MTUNE: return FT857_VFO_MTQMB;
	default: FT857_VFO_ERR;
	}
}

static int get_vfo_subindex(struct CAT_device* dev, enum FT857_vfo vfo)
{
	switch (vfo) {
	case FT857_VFO_A: return get_subband_a(dev);
	case FT857_VFO_B: return get_subband_b(dev);
	case FT857_VFO_HOME: return get_band(dev);
		/* Unknown way to determine wich channel struct is active */
	case FT857_VFO_MCHAN: return 0;
	case FT857_VFO_PMS: return 0;
		/* Single channel struct VFO mode */
	case FT857_VFO_MTUNE:
	case FT857_VFO_QMB:
	case FT857_VFO_MTQMB: return 0; //not used
	default: return -1;
	}
}

static bool*
bits_to_array(uint8_t* src, size_t src_len)
{
	int i, j, k;
	uint8_t flag;
	int dest_len = src_len * 8;
	bool* dest = malloc(dest_len * sizeof(bool));
	if (!dest) {
		//fprintf(stderr, "Error allocating memory\n");
		return NULL;
	}
	for (i = 0, j = 0, k = 0, flag = 1; i < dest_len; i++) {
		dest[i] = (src[j] & flag) >> k;
		flag = flag << 1;
		if (k < 7) {
			k++;
		} else {
			k = 0;
			j++;
			flag = 1;
		}
	}
	return dest;
}

/* Decode data from eeprom data byte */
static uint8_t
decode_eeprom(uint8_t byte, uint8_t bitmask)
{
	if (bitmask == 0b11111111) {
		return byte;
	} else {
		int offset = mask_offset(bitmask);
		return(byte & bitmask) >> offset;
	}
}

/* Code data to eeprom data byte */
static int
encode_eeprom(uint8_t* byte, uint8_t bitmask, uint8_t data)
{
	int offset = mask_offset(bitmask);
	if (data > (bitmask >> offset)) {
		return 0; // Value overflow
	} else {
		*byte = (~bitmask & *byte) | (data << offset);
		return 1; // Valid value
	}
}

static int
mask_offset(int mask)
{
	int offset = 0;
	while (mask % 2 == 0) {
		mask = mask >> 1;
		offset++;
	}
	return offset;
}

/* Get absolut adress from a EEPROM channel struct */
static uint16_t
seek_adress(enum FT857_vfo d, int i, int byte)
{
	switch (d) {
	case FT857_VFO_A: //VFO A subband channels
		switch (i) {
		case FT857_SBAND_160M:
		case FT857_SBAND_80M:
		case FT857_SBAND_60M:
		case FT857_SBAND_40M:
		case FT857_SBAND_30M:
		case FT857_SBAND_20M:
		case FT857_SBAND_17M:
		case FT857_SBAND_15M:
		case FT857_SBAND_12M:
		case FT857_SBAND_10M:
		case FT857_SBAND_6M:
		case FT857_SBAND_3M:
		case FT857_SBAND_250CM:
		case FT857_SBAND_2M:
		case FT857_SBAND_70CM:
		case FT857_SBAND_PHANTOM:
			return ADR_VFO_A[i] + byte;
		default: return -1;
		}
	case FT857_VFO_B: //VFO B subband channels
		switch (i) {
		case FT857_SBAND_160M:
		case FT857_SBAND_80M:
		case FT857_SBAND_60M:
		case FT857_SBAND_40M:
		case FT857_SBAND_30M:
		case FT857_SBAND_20M:
		case FT857_SBAND_17M:
		case FT857_SBAND_15M:
		case FT857_SBAND_12M:
		case FT857_SBAND_10M:
		case FT857_SBAND_6M:
		case FT857_SBAND_3M:
		case FT857_SBAND_250CM:
		case FT857_SBAND_2M:
		case FT857_SBAND_70CM:
		case FT857_SBAND_PHANTOM:
			return ADR_VFO_B[i] + byte;
		default: return -1;
		}
	case FT857_VFO_HOME: //Home channels
		switch (i) {
		case FT857_BAND_HF:
		case FT857_BAND_6M:
		case FT857_BAND_VHF:
		case FT857_BAND_UHF:
			return ADR_HOME[i] + byte;
		default: return -1;
		}
	case FT857_VFO_MCHAN: //Memory user channels
		if (i > 0 && i <= 200) {
			return ADR_CHAN(i) + byte;
		} else {
			return -1;
		}
	case FT857_VFO_MTUNE:
		return ADR_MTUNE + byte;
	case FT857_VFO_QMB:
		return ADR_QMB + byte;
	case FT857_VFO_MTQMB:
		return ADR_MTQMB + byte;
	case FT857_VFO_PMS:
		if (i > 0 && i <= 5) {
			return ADR_PMS[i - 1] + byte;
		} else {
			return -1;
		}
	default:
		return -1;
	}
}

/**************************
 * WRITE EEPROM FUNCTIONS *
 **************************/

int
set_value(struct CAT_device* dev, uint16_t adr, uint8_t mask, int value)
{
	struct CAT_response resp_r, resp_w;

	resp_r = CAT_transaction(dev, CAT_read_eeprom_request(adr));
	if (CAT_check_response(&resp_r) < 1) {
		return 0;
	}
	bool ok = encode_eeprom(&resp_r.frame[0], mask, value);
	if (ok == false) {
		return 0;
	}
	resp_w = CAT_transaction(dev, CAT_write_eeprom_request(
		adr, resp_r.frame[0], resp_r.frame[1]));
	return CAT_check_response(&resp_w);
}