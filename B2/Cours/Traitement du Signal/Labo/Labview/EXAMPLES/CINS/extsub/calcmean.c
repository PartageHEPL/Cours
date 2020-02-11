/*
 * calcmean.c
 */

#include "extcode.h"
#include "calcmean.h"

extern float64 sum(float64 *x, int32 n);

CIN MgErr CINRun(TD1Hdl xarrayh, float64 *meanp)
	{
	float64 *x, total;
	int32 n;

ENTERLVSB
	/* ENTERLVSB and LEAVELVSB needed for Macintosh */
	/* if you reference globals or an external subroutine */

	x = (*xarrayh)->arg1;
	n = (*xarrayh)->dimSize;
	total = sum(x,n);
	*meanp = total/(float64)n;
LEAVELVSB
	return noErr;
	}
CIN MgErr CINInit(void){return noErr;}
CIN MgErr CINDispose(void){return noErr;}
CIN MgErr CINAbort(void){return noErr;}
CIN MgErr CINLoad(RsrcFile rf){return noErr;}
CIN MgErr CINUnload(void){return noErr;}
CIN MgErr CINSave(RsrcFile rf){return noErr;}
