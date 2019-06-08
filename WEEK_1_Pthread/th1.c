#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<math.h>
 
// A normal C function that is executed as a thread when its name
// is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}
  
void *fun(void *c)
{
	printf("HELLO\n") ;
	return NULL ;
} 

struct node
{
int a[100],s ;
}; 

void *fun2( void *b)
{
	int i ;
	
	struct node *a= b; 
	

	for(i=0 ; i<(*a).s ;i++)
		printf("%d " ,(*a).a[i]) ;
	printf("\n") ;
	
return NULL ;
}
  

void *fun3(void *b)
{
	int *n = b ;
	
	float *f ;
		
	f =calloc(100 , sizeof(float))	 ;
	
	int i=0 ;
		
	for( ; *n<=100 ;(*n)++ )	
		f[i++] = 	 sqrt(*n) ; ;
		
	printf("%d  ",*n) ;
	
	pthread_exit(f) ;
	
}
  
  
int main()
{
/*    pthread_t tid;
    printf("Before Thread\n");
    pthread_create(&tid, NULL, myThreadFun, NULL );
    pthread_join(tid, NULL);
    printf("After Thread\n");
*/    
    
    
	printf("\nnew\n\n") ;
    
    pthread_t t1,t2 ;
    
    char c[]="hello"; 
    
    pthread_create(&t1  ,NULL , fun , NULL) ;
		
		pthread_join(t1,NULL) ;
		
/*					------------- 1 -------------------
int i; 
	for( i=0 ; i<5 ;i++)
	{
		pthread_create(&t1  ,NULL , fun , NULL) ;
		
		pthread_join(t1,NULL) ;
    }
*/    
    
    
    int a[]={0,1,2,3,4,5} ;
    
    pthread_t t; 
    
    int s=6 ,i;
    
    struct node b ;
    b.s=6 ;
    
    for( i=0 ; i<b.s ;i++ ) b.a[i]=i ;
    
    pthread_create( &t , NULL , fun2 , &b) ;
    
    pthread_join( t , NULL) ; 
    
    for( i=1 ; i<=1 ;i++ )
	{
		pthread_create( &t , NULL , fun3 , &i ); 

		void *b; 

		pthread_join( t,&b ); 

		float *f=b ;
		
		for( i=0 ; i<100 ;i++ )
			printf("%f\n",f[i]) ;
		
	}    
    
    
    exit(0);
}
