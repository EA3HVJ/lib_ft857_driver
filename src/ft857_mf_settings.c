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

#include "../include/ft857_mf_settings.h"

#include <stdlib.h>
#include "eeprom_codec.h"
#include "eeprom_map.h"
#include "strings/strings.h"

static bool get_split_tone_from_selec_call(enum FT857_MFe_selective_call status);

/****************************
 * ENUM TO STRING FUNCTIONS *
 ****************************/

/* Enum FT857_MF_settings To String */
const char* FT857_MF_settings_to_str(enum FT857_MF_settings src)
{
	switch (src) {
	case FT857_MFa_A_SWITCH_VFO: return STR_MFa_A_SWITCH_VFO;
	case FT857_MFa_B_COPY_VFO: return STR_MFa_B_COPY_VFO;
	case FT857_MFa_C_SPL: return STR_MFa_C_SPL;
	case FT857_MFb_A_MW: return STR_MFb_A_MW;
	case FT857_MFb_B_SKIP: return STR_MFb_B_SKIP;
	case FT857_MFb_C_TAG: return STR_MFb_C_TAG;
	case FT857_MFc_A_STO: return STR_MFc_A_STO;
	case FT857_MFc_B_RCL: return STR_MFc_B_RCL;
	case FT857_MFc_C_PROC: return STR_MFc_C_PROC;
	case FT857_MFd_A_RPT: return STR_MFd_A_RPT;
	case FT857_MFd_B_REV: return STR_MFd_B_REV;
	case FT857_MFd_C_VOX: return STR_MFd_C_VOX;
	case FT857_MFe_A_ENC: return STR_MFe_A_ENC;
	case FT857_MFe_B_DEC: return STR_MFe_B_DEC;
	case FT857_MFe_C_TDCH: return STR_MFe_C_TDCH;
	case FT857_MFf_A_ARTS: return STR_MFf_A_ARTS;
	case FT857_MFf_B_SRCH: return STR_MFf_B_SRCH;
	case FT857_MFf_C_PMS: return STR_MFf_C_PMS;
	case FT857_MFg_A_SCN: return STR_MFg_A_SCN;
	case FT857_MFg_B_PRI: return STR_MFg_B_PRI;
	case FT857_MFg_C_DW: return STR_MFg_C_DW;
	case FT857_MFh_A_SCOP: return STR_MFh_A_SCOP;
	case FT857_MFh_B_WID: return STR_MFh_B_WID;
	case FT857_MFh_C_STEP: return STR_MFh_C_STEP;
	case FT857_MFi_A_MTR: return STR_MFi_A_MTR;
	case FT857_MFi_C_DISP: return STR_MFi_C_DISP;
	case FT857_MFj_A_SPOT: return STR_MFj_A_SPOT;
	case FT857_MFj_B_BK: return STR_MFj_B_BK;
	case FT857_MFj_C_KYR: return STR_MFj_C_KYR;
	case FT857_MFk_A_TUNE: return STR_MFk_A_TUNE;
	case FT857_MFk_B_DOWN_ATAS: return STR_MFk_B_DOWN_ATAS;
	case FT857_MFk_C_UP_ATAS: return STR_MFk_C_UP_ATAS;
	case FT857_MFl_A_NB: return STR_MFl_A_NB;
	case FT857_MFl_B_AGC: return STR_MFl_B_AGC;
	case FT857_MFl_C_AGC_RECOVER: return STR_MFl_C_AGC_RECOVER;
	case FT857_MFm_A_IPO: return STR_MFm_A_IPO;
	case FT857_MFm_B_ATT: return STR_MFm_B_ATT;
	case FT857_MFm_C_NAR: return STR_MFm_C_NAR;
	case FT857_MFn_A_CFIL: return STR_MFn_A_CFIL;
	case FT857_MFn_B_FIL1: return STR_MFn_B_FIL1;
	case FT857_MFn_C_FIL2: return STR_MFn_C_FIL2;
	case FT857_MFo_A_PLY1: return STR_MFo_A_PLY1;
	case FT857_MFo_B_PLY2: return STR_MFo_B_PLY2;
	case FT857_MFo_C_PLY3: return STR_MFo_C_PLY3;
	case FT857_MFp_A_DNR: return STR_MFp_A_DNR;
	case FT857_MFp_B_DNF: return STR_MFp_B_DNF;
	case FT857_MFp_C_DBF: return STR_MFp_C_DBF;
	case FT857_MFq_A_MONI: return STR_MFq_A_MONI;
	case FT857_MFq_B_QSPL: return STR_MFq_B_QSPL;
	case FT857_MFq_C_ATC: return STR_MFq_C_ATC;
	default: return NULL;
	}
}

const char* FT857_MFa_C_spl_to_str(enum FT857_MFa_C_spl src)
{
	switch (src) {
	case FT857_MFa_C_SPL_OFF: return STR_MFa_C_SPL_OFF;
	case FT857_MFa_C_SPL_ON: return STR_MFa_C_SPL_ON;
	default: return NULL;
	}
}

const char* FT857_MFb_B_skip_to_str(enum FT857_MFb_B_skip src)
{
	switch (src) {
	case FT857_MFb_B_SKIP_OFF: return STR_MFb_B_SKIP_OFF;
	case FT857_MFb_B_SKIP_ON: return STR_MFb_B_SKIP_ON;
	default: return NULL;
	}
}

const char* FT857_MFb_C_tag_to_str(enum FT857_MFb_C_tag src)
{
	switch (src) {
	case FT857_MFb_C_TAG_OFF: return STR_MFb_C_TAG_OFF;
	case FT857_MFb_C_TAG_ON: return STR_MFb_C_TAG_ON;
	default: return NULL;
	}
}

const char* FT857_MFd_A_rpt_to_str(enum FT857_MFd_A_rpt src)
{
	switch (src) {
	case FT857_MFd_A_RPT_SIMPLEX: return STR_MFd_A_RPT_SIMPLEX;
	case FT857_MFd_A_RPT_NEGATIVE: return STR_MFd_A_RPT_NEGATIVE;
	case FT857_MFd_A_RPT_POSITIVE: return STR_MFd_A_RPT_POSITIVE;
	default: return NULL;
	}
}

const char* FT857_MFd_C_vox_to_str(enum FT857_MFd_C_vox src)
{
	switch (src) {
	case FT857_MFd_C_VOX_DISABLE: return STR_MFd_C_VOX_DISABLE;
	case FT857_MFd_C_VOX_ENABLE: return STR_MFd_C_VOX_ENABLE;
	default: return NULL;
	}
}

const char* FT857_MFe_A_enc_to_str(enum FT857_MFe_A_enc src)
{
	switch (src) {
	case FT857_MFe_A_ENC_OFF: return STR_MFe_A_ENC_OFF;
	case FT857_MFe_A_ENC_CTCSS: return STR_MFe_A_ENC_CTCSS;
	case FT857_MFe_A_ENC_DCS: return STR_MFe_A_ENC_DCS;
	default: return NULL;
	}
}

const char* FT857_MFe_B_dec_to_str(enum FT857_MFe_B_dec src)
{
	switch (src) {
	case FT857_MFe_B_DEC_OFF: return STR_MFe_B_DEC_OFF;
	case FT857_MFe_B_DEC_CTCSS: return STR_MFe_B_DEC_CTCSS;
	case FT857_MFe_B_DEC_DCS: return STR_MFe_B_DEC_DCS;
	default: return NULL;
	}
}

const char* FT857_MFe_selective_call_to_str(enum FT857_MFe_selective_call src)
{
	switch (src) {
	case FT857_MFe_SELEC_CALL_OFF:
	case FT857_MFe_SELEC_CALL_SPL_OFF: return STR_MFe_SELEC_CALL_OFF;
	case FT857_MFe_SELEC_CALL_TDE: return STR_MFe_SELEC_CALL_TDE;
	case FT857_MFe_SELEC_CALL_DDE: return STR_MFe_SELEC_CALL_DDE;
	case FT857_MFe_SELEC_CALL_TEN: return STR_MFe_SELEC_CALL_TEN;
	case FT857_MFe_SELEC_CALL_TSQ: return STR_MFe_SELEC_CALL_TSQ;
	case FT857_MFe_SELEC_CALL_DEN: return STR_MFe_SELEC_CALL_DEN;
	case FT857_MFe_SELEC_CALL_DCS: return STR_MFe_SELEC_CALL_DCS;
	case FT857_MFe_SELEC_CALL_SPL_X_T: return STR_MFe_SELEC_CALL_SPL_X_T;
	case FT857_MFe_SELEC_CALL_SPL_X_D: return STR_MFe_SELEC_CALL_SPL_X_D;
	case FT857_MFe_SELEC_CALL_SPL_T_X: return STR_MFe_SELEC_CALL_SPL_T_X;
	case FT857_MFe_SELEC_CALL_SPL_T_T: return STR_MFe_SELEC_CALL_SPL_T_T;
	case FT857_MFe_SELEC_CALL_SPL_T_D: return STR_MFe_SELEC_CALL_SPL_T_D;
	case FT857_MFe_SELEC_CALL_SPL_D_X: return STR_MFe_SELEC_CALL_SPL_D_X;
	case FT857_MFe_SELEC_CALL_SPL_D_T: return STR_MFe_SELEC_CALL_SPL_D_T;
	case FT857_MFe_SELEC_CALL_SPL_D_D: return STR_MFe_SELEC_CALL_SPL_D_D;
	default: return NULL;
	}
}

const char* FT857_MFf_A_arts_to_str(enum FT857_MFf_A_arts src)
{
	switch (src) {
	case FT857_MFf_A_ARTS_OFF: return STR_MFf_A_ARTS_OFF;
	case FT857_MFf_A_ARTS_ON: return STR_MFf_A_ARTS_ON;
	default: return NULL;
	}
}

const char* FT857_MFg_A_scn_to_str(enum FT857_MFg_A_scn src)
{
	switch (src) {
	case FT857_MFg_A_SCN_OFF: return STR_MFg_A_SCN_OFF;
	case FT857_MFg_A_SCN_ON: return STR_MFg_A_SCN_ON;
	default: return NULL;
	}
}

const char* FT857_MFg_B_pri_to_str(enum FT857_MFg_B_pri src)
{
	switch (src) {
	case FT857_MFg_B_PRI_OFF: return STR_MFg_B_PRI_OFF;
	case FT857_MFg_B_PRI_ON: return STR_MFg_B_PRI_ON;
	default: return NULL;
	}
}

const char* FT857_MFg_C_dw_to_str(enum FT857_MFg_C_dw src)
{
	switch (src) {
	case FT857_MFg_C_DW_OFF: return STR_MFg_C_DW_OFF;
	case FT857_MFg_C_DW_ON: return STR_MFg_C_DW_ON;
	default: return NULL;
	}
}

const char* FT857_MFh_A_scop_to_str(enum FT857_MFh_A_scop src)
{
	switch (src) {
	case FT857_MFh_A_SCOP_OFF: return STR_MFh_A_SCOP_OFF;
	case FT857_MFh_A_SCOP_ON: return STR_MFh_A_SCOP_ON;
	default: return NULL;
	}
}

const char* FT857_MFi_A_mtr_to_str(enum FT857_MFi_A_mtr src)
{
	switch (src) {
	case FT857_MFi_A_MTR_PWR: return STR_MFi_A_MTR_PWR;
	case FT857_MFi_A_MTR_ALC: return STR_MFi_A_MTR_ALC;
	case FT857_MFi_A_MTR_SWR: return STR_MFi_A_MTR_SWR;
	case FT857_MFi_A_MTR_MOD: return STR_MFi_A_MTR_MOD;
	default: return NULL;
	}
}

const char* FT857_MFi_C_disp_to_str(enum FT857_MFi_C_disp src)
{
	switch (src) {
	case FT857_MFi_C_DISP_SMALL: return STR_MFi_C_DISP_SMALL;
	case FT857_MFi_C_DISP_LARGE: return STR_MFi_C_DISP_LARGE;
	default: return NULL;
	}
}

const char* FT857_MFj_A_spot_to_str(enum FT857_MFj_A_spot src)
{
	switch (src) {
	case FT857_MFj_A_SPOT_OFF: return STR_MFj_A_SPOT_OFF;
	case FT857_MFj_A_SPOT_ON: return STR_MFj_A_SPOT_ON;
	default: return NULL;
	}
}

const char* FT857_MFj_B_bk_to_str(enum FT857_MFj_B_bk src)
{
	switch (src) {
	case FT857_MFj_B_BK_DISABLE: return STR_MFj_B_BK_DISABLE;
	case FT857_MFj_B_BK_ENABLE: return STR_MFj_B_BK_ENABLE;
	default: return NULL;
	}
}

const char* FT857_MFj_C_kyr_to_str(enum FT857_MFj_C_kyr src)
{
	switch (src) {
	case FT857_MFj_C_KYR_OFF: return STR_MFj_C_KYR_OFF;
	case FT857_MFj_C_KYR_ON: return STR_MFj_C_KYR_ON;
	default: return NULL;
	}
}

const char* FT857_MFk_A_tune_to_str(enum FT857_MFk_A_tune src)
{
	switch (src) {
	case FT857_MFk_A_TUNE_OFF: return STR_MFk_A_TUNE_OFF;
	case FT857_MFk_A_TUNE_ON: return STR_MFk_A_TUNE_ON;
	default: return NULL;
	}
}

const char* FT857_MFl_A_nb_to_str(enum FT857_MFl_A_nb src)
{
	switch (src) {
	case FT857_MFl_A_NB_OFF: return STR_MFl_A_NB_OFF;
	case FT857_MFl_A_NB_ON: return STR_MFl_A_NB_ON;
	default: return NULL;
	}
}

const char* FT857_MFl_B_agc_to_str(enum FT857_MFl_B_agc src)
{
	switch (src) {
	case FT857_MFl_B_AGC_OFF: return STR_MFl_B_AGC_OFF;
	case FT857_MFl_B_AGC_ON: return STR_MFl_B_AGC_ON;
	default: return NULL;
	}
}

const char* FT857_MFl_C_agc_recover_to_str(enum FT857_MFl_C_agc_recover src)
{
	switch (src) {
	case FT857_MFl_C_AGC_RECOVER_SLOW: return STR_MFl_C_AGC_RECOVER_SLOW;
	case FT857_MFl_C_AGC_RECOVER_AUTO: return STR_MFl_C_AGC_RECOVER_AUTO;
	case FT857_MFl_C_AGC_RECOVER_FAST: return STR_MFl_C_AGC_RECOVER_FAST;
	default: return NULL;
	}
}

const char* FT857_MFm_A_ipo_to_str(enum FT857_MFm_A_ipo src)
{
	switch (src) {
	case FT857_MFm_A_IPO_OFF: return STR_MFm_A_IPO_OFF;
	case FT857_MFm_A_IPO_ON: return STR_MFm_A_IPO_ON;
	default: return NULL;
	}
}

const char* FT857_MFm_B_att_to_str(enum FT857_MFm_B_att src)
{
	switch (src) {
	case FT857_MFm_B_ATT_OFF: return STR_MFm_B_ATT_OFF;
	case FT857_MFm_B_ATT_ON: return STR_MFm_B_ATT_ON;
	default: return NULL;
	}
}

const char* FT857_MFm_C_nar_to_str(enum FT857_MFm_C_nar src)
{
	switch (src) {
	case FT857_MFm_C_NAR_OFF: return STR_MFm_C_NAR_OFF;
	case FT857_MFm_C_NAR_ON: return STR_MFm_C_NAR_ON;
	default: return NULL;
	}
}

const char* FT857_MFp_A_dnr_to_str(enum FT857_MFp_A_dnr src)
{
	switch (src) {
	case FT857_MFp_A_DNR_OFF: return STR_MFp_A_DNR_OFF;
	case FT857_MFp_A_DNR_ON: return STR_MFp_A_DNR_ON;
	default: return NULL;
	}
}

const char* FT857_MFp_B_dnf_to_str(enum FT857_MFp_B_dnf src)
{
	switch (src) {
	case FT857_MFp_B_DNF_OFF: return STR_MFp_B_DNF_OFF;
	case FT857_MFp_B_DNF_ON: return STR_MFp_B_DNF_ON;
	default: return NULL;
	}
}

const char* FT857_MFp_C_dbf_to_str(enum FT857_MFp_C_dbf src)
{
	switch (src) {
	case FT857_MFp_C_DBF_OFF: return STR_MFp_C_DBF_OFF;
	case FT857_MFp_C_DBF_ON: return STR_MFp_C_DBF_ON;
	default: return NULL;
	}
}

/**********************
 * GET DATA FUNCTIONS *
 **********************/

enum FT857_MFa_C_spl
FT857_get_MFa_C_spl(struct CAT_device* dev)
{
	return(enum FT857_MFa_C_spl) get_value(dev, ADR_MFa_C_SPL, MASK_MFa_C_SPL);
}

enum FT857_MFb_B_skip
FT857_get_MFb_B_skip(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex)
{
	return(enum FT857_MFb_B_skip)
		get_channel_value(dev, vfo, vfo_subindex,
		POS_MFb_B_SKIP, MASK_MFb_B_SKIP);
}

enum FT857_MFb_C_tag
FT857_get_MFb_C_tag(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex)
{
	return(enum FT857_MFb_C_tag)
		get_channel_value(dev, vfo, vfo_subindex,
		POS_MFb_C_TAG, MASK_MFb_C_TAG);
}

enum FT857_MFc_C_proc
FT857_get_MFc_C_proc(struct CAT_device* dev)
{
	return(enum FT857_MFc_C_proc) get_value(dev, ADR_MFc_C_PROC, MASK_MFc_C_PROC);
}

enum FT857_MFd_A_rpt
FT857_get_MFd_A_rpt(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex)
{
	return(enum FT857_MFd_A_rpt)
		get_channel_value(dev, vfo, vfo_subindex,
		POS_MFd_A_RPT, MASK_MFd_A_RPT);
}

enum FT857_MFe_selective_call
FT857_get_MFe_selective_call(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex)
{
	return(enum FT857_MFe_selective_call)
		get_channel_value(dev, vfo, vfo_subindex,
		POS_MFe_SELECTIVE_CALL, MASK_MFe_SELECTIVE_CALL);
}

enum FT857_MFg_C_dw
FT857_get_MFg_C_dw(struct CAT_device* dev)
{
	return(enum FT857_MFg_C_dw) get_value(dev, ADR_MFg_C_DW, MASK_MFg_C_DW);
}

enum FT857_MFi_A_mtr
FT857_get_MFi_A_mtr(struct CAT_device* dev)
{
	return(enum FT857_MFi_A_mtr) get_value(dev, ADR_MFi_A_MTR, MASK_MFi_A_MTR);
}

enum FT857_MFi_C_disp
FT857_get_MFi_C_disp(struct CAT_device* dev)
{
	return(enum FT857_MFi_C_disp) get_value(dev, ADR_MFi_C_DISP, MASK_MFi_C_DISP);
}

enum FT857_MFj_A_spot
FT857_get_MFj_A_spot(struct CAT_device* dev)
{
	//return (enum FT857_MFj_A_spot) get_value(dev, ADR_MFj_A_SPOT, MASK_MFj_A_SPOT);
}

enum FT857_MFj_B_bk
FT857_get_MFj_B_bk(struct CAT_device* dev)
{
	return(enum FT857_MFj_B_bk) get_value(dev, ADR_MFj_B_BK, MASK_MFj_B_BK);
}

enum FT857_MFj_C_kyr
FT857_get_MFj_C_kyr(struct CAT_device* dev)
{
	return(enum FT857_MFj_C_kyr) get_value(dev, ADR_MFj_C_KYR, MASK_MFj_C_KYR);
}

enum FT857_MFl_A_nb
FT857_get_MFl_A_nb(struct CAT_device* dev)
{
	return(enum FT857_MFl_A_nb) get_value(dev, ADR_MFl_A_NB, MASK_MFl_A_NB);
}

enum FT857_MFl_B_agc
FT857_get_MFl_B_agc(struct CAT_device* dev)
{
	return(enum FT857_MFl_B_agc) get_value(dev, ADR_MFl_B_AGC, MASK_MFl_B_AGC);
}

enum FT857_MFl_C_agc_recover
FT857_get_MFl_C_agc_recover(struct CAT_device* dev)
{
	return(enum FT857_MFl_C_agc_recover)
		get_value(dev, ADR_MFl_C_AGC_RECOVER, MASK_MFl_C_AGC_RECOVER);
}

enum FT857_MFm_A_ipo
FT857_get_MFm_A_ipo(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex)
{
	return(enum FT857_MFm_A_ipo)
		get_channel_value(dev, vfo, vfo_subindex,
		POS_MFm_A_IPO, MASK_MFm_A_IPO);
}

enum FT857_MFm_B_att
FT857_get_MFm_B_att(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex)
{
	return(enum FT857_MFm_B_att)
		get_channel_value(dev, vfo, vfo_subindex,
		POS_MFm_B_ATT, MASK_MFm_B_ATT);
}

enum FT857_MFm_C_nar
FT857_get_MFm_C_nar(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex)
{
	return(enum FT857_MFm_C_nar)
		get_channel_value(dev, vfo, vfo_subindex,
		POS_MFm_C_NAR, MASK_MFm_C_NAR);
}

enum FT857_MFp_A_dnr
FT857_get_MFp_A_dnr(struct CAT_device* dev)
{
	return(enum FT857_MFp_A_dnr) get_value(dev, ADR_MFp_A_DNR, MASK_MFp_A_DNR);
}

enum FT857_MFp_B_dnf
FT857_get_MFp_B_dnr(struct CAT_device* dev)
{
	return(enum FT857_MFp_B_dnf) get_value(dev, ADR_MFp_B_DNF, MASK_MFp_B_DNF);
}

enum FT857_MFp_C_dbf
FT857_get_MFp_C_dbf(struct CAT_device* dev)
{
	return(enum FT857_MFp_C_dbf) get_value(dev, ADR_MFp_C_DBF, MASK_MFp_C_DBF);
}

/********************
 * STATIC FUNCTIONS *
 ********************/

static bool get_split_tone_from_selec_call(enum FT857_MFe_selective_call status)
{
	return status >> 4;
}