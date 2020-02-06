#ifndef IMAGE_H
#define IMAGE_H

#include "Dimension.h"
#include "WindowSDL.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class Image
{
	protected:
		int id;
		char *nom;
		Dimension dimension;
	public:
		//Constructeurs
		Image(void);
		Image(const char* newNom);
		Image(int newId,const char* newNom);
		Image(int newId,const char* newNom,const Dimension& newDim);
		Image(const Image& copie);
		virtual ~Image(void);

		//Variables Statiques

		//Operateurs

		//Setter
		void setId(int newId);
		void setNom(const char* newNom);
		void setDimension(const Dimension& newDim);

		//Getter
		int getId(void) const;
		const char* getNom(void) const;
		const Dimension& getDimension(void) const;

		//Autres
		virtual void Affiche(void) const = 0;
		virtual void Dessine(void) const = 0;
		virtual void exportToBMP(const char* fichier) = 0;
		virtual void Dessine(int x,int y,WindowSDLimage* image) = 0;
		void Save(ofstream& fichier) const;
		void Load(ifstream& fichier);
};

#endif //IMAGE_H