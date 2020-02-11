#include "PixelB.h"
#include "Utils.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

PixelB::PixelB(void) : Pixel()
{
	Debug("[PixelB][Constructeur]void");
	this->setValeur(false);
}
	
PixelB::PixelB(const PixelB & copie) : Pixel(copie)
{
	Debug("[PixelB][Constructeur]copie");
	this->setValeur(copie.getValeur());
}

PixelB::PixelB(int newX, int newY, bool newVal) : Pixel(newX, newY)
{
	Debug("[PixelB][Constructeur]newX,newY,newVal");
	this->setValeur(newVal);	
}
	
PixelB::~PixelB(void)
{
	Debug("[PixelB][Destructeur]void");
}

ostream& operator<<(ostream& s, const PixelB& pixel)
{
	Debug("[PixelB][operator<<]s,pixel");
	s << "X: " << pixel.getX() << " Y: " << pixel.getY() << " Valeur: " << pixel.getValeur();
	return s;
}

	
void PixelB::setValeur(bool newVal)
{
	Debug("[PixelB][setValeur]newVal");
	valeur = newVal;
}

const bool PixelB::getValeur(void) const
{
	Debug("[PixelB][getValeur]void");
	return valeur;
}

