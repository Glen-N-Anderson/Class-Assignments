#include <iostream>
#include "./Surgery.h"
#include <string>
#include <cstdlib>
Surgery::Surgery(){
	sTotal = 0;
}
using namespace std;
void Surgery::surgCost(){
	string surgery;
	cout << "Enter a surgery(brain, head, heart, foot, knee): ";
	cin >> surgery;
	if(surgery == "brain"){
		sTotal = 30400.00;
	}
	else if(surgery == "head"){
		sTotal = 205000.00;
	}
	else if(surgery == "heart"){
		sTotal = 9000.00;
	}
	else if(surgery == "foot"){
		sTotal = 2100.00;
	}
	else if(surgery == "knee"){
		sTotal = 1800.00;
	}
	else{
		cout << "Not a valid surgery!" << endl;
		exit(0);
	} 

	cout << "Your surgery is: " << surgery << endl;
	cout << "Your cost is: " << sTotal << endl;

}
