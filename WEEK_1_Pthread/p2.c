#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
void *myThreadFun(void *vargp)
{
    sleep(1);
    int a=(int)vargp;
    printf("Sum till %d is %d\n",a,(a*(a+1))/2);
    return NULL;
}	
  
int main()
{
    pthread_t tid;
    int i,n;
    scanf("%d",&n);
	pthread_create(&tid, NULL, myThreadFun,(void *)n);
	pthread_exit(NULL);	
    exit(0);
}
