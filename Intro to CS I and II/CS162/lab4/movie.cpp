#include <iostream>
#include "./movie.h"
#include <string>

using namespace std;

movie::movie(){
	name = '\0';
	stars = 0;
	num_cast = 0;
	cast = '\0';
	rating = '\0';
	copies = 0;
}
movie::movie(int){
}
movie::movie(const movie&){
}
movie::~movie(){
	delete [] cast;
}
void movie::getCast(){
	cout << "Enter num cast: " << endl;
	cin >> num_cast;
	cast = new string[num_cast];
	for(int i = 0; i < num_cast; i++){
		cout << "Enter cast member: " << endl;
		cin >> cast[i];
	}
}	
