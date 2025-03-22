/*
==========================================
UPH Project
==========================================
Authors:
 - Serhii Fedorenko (Arch Linux)
 - Lukas Lacko (Kali Linux)

Description:
 This program is recreating the classic game Space Invaders.

License:
 GPL v3

Created on: 20.3.2025
==========================================
*/

// Include the necessary libraries
#include <ncurses.h>
#include <locale.h>

// Include the necessary header files
#include "include/settings.h"
#include "include/sprites.h"
#include "include/function.h"

int main(void) {
    // Inialization
    //------------------------------------------
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, 1);
    nodelay(stdscr, 1);
    //------------------------------------------

    gameLoop();

    return 0;
}
