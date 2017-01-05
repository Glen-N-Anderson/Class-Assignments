#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]){
	char lettermap[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '}; //the array of possible characters to be used in the key 
	int keylen = 0; //we will get this from argv 
	char *p; 
	int i = 0;
	int randnum = 0; //random number to use to get a random index for the letter map

	if(argc > 1){ //check that the correct number of arguments is provided
		keylen = strtol(argv[1], &p, 10); //get the key length from argv  
	}
	else{ //an error occured!
		fprintf(stderr, "error occured, not enough arguments to keygen\n"); //user needs to use correct number of arguments
		exit(0);//exit program so user can do things correctly 
	}
	srand(time(NULL)); //initialize pseudo-random function 
	for(i = 0; i < keylen; i++){ //for the provided length of the key, write a letter
		randnum = rand() % 27; //random number between 0-26 to map lettermap
		fprintf(stdout, "%c", lettermap[randnum]); //print the random letter to standard out
	}
	fprintf(stdout, "\n");	//add newline to file
	return 0;	

}
