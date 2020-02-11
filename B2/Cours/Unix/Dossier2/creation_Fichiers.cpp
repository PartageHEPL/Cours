#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "Ecran.h"
#include "Donnee.dat"
#include <iostream>
using namespace std;
#include <cerrno>

int fichierExiste();
void creationFichier();
void copierElmBase();

char nomFichier [] = {"G2225.dat"};

int main(int argc, char const *argv[])
{
	if(fichierExiste())
	{
		cout << "Le fichier existe deja!" << endl;
	}
	else
	{
		creationFichier();
		copierElmBase();
	}
	return 0;
}

int fichierExiste()
{
	int temp;
	if((temp = open(nomFichier,O_RDONLY)) == -1)
	{
		return 0;
	}
	if(::close(temp) == -1)
	{
		cout << "Erreur lors de la fermeture du fichier" << endl;
		exit(1);
	}
	return 1;
}

void creationFichier()
{
	int temp;
	if((temp = open(nomFichier,O_CREAT,S_IRWXU)) == -1)
	{
		cout << "Erreur lors de la creation du fichier" << endl;
		cout << "test 2" << endl;
		exit(1);
	}
	else
	{
		if(::close(temp) == -1)
		{
			cout << "Erreur lors de la fermeture du ficier" << endl;
			exit(1);
		}
	}
}

void copierElmBase()
{
	int temp;

	if((temp = open(nomFichier,O_RDWR)) == -1)
	{
		cout << "Erreur lors de la lecture du fichier" << endl;
		exit(1);
	}
	if(lseek(temp,0,SEEK_SET) == -1)
	{
		cout << "Erreur lors du deplacement" << endl;
		exit(1);
	}
	for(int i = 0; i < 10; ++i)
	{
		if(write(temp, &Elm[i],sizeof(ELEMENT)) < (int)sizeof(ELEMENT))
		{
			cout << "Erreur lors de l'ecriture" << endl;
			exit(1);
		}
	}
	if(close(temp) == -1)
	{
		cout << "Erreur lors de la fermeture du fichier" << endl;
		exit(1);
	}
}
