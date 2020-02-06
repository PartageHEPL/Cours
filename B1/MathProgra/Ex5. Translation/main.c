#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 3

int main()
{
	int i=0,j=0;
  	int matriceA[M][M]={
  		{1,2,3},
  		{4,5,6},
  		{7,8,9},
  	};
  	int matriceB[M][M]={{0}};


  	//Affichage de A
    for(i=0;i<M;i++)
    {
    	for(j=0;j<M;j++)
    	{
    		printf("%3d",matriceA[i][j]);
    	}
    	printf("\n");
    }

    //Translation
    for(i=0;i<M;i++)
    {
    	for(j=0;j<M;j++)
    	{
    		matriceB[i][j]=matriceA[j][i];
    	}
    }
    printf("\n");

    //Affichage de B
    for(i=0;i<M;i++)
    {
    	for(j=0;j<M;j++)
    	{
    		printf("%3d",matriceB[i][j]);
    	}
    	printf("\n");
    }

    return 0;
}
