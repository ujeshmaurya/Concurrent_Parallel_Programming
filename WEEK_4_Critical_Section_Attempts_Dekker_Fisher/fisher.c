#include <stdio.h>
#include <pthread.h>

int id=0;

void test(int i){
	L : if(id != 0)
			goto L;
		id = i;
		sleep(1);
		if( id != i)
			goto L;
		printf("\t\t%d in crit\n ",i);
		id = 0;
		printf("\t\t\t\t%d out crit\n\n",i);
}

int main(){
	pthread_t t1,t2,t3,t4;
	pthread_create(&t1,NULL,(void*)&test,(void*)1);
	pthread_create(&t2,NULL,(void*)&test,(void*)2);
	pthread_create(&t3,NULL,(void*)&test,(void*)3);
	pthread_create(&t4,NULL,(void*)&test,(void*)4);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	printf("\nParent terminated\n");
	return(0);
}
