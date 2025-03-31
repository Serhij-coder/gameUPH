//
// Created by serhii on 3/20/25.
//
#include "settings.h"
#ifndef SPRITES_H
#define SPRITES_H

extern const char* enemySpriteData1[SPRITE_HEIGHT];
extern const char* enemySpriteData2[SPRITE_HEIGHT];
extern const char* enemySpriteData3[SPRITE_HEIGHT];
extern const char* playerSpriteData[SPRITE_HEIGHT];
extern const char* playerBulletSpriteData[BULLET_HEIGHT];

typedef struct
{
    const char* data[SPRITE_HEIGHT]; // Sprite data (5 lines of characters)
    int width; // Width of the sprite
    int height; // Height of the sprite
    int x, y; // Position on the screen
} Player;

typedef struct
{
    const char* data[SPRITE_HEIGHT];
    int width;
    int height;
    int x, y;
    int active;
    int moveTime;
    int shootDelay;
} Enemy;

typedef struct
{
    const char* data[BULLET_HEIGHT];
    int width;
    int height;
    int x, y;
    int active;
} Bullet;

#endif //SPRITES_H
