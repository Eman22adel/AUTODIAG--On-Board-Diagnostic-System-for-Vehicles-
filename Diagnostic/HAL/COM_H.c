
#include "main.h"
#include "SERIAL_COM.h"
#include "DCM.h"
#include "MASTER_BUS.h"
#include "COM_H.h"

extern SPI_HandleTypeDef hspi1;

Return_Type HAL_COMH_Init(void);

Return_Type HAL_COMH_Receive(uint8_t *BUFFER){
	if(*BUFFER == REQUEST){
		HAL_DCM_MainFunction();
		return Return_OK;
	}
	return Return_NOT_OK;
}

Return_Type HAL_COMH_Send(SYSTEM_Data DATA){
	uint16_t  pTxData;

	pTxData = DATA.sensor1; //Sensor1
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);

	pTxData = DATA.sensor2; //Sensor2
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);

	pTxData = DATA.sensor3; //Sensor3
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);

	pTxData = DATA.sensor4; //Sensor4
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);

	pTxData = DATA.sensor5; //Sensor5
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);

	pTxData = DATA.sensor6; //Sensor6
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);

	pTxData = DATA.sensor7; //Sensor7
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);

	pTxData = DATA.sensor8; //Sensor8
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);

	///////////////////////////////////////
	pTxData = DATA.DTC_1[0];
	HAL_SPI_Transmit(&hspi1,  &pTxData, 2, 10);
	pTxData = DATA.DTC_1[1];
	HAL_SPI_Transmit(&hspi1,  &pTxData, 2, 10);
	pTxData = DATA.DTC_1[2];
	HAL_SPI_Transmit(&hspi1,  &pTxData, 2, 10);
	pTxData = DATA.DTC_1[3];
	HAL_SPI_Transmit(&hspi1,  &pTxData, 2, 10);
	pTxData = DATA.DTC_1[4];
	HAL_SPI_Transmit(&hspi1,  &pTxData, 2, 10);


	pTxData = DATA.DTC_2[0];
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);
	pTxData = DATA.DTC_2[1];
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);
	pTxData = DATA.DTC_2[2];
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);
	pTxData = DATA.DTC_2[3];
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);
	pTxData = DATA.DTC_2[4];
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);

	pTxData = DATA.DTC_3[0];
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);
	pTxData = DATA.DTC_3[1];
	HAL_SPI_Transmit(&hspi1,  &pTxData, 2, 10);
	pTxData = DATA.DTC_3[2];
	HAL_SPI_Transmit(&hspi1,  &pTxData, 2, 10);
	pTxData = DATA.DTC_3[3];
	HAL_SPI_Transmit(&hspi1, &pTxData, 2, 10);
	pTxData = DATA.DTC_3[4];
	HAL_SPI_Transmit(&hspi1,  &pTxData, 2, 10);

	return Return_OK;
}








