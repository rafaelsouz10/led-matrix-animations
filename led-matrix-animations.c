#include <stdio.h>
#include "pico/stdlib.h"
#include "include/buzzer.h"
#include "include/teclado.h"
#include "include/controle_animacao.h"

int main()
{
    // Para realizar testes digitando as teclas via UART (caso não tenha o teclado matricial),
    // comente a linha char key = read_keypad(); e descomente as linhas printf ("\nDigite uma tecla: "); e scanf("%c", &key);

    stdio_init_all(); // Inicializa entradas e saídas.
    npInit(LED_PIN); // Inicializa matriz de LEDs NeoPixel.
    buzzer_init(); // Inicializa buzzers.
    setup_keypad(); // Inicializa o teclado matricial.

    char key;

    while (true)
    {
        sleep_ms(50);

        key = read_keypad();

        //printf("\nDigite uma tecla: ");
        //scanf("%c", &key);

        if (key != '\0')
        {
            printf("Tecla pressionada: %c\n", key);

            switch (key)
            {
            case 'A':
                desligar_leds();
                break;
            case 'B':
                ligar_leds_azul();
                break;
            case 'C':
                ligar_leds_vermelho();
                break;
            case 'D':
                ligar_leds_verde();
                break;
            case '#':
                ligar_leds_branco();
                break;
            case '1':
                executar_animacao_com_som(effect_1, 400);
                break;
            case '2':
                executar_animacao_com_som(effect_2, 500);
                break;
            case '3':
                executar_animacao_com_som(effect_3, 500);
                break;
            case '4':
                executar_animacao_com_som(effect_4, 1000);
                break;
            case '5':
                executar_animacao_com_som(effect_5, 700);
                break;
            case '6':
                executar_animacao_com_som(effect_6, 700);
                break;
            case '7':
                executar_animacao_com_som(effect_7, 700);
                break;
            case '8':
                executar_animacao_com_som(effect_8, 700);
                break;
            case '9':
                executar_animacao_com_som(effect_9, 700);
                break;
            case '0':
                executar_animacao_com_som(effect_0, 800);
                break;
            case '*':
                executar_animacao_com_som(effect_reboot, 200);
                break;
            default:
                printf("Tecla sem função atribuída: %c\n", key);
                break;
            }
        }
    }
    return 0;
}
