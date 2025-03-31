//
// Created by serhii on 3/20/25.
//

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    int width;
    int height;
} Window;

typedef struct
{
    int time;
    int score;
    int gameMode; // 0 - game, 1 - authors, 2 - menu, 3 - game over
} GameStat;

#endif //STRUCTS_H
