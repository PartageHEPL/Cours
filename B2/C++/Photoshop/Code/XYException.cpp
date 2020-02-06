#include "XYException.h"
#include "Utils.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

XYException::XYException(void) : BaseException()
{
	Debug("[XYException][Constructeur]void");
}

XYException::XYException(char newAxe) : BaseException()
{
	Debug("[XYException][Constructeur]newAxe");
	this->setAxe(newAxe);
}

XYException::XYException(char newAxe,const char* newMessage) : BaseException(newMessage)
{
	Debug("[XYException][Constructeur]newAxe,newMessage");
	this->setAxe(newAxe);
}

XYException::XYException(const XYException& newException) : BaseException(newException)
{
	Debug("[XYException][Constructeur]newException");
	this->setAxe(newException.getAxe());
}

XYException::~XYException(void)
{
	Debug("[XYException][Destructeur]void");
}

void XYException::setAxe(char newAxe)
{
	Debug("[XYException][setAxe]newAxe");
	axe = newAxe;
}

char XYException::getAxe(void) const
{
	Debug("[XYException][getAxe]void");
	return axe;
}