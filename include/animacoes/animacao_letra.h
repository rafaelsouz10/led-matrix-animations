int frame1_letra[5][5][3] = {
    {{100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0}},        
    {{0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0}},        
    {{0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0}},        
    {{0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0}}
};

int frame2_letra[5][5][3] = {
    {{0, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}},
    {{100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}}
};

int frame3_letra[5][5][3] = {
    {{100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}},
    {{100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}}
};

int frame4_letra[5][5][3] = {
    {{100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}}
};

int frame5_letra[5][5][3] = {
    {{100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
};

int frame6_letra[5][5][3] = {
    {{0, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}},
    {{100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}},
    {{100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}}
};


void letter_animation(int sleep) {

    print_sprite(frame1_letra); // Desenha o Sprite contido no frame 1
    npWrite();  // Escreve os dados nos LEDs
    sleep_ms(sleep);  // Aguarda o tempo definido
    npClear();  // Limpa os LEDs para o próximo frame

    print_sprite(frame2_letra); // Desenha o Sprite contido no frame 2
    npWrite();  // Escreve os dados nos LEDs
    sleep_ms(sleep);  // Aguarda o tempo definido
    npClear();  // Limpa os LEDs para o próximo frame

    print_sprite(frame3_letra); // Desenha o Sprite contido no frame 3
    npWrite();  // Escreve os dados nos LEDs
    sleep_ms(sleep);  // Aguarda o tempo definido
    npClear();  // Limpa os LEDs para o próximo frame

    print_sprite(frame4_letra); // Desenha o Sprite contido no frame 4
    npWrite();  // Escreve os dados nos LEDs
    sleep_ms(sleep);  // Aguarda o tempo definido
    npClear();  // Limpa os LEDs para o próximo frame

    print_sprite(frame5_letra); // Desenha o Sprite contido no frame 5
    npWrite();  // Escreve os dados nos LEDs
    sleep_ms(sleep);  // Aguarda o tempo definido
    npClear();  // Limpa os LEDs para o próximo frame

    print_sprite(frame6_letra); // Desenha o Sprite contido no frame 6
    npWrite();  // Escreve os dados nos LEDs
    sleep_ms(sleep);  // Aguarda o tempo definido
    npClear();  // Limpa os LEDs para o próximo frame

}