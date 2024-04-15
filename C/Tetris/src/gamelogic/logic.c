#include "logic.h"

int checkCollision(GameInfo_t *game) {
    Coordinat_Current_Figure *current_X_Y = getCoordinate_GameFigure();
    int flag = 0;
    int startY = ((current_X_Y->Y + current_X_Y->dimension) > Y_GAME_BOARD)
                     ? 21
                     : current_X_Y->Y;
    int startX = (current_X_Y->X - (current_X_Y->dimension / 2));
    for (int i = 0; i < current_X_Y->dimension; ++i) {
        for (int j = 0; j < current_X_Y->dimension; ++j) {
            int valuue = current_X_Y->figure[startY + i][startX + j];
            if (valuue == 1 && (game->field[startY + i][startX + j] == 1)) {
                flag = 1;  // столкновение обранурежно
                break;
            }
        }
    }
    return flag;
}

void swapFigureLeght(GameInfo_t *game) {
    Coordinat_Current_Figure *current_X_Y = getCoordinate_GameFigure();
    // clearBoard(game);
    int startY = ((current_X_Y->Y + current_X_Y->dimension) > Y_GAME_BOARD)
                     ? 21
                     : current_X_Y->Y;
    int startX =
        ((current_X_Y->X - current_X_Y->dimension) < 0) ? 1 : current_X_Y->X;

    for (int i = 0; i < current_X_Y->dimension; ++i) {
        for (int j = 0; j < current_X_Y->dimension; ++j) {
            game->field[startY + i][startX + j] = current_X_Y->figure[i][j];
        }
    }

    getCoordinatsFigure(current_X_Y->Y, current_X_Y->X - 1);
    // swapFigureDown(game);
}

void swapFigureRight(GameInfo_t *game) {
    Coordinat_Current_Figure *current_X_Y = getCoordinate_GameFigure();
    // clearBoard(game);
    int startY =
        ((current_X_Y->Y + (int)(current_X_Y->dimension / 2)) > Y_GAME_BOARD)
            ? 21
            : current_X_Y->Y;
    int startX = ((current_X_Y->X + current_X_Y->dimension) >= X_GAME_BOARD)
                     ? (current_X_Y->dimension == 3) ? 7 : 8
                     : current_X_Y->X;

    for (int i = 0; i < current_X_Y->dimension; ++i) {
        for (int j = 0; j < current_X_Y->dimension; ++j) {
            game->field[startY + i][startX + j] = current_X_Y->figure[i][j];
        }
    }

    getCoordinatsFigure(current_X_Y->Y, current_X_Y->X + 1);
    swapFigureDown(game);
}

void swapFigureDown(GameInfo_t *game) {
    Coordinat_Current_Figure *current_X_Y = getCoordinate_GameFigure();
    // clearBoard(game);
    StatusGame_t *statusGame = getStatus_Game();
    int startY = ((current_X_Y->Y + current_X_Y->dimension) > Y_GAME_BOARD)
                     ? 17
                     : current_X_Y->Y;
    int startX = ((current_X_Y->X + (int)(X_GAME_BOARD / 2)) >= X_GAME_BOARD)
                     ? 11
                     : current_X_Y->X;
    startX = (startX < 1) ? 1 : startX;
    for (int i = 0; i < current_X_Y->dimension; ++i) {
        for (int j = 0; j < current_X_Y->dimension; ++j) {
            game->field[startY + i][startX + j] = current_X_Y->figure[i][j];
        }
    }
    getCoordinatsFigure((current_X_Y->Y + 1) == 21 ? 20 : (current_X_Y->Y + 1),
                        current_X_Y->X);
    if (checkCollision(game)) {
        saveOldMap(game);
        *statusGame = SPAWN;
    }
}

void getCoordinatsFigure(int y, int x) {
    Coordinat_Current_Figure *current_X_Y = getCoordinate_GameFigure();
    current_X_Y->X = x;
    current_X_Y->Y = y;
}

Coordinat_Current_Figure *getCoordinate_GameFigure() {
    static Coordinat_Current_Figure coordinate_X_y;
    return &coordinate_X_y;
}