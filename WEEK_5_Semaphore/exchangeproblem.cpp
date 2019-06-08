#include<bits/stdc++.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
void exchange(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int common=1;
void *callThread1(void *arg){
	int local1=0;	
	while(1){	
		sleep(2);
		cout<<"\n\tProcess p in non-critical section\n";
		do{
			exchange(&common, &local1);
		}
		while(local1!=1);
		cout<<"\n\t\t=============================\n\t\tProcess p in critical section\n\t\t=============================\n\n";
		cout<<"\tProcess p out of critical section\n";
		exchange(&common, &local1);
		sleep(2);
	}
}
void *callThread2(void *arg){
	int local2=0;	
	while(1){	
		sleep(2);
		cout<<"\n\tProcess q in non-critical section\n";
		do{
			exchange(&common, &local2);
		}
		while(local2!=1);
		cout<<"\n\t\t=============================\n\t\tProcess q in critical section\n\t\t=============================\n\n";
		cout<<"\tProcess q out of critical section\n";
		exchange(&common, &local2);
		sleep(2);
	}
}

int main(){
	pthread_t p, q;
	pthread_create(&p, NULL, &callThread1, NULL);
	pthread_create(&q, NULL, &callThread2, NULL);
	pthread_exit(NULL);
	return 0;
}
