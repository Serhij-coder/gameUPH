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
    // After createEnemiesArr(enemies);
    // for (int i = 0; i < ENEMIES_ARR_SIZE; i++)
    // {
    //     enemies[i].active = 1; // Force activate
    //
    //     // Grid positioning
    //     const int enemiesPerRow = 10;
    //     const int spacingX = 2;
    //     const int startX = (window.width - (enemiesPerRow * (SPRITE_WIDTH + spacingX))) / 2;
    //
    //     enemies[i].x = startX + (i % enemiesPerRow) * (SPRITE_WIDTH + spacingX);
    //     enemies[i].y = 2 + (i / enemiesPerRow) * (SPRITE_HEIGHT + 1); // Start at top
    // }

    Bullet enemyBullets[ENEMY_BULLETS_ARR_SIZE];
    createEnemyBulletArr(enemyBullets);


    while (1)
    {
        char key = getKeyPress();
        playerMovement(&player, &window, key);
        playerShoot(playerBullets, &player, key);

        enemyMovement(enemies, &window);

        collisionCheck(&player, enemies, playerBullets, enemyBullets);

        clear();
        renderEnemies(enemies); // Should come FIRST
        renderBullet(playerBullets);
        renderSprite(&player);
        waitForRefreshRate();
    };
}


void playerMovement(Player* player, const Window* window, int key)
{
    switch (key)
    {
    case MOVE_LEFT:
        player->x--;
        if (player->x < 0) player->x = 0;
        break;
    case MOVE_RIGHT:
        player->x++;
        if (player->x > window->width - player->width)
            player->x = window->width - player->width;
        break;
    default: break;
    }
}

void playerShoot(Bullet playerBulletsArr[BULLETS_ARR_SIZE], const Player* player, int key)
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
                playerBulletsArr[i].x = player->x + player->width / 2;
                playerBulletsArr[i].y = player->y;
                delay = FRAME_RATE / SHOOT_SPEED;
                break;
            }
        }
    }
}

void enemyMovement(Enemy enemies[ENEMIES_ARR_SIZE], Window* window)
{
    static int spawnDelay = 0;
    if (spawnDelay == 0)
    {
        for (int i = 0; i < ENEMIES_ARR_SIZE; i++)
        {
            if (enemies[i].active == 0)
            {
                enemies[i].active = 1;
                enemies[i].x = Random(0, window->width - SPRITE_WIDTH);
                enemies[i].y = 0;
                spawnDelay = FRAME_RATE * ENEMIES_SPAWN_RATE;
                break;
            }
        }
    }
    else
    {
        spawnDelay--;
    }
    for (int i = 0; i < ENEMIES_ARR_SIZE; i++)
    {
        if (enemies[i].active == 1)
        {
            if (enemies[i].moveTime == ENEMY_MOVE_SPEED)
            {
                enemies[i].y++;
                enemies[i].moveTime = 0;
                if (Random(0, 10) == 2)
                {
                    enemies[i].x++;
                }
                else if (Random(0, 10) == 8)
                {
                    enemies[i].x--;
                }

                if (enemies[i].x < 0) enemies[i].x = 0;
                if (enemies[i].x > window->width - SPRITE_WIDTH) enemies[i].x = window->width - SPRITE_WIDTH;
            }
            else
            {
                enemies[i].moveTime++;
            }
        }

        if (enemies[i].y >= window->height - SPRITE_HEIGHT)
        {
            gameOver();
        }
    }
}

void collisionCheck(Player* player,
                    Enemy enemies[ENEMIES_ARR_SIZE],
                    Bullet playerBulletsArr[BULLETS_ARR_SIZE],
                    Bullet enemyBullets[ENEMY_BULLETS_ARR_SIZE])
{
    for (int i = 0; i < ENEMIES_ARR_SIZE; i++)
    {
        for (int j = 0; j < BULLETS_ARR_SIZE; j++)
        {
            if (playerBulletsArr[j].x >= enemies[i].x &&
                playerBulletsArr[j].x <= enemies[i].x + enemies[i].width &&
                playerBulletsArr[j].y >= enemies[i].y &&
                playerBulletsArr[j].y <= enemies[i].y + enemies[i].height)
            {
                playerBulletsArr[j].active = 0;
                playerBulletsArr[j].y = 1000;
                enemies[i].active = 0;
                enemies[i].y = -10;
            }
        }
    }
}

void gameOver()
{
}
