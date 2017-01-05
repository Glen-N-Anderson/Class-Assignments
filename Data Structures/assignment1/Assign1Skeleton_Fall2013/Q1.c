/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description: Fills 2 arrays with unique IDs and scores of students, then prints them
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
struct student{
	int id;
	int score;
};

struct student* allocate(){
     	/*Allocate memory for ten students*/
	struct student *ptr;
	ptr = (struct student*) malloc(sizeof(struct student)*10);//mem for 10 students     
     	/*return the pointer*/
	return ptr;
}
/*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
void generate(struct student* students){
	int i, r, j = 0;
	//generate unique IDs
	srand(time(NULL));
	students[0].id = rand() % 10 + 1;
	for(i = 0; i < 10; i++){
		r = rand() % 10 + 1;
		for(j = 0; j < i; j++){
			if(r == students[j].id){
				i--;
				break;
			}
			else if(r != students[j].id) {
				students[i].id = r;
			}
		}	
	}
	//generate scores
	for(i = 0; i < 10; i++){
		students[i].score = rand() % 100 + 1;

	}
}	

/*Output information about the ten students*/
void output(struct student* students){
	int i;
	for(i = 0; i < 10; i++){
		printf("IDs: %d", students[i].id);
		printf("   Scores: %d\n", students[i].score);

	}

}

void summary(struct student* students){
     	/*Compute and print the minimum, maximum and average scores of the ten students*/
	int i, j, temp = 0;
	
	for(i = 0; i < 10; i++){
		for(j = i + 1; j < 10; j++){
			if(students[i].score > students[j].score){
				temp = students[i].score;
				students[i].score = students[j].score;
				students[j].score = temp;
			}
		}
	}
	float sum = 0, average = 0;
	for(i = 0; i < 10; i++){
		sum += students[i].score;
	}
	
	average = (sum/10.0);
	
	printf("Minimum score: %d\n", students[0].score);
        printf("Maximum score: %d\n", students[9].score);
	printf("Average score: %.6f\n", average);
}

void deallocate(struct student* stud){
     	if(stud != NULL){
		free(stud);
	}
	/*Deallocate memory from stud*/
}

int main(){
	struct student* stud= NULL;
   	 
	/*call allocate*/
	stud = allocate();    
	/*call generate*/
	generate(stud);   
	/*call output*/
 	output(stud);   
        /*call summary*/
    	summary(stud);
        /*call deallocate*/
	deallocate(stud);
    	return 0;
}
