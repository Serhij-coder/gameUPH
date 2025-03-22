#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

#include "../include/sprites.h"
#include "../include/function.h"
#include "../include/settings.h"

void gameLoop() {
    Sprite player = createSprite(playerSpriteData, 7, 5, 2, 2);

    while (1) {
        char key = getKeyPress();
        playerMovement(&player, key);

        clear();
        renderSprite(&player);

        waightForRefreshRate();
    }
}

void playerMovement(Sprite *player, int key) {
    switch (key) {
        case 'w':
            player->y--;
            break;
        case 's':
            player->y++;
            break;
        case 'a':
            player->x--;
            break;
        case 'd':
            player->x++;
            break;
        default:
            break;
    }
}
