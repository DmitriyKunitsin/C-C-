#include "reader_with_console.h"

void ReaderForMenuSelectedItem(int **map, WINDOW *menuWindow,
                               WINDOW *gameWind) {
    keypad(stdscr, TRUE);
    int key;
    int selectedItem = 0;
    while ((key = getch()) != KEY_BACKSPACE) {
        switch (key) {
            case KEY_UP:
                selectedItem = (selectedItem - 1 > 0) ? selectedItem - 1 : 0;
                break;
            case KEY_DOWN:
                selectedItem =
                    (selectedItem + 1 < 2) ? selectedItem + 1 : 2 - 1;
                break;
            case '\n':
                executeMenuItem(selectedItem, map, gameWind, menuWindow);
                break;
            default:
                selectedItem = 0;
                break;
        }
        printMenu(menuWindow, selectedItem);
    }
}
int ReaderSelectedMenu(WINDOW *menuWindow) {
    keypad(stdscr, TRUE);
    int key;
    int selectedItem = 0;
    int flag = 0;
    while ((key = getch()) != KEY_BACKSPACE && flag == 0) {
        switch (key) {
            case KEY_UP:
                selectedItem = (selectedItem - 1 > 0) ? selectedItem - 1 : 0;
                break;
            case KEY_DOWN:
                selectedItem =
                    (selectedItem + 1 < 2) ? selectedItem + 1 : 2 - 1;
                break;
            case '\n':
                selectedItem = selectedItem;
                flag = 1;
                break;
            default:
                selectedItem = 0;
                break;
        }
        printMenu(menuWindow, selectedItem);
    }
    return selectedItem;
}