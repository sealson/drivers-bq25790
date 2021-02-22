#ifndef __BQ25790_REG_H
#define __BQ25790_REG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define BQ25790_MINI_SYS_VOLT 0x00

typedef union {
    uint8_t val;
    struct {
        uint8_t vsysmin : 6;
        uint8_t reserved : 2;
    } bit;
} bq25790_vsysmin_reg;

#define BQ25790_REG_CHARGE_VOLT 0x01

typedef union {
    uint16_t val;
    struct {
        uint16_t vreg : 11;
        uint16_t reserved : 5;
    } bit;
} bq25790_vreg_reg;

#define BQ25790_REG_CHARGE_CURRENT 0x03

typedef union {
    uint16_t val;
    struct {
        uint16_t ichg : 9;
        uint16_t reserved : 7;
    } bit;
} bq25790_ichg_reg;

#define BQ25790_REG_VINDPM     0x05

typedef union {
    uint16_t val;
} bq25790_vindpm_reg;

#define BQ25790_REG_IINDPM     0x06

typedef union {
    uint16_t val;
    struct {
        uint16_t iindpm : 9;
        uint16_t reserved : 7;
    } bit;
} bq25790_iindpm_reg;

#define BQ25790_REG_PRECHG_CTRL 0x08

typedef union {
    uint8_t val;
    struct {
        uint8_t iprecgh : 6;
        uint8_t vbatlow : 2;
    } bit;
} bq25790_iprechg_reg;

#define BQ25790_REG_ITERM_CTRL 0x09

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

typedef union {
    uint8_t val;
    struct {
        uint8_t vrechg : 4;
        uint8_t trechg : 2;
        uint8_t cellx : 2;
    } bit;
} bq25790_rechg_reg;

// TODO Reg 0B

#define BQ25790_REG_IOTG_REGULATION 0x0D

typedef union {
    uint8_t val;
    struct {
        uint8_t iotg : 7;
        uint8_t prechg_tmr : 1;
    } bit;
} bq25790_iotg_reg;

#define BQ25790_REG_TIMER_CTRL 0x0E

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

#define BQ25790_REG_CHG_CTRL5 0x14

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

typedef union {
    uint8_t val;
    struct {
        uint8_t bc12_done_stat : 1;
        uint8_t vbus_stat : 4;
        uint8_t chg_stat : 3;
    } bit;
} bq25790_chgstat1_reg;

#define BQ25790_REG_CHG_STATUS2 0x1D

typedef union {
    uint8_t val;
    struct {
        uint8_t vbat_present_stat : 1;
        uint8_t dpdm_stat : 1;
        uint8_t tregs_stat : 1;
        uint8_t reserved : 3;
        uint8_t ico_stat : 2;
    } bit;
} bq25790_chgstat2_reg;

#define BQ25790_REG_CHG_STATUS3 0x1E

#define BQ25790_REG_CHG_STATUS4 0x1F

#define BQ24790_REG_FLT_STATUS0 0x20

#define BQ24790_REG_FLT_STATUS1 0x21

#define BQ24790_REG_CHG_FLAG0 0x22

#define BQ24790_REG_CHG_FLAG1 0x23

#define BQ24790_REG_CHG_FLAG2 0x24

#define BQ24790_REG_CHG_FLAG3 0x25

#define BQ24790_REG_FLT_FLAG0 0x26

#define BQ24790_REG_FLT_FLAG1 0x27

#define BQ25790_REG_CHG_INT_MASK0 0x28

typedef union {
    uint8_t val;
    struct {
        uint8_t vbus_present_mask   : 1;
        uint8_t ac1_present_mask    : 1;
        uint8_t ac2_present_mask    : 1;
        uint8_t pg_mask             : 1;
        uint8_t poorsrc_mask        : 1;
        uint8_t wd_mask             : 1;
        uint8_t vindpm_mask         : 1;
        uint8_t iindpm_mask         : 1;
    } bit;
} bq25790_intmask0_reg;

#define BQ25790_REG_CHG_INT_MASK1 0x29

typedef union {
    uint8_t val;
    struct {
        uint8_t  bc12_done_mask    : 1;
        uint8_t  vbat_present_mask  : 1;
        uint8_t  treg_mask  : 1;
        uint8_t  reserved   : 1;
        uint8_t  vbus_mask  : 1;
        uint8_t  reserved2   : 1;
        uint8_t  ico_mask   : 1;
        uint8_t  chg_mask   : 1;
    } bit;
} bq25790_intmask1_reg;

#define BQ25790_REG_CHG_INT_MASK2 0x2A

#define BQ25790_REG_CHG_INT_MASK3 0x2B

#define BQ25790_REG_FLT_MASK0 0x2C

#define BQ25790_REG_FLT_MASK1 0x2D

#define BQ25790_ADC_CONTROL_REG 0x2E

#define BQ25790_REG_IBUS_ADC_1 0x31

#define BQ25790_REG_IBUS_ADC_0 0x32

#define BQ25790_REG_IBAT_ADC_1 0x33

#define BQ25790_REG_IBAT_ADC_0 0x34

#define BQ25790_REG_VBUS_ADC_1 0x35

#define BQ25790_REG_VBUS_ADC_0 0x36

#define BQ25790_REG_VBAT_ADC_1 0x3B

#define BQ25790_REG_VBAT_ADC_0 0x3C

#define BQ25790_REG_VSYS_ADC_1 0x3D

#define BQ25790_REG_VSYS_ADC_0 0x3E

#define BQ25790_REG_TS_ADC_1 0x3F

#define BQ25790_REG_TS_ADC_0 0x40

#define BQ25790_REG_TDIE_ADC_1 0x41

#define BQ25790_REG_TDIE_ADC_0 0x42

#define BQ25790_REG_PART_NUM    0x48

typedef union {
    uint8_t val;
    struct {
        uint8_t  devrev : 3;
        uint8_t  partnum: 3;
        uint8_t  reserved : 2;
    } bit;
} bq25790_partnum_reg;

#ifdef __cplusplus
}
#endif

#endif // __BQ25790_REG_H
