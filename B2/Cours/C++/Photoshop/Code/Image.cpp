#include "Image.h"
#include "WindowSDL.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

Image::Image(void)
{
	Debug("[Image][Constructeur]void");
	nom = NULL;
	this->setId(0);
	this->setDimension(Dimension::VGA);
}

Image::Image(const char* newNom)
{
	Debug("[Image][Constructeur]newNom");
	nom = NULL;
	this->setId(0);
	this->setNom(newNom);
	this->setDimension(Dimension::VGA);
}

Image::Image(int newId,const char* newNom)
{
	Debug("[Image][Constructeur],newId,newNom");
	nom = NULL;
	this->setId(newId);
	this->setNom(newNom);
}

Image::Image(int newId,const char*newNom,const Dimension& newDim)
{
	Debug("[Image][Constructeur]newId,newNom,newDim");
	nom = NULL;
	this->setId(newId);
	this->setNom(newNom);
	this->setDimension(newDim);
}

Image::Image(const Image& copie)
{
	Debug("[Image][Constructeur]copie");
	nom = NULL;
	this->setNom(copie.getNom());
	this->setId(copie.getId());
	this->setDimension(copie.getDimension());
}

Image::~Image(void)
{
	Debug("[Image][Destructeur]void");
	delete [] nom;
}

void Image::setId(int newId)
{
	Debug("[Image][setId]newId");
	id = newId;
}

void Image::setNom(const char* newNom)
{
	Debug("[Image][setNom]newNom");
	if(nom)
	{
		delete nom;
	}
	if(newNom)
	{
		nom = new char[strlen(newNom)+1];
		strcpy(nom, newNom);
	}
	else
	{
		nom = NULL;
	}
}

void Image::setDimension(const Dimension& newDim)
{
	Debug("[Image][setDimension]newDim");

	if(newDim.getHauteur() > 0 && newDim.getLargeur() > 0)
	{
		dimension.setLargeur(newDim.getLargeur());
		dimension.setHauteur(newDim.getHauteur());
	}
}

int Image::getId(void) const
{
	Debug("[Image][getId]void");
	return id;
}

const char* Image::getNom(void) const
{
	Debug("[Image][getNom]void");
	if(nom == NULL)
	{
		return "";
	}
	else
	{
		return nom;
	}
}

const Dimension& Image::getDimension(void) const
{
	Debug("[Image][getDimension]void");
	return dimension;
}

void Image::Save(ofstream& fichier) const
{
	Debug("[Image][Save]fichier");
	if(!fichier.is_open())
	{
		cout << "[Image][Save]Erreur le fichier n'est pas ouvert!" << endl;
		return;
	}
	
	//Id
	int intTemp;
	if(fichier.eof())
	{
		cout << "[Image][Save]Fin de fichier(Id)" << endl;
		return;
	}
	else
	{
		intTemp = this->getId();
		fichier.write((char*)&intTemp,sizeof(int));
	}
	//Taille du nom
	if(fichier.eof())
	{
		cout << "[Image][Save]Fin de fichier(Taille Nom)" << endl;
		return;
	}
	else
	{
		intTemp = strlen(this->getNom());
		fichier.write((char*)&intTemp,sizeof(int));
	}
	//Nom
	if(fichier.eof())
	{
		cout << "[Image][Save]Fin de fichier(Nom)" << endl;
		return;	
	}
	else
	{
		char* nomTemp = new char[intTemp];
		strcpy(nomTemp,this->getNom());
		nomTemp[intTemp] = '\0';
		fichier.write(nomTemp,intTemp - 1);
		delete [] nomTemp;	
	}
	this->getDimension().Save(fichier);
}

void Image::Load(ifstream& fichier)
{
	Debug("[Image][Load]fichier");
	if(!fichier.is_open())
	{
		cout << "[Image][Load]Erreur le fichier n'est pas ouvert!" << endl;
		return;
	}
	
	int intTemp;
	//Id
	if(fichier.eof())
	{
		cout << "[Image][Load]Fin du fichier(Id)" << endl;
		return;
	}
	else
	{
		fichier.read((char*)&intTemp,sizeof(int));
		this->setId(intTemp);	
	}

	//Taille du nom
	if(fichier.eof())
	{
		cout << "[Image][Load]Fin du fichier(Taille Nom)" << endl;
		return;
	}
	else
	{
		fichier.read((char*)&intTemp,sizeof(int));
	}
	//Alloc nom et lecture du nom
	char *nomTemp = new char[intTemp];
	if(fichier.eof())
	{
		cout << "[Image][Load]Fin du fichier(Nom)" << endl;
		return;
	}
	else
	{
		fichier.read((char*)nomTemp,intTemp - 1);
		nomTemp[intTemp] = '\0';
		this->setNom(nomTemp);
	}
	delete [] nomTemp;
	//Load Dimension
	Dimension dimTemp;
	dimTemp.Load(fichier);
	this->setDimension(dimTemp);
}