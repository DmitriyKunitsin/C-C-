#ifndef FRONTEND_H
#define FRONTEND_H


#include <locale.h>
#include <ncurses.h>
#include <unistd.h>
#include <wchar.h>
#include "../../brick_game/tetris/inc/game.h"

#define CURENT_FIGURE_START_PRINT 9
#define NEXT_FIGURE_START_PRINT 14
#define SCORE_PRINT(c) do { attron(COLOR_PAIR(1)); mvprintw(1, 22, "Score : %d", c); attroff(COLOR_PAIR(1)); } while (0)
#define LEVEL_PRINT(c) do { attron(COLOR_PAIR(1)); mvprintw(2, 22, "LVL : %d", c); attroff(COLOR_PAIR(1)); } while (0)
#define RECORD_PRINT(c) do { attron(COLOR_PAIR(1)); mvprintw(3, 22, "High score : %d", c); attroff(COLOR_PAIR(1)); } while (0)
#define PAUSE_PRINT do {attron(COLOR_PAIR(1)); mvprintw(5,22, "Press Q"); mvprintw(6,22, "for pause"); attroff(COLOR_PAIR(1));} while (0)
#define EXIT_PRINT do { attron(COLOR_PAIR(1)); mvprintw(7, 22, "Press enter"); mvprintw(8,22, "for exit"); attroff(COLOR_PAIR(1)); } while (0)



/*!
    \brief Функция игровой петли
    \code
    WIN_INIT(1000);
    GAME();
    FreeMemory();
    EXIT_GAME();
    \endcode

    1.Запускает настройку ncurses макросом WIN_INIT
    \n2.Запускает игру макросом GAME
    \n3.После выхода из игры, очищает выделенную динамическую память
    \n4.Макрос вызывает последовательность функций для выхода из игры

*/
void gameLoop();
void ReaderForMenuSelectedItem();
void printLoseBanner();
void printCurrentFigure();
void printNextFigure();
void updateGameScreen();
void clearOldNextMap();
void printMenu(int selectedItem);
void printPauseMenu();
void PrintExitMenu();
void printGameMap() ;
void executeMenuItem(int item);

#endif