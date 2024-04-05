#ifndef FIGURES_FOR_GAMES_H
#define FIGURES_FOR_GAMES_H

#include "../includes/common.h"

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

int* getFigure(FigureType type);

// extern int figure_line[4][4];

// extern int figure_G_left[3][3];

// extern int figure_G_right[3][3];

// extern int figure_Cube[3][3];

// extern int figure_Z_right_up[3][3];

// extern int figure_cross[3][3];

// extern int figure_Z_left_up[3][3];

#endif  // FIGURES_FOR_GAMES_H