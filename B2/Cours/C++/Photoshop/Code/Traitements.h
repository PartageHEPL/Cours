#ifndef TRAITEMENTS_H
#define TRAITEMENTS_H

#include "ImageB.h"
#include "ImageNG.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Traitements
{
	public:
		static ImageB Seuillage(const ImageNG& image,int seuil);
		static ImageNG FiltreMoyenneur(const ImageNG& imageIn, int taille, Pixel p1=Pixel(), Pixel p2=Pixel());
		static ImageNG FiltreMedian(const ImageNG& imageIn, int taille);
		static ImageNG Erosion(const ImageNG& imageIn, int taille);
		static ImageNG Dilatation(const ImageNG& imageIn, int taille);
		static ImageNG Negatif(const ImageNG& imageIn);

};

#endif //TRAITEMENTS_H