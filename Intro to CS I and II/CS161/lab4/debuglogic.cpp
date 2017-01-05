#include <iostream>
#define PROMPT "Please enter a whole number:"
#define NOT_PRIME "The number is not a prime number"
#define PRIME "The number is a prime number"
#define DONE 0 /* ends successful program */
#define FIRST_FACTOR 2 /* initial value in for loop */
using namespace std; //this is just simpler
int main(){
	int i, x= 0, number; /* loop counter */
	cout << PROMPT; /* promt user */
	cin >> number; /* wait for user input */
 /* Prime numbers are defined as any number
 *  * greater than one that is only divisible
 *   * by one and itself. Dividing the number
 *    * by two shortens the time it takes to
 *     * complete. */
	for(i = FIRST_FACTOR; i < (number-1); ++i) { //should have brackets, / does integer division, use postincrement though
		//cout << number << endl;
		if(number % i == 0 ){ /* if divisible */ //modular division might be more successful
			x = 1;  /* not prime */
			 /* exit program */
		}
	}	
		if(x == 1){
			cout << NOT_PRIME << endl;
		}

		else{
			//cout << number << endl;
			cout << PRIME << endl;
		}
	
 // if not divisible by anything, then it must be prime
 //  cout << PRIME << number;
 //   return 0; /* exit program */
	return 0;
}
