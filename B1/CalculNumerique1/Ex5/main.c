#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 3

int main()
{
 	int A[N][M]={{1,2,3},{4,5,6},{7,8,9}};
 	int Atr[N][M]={{0}};
 	int i,j;
 	//s Atr={{1,4,7},{2,5,8},{3,6,9}};

	printf("\nIn matrice A\n");

	for(i=0;i<N;i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%3d",A[i][j] );
		}
		printf("\n");
	}

	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			Atr[i][j]=A[j][i];
		}
	}
	//transposee de A

	printf("\n matrice A transposee\n");

	for(i=0;i<M;i++)
	{
		for(j=0;j<M;i++)
		{
			printf("%3d",Atr[i][j]);
		}
		printf("\n");
	}
	
    return 0;
}
