#include "fenetreclient.h"
#include "ui_fenetreclient.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <signal.h>

#include "Fichier.ini"
#include "Ecran.h"

extern int idQ;
extern FenetreClient* w;

MESSAGE Message,MessageRecu;

void H(int Sig);

FenetreClient::FenetreClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetreClient)
{
 ui->setupUi(this);
     
}

FenetreClient::~FenetreClient()
{
    delete ui;
}

void FenetreClient::on_ButtonEmettre_clicked()
{
Trace("Dans on_ButtonEmettre_clicked");
char buff[255];
strcpy(buff,getMessageEmettre());
Message.Type = 1;
Message.Pid = getpid();
strcpy(Message.M,getMessageEmettre());


if(msgsnd(idQ,&Message,32,0) == -1)
{
	perror("Erreur lors de msgsnd");
	exit(1);
}

if(msgrcv(idQ,&MessageRecu,255,getpid(),0) == -1)
{
	perror("Erreur lors de msgrcv");
	exit(1);
}

setMessageRecu(MessageRecu.M);
setMessageEmettre("");
}

void FenetreClient::on_ButtonTerminer_clicked()
{
    Trace("Dans on_ButtonTerminer_clicked");

}

#include "fctUtiles.cpp"

void H(int Sig)
{
Trace("Reception du nsignal %d",Sig);
}
