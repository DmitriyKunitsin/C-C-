#ifndef MENU_FOR_GAME_H
#define MENU_FOR_GAME_H

#include "../includes/common.h"
#include "../macro/macro_definitions.h"

void executeMenuItem(int item, int **map, WINDOW *gameWindow);
void printMenu(WINDOW *menuWindow, int selectedItem);

#endif  // MENU_FOR_GAME_H