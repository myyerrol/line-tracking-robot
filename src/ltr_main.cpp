#include "ltr_main.h"

#define DEBUG_PID_CYCLE

int main(void) {
    initMotors();
    setMotorDirection(MOTOR_A, MOTOR_FRONT);
    setMotorDirection(MOTOR_B, MOTOR_FRONT);
    setMotorSpeed(MOTOR_A, 200);
    setMotorSpeed(MOTOR_B, 200);

    while (1) {
        // cacluteTurnPID();

        uint16_t a0 = analogRead(A0);
        uint16_t a1 = analogRead(A1);
        uint16_t a2 = analogRead(A2);
        uint16_t a3 = analogRead(A3);
        printf("a0: %d, a1: %d, a2: %d, a3: %d\n", a0, a1, a2, a3);
        delay(1000);
    }
}
