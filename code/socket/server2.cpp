#include<poll.h>
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main(int argc,char** argv)
{
	int polled0,polled1,polled2;
	polled0=socket(AF_INET,SOCK_STREAM,0);
	polled1=socket(AF_INET,SOCK_STREAM,0);
	polled2=socket(AF_INET,SOCK_STREAM,0);

	struct pollfd fdarray[3];
	memset(fdarray,0,sizeof(fdarray));
	fdarray[0].fd=polled0;
	fdarray[0].events=POLLIN|POLLERR;

    fdarray[1].fd=polled1;
    fdarray[1].events=POLLIN|POLLERR;

    fdarray[2].fd=polled2;
    fdarray[2].events=POLLIN|POLLERR;

//bind
    struct sockaddr_in addr0,addr1,addr2;

	addr0.sin_family=AF_INET;
	addr0.sin_port=htons(7777);
	addr0.sin_addr.s_addr=htonl(INADDR_ANY); 
	bind(polled0,(struct sockaddr*) &addr0,sizeof(sockaddr_in));
    //listen
    listen(polled0,10);

    addr1.sin_family=AF_INET;
	addr1.sin_port=htons(7778);
	addr1.sin_addr.s_addr=htonl(INADDR_ANY); 
    bind(polled1,(struct sockaddr*) &addr1,sizeof(sockaddr_in));
    listen(polled1,10);

	addr2.sin_family=AF_INET;
	addr2.sin_port=htons(7779);
	addr2.sin_addr.s_addr=htonl(INADDR_ANY); 
    bind(polled2,(struct sockaddr*) &addr2,sizeof(sockaddr_in));
    listen(polled2,10);
    int connfd;
    char buffer[4096];
    int n,retval;
    cout<<"================waiting for server2 client request=================="<<endl;
    while(1)
    {
    	retval=poll((struct pollfd*) &fdarray,3,-1);
    	if(retval<0)
    	{
    		perror("poll");
    		exit(0);
    	}
    	if(retval==0)
    	{
    		printf("no data in 5 seconds\n");
    		continue;
    	}
    	for(int i=0;i<3;i++)
    	{
    			if(fdarray[i].revents&POLLERR)
    			{
    			    cout<<"device error!\n";
    			    exit(0);	
    			}
    			if(fdarray[i].revents&POLLIN)
    			{
    				connfd=accept(fdarray[i].fd,(struct sockaddr*)NULL,NULL);
    				bzero(buffer,4096);
    				n=recv(connfd,buffer,4096,0);
    				buffer[n]='\0';
    				cout<<"receive msg from client(7778): "<<buffer<<endl;
    			}
    	}

    }
    close(polled0);
    close(polled1);
    close(polled2);

    

}
