#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "fonctions.h"
#include "OrgSeqLog.h"


/**************************************************************************/
/**************************************************************************/
//Menu:
void Menu_Connexion(Globale *pVar_Globale)
{
	int choixMenu;
	printf("Menu de connexion:\n");
	printf("1. Se onnecter\n");
	printf("2. Cree un compte\n");
	printf("3. Quitter\n\n");
	do
	{
		printf("Quel est votre choix? ");
		fflush(stdin);
		scanf("%d",&choixMenu);
	}while(choixMenu < 1 || choixMenu > 3);
	switch(choixMenu)
	{
		case 1:
			Connecter();
		case 2:
			Cree_Compte();
		case 3:
			exit(0);
	}
}

void Menu_Principal(Globale *pVar_Globale)
{
	int choix_Menu_Principal;
	int choixSupprimer;
	system("cls");
	
	printf("Menu G%cn%cral:\n",130,130);
	printf("1. Menu Profils\n");
	printf("2. Menu R%cponses\n",130);
	printf("3. Menu Questions\n");
	printf("4. Supprimer tous les fichier\n");
	printf("5. Quitter le programme\n\n");
	do
	{
		printf("Quel est votre choix? ");
		fflush(stdin);
		scanf("%d",&choix_Menu_Principal);
	}while(choix_Menu_Principal < 1 || choix_Menu_Principal > 5);
	switch(choix_Menu_Principal)
	{
		case 1:
			Menu_Profils(pVar_Globale);
			break;
		case 2:
			Menu_Reponses(pVar_Globale);
			break;
		case 3:
			Menu_Questions(pVar_Globale);
			break;
		case 4:
			printf("Supprimer tous les fichiers?(0 non 1 oui) ");
			fflush(stdin);
			scanf("%d",&choixSupprimer);
			if(choixSupprimer == 1)
			{
				Supprimer_Tous_Fichier(pVar_Globale);
				printf("Tous les fichiers ont %ct%c supprimer!\n",130,130);
			}
			Pause();
			Menu_Principal(pVar_Globale);
			break;
		case 5:
			exit(0);
			break;
	}
}

void Menu_Profils(Globale *pVar_Globale)
{
	int choix_Menu_Profils;
	system("cls");
	
	printf("Menu Profils:\n");
	printf("1. Ajouter un nouveau profil\n");
	printf("2. Afficher les profils dans l'ordre alphab%cthique\n",130);
	printf("3. Rechercher un profile grace aux nom\n");
	printf("4. Modifier la fiche d'un utilisateur grace aux nom\n");
	printf("5. Supprimer un profil/utilisateur\n");
	printf("6. Retour Menu Principal\n\n");
	do
	{
		printf("Quel est votre choix? ");
		fflush(stdin);
		scanf("%d",&choix_Menu_Profils);
	}while(choix_Menu_Profils < 1 || choix_Menu_Profils > 6);
	switch(choix_Menu_Profils)
	{
		case 1:
			Encoder_Profils(pVar_Globale,1);
			Pause();
			Menu_Profils(pVar_Globale);
			break;
		case 2:
			if(Afficher_Tous_Profils(pVar_Globale)==-1)
			{
				printf("Erreur lors de l'affichage de tous les profiles!\n");
				Pause();
			}
			Pause();
			Menu_Profils(pVar_Globale);
			break;
		case 3:
			if(Rechercher_Profils(pVar_Globale)==-1)
			{
				printf("Erreur lors de la recher de profiles!");
			}
			Pause();
			Menu_Profils(pVar_Globale);
			break;
		case 4:
			Modifier_Profile(pVar_Globale);
			Pause();
			Menu_Profils(pVar_Globale);
			break;
		case 5:
			Supprimer_Profile(pVar_Globale);
			Pause();
			Menu_Profils(pVar_Globale);
			break;
		case 6:
			Menu_Principal(pVar_Globale);
			break;
	}
}

void Menu_Reponses(Globale *pVar_Globale)
{
	int choix_Menu_Reponses;
	system("cls");

	printf("Menu R%cponses:\n",130);
	printf("1. Ajouter des nouvelles r%cponses\n",130);
	printf("2. Afficher des parties jou%ces par un utilisateur donn%c + total des points de chaque partie\n",130,130);
	printf("3. Afficher les th%cmes auxquels un utilisateur donn%c a particip%c + total des points pour ce th%cme\n",138,130,130,138);
	printf("4. Retour Menu Principal\n\n");
	do
	{
		printf("Quel est votre choix? ");
		fflush(stdin);
		scanf("%d",&choix_Menu_Reponses);
	}while(choix_Menu_Reponses < 1 || choix_Menu_Reponses > 4);
	switch(choix_Menu_Reponses)
	{
		case 1:
			//Faire appele a la fonctions pour ajouter nouvelle reponses
			break;
		case 2:
			//Faire appele a la fonctions pour afficher pertis jouees
			break;
		case 3:
			//Faire appele a la fonctions pour afficher les themes etc
			break;
		case 4:
			Menu_Principal(pVar_Globale);
	}	
}

void Menu_Questions(Globale *pVar_Globale)
{
	int choix_Menu_Questions;
	system("cls");
	
	printf("Menu Questions:\n");
	printf("1. Ajouter une nouvelle question\n");
	printf("2. Afficher les questions dans l'ordre alphab%ctique(theme + libelle)\n",130);
	printf("3. Afficher l'ensemble des th%cmes existants dans le fichier\n",138);
	printf("4. Rechercher et afficher des questions associ%ces %c un th%cme\n",130,133,138);
	printf("5. Rechercher des questions dont le libell%c contient un mot\n",130);
	printf("6. Modification de la fiche d'une question dont la fiche a %ct%c recherch%c\n",130,130,130);
	printf("7. Suppression de le fiche d'une question dont la fiche a %ct%c recherch%ce\n",130,130,130);
	printf("8. BONUS : Afficher la liste des question jamais pos%ces\n",130 );
	printf("9. Retour Menu Principal\n\n");
	do
	{
		printf("Quel est votre choix? ");
		fflush(stdin);
		scanf("%d",&choix_Menu_Questions);
	}while(choix_Menu_Questions < 1 || choix_Menu_Questions > 9);
	switch(choix_Menu_Questions)
	{
		case 1:
			//Faire appele a la fonctions pour ajouter nouvelle question
			break;
		case 2:
			//Faire appele a la fonctions pour afficher question
			break;
		case 3:
			//Faire appele a la fonctions pour afficher themes
			break;
		case 4:
			//Faire appele a la fonctions pour recherche et afficher question
			break;
		case 5:
			//Faire appele a la fonctions pour rechercher question
			break;
		case 6:
			//Faire appele a la fonctions pour modifier une fiche
			break;
		case 7:
			//Faire appele a la fonctions pour supprimer de la fiche une question jsp quoi
			break;
		case 8:
			//Faire appele a la fonctions pour afficher liste question jamais posees
			break;
		case 9:
			Menu_Profils(pVar_Globale);
			break;
	}
}