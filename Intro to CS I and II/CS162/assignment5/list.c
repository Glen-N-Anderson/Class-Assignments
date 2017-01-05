#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*length() function:
 * Input: head pointer
 * Output: Length of the linked list
 * Purpose: Get the length of the linked list created by user
 */


int length(struct node* head){
	struct node* current = head;
	int count = 0;
	
	while(current != NULL){
		count++;	
		current = current->next;
	}
	return count;


}
/*push() function:
 * Input: Head reference, number the user enters
 * Output: None
 * Purpose: Add number to front of list
 */

struct node* push(struct node ** headRef, int val){ //add to front of list
	struct node* newNode = malloc(sizeof(struct node));
	newNode->val = val;
	newNode->next = *headRef;
	*headRef = newNode;
	

} 
/*append() function:
 * Input: Head reference, number the user enters
 * Output: None
 * Purpose: Add number to back of list
 */
struct node* append(struct node ** headRef, int num){ //add to back of list
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
/*print() function:
 * Input: Head pointer
 * Output: All values in the linked list
 * Purpose: Print out the linked list 
 */
void print(struct node *head){
	while(head != NULL){	
		printf("Value: %d\n", *head);
		head = head->next;
	}		
}
/*clear() function:
 * Input: Head reference
 * Output: None
 * Purpose: free entire linked list
 */
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
/*sort_ascending() function:
 * Input: Head pointer
 * Output: None
 * Purpose: Sort linked list in ascending order (least to greatest)
 */
struct node* sort_ascending(struct node* head){
	int i;
	bool s;
	struct node* ptr1;
	struct node* end = NULL;//checks for end of list

	do{
		s = false;
		ptr1 = head;

		while(ptr1->next != end){
			if(ptr1->val > ptr1->next->val){
				swap(ptr1, ptr1->next);
				s = true;
			}
			ptr1 = ptr1->next;
		}
		end = ptr1->next;
	}
	while(s);
		
}
/*swap() function
 * Input: node pointers from sort functions
 * Output: None
 * Purpose: swap values according to sort functions (helper function for sort functions)
 */
void swap(struct node *a, struct node *b){
	int tempPtr = a->val;
	a->val = b->val;
	b->val = tempPtr;
}
/*sort_descending() function:
 * Input: Head pointer
 * Output: None
 * Purpose: Sort linked list in descending order (greatest to least)
 */
struct node* sort_descending(struct node* head){
	int i;
        bool s;
        struct node* ptr1;
        struct node* end = NULL;//checks for end of list

        do{
                s = false;
                ptr1 = head;

                while(ptr1->next != end){
                        if(ptr1->val < ptr1->next->val){
                                swap(ptr1, ptr1->next);
                                s = true;
                        }
                        ptr1 = ptr1->next;
                }
                end = ptr1->next;
        }
        while(s);

}
/*insert_middle() function:
 * Input: Head reference, number from user, location in list
 * Output: Will print not in range if user enters bad value
 * Purpose: Insert a node into the nth location of linked list
 */
struct node* insert_middle(struct node** headRef, int num, int loc){
	int i;
	for(i = 0; *headRef!=NULL && i < loc; ++i){
		headRef = &((*headRef)->next);
	}
	if(i == loc){
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->val = num;
		temp->next = *headRef;
		*headRef = temp;
	}		

	else{
		printf("Not in range of list!\n");

	}
}
/*removeNode() function:
 * Input: Head pointer, number to be removed (rm)
 * Output: None
 * Purpose: Free individual node at nth location specified by user
 */
struct node* removeNode(struct node* head, int rm){
	struct node* temp1 = head;
	struct node* n = head->next->next;
	int i, count;
	
	if(rm == 1){
		head->val = head->next->val;
		n = head->next;
		head->next = head->next->next;
		free(n);
		
		return;
	}
	for(i = 0; i < rm - 2; i++){
		temp1 = temp1->next;
	}
	struct node* temp2 = temp1->next;
	temp1->next = temp2->next;
	free(temp2);
	
}	
