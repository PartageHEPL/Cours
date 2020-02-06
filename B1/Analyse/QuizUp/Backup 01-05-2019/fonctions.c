#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "fonctions.h"
#include "OrgSeqLog.h"
#include "OrgIdx.h"
#include "OrgSeqPhys.h"


/**************************************************************************/
/**************************************************************************/
//Encodage et affichage:

//I: Un pointeur sur la structure Var_Globale,un int pour savoir si on veut ajouter le profile aux fichier profiles.dat
//P: On va encoder tous les elements d'une struct profils
//O: /
int Encoder_Profils(Globale *pVar_Globale,int sauvegarder)
{
	int erreur = 0;
	printf("Encodez le profile:\n");
	pVar_Globale->enrg_seq_log.payload.utilisateur.idProfil = ((pVar_Globale->nbr_profile_cree) +1) ;
	do
	{
		printf("Entrez votre Nom: ");
		fflush(stdin);
		gets(pVar_Globale->enrg_seq_log.payload.utilisateur.nom);
	}while(Tester_Nom(&(pVar_Globale->enrg_seq_log.payload.utilisateur)) == -1 || Test_Imprimable((char *)&(pVar_Globale->enrg_seq_log.payload.utilisateur.nom))==-1);
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
	}while(Tester_Ville(&(pVar_Globale->enrg_seq_log.payload.utilisateur))== -1 || Test_Imprimable((char *)&(pVar_Globale->enrg_seq_log.payload.utilisateur.ville))==-1);
	do
	{
		printf("Entrez votre r%cgion: ",130);
		fflush(stdin);
		gets(pVar_Globale->enrg_seq_log.payload.utilisateur.region);
	}while(Tester_Region(&(pVar_Globale->enrg_seq_log.payload.utilisateur))== -1 || Test_Imprimable((char *)&(pVar_Globale->enrg_seq_log.payload.utilisateur.region))==-1);
	do
	{
		printf("Entrez votre pays: ");
		fflush(stdin);
		gets(pVar_Globale->enrg_seq_log.payload.utilisateur.pays);
	}while(Tester_Pays(&(pVar_Globale->enrg_seq_log.payload.utilisateur)) == -1 || Test_Imprimable((char *)&(pVar_Globale->enrg_seq_log.payload.utilisateur.pays))==-1);
	do
	{
		printf("Entrez votre mot de passe: ");
		fflush(stdin);
		gets(pVar_Globale->enrg_seq_log.payload.utilisateur.password);
	}while(Tester_Motdepasse(&(pVar_Globale->enrg_seq_log.payload.utilisateur)) == -1 || Test_Imprimable((char *)&(pVar_Globale->enrg_seq_log.payload.utilisateur.password))==-1);

	pVar_Globale->enrg_seq_log.payload.utilisateur.lastActivity = time(NULL);

	Encoder_Date(&(pVar_Globale->enrg_seq_log.payload.utilisateur));
	
	if(sauvegarder == 1)
	{	if(writeFileSeqLog(pVar_Globale->profiles,&(pVar_Globale->enrg_seq_log.payload))==-1)
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
	}
	
	return erreur;
}

//I:
//P:
//O:
int Encoder_Reponses()
{
	/*
	long idProfil; => nom de la personne connecter
	long idQuestion; 
	long idPartie; 
	short reponseDonnee; 1 2 3 4
	short points; -1 => 10 
	time_t timestamp; => nbr de seconde
	*/
	return 0;
}

//I:
//P:
//O:
int Encoder_Questions(Globale *pVar_Globale,int sauvegarder)
{
	Question question;
	int erreur = 0;
	int ID = 0;

	//ID
	ID = GetID(pVar_Globale->globale);
	ID++;
	printf("Id: %d\n",ID);
	question.idQuestion = ID;
	WriteID(pVar_Globale->globale,ID);

	//Theme
	do
	{
		printf("Entrez le th%cme: ",138);
		fflush(stdin);
		gets(question.theme);
	}while(TesterTheme((char *)&(question.theme)) == -1 || Test_Imprimable((char *)&(question.theme)) == -1);	
	//Libelle
	do
	{
		printf("Entrez la question: ");
		fflush(stdin);
		gets(question.libelle);
	}while(Test_Imprimable((char *)(&question.libelle)) == -1);
	//CorrectAnswer
	do
	{
		printf("Entrez la bonne r%cponse: ",130);
		fflush(stdin);
		gets(question.correctAnswer);
	}while(Test_Imprimable((char *)&(question.correctAnswer)) == -1);
	//Distracteur1
	do
	{
		printf("Entrez le distracteur 1: ");
		fflush(stdin);
		gets(question.distracteur1);
	}while(Test_Imprimable((char *)&(question.distracteur1)) == -1);
	//Distracteur2
	do
	{
		printf("Entrez le distracteur 2: ");
		fflush(stdin);
		gets(question.distracteur2);
	}while(Test_Imprimable((char *)&(question.distracteur2)) == -1);
	//Disctracteur3
	do
	{
		printf("Entrez le distracteur 3: ");
		fflush(stdin);
		gets(question.distracteur3);
	}while(Test_Imprimable((char *)&(question.distracteur3)) == -1);
	
	erreur = writeQuestion(pVar_Globale->questions,&question);

	(pVar_Globale->nbrQuestions)++;
	//Incremente le nombre de questions
	WriteNbrQuestions(pVar_Globale->globale,pVar_Globale->nbrQuestions);
	
	return erreur;
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
void Afficher_Profils(Profile *pUtilisateur)
{
	if((pUtilisateur->idProfil) != -1)
	{
		printf("ID Utilisateur: %ld\n",pUtilisateur->idProfil);
		printf("Nom: %s\n",pUtilisateur->nom);
		printf("Langue: %s\n",pUtilisateur->codeLangue);
		printf("Ville: %s\n",pUtilisateur->ville);
		printf("Region: %s\n",pUtilisateur->region);
		printf("Pays: %s\n",pUtilisateur->pays);
		printf("Mot de passe: ");
		Afficher_Motdepasse(pUtilisateur);
		printf("Dernier activitee: ");
		Afficher_Derniere_Activitee(pUtilisateur);
		printf("Date de naissance: %02d/%02d/%d\n",pUtilisateur->DdN.jour,pUtilisateur->DdN.mois,pUtilisateur->DdN.annee);
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
			if(Test_Caractere_Alphabet(temp[i]) == -1 && temp[i] != '-')
			{
				resultat = -1;
				i = taille;
			}
		}
	}
	if(resultat == 0)
	{
		Initial(temp);
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
		Initial(temp);
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
		Initial(temp);
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
		Initial(temp);
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

//I:
//P:
//O:
int TesterTheme(char *theme)
{
	int erreur = 0;
	char temp[50] = {0};
	strcpy(temp,theme);
	int taille = strlen(temp),i;
	for(i = 0; i < taille; i++)
	{
		if(Test_Caractere_Alphabet(temp[i]) == 0)
		{
			erreur = 0;
		}
		else
		{
			if(Test_Chiffre(temp[i]) == 0)
			{
				erreur = 0;
			}
			else
			{
				if(temp[i] == '_' || temp[i] == '-' || temp[i] == '.' || temp[i] == 39)
				{
					erreur = 0;
				}
				else
				{
					erreur = -1;
				}
			}
		}
	}
	return erreur;
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
void Initial(char *ptemp)
{
	int i,taille;
	char chaine[50];
	strcpy(chaine,ptemp);
	taille = strlen(chaine);
	//On met la premiere lettre en majuscule
	chaine[0] = toupper(chaine[0]);
	for(i = 0; i < taille; i++)
	{
		//Si on a un espace et que la case d'apres ne depace pas la taille du vecteur
		if((chaine[i] == 32  || chaine[i] == '-') && (i + 1) < taille)
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
	getch();
}




int Test_Imprimable(char *pmot)
{
	int resultat,i,taille;
	char temp[50] = {0};
	strcpy(temp,pmot);
	taille = strlen(temp);
	for(i = 0; i < taille;i++)
	{
		if(isprint(temp[i])==0)
		{
			resultat = -1;
		}
	}
	return resultat;
}

int GetID(char* filename)
{
	int erreur = 0;
	int offset = sizeof(Header) + sizeof(EnrSeqLog) + sizeof(int);
	FILE *fichier = NULL;
	fichier = fopen(filename,"rb+");

	if(fichier == NULL)
	{
		erreur = -1;
	}
	else
	{
		fseek(fichier,offset,SEEK_SET);
		if(fread(&erreur,sizeof(erreur),1,fichier)!= 1)
		{
			erreur = -1;
		}
		else
		{
			erreur++;
			fseek(fichier,offset,SEEK_SET);
			if(fwrite(&erreur,sizeof(int),1,fichier)!= 1)
			{
				erreur = -1;
			}
			erreur--;
		}
		
	}
	return 0;
}

int InitialiserID(char *filename)
{
	int erreur = 0;
	int offset = sizeof(Header) + sizeof(EnrSeqLog) +sizeof(int);
	FILE *fichier = NULL;
	fichier = fopen(filename,"rb+");

	if(fichier == NULL)
	{
		erreur = -1;
	}
	else
	{
		fseek(fichier,offset,SEEK_SET);
		if(fread(&erreur,sizeof(int),1,fichier) != 1)
		{
			erreur = -1;
		}
	}
	return erreur;
}

int InitialiserNbrQuestion(char * filename)
{
	int erreur = 0;
	int offset = sizeof(Header) + sizeof(EnrSeqLog) + sizeof(int) * 2 + sizeof(char) * 20 * 4 + sizeof(char) * 50;
	FILE *fichier = NULL;
	fichier = fopen(filename,"rb+");

	if(fichier == NULL)
	{
		erreur = -1;
	}
	else
	{
		fseek(fichier,offset,SEEK_SET);
		if(fread(&erreur,sizeof(int),1,fichier) != 1)
		{
			erreur = -1;
		}
	}
	return erreur;
}

//I:
//P:
//O:
int WriteID(char *filename,int ID)
{
	int erreur = 0;
	int offset = sizeof(Header) + sizeof(EnrSeqLog) +sizeof(int);
	FILE *fichier = NULL;
	fichier = fopen(filename,"rb+");

	if(fichier == NULL)
	{
		erreur = -1;
	}
	else
	{
		fseek(fichier,offset,SEEK_SET);
		if(fwrite(&ID,sizeof(int),1,fichier) != 1)
		{
			erreur = -1;
		}
	}
	return erreur;
}

//I:
//P:
//O:
int WriteNbrQuestions(char *filename,int valeur)
{
	int erreur = 0;
	int offset = sizeof(Header) + sizeof(EnrSeqLog) + sizeof(int) * 2 + sizeof(char) * 20 *4 + sizeof(char) * 50;
	FILE *fichier = NULL;
	fichier = fopen(filename,"rb+");

	if(fichier == NULL)
	{
		erreur = -1;
	}
	else
	{
		fseek(fichier,offset,SEEK_SET);
		if(fwrite(&valeur,sizeof(int),1,fichier) != 1)
		{
			erreur = -1;
		}
	}
	return erreur;
}

//I:
//P:
//O:
void AfficherTousQuestions(char * filename,int nbrQuestions)
{
	FILE *fichier = NULL;
	Question temp;

	fichier = fopen(filename,"rb+");
	if(nbrQuestions == 0)
	{
		printf("Il n'y a aucuns questions enregistre!\n");
	}
	while(fread(&temp,sizeof(Question),1,fichier) == 1)
	{
		printf("Question n%c%ld (ID):\n",167,temp.idQuestion);
		printf("Th%cme: %s\n",138,temp.theme);
		printf("Libelle: %s\n",temp.libelle);
		printf("Bonne r%cponse: %s\n",130,temp.correctAnswer);
		printf("Distracteur 1: %s\n",temp.distracteur1);
		printf("Distracteur 2: %s\n",temp.distracteur2);
		printf("Distracteur 3: %s\n",temp.distracteur3);
	}
}

//I:
//P:
//O:
void AfficherThemes(char *filename,int nbrQuestions)
{
	int present;
	char list[10000][20] = {0};	//On va stocker tous les themes dans un tableau puis les comparer
	char *pList = &list[0][0];
	FILE *fichier = NULL;
	Question temp;
	fichier = fopen(filename,"rb+");
	if(nbrQuestions == 0)
	{
		printf("Il n'y a aucuns questions enregistre!\n");
	}
	else
	{
		if(fichier != NULL)
		{
			printf("Voici la liste des th%cmes:\n",138);
			while(fread(&temp,sizeof(Question),1,fichier) == 1)
			{
				present = IsInList(list[0],10000,temp.theme);
				if(!present)
				{
					printf("%s\n",temp.theme);
				}
				strcpy(pList,temp.theme);
				pList++;
			}
		}
		fclose(fichier);
	}
}

int IsInList(char *list,int taille,char *theme)
{
	int i;
	int present = 0;
	for(i = 0; i < taille; i++)
	{
		if(strcmp(list,theme) == 0)
		{
			present = 1;
			i = taille;
		}
		list++;
	}
	return present;
}

int writeQuestion(char * filename,Question *question)
{
	int erreur = -1;

	FILE *fichier = NULL;
	fichier = fopen(filename,"ab");

	if(fichier != NULL)
	{
		if(fwrite(question,sizeof(Question),1,fichier) == 1)
		{
			erreur = 0;
		}
		fclose(fichier);
	}
	return erreur;
}

int RecercherQuestion(char *filename,char *mode,char *cible)
{
	int erreur = 0,trouver = 0;
	Question temp;
	FILE *fichier = NULL;
	fichier = fopen(filename,"rb+");

	if(fichier == NULL)
	{
		erreur = -1;
	}
	else
	{
		if(strcmp(mode,"theme") == 0)
		{
			while(fread(&temp,sizeof(Question),1,fichier) == 1)
			{
				if(strcmp(temp.theme,cible) == 0)
				{
					if(trouver == -1)
					{
						printf("Question n%c%ld => %s\n",167,temp.idQuestion,temp.libelle);
					}
					else if(trouver == 0)
					{
						//Si on trouve le primier
						printf("\nVoici la liste des questions:\n");
						printf("Question n%c%ld => %s\n",167,temp.idQuestion,temp.libelle);
						trouver = -1;
					}					
				}
			}
			if(trouver == 0)
			{
				printf("Aucunes questions trouve avec le theme %s!\n\n",cible);
			}
		}
		else
		{
			if(strcmp(mode,"libelle") == 0)
			{
				while(fread(&temp,sizeof(Question),1,fichier) == 1)
				{
					if(strstr(temp.libelle,cible) != NULL)
					{
						if(trouver == -1)
						{
							printf("Question n%c%ld => %s\n",167,temp.idQuestion,temp.libelle);
						}
						else if(trouver == 0)
						{
							//Si on trouve le premier
							printf("\nVoicie la liste des question contenant le mot %s\n\n",cible);
							printf("Question n%c%ld => %s\n",167,temp.idQuestion,temp.libelle);
							trouver = -1;
						}
					}
				}
				if(trouver == 0)
				{
					printf("Aucunes question trouve contenant le mot %s!\n",cible);
				}
			}
			else
			{
				printf("Mode entree invalide!\n");
				erreur = -1;
			}
		}
		fclose(fichier);
	}

	return erreur;
}

int ModifierQuestion(Globale *pVar_Globale,char *filename,int nbrQuestions)
{
	int erreur = 0,trouver = 0,choixMenuModification = 0;
	int choixMenu;
	char tTemp[50];
	char motTemp[50];
	int ModifierID,position;
	Question aModifier;
	Question temp;
	system("cls");
	printf("\nOption de recherche:\n");
	printf("1. Afficher toute les questions\n");
	printf("2. Afficher les resultat de la recherche sur le nom\n");
	printf("3. Afficher les resultat de la recherche sur le libelle\n");
	do
	{
		printf("Quel est votre choix? ");
		fflush(stdin);
		scanf("%d",&choixMenu);
	}while(choixMenu < 1 || choixMenu > 3);
	printf("\n");
	switch(choixMenu)
	{
		case 1:
			AfficherTousQuestions(pVar_Globale->questions,pVar_Globale->nbrQuestions);
			break;
		case 2:
			printf("Entrez le theme a rechercher: ");
			fflush(stdin);
			gets(tTemp);
			RecercherQuestion(pVar_Globale->questions,"theme",tTemp);
			break;
		case 3:
			printf("Entrez le mot a rechercher: ");
			fflush(stdin);
			gets(motTemp);
			RecercherQuestion(pVar_Globale->questions,"libelle",motTemp);
			break;
	}
	do
	{
		printf("\nQuel question voulez vous modifier? ");
		fflush(stdin);
		scanf("%d",&ModifierID);
	}while(ModifierID > pVar_Globale->questionID);
	
	FILE *fichier = NULL;
	fichier = fopen(filename,"rb+");

	if(fichier == NULL)
	{
		erreur = -1;
	}
	else
	{
		while(fread(&aModifier,sizeof(Question),1,fichier) == 1 && trouver == 0)
		{
			if(aModifier.idQuestion == ModifierID)
			{
				//On a trouver la bonne question
				position = ftell(fichier);
				trouver = 1;
			}
		}
		if(trouver == 0)
		{
			printf("Impossible de trouver la question avec l'ID %d\n",ModifierID);
		}
		else
		{
			//Si on a trouver la fiche on peu la modifier
			system("cls");
			//Afficher
			printf("Voici la question a modifier:\n\n");
			printf("Question n%c%ld (ID):\n",167,aModifier.idQuestion);
			printf("Th%cme: %s\n",138,aModifier.theme);
			printf("Libelle: %s\n",aModifier.libelle);
			printf("Bonne r%cponse: %s\n",130,aModifier.correctAnswer);
			printf("Distracteur 1: %s\n",aModifier.distracteur1);
			printf("Distracteur 2: %s\n",aModifier.distracteur2);
			printf("Distracteur 3: %s\n",aModifier.distracteur3);

			//Menu
			printf("\nMenu de modifications:\n");
			printf("1. Modifier le theme\n");
			printf("2. Modifier le libelle\n");
			printf("3. Modifier la bonne reponse\n");
			printf("4. Modifier le distracteur 1\n");			
			printf("5. Modifier le distracteur 2\n");
			printf("6. Modifier le distracteur 3\n");
			do
			{
				printf("Quel est votre choix? ");
				fflush(stdin);
				scanf("%d",&choixMenuModification);
			}while(choixMenuModification < 1 ||choixMenuModification > 6);

			//Modifier
			switch(choixMenuModification)
			{
				case 1:
					do
					{
						printf("\nEntrez le nouvrea th%cme: ",138);
						fflush(stdin);
						gets(temp.theme);
					}while(TesterTheme((char *)&(temp.theme)) == -1 || Test_Imprimable((char *)&(temp.theme)) == -1);	
					strcpy(aModifier.theme,temp.theme);
					break;
				case 2:
					do
					{
						printf("\nEntrez la nouvelle question: ");
						fflush(stdin);
						gets(temp.libelle);
					}while(Test_Imprimable((char *)(&temp.libelle)) == -1);
					strcpy(aModifier.libelle,temp.libelle);
					break;	
				case 3:
					do
					{
						printf("\nEntrez la nouvelle bonne r%cponse: ",130);
						fflush(stdin);
						gets(temp.correctAnswer);
					}while(Test_Imprimable((char *)&(temp.correctAnswer)) == -1);
					strcpy(aModifier.correctAnswer,temp.correctAnswer);
					break;
				case 4:
					do
					{
						printf("\nEntrez le nouveau distracteur 1: ");
						fflush(stdin);
						gets(temp.distracteur1);
					}while(Test_Imprimable((char *)&(temp.distracteur1)) == -1);
					strcpy(aModifier.distracteur1,temp.distracteur1);
					break;
				case 5:
					do
					{
						printf("\nntrez le nouveau distracteur 2: ");
						fflush(stdin);
						gets(temp.distracteur2);
					}while(Test_Imprimable((char *)&(temp.distracteur2)) == -1);
					strcpy(aModifier.distracteur2,temp.distracteur2);
					break;
				case 6:
					do
					{
						printf("\nEntrez le nouveau tempdistracteur 3: ");
						fflush(stdin);
						gets(temp.distracteur3);
					}while(Test_Imprimable((char *)&(temp.distracteur3)) == -1);
					strcpy(aModifier.distracteur3,temp.distracteur3);
					break;
			}
			//Ecrire dans le fichier aModifier
			fseek(fichier,(position - sizeof(Question)),SEEK_SET);
			if(fwrite(&aModifier,sizeof(Question),1,fichier) != 1)
			{
				erreur = -1;
			}
		}
		fclose(fichier);
	}

	return erreur;
}




/**************************************************************************/
/**************************************************************************/
//Fonctions Menu:


//I: Un pointeur sur la structure Var_Globale
//P: Affiche tous les profiles
//O: /
int Afficher_Tous_Profils(Globale *pVar_Globale)
{
	int erreur = 0;
	Header header;
	EnrSeqLog temp = {{{0}},-1};
	FILE *fichier = NULL;
	fichier = fopen(pVar_Globale->profiles,"rb");
	if(fichier != NULL)
	{
		system("cls");
		if((pVar_Globale->nbr_profile_cree) == 0)
		{
			printf("Aucuns profiles dans %s\n",pVar_Globale->profiles);
		}
		else
		{
			printf("Liste des profiles dans l'ordre alphab%ctique:\n\n",130);
			if(fread(&header,sizeof(Header),1,fichier)!=1)
			{
				erreur = -1;
			}
			fclose(fichier);
			temp.offset = header.PTO;
			while(temp.offset != -1)
			{
				if(readFileSeqLog(pVar_Globale->profiles,temp.offset,&(temp.payload),&(temp.offset),NULL)== -1)
				{
					erreur = -1;
				}
				else
				{
					Afficher_Profils(&(temp.payload.utilisateur));
					printf("\n");
				}

			}
		}
		
	}
	return erreur;
}

//I:
//P:
//O:
int Rechercher_Profils(Globale *pVar_Globale)
{
	int trouver = 0;
	char nom[50] = {0};
	Header header;
	EnrSeqLog temp = {{{0}},-1};
	system("cls");
	if(pVar_Globale->nbr_profile_cree == 0)
	{
		printf("Le fichier %s est vide!\n",pVar_Globale->profiles);
		return 0;
	}
	FILE *fichier = NULL;
	fichier = fopen(pVar_Globale->profiles,"rb");
	printf("Entrez le nom a rechercher: ");
	fflush(stdin);
	gets(nom);
	Initial(nom);
	if(fichier != NULL)
	{
		system("cls");
		fread(&header,sizeof(Header),1,fichier);
		fclose(fichier);
		temp.offset = header.PTO;
		while(temp.offset != -1)
		{
			readFileSeqLog(pVar_Globale->profiles,temp.offset,&(temp.payload),&(temp.offset),NULL);
			if(strcmp(temp.payload.utilisateur.nom,nom)==0)
			{
				if(trouver == 0)
				{
					printf("Liste des profiles trouv%c:\n\nAppuyer",130);
				}
				Afficher_Profils(&(temp.payload.utilisateur));
				trouver++;
			}
		}
	}
	return trouver;
}



int Modifier_Profile(Globale *pVar_Globale)
{
	int erreur = -1,trouver = 0,ID = -1,continuerModifications = -1,choixMenu = -1;
	long position = 0;
	Header header;
	EnrSeqLog temp = {{{0}},-1};
	system("cls");
	if(pVar_Globale->nbr_profile_cree == 0)
	{
		printf("Le fichier %s est vide!\n",pVar_Globale->profiles);
		return erreur;
	}
	Afficher_Tous_Profils(pVar_Globale);
	printf("Entrez l'Id du profile %c modifier: ",133);
	fflush(stdin);
	scanf("%d",&ID);
	FILE *fichier = NULL;
	fichier = fopen(pVar_Globale->profiles,"rb+");
	if(fichier!=NULL)
	{
		fread(&header,sizeof(Header),1,fichier);
		fclose(fichier);
		if(header.PTO != -1)
		{
			temp.offset = header.PTO;
			while(temp.offset != -1)
			{
				readFileSeqLog(pVar_Globale->profiles,temp.offset,&(temp.payload),&(temp.offset),&position);
				if(ID == (temp.payload.utilisateur.idProfil))
				{
					trouver++;
					system("cls");
					printf("Profile trouv%c:\n\n",130);
					Afficher_Profils(&(temp.payload.utilisateur));
					printf("\n");
					Vider_Profile(pVar_Globale);
					//Copier temp
					pVar_Globale->enrg_seq_log.payload = temp.payload;
					//Menu de modifications
					do
					{
						if(continuerModifications == 1)
						{
							system("cls");
							printf("Etat acutel du profile:\n\n");
							Afficher_Profils(&(pVar_Globale->enrg_seq_log.payload.utilisateur));
							printf("\n");
						}
						printf("Menu des modifications:\n");
						printf("1. Modifier le nom\n");
						printf("2. Modifier la langue\n");
						printf("3. Modifier la ville\n");
						printf("4. Modifier la region\n");
						printf("5. Modifier le pays\n");
						printf("6. Modifier le mot de passe\n");
						printf("7. Modifier la date de naissance\n");
						printf("8. Quitter\n");
						do
						{
							printf("Quel est votre choix? ");
							fflush(stdin);
							scanf("%d",&choixMenu);
						}while(choixMenu < 1 || choixMenu > 8);
						switch(choixMenu)
						{
							case 1:
								do
								{
									printf("Entrez un nom: ");
									fflush(stdin);
									gets(pVar_Globale->enrg_seq_log.payload.utilisateur.nom);
								}while(Tester_Nom(&(pVar_Globale->enrg_seq_log.payload.utilisateur)) == -1 || Test_Imprimable((char *)&(pVar_Globale->enrg_seq_log.payload.utilisateur.nom))==-1);
								break;
							case 2:
								do
								{
									printf("Entrez votre langue(FR,EN,DE,NL): ");
									fflush(stdin);
									gets(pVar_Globale->enrg_seq_log.payload.utilisateur.codeLangue);
								}while(Tester_Langue(&(pVar_Globale->enrg_seq_log.payload.utilisateur)) == -1);
								break;
							case 3:
								do
								{
									printf("Entrez votre ville: ");
									fflush(stdin);
									gets(pVar_Globale->enrg_seq_log.payload.utilisateur.ville);
								}while(Tester_Ville(&(pVar_Globale->enrg_seq_log.payload.utilisateur))== -1 || Test_Imprimable((char *)&(pVar_Globale->enrg_seq_log.payload.utilisateur.ville))==-1);
								break;
							case 4:
								do
								{
									printf("Entrez votre r%cgion: ",130);
									fflush(stdin);
									gets(pVar_Globale->enrg_seq_log.payload.utilisateur.region);
								}while(Tester_Region(&(pVar_Globale->enrg_seq_log.payload.utilisateur))== -1 || Test_Imprimable((char *)&(pVar_Globale->enrg_seq_log.payload.utilisateur.region))==-1);
								break;
							case 5:
								do
								{
									printf("Entrez votre pays: ");
									fflush(stdin);
									gets(pVar_Globale->enrg_seq_log.payload.utilisateur.pays);
								}while(Tester_Pays(&(pVar_Globale->enrg_seq_log.payload.utilisateur)) == -1 || Test_Imprimable((char *)&(pVar_Globale->enrg_seq_log.payload.utilisateur.pays))==-1);
								break;
							case 6:
								do
								{
									printf("Entrez votre mot de passe: ");
									fflush(stdin);
									gets(pVar_Globale->enrg_seq_log.payload.utilisateur.password);
								}while(Tester_Motdepasse(&(pVar_Globale->enrg_seq_log.payload.utilisateur)) == -1 || Test_Imprimable((char *)&(pVar_Globale->enrg_seq_log.payload.utilisateur.password))==-1);
								break;
							case 7:
								Encoder_Date(&(pVar_Globale->enrg_seq_log.payload.utilisateur));
								break;
							case 8:
								break;
						}
						//Update lastActivity
						pVar_Globale->enrg_seq_log.payload.utilisateur.lastActivity = time(NULL);
						//Garder l'id car on ne peut la modifier
						pVar_Globale->enrg_seq_log.payload.utilisateur.idProfil = temp.payload.utilisateur.idProfil;
						printf("Continuer %c modifier le profile?\n",133);
						printf("0. Non\n");
						printf("1. Oui\n");
						do
						{
							printf("Quel est votre choix? ");
							fflush(stdin);
							scanf("%d",&continuerModifications);
						}while(continuerModifications < 0 || continuerModifications > 1);
					}while(continuerModifications == 1);
					system("cls");
					printf("Profile apr%cs modifications:\n\n",138);
					Afficher_Profils(&(pVar_Globale->enrg_seq_log.payload.utilisateur));
					fichier = fopen(pVar_Globale->profiles,"rb+");
					if(fichier!= NULL)
					{
						fseek(fichier,position,SEEK_SET);
						if(fwrite(&(pVar_Globale->enrg_seq_log.payload),sizeof(PayLoad),1,fichier)==1)
						{
							erreur = 0;
						}
					}
					Vider_Profile(pVar_Globale);
					break;
				}
			}
			if(trouver == 0)
			{
				printf("\nAucuns profiles trouver avec l'ID: %d\n",ID);
			}
		}
		fclose(fichier);
	}
	return erreur;
}


int Supprimer_Profile(Globale *pVar_Globale)
{
	int erreur = -1;
	char nom[50] = {0};
	long position = 0;
	EnrSeqLog temp = {{{0}},-1};
	Header header;
	system("cls");
	if(pVar_Globale->nbr_profile_cree == 0)
	{
		printf("Aucuns profiles a supprimer dans %s\n",pVar_Globale->profiles);
		return erreur;
	}
	Afficher_Tous_Profils(pVar_Globale);
	printf("Entrez le nom du profile a supprimer: ");
	fflush(stdin);
	gets(nom);
	Initial(nom);
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
				readFileSeqLog(pVar_Globale->profiles,temp.offset,&(temp.payload),&(temp.offset),&position);
				if(strcmp(temp.payload.utilisateur.nom,nom)==0)
				{
					//Tester le retour de la fonction
					printf("Suppression du profile %s\n",nom);
					deleteFileSeqLog(pVar_Globale->profiles,(position - sizeof(Header))/sizeof(EnrSeqLog));
					erreur = 0;
					break;
				}
				Vider_Profile(pVar_Globale);
			}
		}
		pVar_Globale->nbr_profile_cree--;
		Write_Nbr_Profile_Cree(pVar_Globale);
	}
	return erreur;
}


int Connecter(Globale *pVar_Globale)
{
	Header header = {0};
	EnrSeqLog temp = {{{0}},-1};
	int erreur = -1;
	char mdp[50] = {0};
	printf("Entrez votre nom: ");
	fflush(stdin);
	gets(pVar_Globale->nomConnexion);
	printf("Entrez le mot de passe: ");
	fflush(stdin);
	gets(mdp);
	if(strcmp(pVar_Globale->nomConnexion,"root") == 0 && strcmp(mdp,"azerty")== 0)
	{
		erreur = 0;
	}
	else
	{
		Initial(pVar_Globale->nomConnexion);
		//Verifier le nom et le mdp dans le fichier profiles.dat
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
					if(strcmp(temp.payload.utilisateur.nom,pVar_Globale->nomConnexion)== 0 && strcmp(temp.payload.utilisateur.password,mdp)== 0)
					{
						//L'utilisateur est bien connecter
						erreur = 0;
					}
				}
			}
			fclose(fichier);
		}
	}
	return erreur;
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
	int offset = sizeof(EnrSeqLog) + sizeof(Header);
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
	int offset = sizeof(EnrSeqLog) + sizeof(Header);
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

//I: /
//P: Supprime tous les fichiers .dat du programme
//O: /
void Supprimer_Tous_Fichier(Globale *pVar_Globale)
{
	remove(pVar_Globale->profiles);
	remove(pVar_Globale->questions);
	remove(pVar_Globale->reponses);
	remove(pVar_Globale->globale);
}

//I: Un pointeur sur la structure Var_Globale
//P: Vide le profile dans l'enrseqlog de la struct globale
//O: /
void Vider_Profile(Globale *pVar_Globale)
{
	Profile Vide = {0};
	memcpy(&(pVar_Globale->enrg_seq_log.payload.utilisateur),&Vide,sizeof(Profile));
}

