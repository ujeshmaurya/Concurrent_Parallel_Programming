#include<bits/stdc++.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<queue>
#include <unistd.h>


using namespace std;
int inf_buff[1000001];
sem_t notEmpty, notFull, mutex;
int data=1;
int con=1;
int ind=1;
int srd=1;
int in=0, out=0, n;
void *producerFunc(void *arg){
	while(1){
		usleep(3000000);
		printf("Producer producing data %d at index %d\n\n", data,in);
		sem_wait(&notFull);
		inf_buff[in]=data;
		data++;
		in=(in+1)%n;
		sem_post(&notEmpty);
		usleep(1000000);
		con++;
		ind++;
	}
}

void *consumerFunc(void *arg){
	while(1){
		usleep(4000000);
		sem_wait(&notEmpty);
		printf("\n\t\t\tConsumer is waiting\n\n");
		usleep(1000000);
		int k=inf_buff[out];
		out=(out+1)%n;			
		sem_post(&notFull);
		printf("\t\t\tConsumer consuming data %d\n\n",k);
		usleep(3000000);
		con++;
		ind++;
	}
}

int main(){
	int i;
	sem_init(&notEmpty, 0, 0);
	printf("Enter size of buffer: ");
	scanf("%d", &n);
	sem_init(&notFull, 0, n - 1);
	pthread_t producer, consumer;
	pthread_create(&producer, NULL, &producerFunc, NULL);
	pthread_create(&consumer, NULL, &consumerFunc, NULL);
	pthread_exit(NULL);
	return 0;
}
