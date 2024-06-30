/*
 * SERIAL_COM.c
 *
 *  Created on: Feb 13, 2024
 *      Author: eman adel
 */

#include "main.h"
#include "SERIAL_COM.h"
#include "stm32f1xx_hal_uart.h"


SYSTEM_Data DATA;

extern UART_HandleTypeDef huart1;



Return_Type SERIAL_COM_Init(void);

///
Return_Type SERIAL_COM_Receive(uint8_t * RXBUFFER){

	uint16_t Temp_Convert = 0, Counter_array = 0,Counter_Sensor=0, char_array = 0, stop_value = 0;
	uint16_t sensor[8];
	while(stop_value < 8){
		if(RXBUFFER[Counter_array] >= '0' && RXBUFFER[Counter_array] <= '9'){  //(8)
			Temp_Convert = Temp_Convert *10;
			char_array =RXBUFFER[Counter_array]-'0';
			Temp_Convert = Temp_Convert + char_array;
		}else if(RXBUFFER[Counter_array] == ',' ){
			sensor[Counter_Sensor] = Temp_Convert;
			Counter_Sensor++;
			Temp_Convert = 0;
			stop_value++;
		}
		Counter_array++;
	}

	DATA.sensor1 = sensor[0];
	DATA.sensor2 = sensor[1];
	DATA.sensor3 = sensor[2];
	DATA.sensor4 = sensor[3];
	DATA.sensor5 = sensor[4];
	DATA.sensor6 = sensor[5];
	DATA.sensor7 = sensor[6];
	DATA.sensor8 = sensor[7];

	return Return_OK;
}

///send uart
Return_Type SERIAL_COM_Send(uint8_t  *TXBUFFER , uint8_t size){
	Return_Type Return_Result = Return_NOT_OK;
	if (HAL_UART_Transmit(&huart1, TXBUFFER, size, 10) == HAL_OK){
		Return_Result = Return_OK;
	}
	return Return_Result;
}

