#ifndef RGBEXCEPTION_H
#define RGBEXCEPTION_H

#include "BaseException.h"

class RGBException : public BaseException
{
	private:
		int valeur;
	public:
		RGBException(void);
		RGBException(int newValeur);
		RGBException(int newValeur,const char* newMessage);
		RGBException(const RGBException& newException);
		~RGBException(void);

		void setValeur(int newValeur);

		int getValeur(void) const;
};

#endif //RGBEXCEPTION_H