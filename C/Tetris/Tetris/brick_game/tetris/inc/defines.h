/**
 * @file defines.h
 * @brief Модуль реализации основных макросов для игры 
 */

#ifndef DEFINES_H
#define DEFINES_H

#include "game.h"
#include "../inc/fsm.h"

/**
 * @brief Макрос инициализации библиотеки ncurses для работы с ней
 */
#define WIN_INIT(time) { \
                            initscr();\
                            noecho();\
                            curs_set(0);\
                            keypad(stdscr, TRUE);\
                            timeout(time);\
                            attron(COLOR_PAIR(1));\
                            }
/**
 * @brief Макрос для выхода из игры
 * Отключает цвет
 * Очищает память выделенную библиотекой 
 * закрывает окно
 */
#define EXIT_GAME() {\
                    attroff(COLOR_PAIR(1));\
                    endwin();\
                    exit(0);\
                    }
/**
 * @brief Макрос для получения ввода пользователя
 */
#define GET_USER_INPUT getch()
/**
 * Макрос размера карты по Y
 */
#define SIZE_MAX_MAP_Y 21
/**
 * Макрос размера карты по X
 */
#define SIZE_MAX_MAP_X 10

#endif