#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#include "../include/sprites.h"
#include "../include/settings.h"
#include "../include/structs.h"

void renderSprite(const Sprite *sprite) {
    for (int i = 0; i < sprite->height; i++) {
        // Move the cursor to the correct position (optional, depends on your platform)
        // printw("\033[%d;%dH", sprite->y + i, sprite->x); // ANSI escape code for cursor positioning
        mvaddstr(sprite->y + i, sprite->x, sprite->data[i]);
    }
}

void renderBorder(const Border *border) {
    printf("\033[%d;%dH", border->y, border->x); // ANSI escape code for cursor positioning

    printf("%c", border->topLeftCorner);
    for (int i = 0; i < border->width - 2; i++) {
        printf("%c", border->horizontalSymbol);
    }
    printf("%c\n", border->topRightCorner);

    for (int i = 0; i < border->height; i++) {
        printf("%c", border->verticalSymbol);
        for (int j = 0; j < border->width - 2; j++) {
            printf(" ");
        }
        printf("%c\n", border->verticalSymbol);
    }

    printf("%c", border->topLeftCorner);
    for (int i = 0; i < border->width - 2; i++) {
        printf("%c", border->horizontalSymbol);
    }
    printf("%c\n", border->topRightCorner);
}

void clearConsole() {
    printf("\033[2J"); // ANSI escape code for clearing the screen
    printf("\033[1;1H"); // ANSI escape code for moving the cursor to the top-left corner
}

void fieldRender(const Border *border) {
    clearConsole();
    renderBorder(border);
}

void waightForRefreshRate() {
    usleep(1000000 / FRAME_RATE);
}

void initWindow(Window *window) {
    getmaxyx(stdscr, window->height, window->width);
}
