#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

#include "../include/sprites.h"
#include "../include/function.h"
#include "../include/settings.h"
#include "../include/structs.h"

void gameLoop() {
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
    for (int i = 0; i < ENEMIES_ARR_SIZE; i++) {
        enemies[i].active = 1;  // Force activate

        // Grid positioning
        const int enemiesPerRow = 10;
        const int spacingX = 2;
        const int startX = (window.width - (enemiesPerRow * (SPRITE_WIDTH + spacingX))) / 2;

        enemies[i].x = startX + (i % enemiesPerRow) * (SPRITE_WIDTH + spacingX);
        enemies[i].y = 2 + (i / enemiesPerRow) * (SPRITE_HEIGHT + 1);  // Start at top
    }

    Bullet enemyBullets[ENEMY_BULLETS_ARR_SIZE];
    createEnemyBulletArr(enemyBullets);


    while (1) {
        char key = getKeyPress();
        playerMovement(&player, &window, key);
        playerShoot(playerBullets, &player, key);

        clear();
        renderEnemies(enemies);  // Should come FIRST
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
    if (delay > 0) {
        delay--;
        return;
    }
    if (key == SHOOT) {
        for (int i = 0; i < BULLETS_ARR_SIZE; i++) {
            if (playerBulletsArr[i].active == 0) {
                playerBulletsArr[i].active = 1;
                playerBulletsArr[i].x = player->x + player->width/2;
                playerBulletsArr[i].y = player->y;
                delay = FRAME_RATE / SHOOT_SPEED;
                break;
            }
        }
    }
}

void enemyMovement(Enemy enemies[ENEMIES_ARR_SIZE], Window *window) {
    for (int i = 0; i < ENEMIES_ARR_SIZE; i++) {
        if (enemies[i].active) {
            enemies[i].y++;  // Move enemies downward

            // Check if an enemy reaches the bottom of the window
            if (enemies[i].y >= window->height - SPRITE_HEIGHT) {
                enemies[i].active = 0;  // Deactivate enemy
            }
        }
    }
}
