#ifndef PIXEL_H
#define PIXEL_H

#include "XYException.h"

class Pixel
{
	protected:
		int x;
		int y;
	public:
		Pixel(void);
		Pixel(int newX,int newY);
		Pixel(const Pixel& copie);
		~Pixel(void);

		void setX(int) throw (XYException);
		void setY(int) throw (XYException);

		int getX(void) const;
		int getY(void) const;
};

#endif //PIXEL_H