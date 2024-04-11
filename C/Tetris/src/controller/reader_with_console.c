#include "reader_with_console.h"

void ReaderForMenuSelectedItem(WINDOW *menuWindow, WINDOW *gameWind) {
    int key;
    int selectedItem = 0;
    printMenu(menuWindow, 0);
    while ((key = getch()) != KEY_BACKSPACE) {
        switch (key) {
            case KEY_UP:
                selectedItem = (selectedItem - 1 >= 0) ? selectedItem - 1 : 0;
                break;
            case KEY_DOWN:
                selectedItem =
                    (selectedItem + 1 < 2) ? selectedItem + 1 : 2 - 1;
                break;
            case '\n':
                executeMenuItem(selectedItem, gameWind, menuWindow);
                break;
            default:
                selectedItem = 0;
                break;
        }
        printMenu(menuWindow, selectedItem);
    }
}

void clearCurrentScreen(WINDOW *currentScreen) {
    werase(currentScreen);
    wrefresh(currentScreen);
}
