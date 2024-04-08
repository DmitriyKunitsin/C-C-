#include "menu_for_game.h"

#include "../gamelogic/start_game.h"

void executeMenuItem(int item, int **map, WINDOW *gameWindow) {
    switch (item) {
        case 0:
            startGame(map, gameWindow);
            break;
        case 1:
            endwin();
            exit(0);
            break;
        default:
            break;
    }
}

void printMenu(WINDOW *menuWindow, int selectedItem) {
    int startY = 1;
    int startX =  1;
    
    mvwprintw(menuWindow, startY, startX, "Menu");
    for (int i = 0; i < 2; i++) {
        if (selectedItem == i) {
            wattron(menuWindow, A_REVERSE);
        }
        mvwprintw(menuWindow, startY + 1 + i, startX, "%d. %s", i + 1,
                 (i == 0) ? "Start" : "Exit");
        if (selectedItem == i) {
            wattroff(menuWindow, A_REVERSE);
        }
    }
    wrefresh(menuWindow);
}