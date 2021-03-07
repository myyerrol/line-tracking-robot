#ifndef RVSTAR_ARDUINO_H
#define RVSTAR_ARDUINO_H

#ifdef cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "gd32vf103.h"
#include "gd32vf103_libopt.h"

// 仅支持Arduino UNO标准引脚（D0-D13, A0-A5）
// Only Arduino Uno standard pins are supported(D0-D13, A0-A5)
#define A0           14
#define A1           15
#define A2           16
#define A3           17
#define A4           18
#define A5           19

// 引用自Arduino.h文件
// Reference from Arduino.h file
#define LOW          0x0
#define HIGH         0x1

#define INPUT        0x0
#define OUTPUT       0x1
#define INPUT_PULLUP 0x2

#define PI           3.1415926535897932384626433832795
#define HALF_PI      1.5707963267948966192313216916398
#define TWO_PI       6.283185307179586476925286766559
#define DEG_TO_RAD   0.017453292519943295769236907684886
#define RAD_TO_DEG   57.295779513082320876798154814105
#define EULER        2.718281828459045235360287471352

#define SERIAL       0x0
#define DISPLAY      0x1

#define LSBFIRST     0
#define MSBFIRST     1

#define CHANGE       1
#define FALLING      2
#define RISING       3

#ifdef abs
#undef abs
#endif

#define min(a, b)                      ((a) < (b) ? (a) : (b))
#define max(a, b)                      ((a) > (b) ? (a) : (b))
#define abs(x)                         ((x) > 0 ? (x) : -(x))
#define constrain(amt, low, high)      ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))
#define round(x)                       ((x) >= 0 ? (long)((x) + 0.5) : (long)((x) - 0.5))
#define radians(deg)                   ((deg) * DEG_TO_RAD)
#define degrees(rad)                   ((rad) * RAD_TO_DEG)
#define sq(x)                          ((x) * (x))

#define lowByte(w)                     ((uint8_t) ((w) & 0xff))
#define highByte(w)                    ((uint8_t) ((w) >> 8))

#define bitRead(value, bit)            (((value) >> (bit)) & 0x01)
#define bitSet(value, bit)             ((value) |= (1UL << (bit)))
#define bitClear(value, bit)           ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit)          ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

#define bit(b)                         (1UL << (b))

typedef unsigned int word;
typedef bool boolean;
typedef uint8_t byte;

void initTimerPWMMode(uint8_t pin);

int analogRead(uint8_t pin);
void analogReference(uint8_t mode);
void analogWrite(uint8_t pin, int val);
int digitalRead(uint8_t pin);
void digitalWrite(uint8_t pin, uint8_t val);
void pinMode(uint8_t pin, uint8_t mode);

void delay(unsigned long ms);
void delayMicroseconds(unsigned int us);
unsigned long micros(void);
unsigned long millis(void);

#ifdef cplusplus
}
#endif

#endif // RVSTAR_ARDUINO_H
