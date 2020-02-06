#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	double x1,y1,x2,y2;
	char mode;
	double valeur;
	double resultatX = 0,resultatY = 0;

	//Initialiser
	x1 = atof(argv[1]);
	y1 = atof(argv[2]);
	x2 = atof(argv[3]);
	y2 = atof(argv[4]);
	strcpy(&mode,argv[5]);
	valeur = atof(argv[6]);

	//Mode
	if(mode == 'x' || mode == 'X')
	{
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