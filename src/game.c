#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

#include "../include/sprites.h"
#include "../include/function.h"
#include "../include/settings.h"
#include "../include/structs.h"

void gameLoop()
{
    static int isGame = 1;

    Window window;
    initWindow(&window);

    GameStat gameStat;
    gameStat.time = 0;
    gameStat.score = 0;
    gameStat.gameMode = 3;

    Player player = createPlayer(playerSpriteData, 7, SPRITE_HEIGHT, 0, 0);
    player.y = window.height - player.height;
    player.x = window.width / 2 - player.width / 2;

    Bullet playerBullets[BULLETS_ARR_SIZE];
    createPlayerBulletsArr(playerBullets);

    Enemy enemies[ENEMIES_ARR_SIZE];
    createEnemiesArr(enemies);

    Bullet enemyBullets[ENEMY_BULLETS_ARR_SIZE];
    createEnemyBulletArr(enemyBullets);


    while (isGame)
    {
        if (isGame == 0)
        {
            break;
        }
        char key = getKeyPress();

        if (gameStat.gameMode == 0) // Game
        {
            if (key == 'q')
            {
                gameStat.gameMode = 3;
                continue;
            }

            playerMovement(&player, &window, key);
            playerShoot(playerBullets, &player, key);

            enemyMovement(enemies, &window);

            collisionCheck(&player, enemies, playerBullets, enemyBullets, &gameStat);

            clear();
            renderEnemies(enemies);
            renderBullet(playerBullets);
            renderSprite(&player);
            renderGameStat(&gameStat);

            waitForRefreshRate();
            countGameTime(&gameStat);
        }
        else if (gameStat.gameMode == 1) // Settings
        {
            clear();

            settings(&window);

            gameStat.gameMode = 3;
        }
        else if (gameStat.gameMode == 2) // Authors
        {
            clear();

            authors(&window);

            gameStat.gameMode = 3;
        }
        else if (gameStat.gameMode == 3) // Menu
        {
            clear();

            menu(&window, &gameStat, key);

            waitForRefreshRate();
        }
    };
}


void playerMovement(Player* player, const Window* window, int key)
{
    switch (key)
    {
    case MOVE_LEFT:
        player->x--;
        if (player->x < 0) player->x = 0;
        break;
    case MOVE_RIGHT:
        player->x++;
        if (player->x > window->width - player->width)
            player->x = window->width - player->width;
        break;
    default: break;
    }
}

void playerShoot(Bullet playerBulletsArr[BULLETS_ARR_SIZE], const Player* player, int key)
{
    static int delay = 0;
    if (delay > 0)
    {
        delay--;
        return;
    }
    if (key == SHOOT)
    {
        for (int i = 0; i < BULLETS_ARR_SIZE; i++)
        {
            if (playerBulletsArr[i].active == 0)
            {
                playerBulletsArr[i].active = 1;
                playerBulletsArr[i].x = player->x + player->width / 2;
                playerBulletsArr[i].y = player->y;
                delay = FRAME_RATE / SHOOT_SPEED;
                break;
            }
        }
    }
}

void enemyMovement(Enemy enemies[ENEMIES_ARR_SIZE], Window* window)
{
    static int spawnDelay = 0;
    if (spawnDelay == 0)
    {
        for (int i = 0; i < ENEMIES_ARR_SIZE; i++)
        {
            if (enemies[i].active == 0)
            {
                enemies[i].active = 1;
                enemies[i].x = Random(0, window->width - SPRITE_WIDTH);
                enemies[i].y = 0;
                spawnDelay = FRAME_RATE * ENEMIES_SPAWN_RATE;
                break;
            }
        }
    }
    else
    {
        spawnDelay--;
    }
    for (int i = 0; i < ENEMIES_ARR_SIZE; i++)
    {
        if (enemies[i].active == 1)
        {
            if (enemies[i].moveTime == ENEMY_MOVE_SPEED)
            {
                enemies[i].y++;
                enemies[i].moveTime = 0;
                if (Random(0, 10) == 2)
                {
                    enemies[i].x++;
                }
                else if (Random(0, 10) == 8)
                {
                    enemies[i].x--;
                }

                if (enemies[i].x < 0) enemies[i].x = 0;
                if (enemies[i].x > window->width - SPRITE_WIDTH) enemies[i].x = window->width - SPRITE_WIDTH;
            }
            else
            {
                enemies[i].moveTime++;
            }
        }

        if (enemies[i].y >= window->height - SPRITE_HEIGHT)
        {
            gameOver();
        }
    }
}

void collisionCheck(Player* player,
                    Enemy enemies[ENEMIES_ARR_SIZE],
                    Bullet playerBulletsArr[BULLETS_ARR_SIZE],
                    Bullet enemyBullets[ENEMY_BULLETS_ARR_SIZE],
                    GameStat* gameStat)
{
    for (int i = 0; i < ENEMIES_ARR_SIZE; i++)
    {
        for (int j = 0; j < BULLETS_ARR_SIZE; j++)
        {
            if (playerBulletsArr[j].x >= enemies[i].x &&
                playerBulletsArr[j].x <= enemies[i].x + enemies[i].width &&
                playerBulletsArr[j].y >= enemies[i].y &&
                playerBulletsArr[j].y <= enemies[i].y + enemies[i].height)
            {
                playerBulletsArr[j].active = 0;
                playerBulletsArr[j].y = 1000;
                enemies[i].active = 0;
                enemies[i].y = -10;

                gameStat->score += Random(8, 12);
            }
        }
    }
}

void countGameTime(GameStat* gameStat)
{
    static int ctr = 0;
    if (ctr == FRAME_RATE)
    {
        gameStat->time++;
        ctr = 0;
    }
    else
    {
        ctr++;
    }
}

void gameOver()
{
}

// Welcome to my dark, dark, dark side
// Toto je velmi hnusne :(
void menu(Window* window, GameStat* game_stat, int key)
{
    static int start_x = 0;
    static int start_y = 0;
    static int menuMode = 0; // 0 - game, 1 - settings, 2 - authors

    const char* asciiArt[] = {
        " ██████  ████████    ███    ████████          ████████  ████████ ████████ ████████ ██    ██ ████████  ████████ ████████   ██████  ",
        "██    ██    ██      ██ ██   ██     ██         ██     ██ ██       ██       ██       ███   ██ ██     ██ ██       ██     ██ ██    ██ ",
        "██          ██     ██   ██  ██     ██         ██     ██ ██       ██       ██       ████  ██ ██     ██ ██       ██     ██ ██       ",
        " ██████     ██    ██     ██ ████████          ██     ██ ██████   ██████   ██████   ██ ██ ██ ██     ██ ██████   ████████   ██████  ",
        "      ██    ██    █████████ ██   ██           ██     ██ ██       ██       ██       ██  ████ ██     ██ ██       ██   ██         ██ ",
        "██    ██    ██    ██     ██ ██    ██          ██     ██ ██       ██       ██       ██   ███ ██     ██ ██       ██    ██  ██    ██ ",
        " ██████     ██    ██     ██ ██     ██         ████████  ████████ ██       ████████ ██    ██ ████████  ████████ ██     ██  ██████  "
    };

    const char* pointer[] = {
        "██     ",
        " ██    ",
        "  ██   ",
        "   ██  ",
        "  ██   ",
        " ██    ",
        "██     "
    };

    const char* menuItems[] = {
        " ██████      ███    ██     ██ ████████                              ",
        "██    ██    ██ ██   ███   ███ ██                                    ",
        "██         ██   ██  ████ ████ ██                                    ",
        "██   ████ ██     ██ ██ ███ ██ ██████                                ",
        "██    ██  █████████ ██     ██ ██                                    ",
        "██    ██  ██     ██ ██     ██ ██                                    ",
        " ██████   ██     ██ ██     ██ ████████                              ",
        "                                                                    ",
        "██████  ████████ ████████ ████████ ████ ██    ██  ██████    ██████  ",
        "██    ██ ██         ██       ██     ██  ███   ██ ██    ██  ██    ██ ",
        "██       ██         ██       ██     ██  ████  ██ ██        ██       ",
        " ██████  ██████     ██       ██     ██  ██ ██ ██ ██   ████  ██████  ",
        "      ██ ██         ██       ██     ██  ██  ████ ██    ██        ██ ",
        "██    ██ ██         ██       ██     ██  ██   ███ ██    ██  ██    ██ ",
        " ██████  ████████   ██       ██    ████ ██    ██  ██████    ██████  ",
        "                                                                    ",
        "   ███    ██     ██ ████████ ██     ██  ███████  ████████   ██████  ",
        "  ██ ██   ██     ██    ██    ██     ██ ██     ██ ██     ██ ██    ██ ",
        " ██   ██  ██     ██    ██    ██     ██ ██     ██ ██     ██ ██       ",
        "██     ██ ██     ██    ██    █████████ ██     ██ ████████   ██████  ",
        "█████████ ██     ██    ██    ██     ██ ██     ██ ██   ██         ██ ",
        "██     ██ ██     ██    ██    ██     ██ ██     ██ ██    ██  ██    ██ ",
        "██     ██  ███████     ██    ██     ██  ███████  ██     ██  ██████  "
    };

    start_x = window->width / 2 - 65;
    start_y = window->height / 2 - 20;

    clear();

    for (int i = 0; i < 7; i++)
    {
        mvprintw(start_y + i, start_x, "%s", asciiArt[i]);
    }

    if (key == MENU_UP)
    {
        menuMode = (menuMode - 1 + 3) % 3;
    }
    else if (key == MENU_DOWN)
    {
        menuMode = (menuMode + 1) % 3;
    }
    else if (key == 'q')
    {
        game_stat->gameMode = 0;
        return;
    }
    else if (key == 'e' || key == SHOOT)
    {
        game_stat->gameMode = menuMode;
        return;
    }

    int menu_start_y = start_y + 10;
    int menu_start_x = start_x + 20;

    for (int i = 0; i < 23; i++)
    {
        mvprintw(menu_start_y + i, menu_start_x + 7, "%s", menuItems[i]);
    }

    int pointer_y = menu_start_y + (menuMode * 8);
    for (int i = 0; i < 7; i++)
    {
        mvprintw(pointer_y + i, menu_start_x, "%s", pointer[i]);
    }

    refresh();
}

void authors(Window* window)
{
    const char* authorsArt[] = {
        " ██████  ████████ ████████  ██     ██ ████ ████                                      ",
        "██    ██ ██       ██     ██ ██     ██  ██   ██                                       ",
        "██       ██       ██     ██ ██     ██  ██   ██                                       ",
        " ██████  ██████   ████████  █████████  ██   ██                                       ",
        "      ██ ██       ██   ██   ██     ██  ██   ██                                       ",
        "██    ██ ██       ██    ██  ██     ██  ██   ██                                       ",
        " ██████  ████████ ██     ██ ██     ██ ████ ████                                      ",
        "                                                                                     ",
        "████████ ████████ ████████   ███████  ████████  ████████ ██    ██ ██    ██  ███████  ",
        "██       ██       ██     ██ ██     ██ ██     ██ ██       ███   ██ ██   ██  ██     ██ ",
        "██       ██       ██     ██ ██     ██ ██     ██ ██       ████  ██ ██  ██   ██     ██ ",
        "██████   ██████   ██     ██ ██     ██ ████████  ██████   ██ ██ ██ █████    ██     ██ ",
        "██       ██       ██     ██ ██     ██ ██   ██   ██       ██  ████ ██  ██   ██     ██ ",
        "██       ██       ██     ██ ██     ██ ██    ██  ██       ██   ███ ██   ██  ██     ██ ",
        "██       ████████ ████████   ███████  ██     ██ ████████ ██    ██ ██    ██  ███████  ",
        "                                                                                     ",
        "                                                                                     ",
        "                                                                                     ",
        "██       ██     ██ ██    ██    ███     ██████                                        ",
        "██       ██     ██ ██   ██    ██ ██   ██    ██                                       ",
        "██       ██     ██ ██  ██    ██   ██  ██                                             ",
        "██       ██     ██ █████    ██     ██  ██████                                        ",
        "██       ██     ██ ██  ██   █████████       ██                                       ",
        "██       ██     ██ ██   ██  ██     ██ ██    ██                                       ",
        "████████  ███████  ██    ██ ██     ██  ██████                                        ",
        "                                                                                     ",
        "██          ███     ██████  ██    ██  ███████                                        ",
        "██         ██ ██   ██    ██ ██   ██  ██     ██                                       ",
        "██        ██   ██  ██       ██  ██   ██     ██                                       ",
        "██       ██     ██ ██       █████    ██     ██                                       ",
        "██       █████████ ██       ██  ██   ██     ██                                       ",
        "██       ██     ██ ██    ██ ██   ██  ██     ██                                       ",
        "████████ ██     ██  ██████  ██    ██  ███████                                        "
    };
    int start_x = window->width / 2 - 43;
    int start_y = window->height / 2 - 16;

    for (int i = 0; i < 33; i++)
    {
        mvprintw(start_y + i, start_x, "%s", authorsArt[i]);
    }

    nodelay(stdscr, 0);
    getch();
    nodelay(stdscr, 1);
}

void settings(Window* window)
{
    const char* asciiArt[] = {
        "██    ██  ███████  ████████ ██     ██ ████ ██    ██  ██████   ",
        "███   ██ ██     ██    ██    ██     ██  ██  ███   ██ ██    ██  ",
        "████  ██ ██     ██    ██    ██     ██  ██  ████  ██ ██        ",
        "██ ██ ██ ██     ██    ██    █████████  ██  ██ ██ ██ ██   ████ ",
        "██  ████ ██     ██    ██    ██     ██  ██  ██  ████ ██    ██  ",
        "██   ███ ██     ██    ██    ██     ██  ██  ██   ███ ██    ██  ",
        "██    ██  ███████     ██    ██     ██ ████ ██    ██  ██████   ",
        "                                                              ",
        "████████  ███████  ████████                                   ",
        "██       ██     ██ ██     ██                                  ",
        "██       ██     ██ ██     ██                                  ",
        "██████   ██     ██ ████████                                   ",
        "██       ██     ██ ██   ██                                    ",
        "██       ██     ██ ██    ██                                   ",
        "██        ███████  ██     ██                                  ",
        "                                                              ",
        "██    ██  ███████  ██      ██                                 ",
        "███   ██ ██     ██ ██  ██  ██                                 ",
        "████  ██ ██     ██ ██  ██  ██                                 ",
        "██ ██ ██ ██     ██ ██  ██  ██                                 ",
        "██  ████ ██     ██ ██  ██  ██                                 ",
        "██   ███ ██     ██ ██  ██  ██                                 ",
        "██    ██  ███████   ███  ███                                  "
    };

    int start_x = window->width / 2 - 31;
    int start_y = window->height / 2 - 11;

    for (int i = 0; i < 23; i++)
    {
        mvprintw(start_y + i, start_x, "%s", asciiArt[i]);
    }

    nodelay(stdscr, 0);
    getch();
    nodelay(stdscr, 1);
}