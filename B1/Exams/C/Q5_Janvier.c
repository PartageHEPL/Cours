//Tableau de 20 par 16 avec des chaines de caractere par ligne
//On dois parcourir le tableau et prendre la taille du mot et le placer dans le vecteur pour compter le nombre de mots
//La case v[0] dois contenir le nombre de mot de 15 caractere de longeur
//La case v[14] dois contenier le nombre de mot de 1 caractere de longeur

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	char tab[20][16]={
		{'j','e'},
		{'v','o','u','s'},
		{'t','r','o','u','v','e'},
		{'t','r','e','s'},
		{'t','e','s','t'},
		{'m','o','t'},
	};
	int v[15]={0};
	int taille;
	int i,j;
	char *pointeur;
	pointeur=&tab[0][0];

	//Parcourir le vecteur et calculer la taille
	for(i = 0;i < 15;i++)
	{
		taille = strlen(pointeur);
		v[15-taille]++;
		pointeur+=16;
	}

	//Afficher le tableau
	printf("Tableau:\n");
	for(i = 0;i < 15;i++)
	{
		for(j = 0;j <15;j++)
		{
			printf("%c",tab[i][j]);
		}
		printf("\n");
	}

	//Afficher le vecteur
	printf("\nVecteur:\n");
	for(i = 0;i < 15;i++)
	{
		printf("Case %d (mot de %d lettres) = %d\n",i,i+1,v[i]);
	}


	return 0;
}