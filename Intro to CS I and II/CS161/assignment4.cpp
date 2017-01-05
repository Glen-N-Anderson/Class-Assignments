/******************************************************
 **** Program: Assignment #4
 **** Author: Glen Anderson
 **** Date: 02/06/15
 **** Description: Takes binary string, converts to chars, takes string of chars, converts to binary
 **** Input: binary_input (binary input from user), string_input (input of chars from user)
 **** Output: String of chars, string of binary (conversions of input)
 ********************************************************/



#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

void check_bin_number(char *s);
void bin_to_ascii(char *s);
void ascii_to_bin(char *string_input);

				

/*********************************************************************
 *** Function: void check_bin_number
 *** Description: Checks validity of binary input
 *** Parameters: char *s
 *** Pre-Conditions: Command line must be enterted correctly
 *** Post-Conditions: Binary input must be valid
 **********************************************************************/ 				
void check_bin_number(char *s){

	
	
	for(int i = 0; i < strlen(s); i++){
		while(s[i] !='1' && s[i] != '0' || strlen(s) % 8 != 0){
			cout << "Error: Invalid binary input!" << endl;
			//cout << "Enter valid binary input (1s and 0s only, length divisible by 8): " << endl;
			//getline(cin,s);
			exit(0);					
		}	
	}
	bin_to_ascii(s);
}
	
	



/*********************************************************************
 *** Function: void ascii_to_bin
 *** Description: Takes ascii input and converts to binary
 *** Parameters: char *string_input
 *** Pre-Conditions: String input must be entered in command line, must be valid
 *** Post-Conditions: None
 **********************************************************************/ 
void ascii_to_bin(char *string_input){
	
	
	for(int i = 0; i < strlen(string_input); i++){ 
                int x = string_input[i];
                for(int j = 7; j >= 0; j--){
                       int in_there = x / pow(2, j);
                        x = x - pow(2, j) * in_there;

                        cout << in_there << "";
                }
	}
	cout << "" << endl;
	
}

/*********************************************************************
 *** Function: void bin_to_ascii
 *** Description: Takes binary as input, converts it to ascii
 *** Parameters: char *s (binary input)
 *** Pre-Conditions: Binary value must be passed from check_bin_number, must be valid
 *** Post-Conditions: None
 **********************************************************************/ 
void bin_to_ascii(char *s){
	
	
	
	for(int i = 0; i < s[i]; i += 8){
		int change = 0;
                for(int z = 0; z < 8; z++){
                        if(s[z+i] == '1'){
                                int num = pow(2, (7 - z));
                                change = change + num;
                                }
                        else if(s[z] == '0'){
                                        change;
                        }
                }
         
		cout << (char) change << "";
        }
	cout << "" << endl;
	return;
}



/*********************************************************************
 *** Function: int main
 *** Description: Takes command line input, checks for error, passes input to appropriate function
 *** Parameters: int argc, char *argv[]
 *** Pre-Conditions: None
 *** Post-Conditions: Command line must be valid for value to be passed
 **********************************************************************/ 

int main(int argc, char *argv[]) {
	
	if(strcmp(argv[1], "-a") == 0){
		ascii_to_bin(argv[2]);
	}
	else if(strcmp(argv[1], "-b") == 0){
		check_bin_number(argv[2]);
	
	}
	else{
		cout << "Input error" << endl;
		exit(0);
	}
	
	if(strcmp(argv[3], "-a") == 0){
		ascii_to_bin(argv[4]);
	}
	else if(strcmp(argv[3], "-b") == 0){	
		check_bin_number(argv[4]);
	}
	else{
		cout << "Input error" << endl;
		exit(0);
	}
	
	
	
	
		
	return 0;
}

