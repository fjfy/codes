#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;
#define MAXLINE 4096
int main(int argc, char **argv)
{
	int sockfd,n;
	char recvline[4096],sendline[4096];
	struct sockaddr_in servaddr;
	if(argc!=2)
	{
		cout<<"usage:./client <ipaddress>"<<endl;
		exit(0);
	}
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		cout<<"creat socket error"<<endl;
		exit(0);
	}
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(7778);
	char *addr="192.168.3.10";
	if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr.s_addr)<=0)
	{
		cout<<"inet_pton error for "<<argv[1]<<endl;
		exit(0);
	}
	if(connect(sockfd,(struct sockaddr*) &servaddr,sizeof(servaddr))<0)
	{
		cout<<"connect error"<<endl;
		exit(9);
	}
	cout<<"send msg to serve:"<<endl;
	fgets(sendline,4096,stdin);
	if(send(sockfd,sendline,strlen(sendline),0)<0)
	{
		cout<<"send msg error: "<<endl;
		exit(0);
	}
	close(sockfd);
	exit(0);
}
