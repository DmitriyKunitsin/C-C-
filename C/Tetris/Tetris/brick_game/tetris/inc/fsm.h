/**
 * @file fsm.h
 * @brief Модуль для работы с логикой игры и полем
 */
#ifndef FSM_H
#define FSM_H

#include "game.h"
#include "../../../gui/cli/game_frontend.h"

/*! 
    @brief Перечисление с параметрами действий в игре
    \param Start  играем
    \param Pause  пауза
    \param Terminate  меню
    \param Left  влево
    \param Right вправо
    \param Up   вверх
    \param Down   вниз
    \param Action  генерация фиуры
    \param Inaction бездействие
    */
typedef enum {
    Start = 0,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action,
    Inaction
} UserAction_t;
/**  
 * @brief
    @param field основное поле
    @param next поле с фигурой
    @param score  текущий счет
    @param high_score  максимальный счет
    @param level уровень
    @param speed скорость
    @param pause флаг паузы
    
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

/**
 * @brief Функция для инициализации структуры 
 * 
 * Инициализирует структуры для работы с ней 
 */
void initBoard();
/**
 * @brief Очищение структуры
 * Очищает выделенную память для структуры
 */
void FreeMemory();
/** @brief Старт игры, бесконечный цикл до выполнения выхода из игры */
void startGame();
/** @brief Инициализация счета, рекорда, скорости перед начало новой игры */
void initGameSetting();
/**
 * @brief Реализаци действий в игре, в зависимости от того, какая нажата клавиша
 */
void userInput(UserAction_t action, bool hold);
/**
 * @brief Работа со статической локальной переменной
 * @code 
 *   GameInfo_t *getGameInfo() {
        static GameInfo_t gameInfo;
        return &gameInfo;
    }
 * @endcode
 @returns Возвращает указатель на структуру с текущими значениями в ней
 */
GameInfo_t *getGameInfo();
/**
 * @brief Работа со статической локальной переменной
 * @code
 *  UserAction_t *getUserStatus() {
        static UserAction_t userAction;
        return &userAction;
    }
 * @endcode
 @returns Возвращает указатель на перечисление с текущими значениями в ней
 */
UserAction_t *getUserStatus();
/**
 * @brief Устанавливает необходимое значение в перечесиление
 * @code 
 * void setUserStatus(UserAction_t status) {
        UserAction_t *userAction = getUserStatus();
        *userAction = status;
    }
 * @endcode
 @returns После выполнения функции, в перечеслении будет установлено переданное значение
 */
void setUserStatus(UserAction_t status);

/**
 * @brief Принимает значение ввода
 * Конвертирует значение ввода, после чего в зависимости от ввода присваивает значение перечислению UserAction_t
 */
UserAction_t checkTheKeyPressed(int key);
/**
 * @brief Конвертирует ввод в зависимости от регистра
 */
int convertInput(int key);
/**
 * Обновляет значение игровой структуры
 */
GameInfo_t *updateCurrentState();
/**
 * @brief Сохраняет рекорд в случае, если нынешний результат больше рекорда
 */
void saveRecord();
/**
 * @brief Реализация логики паузы
 * Крутит цикл, пока пользователь не нажмет Q для выхода из паузы
 */
void pauseLogic();
/**
 * @brief Реализация логики выхода из текущей игры
 * Крутит цикл, пока пользователь не нажмет Q для выхода из паузы\n
 * или enter для выхода из текущей игры
 */
void exitLogic();
#endif 