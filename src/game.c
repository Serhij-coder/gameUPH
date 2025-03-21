#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

#include "../include/sprites.h"
#include "../include/function.h"
#include "../include/settings.h"

void gameLoop() {
    Border border = createBorder(GAME_POLE_WIDTH,
                                 GAME_POLE_HEIGHT,
                                 BORDER_HORIZONTAL_SYMBOL,
                                 BORDER_VERTICAL_SYMBOL,
                                 BORDER_TOP_LEFT_CORNER,
                                 BORDER_TOP_RIGHT_CORNER,
                                 BORDER_BOTTOM_LEFT_CORNER,
                                 BORDER_BOTTOM_RIGHT_CORNER,
                                 0, 0);
    Sprite player = createSprite(playerSpriteData, 7, 5, 2, 2);

    while (1) {
        char key = getKeyPress();
        playerMovement(&player, key);

        // fieldRender(&border);
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
