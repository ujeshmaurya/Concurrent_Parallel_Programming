#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int rank, numprocs, src, dest, data, sum = 0;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	char buf[100];
	int l;
	if(rank == 0)
	{
		strcpy(buf,"Hello world");
		l=strlen(buf);
	}
	MPI_Bcast (buf,13, MPI_CHAR,0, MPI_COMM_WORLD);
	printf("Process %d Recieved %s\n",rank,buf);
	MPI_Finalize();
	return 0;
}
