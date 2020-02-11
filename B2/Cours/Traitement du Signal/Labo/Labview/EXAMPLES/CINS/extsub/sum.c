/*
 * sum.c
 */

#include "extcode.h"

float64 LVSBMain(float64 *x, int32 n);
float64 LVSBMain(float64 *x, int32 n)
	{
	int32 i;
	float64 sum;

ENTERLVSB
	sum=0.0;
	for (i=0; i<n; i++)
		sum += *x++;
LEAVELVSB
	return sum;
	}
