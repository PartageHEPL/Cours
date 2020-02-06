#include "Moteur.h"
#include "Utils.h"
#include "Iterateur.h"
#include "ImageNG.h"
#include "ImageRGB.h"
#include "ImageB.h"
#include "Traitements.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Moteur::Moteur(void)
{
	Debug("[Moteur][Constructeur]void");
	ImageNG::setComparaison(ImageNG::LUMINANCE);
}

int Moteur::Insere(Image *pImage)
{
	Debug("[Moteur][Insere]pImage");
	int id = this->GetNextId();
	ImageNG *pImageNG;
	ImageRGB *pImageRGB;
	ImageB *pImageB;

	pImage->setId(id);

	if((pImageNG = dynamic_cast<ImageNG*>(pImage)))
	{
		Debug("[Moteur][Insere]C'est une ImagesNG!");
		ImageNG image1;
		image1 = pImageNG;
		(this->imagesNG).insere(image1);
	}
	if((pImageRGB = dynamic_cast<ImageRGB*>(pImage)))
	{
		Debug("[Moteur][Insere]C'est une ImagesRGB!");
		ImageRGB image2;
		image2 = pImageRGB;
		this->imagesRGB.insere(image2);
	}
	if((pImageB = dynamic_cast<ImageB*>(pImage)))
	{
		Debug("[Moteur][Insere]C'est une ImageB!");
		ImageB image3;
		image3 = pImageB;
		this->imagesB.insere(image3);
	}
	return id;
}

ImageNG Moteur::GetImageNG(int id)
{
	Debug("[Moteur][getImageNG]id");
	Iterateur<ImageNG> it(this->imagesNG);

	for(it.reset(); !it.end(); it++)
	{
		if(((ImageNG)it).getId() == id)
		{
			ImageNG newImage((ImageNG)it);
			return newImage;
		}
	}
	return NULL;
}

Image& Moteur::GetImage(int id) throw (MoteurException)
{
	Debug("[Moteur][getImage]id");
	//ImageNG
	Iterateur<ImageNG> it1(this->imagesNG);
	for(it1.reset(); !it1.end(); it1++)
	{
		if(((ImageNG)it1).getId() == id)
		{
			Debug("[Moteur][getImage][ImageNG]Trouve!");
			return &it1;
		}
	}

	//ImageRGB
	Iterateur<ImageRGB> it2(this->imagesRGB);
	for(it2.reset(); !it2.end(); it2++)
	{
		if(((ImageRGB)it2).getId() == id)
		{
			Debug("[Moteur][getImage][ImageRGB]Trouve!");
			return &it2;
		}
	}

	//ImageB
	Iterateur<ImageB> it3(this->imagesB);
	for(it3.reset(); !it3.end(); it3++)
	{
		if(((ImageB)it3).getId() == id)
		{
			Debug("[Moteur][getImage][ImageB]Trouve!");

			return &it3;
		}
	}
	throw MoteurException("[MoteurException][getImage]Id non trouvée!");
}

int Moteur::GetNextId(void)
{
	int id = -1;
	Debug("[Moteur][getNextId]void");
	fstream fichier("ID.dat",ios::in | ios::out | ios:: binary);
	if(fichier.is_open())
	{
		fichier.seekg(0,fichier.beg);
		fichier.read((char*)&id,sizeof(int));
		id++;
		fichier.seekg(0,fichier.beg);
		fichier.write((char*)&id,sizeof(int));
		fichier.close();
	}
	else
	{	
		FILE* newFile = fopen("ID.dat","wb");
		if(newFile)
		{
			id = 0;
			if((fwrite(&id,1,sizeof(int),newFile)) != sizeof(int))
			{
				cout << "[Moteur][getNextId]Erreur fwrite != 1" << endl;
			}
			if(fseek(newFile,0,SEEK_SET) != 0)
			{
				cout << "[Moteur][getNextId]Erreur de fseek" << endl;
			}
			id++;
			if(fwrite(&id,1,sizeof(int),newFile) != 1)
			{

			}
			fclose(newFile);
		}
		else
		{
			cout << "[Moteur][getNextId]Creation de fichier impossible" << endl;
		}
	}
	return id;
}

void Moteur::Affiche(void)
{
	Debug("[Moteur][Affiche]void");
	cout << "[ImagesNG]" << endl;
	Iterateur<ImageNG> it1(this->imagesNG);
	for(it1.reset(); !it1.end(); it1++)
	{
		cout << (ImageNG)it1 << endl;
	}

	cout << "[ImageRGB]" << endl;
	Iterateur<ImageRGB> it2(this->imagesRGB);
	for(it2.reset(); !it2.end(); it2++)
	{
		cout << (ImageRGB)it2 << endl;
	}

	cout << "[ImageB]" << endl;
	Iterateur<ImageB> it3(this->imagesB);
	for(it3.reset(); !it3.end(); it3++)
	{
		cout << (ImageB)it3 << endl;
	}
}

void Moteur::SupprimerImage(int id)
{
	Debug("[Moteur][SupprimerImage]id");
	Iterateur<ImageNG> it1(this->imagesNG);
	for(it1.reset(); !it1.end(); it1++)
	{
		if(((ImageNG)it1).getId() == id)
		{
			it1.remove();
			return;
		}
	}

	Iterateur<ImageRGB> it2(this->imagesRGB);
	for(it2.reset(); !it2.end(); it2++)
	{
		if(((ImageRGB)it2).getId() == id)
		{
			it2.remove();
			return;
		}
	}

	Iterateur<ImageB> it3(this->imagesB);
	for(it3.reset(); !it3.end(); it3++)
	{
		if(((ImageB)it3).getId() == id)
		{
			it3.remove();
			return;
		}
	}
	Debug("[MoteurException][supprimerImage]Erreur: Aucunes images trouve!");
	cout << "Aucune image trouve avec l'id : " << id << endl;
}

//Erreur dans la fonction donc debug oblige
int Moteur::ImporteImageNG(const char *fichier)
{
	Debug("[Moteur][ImporteImageNG]fichier");
	try
	{
		char *Buff = new char[strlen(fichier + 15)];
		strcpy(Buff,"../images/");
		strcat(Buff,fichier);
		strcat(Buff,".bmp");
		ImageNG newImage;
		newImage.importFromBMP(Buff);
		//newImage.Affiche();
		newImage.Dessine();
		Insere(&newImage);
		delete [] Buff;
		return newImage.getId();
	}
	catch(MoteurException& exception)
	{
		cout << "erreur importeImageNG" << endl;
		cout << exception.getMessage() << endl;
		return -1;
	}
}

int Moteur::ImporteImageRGB(const char *fichier)
{
	Debug("[Moteur][ImporteImageRGB]fichier");
	char *Buff = new char[strlen(fichier + 15)];
	strcpy(Buff,"../images/");
	strcpy(Buff,fichier);
	strcpy(Buff,".BMP");
	ImageRGB newImage(Buff);
	newImage.setId(this->GetNextId());
	try
	{
		this->imagesRGB.insere(newImage);
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
		delete [] Buff;
		return -1;
	}
	delete [] Buff;
	return newImage.getId();
}

void Moteur::VisualiseImage(int id)
{
	Debug("[Moteur][VisualiseImage]id");
	try
	{
		this->GetImage(id).Affiche();
		cout << endl;
		this->GetImage(id).Dessine();
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
	}
}

void Moteur::VisualiseImage(int id1,int id2)
{
	Debug("[Moteur][VisualiseImage]id1,id2");
	int largeur = 0,hauteur = 0;
	try
	{
		largeur = this->GetImage(id1).getDimension().getLargeur() + this->GetImage(id2).getDimension().getLargeur() + 1;
		if(this->GetImage(id1).getDimension().getLargeur() > this->GetImage(id2).getDimension().getLargeur())
		{
			hauteur = this->GetImage(id1).getDimension().getLargeur();
		}
		else
		{
			hauteur = this->GetImage(id2).getDimension().getLargeur();
		}
		cout << endl << "Premiere Image:" << endl;
		this->GetImage(id1).Affiche();
		cout << endl;
		cout << "Deuxieme Image:" << endl;
		this->GetImage(id2).Affiche();
		cout << endl;
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
		throw MoteurException("[Moteur][VisualiseImage]Id1 invalide!");
	}

	WindowSDL fenetre;

	try
	{
		fenetre.open(largeur,hauteur);
	}
	catch(WindowSDLexception &c)
	{
		cout << c.getMessage() << endl;
		return;
	}

	WindowSDLimage image(largeur,hauteur);
	try
	{
		this->GetImage(id1).Dessine(0,0,&image);
		this->GetImage(id2).Dessine(this->GetImage(id2).getDimension().getLargeur(),0,&image);
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
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

void Moteur::ExporterBMP(int id,const char* fichier)
{
	Debug("[Moteur][exportToBMP]id,fichier");
	try
	{
		this->GetImage(id).exportToBMP(fichier);
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
		return;
	}
}

int Moteur::AugmenteLuminosite(int id,int val)
{
	Debug("[Moteur][AugmenteLuminosite]id,val");
	try
	{
		ImageNG newImage((ImageNG&)this->GetImage(id));
		newImage = newImage + val;
		int newId = this->Insere(&newImage);
		return newId;
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
		return -1;
	}
}

int Moteur::DiminueLuminosite(int id, int val)
{
	Debug("[Moteur][DiminueLuminosite]id,val");
	try
	{
		ImageNG newImage((ImageNG&)this->GetImage(id));
		newImage =  newImage - val;
		int newId = this->Insere(&newImage);
		return newId;
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
		return -1;
	}
}

int Moteur::Soustraire(int id1, int id2)
{
	Debug("[Moteur][Soustraire]id1,id2");
	try
	{
		ImageNG newImage1((ImageNG&)this->GetImage(id1));
		ImageNG newImage2((ImageNG&)this->GetImage(id2));
		ImageNG newImage3;
		newImage3 = newImage1 - newImage2;
		int newId = this->Insere(&newImage3);
		return newId;
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
		return -1;
	}
}

int Moteur::Seuillage(int id, int seuil)
{
	Debug("[Moteur][Seuillage]id,seuil");
	try
	{
		ImageNG newImage1((ImageNG&)this->GetImage(id));
		ImageB newImage2;
		newImage2 = Traitements::Seuillage(newImage1,seuil);
		int newId = this->Insere(&newImage2);
		return newId;
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
		return -1;
	}
}

int Moteur::Negatif(int id)
{
	Debug("[Moteur][Negatif]id");
	try
	{
		ImageNG newImage1((ImageNG&)this->GetImage(id));
		ImageNG newImage2;
		newImage2 = Traitements::Negatif(newImage1);
		int newId = this->Insere(&newImage2);
		return newId;
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
		return -1;
	}
}

int Moteur::FiltreMedian(int id, int tailleFiltre)
{
	Debug("[Moteur][FiltreMedian]id,tailleFiltre");
	try
	{
		ImageNG newImage1((ImageNG&)this->GetImage(id));
		ImageNG newImage2;
		newImage2 = Traitements::FiltreMedian(newImage1,tailleFiltre);
		int newId = this->Insere(&newImage2);
		return newId;
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
		return -1;
	}
}

int Moteur::FiltreMoyenneur(int id, int tailleFiltre)
{
	Debug("[Moteur][FiltreMoyenneur]id,tailleFiltre");
	try
	{
		ImageNG newImage1((ImageNG&)this->GetImage(id));
		ImageNG newImage2;
		newImage2 = Traitements::FiltreMoyenneur(newImage1,tailleFiltre);
		int newId = this->Insere(&newImage2);
		return newId;
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
		return -1;
	}
}

int Moteur::Dilatation(int id, int tailleFiltre)
{
	Debug("[Moteur][Dilatation]id,tailleFiltre");
	try
	{
		ImageNG newImage1((ImageNG&)this->GetImage(id));
		ImageNG newImage2;
		newImage2 = Traitements::Dilatation(newImage1,tailleFiltre);
		int newId = this->Insere(&newImage2);
		return newId;
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
		return -1;
	}
}

int Moteur::Erosion(int id, int tailleFiltre)
{
	Debug("[Moteur][Erosion]id,tailleFiltre");
	try
	{
		int temp;
		int continuer = 1;
		ImageNG newImage1((ImageNG&)this->GetImage(id));

		WindowSDL fenetre;

		fenetre.open(newImage1.getDimension().getLargeur(),newImage1.getDimension().getHauteur());

		WindowSDLimage image(newImage1.getDimension().getLargeur(),newImage1.getDimension().getHauteur());
		newImage1.Dessine(0,0,&image);
		fenetre.drawImage(image,0,0);
		while(continuer)
		{
			WindowSDLclick click;
			//Click 1
			click = fenetre.waitClick();
			if(click.getX() == -1 || click.getY() == -1)
			{
				continuer = 0;
			}
			else
			{
				Pixel P1(click.getX(),click.getY());
				//Click 2
				click = fenetre.waitClick();
				if(click.getX() == -1 || click.getY() == -1)
				{
					continuer = 0;
				}
				else
				{
					Pixel P2(click.getX(),click.getY());
					//Modifier les coins si on les choisi mal
					if(P1.getX() > P2.getX())
					{
						temp = P1.getX();
						P1.setX(P2.getX());
						P2.setX(temp);
					}
					if(P1.getY() > P2.getY())
					{
						temp = P1.getY();
						P1.setY(P2.getY());
						P2.setY(temp);
					}
					//On applique le filtre
					newImage1 = Traitements::FiltreMoyenneur(newImage1,tailleFiltre,P1,P2);
					WindowSDLimage image2(newImage1.getDimension().getLargeur(),newImage1.getDimension().getHauteur());
					for(int i = 0; i < newImage1.getDimension().getLargeur(); i++)
					{
						for(int j = 0; j < newImage1.getDimension().getHauteur(); j++)
						{
							try
							{
								image2.setPixel(i,j,newImage1.getPixel(i,j),newImage1.getPixel(i,j),newImage1.getPixel(i,j));
							}
							catch(WindowSDLexception &c)
							{
								cout << c.getMessage() << endl;
							}
						}
					}
					fenetre.drawImage(image2,0,0);
				}
			}
		}
		fenetre.close();
		int newId = this->Insere(&newImage1);
		return newId;
	}
	catch(WindowSDLexception &c)
	{
		cout << c.getMessage() << endl;
		return -1;
	}
	catch(MoteurException& exception)
	{
		cout << exception.getMessage() << endl;
		return -1;
	}
}
