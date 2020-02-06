#include "Iterateur.h"
#include "ListeTriee.h"
#include "Liste.h"
#include "Utils.h"
#include "Traitements.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

ImageB Traitements::Seuillage(const ImageNG& image, int seuil)
{
	Debug("[Traitements][Seuillage]");
	ImageB newImage;
	newImage.setId(image.getId());
	newImage.setNom(image.getNom());
	newImage.setDimension(image.getDimension());

	for(int i = 0; i < image.getDimension().getLargeur(); i++)
	{
		for(int j = 0; j < image.getDimension().getHauteur(); j++)
		{
			if(image.getPixel(i,j) > seuil)
			{
				newImage.setPixel(i,j,true);
			}
			else
			{
				newImage.setPixel(i,j,false);
			}
		}
	}
	return newImage;
}

ImageNG Traitements::FiltreMoyenneur(const ImageNG& imageIn, int taille, Pixel p1, Pixel p2)
{
	Debug("[Traitements][FiltreMoyenneur]");
	ImageNG imageOut(imageIn);

	int somme;
	int nbrPixel;
	int demiFiltre = taille / 2;
	Pixel coin1(p1);
	Pixel coin2(p2);

	if(coin2.getX() == 0 && coin2.getY() == 0)
	{
		coin2.setX(imageIn.getDimension().getLargeur());
		coin2.setY(imageIn.getDimension().getHauteur());
	}

	for(int y = coin1.getY(); y < coin2.getY(); y++)
	{
		for(int x = coin1.getX(); x < coin2.getX(); x++)
		{
			nbrPixel = 0;
			somme = 0;
			for(int y2 = y - demiFiltre; y2 <= y + demiFiltre; y2++)
			{
				for(int x2 = x - demiFiltre; x2 <= x + demiFiltre; x2++)
				{
					if((x2 > 0 && y2 > 0) && (x2 < imageIn.getDimension().getLargeur() && y2 < imageIn.getDimension().getHauteur()))
					{
						somme += imageIn.getPixel(x2,y2);
						nbrPixel++;
					}
				}
			}
			try
			{
				imageOut.setPixel(x,y,(somme / nbrPixel));
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
	return imageOut;
}

ImageNG Traitements::FiltreMedian(const ImageNG& imageIn, int taille)
{
	Debug("[Traitements][FiltreMedian]");
	
	ImageNG imageOut(imageIn);

	int demiFiltre = taille / 2;

	for(int y = 0; y < imageIn.getDimension().getHauteur(); y++)
	{
		for(int x = 0; x < imageIn.getDimension().getLargeur(); x++)
		{
			ListeTriee<int> liste;
			for(int y2 = y - demiFiltre; y2 <= y + demiFiltre; y2++)
			{
				for(int x2 = x - demiFiltre; x2 <= x + demiFiltre; x2++)
				{
					if((x2 > 0 && y2 > 0) && (x2 < imageIn.getDimension().getLargeur() && y2 < imageIn.getDimension().getHauteur()))
					{
						try
						{
							liste.insere(imageIn.getPixel(x2,y2));
						}
						catch(XYException& exception)
						{
							cout << exception.getMessage() << endl;
							cout << "Axe: " << exception.getAxe() << endl;
						}
					}
					else
					{
						liste.insere(0);
					}
				}
			}
			Iterateur<int> it(liste);
			it.reset();
			for(int i = 1; i < (taille * taille) / 2 + 1; i++,it++)
			{

			}
			try
			{
				imageOut.setPixel(x,y,(int)it);
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
	return imageOut;
}

ImageNG Traitements::Erosion(const ImageNG& imageIn, int taille)
{
	Debug("[Traitements][Erosion]");

	ImageNG imageOut(imageIn);

	int demiFiltre = taille / 2;

	for(int y = 0; y < imageIn.getDimension().getHauteur(); y++)
	{
		for(int x = 0; x < imageIn.getDimension().getLargeur(); x++)
		{
			ListeTriee<int> liste;
			for(int y2 = y - demiFiltre; y2 <= y + demiFiltre; y2++)
			{
				for(int x2 = x - demiFiltre; x2 <= x + demiFiltre; x2++)
				{
					if((x2 > 0 && y2 > 0) && (x2 < imageIn.getDimension().getLargeur() && y2 < imageIn.getDimension().getHauteur()))
					{
						try
						{
							liste.insere(imageIn.getPixel(x2,y2));
						}
						catch(XYException& exception)
						{
							cout << exception.getMessage() << endl;
							cout << "Axe: " << exception.getAxe() << endl;
						}
					}
					else
					{
						liste.insere(0);
					}
				}
			}
			Iterateur<int> it(liste);
			it.reset();
			try
			{
				imageOut.setPixel(x,y,(int)it);
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
	return imageOut;
}

ImageNG Traitements::Dilatation(const ImageNG& imageIn, int taille)
{
	Debug("[Traitements][Dilatation]");

	ImageNG imageOut(imageIn);

	int demiFiltre = taille / 2;

	for(int y = 0; y < imageIn.getDimension().getHauteur(); y++)
	{
		for(int x = 0; x < imageIn.getDimension().getLargeur(); x++)
		{
			ListeTriee<int> liste;
			for(int y2 = y - demiFiltre; y2 <= y + demiFiltre; y2++)
			{
				for(int x2 = x - demiFiltre; x2 <= x + demiFiltre; x2++)
				{
					if((x2 > 0 && y2 > 0) && (x2 < imageIn.getDimension().getLargeur() && y2 < imageIn.getDimension().getHauteur()))
					{
						try
						{
							liste.insere(imageIn.getPixel(x2,y2));
						}
						catch(XYException& exception)
						{
							cout << exception.getMessage() << endl;
							cout << "Axe: " << exception.getAxe() << endl;
						}
					}
					else
					{
						liste.insere(0);
					}
				}
			}
			Iterateur<int> it(liste);
			it.reset();
			for(int i = 1; i < taille; i++,it++)
			{

			}
			try
			{
				imageOut.setPixel(x,y,(int)it);
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
	return imageOut;
}

ImageNG Traitements::Negatif(const ImageNG& imageIn)
{
	Debug("[Traitements][Negatif]");
	ImageNG imageOut(imageIn);

	for(int y = 0; y < imageIn.getDimension().getHauteur(); y++)
	{
		for(int x = 0; x < imageIn.getDimension().getLargeur(); x++)
		{
			try
			{
				imageOut.setPixel(x,y,(255 - imageIn.getPixel(x,y)));
			}
			catch(XYException& exception)
			{
				cout << exception.getMessage() << endl;
				cout << "Axe: " << exception.getAxe() << endl;
			}
		}
	}
	return imageOut;
}