#include <ncurses.h>

#include <stdio.h>
#include <unistd.h>

#include "../include/sprites.h"
#include "../include/settings.h"
#include "../include/structs.h"

void renderSprite(const Sprite *sprite) {
    for (int i = 0; i < sprite->height; i++) {
        mvprintw(sprite->y + i, sprite->x, "%s", sprite->data[i]);
    }
    refresh(); // Single refresh after all updates
}

void clearConsole() {
    printf("\033[2J"); // ANSI escape code for clearing the screen
    printf("\033[1;1H"); // ANSI escape code for moving the cursor to the top-left corner
}

void waightForRefreshRate() {
    usleep(1000000 / FRAME_RATE);
}

void initWindow(Window *window) {
    getmaxyx(stdscr, window->height, window->width);
}
