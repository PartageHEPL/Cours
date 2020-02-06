#include <stdio.h>
#include <stdlib.h>
#define N 3

int main()
{
	int B[N][N]=
	{
		{2,-1,-2},
		{6,-1,1},
		{4,5,3},
	};

		int det,temp1,temp2,temp3,i,j,temp4,temp5,temp6;

	printf("\nIn matrice B\n");

	for(i=0;i<N;i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%2d",B[i][j] );
		}
		printf("\n");
	}
	//calcule de déterminant par sarrus

	//1
	det=0;
	temp1=1;
	for(i=0,j=0;i<3;i++,j=(j+1)%3)
	{
		temp1*=B[i][j];
	}

	//2
	temp2=1;
	for(i=0,j=1;i<3;i++,j=(j+1)%3)
	{
		temp2*=B[i][j];
	}
	//3
	temp3=1;
	for(i=0,j=2;i<3;i++,j=(j+1)%3)
	{
		temp3*=B[i][j];
	}
	//4
	temp4=1;
	for(i=2,j=0;i>=0;i--,j=(j+1)%3)
	{
		temp4*=B[i][j];
	}
	//5
	temp5=1;
	for(i=2,j=1;i>=0;i--,j=(j+1)%3)
	{
		temp5*=B[i][j];
	}
	//6
	temp6=1;
	for(i=2,j=2;i>=0;i--,j=(j+1)%3)
	{
		temp6*=B[i][j];
	}

	det=(temp1+temp2+temp3)-(temp4+temp5+temp6);

	printf("la valeur du determinant est %d\n",det);

    return 0;
}
