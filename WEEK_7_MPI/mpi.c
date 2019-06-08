#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>

#define Size 100

int main(int argc, char *argv[])
{
	
	int Myrank,NoOfProcess,i;
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&Myrank);
	MPI_Comm_size(MPI_COMM_WORLD,&NoOfProcess);
	
	if(Myrank!=0)
		{
			char buf[]="Hello World!!";
			int l=strlen(buf);
			printf("sending\n");
			MPI_Send(buf,l,MPI_CHAR,0,0,MPI_COMM_WORLD);
		}
	else
		{
			char recbuf[200];
			for(i=1;i<NoOfProcess;i++)
			{
				MPI_Recv(recbuf,200,MPI_CHAR,MPI_ANY_SOURCE,0,MPI_COMM_WORLD,&status);
				printf("P:%d Got data from processor %d \n",Myrank,status.MPI_SOURCE);
			}
		}	
	MPI_Finalize();
	return 0;
}
