#include "reader_with_console.h"

void ReaderForMenuSelectedItem(GameInfo_t *game, WINDOW *menuWindow,
                               WINDOW *gameWind) {
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
                executeMenuItem(selectedItem, game, gameWind, menuWindow);
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

void userInput(UserAction_t action, bool hold) {
    switch (action) {
        case Start:
            // Обработка действия "Start"
            break;
        case Pause:
            // Обработка действия "Pause"
            break;
        case Terminate:
            // Обработка действия "Terminate"
            break;
        case Left:
            // Обработка действия "Left"
            break;
        case Right:
            // Обработка действия "Right"
            break;
        case Up:
            // Обработка действия "Up"
            break;
        case Down:
            // Обработка действия "Down"
            break;
        case Action:
            // Обработка действия "Action"
            break;
        default:
            // Обработка неверного действия
            break;
    }

    if (hold) {
        // Обработка случая, когда удерживается клавиша
    }
}