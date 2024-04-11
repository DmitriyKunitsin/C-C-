#include "start_game.h"

#include <sys/select.h>

#include "../controller/reader_with_console.h"
#include "../figures/figuresForGames.h"
#include "../includes/common.h"
#include "../menu/menu_for_game.h"

#define Q_KEY 113
#define NUM_KEYS 6
int validKeys[NUM_KEYS] = {KEY_LEFT, KEY_RIGHT, KEY_UP,
                           KEY_DOWN, '\n',      KEY_BACKSPACE};
void startGame(WINDOW *gameWindow) {
    GameInfo_t *game = getInstance_GameInfo();
    UserAction_t action = Start;
    initGame(game);

    nodelay(stdscr, TRUE);  // Включаю режим немедленного ввода
    InitGameBoard(game->field);
    printNextMap(game->field, gameWindow);
    InformationMenu(game, stdscr);
    nextFigureGeneretion(game, gameWindow);

    bool hold = false;
    bool keyHeld = false;
    int buf_ch = -1;
    int heldInptKey =
        -1;  // TODO может добавлю расширение для разных клавиш зажатие

    while (action != Terminate) {
        int ch = getch();
        if (buf_ch != -1) {
            ch = buf_ch;
        }
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
                    buf_ch = -1;
                    break;
            }
        }
        if (keyHeld) {
            // Обработка удержании клавиши
            switch (heldInptKey) {
                    // Обработка действия при удержании клавиши
                case KEY_DOWN:
                    hold = true;
                    *game = updateCurrentState();
                    keyHeld = false;
                    break;
                // TODO стрелку вверх надо будет настроить на переворот фигуры
                default:
                    continue;
            }
        } else {
            keyHeld = false;
            hold = false;
            heldInptKey = -1;
            game->delay = 10;
            game->speed = 1;
        }
        if (action == Terminate) {
            break;
        }
        game->level += 1;
        // halfdelay(game->delay);
        buf_ch = myDelay(1000);
        userInput(action, hold);
        InformationMenu(game, stdscr);
        nextFigureGeneretion(game, gameWindow);

        action = Start;
    }
    clearBoard(game);
    nodelay(stdscr, FALSE);  // Включаю режим немедленного ввода
    werase(stdscr);
    wrefresh(stdscr);
    cleanupGameInfo(game);
}

GameInfo_t *getInstance_GameInfo() {
    static GameInfo_t game_info;
    return &game_info;
}

UserAction_t *getUserAction() {
    static UserAction_t user_info;
    return &user_info;
}

GameInfo_t updateCurrentState() {
    GameInfo_t *game = getInstance_GameInfo();
    game->speed = 5;
    game->delay = 2;
    // game->level += 1;
    return *game;
}

void cleanupGameInfo(GameInfo_t *game) {
    // Освобождение ресурсов, связанных с game_info
    my_free(game->field);
    my_free(game->menu);
    my_free(game->next);
}

bool isValidKey(int ch) {
    bool bl = false;
    for (int i = 0; i < NUM_KEYS; ++i) {
        if (ch == validKeys[i]) {
            bl = true;
        }
    }
    return bl;
}

int myDelay(int milliseconds) {
    struct timeval tv;
    fd_set fds;

    tv.tv_sec = milliseconds / 1000;
    tv.tv_usec = (milliseconds % 1000) * 1000;

    FD_ZERO(&fds);
    FD_SET(fileno(stdin), &fds);

    int result = 0;
    int ch = ERR;

    while (result <= 0 || !isValidKey(ch)) {
        result = select(fileno(stdin) + 1, &fds, NULL, NULL, &tv);

        if (result > 0 && FD_ISSET(fileno(stdin), &fds)) {
            ch = getch();
        } else {
            ch = -1;
            ;  // Тайм-аут
            // если фигура должна падать только по истечению времени, то
            // добавлять сюда эту логику
            break;
        }
    }
    // TODO скорее всего надо будет здесь добавить перед выходом программы
    // расчет по поводу того, что фигура должна падать
    // по условиям либо при нажатии и происходит действие
    // либо по истечению таймера
    return ch;
}

void userInput(UserAction_t action, bool hold) {
    GameInfo_t *game = getInstance_GameInfo();
    switch (action) {
        case Start:
            // Обработка действия "Start"
            break;
        case Pause:
            // Обработка действия "Pause"
            int ch = -1;
            strcpy(game->status, "Pause");
            InformationMenu(game, stdscr);
            // printNextMap(game->field, stdscr);
            // printPauseGame(game, stdscr);
            while ((ch = getch()) != '\n') {
            }
            strcpy(game->status, "Game");
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
                game->delay = 200;
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
    game->delay = 10;
    strcpy(game->status, "Game");
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