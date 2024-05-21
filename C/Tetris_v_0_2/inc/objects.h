#ifndef OBJECTS_H
#define OBJECTS_H

#include "game.h"

#define MAX_DEMISION 4

typedef struct
{
    int Y;
    int X;
    int dimension;
    int curFigure[MAX_DEMISION][MAX_DEMISION];
    int nextFigure[MAX_DEMISION][MAX_DEMISION];
}Current_Figure;

typedef enum {
    LINE,
    G_LEFT,
    G_RIGHT,
    CUBE,
    Z_RIGHT_UP,
    CROSS,
    Z_LEFT_UP,
    FIGURE_COUNT
} FigureType;
Current_Figure *getCurrentFigure();



void initBoard();
void FreeMemory();
void GenereatedNextFigure();
int getRandNumberFigures();
int *getFigure(FigureType type);
void SwapFigureOldToNew();

#endif