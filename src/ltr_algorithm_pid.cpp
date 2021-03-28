#include "ltr_main.h"

double g_turn_kp = 0.0;
double g_turn_ki = 0.0;
double g_turn_kd = 0.0;
double g_turn_p  = 0.0;
double g_turn_i  = 0.0;
double g_turn_d  = 0.0;

double g_turn_error_k0   = 2.0;
double g_turn_error_k1   = 1.0;
double g_turn_error      = 0.0;
double g_turn_error_last = 0.0;

uint32_t g_timer_turn_pid = 0;

void cacluteTurnPID(void) {
    uint64_t ms = millis();
    if (ms - g_timer_turn_pid > 50) {
#ifdef DEBUG_PID_CYCLE
        printf("Time turn: %dms", ms);
#endif
        // 获取每个红外传感器的模拟值
        uint16_t a0 = analogRead(A0);
        uint16_t a1 = analogRead(A1);
        uint16_t a2 = analogRead(A2);
        uint16_t a3 = analogRead(A3);

        // 使用加权求和的方式来表示系统误差
        g_turn_error = g_turn_error + g_turn_error_k0 * a0;
        g_turn_error = g_turn_error + g_turn_error_k1 * a1;
        g_turn_error = g_turn_error - g_turn_error_k1 * a2;
        g_turn_error = g_turn_error - g_turn_error_k0 * a3;

        // 转向环
        g_turn_p = g_turn_kp * g_turn_error;
        g_turn_i = g_turn_ki * (g_turn_i + g_turn_error);
        g_turn_d = g_turn_kd * (g_turn_error - g_turn_error_last);
        double g_turn = g_turn_p + g_turn_i + g_turn_d;

        // 根据计算结果控制电机转向
        if (g_turn > 0) {
            // setMotorDirection(MOTOR_A, MOTOR_FRONT);
            // setMotorDirection(MOTOR_B, MOTOR_BACK);
        }
        else if (g_turn < 0) {
            // setMotorDirection(MOTOR_A, MOTOR_BACK);
            // setMotorDirection(MOTOR_B, MOTOR_FRONT);
        }
        else {
            // setMotorDirection(MOTOR_A, MOTOR_FRONT);
            // setMotorDirection(MOTOR_B, MOTOR_FRONT);
        }

        g_turn_error_last = g_turn_error;
        g_timer_turn_pid = millis();
    }
}
