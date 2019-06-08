#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>

void sighandler(int);
int c=0;
void *myThreadFun(void *vargp)
{
    sleep(1);
    int *n=vargp;
    int a=*n;
     pid_t id = syscall(__NR_gettid);
    printf("Hello!! Thread no. %d created and tid = %d\n",a,id);
	pthread_exit(NULL);	
}	
int main()
{
   signal(SIGINT,sighandler);
   pthread_t tid[100000];
	int i=0;
   while(1) 
   {
      pthread_create(&tid[i], NULL, myThreadFun,&i);
	pthread_join(tid[i], NULL); 	
      c++;
      i++;
   }
   return(0);
}

void sighandler(int signum)
{
   printf("\nTotal processes done till now : %d\n", c);
   exit(1);
}
