#include "../inc/fsm.h"

GameInfo_t *getGameInfo() {
    static GameInfo_t gameInfo;
    return &gameInfo;
}

UserAction_t *getUserStatus() {
    static UserAction_t userAction;
    return &userAction;
}

GameInfo_t updateCurrentState() {
    GameInfo_t *game = getGameInfo();
    return *game;
}

void userInput(UserAction_t action, bool hold) {
    GameInfo_t *game = getGameInfo();
    switch (action) {
        case Start:
            // TODO реализация страрта игры, загрузки с бд данных о прошлом
            // рекорде
            printFieldMap();
            break;
        case Pause:
            game->pause = 1;
            break;
        case Terminate:
            // TODO реализация меню
            break;
        case Left:

            break;
        case Right:

            break;
        case Up:

            break;
        case Down:

            if (hold == true) {
                // TODO реализация зажатой клавиши вниз
            }
            break;
        case Action:
            // TODO реализация появления новой фигуры
            break;
    }
}