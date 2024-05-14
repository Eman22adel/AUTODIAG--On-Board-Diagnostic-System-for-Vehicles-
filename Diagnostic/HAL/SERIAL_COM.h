/*
 * SERIAL_COM.h
 *
 *  Created on: Feb 13, 2024
 *      Author: eman adel
 */

#ifndef SERIAL_COM_H_
#define SERIAL_COM_H_

Return_Type HAL_SERIAL_COMH_Init(void);

Return_Type HAL_SERIAL_COMH_Receive(uint8_t * RXBUFFER_SIZE);

Return_Type HAL_SERIAL_COMH_Send(uint8_t ID_REQUEST[],uint8_t size);

Return_Type  COPY_STRING(uint8_t arr1[],uint8_t arr2[],uint8_t start,uint8_t end);

#endif /* SERIAL_COM_H_ */
