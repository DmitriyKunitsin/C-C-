#include "reader_with_console.h"

void ReaderForMenuSelectedItem(GameInfo_t *game, WINDOW *menuWindow,
                               WINDOW *gameWind) {
    keypad(stdscr, TRUE);
    noecho();  // Отключаю отображение вводимых символов
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
                selectMenuItem(selectedItem, game, menuWindow, gameWind);
                keypad(menuWindow, TRUE);
                break;
            default:
                selectedItem = 0;
                break;
        }
        printMenu(menuWindow, selectedItem);
    }
}

void selectMenuItem(int selectitem, GameInfo_t *game, WINDOW *menuWindow,
                    WINDOW *gameWindow) {
    werase(menuWindow);
    wrefresh(menuWindow);
    executeMenuItem(selectitem, game, gameWindow);
    werase(gameWindow);
    wrefresh(gameWindow);
    // printMenu(menuWindow, 0);
}
// int ReaderSelectedMenu(WINDOW *menuWindow) {
//     keypad(stdscr, TRUE);
//     int key;
//     int selectedItem = 0;
//     int flag = 0;
//     while ((key = getch()) != KEY_BACKSPACE && flag == 0) {
//         switch (key) {
//             case KEY_UP:
//                 selectedItem = (selectedItem - 1 > 0) ? selectedItem - 1 : 0;
//                 break;
//             case KEY_DOWN:
//                 selectedItem =
//                     (selectedItem + 1 < 2) ? selectedItem + 1 : 2 - 1;
//                 break;
//             case '\n':
//                 selectedItem = selectedItem;
//                 flag = 1;
//                 break;
//             default:
//                 selectedItem = 0;
//                 break;
//         }
//         printMenu(menuWindow, selectedItem);

//     }
//     return selectedItem;
// }

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