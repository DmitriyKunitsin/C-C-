#include "../inc/game_frontend.h"

#include "../inc/fsm.h"
#include "../inc/game_backend.h"
#include "../inc/objects.h"

#pragma region -GAME

void printALLmap() {
    printGameMap();
    printFieldMap();
    printNEXTmap();
}
void printFieldMap() {
    GameInfo_t *game = getGameInfo();
    mvprintw(0, 13, "field");
    for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
        for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
            (game->field[i][j] == 1) ? mvprintw(i + 1, 13 + j, "%d", 1)
                                     : mvprintw(i + 1, 13 + j, "%d", 0);
        }
    }
}
void printNEXTmap() {
    GameInfo_t *game = getGameInfo();
    mvprintw(0, 25, "next");
    for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
        for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
            (game->next[i][j] == 1) ? mvprintw(i + 1, 25 + j, "%d", 1)
                                    : mvprintw(i + 1, 25 + j, "%d", 0);
        }
    }
}
void printGameMap() {
    const GameInfo_t *game = updateCurrentState();
    for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
        for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
            ((game->field[i][j] == 1) || (game->next[i][j] == 1))
                ? mvprintw(i, j, "%d", 1)
                : mvprintw(i, j, "%d", 0);
        }
    }
}

void printPauseMenu() {
    clear();
    mvprintw(10, 10, "PAUSE");
    mvprintw(12, 10, "press Q for GO");
}
void updateGameScreen() {
    const GameInfo_t *game = getGameInfo();
    Current_Figure *currentGameFigure = getCurrentFigure();
    clearOldNextMap();
    mvprintw(5, 45, "f->Y :%d , f->X :%d", currentGameFigure->Y,
             currentGameFigure->X);
    for (int i = 0; i < currentGameFigure->dimension; ++i) {
        for (int j = 0; j < currentGameFigure->dimension; ++j) {
            int value = currentGameFigure->curFigure[i][j];
            game->next[currentGameFigure->Y + i][currentGameFigure->X + j] =
                value;
        }
    }
}
void clearOldNextMap() {
    GameInfo_t *game = getGameInfo();
    for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
        for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
            game->next[i][j] = 0;
        }
    }
}
void printCurrentFigure() {
    const Current_Figure *figre = getCurrentFigure();
    mvprintw(9, 40, "Field");
    for (int i = 0; i < figre->dimension; ++i) {
        for (int j = 0; j < figre->dimension; ++j) {
            figre->curFigure[i][j] == 1
                ? mvprintw(10 + i, 40 + j, "%d", figre->curFigure[i][j])
                : mvprintw(10 + i, 40 + j, "0 ");
        }
    }
}
void printNextFigure() {
    const Current_Figure *figre = getCurrentFigure();
    mvprintw(14, 40, "Next");
    for (int i = 0; i < figre->dimension; ++i) {
        for (int j = 0; j < figre->dimension; ++j) {
            figre->nextFigure[i][j] == 1
                ? mvprintw(15 + i, 40 + j, "%d", figre->nextFigure[i][j])
                : mvprintw(15 + i, 40 + j, "0");
        }
    }
}
#pragma endregion

#pragma region -MENU-code
/*Блок с меню*/
void executeMenuItem(int item) {
    switch (item) {
        case 0:
            startGame();
            clear();
            break;
        case 1:
            EXIT_GAME();
            break;
        default:
            break;
            // TODO добавить в меню просмотр рекордов, мб настройки
    }
}
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
#pragma endregion