/******************************************************
 **** Program: Final Project CS 162, merge-sort algorithm
 **** Author: Glen Anderson
 **** Date: 06/09/2015
 **** Description: Runs the merge sort algorithm on a list supplied by user 
 **** Input: Numbers from user to add onto list to be sorted
 **** Output: Prints sorted list of numbers
 ********************************************************/

struct node* push(struct node ** headRef, int val);
struct node* clear(struct node **headRef);
void print(struct node *head);

#include <stdlib.h>
#include <stdio.h>
#include "merge.h"
int main() {
	struct node *head = NULL;
	struct node *last = NULL;

	int num;
	char ans;
	do{
		do{
			printf("Enter a number to add to list: ");
			scanf("%d", &num);	
			
			push(&head, num);//add users input to front of the list as long as they continue to enter numbers		
	
			printf("Do you want to enter another number (y or n)?: ");
			scanf("%1s", &ans); 
		} while(ans == 'y');
	
	mergeSort(&head, &last); //call mergeSort to begin the algorithm
	print(head); //print out the final list after the algorithm is completed		
	printf("Do you want to do this again (y or n)? ");
	scanf("%1s", &ans);
	if(ans == 'y'){
		clear(&head); //call clear if user wants to re-run the program, to avoid any memory leaks
	}
	} while(ans == 'y');
	

	return 0;
}
/*push() function:
 *  * Input: Head reference, number the user enters
 *   * Output: None
 *    * Purpose: Add number to front of list
 *     */

struct node* push(struct node ** headRef, int info){ //add to front of list
        struct node* newNode = malloc(sizeof(struct node));
        newNode->info = info;
        newNode->next = *headRef;
        *headRef = newNode;


}
/*clear() function:
 *  * Input: Head reference
 *   * Output: None
 *    * Purpose: free entire linked list
 *     */
struct node* clear(struct node **headRef){
        struct node* current = *headRef;
        struct node* next;
        while(current != NULL){
                next = current->next;
                free(current);
                current = next;
        }
        *headRef = NULL;

}
/*print() function:
 *  * Input: Head pointer
 *   * Output: All values in the linked list
 *    * Purpose: Print out the linked list
 *     */
void print(struct node *head){
        while(head != NULL){
                printf("Value: %d\n", *head);
                head = head->next;
        }
}

