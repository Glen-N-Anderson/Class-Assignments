/******************************************************
 **** Program: 
 **** Author: 
 **** Date:
 **** Description: 
 **** Input:
 **** Output:
 ********************************************************/



#include <iostream>
#include <cmath>

using namespace std;

void squareArea(float a, float b, float step, float &total);
void AreaIter(float a, float b, float step, float &total2);

int main() {
	float a, b, step, total = 0, total2 = 0;
	cout << "Enter starting point: " << endl;
	cin >> a;
	
	cout << "Enter ending point: " << endl;
	cin >> b;

	cout << "Enter how many rectangles: " << endl;
	cin >> step;
	step = (b-a)/step;
	squareArea(a, b, step, total);
	AreaIter(a, b, step, total2);
	cout << "Area is: " << total << endl;
	
	


	return 0;
}
void squareArea(float a, float b, float step, float &total){

	float area;
	area = (pow(a,5) + 10) * step;
	total += area;
	a += step;
	
	if(a >= b){
		return;
	}
	squareArea(a, b, step, total);
	
}	

void AreaIter(float a, float b, float step, float &total2){
	cout << "test" << a << b << step << endl;

	float area2 = 0;
	for(a; a < b; a += step){
		area2 = pow(a,5) + 10 * step;
        	total2 += area2;
	}
	cout << "Iterative solution: " << total2 << endl;
	return;
}



	
