#include "menu_for_game.h"

#include "../gamelogic/start_game.h"
#include "../map/map_for_board.h"

void executeMenuItem(int item, GameInfo_t *game, WINDOW *gameWindow, WINDOW *menuWindow) {
    switch (item) {
        case 0:
            // switch_to_game(gameWindow);
            werase(menuWindow);
            wrefresh(menuWindow);
            startGame(game, gameWindow);
            werase(gameWindow);
            wrefresh(gameWindow);
            // switch_to_menu(menuWindow);
            break;
        case 1:
            endwin();
            exit(0);
            break;
        default:
            break;
    }
}
// void switch_to_menu(WINDOW *menuWindow) {
//      PANEL *currentPanel = panel_above(top_panel(panel_window(stdscr)));
//     hide_panel(panel_window(panel_above(top_panel(currentPanel))));
//     show_panel(panel_above(menuWindow));
// }

// void switch_to_game(WINDOW *gameWindow) {
//      PANEL *currentPanel = panel_above(top_panel(panel_window(stdscr)));
//     hide_panel(panel_window(panel_above(top_panel(currentPanel))));
//     show_panel(panel_above(gameWindow));
// }



void printMenu(WINDOW *menuWindow, int selectedItem) {
    int startY = 5;
    int startX = 5;
    wclear(menuWindow);
    box(menuWindow, 0, 0);
    mvwprintw(menuWindow, 2, 8, "Menu");
    for (int i = 0; i < 2; i++) {
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
    for (int i = 0; i < X_MENU; i += 2) {
        if (i == 2) {
            mvwprintw(menuWin, i, 14, "Back for ext");
        } else if (i == 4) {
            mvwprintw(menuWin, i, 14, "Level :%d", game_inf->level);
        } else if (i == 6) {
            mvwprintw(menuWin, i, 14, "Score :%d", game_inf->score);
        } else if (i == 8) {
            mvwprintw(menuWin, i, 14, "Speed :%d", game_inf->speed);
        } else if (i == 10) {
            mvwprintw(menuWin, i, 14, "Record :%d", game_inf->high_score);
        }
    }

    wrefresh(menuWin);
}