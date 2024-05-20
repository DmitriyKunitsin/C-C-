#include "../inc/fsm.h"

GameInfo_t *getGameInfo() {
    static GameInfo_t gameInfo;
    return &gameInfo;
}

UserAction_t *getUserStatus() {
    static UserAction_t userAction;
    return &userAction;
}

const GameInfo_t *updateCurrentState() { return getGameInfo(); }

void userInput(UserAction_t action, bool hold) {
    switch (action) {
        case Start:
            // TODO реализация страрта игры, загрузки с бд данных о прошлом
            // рекорде
            printFieldMap();
            break;
        case Pause:
            OnPauseGame();
            do {
                // TODO отрисовка ожидания
                int keyPause = GET_USER_INPUT;
                if(IS_Q(keyPause)) {
                    OffPauseGame();
                }
            } while (!checkedPause());
            break;
        case Terminate:
            // TODO реализация выхода в меню
            break;
        case Left:
            MoveFigureLeft();
            break;
        case Right:
            MoveFigureRight();
            break;
        case Up:

            break;
        case Down:
            MoveFigureDown();
            if (hold == true) {
                // TODO реализация зажатой клавиши вниз
            }
            break;
        case Action:
            // TODO реализация появления новой фигуры
            break;
    }
}