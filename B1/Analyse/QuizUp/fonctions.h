#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


//Structures:
//6 octets
typedef struct
{
	short jour;
	short mois;
	short annee;
}Date;

//272 octets
typedef struct
{
	long idProfil;
	char nom[50];
	char codeLangue[3];
	char ville[50];
	char region[50];
	char pays[50];
	char password[50];
	time_t lastActivity;
	Date DdN;
}Profile;

//20 octets
typedef struct
{
	long idProfil;
	long idQuestion;
	long idPartie;
	short reponseDonnee;
	short points;
	time_t timestamp;
}Reponse;

//400 Octets
typedef struct
{
	long idQuestion;
	char theme[50];
	char libelle[144];
	char correctAnswer[50];
	char distracteur1[50];
	char distracteur2[50];
	char distracteur3[50];
}Question;


#include "OrgSeqLog.h"
//OrgIdx
typedef struct
{
  Question question;
} EnrIdx;

typedef struct
{
  EnrIdx enregistrement; // contenu fictif a adapter
  int offset;    // position dans le fichier indexe
} IdxRecord;
#include "OrgIdx.h"

//X Octets
typedef struct 
{
	Header header;				//Variable temporaire a ne jamais ecrire dans le fichier
	EnrSeqLog enrg_seq_log;		//Variable temporaire a ne jamais ecrire dans le fichier
	int nbr_profile_cree;		//A enregistrer dans le fichier
	int questionID;
	char profiles[20];			//profiles.dat
	char questions[20];			//Questions.dat
	char reponses[20];			//reponses.dat
	char globale[20];			//globale.dat
	char nomConnexion[50];		//Variable temporaire a ne jamais ecrire dans le fichier
	int nbrQuestions;
	Question question;	
	int reponseID;
}Globale;





//Encodage et affichage:
int Encoder_Profils(Globale *,int);
int Encoder_Reponses(Globale *);
int Encoder_Questions(Globale *pVar_Globale,int sauvegarder);
void Encoder_Date(Profile *);
void Afficher_Profils(Profile *);
void Afficher_Reponses();
void Afficher_Questions();
void Afficher_Date();

//Contraintes:
int Tester_Nom(Profile *);
int Tester_Langue(Profile *);
int Tester_Ville(Profile *);
int Tester_Region(Profile *);
int Tester_Pays(Profile *);
int Tester_Motdepasse(Profile *);
void Afficher_Motdepasse(Profile *);
void Afficher_Derniere_Activitee(Profile *);
int Tester_Date(Profile *);
int TesterTheme(char *);


//Fonctions:
int Test_Date_Valide(int,int,int);
int Test_Date_Anterieur(int,int,int);
int Test_Caractere_Alphabet(char);
int Test_Caractere_Symbole(char);
void Majuscule_Chaine(char *);
void Minuscule_Chaine(char *);
char Minuscule_Caractere(char);
char Majuscule_Caractere(char);
void Initial(char *);
int Test_Chiffre(char );
int Age_Personne(int ,int ,int);
void Duree(int *,time_t *,time_t *);
void Pause();
int Test_Imprimable(char *);
int GetID(char *);
int InitialiserID(char*);
int InitialiserNbrQuestion(char *);
int WriteID(char*,int);
int WriteNbrQuestions(char *,int);
void AfficherTousQuestions(char *,int);
int AfficherThemes(char *,int);
int IsInList(char *,int ,char *);
int RecercherQuestion(char *,char *,char *);
int writeQuestion(char *,Question *);
int ModifierQuestion(Globale *,char *,int );
int SupprimerQuestion(Globale *,char *);
int GetTheme(char *,int ,char *);
int GetLibelle(char *,int ,char *);
int GetQuestionId(char *);
int GetQuestions(char *,char *,Question *,Question *,Question *,Question *,Question *);
int UpdateLastActivity(Globale *,char *);
int AfficherPartie(Globale *, int );
void GetQuestion(Globale *,int ,Question *);

//Menu:
void Menu_Connexion(Globale *);
void Menu_Principal(Globale *);
void Menu_Profils(Globale *);
void Menu_Reponses(Globale *);
void Menu_Questions(Globale *);

//Fonctions du menu:
int Afficher_Tous_Profils(Globale *);
int Rechercher_Profils(Globale *);
int Modifier_Profile(Globale *);
int Supprimer_Profile(Globale *);
int Connecter(Globale *);

//Fonctions sur fichier
int Initialiser_Nbr_Profile_Cree(Globale*);
int Write_Globale(Globale *);
int Write_Nbr_Profile_Cree(Globale *);
int Read_Nbr_Profile_Cree(Globale *);
int Test_Fichier_Vide(char *);
int Test_Fichier_Existe(char *);
int Cree_Fichier(char*);
void Vider_Profile(Globale*);
int Read_Header(char *,Header*);
void Afficher_Header(Header *);
int Supprimer_Tous_Fichier(Globale *);




#endif // FONCTIONS_H_INCLUDED

;