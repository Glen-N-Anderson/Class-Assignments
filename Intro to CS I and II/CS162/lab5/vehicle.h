#ifndef V_H
#define V_H
#include "./Date.h"
class vehicle {
	private:
		int seats;
	public:
		vehicle();
		vehicle(int);
		int get_seats();
		virtual int get_toll();
		Date day;



};
#endif
