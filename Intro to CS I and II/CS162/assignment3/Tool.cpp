#include <iostream>
#include "./Tool.h"

using namespace std;
Tool::Tool(){
	srock = 2;
	ssci = 2;
	spap = 2;
}
Tool::Tool(char){
}
void Tool::setStrength(int){}





int Tool::fight(char type, char aiType){
	if(type == 'r' && aiType == 's'){
		srock * 2;
		ssci / 2;
		return 1;	
	}
	if(type == 'p' && aiType == 'r'){
		spap * 2;
		srock / 2;
		return 1;	
	}
	if(type == 's' && aiType == 'p'){
		ssci * 2;
		spap / 2;
		return 1;
	}	
	if(type == 'r' && aiType == 'p'){
		return 2;
	
	}
	if(type == 's' && aiType == 'r'){
		return 2;
	}
	if(type == 'p' && aiType == 's'){
		return 2;
	}
	if(type == aiType){
		return 3;
	}
}
Tool::~Tool(){
}



