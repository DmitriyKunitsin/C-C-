#include "../inc/tetric.h"
#include "../inc/frontend.h"

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
  ApperanceFigureToNextField();
  // printMap();
  CurrentFigure_my *figur = getCoordinate_GameFigure();
  while ((key = getch()) != 'q') {

    // clearMap();
    // MyDelay(10);
    // ApperanceFigureToNextField();
    figureMoveDown();
    // controllerGame(key);
    printMap();
    print2Map();
    print3Map();
    mvprintw(14, 24, "_next___current___");
    for (int i = 0; i < figur->dimension; ++i) {
      for (int j = 0; j < figur->dimension; ++j) {
        mvprintw(15 + i, 25 + j, "%d", figur->nextFigure[i][j]);
      }
    }
    for (int i = 0; i < figur->dimension; ++i) {
      for (int j = 0; j < figur->dimension; ++j) {
        mvprintw(15 + i, 35 + j, "%d", figur->figure[i][j]);
      }
    }
    // mvprintw(19, 24, "___________________\n");
    mvprintw(20, 30, "step : %d", counter++);
    refresh();
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
void print2Map() {
  GameInfo_t *game = getInstance_GameInfo();
  mvprintw(0, 45, "field");
  for (int i = 0; i < SIZE_MAP_Y; ++i) {
    for (int j = 0; j < SIZE_MAP_X; ++j) {
      if (game->field[i][j] == 1) {
        mvprintw(1 + i, 45 + j, "*  ");
      } else if (game->field[i][j] == 2) {
        mvprintw(1 + i, 45 + j, "1  ");
      } else if (game->field[i][j] == 3) {
        mvprintw(1 + i, 45 + j, "*  ");
      } else {
        mvprintw(1 + i, 45 + j, "0  ");
      }
    }
  }
}
void print3Map() {
  GameInfo_t *game = getInstance_GameInfo();
  mvprintw(0, 65, "next");
  for (int i = 0; i < SIZE_MAP_Y; ++i) {
    for (int j = 0; j < SIZE_MAP_X; ++j) {
      if (game->next[i][j] == 1) {
        mvprintw(1 + i, 65 + j, "*  ");
      } else if (game->next[i][j] == 2) {
        mvprintw(1 + i, 65 + j, "1  ");
      } else if (game->next[i][j] == 3) {
        mvprintw(1 + i, 65 + j, "*  ");
      } else {
        mvprintw(1 + i, 65 + j, "0  ");
      }
    }
  }
}

/*отрисовка карты*/
void printMap() {
  GameInfo_t *game = getInstance_GameInfo();
  for (int i = 0; i < SIZE_MAP_Y; ++i) {
    for (int j = 0; j < SIZE_MAP_X; ++j) {
      if (game->field[i][j] == 1 || game->next[i][j] == 1) {
        mvprintw(i, j, "*  ");
      } else if (game->field[i][j] == 2 || game->next[i][j] == 2) {
        mvprintw(i, j, "1  ");
      } else if (game->field[i][j] == 3 || game->next[i][j] == 3) {
        mvprintw(i, j, "*  ");
      } else {
        mvprintw(i, j, "0  ");
      }
    }
  }
}
void clearFieldMap() {
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
void clearNextMap() {
  GameInfo_t *gameBoard = getInstance_GameInfo();
  for (int i = 0; i < SIZE_MAP_Y; ++i) {
    for (int j = 0; j < SIZE_MAP_X; ++j) {
      if (i == 0 || i == 19) {
        gameBoard->next[i][j] = 1;
      } else if (j == 0 || j == 9) {
        gameBoard->next[i][j] = 1;
      } else {
        gameBoard->next[i][j] = 0;
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
  currentFigure->Y = check_Y_EdgeBoard_Down_Up();
  currentFigure->X = check_X_EdgeBoard_Left_Right();
  mvprintw(1, 25, "y = %d", currentFigure->Y);
  mvprintw(2, 25, "x = %d", currentFigure->X);
  int countI = 0;
  int countJ = 0;
  checkColissionFigure();
  for (int i = currentFigure->Y;
       i < (currentFigure->Y + currentFigure->dimension); ++i) {
    for (int j = currentFigure->X;
         j < (currentFigure->X + currentFigure->dimension); ++j) {
      if (currentFigure->figure[countI][countJ] == 1) {
        game->next[i][j] = currentFigure->figure[countI][countJ];
      } else {
        game->next[i][j] = 0;
      }
      countJ++;
    }
    countI++;
    countJ = 0;
  }
  countI = 0;
  countJ = 0;
}
/*изменение координаты Y снизу, в случае выхода из границы*/
int check_Y_EdgeBoard_Down_Up() {
  CurrentFigure_my *figure = getCoordinate_GameFigure();
  figure->Y = (figure->Y + figure->dimension) > SIZE_MAP_Y ? 16 : figure->Y;
  mvprintw(8,25,"check Y Edge = %d",figure->Y);
  mvprintw(9,25,"check dimen+Y = %d",(figure->Y + figure->dimension));
  mvprintw(7,25,"check Y dim = %d",figure->dimension);
  return figure->Y;
}
/*изменение координаты X слева и справа, в случае выхода из границы*/
int check_X_EdgeBoard_Left_Right() {
  CurrentFigure_my *figure = getCoordinate_GameFigure();
  figure->X =
      (figure->X + (figure->dimension / 2)) > SIZE_MAP_X ? 9 : figure->X;
  figure->X = ((figure->X - (figure->dimension / 2)) <= 0) ? 1 : figure->X;
  return figure->X;
}
/*Чек окружения вокруг фигуры*/
void checkColissionFigure() {
  CurrentFigure_my *figure = getCoordinate_GameFigure();
  // UserAction_t *status = getUserAction();
  // *status = Action;
  GameInfo_t *game = getInstance_GameInfo();
  int t = 0;
  int g = 0;
  for (int i = figure->Y; i < (figure->dimension + figure->Y); ++i) {
    for (int j = figure->X; j < (figure->dimension + figure->X); ++j) {
      if (figure->figure[t][g] == 1) {
        mvprintw(3, 25, "check i = %d", i);
        if (game->field[i][j] == 1) {
          // mvprintw(6, 25, "check saveMap");
          saveMapAndNextFigure();
        }
      }
      g++;
    }
    t++;
  }
  t = 0;
  g = 0;
  // refresh();
  // int jec = 7;
  // for (int i = figure->Y; i < (figure->Y + 5); ++i) {
  //   for (int j = figure->X; j < figure->X + 5; ++j) {
  //     // mvprintw(jec++, 55, "i :%d j: %d", i, j);
  //   }
  // }
}

void saveMapAndNextFigure() {
  GameInfo_t *game = getInstance_GameInfo();
  CurrentFigure_my *figure = getCoordinate_GameFigure();
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension - 1; ++j) {
      if(figure->figure[i][j] == 1) {
      game->field[figure->Y + i][figure->X + j] = figure->figure[i][j];
      }
    }
  }

  mvprintw(10,25, "old y = %d x = %d ", figure->Y, figure->X);
  
  // clearNextMap();
  mvprintw(6, 25, "check saveMap");
  ApperanceFigureToNextField();
}
/*чек края карты по X для проверки окружения, чтобы не выйти за границы игрового
 * массива в случае, если уходит за края, то будет отнимать колизию, чтобы
 * обработать окружение*/
// int check_X_Edge() {
//   CurrentFigure_my *figure = getCoordinate_GameFigure();
//   int returnPosition = 0;
//   if ((figure->X + figure->dimension) > 10) {
//     returnPosition = 15;
//   } else if (figure->X < 0) {
//     returnPosition = 0;
//   } else {
//     returnPosition = figure->X;
//   }
//   return returnPosition;
// }
// /*чек края карты по Y для проверки окружения, чтобы не выйти за границы
// игрового
//  * массива*/
// int check_Y_Edge() {
//   CurrentFigure_my *figure = getCoordinate_GameFigure();
//   int returnPosition = 0;
//   if ((figure->Y + figure->dimension) >= 20) {
//     returnPosition = 16;
//   } else {
//     returnPosition = figure->Y;
//   }
//   return returnPosition;
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
void ApperanceFigureToNextField() {
  GameInfo_t *game = getInstance_GameInfo();
  CurrentFigure_my *currentGameFigure = getCoordinate_GameFigure();
    currentGameFigure->X = ((SIZE_MAP_X - currentGameFigure->dimension) /
                          2); // стартовые позиции фигуры
  currentGameFigure->Y = 0;
  for (int i = 0; i < currentGameFigure->dimension; ++i) {
    for (int j = 0; j < currentGameFigure->dimension; ++j) {
      int value = currentGameFigure->figure[i][j];
      game->next[currentGameFigure->Y + i][currentGameFigure->X + j] = value;
    }
  }
  mvprintw(12,25, "new y = %d x =%d ", currentGameFigure->Y, currentGameFigure->X);
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
  // clearNextMap()
  currentGameFigure->dimension = 4;
  for (int i = 0; i < currentGameFigure->dimension; ++i) {
    for (int j = 0; j < currentGameFigure->dimension; ++j) {
      int value = *(figurePointer + i * currentGameFigure->dimension + j);
      currentGameFigure->nextFigure[i][j] = value;
    }
  }
}