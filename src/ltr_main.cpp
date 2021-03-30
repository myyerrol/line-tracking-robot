#include "ltr_main.h"

int main(void) {
    initMotors();
    setMotorDirection(MOTOR_A, MOTOR_FRONT);
    setMotorDirection(MOTOR_B, MOTOR_FRONT);
    setMotorSpeed(MOTOR_A, MOTOR_SPEED_REF);
    setMotorSpeed(MOTOR_B, MOTOR_SPEED_REF);

    while (1) {
        cacluteTurnPID();
    }
}
