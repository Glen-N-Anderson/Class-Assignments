#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "./Movie.h"
#include "./Netflix.h"
using namespace std;
Netflix::Netflix(){
	numMovies = 0;
}
int Netflix::getNumMovies(){
	return numMovies;

}



void Netflix::setNumMovies(){
	cout << "How many movies are there?" << endl;
	cin >> numMovies;	

}


void Netflix::searchTitle(){
	string info;
	string search;

	ifstream iofile;
	iofile.open("netflix.dat");
	iofile >> info;
	cout << "Enter search: " << endl;
	cin >> search;

	if(info.find(search) != string::npos){
		cout << "Found match! Printing..." << endl;
		cout << info << endl;
	}
	else{
		cout << "No match for this search was found!" << endl;
	}
}


		
	
