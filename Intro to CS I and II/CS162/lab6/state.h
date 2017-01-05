/*
 * state.h
 *
 *  Created on: Apr 25, 2014
 *      Author: eecs162
 */
#include <string>
#ifndef STATE_H_
#define STATE_H_
using namespace std;

class state {
private:
	string name;
	int pop;
public:
	void set_name(string);
	void display_pop();
	void set_pop(int);
	state();
	virtual ~state();
};

#endif /* STATE_H_ */
