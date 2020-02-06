#include "Utils.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void Debug(const char* message)
{
	#ifdef DEBUG
	cout << message << endl;
	#endif
}

void Pause(void)
{
	cout << "Appuyer sur un touche pour continuer...";
	getchar();
}
