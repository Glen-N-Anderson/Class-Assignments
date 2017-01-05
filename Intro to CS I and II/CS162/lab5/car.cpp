#include "./car.h"
car::car(){

}
car::car(int x):vehicle(x) {}

int car::get_toll(){
	

	return 20*get_seats();
}
