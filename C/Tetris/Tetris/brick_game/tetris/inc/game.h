
/**
 *  @file  game.h
 *  @brief Модуль для реализации игровой петли
 * @author Дмитрий Куницин
 * @version 1.0
 */

#ifndef GAME_H
#define GAME_H
/*!
    \brief Макрос для старта игры
     Содержит в себе функцию реализации меню с выбором
*/
#define GAME() {\
                ReaderForMenuSelectedItem();\
                }

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include "../inc/fsm.h"
#include "../inc/defines.h"
#include "../inc/game_backend.h"
#include "../inc/objects.h"


#endif