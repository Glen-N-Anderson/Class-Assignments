/******************************************************
 * ** Program: assignment1.cpp
 * ** Author: Glen Anderson
 * ** Date: 1/16/2015
 * ** Description: Prints signed/unsigned values of int,short,long. Converts character to decimal,binary, hexadecimal.
 * ** Input:User inputs character in second part of program.
 * ** Output:Printed values of signed/unsigned int,short,long. Printed values of input in decimal,bindary,hexadecimal. 
 * ******************************************************/

#include <iostream> 
#include <cmath>
#include <climits> 

using namespace std;

int main() {
	int maxint,minint;
	unsigned int umaxint,uminint;
	short shrt,minshrt;
	unsigned short ushrt,minushrt;
	long maxlong,minlong;
	unsigned long umaxlong,uminlong;
	
	shrt = (pow(2, (sizeof(short))*8-2)-1)*2+1;
	minshrt = pow(2, sizeof(short)*8-1)*-1;
	
	ushrt = pow(2, sizeof(unsigned short)* 8)-1;
	minushrt = 0; 

	maxint = pow(2, sizeof(int)*8-1)-1;
	minint =(pow(2, sizeof(int)*8-1)-1)*-2;
	
	umaxint = pow(2, sizeof(unsigned int)*8)-1;
	uminint = 0;
	
	
	maxlong = pow(2, sizeof(long)*8-1)-1;
	minlong = -1 *(pow(2, sizeof(long)* 8-1))-1;


	umaxlong = pow(2, sizeof(unsigned long)*8)-1;
	uminlong = 0;
	
	cout << SHRT_MAX << endl;
	cout << "Max for signed short: " << shrt << endl;
	
	cout << SHRT_MIN << endl;
	cout << "Min for signed short: " << minshrt << endl;
	
	cout << USHRT_MAX << endl;
	cout << "Max for unsigned short: " << ushrt << endl;
	
	cout << "Min for unsigned short: " << minushrt << endl;
	
	cout << INT_MAX << endl;
	cout << "Max for signed int: " << maxint << endl;
	
	cout << INT_MIN << endl;
	cout << "Min for signed int: " << minint << endl;
	
	cout << UINT_MAX << endl;
	cout << "Max for unsigned int: " << umaxint << endl;

	cout << "Min for unsigned int: " << uminint << endl;

	cout << LONG_MAX << endl;
	cout << "Max for signed long: " << maxlong << endl;

	cout << LONG_MIN << endl;
	cout << "Min for signed long: " << minlong << endl;
	
	cout << ULONG_MAX << endl;
	cout << "Max for unsigned long: " << umaxlong << endl;
	
	cout << "Min for unsigned long: " << uminlong << endl;


// character to decimal/binary/hexadecimal
	int contains,input;
	cout << "Enter a character: ";
	cin >> input;
	
	cout << input << endl;	
	cout << hex << input << endl;
	cout << dec << input << endl;
	
	contains = input/pow(2,7);
	input = input-pow(2,7) * contains;	
	cout << contains;
	contains = input/pow(2,6);
        input = input-pow(2,6) * contains;
        cout << contains;
	contains = input/pow(2,5);
        input = input-pow(2,5) * contains;
        cout << contains;
	contains = input/pow(2,4);
        input = input-pow(2,4) * contains;
        cout << contains;
	contains = input/pow(2,3);
        input = input-pow(2,3) * contains;
        cout << contains;
	contains = input/pow(2,1);
        input = input-pow(2,1) * contains;
        cout << contains;
	contains = input/pow(2,0);
        input = input-pow(2,0) * contains;
        cout << contains << endl;

        
	return 0;
}



