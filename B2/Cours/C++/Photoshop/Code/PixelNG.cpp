#include "PixelNG.h"
#include "Utils.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

PixelNG::PixelNG(void) : Pixel()
{
	Debug("[PixelNG][Constructeur]void");
	this->setValeur(0);
}

PixelNG::PixelNG(int newX,int newY,int newValeur) : Pixel(newX,newY)
{
	Debug("[PixelNG][Constructeur]newX,newY,newValeur");
	try
	{
		this->setValeur(newValeur);
	}
	catch(RGBException& exception)
	{
		this->setValeur(0);
		cout << exception.getMessage() << endl;
		cout << "Valeur: " << exception.getValeur() << endl;
	}
}

PixelNG::PixelNG(const PixelNG& copie) : Pixel(copie.getX(),copie.getY())
{
	Debug("[PixelNG][Constructeur]copie");
	this->setValeur(copie.getValeur());
}

PixelNG::~PixelNG(void)
{
	Debug("[PixelNG][Destructeur]void");
}

PixelNG PixelNG::operator=(const PixelNG& pixel)
{
	Debug("[PixelNG][operator=]pixel");
	this->setX(pixel.getX());
	this->setY(pixel.getY());
	this->setValeur(pixel.getValeur());
	return *this;
}

ostream& operator<<(ostream& s,const PixelNG& pixel)
{
	Debug("[PixelNG][operator<<]s,pixel");
	cout << "X: " << pixel.getX() << " Y: " << pixel.getY() << " Valeur: " << pixel.getValeur() << endl;
	return s;
}


void PixelNG::setValeur(int newValeur) throw (RGBException)
{
	Debug("[PixelNG][setValeur]newValeur");
	if(newValeur >= 0 && newValeur <= 255)
	{
		valeur = newValeur;	
	}
	else
	{
		valeur = 0;
		throw RGBException(newValeur,"[XYException][Erreur] Valeur < 0 || Valeur > 255");
	}
}

int PixelNG::getValeur(void) const
{
	Debug("[PixelNG][getValeur]void");
	return valeur;
}