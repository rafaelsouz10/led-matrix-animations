#ifndef TECLADO_H
#define TECLADO_H

#include <stdio.h>
#include "pico/stdlib.h"

uint columns[4] = {16, 9, 8, 4};
uint rows[4] = {17, 18, 19, 20};

// mapeamento das teclas
char KEY_MAP[16] = { '1', '2', '3', 'A',
                     '4', '5', '6', 'B',
                     '7', '8', '9', 'C',
                     '*', '0', '#', 'D' };

// função de inicialização do teclado

void setup_keypad()
{
    for (int i = 0; i < 4; i++)
    {
        gpio_init(columns[i]); // inicializa o pino como uma GPIO
        gpio_set_dir(columns[i], GPIO_IN); // configura o pino coluna como entrada
        gpio_pull_up(columns[i]); // ativação de resistor pull-up que quando precionado vai puxar o pino do estado 1 (HIGH) para o 0 (LOW)

        gpio_init(rows[i]); // inicializa o pino como uma GPIO
        gpio_set_dir(rows[i], GPIO_OUT); // configura o pino como saida
        gpio_put(rows[i], 1); // define o estado logico das linhas como 1 (HIGH)
    }
}



#endif