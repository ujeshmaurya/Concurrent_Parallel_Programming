#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
void *myThreadFun(void *vargp)
{
    sleep(1);
    int a=(int)vargp;
    printf("Hello %d\n",a);
    return NULL;
}	
  
int main()
{
    pthread_t tid[5];
    int i,ch;
    for(i=0;i<5;i++)
    {
			pthread_create(&tid[i], NULL, myThreadFun,(void *)i);
			pthread_join(tid[i], NULL);
	}
	pthread_exit(NULL);	
    exit(0);
}
