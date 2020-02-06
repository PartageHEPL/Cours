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
void Menu_Principal(Globale *pVar_Globale)
{
	int choix_Menu_Principal;
	system("cls");
	do
	{
		printf("Menu G%cn%cral:\n",130,130);
		printf("1. Menu Profils\n");
		printf("2. Menu R%cponses\n",130);
		printf("3. Menu Questions\n");
		printf("4. Quitter le programme\n");
		fflush(stdin);
		scanf("%d",&choix_Menu_Principal);
	}while(choix_Menu_Principal < 1 || choix_Menu_Principal > 4);
	switch(choix_Menu_Principal)
	{
		case 1:
			Menu_Profils(pVar_Globale);
		case 2:
			Menu_Reponses(pVar_Globale);
		case 3:
			Menu_Questions(pVar_Globale);
		case 4:
			exit(0);
	}
}
void Menu_Profils(Globale *pVar_Globale)
{
	int choix_Menu_Profils;
	char rpTemp[50];
	system("cls");
	do
	{
		printf("Menu Profils:\n");
		printf("1. Ajouter un nouveau profil\n");
		printf("2. Afficher tous les profiles dans l'ordre\n");
		printf("3. Afficher les profils dans l'ordre alphab%cthique\n",130);
		printf("4. Rechercher un profile grace aux nom\n");
		printf("5. Modifier la fiche d'un utilisateur grace aux nom\n");
		printf("6. Supprimer un profil/utilisateur\n");
		printf("7. Retour Menu Principal\n");
		fflush(stdin);
		scanf("%d",&choix_Menu_Profils);
	}while(choix_Menu_Profils < 1 || choix_Menu_Profils > 7);
	switch(choix_Menu_Profils)
	{
		case 1:
			Encoder_Profils(pVar_Globale);
			Pause();
			Menu_Profils(pVar_Globale);
			break;
		case 2:
			if(Afficher_Tous_Profils(pVar_Globale)==-1)
			{
				printf("Erreur lors de l'affichage de tous les profiles!\n");
			}
			Pause();
			Menu_Profils(pVar_Globale);
			break;
		case 3:
			//Faire appele a la fonctions pour afficher les profiles dans l'ordre alpabetique
			break;
		case 4:
			printf("Entrez le nom a rechercher: ");
			fflush(stdin);
			gets(rpTemp);
			//Rechercher_Profils(pUtilisateur,pnbr_profile,rpTemp);
			Pause();
			Menu_Profils(pVar_Globale);
			break;
		case 5:
			//Faire appele a la fonctions pour modifier une fiche
			Pause();
			Menu_Profils(pVar_Globale);
			break;
		case 6:
			//Faire appele a la fonctions pour supprimer un profile
			//Mettre idProfile à -1
			Pause();
			Menu_Profils(pVar_Globale);
			break;
		case 7:
			Menu_Principal(pVar_Globale);
			break;
	}
}
void Menu_Reponses(Globale *pVar_Globale)
{
	int choix_Menu_Reponses;
	system("cls");
	do
	{
		printf("Menu R%cponses:\n",130);
		printf("1. Ajouter des nouvelles r%cponses\n",130);
		printf("2. Afficher des parties jou%ces par un utilisateur donn%c + total des points de chaque partie\n",130,130);
		printf("3. Afficher les th%cmes auxquels un utilisateur donn%c a particip%c + total des points pour ce th%cme\n",138,130,130,138);
		printf("4. Retour Menu Principal\n");
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
	do
	{
		printf("Menu Questions:\n");
		printf("1. Ajouter une nouvelle question\n");
		printf("2. Afficher les questions dans l'ordre alphab%ctique(theme + libelle)\n",130);
		printf("3. Afficher l'ensemble des th%cmes existants dans le fichier\n",138);
		printf("4. Rechercher et afficher des questions associ%ces %c un th%cme\n",130,133,138);
		printf("5. Rechercher des questions dont le libell%c contient un mot\n",130);
		printf("6. Modification de la fiche d'une question dont la fiche a %ct%c recherch%c\n",130,130,130);
		printf("7. Suppression de le fiche d'une question dont la fiche a %ct%c recherch%ce\n",130,130,130);
		printf("8. BONUS : Afficher la liste des question jamais pos%ces\n",130 );
		printf("9. Retour Menu Principal\n");
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