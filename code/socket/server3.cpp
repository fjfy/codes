#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>
#include<sys/epoll.h>
#include<iostream>
using namespace std;
int main(int argc,char **argv)
{
	
	int fed[3];
	fed[0]=socket(AF_INET,SOCK_STREAM,0);
	fed[1]=socket(AF_INET,SOCK_STREAM,0);
	fed[2]=socket(AF_INET,SOCK_STREAM,0);
	
    int maxevents=3;
	struct sockaddr_in addr0,addr1,addr2;

	addr0.sin_family=AF_INET;
	addr0.sin_port=htons(7777);
	addr0.sin_addr.s_addr=htonl(INADDR_ANY); 
	bind(fed[0],(struct sockaddr*) &addr0,sizeof(sockaddr_in));
    //listen
    listen(fed[0],10);

    addr1.sin_family=AF_INET;
	addr1.sin_port=htons(7778);
	addr1.sin_addr.s_addr=htonl(INADDR_ANY); 
    bind(fed[1],(struct sockaddr*) &addr1,sizeof(sockaddr_in));
    listen(fed[1],10);

	addr2.sin_family=AF_INET;
	addr2.sin_port=htons(7779);
	addr2.sin_addr.s_addr=htonl(INADDR_ANY); 
    bind(fed[2],(struct sockaddr*) &addr2,sizeof(sockaddr_in));
    listen(fed[2],10);

	int a=epoll_create(3);
	struct epoll_event epolled;
	epolled.events=EPOLLIN|EPOLLERR;
	for(int i=0;i<3;++i)
		epoll_ctl(a,EPOLL_CTL_ADD,fed[i],&epolled);
	int n,connfd;
	char buffer[4096];
     cout<<"==============receive msg from epoll client=================="<<endl;
     while(1)
     {
     	for(int i=0;i<3;++i)
     	{
     		if(epoll_wait(fed[i],&epolled,maxevents,-1))
			{
        		connfd=accept(fed[i],(struct sockaddr*)NULL,NULL);
    			bzero(buffer,4096);
    			n=recv(connfd,buffer,4096,0);
    			buffer[n]='\0';
    			cout<<"receive msg from client(7778): "<<buffer<<endl;
			}

     	}
		
		
	}
}
