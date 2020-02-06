#ifndef OrgSeqLog_H_INCLUDED
#define OrgSeqLog_H_INCLUDED

/*********************************************************************/
/* Manipulation de fichiers binaires.                                */
/*  Organisation sequentielle logique.                               */
/*  Taille d'enregistrement fixe.                                    */
/*  Adressage par numero d'enregistrement (de 0 a nbenreg-1          */
/*  Fichier non bidonné                                              */
/*********************************************************************/
//272 octets
typedef struct 
{
	Profile utilisateur;
}PayLoad;
//8 octets
typedef struct
{
  long PTO;
  long PTL;
}Header;   // structure destinee a contenir PTO et PTL
//276 octets
typedef struct
{
  PayLoad payload;  // contenu fictif a adapter
  long    offset;   // numero de l'enregistrement suivant dans l'ordre logique choisi. -1 pour le dernier.
}EnrSeqLog;

int createFileSeqLog(char *);                           // Creer fichier SeqLog
int writeFileSeqLog(char *,PayLoad *);                  // Ajouter enregistrement SeqLog
int comparePayLoad(PayLoad *,PayLoad *);                // Comparer le contenu de deux enregistrements pour les classer
int searchFileSeqLog(char *,char *,long,PayLoad *);     // Chercher un enregistrement SeqLog
int deleteFileSeqLog(char *,long deletepos);            // Supprimer un enregistrement SeqLog
int readFileSeqLog(char * ,long ,PayLoad * ,long *);  	//Lire un enregistrement




#endif // OrgSeqLog_H_INCLUDED