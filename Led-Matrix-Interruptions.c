#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"
#include <stdint.h>

#include "ws2812.pio.h"  // Ajustado para ws2812 padrão

#define LED_COUNT 25
#define LED_PIN 7
#define BOTAO_A 5
#define BOTAO_B 6
#define LED_R 13
#define BLINK_INTERVAL 100
#define DEBOUNCE_TIME 300

uint32_t lastBlinkTime = 0;
bool ledState = false;
volatile uint32_t lastPressTimeA = 0;
volatile uint32_t lastPressTimeB = 0;


bool press_buttonA = false;
bool press_buttonB = false;

struct pixel_t {
    uint8_t G, R, B;
};
typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t;

npLED_t leds[LED_COUNT];

PIO np_pio;
uint sm;
volatile int numero_atual = 0;

// Inicializa ws2812
void npInit(uint pin) {
    uint offset = pio_add_program(pio0, &ws2812_program);
    np_pio = pio0;
    sm = pio_claim_unused_sm(np_pio, true);
    ws2812_program_init(np_pio, sm, offset, pin, 800000.f, false);

    for (uint i = 0; i < LED_COUNT; ++i) {
        leds[i].R = 0;
        leds[i].G = 0;
        leds[i].B = 0;
    }
}

void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b) {
    leds[index].R = r;
    leds[index].G = g;
    leds[index].B = b;
}

void npClear() {
    for (uint i = 0; i < LED_COUNT; ++i) {
        npSetLED(i, 0, 0, 0);
    }
}

void npWrite() {
    for (uint i = 0; i < LED_COUNT; ++i) {
        pio_sm_put_blocking(np_pio, sm, (leds[i].G << 16) | (leds[i].R << 8) | leds[i].B);
    }
    sleep_us(100);
}


uint32_t numeros[10][LED_COUNT] = {
    {1, 1, 1, 1, 1,
     1, 0, 0, 0, 1,
     1, 0, 0, 0, 1,
     1, 0, 0, 0, 1,
     1, 1, 1, 1, 1}, // 0
    
    {0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0}, // 1
    
    {1, 1, 1, 1, 1,
     0, 0, 0, 0, 1,
     1, 1, 1, 1, 1,
     1, 0, 0, 0, 0,
     1, 1, 1, 1, 1}, // 2
    
    {1, 1, 1, 1, 1,
     0, 0, 0, 0, 1,
     0, 1, 1, 1, 1,
     0, 0, 0, 0, 1,
     1, 1, 1, 1, 1}, // 3
    
    {1, 0, 0, 0, 1,
     1, 0, 0, 0, 1,
     1, 1, 1, 1, 1,
     0, 0, 0, 0, 1,
     0, 0, 0, 0, 1}, // 4
    
    {1, 1, 1, 1, 1,
     1, 0, 0, 0, 0,
     1, 1, 1, 1, 1,
     0, 0, 0, 0, 1,
     1, 1, 1, 1, 1}, // 5
    
    {1, 1, 1, 1, 1,
     1, 0, 0, 0, 0,
     1, 1, 1, 1, 1,
     1, 0, 0, 0, 1,
     1, 1, 1, 1, 1}, // 6
    
    {1, 1, 1, 1, 1,
     0, 0, 0, 0, 1,
     0, 0, 0, 1, 0,
     0, 0, 1, 0, 0,
     0, 1, 0, 0, 0}, // 7
    
    {1, 1, 1, 1, 1,
     1, 0, 0, 0, 1,
     1, 1, 1, 1, 1,
     1, 0, 0, 0, 1,
     1, 1, 1, 1, 1}, // 8
    
    {1, 1, 1, 1, 1,
     1, 0, 0, 0, 1,
     1, 1, 1, 1, 1,
     0, 0, 0, 0, 1,
     1, 1, 1, 1, 1}  // 9
};

void mostrarNumero(int numero) {
    npClear();
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            int index = (4 - y) * 5 + ((4 - y) % 2 == 0 ? (4 - x) : x);
            if (numeros[numero][y * 5 + x]) {
                npSetLED(index, 255, 0, 0);
            }
        }
    }
    npWrite();
}

// Função de interrupção dos botões
void gpio_callback(uint gpio, uint32_t events) {
    uint32_t currentTime = to_ms_since_boot(get_absolute_time());

    if (gpio == BOTAO_A && (currentTime - lastPressTimeA > DEBOUNCE_TIME)) {
        lastPressTimeA = currentTime;
        if (numero_atual < 9) {
            numero_atual++;
            printf("Numero atual: %d\n", numero_atual);
            press_buttonA = true;
        }
    }

    if (gpio == BOTAO_B && (currentTime - lastPressTimeB > DEBOUNCE_TIME)) {
        lastPressTimeB = currentTime;
        if (numero_atual > 0) {
            numero_atual--;
            printf("Numero atual: %d\n", numero_atual);
            press_buttonB = true;
        }
    }
}

// Função para piscar LED vermelho 5 vezes por segundo
void piscarLED() {
    uint32_t currentTime = to_ms_since_boot(get_absolute_time());
    if (currentTime - lastBlinkTime >= BLINK_INTERVAL) {
        lastBlinkTime = currentTime;
        ledState = !ledState;
        gpio_put(LED_R, ledState);
    }
}

int main() {
    stdio_init_all(); // Inicializa entradas e saídas.

    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);

    gpio_init(BOTAO_A);
    gpio_set_dir(BOTAO_A, GPIO_IN);
    gpio_pull_up(BOTAO_A);
    gpio_set_irq_enabled_with_callback(BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    gpio_init(BOTAO_B);
    gpio_set_dir(BOTAO_B, GPIO_IN);
    gpio_pull_up(BOTAO_B);
    gpio_set_irq_enabled_with_callback(BOTAO_B, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    npInit(LED_PIN);
    npClear();

    while (true) {
        if(press_buttonA){
            mostrarNumero(numero_atual);
            press_buttonA = false;
        }
        if(press_buttonB){
            mostrarNumero(numero_atual);
            press_buttonB = false;
        }

        piscarLED();
    }
}
