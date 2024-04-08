#ifndef START_GAME_H
#define START_GAME_H

#include "../includes/common.h"
#include "../map/map_for_board.h"

void startGame(int **map, WINDOW *gameWindow, WINDOW *menuWin);
void nextFigureGeneretion(int **map, WINDOW *gameWindow);
int getRandNumberFigures();

#endif