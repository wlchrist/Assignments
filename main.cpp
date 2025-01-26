//
//  main.cpp
//  PA1
//
//  Created by Warren Christian on 1/24/25.
//

#include "game.h"

int main(int argc, const char * argv[]) {
    Game game;
    game.loadCommands();
    game.menuSelection();
    return 0;
}
