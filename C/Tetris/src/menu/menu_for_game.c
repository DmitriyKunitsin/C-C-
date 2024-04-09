#include "menu_for_game.h"

#include "../gamelogic/start_game.h"

void executeMenuItem(int item, GameInfo_t *game, WINDOW *gameWindow,
                     WINDOW *menuWin) {
    switch (item) {
        case 0:
            startGame(game, gameWindow, menuWin);
            break;
        case 1:
            endwin();
            exit(0);
            break;
        default:
            break;
    }
}

// void executeMenu(int item) {
//     int current_item = 0;
//     switch (item) {
//         case 0:

//             break;
//         case 1:
//             endwin();
//             exit(0);
//             break;
//         default:
//             break;
//     }
//     return current_item;
// }

void printMenu(WINDOW *menuWindow, int selectedItem) {
    int startY = 0;
    int startX = 1;
    wclear(menuWindow);
    mvwprintw(menuWindow, startY, startX, "Menu");
    for (int i = 0; i < 2; i++) {
        if (selectedItem == i) {
            wattron(menuWindow, A_REVERSE);
        }
        mvwprintw(menuWindow, startY + 2 + i, startX, "%d. %s", i + 1,
                  (i == 0) ? "Create" : "Exit");
        if (selectedItem == i) {
            wattroff(menuWindow, A_REVERSE);
        }
    }
    wrefresh(menuWindow);
}

void InformationMenu(GameInfo_t *game_inf, WINDOW *menuWin) {
    wclear(menuWin);
        for (int i = 0; i < X_MENU; i+=2) {
            if(i == 2) {
                mvwprintw(menuWin, i, 1, "Back for ext");
            } else if (i == 4) {
                mvwprintw(menuWin, i, 1, "Level :%d", game_inf->level);
            } else if (i == 6) {
                mvwprintw(menuWin, i, 1, "Score :%d", game_inf->score);
            } else if (i == 8) {
                mvwprintw(menuWin, i, 1, "Speed :%d", game_inf->speed);
            } else if (i == 10) {
                mvwprintw(menuWin, i, 1, "Record :%d", game_inf->high_score);
            }
        }
    
    wrefresh(menuWin);
}