/******************************************************
 **** Program: 
 **** Author: 
 **** Date:
 **** Description: 
 **** Input:
 **** Output:
 ********************************************************/



#include <iostream>
#include <vector>
#include "./room.hpp"
using namespace std;

int main(int argc, char *argv[]) {
	string filename;
	Room <Roomba> r;
	int batt = 0, row = 0, col = 0, view = 0;
	int choice;
	filename = argv[2];  
	batt = *argv[4];
	row = *argv[6];
	col = *argv[8];
	view = *argv[10];
	
	cout << "Which roomba? (1-Rand 2-By Row 3-By Column): ";
	cin >> choice;
	/*if(choice == 1){
		r.set_roomba(new RandomRoomba);
	}
	if(choice == 2){
		r.set_roomba(new RowRoomba);
	}
	if(choice == 3){
		r.set_roomba(new ColRoomba);
	}*/
	r.f.init_v(filename);
	return 0;
}

