#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#include <signal.h>

#include "Fichier.ini"
#include "Ecran.h"

int idQ;


MESSAGE Message,MessageRecu;

int main()
{
	idQ = msgget(CLE,IPC_CREAT | IPC_EXCL | 0666);
	printf("Idq: %d\n",idQ);	
	
	//Le server lis le message sur le file
	if(msgrcv(idQ,&MessageRecu,255,1,0) == -1)
	{
		perror("Erreur lors de msgrcv");
		exit(1);
	}
	printf("--%s--\n",MessageRecu.M);
	
	//Le server renvoye le message
	MessageRecu.Type = MessageRecu.Pid;
	if(msgsnd(idQ,&Message,32,0) == -1)
	{
		perror("Erreur lors de msgsnd");
		exit(1);
	}
}
