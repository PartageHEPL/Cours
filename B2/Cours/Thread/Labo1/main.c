#include "pthread.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

void* Fct(void* p);

typedef struct
{
	pthread_t tid;
	char mot[32];
	char fichier[32];
	int* valeurRetour;
	int nbrThread; 
}INFO;

int main()
{
	INFO t1,t2,t3,t4;
	t1.tid = NULL;
	strcpy(t1.mot,"cout");
	strcpy(t1.fichier,"fichier2.cpp");
	t1.valeurRetour = NULL;
	t1.nbrThread = 0;
	t2.tid = NULL;
	strcpy(t2.mot,"Debug");
	strcpy(t2.fichier,"fichier2.cpp");
	t2.valeurRetour = NULL;
	t2.nbrThread = 1;
	t3.tid = NULL;
	strcpy(t3.mot,"<<");
	strcpy(t3.fichier,"fichier2.cpp");
	t3.valeurRetour = NULL;
	t3.nbrThread = 2;
	t4.tid = NULL;
	strcpy(t4.mot,"{");
	strcpy(t4.fichier,"fichier2.cpp");
	t4.valeurRetour = NULL;
	t4.nbrThread = 3;

	pthread_create(&t1.tid,NULL,Fct,(void*)&t1);
	pthread_create(&t2.tid,NULL,Fct,(void*)&t2);
	pthread_create(&t3.tid,NULL,Fct,(void*)&t3);
	pthread_create(&t4.tid,NULL,Fct,(void*)&t4);
	
	pthread_join(t1.tid,(void**)&(t1.valeurRetour));
	pthread_join(t2.tid,(void**)&(t2.valeurRetour));
	pthread_join(t3.tid,(void**)&(t3.valeurRetour));
	pthread_join(t4.tid,(void**)&(t4.valeurRetour));
		
	printf("Le mot %s a ete trouve %d fois!\n",t1.mot,*t1.valeurRetour);
	printf("Le mot %s a ete trouve %d fois!\n",t2.mot,*t2.valeurRetour);
	printf("Le mot %s a ete trouve %d fois!\n",t3.mot,*t3.valeurRetour);
	printf("Le mot %s a ete trouve %d fois!\n",t4.mot,*t4.valeurRetour);
	
	free(t1.valeurRetour);
	free(t2.valeurRetour);
	free(t3.valeurRetour);
	free(t4.valeurRetour);
	
	
	
	return 0;
}


void* Fct(void* p)
{
	int continuer = 1;
	int* compteur = (int*)malloc(sizeof(int));
	*compteur = 1;
	int position = 0;
	char buff[32];
	INFO *pInfo = (INFO*)p;
	
	while(continuer)
	{
		FILE* fichier = fopen(pInfo->fichier,"r");
		if(fichier == NULL)
		{
			printf("Erreur lors de l'ouverture du fichier %s",pInfo->fichier);
			continuer = 0;
		}
		else
		{
			for(int i = 0; i < pInfo->nbrThread; i++)
			{
				printf("\t");
			}
			printf("*\n");
			fseek(fichier,position,SEEK_SET);
			if(fread(&buff,strlen(pInfo->mot),1,fichier) != 1)
			{
				//On a atteins la fin du fichier
				continuer = 0;
			}
			else
			{
				//printf("-%s-",buff);
				buff[strlen(pInfo->mot)] = '\0';
				if(strcmp(buff,pInfo->mot) == 0)
				{
					(*compteur)++;
				}
			}
		}
		position += 1;
		fclose(fichier);
	}
	
	pthread_exit(compteur);
}

























