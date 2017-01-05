/******************************************************
 **** Program: Assignment #3
 **** Author: Glen Anderson
 **** Date: 02/06/15
 **** Description: Takes binary string, converts to chars, takes string of chars, converts to binary
 **** Input: binary_input (binary input from user), string_input (input of chars from user)
 **** Output: String of chars, string of binary (conversions of input)
 ********************************************************/



#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void check_bin_number(string &s);
void bin_to_ascii(string &s);
void ascii_to_bin(string &string_input);

void get_user_input(string &b, string &s){
				
	cout << "Enter a string to be converted to binary: " << endl;
	getline(cin, s);
	
	cout << "Enter binary to be converted to a string of chars: " << endl;
	getline(cin, b);
	
	check_bin_number(b);	
	return;	
	 
}
				
void check_bin_number(string &s){

	
	
	for(int i = 0; i < s.length(); i++){
		while(s.at(i) !='1' && s.at(i) != '0' || s.length() % 8 != 0){
			cout << "Error: Invalid binary input!" << endl;
			cout << "Enter valid binary input (1s and 0s only, length divisible by 8): " << endl;
			getline(cin,s);
								
		}	
	}
	bin_to_ascii(s);
}
	
	




void ascii_to_bin(string &string_input){
	
	
	for(int i = 0; i < string_input.length(); i++){ 
                int x = string_input.at(i);
                for(int j = 7; j >= 0; j--){
                       int in_there = x / pow(2, j);
                        x = x - pow(2, j) * in_there;

                        cout << in_there << "";
                }
	}
	cout << "" << endl;
	
}
void bin_to_ascii(string &s){
	
	
	
	for(int i = 0; i < s.length(); i += 8){
		int change = 0;
                for(int z = 0; z < 8; z++){
                        if(s.at(z+i) == '1'){
                                int num = pow(2, (7 - z));
                                change = change + num;
                                }
                        else if(s.at(z) == '0'){
                                        change;
                        }
                }
         
		cout << (char) change << "";
        }
	cout << "" << endl;
	return;
}





int main() {
	
	string binary_input, string_input;
	get_user_input(binary_input, string_input);
	ascii_to_bin(string_input);
	
		
	return 0;
}

