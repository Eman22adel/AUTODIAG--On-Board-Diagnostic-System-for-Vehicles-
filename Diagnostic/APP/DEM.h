/*
 * DEM.h
 *
 *  Created on: Feb 13, 2024
 *  Author: eman adel
 */

#ifndef DEM_H_
#define DEM_H_


/*sensor rang */
// Throttle Position Range
#define THROTTLE_POS_RANG1  1330
#define THROTTLE_POS_RANG2  1762
#define THROTTLE_POS_RANG3  2194
#define THROTTLE_POS_RANG4  2626
#define THROTTLE_POS_RANG5  3058
#define THROTTLE_POS_RANG6  3490
#define THROTTLE_POS_RANG7  3922
#define THROTTLE_POS_RANG8  4354



// Timing Advance Range
#define TIMING_ADVANCE_RANG1  3650
#define TIMING_ADVANCE_RANG2  4130
#define TIMING_ADVANCE_RANG3  4610
#define TIMING_ADVANCE_RANG4  5090
#define TIMING_ADVANCE_RANG5  5570
#define TIMING_ADVANCE_RANG6  6050
#define TIMING_ADVANCE_RANG7  6530
#define TIMING_ADVANCE_RANG8  7010


// Air Intake Temperature Range
#define AIR_INTAKE_TEMP_RANG1  28
#define AIR_INTAKE_TEMP_RANG2  31
#define AIR_INTAKE_TEMP_RANG3  34
#define AIR_INTAKE_TEMP_RANG4  37
#define AIR_INTAKE_TEMP_RANG5  40
#define AIR_INTAKE_TEMP_RANG6  43
#define AIR_INTAKE_TEMP_RANG7  46
#define AIR_INTAKE_TEMP_RANG8  49


// Intake Manifold Pressure Range
#define INTAKE_MANIFOLD_PRESSURE_RANG1  26
#define INTAKE_MANIFOLD_PRESSURE_RANG2  36
#define INTAKE_MANIFOLD_PRESSURE_RANG3  46
#define INTAKE_MANIFOLD_PRESSURE_RANG4  56
#define INTAKE_MANIFOLD_PRESSURE_RANG5  66
#define INTAKE_MANIFOLD_PRESSURE_RANG6  76
#define INTAKE_MANIFOLD_PRESSURE_RANG7  86
#define INTAKE_MANIFOLD_PRESSURE_RANG8  96


// Engine RPM Range
#define ENGINE_RPM_RANG1  707
#define ENGINE_RPM_RANG2  1009
#define ENGINE_RPM_RANG3  1311
#define ENGINE_RPM_RANG4  1613
#define ENGINE_RPM_RANG5  1915
#define ENGINE_RPM_RANG6  2217
#define ENGINE_RPM_RANG7  2519
#define ENGINE_RPM_RANG8  2821



// Engine Load Range
#define ENGINE_LOAD_RANG1  1800
#define ENGINE_LOAD_RANG2  2787
#define ENGINE_LOAD_RANG3  3774
#define ENGINE_LOAD_RANG4  4761
#define ENGINE_LOAD_RANG5  5748
#define ENGINE_LOAD_RANG6  6735
#define ENGINE_LOAD_RANG7  7722
#define ENGINE_LOAD_RANG8  8709


// Engine Coolant Temperature Range
#define ENGINE_COOLANT_TEMP_RANG1  44
#define ENGINE_COOLANT_TEMP_RANG2  51
#define ENGINE_COOLANT_TEMP_RANG3  58
#define ENGINE_COOLANT_TEMP_RANG4  65
#define ENGINE_COOLANT_TEMP_RANG5  72
#define ENGINE_COOLANT_TEMP_RANG6  79
#define ENGINE_COOLANT_TEMP_RANG7  86
#define ENGINE_COOLANT_TEMP_RANG8  93

// Engine Power Range
#define ENGINE_POWER_RANG1  14
#define ENGINE_POWER_RANG2  14


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
