/*
 * SERIAL_COM.h
 *
 *  Created on: Feb 13, 2024
 *      Author: eman adel
 */

#ifndef SERIAL_COM_H_
#define SERIAL_COM_H_


typedef struct{
	uint16_t sensor1;
	uint16_t sensor2;
	uint16_t sensor3;
	uint16_t sensor4;
	uint16_t sensor5;
	uint16_t sensor6;
	uint16_t sensor7;
	uint16_t sensor8;

	uint8_t DTC_1[5];
	uint8_t DTC_2[5];
	uint8_t DTC_3[5];

}SYSTEM_Data;

Return_Type SERIAL_COM_Init(void);

Return_Type SERIAL_COM_Receive(uint8_t * RXBUFFER);

Return_Type SERIAL_COM_Send(uint8_t  *TXBUFFER , uint8_t size);

//Return_Type SERIAL_COM_Send(void);


#endif /* SERIAL_COM_H_ */
