#ifndef BUZZER_H
#define BUZZER_H

#include "pico/stdlib.h"

// Define os pinos dos buzzers
#define BUZZER_PIN_1 21
#define BUZZER_PIN_2 10

// Inicializa os buzzers
void buzzer_init() {
    gpio_init(BUZZER_PIN_1);
    gpio_set_dir(BUZZER_PIN_1, GPIO_OUT);

    gpio_init(BUZZER_PIN_2);
    gpio_set_dir(BUZZER_PIN_2, GPIO_OUT);
}

// Liga os buzzers com uma frequência específica
void buzzer_on(uint frequency) {
    gpio_put(BUZZER_PIN_1, 1);
    gpio_put(BUZZER_PIN_2, 1);
    sleep_us(1000000 / frequency / 2);

    gpio_put(BUZZER_PIN_1, 0);
    gpio_put(BUZZER_PIN_2, 0);
    sleep_us(1000000 / frequency / 2);
}

// Desliga os buzzers
void buzzer_off() {
    gpio_put(BUZZER_PIN_1, 0);

    gpio_put(BUZZER_PIN_2, 0);
}

// Gera um som procedural baseado na seed da animação
void buzzer_procedural_sound(void (*animation)(), int duration) {
    uint seed = (uint)(uintptr_t)animation; // Usa o endereço do ponteiro da função como seed

    for (int i = 0; i < duration; i += 10) {
        uint frequency = 1000 + (seed % 500) + (i % 500); // Gera a frequência de forma procedural
        buzzer_on(frequency);
    }

    buzzer_off();
}

#endif