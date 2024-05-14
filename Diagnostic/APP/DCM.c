
#include "main.h"
#include "COM_H.h"
#include "DCM.h"
#include "MASTER_BUS.h"

extern SYSTEM_Data DATA;

Return_Type HAL_DCM_Init(void);

Return_Type HAL_DCM_MainFunction(void){
	if (HAL_COMH_Send(DATA) == Return_OK){
		return Return_OK;
	}
	return Return_NOT_OK;
}
