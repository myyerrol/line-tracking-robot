#ifndef LTR_MAIN_H
#define LTR_MAIN_H

#include "RVStarArduino.h"
#include "Wire.h"

#define MOTOR_A       0
#define MOTOR_B       1

#define PIN_MOTOR_IN1 5
#define PIN_MOTOR_IN2 6
#define PIN_MOTOR_IN3 7
#define PIN_MOTOR_IN4 8
#define PIN_MOTOR_ENA 9
#define PIN_MOTOR_ENB 10

typedef enum MotorState {
    MOTOR_FRONT,
    MOTOR_BACK,
    MOTOR_STOP
} MotorState;

void initMotors(void);
void setMotorDirection(uint8_t motor, MotorState state);
void setMotorSpeed(uint8_t motor, int16_t speed);

#endif // LTR_MAIN_H
