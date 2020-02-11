#include "MainListeEtudiants2019.h"
#include "ui_MainListeEtudiants2019.h"

#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

#include "Ecran.h"

MainListeEtudiants2019::MainListeEtudiants2019(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainListeEtudiants2019)
{
Trace("Debut de l'appic.");
ui->setupUi(this);
struct sigaction Act;
Act.sa_handler = SIG_DFL;
sigaction(SIGCHLD,&Act,NULL);
}

MainListeEtudiants2019::~MainListeEtudiants2019()
{
delete ui;
}

void MainListeEtudiants2019::on_ButtonOk_clicked()
{
Trace("Dans Ok.");
Trace("Groupe 1 : %s",getGroupe1());
Trace("Groupe 2 : %s",getGroupe2());
Trace("Groupe 3 : %s",getGroupe3());
int status;
int idfils1 = fork();
if(idfils1 == 0)
{
	//On est dans le fils
	execl("Lect","Lect",getGroupe1(),(char *)NULL);
	perror("Erreur de exec");
	exit(5);
}
//On estdans le pere
int idfils2 = fork();
if(idfils2 == 0)
{
	//On est dans le fils
	execl("Lect","Lect",getGroupe2(),(char *)NULL);
	perror("Erreur de exec");
	exit(5);
}
int idfils3 = fork();
if(idfils3 == 0)
{
	//On est dans le fils
	execl("Lect","Lect",getGroupe3(),(char *)NULL);
	perror("Erreur de exec");
	exit(5);
}

for(int i = 0; i < 3; i++)
{
	int temp = wait(&status);
	if(temp == idfils1)
	setNbEtud1(WEXITSTATUS(status));
	if(temp == idfils2)
	setNbEtud2(WEXITSTATUS(status));
	if(temp == idfils3)
	setNbEtud3(WEXITSTATUS(status));
}	

}


void MainListeEtudiants2019::on_ButtonEffacer_clicked()
{
Trace("Dans Effacer.");
setGroupe1("");
setNbEtud1(-1);
// ...
}

void MainListeEtudiants2019::on_ButtonTerminer_clicked()
{
Trace("Dans Terminer.");
exit(0);
}

#include "fctUtiles.cpp"
