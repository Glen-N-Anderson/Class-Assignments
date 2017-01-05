/* CS261- Assignment 1 - Q.5*/
/* Name: Glen Anderson
 * Date: 10/08/15
 * Solution description: Converts user inputted words into studly caps
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
	return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}
/*converts word into studly caps*/
void studly(char* word){
     	/*Convert to studly caps*/
	int i;
	if((word[0] > 96) && (word[0] < 123)){ 
		for(i = 0; i < strlen(word); i+=2){
			word[i] = toUpperCase(word[i]);
	
		}
        }
        else if((word[0] > 64) && (word[0] < 91)){
		for(i = 1; i < strlen(word); i+=2){	

			if((word[i] > 64) && (word[i] < 91)){
               		        word[i] = toLowerCase(word[i]);
                	}
        	}
		
	}
}

int main(){
	char word[100];
	printf("Enter a word: ");
	scanf("%s", word);	
    	/*Read word from the keyboard using scanf*/
	/*Call studly*/
	studly(word);	
	
	printf("New word: %s\n", word);
	/*Print the new word*/
    	return 0;
}
