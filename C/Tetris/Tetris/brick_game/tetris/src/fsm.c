#include "../inc/fsm.h"

GameInfo_t *getGameInfo() {
  static GameInfo_t gameInfo;
  return &gameInfo;
}
UserAction_t *getUserStatus() {
  static UserAction_t userAction;
  return &userAction;
}
void setUserStatus(UserAction_t status) {
  UserAction_t *userAction = getUserStatus();
  *userAction = status;
}

GameInfo_t *updateCurrentState() { return getGameInfo(); }

void initBoard() {
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
  game->high_score = 0;
  game->level = 0;
  game->pause = 0;
  game->score = 0;
  game->speed = 1;
}
void FreeMemory() {
  GameInfo_t *game = getGameInfo();
  for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
    if (game->field[i] != NULL) {
      free(game->field[i]);
      game->field[i] = NULL;
    }
    if (game->next[i] != NULL) {
      free(game->next[i]);
      game->next[i] = NULL;
    }
  }
  if (game->field != NULL) {
    free(game->field);
    game->field = NULL;
  }
  if (game->next != NULL) {
    free(game->next);
    game->next = NULL;
  }
  game->field = NULL;
  game->next = NULL;
}

void startGame() {
  int key;
  clear();
  initBoard();
  UserAction_t *input;
  userInput(Start, false);
  do {
    input = getUserStatus();
    GameInfo_t *game = updateCurrentState();
    int buf_lvl = lvlUp(game->score);
    game->level = (buf_lvl == 0) ? 1 : buf_lvl;
    key = GET_USER_INPUT;
    if (myDelay(game->speed, key)) {  // нажата валидная клавиша
      *input = checkTheKeyPressed(key);
      userInput(*input, true);
    } else {  // прошел таймер и валидная клавиша не нажата
      userInput(Down, false);
    }

  } while (*input != Terminate);
}
void initGameSetting() {
  GameInfo_t *game = getGameInfo();
  UserAction_t *statusGame = getUserStatus();
  *statusGame = Start;
  setUserStatus(*statusGame);
  game->level = 1;
  game->score = 0;
  game->speed = 10;
  game->high_score = checkRecords();
}
void pauseLogic() {
  printPauseMenu();
  do {
    int keyPause = GET_USER_INPUT;
    if (IS_Q(keyPause)) {
      OffPauseGame();
    }
  } while (checkedPause());
  clear();
  printGameMap();
  printNextFigure();
}
void saveRecord() {
  GameInfo_t *game = getGameInfo();
  int oldRecord = checkRecords();
  game->high_score = (game->score > oldRecord) ? game->score : oldRecord;
  FILE *file;
  file = fopen("records.txt", "w");
  fprintf(file, "%d", game->high_score);
  fclose(file);
}
void userInput(UserAction_t action, bool hold) {
  switch (action) {
    case Start:
      clear();
      initGameSetting();
      GenereatedNextFigure();
      createRandomTetromino();
      printGameMap();
      break;
    case Pause:
      OnPauseGame();
      pauseLogic();
      break;
    case Terminate:
      saveRecord();
      break;
    case Left:
      MoveFigureLeft();
      updateGameScreen();
      printGameMap();
      break;
    case Right:
      MoveFigureRight();
      updateGameScreen();
      printGameMap();
      break;
    case Up:
      RotateFigure();
      updateGameScreen();
      printGameMap();
      break;
    case Down:
      if (hold == true) {
        while (1 != checkCollissionDown()) {
          MoveFigureDown();
          updateGameScreen();
        }
      }
      MoveFigureDown();
      updateGameScreen();
      printGameMap();
      break;
    case Action:
      clear();
      createRandomTetromino();
      printGameMap();
      break;
    case Inaction:
      break;
  }
}
void exitLogic() {
  UserAction_t *input = getUserStatus();
  do {
    int keyEnter = GET_USER_INPUT;
    if (IS_ENTER(keyEnter)) {
      *input = Terminate;
      OffPauseGame();
    }
    if (IS_Q(keyEnter)) {
      *input = Inaction;
      OffPauseGame();
    }
  } while (checkedPause());
  clear();
  printGameMap();
  printNextFigure();
}
UserAction_t checkTheKeyPressed(int key) {
  key = convertInput(key);
  UserAction_t *input = getUserStatus();
  switch (key) {
    case DOWN_ARROW:
      *input = Down;
      break;
    case UP_ARROW:
      *input = Up;
      break;
    case LEFT_ARROW:
      *input = Left;
      break;
    case RIGHT_ARROW:
      *input = Right;
      break;
    case 'Q':
      *input = Pause;
      break;
    case '\n':
      PrintExitMenu();
      OnPauseGame();
      exitLogic();
      break;
    default:
      *input = Action;
      break;
  }
  return *input;
}

int convertInput(int key) {
  if (IS_Q(key)) {
    key = 'Q';
  } else if (IS_ENTER(key)) {
    key = '\n';
  }
  return key;
}