//F point col
//Maximum de sa ligne
//Minimum d'une colone

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int max_Ligne(int,int,int *);
int min_Colonne(int,int,int *);

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int i,j;
	int max_ligne,min_colonne;
	int Max = 9,Min = 0;
	int tab[3][3]={
	{1,2,3},
	{4,5,6},
	{7,8,9}
	};
	int *pTab;
	pTab=&tab[0][0];

	/*
	//Remplissage aleatoire
	for(i = 0;i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			tab[i][j] = rand() % (Max - Min + 1) + Min; //Min = 0 Max = 5
			printf("Test\n");
		}
	}
	*/

	//Affichage du tableau
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d ",tab[i][j]);
		} 
		printf("\n");
	}

	//Trouver le point col Max ligne Min colonne
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			max_ligne =max_Ligne(i,j,pTab);
			min_colonne =min_Colonne(i,j,pTab);
			//printf("Valeur: %d Max: %d Min: %d\n",tab[i][j],max_ligne,min_colonne);
			if(max_ligne && min_colonne)
			{
				printf("Point col trouver: %d\n",tab[i][j]);
				printf("Indice: I:%d J:%d\n",i,j);
			}
		}
	}
	return 0;
}

int max_Ligne(int i,int j,int *pTab)
{
	int valeur,resultat=1;
	valeur=*(pTab+i*3+j);
	pTab+=i*3;
	for(i = 0; i < 3; i++)
	{
		if(*pTab > valeur)
		{
			resultat=0;
		}
		pTab++;
	}
	return resultat;
}


int min_Colonne(int i,int j,int *pTab)
{
	int valeur,resultat=1;
	valeur=*(pTab+i*3+j);
	pTab+=j;
	for(i = 0; i < 3; i++)
	{
		if(*pTab < valeur)
		{
			resultat=0;
		}
		pTab+=3;
	}
	return resultat;
}