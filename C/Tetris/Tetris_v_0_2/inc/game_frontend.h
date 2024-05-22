#ifndef FRONTEND_H
#define FRONTEND_H

#include "game.h"

#define CURENT_FIGURE_START_PRINT 9
#define NEXT_FIGURE_START_PRINT 14
#define SCORE_PRINT(c) mvprintw(1, 20, "Score : %d", c)
#define LEVEL_PRINT(c) mvprintw(2, 20, "LVL : %d", c)
#define RECORD_PRINT(c) mvprintw(3, 20, "High score : %d", c)


void ReaderForMenuSelectedItem();
void printCurrentFigure();
void printNextFigure();
void updateGameScreen();
void clearOldNextMap();
void printMenu(int selectedItem);
void printPauseMenu();
void printGameMap() ;
/*0 - старт игры
1 - выход из игры*/
void executeMenuItem(int item);

#endif