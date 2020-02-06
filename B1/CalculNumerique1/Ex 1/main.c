#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 2

int main()
{
	int A[N][M]={{1,9},{0,3},{3,7}};
	int B[N][M]={{1,1},{5,3},{0,8}};
	int C[N][M]={{0,8},{-5,0},{3,-1}};
	int D[N][M]={{0}};
	int i,j;

	printf("\nIn matrice A\n");

	for(i=0;i<N;i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%2d",A[i][j] );
		}
		printf("\n");
	}

	printf("\n");

	printf("\nIn matrice B\n");

	for(i=0;i<N;i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%2d",B[i][j] );
		}
		printf("\n");
	}

	printf("\n");

	printf("\nIn matrice C\n");

	for(i=0;i<N;i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%2d",C[i][j] );
		}
		printf("\n");
	}

	printf("\n");

	printf("D = A + 2*B - 3*C\n");

	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			D[i][j]=A[i][j]+2*B[i][j]-3*C[i][j];

			printf("%4d",D[i][j]);
		}
		printf("\n");
	}


    return 0;
}
