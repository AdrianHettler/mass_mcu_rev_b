#include "main.h"
/*
#define GPIO_PIN_PULLER_1_Pin GPIO_PIN_2
#define GPIO_PIN_PULLER_1_GPIO_Port GPIOC
#define GPIO_PIN_PULLER_2_Pin GPIO_PIN_3
#define GPIO_PIN_PULLER_2_GPIO_Port GPIOC

#define GPIO_LED_1_Pin GPIO_PIN_0
#define GPIO_LED_1_GPIO_Port GPIOD
#define GPIO_LED_2_Pin GPIO_PIN_1
#define GPIO_LED_2_GPIO_Port GPIOD

#define GPIO_VALVE_4_Pin GPIO_PIN_4
#define GPIO_VALVE_4_GPIO_Port GPIOD
#define GPIO_VALVE_3_Pin GPIO_PIN_5
#define GPIO_VALVE_3_GPIO_Port GPIOD
#define GPIO_VALVE_2_Pin GPIO_PIN_6
#define GPIO_VALVE_2_GPIO_Port GPIOD
#define GPIO_VALVE_1_Pin GPIO_PIN_3
#define GPIO_VALVE_1_GPIO_Port GPIOE
*/

#define DEVICE_LED_1 0
#define DEVICE_LED_2 1

#define DEVICE_PIN_PULLER_1 2
#define DEVICE_PIN_PULLER_2 3

#define DEVICE_VALVE_1 4
#define DEVICE_VALVE_2 5
#define DEVICE_VALVE_3 6
#define DEVICE_VALVE_4 7


#define DEVICES_ID_MAX 10 //larger or equal than biggest device number

void switch_on(uint8_t device);
void switch_off(uint8_t device);
void switch_off_handler();
