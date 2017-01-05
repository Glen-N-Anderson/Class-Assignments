#include <stdlib.h>
#include "./merge.h"
#define nullptr NULL

void divideList(struct node* first1,struct node** first2)
{
   struct node* middle;
   struct node* current;
   if (first1 == nullptr)  //list is empty
      *first2 = nullptr;
   else if (first1->next == nullptr)  //list has only one node
      *first2 = nullptr;
   else
   {
      middle = first1;
      current = first1->next;
      if (current != nullptr)	 //list has more than two nodes
	 current = current->next;
      while (current != nullptr)
      {
	 middle = middle->next;
	 current = current->next;
	 if (current != nullptr)
	    current = current->next;
      } //end while
      *first2 = middle->next;  
      middle->next = nullptr; 
   } //end else
} //end divideList


struct node* mergeList(struct node* first1,struct node* first2)
{
   struct node *lastSmall; //pointer to the last node 
   struct node *newHead;  //pointer to the merged list

   if (first1 == nullptr)  //the first sublist is empty
      return first2;
   else if (first2 == nullptr)  //the second sublist is empty
      return first1;
   else
   {
      if (first1->info < first2->info) //compare the first nodes
      {
	 newHead = first1;
	 first1 = first1->next;
	 lastSmall = newHead;
      }
      else
      {
	 newHead = first2;
	 first2 = first2->next;
	 lastSmall = newHead;
      }
      while (first1 != nullptr && first2 != nullptr)
      {
	 if (first1->info < first2->info)
	 {
	    lastSmall->next = first1;
	    lastSmall = lastSmall->next;
	    first1 = first1->next;
	 }
	 else
	 {
	    lastSmall->next = first2;
	    lastSmall = lastSmall->next;
	    first2 = first2->next;
	 }
      } //end while
      if (first1 == nullptr) //first sublist is exhausted first
	 lastSmall->next = first2;
      else	 //second sublist is exhausted first
	 lastSmall->next = first1;
      return newHead;
   }
}//end mergeList


void recMergeSort(struct node** head)
{
   struct node* otherHead;

   if (*head != nullptr)  //if the list is not empty
      if ((*head)->next != nullptr)  //if list has more than one
      {
	 divideList(*head, &otherHead);
	 recMergeSort(head);
	 recMergeSort(&otherHead);
	 *head = mergeList(*head, otherHead);
      }
} //end recMergeSort


void mergeSort(struct node **first, struct node **last)
{
   recMergeSort(first);

   if (*first == nullptr)
      *last = nullptr;
   else
   {
      *last = *first;
      while ((*last)->next != nullptr)
	 *last = (*last)->next;
   }
} //end mergeSort
