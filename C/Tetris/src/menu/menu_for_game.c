#include "menu_for_game.h"

#include "../gamelogic/start_game.h"

void executeMenuItem(int item, int map[Y_SIZE_ARRAY][X_SIZE_ARRAY]) {
    switch (item) {
        case 0:
            startGame(map);
            break;
        case 1:
            endwin();
            exit(0);
            break;
        default:
            break;
    }
}

void printMenu(int selectedItem) {
    int startY = 1;
    int startX = START_RIGHT_MENU_WIDTH + 1;
    mvprintw(startY, startX, "Menu");
    for (int i = 0; i < 2; i++) {
        if (selectedItem == i) {
            attron(A_REVERSE);
        }
        mvprintw(startY + 1 + i, startX, "%d. %s", i + 1,
                 (i == 0) ? "Start Game" : "Exit");
        if (i == selectedItem) {
            attroff(A_REVERSE);
        }
    }
}