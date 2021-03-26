#ifndef LTR_MAIN_H
#define LTR_MAIN_H

#include "RVStarArduino.h"
#include "Wire.h"

#define MOTOR_A        0
#define MOTOR_B        1

#define PIN_MOTOR_AIN1 5
#define PIN_MOTOR_AIN2 6
#define PIN_MOTOR_BIN1 7
#define PIN_MOTOR_BIN2 8
#define PIN_MOTOR_PWMA 9
#define PIN_MOTOR_PWMB 10

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
