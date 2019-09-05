#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>c

int main()
{
    struct sockaddr_in Address;
    int fd;
    int connection;
    char message[100] = "";
    Address.sin_family = AF_INET;
    Address.sin_port = htons(8096);
    Address.sin_addr.s_addr = INADDR_ANY;
    fd = socket(AF_INET,SOCK_STREAM,0);
    bind(fd, (struct sockaddr *)&Address,sizeof(Address));
    listen(fd,5);
    while (connection = accept(fd, (struct sockaddr *)NULL,NULL)){
        int pid;
        if((pid == fork()) == 0){
            while(recv(connection,message,100,0)>0)
            {
                printf("Message Recieved: %s\n",message);
                memset(message,"",strlen(message));
            }
            exit(0);
        }
    }

}
