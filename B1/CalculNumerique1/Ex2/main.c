#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 2

int main()
{
	int A[N][M]={{1,2,3},{4,5,6},{7,8,9}};
	int B[N][M]={{1,0,3},{-1,5,2},{-3,4,0}};
	//int C[N][M]={{-10,22,7},{-19,49,22},{-28,76,37}};
	int C[N][N]={{0}};
	int i,j,k;

	printf("\nIn matrice A\n");

	for(i=0;i<N;i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%3d",A[i][j] );
		}
		printf("\n");
	}

	printf("\nIn matrice B\n");

	for(i=0;i<N;i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%3d",B[i][j] );
		}
		printf("\n");
	}

	printf("C=A*B\n");

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			for(k=0;k<N;k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
		printf("\n");
	}

	for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%4d",C[i][j]);
        }
        printf("\n");
    }




    return 0;
}
