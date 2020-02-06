#include <stdio.h>
#include <stdlib.h>
#define LMAX 3
#define CMAX 3

//C=A*B

int main()
{
    int i=0,j=0,k=0;
    int matriceA[LMAX][CMAX]={
    	{1,2,3},
    	{4,5,6},
    	{7,8,9},
    };
    int matriceB[LMAX][CMAX]={
    	{1,0,3},
    	{-1,5,2},
    	{-3,4,0},
    };
    int matriceC[LMAX][CMAX]={{0}};
    /*
    Reponse=
    	{-10,22,7},
    	{-19,49,22},
    	{-28,76,37},
    };
*/
    //Afficher les matrices A
    printf("Matrice A:\n");
    for(i=0;i<LMAX;i++)
    {
    	for(j=0;j<CMAX;j++)
    	{
    		printf("%2d",matriceA[i][j]);
    	}
    	printf("\n");
    }
    //Afficher les matrices B
    printf("Matrice B:\n");
    for(i=0;i<LMAX;i++)
    {
    	for(j=0;j<CMAX;j++)
    	{
    		printf("%2d",matriceB[i][j]);
    	}
    	printf("\n");
    }
    //Afficher les matrices C
    printf("Matrice C:\n");
    for(i=0;i<LMAX;i++)
    {
    	for(j=0;j<CMAX;j++)
    	{
    		printf("%2d",matriceC[i][j]);
    	}
    	printf("\n");
    }

    //Multiplication de matrice
    //Meme nombre de ligne et de colonnes
    for(i=0;i<LMAX;i++)
    {
    	for(j=0;j<CMAX;j++)
    	{
    		for(k=0;k<CMAX;k++)
    		{
    			matriceC[i][j]+=matriceA[i][k]*matriceB[k][j];
    		}
    	}
    }

	//Afficher matrice C/Resultat
    printf("Resultat/Matrice C:\n");
    for(i=0;i<LMAX;i++)
    {
    	for(j=0;j<CMAX;j++)
    	{
    		printf("%4d",matriceC[i][j]);
    	}
    	printf("\n");
    }

    return 0;
}
