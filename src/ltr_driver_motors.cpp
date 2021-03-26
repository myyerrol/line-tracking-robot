#include "ltr_main.h"

void initMotors(void) {
    pinMode(PIN_MOTOR_AIN1, OUTPUT);
    pinMode(PIN_MOTOR_AIN2, OUTPUT);
    pinMode(PIN_MOTOR_BIN1, OUTPUT);
    pinMode(PIN_MOTOR_BIN2, OUTPUT);
    pinMode(PIN_MOTOR_PWMA, OUTPUT);
    pinMode(PIN_MOTOR_PWMB, OUTPUT);

    setMotorDirection(MOTOR_A, MOTOR_STOP);
    setMotorDirection(MOTOR_B, MOTOR_STOP);
}

void setMotorDirection(uint8_t motor, MotorState state) {
    if (state == MOTOR_FRONT) {
        if (motor == MOTOR_A) {
            digitalWrite(PIN_MOTOR_AIN1, LOW);
            digitalWrite(PIN_MOTOR_AIN2, HIGH);
        }
        else if (motor == MOTOR_B) {
            digitalWrite(PIN_MOTOR_BIN1, HIGH);
            digitalWrite(PIN_MOTOR_BIN2, LOW);
        }
        else {
            return;
        }
    }
    else if (state == MOTOR_BACK) {
        if (motor == MOTOR_A) {
            digitalWrite(PIN_MOTOR_AIN1, HIGH);
            digitalWrite(PIN_MOTOR_AIN2, LOW);
        }
        else if (motor == MOTOR_B) {
            digitalWrite(PIN_MOTOR_BIN1, LOW);
            digitalWrite(PIN_MOTOR_BIN2, HIGH);
        }
        else {
            return;
        }
    }
    else if (state == MOTOR_STOP) {
        if (motor == MOTOR_A) {
            digitalWrite(PIN_MOTOR_AIN1, LOW);
            digitalWrite(PIN_MOTOR_AIN2, LOW);
        }
        else if (motor == MOTOR_B) {
            digitalWrite(PIN_MOTOR_BIN1, LOW);
            digitalWrite(PIN_MOTOR_BIN2, LOW);
        }
        else {
            return;
        }
    }
    else {
        return;
    }
}

void setMotorSpeed(uint8_t motor, int16_t speed) {
    speed = constrain(abs(speed), 0, 255);

    if (motor == MOTOR_A) {
        analogWrite(PIN_MOTOR_PWMA, speed);
    }
    else if (motor == MOTOR_B) {
        analogWrite(PIN_MOTOR_PWMB, speed);
    }
}
