//
// Created by serhii on 3/20/25.
//
#include "settings.h"
#include "structs.h"
#ifndef FUCTION_H
#define FUCTION_H

// Sprites.c
Sprite createSprite(const char* data[], int width, int height, int x, int y);
Bullet createBullet(const char* data[], int width, int height, int x, int y, int active);
Bullet createPlayerBulletsArr(Bullet bullets[BULLETS_ARR_SIZE]);


// Render.c
void clearConsole();
void renderSprite(const Sprite* sprite);
void renderBullet(const Bullet* bullet);
void waightForRefreshRate();
void initWindow(Window* window);

// Input.c
void setupNonBlockingInput();
char getKeyPress();

// Game.c
void gameLoop();
void playerMovement(Sprite* player, int key);
void playerShoot(Bullet* playerBulletsArr, Sprite* player, int key);

#endif //FUCTION_H
