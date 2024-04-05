#ifndef MENU_FOR_GAME_H
#define MENU_FOR_GAME_H



#include "../macro/macro_definitions.h"
#include "../includes/common.h"

#define A_REVERSE	NCURSES_BITS(1U,10)

void executeMenuItem(int item, int map[Y_SIZE_ARRAY][X_SIZE_ARRAY]);
void printMenu(int selectedItem);


#endif// MENU_FOR_GAME_H