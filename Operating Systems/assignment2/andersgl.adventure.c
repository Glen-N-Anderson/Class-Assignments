#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

#define bool int
#define true 1
#define false 0
struct Room{ //create our struct to hold all of the data that a room needs
	char roomname[50]; 
	char roomtype[50];
	char* connections[6];
	int max_connections; //holsd the number of connections that a room has
	int num_connections;
	int current;

};

struct Room playable_rooms[7]; //creates an array of structs so we can use for playable rooms


void play_game(char* directory){
	// read in information from the files, store it in the struct 
	FILE *fp;
	int i = 0;
	char rooms[7][50]; //for each of 7 rooms, give us 50 characters to hold the name
	char connections[6][50]; //for each of up to 6 connections, 50 characters to hold connection name
	char types[7][50]; //for each of 7 types, give us 50 characters to hold room type
	char begin[50];
	char end[50];
	char temp[50]; //used for copying/validation of user input later in the function
	char line[150];
	int count = 0;
	int check = 1;
	char path[100][50]; //stores the users path as they go through the game
	int steps = 0;
	chdir(directory); //make sure we are in the right directory with all of our room files
	for(i = 0; i < 7; i++){ //for each room, check if the room is a start room
		if(strcmp(playable_rooms[i].roomtype, "START_ROOM") == 0){
			strcpy(begin,playable_rooms[i].roomname);
			break;
		}
	}
	for(i = 0; i < 7; i++){ //check if room is the end room
                if(strcmp(playable_rooms[i].roomtype, "END_ROOM") == 0){
                        strcpy(end,playable_rooms[i].roomname);
                        break;
                }
        }
	strcpy(path[0], begin); //set the beginning to tbe the users first step on path
	while(true){ //infinite loop to play game until user is the winner
		count = 0; //this keeps track of how many connections we get each run
		fp = fopen(begin, "r+"); //open our file for reading
		while(fgets(line, 150, fp)){ //this will read through file lines while fp is not null
			sscanf(line,"ROOM NAME: %s", rooms[0]);
			sscanf(line,"CONNECTION 1: %s", connections[0]); //store each connection in array of connections,
			sscanf(line,"CONNECTION 2: %s", connections[1]); //up to 6 total connections
			sscanf(line,"CONNECTION 3: %s", connections[2]);
			sscanf(line,"CONNECTION 4: %s", connections[3]);
			sscanf(line,"CONNECTION 5: %s", connections[4]);
			sscanf(line,"CONNECTION 6: %s", connections[5]);
			sscanf(line,"ROOM TYPE: %s", types[0]);
			count++; //incremement to track connections
		}
		fclose(fp); //close file so that we don't end up opening it twice when we run through during game
		check = 1;	
		while(check == 1){ //this will act as a way to force user to enter valid input
			printf("\nCURRENT LOCATION: %s", begin); 
			printf("\nPOSSIBLE CONNECTIONS: "); //print each possible connection for the user
			for(i = 0; i < count - 2; i++){
				printf("%s, ", connections[i]);
	
			}
			printf("\nWHERE TO? >"); //prompt user to enter a room to go to
			scanf("%s", temp); //get the users input and store it in a temp variable so we can check its validity 
			for(i = 0; i < count - 2; i++){
				if(strcmp(temp, connections[i]) == 0){ //if the user's input is somewhere in the array of valid connections
					check = 0; //let us break from while loop
                                	strcpy(begin, temp); //copy temp into begin, which will be our current state when we run through again
				}
			}	
			if(check == 1){ //this checks if the user entered invalid input
				if(strcmp(temp, "time") == 0){ //check if user wants the time
					time_t currtime;
					currtime = time(NULL); //initialize time

					printf(ctime(&currtime));	
				}
				else{

				printf("\nI DO NOT UNDERSTAND THAT ROOM");//yell at the user for entering bad input
				}
			}
			else{ //if all went well, increment the steps user has taken and copy the current room into the path the user took
				steps++;
				strcpy(path[steps], begin);
			
			}
		}
		if(strcmp(begin, end) == 0){ //check if beginning room is the same as the ending room
			printf("\nYOU WIN, GG"); //congratulate the user on their accomplishment
			printf("\nYOU TOOK %d STEPS!! YOUR PATH WAS:\n", steps); //tell the user how many steps they took
			for(i = 0; i < steps + 1; i++){ //show the user the path they took to get to the finishing room 
				printf("%s\n", path[i]);
			}
			exit(0); //quit the program as the user has won
		}
		
		

	}

	
}
void write_file(){
	FILE* fp; //allows us to open and append to file pointed to by fp
	int i = 0;
	int j = 0;
	char directory[100]; //holds our directory that will hold all of our files

	memset(directory, '\0', 100); //make sure our directory is free of garbage
        sprintf(directory, "andersgl.rooms.%d", getpid()); //name the directory with ID
        mkdir(directory, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH); //create the directory
        chdir(directory); //makes sure our files are created in the subdirectory

	for(i = 0; i < 7; i++){ //for each room, open the rooms file (or create) 
		fp = fopen(playable_rooms[i].roomname, "a");
		fprintf(fp, "ROOM NAME: %s", playable_rooms[i].roomname); //write the room name into file on the first line
		fclose(fp);
	}
	for(i = 0; i < 7; i++){
		for(j = 0; j < playable_rooms[i].max_connections; j++){ //we use a double for loop to go through each connection and write it to file
			fp = fopen(playable_rooms[i].roomname, "a"); //open for appending and write in connections
			fprintf(fp, "\nCONNECTION %d: %s", j+1, playable_rooms[i].connections[j]); 
			fclose(fp);
		}
	}
	for(i = 0; i < 7; i++){ 
		fp = fopen(playable_rooms[i].roomname, "a"); //open room for appending and add in the room type as last line of file
		fprintf(fp, "\nROOM TYPE: %s", playable_rooms[i].roomtype);
		fclose(fp);
	}	

	play_game(directory); //the games may begin now that file has been filled
}
void assign_type(){ //pseudo random assignment for types
	int rand_start = 0;
	int rand_end = 0;
	int i = 0;
	//somefin like if i == rand_Start if i == rand_end else mid
	rand_start = rand() % 3;
	rand_end = rand() % 3 + 4;
		
	for(i = 0; i < 7; i++){
		if(i == rand_start){ //assign start room when our iterator matches our random number 
			strcpy(playable_rooms[i].roomtype, "START_ROOM");
		
		}
		else if(i == rand_end){ //same as start room but for end room
			strcpy(playable_rooms[i].roomtype, "END_ROOM");

		}
		else{ //all rooms that aren't end or start rooms are assigned to be mid rooms
			strcpy(playable_rooms[i].roomtype, "MID_ROOM");
		}
	}
	
		
}
void create_connections(){ //this creates connections between rooms in our array of structs
	int i = 0;
	int j = 0;
	int num = 0;
	int max = 0;

	for(i = 0; i < 7; i++){ //for every room and every potential connection
		for(j = 0; j < 6; j++){
			playable_rooms[i].connections[j] = '\0'; //set connection to be empty so that we don't get garbage in our connections
		}
	}

	for(i = 0; i < 7; i++){
		playable_rooms[i].max_connections = rand() % 4 + 3; //give max connections a random number in appropriate range of 3-6
	}
	
	for(i = 0; i < 7; i++){ //for each room in the array of structs
		max = playable_rooms[i].max_connections;
		while(max != 0){ //while there are still connections to be added to this room
			
			for(j = 0; j < playable_rooms[i].max_connections; j++){ //for each connection
				num = rand() % 7;		
				if(playable_rooms[i].connections[j] != '\0'){ //prevents us from overwriting a two way connection already existing at j
					max--;
				}
				else{	//if all went well, we can connect the rooms to eachother
					playable_rooms[i].connections[j] = playable_rooms[num].roomname;
					playable_rooms[num].connections[j] = playable_rooms[i].roomname; //connects back to room that connected to it
	
					playable_rooms[i].num_connections++; //increment the number of connections so we can keep track of that later
                	                playable_rooms[num].num_connections++;
					
				
					max--;
				}
			}
		}

	}



}
void create_playable(){ //pseudo-randomly sets the 7 playable rooms
	char directory[1000];
        char* rooms[10]; //array for every possible room

        char* temp[10]; //we'll use this to shuffle rooms to achieve some pseudo-random arrangement


	int rand_num = 0;

        rooms[0] = "RoomA"; //assign each room, one element at a time, and name it
        rooms[1] = "RoomB";
        rooms[2] = "RoomC";
        rooms[3] = "RoomD";
        rooms[4] = "RoomE";
        rooms[5] = "RoomF";
        rooms[6] = "RoomG";
        rooms[7] = "RoomH";
        rooms[8] = "RoomI";
        rooms[9] = "RoomJ";
        srand(time(NULL)); //this will ensure that we get a good random number each time we use rand(), instead of same number
        int j = 0;
        int n = 9;
        for(j = 0; j < 10; j++){ //for each possible room
                rand_num = rand() % n; //tells us which room to switch to create pseudo-random arrangement
                temp[j] = rooms[0];
                rooms[0] = rooms[rand_num];
                rooms[rand_num] = temp[j];

        }

	int i = 0;
	for(i = 0; i < 7; i++){ //for first 7 shuffled rooms, add them to playable rooms so that they may be used in the game
		strcpy(playable_rooms[i].roomname, rooms[i]);

	}


}
int main(void){
	create_playable(); //create set of playable rooms
	create_connections(); //create connections between playable rooms
	assign_type();//assign each room a start, end, or mid type
	write_file(); //write to the file with all the data we gathered in struct-this will also start the game when it is done
	
	
	return 0;
}

