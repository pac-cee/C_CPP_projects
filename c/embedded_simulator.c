// Embedded System Simulator in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate_sensor() {
    int value = rand() % 100; // Simulated sensor value
    printf("Sensor value: %d\n", value);
}

void control_led(int value) {
    if (value > 50)
        printf("LED ON\n");
    else
        printf("LED OFF\n");
}

int main() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++) {
        int sensor = rand() % 100;
        simulate_sensor();
        control_led(sensor);
    }
    return 0;
}
