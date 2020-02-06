#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 3


void afficheA(float matriceA[][N]);

void afficheB(float matriceB[N]);


int main()
{
	system("CLS");
	int i,j;
	int lignePivot=0;
	int pivot=0;
	int temp;
	float coef;

	float matriceA[N][N]={
		{2.0,-1.0,3.0},
		{4.0,2.0,-2.0},
		{1.0,1.0,1.0},
	};

	float matriceB[N]={17.0,-2.0,5.0};

	
	afficheA(matriceA);
	afficheB(matriceB);

	//Pivot et pivot max
	for(i=0;i<N;i++)
	{
		if(fabs(matriceA[i][0])>pivot)
		{
			pivot=fabs(matriceA[i][0]);
			lignePivot=i;
		}
	}
	printf("\nPivot = %d LignePivot= %d\n\n",pivot,lignePivot);

	//Permuter la ligne pivot et 0
	for(j=0;j<N;j++)
	{
		temp=matriceA[0][j];
		matriceA[0][j]=matriceA[lignePivot][j];
		matriceA[lignePivot][j]=temp;
	}
	//Permuter la matrice b (case 1 et 0)
	temp=matriceB[0];
	matriceB[0]=matriceB[lignePivot];
	matriceB[lignePivot]=temp;

	afficheA(matriceA);

	afficheB(matriceB);

	//Supression de x sur la ligne 2 et 3
	for(i=1;i<N;i++)
	{
		coef=matriceA[i][0]/matriceA[0][0];
		for(j=0;j<N;j++)
		{
			matriceA[i][j]=matriceA[i][j]-coef*matriceA[0][j];
		}
		matriceB[i]=matriceB[i]-coef*matriceB[0];
	}

	//Recherche ligne pivot sur la 2eme colone
	




	printf("\nFinal:\n");
	afficheA(matriceA);

	afficheB(matriceB);

	return 0;
}



void afficheA(float matriceA[][N])
{
	int i,j;

	printf("Matrice A:\n\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%6.2f",matriceA[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void afficheB(float matriceB[N])
{
	int i;

	printf("Matrice B:\n\n");
	for(i=0;i<N;i++)
	{
		printf("%6.2f",matriceB[i]);
	}
	printf("\n");
}