#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define M 3

int main()
{
    int A[M][M]=
	{
		{3,1,2},
		{0,-2,3},
		{0,4,2},
	};
	int mmA[M][M]={{0}};
	int trmmA[M][M]={{0}};
	int i,j;

	printf("\nIn matrice A\n");

	for(i=0;i<M;i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%2d",A[i][j] );
		}
		printf("\n");
	}

	i=0;
	j=0;

	mmA[i][j]=pow(-1,i+j)*(A[i+1][j+1]*A[i+2][j+2]-A[i+2][j+1]*A[i+1][j+2]);

	i=0;
	j=1;

	mmA[0][1]=pow(-1,0+1)*(A[1][0]*A[2][2]-A[2][0]*A[1][2]);
	mmA[0][2]=pow(-1,0+2)*(A[1][0]*A[2][1]-A[2][0]*A[1][1]);
	mmA[1][0]=pow(-1,1+0)*(A[0][1]*A[2][2]-A[2][1]*A[0][2]);
	mmA[1][1]=pow(-1,1+1)*(A[0][0]*A[2][2]-A[2][0]*A[0][2]);
	mmA[1][2]=pow(-1,1+2)*(A[0][0]*A[2][1]-A[2][0]*A[0][1]);
	mmA[2][0]=pow(-1,2+0)*(A[0][1]*A[1][2]-A[1][1]*A[0][2]);
	mmA[2][1]=pow(-1,2+1)*(A[0][0]*A[1][2]-A[1][0]*A[1][2]);
	mmA[2][2]=pow(-1,2+2)*(A[0][0]*A[1][1]-A[1][0]*A[0][1]);

	printf("\nIn matrice des mineur A\n");

	for(i=0;i<M;i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%2d",mmA[i][j] );
		}
		printf("\n");
	}
    printf("\n");
	//transpose
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			trmmA[i][j]=mmA[j][i];
		}
	}

	for(i=0;i<M;i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%2d",trmmA[i][j] );
		}
		printf("\n");
	}

    return 0;
}
