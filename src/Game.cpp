#include "Game.hpp"
#include <time.h>
#include <iostream>

void Game::display_board() {
    for(int y = 0; y < 4; y++) {
            for(int x = 0; x < 4; x++) {
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


void Game::slide_left() {
    for(int y = 0; y < 4; y++) {
        int found_values = 0;
        for(int x = 0; x < 4; x++) {
            if(board[x][y] == 0) continue;
            int found_value = board[x][y];
            board[x][y] = 0;
            board[found_values][y] = found_value;
            
            found_values += 1;
        }
    }
}

void Game::merge_left() {
    for(int y=0; y < 4; y++) {
        int block_1 = board[0][y];
        int block_2 = board[1][y];
        if(block_1 == block_2) {
            board[0][y] = block_1 + block_2;
            board[1][y] = 0;
        }
    }
    for(int y=0; y < 4; y++) {
        int block_1 = board[1][y];
        int block_2 = board[2][y];
        if(block_1 == block_2) {
            board[1][y] = block_1 + block_2;
            board[2][y] = 0;
        }
    }
    for(int y=0; y < 4; y++) {
        int block_1 = board[2][y];
        int block_2 = board[3][y];
        if(block_1 == block_2) {
            board[2][y] = block_1 + block_2;
            board[3][y] = 0;
        }
    }
}

void Game::push_to_left() {
    slide_left();
    merge_left();
    slide_left();
}


void Game::slide_right() {
    for(int y = 0; y < 4; y++) {
        int found_values = 0;
        for(int x = 3; x >= 0; x--) {
            if(board[x][y] == 0) continue;
            int found_value = board[x][y];
            board[x][y] = 0;
            board[3 - found_values][y] = found_value;
            
            found_values += 1;
        }
    }
}

void Game::merge_right() {
    for(int y=0; y < 4; y++) {
        int block_1 = board[3][y];
        int block_2 = board[2][y];
        if(block_1 == block_2) {
            board[3][y] = block_1 + block_2;
            board[2][y] = 0;
        }
    }
    for(int y=0; y < 4; y++) {
        int block_1 = board[2][y];
        int block_2 = board[1][y];
        if(block_1 == block_2) {
            board[2][y] = block_1 + block_2;
            board[1][y] = 0;
        }
    }
    for(int y=0; y < 4; y++) {
        int block_1 = board[1][y];
        int block_2 = board[0][y];
        if(block_1 == block_2) {
            board[1][y] = block_1 + block_2;
            board[0][y] = 0;
        }
    }
}
void Game::push_to_right() {
    slide_right();
    merge_right();
    slide_right();
}


void Game::slide_up() {
    for(int x = 0; x < 4; x++) {
        int found_values = 0;
        for(int y = 0; y < 4; y++) {
            if(board[x][y] == 0) continue;
            int found_value = board[x][y];
            board[x][y] = 0;
            board[x][found_values] = found_value;
            
            found_values += 1;
        }
    }
}
void Game::merge_up() {
    for(int x=0; x < 4; x++) {
        int block_1 = board[x][0];
        int block_2 = board[x][1];
        if(block_1 == block_2) {
            board[x][0] = block_1 + block_2;
            board[x][1] = 0;
        }
    }
    for(int x=0; x < 4; x++) {
        int block_1 = board[x][1];
        int block_2 = board[x][2];
        if(block_1 == block_2) {
            board[x][1] = block_1 + block_2;
            board[x][2] = 0;
        }
    }
    for(int x=0; x < 4; x++) {
        int block_1 = board[x][2];
        int block_2 = board[x][3];
        if(block_1 == block_2) {
            board[x][2] = block_1 + block_2;
            board[x][3] = 0;
        }
    }
}
void Game::push_to_up() {
    slide_up();
    merge_up();
    slide_up();
}


void Game::slide_down() {
    for(int x = 0; x < 4; x++) {
        int found_values = 0;
        for(int y = 3; y >= 0; y--) {
            if(board[x][y] == 0) continue;
            int found_value = board[x][y];
            board[x][y] = 0;
            board[x][3 - found_values] = found_value;
            
            found_values += 1;
        }
    }
}
void Game::merge_down() {
    for(int x=0; x < 4; x++) {
        int block_1 = board[x][3];
        int block_2 = board[x][2];
        if(block_1 == block_2) {
            board[x][3] = block_1 + block_2;
            board[x][2] = 0;
        }
    }
    for(int x=0; x < 4; x++) {
        int block_1 = board[x][2];
        int block_2 = board[x][1];
        if(block_1 == block_2) {
            board[x][2] = block_1 + block_2;
            board[x][1] = 0;
        }
    }
    for(int x=0; x < 4; x++) {
        int block_1 = board[x][1];
        int block_2 = board[x][0];
        if(block_1 == block_2) {
            board[x][1] = block_1 + block_2;
            board[x][0] = 0;
        }
    }
}
void Game::push_to_down() {
    slide_down();
    merge_down();
    slide_down();
}