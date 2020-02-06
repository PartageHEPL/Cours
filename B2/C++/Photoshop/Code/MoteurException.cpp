#include "MoteurException.h"
#include "Utils.h"

MoteurException::MoteurException(void) : BaseException()
{
	Debug("[MoteurException][Constructeur]void");
}

MoteurException::MoteurException(const char* newMessage) : BaseException(newMessage)
{
	Debug("[MoteurException][Constructeur]newMessage");
}

MoteurException::~MoteurException(void)
{
	Debug("[MoteurException][Destructeur]void");
}