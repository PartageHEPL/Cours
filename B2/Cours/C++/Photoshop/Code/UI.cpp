#include "UI.h"
#include "Utils.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

UI::UI(Moteur *pMoteur)
{
	Debug("[UI]Constructeur(pMoteur)");
	if(pMoteur == NULL)
	{
		cout << "[UI]pMoteur == NULL" << endl;;
	}
	else
	{
		moteur = pMoteur;
	}
}

UI::~UI(void)
{
	Debug("[UI]Destructeur");
}

void UI::Menu(void)
{
	Debug("[UI][Menu]");
	moteur->Affiche();
	cout << endl;

	//Afficher le menu
	cout << "╔══════════════════════════════════════ Menu General ══════════════════════════════════════╗" << endl;
	cout << "║  0. Quitter                                                                              ║" << endl;
	cout << "║  1. Visualiser une image et ses caracteristiques                                         ║" << endl;
	cout << "║  2. Visualiser deux images simultanement                                                 ║" << endl;
	cout << "║  3. Importer un ensemble d'images a partir d'un fichier csv                              ║" << endl;
	cout << "║  4. Exporter vers BMP                                                                    ║" << endl;
	cout << "║  5. Supprimer une image                                                                  ║" << endl;
	cout << "╠══════════════════════════════════════ Menu ImageNG ══════════════════════════════════════╣" << endl;
	cout << "║  6. Importer une ImageNG                                                                 ║" << endl;
	cout << "║  7. Augmenter la luminosite                                                              ║" << endl;
	cout << "║  8. Diminuer la luminosite                                                               ║" << endl;
	cout << "║  9. Soustraire deux images                                                               ║" << endl;
	cout << "║ 10. Seuillage                                                                            ║" << endl;
	cout << "║ 11. Filtre moyenneur                                                                     ║" << endl;
	cout << "║ 12. Filtre median                                                                        ║" << endl;
	cout << "║ 13. Erosion                                                                              ║" << endl;
	cout << "║ 14. Dilatation                                                                           ║" << endl;
	cout << "║ 15. Negatif                                                                              ║" << endl;
	cout << "╠══════════════════════════════════════ Menu ImageRGB ═════════════════════════════════════╣" << endl;
	cout << "║ 16. Importer une ImageRGB                                                                ║" << endl;
	cout << "╠═══════════════════════════════════════ Menu ImageB ══════════════════════════════════════╣" << endl;
	cout << "║ 17. Changer les couleurs des booleens                                                    ║" << endl;
	cout << "╚══════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
}

void UI::Start(void)
{
	Debug("[UI][Start]");
	int continuer = 1;
	int choixMenu = -1;
	int id1 = -1;
	int id2 = -1;
	int val = -1;
	int seuil = -1;
	int tailleFiltre = -1;
	char vecTemp[255];

	while(continuer)
	{
		choixMenu = -1;
		while(choixMenu < 0 || choixMenu > 17)
		{
			system("clear");
			Menu();
			cout << "Choix: ";
			cin >> choixMenu;
			cin.ignore();
		}
		
		id1 = -1;
		id2 = -1;
		val = -1;
		seuil = -1;
		tailleFiltre = -1;
		strcpy(vecTemp,"");
		switch(choixMenu)
		{
			case 0:
				exit(0);
				continuer = 0;
				break;
			case 1:
				while(id1 < 0)
				{
					cout << "Entre l'id: ";
					cin >> id1;
					cin.ignore();
				}
				moteur->VisualiseImage(id1);
				break;
			case 2:
				while(id1 < 0)
				{
					cout << "Entre l'id1: ";
					cin >> id1;
					cin.ignore();
				}
				while(id2 < 0)
				{
					cout << "Entre l'id2: ";
					cin >> id2;
					cin.ignore();
				}
				try
				{
					moteur->VisualiseImage(id1,id2);
				}
				catch(MoteurException& exception)
				{
					cout << exception.getMessage() << endl;
				}
				
				Pause();
				break;
			case 3:
				cout << "pas encore fait" << endl;
				break;
			case 4:
				while(id1 < 0)
				{
					cout << "Entre l'id: ";
					cin >> id1;
				}
				while(strlen(vecTemp) == 0)
				{
					cout << "Entre le nom du fichier: ";
					cin >> vecTemp;
					cin.ignore();
				}
				moteur->ExporterBMP(id1,vecTemp);
				break;
			case 5:
				while(id1 < 0)
				{
					cout << "Entre l'id: ";
					cin >> id1;
					cin.ignore();
				}
				moteur->SupprimerImage(id1);
				break;
			case 6:
				while(strlen(vecTemp) == 0)
				{
					cout << "Entre le nom de l'image a importer: ";
					cin >> vecTemp;
					cin.ignore();
				}
				if(moteur->ImporteImageNG(vecTemp) <= 0)
				{
					cout << "Erreur: Le nom de l'image n'est pas correcte ou n'a pas ete trouve!" << endl;
					//Debug("Erreur: Le nom de l'image n'est pas correcte ou n'a pas ete trouve!");
				}
				
				break;
			case 7:
				while(id1 < 0)
				{
					cout << "Entre l'id: ";
					cin >> id1;
					cin.ignore();
				}
				while(val < 0)
				{
					cout << "Valeur: ";
					cin >> val;
					cin.ignore();
				}
				moteur->AugmenteLuminosite(id1,val);
				break;
			case 8:
				while(id1 < 0)
				{
					cout << "Entre l'id: ";
					cin >> id1;
					cin.ignore();
				}
				while(val < 0)
				{
					cout << "Valeur: ";
					cin >> val;
					cin.ignore();
				}
				moteur->DiminueLuminosite(id1,val);
				break;
			case 9:
				while(id1 < 0)
				{
					cout << "Entre l'id1: ";
					cin >> id1;
					cin.ignore();
				}
				while(id2 < 0)
				{
					cout << "Entre l'id2: ";
					cin >> id2;
					cin.ignore();
				}
				moteur->Soustraire(id1,id2);
				break;
			case 10:
				while(id1 < 0)
				{
					cout << "Entre l'id: ";
					cin >> id1;
					cin.ignore();
				}
				while(seuil < 0)
				{
					cout << "Seuil: ";
					cin >> seuil;
					cin.ignore();
				}
				moteur->Seuillage(id1,seuil);
				break;
			case 11:
				while(id1 < 0)
				{
					cout << "Entre l'id: ";
					cin >> id1;
					cin.ignore();
				}
				while(tailleFiltre < 0 && tailleFiltre%2 != 0)
				{
					cout << "Taille du Filtre: ";
					cin >> tailleFiltre;
					cin.ignore();
				}
				moteur->FiltreMoyenneur(id1,tailleFiltre);
				break;
			case 12:
				while(id1 < 0)
				{
					cout << "Entre l'id: ";
					cin >> id1;
					cin.ignore();
				}
				while(tailleFiltre < 0 && tailleFiltre%2 != 0)
				{
					cout << "Taille du Filtre: ";
					cin >> tailleFiltre;
					cin.ignore();
				}
				moteur->FiltreMedian(id1,tailleFiltre);
				break;
			case 13:
				while(id1 < 0)
				{
					cout << "Entre l'id: ";
					cin >> id1;
					cin.ignore();
				}
				while(tailleFiltre < 0 && tailleFiltre%2 != 0)
				{
					cout << "Taille du Filtre: ";
					cin >> tailleFiltre;
					cin.ignore();
				}
				moteur->Erosion(id1,tailleFiltre);
				break;
			case 14:
				while(id1 < 0)
				{
					cout << "Entre l'id: ";
					cin >> id1;
					cin.ignore();
				}
				while(tailleFiltre < 0 && tailleFiltre%2 != 0)
				{
					cout << "Taille du Filtre: ";
					cin >> tailleFiltre;
					cin.ignore();
				}
				moteur->Dilatation(id1,tailleFiltre);
				break;
			case 15:
				while(id1 < 0)
				{
					cout << "Entre l'id: ";
					cin >> id1;
					cin.ignore();
				}
				moteur->Negatif(id1);
				break;
			case 16:
				while(id1 < 0)
				{
					cout << "Entre l'id: ";
					cin >> id1;
					cin.ignore();
				}
				while(strlen(vecTemp) == 0)
				{
					cout << "Entre le nom de l'image a importer: ";
					cin >> vecTemp;
					cin.ignore();
				}
				if(moteur->ImporteImageRGB(vecTemp) <= 0)
				{
					cout << "Erreur: Le nom de l'image n'est pas correcte ou n'a pas ete trouve!" << endl;
				}
				break;
			case 17:
				//A finir
				break;
			default:
				cout << "[UI][Start]Switch case menu = default" << endl;
		}
	}
}
