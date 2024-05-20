#include "../inc/game_backend.h"

int validKeys[NUMBER_OF_KEYS] = {KEY_LEFT, KEY_RIGHT, KEY_UP,
                                 KEY_DOWN, '\n',      KEY_BACKSPACE};
/*Проверка нажатой клавиши на валидность*/
bool isValidKey(int ch) {
    bool bl = false;
    for (int i = 0; i < NUMBER_OF_KEYS; ++i) {
        if (ch == validKeys[i]) {
            bl = true;
        }
    }
    return bl;
}
bool checkedPause() {
    const GameInfo_t *game = updateCurrentState();
    return game->pause;
}
bool myDelay(int milliseconds, int ch) {
    milliseconds *= 100;
    bool checkValid = false;
    clock_t start_time = clock();
    do {
        checkValid = isValidKey(ch);
    } while (((clock() - start_time) * 1000 / CLOCKS_PER_SEC) < milliseconds &&
             !checkValid);
    return checkValid;
}
void startGame() {
    char key;
    clear();
    if (myDelay(10, 1231)) {
        //  пришла нужная клавиша
        do {
            printFieldMap();
        } while ((key = GET_USER_INPUT) != 'q');
    } else {  // пришла не нужная клавиша
        do {
            printFieldMap();
        } while ((key = GET_USER_INPUT) != 'q');
    }
}

int checkTheKeyPressed(int key) {
    key = convertInput(key);
    switch (key) {
        case DOWN_ARROW:
            MoveFigureDown();
            break;
        case UP_ARROW:

            break;
        case LEFT_ARROW:
            MoveFigureLeft();
            break;
        case RIGHT_ARROW:
            MoveFigureRight();
            break;
        case 'Q':

            break;
        case 'W':

            break;
        case 'E':

            break;
        case 'R':

            break;
        default:
            break;
    }
}

int convertInput(int key) {
    if (IS_Q(key)) {
        key = 'Q';
    } else if (IS_E(key)) {
        key = 'E';
    } else if (IS_R(key)) {
        key = 'R';
    } else if (IS_W(key)) {
        key = 'W';
    }
    return key;
}
void MoveFigureDown() {
    Current_Figure *figure = getCurrentFigure();
    figure->Y++;
}
void MoveFigureLeft() {
    Current_Figure *figure = getCurrentFigure();
    figure->X--;
}

void MoveFigureRight() {
    Current_Figure *figure = getCurrentFigure();
    figure->X++;
}

bool isLineFull(int row) {
    GameInfo_t *game = getGameInfo();
    bool checkLine = true;
    for (int i = 0; i < SIZE_MAX_MAP_X; ++i) {
        if (game->field[row][i] == 0) {
            checkLine = false;
        }
    }
    return checkLine;
}

void removeLine(int row) {
    GameInfo_t *game = getGameInfo();
    for (int i = row; i > 0; i--) {
        for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
            game->field[i][j] = game->field[i - 1][j];
        }
    }
}

void checkLines() {
    for (int i = SIZE_MAX_MAP_Y - 1; i >= 0; i--) {
        if (isLineFull(i)) {
            removeLine(i);
        }
    }
}