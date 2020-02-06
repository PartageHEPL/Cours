#ifndef DIMENSION_H
#define DIMENSION_H

#include "XYException.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class Dimension
{
	private:
		int largeur,hauteur;
	public:
		//Constructeurs
		Dimension(void);
		Dimension(int newLargeur,int newHauteur);
		Dimension(const Dimension& newDim);
		~Dimension(void);

		//Variables Statiques
		static const Dimension VGA;
		static const Dimension HD;
		static const Dimension FULL_HD;
		
		//Operator
		bool operator==(const Dimension& newDim);
		bool operator!=(const Dimension& newDim);
		friend ostream& operator<<(ostream& s,const Dimension& newDim);
		friend istream& operator>>(istream& s,Dimension& newDim);

		//Setter
		void setLargeur(int newLargeur) throw (XYException);
		void setHauteur(int newHauteur) throw (XYException);

		//Getter
		int getLargeur(void) const;
		int getHauteur(void) const;

		//Autres
		void Affiche(void) const;
		void Save(ofstream& fichier) const;
		void Load(ifstream& fichier);
};

#endif //DIMENSION_H
