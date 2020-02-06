#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system("cls");
	int matriceA[3][3]=
	{
		{3,1,2},
		{0,-2,3},
		{0,4,2},
	};

	int mmA[3][3]=
	{
		{0,0,0},
		{0,0,0},
		{0,0,0},
	};

	int matriceAdjointe[3][3]={{0}};

	float InverseA[3][3]={{0}};

	int i=0,j=0;
	float determinant;
	determinant=0;
	//Correction:
	/*MMA=
	{-16,0,0}
	{6,6,-12}
	{7,-8,-6}
	*/
	
	//Calculer:

	//Mineur Algebrique

	mmA[0][0]=pow(-1,0+0)*(matriceA[1][1]*matriceA[2][2]-matriceA[2][1]*matriceA[1][2]);
	mmA[0][1]=pow(-1,0+1)*(matriceA[1][0]*matriceA[2][2]-matriceA[2][0]*matriceA[1][2]);
	mmA[0][2]=pow(-1,0+2)*(matriceA[1][0]*matriceA[2][1]-matriceA[2][0]*matriceA[1][1]);
	mmA[1][0]=pow(-1,1+0)*(matriceA[0][1]*matriceA[2][2]-matriceA[2][1]*matriceA[0][2]);
	mmA[1][1]=pow(-1,1+1)*(matriceA[0][0]*matriceA[2][2]-matriceA[0][2]*matriceA[0][3]);
	mmA[1][2]=pow(-1,1+2)*(matriceA[0][0]*matriceA[2][1]-matriceA[2][0]*matriceA[0][1]);
	mmA[2][0]=pow(-1,2+0)*(matriceA[0][1]*matriceA[1][2]-matriceA[1][1]*matriceA[0][2]);
	mmA[2][1]=pow(-1,2+1)*(matriceA[0][0]*matriceA[1][2]-matriceA[1][0]*matriceA[0][2]);
	mmA[2][2]=pow(-1,2+2)*(matriceA[0][0]*matriceA[1][1]-matriceA[1][0]*matriceA[0][1]);

	//Determinant
	//Multiplier une ligne par la ligne dans la matrice Adjointe(transposer de la mma)
	for(i=0;i<1;i++)
	{
		for(j=0;j<3;j++)
		{
			determinant+=(matriceA[i][j]*mmA[i][j]);
		}
	}

	//Transposer mmA
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			matriceAdjointe[i][j]=mmA[j][i];
		}
	}

	//Inverse de A
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			InverseA[i][j]=(1/determinant*matriceAdjointe[i][j]);
		}
	}

	//Afficher tout
	//Afficher le determinent
	printf("\nDeterminant= %f\n",determinant);

	//Afficher A
	printf("Matrice A:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%3d",matriceA[i][j]);
		}
		printf("\n");
	}

	//Afficher mmA
	printf("mmA:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%3d",mmA[i][j]);
		}
		printf("\n");
	}

	//Afficher matriceAdjointe
	printf("\nMatrice Adjointe/Transposer:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%3d",matriceAdjointe[i][j]);
		}
		printf("\n");
	}

	//Afficher matrice Inverse
	printf("\nMatrice Inverse:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%7.3f",InverseA[i][j]);
		}
		printf("\n");
	}

	return 0;
}
