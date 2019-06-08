#include<bits/stdc++.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
sem_t mutex, delay;
int count, k, n;
void *callThread(void *arg){
	int *x=(int *)arg;
	int id=*x;
	int m;
	id++;
	while(1){	
		printf("\n\tProcess %d in non-critical section\n", id);
		sleep(1);
		sem_wait(&mutex);
		count=count-1;
		m=count;
		sem_post(&mutex);
		if(m<=-1)sem_wait(&delay);
		printf("\n\t\t\t\t=============================\n\t\t\t\tProcess %d in critical section\n\t\t\t\t=============================\n\n", id);
		sleep(n);
		printf("\tProcess %d out of critical section\n", id);
		sem_wait(&mutex);
		count=count+1;
		if(count<=0)sem_post(&delay);
		sem_post(&mutex);
		sleep(1+id*1);
	}
}
int main(){
	int i;
	sem_init(&mutex, 0, 1);
	sem_init(&delay, 0, 0);
	printf("Enter no. of threads: ");
	scanf("%d", &n);
	printf("Enter processes to be in critical section: ");
	scanf("%d", &k);
	if(n<k)
	{
		printf("Value of k is greater than n\n");
		return 0;
	}
	count=k;
	pthread_t thread_buffer[n];
	for(i=0; i<n; i++){
		pthread_create(&thread_buffer[i], NULL, &callThread, &i);
		sleep(1);
	}
	pthread_exit(NULL);
	return 0;
}
