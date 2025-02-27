int frame1_coracao[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {200, 0, 200}, {0, 0, 0}, {200, 0, 200}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {200, 0, 200}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {200, 0, 200}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
};

int frame2_coracao[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {200, 0, 200}, {0, 0, 0}, {200, 0, 200}, {0, 0, 0}},
    {{0, 0, 0}, {200, 0, 200}, {200, 0, 200}, {200, 0, 200}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {200, 0, 200}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
};

int frame3_coracao[5][5][3] = {
    {{0, 0, 0}, {200, 0, 200}, {0, 0, 0}, {200, 0, 200}, {0, 0, 0}},
    {{0, 0, 0}, {200, 0, 200}, {200, 0, 200}, {200, 0, 200}, {0, 0, 0}},
    {{0, 0, 0}, {200, 0, 200}, {200, 0, 200}, {200, 0, 200}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {200, 0, 200}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {200, 0, 200}, {0, 0, 0}, {0, 0, 0}}
};

int frame4_coracao[5][5][3] = {
    {{0, 0, 0}, {200, 0, 200}, {0, 0, 0}, {200, 0, 200}, {0, 0, 0}},
    {{200, 0, 200}, {200, 0, 200}, {200, 0, 200}, {200, 0, 200}, {200, 0, 200}},
    {{200, 0, 200}, {200, 0, 200}, {200, 0, 200}, {200, 0, 200}, {200, 0, 200}},
    {{0, 0, 0}, {0, 0, 0}, {200, 0, 200}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {200, 0, 200}, {0, 0, 0}, {0, 0, 0}}
};

int frame5_coracao[5][5][3] = {
    {{0, 0, 0}, {200, 0, 200}, {0, 0, 0}, {200, 0, 200}, {0, 0, 0}},
    {{200, 0, 200}, {200, 0, 200}, {200, 0, 200}, {200, 0, 200}, {200, 0, 200}},
    {{200, 0, 200}, {200, 0, 200}, {200, 0, 200}, {200, 0, 200}, {200, 0, 200}},
    {{0, 0, 0}, {200, 0, 200}, {200, 0, 200}, {200, 0, 200}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {200, 0, 200}, {0, 0, 0}, {0, 0, 0}}
};

void heart_animation(int sleep){

    print_sprite(frame1_coracao); //Desenha o Sprite contido no frame
    npWrite();  // Escreve os dados nos LEDs.
    sleep_ms(sleep);
    npClear();

    print_sprite(frame2_coracao);
    npWrite();
    sleep_ms(sleep);
    npClear();

    print_sprite(frame3_coracao);
    npWrite();
    sleep_ms(sleep);
    npClear();

    print_sprite(frame4_coracao);
    npWrite();
    sleep_ms(sleep);
    npClear();
    
    print_sprite(frame5_coracao);
    npWrite();
    sleep_ms(sleep);
    npClear();
}