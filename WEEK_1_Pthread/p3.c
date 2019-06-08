#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
 
void *calc(void *vargp)
{
    double a[100];
    int i;
    void *ap;
    for(i=0;i<100;i++)
    	a[i]=sqrt(i),printf("%.2lf \t",a[i]);
	void *ap;
	ap=(void*)a;
	return ap;
}	
void *show(double* p)
{
	/*double *p;
	p=*((double*)vargp);*/
	int i;
	
	for(i=0;i<100;i++)
		printf("%.2lf \t",p[i]);
	printf("\n");
	return NULL;	
}
int main()
{
    pthread_t tid,tid2;
    int i,n;
    double *p;
	pthread_create(&tid, NULL, calc,NULL);
	//p=pthread_join(tid, NULL);
	p=(double *)calc(
	//pthread_create(&tid2, NULL, show, p);
	//pthread_join(tid2, NULL);
    exit(0);
}
