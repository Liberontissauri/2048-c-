class Game {
    public:
        int board[4][4] = {0, 0, 0, 0,
                           0, 2, 2, 2,
                           0, 2, 4, 2,
                           0, 2, 2, 2};;
        void display_board();
        void generate_new_block();

        void slide_left();
        void merge_left();
        void push_to_left();

        void slide_right();
        void merge_right();
        void push_to_right();

        void slide_up();
        void merge_up();
        void push_to_up();

        void slide_down();
        void merge_down();
        void push_to_down();
};