#include <stdio.h>
#include <stdlib.h>
#define M 3

int main()
{
	system("cls");
	int matriceA[M][M]=
	{
		{5,2,-1},
		{1,-2,2},
		{0,3,1},
	};
	
	/*
	int matriceA[M][M]=
	{
		{2,-1,-2},
		{6,-1,1},
		{4,5,3},
	};
	*/
	int i=0,j=0;
	int resultat=0;
	int temp[6];

	//Afficher Matrice A
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			printf("%3d",matriceA[i][j]);
		}
		printf("\n");
	}

	//Initialiser le vecteur a 1
	for(i=0;i<6;i++)
	{
		temp[i]=1;
	}


	//Calculer le déterminant avec Sarrus
	//Pour le 1
	for(i=0,j=0;i<3;i++,j=(j+1)%3)
	{
		temp[0]*=matriceA[i][j];
	}
	//Pour le 2
	for(i=0,j=1;i<3;i++,j=(j+1)%3)
	{
		temp[1]*=matriceA[i][j];
	}
	//Pour le 3
	for(i=0,j=2;i<3;i++,j=(j+1)%3)
	{
		temp[2]*=matriceA[i][j];
	}
	//Pour le 4
	for(i=2,j=0;i>=0;i--,j=(j+1)%3)
	{
		temp[3]*=matriceA[i][j];
	}
	//Pour le 5
	for(i=2,j=1;i>=0;i--,j=(j+1)%3)
	{
		temp[4]*=matriceA[i][j];
	}
	//Pour le 6
	for(i=2,j=2;i>=0;i--,j=(j+1)%3)
	{
		temp[5]*=matriceA[i][j];
	}
	
	//Afficher les temps
	printf("\n");
	for(i=0;i<6;i++)
	{
		printf("%d\n",temp[i]);
	}

	resultat=(temp[0]+temp[1]+temp[2])-(temp[3]+temp[4]+temp[5]);

	printf("Le resultat/determinant = %d\n",resultat);




	return 0;
}