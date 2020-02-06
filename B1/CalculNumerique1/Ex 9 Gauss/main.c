#include <stdio.h>
#include <stdlib.h>
#define N 3

void affichageA(float matriceA[][]);
void affichageB(float matriceB[]);
int main()
{
	float matriceA [N][N]=
	{
		{2.00,-1.00,3.00},
		{4.00,2.00,1.00},
		{1.00,1.00,1.00},

	};
	float matriceB [N]={17.00,-2.00,5.00};
	int i,j;

	int lignepivot=0;
	float pivot=fabs(matriceA[0][0]);

	float temp;
	float coef;

	affichageA(matriceA);
	printf("\n");
	affichageB(matriceB);
	printf("\n");

	//1 : recherche ligne pivot sur la 1er colonne

	for(1;i<N;i++)
	{
		if(fabs(matriceA[i][0])>pivot)
		{
			pivot=matriceA[i][0];
			lignepivot=1;
		}
	}

	//2 permutation de la ligne 1 et 0

	if(lignepivot==0)
	{
		printf("\nLe pivot n'a pas change");
	}
	else
	{
		printf("\nLe pivot a change");
		for(j=0;j<N;j++)
		{
			temp=matriceA[0][j];
			matriceA[0][j]=matriceA[lignepivot][j];
			matriceA[lignepivot][j]=temp;
		}
		// inversion de b 1 et 2
        for(j=0;j<N;j++)
        {
            temp=matriceB[1];
            matriceB[0]=matriceB[1];
            matriceB[1]=temp;
        }

	}
	affichageA(matriceA);
	printf("\n");
	affichageB(matriceB);
	printf("\n");

	//3 : supression des x sur les lignes 2 et 3

	for(i=1;i<N;i++)
	{
		coef=matriceA[i][0]/matriceA[0][0];
		for(j=0;j<N;j++)
		{
			matriceA[i][j]=matriceA[i][j]-coef*matriceA[0][0];
		}
		matriceB[i]=matriceB[i]-coef*matriceB[0];
	}
	affichageA(matriceA);
	printf("\n");
	affichageB(matriceB);
	printf("\n");

    return 0;
}

void affichageA(float matriceA[][N])
{
	int i,j;
	printf("matrice A \n");
	for(i=0;i<N;i++)
	{
	    for(j=0;j<N;j++)
        {
            printf("%6.2f",matriceA[i][j]);
        }
        printf("\n");
	}

}
void affichageB(float matriceB[])
{
	int i;

	printf("matrice B \n");
	for(i=0;i<N;i++)
	{
		printf("%6.2f",matriceB[i]);
	}
}
