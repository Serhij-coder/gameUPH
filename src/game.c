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
    static int continueGame = 0;

    Settings setts;
    setts.FRAME_RATE = 30; // !!!_NEMENIT_!!!
    setts.ENEMY_SHOOT_SPEED = 3; // Seconds per bullet
    setts.ENEMY_MOVE_SPEED = 15; // Every x frames
    setts.ENEMIES_SPAWN_RATE = 5; // Every x seconds
    setts.IS_ENEMY_SHOOTING = 0;
    setts.SHOOT_SPEED = 3; // Bullets per second

    Window window;
    initWindow(&window);

    GameStat gameStat;
    gameStat.time = 0;
    gameStat.score = 0;
    gameStat.gameMode = 2; // 0 - game, 1 - authors, 2 - menu, 3 - game over

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
                gameStat.gameMode = 2;
                continue;
            }

            playerMovement(&player, &window, key);
            playerShoot(playerBullets, &player, &setts, key);

            enemyMovement(enemies, &window, &setts);
            if (setts.IS_ENEMY_SHOOTING == 1)
            {
                enemyShoot(enemyBullets, enemies, &setts);
            }

            collisionCheck(&player, enemies, playerBullets, enemyBullets, &gameStat);

            clear();
            renderEnemyBullet(enemyBullets);
            renderBullet(playerBullets);
            renderEnemies(enemies);
            renderSprite(&player);
            renderGameStat(&gameStat);

            waitForRefreshRate(&setts);
            countGameTime(&gameStat, &setts);
        }
        else if (gameStat.gameMode == 1) // Authors
        {
            clear();

            authors(&window);

            gameStat.gameMode = 2;
        }
        else if (gameStat.gameMode == 2) // Menu
        {
            clear();

            menu(&window, &gameStat, key);

            waitForRefreshRate(&setts);
        }
        else if (gameStat.gameMode == 3) // Game over
        {
            clear();
            continueGame = gameOver(&window, &gameStat);
            if (continueGame == 0)
            {
                isGame = 0;
            }
            else if (continueGame == 1)
            {
                setts.FRAME_RATE = 30;
                setts.ENEMY_SHOOT_SPEED = 3; // Seconds per bullet
                setts.ENEMY_MOVE_SPEED = 15; // Every x frames
                setts.ENEMIES_SPAWN_RATE = 5; // Every x seconds
                setts.IS_ENEMY_SHOOTING = 0;
                setts.SHOOT_SPEED = 3; // Bullets per second

                gameStat.time = 0;
                gameStat.score = 0;
                gameStat.gameMode = 2; // 0 - game, 1 - authors, 2 - menu, 3 - game over

                clearGameField(enemies, playerBullets, enemyBullets);
                continue;
            }
        }
    }
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

void playerShoot(Bullet playerBulletsArr[BULLETS_ARR_SIZE], const Player* player, Settings* setts, int key)
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
                delay = setts->FRAME_RATE / setts->SHOOT_SPEED;
                break;
            }
        }
    }
}

void enemyMovement(Enemy enemies[ENEMIES_ARR_SIZE], Window* window, Settings* setts)
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
                spawnDelay = setts->FRAME_RATE * setts->ENEMIES_SPAWN_RATE;
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
            if (enemies[i].moveTime >= setts->ENEMY_MOVE_SPEED)
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
    }
}

void enemyShoot(Bullet enemyBullets[ENEMY_BULLETS_ARR_SIZE], Enemy enemies[ENEMIES_ARR_SIZE], Settings* setts)
{
    for (int i = 0; i < ENEMIES_ARR_SIZE; i++)
    {
        if (enemies[i].active == 1)
        {
            if (enemies[i].shootDelay > 0)
            {
                enemies[i].shootDelay--;
            }
            else
            {
                for (int j = 0; j < ENEMY_BULLETS_ARR_SIZE; j++)
                {
                    if (enemyBullets[j].active == 0)
                    {
                        enemyBullets[j].active = 1;
                        enemyBullets[j].x = enemies[i].x + enemies[i].width / 2;
                        enemyBullets[j].y = enemies[i].y + enemies[i].height;
                        enemies[i].shootDelay = setts->FRAME_RATE * setts->ENEMY_SHOOT_SPEED;
                        break;
                    }
                }
            }
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
    for (int i = 0; i < ENEMY_BULLETS_ARR_SIZE; i++)
    {
        if (enemyBullets[i].active == 1)
        {
            if (enemyBullets[i].x >= player->x &&
                enemyBullets[i].x <= player->x + player->width &&
                enemyBullets[i].y >= player->y &&
                enemyBullets[i].y <= player->y + player->height)
            {
                enemyBullets[i].active = 0;
                enemyBullets[i].y = 1000;

                gameStat->score -= Random(18, 22);
            }
        }
    }
    for (int i = 0; i < ENEMIES_ARR_SIZE; i++)
    {
        if (enemies[i].active == 1)
        {
            if (enemies[i].y >= player->y)
            {
                gameStat->gameMode = 3; // Game over
            }
        }
    }
}

void countGameTime(GameStat* gameStat, Settings* setts)
{
    static int ctr = 0;
    if (ctr == setts->FRAME_RATE)
    {
        gameStat->time++;
        ctr = 0;
    }
    else
    {
        ctr++;
    }


    if (gameStat->time == 60) // 1 minute
    {
        setts->ENEMY_MOVE_SPEED = 13;
    }
    else if (gameStat->time == 120) // 2 minutes
    {
        setts->ENEMIES_SPAWN_RATE = 3;
    }
    else if (gameStat->time == 180) // 3 minutes
    {
        setts->ENEMY_MOVE_SPEED = 11;
    }
    else if (gameStat->time == 240) // 4 minutes
    {
        setts->IS_ENEMY_SHOOTING = 1;
    }
    else if (gameStat->time == 300) // 5 minutes
    {
        setts->ENEMY_SHOOT_SPEED = 2;
    }
    else if (gameStat->time == 360) // 6 minutes
    {
        setts->ENEMIES_SPAWN_RATE = 2;
    }
    else if (gameStat->time == 400) // 7 minutes
    {
        setts->ENEMY_MOVE_SPEED = 9;
    }
    else if (gameStat->time == 480) // 8 minutes
    {
        setts->ENEMY_SHOOT_SPEED = 1;
    }
    else if (gameStat->time == 540) // 9 minutes
    {
        setts->ENEMY_MOVE_SPEED = 7;
    }
    else if (gameStat->time == 600) // 10 minutes
    {
        setts->ENEMIES_SPAWN_RATE = 1;
    }
}

int gameOver(Window* window, GameStat* gameStat)
{
    static int start_x = 0;
    static int start_y = 0;

    const char* gameOver[] = {
        " ██████      ███    ██     ██ ████████         ███████  ██     ██ ████████ ████████  ",
        "██    ██    ██ ██   ███   ███ ██              ██     ██ ██     ██ ██       ██     ██ ",
        "██         ██   ██  ████ ████ ██              ██     ██ ██     ██ ██       ██     ██ ",
        "██   ████ ██     ██ ██ ███ ██ ██████          ██     ██ ██     ██ ██████   ████████  ",
        "██    ██  █████████ ██     ██ ██              ██     ██  ██   ██  ██       ██   ██   ",
        "██    ██  ██     ██ ██     ██ ██              ██     ██   ██ ██   ██       ██    ██  ",
        " ██████   ██     ██ ██     ██ ████████         ███████     ███    ████████ ██     ██ "
    };

    start_x = window->width / 2 - 43;
    start_y = window->height / 2 - 20;

    clear();

    for (int i = 0; i < 7; i++)
    {
        mvprintw(start_y + i, start_x, "%s", gameOver[i]);
    }
    mvprintw(start_y + 8, start_x, "Your score: %d", gameStat->score);
    mvprintw(start_y + 9, start_x, "Time played: %d:%02d", gameStat->time / 60, gameStat->time % 60);
    mvprintw(start_y + 10, start_x, "Press 'q' to quit or 'e' to return to menu");

    nodelay(stdscr, 0);
    int key = getch();
    if (key == 'q')
    {
        nodelay(stdscr, 1);
        return 0;
    }
    else if (key == 'e')
    {
        nodelay(stdscr, 1);
        return 1;
    }
}

void clearGameField(Enemy enemies[ENEMIES_ARR_SIZE],
                    Bullet playerBulletsArr[BULLETS_ARR_SIZE],
                    Bullet enemyBullets[ENEMY_BULLETS_ARR_SIZE])
{
    for (int i = 0; i < ENEMIES_ARR_SIZE; i++)
    {
        enemies[i].active = 0;
        enemies[i].y = -10;
    }
    for (int i = 0; i < BULLETS_ARR_SIZE; i++)
    {
        playerBulletsArr[i].active = 0;
        playerBulletsArr[i].y = 1000;
    }
    for (int i = 0; i < ENEMY_BULLETS_ARR_SIZE; i++)
    {
        enemyBullets[i].active = 0;
        enemyBullets[i].y = 1000;
    }
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
        menuMode = (menuMode - 1 + 2) % 2;
    }
    else if (key == MENU_DOWN)
    {
        menuMode = (menuMode + 1) % 2;
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

    for (int i = 0; i < 15; i++)
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
        "ChatGPT DeepSeek                                                                     ",
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