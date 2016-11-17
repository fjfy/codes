#include<sys/msg.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<iostream>
using namespace std;
const int buffsize=4096;
struct my_message
   {
        long int msgtype;
        char text[buffsize];

   };
int main(int argc,char **argv)
{
    //int msgget(key_t key,int msgflg);
    //int msgsend(int msgid,const void *msg_ptr,size_t msg_sz,int msgflg);
    //int msgrcv(int msgid,void *msg_ptr,long int msgtype,int msgflag);
    //int msgctl(int msgid,int command,struct msgid_ds *buf);
    //msgflag=0666;
    struct my_message data;
    int bsize=4096;
    int msgid;
    msgid=msgget((key_t)1234,0666|IPC_CREAT);
    char buffer[bsize];
    int running=1;
    if(msgid==-1)
        cout<<"msgget error"<<endl;
    while(running)
    {
        cout<<"enter some text: "<<endl;
        fgets(buffer,bsize,stdin);
        data.msgtype=1;
        strcpy(data.text,buffer);

        if(msgsnd(msgid,(void *)(&data),buffsize,0)==-1)
            cout<<"receive error"<<endl;
        cout<<"you wrote:"<<data.text<<endl;
        if(strncmp(data.text,"end",3)==0)
            running=0;
    }
    
    return 0;



}
