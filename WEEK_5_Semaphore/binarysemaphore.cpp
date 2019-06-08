#include <bits/stdc++.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;
sem_t mutex;
int ind=0;
void *p(void* id) {
	while(1)
	{
		//ncs_begin
		int *idd=(int*)id;
		int id1=*idd;
		//ncs_end
	
		//waiting_process_begin
		usleep(1500000);
		sem_wait(&mutex);
		lab:
		cout<<"\t"<<id1<<" is waiting"<<endl;
		
		//waiting_process_end()
		
		//critical_section_begin
		cout<<"\t|================================|\n";
		cout<<"\t|"<<id1<<" is in Critical Section        |"<<endl;
		cout<<"\t|================================|\n\n";
		cout<<"\t"<<id1<<" is out of Critical Section"<<endl<<endl;
		//critical_section_ends
		
		//post_critical_section_start
		sem_post(&mutex);
		cout<<"\t"<<id1<<" called Signal()"<<endl<<endl;
		ind++;
		if(ind%4!=0)
			usleep(1000000);
		else
			goto lab;
		//post_critcal_section_finish
		
	}
	pthread_exit(NULL);
}

void *q(void* id) {
	while(1)
	{
		//ncs_begin
		int *idd=(int*)id;
		int id2=*idd;
		//ncs_end


		//waiting_process_begin
		cout<<"\t\t"<<id2<<" is waiting"<<endl;
		sem_wait(&mutex);
		usleep(1000000);
		//waiting_process_end()


		//critical_section_begin
		cout<<"\t\t|================================|\n";
		cout<<"\t\t|"<<id2<<" is in Critical Section        |"<<endl;
		cout<<"\t\t|================================|\n\n";
		cout<<"\t\t"<<id2<<" is out of Critical Section"<<endl;
		//critical_section_ends


		//post_critical_section_start
		sem_post(&mutex);
		cout<<"\t\t"<<id2<<" called Signal()"<<endl<<endl;
		usleep(1500000);
		//post_critcal_section_finish
	}
	pthread_exit(NULL);
}
int main() 
{
	pthread_t thread1, thread2;
	sem_init(&mutex, 0, 1);
	int id1=1,id2=2;
	pthread_create(&thread1, NULL, &p, &id1);
	pthread_create(&thread2, NULL, &q, &id2);
	pthread_exit(NULL);
	return 0;
}
