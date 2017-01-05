#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int length(struct node* head){
	struct node* current = head;
	int count = 0;
	
	while(current != NULL){
		count++;	
		current = current->next;
	}
	return count;


}
void push(struct node ** headRef, int val){ //add to front of list
	struct node* newNode = malloc(sizeof(struct node));
	newNode->val = val;
	newNode->next = *headRef;
	*headRef = newNode;
	

} 
void append(struct node ** headRef, int num){ //add to back of list
	struct node* current = *headRef;
	struct node* newNode;

	newNode = malloc(sizeof(struct node));
	newNode->val = num;
	newNode->next = NULL;

	//for len 0
	if(current == NULL){
		*headRef = newNode;
	}
	else{
		//Locate the last node
		while(current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}

} 
void print(struct node *head, int len){
	int i = 0;
	for(i = 0; i < len; i++){
		printf("Value: %d\n", *head);
		head = head->next;
	}		
}

