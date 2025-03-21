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

// Include the necessary header files
#include "include/settings.h"
#include "include/sprites.h"
#include "include/function.h"

int main(void) {
    // Inialization
    //------------------------------------------
    setupNonBlockingInput();
    initscr();
    noecho();
    curs_set(0);
    //------------------------------------------

        gameLoop();

    return 0;
}
