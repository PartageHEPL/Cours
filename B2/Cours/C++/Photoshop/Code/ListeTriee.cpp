#include "ListeTriee.h"
#include "Utils.h"
#include "ImageNG.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

template <class T> void ListeTriee<T>::insere(const T& val)
{
	Debug("[ListeTriee][insere]val");
	if(this->estVide())
	{
		Cellule<T> *pNew = new Cellule<T>;
		pNew->valeur = val;
		pNew->suivant = NULL;
		this->setPtete(pNew);
	}
	else
	{
		Cellule<T> *pTemp = this->getPtete();
		Cellule<T> *pPrec = NULL;
		Cellule<T> *pNew = new Cellule<T>;
		pNew->valeur = val;
		pNew->suivant = NULL;

		//On trouve la bonne case
		while(pTemp && pTemp->valeur < pNew->valeur)
		{
			pPrec = pTemp;
			pTemp = pTemp->suivant;
		}
		if(pPrec == NULL)
		{
			//On ajoute au debut
			pNew->suivant = pTemp;
			this->setPtete(pNew);
		}
		else
		{
			pPrec->suivant = pNew;
			pNew->suivant = pTemp;
		}
	}
}

template class ListeTriee<int>;
template class ListeTriee<ImageNG>;