#include "RGBException.h"
#include "Utils.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

RGBException::RGBException(void) : BaseException()
{
	Debug("[RGBException][Constructeur]void");
	this->setValeur(0);
}

RGBException::RGBException(int newValeur) : BaseException()
{
	Debug("[RGBException][Constructeur]newValeur");
	this->setValeur(newValeur);
}

RGBException::RGBException(int newValeur,const char* newMessage) : BaseException(newMessage)
{
	Debug("[RGBException][Constructeur]newValeur,newMessage");
	this->setValeur(newValeur);
}

RGBException::RGBException(const RGBException& newException) : BaseException(newException)
{
	Debug("[RGBException][Constructeur]newException");
	this->setValeur(newException.getValeur());
}

RGBException::~RGBException(void)
{
	Debug("[RGBException][Destructeur]void");
}

void RGBException::setValeur(int newValeur)
{
	Debug("[RGBException][setValeur]newValeur");
	valeur = newValeur;
}

int RGBException::getValeur(void) const
{
	Debug("[RGBException][getValeur]void");
	return valeur;
}