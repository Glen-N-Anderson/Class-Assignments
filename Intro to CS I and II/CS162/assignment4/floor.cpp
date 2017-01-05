#include <iostream>
#include <fstream>
#include <string>
#include "./floor.h"
using namespace std;
Floor::Floor(){
	obj_row = 0;
	obj_col = 0;
	objx = 0;
	objy = 0;
}
void Floor::init_v(string name){
	string info;
	int c = 0, c2 = 0;

	vector <char> temp;	

	fstream file;
	file.open(name.c_str());

	while(!(file.eof())){
		getline(file, info);
		c++;
		if(c == 1)
			c2 = info.length();
	}
	for(int i = 0; i < c2; i++){
		temp.push_back('f');
	}
	for(int j = 0; j < c - 1; j++){
		v.push_back(temp);
	}
	
	obj_row = c -1;
	obj_col = c2;
	
	cout << "ROWS: " << obj_row << endl;
	cout << "COLS: " << obj_col << endl;
	
}
int Floor::get_objx(){
	return objx;
}
int Floor::get_objy(){
	return objy;
}
void Floor::view(){
        for(int i = 0; i < v.size(); i++){
                for(int j = 0; j < v[i].size(); j++){
                        cout << v[i][j] << ' ';
                }
                cout << endl;
        }

}


