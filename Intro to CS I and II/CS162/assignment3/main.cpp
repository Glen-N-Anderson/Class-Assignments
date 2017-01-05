/******************************************************
 **** Program: Rock, Paper, Scissors 
 **** Author: Glen Anderson
 **** Date: 05/05/15
 **** Description: Uses classes to play rock paper scissors with a computer AI
 **** Input: Choice of r, p, s
 **** Output: Wins, loses, ties
 ********************************************************/



#include <iostream>
#include "./Tool.h"
#include "./RPSGame.h"
#include <cstdlib>
using namespace std;

int main() {
	char type = ' ', c = ' ';
	int l, h = 0, com = 0, t = 0;
	
	RPSGame ai;
	Tool p;
	
	h = ai.getHwin();
       	com = ai.getCompwin();
        t = ai.getTies();
	
	while(true){	
		cout << "Play a round or quit(1=play, 0=quit)?" << endl;
		cin >> l;
		//PRINT FINAL SCORE IF USER QUITS

		if(l == 0){
			cout << "Final score: " << endl;
			cout << "Computer: " << com << endl;
			cout << "Player: " << h << endl;
			cout << "Ties: " << t << endl;
			exit(0);
		}
	
		cout << "Enter rock, paper, scissors(r,p,s): " << endl;
		cin >> type;
		cin.ignore();
	
		c = ai.setAI();
	
	
		//PRINT CURRENT GAME INFORMATION
	
		cout << "Computer chose " << c << endl;
		if(p.fight(type, c) == 1){
			cout << "YOU WON!" << endl;
			h += 1;
		}
		if(p.fight(type, c) == 2){
			cout << "Computer wins D:!" << endl;
			com += 1;
		}
		if(p.fight(type, c) == 3){
			cout << "TIE GAME!" << endl;
			t += 1;
		}
 		cout << "Your wins: " << h << endl;
		cout << "Computer wins: " << com << endl;
		cout << "Ties: " << t << endl;
	}
	
	return 0;
}

