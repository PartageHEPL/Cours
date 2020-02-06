#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 3

//C=B*A

int main()
{
    int i=0,j=0,k=0;
    int matriceA[N][M]={
    	{3,4,-1},
    	{2,1,3},
    };
    int matriceB[M][N]={

    	{3,1},
    	{4,5},
    	{6,2},
    };
    int matriceC[M][M]={{0}};

    //Affichage des matrices
    //Affichage de A
    for(i=0;i<N;i++)
    {
    	for(j=0;j<M;j++)
    	{
    		printf("%3d",matriceA[i][j]);
    	}
    	printf("\n");
    }
    //Ecart visuel
    printf("\n");
    //Affichage de B
    for(i=0;i<M;i++)
    {
    	for(j=0;j<N;j++)
    	{
    		printf("%3d",matriceB[i][j]);
    	}
    	printf("\n");
    }

    //Calculer C
    for(i=0;i<M;i++)
    {
    	for(j=0;j<M;j++)
    	{
    		for(k=0;k<N;k++)
    		{
    			matriceC[i][j]+=matriceB[i][k]*matriceA[k][j];
    		}
    	}
    }

    //Ecart visuel
    printf("\n");
    //Affichage de C
    for(i=0;i<M;i++)
    {
    	for(j=0;j<M;j++)
    	{
    		printf("%3d",matriceC[i][j]);
    	}
    	printf("\n");
    }




    return 0;
}
