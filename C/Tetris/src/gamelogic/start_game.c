#include "start_game.h"

#include "../includes/common.h"

void startGame(int map[Y_SIZE_ARRAY][X_SIZE_ARRAY]) {
    int mm = map[1][1];
    endwin();
    exit(0);
    printf("%d", mm);
}