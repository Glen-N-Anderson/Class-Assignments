#include <iostream>

using namespace std;
typedef struct game{
        char **board;
        int r, c, p;
        char p1;
        char p2;
} GAME;

bool is_valid_arguments( GAME*, int argc, char *argv[]);
void set_game_info( GAME *aGame, char *argv[] );
char** create_table(int rows, int cols);
void print(GAME *);
void play_game(GAME *);
bool test_win(const GAME &);
bool check_winner(GAME);
void delete_game(GAME *);

