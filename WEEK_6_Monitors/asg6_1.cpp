#include<bits/stdc++.h>
#include<pthread.h>
#include <unistd.h>
using namespace std;
pthread_mutex_t mutex;
int con=0;
class monitor
{
	public:
		int s;
		
		pthread_cond_t notZero;
		//pthread_cond_init(&notZero,NULL);
		void wait(char id){
			if(s==0)
			 	{
					printf("\t\tProcess %c blocked\n\n", id);
					pthread_cond_wait(&notZero,&mutex);
				}
			s=s-1;
		}
		void signal(){
			s=s+1;
			pthread_cond_signal(&notZero);
		}
		monitor(){
			s=1;
			pthread_cond_init(&notZero,NULL);
			//printf("dsgdf\n");
		}
};
monitor obj;
void *callThread1(void *arg)
{
	char *k=(char *)arg;
	char id=*k;
	while(1)
	{	
		//monitor obj;
		//pthread_mutex_lock(&mutex);
		usleep(1000000);
	abc:	obj.wait(id);
		//usleep(1000000);
		printf("========================\nprocess A is in critical section\n===========================\n\n");
		usleep(1000000);
		printf("\t--------------------------------\n\tprocess A out of critical section\n\t--------------------------------\n\n");
		obj.signal();
		//pthread_mutex_unlock(&mutex);
		if(con%3!=0)
		usleep(1000000);
		else
			goto abc;
		con++;
	}
}
void *callThread2(void *arg)
{
	char *k=(char *)arg;
	char id=*k;
	while(1)
	{
		//monitor obj;
		//pthread_mutex_lock(&mutex);
		usleep(1000000);
		obj.wait(id);
		//usleep(1000000);
			  
		printf("========================\nprocess B is in critical section\n===========================\n\n");
		usleep(1000000);
		printf("\t--------------------------------\n\tprocess B out of critical section\n\t--------------------------------\n\n");
		obj.signal();
		//pthread_mutex_unlock(&mutex);
		usleep(1000000);
	}
}

int main()
{
	pthread_t tid1, tid2;
	char p='A', q='B';
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&tid1, NULL, &callThread1, &p);
	pthread_create(&tid2, NULL, &callThread2, &q);
	pthread_exit(NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
