#include "ltr_main.h"

double g_turn_p = 0.000;
double g_turn_i = 0.000;
double g_turn_d = 0.000;
uint32_t g_timer_turn_pid = 0;

int main(void) {
    initMotors();
    setMotorDirection(MOTOR_A, MOTOR_BACK);
    setMotorDirection(MOTOR_B, MOTOR_BACK);

    while (1) {
        // setMotorDirection(MOTOR_A, MOTOR_FRONT);
        // setMotorDirection(MOTOR_B, MOTOR_FRONT);
        // uint16_t a0 = analogRead(A0);
        // uint16_t a1 = analogRead(A1);
        // uint16_t a2 = analogRead(A2);
        // uint16_t a3 = analogRead(A3);
        // printf("a0: %d, a1: %d, a2: %d, a3: %d\n", a0, a1, a2, a3);
        delay(1000);
    }
}
