/*
 * MASTER_BUS.c
 *
 *  Created on: Feb 15, 2024
 *      Author: eman adel
 */

#include "main.h"
#include "SERIAL_COM.h"
#include "MASTER_BUS.h"

SYSTEM_Data DATA;


uint8_t TX_BUFFER[TX_BUFFER_SIZE]= "Remote frame";

Return_Type HAL_MASTER_BUS_Init(void);

Return_Type HAL_MASTER_BUS_MainFunction(void){
	HAL_SERIAL_COMH_Send(TX_BUFFER,TX_BUFFER_SIZE);
	return Return_OK;
}

