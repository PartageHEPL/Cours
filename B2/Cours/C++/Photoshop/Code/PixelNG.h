#ifndef PIXELNG_H
#define PIXELNG_H

#include "Pixel.h"
#include "RGBException.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class PixelNG : public Pixel
{
	private:
		int valeur;
	public:
		//Constructeurs
		PixelNG(void);
		PixelNG(int x,int y,int newVal);
		PixelNG(const  PixelNG& copie);
		~PixelNG(void);
		
		//Operateurs
		PixelNG operator=(const PixelNG& pixel);
		friend ostream& operator<<(ostream& s,const PixelNG& pixel);
		
		//Setter
		void setValeur(int newVal) throw (RGBException);

		//Getter
		int getValeur(void) const;
};


#endif //PIXELNG_H