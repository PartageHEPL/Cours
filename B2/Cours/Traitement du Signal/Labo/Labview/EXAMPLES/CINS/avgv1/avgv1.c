#include "extcode.h"
#include "avgv1.h"

float64 gTotal;
int32 gNumElements;

CIN MgErr CINRun(float64 *var1, float64 *var2) {
	ENTERLVSB		/* these macros used for globals & LabVIEW function calls */

	gTotal += *var1;
	gNumElements++;
	*var2 = gTotal / gNumElements;

	LEAVELVSB
	return noErr;
	}

CIN MgErr CINInit() {
	return noErr;
	}

CIN MgErr CINDispose() {
	return noErr;
	}

CIN MgErr CINAbort() {
	return noErr;
	}

CIN MgErr CINLoad(RsrcFile rf) {
	ENTERLVSB

	gTotal=0;
	gNumElements=0;

	LEAVELVSB
	return noErr;
	}

CIN MgErr CINUnload() {
	return noErr;
	}

CIN MgErr CINSave(RsrcFile rf) {
	return noErr;
	}
