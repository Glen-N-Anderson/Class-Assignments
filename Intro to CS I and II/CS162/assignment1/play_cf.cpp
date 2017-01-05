#include <iostream>
#include "./connect_four.h"
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[]) {
        GAME *g = new GAME;
        if(argc == 7){
                bool validArgs = is_valid_arguments(g, argc, argv);
                if(validArgs) {
                        set_game_info(g, argv);
                        play_game(g);
                        delete_game(g);

                }
        }
        else{
                cout << "Bad input, invalid num of args!" << endl;
        delete_game( g );
                exit(0);
        }
        char decide;
        cout << "Do you want to countinue playing? (y/n) ";
        cin >> decide;
        while(decide == 'y'){
                cout << "Use ctrl-c at any time to quit. " << endl;
                set_game_info(g, argv);
                play_game(g);
                delete_game(g);
        }
        return 0;
}

