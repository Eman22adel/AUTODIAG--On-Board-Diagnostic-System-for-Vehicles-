

#include "main.h"
#include "COM_H.h"
#include "DCM.h"
#include "DEM.h"
#include "MASTER_BUS.h"


extern SYSTEM_Data DATA;

Return_Type HAL_DEM_Init(void);

Return_Type HAL_DEM_MainFunction(void){
	// Throttle Position Range
	if (DATA.sensor1 >= THROTTLE_POS_RANG1 && DATA.sensor1 <= THROTTLE_POS_RANG2) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '0';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '7';
		DATA.DTC_1[4] = '9';

		DATA.DTC_2[0] = 'P';
		DATA.DTC_2[1] = '2';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '0';
		DATA.DTC_2[4] = '4';

		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '3';
		DATA.DTC_3[2] = '0';
		DATA.DTC_3[3] = '0';
		DATA.DTC_3[4] = '0';
	}

	// Timing Advance Range
	if (DATA.sensor2 >= TIMING_ADVANCE_RANG1 && DATA.sensor2 <= TIMING_ADVANCE_RANG2) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '0';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '7';
		DATA.DTC_1[4] = '8';

		DATA.DTC_2[0] = 'U';
		DATA.DTC_2[1] = '1';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '0';
		DATA.DTC_2[4] = '4';

		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '3';
		DATA.DTC_3[2] = '0';
		DATA.DTC_3[3] = '0';
		DATA.DTC_3[4] = '0';

	}

	// Air Intake Temperature Range
	if (DATA.sensor3 >= AIR_INTAKE_TEMP_RANG1 && DATA.sensor3 <= AIR_INTAKE_TEMP_RANG2) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '0';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '7';
		DATA.DTC_1[4] = '9';

		DATA.DTC_2[0] = 'C';
		DATA.DTC_2[1] = '1';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '0';
		DATA.DTC_2[4] = '4';

		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '3';
		DATA.DTC_3[2] = '0';
		DATA.DTC_3[3] = '0';
		DATA.DTC_3[4] = '0';

	}

	// Intake Manifold Pressure Range
	if (DATA.sensor4 >= INTAKE_MANIFOLD_PRESSURE_RANG1 && DATA.sensor4 <= INTAKE_MANIFOLD_PRESSURE_RANG2) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '0';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '7';
		DATA.DTC_1[4] = 'E';

		DATA.DTC_2[0] = 'P';
		DATA.DTC_2[1] = '2';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '3';
		DATA.DTC_2[4] = '6';

		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '1';
		DATA.DTC_3[2] = '8';
		DATA.DTC_3[3] = 'E';
		DATA.DTC_3[4] = '0';

	}

	// Engine RPM Range
	if (DATA.sensor5 >= ENGINE_RPM_RANG1 && DATA.sensor5 <= ENGINE_RPM_RANG2) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '0';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '7';
		DATA.DTC_1[4] = 'F';

		DATA.DTC_2[0] = 'P';
		DATA.DTC_2[1] = '2';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '3';
		DATA.DTC_2[4] = '6';

		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '1';
		DATA.DTC_3[2] = '8';
		DATA.DTC_3[3] = 'D';
		DATA.DTC_3[4] = '0';

	}

	// Engine Load Range
	if (DATA.sensor6 >= ENGINE_LOAD_RANG1 && DATA.sensor6  <= ENGINE_LOAD_RANG2) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '0';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '7';
		DATA.DTC_1[4] = '8';

		DATA.DTC_2[0] = 'B';
		DATA.DTC_2[1] = '3';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '0';
		DATA.DTC_2[4] = '0';

		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '0';
		DATA.DTC_3[2] = '0';
		DATA.DTC_3[3] = '7';
		DATA.DTC_3[4] = '9';

	}

	// Engine Power Range
	if (DATA.sensor7 >= ENGINE_POWER_RANG1 && DATA.sensor7 <= ENGINE_POWER_RANG2) {
		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '1';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '0';
		DATA.DTC_1[4] = '4';

		DATA.DTC_2[0] = 'P';
		DATA.DTC_2[1] = '3';
		DATA.DTC_2[2] = '0';
		DATA.DTC_2[3] = '0';
		DATA.DTC_2[4] = '0';

		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '0';
		DATA.DTC_3[2] = '0';
		DATA.DTC_3[3] = '7';
		DATA.DTC_3[4] = 'E';

	}

	// Engine Coolant Temperature Range
	if (DATA.sensor8 >= ENGINE_COOLANT_TEMP_RANG1 && DATA.sensor8 <= ENGINE_COOLANT_TEMP_RANG2) {
		DATA.DTC_3[0] = 'P';
		DATA.DTC_3[1] = '0';
		DATA.DTC_3[2] = '0';
		DATA.DTC_3[3] = '7';
		DATA.DTC_3[4] = 'E';

		DATA.DTC_1[0] = 'P';
		DATA.DTC_1[1] = '2';
		DATA.DTC_1[2] = '0';
		DATA.DTC_1[3] = '3';
		DATA.DTC_1[4] = '6';

		DATA.DTC_2[0] = 'P';
		DATA.DTC_2[1] = '1';
		DATA.DTC_2[2] = '8';
		DATA.DTC_2[3] = 'F';
		DATA.DTC_2[4] = '0';

	}

	return Return_OK;
}
