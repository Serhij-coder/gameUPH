#include "../include/settings.h"
#include "../include/sprites.h"

#include <stdlib.h>

// Define the sprite for an enemy
const char* enemySpriteData1[] = {
    " ▀ ▀ ▀ ",
    "███████",
    "█ ███ █",
    " █████ ",
    "  ███  ",
};
const char* enemySpriteData2[] = {
    "  ███  ",
    " █████ ",
    "██ █ ██",
    " █████ ",
    "  █ █  ",
};
const char* enemySpriteData3[] = {
    " █████ ",
    "█ █ █ █",
    "███████",
    " █ █ █ ",
    "█     █",
};

const char* playerSpriteData[] = {
    "   ▲   ",
    "  ███  ",
    " █████ ",
    "███████",
    "█  █  █",
};

const char* playerBulletSpriteData[] = {
    "*",
    "|",
};

const char* enemyBulletSpriteData[] = {
    "|",
    "#",
};

Player createPlayer(const char* data[], int width, int height, int x, int y)
{
    Player sprite;
    for (int i = 0; i < height; i++)
    {
        sprite.data[i] = data[i];
    }
    sprite.width = width;
    sprite.height = height;
    sprite.x = x;
    sprite.y = y;
    return sprite;
}

Enemy createEnemy(const char* data[], int width, int height, int x, int y, int active)
{
    Enemy enemy;
    for (int i = 0; i < height; i++)
    {
        enemy.data[i] = data[i];
    }
    enemy.width = width;
    enemy.height = height;
    enemy.x = x;
    enemy.y = y;
    enemy.active = active;
    return enemy;
}

Bullet createBullet(const char* data[], int width, int height, int x, int y, int active)
{
    Bullet bullet;
    for (int i = 0; i < height; i++)
    {
        bullet.data[i] = data[i];
    }
    bullet.width = width;
    bullet.height = height;
    bullet.x = x;
    bullet.y = y;
    bullet.active = active;
    return bullet;
}

void createPlayerBulletsArr(Bullet bullets[BULLETS_ARR_SIZE])
{
    Bullet bullet = createBullet(playerBulletSpriteData, 1, BULLET_HEIGHT, -10, -10, 0);
    for (int i = 0; i < BULLETS_ARR_SIZE; i++)
    {
        bullets[i] = bullet;
    }
}

void createEnemiesArr(Enemy enemies[ENEMIES_ARR_SIZE])
{
    for (int i = 0; i < ENEMIES_ARR_SIZE; i++)
    {
        Enemy enemy1 = createEnemy(enemySpriteData1, SPRITE_WIDTH, SPRITE_HEIGHT, -10, -10, 0);
        Enemy enemy2 = createEnemy(enemySpriteData2, SPRITE_WIDTH, SPRITE_HEIGHT, -10, -10, 0);
        Enemy enemy3 = createEnemy(enemySpriteData3, SPRITE_WIDTH, SPRITE_HEIGHT, -10, -10, 0);
        if (rand() % ENEMIES_SPRITES_COUNT == 0)
        {
            enemies[i] = enemy1;
        }
        else if (rand() % ENEMIES_SPRITES_COUNT == 1)
        {
            enemies[i] = enemy2;
        }
        else
        {
            enemies[i] = enemy3;
        }
    }
}

void createEnemyBulletArr(Bullet bullets[ENEMY_BULLETS_ARR_SIZE])
{
    Bullet bullet = createBullet(enemyBulletSpriteData, 1, BULLET_HEIGHT, -11, -11, 0);
    for (int i = 0; i < ENEMY_BULLETS_ARR_SIZE; i++)
    {
        bullets[i] = bullet;
    }
}
