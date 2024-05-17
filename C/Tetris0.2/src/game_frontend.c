#include "../inc/game_frontend.h"

#include "../inc/fsm.h"
#include "../inc/game_backend.h"

#pragma region -GAME

void printFieldMap() {
    GameInfo_t *game = getGameInfo();
    for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
        for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
            (game->field[i][j] == 1) ? mvprintw(i, j, "%d", 1)
                                     : mvprintw(i, j, "%d", 0);
        }
    }
}

#pragma endregion

#pragma region -MENU-code

void ReaderForMenuSelectedItem() {
    int key;
    int selectedItem = 0;
    printMenu(0);
    while ((key = getch()) != KEY_BACKSPACE) {
        switch (key) {
            case KEY_UP:
                selectedItem = (selectedItem - 1 >= 0) ? selectedItem - 1 : 0;
                break;
            case KEY_DOWN:
                selectedItem =
                    (selectedItem + 1 < 2) ? selectedItem + 1 : 2 - 1;
                break;
            case '\n':
                executeMenuItem(selectedItem);
                break;
            default:
                selectedItem = 0;
                break;
        }
        printMenu(selectedItem);
    }
}
void printMenu(int selectedItem) {
    int startY = 5;
    int startX = 5;
    mvprintw(2, 8, "Menu");
    for (int i = 0; i < 2; ++i) {
        if (selectedItem == i) {
            attron(A_REVERSE);
        }
        mvprintw(startY + 2 + i, startX, "%d. %s", i + 1,
                 (i == 0) ? "Start" : "Exit");
        if (selectedItem == i) {
            attroff(A_REVERSE);
        }
    }
    refresh();
}
void executeMenuItem(int item) {
    switch (item) {
        case 0:
            startGame();
            clear();
            break;
        case 1:
            endwin();
            exit(0);
            break;
        default:
            break;
            // TODO добавить в меню просмотр рекордов, мб настройки
    }
}
#pragma endregion