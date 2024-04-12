#ifndef START_GAME_H
#define START_GAME_H

#include "../includes/common.h"
#include "../map/map_for_board.h"

void startGame(WINDOW *gameWindow);
void nextFigureGeneretion(GameInfo_t *game, WINDOW *gameWindow);
int getRandNumberFigures();

void clearBoard(GameInfo_t *game);

void initGame(GameInfo_t *game);
void cleanupGameInfo(GameInfo_t *game);
void my_free(int **array);
void initArray(int ***array);

GameInfo_t *getInstance_GameInfo();
UserAction_t *getUserAction();

GameInfo_t updateCurrentState();
void userInput(UserAction_t action, bool hold);

void PauseGame(GameInfo_t *game);

/*функция delay() принимает значение времени в микросекундах,
а затем разбивает его на секунды и наносекунды для использования функции
nanosleep(). Функция nanosleep() приостанавливает выполнение программы на
указанное время. Если задержка была прервана (например, из-за сигнала), она
продолжит оставшуюся часть задержки.*/
int myDelay(int milliseconds);
/*Проверка на валидность клавиши, чтобы игра не отрабатывала на не нужные
 * клавиши*/
bool isValidKey(int ch);

#endif