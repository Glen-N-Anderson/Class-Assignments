/******************************************************
 **** Program: 
 **** Author: 
 **** Date:
 **** Description: 
 **** Input:
 **** Output:
 ********************************************************/



#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


struct netflix{
	string name;
	int stars;
	char *cast; //dynamic array
	string rating;
};

void get_user_input(netflix &movie);
void print_info(netflix movie, int cn);

int main() {
	netflix movie;
	get_user_input(movie);
	return 0;
}
void get_user_input(netflix &movie){
	int cn, cns;
	cout << "Enter name of movie: ";
	cin >> movie.name; 
	cout << "How many cast members are there? ";
	/*do{
		cout << "Enter int for cast members: ";
		cin >> cn;
	}
	while()*/
	cin >> cn;
	cns = cn * 20;
	
	movie.cast = new char [cns];
	for(int i = 0; i < cn; i++){
		cout << "Enter cast member " << i + 1 << ": " << endl;
		cin >> movie.cast[i];	

	}
	cout << "How many stars? ";
	cin >> movie.stars;
	
	cout << "Enter the movie rating (G, PG, etc.): ";
	cin >> movie.rating;
	
	print_info(movie, cn);

}
void print_info(netflix movie, int cn){
	cout << "Your movie entry is: " << endl;
	cout << "Title: " << movie.name << endl;
	cout << "Stars: " << movie.stars << endl;
	for(int i = 0; i < cn; i++){
		cout << "Cast: " << *movie.cast  << endl;
	}
	cout << "Rating: " << movie.rating << endl;	
	
	char decision;
        cout << "Do you want to enter a movie to the database?(y/n) ";
        cin >> decision;
        if(decision == 'y'){
                get_user_input(movie);
        }
        else{
                exit(0);
        }
	

}
