#include "../inc/game.h"

int main() {
    gameLoop();
    return 0;
}

void gameLoop() {
    WIN_INIT(1000);
    GAME();
}