#include <stdio.h>

#include "..//include/sprites.h"

void renderSprite(const Sprite* sprite) {
    for (int i = 0; i < sprite->height; i++) {
        // Move the cursor to the correct position (optional, depends on your platform)
        printf("\033[%d;%dH", sprite->y + i, sprite->x); // ANSI escape code for cursor positioning
        printf("%s\n", sprite->data[i]);
    }
}

void clearConsole() {
    printf("\033[2J"); // ANSI escape code for clearing the screen
    printf("\033[1;1H"); // ANSI escape code for moving the cursor to the top-left corner
}