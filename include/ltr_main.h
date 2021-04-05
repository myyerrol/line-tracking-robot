#ifndef LTR_MAIN_H
#define LTR_MAIN_H

#include "RVStarArduino.h"

#define MOTOR_A        0
#define MOTOR_B        1

#define PIN_MOTOR_AIN1 5
#define PIN_MOTOR_AIN2 6
#define PIN_MOTOR_BIN1 7
#define PIN_MOTOR_BIN2 8
#define PIN_MOTOR_PWMA 9
#define PIN_MOTOR_PWMB 11

#define MOTOR_SPEED_REF 120

#define DEBUG_ADC_VALUE
#define DEBUG_MTR_VALUE
#define DEBUG_PID_CYCLE
#define DEBUG_PID_VALUE

typedef enum MotorState {
    MOTOR_FRONT,
    MOTOR_BACK,
    MOTOR_STOP
} MotorState;

void initMotors(void);
void setMotorDirection(uint8_t motor, MotorState state);
void setMotorSpeed(uint8_t motor, int16_t speed);
void cacluteTurnPID(void);

#endif // LTR_MAIN_H
