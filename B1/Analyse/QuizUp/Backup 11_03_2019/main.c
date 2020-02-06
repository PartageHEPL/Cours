#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "fonctions.h"
#include "OrgSeqLog.h"



/*
A faire:
-fonctions afficher tous les profiles
-fonctions rechercher un profile
-Retirter_Enter
-Test_Implimable => caractere ascii???
-structure partie
-Tri alphabetique(nouvelle struct)
-Modifier les libraires fournies:
OrgSecLog:
	-Fonction comparePayload
	-Fonction modifierProfile
	-Fonction affichageProfile
-Fonction reset qui supprime phisiquement tous les profiles/questions/reponses
-Fonction pour savoir si on a deja pose cette question ou non (un indicateur 1/0)
-Fonction qui affiche tous les profiles supprimer et/ou replace leurs indice de base ( on fais un not? )
-Fonctions qui affiche les stats (perties gagne/eprdues etc ratio)

Les Regles/choix etabli:
-La suppression des question/profils etc sera logique et non phisique
-Pour le profile on mettra l'idProfile à -1
-Vecteur de 5000 questions
-Vecteur de 5000 reponses
-100 profiles/utilisateurs 
-Pour trier les profiles dans l'ordre, on fais une struct contenant la struct
profile et on ajouter un int pour la position qui va pointer sur le prochain profile

Question:


Bug:
-Fonctions d'affichage du profile car on a un proleme lors de l'ecriture de l'offset
-Nom ne veut pas prendre un -
*/

//gcc -o test main.c fonctions.c -Wall

//gcc -o test main.c fonctions.c OrgSeqLog.c OrgSeqPhys.c OrgIdx.c -Wall



int main(void)
{
	Globale Var_Globale = {{0,0},{{{0}},0},0,"profiles.dat","questions.dat","reponses.dat","parties.dat","globale.dat"};	
	

	//Tester si les fichier existent
	if(Test_Fichier_Existe(Var_Globale.profiles)== -1)
	{
		if(createFileSeqLog(Var_Globale.profiles)== -1)
		{
			printf("Erreur lors de la cr%cation du fichier profiles.dat!\n",130);
			Pause();
		}
	}
	if(Test_Fichier_Existe(Var_Globale.questions)== -1)
	{
		//Cree le fichier avec la bonne méthode
	}
	if(Test_Fichier_Existe(Var_Globale.reponses)== -1)
	{
		//Cree le fichier avec la bonne méthode
	}
	if(Test_Fichier_Existe(Var_Globale.parties)== -1)
	{
		//Cree le fichier avec la bonne méthode
		//EngSeqLog 
	}
	if(Test_Fichier_Existe(Var_Globale.globale)== -1)
	{
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
	printf("Nbr_Profile_Cree: %d\n",Var_Globale.nbr_profile_cree);


	//Début du programme
	system("cls");
	Menu_Principal(&Var_Globale);


	//system("pause");
	return 0;
}