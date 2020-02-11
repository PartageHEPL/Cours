#include "pthread.h"
#include "stdlib.h"
#include "stdio.h"
#include "signal.h"
#include "string.h"
#include "unistd.h"

void* Thread(void* s);
void HandlerInt(int s);

int main()
{
	//SIGINT
	struct sigaction A;
	A.sa_handler = HandlerInt;
	A.sa_flags = 0;
	sigemptyset(&A.sa_mask);
	sigaction(SIGINT,&A,NULL);

	//On crée les 4 threads
	pthread_create(NULL,NULL,Thread,NULL);
	pthread_create(NULL,NULL,Thread,NULL);
	pthread_create(NULL,NULL,Thread,NULL);
	pthread_create(NULL,NULL,Thread,NULL);
	pause();
	
	//Soit pthread_exit(NULL) soit exit(0)
	
	pthread_exit(NULL);			//=> On dois faire 5 fois ctrl-c pour envoyer le signal a chaque thread_t
	//exit(0);					//=> On envoye une fois le signal et le thread pricipal va le recevoir et tuer tout les threads
								//=> C'est mieux d'utiliser pthread_exit
}


void* Thread(void* s)
{
	printf("Thread: PID = %d TID = %d\n",getpid(),pthread_self());
	pause();
	pthread_exit(NULL);
}


void HandlerInt(int s)
{
	printf("HandlerInt => Fin du thread PID = %d TID = %d\n",getpid(),pthread_self());
}







