/* CS261- Assignment 1 - Q. 0*/
/* Name: Glen Anderson
 * Date: 10/08/15
 * Solution description: Prints adresses and values of x and iptr.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     	/*Print the value pointed to by iptr*/
	printf("Value pointed to by iptr: %d\n", *iptr); 
     	/*Print the address pointed to by iptr*/
	printf("Address pointed to by iptr: %p\n", iptr);     
     	/*Print the address of iptr itself*/
	printf("Address of iptr: %p\n", &iptr);
}

int main(){
    
    	/*declare an integer x*/
	int x;
	    
    	/*print the address of x*/
	printf("Address of x: %p\n", &x);    
    	/*Call fooA() with the address of x*/
	fooA(&x);    
    	/*print the value of x*/
	printf("Value of x: %d\n", x);
    	return 0;
}
