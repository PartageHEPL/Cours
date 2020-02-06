#ifndef MOTEUREXCEPTION_H
#define MOTEUREXCEPTION_H

#include "BaseException.h"

class MoteurException : public BaseException
{
	public:
		MoteurException(void);
		MoteurException(const char* newMessage);
		~MoteurException(void);
};


#endif //MOTEUREXCEPTION_H