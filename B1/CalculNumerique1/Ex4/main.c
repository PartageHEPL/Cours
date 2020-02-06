#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 3

int main()
{
	int A[N][M]={{3,4,-1},{2,1,3}};
	int B[M][N]={{3,1},{4,5},{6,2}};
	int C[M][M]={{0}};
	int i,j,k;
	//s = C[N][M]={{11,13,0},{22,21,11},{22,26,0}};

	printf("\nIn matrice A\n");

	for(i=0;i<N;i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%2d",A[i][j] );
		}
		printf("\n");
	}

	printf("\nIn matrice B\n");

	for(i=0;i<N;i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%2d",B[i][j] );
		}
		printf("\n");
	}

	printf("C=B*A\n");

	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			for(k=0;k<N;k++)
			{
				C[i][j]+=B[i][k]*A[k][j];
			}

		}

	}

	for(i=0;i<M;i++)
    {
        for(j=0;j<M;j++)
        {
            printf("%3d",C[i][j]);

        }
        printf("\n");
    }

    return 0;
}

