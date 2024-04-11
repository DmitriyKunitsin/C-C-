#include "menu_for_game.h"

#include "../gamelogic/start_game.h"
#include "../map/map_for_board.h"

void executeMenuItem(int item, WINDOW *gameWindow, WINDOW *menuWindow) {
    switch (item) {
        case 0:
            werase(menuWindow);
            wrefresh(menuWindow);
            startGame(gameWindow);
            werase(stdscr);
            wrefresh(stdscr);
            break;
        case 1:
            endwin();
            exit(0);
            break;
        default:
            break;
    }
}
void printMenu(WINDOW *menuWindow, int selectedItem) {
    int startY = 5;
    int startX = 5;
    wclear(menuWindow);
    box(menuWindow, 0, 0);
    mvwprintw(menuWindow, 2, 8, "Menu");
    for (int i = 0; i < 2; ++i) {
        if (selectedItem == i) {
            wattron(menuWindow, A_REVERSE);
        }
        mvwprintw(menuWindow, startY + 2 + i, startX, "%d. %s", i + 1,
                  (i == 0) ? "Start" : "Exit");
        if (selectedItem == i) {
            wattroff(menuWindow, A_REVERSE);
        }
    }
    wrefresh(menuWindow);
}

void InformationMenu(GameInfo_t *game_inf, WINDOW *menuWin) {
    wclear(menuWin);
    wattron(menuWin, COLOR_PAIR(3));
    for (int i = 0; i < Y_MENU; i += 2) {
        if (i == 2) {
            mvwprintw(menuWin, i, 14, "Backspace for exit");
        } else if (i == 4) {
            mvwprintw(menuWin, i, 14, "Enter for pause");
        } else if (i == 6) {
            mvwprintw(menuWin, i, 14, "Level :%d", game_inf->level);
        } else if (i == 8) {
            mvwprintw(menuWin, i, 14, "Score :%d", game_inf->score);
        } else if (i == 10) {
            mvwprintw(menuWin, i, 14, "Speed :%d", game_inf->speed);
        } else if (i == 12) {
            mvwprintw(menuWin, i, 14, "Record :%d", game_inf->high_score);
        } else if (i == 14) {
            mvwprintw(menuWin, i, 14, "Status game: %s", game_inf->status);
        }
    }
    wattroff(menuWin, COLOR_BLACK);
    wrefresh(menuWin);
}

void printPauseGame(GameInfo_t *game_inf, WINDOW *menuWin) {
    wclear(menuWin);
    wattron(menuWin, COLOR_PAIR(3));
    for (int i = 0; i < Y_MENU; i += 2) {
        if (i == 2) {
            mvwprintw(menuWin, i, 8, "Game is paused");
        } else if (i == 8) {
            mvwprintw(menuWin, i, 2, "Status game: %s", game_inf->status);
        } else if (i == 14) {
            mvwprintw(menuWin, i, 2, "press Enter to continue");
        }
    }
    wattroff(menuWin, COLOR_BLACK);
    for (int i = 1; i < Y_MENU - 1; ++i) {
        mvwaddch(menuWin, i, 0, ACS_VLINE);  // Вертикальная линия слева
        mvwaddch(menuWin, i, 29, ACS_VLINE);  // Вертикальная линия справа
    }
    for (int j = 1; j < 30 - 1; ++j) {
        mvwaddch(menuWin, 0, j, ACS_HLINE);  // Горизонтальная линия сверху
        mvwaddch(menuWin, 20, j, ACS_HLINE);  // Горизонтальная линия снизу
    }

    mvwaddch(menuWin, 0, 0, ACS_ULCORNER);  // Левый верхний угол
    mvwaddch(menuWin, Y_MENU - 1, 0, ACS_LLCORNER);  // Левый нижний угол
    mvwaddch(menuWin, 0, 29, ACS_URCORNER);  // Правый верхний угол
    mvwaddch(menuWin, Y_MENU - 1, 29, ACS_LRCORNER);  // Правый нижний угол

    wrefresh(menuWin);
}
