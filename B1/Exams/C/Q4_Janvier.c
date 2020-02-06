//Quesiton 4 Exam Program Janvier
//Faire une fonction pour calculer e exposant x
//e^x = 1+x+x^2/2!+x^3/3!....x^n/n!
//Seulement x et k peuvent changer car ils son passer par l'utilisateur
//Il faut 2 fonctions avec des float

//Ca marche pas
//On saisi x et k pas x et e car e a deja une valeur

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fact(int);

int main(int argc, char const *argv[])
{
	int i;
	int temp;
	int e,x;
	float num,denum;
	float resultat = 1;

	do
	{
		printf("Entrez la valeur de e: ");
		fflush(stdin);
		scanf("%d",&e);
	}while(e<0);

	do
	{
		printf("Entrez la valeur de x: ");
		fflush(stdin);
		scanf("%d",&x);
	}while(x<0);


	for(i = 1;i < x;i++)
	{
		num = pow(x,i);
		denum = fact(i);
		temp = num / denum;
		resultat+= temp;
	}

	printf("%d^%d = %f\n",e,x,resultat);

	return 0;
}

int fact(int num)
{
	int i;
	int resultat=1;

	for(i = 0;i < num;i++)
	{
		resultat*=i;
	}

	return resultat;
}