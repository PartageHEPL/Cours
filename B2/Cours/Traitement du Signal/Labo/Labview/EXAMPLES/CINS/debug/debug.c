#include "extcode.h"
#include "debug.h"

CIN MgErr CINInit() {
	return noErr;
	}

CIN MgErr CINDispose() {
	return noErr;
	}

CIN MgErr CINAbort() {
	return noErr;
	}

CIN MgErr CINRun(uInt16 *var1, LStrHandle var2) {
	ENTERLVSB		/* these macros used for globals & LabVIEW function calls */

	switch (*var1) {
		case 0:
			DbgPrintf("");
			/* If you call DbgPrintf with a string it */
			/* opens the debug window if is not already open */
			break;
		case 1:
			DbgPrintf("%H", var2);
			/* DbgPrintf takes the same arguments as SPrintf */
			break;
		case 2:
			DbgPrintf(NULL);
			/* If you call DbgPrintf with NULL, it closes */
			/* the debug window */
		}
	LEAVELVSB
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
