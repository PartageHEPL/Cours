#ifndef PIXELB_H
#define PIXELB_H

#include "Pixel.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class PixelB : public Pixel
{
	private:
		bool valeur;
	public:
		//Constructeur
		PixelB(void);
		PixelB(const PixelB & copie);
		PixelB(int x, int y, bool newVal);
		~PixelB(void);
		
		//Operateurs
		friend ostream& operator<<(ostream&, const PixelB&);

		//Setter
		void setValeur(bool newVal);

		//Getter
		const bool getValeur(void) const;
		
};

#endif //PIXELB_H