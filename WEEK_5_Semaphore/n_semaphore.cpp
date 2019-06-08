#include<bits/stdc++.h>
#include<pthread.h>
#include<cstdio>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
using namespace std;

sem_t mutex;
int CSvalue=0;

void *p(void* id) {
	while(1)
	{
		//ncs_begin
		int *idd=(int*)id;
		int id1=*idd;
		//ncs_end
	
		//waiting_process_begin
		sem_wait (&mutex);
		cout<<"\t"<<id1<<" is waiting"<<endl;
		usleep(1500000+id1*100000);
		//waiting_process_end()
		
		//critical_section_begin
		cout<<"\t\t\t================================\n\n";
		cout<<"\t\t\t"<<id1<<" is in Critical Section CSvalue="<<(++CSvalue)<<endl<<endl;
		cout<<"\t\t\t================================\n\n";
		cout<<"\t"<<id1<<" is out of Critical Section"<<endl<<endl;
		//critical_section_ends
		
		//post_critical_section_start
		sem_post (&mutex);
		cout<<"\t"<<id1<<" called Signal()"<<endl<<endl;
		usleep(1000000+id1*100000);
		//post_critcal_section_finish
	}
	pthread_exit(NULL);
}
//driver code
int main(int argc,char* argv[]) //value of 'n' using command line arguments
{
	int n=atoi(argv[1]);
	pthread_t thread[n];
	sem_init(&mutex, 0, 1);
	int id[n];
	for(int i=0;i<n;i++)
	{
		id[i]=i+1;
		pthread_create(&thread[i], NULL, &p, &id[i]);
	}
	pthread_exit(NULL);
	return 0;
}
