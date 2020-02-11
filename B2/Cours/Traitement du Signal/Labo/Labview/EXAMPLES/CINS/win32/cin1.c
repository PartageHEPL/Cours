/*
 * Code Interface Node header file
 */

#include "extcode.h"
#include "cin1.h"
#include "windows.h"

void lsb1(int32*,int32*,int32*);

CIN MgErr CINInit(){
  DPrintf((" calling CIN Init"));
	return(noErr);

	}

CIN MgErr CINDispose(void){
	return(noErr);
	}

CIN MgErr CINAbort(void){
	return(noErr);
	}

CIN MgErr CINRun(int32 *var1, int32 *var2, int32 *var3){
	int tmp;

	tmp=MessageBox(NULL,"This is a message box created from a CIN using the WIN32 MessageBox function."
				  ,"Message Box",MB_OK+MB_TASKMODAL+MB_ICONHAND);
	lsb1(var1,var2, var3);
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
