/*
 * SERIAL_COM.c
 *
 *  Created on: Feb 13, 2024
 *      Author: eman adel
 */

#include "main.h"
#include "SERIAL_COM.h"
#include "MASTER_BUS.h"

extern SYSTEM_Data DATA;
extern UART_HandleTypeDef huart1;

Return_Type HAL_SERIAL_COMH_Init(void);

Return_Type HAL_SERIAL_COMH_Receive(uint8_t * RXBUFFER_SIZE){

		uint16_t x = 0, i = 0,j=0,c=0,stop=0,START_DCT=0;
		uint16_t sensor[8];
		while(stop < 8){
			START_DCT++;
			if(RXBUFFER_SIZE[i] >= '0' && RXBUFFER_SIZE[i] <= '9'){
				x = x*10;
				c =RXBUFFER_SIZE[i]-'0';
				x = x + c;
			}else if(RXBUFFER_SIZE[i] == ',' ){
				sensor[j] = x;
				j++;
				x=0;
				stop++;
			}
			i++;
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

Return_Type HAL_SERIAL_COMH_Send(uint8_t ID_REQUEST[],uint8_t size){
	if( HAL_UART_Transmit(&huart1, ID_REQUEST, size, 10) == HAL_OK){
		return Return_OK;
	}
	return Return_NOT_OK;
}

Return_Type  COPY_STRING(uint8_t arr1[],uint8_t arr2[],uint8_t start,uint8_t end){
	int j = 0;
	for(int i = start ; i < end ;i++){
		arr2[j] = arr1[i];
		j++;
	}
	return Return_OK;
}


