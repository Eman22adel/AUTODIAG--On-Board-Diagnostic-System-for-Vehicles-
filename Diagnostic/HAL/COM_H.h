/*
 * COM_H.h
 *
 *  Created on: Mar 1, 2024
 *      Author: eman adel
 */

#ifndef COM_H_H_
#define COM_H_H_


#define REQUEST 30

Return_Type HAL_COMH_Init(void);

Return_Type HAL_COMH_Receive(uint8_t *BUFFER);

Return_Type HAL_COMH_SendDATA(SYSTEM_Data DATA);


#endif /* COM_H_H_ */
