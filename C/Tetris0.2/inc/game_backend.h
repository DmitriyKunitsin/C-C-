#ifndef BACKEND_H
#define BACKEND_H

#include "./fsm.h"
#include "objects.h"

#define NUMBER_OF_KEYS 6



/*if(game->pause == 0) 
    false
if(game->pause ==  1)
true
*/
bool checkedPause();
/*Если нажатая клавиша не совпадает с валидными, то возвращает false*/
bool isValidKey(int ch);
/*myDelay(1, getch())
принимает в себя время ожидание и символ 10 = 1 секунде, выполняется либо 1 секунду, либо пока не примет валидное значение
если значение валидное, то не ждет 1 секунды и возвращает true, иначе ждет и возвращает false*/
bool myDelay(int milliseconds, int ch);
/*Начало логики игры и самой игры*/
void startGame();

#endif