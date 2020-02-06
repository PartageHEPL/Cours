#ifndef IMAGENG_H
#define IMAGENG_H

#include "Image.h"
#include "Dimension.h"
#include "PixelNG.h"
#include "XYException.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

class ImageNG : public Image
{
	private:
		int **matrice;
		static int comparaison;
	public:
		//Constructeurs
		ImageNG(void);
		ImageNG(const char* newImage);
		ImageNG(int newId,const char* newNom);
		ImageNG(int newId,const char* newNom,const Dimension & newDim);
		ImageNG(const ImageNG& copie);
		~ImageNG(void);

		//Variables Statiques
		static const int LUMINANCE;
		static const int PIXEL_A_PIXEL;

		//Operateurs
		ImageNG& operator=(const ImageNG& image);
		ImageNG& operator=(const ImageNG* image);
		ImageNG operator+(int val);
		ImageNG operator-(int val);
		ImageNG operator+(const ImageNG& image);
		ImageNG operator-(const ImageNG& image);
		bool operator<(const ImageNG& image);
		bool operator>(const ImageNG& image);
		bool operator==(const ImageNG& image);
		friend ImageNG operator+(int val,const ImageNG& image);
		friend ImageNG operator-(int val,const ImageNG& image);
		friend ImageNG operator+(ImageNG& image,const PixelNG & pixel);
		friend ImageNG operator+(const PixelNG& pixel,const ImageNG& image);
		ImageNG operator++(void);
		ImageNG operator++(int);
		ImageNG operator--(void);
		ImageNG operator--(int);
		friend ostream& operator<<(ostream& s,const ImageNG& image);
		friend istream& operator>>(istream& s,ImageNG& image);

		//Setter
		void setId(int newId);
		void setNom(const char* newNom);
		void setDimension(const Dimension & newDim);
		void setPixel(int x,int y,int val) throw (XYException);
		void setBackground(int val);
		static void setComparaison(int val);

		//Getter
		int getId(void) const;
		const char* getNom(void) const;
		const Dimension& getDimension(void) const;
		int getPixel(int x,int y) const throw (XYException);
		int getLuminance(void) const;
		int getMinimum(void) const;
		int getMaximum(void) const;
		float getContraste(void) const;
		static int getComparaison(void);

		//Autres
		void Affiche(void) const;
		void Dessine(void) const;
		void importFromBMP(const char* fichier);
		void exportToBMP(const char* fichier);
		void allocMatrice(void);
		void deleteMatrice(void);
		void Dessine(int x,int y,WindowSDLimage* image);
		void Save(ofstream& fichier) const;
		void Load(ifstream& fichier);
};

#endif //IMAGENG_H
