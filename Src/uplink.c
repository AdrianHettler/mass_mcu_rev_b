#include "main.h"
#include "ethernet/message_ids.h"
#include "devices/sensors/sensors.h"
#include "devices/switches/switches.h"

uint8_t return_data[5] = {};


uint32_t switch_off_time_list[DEVICES_ID_MAX] = {};




uint8_t uplink(void* payload, int payload_size)
{

	uint8_t data_received[50] = { };


	if (payload_size <= sizeof(data_received)) {
		memcpy(&data_received, payload, payload_size);
		uint8_t message_id = data_received[0];
		uint8_t device_id = 0;
		switch (message_id) {

		case exp_release_structures: ; //i hate C
			device_id = data_received[1];
			switch_on(device_id);
			if (device_id < DEVICES_ID_MAX) {
				switch_off_time_list[device_id] = (uint32_t) (HAL_GetTick()
						+ 1000 * (uint32_t) data_received[2]); //switch off after X sec. data_received[2] = activation time
			}
			return tcp_ok;

		case exp_uv_on: ;
			device_id = data_received[1];
			switch_on(device_id);
			return tcp_ok;

		case exp_uv_off: ;
			device_id = data_received[1];
			switch_off(device_id);
			return tcp_ok;

		case exp_valves_manual_on: ;
			device_id = data_received[1];
			switch_on(device_id);
			return tcp_ok;

		case exp_valves_manual_off:	;
			device_id = data_received[1];
			switch_off(device_id);
			return tcp_ok;

		case tcp_ping: ;
				return tcp_pong;

		}

		return error_tcp_unknown_msg_id; //unknown msg id
	}
	else
		return error_tcp_buffer_size;


	return 0;
}
