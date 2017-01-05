#include <iostream>
#include "./floor.h"
#include "./roomba.h"
using namespace std;
template <typename T>
class Room {
	private:
	//	Floor f;
		T *obj; //obj could be a Roomba, Person, etc.
	public:
Floor f;
Room()	{

}
 //The functionality of a room is to view it, put
 // //objects in it, take objects out of it, etc.
 // …
void clean_room() {
	if(obj!=NULL){
		obj->clean_floor(f);
	}
}
/*void view(){
	for(int i = 0; i < f.v.size(); i++){
		for(int j = 0; j < f.v[i].size(); j++){
			cout << f.v[i][j] << ' ';
		}
		cout << endl;
	}

}*/
void set_roomba(){


}

};
