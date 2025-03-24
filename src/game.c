#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

#include "../include/sprites.h"
#include "../include/function.h"
#include "../include/settings.h"
#include "../include/structs.h"

void gameLoop()
{
    Window window;
    initWindow(&window);
    Sprite player = createSprite(playerSpriteData, 7, SPRITE_HEIGHT, 0, 0);
    player.y = window.height - player.height;
    player.x = window.width / 2 - player.width / 2;
    Bullet playerBullets[BULLETS_ARR_SIZE];
    createPlayerBulletsArr(playerBullets);


    while (1)
    {
        char key = getKeyPress();
        playerMovement(&player, key);
        playerShoot(playerBullets, &player, key);

        clear();
        renderBullet(playerBullets);
        renderSprite(&player);


        waightForRefreshRate();
    }
}

// TODO @kali: Implement ALT key usage (from settings.h)
void playerMovement(Sprite* player, int key)
{
    switch (key)
    {
    case MOVE_LEFT:
        player->x--;
        break;
    case MOVE_RIGHT:
        player->x++;
        break;
    default:
        break;
    }
}

void playerShoot(Bullet playerBulletsArr[BULLETS_ARR_SIZE], Sprite* player, int key)
{
    static int delay = 0;

    if (delay > 0)
    {
        delay--;
        return;
    }

    if (key == SHOOT || key == SHOOT_ALT)
    {
        for (int i = 0; i < BULLETS_ARR_SIZE; i++)
        {
            if (playerBulletsArr[i].active == 0)
            {
                playerBulletsArr[i].active = 1;
                playerBulletsArr[i].x = player->x + player->width/2;
                playerBulletsArr[i].y = player->y;
                delay = FRAME_RATE / SHOOT_SPEED;
                break;
            }
        }
    }
}
