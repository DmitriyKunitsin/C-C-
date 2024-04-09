#ifndef MAP_FOR_BOARD_H
#define MAP_FOR_BOARD_H

#include "../includes/common.h"
#include "../macro/macro_definitions.h"

extern int arr[Y_SIZE_ARRAY][X_SIZE_ARRAY];

void initMap(int **array);
void FillinArrayMap(int **array);
void printArrayWithColors(int **array);
void printNextMap(int **array, WINDOW *gameWindow);
void InitGameBoard(int **map);
void saveOldMap(GameInfo_t *game);

#endif