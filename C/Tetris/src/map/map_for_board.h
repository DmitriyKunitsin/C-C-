#ifndef MAP_FOR_BOARD_H
#define MAP_FOR_BOARD_H

#include "../includes/common.h"
#include "../macro/macro_definitions.h"

extern int arr[Y_SIZE_ARRAY][X_SIZE_ARRAY];

void initMap(int array[Y_SIZE_ARRAY][X_SIZE_ARRAY]);
void FillinArrayMap(int array[Y_SIZE_ARRAY][X_SIZE_ARRAY]);
void printArrayWithColors(int array[Y_SIZE_ARRAY][X_SIZE_ARRAY]);

#endif