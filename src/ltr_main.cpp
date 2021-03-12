#include "ltr_main.h"

int main(void) {
    while (1) {
        delay(1000);
        uint16_t a = analogRead(A0);
        printf("value: %d\n", a);
    }

    // Wire.a = 1;
    // Wire.b = 2;
    // Wire.begin(100);
    // Wire.begin();

    Wire.begin(10);
}
