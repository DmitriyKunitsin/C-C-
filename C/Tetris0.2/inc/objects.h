#ifndef OBJECTS_H
#define OBJECTS_H

#define MAX_DEMISION 4

typedef struct
{
    int Y;
    int X;
    int curFigure[MAX_DEMISION][MAX_DEMISION];
    int nextFigure[MAX_DEMISION][MAX_DEMISION];
}Current_Figure;





void initBoard();

#endif