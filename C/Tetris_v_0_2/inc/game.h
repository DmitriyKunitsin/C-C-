#ifndef GAME_H
#define GAME_H

#define GAME() {\
                ReaderForMenuSelectedItem();\
                }

#include "../inc/defines.h"
#include "../inc/fsm.h"
#include "../inc/game_frontend.h"
#include "../inc/game_backend.h"
#include "../inc/objects.h"
#include <string.h>

void gameLoop();

#endif