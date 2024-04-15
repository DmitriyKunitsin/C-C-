#include "figuresForGames.h"
/*
0 - line
1 - G_left
2 - G_right
3 - Cube
4 - Z_right
5 - cross
6 - Z_left
*/
int* getFigure(FigureType type) {
    static int figure_line[4][4] = {
        {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}};

    static int figure_G_left[3][3] = {{0, 0, 0}, {1, 0, 0}, {1, 1, 1}};

    static int figure_G_right[3][3] = {{0, 0, 0}, {0, 0, 1}, {1, 1, 1}};

    static int figure_Cube[3][3] = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};

    static int figure_Z_right_up[3][3] = { {0, 0, 0},{0, 1, 1}, {1, 1, 0}};

    static int figure_cross[3][3] = { {0, 0, 0}, {0, 1, 0}, {1, 1, 1}};

    static int figure_Z_left_up[3][3] = { {0, 0, 0}, {1, 1, 0}, {0, 1, 1}};

    switch (type) {
        case LINE:
            return (int*)figure_line;
            break;
        case G_LEFT:
            return (int*)figure_G_left;
            break;
        case G_RIGHT:
            return (int*)figure_G_right;
            break;
        case CUBE:
            return (int*)figure_Cube;
            break;
        case Z_RIGHT_UP:
            return (int*)figure_Z_right_up;
            break;
        case CROSS:
            return (int*)figure_cross;
            break;
        case Z_LEFT_UP:
            return (int*)figure_Z_left_up;
            break;
        default:
            return NULL;
    }
}
// int figure_line[4][4]={{0 , 1 , 0 , 0},
//                        {0 , 1, 0 , 0},
//                        {0 , 1 , 0 , 0},
//                        {0 , 1 , 0 , 0}};

// int figure_G_left[3][3]={{0 , 0 , 0},
//                          {1 , 0 , 0},
//                          {1 , 1 , 1 }};

// int figure_G_right[3][3]={{0 , 0 , 0},
//                           {0 , 0 , 1},
//                           {1 , 1 , 1}};

// int figure_Cube[3][3] = {{1 , 1 , 0},
//                          {1 , 1 , 0},
//                          {0 , 0 , 0}};

// int figure_Z_right_up[3][3] = {{0 , 1, 1},
//                                {1 , 1 , 0},
//                                {0 , 0 , 0}};

// int figure_cross[3][3] = {{0 , 1 , 0},
//                           {1 , 1 , 1},
//                           {0 , 0 , 0}};

// int figure_Z_left_up[3][3] = {{1 , 1 , 0},
//                               {0 , 1 , 1},
//                               {0 , 0 , 0}};