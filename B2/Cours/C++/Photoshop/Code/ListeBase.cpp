#include "ListeBase.h"
#include "Couleur.h"
#include "ImageNG.h"
#include "ImageRGB.h"
#include "ImageB.h"
#include "Utils.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

template<class T> ListeBase<T>::ListeBase(void)
{
	Debug("[ListeBase][Constructeur]void");
	this->pTete = NULL;
}

template<class T> ListeBase<T>::ListeBase(ListeBase<T>& copie)
{
	Debug("[ListeBase][Constructeur]copie");
	this->setPtete(NULL);
	Cellule<T> *pNew = this->getPtete();
	Cellule<T> *pPrec = NULL;
	Cellule<T> *pTempCopie = copie.getPtete();

	while(pTempCopie)
	{
		pNew = new Cellule<T>;
		pNew->valeur = pTempCopie->valeur;
		pNew->suivant = NULL;

		if(pPrec)
		{
			pPrec->suivant = pNew;
		}
		else
		{
			this->setPtete(pNew);
		}
		pPrec = pNew;
		pTempCopie = pTempCopie->suivant;
		pNew = pNew->suivant;
	}
}

template<class T> ListeBase<T>::~ListeBase(void)
{
	Debug("[ListeBase][Destructeur]void");

	Cellule<T> *pTemp = this->pTete;
	Cellule<T> *pPrec;

	//On fait tout les delete
	if(this->pTete != NULL)
	{
		while(pTemp != NULL)
		{
			pPrec = pTemp;
			pTemp = pTemp->suivant;
			if(pPrec)
			{
				delete [] pPrec;
			}
		}
	} 
}

template<class T> bool ListeBase<T>::estVide(void) const
{
	Debug("[ListeBase][estVide]void");
	if(this->getNombreElements() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T> int ListeBase<T>::getNombreElements(void) const
{
	Debug("[ListeBase][getNombreElements]void");

	int nbrElements = 0;
	Cellule<T> *pTemp = this->pTete;
	if(this->pTete != NULL)
	{
		while(pTemp != NULL)
		{
			pTemp = pTemp->suivant;
			nbrElements++;
		}
	}
	return nbrElements;
}

template<class T> void ListeBase<T>::Affiche(void) const
{
	Debug("[ListeBase][Affiche]void");
	Cellule<T> *pTemp = this->pTete;
	cout << "Liste: (";
	if(this->pTete != NULL)
	{
		while(pTemp != NULL)
		{
			cout << pTemp->valeur;
			if(pTemp->suivant != NULL)
			{
				cout << " ";
			}
			pTemp = pTemp->suivant;
		}
	}
	cout << ")" << endl;
}

template<class T> ListeBase<T>& ListeBase<T>::operator=(const ListeBase<T>& liste)
{
	Debug("[ListeBase][operator=]liste");
	//On supprime tout
	Cellule<T> *pCur;
	while (pTete != NULL)
	{
		pCur = pTete->suivant;
		delete pTete;
		pTete = pCur;
	}
	//On recopie
	Cellule<T> *pPrec=NULL;
	Cellule<T> *pTemp=liste.pTete;
	Cellule<T> *pPrem = new Cellule<T>;
	pPrem->valeur=pTemp->valeur;
	pPrem->suivant=NULL;
	pTete=pPrem;
	pPrec=pPrem;
	pTemp=pTemp->suivant;
	while(pTemp!=NULL)
	{
	
		Cellule<T> *pNew= new Cellule<T>;
		pNew->valeur=pTemp->valeur;
		pPrec->suivant=pNew;
		pPrec=pNew;
		pNew->suivant=NULL;
		pTemp=pTemp->suivant;
	}
	return *this;
}

template<class T> void ListeBase<T>::setPtete(Cellule<T>* newTete)
{
	Debug("[ListeBase][setPtete]newTete");
	pTete = newTete;
}

template<class T> Cellule<T>* ListeBase<T>::getPtete(void) const
{
	Debug("[ListeBase][getPtete]void");
	return pTete;
}

//Instancier les templates
template class ListeBase<int>;
template class ListeBase<Couleur>;
template class ListeBase<ImageNG>;
template class ListeBase<ImageRGB>;
template class ListeBase<ImageB>;