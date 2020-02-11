#include "traitementfichier.h"
#include "ui_traitementfichier.h"

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <mysql.h>
#include <iostream>
using namespace std;

#include "Ecran.h"
MYSQL			*Connexion;
MYSQL_RES	*Resultat;
MYSQL_ROW	Ligne;

FILE*	hfFich;
extern TraitementFichier* w;
extern char Nom[];
extern int Colonne;
extern int	idGrp;

void HandlerAlarm(int);
void HandlerSIGUSER1(int);

TraitementFichier::TraitementFichier(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TraitementFichier)
{
ui->setupUi(this);
char		Buff[80];
this->move(800,Colonne);
ui->lineEdit->setText(Nom);

struct sigaction Act;
Act.sa_handler = SIG_IGN;
sigemptyset(&Act.sa_mask);
Act.sa_flags = 0;
sigaction(SIGCHLD,&Act,NULL);
Act.sa_handler = HandlerAlarm;
sigemptyset(&Act.sa_mask);
Act.sa_flags = 0;
sigaction(SIGALRM,&Act,NULL);
 
Connexion = mysql_init(NULL);
mysql_real_connect(Connexion,"localhost","student",
"PassStudent","PourStudent",0,0,0);
sprintf(Buff,"select * from Bd2019 where Groupe='%s' order by Nom;",Nom);
mysql_query(Connexion,Buff),
Resultat = mysql_store_result(Connexion);
Trace("on commence");
alarm(1); 

}

TraitementFichier::~TraitementFichier()
{
delete ui;
}

int Cpt = 0;

void HandlerAlarm(int Sig)
{
Trace("Dans HandlerAlarm (%d)",Sig);
cout << "Cpt: " << Cpt << endl;
if((Ligne = mysql_fetch_row(Resultat)) == NULL)
{
	exit(Cpt);
}
Cpt++;
w->AffTraitementEnCours(Ligne[1]);
w->AffNumeroTraitement(Cpt);
alarm(1);
}

void HandlerSIGUSER1(int)
{
	exit(Cpt);
}

#include "fctUtilesTraitement.cpp"
