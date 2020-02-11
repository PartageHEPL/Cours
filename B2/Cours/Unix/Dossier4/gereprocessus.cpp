#include "gereprocessus.h"
#include "ui_gereprocessus.h"

#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <iostream>
using namespace std;
#include "Ecran.h"

void FinFils(int);
extern GereProcessus* w;

GereProcessus::GereProcessus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GereProcessus)
{
ui->setupUi(this);
this->move(200,200);
struct sigaction Act;
Act.sa_handler = FinFils;
sigemptyset(&Act.sa_mask);
Act.sa_flags = 0;
sigaction(SIGCHLD,&Act,NULL);

}

GereProcessus::~GereProcessus()
{
    delete ui;
}
int idF1 = 0;
int idF2 = 0;
int idF3 = 0;

void GereProcessus::on_ButtonTerminer1_clicked()
{
Trace("Terminer 1");
kill(idF1,SIGUSR1);
}

void GereProcessus::on_ButtonTerminer2_clicked()
{
Trace("Terminer 2");
kill(idF2,SIGUSR1);
}

void GereProcessus::on_ButtonTerminer3_clicked()
{
Trace("Terminer 3");
kill(idF3,SIGUSR1);
}

void GereProcessus::on_ButtonGo_clicked()
{
	Trace("Dans ButtonGo");
	if(getNomGroupe1())
	{
		if((idF1 = fork())== -1)
		{
			perror("error de fork");
			exit(1);
		}
	
		if(!idF1)//processus fils 1
		{
			execl("TraitementFichier", "TraitementFichier", getNomGroupe1(), "300", (char*)NULL);
			perror("error de execl");
			exit(5);
		}
	}
	
	if(getNomGroupe2())
	{
		if((idF2 = fork())== -1)
		{
			perror("error de fork");
			exit(1);
		}
	
		if(!idF2)//processus fils 2
		{
			execl("TraitementFichier", "TraitementFichier", getNomGroupe2(), "500", (char*)NULL);
			perror("error de execl");
			exit(5);
		}
	}
	if(getNomGroupe3())
	{
		if((idF3 = fork())== -1)
		{
			perror("error de fork");
			exit(1);
		}
	
		if(!idF3)//processus fils 3
		{
			execl("TraitementFichier", "TraitementFichier", getNomGroupe3(), "700", (char*)NULL);
			perror("error de execl");
			exit(5);
		}
	}
}

void GereProcessus::on_ButtonEffacer_clicked()
{
Trace("Dans ButtonEffacer");
setNomGroupe1("");
setNbEtud1(-1);
setNomGroupe2("");
setNbEtud2(-1);
setNomGroupe3("");
setNbEtud3(-1);  
}

void GereProcessus::on_ButtonTerminer_clicked()
{
Trace("Dans ButtonTerminer");
exit(0);
}

void FinFils(int Sig)
{
	Trace("Reception du signal %d",Sig);

	int status;
	int pidFils = wait(&status);
	if(pidFils == idF1)
	{
		cout<<"fin du fils"<<endl;
		w->setNbEtud1(WEXITSTATUS(status));
	}
	
	if(pidFils == idF2)
	{
		cout<<"fin du fils"<<endl;
		w->setNbEtud2(WEXITSTATUS(status));
	}
	
	if(pidFils == idF3)
	{
		cout<<"fin du fils"<<endl;
		w->setNbEtud3(WEXITSTATUS(status));
	}
	return;
}

#include "fctUtilesGerProcessus.cpp"
