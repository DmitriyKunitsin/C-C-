#include "start_game.h"

#include "../controller/reader_with_console.h"
#include "../figures/figuresForGames.h"
#include "../includes/common.h"
#include "../menu/menu_for_game.h"

#define Q_KEY 113

void startGame(GameInfo_t *game, WINDOW *gameWindow) {
    // cbreak();  // Включаю режим "cbreak" для обработки клавиш без ожидания Enter
    // noecho();  // Отключаю отображение вводимых символов
    nodelay(stdscr, TRUE);  // Включаю режим немедленного ввода
    InitGameBoard(game->field);
    printNextMap(game->field, gameWindow);
    UserAction_t action = Start;
    // bool hold = false;
    bool keyHeld = false;
    int ch = getch();
    while ((ch = getch()) != Q_KEY) {
        // while (action != Terminate) {
        if (ch != ERR) {  // Если клавиша нажата
            switch (ch) {
                case KEY_LEFT:

                    break;
                case KEY_RIGHT:

                    break;
                case KEY_UP:

                    break;
                case KEY_DOWN:

                    break;
                case Q_KEY:
                    // action = Terminate;
                    break;
                default:
                    break;
            }
        } else {  // Если ничего не было нажато

            if (keyHeld) {
                // Обработка действия при удержании клавиши
            }
        }

        if (action == Terminate) {
            break;  // выход из цикла, если action равно Terminate
        }

        InformationMenu(game, stdscr);
        nextFigureGeneretion(game, gameWindow);

        napms(500);
    }

    // TODO по какой-то причине я работаю в основном окне stdscr, а не в игровом
    clearBoard(game);
    nodelay(stdscr, FALSE);  // Включаю режим немедленного ввода
    werase(stdscr);
    wrefresh(stdscr);
    // printNextMap(game->field, gameWindow);
    // printMenu(menuWin, 0);
    //     return;  // выход из функции startGame(), если action равно Terminate
    // }
}
void nextFigureGeneretion(GameInfo_t *game, WINDOW *gameWindow) {
    int figureNumber = getRandNumberFigures();

    saveOldMap(game);

    clearBoard(game);

    FigureType type = (FigureType)figureNumber;

    int *figurePointer = getFigure(type);

    int dimesion = (figureNumber == 0) ? 4 : 3;

    for (int i = 0; i < dimesion; i++) {
        for (int j = 0; j < dimesion; j++) {
            int value = *(figurePointer + i * dimesion + j);

            game->field[i + 1][(X_GAME_BOARD / 2) + j] = value;
        }
    }
    printNextMap(game->field, gameWindow);
}

void clearBoard(GameInfo_t *game) {
    for (int i = 0; i < Y_GAME_BOARD; i++) {
        for (int j = 0; j < X_GAME_BOARD; j++) {
            if (i == 0 || i == Y_GAME_BOARD - 1) {
                game->field[i][j] = 1;
            } else if (j == 0 || j == X_GAME_BOARD - 1) {
                game->field[i][j] = 1;
            } else {
                game->field[i][j] = 0;
            }
        }
    }
}

int getRandNumberFigures() {
    int min = 0;
    int max = 6;
    int random_value = rand() % (max - min + 1) + min;
    random_value %= 10;
    return random_value;
}