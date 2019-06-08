#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc , char **argv)
{
	int Threadid, Noofthreads;


	omp_set_num_threads(atoi(argv[1])); 
#pragma omp parallel private(Threadid)
{
		Threadid = omp_get_thread_num();
		printf("\n\t\t Hello World is being printed by the thread : %d\n", Threadid);

		/*if (Threadid == 0) {
			Noofthreads = omp_get_num_threads();
			printf("\n\t\t Master thread printing total number of threads for this execution are : %d\n", Noofthreads);
		}*/
}

	return 0;
}



