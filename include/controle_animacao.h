#ifndef ANIMACAO_H
#define ANIMACAO_H


#include "include/reboot.h"
#include "include/buzzer.h"
#include "include/matriz_led.h"
#include "include/animacoes/animacaoT1.h"
#include "include/animacoes/animcaoT2.h"
#include "include/animacoes/animacao_basicas.h"

#include "include/animacoes/animacao_coracao.h"
#include "include/animacoes/animacao_b.h"
#include "include/animacoes/animacao_letra.h"
#include "include/animacoes/animacao_linha.h"
#include "include/animacoes/animacao_circulo.h"
#include "include/animacoes/animacao_estrela.h"
#include "include/animacoes/animacaoT9.h"
#include "include/animacoes/animacaoT0.h"

// Função para desligar todos os LEDs
void desligar_leds() {
    printf("Desligando todos os LEDs.\n");
    off_animation();
    // Implementação para desligar os LEDs
}

// Função para ligar LEDs na cor azul
void ligar_leds_azul() {
    printf("Ligando LEDs na cor azul (100%% intensidade).\n");
    blue_animation();
    // Implementação para LEDs azuis
}

// Função para ligar LEDs na cor vermelha
void ligar_leds_vermelho() {
    printf("Ligando LEDs na cor vermelha (80%% intensidade).\n");
    red_animation();
    // Implementação para LEDs vermelhos
}

// Função para ligar LEDs na cor verde
void ligar_leds_verde() {
    printf("Ligando LEDs na cor verde (50%% intensidade).\n");
    green_animation();
    // Implementação para LEDs verdes
}

// Função para ligar LEDs na cor branca
void ligar_leds_branco() {
    printf("Ligando LEDs na cor branca (20%% intensidade).\n");
    white_animation();
    // Implementação para LEDs brancos
}

// Função para efeito 1
void effect_1(int duration) {
    printf("Executando efeito 1 nos LEDs.\n");
    clock_animation(duration);
}

// Função para efeito 2
void effect_2(int duration) {
    printf("Executando efeito 2 nos LEDs.\n");
    wave_animation(duration);
}

// Função para efeito 3
void effect_3(int duration) {
    printf("Executando efeito 3 nos LEDs.\n");
    heart_animation(duration);
}

// Função para efeito 4
void effect_4(int duration) {
    printf("Executando efeito 4 nos LEDs.\n");
    beer_animation(duration);
}

// Função para efeito 5
void effect_5(int duration) {
    printf("Executando efeito 5 nos LEDs.\n");
    letter_animation(duration);
}

// Função para efeito 6
void effect_6(int duration) {
    printf("Executando efeito 6 nos LEDs.\n");
    line_animation(duration);
}

// Função para efeito 7
void effect_7(int duration) {
    printf("Executando efeito 7 nos LEDs.\n");
    circle_animation(duration);
}

// Função para efeito 8
void effect_8(int duration) {
    printf("Executando efeito 8 nos LEDs.\n");
    star_animation(duration);
}

// Função para efeito 9
void effect_9(int duration) {
    printf("Executando efeito 9 nos LEDs.\n");
    XYZ_animation(duration);
}

// Função para efeito 0
void effect_0(int duration) {
    printf("Executando efeito 0 nos LEDs.\n");
    ten_animation(duration);
}

// Função genérica para um efeito especial
void effect_reboot(int duration) {
    printf("Executando efeito especial.\n");

    effect_1(duration);
    effect_2(duration);
    effect_3(duration);
    effect_4(duration);
    effect_5(duration);
    effect_6(duration);
    effect_7(duration);
    effect_8(duration);
    effect_9(duration);
    effect_0(duration);

    reboot_to_bootloader();
}

#include "pico/multicore.h"

// Estrutura para passar múltiplos argumentos para a thread
typedef struct {
    void (*animation)(int);
    int duration;
} AnimacaoArgs;

void sound(void (*animation)(int), int duration) {
    buzzer_procedural_sound(animation, duration);
}

void core1_entry() {
    while (true) {
        // Espera por dados na FIFO
        uint32_t data = multicore_fifo_pop_blocking();
        if (data == 0) break; // Sinal para terminar

        // Executa a função de som
        AnimacaoArgs* args = (AnimacaoArgs*)data;
        sound(args->animation, args->duration);

        // Adiciona um pequeno atraso para evitar sobrecarga
        sleep_ms(10);
    }
}

// Função geral para executar uma animação com sinal sonoro
void executar_animacao_com_som(void (*animation)(int), int duration) {
    printf("Executando animação com sinal sonoro.\n");

    // Inicializa o segundo núcleo
    multicore_launch_core1(core1_entry);

    // Prepara os argumentos para a função de som
    AnimacaoArgs args = {animation, duration};

    // Envia os argumentos para o segundo núcleo
    multicore_fifo_push_blocking((uint32_t)&args);

    // Executa a animação no núcleo principal
    animation(duration);

    // Sinaliza o segundo núcleo para terminar
    multicore_fifo_push_blocking(0);
}
#endif
