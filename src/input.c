#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

char getKeyPress()
{
    return getch();
}

int Random(int min, int max)
{
    static unsigned int seed;
    static int flag = 1;
    if (flag == 1)
    {
        seed = time(0);
        flag = 0;
    }
    // Generate a random number in the range [min, max]
    int rd_num = rand_r(&seed) % (max - min + 1) + min;
    return rd_num;
}
