#ifndef BACKEND_H
#define BACKEND_H

// #include "fsm.h"
// #include "objects.h"
#include "game.h"

#define NUMBER_OF_KEYS 6

#define UP_ARROW KEY_UP
#define DOWN_ARROW KEY_DOWN
#define LEFT_ARROW KEY_LEFT
#define RIGHT_ARROW KEY_RIGHT
#define IS_Q(c) ((c == 'q') || (c == 'Q'))
#define IS_W(c) ((c == 'w') || (c == 'W'))
#define IS_E(c) ((c == 'e') || (c == 'E'))
#define IS_R(c) ((c == 'r') || (c == 'R'))
#define IS_ENTER(c) (c == '\n')
#define IF_INPUT(c) ((IS_Q(c) == true) || (IS_W(c) == true) || (IS_E(c) == true) || (IS_R(c) == true))


void calculateScore(int score);
int lvlUp(int score);
/*if(game->pause == 0) 
    false
if(game->pause ==  1)
true
*/
bool checkedPause();
void OnPauseGame();
void OffPauseGame();
/*Если нажатая клавиша не совпадает с валидными, то возвращает false*/
bool isValidKey(int ch);
/*myDelay(1, getch())
принимает в себя время ожидание и символ 10 = 1 секунде, выполняется либо 1 секунду, либо пока не примет валидное значение
если значение валидное, то не ждет 1 секунды и возвращает true, иначе ждет и возвращает false*/
bool myDelay(int milliseconds, int ch);
/*Начало логики игры и самой игры*/
void startGame();
void initGameSetting();
// передвижение фигуры и генерация новой фигуры
/*Переворот фигуры*/
void RotateFigure();
bool checkCollissionRotate();
/*Y++*/
void MoveFigureDown();
bool checkCollissionDown();
/*X--*/
void MoveFigureLeft();
bool checkCollisionLeft();
/*X++*/
void MoveFigureRight();
bool checkCollisionRight();
/*Генерирует новую рандомную фигуру и записывает ее в next  фигуру*/
void GenereatedNextFigure();
/*Обнуляет координаты фигуры, которой управляет игрок и записывает(cur) ее в next игровое поле*/
void ApperanceFigureToNextField();
/*записывает фигуру next(следующую) в cur(текущую), функция для того, чтобы знать, что за след фигура*/
void SwapFigureOldToNew();
/*Функция для первого запуска*/
void createRandomTetromino();
/*Функция для получения рандомного числа с номером фигуры*/
int getRandNumberFigures();
//  работа с полем на заполнение и кализию
/*Функция для сохранения фигуры на основную карту*/
void saveNextMapInFieldMap();

int checkLines();
void removeLines(int removeLinesY);
bool isFullLines(int Y);
// bool isLineFull(int row);
// void removeLine(int row);
// void checkLines();
void addScore(int countTrue);




#endif