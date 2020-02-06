#include "Pixel.h"
#include "Utils.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Pixel::Pixel(void)
{
	Debug("[Pixel][Constructeur]void");
	this->setX(0);
	this->setY(0);
}

Pixel::Pixel(int newX,int newY)
{
	Debug("[Pixel][Constructeur]newX,newY");
	try
	{
		this->setX(newX);
	}
	catch(XYException& exception)
	{
		this->setX(0);
		cout << exception.getMessage() << endl;
		cout << "Axe: " << exception.getAxe() << endl;
	}
	try
	{
		this->setY(newY);
	}
	catch(XYException& exception)
	{
		this->setY(0);
		cout << exception.getMessage() << endl;
		cout << "Axe: " << exception.getAxe() << endl;
	}
}

Pixel::Pixel(const Pixel& copie)
{
	Debug("[Pixel][Constructeur]copie");
	this->setX(copie.getX());
	this->setY(copie.getY());
}

Pixel::~Pixel(void)
{
	Debug("[Pixel][Destructeur]void");
}

void Pixel::setX(int newX) throw (XYException)
{
	Debug("[Pixel][setX]newX");
	if(newX >= 0)
	{
		x = newX;
	}
	else
	{
		throw  XYException('x',"[XYException][Erreur] X < 0");
	}
}

void Pixel::setY(int newY) throw (XYException)
{
	Debug("[Pixel][setY]newY");
	if(newY >= 0)
	{
		y = newY;	
	}
	else
	{
		throw XYException('y',"[XYException][Erreur] Y < 0");
	}
}

int Pixel::getX(void) const
{
	Debug("[Pixel][getX]void");
	return x;
}

int Pixel::getY(void) const
{
	Debug("[Pixel][getY]void");
	return y;
}