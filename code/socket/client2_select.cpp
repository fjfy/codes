#include<sys/select.h>
#include<sys/time.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{
	int socketfd,n;
	socketfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr;
    bzero(&addr,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(7777);
	inet_pton(AF_INET,argv[1],&addr.sin_addr.s_addr);
	connect(socketfd,(struct sockaddr*) &addr,sizeof(addr));
	char sendline[4096];
	fgets(sendline,4096,stdin);
	send(socketfd,sendline,strlen(sendline),0);
	close(socketfd);
	return 0;
}
