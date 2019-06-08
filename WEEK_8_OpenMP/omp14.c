#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc , char **argv)
{
	int Threadid, Noofthreads,i;
	printf("Parallel execution:\n");
	int sum=0;
#pragma omp parallel for
for(i=1;i<=atoi(argv[1]);i++)
{
#pragma omp critical
	sum+=i;
	printf("Sum = %d \n",sum);
}
printf("Final  sum: %d\n", sum);
printf("\nSequential execution:\n");
sum=0;
for(i=1;i<=atoi(argv[1]);i++)
{
	sum+=i;
	printf("Sum = %d \n",sum);
}
	return 0;
}



