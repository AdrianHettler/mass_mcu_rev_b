#include "main.h"
#include <math.h>



struct power_data
{
	float voltage_bexus;
	float voltage_extra;
	float current_bexus;
	float current_extra;
};

struct power_data *get_power_data();

struct ambient_data
{
	float temperature_inside;
	float temperature_outside;
	float pressure;
};

struct ambient_data *get_ambient_data();

float get_pressure_structures_inside();
float get_pressure_structures_outside();
