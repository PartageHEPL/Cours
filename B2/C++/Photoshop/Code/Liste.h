#ifndef LISTE_H
#define LISTE_H

#include "ListeBase.h"

template <class T> class Liste : public ListeBase<T>
{
	public:
		void insere(const T & val);
};

#endif //LISTE_H