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
