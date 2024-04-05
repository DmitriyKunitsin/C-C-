#ifndef FIGURES_FOR_GAMES_H
#define FIGURES_FOR_GAMES_H

int figure_line[4][4]={{0 , 1 , 0 , 0},
                      {0 , 1, 0 , 0},
                      {0 , 1 , 0 , 0},
                      {0 , 1 , 0 , 0}};

int figure_G_left[4][4]={{0 , 0 , 0 , 0},
                         {1 , 0 , 0 , 0},
                         {1 , 1 , 1 , 0},
                         {0 , 0 , 0 , 0}};

int figure_G_right[4][4]={{0 , 0 , 0 , 0},
                          {0 , 0, 0 , 1},
                          {0 , 1 , 1 , 1},
                          {0 , 0 , 0 , 0}};

int figure_Cube[4][4] = {{0 , 0 , 0 , 0},
                         {0 , 1 , 1 , 0},
                         {0 , 1 , 1 , 0},
                         {0 , 0 , 0 , 0}};

int figure_Z_right_up[4][4] = {{0 , 0 , 0 , 0},
                               {0 , 0 , 1, 1},
                               {0 , 1 , 1 , 0},
                               {0 , 0 , 0 , 0}};

int figure_cross[4][4] = {{0 , 0 , 0 , 0},
                         {0 , 0 , 1 , 0},
                         {0 , 1 , 1 , 1},
                         {0 , 0 , 0 , 0}};

int figure_Z_left_up[4][4] = {{0 , 0 , 0 , 0},
                              {1 , 1 , 0 , 0},
                              {0 , 1 , 1 , 0},
                              {0 , 0 , 0 , 0}};                        
#endif //FIGURES_FOR_GAMES_H