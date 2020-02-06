#ifndef ITERATEUR_H
#define ITERATEUR_H

#include "ListeBase.h"
#include "Cellule.h"

template <class T> class Iterateur
{
	private:
		ListeBase<T>& liste;
		Cellule<T> *position;
	public:
		Iterateur(ListeBase<T>& l);
		~Iterateur(void);
		void reset(void);
		bool end(void) const;
		T remove(void);
		void operator++(void);
		void operator++(int);
		operator T(void);
		T& operator&(void);
};

#endif //ITERATEUR_H