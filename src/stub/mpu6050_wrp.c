#include "stm32f103x_i2c.h"
#include "mpu6050_cfg.h"

void mpu6050_read_byte(uint8_t s_addr, uint8_t m_addr, uint8_t* data)
{
    i2c_master_read_byte(I2C1, s_addr, m_addr,data);
}

void mpu6050_write_byte(uint8_t s_addr, uint8_t m_addr, uint8_t* data)
{
    i2c_master_write_byte(I2C1, s_addr, m_addr,data);
}