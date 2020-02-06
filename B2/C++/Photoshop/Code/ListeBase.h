#ifndef LISTEBASE_H
#define LISTEBASE_H

#include "Cellule.h"

template <class T> class ListeBase
{
	protected :
		Cellule<T> *pTete;

	public:
		ListeBase(void);
		ListeBase(ListeBase<T>& copie);
		~ListeBase(void);

		bool estVide(void) const;
		int getNombreElements(void) const;
		void Affiche(void) const;
		void virtual insere(const T & val) = 0;
		ListeBase<T>& operator=(const ListeBase<T>& liste);

		void setPtete(Cellule<T>*);

		Cellule<T>* getPtete(void) const;
};

#endif //LISTEBASE_H