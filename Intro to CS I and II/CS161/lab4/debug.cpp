#include <iostream> //mispelling 
#include <cmath>
#define WATER_WEIGHT 62.4; //Defines the specific weight of water
#define PI //uses pi constant
using namespace std; //use things like cout

int main() { //must have parenthesis() for yer function
	
	float radius, bforce, volume, weight;
	cout << "Please enter the weight (lbs): " << endl; //endl looks neater, missing semi colon
	cin >> weight; //switched up some of the >> on  the cout/cin, they were wrong way
	cout << "Please enter the radius: " << endl;
	cin >> radius;
	volume = 4./3. * PI(pow(radius, 3)); //pow is correct function
 	bforce = volume * WATER_WEIGHT; //volume was mispelled, water weight was as well, also bforce
	if(bforce >= weight) { //weight was not declared, should only be one "=" sign
		cout << "The sphere will float!" << endl; //I prefer endl, also ";" was in the statement
	} 	
	else { //removed ";", added bracket
			cout << "The sphere will sink!" << endl; //changed to endl
		} 
	 return 0; //needs to return 0, not just "return"
} //need this to close main function
