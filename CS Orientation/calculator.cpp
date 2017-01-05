#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string op;
	float num1, num2, answer;
	cout <<"Enter operation(+, -, /, *, ^, %): ";
	cin >> op;
	cout <<"Enter first number: ";
	cin >> num1;
	cout <<"Enter second number: ";
	cin >> num2;
	
	if(op == "^"){
		answer = pow(num1,num2);
		cout << answer << endl;
	}
	else if(op == "%"){
		answer = fmod(num1,num2);
		cout << answer << endl;
	}
	else if(op == "+"){
		answer = num1 + num2;
		cout << answer << endl;
	}
	else if(op == "-"){
		answer = num1 - num2;
		cout << answer << endl;
	}
	else if(op == "/"){
		answer = num1 / num2;
		cout << answer << endl;
	}
	else if(op == "*"){
		answer = num1 * num2;
		cout << answer << endl;
	}
	

	return 0;
}


				

