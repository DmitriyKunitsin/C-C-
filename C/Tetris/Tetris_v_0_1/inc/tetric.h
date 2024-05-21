#ifndef TETRIS_H
#define TETRIS_H

#define SIZE_MAP_X 10
#define SIZE_MAP_Y 20
#define MAX_DEMISSION 4

#include <stdio.h>
// #include <pthread.h>
#include <stdlib.h>
#include <ncurses.h>

typedef enum {
    LINE,
    G_LEFT,
    G_RIGHT,
    CUBE,
    Z_RIGHT_UP,
    CROSS,
    Z_LEFT_UP,
    FIGURE_COUNT
} FigureType;

typedef enum {
    Start,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action
} UserAction_t;

typedef struct {
    int **field;
    int **next;
    int score;
    int high_score;
    int level;
    int speed;
    int pause;
} GameInfo_t;

typedef struct {
    int X;
    int Y;
    int dimension;
    int figure[MAX_DEMISSION][MAX_DEMISSION];
    int nextFigure[MAX_DEMISSION][MAX_DEMISSION];

} CurrentFigure_my;


// void userInput(UserAction_t action, bool hold);

void ApperanceFigureToNextField();
void saveMapAndNextFigure();
void MyDelay(int millisecond);
int getRandNumberFigures();
int* getFigure(FigureType type);
void controllerGame(char key);
CurrentFigure_my *getCoordinate_GameFigure();
GameInfo_t *getInstance_GameInfo();
int check_Y_EdgeBoard_Down_Up();
int check_X_EdgeBoard_Left_Right();
void GenereatedNextFigure();
void SwapFigureOldToNew();
void figureMoveDown();
void checkColissionFigure();
int check_X_Edge();
int check_Y_Edge();
void startGame();
void clearMap();
void AllocateMemory();
void FreeMemory();

GameInfo_t updateCurrentState();

#endif