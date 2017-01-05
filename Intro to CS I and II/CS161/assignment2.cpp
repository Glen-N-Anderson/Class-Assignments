/******************************************************
 **** Program: Assignment 2 
 **** Author: Glen Anderson
 **** Date: 01/26/15
 **** Description: Converts string to binary, binary to string
 **** Input: string_input, binary_input (from user) 
 **** Output: letters (string of letters from the binary input), in_there (binary from the characters input)
 ********************************************************/



#include <iostream>
#include <string> 
#include <cmath> 
#include <stdlib.h>

using namespace std;

int main() {
	string string_input, binary_input, letters;
	int i, in_there, x, num, z, change;
	cout << "Enter a string of characters to be converted into binary: " << endl;
	getline(cin, string_input); //gets user input

	for(int i = 0; i < string_input.length(); i++){ //start at 0, increment by one each time for the length of input
		x = string_input.at(i);	
		for(int j = 7; j >= 0; j--){	
			in_there = x / pow(2, j);
			x = x - pow(2, j) * in_there;
			
			cout << in_there << "";	
		}
	}
	cout << endl; //just to make it look nice
	cout << "Enter binary to be converted to characters: ";
	getline(cin, binary_input);
	
	for(int i = 0; i < binary_input.length(); i++){
		if(!(binary_input.at(i) == '0' or binary_input.at(i) == '1')){
			cout << "You entered invalid input!" << endl;
			exit(0);
		}
	}

	for(int i = 0; i < binary_input.length(); i += 8){

		change = 0;
		for(int z = 0; z < 8; z++){
			if(binary_input.at(z+i) == '1'){
				num = pow(2, (7 - z));
				change = change + num;
				}
			else if(binary_input.at(z) == '0'){
					change;
			}
		}
	        
		cout << (char) change << "";		
	}	
        cout << endl;
	

	return 0;
}

