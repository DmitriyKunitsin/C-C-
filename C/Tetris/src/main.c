#include <math.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "./figures/figuresForGames.h"
#include "controller/reader_with_console.h"
#include "gamelogic/start_game.h"
#include "macro/macro_definitions.h"
#include "map/map_for_board.h"
#include "menu/menu_for_game.h"

// void inputKey();
// void FillinArrayMap(int array[Y_SIZE_ARRAY][X_SIZE_ARRAY]);
// void printArrayWithColors(int array[Y_SIZE_ARRAY][X_SIZE_ARRAY]);
void initArray(int ***array);
void my_free(int **array);
void initGame(GameInfo_t *game);

void initializeWindows(WINDOW **gameWindow, WINDOW **menuWindow);
void cleanupWindows(WINDOW *gameWindow, WINDOW *menuWindow);

int main() {
    GameInfo_t game;
    initGame(&game);
    WINDOW *gameWindow;
    WINDOW *menuWindow;

    initializeWindows(&gameWindow, &menuWindow);
    // initscr();
    srand(time(NULL));
    keypad(menuWindow, TRUE);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);
    /*___________________________________________________*/

    // int key;
    // int current_screen = 1;  // 1 - menu 2 - game
    // while ((key = getch()) != KEY_BACKSPACE) {
    //     if (current_screen == 1) {
    //         printMenu(menuWindow, 0);
    //         int selectedMenu = ReaderSelectedMenu(menuWindow);
    //         current_screen = selectedMenu;
    //     } else if (current_screen == 2) {
    //         startGame(game.field, gameWindow);
    //     }
    // }

    /*_____________________________________________________*/
    initMap(game.field);

    ReaderForMenuSelectedItem(&game, menuWindow, gameWindow);

    my_free(game.field);
    my_free(game.menu);
    my_free(game.next);

    cleanupWindows(gameWindow, menuWindow);
    endwin();
    return 0;
}

void initializeWindows(WINDOW **gameWindow, WINDOW **menuWindow) {
    initscr();  // Инициализация ncurses
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    *gameWindow = newwin(Y_GAME_BOARD, X_GAME_BOARD, 0, 0);
    *menuWindow = newwin(Y_MENU, X_MENU, 0, X_GAME_BOARD + 1);
}

void cleanupWindows(WINDOW *gameWindow, WINDOW *menuWindow) {
    delwin(gameWindow);
    delwin(menuWindow);
    endwin();  // Завершение работы с ncurses
}
void initArray(int ***array) {
    *array = (int **)malloc(Y_SIZE_ARRAY * sizeof(int *));
    for (int i = 0; i < Y_SIZE_ARRAY; i++) {
        (*array)[i] = (int *)malloc(X_SIZE_ARRAY * sizeof(int));
    }
}

void my_free(int **array) {
    for (int i = 0; i < Y_SIZE_ARRAY; i++) {
        free(array[i]);
    }
    free(array);
}

void initGame(GameInfo_t *game) {
    initArray(&(game->field));
    initArray(&(game->menu));
    // initArray(&(game->next));
    // int score = 0;
    // int high_score = 0;
    // int level = 1;
    // int speed = 1;
    // int pause = 0;
}
/******************************************TRASH*********************************************************/
// State Transition(State current, char input);
// State currentState = STATE_A;
// char inp[] = {'0', '1', '0', '1', '0'};

// for (size_t i = 0; i < sizeof(inp) / sizeof(inp[0]); i++) {
//     currentState = Transition(currentState, inp[i]);
//     printf("Input: %c, State: %d\n", inp[i], currentState);
// }

// State Transition(State current, char input) {
//     switch (current) {
//         case STATE_A:
//             if (input == '0') {
//                 return STATE_B;
//             } else {
//                 return STATE_A;
//             }
//             break;
//         case STATE_B:
//             if (input == '1') {
//                 return STATE_C;
//             } else {
//                 return STATE_A;
//             }
//             break;
//         case STATE_C:
//             if (input == '0') {
//                 return STATE_B;
//             } else {
//                 return STATE_C;
//             }
//             break;
//     }
//     return current;
// }

// void printFieldBound() {
//     for (int i = 0; i < Y_GAME_BOARD; i++) {
//         for (int j = 0; j < X_GAME_BOARD; j++) {
//             printf("%c",
//                    (i == 0 || i == Y_GAME_BOARD - 1)
//                        ? (j != 0 && j != X_GAME_BOARD - 1 ? TOP_LINE : ' ')
//                        : ' ');
//             printf("%c", (j == 0 || j == X_GAME_BOARD - 1)
//                              ? (i != 0 && i != Y_GAME_BOARD - 1
//                                     ? SIDE_LINE
//                                     : (j == X_GAME_BOARD - 1 &&
//                                                (i == 0 || i == Y_GAME_BOARD -
//                                                1)
//                                            ? SIDE_LINE
//                                            : ' '))
//                              : ' ');
//         }
//         printf("\n");
//     }
// }

// for(int i = 0; i < X_GAME_BOARD; i++) {
//     for(int j = 0; j < Y_GAME_BOARD; j++) {
//         if (i == 0 || i == X_GAME_BOARD - 1) {
//             if(j != 0 && j != Y_GAME_BOARD - 1) {
//             printf("%c", TOP_LINE);
//             } else {
//                 printf("%s", " ");
//             }
//         } else {
//             printf("%s"," ");
//         }
//         if(j == 0 || j == Y_GAME_BOARD - 2) {
//             if(i != 0 && i != X_GAME_BOARD - 1) {
//                 printf("%c", SIDE_LINE);
//             } else if(j == Y_GAME_BOARD - 2 && (i == 0 || i ==
//             X_GAME_BOARD - 1)) {
//                 printf(" %c", SIDE_LINE);
//             }
//         } else {
//             printf("%s", " ");
//         }
//     }
//     printf("\n");
// }
// }