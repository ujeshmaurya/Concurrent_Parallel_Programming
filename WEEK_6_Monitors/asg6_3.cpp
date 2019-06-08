#include<bits/stdc++.h>
#include<pthread.h>
#include <unistd.h>
using namespace std;
pthread_mutex_t mutex;
int con=0, n, data=1,srd=0;
class monitor
{
	public:
		int readers, writers, bk_writer, bk_reader;
		pthread_cond_t OKtoRead, OKtoWrite;
		//pthread_cond_init(&notZero,NULL);
			void StartRead(int id){
			if(writers!=0 || bk_writer!=0){
				
				bk_reader++;
				printf("Reader %d blocked\n",id);
				pthread_cond_wait(&OKtoRead, &mutex);
					
			}
			readers++;
			pthread_cond_signal(&OKtoRead);
		}
		
		void EndRead(int id){
			readers--;
			printf("Reader %d leaving database\n",id);
			if(readers==0){
				pthread_cond_signal(&OKtoWrite);
			}
			
		}

		void StartWrite(int id){
			if(writers!=0 || readers!=0){
				bk_writer++;		
				printf("Writer %d blocked\n",id);
				pthread_cond_wait(&OKtoWrite, &mutex);
			}
			writers++;
		}

		void EndWrite(int id){
			writers--;
			printf("Writer %d leaving database\n",id);
			if(bk_reader==0){
				pthread_cond_signal(&OKtoWrite);
			}
			else{
				pthread_cond_signal(&OKtoRead);
			}
			
		}
		monitor(){
			readers=0, writers=0, bk_writer=0, bk_reader=0;
			pthread_cond_init(&OKtoRead, NULL);
			pthread_cond_init(&OKtoWrite, NULL);
		}
};
monitor obj;
int reader_id=1 ,writer_id=1;

void *readerFunc(void *arg)
{
	while(1){
		
		obj.StartRead(reader_id);
		printf("***** Reader %d reading database *****\n\n",reader_id);
		usleep(1000000);
		obj.EndRead(reader_id);
		usleep(1000000);
		reader_id++;
	}
}

void *writerFunc(void *arg)
{
	while(1)
	{
		//usleep(1000000);
		obj.StartWrite(writer_id);
		printf("<<<<<< Writer %d writing database >>>>>> \n\n",writer_id);
		usleep(1000000);
		obj.EndWrite(writer_id);
		usleep(1000000);
		writer_id++;
	}
}

int main(){
	pthread_t reader, writer;
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&reader, NULL, &readerFunc, NULL);
	pthread_create(&writer, NULL, &writerFunc, NULL);
	pthread_exit(NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}

