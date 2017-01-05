/******************************************************
 **** Program: 
 **** Author: 
 **** Date:
 **** Description: 
 **** Input:
 **** Output:
 ********************************************************/



#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int decimal = 0;
	string roman_input;
	
	i = 1;
	v = 5;
	x = 10;
	l = 50;
	c = 100;
	d = 500;
	m = 1000;
	
	cout << "Enter a roman numeral: " << endl;
	getline(cin, roman_input);
	
	
	for(int j = 0; j < roman_input.length(); j++){
		switch(roman_input.at(j)){
			case('M'):
				decimal += 1000;
					
			case('D'):
				if(roman_input.at(j+1) == 'M'){
					decimal -= 500;
					break;
				}
				else{
					decimal += 500;
					break;
				}
			
			case('C'):
				if (roman_input.at(j+1) == 'D' || 'M'){
					decimal -= 100;
					break;
				}
				else{
					decimal += 100;
					break;
				}
			
			case('L'):
				if(roman_input.at(j+1) == 'C' || 'D' || 'M'){
					decimal -= 50;
					break;
				}
				else{
					decimal += 50;
					break;
				}
			case('X'):
				if(roman_input.at(j+1) == 'L' || 'C' || 'D' || 'M'){
					decimal -= 10;
					break;
				}
				else{
					decimal += 10;
					break;
				}

			case('V'):
				if(roman_input.at(j+1) == 'X' || 'L' || 'C' || 'D' || 'M'){
					decimal -= 5;
					break;
				}
				else{
					decimal += 5;
					break;
				}
			case('I'): 
				if(roman_input.at(j+1) != 'I' && roman_input.at(j+1) != roman_input.length()){
					decimal -= 1;
					break;
				}
				else{
					decimal += 1;
				break;
				}			


			
		cout << decimal << endl;
		}
				
	}	
	
	//code to convert from decimal to roman
	
	string roman;
	int num;
	int chunk;

	cout << "Enter num to be converted to roman numerals: " << endl;
	cin >> num;

	if(num >= 4000){
		cout << "Invalid input" << endl;
	}
	else{
		if(num >= 1000){
			chunk = (num / 1000); //gives number of thousands, because integer division
			
			for(int i = 0; i < chunk; i++){
				roman += 'M';
			}	
		}
		num %= 1000;
		if(num >=100){
			chunk = num / 100;
			if(chunk == 9){
				roman += "CM";
			}
			else if(chunk >= 5) {
				roman += 'D';
				for(int i = 0; i < chunk - 5; i++){
					roman += 'C';
				}
			}
			else if(chunk == 4) {
				roman += "CD";
			}
			else if(chunk >=1){
				for(int i = 0; i < chunk; i++){
					roman += 'C';
				}
			}
			num %= 100;
		}

		if(num >= 10){
			chunk = num / 10;
			if (chunk == 9){
				roman += "XC";
			}
			else if (chunk >= 5){
				roman += 'L';
				for(int i = 0; i < chunk - 5; i++){
					roman += 'X';
				}
			}
			else if (chunk == 4){
				roman += "XL";
			}
			else if (chunk >= 1){
				for(int i = 0; i < chunk; i++){
					roman += 'X';
				}
			}
			num %= 10;
		}
		if(num >= 1) {
			chunk = num;
			if (chunk == 9){
				roman += "IX";
			}
			else if (chunk >= 5){
				roman += "V";
				for(int i = 0; i < chunk - 5; i++){
					roman += 'I';
				}
			}		
			else if(chunk == 4) {
				roman += "IV";
			}
			else if(chunk >= 1){
				for (int i = 0; i < chunk; i++){
					roman += 'I';
				}
			}
		}
		cout << "Roman numeral of decimal is: " << roman << endl;	
				


	}

	return 0;
}

