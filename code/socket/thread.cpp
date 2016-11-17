#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
int num=0;
pthread_mutex_t mylock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t qready=PTHREAD_COND_INITIALIZER;
void *thread_fun(void *arg)
{
	int* thi=(int*)(arg);
	int i=*thi;
	int ret;
	sleep(5-i);
	pthread_mutex_lock(&mylock);
	while(i!=num)
	{
		printf("thread %d waiting\n",i);
		ret=pthread_cond_wait(&qready,&mylock);
		if(ret==0)
		{
		printf("thread %d wait success\n",i);
		}
		else
		printf("thread %d wait failed:%s\n",i,strerror(ret));
	}
	printf("thread %d is running \n",i);
	num++;
	pthread_mutex_unlock(&mylock);
	pthread_cond_broadcast(&qready);
	return (void *)0;
}
int main(int argc,char** argv)
{
	pthread_t tid[4];
	for(int i=0;i<4;i++)
	{
		pthread_create(&tid[i],NULL,thread_fun,(void*)i);
	}
	void *tret;
	for(int i=0;i<4;i++)
	pthread_join(tid[i],&tret);
	return 0;
}
