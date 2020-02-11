#include "Liste.h"
#include "Utils.h"
#include "Couleur.h"
#include "ImageB.h"
#include "ImageNG.h"
#include "ImageRGB.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

template<class T> void Liste<T>::insere(const T& val)
{
	Debug("[Liste][insere]");
	Cellule<T> *pNew = new Cellule<T>;
	Cellule<T> *pTemp = this->getPtete();
	pNew->valeur = val;
	pNew->suivant = NULL;

	if(!this->estVide())
	{
		while(pTemp->suivant)
		{
			pTemp = pTemp->suivant;
		}
		pTemp->suivant = pNew;
	}
	else
	{
		this->setPtete(pNew);
	}
}

template class Liste<int>;
template class Liste<Couleur>;
template class Liste<ImageNG>;
template class Liste<ImageRGB>;
template class Liste<ImageB>;