#include <iostream>
#include <string>
#include "./Movie.h"
#include <fstream>

using namespace std;

Movie::Movie(){ //default constructor, sets all variables to null
	num = 0;
	stars = 0;
	numCast = 0;
	copies = 0;

}
/*Movie::Movie(string name, int stars, int numCast, string *cast, string rating, int copies){
	cout << "Enter name of movie: " << endl;
	cin >> name;
	
	cout << "Enter stars: " << endl;
	cin >> stars;
	
	cout << "How many cast members?: " << endl;
	cin >> numCast;
	
	cast = new string [numCast];
	for(int i = 0; i < numCast; i++){
		cout << "Enter cast member: " << endl;
		cin >> cast[i];
	}
	
	cout << "Enter rating: " << endl;
	cin >> rating;

	cout "Enter copies available: " << endl;	
	cin >> copies;

}*/
int Movie::getNum(){
	return num;
}
string Movie::getName(){
	return name;
}
int Movie::getStars(){
	return stars;
}
int Movie::getNumCast(){
	return numCast;
}
string* Movie::getCast(){
	return cast;
}
string Movie::getRating(){
	return rating;
}
int Movie::getCopies(){
	return copies;
}



void Movie::setNum(){
		

}
void Movie::setName(){
	fstream iofile;
	
	cout << "Enter name of movie: " << endl;
	cin >> name;
	
	iofile.open("file.txt", ios::in|ios::out|ios::app); //append to file
	iofile << name << " | ";

}
void Movie::setStars(){
	fstream iofile;
	
	cout << "Enter number of stars: " << endl;
	cin >> stars;

	iofile.open("file.txt", ios::in|ios::out|ios::app);
	iofile << stars << " | ";
}
void Movie::setNumCast(){
	fstream iofile;
	
	cout << "Enter number of cast members: " << endl;
	cin >> numCast;

	iofile.open("file.txt", ios::in|ios::out|ios::app);
	iofile << numCast << " | ";
}
void Movie::setCast(){
	fstream iofile;
	iofile.open("file.txt", ios::in|ios::out|ios::app);
	cast = new string[numCast];
	for(int i = 0; i < numCast; i++){
		
		cout << "Enter cast member: " << endl;
		cin >> cast[i];
		
		iofile << cast[i] << " | ";

	}
}
void Movie::setRating(){
	fstream iofile;

	cout << "Enter rating: " << endl;
	cin >> rating;

	iofile.open("file.txt", ios::in|ios::out|ios::app);
	iofile << rating  << " | ";

}
void Movie::setCopies(){
	fstream iofile;
	
	cout << "Enter number of available copies: " << endl;
	cin >> copies;

	iofile.open("file.txt", ios::in|ios::out|ios::app);
	iofile << copies << " | " << endl;
}







