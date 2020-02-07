#ifndef _hosttype_H
#define _hosttype_H

/*
	NI CONFIDENTIAL
	hosttype.h - host specific definitions, etc.

	© Copyright 1990-1995 by National Instruments Corp.
	All Rights Reserved.

	$Id: hosttype.h,v 2.10 1995/10/24 20:11:24 gregr Exp $

*/

#define __HOSTTYPE__
#if Mac
	#include <Memory.h>
	#include <Files.h>
	#include <TextEdit.h>
	#include <Windows.h>
	#include <Dialogs.h>
	#include <OSUtils.h>
	#include <Resources.h>
	#include <Events.h>
	#include <Traps.h>
	#include <QDOffscreen.h>
	#include <Menus.h>
	#include <Packages.h>
	#include <Printing.h>
	#include <Palettes.h>
	#include <SegLoad.h>
	#include <LowMem.h>
	#include <Gestalt.h>
	#include <Errors.h>

	#define QDG(qdField)	(qd.qdField)

#endif	/* Mac */

#if Unix
typedef enum { false, true } BOOLEAN;
#undef NULL
#include <stdio.h>
#include <string.h>
#if XWindows
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#endif /* XWindows */
#if (Compiler==kGCC)
#ifdef NULL /* GCC wants to define NULL as (void*)0 */
#undef NULL
#endif
#define NULL 0L
#endif /* GCC */
#endif /* Unix */

#if MSWin
#define NOMINMAX
#define LBVW
#define INCLUDE_DRIVINIT_H
#ifdef NULL
#undef NULL
#endif
#ifdef TRUE
#undef TRUE
#endif
#ifdef FALSE
#undef FALSE
#endif
#define USECOMM
#define	 WIN31
#define INCLUDE_MMSYSTEM_H
#define INCLUDE_COMMDLG_H
#if !Win32
#define INCLUDE_DDEML_H
#define INCLUDE_SHELLAPI_H
#include <win386.h>
#else
#include <windows.h>
#endif
#include <dos.h>
#include <conio.h>
#ifdef NULL
#undef NULL
#endif
#define NULL 0L
#ifdef TRUE
#undef TRUE
#endif
#define TRUE 1L
#ifdef FALSE
#undef FALSE
#endif
#define FALSE 0L
#define GP16(x) ((WNDPROC)x)

#ifndef lvsbutil
typedef struct FPNP {
					NEARPROC	np;
					FARPROC		fp;
					FARPROC		pi;
					} FpNp;

extern FpNp *fps;

typedef struct PRS	{
					NEARPROC	np;
					FARPROC		fp;
					int32		idx;
					} Prs;

extern	Prs *pat;

#define SM_NORMAL	0
#define SM_LPtoPTR	1
#define SM_LPtoMDICREATESTRUCT 2

int32	FarLong(int32,int32);
int16	FarWord(int32,int32);
int8	FarByte(int32,int32);

BOOL  PASCAL RgClss(LPWNDCLASS);
FARPROC	 PASCAL MkPrInst(FARPROC, HANDLE);
void	 PASCAL FrPrInst(FARPROC);
FARPROC FProc(NEARPROC);
NEARPROC GetProcAddr(HANDLE, char*, int16);

#if Win32
FARPROC LVMakeProcInstance(FARPROC lpProc);
#else
FARPROC LVMakeProcInstance(REALFARPROC lpProc);
#endif
void	LVFreeProcInstance(FARPROC lpProc);
void	ReleasProcAddr(NEARPROC);
void	ReleaselongID(int16);
int32	LongIDtoLong(int16);
int16	GetLongId(int32);
int16	Escape1(int16,int16,int16,int32,int32);

/* Export globals for native file dialog. */
extern HWND gDummyHWND;

#endif /* lvsbutil */
extern HANDLE gHInstance;
#endif /* MSWin */

#endif	/* _hosttype_H */
