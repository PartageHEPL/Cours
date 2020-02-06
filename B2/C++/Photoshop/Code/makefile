 ##g++ -o app main.cpp Couleur.cpp Dimension.cpp Image.cpp ImageNG.cpp ImageRGB.cpp ImageB.cpp Pixel.cpp PixelNG.cpp PixelRGB.cpp PixelB.cpp BaseException.cpp RGBException.cpp XYException.cpp MoteurException.cpp ListeBase.cpp Liste.cpp ListeTriee.cpp Traitements.cpp Iterateur.cpp Moteur.cpp UI.cpp Utils.cpp ./WindowSDL/WindowSDL.cpp ./WindowSDL/WindowSDLclick.cpp ./WindowSDL/WindowSDLexception.cpp ./WindowSDL/WindowSDLimage.cpp -Wall -lpthread -lSDL -I./WindowSDL/ -I./JeuxDeTest/ -I./

.SILENT:

FICHIERS = Couleur.o Dimension.o Image.o ImageNG.o ImageRGB.o ImageB.o Pixel.o PixelNG.o PixelRGB.o PixelB.o BaseException.o RGBException.o XYException.o MoteurException.o ListeBase.o Liste.o ListeTriee.o Traitements.o Iterateur.o Moteur.o UI.o Utils.o $(SDL)
INCLUDE_ALL = -Wall -D SUN  -I./WindowSDL/ -I./ -lpthread -lSDL #-D DEBUG -D DEBUGALL 
EMPLACEMENT_TEST = ./JeuxDeTest/
SDL = WindowSDL.o WindowSDLclick.o WindowSDLexception.o WindowSDLimage.o
GPP = g++ -m64

all: app Test1 Test2 Test3 Test4 Test5 Test6 Test8 Test9 Test10

app: $(FICHIERS) main.o
	echo Creation de app
	$(GPP) $(FICHIERS) main.o -lpthread -lSDL -o app $(INCLUDE_ALL)

main.o: main.cpp Moteur.o UI.o $(SDL)
	echo Creation de main.o
	$(GPP) -c main.cpp -o main.o $(INCLUDE_ALL)

Couleur.o: Couleur.cpp Couleur.h RGBException.o Utils.o $(SDL)
	echo Creation de Couleur.o
	$(GPP) -c Couleur.cpp -o Couleur.o $(INCLUDE_ALL)

Dimension.o: Dimension.cpp Dimension.h XYException.o Utils.o $(SDL)
	echo Creation de Dimension.o
	$(GPP) -c Dimension.cpp -o Dimension.o $(INCLUDE_ALL)

Image.o: Image.cpp Image.h  Utils.o $(SDL)
	echo Creation de Image.o
	$(GPP) -c Image.cpp -o Image.o $(INCLUDE_ALL)

ImageNG.o: ImageNG.cpp ImageNG.h Dimension.o Image.o XYException.o Utils.o $(SDL)
	echo Creation de ImageNG.o
	$(GPP) -c ImageNG.cpp -o ImageNG.o $(INCLUDE_ALL)

ImageRGB.o: ImageRGB.cpp ImageRGB.h Dimension.o Image.o XYException.o Utils.o $(SDL)
	echo Creation de ImageRGB.o
	$(GPP) -c ImageRGB.cpp -o ImageRGB.o $(INCLUDE_ALL)

ImageB.o: ImageB.cpp ImageB.h Dimension.o Image.o XYException.o Utils.o $(SDL)
	echo Creation de ImageB.o
	$(GPP) -c ImageB.cpp -o ImageB.o $(INCLUDE_ALL)

Pixel.o: Pixel.cpp Pixel.h XYException.o Utils.o $(SDL)
	echo Creation de Pixel.o
	$(GPP) -c Pixel.cpp -o Pixel.o $(INCLUDE_ALL)
	
PixelNG.o: PixelNG.cpp PixelNG.h Pixel.o RGBException.o Utils.o $(SDL)
	echo Creation de PixelNG.o
	$(GPP) -c PixelNG.cpp -o PixelNG.o $(INCLUDE_ALL)

PixelRGB.o: PixelRGB.cpp PixelRGB.h Pixel.o Couleur.o RGBException.o Utils.o $(SDL)
	echo Creation de PixelRGB.o
	$(GPP) -c PixelRGB.cpp -o PixelRGB.o $(INCLUDE_ALL)
	
PixelB.o: PixelB.cpp PixelB.h Pixel.o Utils.o $(SDL)
	echo Creation de PixelB.o
	$(GPP) -c PixelB.cpp -o PixelB.o $(INCLUDE_ALL)

BaseException.o: BaseException.cpp BaseException.cpp Utils.o $(SDL)
	echo Creation de BaseException.o
	$(GPP) -c BaseException.cpp -o BaseException.o $(INCLUDE_ALL)
	
RGBException.o: RGBException.cpp RGBException.h BaseException.o Utils.o $(SDL)
	echo Creation de RGBException.o
	$(GPP) -c RGBException.cpp -o RGBException.o $(INCLUDE_ALL)
	
XYException.o: XYException.cpp XYException.h BaseException.o Utils.o $(SDL)
	echo Creation de XYException.o
	$(GPP) -c XYException.cpp -o XYException.o $(INCLUDE_ALL)

MoteurException.o: MoteurException.cpp MoteurException.h BaseException.o Utils.o $(SDL)
	echo Creation de MoteurException.o
	$(GPP) -c MoteurException.cpp -o MoteurException.o $(INCLUDE_ALL) 

ListeBase.o: ListeBase.cpp ListeBase.h Utils.o $(SDL)
	echo Creation de ListeBase.o
	$(GPP) -c ListeBase.cpp -o ListeBase.o $(INCLUDE_ALL)

Liste.o: Liste.cpp Liste.h ListeBase.o Cellule.h Couleur.o Image.o ImageNG.o ImageRGB.o ImageB.o Utils.o $(SDL)
	echo Creation de Liste.o
	$(GPP) -c Liste.cpp -o Liste.o $(INCLUDE_ALL)

ListeTriee.o: ListeTriee.cpp ListeTriee.h ListeBase.o Cellule.h ImageNG.o Utils.o $(SDL)
	echo Creation de ListeTriee.o
	$(GPP) -c ListeTriee.cpp -o ListeTriee.o $(INCLUDE_ALL)

Iterateur.o: Iterateur.cpp Iterateur.h ListeBase.o Cellule.h Couleur.o Image.o ImageNG.o ImageRGB.o ImageB.o Utils.o $(SDL)
	echo Creation de Iterateur.o
	$(GPP) -c Iterateur.cpp -o Iterateur.o $(INCLUDE_ALL)

Traitements.o: Traitements.cpp Traitements.h Pixel.o Image.o ImageNG.o ImageRGB.o ImageB.o XYException.o Iterateur.o ListeTriee.o ListeBase.o Utils.o $(SDL)
	echo Creation de Traitements.o
	$(GPP) -c Traitements.cpp -o Traitements.o $(INCLUDE_ALL)

Moteur.o: Moteur.cpp Moteur.h Image.o ImageNG.o ImageRGB.o ImageB.o Iterateur.o MoteurException.o Traitements.o Utils.o $(SDL)
	echo Creation de Moteur.o
	$(GPP) -c Moteur.cpp -o Moteur.o $(INCLUDE_ALL)

UI.o: UI.cpp UI.h Moteur.o MoteurException.o Utils.o $(SDL)
	echo Creation de UI.o
	$(GPP) -c UI.cpp -o UI.o $(INCLUDE_ALL)

Utils.o: Utils.cpp Utils.h $(SDL)
	echo Creation de Utils.o
	$(GPP) -c Utils.cpp -o Utils.o $(INCLUDE_ALL)

WindowSDL.o:
	echo Creation de WindowSDL.o
	$(GPP) -c WindowSDL.cpp -o WindowSDL.o $(INCLUDE_ALL)
WindowSDLclick.o:
	echo Creation de WindowSDLclick.o
	$(GPP) -c WindowSDLclick.cpp -o WindowSDLclick.o $(INCLUDE_ALL)
WindowSDLexception.o:
	echo Creation de WindowSDLexception.o
	$(GPP) -c WindowSDLexception.cpp -o WindowSDLexception.o $(INCLUDE_ALL)
WindowSDLimage.o:
	echo Creation de WindowSDLimage.o
	$(GPP) -c WindowSDLimage.cpp -o WindowSDLimage.o $(INCLUDE_ALL)

Test1.o: $(EMPLACEMENT_TEST)Test1.cpp $(FICHIERS)
	echo Creation de Test1.o
	$(GPP) -c $(EMPLACEMENT_TEST)Test1.cpp -o Test1.o -Wall -D SUN  -I./WindowSDL/ -I./

Test2.o: $(EMPLACEMENT_TEST)Test2.cpp $(FICHIERS)
	echo Creation de Test2.o
	$(GPP) -c $(EMPLACEMENT_TEST)Test2.cpp -o Test2.o -Wall -D SUN  -I./WindowSDL/ -I./

Test3.o: $(EMPLACEMENT_TEST)Test3.cpp $(FICHIERS)
	echo Creation de Test3.o
	$(GPP) -c $(EMPLACEMENT_TEST)Test3.cpp -o Test3.o -Wall -D SUN  -I./WindowSDL/ -I./
	
Test4.o: $(EMPLACEMENT_TEST)Test4.cpp $(FICHIERS)
	echo Creation de Test4.o
	$(GPP) -c $(EMPLACEMENT_TEST)Test4.cpp -o Test4.o -Wall -D SUN  -I./WindowSDL/ -I./
	
Test5.o: $(EMPLACEMENT_TEST)Test5.cpp $(FICHIERS)
	echo Creation de Test5.o
	$(GPP) -c $(EMPLACEMENT_TEST)Test5.cpp -o Test5.o -Wall -D SUN  -I./WindowSDL/ -I./
	
Test6.o: $(EMPLACEMENT_TEST)Test6.cpp $(FICHIERS)
	echo Creation de Test6.o
	$(GPP) -c $(EMPLACEMENT_TEST)Test6.cpp -o Test6.o -Wall -D SUN  -I./WindowSDL/ -I./
	
Test7.o: $(EMPLACEMENT_TEST)Test7.cpp $(FICHIERS)
	echo Creation de Test7.o
	$(GPP) -c $(EMPLACEMENT_TEST)Test7.cpp -o Test7.o -Wall -D SUN  -I./WindowSDL/ -I./
	
Test8.o: $(EMPLACEMENT_TEST)Test8.cpp $(FICHIERS)
	echo Creation de Test8.o
	$(GPP) -c $(EMPLACEMENT_TEST)Test8.cpp -o Test8.o -Wall -D SUN  -I./WindowSDL/ -I./

Test9.o: $(EMPLACEMENT_TEST)Test9.cpp $(FICHIERS)
	echo Creation de Test9.o
	$(GPP) -c $(EMPLACEMENT_TEST)Test9.cpp -o Test9.o -Wall -D SUN  -I./WindowSDL/ -I./

Test10.o: $(EMPLACEMENT_TEST)Test10.cpp $(FICHIERS)
	echo Creation de Test10.o
	$(GPP) -c $(EMPLACEMENT_TEST)Test10.cpp -o Test10.o  -Wall -D SUN  -I./WindowSDL/ -I./

Test1: Test1.o $(FICHIERS)
	echo Creation de Test1
	$(GPP) -o Test1 Test1.o -lpthread -lSDL $(FICHIERS) -Wall -D SUN  -I./WindowSDL/ -I./

Test2: Test2.o  $(FICHIERS)
	echo Creation de Test2
	$(GPP) -o Test2 Test2.o -lpthread -lSDL $(FICHIERS) -Wall -D SUN  -I./WindowSDL/ -I./

Test3: Test3.o  $(FICHIERS)
	echo Creation de Test3
	$(GPP) -o Test3 Test3.o -lpthread -lSDL $(FICHIERS) -Wall -D SUN  -I./WindowSDL/ -I./

Test4: Test4.o  $(FICHIERS)
	echo Creation de Test4
	$(GPP) -o Test4 Test4.o -lpthread -lSDL $(FICHIERS) -Wall -D SUN  -I./WindowSDL/ -I./

Test5: Test5.o  $(FICHIERS)
	echo Creation de Test5
	$(GPP) -o Test5 Test5.o -lpthread -lSDL $(FICHIERS) -Wall -D SUN  -I./WindowSDL/ -I./

Test6: Test6.o  $(FICHIERS)
	echo Creation de Test6
	$(GPP) -o Test6 Test6.o -lpthread -lSDL $(FICHIERS) -Wall -D SUN  -I./WindowSDL/ -I./

#Test7: Test7.o  $(FICHIERS)
#	echo Creation de Test7
#	$(GPP) -o Test7 Test7.o -lpthread -lSDL $(FICHIERS) -Wall -D SUN  -I./WindowSDL/ -I./

Test8: Test8.o  $(FICHIERS)
	echo Creation de Test8
	$(GPP) -o Test8 Test8.o -lpthread -lSDL $(FICHIERS) -Wall -D SUN  -I./WindowSDL/ -I./

Test9: Test9.o  $(FICHIERS)
	echo Creation de Test9
	$(GPP) -o Test9 Test9.o -lpthread -lSDL $(FICHIERS) -Wall -D SUN  -I./WindowSDL/ -I./

Test10: Test10.o  $(FICHIERS)
	echo Creation de Test10
	$(GPP) -o Test10 Test10.o -lpthread -lSDL $(FICHIERS) -Wall -D SUN  -I./WindowSDL/ -I./

clean:
	echo Nettoyage effectué!
	rm -rf *.o

