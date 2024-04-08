
#include "map_for_board.h"

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
// void FillinArrayMap(int **array) {
//     for (int i = 0; i < Y_SIZE_ARRAY; i++) {
//         for (int j = 0; j < X_SIZE_ARRAY; j++) {
//             if ((i == 0 || i == Y_GAME_BOARD - 1) && (j < X_GAME_BOARD)) {
//                 array[i][j] = 1;
//             } else if (j == 0 || j == X_GAME_BOARD - 1) {
//                 array[i][j] = 1;
//             } else {
//                 array[i][j] = 0;
//             }
//         }
//     }
//     printArrayWithColors(array);
//     printMenu(0);
// }

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
    printArrayWithColors(map);
    // printMenu(1);
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