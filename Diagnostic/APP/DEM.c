/*
 * DEM.C
 *
 *  Created on: Feb 13, 2024
 *  Author: eman adel
 */

#include "main.h"
#include "SERIAL_COM.h"
#include "COM_H.h"
#include "DCM.h"
#include "DEM.h"
#include "MASTER_BUS.h"


static uint8_t First_Data_Done = 1;
extern SYSTEM_Data DATA;

Return_Type HAL_DEM_Init(void);

Return_Type HAL_DEM_MainFunction(void){

	/*
	 *
	 *
	 * DTC 1
	 *
	 *
	 * */

	if (((DATA.sensor7 >= THROTTLE_POS_RANG1 && DATA.sensor7 <= THROTTLE_POS_RANG2) ||
			(DATA.sensor8 >= TIMING_ADVANCE_RANG1 && DATA.sensor8 <= TIMING_ADVANCE_RANG2))) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '0';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '7';
		DATA.DTC_1[4] = '9';
	} else if ((DATA.sensor7 > THROTTLE_POS_RANG2 && DATA.sensor7 <= THROTTLE_POS_RANG3) ||
			(DATA.sensor8 > TIMING_ADVANCE_RANG2 && DATA.sensor8 <= TIMING_ADVANCE_RANG3)) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '0';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '7';
		DATA.DTC_1[4] = '8';
	} else if ((DATA.sensor7 > THROTTLE_POS_RANG3 && DATA.sensor7 <= THROTTLE_POS_RANG4) ||
			(DATA.sensor8 > TIMING_ADVANCE_RANG3 && DATA.sensor8 <= TIMING_ADVANCE_RANG4)) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '0';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '7';
		DATA.DTC_1[4] = 'E';
	} else if ((DATA.sensor7 > THROTTLE_POS_RANG4 && DATA.sensor7 <= THROTTLE_POS_RANG5) ||
			(DATA.sensor8 > TIMING_ADVANCE_RANG4 && DATA.sensor8 <= TIMING_ADVANCE_RANG5)) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '0';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '7';
		DATA.DTC_1[4] = 'F';
	} else if ((DATA.sensor7 > THROTTLE_POS_RANG5 && DATA.sensor7 <= THROTTLE_POS_RANG6) ||
			(DATA.sensor8 > TIMING_ADVANCE_RANG5 && DATA.sensor8 <= TIMING_ADVANCE_RANG6)) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '0';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '7';
		DATA.DTC_1[4] = '8';
	} else if ((DATA.sensor7 > THROTTLE_POS_RANG6 && DATA.sensor7 <= THROTTLE_POS_RANG7) ||
			(DATA.sensor8 > TIMING_ADVANCE_RANG6 && DATA.sensor8 <= TIMING_ADVANCE_RANG7)) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '1';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '0';
		DATA.DTC_1[4] = '4';
	} else if ((DATA.sensor7 > THROTTLE_POS_RANG7 && DATA.sensor7 <= THROTTLE_POS_RANG8) ||
			(DATA.sensor8 > TIMING_ADVANCE_RANG7 && DATA.sensor8 <= TIMING_ADVANCE_RANG8)) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '2';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '3';
		DATA.DTC_1[4] = '6';
	}else if ((DATA.sensor7 > THROTTLE_POS_RANG8) ||
			(DATA.sensor8 > TIMING_ADVANCE_RANG8)) {

		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '2';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '3';
		DATA.DTC_1[4] = '6';

	} else {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '0';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '0';
		DATA.DTC_1[4] = '0';
	}



	/*
	 *
	 *
	 * DTC 2
	 *
	 *
	 * */


	if (((DATA.sensor6 >= AIR_INTAKE_TEMP_RANG1 && DATA.sensor6 <= AIR_INTAKE_TEMP_RANG2) ||
			(DATA.sensor5 >= INTAKE_MANIFOLD_PRESSURE_RANG1 && DATA.sensor5 <= INTAKE_MANIFOLD_PRESSURE_RANG2))) {
		DATA.DTC_2[0] = 'P';
		DATA.DTC_2[1] = '1';
		DATA.DTC_2[2] = '8';
		DATA.DTC_2[3] = 'F';
		DATA.DTC_2[4] = '0';
	} else if ((DATA.sensor6 > AIR_INTAKE_TEMP_RANG2 && DATA.sensor6 <= AIR_INTAKE_TEMP_RANG3) ||
			(DATA.sensor5 > INTAKE_MANIFOLD_PRESSURE_RANG2 && DATA.sensor5 <= INTAKE_MANIFOLD_PRESSURE_RANG3)) {
		DATA.DTC_2[0] = 'P';
		DATA.DTC_2[1] = '3';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '0';
		DATA.DTC_2[4] = '0';
	} else if ((DATA.sensor6 > AIR_INTAKE_TEMP_RANG3 && DATA.sensor6 <= AIR_INTAKE_TEMP_RANG4) ||
			(DATA.sensor5 > INTAKE_MANIFOLD_PRESSURE_RANG3 && DATA.sensor5 <= INTAKE_MANIFOLD_PRESSURE_RANG4)) {
		DATA.DTC_2[0] = 'B';
		DATA.DTC_2[1] = '3';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '0';
		DATA.DTC_2[4] = '0';
	} else if ((DATA.sensor6 > AIR_INTAKE_TEMP_RANG4 && DATA.sensor6 <= AIR_INTAKE_TEMP_RANG5) ||
			(DATA.sensor5 > INTAKE_MANIFOLD_PRESSURE_RANG4 && DATA.sensor5 <= INTAKE_MANIFOLD_PRESSURE_RANG2)) {
		DATA.DTC_2[0] = 'P';
		DATA.DTC_2[1] = '2';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '3';
		DATA.DTC_2[4] = '6';
	} else if ((DATA.sensor6 > AIR_INTAKE_TEMP_RANG5 && DATA.sensor6 <= AIR_INTAKE_TEMP_RANG6) ||
			(DATA.sensor5 > INTAKE_MANIFOLD_PRESSURE_RANG2 && DATA.sensor5 <= INTAKE_MANIFOLD_PRESSURE_RANG2)) {
		DATA.DTC_2[0] = 'P';
		DATA.DTC_2[1] = '2';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '3';
		DATA.DTC_2[4] = '6';
	} else if ((DATA.sensor6 > AIR_INTAKE_TEMP_RANG6 && DATA.sensor6 <= AIR_INTAKE_TEMP_RANG7) ||
			(DATA.sensor5 > INTAKE_MANIFOLD_PRESSURE_RANG2 && DATA.sensor5 <= INTAKE_MANIFOLD_PRESSURE_RANG7)) {
		DATA.DTC_2[0] = 'C';
		DATA.DTC_2[1] = '1';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '0';
		DATA.DTC_2[4] = '4';
	} else if ((DATA.sensor6 > AIR_INTAKE_TEMP_RANG7 && DATA.sensor6 <= AIR_INTAKE_TEMP_RANG8) ||
			(DATA.sensor5 > INTAKE_MANIFOLD_PRESSURE_RANG7 && DATA.sensor5 <= INTAKE_MANIFOLD_PRESSURE_RANG8)) {
		DATA.DTC_2[0] = 'U';
		DATA.DTC_2[1] = '1';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '0';
		DATA.DTC_2[4] = '4';
	}else if ((DATA.sensor6 > AIR_INTAKE_TEMP_RANG8) ||
			(DATA.sensor5 > INTAKE_MANIFOLD_PRESSURE_RANG8)) {
		DATA.DTC_2[0] = 'P';
		DATA.DTC_2[1] = '2';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '0';
		DATA.DTC_2[4] = '4';
	} else {
		DATA.DTC_2[0] = 'P';
		DATA.DTC_2[1] = '0';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '0';
		DATA.DTC_2[4] = '0';
	}


	/*
	 *
	 *
	 * DTC 3
	 *
	 *
	 * */

	if (((DATA.sensor2 >= ENGINE_COOLANT_TEMP_RANG1 && DATA.sensor2 <= ENGINE_COOLANT_TEMP_RANG2) ||
			(DATA.sensor3 >= ENGINE_LOAD_RANG1 && DATA.sensor3 <= ENGINE_LOAD_RANG2) ||
			(DATA.sensor4 >= ENGINE_RPM_RANG1 && DATA.sensor4 <= ENGINE_RPM_RANG2))) {
		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '3';
		DATA.DTC_3[2] = '0';
		DATA.DTC_3[3] = '0';
		DATA.DTC_3[4] = '0';
	} else if ((DATA.sensor2 > ENGINE_COOLANT_TEMP_RANG2 && DATA.sensor2 <= ENGINE_COOLANT_TEMP_RANG3) ||
			(DATA.sensor3 > ENGINE_LOAD_RANG2 && DATA.sensor3 <= ENGINE_LOAD_RANG3) ||
			(DATA.sensor4 > ENGINE_RPM_RANG2 && DATA.sensor4 <= ENGINE_RPM_RANG3)) {
		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '3';
		DATA.DTC_3[2] = '0';
		DATA.DTC_3[3] = '0';
		DATA.DTC_3[4] = '0';
	} else if ((DATA.sensor2 > ENGINE_COOLANT_TEMP_RANG3 && DATA.sensor2 <= ENGINE_COOLANT_TEMP_RANG4) ||
			(DATA.sensor3 > ENGINE_LOAD_RANG3 && DATA.sensor3 <= ENGINE_LOAD_RANG4) ||
			(DATA.sensor4 > ENGINE_RPM_RANG3 && DATA.sensor4 <= ENGINE_RPM_RANG4)) {
		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '3';
		DATA.DTC_3[2] = '0';
		DATA.DTC_3[3] = '0';
		DATA.DTC_3[4] = '0';
	} else if ((DATA.sensor2 > ENGINE_COOLANT_TEMP_RANG4 && DATA.sensor2 <= ENGINE_COOLANT_TEMP_RANG5) ||
			(DATA.sensor3 > ENGINE_LOAD_RANG4 && DATA.sensor3 <= ENGINE_LOAD_RANG5) ||
			(DATA.sensor4 > ENGINE_RPM_RANG4 && DATA.sensor4 <= ENGINE_RPM_RANG5)) {
		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '1';
		DATA.DTC_3[2] = '8';
		DATA.DTC_3[3] = 'E';
		DATA.DTC_3[4] = '0';
	} else if ((DATA.sensor2 > ENGINE_COOLANT_TEMP_RANG5 && DATA.sensor2 <= ENGINE_COOLANT_TEMP_RANG6) ||
			(DATA.sensor3 > ENGINE_LOAD_RANG5 && DATA.sensor3 <= ENGINE_LOAD_RANG6) ||
			(DATA.sensor4 > ENGINE_RPM_RANG5 && DATA.sensor4 <= ENGINE_RPM_RANG6)) {
		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '1';
		DATA.DTC_3[2] = '8';
		DATA.DTC_3[3] = 'D';
		DATA.DTC_3[4] = '0';
	} else if ((DATA.sensor2 > ENGINE_COOLANT_TEMP_RANG6 && DATA.sensor2 <= ENGINE_COOLANT_TEMP_RANG7) ||
			(DATA.sensor3 > ENGINE_LOAD_RANG6 && DATA.sensor3 <= ENGINE_LOAD_RANG7) ||
			(DATA.sensor4 > ENGINE_RPM_RANG6 && DATA.sensor4 <= ENGINE_RPM_RANG7)) {
		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '0';
		DATA.DTC_3[2] = '0';
		DATA.DTC_3[3] = '7';
		DATA.DTC_3[4] = '9';
	} else if ((DATA.sensor2 > ENGINE_COOLANT_TEMP_RANG7 && DATA.sensor2 <= ENGINE_COOLANT_TEMP_RANG8) ||
			(DATA.sensor3 > ENGINE_LOAD_RANG7 && DATA.sensor3 <= ENGINE_LOAD_RANG8) ||
			(DATA.sensor4 > ENGINE_RPM_RANG7 && DATA.sensor4 <= ENGINE_RPM_RANG8)) {
		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '0';
		DATA.DTC_3[2] = '0';
		DATA.DTC_3[3] = '7';
		DATA.DTC_3[4] = 'E';
	} else if ((DATA.sensor2 > ENGINE_COOLANT_TEMP_RANG8) ||
			(DATA.sensor3 > ENGINE_LOAD_RANG8) ||
			(DATA.sensor4 > ENGINE_RPM_RANG8)) {
		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '0';
		DATA.DTC_3[2] = '0';
		DATA.DTC_3[3] = '7';
		DATA.DTC_3[4] = 'E';
	} else {
		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '0';
		DATA.DTC_3[2] = '0';
		DATA.DTC_3[3] = '0';
		DATA.DTC_3[4] = '0';
	}


	return Return_OK;
}

