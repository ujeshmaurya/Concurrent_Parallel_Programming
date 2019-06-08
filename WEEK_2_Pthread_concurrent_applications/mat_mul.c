#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define M 3
#define K 3
#define N 3

long int A [M][K] = { {1,2,3}, {3,2,1}, {1,2,3} };
long int B [K][N] = { {7,2,9}, {5,4,3}, {3,4,5} };
long int C [M][N];

struct node 
{
   int i;
   int j;
};
void *multiply(void *param) 
{
   struct node *matrix=param; 
   int n,sum=0; 
   for(n = 0; n< K; n++)
   {
      sum+=A[matrix->i][n]*B[n][matrix->j];
   }
   C[matrix->i][matrix->j]=sum;
   pthread_exit(0);
}

int main() 
{

   int i,j, count = 0;
   
   for(i=0;i<M;i++) 
   {
      for(j=0;j<N;j++) 
      {
         struct node *matrix=(struct node *)malloc(sizeof(struct node));
         matrix->i = i;
         matrix->j = j;
         pthread_t tid;       
         pthread_create(&tid,NULL,multiply,matrix);
         pthread_join(tid, NULL);
         count++;
      }
   }
   for(i=0;i<M;i++) 
   {
      for(j=0;j<N;j++) 
      {
         printf("%ld ", C[i][j]);
      }
      printf("\n");
   }
}

