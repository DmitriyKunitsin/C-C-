#include "reader_with_console.h"

void inputKey(int **map, WINDOW *menuuWind, WINDOW *gameWind) {
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
                executeMenuItem(selectedItem, map, gameWind);
                break;
            default:
            selectedItem = 0;
                break;
        }
        refresh();
        printMenu(menuuWind, selectedItem);
    }
}