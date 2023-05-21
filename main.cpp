#include "Game.h"

int main() {
    Player playercoord;
    Game game;
    game.setPlayerGhost(&playercoord);
    game.generatelevel();
    return 0;
}
