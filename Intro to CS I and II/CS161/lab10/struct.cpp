/******************************************************
 **** Program: 
 **** Author: 
 **** Date:
 **** Description: 
 **** Input:
 **** Output:
 ********************************************************/


//#include <iostream>
#include "netflix.hpp"
using namespace std;

netflix set_netflix_info(){
        netflix movie;
        cout << "Enter name: " << endl;
        cin >> movie.name;
        cout << "Enter rating: " << endl;
        cin >> movie.rating;
	return movie;
}


/*int main() {
	netflix movie;
	set_netflix_info(&movie);
	cout << "Name: " << movie.name << endl;
	cout << "Rating: " << movie.rating << endl;
	return 0;
}*/

void set_netflix_info(netflix *movie){
	cout << "Enter name: ";
	cin >> movie->name;
	cout << "Enter rating: ";
	cin >> movie->rating;
}
