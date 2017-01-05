/******************************************************
 **** Program: Assignment #1, Connect four!
 **** Author: Glen Anderson
 **** Date: 04/06/15
 **** Description: Connect any game, using printed board
 **** Input: Command line: r, c, p
 **** Output: Board, winner
 ********************************************************/



#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "./connect_four.h"
using namespace std;
void delete_game(GAME *theGame) { 
	for(int r = 0; r < theGame->r; r++) {
		delete [] theGame->board[r];
	}
	delete [] theGame->board;
}

// Function is used to merely check if the arguments are valid
bool is_valid_arguments( GAME* g, int argc, char *argv[]){

	if(strcmp(argv[0], "./connect_four") == 0) {
                if(!(strcmp(argv[1], "-r") == 0 && strcmp(argv[3], "-c") == 0 && strcmp(argv[5], "-p") == 0 )){
                        cout << "Bad input, wrong args!" << endl;
                        exit(0);
                }

        }
	
	return 1;
}

// Function is used to initialize the game only
void set_game_info(GAME *g, char *argv[]){
    char rc = *argv[2];
    char cc = *argv[4];
    char pc = *argv[6];
    while((rc <= 48 || rc >= 58) || (cc <= 48 || cc >= 58) || (pc <= 48 || pc >= 58)){
        cout << "Enter valid integer for rows: " << endl;
        cin >> rc;
        cout << "Enter valid integer for cols: " << endl;
        cin >> cc;
        cout << "Enter valid integer for p: " << endl;
        cin >> pc;
    }
    
    g->r = rc - '0';
    g->c = cc - '0';
    g->p = pc - '0';
	
	g->board = create_table(g->r, g->c);
}

char** create_table(int rows, int cols){
	char **board = new char *[rows];
	for(int i = 0; i < rows; i++){
		board[i] = new char[cols];
	}	
	
	
	
	for(int j = 0; j < rows; j++){
		cout << "|";
		for(int k = 0; k < cols; k++){
			board[j][k] = ' ';
			cout << board[j][k] << "\t"; 
			cout << "|";

		}
	cout << endl;	
	}

	return board;
}

void print(GAME* aGame){
    // Print by row
	 for(int j = 0; j < aGame->r; j++){
                cout << "|";
                // Print by column
                for(int k = 0; k < aGame->c; k++){
                        cout << aGame->board[j][k] << "\t";
                        cout << "|";

                }
        cout << endl;
        }
	return;
}


// Helper functions --------

bool dropInColumn(GAME *aGame, int column, char player) {
    
       for(int i = 0; i < aGame->r; i++) {
    	      if(aGame->board[i][column] == ' ') {
    	   	      aGame->board[i][column] = player;
            		      return true;
        }
    }
       return false;
}

void selectColor(GAME* aGame) {
       cout << "Player one, red or yellow (y/r): ";
       cin >> aGame->p1;
       if(aGame->p1 == 'y'){
              aGame->p2 = 'r';
    }
       else{
              aGame->p2 = 'y';
    }
}


void play_game(GAME* aGame){

	int choice, a = 1;

	selectColor(aGame);
    
    // Loop until game is over
        while(true) {
                bool gameOver = false;

	        cout << "Player one, select column: " << endl;
                cin >> choice;
        while(!dropInColumn(aGame, choice - 1, aGame->p1)) {
                cout << "Player one, that was not a valid column, please select new column: " << endl;
                cin >> choice;
        }
        
		print(aGame);
		gameOver = test_win(*aGame);
        
        if(true == gameOver) {
               cout << aGame->p1 << " has won! Congratulations player one! " << endl;
               break;
        }
        
        cout << "Player two, select column: " << endl;
        cin >> choice;
        while(!dropInColumn(aGame, choice - 1, aGame->p2)) {
               cout << "Player two, that was not a valid column, please select new column: " << endl;
               cin >> choice;
        }
        
        print(aGame);
        // Dereference and pass the heap allocated GAME variable to the function
        gameOver = test_win(*aGame);
        
        if(true == gameOver) {
               cout << aGame->p2 << " has won! Congratulations player two! " << endl;
               break;
        }
    }
	


}

// This function will return whether or not the users newest choice wins them the game
// a constant reference to the game is passed so that no values are changed in the process
bool test_win(const GAME &theGame){
	bool result = false;
	int remainingPieces = theGame.p - 1;
	for(int r = 0; r < theGame.r; r++) {
		for(int c = 0; c < theGame.c; c++) {
			char current_player = theGame.board[r][c];
			if(current_player != ' '){
			bool horiz, vert, diaR, diaL;
			horiz = vert = diaR = diaL = true;
			for(int p = 1; p < theGame.p; p++) {

				if(((r + remainingPieces) < theGame.r)) {
					horiz = horiz && (current_player == theGame.board[r + p][c]);
				} else {
					horiz = false;
				}
				if((c + remainingPieces) < theGame.c) {
					vert = vert && (current_player == theGame.board[r][c + p]);
				} else {
					vert = false;
				}
				if(((c + remainingPieces) < theGame.c) && ((r + remainingPieces) < theGame.r)) {
					diaR = diaR && (current_player == theGame.board[r+p][c+p]);
				} else {
					diaR = false;
				}
				if(((c - remainingPieces) >= 0) && ((r + remainingPieces) < theGame.r)) {
					diaL = diaL && (current_player == theGame.board[r+p][c-p]);
				} else {
					diaL = false;
				}
			}
			result = result || horiz || vert || diaR || diaL;
			}
		}
	}

	return result;
} 










