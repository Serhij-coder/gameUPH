#include <stdio.h>

#ifndef SPRITES
#include "Sprites.h"
#endif

int main(void) {
    for (int i = 0; i < 5; i++) {
        printf("%s\n", enemy1[i]);
    }
    return 0;
}