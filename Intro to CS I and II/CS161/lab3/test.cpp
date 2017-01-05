/******************************************************
 **** Program: 
 **** Author: 
 **** Date:
 **** Description: 
 **** Input:
 **** Output:
 ********************************************************/



#include <iostream>

using namespace std;

int main() {
	int preference;
	cout << "Do you like vi as an editor?(1=y,0=n): " << endl;
	cin >> preference;

		if(preference == 1){
			cout << "You love vi!" << endl;
		}		
		else if(preference == 0){
				cout << "You hate vi!" << endl;
			}
	return 0;
}

