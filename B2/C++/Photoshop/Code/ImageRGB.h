#ifndef IMAGERGB_H
#define IMAGERGB_H

#include "Image.h"
#include "Couleur.h"
#include "PixelRGB.h"
#include "XYException.h"
#include "WindowSDL.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

class ImageRGB : public Image
{
	private:
		Couleur** matrice;
	public:
		//Constructeurs
		ImageRGB(void);
		ImageRGB(const char* filename);
		ImageRGB(int newId, const char* newNom);
		ImageRGB(int newId, const char* newNom, const Dimension& newDim);
		ImageRGB(const ImageRGB& copie);
		~ImageRGB(void);

		//Operateurs
		ImageRGB& operator=(const ImageRGB& image);
		ImageRGB& operator=(const ImageRGB* image);
		friend ostream& operator<<(ostream& s,const ImageRGB& image);
		friend ImageRGB operator+(const PixelRGB& pixel, ImageRGB& image);
		ImageRGB operator+(const PixelRGB& pixel);

		//Setter
		void setBackground(const Couleur& newCouleur);
		void setPixel(int x, int y, const Couleur& newCouleur) throw (XYException);
		void setDimension(const Dimension &dim);

		//Getter
		Couleur getPixel(int x, int y) const throw (XYException);

		//Autres
		void importFromBMP(const char* filename);
		void exportToBMP(const char*);
		void Affiche(void) const;
		void Dessine(void) const;
		void allocMatrice(void);
		void deleteMatrice(void);
		void Dessine(int x,int y,WindowSDLimage* image);
		void Save(ofstream& fichier) const;
		void Load(ifstream& fichier);
};

#endif //IMAGERGB_H