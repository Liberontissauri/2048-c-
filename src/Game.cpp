#include "Game.hpp"
#include <time.h>
#include <iostream>

void Game::display_board() {
    for(int x = 0; x < 4; x++) {
            for(int y = 0; y < 4; y++) {
                std::cout << board[x][y] << " ";
            }
            std::cout << "\n";
        }
}
void Game::generate_new_block() {
    srand(time(NULL));
    while(true) {
        int random_x = rand() % 4;
        int random_y = rand() % 4;

        if(board[random_x][random_y] != 0) {continue;}

        //Returns 1 or 0, which acts as true or false
        if(rand() % 2 == 0) {
            board[random_x][random_y] = 2;
            break;
        }
        board[random_x][random_y] = 4;
        break;
    }
}