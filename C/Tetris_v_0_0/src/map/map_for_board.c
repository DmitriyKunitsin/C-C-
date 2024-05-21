
#include "map_for_board.h"

#include "../gamelogic/start_game.h"
#include "../menu/menu_for_game.h"

int arr[Y_SIZE_ARRAY][X_SIZE_ARRAY];

void initMap(int **array) { InitGameBoard(array); }

void printArrayWithColors(int **array) {
    for (int i = 0; i < Y_SIZE_ARRAY; i++) {
        for (int j = 0; j < X_MENU; j++) {
            if (array[i][j] == 0) {
                attron(COLOR_PAIR(1));  // цвет вместо нуля
                printw(" ");  // вывод пробела вместо нуля
                attroff(COLOR_BLACK);
            } else {
                attron(COLOR_PAIR(2));
                printw("#");
                attroff(COLOR_BLACK);
            }
        }
        printw("\n");
    }
}

void saveOldMap(GameInfo_t *game) {
    for (int i = 1; i < Y_GAME_BOARD; ++i) {
        for (int j = 1; j < X_GAME_BOARD; ++j) {
            game->next[i][j] = game->field[i][j];
        }
    }
    clearBoard(game);
    for (int i = 1; i < Y_GAME_BOARD; ++i) {
        for (int j = 1; j < X_GAME_BOARD; ++j) {
            game->field[i][j] = game->next[i][j];
        }
    }
}

void InitGameBoard(int **map) {
    for (int i = 0; i < Y_GAME_BOARD; i++) {
        for (int j = 0; j < X_GAME_BOARD; j++) {
            if (i == 0 || i == Y_GAME_BOARD - 1) {
                map[i][j] = 1;
            } else if (j == 0 || j == X_GAME_BOARD - 1) {
                map[i][j] = 1;
            } else {
                map[i][j] = 0;
            }
        }
    }
    // printArrayWithColors(map);
}

void printNextMap(int **array, WINDOW *gameWindow) {
    for (int i = 0; i < Y_GAME_BOARD; i++) {
        for (int j = 0; j < X_GAME_BOARD; j++) {
            if (array[i][j] == 0) {
                wattron(gameWindow, COLOR_PAIR(1));  // цвет вместо нуля
                mvwprintw(gameWindow, i, j, " ");  // вывод пробела вместо нуля
                wattroff(gameWindow, COLOR_BLACK);
            } else {
                wattron(gameWindow, COLOR_PAIR(2));
                mvwprintw(gameWindow, i, j, "#");
                wattroff(gameWindow, COLOR_BLACK);
            }
        }
        wprintw(gameWindow, "\n");
    }
    wrefresh(gameWindow);
}
