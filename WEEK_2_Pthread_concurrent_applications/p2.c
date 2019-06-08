#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
void *myThreadFun(void *vargp)
{
    int *n=vargp;
    int a=*n;
    int *ans=(int*)malloc(sizeof(int));
    *ans=(a*(a+1)*(2*a+1))/6;
    pthread_exit(ans);
}	
  
int main()
{
    pthread_t tid;
    int i,n;
    void *ans;
    scanf("%d",&n);
	pthread_create(&tid, NULL, myThreadFun,&n);
	pthread_join(tid,&ans);
	int *ansa=ans;
	printf("Sum of series til %d is %d\n",n,*ansa);
    return 0;
}
