#ifndef FRONTEND_H
#define FRONTEND_H

#include "game.h"

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