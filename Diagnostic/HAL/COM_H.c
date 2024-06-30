
#include "main.h"
#include "SERIAL_COM.h"
#include "COM_H.h"
#include "stm32f1xx_hal_spi.h"


extern SYSTEM_Data DATA;
extern SPI_HandleTypeDef hspi1;

uint16_t  pTxData = 0;

Return_Type HAL_COMH_Init(void);


Return_Type HAL_COMH_Receive(void){
	Return_Type Return_Result = Return_NOT_OK;
	if (HAL_DCM_Receive() == Return_OK){
		Return_Result = Return_OK;
	}
	return Return_Result;
}


Return_Type HAL_COMH_Send(void){
	Return_Type Return_Result = Return_NOT_OK;
	uint8_t check = 1;

	pTxData = DATA.sensor1; //Sensor1
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}

	pTxData = DATA.sensor2; //Sensor2
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}

	pTxData = DATA.sensor3; //Sensor3
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}

	pTxData = DATA.sensor4; //Sensor4
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}

	pTxData = DATA.sensor5; //Sensor5
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}

	pTxData = DATA.sensor6; //Sensor6
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}

	pTxData = DATA.sensor7; //Sensor7
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}

	pTxData = DATA.sensor8; //Sensor8
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}

	///////////////////////////////////////

	pTxData = DATA.DTC_1[0];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}
	pTxData = DATA.DTC_1[1];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}
	pTxData = DATA.DTC_1[2];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}
	pTxData = DATA.DTC_1[3];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}
	pTxData = DATA.DTC_1[4];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}

	pTxData = DATA.DTC_2[0];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}
	pTxData = DATA.DTC_2[1];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}
	pTxData = DATA.DTC_2[2];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}
	pTxData = DATA.DTC_2[3];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}
	pTxData = DATA.DTC_2[4];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}

	pTxData = DATA.DTC_3[0];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}
	pTxData = DATA.DTC_3[1];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}
	pTxData = DATA.DTC_3[2];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}
	pTxData = DATA.DTC_3[3];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}
	pTxData = DATA.DTC_3[4];
	if(HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10) != HAL_OK){
		check &= 0;
	}
	if(check == 1){
		Return_Result = Return_OK;
	}

	pTxData = 0;

	return Return_Result;
}


