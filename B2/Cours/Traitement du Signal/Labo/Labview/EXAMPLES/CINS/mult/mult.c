/*
 * mult.c
 */

#include "extcode.h"
#include "mult.h"

CIN MgErr CINRun(
	float32 *ap,
	float32 *bp,
	float32 *resultp)
	{
	*resultp = *ap * *bp;
	return noErr;
	}
CIN MgErr CINInit(void) {return noErr;}
CIN MgErr CINDispose(void) {return noErr;}
CIN MgErr CINAbort(void) {return noErr;}
CIN MgErr CINLoad(RsrcFile rf) {return noErr;}
CIN MgErr CINUnload(void) {return noErr;}
CIN MgErr CINSave(RsrcFile rf) {return noErr;}
