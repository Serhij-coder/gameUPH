//
// Created by serhii on 3/20/25.
//
#include "settings.h"
#include "structs.h"
#ifndef FUCTION_H
#define FUCTION_H

// Sprites.c
Player createPlayer(const char* data[], int width, int height, int x, int y);
Bullet createBullet(const char* data[], int width, int height, int x, int y, int active);
Enemy createEnemy(const char* data[], int width, int height, int x, int y, int active);
void createEnemiesArr(Enemy enemies[ENEMIES_ARR_SIZE]);
void createPlayerBulletsArr(Bullet bullets[BULLETS_ARR_SIZE]);
void createEnemyBulletArr(Bullet bullets[ENEMY_BULLETS_ARR_SIZE]);


// Render.c
void renderSprite(const Player* sprite);
void renderBullet(const Bullet* bullet);
void waitForRefreshRate(Settings* setts);
void initWindow(Window* window);
void renderEnemies(Enemy enemies[ENEMIES_ARR_SIZE]);
void renderEnemyBullet(Bullet bulletArr[ENEMY_BULLETS_ARR_SIZE]);
void renderGameStat(GameStat* stats);

// Input.c
int Random(int min, int max);
char getKeyPress();

// Game.c
void gameLoop();
void playerMovement(Player* player, const Window* window, int key);
void playerShoot(Bullet playerBulletsArr[BULLETS_ARR_SIZE], const Player* player, Settings* setts, int key);
void enemyMovement(Enemy enemies[ENEMIES_ARR_SIZE], Window* window, Settings* setts);
void enemyShoot(Bullet enemyBullets[ENEMY_BULLETS_ARR_SIZE], Enemy enemies[ENEMIES_ARR_SIZE], Settings* setts);
void collisionCheck(Player* player,
                    Enemy enemies[ENEMIES_ARR_SIZE],
                    Bullet playerBulletsArr[BULLETS_ARR_SIZE],
                    Bullet enemyBullets[ENEMY_BULLETS_ARR_SIZE],
                    GameStat* gameStat);
void countGameTime(GameStat* gameStat, Settings* setts);
void clearGameField(Enemy enemies[ENEMIES_ARR_SIZE],
                    Bullet playerBulletsArr[BULLETS_ARR_SIZE],
                    Bullet enemyBullets[ENEMY_BULLETS_ARR_SIZE]);
void menu(Window* window, GameStat* game_stat, int key);
void authors(Window* window);
void settings(Window* window);
int gameOver(Window* window, GameStat* gameStat);


#endif //FUCTION_H
