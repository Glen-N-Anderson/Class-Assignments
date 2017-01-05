/*
 * state.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: eecs162
 */
#include <iostream>
#include <cstring>
#include "state.h"

using namespace std;

void state::set_name(const char *n) {
//	delete [] name;
	name= new char [strlen(n)];
	for(int j = 0; j < 50; j++){
		name[j] = 'o';
	}
	for(int i = 0; i < 50; i++){
		name[i] = n[i];
	}

}

void state::display_name() {
	for(int i = 0; i < 5; i++)
	cout << "State is: " << name[i] << endl;
}

void state::set_pop(int n){
    this->pop=n;
}

void state::display_pop() {
	cout << "state, " << name << ", pop: " << pop << endl;
}

state::state() {
	pop=0;
	name=NULL;
}

state::~state() {

}
