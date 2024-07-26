#include "../../../tests/tetris_cli_tests.h"

/**
 * @brief lvlUp
 * Функция установки конкретного уровня
 */
START_TEST(tc_ok_1) {
  GameInfo_t game;
  game.score = 500;
  int lvl = lvlUp(game.score);
  ck_assert_int_eq(lvl, 1);
  game.score = 7000;
  lvl = lvlUp(game.score);
  ck_assert_int_eq(lvl, 10);
  game.score = 1500;
  lvl = lvlUp(game.score);
  ck_assert_int_eq(lvl, 3);
  game.score = 0;
  lvl = 0;
  for (int i = 2; i < 11; ++i) {
    game.score += 600;
    ck_assert_int_eq(lvlUp(game.score), i);
  }
  GameInfo_t* gg = getGameInfo();
  gg->score = 1100;
  lvl = lvlUp(gg->score);
  ck_assert_int_eq(lvl, 2);
  ck_assert_int_eq(gg->speed, 8);
  gg->score = 10000;
  lvl = lvlUp(gg->score);
  ck_assert_int_eq(lvl, 10);
  ck_assert_int_eq(gg->speed, 0);
  gg->score = 500;
  lvl = lvlUp(gg->score);
  ck_assert_int_eq(lvl, 1);
  ck_assert_int_eq(gg->speed, 9);
}
END_TEST
/**
 * @brief isValidKey
 * Проверка функции валидности клавиш
 */
START_TEST(tc_ok_2) {
  int validKeys[NUMBER_OF_KEYS] = {LEFT_ARROW, RIGHT_ARROW, UP_ARROW,
                                   DOWN_ARROW, '\n',        KEY_BACKSPACE};
  for (int i = 0; i < 6; ++i) {
    ck_assert_int_eq(isValidKey(validKeys[i]), 1);
  }
  int notValidKeys[NUMBER_OF_KEYS] = {'X', 'T', 'W', 'Y', ' ', 'z'};
  for (int i = 0; i < 6; ++i) {
    ck_assert_int_eq(isValidKey(notValidKeys[i]), 0);
  }
}
END_TEST

// /**
//  * @brief MoveFigureDown
//  * Передвижение фигуры вниз
//  */
START_TEST(tc_ok_3) {
  initBoard();
  Current_Figure* figura = getCurrentFigure();
  GameInfo_t* game = getGameInfo();
  int* figurePointer = getFigure(0);
  figura->dimension = 4;
  for (int i = 0; i < figura->dimension; ++i) {
    for (int j = 0; j < figura->dimension; ++j) {
      int value = *(figurePointer + i * figura->dimension + j);
      figura->curFigure[i][j] = value;
    }
  }
  for (int i = 0; i < figura->dimension; ++i) {
    for (int j = 0; j < figura->dimension; ++j) {
      int value = figura->curFigure[i][j];
      game->next[figura->Y + i][figura->X + j] = value;
    }
  }
  figura->Y = 9;
  figura->X = 5;

  game->field[10][5] = 1;
  MoveFigureDown();

  ck_assert_int_eq(figura->Y, 10);

  figura->Y = 10;
  figura->X = 3;
  game->next[10][3] = 1;
  game->field[11][3] = 1;
  MoveFigureDown();

  ck_assert_int_eq(figura->Y, 0);

  MoveFigureDown();

  ck_assert_int_eq(figura->Y, 1);

  figura->Y = 0;
  figura->X = 3;
  game->next[0][3] = 1;
  game->field[0][3] = 1;
  MoveFigureDown();

  ck_assert_int_eq(figura->Y, 1);
  FreeMemory();
}
END_TEST

/**
 * @brief MoveFigureLeft
 * Передвижение фигуры влево
 */
START_TEST(tc_ok_4) {
  initBoard();
  Current_Figure* figura = getCurrentFigure();
  GameInfo_t* game = getGameInfo();
  int* figurePointer = getFigure(4);
  figura->dimension = 4;
  for (int i = 0; i < figura->dimension; ++i) {
    for (int j = 0; j < figura->dimension; ++j) {
      int value = *(figurePointer + i * figura->dimension + j);
      figura->curFigure[i][j] = value;
    }
  }
  figura->Y = 10;
  figura->X = 5;
  updateGameScreen();
  game->field[9][4] = 1;
  game->field[10][4] = 1;
  game->field[11][4] = 1;
  game->field[11][5] = 1;
  game->field[11][6] = 1;

  MoveFigureLeft();
  ck_assert_int_eq(figura->X, 5);

  figura->Y = 4;
  figura->X = 5;
  game->field[3][4] = 0;
  game->field[4][4] = 0;
  game->field[5][4] = 0;
  updateGameScreen();
  MoveFigureLeft();
  ck_assert_int_eq(figura->X, 4);
  FreeMemory();
}
END_TEST
/**
 * @brief MoveFigureRight
 * Передвижение фигуры вправо
 */
START_TEST(tc_ok_5) {
  initBoard();
  Current_Figure* figura = getCurrentFigure();
  GameInfo_t* game = getGameInfo();
  int* figurePointer = getFigure(4);
  figura->dimension = 4;
  for (int i = 0; i < figura->dimension; ++i) {
    for (int j = 0; j < figura->dimension; ++j) {
      int value = *(figurePointer + i * figura->dimension + j);
      figura->curFigure[i][j] = value;
    }
  }
  figura->Y = 10;
  figura->X = 5;
  updateGameScreen();
  game->field[9][6] = 1;
  game->field[10][6] = 1;
  game->field[11][6] = 1;
  game->field[11][7] = 1;
  game->field[11][8] = 1;

  MoveFigureRight();
  ck_assert_int_eq(figura->X, 5);

  figura->Y = 10;
  figura->X = 5;
  game->field[9][6] = 1;
  game->field[10][6] = 1;
  game->field[11][6] = 1;
  game->field[12][5] = 1;
  game->field[12][6] = 1;
  game->field[12][4] = 1;
  updateGameScreen();

  MoveFigureRight();
  ck_assert_int_eq(figura->Y, 0);
  FreeMemory();
}
END_TEST

/**
 * @brief Rotate
 */
START_TEST(tc_ok_6) {
  initBoard();
  Current_Figure* figure = getCurrentFigure();
  GameInfo_t* game = getGameInfo();
  figure->dimension = 4;
  int* figurePointer = getFigure(0);
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      int value = *(figurePointer + i * figure->dimension + j);
      figure->curFigure[i][j] = value;
    }
  }
  figure->Y = 10;
  figure->X = 5;
  updateGameScreen();
  ck_assert_int_eq(game->next[12][6], 1);
  RotateFigure();
  ck_assert_int_eq(game->next[12][6], 0);
  FreeMemory();
}
END_TEST
/**
 * @brief setUserStatus
 */
START_TEST(tc_ok_7) {
  UserAction_t test = Start;
  setUserStatus(test);
  UserAction_t* check = getUserStatus();
  ck_assert_int_eq(*check, 0);
  UserAction_t test2 = Terminate;
  setUserStatus(test2);
  UserAction_t* check2 = getUserStatus();
  ck_assert_int_eq(*check2, 2);
}
END_TEST
/**
 * @brief OnPause and OffPause
 */
START_TEST(tc_ok_8) {
  GameInfo_t* game = getGameInfo();
  OnPauseGame();
  ck_assert_int_eq(game->pause, 1);
  OffPauseGame();
  ck_assert_int_eq(game->pause, 0);
  bool checkPause = checkedPause();
  ck_assert_int_eq(checkPause, 0);
}
END_TEST
/**
 * @brief addScore
 */
START_TEST(tc_ok_9) {
  GameInfo_t* game = getGameInfo();
  game->score = 100;
  addScore(4);  // +1500
  ck_assert_int_eq(game->score, 1600);
  addScore(3);  // +700
  ck_assert_int_eq(game->score, 2300);
  addScore(2);  // +300
  ck_assert_int_eq(game->score, 2600);
  addScore(1);  // +100
  ck_assert_int_eq(game->score, 2700);
}
END_TEST
// /**
//  * @brief checkLines and removeLines
//  */
START_TEST(tc_ok_10) {
  initBoard();
  GameInfo_t* game = getGameInfo();
  game->field[10][1] = 1;
  game->field[10][2] = 1;
  game->field[10][3] = 1;
  game->field[10][4] = 1;
  game->field[10][5] = 1;
  game->field[10][6] = 1;
  game->field[10][7] = 1;
  game->field[10][8] = 1;
  game->field[10][9] = 1;

  int countTrue = 0;
  countTrue = checkLines(countTrue);
  ck_assert_int_eq(countTrue, 1);
  FreeMemory();
}
END_TEST
/**
 * @brief checkRecords
 */
START_TEST(tc_ok_11) {
  initBoard();
  GameInfo_t* game = getGameInfo();
  game->score = 4444;
  saveRecord();
  int rec = checkRecords();
  ck_assert_int_eq(rec, 4444);
  FreeMemory();
}
END_TEST

/**
 * @brief meDelay
 */
START_TEST(tc_ok_12) {
  int delay = myDelay(10, '\n');
  ck_assert_int_eq(delay, 1);
}
END_TEST

/**
 * @brief iniGameSetting
 */
START_TEST(tc_ok_13) {
  GameInfo_t* game = getGameInfo();
  game->level = 7;
  initGameSetting();
  ck_assert_int_eq(game->level, 1);
}
END_TEST

int checkFigure() {
  Current_Figure* figure = getCurrentFigure();
  int check = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (figure->curFigure[i][j] == 1) {
        check = 1;
      }
    }
  }
  return check;
}
/**
 * @brief userInput
 */
START_TEST(tc_ok_14) {
  initBoard();
  GameInfo_t* game = getGameInfo();
  game->score = 4444;
  userInput(Terminate, false);
  int record = checkRecords();
  ck_assert_int_eq(game->high_score, record);

  Current_Figure* figure = getCurrentFigure();
  figure->dimension = 4;
  int* figurePointer = getFigure(0);
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      int value = *(figurePointer + i * figure->dimension + j);
      figure->curFigure[i][j] = value;
    }
  }
  figure->Y = 10;
  figure->X = 5;
  updateGameScreen();
  ck_assert_int_eq(game->next[13][6], 1);
  userInput(Up, false);
  ck_assert_int_eq(game->next[13][6], 0);

  figure->Y = 15;
  figure->X = 5;
  updateGameScreen();
  userInput(Down, true);
  ck_assert_int_eq(figure->Y, 0);

  figure->Y = 10;
  figure->X = 5;
  updateGameScreen();
  userInput(Right, false);
  ck_assert_int_eq(figure->X, 6);

  figure->Y = 10;
  figure->X = 5;
  updateGameScreen();
  userInput(Left, false);
  ck_assert_int_eq(figure->X, 4);

  figure->Y = 15;
  figure->X = 5;
  updateGameScreen();
  userInput(Action, false);
  ck_assert_int_eq(figure->Y, 0);

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      figure->curFigure[i][j] = 0;
    }
  }
  int check = checkFigure();
  ck_assert_int_eq(check, 0);
  userInput(Start, false);
  check = checkFigure();
  ck_assert_int_eq(check, 1);
  FreeMemory();
}
END_TEST
START_TEST(tc_ok_15) {
  initBoard();
  UserAction_t* input = getUserStatus();
  checkTheKeyPressed(DOWN_ARROW);
  ck_assert_int_eq(*input, Down);
  checkTheKeyPressed(UP_ARROW);
  ck_assert_int_eq(*input, Up);
  checkTheKeyPressed(LEFT_ARROW);
  ck_assert_int_eq(*input, Left);
  checkTheKeyPressed(RIGHT_ARROW);
  ck_assert_int_eq(*input, Right);
  checkTheKeyPressed('Q');
  ck_assert_int_eq(*input, Pause);
  GameInfo_t* game = getGameInfo();
  game->pause = 0;
  exitLogic();
  ck_assert_int_eq(*input, Pause);
  pauseLogic();
  ck_assert_int_eq(*input, Pause);
  checkTheKeyPressed('W');
  ck_assert_int_eq(*input, Action);
  FreeMemory();
}
END_TEST
Suite* tetris_suite() {
  Suite* s = suite_create("\033[36m Начинаем Union-тесты Тетриса \033[0m");
  TCase* tcases_ok;

  tcases_ok = tcase_create("tetris_ok");
  tcase_add_test(tcases_ok, tc_ok_1);
  tcase_add_test(tcases_ok, tc_ok_2);
  tcase_add_test(tcases_ok, tc_ok_3);
  tcase_add_test(tcases_ok, tc_ok_4);
  tcase_add_test(tcases_ok, tc_ok_5);
  tcase_add_test(tcases_ok, tc_ok_6);
  tcase_add_test(tcases_ok, tc_ok_7);
  tcase_add_test(tcases_ok, tc_ok_8);
  tcase_add_test(tcases_ok, tc_ok_9);
  tcase_add_test(tcases_ok, tc_ok_10);
  tcase_add_test(tcases_ok, tc_ok_11);
  tcase_add_test(tcases_ok, tc_ok_12);
  tcase_add_test(tcases_ok, tc_ok_13);
  tcase_add_test(tcases_ok, tc_ok_14);
  tcase_add_test(tcases_ok, tc_ok_15);

  suite_add_tcase(s, tcases_ok);

  return s;
}