#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc , char **argv)
{
	int Threadid, Noofthreads,i;
	printf("Parallel execution:\n");
#pragma omp parallel for
for(i=0;i<atoi(argv[1]);i++)
{
	printf("Hello world iteration no. = %d \n",i);
}
printf("Sequential execution:\n");
for(i=0;i<atoi(argv[1]);i++)
{
	printf("Hello world iteration no. = %d \n",i);
}
	return 0;
}



