#include "menu_for_game.h"

#include "../gamelogic/start_game.h"
#include "../map/map_for_board.h"

void executeMenuItem(int item, WINDOW *gameWindow, WINDOW *menuWindow) {
    switch (item) {
        case 0:
            werase(menuWindow);
            wrefresh(menuWindow);
            startGame(gameWindow);
            werase(gameWindow);
            wrefresh(gameWindow);
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
    for (int i = 0; i < X_MENU; i += 2) {
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
        }
    }
    wattroff(menuWin, COLOR_BLACK);
    wrefresh(menuWin);
}