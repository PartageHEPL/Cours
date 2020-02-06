#ifndef MOTEUR_H
#define MOTEUR_H

#include "ListeTriee.h"
#include "Liste.h"
#include "Image.h"
#include "ImageNG.h"
#include "ImageRGB.h"
#include "ImageB.h"
#include "MoteurException.h"

class Moteur
{
	private:
		ListeTriee<ImageNG> imagesNG;
 		Liste<ImageRGB> imagesRGB;
 		Liste<ImageB> imagesB;

 		ImageNG GetImageNG(int id);
 		Image& GetImage(int id) throw (MoteurException);
 		int GetNextId(void);
	public:
		Moteur(void);
		void Affiche(void);
		void SupprimerImage(int id);
		int ImporteImageNG(const char *fichier);
		int ImporteImageRGB(const char *fichier);
		void VisualiseImage(int id);
		void VisualiseImage(int id1,int id2);
		int Insere(Image *pImage);
		void ExporterBMP(int id,const char* fichier);
		int AugmenteLuminosite(int id,int val);
		int DiminueLuminosite(int id, int val);
		int Soustraire(int id1, int id2);

		//Traitements
		int Seuillage(int id, int seuil);
		int Negatif(int id);
		int FiltreMedian(int id, int tailleFiltre);
		int FiltreMoyenneur(int id, int tailleFiltre);
		int Dilatation(int id, int tailleFiltre);
		int Erosion(int id, int tailleFiltre);
};

#endif