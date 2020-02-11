#include "ImageRGB.h"
#include "Utils.h"

ImageRGB::ImageRGB(void) : Image()
{
	Debug("[ImageRGB][Constructeur]void");
	matrice = NULL;
	this->allocMatrice();
	this->setBackground(Couleur::NOIR);
}

ImageRGB::ImageRGB(const char* filename) : Image(filename)
{
	Debug("[ImageRGB][Constructeur]filename");
	matrice = NULL;
	this->importFromBMP(filename);
}

ImageRGB::ImageRGB(int newId, const char* newNom) : Image(newId,newNom)
{
	Debug("[ImageRGB][Constructeur]newId,newNom");
	matrice = NULL;
	this->allocMatrice();
	this->setBackground(Couleur::NOIR);
}
ImageRGB::ImageRGB(int newId, const char* newNom, const Dimension& newDim) : Image(newId,newNom,newDim)
{
	Debug("[ImageRGB][Constructeur]newId,newNom,newDim");
	matrice = NULL;
	this->setDimension(newDim);
}
ImageRGB::ImageRGB(const ImageRGB& copie) : Image(copie)
{
	Debug("[ImageRGB][Constructeur]void");
	matrice = NULL;
	this->setNom(copie.getNom());
	this->setDimension(copie.getDimension());
	//Copie de l'image depuis la variable copie
	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				this->setPixel(i,j,copie.getPixel(i,j));
			}
			catch(XYException exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
}
ImageRGB::~ImageRGB(void)
{
	Debug("[ImageRGB][Destructeur]void");
	this->deleteMatrice();
}

ImageRGB operator+(const PixelRGB& pixel, ImageRGB& image)
{
	Debug("[ImageRGB][operator+]pixel,image");
	ImageRGB temp(image);
	try
	{
		temp.setPixel(pixel.getX(),pixel.getY(),pixel.getValeur());		
	}
	catch(XYException& exception)
	{
		cout << exception.getMessage() << endl;
		cout << "Axe: " << exception.getAxe() << endl;
	}
	return temp;
}

ImageRGB ImageRGB::operator+(const PixelRGB& pixel)
{
	Debug("[ImageRGB][operator+]pixel");
	ImageRGB temp(*this);
	try
	{
		temp.setPixel(pixel.getX(),pixel.getY(),pixel.getValeur());	
	}
	catch(XYException& exception)
	{
		cout << exception.getMessage() << endl;
		cout << "Axe: " << exception.getAxe() << endl;
	}
	return temp;
}


ImageRGB& ImageRGB::operator=(const ImageRGB& image)
{
	Debug("[ImageRGB][operator=]image");
	this->setId(image.getId());
	this->setNom(image.getNom());
	this->setDimension(image.getDimension());
	//Copie de l'image depuis la copie
	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
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

ImageRGB& ImageRGB::operator=(const ImageRGB* image)
{
	Debug("[ImageRGB][operator=]image");
	this->setId(image->getId());
	this->setNom(image->getNom());
	this->setDimension(image->getDimension());
	//Copie de l'image depuis la copie
	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
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

ostream& operator<<(ostream& s,const ImageRGB& image)
{
	Debug("[ImageRGB][operator<<]s,image");
	s << "Id: " << image.getId() << " Nom: " << image.getNom() << " " << image.getDimension();
	return s;
}


void ImageRGB::setBackground(const Couleur& newCouleur)
{
	Debug("[ImageRGB][setBackground]newCouleur");

	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				this->setPixel(i,j,newCouleur);
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}	
}
void ImageRGB::setPixel(int x, int y, const Couleur& newCouleur) throw (XYException)
{
	Debug("[ImageRGB][setPixel]x,y,newCouleur");
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
	matrice[x][y] = newCouleur;
}

void ImageRGB::setDimension(const Dimension &dim)
{
	Debug("[ImageRGB][setDimension]dim");
	if(dim.getLargeur() > 0 && dim.getHauteur() > 0)
	{
		if(matrice == NULL)
		{
			dimension.setLargeur(dim.getLargeur());
			dimension.setHauteur(dim.getHauteur());
			allocMatrice();
			setBackground(Couleur::NOIR);
		}
		else
		{
			Couleur **imageTemp;
			imageTemp = new Couleur*[dim.getLargeur()];
			for (int x = 0; x < dim.getLargeur(); x++)
			{
				imageTemp[x] = new Couleur[dim.getHauteur()];
			}
			//Copier l'image dans une image temp
			if(dim.getLargeur() < getDimension().getLargeur() && dim.getHauteur() < getDimension().getHauteur())
			{
				for(int i = 0; i < dim.getLargeur(); i++)
				{
					for(int j = 0; j < dim.getHauteur(); j++)
					{
						imageTemp[i][j] = matrice[i][j];
					}
				}
			}
			else
			{
				//Si la nouvelle image est plus grande
				//On set background = 0
				for(int i = 0; i < dim.getLargeur(); i++)
				{
					for(int j = 0;j < dim.getHauteur(); j++)
					{
						imageTemp[i][j] = Couleur::BLANC;
					}
				}
				
				//On recopie l'image
				for(int i = 0; i < dim.getLargeur(); i++)
				{
					for(int j = 0; j < dim.getHauteur(); j++)
					{
						imageTemp[i][j] = matrice[i][j];
					}
				}
			}
			//Desalouer l'ancienne matrice
			deleteMatrice();
			//Matrice pointe vers la nouvelle image
			matrice = imageTemp;
			dimension.setLargeur(dim.getLargeur());
			dimension.setHauteur(dim.getHauteur());	
		}
	}
}


Couleur ImageRGB::getPixel(int x, int y) const throw (XYException)
{
	Debug("[ImageRGB][getPixel]x,y");
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


void ImageRGB::importFromBMP(const char* filename)
{
	Debug("[ImageRGB][importFromBMP]filename");
	WindowSDLimage image(filename);
	Dimension temp(image.getWidth(),image.getHeight());
	this->setDimension(temp);
	Couleur couleur;
	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		int *r = new int,*g = new int,*b = new int;
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				image.getPixel(i,j,r,g,b);
			}
			catch(WindowSDLexception& c)
			{
				cout << c.getMessage() << endl;
			}
			couleur.setRouge(*r);
			couleur.setVert(*g);
			couleur.setBleu(*b);
			this->setPixel(i,j,couleur);
		}
	}
}

void ImageRGB::exportToBMP(const char* filename)
{
	Debug("[ImageRGB][exportToBMP]filename");
	WindowSDLimage temp(this->getDimension().getLargeur(),this->getDimension().getHauteur());

	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				temp.setPixel(i,j,this->getPixel(i,j).getRouge(),this->getPixel(i,j).getVert(),this->getPixel(i,j).getBleu());
			}
			catch(WindowSDLexception& c)
			{
				cout << c.getMessage() << endl;
			}
		}
	}
	try
	{
		temp.exportToBMP(filename);
	}
	catch(WindowSDLexception &c)
	{
		cout << c.getMessage() << endl;
	}
}

void ImageRGB::Affiche(void) const
{
	Debug("[ImageRGB][Affiche]void");
	cout << "Id = " << this->getId();
	if(this->getNom())
	{
		cout << " Nom = " << this->getNom() << " ";
	}
	else
	{
		cout << " Nom = ";
	}
	this->getDimension().Affiche();
}

void ImageRGB::Dessine(void) const
{
	Debug("[ImageRGB][Dessine]void");
	WindowSDL fenetre;

	try
	{
		fenetre.open(this->getDimension().getLargeur(),this->getDimension().getHauteur());
	}
	catch(WindowSDLexception &c)
	{
		cout << c.getMessage() << endl;
	}

	WindowSDLimage image(this->getDimension().getLargeur(),this->getDimension().getHauteur());

	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				image.setPixel(i,j,this->getPixel(i,j).getRouge(),this->getPixel(i,j).getVert(),this->getPixel(i,j).getBleu());
			}
			catch(WindowSDLexception &c)
			{
				cout << c.getMessage() << endl;
			}
		}
	}

	try
	{
		fenetre.drawImage(image,0,0);
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

void ImageRGB::allocMatrice(void)
{
	Debug("[ImageRGB][allocMatrice]void");
	matrice = new Couleur*[this->getDimension().getLargeur()];
	for (int x = 0; x < this->getDimension().getLargeur(); x++)
	{
		matrice[x] = new Couleur[this->getDimension().getHauteur()];
	}
}

void ImageRGB::deleteMatrice(void)
{
	Debug("[ImageRGB][deleteMatrice]void");
	for(int x = 0; x < this->getDimension().getLargeur(); x++)
	{
		delete [] matrice [x];
	}
	delete [] matrice;
}

void ImageRGB::Dessine(int x,int y,WindowSDLimage* image)
{
	Debug("[ImageRGB][Dessine]x,y,image");
	for(int i = x; i < this->getDimension().getLargeur(); i++)
	{
		for(int j = y; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				image->setPixel(i,j,this->getPixel(i,j).getRouge(),this->getPixel(i,j).getVert(),this->getPixel(i,j).getBleu());
			}
			catch(WindowSDLexception &c)
			{
				cout << c.getMessage() << endl;
			}
		}
	}
}

void ImageRGB::Save(ofstream& fichier) const
{
	Debug("[ImageRGB][Save]fichier");
	if(!fichier.is_open())
	{
		cout << "[ImageRGB][Save]Erreur fichier == NULL!" << endl;
	}
	else
	{
		Image::Save(fichier);
		Couleur temp;
		int temp2;
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
				temp2 = temp.getRouge();
				fichier.write((char*)&temp2,sizeof(int));
				temp2 = temp.getVert();
				fichier.write((char*)&temp2,sizeof(int));
				temp2 = temp.getBleu();
				fichier.write((char*)&temp2,sizeof(int));
			}
		}
	}
}

void ImageRGB::Load(ifstream& fichier)
{
	Debug("[ImageRGB][Load]fichier");
	if(!fichier.is_open())
	{
		cout << "[ImageNG][Load]Erreur fichier == NULL!" << endl;
	}
	else
	{
		Image::Load(fichier);
		Couleur temp;
		int temp2;
		for(int i = 0; i < (this->getDimension().getLargeur()); i++)
		{
			for(int j = 0; j < (this->getDimension().getHauteur()); j++)
			{
				fichier.read((char*)&temp2,sizeof(int));
				temp.setRouge(temp2);
				fichier.read((char*)&temp2,sizeof(int));
				temp.setVert(temp2);
				fichier.read((char*)&temp2,sizeof(int));
				temp.setBleu(temp2);
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