#include "extcode.h"
#include "avgv2.h"

typedef struct {
	float64		total;
	int32		numElements;
	} dsGlobalStruct;

CIN MgErr CINInit() {
	dsGlobalStruct **dsGlobals;

	if (!(dsGlobals = (dsGlobalStruct **)
				DSNewHandle(sizeof(dsGlobalStruct)))) /* if 0, ran out of memory */
		return mFullErr;

	(*dsGlobals)->numElements=0;
	(*dsGlobals)->total=0;

	SetDSStorage((int32) dsGlobals);
	return noErr;
	}

CIN MgErr CINDispose() {
	dsGlobalStruct **dsGlobals;

	dsGlobals=(dsGlobalStruct **) GetDSStorage();

	if (dsGlobals)
		DSDisposeHandle(dsGlobals);

	return noErr;
	}

CIN MgErr CINAbort() {
	return noErr;
	}

CIN MgErr CINRun(float64 *var1, float64 *var2) {
	dsGlobalStruct **dsGlobals;

	dsGlobals=(dsGlobalStruct **) GetDSStorage();

	if (dsGlobals) {
		(*dsGlobals)->total += *var1;
		(*dsGlobals)->numElements++;
		*var2 = (*dsGlobals)->total / (*dsGlobals)->numElements;
		}
	return noErr;
	}

CIN MgErr CINLoad(RsrcFile rf) {
	return noErr;
	}

CIN MgErr CINUnload() {
	return noErr;
	}

CIN MgErr CINSave(RsrcFile rf) {
	return noErr;
	}
