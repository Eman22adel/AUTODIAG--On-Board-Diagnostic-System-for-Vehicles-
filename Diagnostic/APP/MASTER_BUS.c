/*
 * Master_Bus.c
 *
 *  Created on: Jun 8, 2024
 *      Author: eman adel
 */

#include "main.h"
#include "SERIAL_COM.h"
#include "MASTER_BUS.h"


static uint8_t TX_BUFFER[TX_BUFFER_SIZE]= "1\n\r";


Return_Type HAL_MASTER_BUS_Init(void);

Return_Type HAL_MASTER_BUS_MainFunction(void){
	Return_Type Return_Result = Return_NOT_OK;

	if(SERIAL_COM_Send(TX_BUFFER,TX_BUFFER_SIZE) == Return_OK){
		Return_Result = Return_OK;
	}
	return Return_OK;
}



