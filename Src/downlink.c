#include "main.h"
#include "ethernet/message_ids.h"
#include "devices/sensors/sensors.h"

void downlink()
{


	//ambient
	struct ambient_data *amb_data = get_ambient_data();
	udp_echoclient_send(data_down_ambient, amb_data, sizeof(struct ambient_data));

	//power
	struct power_data * pwr_data = get_power_data();
	udp_echoclient_send(data_down_power, pwr_data, sizeof(struct power_data));


	//pressure



	//picture data


	//gyro data
}
