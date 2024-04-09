#include "start_game.h"

#include "../figures/figuresForGames.h"
#include "../menu/menu_for_game.h"
#include "../includes/common.h"

void startGame(GameInfo_t *game, WINDOW *gameWindow, WINDOW *menuWin) {
    int key;
    while ((key = getch()) != KEY_BACKSPACE) {
        InformationMenu(game, menuWin);
        nextFigureGeneretion(game, gameWindow);
    }
}

// void InformationMenu(GameInfo_t *game_inf, WINDOW *menuWin) {
//     wclear(menuWin);
//     for (int i = 0; i < Y_MENU; i++) {
//         for (int j = 0; j < X_MENU; j++) {
//             if (i == 2) {
//                 mvwprintw(menuWin, i, j, "Level :%d", game_inf->level);
//             } else if (i == 4) {
//                 mvwprintw(menuWin, i, j, "Score :%d", game_inf->score);
//             } else if (i == 6) {
//                 mvwprintw(menuWin, i, j, "Speed :%d", game_inf->speed);
//             } else if (i == 8) {
//                 mvwprintw(menuWin, i, j, "Record :%d", game_inf->high_score);
//             }
//         }
//         wprintw(menuWin, "\n");
//     }
//     wrefresh(menuWin);
// }

void nextFigureGeneretion(GameInfo_t *game, WINDOW *gameWindow) {
    int figureNumber = getRandNumberFigures();

    clearBoard(game);

    FigureType type = (FigureType)figureNumber;

    int *figurePointer = getFigure(type);

    int dimesion = (figureNumber == 0) ? 4 : 3;

    for (int i = 0; i < dimesion; i++) {
        for (int j = 0; j < dimesion; j++) {
            int value = *(figurePointer + i * dimesion + j);

            game->field[i + 1][(X_GAME_BOARD / 2) + j] = value;
        }
    }
    printNextMap(game->field, gameWindow);
}

void clearBoard(GameInfo_t *game) {
    for (int i = 0; i < Y_GAME_BOARD; i++) {
        for (int j = 0; j < X_GAME_BOARD; j++) {
            if (i == 0 || i == Y_GAME_BOARD - 1) {
                game->field[i][j] = 1;
            } else if (j == 0 || j == X_GAME_BOARD - 1) {
                game->field[i][j] = 1;
            } else {
                game->field[i][j] = 0;
            }
        }
    }
}

int getRandNumberFigures() {
    int min = 0;
    int max = 6;
    int random_value = rand() % (max - min + 1) + min;
    random_value %= 10;
    return random_value;
}