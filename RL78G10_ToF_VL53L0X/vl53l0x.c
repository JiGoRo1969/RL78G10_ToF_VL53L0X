
#include	<string.h>
#include	"r_cg_macrodriver.h"
#include	"r_cg_userdefine.h"
#include	"r_cg_iica.h"
#include	"vl53l0x.h"

// #define 	D_USE_I2C_CONST_TABLE

#define		D_IIC_WAITLOOPCOUNT		(10000)

static	uint32_t	measurement_timing_budget_us;
static	uint8_t		bufi2c[10];
static	uint8_t		address = ADDRESS_DEFAULT;
static	uint8_t		stop_variable;

static	uint16_t	decodeTimeout(uint16_t value);
static	uint16_t	encodeTimeout(uint32_t timeout_mclks);
static	uint32_t	timeoutMclksToMicroseconds(uint16_t timeout_period_mclks, uint8_t vcsel_period_pclks);
static	uint32_t	timeoutMicrosecondsToMclks(uint32_t timeout_period_us, uint8_t vcsel_period_pclks);
#ifdef	D_USE_I2C_CONST_TABLE
static	void		writeRegs(const st_i2c *a, uint8_t n);
#endif	// D_USE_I2C_CONST_TABLE
static	void		writeReg(uint8_t reg, uint8_t value);
static	void		writeReg16Bit(uint8_t reg, uint16_t value);
static	uint8_t		readReg(uint8_t reg);
static	uint16_t	readReg16Bit(uint8_t reg);
static	void		writeMulti(uint8_t reg, uint8_t const * src, uint8_t count);
static	void		readMulti(uint8_t reg, uint8_t * dst, uint8_t count);
static	bool		getSpadInfo(uint8_t * count, bool * type_is_aperture);
static	void		getSequenceStepEnables(SequenceStepEnables * enables);
static	void		getSequenceStepTimeouts(SequenceStepEnables const * enables, SequenceStepTimeouts * timeouts);
static	bool		performSingleRefCalibration(uint8_t vhv_init_byte);

#ifdef	D_USE_I2C_CONST_TABLE

const st_i2c	init_1[] =
{
	{0x88, 0x00},
	{0x80, 0x01},
	{0xFF, 0x01},
	{0x00, 0x00}
};

const st_i2c	init_2[] =
{
	{0x00, 0x01},
	{0xFF, 0x00},
	{0x80, 0x00}
};

const st_i2c	init_3[] =
{
	{0xFF, 0x01},
	{DYNAMIC_SPAD_REF_EN_START_OFFSET, 0x00},
	{DYNAMIC_SPAD_NUM_REQUESTED_REF_SPAD, 0x2C},
	{0xFF, 0x00},
	{GLOBAL_CONFIG_REF_EN_START_SELECT, 0xB4}
};

const st_i2c	init_4[] =
{
	{0xFF, 0x01}, {0x00, 0x00}, {0xFF, 0x00}, {0x09, 0x00}, {0x10, 0x00},
	{0x11, 0x00}, {0x24, 0x01}, {0x25, 0xFF}, {0x75, 0x00}, {0xFF, 0x01},
	{0x4E, 0x2C}, {0x48, 0x00}, {0x30, 0x20}, {0xFF, 0x00}, {0x30, 0x09},
	{0x54, 0x00}, {0x31, 0x04}, {0x32, 0x03}, {0x40, 0x83}, {0x46, 0x25},
	{0x60, 0x00}, {0x27, 0x00}, {0x50, 0x06}, {0x51, 0x00}, {0x52, 0x96},
	{0x56, 0x08}, {0x57, 0x30}, {0x61, 0x00}, {0x62, 0x00}, {0x64, 0x00},
	{0x65, 0x00}, {0x66, 0xA0}, {0xFF, 0x01}, {0x22, 0x32}, {0x47, 0x14},
	{0x49, 0xFF}, {0x4A, 0x00}, {0xFF, 0x00}, {0x7A, 0x0A}, {0x7B, 0x00},
	{0x78, 0x21}, {0xFF, 0x01}, {0x23, 0x34}, {0x42, 0x00}, {0x44, 0xFF},
	{0x45, 0x26}, {0x46, 0x05}, {0x40, 0x40}, {0x0E, 0x06}, {0x20, 0x1A},
	{0x43, 0x40}, {0xFF, 0x00}, {0x34, 0x03}, {0x35, 0x44}, {0xFF, 0x01},
	{0x31, 0x04}, {0x4B, 0x09}, {0x4C, 0x05}, {0x4D, 0x04}, {0xFF, 0x00},
	{0x44, 0x00}, {0x45, 0x20}, {0x47, 0x08}, {0x48, 0x28}, {0x67, 0x00},
	{0x70, 0x04}, {0x71, 0x01}, {0x72, 0xFE}, {0x76, 0x00}, {0x77, 0x00},
	{0xFF, 0x01}, {0x0D, 0x01}, {0xFF, 0x00}, {0x80, 0x01}, {0x01, 0xF8},
	{0xFF, 0x01}, {0x8E, 0x01}, {0x00, 0x01}, {0xFF, 0x00}, {0x80, 0x00},
	{SYSTEM_INTERRUPT_CONFIG_GPIO, 0x04}
};

const st_i2c	init_11[] =
{
	{FINAL_RANGE_CONFIG_VALID_PHASE_HIGH, 0x10},
	{FINAL_RANGE_CONFIG_VALID_PHASE_LOW,  0x08},
	{GLOBAL_CONFIG_VCSEL_WIDTH, 0x02},
	{ALGO_PHASECAL_CONFIG_TIMEOUT, 0x0C},
	{0xFF, 0x01},
	{ALGO_PHASECAL_LIM, 0x30},
	{0xFF, 0x00}
};

const st_i2c	init_12[] =
{
	{FINAL_RANGE_CONFIG_VALID_PHASE_HIGH, 0x28},
	{FINAL_RANGE_CONFIG_VALID_PHASE_LOW,  0x08},
	{GLOBAL_CONFIG_VCSEL_WIDTH, 0x03},
	{ALGO_PHASECAL_CONFIG_TIMEOUT, 0x09},
	{0xFF, 0x01},
	{ALGO_PHASECAL_LIM, 0x20},
	{0xFF, 0x00}
};

const st_i2c	init_13[] =
{
	{FINAL_RANGE_CONFIG_VALID_PHASE_HIGH, 0x38},
	{FINAL_RANGE_CONFIG_VALID_PHASE_LOW,  0x08},
	{GLOBAL_CONFIG_VCSEL_WIDTH, 0x03},
	{ALGO_PHASECAL_CONFIG_TIMEOUT, 0x08},
	{0xFF, 0x01},
	{ALGO_PHASECAL_LIM, 0x20},
	{0xFF, 0x00}
};

const st_i2c	init_14[] =
{
	{FINAL_RANGE_CONFIG_VALID_PHASE_HIGH, 0x48},
	{FINAL_RANGE_CONFIG_VALID_PHASE_LOW,  0x08},
	{GLOBAL_CONFIG_VCSEL_WIDTH, 0x03},
	{ALGO_PHASECAL_CONFIG_TIMEOUT, 0x07},
	{0xFF, 0x01},
	{ALGO_PHASECAL_LIM, 0x20},
	{0xFF, 0x00}
};

const st_i2c	init_21[] =
{
	{0x80, 0x01},
	{0xFF, 0x01},
	{0x00, 0x00}
};

const st_i2c	init_22[] =
{
	{0x00, 0x01},
	{0xFF, 0x00},
	{0x80, 0x00}
};

const st_i2c	init_23[] =
{
	{SYSRANGE_START, 0x01},
	{0xFF, 0x01},
	{0x00, 0x00},
	{0x91, 0x00},
	{0x00, 0x01},
	{0xFF, 0x00}
};

const st_i2c	init_24[] =
{
	{0x80, 0x01},
	{0xFF, 0x01},
	{0x00, 0x00}
};

const st_i2c	init_25[] =
{
	{0x00, 0x01},
	{0xFF, 0x00},
	{0x80, 0x00},
	{SYSRANGE_START, 0x01}
};

#endif	// D_USE_I2C_CONST_TABLE

static
uint16_t	decodeTimeout(uint16_t reg_val)
{
	return (uint16_t)((reg_val & 0x00FF) << (uint16_t)((reg_val & 0xFF00) >> 8)) + 1;
}

static
uint16_t	encodeTimeout(uint32_t timeout_mclks)
{
	uint32_t	ls_byte = 0;
	uint16_t	ms_byte = 0;

	if(timeout_mclks > 0)
	{
		ls_byte = timeout_mclks - 1;
		while((ls_byte & 0xFFFFFF00) > 0)
		{
			ls_byte >>= 1;
			ms_byte++;
		}
		return (ms_byte << 8) | (ls_byte & 0xFF);
	}
	else
	{
		return 0;
	}
}

static
uint32_t	timeoutMclksToMicroseconds(uint16_t timeout_period_mclks, uint8_t vcsel_period_pclks)
{
	return ((calcMacroPeriod(vcsel_period_pclks) * timeout_period_mclks) + 500) / 1000;
}

static
uint32_t	timeoutMicrosecondsToMclks(uint32_t timeout_period_us, uint8_t vcsel_period_pclks)
{
	return (timeout_period_us * 1000) / calcMacroPeriod(vcsel_period_pclks);
}

#ifdef	D_USE_I2C_CONST_TABLE
static
void	writeRegs(const st_i2c *a, uint8_t n)
{
	while(0 < n)
	{
		n--;
		r_iic_master_send(address, (void *)a, 2);
		a++;
	}
}
#endif	// D_USE_I2C_CONST_TABLE

static
void	writeReg(uint8_t reg, uint8_t value)
{
	bufi2c[0] = reg;
	bufi2c[1] = value;
	r_iic_master_send(address, bufi2c, 2);
}

static
void	writeReg16Bit(uint8_t reg, uint16_t value)
{
	uint16_u	t_val;

	t_val.w = value;
	bufi2c[0] = reg;
	bufi2c[1] = t_val.b[1];
	bufi2c[2] = t_val.b[0];
	r_iic_master_send(address, bufi2c, 3);
}

static
void	writeMulti(uint8_t reg, uint8_t const * src, uint8_t count)
{
	bufi2c[0] = reg;
	memcpy(&bufi2c[1], src, count);
	r_iic_master_send(address, bufi2c, count + 1);
}

static
uint8_t		readReg(uint8_t reg)
{
	r_iic_master_receive(address, reg, bufi2c, 2);
	return bufi2c[0];
}

static
uint16_t	readReg16Bit(uint8_t reg)
{
	uint16_u	t_val;

	r_iic_master_receive(address, reg, bufi2c, 2);
	t_val.b[1] = bufi2c[0];
	t_val.b[0] = bufi2c[1];
	return t_val.w;
}

static
void	readMulti(uint8_t reg, uint8_t * dst, uint8_t count)
{
	r_iic_master_receive(address, reg, dst, count);
}

static
bool	getSpadInfo(uint8_t * count, bool * type_is_aperture)
{
	uint16_t	i;
	uint8_t		tmp;

	writeReg(0x80, 0x01);
	writeReg(0xFF, 0x01);
	writeReg(0x00, 0x00);
	writeReg(0xFF, 0x06);
	writeReg(0x83, readReg(0x83) | 0x04);
	writeReg(0xFF, 0x07);
	writeReg(0x81, 0x01);
	writeReg(0x80, 0x01);
	writeReg(0x94, 0x6b);
	writeReg(0x83, 0x00);
	for(i = 0; i < D_IIC_WAITLOOPCOUNT; i++)
	{
		if(0 != readReg(0x83))
		{
			break;
		}
	}
	if(i == D_IIC_WAITLOOPCOUNT)
	{
		return false;
	}
	writeReg(0x83, 0x01);
	tmp = readReg(0x92);
	*count = tmp & 0x7f;
	*type_is_aperture = (tmp >> 7) & 0x01;
	writeReg(0x81, 0x00);
	writeReg(0xFF, 0x06);
	writeReg(0x83, readReg(0x83)  & ~0x04);
	writeReg(0xFF, 0x01);
	writeReg(0x00, 0x01);
	writeReg(0xFF, 0x00);
	writeReg(0x80, 0x00);
	return true;
}

static
void	getSequenceStepEnables(SequenceStepEnables * enables)
{
	uint8_t		sequence_config;

	sequence_config = readReg(SYSTEM_SEQUENCE_CONFIG);
	enables->tcc          = (sequence_config >> 4) & 1;
	enables->dss          = (sequence_config >> 3) & 1;
	enables->msrc         = (sequence_config >> 2) & 1;
	enables->pre_range    = (sequence_config >> 6) & 1;
	enables->final_range  = (sequence_config >> 7) & 1;
}

static
void	getSequenceStepTimeouts(SequenceStepEnables const * enables, SequenceStepTimeouts * timeouts)
{
	timeouts->pre_range_vcsel_period_pclks = getVcselPulsePeriod(VcselPeriodPreRange);
	timeouts->msrc_dss_tcc_mclks = readReg(MSRC_CONFIG_TIMEOUT_MACROP) + 1;
	timeouts->msrc_dss_tcc_us = timeoutMclksToMicroseconds(timeouts->msrc_dss_tcc_mclks, timeouts->pre_range_vcsel_period_pclks);
	timeouts->pre_range_mclks = decodeTimeout(readReg16Bit(PRE_RANGE_CONFIG_TIMEOUT_MACROP_HI));
	timeouts->pre_range_us = timeoutMclksToMicroseconds(timeouts->pre_range_mclks, timeouts->pre_range_vcsel_period_pclks);
	timeouts->final_range_vcsel_period_pclks = getVcselPulsePeriod(VcselPeriodFinalRange);
	timeouts->final_range_mclks = decodeTimeout(readReg16Bit(FINAL_RANGE_CONFIG_TIMEOUT_MACROP_HI));
	if(enables->pre_range)
	{
		timeouts->final_range_mclks -= timeouts->pre_range_mclks;
	}
	timeouts->final_range_us = timeoutMclksToMicroseconds(timeouts->final_range_mclks, timeouts->final_range_vcsel_period_pclks);
}

static
bool		performSingleRefCalibration(uint8_t vhv_init_byte)
{
	uint16_t	i;

	writeReg(SYSRANGE_START, 0x01 | vhv_init_byte);
	for(i = 0; i < D_IIC_WAITLOOPCOUNT; i++)
	{
		if(0 != readReg(RESULT_INTERRUPT_STATUS) & 0x07)
		{
			break;
		}
	}
	if(i == D_IIC_WAITLOOPCOUNT)
	{
		return false;
	}
	writeReg(SYSTEM_INTERRUPT_CLEAR, 0x01);
	writeReg(SYSRANGE_START, 0x00);
	return true;
}

bool	init(bool io_2v8)
{
	bool		spad_type_is_aperture;
	uint8_t		spad_count;
	uint8_t		first_spad_to_enable;
	uint8_t		spads_enabled;
	uint8_t		ref_spad_map[6];
	uint8_t		i;

	if(0xEE != readReg(IDENTIFICATION_MODEL_ID))
	{
		return false;
	}
	if(io_2v8)
	{
		writeReg(VHV_CONFIG_PAD_SCL_SDA__EXTSUP_HV, readReg(VHV_CONFIG_PAD_SCL_SDA__EXTSUP_HV) | 0x01);
	}
#ifdef	D_USE_I2C_CONST_TABLE
	writeRegs(init_1, 4);
#else	// !D_USE_I2C_CONST_TABLE
	writeReg(0x88, 0x00);
	writeReg(0x80, 0x01);
	writeReg(0xFF, 0x01);
	writeReg(0x00, 0x00);
#endif	// D_USE_I2C_CONST_TABLE
	stop_variable = readReg(0x91);
#ifdef	D_USE_I2C_CONST_TABLE
	writeRegs(init_2, 3);
#else	// !D_USE_I2C_CONST_TABLE
	writeReg(0x00, 0x01);
	writeReg(0xFF, 0x00);
	writeReg(0x80, 0x00);
#endif	// D_USE_I2C_CONST_TABLE
	writeReg(MSRC_CONFIG_CONTROL, readReg(MSRC_CONFIG_CONTROL) | 0x12);
	writeReg16Bit(FINAL_RANGE_CONFIG_MIN_COUNT_RATE_RTN_LIMIT, 32);
	writeReg(SYSTEM_SEQUENCE_CONFIG, 0xFF);
	if(!getSpadInfo(&spad_count, &spad_type_is_aperture))
	{
		return false;
	}
	readMulti(GLOBAL_CONFIG_SPAD_ENABLES_REF_0, ref_spad_map, 6);
#ifdef	D_USE_I2C_CONST_TABLE
	writeRegs(init_3, 5);
#else	// !D_USE_I2C_CONST_TABLE
	writeReg(0xFF, 0x01);
	writeReg(DYNAMIC_SPAD_REF_EN_START_OFFSET, 0x00);
	writeReg(DYNAMIC_SPAD_NUM_REQUESTED_REF_SPAD, 0x2C);
	writeReg(0xFF, 0x00);
	writeReg(GLOBAL_CONFIG_REF_EN_START_SELECT, 0xB4);
#endif	// D_USE_I2C_CONST_TABLE
	first_spad_to_enable = spad_type_is_aperture ? 12 : 0;
	spads_enabled = 0;
	for(i = 0; i < 48; i++)
	{
		if((i < first_spad_to_enable) || (spads_enabled == spad_count))
		{
			ref_spad_map[i / 8] &= ~(1 << (i % 8));
		}
		else if((ref_spad_map[i / 8] >> (i % 8)) & 0x1)
		{
			spads_enabled++;
		}
	}
	writeMulti(GLOBAL_CONFIG_SPAD_ENABLES_REF_0, ref_spad_map, 6);
#ifdef	D_USE_I2C_CONST_TABLE
	writeRegs(init_4, 81);
#else	// !D_USE_I2C_CONST_TABLE
	writeReg(0xFF, 0x01);
	writeReg(0x00, 0x00);
	writeReg(0xFF, 0x00);
	writeReg(0x09, 0x00);
	writeReg(0x10, 0x00);
	writeReg(0x11, 0x00);
	writeReg(0x24, 0x01);
	writeReg(0x25, 0xFF);
	writeReg(0x75, 0x00);
	writeReg(0xFF, 0x01);
	writeReg(0x4E, 0x2C);
	writeReg(0x48, 0x00);
	writeReg(0x30, 0x20);
	writeReg(0xFF, 0x00);
	writeReg(0x30, 0x09);
	writeReg(0x54, 0x00);
	writeReg(0x31, 0x04);
	writeReg(0x32, 0x03);
	writeReg(0x40, 0x83);
	writeReg(0x46, 0x25);
	writeReg(0x60, 0x00);
	writeReg(0x27, 0x00);
	writeReg(0x50, 0x06);
	writeReg(0x51, 0x00);
	writeReg(0x52, 0x96);
	writeReg(0x56, 0x08);
	writeReg(0x57, 0x30);
	writeReg(0x61, 0x00);
	writeReg(0x62, 0x00);
	writeReg(0x64, 0x00);
	writeReg(0x65, 0x00);
	writeReg(0x66, 0xA0);
	writeReg(0xFF, 0x01);
	writeReg(0x22, 0x32);
	writeReg(0x47, 0x14);
	writeReg(0x49, 0xFF);
	writeReg(0x4A, 0x00);
	writeReg(0xFF, 0x00);
	writeReg(0x7A, 0x0A);
	writeReg(0x7B, 0x00);
	writeReg(0x78, 0x21);
	writeReg(0xFF, 0x01);
	writeReg(0x23, 0x34);
	writeReg(0x42, 0x00);
	writeReg(0x44, 0xFF);
	writeReg(0x45, 0x26);
	writeReg(0x46, 0x05);
	writeReg(0x40, 0x40);
	writeReg(0x0E, 0x06);
	writeReg(0x20, 0x1A);
	writeReg(0x43, 0x40);
	writeReg(0xFF, 0x00);
	writeReg(0x34, 0x03);
	writeReg(0x35, 0x44);
	writeReg(0xFF, 0x01);
	writeReg(0x31, 0x04);
	writeReg(0x4B, 0x09);
	writeReg(0x4C, 0x05);
	writeReg(0x4D, 0x04);
	writeReg(0xFF, 0x00);
	writeReg(0x44, 0x00);
	writeReg(0x45, 0x20);
	writeReg(0x47, 0x08);
	writeReg(0x48, 0x28);
	writeReg(0x67, 0x00);
	writeReg(0x70, 0x04);
	writeReg(0x71, 0x01);
	writeReg(0x72, 0xFE);
	writeReg(0x76, 0x00);
	writeReg(0x77, 0x00);
	writeReg(0xFF, 0x01);
	writeReg(0x0D, 0x01);
	writeReg(0xFF, 0x00);
	writeReg(0x80, 0x01);
	writeReg(0x01, 0xF8);
	writeReg(0xFF, 0x01);
	writeReg(0x8E, 0x01);
	writeReg(0x00, 0x01);
	writeReg(0xFF, 0x00);
	writeReg(0x80, 0x00);
	writeReg(SYSTEM_INTERRUPT_CONFIG_GPIO, 0x04);
#endif	// D_USE_I2C_CONST_TABLE
	writeReg(GPIO_HV_MUX_ACTIVE_HIGH, readReg(GPIO_HV_MUX_ACTIVE_HIGH) & ~0x10);
	writeReg(SYSTEM_INTERRUPT_CLEAR, 0x01);
	measurement_timing_budget_us = getMeasurementTimingBudget();
	writeReg(SYSTEM_SEQUENCE_CONFIG, 0xE8);
	setMeasurementTimingBudget(measurement_timing_budget_us);
	writeReg(SYSTEM_SEQUENCE_CONFIG, 0x01);
	if(!performSingleRefCalibration(0x40))
	{
		return false;
	}
	writeReg(SYSTEM_SEQUENCE_CONFIG, 0x02);
	if(!performSingleRefCalibration(0x00))
	{
		return false;
	}
	writeReg(SYSTEM_SEQUENCE_CONFIG, 0xE8);
	return true;
}

bool	setMeasurementTimingBudget(uint32_t budget_us)
{
	uint16_t const StartOverhead		= 1910;
	uint16_t const EndOverhead			= 960;
	uint16_t const MsrcOverhead			= 660;
	uint16_t const TccOverhead			= 590;
	uint16_t const DssOverhead			= 690;
	uint16_t const PreRangeOverhead		= 660;
	uint16_t const FinalRangeOverhead	= 550;
	uint32_t const MinTimingBudget		= 20000;

	SequenceStepEnables		enables;
	SequenceStepTimeouts	timeouts;
	uint32_t	used_budget_us;
	uint32_t	final_range_timeout_us;
	uint32_t	final_range_timeout_mclks;

	if(budget_us < MinTimingBudget)
	{
		return false;
	}
	used_budget_us = StartOverhead + EndOverhead;
	getSequenceStepEnables(&enables);
	getSequenceStepTimeouts(&enables, &timeouts);
	if (enables.tcc)
	{
		used_budget_us += (timeouts.msrc_dss_tcc_us + TccOverhead);
	}
	if (enables.dss)
	{
		used_budget_us += 2 * (timeouts.msrc_dss_tcc_us + DssOverhead);
	}
	else if (enables.msrc)
	{
		used_budget_us += (timeouts.msrc_dss_tcc_us + MsrcOverhead);
	}
	if (enables.pre_range)
	{
		used_budget_us += (timeouts.pre_range_us + PreRangeOverhead);
	}
	if (enables.final_range)
	{
		used_budget_us += FinalRangeOverhead;
		if (used_budget_us > budget_us)
		{
			return false;
		}
		final_range_timeout_us = budget_us - used_budget_us;
		final_range_timeout_mclks =
			timeoutMicrosecondsToMclks(final_range_timeout_us, timeouts.final_range_vcsel_period_pclks);
		if (enables.pre_range)
		{
			final_range_timeout_mclks += timeouts.pre_range_mclks;
		}
		writeReg16Bit(FINAL_RANGE_CONFIG_TIMEOUT_MACROP_HI, encodeTimeout(final_range_timeout_mclks));
		measurement_timing_budget_us = budget_us;
	}
	return true;
}

uint32_t	getMeasurementTimingBudget(void)
{
	uint16_t const StartOverhead		= 1910;
	uint16_t const EndOverhead			= 960;
	uint16_t const MsrcOverhead			= 660;
	uint16_t const TccOverhead			= 590;
	uint16_t const DssOverhead			= 690;
	uint16_t const PreRangeOverhead		= 660;
	uint16_t const FinalRangeOverhead	= 550;

	SequenceStepEnables		enables;
	SequenceStepTimeouts	timeouts;

	uint32_t		budget_us;

	budget_us = StartOverhead + EndOverhead;
	getSequenceStepEnables(&enables);
	getSequenceStepTimeouts(&enables, &timeouts);
	if(enables.tcc)
	{
		budget_us += (timeouts.msrc_dss_tcc_us + TccOverhead);
	}
	if(enables.dss)
	{
		budget_us += 2 * (timeouts.msrc_dss_tcc_us + DssOverhead);
	}
	else if (enables.msrc)
	{
		budget_us += (timeouts.msrc_dss_tcc_us + MsrcOverhead);
	}
	if (enables.pre_range)
	{
		budget_us += (timeouts.pre_range_us + PreRangeOverhead);
	}
	if (enables.final_range)
	{
		budget_us += (timeouts.final_range_us + FinalRangeOverhead);
	}
	measurement_timing_budget_us = budget_us;
	return budget_us;
}

uint8_t		getVcselPulsePeriod(vcselPeriodType type)
{
	if(type == VcselPeriodPreRange)
	{
		return decodeVcselPeriod(readReg(PRE_RANGE_CONFIG_VCSEL_PERIOD));
	}
	if(type == VcselPeriodFinalRange)
	{
		return decodeVcselPeriod(readReg(FINAL_RANGE_CONFIG_VCSEL_PERIOD));
	}
	return 255;
}

#ifdef	D_USE_ToF_SINGLE_MODE

uint16_t	readRangeSingleMillimeters(void)
{
	uint16_t	t_val;

#ifdef	D_USE_I2C_CONST_TABLE
	writeRegs(init_24, 3);
#else	// !D_USE_I2C_CONST_TABLE
	writeReg(0x80, 0x01);
	writeReg(0xFF, 0x01);
	writeReg(0x00, 0x00);
#endif	// D_USE_I2C_CONST_TABLE
	writeReg(0x91, stop_variable);
#ifdef	D_USE_I2C_CONST_TABLE
	writeRegs(init_25, 4);
#else	// !D_USE_I2C_CONST_TABLE
	writeReg(0x00, 0x01);
	writeReg(0xFF, 0x00);
	writeReg(0x80, 0x00);
	writeReg(SYSRANGE_START, 0x01);
#endif	// D_USE_I2C_CONST_TABLE
	for(t_val = 0; readReg(SYSRANGE_START) & 0x01; t_val++)
	{
		if(D_IIC_WAITLOOPCOUNT <= t_val)
		{
			return 65535;
		}
	}
	for(t_val = 0; 0 == readReg(RESULT_INTERRUPT_STATUS) & 0x07; t_val++)
	{
		if(D_IIC_WAITLOOPCOUNT <= t_val)
		{
			return 65535;
		}
	}
	t_val = readReg16Bit(RESULT_RANGE_STATUS + 10);
	writeReg(SYSTEM_INTERRUPT_CLEAR, 0x01);
	return t_val;
}

#else	// !D_USE_ToF_SINGLE_MODE

void	startContinuous(void)
{
	writeReg(0x80, 0x01);
	writeReg(0xFF, 0x01);
	writeReg(0x00, 0x00);
	writeReg(0x91, stop_variable);
	writeReg(0x00, 0x01);
	writeReg(0xFF, 0x00);
	writeReg(0x80, 0x00);
	writeReg(SYSRANGE_START, 0x02);
}

#if 0
void	stopContinuous(void)
{
	writeReg(SYSRANGE_START, 0x01);
	writeReg(0xFF, 0x01);
	writeReg(0x00, 0x00);
	writeReg(0x91, 0x00);
	writeReg(0x00, 0x01);
	writeReg(0xFF, 0x00);
}
#endif

uint16_t	readRangeContinuousMillimeters(void)
{
	uint16_t	t_val;

	for(t_val = 0; 0 == readReg(RESULT_INTERRUPT_STATUS) & 0x07; t_val++)
	{
		if(D_IIC_WAITLOOPCOUNT <= t_val)
		{
			return 65535;
		}
	}
	t_val = readReg16Bit(RESULT_RANGE_STATUS + 10);
	writeReg(SYSTEM_INTERRUPT_CLEAR, 0x01);
	return t_val;
}

#endif
