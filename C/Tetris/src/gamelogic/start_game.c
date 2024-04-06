#include "start_game.h"
#include "../figures/figuresForGames.h"
#include "../includes/common.h"

void startGame(int map[Y_SIZE_ARRAY][X_SIZE_ARRAY]) {
    int mm = map[1][1];
    
    mvprintw(12, 12, "RAND num : %d", getRandNumberFigures());
    
    mvprintw(18, 18,"CHECK : %d" ,mm);

}

void nextMapGeneretion(int map[Y_SIZE_ARRAY][X_SIZE_ARRAY]) {
    int figureNumber = getRandNumberFigures();
    int dimesion = (figureNumber == 0) ? 4 : 3;

    int **nextFigure = (int**)malloc(dimesion * sizeof(int *));
    for (int i = 0; i < dimesion; ++i) {
        nextFigure[i] = (int *)malloc(dimesion * sizeof(int));
    }

    // TODO  заполнение карты, новой фигурой

    for(int i = 0; i < dimesion; ++i) {
        free(nextFigure[i]);
    }
    free(nextFigure);
}

int getRandNumberFigures() {
    int min = 0;
    int max = 6;
    int random_value = rand() % (max - min + 1) + min ;
    random_value %= 10;
    return random_value;
}