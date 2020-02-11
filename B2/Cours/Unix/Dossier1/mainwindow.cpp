#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Ecran.h"
#include "Fichier.dat"

int numeroGlobale = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setNom(Elm[1].Nom);
    setMail(Elm[1].Mail);
    numeroGlobale = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonPrecedent_clicked()
{
	Trace("ButtonPrecedent");
	if(numeroGlobale - 1 > 0)
	{
		numeroGlobale--;
		setNom(Elm[numeroGlobale].Nom);
		setMail(Elm[numeroGlobale].Mail);
	}
	else
	{
		numeroGlobale = 5;
		setNom(Elm[numeroGlobale].Nom);
		setMail(Elm[numeroGlobale].Mail);
	}
}

void MainWindow::on_ButtonSuivant_clicked()
{
	Trace("ButtonSuivant");
	
	if(numeroGlobale + 1 <= 5)
	{
		numeroGlobale++;
		setNom(Elm[numeroGlobale].Nom);
		setMail(Elm[numeroGlobale].Mail);
	}
	else
	{
		numeroGlobale = 1;
		setNom(Elm[numeroGlobale].Nom);
		setMail(Elm[numeroGlobale].Mail);
	}
	
}

void MainWindow::on_ButtonTerminer_clicked()
{
Trace("ButtonTerminer");
exit(0);

}

#include "fctUtiles.cpp"
