#include<bits/stdc++.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<queue>
#include <unistd.h>
using namespace std;
queue <int> inf_buff;
sem_t notEmpty, notFull;
int n;
bool ful=false;
int data=1;
void *producerFunc(void *arg){
	while(1){
		usleep(3000000);
		printf("Producer producing data %d\n\n", data);
		int val;
		sem_getvalue(&notFull,&val);
		if(val<=0&&ful==false)
		{
			printf("Buffer FULL Producer waiting to produce\n");
			ful=true;
		}
		
		sem_wait(&notFull);
		inf_buff.push(data);
		data++;
		sem_post(&notEmpty);
		usleep(1000000);
	}
}

void *consumerFunc(void *arg){
	while(1){
		usleep(4000000);
		sem_wait(&notEmpty);
		printf("\n\t\t\t\tConsumer is waiting\n\n");
		usleep(1000000);
		if(inf_buff.size()>=n-1&&ful==true){
			ful=false;
			while(!inf_buff.empty()){
				int k=inf_buff.front();
				//Consumer consuming data
				
				sem_post(&notFull);
				printf("\t\t\t\tConsumer consuming data %d\n\n", k);
				inf_buff.pop();
				//printf("\t\t\t\tCurrent buffer size =%ld \n\n",inf_buff.size());
				usleep(1000000);
			}
		}
		else
		{
			int k=inf_buff.front();
			sem_post(&notFull);
			//Consumer consuming data
			printf("\t\t\t\tConsumer consuming data %d\n\n", k);
			inf_buff.pop();
			//printf("\t\t\t\tCurrent buffer size =%ld \n\n",inf_buff.size());
		}
		usleep(3000000);
	}
}

int main(){
	int  i;
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
