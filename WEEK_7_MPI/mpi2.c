#include<stdio.h>
#include<string.h>
#include<mpi.h>
#define BUFFER_SIZE 100
int main(int argc, char *argv[]){
  int rank, numprocs, src, dest, src_tag, dest_tag;
  int root=0, len_name, l, i;
  char proc_name[100], proc_name_root[100];
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  for(i=0; i<numprocs; i++){
    if(i==rank)continue;
    char msg[]="HELLO WORLD";
    l = strlen(msg);
    dest = i;
    dest_tag = 0;
    printf("Process with rank %d sending msg %s to process with rank %d\n", rank, msg, i);
    MPI_Send(msg, l, MPI_CHAR, dest, dest_tag, MPI_COMM_WORLD);
  }
  for(i=0; i<numprocs; i++){
    if(i==rank)continue;
    char rmsg[BUFFER_SIZE];
    src=i, src_tag=0;
    MPI_Recv(rmsg, BUFFER_SIZE, MPI_CHAR, src, src_tag, MPI_COMM_WORLD, &status);
    printf("Process %d received msg %s from process %d\n", rank, rmsg, src);
  }
  MPI_Finalize();
  return 0;
}
