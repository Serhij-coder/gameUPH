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
#include <stdio.h>
#include <unistd.h>

// Include the necessary header files
#include "include/vars.h"
#include "include/structs.h"
#include "include/sprites.h"
#include "include/function.h"

int main(void) {
    Sprite enemy = createSprite(enemySpriteData, 7, 5, 5, 5); // Enemy at (10, 5)

    clearConsole();
    while (1) {
        for (int i = 0; i < 10; i++) {
            enemy.x += 1;
            clearConsole();
            renderSprite(&enemy);
            usleep(100000); // Sleep for 100 ms
        }
        for (int i = 0; i < 10; i++) {
            enemy.y += 1;
            clearConsole();
            renderSprite(&enemy);
            usleep(100000); // Sleep for 100 ms
        }
        for (int i = 0; i < 10; i++) {
            enemy.x -= 1;
            clearConsole();
            renderSprite(&enemy);
            usleep(100000); // Sleep for 100 ms
        }
        for (int i = 0; i < 10; i++) {
            enemy.y -= 1;
            clearConsole();
            renderSprite(&enemy);
            usleep(100000); // Sleep for 100 ms
        }
    }
    return 0;
}
