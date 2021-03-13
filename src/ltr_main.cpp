#include "ltr_main.h"

int main(void) {
    Wire.begin();

    while (1) {
        uint16_t a = analogRead(A0);
        printf("value: %d\n", a);
        delay(1000);
    }
}
