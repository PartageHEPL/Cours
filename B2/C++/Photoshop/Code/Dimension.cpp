#include "Dimension.h"
#include "Utils.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

Dimension::Dimension(void)
{
	Debug("[Dimension][Constructeur]void");
	this->setLargeur(400);
	this->setHauteur(300);
}

Dimension::Dimension(int newLargeur,int newHauteur)
{
	Debug("[Dimension][Constructeur]newLargeur,newHauteur");
	
	try
	{
		this->setLargeur(newLargeur);
	}
	catch(XYException& exception)
	{
		this->setLargeur(VGA.getLargeur());
		cout << exception.getMessage() << endl;
		cout << "Axe: " << exception.getAxe() << endl;
	}
	try
	{
		this->setHauteur(newHauteur);	
	}
	catch(XYException& exception)
	{
		this->setHauteur(VGA.getLargeur());
		cout << exception.getMessage() << endl;
		cout << "Axe: " << exception.getAxe() << endl;
	}
}

Dimension::Dimension(const Dimension& newDim)
{
	Debug("[Dimension][Constructeur]newDim");
	this->setLargeur(newDim.getLargeur());
	this->setHauteur(newDim.getHauteur());
}

Dimension::~Dimension(void)
{
	Debug("[Dimension][Destructeur]void");
}


const Dimension Dimension::VGA(640,480);

const Dimension Dimension::HD(1280,720);

const Dimension Dimension::FULL_HD(1980,1080);


bool Dimension::operator==(const Dimension& newDim)
{
	Debug("[Dimension][operator==]newDim");
	if(getLargeur() == newDim.getLargeur() && getHauteur() == newDim.getHauteur())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Dimension::operator!=(const Dimension& newDim)
{
	Debug("[Dimension][operator!=]newDim");
	if(getLargeur() != newDim.getLargeur() || getHauteur() != newDim.getHauteur())
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& s,const Dimension& newDim)
{
	Debug("[Dimension][operator<<]s,newDim");
	cout << "Dimension: " << newDim.getLargeur() << " x " << newDim.getHauteur();
	return s;
}

istream& operator>>(istream& s,Dimension& newDim)
{
	Debug("[Dimension][operator>>]s,newDim");
	int largeur;
	int hauteur;
	cout << "Remplissage de la dimension: " << endl;
	cout << "Largeur: "; cin >> largeur; cin.ignore();
	cout << "Hauteur: "; cin >> hauteur; cin.ignore();
	try
	{
		newDim.setLargeur(largeur);	
	}
	catch(XYException& exception)
	{
		newDim.setLargeur(Dimension::VGA.getLargeur());
		cout << exception.getMessage() << endl;
		cout << "Axe: " << exception.getAxe() << endl;
	}
	try
	{
		newDim.setHauteur(hauteur);	
	}
	catch(XYException& exception)
	{
		newDim.setHauteur(Dimension::VGA.getHauteur());
		cout << exception.getMessage() << endl;
		cout << "Axe: " << exception.getAxe() << endl;	
	}
	return s;
}

void Dimension::setLargeur(int newLargeur) throw (XYException) 
{
	Debug("[Dimension][setLargeur]newLargeur");
	if(newLargeur > 0)
	{
		largeur = newLargeur;
	}
	else
	{
		throw XYException('x',"[XYException][Erreur] newLargeur < 0");
	}
}

void Dimension::setHauteur(int newHauteur)  throw (XYException)
{
	Debug("[Dimension][setHauteur]newHauteur");
	if(newHauteur > 0)
	{
		hauteur = newHauteur;
	}
	else
	{
		throw XYException('y',"[XYException][Erreur] newHauteur < 0");
	}
}


int Dimension::getLargeur(void) const
{
	Debug("[Dimension][getLargeur]void");
	return largeur;
}

int Dimension::getHauteur(void) const
{
	Debug("[Dimension][getHauteur]void");
	return hauteur;
}


void Dimension::Affiche() const
{
	Debug("[Dimension][Affiche]void");
	cout << "Dimensions: " << this->getLargeur() << "x" << this->getHauteur() << endl;
}

void Dimension::Save(ofstream& fichier) const
{
	Debug("[Dimension][Save]fichier");
	if(fichier == NULL)
	{
		cout << "[Dimension][Save]Erreur fichier == NULL" << endl;
		return;
	}
	
	//Largeur
	int intTemp;
	if(fichier.eof())
	{
		cout << "[Dimension][Save]Fin du fichier(Largeur)" << endl;
		return;
	}
	else
	{
		intTemp = this->getLargeur();
		fichier.write((char*)&intTemp,sizeof(int));
	}
	//Hauteur
	if(fichier.eof())
	{
		cout << "[Dimension][Save]Fin du fichier(Hauteur)" << endl;
		return;
	}
	else
	{
		intTemp = this->getHauteur();
		fichier.write((char*)&intTemp,sizeof(int));
	}
}

void Dimension::Load(ifstream& fichier)
{
	Debug("[Dimension][Load]fichier");
	if(fichier == NULL)
	{
		cout << "[Dimension][Load]Erreur fichier == NULL!" << endl;
		return;
	}

	//Largeur
	int intTemp;
	if(fichier.eof())
	{
		cout << "[Dimension][Load]Fin du fichier(Largeur)" << endl;
		return;
	}
	else
	{
		fichier.read((char*)&intTemp,sizeof(int));
		this->setLargeur(intTemp);	
	}
	//Hauteur
	if(fichier.eof())
	{
		cout << "[Dimension][Load]Fin du fichier(Hauteur)" << endl;
		return;	
	}
	else
	{
		fichier.read((char*)&intTemp,sizeof(int));
		this->setHauteur(intTemp);
	}
}