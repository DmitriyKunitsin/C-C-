#include <stdio.h>

#define X 10
#define Y 20
#define MAX_DIMENSION 3

typedef struct {
    int field[Y][X];
} GameInfo_t;

typedef struct {
    int Ycord;
    int Xcord;
    int dimension;
    int figure[MAX_DIMENSION][MAX_DIMENSION];
} Coordinat_Current_Figure;

Coordinat_Current_Figure *getCoordinate_GameFigure();
GameInfo_t *getInstance_GameInfo();
void nextFigure();


int main() {
    printf("\n");
    GameInfo_t *game = getInstance_GameInfo();

    for(int i = 0; i < Y; ++i) {
        for (int j = 0; j < X; ++j) {
             if (i == 0 || i == Y - 1) {
                game->field[i][j] = 1;
            } else if (j == 0 || j == X - 1) {
                game->field[i][j] = 1;
            } else {
                game->field[i][j] = 0;
            }
        }
    } 
    nextFigure();
    for(int i = 0; i < Y; ++i) {
        for (int j = 0; j < X; ++j) {
            printf("%d", game->field[i][j]);
        }
        printf("\n");
    }


printf("\n");
    return 0;
}
void nextFigure() {
    GameInfo_t *game = getInstance_GameInfo();
    Coordinat_Current_Figure *coord = getCoordinate_GameFigure();
    int figure[3][3] = {{0, 1, 0}, 
                        {1, 1, 1},
                        {0, 0, 0}};
    coord->Ycord = 1;
    coord->Xcord = 1;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            coord->figure[i][j] = figure[i][j];
        }
    }
    int countY = 0;
    int countX = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            game->field[1+i][4+j] = coord->figure[countY][countX];
            countX++;
        }
        countX = 0;
        countY++;
    }
    
}

GameInfo_t *getInstance_GameInfo() {
    static GameInfo_t game_info;
    return &game_info;
}
Coordinat_Current_Figure *getCoordinate_GameFigure() {
    static Coordinat_Current_Figure coordinate_X_y;
    return &coordinate_X_y;
}