#include <iostream>
#include <cstdlib>
#include "./randomroomba.h"
using namespace std;

RandomRoomba::RandomRoomba(){

}
void RandomRoomba::set_rand(){
	r = rand() % 4 + 1;

}
int RandomRoomba::get_r(){
	return r;
}
