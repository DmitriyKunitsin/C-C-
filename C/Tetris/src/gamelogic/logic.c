#include "logic.h"

int checkCollision(GameInfo_t *game) {
    Coordinat_Current_Figure *current_X_Y = getCoordinate_GameFigure();
    int flag = 0;
    for (int i = 0; i < current_X_Y->dimension; ++i) {
        for (int j = 0; j < current_X_Y->dimension; ++j) {
            int valuue = current_X_Y->figure[i][j];
            if (valuue == 1 &&
                game->field[current_X_Y->Y + i][current_X_Y->X + j]) {
                flag = 1;  // столкновение обранурежно
                break;
            }
        }
    }
    return flag;
}

void swapFigureDown(GameInfo_t *game) {
    Coordinat_Current_Figure *current_X_Y = getCoordinate_GameFigure();
    clearBoard(game);
    int dimision = current_X_Y->dimension;
    int startY =
        ((current_X_Y->Y + dimision) > Y_GAME_BOARD) ? 21 : current_X_Y->Y;
    int startX =
        ((current_X_Y->X + dimision) > X_GAME_BOARD) ? 11 : current_X_Y->X;
    for (int i = 0; i < dimision; ++i) {
        for (int j = 0; j < dimision; ++j) {
            game->field[startY + i][startX + j] = current_X_Y->figure[i][j];
        }
    }
    getCoordinatsFigure(current_X_Y->Y + 1, current_X_Y->X);
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