#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
 
int main(int argc,char **argv)
{
    int sockfd,n;
    //char sendline[100];
    //char recvline[100];
    char str[200];
    struct sockaddr_in servaddr;
 
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof servaddr);
 
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(3403);
 
    inet_pton(AF_INET,"127.0.0.1",&(servaddr.sin_addr));
    
    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

    char* jsonList;
    char jArray[20][15];
    int i = 0, j;
    while(1)
    {
    	char sendline[100];
    	char recvline[300];
        bzero(sendline, 100);
        bzero(recvline, 300);
	bzero(str, 200);

	read(sockfd, recvline, 300);
	printf("%s", recvline);

        fgets(sendline, 100, stdin); /*stdin = 0 , for standard input */
	jsonList = strtok(sendline, ", ");
	while (jsonList != NULL){
		strcpy(jArray[i], jsonList);
		jsonList = strtok(NULL, ", ");
		i++;
	}

	//for (j = 0; j < i; j++){
	//	printf("Posicion %d: %s\n", j, jArray[j]);
	//}

	json_object *root = json_object_new_object();

	for (j = 0; j < i; j=j+2){
		json_object_object_add(root, jArray[j], json_object_new_string(jArray[j+1]));
	}

	printf("What you just wrote: \n\n%s\n", json_object_to_json_string_ext(root, JSON_C_TO_STRING_PLAIN));

	write(sockfd, json_object_to_json_string_ext(root, JSON_C_TO_STRING_PLAIN), 200);

	//printf("You typed %s\n", sendline);

        bzero(recvline, 300);
	read(sockfd, recvline, 300);
	printf("Leyendo del socket: %s\n", recvline);


        //write(sockfd,sendline,strlen(sendline)+1);
	//printf("You just type: %s\n", sendline);
	//
        //read(sockfd,recvline,100);
        //printf("%s",recvline);
    	json_object_put(root);
    }
}
