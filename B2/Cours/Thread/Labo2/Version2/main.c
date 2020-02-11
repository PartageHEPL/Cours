#include "pthread.h"
#include "stdlib.h"
#include "stdio.h"
#include "signal.h"
#include "string.h"
#include "unistd.h"

void* Thread(void* s);
void HandlerInt(int s);
void HandlerSIGUSR1(int s);

int main()
{
	//Le main ne peut recevoir que des SIGINT donc on bloque SIGUSER1
	
	//SIGINT
	struct sigaction A;
	A.sa_handler = HandlerInt;
	A.sa_flags = 0;
	sigemptyset(&A.sa_mask);
	sigaction(SIGINT,&A,NULL);
	
	//On masque le SIGUSER1 dans le main
	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask,SIGUSR1);
	sigprocmask(SIG_SETMASK,&mask,NULL);
	
	//On crée les 4 threads
	pthread_create(NULL,NULL,Thread,NULL);
	pthread_create(NULL,NULL,Thread,NULL);
	pthread_create(NULL,NULL,Thread,NULL);
	pthread_create(NULL,NULL,Thread,NULL);
	//On a besoin de faire 4 pauses car le main dois recevoir 4 signaux pour kill les 4 threads
	pause();
	pause();
	pause();
	pause();
	
	pthread_exit(NULL);
	//exit(0);					//=> On peut faire le exit qu'on souhaite car les thread seront deja morts si on a fait 4 pause dans le main
}


void* Thread(void* s)
{
	//Les threads ne peuvent recevoir qu'un SIGUSER1 donc il faut faire un sig action
	//sur le SIGUSER1 et bloquer la reception d'un SIGINT
	
	//SIGUSER1
	struct sigaction B;
	B.sa_handler = HandlerSIGUSR1;
	B.sa_flags = 0;
	sigemptyset(&B.sa_mask);
	sigaction(SIGUSR1,&B,NULL);
	//On bloque le SIGINT dans les threads
	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask,SIGINT);
	sigprocmask(SIG_SETMASK,&mask,NULL);
	
	//On affiche le PID et TID au début du thread
	printf("Debut Thread: PID = %d TID = %d\n",getpid(),pthread_self());
	//Le thread se met ne pause en attendant la reception d'un signal SIGUSER1
	pause();
	//Le thread se fini proprement
	pthread_exit(NULL);
}


void HandlerInt(int s)
{	
	printf("HandlerInt => PID = %d TID = %d\n",getpid(),pthread_self());
	kill(getpid(),SIGUSR1);	
}

void HandlerSIGUSR1(int s)
{
	printf("HandlerSIGUSR1 => Fin du thread PID = %d TID = %d\n",getpid(),pthread_self());
}











