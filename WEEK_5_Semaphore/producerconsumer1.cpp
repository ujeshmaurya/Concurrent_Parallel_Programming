#include <bits/stdc++.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;
sem_t notempty;
vector<int> buffer;
void *produce(void* id) {
	while(1)
	{
		//ncs_begin
		
		//ncs_end
	
		//waiting_process_begin
		//sem_wait(&mutex);
		usleep(1000000);
		cout<<"\tproducer is producing\n";
		//waiting_process_end()
		
		//critical_section_begin
		cout<<"\t|================================|\n";
		cout<<"\t|Producer is in Critical Section |"<<endl;
		buffer.push_back(1);
		cout<<"\t|Size of buffer= "<<buffer.size()<<"    \t\t|\n";
		cout<<"\t|================================|\n\n";
		cout<<"\tProducer is out of Critical Section"<<endl<<endl;
		//critical_section_ends
		
		//post_critical_section_start
		sem_post(&notempty);
		cout<<"\tProducer called Signal()"<<endl<<endl;
		usleep(1000000);
		//post_critcal_section_finish
	}
	pthread_exit(NULL);
}

void *consume(void* id) {
	while(1)
	{
		//ncs_begin
		
		//ncs_end

		
		//waiting_process_begin
		cout<<"\t\tConsumer is waiting\n	";
		sem_wait(&notempty);
		go:
		if(buffer.empty()==true	)
		{
			printf("Consumer cant consume, buffer is empty\n");
			usleep(1000000);
			goto go;
		}
		//waiting_process_end()


		//critical_section_begin
		cout<<"\t\t|================================|\n";
		cout<<"\t\t|Consumer is in Critical Section |"<<endl;
		buffer.pop_back();
		cout<<"\t\t|Size of buffer= "<<buffer.size()<<"    \t\t|\n";
		cout<<"\t\t|================================|\n\n";
		cout<<"\t\tConsumer is out of Critical Section"<<endl;
		//critical_section_ends


		//post_critical_section_start
		//sem_post(&mutex);
		//cout<<"\t\t"<<id2<<" called Signal()"<<endl<<endl;
		usleep(1000000);
		//post_critcal_section_finish
	}
	pthread_exit(NULL);
}
int main() 
{
	pthread_t thread1, thread2;
	sem_init(&notempty, 0, 0);
	int id1=1,id2=2;
	pthread_create(&thread1, NULL, &produce, &id1);
	pthread_create(&thread2, NULL, &consume, &id2);
	pthread_exit(NULL);
	return 0;
}
