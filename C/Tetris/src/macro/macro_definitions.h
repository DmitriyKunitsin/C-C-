#ifndef MACRO_DEFINITIONS_H
#define MACRO_DEFINITIONS_H

typedef enum {  // Конечный автома
    STATE_A,  // Enum для того, что к енаму можно обращаться только к одному
              // объекту
    STATE_B,
    STATE_C
} State;

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
    int **menu;
    int **next;
    int score;
    int high_score;
    int level;
    int speed;
    int pause;
} GameInfo_t;

#define X_GAME_BOARD 11
#define Y_GAME_BOARD 21
#define START_RIGHT_MENU_WIDTH 11
#define END_RIGHT_MENU_WIDTH 31
#define X_MENU 11
#define Y_MENU 21
#define Y_SIZE_ARRAY 21
#define X_SIZE_ARRAY 31
#define SIDE_LINE '*'
#define TOP_LINE '*'

#endif  // MACRO_DEFINITIONS_H