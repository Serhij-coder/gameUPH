//
// Created by serhii on 3/20/25.
//

#ifndef SPRITES_H
#define SPRITES_H

extern const char *enemySpriteData[5];
extern const char *playerSpriteData[5];

typedef struct {
    const char *data[5]; // Sprite data (5 lines of characters)
    int width;           // Width of the sprite
    int height;          // Height of the sprite
    int x, y;            // Position on the screen
} Sprite;

typedef struct {
    int width;
    int height;
    char horizontalSymbol;
    char verticalSymbol;
    char topLeftCorner;
    char topRightCorner;
    char bottomLeftCorner;
    char bottomRightCorner;
    int x, y;
}Border;

#endif //SPRITES_H
