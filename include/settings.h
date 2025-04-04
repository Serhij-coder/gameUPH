//
// Created by serhii on 3/21/25.
//

#ifndef SETTINGGS_H
#define SETTINGGS_H
typedef struct
{
    // Game render
    int FRAME_RATE;

    // Enemies
    int ENEMY_SHOOT_SPEED; // Bullets per second
    int ENEMY_MOVE_SPEED; // Every x frames
    int ENEMIES_SPAWN_RATE; // Every x seconds
    int IS_ENEMY_SHOOTING;

    int SHOOT_SPEED; // Bullets per second
}Settings;
// Game render
// #define FRAME_RATE 30

// Sprites
#define SPRITE_HEIGHT 5
#define SPRITE_WIDTH 7

// Enemies
#define ENEMIES_SPRITES_COUNT 3
#define ENEMIES_ARR_SIZE 50
#define ENEMY_BULLETS_ARR_SIZE 200
// #define ENEMY_SHOOT_SPEED 2 // Bullets per second
// #define ENEMY_MOVE_SPEED 15 // Every x frames
// #define ENEMIES_SPAWN_RATE 4 // Every x seconds

// Bullets
#define BULLET_HEIGHT 2
#define BULLETS_ARR_SIZE 100
// #define SHOOT_SPEED 3 // Bullets per second

// Controls
#define MOVE_LEFT 'a'
#define MOVE_RIGHT 'd'
#define MENU_UP 'w'
#define MENU_DOWN 's'

#define SHOOT ' '

#endif //SETTINGGS_H
