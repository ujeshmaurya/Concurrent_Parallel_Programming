#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

bool wantp = false, wantq = false;
int turn = 1;

void *p() {
	while(1) {
		printf("\t\tp NON-CRITICAL SECTION\n\n");
		wantp = true;
		while(wantq != false) {
			if (turn == 2) {
				wantp = false;
				while(turn != 1) {
					printf("\t\tp Waiting...\n\n");
					sleep(1);
				}
				wantp = true;
			}
		}
		{
			printf("\t\t==================\n");
			printf("\t\tp CRITICAL SECTION\n");
			printf("\t\t==================\n\n");
			sleep(1);
		}
		printf("\t\tp Out of Critical Section\n\n");
		turn = 2;
		wantp = false;
	}
	pthread_exit(NULL);
}

void *q() {
	while(1) {
		printf("\tq NON-CRITICAL SECTION\n\n");
		wantq = true;
		while(wantp != false) {
			if (turn == 1) {
				wantq = false;
				while(turn != 2) {
					printf("\tq Waiting...\n\n");
					sleep(1);
				}
				wantq = true;
			}
		}
		{
			printf("\t==================\n");
			printf("\tq CRITICAL SECTION\n");
			printf("\t==================\n\n");
			sleep(1);
		}
		printf("\tq Out of Critical Section\n\n");
		wantq = false;
		turn = 1;
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
