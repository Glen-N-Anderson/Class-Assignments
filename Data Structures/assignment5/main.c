#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);
	struct Task *new;
	struct Task* first;
	FILE *file; //points to the file 
	char fileName[100];
	char desc[128];
	char *ptr;		
  	int prior;
	printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');
	if(cmd == 'a'){
		printf("Enter task description: ");
		if(fgets(desc, 100, stdin) != NULL){
			ptr = strchr(desc, '\n');
		}		
		printf("Enter priority: ");
		scanf("%d", &prior);
		
		while(getchar() != '\n');
		new = createTask(prior, desc);
		addHeap(mainList, new, compare);
		printf("Task '%s' added!\n\n", desc);
	
	}
	if(cmd == 'g'){
		
		first = (struct Task*)getMinHeap(mainList);
		printf("First task: %s\n\n", first->description);
	}
	if(cmd == 'r'){
		first = (struct Task*)getMinHeap(mainList);
		removeMinHeap(mainList, compare);
		printf("Done with %s, removed!\n\n", first->description);
		free(first);
	}		
	if(cmd == 'p'){
		printList(mainList);
	}
	if(cmd == 's'){
		printf("Enter file name: ");
		if(fgets(fileName, 100, stdin)){
			ptr = strchr(fileName, '\n'); 
		}
		file = fopen(fileName, "w");
		saveList(mainList, file);	
      		fclose(file);
		printf("Saved!\n\n");


	}
	if(cmd == 'l'){
		printf("Enter file name: ");
		scanf("%s", fileName);
		file = fopen(fileName, "r");
		
		if(file == NULL){
                        break;
                }
		 while (getchar() != '\n');
		loadList(mainList, file);
		printf("List loaded! \n\n");
		fclose(file);
	}
	if(cmd == 'e'){
		printf("Exiting...\n\n");
	}	



/* Fixme:  Your logic goes here! */

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
