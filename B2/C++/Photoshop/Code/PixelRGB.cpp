#include "PixelRGB.h"
#include "Utils.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

PixelRGB::PixelRGB(void) : Pixel()
{
	Debug("[PixelRGB][Constructeur]void");
	this->setValeur(Couleur::BLANC);
}

PixelRGB::PixelRGB(int x, int y, const Couleur newCouleur) : Pixel(x,y)
{
	Debug("[PixelRGB][Constructeur]x,y,newCouleur");
	this->setValeur(newCouleur);
}

PixelRGB::PixelRGB(const PixelRGB& copie) : Pixel(copie)
{
	Debug("[PixelRGB][Constructeur]copie");
	this->setValeur(copie.getValeur());
}

PixelRGB::~PixelRGB(void)
{
	Debug("[PixelRGB][Destructeur]void");
}


ostream& operator<<(ostream& s, const PixelRGB& pixel)
{
	Debug("[PixelRGB][operator<<]s,pixel");
	s << "X: " << pixel.getX() << " Y: " << pixel.getY() << " R: " << pixel.getValeur().getRouge() << " G: " << pixel.getValeur().getVert() << " B: " << pixel.getValeur().getBleu();
	return s;
}


void PixelRGB::setValeur(Couleur newCouleur)
{
	Debug("[PixelRGB][setValeur]newCouleur");
	valeur = newCouleur;
}


const Couleur& PixelRGB::getValeur(void) const
{
	Debug("[PixelRGB][getValeur]void");
	return valeur;
}

