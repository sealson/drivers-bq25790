#ifndef __BQ25790_REG_H
#define __BQ25790_REG_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BQ25790_REG_MIN_SYS_VOL 0x00
#define BQ25790_VSYSMIN_OFFSET  2500
#define BQ25790_VSYSMIN_LSB     250

typedef union {
    uint8_t val;
    struct {
        uint8_t vsysmin : 6;
        uint8_t reserved : 2;
    } bit;
} bq25790_vsysmin_reg;

#define BQ25790_REG_CHARGE_VOLT_LIM 0x01
#define BQ25790_VREG_OFFSET         0
#define BQ25790_VREG_LSB            10
#define BQ25790_VREG_MIN            3000
#define BQ25790_VREG_MAX            18800

typedef union {
    uint16_t val;
    struct {
        uint16_t vreg : 11;
        uint16_t reserved : 5;
    } bit;
} bq25790_vreg_reg;

#define BQ25790_REG_CHARGE_CURRENT_LIM 0x03
#define BQ25790_IREG_OFFSET            0
#define BQ25790_IREG_LSB               10
#define BQ25790_IREG_MIN               50
#define BQ25790_IREG_MAX               5000

typedef union {
    uint16_t val;
    struct {
        uint16_t ichg : 9;
        uint16_t reserved : 7;
    } bit;
} bq25790_ichg_reg;

#define BQ25790_REG_VINDPM    0x05
#define BQ25790_VINDPM_OFFSET 0
#define BQ25790_VINDPM_LSB    100
#define BQ25790_VINDPM_MIN    3600
#define BQ25790_VINDPM_MAX    22000

typedef union {
    uint16_t val;
} bq25790_vindpm_reg;

#define BQ25790_REG_IINDPM    0x06
#define BQ25790_IINDPM_OFFSET 0
#define BQ25790_IINDPM_LSB    10
#define BQ25790_IINDPM_MIN    100
#define BQ25790_IINDPM_MAX    3300

typedef union {
    uint16_t val;
    struct {
        uint16_t iindpm : 9;
        uint16_t reserved : 7;
    } bit;
} bq25790_iindpm_reg;

#define BQ25790_REG_PRECHG_CTRL 0x08
#define BQ25790_IPRECHG_OFFSET  0
#define BQ25790_IPRECHG_LSB     40
#define BQ25790_IPRECHG_MIN     40
#define BQ25790_IPRECHG_MAX     2000
/*
 * Battery voltage thresholds for the transition from precharge to fast charge
 */
typedef enum {
    VBATLOW_VREG_15_PERCENT = 0,
    VBATLOW_VREG_62_PERCENT,
    VBATLOW_VREG_66_PERCENT,
    VBATLOW_VREG_71_PERCENT /* default */
} bq25790_vbatlow_t;

typedef union {
    uint8_t val;
    struct {
        uint8_t iprecgh : 6;
        uint8_t vbatlow : 2;
    } bit;
} bq25790_iprechg_reg;

#define BQ25790_REG_ITERM_CTRL 0x09
#define BQ25790_ITERM_OFFSET   0
#define BQ25790_ITERM_LSB      40
#define BQ25790_ITERM_MIN      40
#define BQ25790_ITERM_MAX      1000

typedef union {
    uint8_t val;
    struct {
        uint8_t iterm : 5;
        uint8_t reserved : 1;
        uint8_t regrst : 1;
        uint8_t reserved2 : 1;
    } bit;
} bq25790_iterm_reg;

#define BQ25790_REG_RECHAEGE_CTRL 0x0A
#define BQ25790_VRECHG_OFFSET     50
#define BQ25790_VRECHG_LSB        50
#define BQ25790_VRECHG_MIN        50
#define BQ25790_VRECHG_MAX        800
/*
 * The charger reads the PROG pin resistance to determine the batterycell count
 * and update this CELL bits accordingly
 */
typedef enum {
    CELLX_1S = 0, /* no default value*/
    CELLX_2S,
    CELLX_3S,
    CELLX_4S
} bq24790_cellx_t;

/*
 * Battery recharge deglich time
 */
typedef enum {
    TRECHG_64MS = 0,
    TRECHG_256MS,
    TRECHG_1024MS, /* default */
    TRECHG_2048MS
} bq25790_trechg_t;

typedef union {
    uint8_t val;
    struct {
        uint8_t vrechg : 4;
        uint8_t trechg : 2;
        uint8_t cellx : 2;
    } bit;
} bq25790_rechg_reg;

#define BQ25790_REG_VOTG_REGULATION 0x0B
#define BQ25790_VOTG_OFFSET         2800
#define BQ25790_VOTG_LSB            10
#define BQ25790_VOTG_MIN            2800
#define BQ25790_VOTG_MAX            22000

typedef union {
    uint16_t val;
    struct {
        uint16_t votg : 11;
        uint16_t reserved : 5;
    } bit;
} bq25790_votg_reg;

#define BQ25790_REG_IOTG_REGULATION 0x0D
#define BQ25790_IOTG_OFFSET         0
#define BQ25790_IOTG_LSB            40
#define BQ25790_IOTG_MIN            120
#define BQ25790_IOTG_MAX            3320

typedef enum {
    PRECHG_TMR_2HR = 0, /* default */
    PRECHG_TMR_0HR5
} bq25790_prechg_tmr_t;

typedef union {
    uint8_t val;
    struct {
        uint8_t iotg : 7;
        uint8_t prechg_tmr : 1;
    } bit;
} bq25790_iotg_reg;

#define BQ25790_REG_TIMER_CTRL 0x0E

typedef enum {
    CHG_TMR_5HRS = 0,
    CHG_TMR_8HRS,
    CHG_TMR_12HRS, /* default */
    CHG_TMR_24HRS
} bq25790_chg_tmr_r;

typedef enum {
    TOPOFF_TMR_DIS = 0, /* default */
    TOPOFF_TMR_15MIN,
    TOPOFF_TMR_30MIN,
    TOPOFF_TMR_45MIN,
} bq25790_topoff_tmr_t;

typedef union {
    uint8_t val;
    struct {
        uint8_t tmr2x_en : 1;
        uint8_t chg_tmr : 2;
        uint8_t en_chg_tmr : 1;
        uint8_t en_prechg_tmr : 1;
        uint8_t en_trichg_tmr : 1;
        uint8_t topoff_tmr_1 : 1;
    } bit;
} bq25790_timctrl_reg;

#define BQ25790_REG_CHG_CTRL0 0x0F

typedef union {
    uint8_t val;
    struct {
        uint8_t reserved : 1;
        uint8_t en_term : 1;
        uint8_t en_hiz : 1;
        uint8_t force_ico : 1;
        uint8_t en_ico : 1;
        uint8_t en_chg : 1;
        uint8_t force_ibatdis : 1;
        uint8_t en_auto_ibatdis : 1;
    } bit;
} bq25790_chgctrl0_reg;

#define BQ25790_REG_CHG_CTRL1 0x10

typedef enum {
    WDOG_DIS = 0,
    WDOG_0S5,
    WDOG_1S0,
    WDOG_2S0,
    WDOG_20S,
    WDOG_40S, /* default */
    WDOG_80S,
    WDOG_160S
} bq25790_wdog_t;

typedef enum {
    VACOVP_26V = 0,
    VACOVP_22V,
    VACOVP_12V,
    VACOVP_7V, /* default */
} bq25790_vacovp_t;

typedef union {
    uint8_t val;
    struct {
        uint8_t wdog : 3;
        uint8_t wdog_rst : 1;
        uint8_t vac_ovp : 2;
        uint8_t reserved : 2;
    } bit;
} bq25790_chgctrl1_reg;

#define BQ25790_REG_CHG_CTRL2 0x11

typedef enum {
    SDRV_IDLE = 0, /* default */
    SDRV_SHUTDOWN,
    SDRV_SHIP,
    SDRV_SYS_PWR_RST
} bq25790_sdrv_t;

typedef union {
    uint8_t val;
    struct {
        uint8_t sdrv_dly : 1;
        uint8_t sdrv_ctrl : 2;
        uint8_t hvdcp_en : 1;
        uint8_t en_9v : 1;
        uint8_t en_12v : 1;
        uint8_t auto_indet_en : 1;
        uint8_t force_indet : 1;
    } bit;
} bq25790_chgctrl2_reg;

#define BQ25790_REG_CHG_CTRL3 0x12

typedef union {
    uint8_t val;
    struct {
        uint8_t dis_fwd_ooa : 1;
        uint8_t dis_otg_ooa : 1;
        uint8_t dis_ldo : 1;
        uint8_t wkup_dly : 1;
        uint8_t pfm_fwd_dis : 1;
        uint8_t pfm_otg_dis : 1;
        uint8_t en_otg : 1;
        uint8_t dis_acdrv : 1;
    } bit;
} bq25790_chgctrl3_reg;

#define BQ25790_REG_CHG_CTRL4 0x13

typedef union {
    uint8_t val;
    struct {
        uint8_t en_ibus_ocp : 1;
        uint8_t force_vindpm_det : 1;
        uint8_t dis_votg_uvp : 1;
        uint8_t dis_vsys_short : 1;
        uint8_t dis_stat : 1;
        uint8_t pwm_freq : 1;
        uint8_t en_acdrv1 : 1;
        uint8_t en_acdrv2 : 1;
    } bit;
} bq25790_chgctrl4_reg;

#define BQ25790_REG_CHG_CTRL5 0x14

typedef enum {
    IBAT_3A = 0,
    IBAT_4A,
    IBAT_5A, /* default */
    IBAT_DIS
} bq25790_ibat_t;

typedef union {
    uint8_t val;
    struct {
        uint8_t en_batoc : 1;
        uint8_t en_extilim : 1;
        uint8_t en_iindpm : 1;
        uint8_t ibat_reg_ : 2;
        uint8_t en_ibat : 1;
        uint8_t reserved : 1;
        uint8_t sfet_present : 1;
    } bit;
} bq25790_chgctrl5_reg;

#define BQ25790_REG_RESERVED 0x15

#define BQ25790_REG_TEMP_CTRL 0x16

typedef enum {
    TSHUT_150DEG = 0, /* default */
    TSHUT_130DEG,
    TSHUT_120DEG,
    TSHUT_85DEG
} bq25790_tshut_t;

typedef enum {
    TREG_60DEG = 0,
    TREG_80DEG,
    TREG_100DEG,
    TREG_120DEG /* default */
} bq25790_treg_t;

typedef union {
    uint8_t val;
    struct {
        uint8_t reserved : 1;
        uint8_t vac2_pd_en : 1;
        uint8_t vac1_pd_en : 1;
        uint8_t vbus_pd_en : 1;
        uint8_t tshut : 2;
        uint8_t treg : 2;
    } bit;
} bq25790_tempctrl_reg;

#define BQ25790_REG_NTC_CTRL0 0x17

typedef enum {
    JEITA_VSET_CHG_SUSPEND = 0,
    JEITA_VSET_SUBTRACT_800MV,
    JEITA_VSET_SUBTRACT_600MV,
    JEITA_VSET_SUBTRACT_400MV, /* default */
    JEITA_VSET_SUBTRACT_300MV,
    JEITA_VSET_SUBTRACT_200MV,
    JEITA_VSET_SUBTRACT_100MV,
    JEITA_VSET_UNCHANGED
} bq25790_jeita_vset_t;

typedef enum {
    JEITA_ISETH_CHG_SUSPEND = 0,
    JEITA_ISETH_20_PERCENT,
    JEITA_ISETH_40_PERCENT,
    JEITA_ISETH_UNCHANGED,
} bq25790_jeita_iseth_t;

typedef enum {
    JEITA_ISETC_CHG_SUSPEND = 0,
    JEITA_ISETC_20_PERCENT,
    JEITA_ISETC_40_PERCENT,
    JEITA_ISETC_UNCHANGED,
} bq25790_jeita_isetc_t;

typedef union {
    uint8_t val;
    struct {
        uint8_t reserved : 1;
        uint8_t jeita_isetc : 2;
        uint8_t jeita_iseth : 2;
        uint8_t jeita_vset : 3;
    } bit;
} bq25790_ntcctrl0_reg;

#define BQ25790_REG_NTC_CTRL1 0x18

typedef enum {
    TSCOOL_5DEG = 0,
    TSCOOL_10DEG, /* default */
    TSCOOL_15DEG,
    TSCOOL_20DEG,

} bq25790_tscool_t;

typedef enum {
    TSWARM_40DEG = 0,
    TSWARM_45DEG, /* default */
    TSWARM_50DEG,
    TSWARM_55DEG,

} bq25790_tswarm_t;

typedef enum {
    BHOT_55DEG = 0,
    BHOT_60DEG, /* default */
    BHOT_65DEG,
    BHOT_DIS
} bq25790_bhot_t;

typedef enum {
    BCOLD_MINUS_10DEG = 0, /* default */
    BCOLD_MINUS_20DEG
} bq25790_bcold_t;

typedef union {
    uint8_t val;
    struct {
        uint8_t ts_ignore : 1;
        uint8_t bcold : 1;
        uint8_t bhot : 2;
        uint8_t ts_warm : 2;
        uint8_t ts_cool : 2;
    } bit;
} bq25790_ntcctrl1_reg;

#define BQ25790_REG_ICO_CUR_LIM 0x19
typedef union {
    uint16_t val;
    struct {
        uint16_t ico_ilim : 9;
        uint16_t reserved : 7;
    } bit;
} bq25790_icoilim_reg;

#define BQ25790_REG_CHG_STATUS0 0x1B

typedef union {
    uint8_t val;
    struct {
        uint8_t vbus_present_stat : 1;
        uint8_t ac1_present_stat : 1;
        uint8_t ac2_present_stat : 1;
        uint8_t pg_stat : 1;
        uint8_t poorsrc_stat : 1;
        uint8_t wd_stat : 1;
        uint8_t vindpm_stat : 1;
        uint8_t iindpm_stat : 1;
    } bit;
} bq25790_chgstat0_reg;

#define BQ25790_REG_CHG_STATUS1 0x1C

typedef enum {
    CHGSTAT_NOT_CHARGING     = 0,
    CHGSTAT_TRICKLE          = 0x1,
    CHGSTAT_PRE              = 0x2,
    CHGSTAT_FAST             = 0x3,
    CHGSTAT_TAPER            = 0x4,
    CHGSTAT_TOPOFF           = 0x6,
    CHGSTAT_TERMINATION_DONE = 0x7
} bq25790_chgstat_t;

typedef enum {
    VBUSSTAT_NOINPUT_OR_BHOT_BCOLD = 0,
    VBUSSTAT_USBSDP                = 0x1,
    VBUSSTAT_USBCDP                = 0x2,
    VBUSSTAT_USBDCP                = 0x3,
    VBUSSTAT_ADJ_DCP               = 0x4,
    VBUSSTAT_UNKNOWN               = 0x5,
    VBUSSTAT_NON_STANDARD          = 0x6,
    VBUSSTAT_OTG                   = 0x7,
    VBUSSTAT_NOT_QUALIFIED         = 0x8,
    VBUSSTAT_POWERED_FROM_VBUS     = 0xB
} bq25790_vbusstat_t;

typedef union {
    uint8_t val;
    struct {
        uint8_t bc12_done_stat : 1;
        uint8_t vbus_stat : 4;
        uint8_t chg_stat : 3;
    } bit;
} bq25790_chgstat1_reg;

#define BQ25790_REG_CHG_STATUS2 0x1D

typedef enum {
    ICOSTAT_DISABLED = 0, /* no default */
    ICOSTAT_IN_PROGRESS,
    ICOSTAT_MAX_DETECTED
} bq25790_ico_stat_t;

typedef union {
    uint8_t val;
    struct {
        uint8_t vbat_present_stat : 1;
        uint8_t dpdm_stat : 1;
        uint8_t treg_stat : 1;
        uint8_t reserved : 3;
        uint8_t ico_stat : 2;
    } bit;
} bq25790_chgstat2_reg;

#define BQ25790_REG_CHG_STATUS3 0x1E

typedef union {
    uint8_t val;
    struct {
        uint8_t reserved : 1;
        uint8_t prechg_tmr_stat : 1;
        uint8_t trichg_tmr_stat : 1;
        uint8_t chg_tmr_stat : 1;
        uint8_t vsys_stat : 1;
        uint8_t adc_done_stat : 1;
        uint8_t acrb1_stat : 1;
        uint8_t acrb2_stat : 1;
    } bit;
} bq25790_chgstat3_reg;

#define BQ25790_REG_CHG_STATUS4 0x1F

typedef union {
    uint8_t val;
    struct {
        uint8_t ts_hot_stat : 1;
        uint8_t ts_warm_stat : 1;
        uint8_t ts_cool_stat : 1;
        uint8_t ts_cold_stat : 1;
        uint8_t vbat_otg_low_stat : 1;
        uint8_t reserved : 3;
    } bit;
} bq25790_chgstat4_reg;

#define BQ24790_REG_FLT_STATUS0 0x20

typedef union {
    uint8_t val;
    struct {
        uint8_t vac1_ovp_stat : 1;
        uint8_t vac2_ovp_stat : 1;
        uint8_t conv_ocp_stat : 1;
        uint8_t ibat_ocp_stat : 1;
        uint8_t ibus_ocp_stat : 1;
        uint8_t vbat_ovp_stat : 1;
        uint8_t vbus_ovp_stat : 1;
        uint8_t ibat_reg_stat : 1;
    } bit;
} bq25790_fltstat0_reg;

#define BQ24790_REG_FLT_STATUS1 0x21

typedef union {
    uint8_t val;
    struct {
        uint8_t reserved : 2;
        uint8_t tshut_stat : 1;
        uint8_t reserved2 : 1;
        uint8_t otg_uvp_stat : 1;
        uint8_t otg_ovp_stat : 1;
        uint8_t vsys_ovp_stat : 1;
        uint8_t vsys_short_stat : 1;
    } bit;
} bq25790_fltstat1_reg;

#define BQ24790_REG_CHG_FLAG0 0x22

typedef union {
    uint8_t val;
    struct {
        uint8_t vbus_present_flag : 1;
        uint8_t ac1_present_flag : 1;
        uint8_t ac2_present_flag : 1;
        uint8_t pg_flag : 1;
        uint8_t poorsrc_flag : 1;
        uint8_t wd_flag : 1;
        uint8_t vindpm_flag : 1;
        uint8_t iindpm_flag : 1;
    } bit;
} bq25790_chgflag0_reg;

#define BQ24790_REG_CHG_FLAG1 0x23

typedef union {
    uint8_t val;
    struct {
        uint8_t bc12_done_flag : 1;
        uint8_t vbat_present_flag : 1;
        uint8_t treg_flag : 1;
        uint8_t reserved : 1;
        uint8_t vbus_flag : 1;
        uint8_t reserved2 : 1;
        uint8_t ico_flag : 1;
        uint8_t chg_flag : 1;
    } bit;
} bq25790_chgflag1_reg;

#define BQ24790_REG_CHG_FLAG2 0x24

typedef union {
    uint8_t val;
    struct {
        uint8_t topoff_tmr_flag : 1;
        uint8_t prechg_tmr_flag : 1;
        uint8_t trichg_tmr_flag : 1;
        uint8_t chg_tmr_flag : 1;
        uint8_t vsys_flag : 1;
        uint8_t adc_done_flag : 1;
        uint8_t dpdm_done_flag : 1;
        uint8_t reserved : 1;
    } bit;
} bq25790_chgflag2_reg;

#define BQ24790_REG_CHG_FLAG3 0x25

typedef union {
    uint8_t val;
    struct {
        uint8_t ts_hot_flag : 1;
        uint8_t ts_warm_flag : 1;
        uint8_t ts_cool_flag : 1;
        uint8_t ts_cold_flag : 1;
        uint8_t vbatotg_low_flag : 1;
        uint8_t reserved : 3;
    } bit;
} bq25790_chgflag3_reg;

#define BQ24790_REG_FLT_FLAG0 0x26

typedef union {
    uint8_t val;
    struct {
        uint8_t vac1_ovp_flag : 1;
        uint8_t vac2_ovp_flag : 1;
        uint8_t conv_ocp_flag : 1;
        uint8_t ibat_ocp_flag : 1;
        uint8_t ibus_ocp_flag : 1;
        uint8_t vbat_ovp_flag : 1;
        uint8_t vbus_ovp_flag : 1;
        uint8_t ibat_reg_flag : 1;
    } bit;
} bq25790_fltflag0_reg;

#define BQ24790_REG_FLT_FLAG1 0x27

typedef union {
    uint8_t val;
    struct {
        uint8_t reserved : 2;
        uint8_t tshut_flag : 1;
        uint8_t reserved2 : 1;
        uint8_t otg_uvp_flag : 1;
        uint8_t otg_ovp_flag : 1;
        uint8_t vsys_ovp_flag : 1;
        uint8_t vsys_short_flag : 1;
    } bit;
} bq25790_fltflag1_reg;

#define BQ25790_REG_CHG_INT_MASK0 0x28

typedef union {
    uint8_t val;
    struct {
        uint8_t vbus_present_mask : 1;
        uint8_t ac1_present_mask : 1;
        uint8_t ac2_present_mask : 1;
        uint8_t pg_mask : 1;
        uint8_t poorsrc_mask : 1;
        uint8_t wd_mask : 1;
        uint8_t vindpm_mask : 1;
        uint8_t iindpm_mask : 1;
    } bit;
} bq25790_intmask0_reg;

#define BQ25790_REG_CHG_INT_MASK1 0x29

typedef union {
    uint8_t val;
    struct {
        uint8_t bc12_done_mask : 1;
        uint8_t vbat_present_mask : 1;
        uint8_t treg_mask : 1;
        uint8_t reserved : 1;
        uint8_t vbus_mask : 1;
        uint8_t reserved2 : 1;
        uint8_t ico_mask : 1;
        uint8_t chg_mask : 1;
    } bit;
} bq25790_intmask1_reg;

#define BQ25790_REG_CHG_INT_MASK2 0x2A

typedef union {
    uint8_t val;
    struct {
        uint8_t topoff_tmr_mask : 1;
        uint8_t prechg_tmr_mask : 1;
        uint8_t trichg_tmr_mask : 1;
        uint8_t chg_tmr_mask : 1;
        uint8_t vsys_mask : 1;
        uint8_t adc_done_mask : 1;
        uint8_t dpdm_done_mask : 1;
        uint8_t reserved : 1;
    } bit;
} bq25790_intmask2_reg;

#define BQ25790_REG_CHG_INT_MASK3 0x2B

typedef union {
    uint8_t val;
    struct {
        uint8_t ts_hot_mask : 1;
        uint8_t ts_warm_mask : 1;
        uint8_t ts_cool_mask : 1;
        uint8_t ts_cold_mask : 1;
        uint8_t vbatotg_low_mask : 1;
        uint8_t reserved : 3;
    } bit;
} bq25790_intmask3_reg;

#define BQ25790_REG_FLT_MASK0 0x2C

typedef union {
    uint8_t val;
    struct {
        uint8_t vac1_ovp_mask : 1;
        uint8_t vac2_ovp_mask : 1;
        uint8_t conv_ocp_mask : 1;
        uint8_t ibat_ocp_mask : 1;
        uint8_t ibus_ocp_mask : 1;
        uint8_t vbat_ovp_mask : 1;
        uint8_t vbus_ovp_mask : 1;
        uint8_t ibat_reg_mask : 1;
    } bit;
} bq25790_fltmask0_reg;

#define BQ25790_REG_FLT_MASK1 0x2D

typedef union {
    uint8_t val;
    struct {
        uint8_t reserved : 2;
        uint8_t tshut_mask : 1;
        uint8_t reserved2 : 1;
        uint8_t otg_uvp_mask : 1;
        uint8_t otg_ovp_mask : 1;
        uint8_t vsys_ovp_mask : 1;
        uint8_t vsys_short_mask : 1;
    } bit;
} bq25790_fltmask1_reg;

#define BQ25790_REG_ADC_CONTROL 0x2E

typedef enum {
    ADC_SAMPLE_15BIT = 0,
    ADC_SAMPLE_14BIT,
    ADC_SAMPLE_13BIT,
    ADC_SAMPLE_12BIT /* default */
} bq25790_adc_sample_t;

typedef union {
    uint8_t val;
    struct {
        uint8_t reserved : 2;
        uint8_t adc_avg_init : 1;
        uint8_t adc_avg : 1;
        uint8_t adc_sample : 2;
        uint8_t adc_rate : 1;
        uint8_t adc_en : 1;
    } bit;
} bq25790_adcctrl_reg;

#define BQ25790_REG_FUNC_DIS0 0x2F

typedef union {
    uint8_t val;
    struct {
        uint8_t reserved : 1;
        uint8_t tdie_adc_dis : 1;
        uint8_t ts_adc_dis : 1;
        uint8_t vsys_adc_dis : 1;
        uint8_t vbat_adc_dis : 1;
        uint8_t vbus_adc_dis : 1;
        uint8_t ibat_adc_dis : 1;
        uint8_t ibus_adc_dis : 1;
    } bit;
} bq25790_adcfuncdis0_reg;

#define BQ25790_REG_FUNC_DIS1 0x2F

typedef union {
    uint8_t val;
    struct {
        uint8_t reserved : 4;
        uint8_t vac1_adc_dis : 1;
        uint8_t vac2_adc_dis : 1;
        uint8_t dm_adc_dis : 1;
        uint8_t dp_adc_dis : 1;
    } bit;
} bq25790_adcfuncdis1_reg;

#define BQ25790_REG_IBUS_ADC 0x31

typedef union {
    uint16_t val;
} bq25790_ibus_adc_reg;

#define BQ25790_REG_IBAT_ADC 0x33

typedef union {
    uint16_t val;
} bq25790_ibat_adc_reg;

#define BQ25790_REG_VBUS_ADC 0x35

typedef union {
    uint16_t val;
} bq25790_vbus_adc_reg;

#define BQ25790_REG_VAC1_ADC 0x37

typedef union {
    uint16_t val;
} bq25790_vac1_adc_reg;

#define BQ25790_REG_VAC2_ADC 0x39

typedef union {
    uint16_t val;
} bq25790_vac2_adc_reg;

#define BQ25790_REG_VBAT_ADC 0x3B

typedef union {
    uint16_t val;
} bq25790_vbat_adc_reg;

#define BQ25790_REG_VSYS_ADC 0x3D

typedef union {
    uint16_t val;
} bq25790_vsys_adc_reg;

#define BQ25790_REG_TS_ADC 0x3F
#define BQ25790_TS_LSB     0.0976563f

typedef union {
    uint16_t val;
} bq25790_ts_adc_reg;

#define BQ25790_REG_TDIE_ADC 0x41
#define BQ25790_TS_LSB 0.5f

typedef union {
    uint16_t val;
} bq25790_tdie_adc_reg;

#define BQ25790_REG_DP_ADC 0x43

typedef union {
    uint16_t val;
} bq25790_dp_adc_reg;

#define BQ25790_REG_DM_ADC 0x45

typedef union {
    uint16_t val;
} bq25790_dm_adc_reg;

#define BQ25790_REG_DPDM_DRIVER 0x47

typedef enum {
    DPDM_DAC_HIZ = 0,  /* default */
    DPDM_DAC_0V,
    DPDM_DAC_0V6,
    DPDM_DAC_1V2,
    DPDM_DAC_2V0,
    DPDM_DAC_2V7,
    DPDM_DAC_3V3,
    DPDM_DAC_SHORT
} bq25790_dpdm_dac;

typedef union {
    uint8_t val;
    struct {
        uint8_t reserved : 2;
        uint8_t dm_dac : 3;
        uint8_t dp_dac : 3;
    } bit;
} bq25790_dpdm_driver_reg;

#define BQ25790_REG_PART_NUM 0x48

typedef union {
    uint8_t val;
    struct {
        uint8_t devrev : 3;
        uint8_t partnum : 3;
        uint8_t reserved : 2;
    } bit;
} bq25790_partnum_reg;

#ifdef __cplusplus
}
#endif

#endif // __BQ25790_REG_H
