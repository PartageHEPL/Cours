#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mysql.h>
#include <string.h>
#include <iostream>
using namespace  std;
MYSQL			*Connexion;
MYSQL_RES	*Resultat;
MYSQL_ROW	Ligne;

#include "Ecran.h"

int main(int argc,char*argv[])
{
cout << "test1" << endl;
Trace("Debut pour le groupe %s",argv[1]);
int Cpt = 0;
char 	Buff[255];
if (argc != 2) 
	{
	printf("Err.: Trop ou trop peu d\'argument(s)...\n");
	exit(1);
	}
cout << "test2" << endl;
Connexion = mysql_init(NULL);
cout << "test3" << endl;
mysql_real_connect(Connexion,"localhost","student","PassStudent","PourStudent",0,0,0);
cout << "test4" << endl;
sprintf(Buff,"select count(*) from Bd2019 where Groupe = '%s'",argv[1]);
cout << "test5" << endl;
mysql_query(Connexion,Buff);
cout << "test6" << endl;
Resultat = mysql_store_result(Connexion);
cout << "test7" << endl;
Ligne = mysql_fetch_row(Resultat);
cout << "test8" << endl;
Trace("(%d) sort du  fichier %s  (%d)",getpid(),argv[1],atoi(Ligne[0]));
cout << "test9" << endl;
exit(atoi(Ligne[0]));
}
