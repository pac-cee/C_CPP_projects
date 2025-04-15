// Embedded GPIO Simulator in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GPIO_PIN_COUNT 4

void write_gpio(int pin, int value) {
    printf("GPIO %d set to %d\n", pin, value);
}

int main() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; ++i) {
        int pin = rand() % GPIO_PIN_COUNT;
        int value = rand() % 2;
        write_gpio(pin, value);
    }
    return 0;
}
