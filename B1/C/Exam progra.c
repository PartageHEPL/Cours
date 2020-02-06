//Question de l'exam

1()
int i = 5;
int j = 2;

printf("%f",1.5+(float)(i+1)/(float)j+5/j);

=> 1.5+6.0/2.0+5/2
=> 1.5+6.0/2.0+2
=> 1.5+3+2
=> 6.5 => Réponse

2()
int *ptr,*tmp,*v;
int a;
v=&a;
ptr=v;
tmp=ptr;
v=ptr;

=> QCM 3 propositions => Tout pointe vers a

3()
int i = 0;
int v = 0;
while(i == 0 || v == 20)
{
	if(v % 20)
		i++;
	v = v + 10;
}
//Combien de tour de boucle va faire le programme?
//Propositions: 1,0,3,5,20
Réponse:Tour de boucle => 3

4()
//Exercices complet en programmation papier

5()
//Ecrire les prototypes des 2 fonctions
int a[10][5],*b,*c,n;
char nom[25];
b=&a[0][0];
n=Fonction1(b,n,nom);
Fonctions2(&b,n)
//Réponse:
int Fonction1(int *,int ,char*)
void Fonction2(int **,int) //=>Attention au deux "*"

6()
//Tableau et il faut acceder au 5eme element
//t est un tableau
a:t[4]
b:t,4
c:t+4
d:*(t+4)
e:4t[]
Réponses:a et d

7()
//QCM 4 choix
int main(void)
{
	int tab[10];
	int *start = ;      //1
	int *end = ;        //2
	int taille_tab = ;  //3
	return 0;
}
//un pointeur moins un autre donne l'indice du pointeur a la fin
Réponse: //1 = &tab[0] 2 = &tab[9] 3 = end + 1
