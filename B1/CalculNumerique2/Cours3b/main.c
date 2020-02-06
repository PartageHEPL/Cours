#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	double x1,x2,y1,y2;
	double xs[] = {16,17,18,19,20,21,22};
	double ys[] = {0,0.0122,0.1585,0.4390,0.8171,0.9756,1};
	char mode;
	double valeur;
	double resultatX = 0,resultatY = 0;
	int i,nbr = 7;

	//Initialiser
	strcpy(&mode,argv[1]);
	valeur = atof(argv[2]);



	//Mode
	if(mode == 'x' || mode == 'X')
	{
		for(i = 0;i < nbr && valeur > xs[i]; i++)
		{

		}
		i--;
		y1 = ys[i + 1];
		y2 = ys[i + 2]; 
		x1 = xs[i + 1];
		x2 = xs[i + 2];
		printf("X1: %lf\n",x1);
		printf("X2: %lf\n",x2);
		printf("Y1: %lf\n",y1);
		printf("Y2: %lf\n",y2);
		printf("valeur: %lf\n",valeur);

		if(valeur < x1 || valeur > x2)
		{
			//On est en dehors des bornes du segent
			printf("La valeur de x est en dehors du segment!\n");
		}
		else
		{
			//Calculer Y
			resultatY = ((y2 - y1)/(x2 - x1) ) * (valeur - x1) + y1;
			printf("Y vaut %lf\n",resultatY);
		}
		
	}
	else if(mode == 'y' || mode == 'Y')
	{
		for(i = 0;i < nbr && (valeur > ys[i]); i++)
		{
			
		}
		i--;
		y1 = ys[i];
		y2 = ys[i + 1]; 
		x1 = xs[i];
		x2 = xs[i + 1];
		printf("X1: %lf\n",x1);
		printf("X2: %lf\n",x2);
		printf("Y1: %lf\n",y1);
		printf("Y2: %lf\n",y2);
		printf("valeur: %lf\n",valeur);
		if(valeur < y1 || valeur > y2)
		{
			printf("La valeur de y est en dehors du segment!\n");
		}
		else
		{
			//Calculer X
			resultatX = ((valeur - y1)/(y2 - y1)) * (x2 - x1) + x1;
			printf("X vaut %lf\n",resultatX);
		}
	}


	return 0;
}