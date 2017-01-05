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
#include <cmath>
using namespace std;


void hundreds(int &num, string &roman);
void thousands();
void tens(int &num, string &roman);
void ones(int &num, string &roman);
void roman_to_dec();


int main() {
thousands();
roman_to_dec();
	return 0;
}

void thousands(){
	int num, chunk;
	string roman;
	cout << "Enter a num to be converted to roman numerals: " << endl;
	cin >> num;

	 if(num >= 1000){
                        chunk = (num / 1000);

                        for(int i = 0; i < chunk; i++){
                                roman += 'M';
                        }
                }
                num %= 1000;
	hundreds(num, roman);
}
void hundreds(int &num, string &roman){
	int chunk;
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
	tens(num, roman);
}
void tens(int &num, string &roman){
		int chunk;
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
	ones(num, roman);

}
void ones(int &num, string &roman){
		int chunk;
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

void roman_to_dec(){
	int decimal;
	string roman_input; 
	cout << "Enter a roman numeral: " << endl;
        cin >> roman_input;


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
                                if (roman_input.at(j+1) == 'D' ||roman_input.at(j+1) == 'M'){
                                        decimal -= 100;
                                        break;
                                }
                                else{
                                        decimal += 100;
                                        break;
                                }

                        case('L'):
                                if(roman_input.at(j+1) == 'C' || roman_input.at(j+1) =='D' ||roman_input.at(j+1) == 'M'){
                                        decimal -= 50;
                                        break;
                                }
                                else{
                                        decimal += 50;
                                        break;
                                }
 case('X'):
                                if(roman_input.at(j+1) == 'L' ||roman_input.at(j+1) == 'C' ||roman_input.at(j+1) == 'D' ||roman_input.at(j+1) == 'M'){
                                        decimal -= 10;
                                        break;
                                }
                                else{
                                        decimal += 10;
                                        break;
                                }

                        case('V'):
                                if(roman_input.at(j+1) == 'X' ||roman_input.at(j+1) == 'L' ||roman_input.at(j+1) == 'C' ||roman_input.at(j+1) == 'D' ||roman_input.at(j+1) == 'M'){
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
}
