#ifndef START_GAME_H
#define START_GAME_H

#include "../includes/common.h"
#include "../map/map_for_board.h"

void startGame();
void nextFigureGeneretion(GameInfo_t *game, WINDOW *gameWindow);
int getRandNumberFigures();

void clearBoard(GameInfo_t *game);

void initGame(GameInfo_t *game);
void cleanupGameInfo(GameInfo_t *game);
void my_free(int **array);
void initArray(int ***array);

GameInfo_t *getInstance_GameInfo();
UserAction_t *getUserAction();
StatusGame_t *getStatus_Game();

GameInfo_t updateCurrentState();
void userInput(UserAction_t action, bool hold);

void PauseGame(GameInfo_t *game);

void UpdateGameScreen(GameInfo_t *game_inf, WINDOW *gameWindow);

/*Если во время задержки ничего не нажато, то возвращает -1
иначе возвращает ASCII-код клавиши нажатой.*/
int myDelay(int milliseconds);

/*Проверка на валидность клавиши, чтобы игра не отрабатывала на не нужные
 * клавиши*/
bool isValidKey(int ch);

#endif