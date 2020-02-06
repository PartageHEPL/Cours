#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	double a,b,x,S,dx,fx;
	int i,n,choix = -1;

	printf("Menu:\n");
	printf("0. Triangles Inferieur\n");
	printf("1. Triangles Superieur\n");
	do
	{
		printf("Quel est votre choix? ");
		fflush(stdin);
		scanf("%d",&choix);
	}while(choix < 0 || choix > 3);

	//Initialiser a,b,n
	a = 0;
	b = 1;
	n = 10;		//Le nombre de rectangle que l'on veut on peut metttre 100 ou 1000 sur pc mais papier 10 (plus simple)

	//Calcule de dx
	dx = (b - a)/n;

	//
	S = 0;
	x = a;

	//Boucle
	for(i = 0; i < n; i++)
	{
		switch(choix)
		{
			case 0:
				S = S + fx;
				fx = pow(x,2);
				x = x + dx;
				break;
			case 1:
				x = x + dx;
				fx = pow(x,2);
				S = S + fx;
				break;
		}
	}

	//Calule final
	S = S *dx;

	printf("S = %lf\n",S);

	return 0;
}