#include "ltr_main.h"

int main(void) {
    // pinMode(11, OUTPUT);

    while (1) {
        delay(1000);
        // printf("测试\n");
        uint16_t a = analogRead(A0);
        printf("value: %d\n", a);
    }
}
