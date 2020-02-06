#ifndef PIXELRGB_H
#define PIXELRGB_H

#include "Pixel.h"
#include "Couleur.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class PixelRGB : public Pixel
{
	protected:
		Couleur valeur;
	public:
		//Constructeurs
		PixelRGB(void);
		PixelRGB(int x, int y,const Couleur couleur);
		PixelRGB(const PixelRGB& copie);
		~PixelRGB(void);

		//Operateurs
		friend ostream& operator<<(ostream& s, const PixelRGB& pixel);
		
		//Setter
		void setValeur(Couleur newCouleur);
		
		//Getter
		const Couleur& getValeur(void) const;
		
};


#endif //PIXELRGB_H