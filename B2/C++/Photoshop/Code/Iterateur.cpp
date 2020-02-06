#include "Iterateur.h"
#include "Utils.h"
#include "Couleur.h"
#include "ImageB.h"
#include "ImageNG.h"
#include "ImageRGB.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

template <class T> Iterateur<T>::Iterateur(ListeBase<T>& l) : liste(l), position(l.getPtete())
{
	Debug("[Iterateur]Constructeur(init)");
}

template <class T> Iterateur<T>::~Iterateur(void)
{
	Debug("[Iterateur]Destructeur");
	position = NULL;
	delete [] position;
}

template <class T> void Iterateur<T>::reset(void)
{
	Debug("[Iterateur]reset");
	position = liste.getPtete();
}

template <class T> bool Iterateur<T>::end(void) const
{
	Debug("[Iterateur]end");
	if(position == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T> T Iterateur<T>::remove(void)
{
	Debug("[Iterateur]remove");
	T resultat;
	Cellule<T> *pTemp = liste.getPtete();
	Cellule<T> *pPrec = NULL;

	if(position == NULL)
	{
		cout << "[Iterateur][remove]Erreur position == NULL" << endl;
	}

	//Premiere position
	if(pTemp == position)
	{
		liste.setPtete(liste.getPtete()->suivant);
		resultat = pTemp->valeur;
	}
	else
	{
		//Au milieu ou a la fin
		while(pTemp != position)
		{
			pPrec = pTemp;
			pTemp = pTemp->suivant;
		}
		pPrec->suivant = pTemp->suivant;
		resultat = pTemp->valeur;
		delete [] pTemp;
	}
	return resultat;
}

template <class T> void Iterateur<T>::operator++(void)
{
	Debug("[Iterateur]operator++()");
	if(position)
	{
		position = position->suivant;
	}
}

template <class T> void Iterateur<T>::operator++(int)
{
	Debug("[Iterateur]Operator++(int)");
	return operator++();
}

template <class T> Iterateur<T>::operator T(void) 
{
	Debug("[Iterateur]Operator T(cast)");
	return position->valeur;
}

template <class T> T& Iterateur<T>::operator&(void) 
{
	Debug("[Iterateur]Operator T(cast)");
	return position->valeur;
}

template class Iterateur<int>;
template class Iterateur<Couleur>;
template class Iterateur<ImageNG>;
template class Iterateur<ImageRGB>;
template class Iterateur<ImageB>;