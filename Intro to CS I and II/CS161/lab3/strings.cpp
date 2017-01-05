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

using namespace std;


int main() {
	string message;

	cout << "Enter a message to see text information: " << endl;
	cin >> message;

	cout << "Length of message: " << message.length() << endl;

	cout << "First character in message: " << message.at(0) << endl;

	for(int i = 0; i < message.length(); i++){
		cout << message.at(i) << endl;
	}


	return 0;
}

