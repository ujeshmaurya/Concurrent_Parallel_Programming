#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

/* Main Program */
main(int argc,char **argv)
{
	int  threadid,Noofthreads;

	omp_set_num_threads(atoi(argv[1])); 

	#pragma omp parallel private(threadid)
	{

		threadid = omp_get_thread_num();

		printf("\n\t\t My thread id is : %d\n", threadid);
	
	} 
}
	
	
	

