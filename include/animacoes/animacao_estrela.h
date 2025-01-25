int frame1_estrela[5][5][3] = {
,    {{0, 0, 0}, {0, 0, 0}, {100, 100, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{100, 100, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 100, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {100, 100, git 0}, {0, 0, 0}, {0, 0, 0}}
};

int frame2_estrela[5][5][3] = {
    {{0, 0, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {100, 100, 0}, {0, 0, 0}, {0, 0, 0}},
    {{100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}},
    {{0, 0, 0}, {0, 0, 0}, {100, 100, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {0, 0, 0}}
};

int frame3_estrela[5][5][3] = {
    {{100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}},
    {{100, 100, 0}, {0, 0, 0}, {100, 100, 0}, {0, 0, 0}, {100, 100, 0}},
    {{100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}},
    {{100, 100, 0}, {0, 0, 0}, {100, 100, 0}, {0, 0, 0}, {100, 100, 0}},
    {{100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}}
};

int frame4_estrela[5][5][3] = {
    {{0, 0, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {100, 100, 0}, {0, 0, 0}, {0, 0, 0}},
    {{100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}},
    {{0, 0, 0}, {0, 0, 0}, {100, 100, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {0, 0, 0}}
};

int frame5_estrela[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {100, 100, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{100, 100, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 100, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {100, 100, 0}, {0, 0, 0}, {0, 0, 0}}
};

void star_animation(int sleep) {

    print_sprite(frame1_estrela);
    npWrite();
    sleep_ms(sleep);
    npClear();

    print_sprite(frame2_estrela);
    npWrite();
    sleep_ms(sleep);
    npClear();

    print_sprite(frame3_estrela);
    npWrite();
    sleep_ms(sleep);
    npClear();

    print_sprite(frame4_estrela);
    npWrite();
    sleep_ms(sleep);
    npClear();

    print_sprite(frame5_estrela);
    npWrite();
    sleep_ms(sleep);
    npClear();
}
