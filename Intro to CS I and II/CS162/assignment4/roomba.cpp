#include <iostream>
#include "./randomroomba.h"
#include "./floor.h"
Roomba::Roomba(){
	battery = 0;
	total_moves = 0;
}
void Roomba::clean_floor(Floor f){
	bool clean = false;
	int x = 0, y = 0, z = 0, a = 0;
	string last_dir;

/*	while(clean == false){
		f.v[f.objx][f.objy] = 'c';
		if(last_dir == ""){
			if(f.objy > 0){
				f.objy--;
				cout << "Next move: GO UP" << endl;
				lastdir = ("up");
			}
		else if(f.objx > 0){
			f.objx--;
			cout << "Next move, go left" << endl;
			lastdir = ("left");
		}	
		else{
			lastdir = 



	}*/
}
