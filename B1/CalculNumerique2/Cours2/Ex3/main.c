#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define e 2.718281

int main(int argc, char const *argv[])
{
	double a,b,x,x1,x2,S = 0,S1 = 0,S2 = 0,S3 = 0,fx1 = 0,fx2 = 0,dx = 0,fx = 0;
	int i,n;
	system("cls");
	//Initialiser a,b,n
	a = 0;
	b = 1;
	n = 10;

	//Calcule de dx
	dx = (b - a)/n;

	//
	S = 0;
	x1 = a;
	x2 = a +dx;

	//Debut du tableau
	printf("I    xi-1    xi    (xi-1+xi)/2    f(xi-1)    f(xi)    f((xi-1+xi)/2)\n");
	//Bouble
	for(i = 0; i < n; i++)
	{
		x = (x1 + x2)/2;
		fx1 = pow(x1,2);
		fx2 = pow(x2,2);
		fx = pow(x,2);
		S = S + fx;
		printf("%d    %.2lf    %.2lf  %.2lf           %.2lf       %.2lf     %.4lf\n",i,x1,x2,x,fx1,fx2,fx);
		x1 = x2;
		x2 = x2 + dx;
		S1 +=fx1;
		S2 +=fx2;
		S3 +=fx;
	}
	
	//Afficher la fin du tableau
	printf("\n                                  S1 =        S2 =      S3 = \n");
	printf("                                  %.2lf       %.2lf     %.4lf   \n",S1,S2,S3);
	S = S * dx;

	printf("\n\n");
	printf("s   = %.4lf\n",S1 * dx);
	printf("S   = %.4lf\n",S2 * dx);
	printf("Stg = %.4lf\n",S);
	printf("Stp = %.4lf\n",(S2 + S1) * dx/2);
	printf("Ssp = %.4lf\n",(S1 + 4 * S3 + S2) * dx/6);
	system("pause");
	return 0;
}