/******************************************************
 **** Program: Mouse and Dieter Poison 
 **** Author: Glen Anderson
 **** Date: 01/28/15
 **** Description: Calculates whether or not dieter will de from sweetener poisoning in lifetime
 **** Input: mouse lethal dose, mouse weight, dieter weight, life expectancy of dieter, sodas per week
 **** Output: Lethal dose for dieter, how much sweetener a dieter consumes in life, yes or no on whether it will kill them or not
 ********************************************************/



#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float mlethal, mweight, dweight, life, sodas, dlethal, sweet, sweetlife;

	cout << "Enter the amount of sweetener to kill a mouse: " << endl;
	cin >> mlethal;

	cout << "Enter the weight of the mouse: " << endl;
	cin >> mweight;

	cout << "Enter the weight of the dieter when they stop dieting: " << endl;
	cin >> dweight;
	
	cout << "How long will dieter live (years)? " << endl;
	cin >> life;

	cout << "How many diet sodas does the dieter drink in a week?" << endl;
	cin >> sodas;
	
	dlethal = mlethal * dweight / mweight;
	cout << "It will take " << dlethal << " in sweetener to kill dieter" << endl;

	sweet = sodas * 24 * .001;
	
	sweetlife = sweet * (365 / 7);
	cout << "The amount of sweetener the dieter will consume in a life: " << sweetlife << endl;

	if(dlethal >= sweetlife){
		cout << "yes" << endl;
	}
	else if(dlethal <= sweetlife){
		cout << "no" << endl;
	}
		
	return 0;
}

