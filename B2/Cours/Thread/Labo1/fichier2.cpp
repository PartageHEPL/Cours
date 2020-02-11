#include "ImageNG.h"
#include "Utils.h"

ImageNG::ImageNG() : Image()
{
	Debug("[ImageNG][Constructeur]void");
	matrice = NULL;
	this->allocMatrice();
	this->setBackground(0);
}

ImageNG::ImageNG(const char*newImage) : Image(newImage)
{
	Debug("[ImageNG][Constructeur]newImage");
	matrice = NULL;
	this->importFromBMP(newImage);
}

ImageNG::ImageNG(int newId,const char* newNom) : Image(newId,newNom)
{
	Debug("[ImageNG][Constructeur]newId,newNom");
	matrice = NULL;
	this->allocMatrice();
	this->setBackground(0);
}

ImageNG::ImageNG(int newId,const char* newNom,const Dimension& newDim) : Image(newId,newNom,newDim)
{
	Debug("[ImageNG][Constructeur]newId,newNom,newDim");
	matrice = NULL;
	this->setDimension(newDim);
}

ImageNG::ImageNG(const ImageNG& copie) : Image(copie.getId(),copie.getNom(),copie.getDimension())
{
	Debug("[ImageNG][Constructeur]void");
	matrice = NULL;
	this->setDimension(copie.getDimension());
	//Copie de l'image depuis la variable copie
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

ImageNG::~ImageNG(void)
{
	Debug("[ImageNG][Destructeur]void");
	this->deleteMatrice();
}


const int ImageNG::LUMINANCE = 1;
const int ImageNG::PIXEL_A_PIXEL = 2;
int ImageNG::comparaison = ImageNG::LUMINANCE;


ImageNG& ImageNG::operator=(const ImageNG& image)
{
	Debug("[ImageNG][operator=]image");
	this->setId(image.getId());
	this->setNom(image.getNom());
	//Désallouer
	for (int x = 0; x < (*this).getDimension().getLargeur(); x++)
	{
		delete [] matrice[x];
	}
	delete [] matrice;
	matrice = NULL;
	this->setDimension(image.getDimension());
	//Copie de l'image depuis la copie
	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				int p = 0;
				p = image.getPixel(i,j);
				this->setPixel(i,j,p);
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

ImageNG& ImageNG::operator=(const ImageNG* image)
{
	Debug("[ImageNG][operator=]image");
	nom = NULL;
	this->setId(image->getId());
	this->setNom(image->getNom());
	this->deleteMatrice();
	this->setDimension(image->getDimension());
	//Copie de l'image depuis la copie
	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				int p = image->getPixel(i,j);
				this->setPixel(i,j,p);
			}
			catch(XYException& exception)
			{
				cout << "[XYException]" << exception.getMessage() << endl;
				cout << "Axe:" << exception.getAxe() << endl;
			}
		}
	}
	return *this;
}

ImageNG ImageNG::operator+(int val)
{
	Debug("[ImageNG][operator+]val");
	ImageNG newImage(*this);

	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		int newVal;
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				newVal = this->getPixel(i,j) + val;
				if(newVal > 255)
				{
					newVal = 255;
				}
				newImage.setPixel(i,j,newVal);
			}
			catch(XYException& exception)
			{
				cout << "[XYException]" << exception.getMessage() << endl;
				cout << "Axe:" << exception.getAxe() << endl;
			}
		}
	}
	return newImage;
}

ImageNG ImageNG::operator-(int val)
{
	Debug("[ImageNG][operator-]val");
	ImageNG newImage(*this);

	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		int newVal;
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				newVal = this->getPixel(i,j) - val;
				if(newVal < 0)
				{
					newVal = 0;
				}
				newImage.setPixel(i,j,newVal);
			}
			catch(XYException& exception)
			{
				cout << "[XYException]" << exception.getMessage() << endl;
				cout << "Axe:" << exception.getAxe() << endl;
			}
		}
	}
	return newImage;
}

ImageNG ImageNG::operator+(const ImageNG& image)
{
	Debug("[ImageNG][operator+]image");
	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		int val;
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				val = this->getPixel(i,j) + image.getPixel(i,j);
				if(val > 255)
				{
					val = 255;
				}
				this->setPixel(i,j,val);
			}
			catch(XYException& exception)
			{
				cout << "[XYException]" << exception.getMessage() << endl;
				cout << "Axe:" << exception.getAxe() << endl;
			}
		}
	}
	return *this;	
}

ImageNG ImageNG::operator-(const ImageNG& image)
{
	Debug("[ImageNG][operator-]image");
	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		int val;
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				val = this->getPixel(i,j) - image.getPixel(i,j);
				if(val < 0)
				{
					val = 0;
				}
				this->setPixel(i,j,val);
			}
			catch(XYException& exception)
			{
				cout << "[XYException]" << exception.getMessage() << endl;
				cout << "Axe:" << exception.getAxe() << endl;
			}
		}
	}
	return *this;
}

bool ImageNG::operator<(const ImageNG& image)
{
	Debug("[ImageNG][operator<]image");
	int t = 0;
	if(ImageNG::getComparaison() == LUMINANCE)
	{
		if(this->getLuminance() < image.getLuminance())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		int val1,val2;
		int continuer = 1;
		for(int i = 0; i < this->getDimension().getLargeur() && continuer == 1; i++)
		{
			for(int j = 0; j < this->getDimension().getHauteur() && continuer == 1; j++)
			{
				val1 = this->getPixel(i,j);
				val2 = image.getPixel(i,j);
				if(val1 >= val2)
				{
					continuer = 0;
					cout << t << endl;
				}
				t++;
			}
		}
		if(continuer)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool ImageNG::operator>(const ImageNG& image)
{
	Debug("[ImageNG][operator>]image");
	if(ImageNG::getComparaison() == LUMINANCE)
	{
		if(this->getLuminance() > image.getLuminance())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		int continuer = 1;
		for(int i = 0; i < this->getDimension().getLargeur() && continuer == 1; i++)
		{
			for(int j = 0; j < this->getDimension().getHauteur() && continuer == 1; j++)
			{
				if(this->getPixel(i,j) <= image.getPixel(i,j))
				{
					continuer = 0;
				}
			}
		}
		if(continuer)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool ImageNG::operator==(const ImageNG& image)
{
	Debug("[ImageNG][operator==]image");
	if(this->getComparaison() == LUMINANCE)
	{
		if(this->getLuminance() == image.getLuminance())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		int continuer = 1;
		for(int i = 0; i < this->getDimension().getLargeur(); i++)
		{
			for(int j = 0; j < this->getDimension().getHauteur(); j++)
			{
				if(this->getPixel(i,j) != image.getPixel(i,j))
				{
					continuer = 0;
				}
			}			
		}
		if(continuer)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

ImageNG operator+(int val,const ImageNG& image)
{
	Debug("[ImageNG][operator+]val,image");
	ImageNG newImage(image);

	for(int i = 0; i < image.getDimension().getLargeur(); i++)
	{
		int newVal;
		for(int j = 0; j < image.getDimension().getHauteur(); j++)
		{
			try
			{
				newVal = image.getPixel(i,j) + val;
				if(newVal > 255)
				{
					newVal = 255;
				}
				newImage.setPixel(i,j,newVal);
			}
			catch(XYException& exception)
			{
				cout << "[XYException]" << exception.getMessage() << endl;
				cout << "Axe:" << exception.getAxe() << endl;
			}
		}
	}
	return newImage;
}

ImageNG operator-(int val,const ImageNG& image)
{
	Debug("[ImageNG][operator-]val,image");
	ImageNG newImage(image);

	for(int i = 0; i < image.getDimension().getLargeur(); i++)
	{
		int newVal;
		for(int j = 0; j < image.getDimension().getHauteur(); j++)
		{
			try
			{
				newVal = image.getPixel(i,j) - val;
				if(newVal < 0)
				{
					newVal = 0;
				}
				newImage.setPixel(i,j,newVal);
			}
			catch(XYException& exception)
			{
				cout << "[XYException]" << exception.getMessage() << endl;
				cout << "Axe:" << exception.getAxe() << endl;
			}
		}
	}
	return newImage;
}

ImageNG operator+(ImageNG& image,const PixelNG & pixel)
{
	Debug("[ImageNG][operator+]image,pixel");
	ImageNG copie(image);
	try
	{
		copie.setPixel(pixel.getX(),pixel.getY(),pixel.getValeur());
	}
	catch(XYException& exception)
	{
		cout << exception.getMessage() << endl;
		cout << "Axe: " << exception.getAxe() << endl;
	}
	return copie;
}

ImageNG operator+(const PixelNG& pixel,const ImageNG& image)
{
	Debug("[ImageNG][operator+]pixel,image");
	ImageNG copie(image);
	try
	{
		copie.setPixel(pixel.getX(),pixel.getY(),pixel.getValeur());	
	}
	catch(XYException& exception)
	{
		cout << exception.getMessage() << endl;
		cout << "Axe: " << exception.getAxe() << endl;
	}
	return copie;
}


ImageNG ImageNG::operator++(void)
{
	Debug("[ImageNG][operator++]void");
	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		int val;
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				val = this->getPixel(i,j) + 20;
				if(val > 255)
				{
					val = 255;
				}
				this->setPixel(i,j,val);
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
	return (*this);
}

ImageNG ImageNG::operator++(int)
{
	Debug("[ImageNG][operator++]int");
	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		int val;
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				val = this->getPixel(i,j) + 20;
				if(val > 255)
				{
					val = 255;
				}
				this->setPixel(i,j,val);
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
	return (*this);
}

ImageNG ImageNG::operator--(void)
{
	Debug("[ImageNG][operator--]void");
	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		int val;
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				val = this->getPixel(i,j) - 20;
				if(val < 0)
				{
					val = 0;
				}
				this->setPixel(i,j,val);
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
	return (*this);
}

ImageNG ImageNG::operator--(int)
{
	Debug("[ImageNG][operator--]int");
	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		int val;
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				val = this->getPixel(i,j) - 20;
				if(val < 0)
				{
					val = 0;
				}
				this->setPixel(i,j,val);
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
	return (*this);
}


ostream& operator<<(ostream& s,const ImageNG& image)
{
	Debug("[ImageNG][operator<<]s,image");
	s << "Id: " << image.getId() << " Nom: " << image.getNom() << " Largeur: " << image.getDimension().getLargeur() << " Hauteur: " << image.getDimension().getHauteur() << " Luminance: " << image.getLuminance() << " Contraste: " << image.getContraste();
	return s;
}

istream& operator>>(istream& s,ImageNG& image)
{
	Debug("[ImageNG][operator>>]s,image");
	int id = 0;
	int largeur = 1,hauteur = 1;
	char nom[256] = {0};
	cout << "Remplissage de l'image: " << endl;
	while(id < 0)
	{
		cout << "Id: "; cin >> id;
	}
	cout << "Nom: "; cin >> nom;
	while(largeur < 1)
	{
		cout << "Largeur: "; cin >> largeur;
	}
	while(hauteur < 1)
	{
		cout << "Hauteur: "; cin >> hauteur;
	}
	image.setId(id);
	const char *p = &nom[0];
	image.setNom(p);
	Dimension d(largeur,hauteur);
	image.setDimension(d);
	return s;
}


void ImageNG::setDimension(const Dimension &newDim)
{
	Debug("[ImageNG][setDimension]newDim");
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
			int **imageTemp;
			imageTemp = new int*[newDim.getLargeur()];
			for (int x = 0; x < newDim.getLargeur(); x++)
			{
				imageTemp[x] = new int[newDim.getHauteur()];
			}
			//Copier l'image dans une image temp
			if(newDim.getLargeur() < getDimension().getLargeur() && newDim.getHauteur() < getDimension().getHauteur())
			{
				for(int i = 0; i < newDim.getLargeur(); i++)
				{
					for(int j = 0; j < newDim.getHauteur(); j++)
					{
						imageTemp[i][j] = matrice[i][j];
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
						imageTemp[i][j] = 0;
					}
				}
				
				//On recopie l'image
				for(int i = 0; i < newDim.getLargeur(); i++)
				{
					for(int j = 0; j < newDim.getHauteur(); j++)
					{
						imageTemp[i][j] = matrice[i][j];
					}
				}
			}
			//Matrice pointe vers la nouvelle image
			matrice = imageTemp;
			dimension.setLargeur(newDim.getLargeur());
			dimension.setHauteur(newDim.getHauteur());	
		}
	}
}


void ImageNG::setId(int newId)
{
	Debug("[ImageNG][setId]newId");
	Image::setId(newId);
}

void ImageNG::setNom(const char* newNom)
{
	Debug("[ImageNG][setNom]newNom");
	Image::setNom(newNom);
}

void ImageNG::setPixel(int x,int y,int val) throw (XYException)
{
	Debug("[ImageNG][setPixel]x,y,val");
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
		throw XYException('y',"[XYException][Erreur] Y est invalide!");
	}
	matrice[x][y] = val;
}

void ImageNG::setBackground(int val)
{
	Debug("[ImageNG][setBackground]val");
	for(int i = 0; i < getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < getDimension().getHauteur(); j++)
		{
			try
			{
				this->setPixel(i,j,val);
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
}

void ImageNG::setComparaison(int val)
{
	Debug("[ImageNG][setComparaison]val");
	comparaison = val;
}

int ImageNG::getId(void) const
{
	Debug("[ImageNG][getId]void");
	return Image::getId();
}

const char * ImageNG::getNom(void) const
{
	Debug("[ImageNG][getNom]void");
	return Image::getNom();
}

const Dimension& ImageNG::getDimension(void) const
{
	Debug("[ImageNG][getDimension]void");
	return Image::getDimension();
}

int ImageNG::getPixel(int x,int y) const throw (XYException)
{
	Debug("[ImageNG][getPixel]x,y");
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

int ImageNG::getLuminance(void) const
{
	Debug("[ImageNG][getLuminance]void");
	int nbrPixel = this->getDimension().getLargeur() * getDimension().getHauteur();
	int totalGris = 0;

	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			totalGris += this->getPixel(i,j);
		}
	}
	return totalGris/nbrPixel;
}

int ImageNG::getMinimum(void) const
{
	Debug("[ImageNG][getMinimum]void");
	int min = 255;
	for(int i = 0; i < this->getDimension().getLargeur() && min > 0; i++)
	{
		for(int j = 0; j < this->getDimension().getHauteur() && min > 0; j++)
		{
			if(this->getPixel(i,j) < min)
			{
				min = this->getPixel(i,j);
			}
		}
	}
	return min;
}

int ImageNG::getMaximum(void) const
{
	Debug("[ImageNG][getMaximum]void");
	int max = 0;
	for(int i = 0; i < this->getDimension().getLargeur() && max < 255; i++)
	{
		for(int j = 0; j < this->getDimension().getHauteur() && max < 255; j++)
		{
			if(this->getPixel(i,j) > max)
			{
				max = this->getPixel(i,j);
			}
		}
	}
	return max;
}

float ImageNG::getContraste(void) const
{
	Debug("[ImageNG][getContraste]void");
	float max = this->getMaximum(),min = this->getMinimum();
	float contraste;
	if((min == 0 && max == 0) || (min == 255 && max == 255))
	{
		return 0;
	}
	contraste = (max - min)/(max + min);
	return contraste;
}

int ImageNG::getComparaison(void)
{
	Debug("[ImageNG][getComparaison]void");
	return comparaison;
}


void ImageNG::Affiche(void) const
{
	Debug("[ImageNG][Affiche]void");
	cout << "Id = " << this->getId() << endl;
	cout << "Type = NG" << endl;
	if(this->getNom())
	{
		cout << "Nom = " << this->getNom() << endl;
	}
	else
	{
		cout << "Nom = " << endl;
	}
	this->getDimension().Affiche();
	cout << "Luminance = " << this->getLuminance() << endl;
	cout << "Contraste = " << this->getContraste() << endl;
	cout << "Minimum = " << this->getMinimum() << endl;
	cout << "Maximum = " << this->getMaximum() << endl;
 }

void ImageNG::Dessine(void) const
{
	Debug("[ImageNG][Dessine]void");
	WindowSDL fenetre;
	try
	{
		//cout << this->getDimension().getLargeur() << " " << this->getDimension().getHauteur() << endl;
		fenetre.open(getDimension().getLargeur(),getDimension().getHauteur());
	}
	catch(WindowSDLexception &c)
	{
		cout << "[WindowSDLexception]" << c.getMessage() << endl;
	}
	WindowSDLimage image(this->getDimension().getLargeur(),this->getDimension().getHauteur());
	for(int i = 0; i < this->getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < this->getDimension().getHauteur(); j++)
		{
			try
			{
				image.setPixel(i,j,getPixel(i,j),getPixel(i,j),getPixel(i,j));
			}
			catch(WindowSDLexception &c)
			{
				cout << "[WindowSDLexception]" << c.getMessage() << endl;
			}
		}
	}
	try
	{
		fenetre.drawImage(image,0,0);
	}
	catch(WindowSDLexception &c)
	{
		cout << "[WindowSDLexception]" << c.getMessage() << endl;
	}
	try
	{
		fenetre.waitClick();
	}
	catch(WindowSDLexception &c)
	{
		cout << "[WindowSDLexception]" << c.getMessage() << endl;
	}
	try
	{
		fenetre.close();
	}
	catch(WindowSDLexception &c)
	{
		cout << "[WindowSDLexception]" << c.getMessage() << endl;
	}
}

void ImageNG::importFromBMP(const char* fichier)
{
	Debug("[ImageNG][importFromBMP]fichier");
	try
	{
		WindowSDLimage image(fichier);
		Dimension temp(image.getWidth(),image.getHeight());
		setNom(fichier);
		setDimension(temp);
		int *t = NULL;
		for(int i = 0; i < getDimension().getLargeur(); i++)
		{
			int *r = new int,*g = new int,*b = new int;
			t = matrice[i];
			for(int j = 0; j < getDimension().getHauteur(); j++)
			{
				try
				{
					image.getPixel(i,j,r,g,b);
				}
				catch(WindowSDLexception& c)
				{
					cout << "[WindowSDLexception]" << c.getMessage() << endl;
				}
				*t = (*r + *g + *b) / 3;
				t++;
			}
		}
	}
	catch(WindowSDLexception& exception)
	{
		cout << "[WindowSDLexception]" << exception.getMessage() << endl;
	}
}

void ImageNG::exportToBMP(const char*fichier)
{
	Debug("[ImageNG][exportToBMP]fichier");
	WindowSDLimage temp(getDimension().getLargeur(),getDimension().getHauteur());
	int *t = NULL;
	for(int i = 0; i < getDimension().getLargeur(); i++)
	{
		t = matrice[i];
		for(int j = 0; j < getDimension().getHauteur(); j++)
		{
			try
			{
				temp.setPixel(i,j,*t,*t,*t);
			}
			catch(WindowSDLexception &c)
			{
				cout << c.getMessage() << endl;
			}
			t++;
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

void ImageNG::allocMatrice(void)
{
	Debug("[ImageNG][allocMatrice]void");
	matrice = new int*[getDimension().getLargeur()];
	for(int x = 0; x < dimension.getLargeur(); x++)
	{
		matrice[x] = new int[getDimension().getHauteur()];
	}
}

void ImageNG::deleteMatrice(void)
{
	Debug("[ImageNG][deleteMatrice]void");
	for(int x = 0; x < dimension.getLargeur(); x++)
	{
		delete[] matrice[x];
	}
	delete[] matrice;
}

void ImageNG::Dessine(int x,int y,WindowSDLimage* image)
{
	Debug("[ImageNG][Dessine]x,y,image");
	for(int i = x; i < ((this->getDimension().getLargeur()) + x); i++)
	{
		for(int j = y; j < ((this->getDimension().getHauteur()) + y); j++)
		{
			try
			{
				image->setPixel(i,j,getPixel(i - x,j - y),getPixel(i - x,j - y),getPixel(i - x,j - y));
			}
			catch(WindowSDLexception &c)
			{
				cout << c.getMessage() << endl;
			}
		}
	}
}

void ImageNG::Save(ofstream& fichier) const
{
	Debug("[ImageNG][Save]fichier");
	if(!fichier.is_open())
	{
		cout << "[ImageNG][Save]Erreur fichier == NULL!" << endl;
	}

	Image::Save(fichier);
	int temp;
	for(int i = 0; i < (this->getDimension().getLargeur()); i++)
	{
		for(int j = 0; j < (this->getDimension().getHauteur()); j++)
		{
			try
			{
				temp = getPixel(i,j);
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
				return;
			}
			if(fichier.eof())
			{
				cout << "[ImageNG][Save]Fin du fichier dans la boucle" << endl;
				return;
			}
			fichier.write((char*)&temp,sizeof(int));
		}
	}
}

void ImageNG::Load(ifstream& fichier)
{
	Debug("[ImageNG][Load]fichier");
	if(!fichier.is_open())
	{
		cout << "[ImageNG][Load]Erreur fichier == NULL!" << endl;
		return;
	}
	Image::Load(fichier);
	int temp;
	for(int i = 0; i < (this->getDimension().getLargeur()); i++)
	{
		for(int j = 0; j < (this->getDimension().getHauteur()); j++)
		{
			if(fichier.eof())
			{
				cout << "[ImageNG][Load]Fin du fichier dans la boucle" << endl;
				return;
			}
			fichier.read((char*)&temp,sizeof(int));
			try
			{
				this->setPixel(i,j,temp);
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
				return;
			}
		}
	}
}