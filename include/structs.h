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
    int gameMode; // 0 - game, 1 - settings, 2 - authors, 3 - menu
} GameStat;

#endif //STRUCTS_H
