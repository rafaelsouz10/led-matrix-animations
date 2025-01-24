#ifndef ANIMACAO_H
#define ANIMACAO_H


#include "include/matriz_led.h"
#include "include/animacoes/animacaoT1.h"
#include "include/animacoes/animcaoT2.h"
#include "include/animacoes/animacao_coracao.h"
#include "include/animacoes/animacao_b.h"


// Função para desligar todos os LEDs
void desligar_leds() {
    printf("Desligando todos os LEDs.\n");
    // Implementação para desligar os LEDs
}

// Função para ligar LEDs na cor azul
void ligar_leds_azul() {
    printf("Ligando LEDs na cor azul (100%% intensidade).\n");
    // Implementação para LEDs azuis
}

// Função para ligar LEDs na cor vermelha
void ligar_leds_vermelho() {
    printf("Ligando LEDs na cor vermelha (80%% intensidade).\n");
    // Implementação para LEDs vermelhos
}

// Função para ligar LEDs na cor verde
void ligar_leds_verde() {
    printf("Ligando LEDs na cor verde (50%% intensidade).\n");
    // Implementação para LEDs verdes
}

// Função para ligar LEDs na cor branca
void ligar_leds_branco() {
    printf("Ligando LEDs na cor branca (20%% intensidade).\n");
    // Implementação para LEDs brancos
}

// Função para efeito 1
void efect_1() {
    printf("Executando efeito 1 nos LEDs.\n");
    clock_animation(500);
}

// Função para efeito 2
void efect_2() {
    printf("Executando efeito 2 nos LEDs.\n");
    wave_animation(200);
}

// Função para efeito 3
void efect_3() {
    printf("Executando efeito 3 nos LEDs.\n");
    heart_animation(500);
}

// Função para efeito 4
void efect_4() {
    printf("Executando efeito 4 nos LEDs.\n");
    beer_animation(1000);
}

// Função para efeito 5
void efect_5() {
    printf("Executando efeito 5 nos LEDs.\n");
    // Implementação do efeito 5
}

// Função para efeito 6
void efect_6() {
    printf("Executando efeito 6 nos LEDs.\n");
    // Implementação do efeito 6
}

// Função para efeito 7
void efect_7() {
    printf("Executando efeito 7 nos LEDs.\n");
    // Implementação do efeito 7
}

// Função para efeito 8
void efect_8() {
    printf("Executando efeito 8 nos LEDs.\n");
    // Implementação do efeito 8
}

// Função para efeito 9
void efect_9() {
    printf("Executando efeito 9 nos LEDs.\n");
    // Implementação do efeito 9
}

// Função para efeito 0
void efect_0() {
    printf("Executando efeito 0 nos LEDs.\n");
    // Implementação do efeito 0
}

// Função genérica para um efeito especial
void efect() {
    printf("Executando efeito especial.\n");
    // Implementação do efeito especial
}

#endif
