/*
 * tblsrch.c
 */

#include "extcode.h"
#include "tblsrch.h"

#define ParamNumber 0 /* The array parameter is parameter 0 */

CIN MgErr CINRun(
			TD1Hdl		clusterTableh,
			TD2			*elementp,
			LVBoolean	*presentp,
			int32		*positionp)
	{
	int32		size,i;
	MgErr		mgError=noErr;
	TD2			*tmpp;
	LStrHandle	newStringh;
	TD2			*newElementp;
	int32		newNumElements;

	size = (*clusterTableh)->dimSize;
	tmpp = (*clusterTableh)->arg1;

	*positionp = -1;
	*presentp = LVFALSE;

	for(i=0; i<size; i++) {
		if(tmpp->arg1 == elementp->arg1)
			if(LStrCmp(*(tmpp->arg2), *(elementp->arg2)) == 0)
				break;
		tmpp++;
		}

	if(i<size) {
		*positionp = i;
		*presentp = LVTRUE;
		goto out;
		}

	newStringh = elementp->arg2;
	if(mgError = DSHandToHand((UHandle *)&newStringh))
		goto out;

	newNumElements = size+1;

	if (mgError = SetCINArraySize((UHandle)clusterTableh,
						ParamNumber,
						newNumElements)) {
		DSDisposeHandle(newStringh);
		goto out;
		}
	(*clusterTableh)->dimSize = size+1;

	newElementp = &((*clusterTableh)->arg1[size]);
	newElementp->arg1 = elementp->arg1;
	newElementp->arg2 = newStringh;
	*positionp = size;

out:
	return mgError;
	}
CIN MgErr CINInit(void) {return noErr;}
CIN MgErr CINDispose(void) {return noErr;}
CIN MgErr CINAbort(void) {return noErr;}
CIN MgErr CINLoad(RsrcFile rf) {return noErr;}
CIN MgErr CINUnload(void) {return noErr;}
CIN MgErr CINSave(RsrcFile rf) {return noErr;}
