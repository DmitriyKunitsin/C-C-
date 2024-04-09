#ifndef READER_WITH_CONSOLE_H
#define READER_WITH_CONSOLE_H

#include "../includes/common.h"
#include "../menu/menu_for_game.h"

void ReaderForMenuSelectedItem(GameInfo_t *game, WINDOW *menuuWind,
                               WINDOW *gameWind);

int ReaderSelectedMenu(WINDOW *menuWindow);

void userInput(UserAction_t action, bool hold);

#endif