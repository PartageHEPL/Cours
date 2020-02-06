#include "Moteur.h"
#include "UI.h"
#include "ImageNG.h"

/*
A Faire ou Finir:
UI -> Impossible d'importer une imageNG 
	- Moteur->ImporteImaeNG
	- Dessine crash quand il fait fenetre.open
	- SDL_Init nous donne un seg fault
	- pourtant les dimensions sont bien 256*256 donc
	- la dimension n'est pas le probleme

Une autre méthode mais qui fonctionne pas non plus
int Moteur::ImporteImageNG(const char *fichier)
{
    int id = imagesNG.getNombreElements();
    ImageNG tmp(id, fichier);
    id = Insere(&tmp);
    return id;    
}

UI -> filtre moyenneur demande si on fait sur tout?
UI -> implementer le try catch 
UI -> Changer les coulers des bools sur ImageB
*/


int main()
{
	Moteur moteur;
	UI ui(&moteur);
	
	ui.Start();

	return 0;
}