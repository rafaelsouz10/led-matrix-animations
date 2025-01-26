#ifndef REBOOT_H
#define REBOOT_H

#include <stdio.h>
#include "pico/bootrom.h"

// Função para reiniciar o dispositivo no modo de gravação via USB
void reboot_to_bootloader() {
    printf("Reiniciando para o modo de gravação via USB.\n");
    reset_usb_boot(0, 0);
}

#endif