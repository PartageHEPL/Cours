#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "fonctions.h"
#include "OrgSeqLog.h"
#include "OrgIdx.h"
#include "OrgSeqPhys.h"


/**************************************************************************/
/**************************************************************************/
//Menu:
void Menu_Connexion(Globale *pVar_Globale)
{
	int choixMenu;
	system("cls");
	printf("Menu de connexion:\n");
	printf("1. Se connecter\n");
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
			if(Connecter(pVar_Globale) != -1)
			{
				printf("Connexion r%cussie\n",130);
				Pause();
				//Le nom de connexion est dans pVar_Globale->nomConnexion
				Menu_Principal(pVar_Globale);
			}
			else
			{
				printf("Nom ou mot de passe incorrecte!\n");
				//Vider le nom dans pVar_Globale->nomConnexion
				strcpy(pVar_Globale->nomConnexion,"");
				Pause();
				Menu_Connexion(pVar_Globale);
			}
			break;
		case 2:
			//Cree un nouveau compte et le sauvegarder
			Encoder_Profils(pVar_Globale,1);
			Menu_Connexion(pVar_Globale);
			break;
		case 3:
			exit(0);
			break;
	}
}

void Menu_Principal(Globale *pVar_Globale)
{
	int choix_Menu_Principal;
	int choixSupprimer;
	system("cls");
	
	printf("Menu Principal:\n");
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
				if(Supprimer_Tous_Fichier(pVar_Globale) == -1)
				{
					printf("Erreur lors de la suppresion d'un ou plusieurs fichiers!\n");
				}
				else
				{
					printf("Tous les fichiers ont %ct%c supprimer!\n",130,130);
				}
			}
			Pause();
			Menu_Principal(pVar_Globale);
			break;
		case 5:
			//Update last avtivity
			if(strcmp(pVar_Globale->nomConnexion,"root") != 0)
			{
				//Mettre a jour last activity
				UpdateLastActivity(pVar_Globale,pVar_Globale->nomConnexion);
			}
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
			if(Supprimer_Profile(pVar_Globale) == -1)
			{
				printf("Erreur lors de la suppression du profile!\n");
			}
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
	//int ID = -1;
	//char nom[50] = {0};
	//Header header = {0};
	//EnrSeqLog temp = {0};
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
			 Encoder_Reponses(pVar_Globale);
			 Pause();
			 Menu_Reponses(pVar_Globale);
			break;
		case 2:
		/*
			printf("Entrez le nom du joueur: ");
			fflush(stdin);
			gets(nom);
			Initial((char *)&nom);
			FILE *fichier = NULL;
			fichier = fopen(pVar_Globale->profiles,"rb+");
			if(fichier != NULL)
			{
				fread(&header,sizeof(Header),1,fichier);
				fclose(fichier);
				if(header.PTO != -1)
				{
					temp.offset = header.PTO;
					while(temp.offset != -1)
					{
						readFileSeqLog(pVar_Globale->profiles,temp.offset,&(temp.payload),&(temp.offset),NULL);
						if(strcmp(nom,temp.payload.utilisateur.nom) == 0)
						{
							ID = temp.payload.utilisateur.idProfil;
						}
					}
				}
				fclose(fichier);
			}
			AfficherPartie(pVar_Globale,ID);
			*/
			Pause();
			Menu_Reponses(pVar_Globale);
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
	char tTemp[50],motTemp[50];
	system("cls");
	
	printf("Menu Questions:\n");
	printf("1. Ajouter une nouvelle question\n");
	printf("2. Afficher les questions dans l'ordre alphab%ctique(theme + libelle)\n",130);
	printf("3. Afficher l'ensemble des th%cmes existants dans le fichier\n",138);
	printf("4. Rechercher et afficher des questions associ%ces %c un th%cme\n",130,133,138);
	printf("5. Rechercher des questions dont le libell%c contient un mot\n",130);
	printf("6. Modification de la fiche d'une question dont la fiche a %ct%c recherch%c\n",130,130,130);
	printf("7. Suppression de le fiche d'une question dont la fiche a %ct%c recherch%ce\n",130,130,130);
	printf("8. Retour Menu Principal\n\n");
	do
	{
		printf("Quel est votre choix? ");
		fflush(stdin);
		scanf("%d",&choix_Menu_Questions);
	}while(choix_Menu_Questions < 1 || choix_Menu_Questions > 8);
	switch(choix_Menu_Questions)
	{
		case 1:
			if(Encoder_Questions(pVar_Globale,1) != 0)
			{
				printf("Erreur lors de l'encodage de la question!\n");
			}
			Menu_Questions(pVar_Globale);
			break;
		case 2:
			//A modifier?
			//et a trier
			AfficherTousQuestions(pVar_Globale->questions,pVar_Globale->nbrQuestions);
			Pause();
			Menu_Questions(pVar_Globale);
			break;
		case 3:
			printf("Voici la liste des themes:\n");
			AfficherThemes(pVar_Globale->questions,pVar_Globale->nbrQuestions);
			Pause();
			Menu_Questions(pVar_Globale);
			break;
		case 4:
			printf("Entrez le theme a rechercher: ");
			fflush(stdin);
			gets(tTemp);
			RecercherQuestion(pVar_Globale->questions,"theme",tTemp);
			Pause();
			Menu_Questions(pVar_Globale);
			break;
		case 5:
			printf("Entrez le mot a rechercher: ");
			fflush(stdin);
			gets(motTemp);
			RecercherQuestion(pVar_Globale->questions,"libelle",motTemp);
			Pause();
			Menu_Questions(pVar_Globale);
			break;
		case 6:
			ModifierQuestion(pVar_Globale,pVar_Globale->questions,pVar_Globale->nbrQuestions);
			Pause();
			Menu_Questions(pVar_Globale);
			break;
		case 7:
			SupprimerQuestion(pVar_Globale,pVar_Globale->questions);
			Pause();
			Menu_Questions(pVar_Globale);
			break;
		case 8:
			Menu_Principal(pVar_Globale);
			break;

	}
}