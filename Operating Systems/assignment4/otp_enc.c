#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
int valid_char(char c){


        char lettermap[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
        int i = 0;

        for(i = 0; i < strlen(lettermap); i++){
                if(c == lettermap[i]){
                        return 1;
                }

        }
        return 0;

}




void error(const char *msg) { perror(msg); exit(0); } // Error function used for reporting issues

int main(int argc, char *argv[])
{
        FILE* fp;
        char keyfile[70001];
        char plainfile[70001];
        char c;
        char* p;
        int i = 0;
        int port;

        port = strtol(argv[3], &p, 10);

        fp = fopen(argv[1], "r+");
        while(c != EOF){
                c = fgetc(fp);
                if(c == '\n'){
                        break;
                }
                else if(valid_char(c)){
                        plainfile[i] = c;
                        i++;
                }
                 else{
                        fprintf(stderr, "File contains invalid character(s)\n");
                        fclose(fp);
                        exit(1);
                }


        }
        fclose(fp);
        fp = fopen(argv[2], "r+");
        i = 0;
	while(c != EOF && i < strlen(plainfile)){
                c = fgetc(fp);
                if(c == '\n'){
                        break;
                }
                else if(valid_char(c)){
                        keyfile[i] = c;
                        i++;

                }
                else{
                        fprintf(stderr, "File contains invalid character(s)\n");
                        fclose(fp);
                        exit(1);
                }

        }
        if(strlen(keyfile) < strlen(plainfile)){
                fprintf(stderr, "Key file is smaller than plain text file!\n");
                exit(1);
        }








	//server stuff starts here, uses instructor's code

	int socketFD, portNumber, charsWritten, charsRead;
	struct sockaddr_in serverAddress;
	struct hostent* serverHostInfo;
	char buffer[256];
    	static const char hostname[] = "localhost";
	if (argc < 3) { fprintf(stderr,"USAGE: %s hostname port\n", argv[0]); exit(0); } // Check usage & args

	// Set up the server address struct
	memset((char*)&serverAddress, '\0', sizeof(serverAddress)); // Clear out the address struct
	portNumber = atoi(argv[3]); // Get the port number, convert to an integer from a string
	serverAddress.sin_family = AF_INET; // Create a network-capable socket
	serverAddress.sin_port = htons(portNumber); // Store the port number
	serverHostInfo = gethostbyname(hostname); // Convert the machine name into a special form of address
	if (serverHostInfo == NULL) { fprintf(stderr, "CLIENT: ERROR, no such host\n"); exit(0); }
	memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)serverHostInfo->h_addr, serverHostInfo->h_length); // Copy in the address

	// Set up the socket
	socketFD = socket(AF_INET, SOCK_STREAM, 0); // Create the socket
	if (socketFD < 0) error("CLIENT: ERROR opening socket");
	
	// Connect to server
	if (connect(socketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) // Connect socket to address
		error("CLIENT: ERROR connecting");

	// Get input message from user

	// Send message to server
	charsWritten = send(socketFD, plainfile, strlen(plainfile), 0); // Write to the server
	if (charsWritten < 0) error("CLIENT: ERROR writing to socket"); //was not able to write to the socket
	if (charsWritten < strlen(buffer)) printf("CLIENT: WARNING: Not all data written to socket!\n"); //not all data made it


	charsWritten = send(socketFD, keyfile, strlen(keyfile), 0); // Write to the server
        if (charsWritten < 0) error("CLIENT: ERROR writing to socket"); //not able to write to the socket 
        if (charsWritten < strlen(buffer)) printf("CLIENT: WARNING: Not all data written to socket!\n");




	memset(buffer, '\0', sizeof(buffer)); // Clear out the buffer again for reuse

	charsRead = recv(socketFD, buffer, sizeof(buffer) - 1, 0); // Read data from the socket, leaving \0 at end
	if (charsRead < 0) error("CLIENT: ERROR reading from socket");
	
	int j = 0;
	for(j = 0; j < strlen(buffer); j++){
		printf("%c", buffer[j]); //print the encrypted text to standard out
	}
	printf("\n");
	close(socketFD); // Close the socket
	return 0;
}
