
#include "map_for_board.h"

int arr[Y_SIZE_ARRAY][X_SIZE_ARRAY];

void printArrayWithColors(int array[Y_SIZE_ARRAY][X_SIZE_ARRAY]) {
    for (int i = 0; i < Y_SIZE_ARRAY; i++) {
        for (int j = 0; j < X_SIZE_ARRAY; j++) {
            if (array[i][j] == 0) {
                attron(COLOR_BLACK);  // цвет вместо нуля
                printw(" ");  // вывод пробела вместо нуля
                attroff(COLOR_BLACK);
            } else {
                attron(COLOR_BLACK);
                printw("#");
                attroff(COLOR_BLACK);
            }
        }
        printw("\n");
    }
}
void FillinArrayMap(int array[Y_SIZE_ARRAY][X_SIZE_ARRAY]) {
    for (int i = 0; i < Y_SIZE_ARRAY; i++) {
        for (int j = 0; j < X_SIZE_ARRAY; j++) {
            if ((i == 0 || i == Y_GAME_BOARD - 1) && (j < X_GAME_BOARD)) {
                array[i][j] = 1;
            } else if (j == 0 || j == X_GAME_BOARD - 1) {
                array[i][j] = 1;
            } else {
                array[i][j] = 0;
            }
        }
    }
    printArrayWithColors(array);
}