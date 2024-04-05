#ifndef MENU_FOR_GAME_H
#define MENU_FOR_GAME_H

#include "../includes/common.h"
#include "../macro/macro_definitions.h"


void executeMenuItem(int item, int map[Y_SIZE_ARRAY][X_SIZE_ARRAY]);
void printMenu(int selectedItem);

#endif  // MENU_FOR_GAME_H