#include <iostream>
#include "./RPSGame.h"
#include "./Tool.h"
#include <ctime>
#include <cstdlib>
#include <cmath>


using namespace std;

RPSGame::RPSGame(){
	hwins = 0;
	compwins = 0;
	ties = 0;
}

char RPSGame::setAI(){
	int random;
	Tool t;
	
	srand(time(0));
	random = (rand()%3) + 1;
	if(random == 1){
		return 'r';	
	}
	if(random == 2){
		return 'p';
	}
	if(random == 3){
		return 's';
	}

}
Tool* RPSGame::getAI(){
	return comp;
}

int RPSGame::getHwin(){
	return hwins;
}
int RPSGame::getCompwin(){
	return compwins;
}
int RPSGame::getTies(){
	return ties;
}
