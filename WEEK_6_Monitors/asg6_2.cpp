#include<bits/stdc++.h>
#include<pthread.h>
#include <unistd.h>
using namespace std;
pthread_mutex_t mutex;
int con=0, n, data=1,srd=0,f=0;
class monitor
{
	public:
		int s, curr_size, cnt,asd;
		queue <int> fin_buffer;
		pthread_cond_t notEmpty, notFull;
		//pthread_cond_init(&notZero,NULL);
		void append(int d){
			if(curr_size==n){
				cnt++;
				if(cnt%2==0){
					while(!fin_buffer.empty()){
						int k=fin_buffer.front();
						printf("<<<<< CONSUMER CONSUMING DATA %d>>>>> \n\n", k);
						fin_buffer.pop();
						curr_size--;
									
						//usleep(1000000);
					}
					if(asd%2!=0)
						f=1;	
					asd++;
				}
				else{
					printf("\tProducer blocked\n\n");
					pthread_cond_wait(&notFull, &mutex);
				}
			//if(f==1);
				
			}
			//if(cnt%3==0)f=1;
			if(f==0)
			{
			fin_buffer.push(d);
			curr_size++;
			pthread_cond_signal(&notEmpty);
			}
		}
		int take(){
			if(curr_size==0){
				printf("\tConsumer blocked\n\n");
				pthread_cond_wait(&notEmpty, &mutex);
			}
			int k=fin_buffer.front();
			fin_buffer.pop();
			curr_size--;
			pthread_cond_signal(&notFull);
			return k;
		}
		monitor(){
			s=1; curr_size=0; cnt=0,asd=0;
			pthread_cond_init(&notEmpty, NULL);
			pthread_cond_init(&notFull, NULL);
		}
};
monitor obj;
void *producerFunc(void *arg)
{
	while(1){
		if(srd%3==0)
			usleep(1000000);
		else
			usleep(3000000);
		
		obj.append(data);
		if(f==0)
		printf("*****PRODUCER PRODUCING DATA %d*****\n\n", data);
		f=0;
		data++;
		usleep(1000000);
		srd++;
	}
}

void *consumerFunc(void *arg)
{
	while(1)
	{
		usleep(4000000);
		int k=obj.take();
		printf("<<<<<< CONSUMER CONSUMING DATA %d>>>>>> \n\n", k);
		usleep(3000000);
	}
}

int main(){
	cout<<"Enter size of buffer: "<<endl;
	cin>>n;
	pthread_t producer, consumer;
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&producer, NULL, &producerFunc, NULL);
	pthread_create(&consumer, NULL, &consumerFunc, NULL);
	pthread_exit(NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}

