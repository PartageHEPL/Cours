#ifndef UI_H
#define UI_H

#include "Moteur.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


class UI
{
	private:
		Moteur *moteur;
	public:
		UI(Moteur *pMoteur);
		~UI(void);

		void Menu(void);
		void Start(void);
};

#endif //UI_H