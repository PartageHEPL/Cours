#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "fonctions.h"
#include "OrgSeqLog.h"
#include "OrgIdx.h"
#include "OrgSeqPhys.h"

//J'ai choisi de faire les question en phyisique (j'enregistre les struct questions dans questions.dat)
//car je l'ai pas reussi a utiliser l'OrgQeqIdx

//A mettre ne place
//J'ai instaure un mode root (mdp = azerty) depuis ce mode on peu modifier tout. Si l'on se connecte
//en tant que joueur on ne peu modifier que son profile etc

//ATTENTION remplir les fichiers avec les trucs du prof

/*
A faire:
-supprimer tous les fichiers
-updatelast activity quand on encode un truc ou se connecte et quitte
-le bonus des question est facile a faire 
-verifier l'encodage des question strlen != 0
-tester toute les fonctions pour savoir si on est en mode root ou non
-modifier profile menu de modification par id et pas nom en cas de doublon
-fonctiuon connecter stocker le nom dans la var globale
-decommenter la suppresion du tous les fichier pour reponses.dat
-quand on supprime un profile, on dois aussi supprimer toute les reponses de ce profile

Bug:
-Nom ne veut pas prendre un -
-probleme le nombre de questions augmente de un uqand on en modifier une
-impossible de supprimer globale.dat

//gcc -o test main.c fonctions.c menu.c OrgSeqLog.c -Wall

//gcc -o test *.c -Wall

*/


int main(void)
{
	Globale Var_Globale = {{0,0},{{{0}},0},0,0,"profiles.dat","questions.dat","reponses.dat","globale.dat","",0,{0},0};	

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
		if(Cree_Fichier(Var_Globale.questions) == -1)
		{
			printf("Erreur lors de la cr%cation de fichier %s!\n",130,Var_Globale.questions);
			Pause();
		}
	}
	if(Test_Fichier_Existe(Var_Globale.reponses)== -1)
	{
		printf("Le fichier %s est manquant! Cr%cation en cours...\n",Var_Globale.reponses,130);
		//Cree le fichier avec la bonne méthode
		if(Cree_Fichier(Var_Globale.reponses) == -1)
		{
			printf("Erreur lors de la cr%cation de fichier %s!\n",130,Var_Globale.reponses);
			Pause();
		}
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
	Var_Globale.nbrQuestions = InitialiserNbrQuestion(Var_Globale.globale);
	//Initialiser questionID
	Var_Globale.questionID = InitialiserID(Var_Globale.globale);
	
	
	
	//Début du programme
	system("cls");
	Menu_Connexion(&Var_Globale);

	/*
	long idProfil;
	long idQuestion;
	long idPartie;
	short reponseDonnee;
	short points;
	time_t timestamp;
	

	Reponse temp = {};

	FILE *fichier = NULL;
	fichier = fopen(Var_Globale.reponses,"ab+");
	if(fichier == NULL)
	{
		
	}
	else
	{
		fwrite(&temp,sizeof(Reponse),1,fichier);
		printf("OK\n");
		fclose(fichier);
	}
	
*/
	return 0;
}