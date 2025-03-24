#include "../include/settings.h"
#include "../include/sprites.h"

// Define the sprite for an enemy
const char* enemySpriteData[] = {
    "  ███  ",
    " █████ ",
    "█ ███ █",
    "███████",
    " ▀ ▀ ▀ ",
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

Sprite createSprite(const char* data[], int width, int height, int x, int y)
{
    Sprite sprite;
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

Bullet createPlayerBulletsArr(Bullet bullets[BULLETS_ARR_SIZE])
{
    Bullet bullet = createBullet(playerBulletSpriteData, 3, BULLET_HEIGHT, -10, -10, 0);
    for (int i = 0; i < BULLETS_ARR_SIZE; i++)
    {
        bullets[i] = bullet;
    }
}
