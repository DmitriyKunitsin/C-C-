#include "../inc/objects.h"

#include "../inc/fsm.h"
void initBoard() {
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    GameInfo_t *game = getGameInfo();
    game->field = (int **)calloc(SIZE_MAX_MAP_Y, sizeof(int *));
    game->next = (int **)calloc(SIZE_MAX_MAP_Y, sizeof(int *));
    for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
        game->field[i] = (int *)calloc(SIZE_MAX_MAP_X, sizeof(int));
        game->next[i] = (int *)calloc(SIZE_MAX_MAP_X, sizeof(int));
    }
    for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
        for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
            if (i == 0 || i == 19) {
                game->field[i][j] = 1;
            } else if (j == 0 || j == 9) {
                game->field[i][j] = 1;
            } else {
                game->field[i][j] = 0;
            }
        }
    }
    game->high_score = 0;  // TODO загружать из файла макс счет
    game->level = 0;
    game->pause = 0;
    game->score = 0;
    game->speed = 1;
}
void FreeMemory() {
    GameInfo_t *game = getGameInfo();
    for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
        free(game->field[i]);
        free(game->next[i]);
    }
    free(game->field);
    free(game->next);
}
void GenereatedNextFigure() {
    Current_Figure *currentGameFigure = getCurrentFigure();
    int figureNumber = getRandNumberFigures();
    int *figurePointer = getFigure(figureNumber);
    currentGameFigure->dimension = 4;
    for (int i = 0; i < currentGameFigure->dimension; ++i) {
        for (int j = 0; j < currentGameFigure->dimension; ++j) {
            int value = *(figurePointer + i * currentGameFigure->dimension + j);
            currentGameFigure->nextFigure[i][j] = value;
        }
    }
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
/*получение фигуры*/
int *getFigure(FigureType type) {
    static int figure_line[4][4] = {
        {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}};

    static int figure_G_left[4][4] = {
        {0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}};

    static int figure_G_right[4][4] = {
        {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}};

    static int figure_Cube[4][4] = {
        {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};

    static int figure_Z_right_up[4][4] = {
        {0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}};

    static int figure_cross[4][4] = {
        {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}};

    static int figure_Z_left_up[4][4] = {
        {0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};

    switch (type) {
        case LINE:
            return (int *)figure_line;
            break;
        case G_LEFT:
            return (int *)figure_G_left;
            break;
        case G_RIGHT:
            return (int *)figure_G_right;
            break;
        case CUBE:
            return (int *)figure_Cube;
            break;
        case Z_RIGHT_UP:
            return (int *)figure_Z_right_up;
            break;
        case CROSS:
            return (int *)figure_cross;
            break;
        case Z_LEFT_UP:
            return (int *)figure_Z_left_up;
            break;
        default:
            return NULL;
    }
}