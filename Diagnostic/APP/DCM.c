/*
 * DCM.h
 *
 *  Created on: Feb 13, 2024
 *  Author: eman adel
 */

#include "main.h"
#include "SERIAL_COM.h"
#include "COM_H.h"
#include "DCM.h"
#include "MASTER_BUS.h"


Return_Type HAL_DCM_Init(void);

Return_Type HAL_DCM_Receive(void){
	Return_Type Return_Result = Return_NOT_OK;
	if (HAL_COMH_Send() == Return_OK){
		Return_Result = Return_OK;
	}
	return Return_Result;
}
