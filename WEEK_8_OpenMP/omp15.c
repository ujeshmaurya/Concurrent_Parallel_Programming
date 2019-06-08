#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc , char **argv)
{
	int Threadid, Noofthreads,i;
	
	int a[100],n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int sum=0;
	printf("Parallel execution:\n");
#pragma omp parallel for
for(i=0;i<n;i++)
{
	#pragma omp critical
	sum+=a[i];
	printf("Sum = %d \n",sum);
}
printf("Final  sum: %d\n", sum);
printf("\nSequential execution:\n");
sum=0;
for(i=0;i<n;i++)
{
	sum+=a[i];
	printf("Sum = %d \n",sum);
}
	return 0;
}



