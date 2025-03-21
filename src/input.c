#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>

void setupNonBlockingInput() {
    // struct termios oldt, newt;
    // int oldf;
    //
    // tcgetattr(STDIN_FILENO, &oldt);
    // newt = oldt;
    // newt.c_lflag &= ~(ICANON | ECHO);
    // tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    // oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    // fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
}

char getKeyPress() {
    return  getch();
}
