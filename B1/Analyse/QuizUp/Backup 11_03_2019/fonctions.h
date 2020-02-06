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

typedef struct 
{
	Header header;
	EnrSeqLog enrg_seq_log;
	int nbr_profile_cree;
	char profiles[20];
	char questions[20];
	char reponses[20];
	char parties[20];
	char globale[20];	
}Globale;

/*
//x octets
typedef struct partie
{
long idPartie;
long idProfile
//Combien de question et reponses? 1 ou 5?
int totalPoints;
}
*/

//Encodage et affichage:
int Encoder_Profils(Globale *);
void Encoder_Reponses();
void Encoder_Questions();
void Encoder_Date(Profile *);
void Afficher_Profils(Globale *);
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

//Fonctions:
int Test_Date_Valide(int,int,int);
int Test_Date_Anterieur(int,int,int);
int Test_Caractere_Alphabet(char);
int Test_Caractere_Symbole(char);
void Majuscule_Chaine(char *);
void Minuscule_Chaine(char *);
char Minuscule_Caractere(char);
char Majuscule_Caractere(char);
void Initial(char *,int );
int Test_Chiffre(char );
int Age_Personne(int ,int ,int);
void Duree(int *,time_t *,time_t *);
void Pause();




//Menu:
void Menu_Principal(Globale *);
void Menu_Profils(Globale *);
void Menu_Reponses(Globale *);
void Menu_Questions(Globale *);

//Fonctions du menu:
int Afficher_Tous_Profils(Globale *);
void Rechercher_Profils(Globale *,char *);


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

#endif // FONCTIONS_H_INCLUDED