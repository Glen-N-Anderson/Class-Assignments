#ifndef C_H
#define C_H
#include "./vehicle.h"
class car : public vehicle {
	public:
		car();
		car(int);
		int get_toll();
};
#endif
