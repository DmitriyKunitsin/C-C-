#ifndef START_GAME_H
#define START_GAME_H

#include "../includes/common.h"
#include "../map/map_for_board.h"

void startGame(GameInfo_t *game, WINDOW *gameWindow);
void nextFigureGeneretion(GameInfo_t *game, WINDOW *gameWindow);
int getRandNumberFigures();

void clearBoard(GameInfo_t *game);

#endif