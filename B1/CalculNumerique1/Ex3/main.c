#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 3

int main()
{
	int A[N][M]={{3,4,-1},{2,1,3}};
	int B[M][N]={{3,1},{4,5},{6,2}};
	int C[N][N]={{0}};
	int i,j,k;
	//s = C[N][M]={{19,21},{28,13}};

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

	printf("C=A*B\n");

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			for(k=0;k<M;k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
			}

		}

	}

	for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%3d",C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
