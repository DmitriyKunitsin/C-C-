#include <ncurses.h>
#include <stdio.h>

typedef enum {
    LEFT,
    RIGHT
} test;

int main() {
    initscr();
    keypad(stdscr, TRUE);
    noecho();

    int key = getch();
    test t;

    if(key == KEY_LEFT) {
        t = LEFT;
        printw("Стрелка влево\n");
    } else {
        printw("Ничего\n");
    }

    if(t == LEFT) {
        printw("ENUM LEFT\n");
    }
    printw("\n%d\n", key);
    refresh();
    getch(); // Ждем нажатия любой клавиши
    endwin(); // Завершение работы с ncurses
    return 0;
}
