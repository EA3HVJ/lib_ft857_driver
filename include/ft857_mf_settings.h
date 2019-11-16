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

#ifndef FT857_MF_SETTINGS_H
#define FT857_MF_SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <yaesu_cat.h>
#include "ft857_global_status.h"
	
	enum FT857_MF_settings {
		FT857_MF_ERR = -1,
		FT857_MFa_A_SWITCH_VFO,
		FT857_MFa_B_COPY_VFO,
		FT857_MFa_C_SPL,
		FT857_MFb_A_MW,
		FT857_MFb_B_SKIP,
		FT857_MFb_C_TAG,
		FT857_MFc_A_STO,
		FT857_MFc_B_RCL,
		FT857_MFc_C_PROC,
		FT857_MFd_A_RPT,
		FT857_MFd_B_REV,
		FT857_MFd_C_VOX,
		FT857_MFe_A_ENC,
		FT857_MFe_B_DEC,
		FT857_MFe_C_TDCH,
		FT857_MFf_A_ARTS,
		FT857_MFf_B_SRCH,
		FT857_MFf_C_PMS,
		FT857_MFg_A_SCN,
		FT857_MFg_B_PRI,
		FT857_MFg_C_DW,
		FT857_MFh_A_SCOP,
		FT857_MFh_B_WID,
		FT857_MFh_C_STEP,
		FT857_MFi_A_MTR,
		FT857_MFi_C_DISP,
		FT857_MFj_A_SPOT,
		FT857_MFj_B_BK,
		FT857_MFj_C_KYR,
		FT857_MFk_A_TUNE,
		FT857_MFk_B_DOWN_ATAS,
		FT857_MFk_C_UP_ATAS,
		FT857_MFl_A_NB,
		FT857_MFl_B_AGC,
		FT857_MFl_C_AGC_RECOVER,
		FT857_MFm_A_IPO,
		FT857_MFm_B_ATT,
		FT857_MFm_C_NAR,
		FT857_MFn_A_CFIL,
		FT857_MFn_B_FIL1,
		FT857_MFn_C_FIL2,
		FT857_MFo_A_PLY1,
		FT857_MFo_B_PLY2,
		FT857_MFo_C_PLY3,
		FT857_MFp_A_DNR,
		FT857_MFp_B_DNF,
		FT857_MFp_C_DBF,
		FT857_MFq_A_MONI,
		FT857_MFq_B_QSPL,
		FT857_MFq_C_ATC
	};

	//FT857_MFa_A_switch_vfo

	//FT857_MFa_B_copy_vfo

	enum FT857_MFa_C_spl {
		FT857_MFa_C_SPL_ERR = -1,
		FT857_MFa_C_SPL_OFF,
		FT857_MFa_C_SPL_ON
	};

	//FT857_MFb_A_mw

	enum FT857_MFb_B_skip {
		FT857_MFb_B_SKIP_ERR = -1,
		FT857_MFb_B_SKIP_OFF,
		FT857_MFb_B_SKIP_ON
	};

	enum FT857_MFb_C_tag {
		FT857_MFb_C_TAG_ERR = -1,
		FT857_MFb_C_TAG_OFF,
		FT857_MFb_C_TAG_ON
	};

	//FT857_MFc_A_sto
	//FT857_MFc_B_rcl

	enum FT857_MFc_C_proc {
		FT857_MFc_C_PROC_ERR = -1,
		FT857_MFc_C_PROC_OFF,
		FT857_MFc_C_PROC_ON
	};

	enum FT857_MFd_A_rpt {
		FT857_MFd_A_RPT_ERR = -1,
		FT857_MFd_A_RPT_SIMPLEX,
		FT857_MFd_A_RPT_NEGATIVE,
		FT857_MFd_A_RPT_POSITIVE
	};

	//FT857_MFd_B_rev

	enum FT857_MFd_C_vox {
		FT857_MFd_C_VOX_ERR = -1,
		FT857_MFd_C_VOX_DISABLE,
		FT857_MFd_C_VOX_ENABLE
	};

	enum FT857_MFe_A_enc {
		FT857_MFe_A_ENC_ERR = -1,
		FT857_MFe_A_ENC_OFF,
		FT857_MFe_A_ENC_CTCSS,
		FT857_MFe_A_ENC_DCS
	};

	enum FT857_MFe_B_dec {
		FT857_MFe_B_DEC_ERR = -1,
		FT857_MFe_B_DEC_OFF,
		FT857_MFe_B_DEC_CTCSS,
		FT857_MFe_B_DEC_DCS
	};

	//FT857_MFe_C_tdch

	/* Selective Call Status enum */
	enum FT857_MFe_selective_call {
		FT857_MFe_SELEC_CALL_ERR = -1,
		/* Split Tone Off */
		FT857_MFe_SELEC_CALL_OFF = 0,
		FT857_MFe_SELEC_CALL_TDE,
		FT857_MFe_SELEC_CALL_DDE,
		FT857_MFe_SELEC_CALL_TEN = 4,
		FT857_MFe_SELEC_CALL_TSQ,
		FT857_MFe_SELEC_CALL_DEN = 8,
		FT857_MFe_SELEC_CALL_DCS = 10,
		/* Split Tone On */
		FT857_MFe_SELEC_CALL_SPL_OFF = 16,
		FT857_MFe_SELEC_CALL_SPL_X_T,
		FT857_MFe_SELEC_CALL_SPL_X_D,
		FT857_MFe_SELEC_CALL_SPL_T_X = 20,
		FT857_MFe_SELEC_CALL_SPL_T_T,
		FT857_MFe_SELEC_CALL_SPL_T_D,
		FT857_MFe_SELEC_CALL_SPL_D_X = 24,
		FT857_MFe_SELEC_CALL_SPL_D_T,
		FT857_MFe_SELEC_CALL_SPL_D_D
	};

	enum FT857_MFf_A_arts {
		FT857_MFf_A_ARTS_ERR = -1,
		FT857_MFf_A_ARTS_OFF,
		FT857_MFf_A_ARTS_ON
	};

	//FT857_MFf_B_srch
	//FT857_MFf_C_pms

	enum FT857_MFg_A_scn {
		FT857_MFg_A_SCN_ERR = -1,
		FT857_MFg_A_SCN_OFF,
		FT857_MFg_A_SCN_ON
	};

	enum FT857_MFg_B_pri {
		FT857_MFg_B_PRI_ERR = -1,
		FT857_MFg_B_PRI_OFF,
		FT857_MFg_B_PRI_ON
	};

	enum FT857_MFg_C_dw { //Dual Watch
		FT857_MFg_C_DW_ERR = -1,
		FT857_MFg_C_DW_OFF,
		FT857_MFg_C_DW_ON
	};

	enum FT857_MFh_A_scop {
		FT857_MFh_A_SCOP_ERR = -1,
		FT857_MFh_A_SCOP_OFF,
		FT857_MFh_A_SCOP_ON
	};

	//FT857_MFh_B_wid
	//FT857_MFh_C_step

	enum FT857_MFi_A_mtr {
		FT857_MFi_A_MTR_ERR = -1,
		FT857_MFi_A_MTR_PWR,
		FT857_MFi_A_MTR_ALC,
		FT857_MFi_A_MTR_SWR,
		FT857_MFi_A_MTR_MOD
	};

	enum FT857_MFi_C_disp {
		FT857_MFi_C_DISP_ERR = -1,
		FT857_MFi_C_DISP_SMALL,
		FT857_MFi_C_DISP_LARGE
	};

	enum FT857_MFj_A_spot {
		FT857_MFj_A_SPOT_ERR = -1,
		FT857_MFj_A_SPOT_OFF,
		FT857_MFj_A_SPOT_ON
	};

	enum FT857_MFj_B_bk {
		FT857_MFj_B_BK_ERR = -1,
		FT857_MFj_B_BK_DISABLE,
		FT857_MFj_B_BK_ENABLE
	};

	enum FT857_MFj_C_kyr {
		FT857_MFj_C_KYR_ERR = -1,
		FT857_MFj_C_KYR_OFF,
		FT857_MFj_C_KYR_ON
	};

	enum FT857_MFk_A_tune {
		FT857_MFk_A_TUNE_ERR = -1,
		FT857_MFk_A_TUNE_OFF,
		FT857_MFk_A_TUNE_ON
	};

	//FT857_MFk_B_down_atas
	//FT857_MFk_C_up_atas

	enum FT857_MFl_A_nb {
		FT857_MFl_A_NB_ERR = -1,
		FT857_MFl_A_NB_OFF,
		FT857_MFl_A_NB_ON
	};

	enum FT857_MFl_B_agc {
		FT857_MFl_B_AGC_ERR = -1,
		FT857_MFl_B_AGC_OFF,
		FT857_MFl_B_AGC_ON
	};

	enum FT857_MFl_C_agc_recover {
		FT857_MFl_C_AGC_RECOVER_ERR = -1,
		FT857_MFl_C_AGC_RECOVER_SLOW,
		FT857_MFl_C_AGC_RECOVER_AUTO,
		FT857_MFl_C_AGC_RECOVER_FAST
	};

	enum FT857_MFm_A_ipo {
		FT857_MFm_A_IPO_ERR = -1,
		FT857_MFm_A_IPO_OFF,
		FT857_MFm_A_IPO_ON
	};

	enum FT857_MFm_B_att {
		FT857_MFm_B_ATT_ERR = -1,
		FT857_MFm_B_ATT_OFF,
		FT857_MFm_B_ATT_ON
	};

	enum FT857_MFm_C_nar {
		FT857_MFm_C_NAR_ERR = -1,
		FT857_MFm_C_NAR_OFF,
		FT857_MFm_C_NAR_ON
	};

	//FT857_MFn_A_CFIL
	//FT857_MFn_B_FIL1
	//FT857_MFn_C_FIL2

	//FT857_MFo_A_ply1
	//FT857_MFo_B_ply2
	//FT857_MFo_C_ply3

	enum FT857_MFp_A_dnr {
		FT857_MFp_A_DNR_ERR = -1,
		FT857_MFp_A_DNR_OFF,
		FT857_MFp_A_DNR_ON
	};

	enum FT857_MFp_B_dnf {
		FT857_MFp_B_DNF_ERR = -1,
		FT857_MFp_B_DNF_OFF,
		FT857_MFp_B_DNF_ON
	};

	enum FT857_MFp_C_dbf {
		FT857_MFp_C_DBF_ERR = -1,
		FT857_MFp_C_DBF_OFF,
		FT857_MFp_C_DBF_ON = 3
	};

	enum FT857_MFq_A_moni {
		FT857_MFq_A_MONI_ERR = -1,
		FT857_MFq_A_MONI_OFF,
		FT857_MFq_A_MONI_ON
	};

	enum FT857_MFq_B_qspl {
		FT857_MFq_B_QSPL_ERR = -1,
		FT857_MFq_B_QSPL_OFF,
		FT857_MFq_B_QSPL_ON
	};

	enum FT857_MFq_C_atc {
		FT857_MFq_C_ATC_ERR = -1,
		FT857_MFq_C_ATC_OFF,
		FT857_MFq_C_ATC_ON
	};
	
	const char* FT857_MF_settings_to_str(enum FT857_MF_settings src);
	const char* FT857_MFa_C_spl_to_str(enum FT857_MFa_C_spl src);
	const char* FT857_MFb_B_skip_to_str(enum FT857_MFb_B_skip src);
	const char* FT857_MFb_C_tag_to_str(enum FT857_MFb_C_tag src);
	const char* FT857_MFd_A_rpt_to_str(enum FT857_MFd_A_rpt src);
	const char* FT857_MFd_C_vox_to_str(enum FT857_MFd_C_vox src);
	const char* FT857_MFe_A_enc_to_str(enum FT857_MFe_A_enc src);
	const char* FT857_MFe_B_dec_to_str(enum FT857_MFe_B_dec src);
	const char* FT857_MFe_selective_call_to_str(enum FT857_MFe_selective_call src);
	const char* FT857_MFf_A_arts_to_str(enum FT857_MFf_A_arts src);
	const char* FT857_MFg_A_scn_to_str(enum FT857_MFg_A_scn src);
	const char* FT857_MFg_B_pri_to_str(enum FT857_MFg_B_pri src);
	const char* FT857_MFg_C_dw_to_str(enum FT857_MFg_C_dw src);
	const char* FT857_MFh_A_scop_to_str(enum FT857_MFh_A_scop src);
	const char* FT857_MFi_A_mtr_to_str(enum FT857_MFi_A_mtr src);
	const char* FT857_MFi_C_disp_to_str(enum FT857_MFi_C_disp src);
	const char* FT857_MFj_A_spot_to_str(enum FT857_MFj_A_spot src);
	const char* FT857_MFj_B_bk_to_str(enum FT857_MFj_B_bk src);
	const char* FT857_MFj_C_kyr_to_str(enum FT857_MFj_C_kyr src);
	const char* FT857_MFk_A_tune_to_str(enum FT857_MFk_A_tune src);
	const char* FT857_MFl_A_nb_to_str(enum FT857_MFl_A_nb src);
	const char* FT857_MFl_B_agc_to_str(enum FT857_MFl_B_agc src);
	const char* FT857_MFl_C_agc_recover_to_str(enum FT857_MFl_C_agc_recover src);
	const char* FT857_MFm_A_ipo_to_str(enum FT857_MFm_A_ipo src);
	const char* FT857_MFm_B_att_to_str(enum FT857_MFm_B_att src);
	const char* FT857_MFm_C_nar_to_str(enum FT857_MFm_C_nar src);
	const char* FT857_MFp_A_dnr_to_str(enum FT857_MFp_A_dnr src);
	const char* FT857_MFp_B_dnf_to_str(enum FT857_MFp_B_dnf src);
	const char* FT857_MFp_C_dbf_to_str(enum FT857_MFp_C_dbf src);



	enum FT857_MFa_C_spl
	FT857_get_MFa_C_spl(struct CAT_device* dev);
	
	enum FT857_MFb_B_skip
	FT857_get_MFb_B_skip(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex);
	
	enum FT857_MFb_C_tag
	FT857_get_MFb_C_tag(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex);
	
	enum FT857_MFc_C_proc
	FT857_get_MFc_C_proc(struct CAT_device* dev);

	enum FT857_MFd_A_rpt
	FT857_get_MFd_A_rpt(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex);
	
	enum FT857_MFd_C_vox
	FT857_get_MFd_C_vox(struct CAT_device* dev);
	
	enum FT857_MFe_A_enc
	FT857_get_MFe_A_enc(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex);
	
	enum FT857_MFe_B_dec
	FT857_get_MFe_B_dec(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex);

	enum FT857_MFe_selective_call
	FT857_get_MFe_selective_call(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex);
	
	enum FT857_MFf_A_arts
	FT857_get_MFf_A_arts(struct CAT_device* dev);
	
	enum FT857_MFg_A_scn
	FT857_MFg_A_scn(struct CAT_device* dev);
	
	enum FT857_MFg_B_pri
	FT857_MFg_B_pri(struct CAT_device* dev);

	enum FT857_MFg_C_dw
	FT857_get_MFg_C_dw(struct CAT_device* dev);
	
	enum FT857_MFh_A_scop
	FT857_get_Mfh_A_scop(struct CAT_device* dev);
	
	//enum FT857_MFh_B_wid
	
	enum FT857_MFi_A_mtr
	FT857_get_MFi_A_mtr(struct CAT_device* dev);
	
	enum FT857_MFi_C_disp
	FT857_get_MFi_C_disp(struct CAT_device* dev);
	
	enum FT857_MFj_A_spot
	FT857_get_MFj_A_spot(struct CAT_device* dev);
	
	enum FT857_MFj_B_bk
	FT857_get_MFj_B_bk(struct CAT_device* dev);
	
	enum FT857_MFj_C_kyr
	FT857_get_MFj_C_kyr(struct CAT_device* dev);
	
	enum FT857_MFk_A_tune
	FT857_get_MFk_A_tune(struct CAT_device* dev);
	
	enum FT857_MFl_A_nb
	FT857_get_MFl_A_nb(struct CAT_device* dev);
	
	enum FT857_MFl_B_agc
	FT857_get_MFl_B_agc(struct CAT_device* dev);
	
	enum FT857_MFl_C_agc_recover
	FT857_get_MFl_C_agc_recover(struct CAT_device* dev);
	
	enum FT857_MFm_A_ipo
	FT857_get_MFm_A_ipo(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex);
	
	enum FT857_MFm_B_att
	FT857_get_MFm_B_att(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex);
	
	enum FT857_MFm_C_nar
	FT857_get_MFm_C_nar(struct CAT_device* dev, enum FT857_vfo vfo, int vfo_subindex);
	
	enum FT857_MFp_A_dnr
	FT857_get_MFp_A_dnr(struct CAT_device* dev);
	
	enum FT857_MFp_B_dnf
	FT857_get_MFp_B_dnr(struct CAT_device* dev);
	
	enum FT857_MFp_C_dbf
	FT857_get_MFp_C_dbf(struct CAT_device* dev);
	
	enum FT857_MFq_A_moni
	FT857_get_MFq_A_moni(struct CAT_device* dev);
	
	enum FT857_MFq_B_qspl
	FT857_get_MFq_B_qspl(struct CAT_device* dev);
	
	enum FT857_MFq_C_atc
	FT857_get_MFq_C_atc(struct CAT_device* dev);


#ifdef __cplusplus
}
#endif

#endif /* FT857_MF_SETTINGS_H */

