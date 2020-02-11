#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

#include "Couleur.h"
#include "PixelNG.h"
#include "Dimension.h"
#include "PixelB.h"
#include "PixelRGB.h"
#include "ImageNG.h"
#include "ImageRGB.h"
#include "ImageB.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();
void Essai7();
void Essai8();
void Essai9();
void Essai10();
void Essai11();
void Essai12();
void Essai13();

int main(int argc,char* argv[])
{
  int choix;
  bool fini = false;
  
  while(!fini)
  {
    if (argc == 2) { choix = atoi(argv[1]); fini = true; }
    else choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
      case 2 : Essai2(); break;
      case 3 : Essai3(); break;
      case 4 : Essai4(); break;
      case 5 : Essai5(); break;
      case 6 : Essai6(); break;
      case 7 : Essai7(); break;
      case 8 : Essai8(); break;
      case 9 : Essai9(); break;
      case 10 : Essai10(); break;
      case 11 : Essai11(); break;
      case 12 : Essai12(); break;
      case 13 : Essai13(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 6 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Tests de RGBException dans la classe Couleur" << endl;
  cout << " 2. Tests de RGBException dans la classe PixelNG" << endl;
  cout << " 3. Tests de XYException dans la classe Dimension" << endl;
  cout << " 4. Tests de XYException dans la classe PixelB" << endl;
  cout << " 5. Tests de XYException et RGBException dans la classe PixelNG" << endl;
  cout << " 6. Tests de XYException et RGBException dans la classe PixelRGB" << endl;
  cout << " 7. Tests de setBackground et set/getPixel dans la classe ImageNG" << endl;
  cout << " 8. Tests des operateurs (+ PixelNG) de la classe ImageNG" << endl;
  cout << " 9. Tests des operateurs - < > == de la classe ImageNG" << endl;
  cout << "10. Tests de set/getPixel dans la classe ImageRGB" << endl;
  cout << "11. Tests des operateurs (+ PixelRGB) de la classe ImageRGB" << endl;
  cout << "12. Tests de set/getPixel dans la classe ImageB" << endl;
  cout << "13. Tests des operateurs (+ PixelB) de la classe ImageB" << endl;
  cout << "14. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//**********************************************************************************************
// ATTENTION !!!!
// Les methodes de vos classes NE doivent PAS contenir de TRY{...} CATCH{...} mais
// uniquement des THROW !!! Donc, votre classe lance une exception (une erreur) mais
// ce n'est pas elle qui la traite. C'est l'application qui utilise votre classe
// qui doit traiter les exceptions. C'est donc uniquement dans le main (ou les fonctions appelees)
// que l'on trouve des try...catch 
//**********************************************************************************************
void Essai1()
{
  cout << "***** (1) Tests de RGBException dans la classe Couleur *********************" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // --> remplacer les ... par ce qu'il faut

  // ...
  {
    Couleur c;
    cout << "Couleur cree par defaut = " << c << endl;
    cout << "Modification de la couleur..." << endl;
    int val;
    cout << "Composante Rouge : "; cin >> val; cin.ignore();
    try
    {
      c.setRouge(val);
    }
    catch(RGBException & message)
    {
      cout << message.getMessage() << endl;
      cout << "valeur de la Composante : " << message.getValeur() << endl;
    }

    cout << "Composante Verte : "; cin >> val; cin.ignore();
    try
    {
      c.setVert(val);
    }
    catch(RGBException & message)
    {
      cout << message.getMessage() << endl;
      cout << "valeur de la Composante : " << message.getValeur() << endl;
    }

    cout << "Composante Bleue : "; cin >> val; cin.ignore();
    try
    {
      c.setBleu(val);
    }
    catch(RGBException & message)
    {
      cout << message.getMessage() << endl;
      cout << "valeur de la Composante : " << message.getValeur() << endl;
    }
    cout << "Couleur modifiee = " << c << endl << endl;

    int r,v,b;
    cout << "Creation d'une couleur..." << endl;
    cout << "Composante Rouge : "; cin >> r; cin.ignore();
    cout << "Composante Verte : "; cin >> v; cin.ignore();
    cout << "Composante Bleue : "; cin >> b; cin.ignore();
    Couleur c1(r,v,b);
    cout << "Couleur creee = " << c1 << endl << endl;

    cout << "Modification d'une couleur par saisie clavier..." << endl;
    cin >> c1;
    cout << "Couleur saisie : " << c1 << endl;
  }
  // ...
  
  cout << endl;
}

//**********************************************************************************************
void Essai2()
{
  cout << "***** (2) Tests de RGBException dans la classe PixelNG *****************************" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // --> remplacer les ... par ce qu'il faut

  // ...
  {
    PixelNG p;
    cout << "PixelNG cree par defaut = " << p << endl;
    cout << "Modification du niveau de gris du pixel..." << endl;
    int val;
    cout << "Nouvelle valeur : "; cin >> val; cin.ignore();
    try
    {
      p.setValeur(val);
    }
    catch(RGBException & message)
    {
      cout << message.getMessage() << endl;
      cout << "valeur du niveau de gris : " << message.getValeur() << endl;
    }

    cout << "PixelNG modifie = " << p << endl << endl;

    int x,y,v;
    cout << "Creation d'un PixelNG..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    cout << "Niveau de gris : "; cin >> v; cin.ignore();
    PixelNG p1(x,y,v);
    cout << "PixelNG cree = " << p1 << endl;
  }
  // ...
  
  cout << endl;
}

//**********************************************************************************************
void Essai3()
{
  cout << "***** (3) Tests de XYException dans la classe Dimension *********************" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // --> remplacer les ... par ce qu'il faut

  // ...
  {
    Dimension d;
    cout << "Dimension creee par defaut = " << d << endl;
    cout << "Modification de la dimension..." << endl;
    int val;
    cout << "Largeur : "; cin >> val; cin.ignore();
    try
    {
      d.setLargeur(val);
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }

    cout << "Hauteur : "; cin >> val; cin.ignore();
    try
    {
      d.setHauteur(val);
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }

    cout << "Dimension modifiee = " << d << endl << endl;

    int l,h;
    cout << "Creation d'une dimension..." << endl;
    cout << "Largeur : "; cin >> l; cin.ignore();
    cout << "Hauteur : "; cin >> h; cin.ignore();
    Dimension d1(l,h);
    cout << "Dimension creee = " << d1 << endl << endl;

    cout << "Modification d'une dimension par saisie clavier..." << endl;
    cin >> d1;
    cout << "Dimension saisie : " << d1 << endl;
  }
  
  cout << endl;
}

//**********************************************************************************************
void Essai4()
{
  cout << "***** (4) Tests de XYException dans la classe PixelB *********************" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // --> remplacer les ... par ce qu'il faut

  // ...
  {
    PixelB p;
    cout << "PixelB cree par defaut = " << p << endl;
    cout << "Modification de la position du pixel..." << endl;
    int val;
    cout << "x : "; cin >> val; cin.ignore();
    try
    {
      p.setX(val);
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }
    cout << "y : "; cin >> val; cin.ignore();
    
    try
    {
      p.setY(val);
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }
    cout << "PixelB modifie = " << p << endl << endl;

    int x,y;
    cout << "Creation d'un PixelB..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    PixelB p1(x,y,true);
    cout << "PixelB cree = " << p1 << endl << endl;
  }
  // ...
  
  cout << endl;
}

//**********************************************************************************************
void Essai5()
{
  cout << "***** (5) Tests de XYException et RGBException dans la classe PixelNG ******************" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // --> remplacer les ... par ce qu'il faut

  // ...
  {
    PixelNG p;
    cout << "PixelNG cree par defaut = " << p << endl;
    cout << "Modification du pixel..." << endl;
    int val;
    cout << "x : "; cin >> val; cin.ignore();
    try
    {
      p.setX(val);
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }
    
    cout << "y : "; cin >> val; cin.ignore();
    try
    {
      p.setY(val);
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }
    
    cout << "Niveau de gris : "; cin >> val; cin.ignore();
    try
    {
      p.setValeur(val);
    }
    catch(RGBException & message)
    {
      cout << message.getMessage() << endl;
      cout << "valeur du niveau de gris : " << message.getValeur() << endl;
    }
    cout << "PixelNG modifie = " << p << endl << endl;

    int x,y;
    cout << "Creation d'un PixelNG..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    cout << "Niveau de gris : "; cin >> val; cin.ignore();
    PixelNG p1(x,y,val);
    cout << "PixelNG cree = " << p1 << endl << endl;
  }
  // ...
  
  cout << endl;
}

//**********************************************************************************************
void Essai6()
{
  cout << "***** (6) Tests de XYException et RGBException dans la classe PixelRGB ******************" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // --> remplacer les ... par ce qu'il faut

  // ...
  {
    PixelRGB p;
    cout << "PixelNG cree par defaut = " << p << endl;
    cout << "Modification du pixel..." << endl;
    int val;
    cout << "x : "; cin >> val; cin.ignore();
    try
    {
      p.setX(val);
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }
    
    cout << "y : "; cin >> val; cin.ignore();
    try
    {
      p.setY(val);
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }
    Couleur c;
    cout << "Couleur : " << endl; cin >> c; cin.ignore();
    p.setValeur(c);

    cout << "PixelRGB modifie = " << p << endl << endl;

    int x,y;
    cout << "Creation d'un PixelRGB..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    cout << "Couleur : " << endl; cin >> c; cin.ignore();
    PixelRGB p1(x,y,c);
    cout << "PixelRGB cree = " << p1 << endl << endl;
  }
  // ...
  
  cout << endl;
}

//**********************************************************************************************
void Essai7()
{
  cout << "***** (7) Tests de setBackground et set/getPixel dans la classe ImageNG ******************" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // --> remplacer les ... par ce qu'il faut

  // ...
  {
    ImageNG im;
    cout << "ImageNG creee par defaut :" << endl << im << endl;
    cout << "test" << endl;
    im.Dessine();
    cout << "test" << endl;
    int val;
    cout << "Nouveau fond : "; cin >> val; cin.ignore();
    im.setBackground(val);
    
    cout << "Image modifiee :" << endl << im << endl; im.Dessine();

    int x,y;
    cout << "Dessin d'un pixel..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    cout << "Niveau de gris : "; cin >> val; cin.ignore();
    try
    {
      im.setPixel(x,y,val);
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }
    catch(RGBException & message)
    {
      cout << message.getMessage() << endl;
      cout << "valeur du niveau de gris : " << message.getValeur() << endl;
      exit(1);
    }

    cout << "Image modifiee :" << endl << im << endl; im.Dessine();

    cout << "Recuperation valeur d'un pixel..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    cout << "Valeur en (" << x << "," << y << ") = ";
    try
    {
      cout << im.getPixel(x,y) << endl << endl;
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }
    
  }
  // ...
  
  cout << endl;
}

//**********************************************************************************************
void Essai8()
{
  cout << "***** (8) Tests des operateurs (+ PixelNG) de la classe ImageNG ******************" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // --> remplacer les ... par ce qu'il faut

  // ...
  {
    ImageNG im;
    cout << "ImageNG creee par defaut :" << endl;
    cout << "On change le fond sur 40..." << endl;
    im.setBackground(40);
    cout << "Image :" << endl << im << endl; im.Dessine();

    int x,y;
    cout << "Dessin d'un pixel..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    im = im + PixelNG(x,y,200);
    cout << "Image modifiee :" << endl << im << endl; im.Dessine();

    cout << "Dessin d'un autre pixel..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    im = PixelNG(x,y,200) + im;
    cout << "Image modifiee :" << endl << im << endl; im.Dessine();
  }
  // ...
  
  cout << endl;
}

//**********************************************************************************************
void Essai9()
{
  cout << "***** (9) Tests des operateurs - < > == de la classe ImageNG ******************" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // --> remplacer les ... par ce qu'il faut

  // ...
  {
    ImageNG im1,im2;
    cout << "Choisissez deux images parmi " << endl;
    cout << "  a) joconde.bmp" << endl;
    cout << "  b) lena.bmp" << endl;
    cout << "  c) bulles.bmp" << endl;
    char ch;
    cout << "Image 1 : "; cin >> ch; cin.ignore();
    switch(ch)
    {
       case 'a' : im1.importFromBMP("../images/joconde.bmp"); break;
       case 'b' : im1.importFromBMP("../images/lena.bmp"); break;
       default : im1.importFromBMP("../images/bulles.bmp"); break; 
    }
    cout << "Image 2 : "; cin >> ch; cin.ignore();
    switch(ch)
    {
       case 'a' : im2.importFromBMP("../images/joconde.bmp"); break;
       case 'b' : im2.importFromBMP("../images/lena.bmp"); break;
       default : im2.importFromBMP("../images/bulles.bmp"); break; 
    } 
    cout << "Voici image 1 :" << endl << im1 << endl; im1.Dessine();
    cout << "Voici image 2 :" << endl << im2 << endl; im2.Dessine();

    cout << "Comparaison (c) ou difference (d) ? "; cin >> ch; cin.ignore();

    if (ch == 'c')
    {
      ImageNG::setComparaison(ImageNG::PIXEL_A_PIXEL);
      cout << "Comparaison pixel a pixel des deux images..." << endl;
    
      try
      {
        if (im1 < im2)
        {
          cout << "image1 < image2" << endl;
        }      
        else
        { 
          if (im1 > im2)
          {
            cout << "image1 > image2" << endl;
          }
          else
          { 
            if (im1 ==  im2)
            { 
              cout << "image1 ==  image2" << endl;
            }
            else
            {
              cout << "Aucune des 3 possibilités" << endl;
            }
          }
        } 
      }
      catch(XYException &message)
      {
        cout << message.getMessage() << endl;
        cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
      }     
    }
    else
    {
      cout << "Difference des deux images..." << endl;
      try
      {
        ImageNG im = im1 - im2;
        cout << "Voici l'image resultat :" << endl << im << endl; im.Dessine();
      }
      catch(XYException &message)
      {
        cout << message.getMessage() << endl;
        cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
      }
      
    }
  }
  // ...
  
  cout << endl;
}

//**********************************************************************************************
void Essai10()
{
  cout << "***** (10) Tests de set/getPixel dans la classe ImageRGB *************************" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // --> remplacer les ... par ce qu'il faut

  // ...
  {
    ImageRGB im;
    cout << "ImageRGB creee par defaut :" << endl;
    cout << "On modifie la couleur du fond..." << endl;
    im.setBackground(Couleur(0,255,255));
    cout << "Image modifiee :" << endl << im << endl; im.Dessine();

    int x,y;
    cout << "Dessin d'un pixel..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    try
    {
      im.setPixel(x,y,Couleur(255,0,0));
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }
    cout << "Image modifiee :" << endl << im << endl; im.Dessine();

    cout << "Recuperation valeur d'un pixel..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    try
    {
      cout << "Valeur en (" << x << "," << y << ") = " << im.getPixel(x,y) << endl << endl;
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }
  }
  // ...
  
  cout << endl;
}

//**********************************************************************************************
void Essai11()
{
  cout << "***** (11) Tests des operateurs (+ PixelRGB) de la classe ImageRGB ******************" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // --> remplacer les ... par ce qu'il faut

  // ...
  {
    ImageRGB im;
    cout << "ImageRGB creee par defaut :" << endl;
    cout << "On change la couleur du fond..." << endl;
    im.setBackground(Couleur(255,255,0));
    cout << "Image :" << endl << im << endl; im.Dessine();

    int x,y;
    cout << "Dessin d'un pixel..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    im = im + PixelRGB(x,y,Couleur(0,0,255));
    cout << "Image modifiee :" << endl << im << endl; im.Dessine();

    cout << "Dessin d'un autre pixel..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    im = PixelRGB(x,y,Couleur(0,0,255)) + im;
    cout << "Image modifiee :" << endl << im << endl; im.Dessine();
  }
  // ...
  
  cout << endl;
}

//**********************************************************************************************
void Essai12()
{
  cout << "***** (12) Tests de set/getPixel dans la classe ImageB ***************************" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // --> remplacer les ... par ce qu'il faut

  // ...
  {
    ImageB im;
    cout << "ImageB creee par defaut :" << endl << im << endl; im.Dessine();

    int x,y;
    cout << "Dessin d'un pixel..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    try
    {
      im.setPixel(x,y,true);
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }
    cout << "Image modifiee :" << endl << im << endl; im.Dessine();

    cout << "Recuperation valeur d'un pixel..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    try
    {
      cout << "Valeur en (" << x << "," << y << ") = " << im.getPixel(x,y) << endl << endl;
    }
    catch(XYException &message)
    {
      cout << message.getMessage() << endl;
      cout << "axe (x = largeur, y = hauteur, d = au 2) : " << message.getAxe() << endl;
    }
  }
  // ...
  
  cout << endl;
}

//**********************************************************************************************
void Essai13()
{
  cout << "***** (13) Tests des operateurs (+ PixelB) de la classe ImageB **********************" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // --> remplacer les ... par ce qu'il faut

  // ...
  {
    ImageB im;
    cout << "ImageB creee par defaut :" << endl << im << endl; im.Dessine();

    int x,y;
    cout << "Dessin d'un pixel..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    im = im + PixelB(x,y,true);
    cout << "Image modifiee :" << endl << im << endl; im.Dessine();

    cout << "Dessin d'un autre pixel..." << endl;
    cout << "x : "; cin >> x; cin.ignore();
    cout << "y : "; cin >> y; cin.ignore();
    im = PixelB(x,y,true) + im;
    cout << "Image modifiee :" << endl << im << endl; im.Dessine();
  }
  // ...
  
  cout << endl;
}


