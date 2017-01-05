#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

//this function encrypts the text that is send to it using the key provided 
char* dec_text(char* key, char* text){ //returns char array text_e which is encrypted text
        char* text_e;
	text_e = malloc(strlen(text)); //allocate memory for the array
	int indexes[70001]; //array of text indexes to map the text given to keys
        int key_index[70001]; //array of key indexes to map text given to keys
        int i = 0;
        int j = 0;
        char lettermap[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '}; //array of valid/possible characters in file
        for(i = 0; i < strlen(text); i++){ //loop through the entire text given
                for(j = 0; j < strlen(lettermap); j++){ //loop through each letter to get index of where lettter matches
                        if(text[i] == lettermap[j]){ //this means we found the letter at index j
                                indexes[i] = j; //assign the next location in indexes to be index j
                        }
                        if(key[i] == lettermap[j]){ //this means we found the letter at index j for the key
                                key_index[i] = j; //assign next location in key index to be index j
                        }

                }
                indexes[i] -= key_index[i]; //add the key index to the index array at each location
                if(indexes[i] < 0){ //if we get a negative number, we need to correct it so that it can be mapped properly (can't index negatives!)
			indexes[i] += 27; //we add 26 since there are 27 total possible characters from 0-26 inclusively 
		}
		
		indexes[i] = indexes[i] % 27; //modular division to get encrypted locations in lettermap
                text_e[i] = lettermap[indexes[i]]; //assign encrypted locations a letter in lettermap according to index


        }

	return (char*)text_e; //return encrypted text, this must be sent back to the client  

}



void error(const char *msg) { perror(msg); exit(1); } // Error function used for reporting issues

int main(int argc, char *argv[])
{
	int listenSocketFD, establishedConnectionFD, portNumber, charsRead;
	socklen_t sizeOfClientInfo;
	char buffer[256]; //buffer for text 
	char buffer2[256]; //buffer for key
	char text[70000]; //array to hold largest amount of  text
	char key[70000]; //array to hold largest key
	struct sockaddr_in serverAddress, clientAddress;
	char* text_e;	
	
	if (argc < 2) { fprintf(stderr,"USAGE: %s port\n", argv[0]); exit(1); } // Check usage & args

	// Set up the address struct for this process (the server)
	memset((char *)&serverAddress, '\0', sizeof(serverAddress)); // Clear out the address struct
	portNumber = atoi(argv[1]); // Get the port number, convert to an integer from a string
	serverAddress.sin_family = AF_INET; // Create a network-capable socket
	serverAddress.sin_port = htons(portNumber); // Store the port number
	serverAddress.sin_addr.s_addr = INADDR_ANY; // Any address is allowed for connection to this process

	// Set up the socket
	listenSocketFD = socket(AF_INET, SOCK_STREAM, 0); // Create the socket
	if (listenSocketFD < 0) error("ERROR opening socket");

	// Enable the socket to begin listening
	if (bind(listenSocketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) // Connect socket to port
		error("ERROR on binding");
	listen(listenSocketFD, 5); // Flip the socket on - it can now receive up to 5 connections

	// Accept a connection, blocking if one is not available until one connects
	while(1){
	sizeOfClientInfo = sizeof(clientAddress); // Get the size of the address for the client that will connect
	establishedConnectionFD = accept(listenSocketFD, (struct sockaddr *)&clientAddress, &sizeOfClientInfo); // Accept
	if (establishedConnectionFD < 0) error("ERROR on accept");

	// Get the message from the client and display it
	
	//get the text 

	memset(buffer, '\0', 256); //initialize buffer
	charsRead = recv(establishedConnectionFD, buffer, 255, 0); //read data from the client and store in buffer
	if (charsRead < 0) error("ERROR reading from socket"); //socket could not be read from, possibly used wrong socket in execution
	strcpy(text, buffer); //copy buffer contents into large text array 


	send(establishedConnectionFD, '\0', 0, 0); //this just prevents some issues with hanging
	//get the key

	memset(buffer2, '\0', 256); //initialize buffer for key 
	charsRead = recv(establishedConnectionFD, buffer2, 255, 0); //read data from client and store into buffer2
	if (charsRead < 0) error("ERROR reading from socket");
	strcpy(key, buffer2); //copy buffer contents to larger key array 

	
	text_e = dec_text(key, text); //call enc_text to encrypt our text using the text given and the key given	



	// Send a Success message back to the client
	charsRead = send(establishedConnectionFD, text_e, strlen(text_e), 0); // Send success back
	if (charsRead < 0) error("ERROR writing to socket");
	close(establishedConnectionFD); // Close the existing socket which is connected to the client
	}
	close(listenSocketFD); // Close the listening socket
	return 0; 
}
