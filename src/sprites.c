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
