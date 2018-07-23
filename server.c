/* A simple server in the internet domain using TCP
   The port number is passed as an argument */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int n;
    char buffer[255];
    socklen_t clilen;
    int sockfd, newSockfd, portNo;
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("ERROR opening socket");   
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portNo = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portNo);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newSockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newSockfd < 0)
        error("ERROR on accept");
    
    while (1) {
        bzero(buffer, 256);
        n = read(newSockfd, buffer, 255);

        if (n < 0)
            error("ERROR reading from socket");
        printf("Client : %s\n", buffer);
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);

        n = write(newSockfd, buffer, strlen(buffer));

        if (n < 0)
            error("ERROR writing to socket");
        
        int i = strncmp("Bye", buffer, 3);

        if (i == 0)
            break;
    }
    close(sockfd);
    close(newSockfd);
    
    return 0;
}
