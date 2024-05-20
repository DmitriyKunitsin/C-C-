#ifndef BACKEND_H
#define BACKEND_H

#include "./fsm.h"
#include "objects.h"

#define NUMBER_OF_KEYS 6

#define UP_ARROW KEY_UP
#define DOWN_ARROW KEY_DOWN
#define LEFT_ARROW KEY_LEFT
#define RIGHT_ARROW KEY_RIGHT
#define IS_Q(c) ((c == 'q') || (c == 'Q'))
#define IS_W(c) ((c == 'w') || (c == 'W'))
#define IS_E(c) ((c == 'e') || (c == 'E'))
#define IS_R(c) ((c == 'r') || (c == 'R'))

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

// передвижение фигуры и генерация новой фигуры

/*Y++*/
void MoveFigureDown();
/*X--*/
void MoveFigureLeft();
/*X++*/
void MoveFigureRight();

//  работа с полем на заполнение и кализию

bool isLineFull(int row);
void removeLine(int row);
void checkLines();

//  Проверка ввода пользователя
/*функция для выполнения логики, после нажатия определенной клавиши*/
UserAction_t checkTheKeyPressed(int key);
/*Конверт ввода, с учетом регистра и языка ввода*/
int convertInput(int key);

void OnPauseGame();
void OffPauseGame();

#endif