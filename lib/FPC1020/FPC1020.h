#pragma once

enum fpc1020_reg
{
    /* --- Common registers --- */
    FPC102X_REG_FPC_STATUS = 20,                /* RO, 1 bytes  */
    FPC102X_REG_READ_INTERRUPT = 24,            /* RO, 1 byte   */
    FPC102X_REG_READ_INTERRUPT_WITH_CLEAR = 28, /* RO, 1 byte   */
    FPC102X_REG_FINGER_PRESENT_QUERY = 32,      /* Checks if a finger is present. */
    FPC102X_REG_WAIT_FOR_FINGER = 36,           /* Continue to check for a finger until a finger is present. */
    FPC102X_REG_READ_ERROR_WITH_CLEAR = 56,     /* RO, 1 byte   */
    FPC102X_REG_MISO_EDGE_RIS_EN = 64,          /* WO, 1 byte   */
    FPC102X_REG_FPC_CONFIG = 68,                /* RW, 1 byte   */
    FPC102X_REG_IMG_SMPL_SETUP = 76,            /* RW, 3 bytes  */
    FPC102X_REG_CLOCK_CONFIG = 80,              /* RW, 1 byte   */
    FPC102X_REG_IMG_CAPT_SIZE = 84,             /* RW, 4 bytes  */
    FPC102X_REG_IMAGE_SETUP = 92,               /* RW, 1 byte   */
    FPC102X_REG_ADC_TEST_CTRL = 96,             /* RW, 1 byte   */
    FPC102X_REG_IMG_RD = 100,                   /* RW, 1 byte   */
    FPC102X_REG_SAMPLE_PX_DLY = 104,            /* RW, 8 bytes  */
    FPC102X_REG_PXL_RST_DLY = 108,              /* RW, 1 byte   */
    FPC102X_REG_TST_COL_PATTERN_EN = 120,       /* RW, 2 bytes  */
    FPC102X_REG_CLK_BIST_RESULT = 124,          /* RW, 4 bytes  */
    FPC102X_REG_ADC_WEIGHT_SETUP = 132,         /* RW, 1 byte   */
    FPC102X_REG_ANA_TEST_MUX = 136,             /* RW, 4 bytes  */
    FPC102X_REG_FINGER_DRIVE_CONF = 140,        /* RW, 1 byte   */
    FPC102X_REG_FINGER_DRIVE_DLY = 144,         /* RW, 1 byte   */
    FPC102X_REG_OSC_TRIM = 148,                 /* RW, 2 bytes  */
    FPC102X_REG_ADC_WEIGHT_TABLE = 152,         /* RW, 10 bytes */
    FPC102X_REG_ADC_SETUP = 156,                /* RW, 5 bytes  */
    FPC102X_REG_ADC_SHIFT_GAIN = 160,           /* RW, 2 bytes  */
    FPC102X_REG_BIAS_TRIM = 164,                /* RW, 1 byte   */
    FPC102X_REG_PXL_CTRL = 168,                 /* RW, 2 bytes  */
    FPC102X_REG_FPC_DEBUG = 208,                /* RO, 1 bytes  */
    FPC102X_REG_FINGER_PRESENT_STATUS = 212,    /* RO, 2 bytes  */
    FPC102X_REG_HWID = 252,                     /* RO, 2 bytes  */
    FPC1020_REG_FNGR_DET_THRES = 216,           /* RW, 1 byte   */
    FPC1020_REG_FNGR_DET_CNTR = 220,            /* RW, 2 bytes  */
};

class FPC1020
{
public:
    void init();

    void reset();

    void setup();

    uint8_t interrupt(bool clear = false);

    uint8_t error();

    uint16_t hardware_id();

    uint16_t finger_present_status();

public:
    void command(fpc1020_reg reg);

    uint8_t transmit8(fpc1020_reg reg, uint8_t val);
    uint16_t transmit16(fpc1020_reg reg, uint16_t val);
    uint32_t transmit32(fpc1020_reg reg, uint32_t val);
    uint64_t transmit64(fpc1020_reg reg, uint64_t val);

private:
    void setup_rev3();
};