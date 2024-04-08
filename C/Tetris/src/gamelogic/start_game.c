#include "start_game.h"

#include "../figures/figuresForGames.h"
#include "../includes/common.h"

void startGame(int **map, WINDOW *gameWindow) {
    
    nextFigureGeneretion(map, gameWindow);
}

void nextFigureGeneretion(int **map, WINDOW *gameWindow) {
    int figureNumber = getRandNumberFigures();

    FigureType type = (FigureType)figureNumber;

    int *figurePointer = getFigure(type);

    int dimesion = (figureNumber == 0) ? 4 : 3;

    for (int i = 0; i < dimesion; i++) {
        for (int j = 0; j < dimesion; j++) {
            int value = *(figurePointer + i * dimesion + j);

            map[i + 1][(X_GAME_BOARD / 2) + j] = value;
        }
    }
    printNextMap(map, gameWindow);
}

int getRandNumberFigures() {
    int min = 0;
    int max = 6;
    int random_value = rand() % (max - min + 1) + min;
    random_value %= 10;
    return random_value;
}