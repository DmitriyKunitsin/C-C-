#include "game_frontend.h"


void printLoseBanner() {
  clear();
  int keyInput;
  do {
    GameInfo_t *game = getGameInfo();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    mvprintw(8, 5, "You Lose =( \n your score = %d\n pleas enter Q for exit",
             game->score);
    keyInput = GET_USER_INPUT;
  } while (!IS_Q(keyInput));
  saveRecord();
}
void gameLoop() {
  WIN_INIT(1000);
  GAME();
  EXIT_GAME();
  FreeMemory();
}

void printFieldMap() {
  GameInfo_t *game = getGameInfo();
  mvprintw(0, 15, "field");
  for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
    for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
      (game->field[i][j] == 1) ? mvprintw(i + 1, 15 + j, "@")
                               : mvprintw(i + 1, 15 + j, " ");
    }
  }
}
void printNEXTmap() {
  GameInfo_t *game = getGameInfo();
  mvprintw(0, 27, "next");
  for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
    for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
      (game->next[i][j] == 1) ? mvprintw(i + 1, 27 + j, "@")
                              : mvprintw(i + 1, 27 + j, " ");
    }
  }
}
void printGGameMap() {
  const GameInfo_t *game = updateCurrentState();
  // игровое поле
  for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
    for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
      ((game->field[i][j] == 1) || (game->next[i][j] == 1))
          ? mvprintw(i + 1, j + 2, "@")
          : mvprintw(i + 1, j + 2, " ");
    }
  }
  //  игровое меню
  SCORE_PRINT(game->score);
  LEVEL_PRINT(game->level);
  RECORD_PRINT(game->high_score);
}

void printGameMap() {
  const GameInfo_t *game = updateCurrentState();
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);  // белый фон, черный текст
  for (int i = 0; i < SIZE_MAX_MAP_Y - 1; ++i) {
    for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
      if ((game->field[i][j] == 1) || (game->next[i][j] == 1)) {
        attron(COLOR_PAIR(1));
        mvaddch(i + 1, j + 2, ACS_CKBOARD);  // добавление квадрата
      } else {
        mvaddch(i + 1, j + 2, ' ');
      }
    }
  }
  //  игровое меню
  for (int i = 21; i < 40; ++i) {
    attron(A_BOLD);
    mvaddch(0, i, '-');
  }
  mvaddch(0, 40, '+');
  for (int i = 1; i < 10; ++i) {
    mvaddch(i, 40, '|');
  }
  mvaddch(10, 40, '+');
  for (int i = 39; i > 20; --i) {
    attron(A_BOLD);
    mvaddch(10, i, '-');
  }
  mvaddch(10, 20, '+');
  for (int i = 9; i > 0; --i) {
    mvaddch(i, 20, '|');
  }
  mvaddch(0, 20, '+');
  SCORE_PRINT(game->score);
  LEVEL_PRINT(game->level);
  RECORD_PRINT(game->high_score);
  PAUSE_PRINT;
  EXIT_PRINT;
  attroff(COLOR_PAIR(1));
}
void PrintExitMenu() {
  clear();
  init_pair(3, COLOR_BLACK, COLOR_WHITE);
  attron(COLOR_PAIR(3));
  mvprintw(4, 1, "Do you really want\n to go out?");
  attroff(COLOR_PAIR(3));

  //  рамки
  attron(A_BOLD);  // текст жирным
  mvprintw(7, 1, "+-------------+");
  mvprintw(8, 1, "| Q     - NO  |");
  mvprintw(9, 1, "| Enetr - YES |");
  mvprintw(10, 1, "+------------+");
  attroff(A_BOLD);
}

void printPauseMenu() {
  clear();
  init_pair(3, COLOR_BLACK, COLOR_WHITE);
  attron(COLOR_PAIR(3));
  mvprintw(4, 5, "PAUSE");
  attroff(COLOR_PAIR(3));

  //  рамки
  attron(A_BOLD);  // текст жирным
  mvprintw(7, 1, "+------------+");
  mvprintw(8, 1, "| press Q    |");
  mvprintw(9, 1, "| for GO     |");
  mvprintw(10, 1, "+------------+");
  attroff(A_BOLD);
}
void updateGameScreen() {
  const GameInfo_t *game = getGameInfo();
  Current_Figure *currentGameFigure = getCurrentFigure();
  clearOldNextMap();
  for (int i = 0; i < currentGameFigure->dimension; ++i) {
    for (int j = 0; j < currentGameFigure->dimension; ++j) {
      int value = currentGameFigure->curFigure[i][j];
      game->next[currentGameFigure->Y + i][currentGameFigure->X + j] = value;
    }
  }
}
void clearOldNextMap() {
  GameInfo_t *game = getGameInfo();
  for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
    for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
      game->next[i][j] = 0;
    }
  }
}
void printCurrentFigure() {
  const Current_Figure *figre = getCurrentFigure();
  mvprintw(7, 20, "Field");
  for (int i = 0; i < figre->dimension; ++i) {
    for (int j = 0; j < figre->dimension; ++j) {
      (figre->curFigure[i][j] == 1)
          ? mvprintw(i + CURENT_FIGURE_START_PRINT, 20 + j, "@")
          : mvprintw(i + 9, 20 + j, " ");
    }
  }
}
void printNextFigure() {
  const Current_Figure *figre = getCurrentFigure();
  start_color();
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  for (int i = 21; i < 40; ++i) {
    attron(A_BOLD);
    mvaddch(10, i, '-');
  }
  mvaddch(10, 40, '+');
  for (int i = 11; i < 20; ++i) {
    mvaddch(i, 40, '|');
  }
  mvaddch(19, 40, '+');
  for (int i = 38; i > 20; --i) {
    attron(A_BOLD);
    mvaddch(19, i, '-');
  }
  mvaddch(19, 20, '+');
  for (int i = 18; i > 10; --i) {
    mvaddch(i, 20, '|');
  }
  mvprintw(13, 22, "Next figure");
  for (int i = 0; i < figre->dimension; ++i) {
    for (int j = 0; j < figre->dimension; ++j) {
      if (figre->nextFigure[i][j] == 1) {
        attron(COLOR_PAIR(2));
        mvaddch(i + NEXT_FIGURE_START_PRINT, 30 + j, ACS_CKBOARD);
      } else {
        mvaddch(i + NEXT_FIGURE_START_PRINT, 30 + j, ' ');
      }
    }
  }
}

/*Блок с меню*/
void executeMenuItem(int item) {
  switch (item) {
    case 0:
      startGame();
      clear();
      break;
    case 1:
      EXIT_GAME();
      break;
    default:
      break;
  }
}
void ReaderForMenuSelectedItem() {
  int key;
  int selectedItem = 0;
  printMenu(0);
  while ((key = getch()) != KEY_BACKSPACE) {
    switch (key) {
      case KEY_UP:
        selectedItem = (selectedItem - 1 >= 0) ? selectedItem - 1 : 0;
        break;
      case KEY_DOWN:
        selectedItem = (selectedItem + 1 < 2) ? selectedItem + 1 : 2 - 1;
        break;
      case '\n':
        executeMenuItem(selectedItem);
        break;
      default:
        selectedItem = 0;
        break;
    }
    printMenu(selectedItem);
  }
}
void printMenu(int selectedItem) {
  int startY = 5;
  int startX = 5;
  mvprintw(2, 8, "Menu");
  for (int i = 0; i < 2; ++i) {
    if (selectedItem == i) {
      attron(A_REVERSE);
    }
    mvprintw(startY + 2 + i, startX, "%d. %s", i + 1,
             (i == 0) ? "Start" : "Exit");
    if (selectedItem == i) {
      attroff(A_REVERSE);
    }
  }
  refresh();
}