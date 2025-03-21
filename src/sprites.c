#include "../include/sprites.h"

// Define the sprite for an enemy
const char *enemySpriteData[] = {
    "  ███  ",
    " █████ ",
    "█ ███ █",
    "███████",
    " ▀ ▀ ▀ ",
};

const char *playerSpriteData[] = {
    "   ▲   ",
    "  ███  ",
    " █████ ",
    "███████",
    "█  █  █",
};

Sprite createSprite(const char *data[], int width, int height, int x, int y) {
    Sprite sprite;
    for (int i = 0; i < height; i++) {
        sprite.data[i] = data[i];
    }
    sprite.width = width;
    sprite.height = height;
    sprite.x = x;
    sprite.y = y;
    return sprite;
}

Border createBorder(int width,
                    int height,
                    char horizontalSymbol,
                    char verticalSymbol,
                    char topLeftCorner,
                    char topRightCorner,
                    char bottomLeftCorner,
                    char bottomRightCorner,
                    int x, int y) {
    Border border;

    border.width = width;
    border.height = height;
    border.horizontalSymbol = horizontalSymbol;
    border.verticalSymbol = verticalSymbol;
    border.topLeftCorner = topLeftCorner;
    border.topRightCorner = topRightCorner;
    border.bottomLeftCorner = bottomLeftCorner;
    border.bottomRightCorner = bottomRightCorner;
    border.x = x;
    border.y = y;

    return border;
}
