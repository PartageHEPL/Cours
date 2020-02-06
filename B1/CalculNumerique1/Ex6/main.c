#include <stdio.h>
#include <stdlib.h>
#define M 3

//voir les notes ecrites (programmation math #1)
int main()
{
    int A[M][M]=
    {
    	{5,2,-1},
    	{1,-2,2},
    	{0,3,1},
    };
 

    int det,temp1,temp2,temp3,i,j,temp4,temp5,temp6;

    printf("\nIn matrice A\n");

	for(i=0;i<M;i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%2d",A[i][j] );
		}
		printf("\n");
	}

	

	//calcule de déterminant par sarrus

	//1
	det=0;
	temp1=1;
	for(i=0,j=0;i<3;i++,j=(j+1)%3)
	{
		temp1*=A[i][j];
	}

	//2
	temp2=1;
	for(i=0,j=1;i<3;i++,j=(j+1)%3)
	{
		temp2*=A[i][j];
	}
	//3
	temp3=1;
	for(i=0,j=2;i<3;i++,j=(j+1)%3)
	{
		temp3*=A[i][j];
	}
	//4
	temp4=1;
	for(i=2,j=0;i>=0;i--,j=(j+1)%3)
	{
		temp4*=A[i][j];
	}
	//5
	temp5=1;
	for(i=2,j=1;i>=0;i--,j=(j+1)%3)
	{
		temp5*=A[i][j];
	}
	//6
	temp6=1;
	for(i=2,j=2;i>=0;i--,j=(j+1)%3)
	{
		temp6*=A[i][j];
	}

	det=(temp1+temp2+temp3)-(temp4+temp5+temp6);

	printf("la valeur du determinant est %d\n",det);



    return 0;
}
