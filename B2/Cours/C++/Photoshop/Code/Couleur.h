#ifndef COULEUR_H
#define COULEUR_H

#include "RGBException.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class Couleur
{
	protected:
		int rouge;
		int vert;
		int bleu;
	public:
		//Constructeurs
		Couleur(void);
		Couleur(int newRouge, int newVert, int newBleu);
		Couleur(const Couleur& copie);
		~Couleur(void);
	
		//Variables Statiques
		static const Couleur ROUGE;
		static const Couleur VERT;
		static const Couleur BLEU;
		static const Couleur BLANC;
		static const Couleur NOIR;

		//Operateurs
		Couleur& operator=(const Couleur& couleur);
		friend ostream& operator<<(ostream& s,const Couleur& newCouleur);
		friend istream& operator>>(istream& s,Couleur& couleur);

		//Setter
		void setRouge(int newRouge) throw (RGBException);
		void setVert(int newVert) throw (RGBException);
		void setBleu(int newBleu) throw (RGBException);

		//Getter
		int getRouge(void) const;
		int getVert(void) const;
		int getBleu(void) const;

		//Autres
		void Affiche(void) const;
		void Save(ofstream& fichier) const;
		void Load(ifstream& fichier);
};

#endif //COULEUR_H