#include "tetric.h"

int main() {
  // pthread_t theard1;
  //   pthread_t theard2;
  // Инициализация экрана
  initscr();
  AllocateMemory();
  startGame();
  //   pthread_create(&theard2, NULL, InitMap, map);
  // pthread_create(&theard1, NULL, startGame, NULL);
  // pthread_join(theard1, NULL); // жду завершения потока thread1
  // printf("stop game\n");
  FreeMemory();
  // Завершение работы с ncurses
  endwin();
  return 0;
}
void startGame() {
  char key;
  static int counter = 0;
  // printf("start game\n");
  ApperanceFigure();
  // printMap();
  CurrentFigure_my *figur = getCoordinate_GameFigure();
  while ((key = getch()) != 'q') {

    clearMap();
    // MyDelay(10);
    // ApperanceFigure();
    figureMoveDown();
    // controllerGame(key);
    printMap();
    refresh();
    mvprintw(9, 24, "_______next_figure________\n");
    for (int i = 0; i < figur->dimension; ++i) {
      for (int j = 0; j < figur->dimension; ++j) {
        mvprintw(10 + i, 25 + j, "%d", figur->nextFigure[i][j]);
      }
    }
    mvprintw(15, 24, "__________________________\n");
    mvprintw(20, 30, "step : %d", counter++);
  }
}
/*Выделение памяти для структуры данных игровой  карты*/
void AllocateMemory() {
  GameInfo_t *game = getInstance_GameInfo();
  game->field = (int **)malloc(SIZE_MAP_Y * sizeof(int *));
  game->next = (int **)malloc(SIZE_MAP_Y * sizeof(int *));
  for (int i = 0; i < SIZE_MAP_Y; ++i) {
    game->field[i] = (int *)malloc(SIZE_MAP_Y * sizeof(int));
    game->next[i] = (int *)malloc(SIZE_MAP_Y * sizeof(int));
    for (int j = 0; j < SIZE_MAP_X; ++j) {
      if (i == 0 || i == 19) {
        game->field[i][j] = 1;
      } else if (j == 0 || j == 9) {
        game->field[i][j] = 1;
      } else {
        game->field[i][j] = 0;
      }
    }
  }
  game->score = 0;
  game->high_score = 0;
  game->level = 1;
  game->speed = 1;
  game->pause = 0;
  GenereatedNextFigure();
  SwapFigureOldToNew();
}
void FreeMemory() {
  GameInfo_t *game = getInstance_GameInfo();
  for (int i = 0; i < SIZE_MAP_Y; ++i) {
    free(game->field[i]);
    free(game->next[i]);
  }
  free(game->field);
  free(game->next);
}

/*отрисовка карты*/
void printMap() {
  GameInfo_t *game = getInstance_GameInfo();
  for (int i = 0; i < SIZE_MAP_Y; ++i) {
    for (int j = 0; j < SIZE_MAP_X; ++j) {
      if (game->field[i][j] == 1) {
        mvprintw(i, j, "#  ");
      } else if (game->field[i][j] == 2) {
        mvprintw(i, j, "1  ");
      } else if (game->field[i][j] == 3) {
        mvprintw(i, j, "*  ");
      } else {
        mvprintw(i, j, "0  ");
      }
    }
  }
}
void clearMap() {
  // system("clear");
  GameInfo_t *gameBoard = getInstance_GameInfo();
  for (int i = 0; i < SIZE_MAP_Y; ++i) {
    for (int j = 0; j < SIZE_MAP_X; ++j) {
      if (i == 0 || i == 19) {
        gameBoard->field[i][j] = 1;
      } else if (j == 0 || j == 9) {
        gameBoard->field[i][j] = 1;
      } else {
        gameBoard->field[i][j] = 0;
      }
    }
  }
}
/*получение информации о фигуре*/
CurrentFigure_my *getCoordinate_GameFigure() {
  static CurrentFigure_my coordinate_X_y;
  return &coordinate_X_y;
}
/*получение информации о поле*/
GameInfo_t *getInstance_GameInfo() {
  static GameInfo_t game_info;
  return &game_info;
}
UserAction_t *getUserAction() {
  static UserAction_t user_info;
  return &user_info;
}
void figureMoveDown() {
  GameInfo_t *game = getInstance_GameInfo();
  CurrentFigure_my *currentFigure = getCoordinate_GameFigure();
  currentFigure->Y += 1;
  mvprintw(1, 25, "y = %d", currentFigure->Y);
  mvprintw(2, 25, "x = %d", currentFigure->X);
  mvprintw(3, 25, "center y = %d", currentFigure->Y + 2);
  mvprintw(4, 25, "center X = %d", currentFigure->X + 2);
  currentFigure->Y = check_Y_EdgeBoard_Down_Up();
  currentFigure->X = check_X_EdgeBoard_Left_Right();
  int countI = 0;
  int countJ = 0;
  // mvprintw(2,25,"countI = %d,countJ = %d",countI,countJ);
  for (int i = currentFigure->Y; i < (currentFigure->Y+currentFigure->dimension); ++i) {
    for (int j = currentFigure->X; j < (currentFigure->X+currentFigure->dimension); ++j) {
      if (currentFigure->figure[countI][countJ] == 2) {
        game->field[i][j] = currentFigure->figure[countI][countJ];
      }
      if (currentFigure->Y == i && currentFigure->X == j) {
        game->field[i][j] = 3;
      }
      countJ++;
    }
    countI++;
    countJ = 0;
  }
  countI = 0;
  countJ = 0;
}
int check_Y_EdgeBoard_Down_Up() {
  CurrentFigure_my *figure = getCoordinate_GameFigure();
  figure->Y = (figure->Y + figure->dimension) > SIZE_MAP_Y ? 16 : figure->Y;
  return figure->Y;
}
int check_X_EdgeBoard_Left_Right() {
  CurrentFigure_my *figure = getCoordinate_GameFigure();
  figure->X =
      (figure->X + (figure->dimension / 2)) > SIZE_MAP_X ? 9 : figure->X;
  figure->X = ((figure->X - (figure->dimension / 2)) <= 0) ? 1 : figure->X;
  return figure->X;
}
// void checkColissionFigure() {
//   CurrentFigure_my *figure = getCoordinate_GameFigure();
//   UserAction_t *game = getUserAction();
//   for(int i = 0; i < 5 ; ++i) {
//     for(int j = 0; j < 5 ; ++j) {

//     }
//   }

// }
void controllerGame(char key) {
  UserAction_t *selectUser = getUserAction();
  switch (key) {
  case 'w':
    /* code */
    printf("Стрелка вверх\n");
    *selectUser = Up;
    break;
  case 's':
    printf("Стрелка вниз\n");
    *selectUser = Down;
    break;
  case 'a':
    printf("Стрелка влево\n");
    *selectUser = Left;
    break;
  case 'd':
    printf("Стрелка вправо\n");
    *selectUser = Right;
    break;
  }
}
/*получение фигуры*/
int *getFigure(FigureType type) {
  static int figure_line[4][4] = {
      {0, 2, 0, 0}, {0, 2, 0, 0}, {0, 2, 0, 0}, {0, 2, 0, 0}};

  static int figure_G_left[4][4] = {
      {0, 0, 0, 0}, {2, 0, 0, 0}, {2, 2, 2, 0}, {0, 0, 0, 0}};

  static int figure_G_right[4][4] = {
      {0, 0, 0, 0}, {0, 0, 2, 0}, {2, 2, 2, 0}, {0, 0, 0, 0}};

  static int figure_Cube[4][4] = {
      {0, 0, 0, 0}, {0, 2, 2, 0}, {0, 2, 2, 0}, {0, 0, 0, 0}};

  static int figure_Z_right_up[4][4] = {
      {0, 0, 0, 0}, {0, 2, 2, 0}, {2, 2, 0, 0}, {0, 0, 0, 0}};

  static int figure_cross[4][4] = {
      {0, 0, 0, 0}, {0, 2, 0, 0}, {2, 2, 2, 0}, {0, 0, 0, 0}};

  static int figure_Z_left_up[4][4] = {
      {0, 0, 0, 0}, {2, 2, 0, 0}, {0, 2, 2, 0}, {0, 0, 0, 0}};
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
void MyDelay(int millisecond) {
  millisecond *= 10e6;
  for (int i = 0; i < millisecond; ++i) {
  }
}
/*получение радномного числа для выбора фигуры*/
int getRandNumberFigures() {
  int min = 0;
  int max = 6;
  int random_value = rand() % (max - min + 1) + min;
  random_value %= 10;
  return random_value;
}
/*появление новой фигуры*/
void ApperanceFigure() {
  GameInfo_t *game = getInstance_GameInfo();
  CurrentFigure_my *currentGameFigure = getCoordinate_GameFigure();
  for (int i = 0; i < currentGameFigure->dimension; ++i) {
    for (int j = 0; j < currentGameFigure->dimension; ++j) {
      int value = currentGameFigure->figure[i][j];
      game->field[currentGameFigure->Y + i][currentGameFigure->X + j] = value;
    }
  }
  SwapFigureOldToNew();
  GenereatedNextFigure();
}
/*замена новой на старую фигуру*/
void SwapFigureOldToNew() {
  CurrentFigure_my *GameFigure = getCoordinate_GameFigure();
  for (int i = 0; i < GameFigure->dimension; ++i) {
    for (int j = 0; j < GameFigure->dimension; ++j) {
      GameFigure->figure[i][j] = GameFigure->nextFigure[i][j];
    }
  }
}
/*Генерация следующей фигуры*/
void GenereatedNextFigure() {
  CurrentFigure_my *currentGameFigure = getCoordinate_GameFigure();
  int figureNumber = getRandNumberFigures();
  int *figurePointer = getFigure(figureNumber);

  currentGameFigure->dimension = 4;
  currentGameFigure->X = ((SIZE_MAP_X - currentGameFigure->dimension) /
                          2); // стартовые позиции фигуры
  currentGameFigure->Y = 0;
  for (int i = 0; i < currentGameFigure->dimension; ++i) {
    for (int j = 0; j < currentGameFigure->dimension; ++j) {
      int value = *(figurePointer + i * currentGameFigure->dimension + j);
      currentGameFigure->nextFigure[i][j] = value;
    }
  }
}