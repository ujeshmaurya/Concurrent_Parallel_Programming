#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define  LOG2(x)    log10((double)(x)) / log10((double) 2)
int main(int argc, char *argv[])
{
	int rank, numprocs, src, dest, data, i, no1, no2, sum = 0;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	double height = LOG2(numprocs);
	if(ceil(height) != floor(height))
	{
		printf("Number should be exact power of 2\n");
		return 1;
	}
	sum = rank;
	for(i = 0; i < (int)height; i++)
	{
		no1 = pow(2, i);
		if(rank%no1 == 0)
		{
			no2 = pow(2, i+1);
			if(rank%no2 == 0)
			{
				MPI_Recv(&data, 1, MPI_INT, rank + no1, 0, MPI_COMM_WORLD, &status);
				sum = sum + data;
			}
			else
			{
				MPI_Send(&sum, 1, MPI_INT, rank - no1, 0, MPI_COMM_WORLD);

			}
		}
	}
	if(rank == 0)
	{
		printf("SUM IS: %d\n", sum + numprocs);
	}
	MPI_Finalize();
	return 0;
}
