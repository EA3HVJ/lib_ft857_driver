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

#ifndef EEPROM_MAP_H
#define EEPROM_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

#define EEPROM_SIZE 0x1CF3 /**< Size of Yaesu FT857d EEPROM */

#define NUM_ALIGNMENTS 74
#define NUM_SETTINGS 91

	/* Single byte adresses */
#define ADR_VFO_FLAGS             0x0068 /**< Adress of VFO-A/VFO-B/M status */
#define ADR_BAND                  0x0069 /**< Adress of Band status HF/6m/VHF/UHF */
#define ADR_SUBBAND_A             0x006C /**< Adress of Subband/wavelength status (or wich VFO channel block is active) */
#define ADR_SUBBAND_B             0x006C
#define ADR_LOCK                  0x006A /**< Adress of Lock status */

	/* MENU SETTINGS ADRESSES */
#define ADR_N01_EXT_MENU          0x0091
#define ADR_N02_144_MHZ_ARS       0x0072
#define ADR_N03_430_MHZ_ARS       0x0072
#define ADR_N04_AM_FM_DIAL        0x0076
#define ADR_N05_AM_MIC_GAIN       0x007B
	//N6 POS 
#define ADR_N07_APO_TIME          0x0078
#define ADR_N08_ARTS_BEEP         0x0070
#define ADR_N09_ARTS_ID           0x008C
#define ADR_N10_ARTS_IDW          0x1C59
#define ADR_N11_BEACON_TEXT_1     0x1C63
#define ADR_N11_BEACON_TEXT_2     0x1C8B
#define ADR_N11_BEACON_TEXT_3     0x1CB3
#define ADR_N12_BEACON_TIME       0x00A6
#define ADR_N13_BEEP_TONE         0x006F
#define ADR_N14_BEEP_VOL          0x008F
#define ADR_N15_CAR_LSB_RX        0x0084
#define ADR_N16_CAR_LSB_TX        0x0086
#define ADR_N17_CAR_USB_RX        0x0085
#define ADR_N18_CAR_USB_TX        0x0087
#define ADR_N19_CAT_RATE          0x0094 /**< Adress of CAT rate (4800/9600/38400) */ //0x10 4800, 0x50 9600, 0x90 38400
#define ADR_N20_COM_PORT          0x008E /**< Adress of CAT port mode (CAT/Tuner/Linear) */
#define ADR_N21_CLAR_DIAL_SEL     0x006F
#define ADR_N22_CW_AUTO_MODE      0x0092
#define ADR_N23_CW_BFO            0x0092
#define ADR_N24_CW_DELAY          0x0073 //PROVAT FINS AQUÍ
#define ADR_N25_CW_KEY_REV        0x006B
#define ADR_N26_CW_PADDLE         0x007B
#define ADR_N27_CW_PITCH          0x0071
#define ADR_N28_CW_QSK            0x0092
#define ADR_N29_CW_SIDE_TONE      0x0074
#define ADR_N30_CW_SPEED          0x0075
#define ADR_N31_CW_TRAINING       0x0092
#define ADR_N32_CW_WEIGHT         0x0072
	//N33 Channel structure
#define ADR_N34_DCS_INV           0x0079
#define ADR_N35_DIAL_STEP         0x0070
#define ADR_N36_DIG_DISP          0x0082
#define ADR_N37_DIG_GAIN          0x007D
#define ADR_N38_DIG_MODE          0x0078
#define ADR_N39_DIG_SHIFT         0x0080
#define ADR_N40_DIG_VOX           0x0090
#define ADR_N41_DISP_COLOR        0x0096 //mode
#define ADR_N41_DISP_COLOR_ARTS   0x0097
#define ADR_N41_DISP_COLOR_BAND   0x0097
#define ADR_N41_DISP_COLOR_FIX    0x0098
#define ADR_N41_DISP_COLOR_MEMGRP 0x0097
#define ADR_N41_DISP_COLOR_MODE   0x0097
#define ADR_N41_DISP_COLOR_MTR    0x0097
#define ADR_N41_DISP_COLOR_VFO    0x0097
#define ADR_N42_DISP_CONTRAST     0x006E
#define ADR_N43_DISP_INTENSITY    0x0096
#define ADR_N44_DISP_MODE         0x006E
#define ADR_N45_DSP_BPF_WIDTH     0x0093
#define ADR_N46_DSP_HPF_CUTOFF    0x0095
#define ADR_N47_DSP_LPF_CUTOFF    0x0094
#define ADR_N48_DSP_MIC_EQ        0x0093
#define ADR_N49_DSP_NR_LEVEL      0x0093
#define ADR_N50_EMERGENCY         0x0077
#define ADR_N51_FM_MIC_GAIN       0x007C
	//N52 POS
#define ADR_N53_HOME_VFO          0x0091
#define ADR_N54_LOCK_MODE         0x0071
#define ADR_N55_MEM_GROUP         0x0078
	//N56_MEM_TAG POS
#define ADR_N57_DIAL_MODE         0x009C
#define ADR_N58_MIC_SCAN          0x007A
#define ADR_N59_MIC_SEL           0x008E
#define ADR_N60_MTR_ARX_SEL       0x00A5
#define ADR_N61_MTR_ATX_SEL       0x0095
#define ADR_N62_MTR_PEAK_HOLD     0x008E
#define ADR_N63_NB_LEVEL          0x0099
#define ADR_N64_OP_FILTER         0x00A3
#define ADR_N64_OP_FILTER1_NAME   0x1CE3
#define ADR_N64_OP_FILTER2_NAME   0x1CE7
#define ADR_N65_PG_A              0x009D
#define ADR_N66_PG_B              0x009E
#define ADR_N67_PG_C              0x009F
#define ADR_N68_PG_ACC            0x00A0
#define ADR_N69_PG_P1             0x00A1
#define ADR_N70_PG_P2             0x00A2
#define ADR_N71_PKT_1200          0x007E
#define ADR_N72_PKT_9600          0x007F
#define ADR_N73_PKT_RATE          0x0070
#define ADR_N74_PROC_LEVEL        0x009A
#define ADR_N75_POWER_SET_HF      0x009B
#define ADR_N75_POWER_SET_6M      0x00AA
#define ADR_N75_POWER_SET_VHF     0x00AB
#define ADR_N75_POWER_SET_UHF     0x00AC
	//76 Channel structure
#define ADR_N77_SCAN_MODE         0x0091
#define ADR_N78_SCAN_RESUME       0x0091
#define ADR_N79_SPLIT_TONE        0x008E
#define ADR_N80_SQL_RF_GAIN       0x0072
#define ADR_N81_SSB_MIC_GAIN      0x007A
	//N82 POS
	//83 Channel structure
#define ADR_N84_TOT_TIME          0x0079
#define ADR_N85_TUNER_ATAS        0x009C
#define ADR_N86_TX_IF_FILTER      0x00A4
#define ADR_N87_VOX_DELAY         0x0077
#define ADR_N88_VOX_GAIN          0x0076
#define ADR_N89_XVTR_A_FREQ       0x1CDB
#define ADR_N89_XVTR_A_SHIFT      0x00A5
#define ADR_N90_XVTR_B_FREQ       0x1CDF
#define ADR_N90_XVTR_B_SHIFT      0x00A5
#define ADR_N91_XVTR_SEL          0x00A3

	/* MULTI FUNCTION KEY SETTINGS ADRESSES */
	//MFa_A_A/B
	//MFa_B_A=B
#define ADR_MFa_C_SPL             0x008D /**< Adress of Split mode status */
	//MFb_A_MW
	//MFb_B_SKIP = POS
	//MFb_C_TAG = POS
	//MFc_A_STO
	//MFc_B_RCL
#define ADR_MFc_C_PROC            0x00A9
	//MFd_A_RPT = POS
	//MFd_B_REV
#define ADR_MFd_C_VOX             0x006B
	//MFe_A_ENC = POS
	//MFe_B_DEC = POS
	//MFe_C_TDCH
#define ADR_MFf_A_ARTS            0x008C
	//MFf_B_SRCH
	//MFf_C_PMS
#define ADR_MFg_A_SCN
#define ADR_MFg_B_PRI             0x008C //PRIORITY SCAN
#define ADR_MFg_C_DW              0x008C //DUAL WATCH
#define ADR_MFh_A_SCOP            0x00A9
#define ADR_MFh_B_WID_SCOP        0x00A9
	//MFh_C_STEP
#define ADR_MFi_A_MTR             0x0095
#define ADR_MFi_C_DISP            0x006A
#define ADR_MFj_A_SPOT
#define ADR_MFj_B_BK              0x006B
#define ADR_MFj_C_KYR             0x006B
#define ADR_MFk_A_TUNE
	//MFk_B_DOWN_ATAS
	//MFk_C_UP_ATAS
#define ADR_MFl_A_NB              0x006A
#define ADR_MFl_B_AGC             0x00A8
#define ADR_MFl_C_AGC_RECOVER     0x006A
	//MFm_A_IPO = POS
	//MFm_B_ATT = POS
	//MFm_C_NAR = POS???
	//MFn_A_CFIL
	//MFn_B_FIL1
	//MFn_C_FIL2
	//MFo_A_PLY1
	//MFo_B_PLY2
	//MFo_C_PLY3
#define ADR_MFp_A_DNR             0x00A8
#define ADR_MFp_B_DNF             0x00A8
#define ADR_MFp_C_DBF             0x00A8
#define ADR_MFq_A_MONI
#define ADR_MFq_B_QSPL
#define ADR_MFq_C_ATC


#define ADR_MISC                  0x0073
#define ADR_ADVANCED_MENU_NUM     0x0088 //FULL BYTE 1 lower than displayed. Menu F button          


	/* Bitmasks */
#define MASK_VFO_FLAGS             0b11111111 /**< Bitmask for VFO or Memory mode */
#define MASK_BAND                  0b00000011 /**< Bitmask for Band status */
#define MASK_NB                    0b00100000 /**< Bitmask for Noise Blanker status */
#define MASK_SUBBAND_A             0b00001111
#define MASK_SUBBAND_B             0b11110000
#define MASK_LOCK                  0b10000000 /**< Bitmask for Lock status */

	/* MENU SETTINGS BITMASKS/SIZES */
#define MASK_N01_EXT_MENU          0b10000000 
#define MASK_N02_144_MHZ_ARS       0b01000000
#define MASK_N03_430_MHZ_ARS       0b00100000
#define MASK_N04_AM_FM_DIAL        0b10000000
#define MASK_N05_AM_MIC_GAIN       0b01111111
	//N06 POS
#define MASK_N07_APO_TIME          0b00000111
#define MASK_N08_ARTS_BEEP         0b11000000
#define MASK_N09_ARTS_ID           0b10000000
#define SIZE_N10_ARTS_IDW          10
#define SIZE_N11_BEACON_TEXT       40
#define MASK_N12_BEACON_TIME       0b11111111
#define MASK_N13_BEEP_TONE         0b00000011
#define MASK_N14_BEEP_VOL          0b01111111
#define MASK_N15_CAR_LSB_RX        0b11111111 //SIGNED
#define MASK_N16_CAR_LSB_TX        0b11111111 //SIGNED
#define MASK_N17_CAR_USB_RX        0b11111111 //SIGNED
#define MASK_N18_CAR_USB_TX        0b11111111 //SIGNED
#define MASK_N19_CAT_RATE          0b11000000
#define MASK_N20_COM_PORT          0b00001100
#define MASK_N21_CLAR_DIAL_SEL     0b00000100
#define MASK_N22_CW_AUTO_MODE      0b10000000
#define MASK_N23_CW_BFO            0b00000011
#define MASK_N24_CW_DELAY          0b11111111
#define MASK_N25_CW_KEY_REV        0b00000100
#define MASK_N26_CW_PADDLE         0b10000000
#define MASK_N27_CW_PITCH          0b00000111
#define MASK_N28_CW_QSK            0b00011100
#define MASK_N29_CW_SIDE_TONE      0b01111111
#define MASK_N30_CW_SPEED          0b00111111
#define MASK_N31_CW_TRAINING       0b01100000
#define MASK_N32_CW_WEIGHT         0b00011111
	//33 channel structure
#define MASK_N34_DCS_INV           0b11000000
#define MASK_N35_DIAL_STEP         0b00100000
#define SIZE_N36_DIG_DISP          2 //SIGNED
#define MASK_N37_DIG_GAIN          0b01111111
#define MASK_N38_DIG_MODE          0b11100000
#define SIZE_N39_DIG_SHIFT         2 //SIGNED
#define MASK_N40_DIG_VOX           0b01111111
#define MASK_N41_DISP_COLOR        0b00000111
#define MASK_N41_DISP_COLOR_ARTS   0b00000001
#define MASK_N41_DISP_COLOR_BAND   0b00000010
#define MASK_N41_DISP_COLOR_FIX    0b00011111 //Color wheel
#define MASK_N41_DISP_COLOR_MEMGRP 0b00001000
#define MASK_N41_DISP_COLOR_MODE   0b00010000
#define MASK_N41_DISP_COLOR_MTR    0b00100000
#define MASK_N41_DISP_COLOR_VFO    0b01000000
#define MASK_N42_DISP_CONTRAST     0b00001111
#define MASK_N43_DISP_INTENSITY    0b00110000
#define MASK_N44_DISP_MODE         0b11000000
#define MASK_N45_DSP_BPF_WIDTH     0b00001100
#define MASK_N46_DSP_HPF_CUTOFF    0b00001111
#define MASK_N47_DSP_LPF_CUTOFF    0b00011111
#define MASK_N48_DSP_MIC_EQ        0b00000011
#define MASK_N49_DSP_NR_LEVEL      0b11110000
#define MASK_N50_EMERGENCY         0b00100000
#define MASK_N51_FM_MIC_GAIN       0b01111111
	//N52 POS
#define MASK_N53_HOME_VFO          0b01000000
#define MASK_N54_LOCK_MODE         0b00110000
#define MASK_N55_MEM_GROUP         0b00010000
	//N56_MEM_TAG POS
#define MASK_N57_DIAL_MODE         0b00000111
#define MASK_N58_MIC_SCAN          0b10000000
#define MASK_N59_MIC_SEL           0b00110000
#define MASK_N60_MTR_ARX_SEL       0b00000111
#define MASK_N61_MTR_ATX_SEL       0b11100000
#define MASK_N62_MTR_PEAK_HOLD     0b01000000
#define MASK_N63_NB_LEVEL          0b01111111
#define MASK_N64_OP_FILTER         0b00000001
#define SIZE_N64_OP_FILTER_NAME    4
#define MASK_N65_PG_A              0b11111111
#define MASK_N66_PG_B              0b11111111
#define MASK_N67_PG_C              0b11111111
#define MASK_N68_PG_ACC            0b11111111
#define MASK_N69_PG_P1             0b11111111
#define MASK_N70_PG_P2             0b11111111
#define MASK_N71_PKT_1200          0b01111111
#define MASK_N72_PKT_9600          0b01111111
#define MASK_N73_PKT_RATE          0b00000100
#define MASK_N74_PROC_LEVEL        0b01111111
#define MASK_N75_POWER_SET         0b01111111 /**< Mask for  *///Both HF/6m/VHF/UHF
	//N76 channel structure
#define MASK_N77_SCAN_MODE         0b00110000
#define MASK_N78_SCAN_RESUME       0b00001111
#define MASK_N79_SPLIT_TONE        0b00000001
#define MASK_N80_SQL_RF_GAIN       0b10000000
#define MASK_N81_SSB_MIC_GAIN      0b01111111
	//N82 POS
	//83 channel structure
#define MASK_N84_TOT_TIME          0b00011111
#define MASK_N85_TUNER_ATAS        0b00111000
#define MASK_N86_TX_IF_FILTER      0b00000011
#define MASK_N87_VOX_DELAY         0b11111111
#define MASK_N88_VOX_GAIN          0b01111111
#define SIZE_N89_XVTR_A_FREQ       4
#define MASK_N89_XVTR_A_SHIFT      0b00010000
#define SIZE_N90_XVTR_B_FREQ       4
#define MASK_N90_XVTR_B_SHIFT      0b00001000
#define MASK_N91_XVTR_SEL          0b00011000 // 01 = XVTR A, 10 = XVTR B

	/* MULTI FUNCTION KEY SETTINGS ADRESSES */
	//MFa_A_A/B
	//MFa_B_A=B
#define MASK_MFa_C_SPL             0b10000000
	//MFb_A_MW
	//MFb_B_SKIP = POS
	//MFb_C_TAG = POS
	//MFc_A_STO
	//MFc_B_RCL
#define MASK_MFc_C_PROC            0b00000010
	//MFd_A_RPT = POS
	//MFd_B_REV
#define MASK_MFd_C_VOX             0b10000000
	//MFe_A_ENC = POS
	//MFe_B_DEC = POS
	//MFe_C_TDCH
#define MASK_MFf_A_ARTS            0b10000000
	//MFf_B_SRCH
	//MFf_C_PMS
#define MASK_MFg_A_SCN
#define MASK_MFg_B_PRI             0b00001000 // comprovar podria ser:
#define MASK_MFg_C_DW              0b00010000 // 1 = off, 2 = PRI, 3 = DW
#define MASK_MFh_A_SCOP            0b00010000
#define MASK_MFh_B_WID_SCOP        0b00001100
	//MFh_C_STEP
#define MASK_MFi_A_MTR             0b11100000
#define MASK_MFi_C_DISP            0b00000100
#define MASK_MFj_A_SPOT
#define MASK_MFj_B_BK              0b00100000
#define MASK_MFj_C_KYR             0b00010000
#define MASK_MFk_A_TUNE
	//MFk_B_DOWN_ATAS
	//MFk_C_UP_ATAS
#define MASK_MFl_A_NB              0b00100000
#define MASK_MFl_B_AGC             0b00100000
#define MASK_MFl_C_AGC_RECOVER     0b00000011
	//MFm_A_IPO = POS
	//MFm_B_ATT = POS
	//MFm_C_NAR = POS???
	//MFn_A_CFIL
	//MFn_B_FIL1
	//MFn_C_FIL2
	//MFo_A_PLY1
	//MFo_B_PLY2
	//MFo_C_PLY3
#define MASK_MFp_A_DNR             0b00000010
#define MASK_MFp_B_DNF             0b00000001
#define MASK_MFp_C_DBF             0b00001100
#define MASK_MFq_A_MONI
#define MASK_MFq_B_QSPL
#define MASK_MFq_C_ATC


#define MASK_ADVANCED_MENU_NUM     0b11111111

#define MASK_XVTR                  0b10000000                        

	/* Power values (standard alignment config) */
#define MAX_PWR_HF  100 /**< Max value for HF Power */
#define MAX_PWR_M6  100 /**< Max value for 6m Power */
#define MAX_PWR_VHF 50  /**< Max value for VHF Power */
#define MAX_PWR_UHF 20  /**< Max value for UHF Power */
#define MIN_PWR_HF  5   /**< Min value for HF Power */
#define MIN_PWR_M6  5   /**< Min value for 6m Power */
#define MIN_PWR_VHF 5   /**< Min value for VHF Power */
#define MIN_PWR_UHF 2   /**< Min value for HF Power */

	/* Mic gain */
#define MAX_MIC_GAIN 100

	/* EEPROM cheksum block*/
#define ADR_EEPROM_CHECKSUM  0x0000      /**< Start adress of EEPROM checksum */
#define SIZE_EEPROM_CHECKSUM 4           /**< Checksum length in bytes */
#define EEPROM_CHEKSUM_OK    0xA55AA55A  /**< Checksum correct value */

	/*
	 * Jumper bitmask
	 * Can get this two data bytes with getRadioConfigRequest()
	 * Bytes 8 and 9 of Response 
	 */
#define ADR_JUMPERS      0x0004
#define SIZE_JUMPERS     2

	/* Alignment Config */
#define ADR_ALIGNMENT_CONFIG  0x0007
#define SIZE_ALIGNMENT_CONFIG 74

	/* All settings */
#define ADR_SETTINGS  0x0068
#define SIZE_SETTINGS 69

	/* 
	 * 28 Byte Block Channels 
	 * Start Adresses
	 */
#define SIZE_CHAN_STRUCT 28
	/* VFO A */
#define ADR_VFO_A_160M     0x00BA
#define ADR_VFO_A_80M      0x00D6
#define ADR_VFO_A_60M      0x00F2
#define ADR_VFO_A_40M      0x010E
#define ADR_VFO_A_30M      0x012A
#define ADR_VFO_A_20M      0x0146
#define ADR_VFO_A_17M      0x0162
#define ADR_VFO_A_15M      0x017E
#define ADR_VFO_A_12M      0x019A
#define ADR_VFO_A_10M      0x01B6
#define ADR_VFO_A_6M       0x01D2
#define ADR_VFO_A_WFM_BCB  0x01EE
#define ADR_VFO_A_AIR      0x020A
#define ADR_VFO_A_2M       0x0226
#define ADR_VFO_A_70CM     0x0242
#define ADR_VFO_A_HF_EXTRA 0x025E
	/* VFO B */
#define ADR_VFO_B_160M     0x027A
#define ADR_VFO_B_80M      0x0296
#define ADR_VFO_B_60M      0x02B2
#define ADR_VFO_B_40M      0x02CE
#define ADR_VFO_B_30M      0x02EA
#define ADR_VFO_B_20M      0x0306
#define ADR_VFO_B_17M      0x0322
#define ADR_VFO_B_15M      0x033E
#define ADR_VFO_B_12M      0x035A
#define ADR_VFO_B_10M      0x0376
#define ADR_VFO_B_6M       0x0392
#define ADR_VFO_B_WFM_BCB  0x03AE
#define ADR_VFO_B_AIR      0x03CA
#define ADR_VFO_B_2M       0x03E6
#define ADR_VFO_B_70CM     0x0402
#define ADR_VFO_B_HF_EXTRA 0x041E
	/* HOME */
#define ADR_HOME_HF        0x043A
#define ADR_HOME_6M        0x0456
#define ADR_HOME_VHF       0x0472
#define ADR_HOME_UHF       0x048E
	/* MEMORY TUNER */
#define ADR_QMB            0x04AA
#define ADR_MTQMB          0x04C6
#define ADR_MTUNE          0x04E2
	/* USER MEMORY CHANNELS (200 channels) */
#define NUM_USER_CHANS 200
#define ADR_USER_CHAN_START 0x0545
#define ADR_CHAN(x) (ADR_USER_CHAN_START+(SIZE_CHAN_STRUCT*((x)-1)))
#define NUM_CHAN(x) ((((x)-ADR_USER_CHAN_START)/SIZE_CHAN_STRUCT)+1)
	/* PMS: Programable Memory Scan */
#define ADR_PMS1L          0x1B25
#define ADR_PMS1U          0x1B41
#define ADR_PMS2L          0x1B5D
#define ADR_PMS2U          0x1B79
#define ADR_PMS3L          0x1B95
#define ADR_PMS3U          0x1BB1
#define ADR_PMS4L          0x1BCD
#define ADR_PMS4U          0x1BE9
#define ADR_PMS5L          0x1C05
#define ADR_PMS5U          0x1C21

	/* 
	 * Used channels bitmasks
	 * 27 Bytes, 8 Channels per Byte
	 * Byte 0 bit 0 = Channel 1
	 */
#define ADR_CHAN_BITMASK  0x050F
#define SIZE_CHAN_BITMASK 25

#define ADR_PMS_BITMASK  0x0528
#define SIZE_PMS_BITMASK 2

#define ADR_XVTR_A_FREQUENCY 0x1CDB
#define ADR_XVTR_B_FREQUENCY 0x1CDF
#define SIZE_XVTR_FREQUENCY  4 //BIG ENDIAN

#define ADR_60M_CH1 0x1D13
#define ADR_60M_CH2 0x1D3B
#define ADR_60M_CH3 0x1D63
#define ADR_60M_CH4 0x1D8B
#define ADR_60M_CH5 0x1DB3

	/* BYTE POSITION IN CHANNEL MEMORY BLOCK */
#define POS_MFb_C_TAG           0
#define POS_MFd_A_RPT           1
#define POS_MFm_A_IPO           2
#define POS_MFm_B_ATT           2
#define POS_MFm_C_NAR           2
#define POS_MFb_B_SKIP          2
#define POS_N06_AM_STEP         3
#define POS_N52_FM_STEP         3
#define POS_N82_SSB_STEP        3
#define POS_MFe_A_ENC           4
#define POS_MFe_B_DEC           4
#define POS_MFe_SELECTIVE_CALL  4
#define POS_N83_TONE_FREQ_TX    6
#define POS_N83_TONE_FREQ_RX    7
#define POS_N33_DCS_CODE_TX     8
#define POS_N33_DCS_CODE_RX     9
#define POS_CLARIFIER_FREQ      10
#define POS_N76_RPT_SHIFT       16
#define POS_N56_MEM_TAG         20

#define MASK_MFb_C_TAG          0b10000000
#define MASK_MFd_A_RPT          0b11000000
#define MASK_MFm_A_IPO          0b00100000
#define MASK_MFm_B_ATT          0b00010000
#define MASK_MFm_C_NAR          0b00001000
#define MASK_MFb_B_SKIP         0b10000000
#define MASK_N06_AM_STEP        0b00111000
#define MASK_N52_FM_STEP        0b00000111
#define MASK_N82_SSB_STEP       0b11000000
#define MASK_MFe_A_ENC          0b00001100
#define MASK_MFe_B_DEC          0b00000011
#define MASK_MFe_SELECTIVE_CALL 0b00011111
#define MASK_N83_TONE_FREQ_TX   0b11111111
#define MASK_N83_TONE_FREQ_RX   0b11111111
#define MASK_N33_DCS_CODE_TX    0b11111111
#define MASK_N33_DCS_CODE_RX    0b11111111

#define SIZE_CLARIFIER_FREQ 2 // BIG ENDIAN
#define SIZE_N76_RPT_SHIFT  4 // BIG ENDIAN
#define SIZE_N56_MEM_TAG    8


#ifdef __cplusplus
}
#endif

#endif /* EEPROM_MAP_H */

