/*

Problem 1: Declare a global variable counter then create the two threads in your C program. Both the threads will execute the following function 
           such that the first thread starts then first thread finishes after that the second thread starts then the second thread finishes.
	   Use semaphore and thread to do the task.

void *fun(void *){++counter; printf("Thread %d has started"ù, counter) sleep(5); printf("Thread %d has finished%d"ù, counter); return NULL;)

*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int counter = 0;
pthread_t threads[2];
pthread_mutex_t lock;

void *fun()
{
	pthread_mutex_lock(&lock);
	++counter; 	
	printf("Thread %d has started\n", counter); 
	sleep(0);
	printf("Thread %d has finished\n", counter); 
	pthread_mutex_unlock(&lock);	
	return NULL;
}

int main()
{
	int flag;

	for(int i=0;i<2;i++)
	{
		flag = pthread_create(&(threads[i]),NULL,fun,NULL);
	}

	pthread_join(threads[0],NULL);
	pthread_join(threads[1],NULL);
}