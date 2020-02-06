#include "BaseException.h"
#include "Utils.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

BaseException::BaseException(void)
{
	Debug("[BaseException][Constructeur]void");
	this->setMessage("");
}

BaseException::BaseException(const char* newMessage)
{
	Debug("[BaseException][Constructeur]newMessage");
	this->setMessage(newMessage);
}

BaseException::BaseException(const BaseException& newException)
{
	Debug("[BaseException][Constructeur]newException");
	this->setMessage(newException.getMessage());
}

BaseException::~BaseException(void)
{
	Debug("[BaseException][Destructeur]void");
	delete [] message;
}

void BaseException::setMessage(const char* newMessage)
{
	Debug("[BaseException][setMessage]newMessage");
	if(newMessage == NULL)
	{	
		message = NULL;
	}
	else
	{
		message = new char[strlen(newMessage) + 1];
		strcpy(message,newMessage);
	}
}

const char* BaseException::getMessage(void) const
{
	Debug("[BaseException][getMessage]void");
	return message;
}