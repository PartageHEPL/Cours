#include "ImageB.h"
#include "Utils.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

ImageB::ImageB(void) : Image()
{
	Debug("[ImageB][Constructeur]void");
	matrice = NULL;
	this->setDimension(Dimension::VGA);
	this->setBackground(false);
}

ImageB::ImageB(int newId, const char* newNom) : Image(newId, newNom)
{
	Debug("[ImageB][Constructeur]newId,newNom");
	matrice = NULL;
	this->setDimension(Dimension::VGA);
	this->setBackground(false);
}

ImageB::ImageB(const ImageB& copie) : Image(copie)
{
	Debug("[ImageB][Constructeur]copie");
	matrice = NULL;
	this->setDimension(copie.getDimension());
	//Copie de l'image depuis la copie
	for(int i = 0; i < getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < getDimension().getHauteur(); j++)
		{
			try
			{
				this->setPixel(i,j,copie.getPixel(i,j));
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
}

ImageB::ImageB(int newId, const char* newNom, const Dimension& newDim) : Image(newId, newNom, newDim)
{
	Debug("[ImageB][Constructeur]newId,newNom,newDim");
	matrice = NULL;
	this->setDimension(newDim);
	this->setBackground(false);
}

ImageB::~ImageB(void)
{
	Debug("[ImageB][Destructeur]void");
	for (int x = 0; x < dimension.getLargeur(); x++)
	{
		delete [] matrice [x];
	}
	delete [] matrice;
}


Couleur ImageB::couleurTrue(255, 255, 255);
Couleur ImageB::couleurFalse(0, 0, 0);


ostream& operator<<(ostream& s, const ImageB& image)
{
	Debug("[ImageB][operator<<]s,image");
	s << "Id: " << image.getId() << " Nom: " << image.getNom() << image.getDimension();
	return s;
}

ImageB operator+(const PixelB & pixel, ImageB& image)
{
	Debug("[ImageB][operator+]pixel,image");
	return image + pixel;
}

ImageB& ImageB::operator=(const ImageB& image)
{
	Debug("[ImageB][operator=]image");
	this->setId(image.id);
	this->setNom(image.nom);
	//Désallouer
	for (int x = 0; x < (*this).getDimension().getLargeur(); x++)
	{
		delete [] matrice [x];
	}
	delete [] matrice;
	matrice = NULL;
	this->setDimension(image.getDimension());
	//Copie de l'image depuis la copie
	for(int i = 0; i < getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < getDimension().getHauteur(); j++)
		{
			try
			{
				this->setPixel(i,j,image.getPixel(i,j));
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
	return *this;
}

ImageB& ImageB::operator=(const ImageB* image)
{
	Debug("[ImageB][operator=]image");
	this->setId(image->getId());
	this->setNom(image->getNom());
	//Désallouer
	for (int x = 0; x < (*this).getDimension().getLargeur(); x++)
	{
		delete [] matrice [x];
	}
	delete [] matrice;
	matrice = NULL;
	this->setDimension(image->getDimension());
	//Copie de l'image depuis la copie
	for(int i = 0; i < getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < getDimension().getHauteur(); j++)
		{
			try
			{
				this->setPixel(i,j,image->getPixel(i,j));
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
	return *this;
}

ImageB ImageB::operator+(const PixelB & pixel)
{
	Debug("[ImageB][operator+]pixel");
	ImageB temp(*this);
	try
	{
		temp.matrice[pixel.getX()][pixel.getY()] = pixel.getValeur();
	}
	catch(XYException& exception)
	{
		cout << exception.getMessage() << endl;
		cout << "Axe: " << exception.getAxe() << endl;
	}
	return temp;
}


void ImageB::setDimension(const Dimension & newDim)
{
	Debug("[ImageB][setDimension]newDim");
	if(newDim.getLargeur() > 0 && newDim.getHauteur() > 0)
	{
		if(matrice == NULL)
		{
			dimension.setLargeur(newDim.getLargeur());
			dimension.setHauteur(newDim.getHauteur());
			this->allocMatrice();
			this->setBackground(0);
		}
		else
		{
			bool **temp;
			temp = new bool*[newDim.getLargeur()];
			for (int x = 0; x < newDim.getLargeur(); x++)
			{
				temp[x] = new bool[newDim.getHauteur()];
			}
			//Copier l'image dans une image temp
			if(newDim.getLargeur() < getDimension().getLargeur() && newDim.getHauteur() < getDimension().getHauteur())
			{
				for(int i = 0; i < newDim.getLargeur(); i++)
				{
					for(int j = 0; j < newDim.getHauteur(); j++)
					{
						temp[i][j] = matrice[i][j];
					}
				}
			}
			else
			{
				//Si la nouvelle image est plus grande
				//On set background = 0
				for(int i = 0; i < newDim.getLargeur(); i++)
				{
					for(int j = 0;j < newDim.getHauteur(); j++)
					{
						temp[i][j] = 0;
					}
				}
				
				//On recopie l'image
				for(int i = 0; i < newDim.getLargeur(); i++)
				{
					for(int j = 0; j < newDim.getHauteur(); j++)
					{
						temp[i][j] = matrice[i][j];
					}
				}
			}
			//Desalouer l'ancienne matrice
			this->deleteMatrice();
			//Matrice pointe vers la nouvelle image
			matrice = temp;
			dimension.setLargeur(newDim.getLargeur());
			dimension.setHauteur(newDim.getHauteur());	
		}
	}
}

void ImageB::setPixel(int x, int y, bool newVal) throw (XYException)
{
	Debug("[ImageB][setPixel]x,y,newVal");
	if((x < 0 || x > getDimension().getLargeur()) && (y < 0 || y > getDimension().getHauteur()))
	{
		throw XYException('d',"[XYException][Erreur] X et Y sont invalide!");
	}

	if(x < 0 || x > getDimension().getLargeur())
	{
		throw XYException('x',"[XYException][Erreur] X est invalide!");
	}

	if(y < 0 || y > getDimension().getHauteur())
	{
		throw XYException('x',"[XYException][Erreur] Y est invalide!");
	}
	matrice[x][y] = newVal;
}

void ImageB::setBackground(bool val)
{
	Debug("[ImageB][setBackground]val");
	for (int x = 0; x < getDimension().getLargeur(); x++)
	{
		for (int y = 0; y < getDimension().getHauteur(); y++)
		{
			matrice[x][y] = val;
		}
	}
}


const bool ImageB::getPixel (int x, int y) const throw (XYException)
{
	Debug("[ImageB][getPixel]x,y");
	if((x < 0 || x > getDimension().getLargeur()) && (y < 0 || y > getDimension().getHauteur()))
	{
		throw XYException('d',"[XYException][Erreur] X et Y sont invalide!");
	}

	if(x < 0 || x > getDimension().getLargeur())
	{
		throw XYException('x',"[XYException][Erreur] X est invalide!");
	}

	if(y < 0 || y > getDimension().getHauteur())
	{
		throw XYException('x',"[XYException][Erreur] Y est invalide!");
	}
	return matrice[x][y];
}


void ImageB::Affiche(void) const
{
	Debug("[ImageB][Affiche]void");
	cout << "Id = " << this->getId() << endl;
	if(this->getNom())
	{
		cout << "Nom = " << getNom() << endl;
	}
	else
	{
		cout << "Nom = " << endl;
	}
	this->getDimension().Affiche();
}

void ImageB::Dessine(void) const
{
	Debug("[ImageB][Dessine]void");
	WindowSDL fenetre;

	try
	{
		fenetre.open(getDimension().getLargeur(),getDimension().getHauteur());
	}
	catch(WindowSDLexception &c)
    {
        cout << c.getMessage() << endl;
    }

	WindowSDLimage temp(getDimension().getLargeur(), getDimension().getHauteur());

	for (int x = 0; x < getDimension().getLargeur(); x++)
	{
		for (int y = 0; y < getDimension().getHauteur(); y++)
		{
			if (matrice[x][y]==true)
			{
				try
				{
					temp.setPixel(x, y, ImageB::couleurTrue.getRouge(), ImageB::couleurTrue.getVert(), ImageB::couleurTrue.getBleu());
				}
				catch(WindowSDLexception &c)
	            {
	                cout << c.getMessage() << endl;
	            }
			}
			else
			{	
				try
				{
					temp.setPixel(x, y, ImageB::couleurFalse.getRouge(), ImageB::couleurFalse.getVert(), ImageB::couleurFalse.getBleu());
				}
				catch(WindowSDLexception &c)
	            {
	                cout << c.getMessage() << endl;
	            }
			}
		}
	}

	try
	{
		fenetre.drawImage(temp, 0, 0);
	}
	catch(WindowSDLexception &c)
    {
        cout << c.getMessage() << endl;
    }

	try
	{
		fenetre.waitClick();
	}
	catch(WindowSDLexception &c)
    {
        cout << c.getMessage() << endl;
    }

	try
	{
		fenetre.close();
	}
	catch(WindowSDLexception &c)
    {
        cout << c.getMessage() << endl;
    }
}

void ImageB::exportToBMP(const char * fichier)
{
	Debug("[ImageB][exportToBMP]fichier");
	WindowSDLimage temp(getDimension().getLargeur(),getDimension().getHauteur());	
	
	for (int x = 0; x < getDimension().getLargeur(); x++)
	{
		for (int y = 0; y < getDimension().getHauteur(); y++)
		{
			if (matrice[x][y]==true)
			{
				try
				{
					temp.setPixel(x, y, ImageB::couleurTrue.getRouge(), ImageB::couleurTrue.getVert(), ImageB::couleurTrue.getBleu());
				}
				catch(WindowSDLexception &c)
	            {
	                cout << c.getMessage() << endl;
	            }
			}
			else
			{	
				try
				{
					temp.setPixel(x, y, ImageB::couleurFalse.getRouge(), ImageB::couleurFalse.getVert(), ImageB::couleurFalse.getBleu());
				}
				catch(WindowSDLexception &c)
	            {
	                cout << c.getMessage() << endl;
	            }
			}
		}
	}

	try
	{
		temp.exportToBMP(fichier);
	}
	catch(WindowSDLexception &c)
	{
		cout << c.getMessage() << endl;
	}
}

void ImageB::allocMatrice(void)
{
	Debug("[ImageB][allocMatrice]void");
	matrice = new bool*[getDimension().getLargeur()];
	for(int x = 0; x < dimension.getLargeur(); x++)
	{
		matrice[x] = new bool[getDimension().getHauteur()];
	}
}

void ImageB::deleteMatrice(void)
{
	Debug("[ImageB][deleteMatrice]void");
	for(int x = 0; x < dimension.getLargeur(); x++)
	{
		delete[] matrice[x];
	}
	delete[] matrice;
}

void ImageB::Dessine(int x,int y,WindowSDLimage* image)
{
	Debug("[ImageB][Dessine]x,y,image");
	for (int x1 = x; x1 < getDimension().getLargeur(); x1++)
	{
		for (int y1 = y; y1 < getDimension().getHauteur(); y1++)
		{
			if (matrice[x1][y1]==true)
			{
				try
				{
					image->setPixel(x1, y1, ImageB::couleurTrue.getRouge(), ImageB::couleurTrue.getVert(), ImageB::couleurTrue.getBleu());
				}
				catch(WindowSDLexception &c)
	            {
	                cout << c.getMessage() << endl;
	            }
			}
			else
			{	
				try
				{
					image->setPixel(x1, y1, ImageB::couleurFalse.getRouge(), ImageB::couleurFalse.getVert(), ImageB::couleurFalse.getBleu());
				}
				catch(WindowSDLexception &c)
	            {
	                cout << c.getMessage() << endl;

	            }
			}
		}
	}
}

void ImageB::Save(ofstream& fichier) const
{
	Debug("[ImageB][Save]fichier");
	if(!fichier.is_open())
	{
		cout << "[ImageB][Save]Erreur fichier == NULL!" << endl;
	}
	else
	{
		Image::Save(fichier);
		bool temp;
		for(int i = 0; i < this->getDimension().getLargeur(); i++)
		{
			for(int j = 0; j < this->getDimension().getHauteur(); j++)
			{
				try
				{
					temp = getPixel(i,j);
				}
				catch(XYException& exception)
				{
					cout << exception.getMessage() << endl;
					cout << "Axe: " << exception.getAxe() << endl;
				}
				fichier.write((char*)&temp,sizeof(bool));
			}
		}
	}
}

void ImageB::Load(ifstream& fichier)
{
	Debug("[ImageB][Load]fichier");
	if(!fichier.is_open())
	{
		cout << "[ImageB][Load]Erreur fichier == NULL!" << endl;
	}
	else
	{
		Image::Load(fichier);
		bool temp;
		for(int i = 0; i < this->getDimension().getLargeur(); i++)
		{
			for(int j = 0; j < this->getDimension().getHauteur(); j++)
			{
				fichier.read((char*)&temp,sizeof(bool));
				try
				{
					this->setPixel(i,j,temp);	
				}
				catch(XYException& exception)
				{
					cout << exception.getMessage() << endl;
					cout << "Axe: " << exception.getAxe() << endl;
				}
			}
		}
	}
}
