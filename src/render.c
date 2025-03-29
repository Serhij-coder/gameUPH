

#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#include "../include/settings.h"
#include "../include/sprites.h"
#include "../include/structs.h"

void renderSprite(const Player* sprite)
{
    for (int i = 0; i < sprite->height; i++)
    {
        mvprintw(sprite->y + i, sprite->x, "%s", sprite->data[i]);
    }
    refresh();
}

void renderBullet(Bullet bulletArr[BULLETS_ARR_SIZE])
{
    for (int i = 0; i < BULLETS_ARR_SIZE; i++)
    {
        if (bulletArr[i].active == 1)
        {
            bulletArr[i].y--;
            if (bulletArr[i].y < -2)
            {
                bulletArr[i].active = 0;
            }
        }
        for (int j = 0; j < bulletArr[i].height; j++)
        {
            mvprintw(bulletArr[i].y + j, bulletArr[i].x, "%s", bulletArr[i].data[j]);
        }
    }
    refresh();
}

void renderEnemies(Enemy enemies[ENEMIES_ARR_SIZE])
{
    for (int i = 0; i < ENEMIES_ARR_SIZE; i++)
    {
        if (enemies[i].active == 1)
        {
            if (enemies[i].y > LINES - 2) // chatko povedal ze aby neusli enemaci z boxu
            {
                enemies[i].active = 0;
            }
        }
        for (int j = 0; j < enemies[i].height; j++)
        {
            mvprintw(enemies[i].y + j, enemies[i].x, "%s", enemies[i].data[j]);
        }
    }
    refresh();
}

void waitForRefreshRate()
{
    usleep(1000000 / FRAME_RATE);
}

void initWindow(Window* window)
{
    getmaxyx(stdscr, window->height, window->width);
}