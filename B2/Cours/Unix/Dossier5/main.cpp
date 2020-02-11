#include "fenetreclient.h"
#include <QApplication>
#include <QTextCodec>

#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>

#include "Fichier.ini"

int	idQ;
FenetreClient* w;

int main(int argc, char *argv[])
{

if((idQ = msgget(CLE,0)) == -1)
{
	perror("Error lors de msgget");
	exit(1);
}
QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));


QApplication a(argc, argv);
w = new FenetreClient;
w->show();

return a.exec();
}
