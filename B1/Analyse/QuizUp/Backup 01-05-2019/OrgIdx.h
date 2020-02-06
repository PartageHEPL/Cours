#include "fonctions.h"

/*********************************************************************/
/* Manipulation de fichiers binaires.                                */
/*  Organisation indexée.                                            */
/*  Fichier bidonné (taille BIDONSIZE enregistrements).              */
/*  Taille d'enregistrement fixe.                                    */
/*  Adressage par numero d'enregistrement (de 0 a nbenreg-1          */
/*********************************************************************/


int createFileIdx(char *, int);                     // Creer et bidonner un fichier Idx
int allocateIdx(IdxRecord **, int);                 // Allouer la memoire pour le tableau Index
IdxRecord * buildIdx(char *,int*);                       // Construire un index
int insertIdx(IdxRecord *,IdxRecord *,int);         // Insere un enregistrement dans l'index
int compareIdxEnreg(IdxRecord *,IdxRecord *);       // Compare deux enregistrements d'index
int writeFileIdx(char *,EnrIdx *);                  // Ajouter enregistrement Idx
int readFileIdx(char *,EnrIdx *,long);              // Lire enregistrement Idx
int searchFileIdx(char *,char *,long,EnrIdx *);     // Chercher un enregistrement Idx
int updateFileIdx(char *,long, EnrIdx *);           // Modifier un enregistrement Idx
