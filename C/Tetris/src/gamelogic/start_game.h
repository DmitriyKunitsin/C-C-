#ifndef START_GAME_H
#define START_GAME_H

#include "../includes/common.h"
#include "../map/map_for_board.h"

void startGame(WINDOW *gameWindow);
void nextFigureGeneretion(GameInfo_t *game, WINDOW *gameWindow);
int getRandNumberFigures();

void clearBoard(GameInfo_t *game);

void initGame(GameInfo_t *game);
void my_free(int **array);
void initArray(int ***array);

GameInfo_t *getInstance_GameInfo();

GameInfo_t updateCurrentState();
void userInput(UserAction_t action, bool hold);

#endif