#include <stdio.h>
#include "pico/stdlib.h"
#include "include/teclado.h"
#include "include/controle_animacao.h"

void test_keypad()
{
  sleep_ms(50);
  
  char key = read_keypad();
  if (key != '\0')
  {
    printf("Tecla pressionada: %c\n", key);

    switch (key) {
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
          efect_1();    
          break;
      case '2': 
          efect_2();      
          break;
      case '3': 
          efect_3();        
          break;
      case '4': 
          efect_4(); 
          break;
      case '5':
          efect_5();
          break;
      case '6': 
          efect_6();       
          break;
      case '7':
          efect_7();  
          break;  
      case '8':
          efect_8();
          break;
      case '9':   
          efect_9();         
          break;
      case '0':
          efect_0();
          break;
      case '*':  
          efect();
          break;
      default:
          printf("Tecla sem função atribuída: %c\n", key);
          break;
    }
  }
}

int main() {

  stdio_init_all();  // Inicializa entradas e saídas.
  npInit(LED_PIN);  // Inicializa matriz de LEDs NeoPixel.
  setup_keypad();
  
  while (true) {
    test_keypad();
  }
  return 0;
}
