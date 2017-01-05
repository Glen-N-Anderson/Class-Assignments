/* CS261- Assignment 1 - Q.4*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct student{
	int id;
	int score;
};
/*sorts students based on their scores (ascending order)*/
void sort(struct student* students, int n){
     	/*Sort the n students based on their score*/     
     	/* Remember, each student must be matched with their original score after sorting */
	int i, j, temp, temp2;
	for(i = 0; i < n; i++){
                for(j = i + 1; j < n; j++){
                        if(students[i].score > students[j].score){
                                temp = students[i].score;
                                temp2 = students[i].id;
				students[i].score = students[j].score;
                                students[i].id = students[j].id;
				students[j].score = temp;
				students[j].id = temp2;
                        }
                }
        }





}

int main(){
    	/*Declare an integer n and assign it a value.*/
	int n = 10;
    	/*Allocate memory for n students using malloc.*/
	struct student *students;
	students = (struct student*) malloc(sizeof(struct student)*n);
    	/*Generate random IDs and scores for the n students, using rand().*/
    	int i;
	srand(time(NULL));
	for(i = 0; i < n; i++){
		students[i].id = rand() % 10 + 1;
		students[i].score = rand() % 101;
	}
    	/*Print the contents of the array of n students.*/
	printf("     UNSORTED SCORES:\n   ");
	for(i = 0; i < n; i++){
		printf("ID: %d   ", students[i].id);
		printf("Score: %d\n   ", students[i].score); 
	}
    	/*Pass this array along with n to the sort() function*/
	sort(students, n); 
    	/*Print the contents of the array of n students.*/
   	printf("  SORTED SCORES:\n   ");
	for(i = 0; i < n; i++){
		printf("ID: %d   ", students[i].id);
		printf("Score: %d\n   ", students[i].score);
	} 
    	return 0;
}
