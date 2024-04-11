#include "start_game.h"

#include "../controller/reader_with_console.h"
#include "../figures/figuresForGames.h"
#include "../includes/common.h"
#include "../menu/menu_for_game.h"

#define Q_KEY 113

void startGame(WINDOW *gameWindow) {
    GameInfo_t *game = getInstance_GameInfo();
    initGame(game);

    nodelay(stdscr, TRUE);  // Включаю режим немедленного ввода
    InitGameBoard(game->field);
    printNextMap(game->field, gameWindow);

    UserAction_t action = Start;
    bool hold = false;
    bool keyHeld = false;
    int heldInptKey = -1;

    while (action != Terminate) {
        int ch = getch();
        if (ch != ERR) {  // Если клавиша нажата
            switch (ch) {
                case KEY_LEFT:
                    action = Left;
                    break;
                case KEY_RIGHT:
                    action = Right;
                    break;
                case KEY_UP:
                    action = Up;
                    break;
                case KEY_DOWN:
                    action = Down;
                    keyHeld = true;
                    heldInptKey = ch;
                    break;
                case '\n':
                    action = Pause;
                    break;
                case KEY_BACKSPACE:
                    action = Terminate;
                    break;
                default:
                    break;
            }
            if (keyHeld) {
                // Обработка удержании клавиши
                switch (heldInptKey) {
                        // Обработка действия при удержании клавиши
                    case KEY_DOWN:
                        game->delay = 200;
                        // game.speed = 5;
                        *game = updateCurrentState();
                        // TODO действия при удержании нижней стрелки
                        break;

                    default:
                        game->delay = 1000;
                        game->speed = 1;
                        break;
                }
            } else {
                game->delay = 1000;
                game->speed = 1;
                keyHeld = false;
                game->speed = 1;
            }
        } else {  // Если ничего не было нажато

            // клавиша отпущена
            keyHeld = false;
            heldInptKey = -1;
            game->delay = 1000;
            game->speed = 1;
        }
        if (action == Terminate) {
            break;  // выход из цикла, еслvoid userInput(UserAction_t action,
                    // bool hold);и action равно Terminate
        }

        userInput(action, hold);
        InformationMenu(game, stdscr);
        nextFigureGeneretion(game, gameWindow);

        napms(game->delay);
        void userInput(UserAction_t action, bool hold);
    }

    // TODO по какой-то причине я работаю в основном окне stdscr, а не в игровом
    clearBoard(game);
    nodelay(stdscr, FALSE);  // Включаю режим немедленного ввода
    werase(stdscr);
    wrefresh(stdscr);
    my_free(game->field);
    my_free(game->menu);
    my_free(game->next);
}

GameInfo_t *getInstance_GameInfo() {
    static GameInfo_t game_info;
    return &game_info;
}

GameInfo_t updateCurrentState() {
    GameInfo_t *game = getInstance_GameInfo();
    // TODO в зависимости от статуса, реализовывать логику
    game->speed = 5;
    // game->field += 1;
    return *game;
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
            if (hold) {
                // Обработка случая, когда удерживается клавиша
            }
            break;
        case Action:
            // Обработка действия "Action"
            break;
        default:
            // Обработка неверного действия
            break;
    }
}

void nextFigureGeneretion(GameInfo_t *game, WINDOW *gameWindow) {
    int figureNumber = getRandNumberFigures();

    saveOldMap(game);

    clearBoard(game);

    FigureType type = (FigureType)figureNumber;

    int *figurePointer = getFigure(type);

    int dimesion = (figureNumber == 0) ? 4 : 3;

    for (int i = 0; i < dimesion; ++i) {
        for (int j = 0; j < dimesion; j++) {
            int value = *(figurePointer + i * dimesion + j);

            game->field[i + 1][(X_GAME_BOARD / 2) + j] = value;
        }
    }
    printNextMap(game->field, gameWindow);
}

void clearBoard(GameInfo_t *game) {
    for (int i = 0; i < Y_GAME_BOARD; ++i) {
        for (int j = 0; j < X_GAME_BOARD; ++j) {
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

void initGame(GameInfo_t *game) {
    initArray(&(game->field));
    initArray(&(game->menu));
    initArray(&(game->next));
    game->score = 0;
    game->high_score = 0;
    game->level = 1;
    game->speed = 1;
    game->pause = 0;
    game->delay = 1000;
}
void my_free(int **array) {
    for (int i = 0; i < Y_SIZE_ARRAY; i++) {
        free(array[i]);
    }
    free(array);
}

void initArray(int ***array) {
    *array = (int **)malloc(Y_SIZE_ARRAY * sizeof(int *));
    for (int i = 0; i < Y_SIZE_ARRAY; i++) {
        (*array)[i] = (int *)malloc(X_SIZE_ARRAY * sizeof(int));
    }
}

int getRandNumberFigures() {
    int min = 0;
    int max = 6;
    int random_value = rand() % (max - min + 1) + min;
    random_value %= 10;
    return random_value;
}