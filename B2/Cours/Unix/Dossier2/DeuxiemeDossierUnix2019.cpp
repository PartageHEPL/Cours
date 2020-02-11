#include "DeuxiemeDossierUnix2019.h"
#include "ui_DeuxiemeDossierUnix2019.h"
#include <QMessageBox>

#include "Ecran.h"
//#include "Donnee.dat"
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#include <cerrno>

int	Pos = 0;
bool Modification = false;

MainDeuxiemeDossierUnix2019::MainDeuxiemeDossierUnix2019(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDeuxiemeDossierUnix2019)
{
ui->setupUi(this);
ELEMENT temp;
	temp = lectureElem();
	setNom(temp.Nom);
	setAnneeNaissance(temp.AnneeNaissance);
	setFichierImage(temp.AdrImage);
	setAdresseMail(temp.Mail);
	setImage(temp.AdrImage);
}

MainDeuxiemeDossierUnix2019::~MainDeuxiemeDossierUnix2019()
{
    delete ui;
}

void MainDeuxiemeDossierUnix2019::on_ButtonPrecedent_clicked()
{
	Trace("Dans Precedent %d",Pos);
	if(Pos - 1 > 0)
	{
		Pos--;
	}
	else
	{
		Pos = 8;
	}
	ELEMENT temp;
	temp = lectureElem();
	setNom(temp.Nom);
	setAnneeNaissance(temp.AnneeNaissance);
	setFichierImage(temp.AdrImage);
	setAdresseMail(temp.Mail);
	setImage(temp.AdrImage);
	
return;
}

void MainDeuxiemeDossierUnix2019::on_ButtonSuivant_clicked()
{
	Trace("Dans Suivant %d",Pos);
	if(Pos + 1 < 9)
	{
		Pos++;
	}
	else
	{
		Pos = 0;
	}
	ELEMENT temp;
	temp = lectureElem();
	setNom(temp.Nom);
	setAnneeNaissance(temp.AnneeNaissance);
	setFichierImage(temp.AdrImage);
	setAdresseMail(temp.Mail);
	setImage(temp.AdrImage);

return;
}

void MainDeuxiemeDossierUnix2019::on_ButtonModifier_clicked()
{
Trace("Dans Modifier");

ecritureElem();
if (Modification)
{
		setImage(getFichierImage());
		if (MessageConfirmation("Modification","Enregistrement va être modifier\nConfirmer..."))
		{ 
			Trace("Ok");
			Modification = false; 
			setTextModifier("Modifier");
		return;
		}
	
	Trace("Faux");
	 
}
Modification = true;
setTextModifier("Continuer");
return;
}

void MainDeuxiemeDossierUnix2019::on_ButtonTerminer_clicked()
{
Trace("Dans Terminer");
if (Modification)
	{	 
	if (MessageConfirmation("Terminer","Modification en cours\nEnregistrer...")) 
		{
		Trace("Ok");
		}
	else 
		{
		Trace("Faux");
		}
	}
exit(0);
}

ELEMENT MainDeuxiemeDossierUnix2019::lectureElem()
{
	ELEMENT temp;
	int fichier;
	if((fichier = open("G2225.dat", O_RDONLY)) == -1)
	{
		cout << "Erreur lors de l'ouverture du fichier" << endl;
		exit(1);
	}
	if(lseek(fichier,sizeof(ELEMENT)*Pos, SEEK_SET) == -1)
	{
		cout << "Erreur lors du deplacement dans le fichier" << endl;
		exit(1);
	}
	if(read(fichier, &temp, sizeof(ELEMENT)) < 0)
	{
		cout << "Erreur lors de la lecture" << endl;
		exit(1);
	}
	if(::close(fichier) == -1)
	{
		cout << "Erreur lors de la fermeture du fichier" << endl;
		exit(1);
	}
	return temp;
}

void MainDeuxiemeDossierUnix2019::ecritureElem()
{

	int fichier;
	ELEMENT temp;

	temp = lectureElem();
	strcpy(temp.AdrImage,getFichierImage());
	strcpy(temp.Mail,getAdresseMail());

	if((fichier = open("G2225.dat",O_WRONLY)) == -1)
	{
		cout << "Erreur lors de la lecture du fichier" << endl;
		exit(1);
	}
	if(lseek(fichier,sizeof(ELEMENT) * Pos, SEEK_SET) == -1)
	{
		cout << "Erreur lors du deplacement dans le fichier" << endl;
		exit(1);
	}
	if(write(fichier, &temp,sizeof(ELEMENT)) != sizeof(ELEMENT))
	{
		cout << "Erreur lors de l'ecriture" << endl;
		cout << "\nERRNO : " << strerror(errno) << endl;
		exit(1);
	}
	if(::close(fichier) == -1)
	{
		cout << "Erreur lors de la fermeture du fichier" << endl;
		exit(1);
	}
}	


#include "fctUtiles.cpp"
