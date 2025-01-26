# led-matrix-animations
Este repositório contém o projeto "Animações Interativas com Matriz de LEDs 5x5", desenvolvido como parte de uma atividade prática do programa EmbarcaTech. O objetivo é controlar uma matriz de LEDs RGB (5x5 WS2812) utilizando um teclado matricial 4x4 e o microcontrolador Raspberry Pi Pico W.

# Sistema Integrado com Raspberry Pi Pico, Teclado Matricial, LEDs RGB e Buzzer

## Descrição do Projeto

Este projeto utiliza o **Raspberry Pi Pico** para controlar uma matriz de LEDs RGB 5x5 (WS2812), permitindo a criação de animações interativas acionadas por meio de um teclado matricial 4x4. O sistema foi desenvolvido em **linguagem C**, simulado no **Wokwi**, e configurado para rodar no **VS Code** com todas as dependências e SDK instalados. Além disso, há suporte para execução em hardware real, utilizando a placa de desenvolvimento **BitDogLab**.

---

## Requisitos

- **Microcontrolador**: Raspberry Pi Pico ou Raspberry Pi Pico W (opcional)
- **Placa de Desenvolvimento:** BitDogLab (opcional).
- **Conta Criada no Wokwi Simulator**: [Wokwi](https://wokwi.com/).
- **Editor de Código**: Visual Studio Code (VS Code).
- **SDK do Raspberry Pi Pico** configurado no sistema.
- Ferramentas de build: **CMake** e **Ninja**.

---

## Instruções de Uso

### 1. Clone o Repositório

Clone o repositório para o seu computador:
```bash
git clone https://github.com/rafaelsouz10/led-matrix-animations.git
cd LED-MATRIX-ANIMATIONS
```
---

### 2. Instale as Dependências

Certifique-se de que o SDK do Raspberry Pi Pico está configurado corretamente no VS Code. As extensões recomendadas são:

- **C/C++** (Microsoft).
- **CMake Tools**.
- **Wokwi Simulator**.
- **Raspberry Pi Pico**.

---

### 3. Configure o VS Code

Abra o projeto no Visual Studio Code e siga as etapas abaixo:

1. Certifique-se de que as extensões mencionadas anteriormente estão instaladas.
2. No terminal do VS Code, compile o código clicando em "Compile Project" na interface da extensão do Raspberry Pi Pico.
3. O processo gerará o arquivo `.uf2` necessário para a execução no hardware real.

---

### 4. Teste no Simulador Wokwi Integrado ao VS Code

Após ter configurado o VS Code conforme descrito no item 3, siga os passos abaixo para simular o projeto:

1. Abra o arquivo `diagram.json` no Visual Studio Code.
2. Clique no botão "Play" disponível na interface.
3. Divirta-se interagindo com os componentes disponíveis no simulador integrado!

---

### 5. Teste no Hardware Real

#### Utilizando a Placa de Desenvolvimento BitDogLab com Raspberry Pi Pico W:

1. Conecte a placa ao computador no modo BOTSEEL:
   - Pressione o botão **BOOTSEL** (localizado na parte de trás da placa de desenvolvimento) e, em seguida, o botão **RESET** (localizado na frente da placa).
   - Após alguns segundos, solte o botão **RESET** e, logo depois, solte o botão **BOOTSEL**.
   - A placa entrará no modo de programação.

2. Compile o projeto no VS Code utilizando a extensão do [Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico):
   - Clique em **Compile Project**.

3. Execute o projeto clicando em **Run Project USB**, localizado abaixo do botão **Compile Project**.

4. Conecte os pinos do teclado matricial ao conector de expansão GPIO da BitDogLab conforme o mapeamento abaixo:

   | **Pino do Teclado** | **Pino no Conector de Expansão (GPIO)** |
   |---------------------|----------------------------------------|
   | R1                 | GP17                                   |
   | R2                 | GP18                                   |
   | R3                 | GP19                                   |
   | R4                 | GP20                                   |
   | C1                 | GP16                                   |
   | C2                 | GP9                                    |
   | C3                 | GP8                                    |
   | C4                 | GP4                                    |

   Para localizar os pinos no conector de expansão:
   - **GP17** a **GP20**: Localizados na fileira superior do conector, na posição 9 a 12.
   - **GP16**, **GP9**, **GP8**, **GP4**: Localizados na fileira inferior do conector, na posição 11, 6, 4 e 8, respectivamente.

   Consulte o datasheet para mais detalhes sobre a localização física dos pinos na BitDogLab.

Após a configuração, todos os componentes estarão prontos para o uso no sistema.

---

## Funcionamento do Sistema

1. **Teclado Matricial 4x4**: Detecta teclas pressionadas e executa ações correspondentes.
2. **LEDs RGB**: Alteram as cores com base nas teclas pressionadas.
3. **Buzzer**: Emite sons como feedback ao pressionar teclas específicas.

### Animações e Funções Associadas

1. **Teclas 0-9: Animações Personalizadas**
   - Cada tecla do teclado matricial de 0 a 9 aciona uma animação única na matriz de LEDs RGB 5x5. Essas animações são fluídas e compostas por pelo menos 5 frames (quadros) diferentes.
   - Exemplos:
     - **Tecla 1 (`effect_1()`):** Executa a animação 1.
     - **Tecla 2 (`effect_2()`):** Executa a animação 2.
     - *(Descrever as animações conforme necessário para as teclas restantes)*.

2. **Teclas de Controle de Cores**
   - **A (`desligar_leds()`):** Desliga todos os LEDs da matriz.
   - **B (`ligar_leds_azul()`):** Liga todos os LEDs na cor azul com intensidade máxima.
   - **C (`ligar_leds_vermelho()`):** Liga todos os LEDs na cor vermelha com 80% da luminosidade.
   - **D (`ligar_leds_verde()`):** Liga todos os LEDs na cor verde com 50% da luminosidade.
   - **# (`ligar_leds_branco()`):** Liga todos os LEDs na cor branca com 20% da luminosidade.

3. **Tecla de Reboot**
   - **\* (`effect()`):** Habilita o modo de gravação (reboot do sistema via software).

4. **Outras Teclas**
   - Teclas não mapeadas imprimem no console a mensagem: "Tecla sem função atribuída".

---

## Testes

Os testes realizados garantiram que todas as funcionalidades do sistema operam conforme esperado. Abaixo estão os resultados detalhados:

1. **Teste das Funções de Controle**:
   - **Tecla A**: Confirmado que desliga todos os LEDs.
   - **Tecla B**: Confirmado que liga todos os LEDs na cor azul com 100% de luminosidade.
   - **Tecla C**: Confirmado que liga todos os LEDs na cor vermelha com 80% de luminosidade.
   - **Tecla D**: Confirmado que liga todos os LEDs na cor verde com 50% de luminosidade.
   - **Tecla #**: Confirmado que liga todos os LEDs na cor branca com 20% de luminosidade.

2. **Teste das Animações**:
   - Cada tecla de 0 a 9 foi testada individualmente, verificando a execução de animações fluídas e com pelo menos 5 frames. Todas as animações foram exibidas corretamente na matriz de LEDs.

3. **Teste do Reboot**:
   - Ao pressionar a tecla \*, o sistema entrou corretamente no modo de gravação (reboot).

4. **Teste Geral**:
   - O sistema foi testado no simulador Wokwi e no hardware real. Em ambas as plataformas, todas as funcionalidades operaram sem falhas.

---

## Divisão de Tarefas do Grupo 9 - Subgrupo 9 do EmbarcaTech - CEPEDI 

- **Líder do Projeto**:
  - RAFAEL SOUZA BARBOSA 
- **Desenvolvimento das Animações**:
  - DANIEL SOARES OLIVEIRA SANTOS
  - GABRIEL SOUZA SANTOS
  - ANDRÉ LUIZ FALCÃO SOARES
  - WALLAS FRANÇA SAMPAIO
- **Programador de Funcionalidades Básicas**:
  - Junior Santos
- **Programador de Funcionalidades Avançadas**:
  - WILSON OLIVEIRA LIMA
- **Documentação e Apresentação**:
  - ANA CARLA MACÁRIO SANTANA 
## Vídeo Demonstrativo

*(A ser adicionado posteriormente)*


