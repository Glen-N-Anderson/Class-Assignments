#include "./motorcycle.h"

motorcycle::motorcycle(){

}
motorcycle::motorcycle(int x):vehicle(x) {}

int motorcycle::get_toll(){
	return 20*get_seats();
}
