#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include <arpa/inet.h>
using namespace std;
#define MAXLINE 4096
int main(int argc,char **agrv)
{
	int listenfd,connfd;
	struct sockaddr_in servaddr;
	char buff[4096];
	int n;
	if((listenfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		cout<<"creat socket error";
		exit(0);
	}
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(6666);
    if(bind(listenfd,(struct sockaddr*) &servaddr,sizeof(servaddr))==-1)
    {
    	cout<<"bind socket error"<<endl;
    }
    if(listen(listenfd,10)==-1)
    {
    	cout<<"listen socket error"<<endl;
    }
    cout<<"====waiting for client't request========"<<endl;
    while(1)
    {
    	if((connfd=accept(listenfd,(struct sockaddr*)NULL,NULL))==-1)
    	{
    		cout<<"accept socket error"<<endl;
    	    continue;
        }
         n=recv(connfd,buff,MAXLINE,0);
         buff[n]='\0';
    cout<<"receive msg from client: "<<buff<<endl;
    close(connfd);
    }
    close(listenfd);
    exit(0);
   

}
