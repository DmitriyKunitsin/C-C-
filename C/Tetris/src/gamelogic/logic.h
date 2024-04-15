#ifndef LOGIC_H
#define LOGIC_H

#define MAX_DIMENSION 4

#include "../includes/common.h"
#include "../macro/macro_definitions.h"
#include "start_game.h"

typedef struct {
    int Y;
    int X;
    int dimension;
    int figure[MAX_DIMENSION][MAX_DIMENSION];
} Coordinat_Current_Figure;

void getCoordinatsFigure(int y, int x);
int checkCollision(GameInfo_t *game);
void swapFigureDown(GameInfo_t *game);
void swapFigureRight(GameInfo_t *game);
void swapFigureLeght(GameInfo_t *game);
Coordinat_Current_Figure *getCoordinate_GameFigure();

#endif