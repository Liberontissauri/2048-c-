#include "Game.hpp"
#include <iostream>

void Game::display_board() {
    for(int x = 0; x < 4; x++) {
            for(int y = 0; y < 4; y++) {
                std::cout << board[x][y] << " ";
            }
            std::cout << "\n";
        }
}