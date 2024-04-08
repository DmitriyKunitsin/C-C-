#ifndef MENU_FOR_GAME_H
#define MENU_FOR_GAME_H

#include "../includes/common.h"
#include "../macro/macro_definitions.h"

void executeMenuItem(int item,GameInfo_t *game, WINDOW *gameWindow, WINDOW *menuWin);
void printMenu(WINDOW *menuWindow, int selectedItem);
void executeMenu(int item);

#endif  // MENU_FOR_GAME_H