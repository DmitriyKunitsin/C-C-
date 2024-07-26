#include "../inc/objects.h"

#include "../inc/fsm.h"
void GenereatedNextFigure() {
  Current_Figure *figure = getCurrentFigure();
  int figureNumber = getRandNumberFigures();
  int *figurePointer = getFigure(figureNumber);
  figure->dimension = 4;
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      int value = *(figurePointer + i * figure->dimension + j);
      figure->nextFigure[i][j] = value;
    }
  }
}
Current_Figure *getCurrentFigure() {
  static Current_Figure figure;
  return &figure;
}
/*получение фигуры*/
int *getFigure(FigureType type) {
  static int figure_line[4][4] = {
      {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}};

  static int figure_G_left[4][4] = {
      {0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}};

  static int figure_G_right[4][4] = {
      {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}};

  static int figure_Cube[4][4] = {
      {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};

  static int figure_Z_right_up[4][4] = {
      {0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}};

  static int figure_cross[4][4] = {
      {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}};

  static int figure_Z_left_up[4][4] = {
      {0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};

  switch (type) {
    case LINE:
      return (int *)figure_line;
      break;
    case G_LEFT:
      return (int *)figure_G_left;
      break;
    case G_RIGHT:
      return (int *)figure_G_right;
      break;
    case CUBE:
      return (int *)figure_Cube;
      break;
    case Z_RIGHT_UP:
      return (int *)figure_Z_right_up;
      break;
    case CROSS:
      return (int *)figure_cross;
      break;
    case Z_LEFT_UP:
      return (int *)figure_Z_left_up;
      break;
    default:
      return NULL;
  }
}
void SwapFigureOldToNew() {
  Current_Figure *GameFigure = getCurrentFigure();
  for (int i = 0; i < GameFigure->dimension; ++i) {
    for (int j = 0; j < GameFigure->dimension; ++j) {
      GameFigure->curFigure[i][j] = GameFigure->nextFigure[i][j];
    }
  }
}
int getRandNumberFigures() {
  int min = 0;
  int max = 6;
  int random_value = rand() % (max - min + 1) + min;
  random_value %= 10;
  return random_value;
}