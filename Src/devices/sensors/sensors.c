#include "sensors.h"
#include "../adc/adc.h"
#include "../i2c_addresses.h"

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

#define VOLTAGE_5V 4.98f
#define VOLTAGE_3V3 3.3f


float voltage_calculation(float voltage_sensor)
{
#define R1 12 //voltage devider resistor 1 12kOhm
#define R2 1 //voltage devider resistor 1 1kOhm


	return voltage_sensor*(R1+R2)/R2;
}


float current_calculation(float voltage_sensor)
{
#define SENS 0.185f //sensor sensitivity

	return ((1.243f - voltage_sensor)*2.f)/SENS;
}

float temperature_calculation(float voltage_sensor)
{
#define T0 293.15f //initial temp 25°C in Kelvin 0.003354f = 1/T0
#define B 3988.f // 0.000250752f = 1/B
#define R 10000.f //inistial resistance thermistor 10kOhm


	return (1.f/( 0.003354f + 0.000250752f * log((voltage_sensor*R)/((VOLTAGE_3V3-voltage_sensor)*R)))) - 273.15f;
}

float pressure_calculation(float voltage_sensor)
{
#define R1 75.f //voltage devider resistor 1 75kOhm
#define R2 49.9f //voltage devider resistor 2 49.9kOhm
#define Pmax 30.f // 30PSI max pressue
#define CONV 68.9476f //conversion psi to mbar

	return CONV * (((voltage_sensor*(R1+R2)/R1)-VOLTAGE_5V*0.1f)*Pmax/(0.8f*VOLTAGE_5V));
}


struct power_data *get_power_data()
{

	static struct power_data pwr_data = {};

	pwr_data.voltage_bexus = voltage_calculation(MCP342X_adc_read_16bit(&hi2c1,I2C_ADDRESS_ADC_VOLT_CURRENT,CHANNEL_1));
	pwr_data.voltage_extra = voltage_calculation(MCP342X_adc_read_16bit(&hi2c1,I2C_ADDRESS_ADC_VOLT_CURRENT,CHANNEL_2));

	pwr_data.current_bexus = current_calculation(MCP342X_adc_read_16bit(&hi2c1,I2C_ADDRESS_ADC_VOLT_CURRENT,CHANNEL_4));
	pwr_data.current_extra = current_calculation(MCP342X_adc_read_16bit(&hi2c1,I2C_ADDRESS_ADC_VOLT_CURRENT,CHANNEL_3));

	return &pwr_data;
}

struct ambient_data *get_ambient_data()
{
	static struct ambient_data amb_data = {};

	amb_data.temperature_inside = temperature_calculation(MCP342X_adc_read_16bit(&hi2c2,I2C_ADDRESS_ADC_TEMPERATURE,CHANNEL_1));
	amb_data.temperature_outside = temperature_calculation(MCP342X_adc_read_16bit(&hi2c2,I2C_ADDRESS_ADC_TEMPERATURE,CHANNEL_2));
	amb_data.pressure = pressure_calculation(MCP342X_adc_read_16bit(&hi2c2,I2C_ADDRESS_ADC_PRESSURE,CHANNEL_1));

	return &amb_data;
}

float get_pressure_structures_inside()
{
	return pressure_calculation(MCP342X_adc_read_16bit(&hi2c2,I2C_ADDRESS_ADC_PRESSURE,CHANNEL_3));
}

float get_pressure_structures_outside()
{
	return pressure_calculation(MCP342X_adc_read_16bit(&hi2c2,I2C_ADDRESS_ADC_PRESSURE,CHANNEL_4));
}


