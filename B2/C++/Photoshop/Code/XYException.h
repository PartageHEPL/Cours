#ifndef XYEXCEPTION_H
#define XYEXCEPTION_H

#include "BaseException.h"

class XYException : public BaseException
{
	private:
		char axe;
	public:
		XYException(void);
		XYException(char newAxe);
		XYException(char newAxe,const char* newMessage);
		XYException(const XYException& newException);
		~XYException(void);

		void setAxe(char newAxe);

		char getAxe(void) const;
};

#endif //XYEXCEPTION_H