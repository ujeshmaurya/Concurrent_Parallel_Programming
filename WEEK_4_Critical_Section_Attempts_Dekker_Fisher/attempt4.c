#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

bool wantp = false, wantq = false;
int cnt=0,bff=0;
void *p() {
	while(1) {
		printf("\t\tp NON-CRITICAL SECTION\n\n");
		wantp = true;
		while(wantq != false) {
			wantp = false;
			printf("\t\tp Waiting...\n\n");
			bff++;
			/*if(bff>10)
			{
				bff=0;
				cnt=0;
				wantp = true;
				sleep(1);
			}*/
			wantp = true;
			if(cnt>3)
				sleep(2);
			else
				sleep(1);
		}
		{
			printf("\t\t==================\n");
			printf("\t\tp CRITICAL SECTION\n");
			printf("\t\t==================\n\n");
			sleep(1);
		}
		printf("\t\tp Out of Critical Section\n\n");
		wantp = false;
		cnt++;
	}
	pthread_exit(NULL);
}

void *q() {
	while(1) {
		printf("\tq NON-CRITICAL SECTION\n\n");
		wantq = true;
		while(wantp != false) {
			wantq = false;
			printf("\tq Waiting...\n\n");
			bff++;
			/*if(bff>10)
			{
				bff=0;
				cnt=0;
				wantq = true;
				sleep(1);
			}*/
			wantq = true;
			if(cnt>3)
				sleep(2);
			else
				sleep(1);
		}
		{
			printf("\t==================\n");
			printf("\tq CRITICAL SECTION\n");
			printf("\t==================\n\n");
			sleep(1);
		}
		printf("\tq Out of Critical Section\n\n");
		wantq = false;
		cnt++;
	}
	pthread_exit(NULL);
}

int main() {
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, p, NULL);
	pthread_create(&thread2, NULL, q, NULL);
	pthread_exit(NULL);
	return 0;
}
