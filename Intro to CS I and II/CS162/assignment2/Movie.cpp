#include <iostream>
#include <string>
#include "./Movie.h"
#include <fstream>
#include <climits>
using namespace std;

Movie::Movie(){ //default constructor, sets all variables to null
	num = 0;
	stars = 0;
	numCast = 0;
	copies = 0;

}
Movie::~Movie(){
	delete [] cast;
}

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
	fstream iofile;
	
	num == 1;
	num += 1;

	iofile.open("netflix.dat", ios::in|ios::out|ios::app);
	iofile << num << "|";
}
void Movie::setName(){
	fstream iofile;
	
	cout << "Enter name of movie: " << endl;
	cin >> name;
	
	iofile.open("netflix.dat", ios::in|ios::out|ios::app); //append to file
	iofile << name << "|";

}
void Movie::setStars(){
	fstream iofile;
	while(1){	//check for valid positive integer
		cout << "Enter number of stars: " << endl;
		cin >> stars;
		
		if(cin.good()){
			if(stars < 0){
				cout << "Negative num! re-enter." << endl;
			}
			else if(stars > 5){
				cout << "Stars are 0-5 only!" << endl;		
			}

			else{
				break;
			}
		}
		else{
			cout << "Not an integer" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}	

	iofile.open("netflix.dat", ios::in|ios::out|ios::app);
	iofile << stars << "|";
}
void Movie::setNumCast(){
	fstream iofile;
	
	while(1){
                cout << "Enter number of cast: " << endl;
                cin >> numCast;

                if(cin.good()){
                        if(numCast < 0){
                                cout << "Negative num! re-enter." << endl;
                        }
                        else{
                                break;
                        }
                }
                else{
                        cout << "Not an integer" << endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                }
        }

	iofile.open("netflix.dat", ios::in|ios::out|ios::app);
	iofile << numCast << "|";
}
void Movie::setCast(){
	fstream iofile;
	iofile.open("netflix.dat", ios::in|ios::out|ios::app);
	cast = new string[numCast];
	for(int i = 0; i < numCast; i++){
		
		cout << "Enter cast member: " << endl;
		cin >> cast[i];
		
		iofile << cast[i] << "|";

	}
}
void Movie::setRating(){
	fstream iofile;

	cout << "Enter rating: " << endl;
	cin >> rating;

	iofile.open("netflix.dat", ios::in|ios::out|ios::app);
	iofile << rating  << "|";

}
void Movie::setCopies(){
	fstream iofile;
	
	while(1){
                cout << "Enter number of copies: " << endl;
                cin >> copies;

                if(cin.good()){
                        if(copies < 0){
                                cout << "Negative num! re-enter." << endl;
                        }
                        else{
                                break;
                        }
                }
                else{
                        cout << "Not an integer" << endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                }
        }

	iofile.open("netflix.dat", ios::in|ios::out|ios::app);
	iofile << copies << "|" << endl;
}







