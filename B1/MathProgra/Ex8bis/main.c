#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 3

void affichematriceA(float[][N]);
void affichematriceB(float[]);

int main()
{
    int i,j,k;
    int lignepivot, pivot;
    float tmp,coef;

    float matriceA[N][N]={
        {2,-1,3},
        {4,2,-2},
        {1,1,1}
    };
    float matriceB[N]={17,-2,5};

    affichematriceA(matriceA);
    printf("\n");
    affichematriceB(matriceB);
    printf("\n");

    //1 : Recherche ligne pivot sur colonne 1

    for(k=0;k<2;k++)
    {
        lignepivot = k;
        pivot = fabs(matriceA[k][k]);

        for(i=k+1;i<N;i++)
        {
            if(abs(matriceA[i][k])>pivot)
            {
                pivot = matriceA[i][k];
                lignepivot = i;
            }
        }

        //2 : Permutation de la ligne 1 et 0

        if(lignepivot==k)
        {
            printf("\n---le pivot n'a pas changer => permutation ligne---\n");
        }
        else
        {
            printf("\n---le pivot a changer => permutation ligne---\n");
            for(j=k;j<N;j++)
            {
                tmp=matriceA[k][j];
                matriceA[k][j]=matriceA[lignepivot][j];
                matriceA[lignepivot][j]=tmp;
            }

            //inverser la matrice B

            for(j=k;j<N;j++)
            {
                tmp=matriceB[k];
                matriceB[k]=matriceB[lignepivot];
                matriceB[lignepivot]=tmp;
            }

        }

        printf("\n");
        affichematriceA(matriceA);
        printf("\n");
        affichematriceB(matriceB);
        printf("\n");

        //3 : supression des x sur la ligne 2 et 3

        for(i=k+1;i<N;i++)
        {
            coef=matriceA[i][k]/matriceA[k][k];
            for(j=k;j<N;j++)
            {
                matriceA[i][j]=matriceA[i][j]-coef*matriceA[k][j];
            }
            matriceB[i]=matriceB[i]-coef*matriceB[k];
        }

        printf("\n=>Suppression des X sur L2 et L3\n\n");
        affichematriceA(matriceA);
        printf("\n");
        affichematriceB(matriceB);
        printf("\n");
        printf("\n++++++++++++++++++++++++++++++++++++++++++\n");
    }

    return 0;
}

//P : affichage Matrice

void affichematriceA(float matriceA[][N])
{
    int i,j;

    printf("     Matrice A\n\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%6.2f",matriceA[i][j]);
        }
        printf("\n");
    }
}

//P : affichage Matrice

void affichematriceB(float matriceA[])
{
    int i;

    printf("    Matrice B\n\n");
    for(i=0;i<N;i++)
    {
        printf("%6.2f",matriceA[i]);
    }
}
