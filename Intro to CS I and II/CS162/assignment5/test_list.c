/******************************************************
 * ** Program: test_list.c
 * ** Author: Glen Anderson
 * ** Date: 06/07/2015
 * ** Description: Creates a linked list through pushing, appending, and specifying location then sorts in ascending or descending order
 * ** Input: Number from user to add to list, location from user to add a number or remove a number
 * ** Output: Prints complete sorted list
 * ******************************************************/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
int main (){
	char ans, choice;
	int num, loc, rm;
	struct node *head = NULL;
	do{
		do {
			printf("Push(a), append(b), enter location(c), or remove(d)?: ");
			scanf("%1s", &choice);
			if(choice != 'd'){
			printf("Enter a number: ");
			scanf("%d", &num);
			}
			if(choice == 'a'){
				push(&head, num);
			}
			else if(choice == 'b'){
				append(&head, num);
			}
			else if(choice == 'c'){
				printf("Enter location to add num: ");
				scanf("%d", &loc);
				insert_middle(&head, num, loc-1);
			}
			else if(choice == 'd'){
				printf("Enter location to remove num: ");
				scanf("%d", &rm);
				removeNode(head, rm);
			}
			printf("Do you want another num (y or n): ");
			scanf("%1s",&ans);
		} while(ans=='y');

	printf("Sort ascending (a), descending (d), or no sort(n) (a, d, n)? ");
	scanf("%1s",&ans);
	if(ans == 'a'){ 
		sort_ascending(head);
	}
	else if(ans == 'd'){
		sort_descending(head);
	}
	print(head);
	printf("Do you want to do this again (y or n)? ");
	scanf("%1s",&ans);
	if(ans == 'y'){ 
		clear(&head);
	}
	
	} while(ans == 'y');
	return 0;
}
