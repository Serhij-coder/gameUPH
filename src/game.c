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

    Player player = createPlayer(playerSpriteData, 7, SPRITE_HEIGHT, 0, 0);
    player.y = window.height - player.height;
    player.x = window.width / 2 - player.width / 2;

    Bullet playerBullets[BULLETS_ARR_SIZE];
    createPlayerBulletsArr(playerBullets);

    Enemy enemies[ENEMIES_ARR_SIZE];
    createEnemiesArr(enemies);

    Bullet enemyBullets[ENEMY_BULLETS_ARR_SIZE];
    createEnemyBulletArr(enemyBullets);


    while (1)
    {
        char key = getKeyPress();
        playerMovement(&player, &window, key);
        playerShoot(playerBullets, &player, key);

        clear();
        renderBullet(playerBullets);
        renderSprite(&player);

        waitForRefreshRate();
    }
}

void playerMovement(Player* player, Window* window, int key)
{
    switch (key)
    {
    case MOVE_LEFT:
        player->x--;
        if (player->x < 0)
        {
            player->x = 0;
        }
        break;
    case MOVE_RIGHT:
        player->x++;
        if (player->x > window->width- player->width)
        {
            player->x = window->width - player->width;
        }
        break;
    default:
        break;
    }
}

void playerShoot(Bullet playerBulletsArr[BULLETS_ARR_SIZE], Player* player, int key)
{
    static int delay = 0;

    if (delay > 0)
    {
        delay--;
        return;
    }

    if (key == SHOOT)
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

void enemyMovement(Enemy enemies[ENEMIES_ARR_SIZE], Window* window)
{

}