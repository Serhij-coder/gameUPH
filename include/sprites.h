//
// Created by serhii on 3/20/25.
//
#include "settings.h"
#ifndef SPRITES_H
#define SPRITES_H

extern const char* enemySpriteData[SPRITE_HEIGHT];
extern const char* playerSpriteData[SPRITE_HEIGHT];
extern const char* playerBulletSpriteData[BULLET_HEIGHT];

typedef struct
{
    const char* data[SPRITE_HEIGHT]; // Sprite data (5 lines of characters)
    int width; // Width of the sprite
    int height; // Height of the sprite
    int x, y; // Position on the screen
} Sprite;

typedef struct
{
    const char* data[BULLET_HEIGHT];
    int width;
    int height;
    int x, y;
    int active;
} Bullet;

#endif //SPRITES_H
