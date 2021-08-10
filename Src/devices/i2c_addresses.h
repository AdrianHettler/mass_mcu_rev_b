#pragma once
#include "main.h"
#define I2C_ADDRESS_TV_DECODER 0xB8
#define I2C_ADDRESS_RTC 0x68
#define I2C_ADDRESS_ADC_VOLT_CURRENT 0x6E
#define I2C_ADDRESS_ADC_TEMPERATURE 0x68
#define I2C_ADDRESS_ADC_PRESSURE 0x6E
#define I2C_ADDRESS_MULTIPLEX 0x70
#define I2C_ADDRESS_GYRO 0x69

void i2c_read(I2C_HandleTypeDef *hi2c,uint8_t device_addr,uint8_t reg_addr,uint8_t *data, uint8_t size);
uint8_t i2c_read_single(I2C_HandleTypeDef *hi2c,uint8_t device_addr,uint8_t register);
void i2c_write_single(I2C_HandleTypeDef *hi2c,uint8_t device_addr,uint8_t register,uint8_t value);
