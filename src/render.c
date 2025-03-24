#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#include "../include/settings.h"
#include "../include/sprites.h"
#include "../include/structs.h"

void renderSprite(const Sprite* sprite)
{
    for (int i = 0; i < sprite->height; i++)
    {
        mvprintw(sprite->y + i, sprite->x, "%s", sprite->data[i]);
    }
    refresh(); // Single refresh after all updates
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

void clearConsole()
{
    printf("\033[2J"); // ANSI escape code for clearing the screen
    printf("\033[1;1H"); // ANSI escape code for moving the cursor to the top-left corner
}

void waightForRefreshRate()
{
    usleep(1000000 / FRAME_RATE);
}

void initWindow(Window* window)
{
    getmaxyx(stdscr, window->height, window->width);
}
