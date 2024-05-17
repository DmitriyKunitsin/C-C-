#include "../inc/game_backend.h"

int validKeys[NUMBER_OF_KEYS] = {KEY_LEFT, KEY_RIGHT, KEY_UP,
                                 KEY_DOWN, '\n',      KEY_BACKSPACE};

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
    GameInfo_t *game = getGameInfo();
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
    printFieldMap();
    if (myDelay(10, KEY_UP)) {
        do {
        } while ((key = GET_USER_INPUT) != 'q');

    } else {
    }
}
