#ifndef FSM_H
#define FSM_H

// #include "defines.h"
// #include "game_frontend.h"
// #include "game_backend.h"
#include "game.h"
/*typedef enum {
    Start = 0, - играем
    Pause, - пауза
    Terminate, - меню
    Left, - влево
    Right, -вправо
    Up, - вверх
    Down, - вниз
    Action - генерация фиуры
} UserAction_t;*/
typedef enum {
    Start = 0,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action
} UserAction_t;
/*  
    int **field; -основное поле
    int **next; - следующее поле
    int score; - текущий счет
    int high_score; - максимальный счет
    int level; - уровень
    int speed; - скорость
    int pause; 0 - нет паузы, 1 - есть пауза
    
*/ 
typedef struct {
    int **field;
    int **next;
    int score;
    int high_score;
    int level;
    int speed;
    int pause;
} GameInfo_t;
/*Реализация логики в зависимости от нажатой клавиши*/
void userInput(UserAction_t action, bool hold);
GameInfo_t *getGameInfo();
UserAction_t *getUserStatus();

//  Проверка ввода пользователя
/*функция для обработки ввода, после нажатия определенной клавиши*/
UserAction_t checkTheKeyPressed(int key);
/*Конверт ввода, с учетом регистра */
int convertInput(int key);
/*Функция для получения информации о статусе игры, не изменяя значения*/
GameInfo_t *updateCurrentState();

#endif 