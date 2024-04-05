#include <math.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "./figures/figuresForGames.h"
#include "controller/reader_with_console.h"
#include "macro/macro_definitions.h"
#include "map/map_for_board.h"
#include "menu/menu_for_game.h"

void inputKey();
void FillinArrayMap(int array[Y_SIZE_ARRAY][X_SIZE_ARRAY]);
void printArrayWithColors(int array[Y_SIZE_ARRAY][X_SIZE_ARRAY]);

int main() {
    initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    initMap(arr);

    inputKey(arr);
    refresh();
    getch();
    endwin();

    return 0;
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