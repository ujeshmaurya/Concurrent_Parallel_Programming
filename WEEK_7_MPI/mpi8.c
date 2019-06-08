#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[]){
	int rank, numprocs, src, dest, data, sum = 0;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	if(rank == 0){
		MPI_Send(&rank, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}
	else{
		src = rank-1;
		MPI_Recv(&data, 1, MPI_INT, src, 0, MPI_COMM_WORLD, &status);
		sum = rank + data;
		printf("process no is %d and Sum is :%d\n",rank,sum);
		dest = (rank + 1)%numprocs;
		MPI_Send(&sum, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
	}
	if(rank==0){
		src = numprocs-1;
		MPI_Recv(&sum, 1, MPI_INT, src, 0, MPI_COMM_WORLD, &status);
		printf("process no is %d and Sum is :0\n",rank);
	}
	MPI_Finalize();
	return 0;
}
