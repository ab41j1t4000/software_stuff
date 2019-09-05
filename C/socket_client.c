#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main()
{
    struct sockaddr_in Address;
    int fd;
    int connection;
    char message[100] = "";
    fd = socket(AF_INET,SOCK_STREAM,0);
    Address.sin_family = AF_INET;
    Address.sin_port = htons(8096);
    inet_pton(AF_INET,"127.0.0.1",&Address.sin_addr);
    connect(fd,(struct sockaddr *)&Address,sizeof(Address));
    while(1){
        printf("Enter message: ");
        fgets(message,100,stdin);
        send(fd,message,strlen(message),0);
    }
}