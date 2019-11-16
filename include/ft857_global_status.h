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

#ifndef FT857_GLOBAL_STATUS_H
#define FT857_GLOBAL_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#define FT857_OPT_GET_VFO      FT857_VFO_ERR
#define FT857_OPT_GET_SUBINDEX (-1)
#define FT857_OPT_GET_BAND     FT857_BAND_ERR

	enum FT857_trx_status {
		FT857_TRX_ERR = -1,
		FT857_TX,
		FT857_RX,
		FT857_SQL
	};

	/* VFO enum type
	 */
	enum FT857_vfo_flags {
		FT857_VFO_FLAG_VFO_A = 0,
		FT857_VFO_FLAG_VFO_B = 1,
		FT857_VFO_FLAG_MTQMB = 2,
		FT857_VFO_FLAG_QMB = 4,
		FT857_VFO_FLAG_PMS = 8,
		FT857_VFO_FLAG_HOME = 16,
		FT857_VFO_FLAG_MTUNE = 32,
		FT857_VFO_FLAG_MODE_MEM = 64,
		FT857_VFO_FLAG_MODE_VFO = 128
	};

	enum FT857_vfo {
		FT857_VFO_ERR = -1,
		FT857_VFO_A,
		FT857_VFO_B,
		FT857_VFO_MTQMB,
		FT857_VFO_QMB,
		FT857_VFO_PMS,
		FT857_VFO_HOME,
		FT857_VFO_MTUNE,
		FT857_VFO_MCHAN
	};

	/* 
	 * Band enum type
	 */
	enum FT857_band {
		FT857_BAND_ERR = -1,
		FT857_BAND_HF,
		FT857_BAND_6M,
		FT857_BAND_VHF,
		FT857_BAND_UHF
	};

	/* 
	 * Subband enum type
	 * Use subband for VFO struct channels index
	 */
	enum FT857_subband {
		FT857_SBAND_ERR = -1,
		FT857_SBAND_160M,
		FT857_SBAND_80M,
		FT857_SBAND_60M,
		FT857_SBAND_40M,
		FT857_SBAND_30M,
		FT857_SBAND_20M,
		FT857_SBAND_17M,
		FT857_SBAND_15M,
		FT857_SBAND_12M,
		FT857_SBAND_10M,
		FT857_SBAND_6M,
		FT857_SBAND_3M,
		FT857_SBAND_250CM,
		FT857_SBAND_2M,
		FT857_SBAND_70CM,
		FT857_SBAND_PHANTOM
	};

	enum FT857_smeter {
		FT857_SMETER_ERR = -1,
		FT857_SMETER_S0,
		FT857_SMETER_S1,
		FT857_SMETER_S2,
		FT857_SMETER_S3,
		FT857_SMETER_S4,
		FT857_SMETER_S5,
		FT857_SMETER_S6,
		FT857_SMETER_S7,
		FT857_SMETER_S8,
		FT857_SMETER_S9,
		FT857_SMETER_S9_10_DB,
		FT857_SMETER_S9_20_DB,
		FT857_SMETER_S9_30_DB,
		FT857_SMETER_S9_40_DB,
		FT857_SMETER_S9_50_DB,
		FT857_SMETER_S9_60_DB
	};
	
	enum FT857_pwr_meter {
		FT857_PWR_ERR = -1,
		FT857_PWR_0,
		FT857_PWR_1,
		FT857_PWR_2,
		FT857_PWR_3,
		FT857_PWR_4,
		FT857_PWR_5,
		FT857_PWR_6,
		FT857_PWR_7,
		FT857_PWR_8,
		FT857_PWR_9,
		FT857_PWR_A,
		FT857_PWR_B,
		FT857_PWR_C,
		FT857_PWR_D,
		FT857_PWR_E,
		FT857_PWR_F
	};
	
	enum FT857_alc_meter {
		FT857_ALC_ERR = -1,
		FT857_ALC_0,
		FT857_ALC_1,
		FT857_ALC_2,
		FT857_ALC_3,
		FT857_ALC_4,
		FT857_ALC_5,
		FT857_ALC_6,
		FT857_ALC_7,
		FT857_ALC_8,
		FT857_ALC_9,
		FT857_ALC_A,
		FT857_ALC_B,
		FT857_ALC_C,
		FT857_ALC_D,
		FT857_ALC_E,
		FT857_ALC_F
	};
	
	enum FT857_mod_meter {
		FT857_MOD_ERR = -1,
		FT857_MOD_0,
		FT857_MOD_1,
		FT857_MOD_2,
		FT857_MOD_3,
		FT857_MOD_4,
		FT857_MOD_5,
		FT857_MOD_6,
		FT857_MOD_7,
		FT857_MOD_8,
		FT857_MOD_9,
		FT857_MOD_A,
		FT857_MOD_B,
		FT857_MOD_C,
		FT857_MOD_D,
		FT857_MOD_E,
		FT857_MOD_F
	};
	
	enum FT857_vswr_meter {
		FT857_VSWR_ERR = -1,
		FT857_VSWR_0,
		FT857_VSWR_1,
		FT857_VSWR_2,
		FT857_VSWR_3,
		FT857_VSWR_4,
		FT857_VSWR_5,
		FT857_VSWR_6,
		FT857_VSWR_7,
		FT857_VSWR_8,
		FT857_VSWR_9,
		FT857_VSWR_A,
		FT857_VSWR_B,
		FT857_VSWR_C,
		FT857_VSWR_D,
		FT857_VSWR_E,
		FT857_VSWR_F
	};

#ifdef __cplusplus
}
#endif

#endif /* FT857_GLOBAL_STATUS_H */

