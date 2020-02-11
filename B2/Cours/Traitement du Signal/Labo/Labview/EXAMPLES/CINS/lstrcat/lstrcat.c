/*
 * lstrcat.c
 */

#include "extcode.h"
#include "lstrcat.h"

CIN MgErr CINRun(
	LStrHandle strh1,
	LStrHandle strh2)
	{
	int32 size1, size2, newSize;
	MgErr err;

	size1 = LStrLen(*strh1);
	size2 = LStrLen(*strh2);
	newSize = size1 + size2;
	if (err = NumericArrayResize(uB, 1L, (UHandle *)&strh1, newSize))
		goto out;

	MoveBlock(LStrBuf(*strh2), LStrBuf(*strh1)+size1, size2);

	LStrLen(*strh1) = newSize; /* update the dimension (length) of the first string */

out:
	return err;
	}
CIN MgErr CINInit(void) {return noErr;}
CIN MgErr CINDispose(void) {return noErr;}
CIN MgErr CINAbort(void) {return noErr;}
CIN MgErr CINLoad(RsrcFile rf) {return noErr;}
CIN MgErr CINUnload(void) {return noErr;}
CIN MgErr CINSave(RsrcFile rf) {return noErr;}
