#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "fonctions.h"
#include "OrgSeqLog.h"



/*
A faire:
-menu connexion
-fonction pour afficher tous les profiles supprimer
-Verifier les retour des fonctions (erreurs/resultat) et les tester a chaque appel
-Retirter_Enter???utile si on fais gets?
-structure partie??? ptetre pas besoin
-Fonction pour savoir si on a deja pose cette question ou non (un indicateur 1/0)
-Fonction qui affiche tous les profiles supprimer et/ou replace leurs indice de base ( on fais un not? )
-Fonctions qui affiche les stats (perties gagne/eprdues etc ratio)



Bug:
-Nom ne veut pas prendre un -


//gcc -o test main.c fonctions.c menu.c OrgSeqLog.c -Wall

//gcc -o test *.c -Wall

*/


int main(void)
{
	Globale Var_Globale = {{0,0},{{{0}},0},0,"profiles.dat","questions.dat","reponses.dat","globale.dat"};	
	

	//Tester si les fichier existent
	if(Test_Fichier_Existe(Var_Globale.profiles)== -1)
	{
		printf("Le fichier %s est manquant! Cr%cation en cours...\n",Var_Globale.profiles,130);
		if(createFileSeqLog(Var_Globale.profiles)== -1)
		{
			printf("Erreur lors de la cr%cation du fichier %s\n",130,Var_Globale.profiles);
			Pause();
		}
	}
	if(Test_Fichier_Existe(Var_Globale.questions)== -1)
	{
		printf("Le fichier %s est manquant! Cr%cation en cours...\n",Var_Globale.questions,130);
		//Cree le fichier avec la bonne méthode
	}
	if(Test_Fichier_Existe(Var_Globale.reponses)== -1)
	{
		printf("Le fichier %s est manquant! Cr%cation en cours...\n",Var_Globale.reponses,130);
		//Cree le fichier avec la bonne méthode
	}
	if(Test_Fichier_Existe(Var_Globale.globale)== -1)
	{
		printf("Le fichier %s est manquant! Cr%cation en cours...\n",Var_Globale.globale,130);
		if(Cree_Fichier(Var_Globale.globale)== -1)
		{
			printf("Erreur lors de la cr%cation du fichier globale!\n",130);
			Pause();
		}	
	}


	//Initialisation de nbr_profile_cree
	if(Test_Fichier_Vide((Var_Globale.globale)) == 0)
	{
		if(Initialiser_Nbr_Profile_Cree(&Var_Globale)== -1)
		{
			printf("Erreur lors de l'initialisation de nbr_profile!\n");
			Pause();
		}
	}
	else
	{
		//Si le fichier globale.dat est vide on write globale
		Write_Globale(&Var_Globale);
		printf("Erreur: Le fichier globale.dat est vide!\n");
		Pause();
	}
	Read_Nbr_Profile_Cree(&Var_Globale);


	//Début du programme
	system("cls");
	Menu_Connexion(&Var_Globale);



	return 0;
}