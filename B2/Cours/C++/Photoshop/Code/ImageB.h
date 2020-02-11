#ifndef IMAGEB_H
#define IMAGEB_H

#include "Image.h"
#include "Couleur.h"
#include "WindowSDL.h"
#include "PixelB.h"
#include "XYException.h"

class ImageB : public Image
{
	private:
		bool ** matrice;
	public:
		//Constructeurs
		ImageB(void);
		ImageB(int newId, const char* newNom);
		ImageB(const ImageB & copie);
		ImageB(int newId, const char* newNom, const Dimension & newDim);
		~ImageB(void);
		
		//Variables Statiques
		static Couleur couleurTrue;
		static Couleur couleurFalse;

		//Operateurs
		friend ostream& operator<<(ostream& s, const ImageB& image);
		friend ImageB operator+(const PixelB & pixel, ImageB& image);
		ImageB& operator=(const ImageB& image);
		ImageB& operator=(const ImageB* image);
		ImageB operator+(const PixelB & image);
		
		//Setter
		void setDimension(const Dimension & newDim);
		void setPixel (int x, int y, bool newVal) throw (XYException);
		void setBackground (bool val);
		//Getter
		const bool getPixel (int, int) const throw (XYException);

		//Autres
		void Affiche(void) const;
		void Dessine(void) const;
		void exportToBMP(const char * fichier);
		void allocMatrice(void);
		void deleteMatrice(void);
		void Dessine(int x,int y,WindowSDLimage* image);
		void Save(ofstream& fichier) const;
		void Load(ifstream& fichier);
};

#endif
