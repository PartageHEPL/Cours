/*
 * Code Interface Node header file
 */

#include "extcode.h"
#include "cin2.h"

CIN MgErr CINInit(){
	return(noErr);
	}

CIN MgErr CINDispose(void){
	return(noErr);
	}

CIN MgErr CINAbort(void){
	return(noErr);
	}

CIN MgErr CINRun(float32 *var1, float32 *var2, float32 *var3){
	WBeep();
	*var3 = *var2 + *var1;
	return(noErr);
	}

CIN MgErr CINLoad(RsrcFile rf){
	return(noErr);
	}

CIN MgErr CINUnload(void){
	return(noErr);
	}

CIN MgErr CINSave(RsrcFile rf){
	return(noErr);
	}
