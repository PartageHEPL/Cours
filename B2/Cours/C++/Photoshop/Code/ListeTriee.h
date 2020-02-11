#ifndef LISTETRIEE_H
#define LISTETRIEE_H

#include "ListeBase.h"

template <class T> class ListeTriee : public ListeBase<T>
{
	public:
		void insere(const T& val);
};

#endif //LISTETRIEE_H