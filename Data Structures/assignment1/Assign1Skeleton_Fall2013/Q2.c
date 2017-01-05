/* CS261- Assignment 1 - Q.2*/
/* Name: Glen Anderson
 * Date: 10/08/15
 * Solution description: Modifies 2 values and modifies a copy of another.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    	/*Set a to double its original value*/
 	*a = *a * 2;	   
    	/*Set b to half its original value*/
    	*b = *b / 2;
    	/*Assign a+b to c*/
    	c = *a + *b;
    	/*Return c*/
	return c;
}

int main(){
    	/*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
	int x = 7, y = 8, z = 9;
	int value;    
    	/*Print the values of x, y and z*/
    	printf("Value of x: %d\n", x);
    	printf("Value of y: %d\n", y);
	printf("Value of z: %d\n", z);


	/*Call foo() appropriately, passing x,y,z as parameters*/
	value = foo(&x, &y, z);    	
    	/*Print the value returned by foo*/
   	printf("Value returned by foo: %d\n", value); 
    	/*Print the values of x, y and z again*/
 	printf("Value of x: %d\n", x);
        printf("Value of y: %d\n", y);
        printf("Value of z: %d\n", z);
    
	return 0;
}
    
/*Is the return value different than the value of z?  Why?*/

        /*Yes, the return value is different because c is a shallow copy of z, and is not able to change the value of
 *  *      of c. x and y could change, because the value at their memory locations were modified (they were not just copies).
 *   */
    
