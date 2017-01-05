/******************************************************
 **** Program: Assign 2: Netflix program 
 **** Author: Glen Anderson
 **** Date: 04/29/15 (late submission)
 **** Description: Takes info from user, puts into file, searches file for info
 **** Input: User input to be put into file, info from file
 **** Output: Info from file
 ********************************************************/



#include <iostream>
#include "./Netflix.h"
#include "./Movie.h"
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	int choice; 
	Movie mov;
	Netflix f;
	while(true){
	cout << "Would you like to find a movie or enter a movie? (1 - enter, 2 - find, 0 - exit): ";
	cin >> choice;
	if(choice == 1){
		mov.setNum();
		mov.setName();
		mov.setStars();
		mov.setNumCast();
		mov.setCast();
		mov.setRating();
		mov.setCopies();
	
	}

	else if(choice == 2){
		Netflix f;
		//f.setNumMovies();

		int decision;	
		cout << "How would you like to search? (1 - name, 2 - num stars,3 - specific cast member, 4 - rating) " << endl;
		
		cin >> decision;
		if(decision == 1){
			f.searchTitle();
		}
		else if(decision == 2){	
			f.searchTitle();
		}	
		
		else if(decision == 3){
			f.searchTitle();
		}	
		else if(decision == 4){
			f.searchTitle();
		}
		else{
			cout << "Invalid choice, quitting program." << endl;
			exit(0);
	
		}

	}
	else if(choice == 0){
		cout << "Thanks for using netflix!" << endl;
		exit(0);
	}	
	
	mov.getName();
        mov.getStars();
        mov.getNumCast();
        mov.getCast();
        mov.getRating();
        mov.getCopies();


	}	
	return 0;
}
/* set()
 * 	ask num movies
 * 	use for loop:
 * 		runs through each variable/stores in array of appropriate type
 * 		calls setter for each variable
 */

