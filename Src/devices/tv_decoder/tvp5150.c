#include "..\i2c_addresses.h"
#include "tvp5150.h"


extern I2C_HandleTypeDef hi2c1;
extern DCMI_HandleTypeDef hdcmi;




void tvp5150_init_register()
{
	//i2c_write_single(&hi2c1,I2C_ADDRESS_TV_DECODER,0x0,0b10);  //Channel 2


	i2c_write_single(&hi2c1,I2C_ADDRESS_TV_DECODER,0x2,0b110000); //Operation Mode Controls Register

	i2c_write_single(&hi2c1,I2C_ADDRESS_TV_DECODER,0x3,0b1111); //Miscellaneous Controls Register
	i2c_write_single(&hi2c1,I2C_ADDRESS_TV_DECODER,0x4,0x0); //Autoswitch Mask Register
	i2c_write_single(&hi2c1,I2C_ADDRESS_TV_DECODER,0xd,0b1100000); //Outputs and Data Rates Select Register
	i2c_write_single(&hi2c1,I2C_ADDRESS_TV_DECODER,0x28,0b100);  //Video Standard Register NTSC 794*480


}

void tvp5150_reset()
{
	HAL_GPIO_WritePin(TV_PDN_GPIO_Port, TV_PDN_Pin, GPIO_PIN_RESET); //PDN
	HAL_GPIO_WritePin(TV_RESET_GPIO_Port, TV_RESET_Pin, GPIO_PIN_RESET); //RESET
	HAL_Delay(250);
	HAL_GPIO_WritePin(TV_PDN_GPIO_Port, TV_PDN_Pin, GPIO_PIN_SET); //PDN
	HAL_Delay(250);
	HAL_GPIO_WritePin(TV_RESET_GPIO_Port, TV_RESET_Pin, GPIO_PIN_SET); //RESET
}

uint8_t tvp5150_get_status()
{
	return i2c_read_single(&hi2c1,I2C_ADDRESS_TV_DECODER,0x88);
}


uint8_t tvp5150_is_sync_locked()
{
	if(tvp5150_get_status() && 0x6)
		return true;
	else
		return false;
}

void tvp5150_capture_snapshot()
{
	HAL_DCMI_Start_DMA(&hdcmi, DCMI_MODE_CONTINUOUS, (uint32_t)frame_buffer,IMG_ROWS * IMG_COLUMNS);//IMG_ROWS * IMG_COLUMNS
}
