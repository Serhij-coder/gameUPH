//
// Created by serhii on 3/20/25.
//

#ifndef FUCTION_H
#define FUCTION_H

// Sprites.c
Sprite createSprite(const char *data[], int width, int height, int x, int y);

Border createBorder(int width,
                    int height,
                    char horizontalSymbol,
                    char verticalSymbol,
                    char topLeftCorner,
                    char topRightCorner,
                    char bottomLeftCorner,
                    char bottomRightCorner,
                    int x, int y);

// Render.c
void clearConsole();

void renderSprite(const Sprite *sprite);

void renderBorder(const Border *border);

void fieldRender(const Border *border);

void waightForRefreshRate();

// Input.c
void setupNonBlockingInput();

char getKeyPress();

// Game.c
void gameLoop();
void playerMovement(Sprite *player, int key);

#endif //FUCTION_H
