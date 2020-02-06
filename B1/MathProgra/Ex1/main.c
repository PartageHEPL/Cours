#include <stdio.h>
#include <stdlib.h>
#define LMAX 3
#define CMAX 2

//D=A+2*B-3C

int main()
{
	int i=0,j=0;
    int matriceA[LMAX][CMAX]={
    	{1,9},
    	{0,3},
    	{3,7},
    };
    int matriceB[LMAX][CMAX]={
    	{1,1},
    	{5,3},
    	{0,8},
    };
    int matriceC[LMAX][CMAX]={
    	{0,8},
    	{-5,0},
    	{3,-1},
    };
    int matriceD[LMAX][CMAX]={0};
    //Afficher matrice A
    printf("Matrice A:\n");
    for(i=0;i<LMAX;i++)
    {
    	for(j=0;j<CMAX;j++)
    	{
    		printf("%2d",matriceA[i][j]);
    	}
    	printf("\n");
    }
    //Afficher matrice B
    printf("Matrice B:\n");
    for(i=0;i<LMAX;i++)
    {
    	for(j=0;j<CMAX;j++)
    	{
    		printf("%2d",matriceB[i][j]);
    	}
    	printf("\n");
    }
    //Afficher matrice C
    printf("Matrice C:\n");
    for(i=0;i<LMAX;i++)
    {
    	for(j=0;j<CMAX;j++)
    	{
    		printf("%2d",matriceC[i][j]);
    	}
    	printf("\n");
    }

    //Calculer
    //Afficher matrice A
    printf("Resultat/Matrice D:\n");
    for(i=0;i<LMAX;i++)
    {
    	for(j=0;j<CMAX;j++)
    	{
    		matriceD[i][j]=matriceA[i][j]+2*matriceB[i][j]-(3*matriceC[i][j]);
    		printf("%3d",matriceD[i][j]);
    	}
    	printf("\n");
    }
    
    return 0;
}
