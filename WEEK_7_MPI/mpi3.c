#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[])
{
	int rank, src, dest, numprocs, i, no, sum=0;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	if(rank==0){
		for(i=1; i<numprocs; i++){
			MPI_Recv(&no, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
			sum+=no;
		}
		printf("SUM IS: %d\n", sum+numprocs);
	}
	else{
		MPI_Send(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}
