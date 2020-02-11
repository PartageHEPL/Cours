/*
 * aequalb.c
 */

#include "extcode.h"
#include "aequalb.h"

CIN MgErr CINRun(
	float32 *ap,
	float32 *bp,
	LVBoolean *aequalbp)
	{
	if (*ap == *bp)
		*aequalbp=LVTRUE;
	else
		*aequalbp=LVFALSE;
	return noErr;
	}
CIN MgErr CINInit(void) {return noErr;}
CIN MgErr CINDispose(void) {return noErr;}
CIN MgErr CINAbort(void) {return noErr;}
CIN MgErr CINLoad(RsrcFile rf) {return noErr;}
CIN MgErr CINUnload(void) {return noErr;}
CIN MgErr CINSave(RsrcFile rf) {return noErr;}
