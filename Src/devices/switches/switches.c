#include "switches.h"


extern uint32_t switch_off_time_list[DEVICES_ID_MAX];

void switch_on(uint8_t device)
{
	switch(device){
	case DEVICE_LED_1: HAL_GPIO_WritePin(GPIO_LED_1_GPIO_Port, GPIO_LED_1_Pin, GPIO_PIN_SET); break;
	case DEVICE_LED_2: HAL_GPIO_WritePin(GPIO_LED_2_GPIO_Port, GPIO_LED_2_Pin, GPIO_PIN_SET); break;

	case DEVICE_PIN_PULLER_1: HAL_GPIO_WritePin(GPIO_PIN_PULLER_1_GPIO_Port, GPIO_PIN_PULLER_1_Pin, GPIO_PIN_SET); break;
	case DEVICE_PIN_PULLER_2: HAL_GPIO_WritePin(GPIO_PIN_PULLER_2_GPIO_Port, GPIO_PIN_PULLER_2_Pin, GPIO_PIN_SET); break;

	case DEVICE_VALVE_1: HAL_GPIO_WritePin(GPIO_VALVE_1_GPIO_Port, GPIO_VALVE_1_Pin, GPIO_PIN_SET); break;
	case DEVICE_VALVE_2: HAL_GPIO_WritePin(GPIO_VALVE_2_GPIO_Port, GPIO_VALVE_2_Pin, GPIO_PIN_SET); break;
	case DEVICE_VALVE_3: HAL_GPIO_WritePin(GPIO_VALVE_3_GPIO_Port, GPIO_VALVE_3_Pin, GPIO_PIN_SET); break;
	case DEVICE_VALVE_4: HAL_GPIO_WritePin(GPIO_VALVE_4_GPIO_Port, GPIO_VALVE_4_Pin, GPIO_PIN_SET); break;
	}
}


void switch_off(uint8_t device)
{
	switch(device){
		case DEVICE_LED_1: HAL_GPIO_WritePin(GPIO_LED_1_GPIO_Port, GPIO_LED_1_Pin, GPIO_PIN_RESET); break;
		case DEVICE_LED_2: HAL_GPIO_WritePin(GPIO_LED_2_GPIO_Port, GPIO_LED_2_Pin, GPIO_PIN_RESET); break;

		case DEVICE_PIN_PULLER_1: HAL_GPIO_WritePin(GPIO_PIN_PULLER_1_GPIO_Port, GPIO_PIN_PULLER_1_Pin, GPIO_PIN_RESET); break;
		case DEVICE_PIN_PULLER_2: HAL_GPIO_WritePin(GPIO_PIN_PULLER_2_GPIO_Port, GPIO_PIN_PULLER_2_Pin, GPIO_PIN_RESET); break;

		case DEVICE_VALVE_1: HAL_GPIO_WritePin(GPIO_VALVE_1_GPIO_Port, GPIO_VALVE_1_Pin, GPIO_PIN_RESET); break;
		case DEVICE_VALVE_2: HAL_GPIO_WritePin(GPIO_VALVE_2_GPIO_Port, GPIO_VALVE_2_Pin, GPIO_PIN_RESET); break;
		case DEVICE_VALVE_3: HAL_GPIO_WritePin(GPIO_VALVE_3_GPIO_Port, GPIO_VALVE_3_Pin, GPIO_PIN_RESET); break;
		case DEVICE_VALVE_4: HAL_GPIO_WritePin(GPIO_VALVE_4_GPIO_Port, GPIO_VALVE_4_Pin, GPIO_PIN_RESET); break;
		}
}


void switch_off_handler()//handles switch off after X sec.
{
	for (uint8_t device_id = 0; device_id < DEVICES_ID_MAX; device_id++) {
		if (switch_off_time_list[device_id] != 0) {
			if(HAL_GetTick() > switch_off_time_list[device_id])
			{
				switch_off(device_id);
				switch_off_time_list[device_id] = 0;
			}
		}
	}
}
