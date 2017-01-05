/* CS261- Assignment 1 - Q.3*/
/* Name: Glen Anderson
 * Date: 10/08/15
 * Solution description: Fills an array with 20 random numbers, then sorts them in ascending order. 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Sorts array of numbers(bubble sort)*/
void sort(int* number, int n){
	int i, j, temp;
	for(i = 0; i < n; i++){	
		for(j = i + 1; j < n; j++){
			if(number[i] > number[j]){
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}     
	}
	/*Sort the given array number , of length n*/     


}

int main(){
    	/*Declare an integer n and assign it a value of 20.*/
	int n = 20, i, j;    
    	/*Allocate memory for an array of n integers using malloc.*/
    	int *array; 
	array = (int*) malloc(sizeof(20));
    	/*Fill this array with random numbers between 0 and n, using rand().*/
    	srand(time(NULL));
	printf("Unsorted array: \n");
	for(i = 0; i < n; i++){
		array[i] = rand() % n;
		printf("%d\n", array[i]);
	}
    	/*Print the contents of the array.*/

    	/*Pass this array along with n to the sort() function.*/
    	sort(array, n);
    	/*Print the contents of the sorted array.*/    
	printf("Sorted array: \n");
	for(j = 0; j < n; j++){
		printf("%d\n", array[j]);
	}   
    	return 0;
}
