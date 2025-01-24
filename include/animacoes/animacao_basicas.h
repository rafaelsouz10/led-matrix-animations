// Frame para LEDs azuis (intensidade 100%)
int blue_frame[5][5][3] = {
    {{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}},  
    {{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}},  
    {{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}},  
    {{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}},  
    {{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}}
};
// Frame para LEDs vermelhos (80% de intensidade)
int red_frame[5][5][3] = {
    {{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}},
    {{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}},
    {{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}},
    {{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}},
    {{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}}
};
// Frame para LEDs verdes (50% de intensidade)
int green_frame[5][5][3] = {
    {{0, 204, 0}, {0, 204, 0}, {0, 204, 0}, {0, 204, 0}, {0, 204, 0}},
    {{0, 204, 0}, {0, 204, 0}, {0, 204, 0}, {0, 204, 0}, {0, 204, 0}},
    {{0, 204, 0}, {0, 204, 0}, {0, 204, 0}, {0, 204, 0}, {0, 204, 0}},
    {{0, 204, 0}, {0, 204, 0}, {0, 204, 0}, {0, 204, 0}, {0, 204, 0}},
    {{0, 204, 0}, {0, 204, 0}, {0, 204, 0}, {0, 204, 0}, {0, 204, 0}}
};
// Frame para LEDs brancos (20% de intensidade)
int white_frame[5][5][3] = {
    {{51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}},
    {{51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}},
    {{51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}},
    {{51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}},
    {{51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}}
};

// Frame para desligar os LEDs
int off_frame[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
};

// Função para acender os LEDs em azul
void blue_animation(){

    print_sprite(blue_frame); //Desenha o Sprite contido no frame
    npWrite();  // Escreve os dados nos LEDs.
 
}
// Função para acender os LEDs em vermelho
void red_animation() {
    print_sprite(red_frame); // Desenha o Sprite contido no frame
    npWrite();               // Escreve os dados nos LEDs
}

// Função para acender os LEDs em verde
void green_animation() {
    print_sprite(green_frame); // Desenha o Sprite contido no frame
    npWrite();                 // Escreve os dados nos LEDs
}

// Função para acender os LEDs em branco
void white_animation() {
    print_sprite(white_frame); // Desenha o Sprite contido no frame
    npWrite();                 // Escreve os dados nos LEDs
}

// Função para desligar todos os LEDs
void off_animation() {
    print_sprite(off_frame); // Desenha o Sprite contido no frame
    npWrite();               // Escreve os dados nos LEDs
}