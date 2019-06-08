#include <stdio.h>
#include <pthread.h>

int turn = 1, cnt = 0;

void *p() {
	while(1) {
		printf("\t\tp NON-CRITICAL SECTION\n\n");
		while(turn != 1) {
			printf("\t\tp Waiting...\n\n");
			sleep(5);
		}
		{
			printf("\t\t==================\n");
			printf("\t\tp CRITICAL SECTION\n");
			printf("\t\t==================\n\n");
		}
		sleep(7);
		printf("\t\tp Out of Critical Section\n\n");
		cnt++;
		if (cnt == 3) pthread_exit(NULL);
		turn = 2;
	}
	pthread_exit(NULL);
}

void *q() {
	while(1) {
		printf("\tq NON-CRITICAL SECTION\n\n");
		while(turn != 2) {
			printf("\tq Waiting...\n\n");
			sleep(5);
		}
		{
			printf("\t==================\n");
			printf("\tq CRITICAL SECTION\n");
			printf("\t==================\n\n");
		}
		sleep(7);
		printf("\tq Out of Critical Section\n\n");
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
