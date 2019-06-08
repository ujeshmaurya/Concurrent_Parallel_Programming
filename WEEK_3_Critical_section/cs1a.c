#include<stdio.h>
#include<pthread.h>
int turn=0,timer=0,done1=0,done2=0;
void *fun1(void *arg)
{
	int *n=arg,i=0;
	int flag1=*n;
	while(1)
	{
		if(turn!=0)
		{
			while(turn!=0)
			{
				printf("0 is waiting at time= %d\n",timer);
				timer++;
				sleep(1);
			}
		}
		else
		{
			printf("0 is enjoying CS at time= %d\n",timer);
			timer++;
			turn=1;
			sleep(1);
		}
		i++;
	}
	done1=1;
	pthread_exit(NULL);	
}
void *fun2(void *arg)
{
	int *n=arg,i=0;
	int flag2=*n;
	while(1)
	{
		if(turn!=1)
		{
			
			while(turn!=1)
			{
				printf("1 is waiting at time= %d\n",timer);
				timer++;
				sleep(1);
			}
		}
		else
		{
			printf("1 is enjoying CS at time= %d\n",timer);
			timer++;
			turn=0;
			sleep(1);
		}
		i++;
	}
	done2=1;
	pthread_exit(NULL);	
}
int main()
{
	int i=0,j=1,k;
	pthread_t tid1,tid2;
	pthread_create(&tid1, NULL,fun1,&i);
	pthread_create(&tid2, NULL,fun2,&j);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
