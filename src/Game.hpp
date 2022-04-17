class Game {
    public:
        int board[4][4] = {0, 2, 2, 2,
                           0, 2, 2, 2,
                           0, 2, 2, 2,
                           0, 2, 2, 2};;
        void display_board();
        void generate_new_block();
};