#include <iostream>

#ifndef RPS_H
#define RPS_H
class Tool;
class RPSGame{
	protected:
		Tool *human;
		Tool *comp;	
		Tool *t;	
		 
		int hwins;
		int compwins;
		int ties;
	public:
		RPSGame();
		char setAI();
		Tool* getAI();
		int getHwin();
		int getCompwin();
		int getTies();	
		void printInfo();	


};
#endif
