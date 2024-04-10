#ifndef MENU_FOR_GAME_H
#define MENU_FOR_GAME_H

#include "../includes/common.h"
#include "../macro/macro_definitions.h"

void executeMenuItem(int item, GameInfo_t *game, WINDOW *gameWindow, WINDOW *menuWindow);
void printMenu(WINDOW *menuWindow, int selectedItem);

void InformationMenu(GameInfo_t *game_inf, WINDOW *menuWin);

void switch_to_menu(WINDOW *gameWindow);
void switch_to_game(WINDOW *gameWindow);

#endif  // MENU_FOR_GAME_H