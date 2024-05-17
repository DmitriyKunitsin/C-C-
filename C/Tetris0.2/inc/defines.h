#ifndef DEFINES_H
#define DEFINES_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "../inc/fsm.h"


#define WIN_INIT(time) { \
                            initscr();\
                            noecho();\
                            curs_set(0);\
                            keypad(stdscr, TRUE);\
                            timeout(time);\
                            attron(COLOR_PAIR(1));\
                            initBoard();\
                            }

#define EXIT_GAME() {\
                    attroff(COLOR_PAIR(1));\
                    endwin();\
                    exit(0);\
                    }

#define GET_USER_INPUT getch()

#define SIZE_MAX_MAP_Y 20
#define SIZE_MAX_MAP_X 10


#define INIT_GREEN() init_pair(1, COLOR_BLUE, COLOR_BLACK)
#define ON_GREEN() attron(COLOR_PAIR(1))
#define OFF_GREEN() attroff(COLOR_PAIR(1))

#define INIT_RED() init_pair(2, COLOR_RED, COLOR_BLACK)
#define ON_RED() attron(COLOR_PAIR(2))
#define OFF_RED() attroff(COLOR_PAIR(2))

#define INIT_BLUE() init_pair(3, COLOR_BLUE, COLOR_WHITE)
#define ON_BLUE() attron(COLOR_PAIR(3))
#define OFF_BLUE() attroff(COLOR_PAIR(3))

#define PRINT_RED_FIGURE(y,x) mvprintw(y,x,"\033[31m#\033[0m")
#define PRINT_GREEN(y,x) mvprintw(y,x, " # ")

#endif