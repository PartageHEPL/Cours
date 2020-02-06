#include "Couleur.h"
#include "Utils.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

Couleur::Couleur(void)
{
	Debug("[Couleur][Constructeur]void");
	this->setRouge(0);
	this->setVert(0);
	this->setBleu(0);
}

Couleur::Couleur(int newRouge, int newVert, int newBleu)
{		
	Debug("[Couleur][Constructeur]newRouge,newVert,newBleu");
	try
	{
		this->setRouge(newRouge);
	}
	catch(RGBException& exception)
	{
		this->setRouge(0);
		cout << exception.getMessage() << endl;
		cout << "Valeur de la composante: " << exception.getValeur() << endl;
	}
	try
	{
		this->setVert(newVert);
	}
	catch(RGBException& exception)
	{
		this->setVert(0);
		cout << exception.getMessage() << endl;
		cout << "Valeur de la composante: " << exception.getValeur() << endl;
	}
	try
	{
		this->setBleu(newBleu);
	}
	catch(RGBException& exception)
	{
		this->setBleu(0);
		cout << exception.getMessage() << endl;
		cout << "Valeur de la composante: " << exception.getValeur() << endl;
	}
}

Couleur::Couleur(const Couleur& copie)
{
	Debug("[Couleur][Constructeur]copie");
	this->setRouge(copie.getRouge());
	this->setVert(copie.getVert());
	this->setBleu(copie.getBleu());
}

Couleur::~Couleur(void)
{
	Debug("[Couleur][Destructeur]void");
}

const Couleur Couleur::ROUGE(255,0,0);
const Couleur Couleur::VERT(0,255,0);
const Couleur Couleur::BLEU(0,0,255);
const Couleur Couleur::BLANC(255,255,255);
const Couleur Couleur::NOIR(0,0,0);

Couleur& Couleur::operator=(const Couleur& couleur)
{
	Debug("[Couleur][operator=]couleur");
	this->setRouge(couleur.getRouge());
	this->setVert(couleur.getVert());
	this->setBleu(couleur.getBleu());
	return *this;
}

ostream& operator<<(ostream& s,const Couleur& couleur)
{
	Debug("[operator<<]s,couleur");
	s << "Rouge: " << couleur.getRouge() << " Vert: " << couleur.getVert() << " Bleu: " << couleur.getBleu();
	return s;
}

istream& operator>>(istream& s,Couleur& couleur)
{
	Debug("[operator>>]s,couleur");
	int r,g,b;
	cout << "Entre les nouvelles couleurs(0 a 255):" << endl;
	cout << "Rouge: "; s >> r; s.ignore();
	try
	{
		couleur.setRouge(r);
	}
	catch(RGBException& exception)
	{
		couleur.setRouge(0);
		cout << exception.getMessage() << endl;
		cout << "Valeur de la composante: " << exception.getValeur() << endl;
	}

	cout << "Vert: "; s >> g; s.ignore();
	try
	{
		couleur.setVert(g);
	}
	catch(RGBException& exception)
	{
		couleur.setVert(0);
		cout << exception.getMessage() << endl;
		cout << "Valeur de la composante: " << exception.getValeur() << endl;
	}

	cout << "Bleu: "; s >> b; s.ignore();
	try
	{
		couleur.setBleu(b);
	}
	catch(RGBException& exception)
	{
		couleur.setBleu(0);
		cout << exception.getMessage() << endl;
		cout << "Valeur de la composante: " << exception.getValeur() << endl;
	}
	return s;
}

void Couleur::setRouge(int newRouge) throw (RGBException)
{
	Debug("[Couleur][setRouge]newRouge");
	if(newRouge >= 0 && newRouge <= 255)
	{
		rouge = newRouge;
	}
	else
	{
		throw RGBException(newRouge,"[RGBException][Erreur]Nouvelle valeur de Rouge incorrecte!");
	}
}

void Couleur::setVert(int newVert) throw (RGBException)
{
	Debug("[Couleur][setVert]newVert");
	if(newVert >= 0 && newVert <= 255)
	{
		vert = newVert;
	}
	else
	{
		throw RGBException(newVert,"[RGBException][Erreur]Nouvelle valeur de Vert incorrecte!");
	}
}

void Couleur::setBleu(int newBleu) throw (RGBException)
{
	Debug("[Couleur][setBleu]newBleu");
	if(newBleu >= 0 && newBleu <= 255)
	{
		bleu = newBleu;
	}
	else
	{
		throw RGBException(newBleu,"[RGBException][Erreur]Nouvelle valeur de Bleu incorrecte!");
	}
}

int Couleur::getRouge(void) const
{
	Debug("[Couleur][getRouge]void");
	return rouge;
}

int Couleur::getVert(void) const
{
	Debug("[Couleur][getVert]void");
	return vert;
}

int Couleur::getBleu(void) const
{
	Debug("[Couleur][getBleu]void");
	return bleu;
}

void Couleur::Affiche(void) const
{
	Debug("[Couleur][Affiche]void");
	cout << "Rouge: " << getRouge() << " Vert: " << getVert() << " Bleu: " << getBleu() << endl;
}

void Couleur::Save(ofstream& fichier) const
{
	Debug("[Couleur][Save]ficher");
	if(fichier == NULL)
	{
		cout << "[Couleur][Save]Erreur fichier == NULL!" << endl;
	}
	else
	{
		int temp;
		temp = this->getRouge();
		fichier.write((char*)&temp,sizeof(int));
		temp = this->getVert();
		fichier.write((char*)&temp,sizeof(int));
		temp = this->getBleu();
		fichier.write((char*)&temp,sizeof(int));
	}
}

void Couleur::Load(ifstream& fichier)
{
	Debug("[Couleur][Load]fichier");
	if(!fichier.is_open())
	{
		cout << "[Couleur][Load]Erreur fichier == NULL!" << endl;
	}
	else
	{
		int temp;
		fichier.read((char*)&temp,sizeof(int));
		this->setRouge(temp);
		fichier.read((char*)&temp,sizeof(int));
		this->setVert(temp);
		fichier.read((char*)&temp,sizeof(int));
		this->setBleu(temp);
	}
}