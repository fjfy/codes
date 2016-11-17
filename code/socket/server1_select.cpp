#include<sys/select.h>
#include<sys/time.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<iostream>
using namespace std;
int main(int argc,char** argv)
{
	int socketfd;
	socketfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr1;
	addr1.sin_family=AF_INET;
	addr1.sin_port=htons(7777);
	addr1.sin_addr.s_addr=htonl(INADDR_ANY); 
	bind(socketfd,(struct sockaddr*) &addr1,sizeof(sockaddr_in));
	listen(socketfd,10);
	int socketfd2;
	socketfd2=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr2;
	addr2.sin_family=AF_INET;
	addr2.sin_port=htons(7778);
	addr2.sin_addr.s_addr=htonl(INADDR_ANY); 
	bind(socketfd,(struct sockaddr*) &addr2,sizeof(sockaddr_in));
	listen(socketfd2,10);
	cout<<"=========waiting for client's request==========="<<endl;
    int maxfd;
    maxfd=socketfd;
    if(socketfd2>maxfd)
    {
    	maxfd=socketfd2;
    }
    fd_set allset,rset;
    FD_ZERO(&allset);
    FD_SET(socketfd,&allset);
    FD_SET(socketfd2,&allset);
    char buffer[4096];
    int n,connfd;
    //select函数每次调用时把没有事件发生的描述字清零
    for(;;)
    {
    	rset=allset;
    	select(maxfd+1,&rset,NULL,NULL,NULL);
    	if(FD_ISSET(socketfd,&rset))
    	{
    		connfd=accept(socketfd,(struct sockaddr*)NULL,NULL);
    		bzero(buffer,4096);
    		n=recv(connfd,buffer,4096,0);
    		buffer[n]='\0';
    		cout<<"receive msg from client(7777): "<<buffer<<endl;
    	}
    	if(FD_ISSET(socketfd2,&rset))
    	{
    		connfd=accept(socketfd2,(struct sockaddr*)NULL,NULL);
    		bzero(buffer,4096);
    		n=recv(connfd,buffer,4096,0);
    		buffer[n]='\0';
    		cout<<"receive msg from client(7778): "<<buffer<<endl;

    	}
    	close(connfd);
    }
    close(socketfd);
    close(socketfd2);
    return 0;
}
