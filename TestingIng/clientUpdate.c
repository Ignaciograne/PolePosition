#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <json-c/json.h>

#define PORT 3403
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char servIP[120]="127.0.0.1";

    if(argc > 1) {
        strncpy(servIP,argv[1],sizeof(servIP));
    }

    int clientSocket, ret;
    struct sockaddr_in serverAddr; // Server address
    char buffer[BUF_SIZE];

    // Create a reliable, stream socket using TCP
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket < 0){
        printf("Error in connection.\n");
        exit(1);
    }
    printf("Client Socket is created.\n");

    // Construct the server address structure
    memset(&serverAddr, '\0', sizeof(serverAddr)); // Zero out structure
    serverAddr.sin_family = AF_INET;               // IPv4 address family
    serverAddr.sin_port = htons(PORT);             // Server port

    // Convert address
    int rtnVal = inet_pton(AF_INET, servIP, &serverAddr.sin_addr.s_addr);
    if (rtnVal == 0)
        printf("inet_pton() failed: invalid address string");
    else if (rtnVal < 0)
        printf("inet_pton() failed");

    // Establish the connection to the sorted server
    ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(ret < 0){
        printf("Error in connection.\n");
        exit(1);
    }
    printf("Connected to Server.\n");

    //Read
    while(fgets(buffer, sizeof(buffer), stdin)){    //read line by line of the input file
            char reply[BUF_SIZE]={0};
            char repList[20][BUF_SIZE]={0};
            int count=0;
            int ret=1;
            printf("You typed: %s", buffer);


            // Send data to the server
            send(clientSocket, buffer, strlen(buffer), 0);
            // Receive json back from the server
            ret=recv(clientSocket, &reply[count],sizeof(reply)-count,0);
            count+=ret;
	    printf("%s", reply);
            if( ret < 0 ) {
                printf("Error in receiving data.\n");
            }
            printf("\n");
        }
    return 0;
}
