#include "../inc/game_backend.h"

int validKeys[NUMBER_OF_KEYS] = {LEFT_ARROW, RIGHT_ARROW, UP_ARROW,
                                 DOWN_ARROW, '\n',        KEY_BACKSPACE};
void startGame() {
    int key;
    clear();
    UserAction_t input;
    initGameSetting();

    GenereatedNextFigure();
    userInput(Action, false);
    do {
        GameInfo_t *game = updateCurrentState();
        int buf_lvl = lvlUp(game->score);
        game->level = (buf_lvl == 0) ? 1 : buf_lvl;
        key = GET_USER_INPUT;
        if (myDelay(game->speed, key)) {  // нажата валидная клавиша
            input = checkTheKeyPressed(key);
            userInput(input, true);
        } else {  // прошел таймер и валидная клавиша не нажата
            userInput(Down, false);
        }

    } while (input != Terminate);
}

void initGameSetting() {
    GameInfo_t *game = getGameInfo();
    game->level = 1;
    game->score = 0;
    game->speed = 10;
    game->high_score = 0;  // TODO получение с бд рекорда
}

int lvlUp(int score) {
    int lvll = 0;
    GameInfo_t *game = getGameInfo();
    game->speed = 10;
    for (int i = 0; i < (score / 600) + 2 && i <= 10; ++i) {
        lvll = i;
    }
    for(int i = lvll; i > 0; --i) {
        game->speed -= 1;
    }
    return lvll;
}

#pragma region Delay
/*Проверка нажатой клавиши на валидность*/
bool isValidKey(int ch) {
    bool bl = false;
    for (int i = 0; i < NUMBER_OF_KEYS; ++i) {
        if (ch == validKeys[i]) {
            bl = true;
        }
    }
    if (IF_INPUT(ch)) {
        bl = true;
    }
    return bl;
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
#pragma endregion

#pragma region MoveFigure

void MoveFigureDown() {
    Current_Figure *figure = getCurrentFigure();
    if (checkCollissionDown()) {
        saveNextMapInFieldMap();
        int countTrue = 0;
        countTrue = checkLines(countTrue);
        addScore(countTrue);
        createRandomTetromino();
    } else {
        figure->Y++;
    }
}
void MoveFigureLeft() {
    Current_Figure *figure = getCurrentFigure();
    figure->X = (checkCollisionLeft() == false) ? (figure->X - 1) : figure->X;
}

void MoveFigureRight() {
    Current_Figure *figure = getCurrentFigure();
    figure->X = (checkCollisionRight() == false) ? (figure->X + 1) : figure->X;
}

void RotateFigure() {
    if (!checkCollissionRotate()) {
        Current_Figure *figure = getCurrentFigure();
        GameInfo_t *game = getGameInfo();
        int temp[4][4];
        for (int y = 0; y < figure->dimension; ++y) {
            for (int x = 0; x < figure->dimension; ++x) {
                temp[y][x] = figure->curFigure[y][x];
            }
        }
        for (int y = 0; y < figure->dimension; ++y) {
            for (int x = 0; x < figure->dimension; ++x) {
                figure->curFigure[y][x] = 0;
            }
        }
        for (int y = 0; y < figure->dimension; ++y) {
            for (int x = 0; x < figure->dimension; ++x) {
                figure->curFigure[y][x] = temp[figure->dimension - 1 - x][y];
            }
        }
        clearOldNextMap();
        for (int y = figure->Y; y < (figure->Y + figure->dimension); ++y) {
            for (int x = figure->X; x < (figure->X + figure->dimension); ++x) {
                game->next[y][x] =
                    figure->curFigure[y - figure->Y][x - figure->X];
            }
        }
    }
}
#pragma endregion

#pragma region PAUSE

void OnPauseGame() {
    GameInfo_t *game = getGameInfo();
    game->pause = 1;
}
void OffPauseGame() {
    GameInfo_t *game = getGameInfo();
    game->pause = 0;
}
bool checkedPause() {
    const GameInfo_t *game = updateCurrentState();
    return game->pause;
}
#pragma endregion

#pragma region CheckFullLine
void addScore(int countTrue) {
    GameInfo_t *game = getGameInfo();
    countTrue = (countTrue > 4) ? 4 : countTrue;
    switch (countTrue) {
        case 4:
            game->score += 1500;
            break;
        case 3:
            game->score += 700;
            break;
        case 2:
            game->score += 300;  // 300
            break;
        case 1:
            game->score += 100;
            break;
        default:
            break;
    }
}
int checkLines(int countTrue) {
    for (int y = SIZE_MAX_MAP_Y - 2; y >= 2; y--) {
        if (isFullLines(y)) {  // return true
            removeLines(y);
            countTrue++;
            countTrue = checkLines(countTrue);
        }
    }
    printGameMap();
    return countTrue;
}
void removeLines(int removeLinesY) {
    GameInfo_t *game = getGameInfo();
    for (int y = removeLinesY; y > 1; --y) {
        for (int x = 1; x < 10; ++x) {
            game->field[y][x] = game->field[y - 1][x];
        }
    }
}

bool isFullLines(int Y) {
    GameInfo_t *game = getGameInfo();
    bool isFull = false;
    int countTrue = 0;
    for (int x = 1; x < SIZE_MAX_MAP_X - 1; ++x) {
        if (game->field[Y][x] == 1) {
            countTrue++;
            if (countTrue == 8) {
                isFull = true;
            }
        }
    }
    countTrue = 0;
    return isFull;
}
#pragma endregion

#pragma region CreatFigure
void createRandomTetromino() {
    SwapFigureOldToNew();
    // printCurrentFigure();
    ApperanceFigureToNextField();
}
void GenereatedNextFigure() {
    Current_Figure *figure = getCurrentFigure();
    int figureNumber = getRandNumberFigures();
    int *figurePointer = getFigure(figureNumber);
    figure->dimension = 4;
    for (int i = 0; i < figure->dimension; ++i) {
        for (int j = 0; j < figure->dimension; ++j) {
            int value = *(figurePointer + i * figure->dimension + j);
            figure->nextFigure[i][j] = value;
        }
    }
}
void ApperanceFigureToNextField() {
    GameInfo_t *game = getGameInfo();
    Current_Figure *currentGameFigure = getCurrentFigure();
    currentGameFigure->X = ((SIZE_MAX_MAP_X - currentGameFigure->dimension) /
                            2);  // стартовые позиции фигуры
    currentGameFigure->Y = 0;
    for (int i = 0; i < currentGameFigure->dimension; ++i) {
        for (int j = 0; j < currentGameFigure->dimension; ++j) {
            int value = currentGameFigure->curFigure[i][j];
            game->next[currentGameFigure->Y + i][currentGameFigure->X + j] =
                value;
        }
    }
    GenereatedNextFigure();
    printNextFigure();
}
void SwapFigureOldToNew() {
    Current_Figure *GameFigure = getCurrentFigure();
    for (int i = 0; i < GameFigure->dimension; ++i) {
        for (int j = 0; j < GameFigure->dimension; ++j) {
            GameFigure->curFigure[i][j] = GameFigure->nextFigure[i][j];
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

#pragma endregion

#pragma region Collission
bool checkCollisionRight() {
    const GameInfo_t *game = getGameInfo();
    const Current_Figure *figure = getCurrentFigure();
    bool checkCollission = false;
    for (int y = figure->Y; y < (figure->Y + figure->dimension); ++y) {
        for (int x = figure->X; x < (figure->X + figure->dimension); ++x) {
            if ((game->next[y][x] == 1)) {
                if (game->field[y][x + 1] == 1) {
                    checkCollission = true;
                }
            }
        }
    }
    return checkCollission;
}
bool checkCollisionLeft() {
    const GameInfo_t *game = getGameInfo();
    const Current_Figure *figure = getCurrentFigure();
    bool checkCollission = false;
    for (int y = figure->Y; y < (figure->Y + figure->dimension); ++y) {
        for (int x = figure->X; x < (figure->X + figure->dimension); ++x) {
            if ((game->next[y][x] == 1)) {
                if (game->field[y][x - 1] == 1) {
                    checkCollission = true;
                }
            }
        }
    }

    return checkCollission;
}

bool checkCollissionDown() {
    const GameInfo_t *game = getGameInfo();
    const Current_Figure *figure = getCurrentFigure();
    bool checkCollission = false;
    for (int y = figure->Y; y < (figure->Y + figure->dimension); ++y) {
        for (int x = figure->X; x < (figure->X + figure->dimension); ++x) {
            if ((game->next[y][x] == 1)) {
                if (game->field[y + 1][x] == 1) {
                    checkCollission = true;
                }
            }
        }
    }

    return checkCollission;
}

bool checkCollissionRotate() {
    const GameInfo_t *game = getGameInfo();
    const Current_Figure *figure = getCurrentFigure();
    bool checkRotate = false;
    int temp[4][4];
    for (int i = 0; i < figure->dimension; ++i) {
        for (int j = 0; j < figure->dimension; ++j) {
            temp[i][j] = figure->curFigure[j][i];
        }
    }
    int i = 0;
    int j = 0;
    for (int y = figure->Y; y < (figure->Y + figure->dimension); ++y) {
        for (int x = figure->X; x < (figure->X + figure->dimension); ++x) {
            if (game->field[y][x] == 1) {
                if (temp[i][j++] == 1) {
                    checkRotate = true;
                }
            }
        }
        i++;
    }
    return checkRotate;
}
#pragma endregion
void saveNextMapInFieldMap() {
    GameInfo_t *game = getGameInfo();
    for (int y = 0; y < SIZE_MAX_MAP_Y; ++y) {
        for (int x = 0; x < SIZE_MAX_MAP_X; ++x) {
            if (game->next[y][x] == 1) {
                game->field[y][x] = game->next[y][x];
            }
        }
    }
}