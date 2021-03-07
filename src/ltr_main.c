#include "ltr_main.h"

int main(void) {
    // pinMode(11, OUTPUT);

    while (1) {
        for (uint8_t i = 0; i < 255; i++) {
            analogWrite(11, i);
            delay(10);
        }
    }
}
