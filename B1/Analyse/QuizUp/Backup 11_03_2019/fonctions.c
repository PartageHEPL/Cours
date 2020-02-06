#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "fonctions.h"
#include "OrgSeqLog.h"


/**************************************************************************/
/**************************************************************************/
//Encodage et affichage:

//I: Un pointeur sur la structure Var_Globale
//P: On va encoder tous les elements d'une struct profils
//O: /
int Encoder_Profils(Globale *pVar_Globale)
{
	int erreur = 0;
	printf("Encodez le profile:\n");
	pVar_Globale->enrg_seq_log.payload.utilisateur.idProfil = ((pVar_Globale->nbr_profile_cree) +1) ;
	do
	{
		printf("Entrez votre Nom: ");
		fflush(stdin);
		gets(pVar_Globale->enrg_seq_log.payload.utilisateur.nom);
	}while(Tester_Nom(&(pVar_Globale->enrg_seq_log.payload.utilisateur)) == -1);
	do
	{
		printf("Entrez votre langue(FR,EN,DE,NL): ");
		fflush(stdin);
		gets(pVar_Globale->enrg_seq_log.payload.utilisateur.codeLangue);
	}while(Tester_Langue(&(pVar_Globale->enrg_seq_log.payload.utilisateur)) == -1);
	do
	{
		printf("Entrez votre ville: ");
		fflush(stdin);
		gets(pVar_Globale->enrg_seq_log.payload.utilisateur.ville);
	}while(Tester_Ville(&(pVar_Globale->enrg_seq_log.payload.utilisateur))== -1);
	do
	{
		printf("Entrez votre r%cgion: ",130);
		fflush(stdin);
		gets(pVar_Globale->enrg_seq_log.payload.utilisateur.region);
	}while(Tester_Region(&(pVar_Globale->enrg_seq_log.payload.utilisateur))== -1);
	do
	{
		printf("Entrez votre pays: ");
		fflush(stdin);
		gets(pVar_Globale->enrg_seq_log.payload.utilisateur.pays);
	}while(Tester_Pays(&(pVar_Globale->enrg_seq_log.payload.utilisateur)) == -1);
	do
	{
		printf("Entrez votre mot de passe: ");
		fflush(stdin);
		gets(pVar_Globale->enrg_seq_log.payload.utilisateur.password);
	}while(Tester_Motdepasse(&(pVar_Globale->enrg_seq_log.payload.utilisateur)) == -1);

	pVar_Globale->enrg_seq_log.payload.utilisateur.lastActivity = time(NULL);

	Encoder_Date(&(pVar_Globale->enrg_seq_log.payload.utilisateur));
	if(writeFileSeqLog(pVar_Globale->profiles,&(pVar_Globale->enrg_seq_log.payload))==-1)
	{
		erreur = -1;
	}
	//Incrementer la valeur de nbr_profile_cree
	pVar_Globale->nbr_profile_cree += 1;
	if(Write_Nbr_Profile_Cree(pVar_Globale)==-1)
	{
		erreur = -1;
	}
	Vider_Profile(pVar_Globale);
	return erreur;
}

//I:
//P:
//O:
void Encoder_Reponses()
{
	/*
	long idProfil;
	long idQuestion;
	long idPartie;
	short reponseDonnee;
	short points;
	time_t timestamp;
	*/
}

//I:
//P:
//O:
void Encoder_Questions()
{
	/*
	long idQuestion;
	char theme[50];
	char libelle[144];
	char correctAnswer[50];
	char distracteur1[50];
	char distracteur2[50];
	char distracteur3[50];
	*/
}

//I: Un pointeur sur la structure Var_Globale
//P: Encode la date dans le profile de l'utilisateur
//O: /
void Encoder_Date(Profile *pUtilisateur)
{
	do
	{
		printf("Encoder votre date de naissance:\n");
		printf("Entrez un jour: ");
		fflush(stdin);
		scanf("%hi",&pUtilisateur->DdN.jour);
		printf("Entrez un mois: ");
		fflush(stdin);
		scanf("%hi",&pUtilisateur->DdN.mois);
		printf("Entrez une annee: ");
		fflush(stdin);
		scanf("%hi",&pUtilisateur->DdN.annee);
	}while(Tester_Date(pUtilisateur) == -1);
}

//I: Un pointeur sur la structure Var_Globale
//P: Affiche un profile
//O: /
void Afficher_Profils(Globale *pVar_Globale)
{
	if((pVar_Globale->enrg_seq_log.payload.utilisateur.idProfil) != -1)
	{
		printf("ID Utilisateur: %ld\n",pVar_Globale->enrg_seq_log.payload.utilisateur.idProfil);
		printf("Nom: %s\n",pVar_Globale->enrg_seq_log.payload.utilisateur.nom);
		printf("Langue: %s\n",pVar_Globale->enrg_seq_log.payload.utilisateur.codeLangue);
		printf("Ville: %s\n",pVar_Globale->enrg_seq_log.payload.utilisateur.ville);
		printf("Region: %s\n",pVar_Globale->enrg_seq_log.payload.utilisateur.region);
		printf("Pays: %s\n",pVar_Globale->enrg_seq_log.payload.utilisateur.pays);
		printf("Mot de passe: ");
		Afficher_Motdepasse(&(pVar_Globale->enrg_seq_log.payload.utilisateur));
		printf("Dernier activitee: ");
		Afficher_Derniere_Activitee(&(pVar_Globale->enrg_seq_log.payload.utilisateur));
		printf("Date de naissance: %02d/%02d/%d\n",pVar_Globale->enrg_seq_log.payload.utilisateur.DdN.jour,pVar_Globale->enrg_seq_log.payload.utilisateur.DdN.mois,pVar_Globale->enrg_seq_log.payload.utilisateur.DdN.annee);
	}
}

//I:
//P:
//O:
void Affichr_Reponses()
{

}

//I:
//P:
//O:
void Afficher_Questions()
{

}










/**************************************************************************/
/**************************************************************************/
//Contraintes:


//I: Un pointeur sur une chaine de max 50 caracteres
//P: Test la validite de chaque caractere du nom
//O: Retourne 0 si tout est une lettre ou -1 si le mot contient un autre caractere
int Tester_Nom(Profile *pUtilisateur)
{
	int i,taille = strlen(pUtilisateur->nom),resultat = 0;
	char temp[50];
	strcpy(temp,pUtilisateur->nom);

	if(taille == 0)
	{
		resultat = -1;
	}
	else
	{
		for( i = 0; i < taille; i++)
		{
			if(Test_Caractere_Alphabet(temp[i]) == -1)
			{
				resultat = -1;
				i = taille;
			}
		}
	}
	if(resultat == 0)
	{
		Initial(temp,taille);
		strcpy(pUtilisateur->nom,temp);
	}
	return resultat;
}

//I: Un pointeur sur la struct Profile
//P: Test la langue (fr,en,de,nl)
//O: Return -1 si on n'a pas fr,nl,de ou en
int Tester_Langue(Profile *pUtilisateur)
{
	int resultat = 0,i = 0,taille = strlen(pUtilisateur->codeLangue);
	char temp[3];
	strcpy(temp,pUtilisateur->codeLangue);
	while(i < taille)
	{
		temp[i] = tolower(temp[i]);
		i++;
	}
	if(!strcmp(temp,"fr") || !strcmp(temp,"en") || !strcmp(temp,"de") || !strcmp(temp,"nl"))
	{

	}
	else
	{
		resultat = -1;
	}
	//Si on  fr,nl,de ou en, on les mets en maj
	if(resultat == 0)
	{
		Majuscule_Chaine(&temp[0]);
		strcpy(pUtilisateur->codeLangue,temp);
	}
	return resultat;
}

//I: Un pointeur sur la struct Profile
//P: Test si la ville est valide ou non
//O: Return 0 si tout est ok ou -1 si on rentre le mauvrais caractere
int Tester_Ville(Profile *pUtilisateur)
{
	int i,taille = strlen(pUtilisateur->ville),resultat = 0;
	char temp[50];
	strcpy(temp,pUtilisateur->ville);

	if(taille > 0)
	{
		for( i = 0; i < taille; i++)
		{
			if(Test_Caractere_Alphabet(temp[i]) == -1)
			{
				if(Test_Caractere_Symbole(temp[i]) == -1)
				{
					resultat = -1;
					i = taille;
				}
			}
		}
	}
	if(resultat == 0)
	{
		Initial(temp,taille);
		strcpy(pUtilisateur->ville,temp);
	}
	return resultat;
}

//I: Un pointeur sur la struct Profile
//P: Test si la string entree est correcte
//O: 0 si tout est bon ou -1 si il y a un mauvais caractere
int Tester_Region(Profile *pUtilisateur)
{
	int i,taille = strlen(pUtilisateur->region),resultat = 0;
	char temp[50];
	strcpy(temp,pUtilisateur->region);

	if(taille > 0)
	{
		for( i = 0; i < taille; i++)
		{
			if(Test_Caractere_Alphabet(temp[i]) == -1)
			{
				if(Test_Caractere_Symbole(temp[i]) == -1)
				{
					resultat = -1;
					i = taille;
				}
			}
		}
	}
	if(resultat == 0)
	{
		Initial(temp,taille);
		strcpy(pUtilisateur->region,temp);
	}
	return resultat;
}


//I: Un pointeur sur le struct Profile
//P: Teste chaque caractere du pays
//O: 0 si tout est bon et -1 si un caractere est invalide
int Tester_Pays(Profile *pUtilisateur)
{
	int i,resultat = 0,taille = strlen(pUtilisateur->pays);
	char temp[50];
	strcpy(temp,pUtilisateur->pays);

	if(taille == 0)
	{
		resultat = -1;
	}
	else
	{
		for( i = 0; i < taille; i++)
		{
			if(Test_Caractere_Alphabet(temp[i]) == -1)
			{
				resultat = -1;
				i = taille;
			}
		}
	}
	if(resultat == 0)
	{
		Initial(temp,taille);
		strcpy(pUtilisateur->pays,temp);
	}
	return resultat;
}

//I: Un pointeur sur une struct profile
//P: Test la validite d'un mot de passe
//O: 0 si tout est bon et -1 si un caractere est invalide
int Tester_Motdepasse(Profile *pUtilisateur)
{
	int i,resultat = 0,taille = strlen(pUtilisateur->password);
	char temp[50];
	strcpy(temp,pUtilisateur->password);
	if(taille == 0)
	{
		resultat = -1;
	}
	else
	{
		for( i = 0; i < taille; i++)
		{
			//On interdis l'espace
			if(temp[i]==32)
			{
				resultat = -1;
				i = taille;
			}
		} 
	}
	return resultat;
}

//I: Un pointeur sur la struct Profile
//P: Affiche des * pour chaque caractere
//O: /
void Afficher_Motdepasse(Profile *pUtilisateur)
{
	int i,taille = strlen(pUtilisateur->password);
	for(i = 0; i < taille; i++)
	{
		printf("*");
	}
	printf("\n");
}

//I: Un pointeur sur la struct Profile
//P: Teste si la date est valide et si la date est inferieur a la date actuelle
//O: 0 si tout est bon ou -1 si la date est invalide
int Tester_Date(Profile *pUtilisateur)
{
	int resultat = 0;
	//Tester si la date est valide

	if((Test_Date_Valide(pUtilisateur->DdN.jour,pUtilisateur->DdN.mois,pUtilisateur->DdN.annee) == 0) && (Test_Date_Anterieur(pUtilisateur->DdN.jour,pUtilisateur->DdN.mois,pUtilisateur->DdN.annee) == 0) && (Age_Personne(pUtilisateur->DdN.jour,pUtilisateur->DdN.mois,pUtilisateur->DdN.annee) > 13))
	{
		resultat = 0;
	}
	else
	{
		resultat = -1;
	}
	return resultat;
}

//I: Un pointeur sur un utilisateur
//P: Affiche la date de la dernier activite
//O: /
void Afficher_Derniere_Activitee(Profile *pUtilisateur)
{
	struct tm *tm = localtime(&pUtilisateur->lastActivity);

	//Jour
	switch(tm->tm_wday)
	{
		case 0: 
			printf("Dimanche ");
			break;
		case 1:
			printf("Lundi ");
			break;
		case 2:
			printf("Mardi ");
			break;
		case 3:
			printf("Mercredi ");
			break;
		case 4:
			printf("Jeudi ");
			break;
		case 5:
			printf("Vendredi ");
			break;
		case 6:
			printf("Samedi ");
			break;
	}
	//Jour chiffre
	printf("%2d ",tm->tm_mday);
	//Mois
	switch(tm->tm_mon)
	{
		case 0:
			printf("Janvier ");
			break;
		case 1:
			printf("F%cvrier ",130);
			break;
		case 2:
			printf("Mars ");
			break;
		case 3:
			printf("Avril ");
			break;
		case 4:
			printf("Mai ");
			break;
		case 5:
			printf("Juin ");
			break;
		case 6:
			printf("Juillet ");
			break;
		case 7:
			printf("Aout ");
			break;
		case 8:
			printf("Septembre ");
			break;
		case 9:
			printf("Octobre ");
			break;
		case 10:
			printf("Novembre ");
			break;
		case 11:
			printf("Decembre ");
			break;
	}
	//Heure
	printf("%02d:",(tm->tm_hour));
	//Minute
	printf("%02d\n",(tm->tm_min));
}










/**************************************************************************/
/**************************************************************************/
//Fonctions:


//I: Un jour,un mois et une annee
//P: Teste si la date est valide ou non
//O: 0 si tout est bon et -1 si la date n'est pas valide
int Test_Date_Valide(int jour,int mois,int annee)
{
	int resultat = -1;

	if(annee >= 1900)
	{
		if(mois >= 1 && mois <= 12)
		{
			if((jour >= 1 && jour <= 31) && (mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12))
			{
				resultat = 0;
			}
			else
			{
				if((jour >= 1 && jour <= 30) && (mois == 4 || mois == 6 || mois == 9 || mois == 11))
				{
					resultat = 0;
				}
				else
				{
					if((jour >= 1 && jour <= 28) && (mois == 2))
					{
						resultat = 0;
					}
					else
					{
						if((jour == 28) && (mois == 2) && (annee % 400 == 0 || (annee %4 ==0 && annee % 100 != 0)))
						{
							resultat = 0;
						}
						else
						{
							resultat = -1;
						}
					}
				}
			}
		}
		else
		{
			resultat = -1;
		}
	}	
	else
	{
		resultat = -1;
	}
	return resultat;
}

//I: Un jour, un mois et une annee
//P: Test si la date entree est anterieur a ajd
//O: 0 si tout est bon ou -1 si la date n'est pas anterieur a ajd
int Test_Date_Anterieur(int jour,int mois,int annee)
{
	int resultat = 0;
	time_t mtn = time(NULL);
	Date ajd;

	struct tm *tm = localtime(&mtn);

	ajd.jour = tm->tm_mday;
	ajd.mois = tm->tm_mon + 1;
	ajd.annee = tm->tm_year + 1900;
	if(annee <= ajd.annee)
	{
		if(annee == ajd.annee)
		{
			if(mois <= ajd.mois)
			{
				if(mois == ajd.mois)
				{
					if(jour <= ajd.jour)
					{
						//La date est ajd donc valide
					}
					else
					{
						resultat = -1;
					}
				}
			}
			else
			{
				resultat = -1;
			}
		}
	}
	else
	{
		resultat = -1;
	}
	return resultat;
}

//I: Un caractere
//P: Test si le char est un caractere alphabetique
//O: 0 si tout est bon ou -1 si un caractere n'est pas dans l'alphabet
int Test_Caractere_Alphabet(char caractere)
{
	int resultat = 0;
	if(caractere >= 65 && caractere <=122)
	{
		if(caractere >= 91 && caractere <= 96)
		{
			resultat = -1;
		}
	}
	else
	{
		resultat = -1;
	}
	return resultat;
}

//I: Un caractere
//P: Test si le caractere fais parti de la liste des symboles authorisé
//O: /
int Test_Caractere_Symbole(char caractere)
{
	int resultat = 0;
	if(caractere == 45 || caractere == 46 || caractere == 39 || caractere == 44)
	{

	}
	else
	{
		resultat = -1;
	}
	return resultat;
}

//I: Un pointeur sur une chaine de max 50 caractere et la taille de la chaine
//P: Met en majuscule l'ensemble de la chaine
//O: /
void Majuscule_Chaine(char *ptemp)
{
	int i,taille = strlen(ptemp);
	char chaine[50];
	strcpy(chaine,ptemp);
	for(i = 0; i < taille ; i++)
	{
		chaine[i] = Majuscule_Caractere(chaine[i]);
	}
	strcpy(ptemp,chaine);
}

//I: Un pointeur sur une chaine de max 50 caractere et la taille de la chaine
//P: Met en minuscule l'ensemble de la chaine 
//O: /
void Minuscule_Chaine(char *ptemp)
{
	int i,taille = strlen(ptemp);
	char chaine[50];
	strcpy(chaine,ptemp);
	for(i = 0; i < taille; i++)
	{
		chaine[i] = Minuscule_Caractere(chaine[i]);
	}
	strcpy(ptemp,chaine);
}

//I: Un caractere
//P: Le met en majuscule
//O: Un caractere
char Majuscule_Caractere(char caractere)
{
	caractere = toupper(caractere);
	return caractere;
}

//I: Un caractere
//P: Le met en minuscule
//O: Un caractere
char Minuscule_Caractere(char caractere )
{
	caractere = tolower(caractere);
	return caractere;
}

//I: Un caractere
//P: Teste si le caractere entree est une lettre
//O: 0 si le caractere est une lettre et -1 si il ne l'est pas
int Test_Chiffre(char caractere)
{
	int resultat = 0;
	if(caractere < 48 || caractere > 57)
	{
		resultat = -1;
	}
	return resultat;
}

//I: Un pointeur sur une chaine de max 50 caractere et la taille de la chaine
//P: Met en majuscule les premiere lettres de chaque mot
//O: /
void Initial(char *ptemp,int taille)
{
	int i;
	char chaine[50];
	strcpy(chaine,ptemp);
	//On met la premiere lettre en majuscule
	chaine[0] = toupper(chaine[0]);
	for(i = 0; i < taille; i++)
	{
		//Si on a un espace et que la case d'apres ne depace pas la taille du vecteur
		if(chaine[i] == 32 && (i + 1) < taille)
		{
			chaine[i + 1] = toupper(chaine[i + 1]);
		}
	}
	strcpy(ptemp,chaine);
}
	

//I: Un jour,un mois et une annee
//P: Calcule l'age de la personne 
//O: L'gae de la personne
int Age_Personne(int jour,int mois,int annee)
{
	int age;
	time_t mtn = time(NULL);
	Date ajd;
	struct tm *tm = localtime(&mtn);
	ajd.jour = tm->tm_mday;
	ajd.mois = tm->tm_mon + 1;
	ajd.annee = tm->tm_year + 1900;
	age = ajd.annee - annee;
	if(ajd.mois < mois)
	{
		age-=1;
	}
	else
	{
		//Si c'est le mois de son anif
		if(ajd.mois == mois)
		{
			if(ajd.jour <= jour)
			{
				age-=1;
			}
		}
	}
	return age;
}

//I: Un pointeur sur la case des secondes a modifier,un time_t de debut et un time_t de fin
//P: Place le nombre de secondes entre les 2 time_t dans *secondes
//O: /
void Duree(int *seconde,time_t *debut,time_t *fin)
{
	time_t difference = difftime(*debut,*fin);
	struct tm *tm = localtime(&difference);
	*seconde = tm->tm_sec;
}

//I: Un pointeur sur la structure Var_Globale
//P: Lis le fichier globale.dat et place le nbr_profile_cree dans la struct globale
//O:
int Initialiser_Nbr_Profile_Cree(Globale* pVar_Globale)
{
	int erreur = -1;
	FILE * fichier = NULL;
	fichier = fopen(pVar_Globale->globale,"rb");
	if(fichier != NULL)
	{
		if(fread(&(pVar_Globale->nbr_profile_cree),sizeof(int),1,fichier)==1)
		{
			erreur = 0;
		}
		fclose(fichier);
	}
	return erreur;
}

//I: /
//P: Met le programme en pause et attends qu'on appuye sur une touche
//O: /
void Pause()
{
	printf("\nAppuyer sur une touche pour continuer...\n");
	fflush(stdin);
	getchar();
}

//I: Un pointeur sur la structure Var_Globale
//P: Vide le profile dans l'enrseqlog de la struct globale
//O: /
void Vider_Profile(Globale *pVar_Globale)
{
	Profile Vide = {0};
	memcpy(&(pVar_Globale->enrg_seq_log.payload.utilisateur),&Vide,sizeof(Profile));
}










/**************************************************************************/
/**************************************************************************/
//Fonctions Menu:


//I: Un pointeur sur la structure Var_Globale
//P: Affiche tous les profiles
//O: /
int Afficher_Tous_Profils(Globale *pVar_Globale)
{
	int i,erreur = 0;
	for(i = 0; i < 100; i++)
	{
		if(Read_Header(pVar_Globale->profiles,&(pVar_Globale->header))==-1)
		{
			erreur = -1;
			i = 100;
		}
		Afficher_Header(&(pVar_Globale->header));
		if(readFileSeqLog(pVar_Globale->profiles,i,&(pVar_Globale->enrg_seq_log.payload),&(pVar_Globale->enrg_seq_log.offset))==-1)
		{
			erreur = -1;
			i = 100;
		}
		Afficher_Profils(pVar_Globale);
		Vider_Profile(pVar_Globale);
		printf("Offset: %ld\n",pVar_Globale->enrg_seq_log.offset);
		Pause();
	}
	return erreur;
}

//I:
//P:
//O:
void Rechercher_Profils(Globale *pVar_Globale,char *chaine)
{
	//rechercher le profile
}










/**************************************************************************/
/**************************************************************************/
//Fonctions Fichier:


//I: Un pointeur sur le nom d'un fichier
//P: Test si le fichier existe ou non
//O: Return 0 si le fichier existe et -1 si il n'existe pas
int Test_Fichier_Existe(char *fileName)
{
	int resultat = -1;
	FILE *fichier;

	fichier = fopen(fileName, "rb");
	if(fichier != NULL)
    {
        fclose(fichier);
     	resultat = 0;   
    }
    return resultat;
}

//I: Un pointeur sur le nom d'un fichier
//P: Cree un fichier avec le filename donnee
//O: Return 0 si il a reussi a cree le fichier et -1 si il n'a pas pu
int Cree_Fichier(char *fileName)
{
	int erreur = -1;
	FILE *fichier = NULL;

	fichier = fopen(fileName,"wb");
	if(fichier != NULL)
	{
		erreur = 0;
		fclose(fichier);
	}
	return erreur;
}

//I: Un pointeur sur un nom de fichier et un pointeur sur le header a remplir
//P: Lire le contenu du header et le placer dans le pointeur du header
//O: Return 0 si on a reussi a lire le fichier et -1 si on n'a pas su le lire
int Read_Header(char *fileName,Header *pHeader)
{
	int erreur = -1;
  	FILE *fichier = NULL;
  
  	fichier = fopen(fileName,"rb");
  	if(fichier != NULL)
  	{
    	if(fread(pHeader,sizeof(Header),1,fichier)==1)
    	{
    	 	erreur = 0;
    	}
  	}
  return erreur;
}

//I: Un pointeur sur la structure Var_Globale
//P: Affiche le header
//O: /
void Afficher_Header(Header *pHeader)
{
	printf("PTO: %ld\n",pHeader->PTO);
	printf("PTL: %ld\n",pHeader->PTL);
}

//I: Un pointeur sur la structure Var_Globale
//P: Lis le fichier globale.dat et remplis nbr_profile_cree dans globale
//O: Return 0 si on a reussi a remplire nbr_profile_cree ou -1 si il y a une erreur
int Read_Nbr_Profile_Cree(Globale *pVar_Globale)
{
	int erreur = -1;
	int offset = sizeof(PayLoad) + sizeof(Header);
	FILE * fichier = NULL;
	fichier = fopen(pVar_Globale->globale,"rb+");

	if(fichier != NULL)
	{	
		if(fseek(fichier,offset,SEEK_SET)== 0)
		{
			if(fread(&(pVar_Globale->nbr_profile_cree),sizeof(int),1,fichier)==0)
			{
				erreur = 0;
			}
		}
		fclose(fichier);
	}
	return erreur;
}

//I: Un pointeur sur la structure Var_Globale
//P: Ecrit dans le fichier globale.dat le nbr_profile_cree
//O: Return 0 si on a reussi a ecrire la valeur ou -1 si il y a eu un erreur
int Write_Nbr_Profile_Cree(Globale *pVar_Globale)
{
	int erreur = -1;
	int offset = sizeof(PayLoad) + sizeof(Header);
	FILE * fichier = NULL;
	fichier = fopen(pVar_Globale->globale,"rb+");

	if(fichier != NULL)
	{	
		if(fseek(fichier,offset,SEEK_SET)== 0)
		{
			if(fwrite(&(pVar_Globale->nbr_profile_cree),sizeof(int),1,fichier)==1)
			{
				erreur = 0;
			}
		}
		fclose(fichier);
	}
	return erreur;
}

//I: Un pointeur sur un nom de fichier
//P: Test si le fichier est vide
//O: Return 0 si le fichier n'est pas vide ou -1 si il est vide
int Test_Fichier_Vide(char *fileName)
{
	int erreur = -1;
	FILE *fichier = NULL;
	fichier = fopen(fileName,"rb");
	if(fichier != NULL)
	{
		if(fseek(fichier,0,SEEK_END)== 0)
		{
			if(ftell(fichier)!= 0)
			{
				erreur = 0;
			}
		}
		fclose(fichier);
	}
	return erreur;
}

//I: Un pointeur sur la structure Var_Globale
//P: Ecrite dans le fichier globale.dat la struct global
//O: Return 0 si on a reussi a ecrire ou -1 si on a pas su
int Write_Globale(Globale *pVar_Globale)
{
	int erreur = -1;
	FILE *fichier = NULL;
	fichier = fopen("globale.dat","rb+");
	if(fichier != NULL)
	{
		if(fwrite(pVar_Globale,sizeof(Globale),1,fichier)==1)
		{
			erreur = 0;
		}
		fclose(fichier);
	}
	return erreur;
}