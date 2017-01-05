#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
int pids[50]; //array to store processes so that they can be deleted 
int is_back(char **command){ //this function checks if the command is a background command or not as indicated by the & symbol 
	int i = 0;
	for(i = 0; command[i] != NULL; i++){ //go through entire command line, look for & symbol 
		if(strcmp(command[i], "&") == 0){
			return 1; //this means that we found & symbol and the process should be run in the background

		}

	}
	return 0; //do not run process in background 

}
char** clean_list(char **command){ //clean the command of symbols that would otherwise cause exec to fail 
	int i = 0;
	for(i = 0; command[i] != NULL; i++){ //iterate through each string in command 
		if(strcmp(command[i], ">") == 0 || strcmp(command[i], "<") == 0 || strcmp(command[i], "&") == 0){ //check entire command for these symbols 
			command[i] = '\0'; //replace symbols with nothing 
		}

	}
	return command; //return cleaned command so that exec can use it 

}
int fork_it_over(char **command){ //this function runs the non-built in part of the shell, where it must fork and exec 
	pid_t spawnpid; //stores the child's pid 
	int status = 0;  //will be returned as 1 or 0 for failure or success respectively 
	int check = 0; //used to check that there is no return value from exec function (meaning successful execution)
	int i = 0; //just an interator to go through command list 
	int input = 0;
	int output = 0;
	int fp = 0; //file desc for input, will be used to open and read
	int count = 0;
	int fp2 = 0; //file desc for output, will be used to open and write 
	char** commandlist; 
	int stat; //exit status of special case 
	int background = 0;
	background = is_back(command);
	spawnpid = fork();
	
	if(spawnpid < 0){
		exit(1);
	}
	else if(spawnpid == 0){ //child does work here
		signal(SIGINT, SIG_IGN); //ignore sigint (ctrl-c) signal 
		//input/output redirecttion goes here
		for(i = 0; command[i] != NULL; i++){ //run through the entire command line to look for special characters 
			if(strcmp(command[i], "<") == 0){ //if input symbol 
				//redirect input so that it comes from i-1	
				fp = open(command[i + 1], O_RDONLY); //this opens the file specified in the command for READING
				if(fp < 0){ //if the file desc is less than 0 an error must have occured 
					printf("Error opening file for reading\n");
					fflush(stdout);
					return 1; //return 1 to indicate an error occured
				}
				dup2(fp, 0);//this changes where the program takes input: it will now look to fp for this instead of standard input
				close(fp);
			}
			if(strcmp(command[i], ">") == 0){ //if output symbol 
				fp2 = creat(command[i + 1], 0644); //make another file pointer for WRITING to a file 
				if(fp2 < 0){ //again, an error occurs if the file desc is less than 0
					printf("Error opening file for writing\n");
					fflush(stdout);
					return 1;

				}
				dup2(fp2, 1); //redirects file to be treated as standard output, aka '1', similar to above 
				close(fp2);	
			
			}
		}
		commandlist = clean_list(command); //get <, >, and & characters out of the command so that exec can use the command 
		check = execvp(command[0], commandlist);
		if(check != 0){ //if exec returns anything, it means that it failed 
			printf("Exec failed, invalid command\n"); 
			fflush(stdout);
			kill(getpid(), SIGTERM);
			return 1; //return 1 to indicate an error occured 
		}
	}
	else{ //parent waits for child 
		if(background == 0){	//not a background task, wait until it finishes to return control 
			while(wait(&status) != spawnpid); //waits for child to terminate before continuing 
		}
		else{
			printf("Background process created, pid: %d\n", spawnpid); //print spawnpid of process when it is completed
			sleep(2); 
			pid_t pid = waitpid(spawnpid, &status, WNOHANG); //return control to user immediately, don't wait for command
			if(pid == spawnpid){ //check to see that the process completed 
				printf("Process %d finished\n", spawnpid); //print the spawnpid of the finished process
				printf("Exit value: %d", status); //will be zero if we can even get into this if statement 
			}

			fflush(stdout);
			for(i = 0; pids[i + 1] != '\0'; i++){ //add completed process to list so that we can delete it later 
				if(pids[i] == '\0') //check for end of list
					pids[i] = spawnpid; //append the spawnpid to list 

			}	
		
	



		}
		int signal;
		if(WIFEXITED(status)){ //if it exited
			stat = WEXITSTATUS(status); //this will get exit status for the case where a command passed to exec fails 
			
	
			return stat; //return special status for exec failure 
		}
	}
	
	return 0; //no handled error occured 	

}
void display_status(int status){ //print the status of the last command to the user
	printf("exit value %d\n", status);
	fflush(stdout);
}
void exit_shell(){ //this function will terminate all child processes and exit shell
	//destroy any remaining processes here, then exit shell
	int i = 0;
	
	for(i = 0; pids[i] != '\0'; i++){
		kill(pids[i], SIGTERM); 
        }
    	

	exit(0);

}
int change_dir(char** directory){ //changes working directory of program 
	int status = 0; //variable to track status of the program
	if(!(directory[1])){ //if cd arrives by itself with no args, change to the HOME directory. Else, change to directory specified 
		chdir(getenv("HOME")); //this will be the directory pointed to by HOME
		return status; //execution successful 
	}
	else{
		chdir(directory[1]); //otherwise, change to directory that the user specified 
		return status;
	}
}
char** split_line(char* input){ //this function processes the info from the buffer so that it can be used by rest of program
	char **args = malloc(512 *sizeof(char*)); //512 arguments maximum 
	char *temp = NULL;
	int index = 0;
	char *word; //this will be the individual arguements, the words seperated by spaces in command line 
	int i = 0;	
	word = strtok(input, " "); //split our string on first space before doing so for the rest of the string  
	do{	
		args[index] = word; //assign the token to the end of the arguments array 
		index++; //step through the array 

	}while((word = strtok(NULL, " ")) != NULL); //while strtok can continue splitting on spaces, not hitting the end of string (NULL) 
	
	return args; //return completed list

}

char* read_buff(){ //get the user's initial input
	char *line = NULL; //stores what is read from buffer 
	size_t size = 0; //size of buffer 
	int num_read = 0;
	num_read = getline(&line, &size, stdin); //use getline to grab the entire buffer 
	if(line[num_read - 1] == '\n'){ //replace the pesky newline with null terminator so that we can actually execute commands 
		line[num_read - 1] = '\0'; //exec and strcmp will not work well if we leave the newline  
		
	}

	return line; //return the read user input 

}

int main(){
	char *input;
	char **sline;
	int i = 0;
	int status = 0; //this variable will store our exit status, changed to 1 for certain errors
	while(1){ //infinite loop to continue running the shell until the user exits 
		fputs(": ", stdout); //print a colon for the user to put in their input 
		fflush(stdout);
		input = read_buff(); //store users input in input 
		sline = split_line(input); //store the processed, split line in sline 
		//the built in commands are below 
		if(strcmp(sline[0], "exit") == 0){ //built in command, will exit the shell when it is excuted 
			exit_shell();
		}
		else if(strcmp(sline[0], "cd") == 0){ //built in command, changes directory based on user's provided (or exempted) file path 
			status = change_dir(sline); //if something went wrong, status will be 1 

		} 
		else if(strcmp(sline[0], "status") == 0){ //built in command, display status to the user
			display_status(status);
		}
		else if(strncmp(sline[0], "#", 1) == 0){ //handles comments by essentially allowing them, preventing them from hitting exec()
			status = 0;
			continue;
		}	
		else{
			//if its not a comment or built in function, enter the danger zone 
			status = fork_it_over(sline); //status will be set to 1 if the child process fails 
		}
	}


	return 0;
}
