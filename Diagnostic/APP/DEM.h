/*
 * DEM.h
 *
 *  Created on: Feb 13, 2024
 *      Author: eman adel
 */

#ifndef DEM_H_
#define DEM_H_


/*sensor rang */
// Throttle Position Range
#define THROTTLE_POS_RANG1  1330
#define THROTTLE_POS_RANG2  4780

// Timing Advance Range
#define TIMING_ADVANCE_RANG1  3650
#define TIMING_ADVANCE_RANG2  7490

// Air Intake Temperature Range
#define AIR_INTAKE_TEMP_RANG1  28
#define AIR_INTAKE_TEMP_RANG2  51

// Intake Manifold Pressure Range
#define INTAKE_MANIFOLD_PRESSURE_RANG1  26
#define INTAKE_MANIFOLD_PRESSURE_RANG2  101

// Engine RPM Range
#define ENGINE_RPM_RANG1  707
#define ENGINE_RPM_RANG2  3121

// Engine Load Range
#define ENGINE_LOAD_RANG1  1800
#define ENGINE_LOAD_RANG2  9690

// Engine Power Range
#define ENGINE_POWER_RANG1  14
#define ENGINE_POWER_RANG2  14

// Engine Coolant Temperature Range
#define ENGINE_COOLANT_TEMP_RANG1  44
#define ENGINE_COOLANT_TEMP_RANG2  99


/*DTC Codes*/
/*
#define Intake_Valve_Control_Solenoid_Circuit_Low_Bank_1                P0079
#define Intake_Manifold_Runner_Control_Stuck_Open_Bank_1                P2004
#define Ignition_Coil_Primary_Control_Circuit_Low                       P3000
#define Exhaust_Valve_Control_Solenoid_Circuit_High_Bank_1              P0078
#define Intake_Valve_Control_Solenoid_Circuit_Performance_Bank_1        P007E
#define Exhaust_Gas_Temperature_Sensor_Circuit_High_Bank_2_Sensor_2     P2036
#define Exhaust_Valve_Control_Solenoid_Circuit_Low_Bank_1               P007F
#define Engine_Oil_Temperature_Sensor_Circuit_Low                       P18E0
#define VVEL_Actuator_Motor_Open_Bank_1                                 P1004
#define Coolant_Temperature_Sensor_Circuit_High                         P18D0
#define Fuel_Temperature_Sensor_Circuit_High                            P18F0
#define Transmission_Control_Module_Random_Access_Memory                C1004
#define ECU_Comm_Fault_with_ECM                                         B0004
#define Data_Circuit_High                                               U1004
#define No_DTCs_Detected                                                P0000
*/
Return_Type HAL_DEM_Init(void);

Return_Type HAL_DEM_MainFunction(void);


#endif /* DEM_H_ */
