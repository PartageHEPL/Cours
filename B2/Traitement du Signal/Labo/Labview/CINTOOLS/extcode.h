#ifndef _extcode_H
#define _extcode_H

/*
	NI CONFIDENTIAL
	extcode.h - DO NOT CHANGE THIS document; it reflects what is published
			in the CIN manual.

	© Copyright 1990-1996 by National Instruments Corp.
	All rights reserved

	$Id: extcode.h,v 2.38 1996/04/24 21:44:17 brian Exp $

*/

#ifdef CIN_VERS
	#if CIN_VERS == 2
		#pragma aux default "*_"
	#endif
#endif

/*
LabVIEW system options: don't uncomment, the compiler defines these automatically
*/
/*	THINK_C			Macintosh */
/*	THINK_CPLUS		Macintosh integrated Symantec C++ translator */
/*	macintosh		Macintosh mpw 68K compiler */
/*	__powerc		Macintosh mpw Power PC compiler */
/*	__WATCOMC__		PC and MS Windows */
/*	WIN32			PC and NT */
/*	unix			UNIX */
/*	xwindows		X Windows */
/*	sparc			SUN Sparc station */
/*	hp9000			HP workstation */

/* Possible values for OpSystem */
	#define kMacOS		1
	#define kMSWin31	10
	#define kMSWin32	11
	#define kLinux		20
	#define kSunOS		21
	#define kSolaris	22
	#define kHPUX		23
	#define kPowerUnix	24

/* Possible values for WindowSystem */
	#define kMacWM		1
	#define kMSWin31WM	10
	#define kMSWin32WM	11
	#define kXWindows	20

/* Possible values for Compiler */
	#define kThinkC		1
	#define kSymanCpp	2
	#define kMPW		3
	#define kMetroWerks 4
	#define kWatcom		10
	#define kVisualC	11
	#define kMicrosoftC 12
	#define kSymanCWin	13
	#define kBorlandC	14
	#define kGCC		20
	#define kUnbundledC 21

/* Possible values for Processor */
	#define kM68000		1
	#define kX86		2
	#define kSparc		3
	#define kPPC		4
	#define kPARISC		5

#if defined(_WIN32) || defined(WIN32) || defined(__WIN32__)
	#define OpSystem		kMSWin32
	#define WindowSystem	kMSWin32WM
	#ifdef __SC__
		#define Compiler		kSymanCWin
	#elif defined(__BORLANDC__) || defined(__BCPLUSPLUS__)
		#define Compiler		kBorlandC
	#elif defined(_MSC_VER)
		#define Compiler		kVisualC
	#else
		#error "We don't know the Compiler"
	#endif
	#ifdef _M_PPC
		#define Processor	kPPC
	#elif defined(_M_IX86)
		#define Processor	kX86
	#elif Compiler == kBorlandC
		#define Processor	kX86
	#else
		#error "We don't know the Processor architecture"
	#endif
	#define BigEndian		0
#elif defined(macintosh) || defined(__PPCC__) || defined(THINK_C) || defined(__SC__) || defined(__MWERKS__)
	#define OpSystem		kMacOS
	#define WindowSystem	kMacWM
	#define OLDROUTINENAMES 0
	#define OLDROUTINELOCATIONS 0
	#if defined(__MWERKS__)
		#define Compiler	kMetroWerks
	#elif defined(__PPCC__) || defined(applec) || defined(__MRC__)
		#define Compiler	kMPW	/* could be one of PPCC, C (MPW's old 68K compiler), or SC, or MrC */
	#elif defined(THINK_C) || defined(__SC__)
		#if defined(THINK_CPLUS)
			#define Compiler	kSymanCpp	/* the integrated C++ compiler from TC6 or Sym C 7 */
		#else
			#define Compiler	kThinkC		/* TC 6 or Sym C 7 */
		#endif
	#endif
	#if defined(__powerc)
		#define Processor	kPPC
	#else
		#define Processor	kM68000
	#endif
	#define BigEndian 1
#elif defined(__WATCOMC__)
	#define OpSystem		kMSWin31
	#define WindowSystem	kMSWin31WM
	#define Compiler		kWatcom
	#define Processor		kX86
	#define BigEndian		0
#elif defined(linux)
	#define WindowSystem	kXWindows
	#define Processor		kX86
	#define OpSystem		kLinux
	#define Compiler		kGCC
	#define BigEndian		0
#elif (defined(__i386) || defined(__i486)) && defined(__svr4__)
	#define WindowSystem	kXWindows
	#define Processor		kX86
	#define OpSystem		kSolaris
	#ifdef __GNUC__
		#define Compiler	kGCC
	#else
		#define Compiler	kUnbundledC
	#endif
	#define BigEndian		0
#elif sparc || __sparc
	#define WindowSystem	kXWindows
	#define Processor		kSparc
	#ifdef __SVR4
		#define OpSystem	kSolaris
	#else
		#define OpSystem	kSunOS
	#endif
	#ifdef __GNUC__
		#define Compiler	kGCC
	#else
		#define Compiler	kUnbundledC
	#endif
	#define BigEndian		1
#elif hp9000
	#define WindowSystem	kXWindows
	#define Processor		kPARISC
	#define OpSystem		kHPUX
	#define Compiler		kUnbundledC
	#define BigEndian		1
#elif defined(__HC__)
	#define OpSystem kPowerUnix
	#define WindowSystem kXWindows
	#define Compiler kUnbundledC
	#define Processor kPPC
	#define BigEndian 1
#endif

#if !defined(OpSystem) || !defined(WindowSystem) || !defined(Compiler) || !defined(Processor)
	#error
#endif

#define Unix		((OpSystem>=kLinux) && (OpSystem<=kPowerUnix))
#define MSWin		((OpSystem>=kMSWin31) && (OpSystem<=kMSWin32))
#define Mac			(OpSystem==kMacOS)
#define XWindows	(WindowSystem==kXWindows)
#define Think		(Compiler==kThinkC)
#define MWerks68K	(Compiler==kMetroWerks && Processor==kM68000)
#define MWerksPPC	(Compiler==kMetroWerks && Processor==kPPC)
#define Win32		(OpSystem==kMSWin32)
#define Sparc		(Processor==kSparc)
#define Linux		(OpSystem==kLinux)
#define PowerPC		(Processor==kPPC)
#define SVR4		(OpSystem==kSolaris)
#define SVR4thread	(OpSystem==kSolaris)

#ifndef StudEd
	#define StudEd 0
#endif

#if (Mac && ((Processor!=kM68000) || (Compiler!=kThinkC))) || StudEd || (Unix && Processor!=kX86)
	#define FPUASM 0
#else
	#define FPUASM 1
#endif


#ifndef PlatformDefinesOnly

#if Mac /*#############################################################*/

typedef char				int8;
typedef unsigned char		uInt8;
typedef uInt8				uChar;
typedef short				int16;
typedef unsigned short		uInt16;
typedef long				int32;
typedef unsigned long		uInt32;
typedef float				float32;
#if (Compiler==kMPW) || ((Processor == kPPC) && (Compiler == kThinkC))
	typedef double			float64;
#else /* Think C and MetroWerks */
	typedef short double	float64;
#endif
typedef int32				Bool32;

#if (Processor == kM68000) || ((Processor == kPPC) && (Compiler == kMPW))
	typedef long double floatExt;
	#define ExtHiLo 0
#else
	typedef struct {
		double hi;
		double lo;
		} floatExt;
	#define ExtHiLo 1
#endif

#if Think
#define Unused(var_or_param)
#else /* MPW and MetroWerks */
#define Unused(var_or_param)		var_or_param=var_or_param;
#endif

#elif Unix /*###############################################################*/
typedef char				int8;
typedef unsigned char		uInt8;
typedef uInt8				uChar;
typedef short int			int16;
typedef unsigned short int	uInt16;
typedef int					int32;
typedef unsigned int		uInt32;
typedef float				float32;
typedef double				float64;
typedef int32				Bool32;
#define ExtHiLo 0
#if Processor==kPARISC
typedef double				floatExt;
#elif Processor==kX86
#if (Compiler==kGCC)
typedef struct { /* force GCC to make this struct 10 bytes */
	int32	mlo __attribute__((packed,aligned(2)));
	int32	mhi __attribute__((packed,aligned(2)));
	int16	e __attribute__((packed,aligned(2)));
	} floatExt;
#else
typedef struct {
	int32	mlo, mhi;
	int16	e;
	} floatExt;
#endif
#else
typedef long double			floatExt;
#endif

#define Unused(var_or_param)

#elif MSWin /*#########################################################*/
typedef char				int8;
typedef unsigned char		uInt8;
typedef uInt8				uChar;
typedef short int			int16;
typedef unsigned short int	uInt16;
typedef long				int32;
typedef unsigned long		uInt32;
typedef float				float32;
typedef double				float64;
typedef int32				Bool32;

#define ExtHiLo 0
#if Processor == kX86
typedef struct {
	int32	mlo, mhi;
	int16	e;
	} floatExt;
#else
typedef double floatExt;
#endif

#define Unused(var_or_param)		var_or_param=var_or_param;
#if Compiler == kVisualC
	/* disable the following warnings */
	#pragma warning (disable : 4001) /* nonstandard extension 'single line comment' was used */
	#pragma warning (disable : 4032) /* formal parameter x has different type when promoted */
	#pragma warning (disable : 4057) /* 'operator' : 'x' differs in indirection to slightly different base types from 'y' */
	#pragma warning (disable : 4115) /* 'x' : named type definition in parentheses */
	#pragma warning (disable : 4125) /* decimal digit terminates octal escape sequence */
	#pragma warning (disable : 4135) /* conversion between different integral types */
	#pragma warning (disable : 4136) /* conversion between different floating point numbers */
	#pragma warning (disable : 4201) /* nonstandard extension used : nameless struct/union */
	#pragma warning (disable : 4209) /* nonstandard extension used : benign typedef redefinition */
	#pragma warning (disable : 4214) /* nonstandard extension used : bit field types other than int */
	#pragma warning (disable : 4244) /* conversion between different sized ints */
	#pragma warning (disable : 4306) /* 'operator' : conversion from 'x ' to 'y' of greater size */
	#pragma warning (disable : 4310) /* cast truncates constant value */
	#pragma warning (disable : 4514) /* 'x' : unreferenced inline function has been removed */
	#pragma warning (disable : 4699) /* Note: pre-compiled header usage information message */
	#pragma warning (disable : 4706) /* assignment within conditional expression */
	#pragma warning (disable : 4761) /* integral size mismatch in argument: conversion supplied */
#endif /* Compiler == kVisualC */
#endif

/* manager.h *=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*/
#if Mac
	#include <Types.h>
	#if defined(__CONDITIONALMACROS__)
		#define UsingUnivIncludes 1
	#else
		#define UsingUnivIncludes 0
	#endif
#else
	/* All of these types are provided by Types.h on the Mac */
	typedef struct Point {
		int16	v, h;
		} Point;
	typedef struct Rect {
		int16	top, left, bottom, right;
		} Rect;
	typedef uChar		Str255[256], Str31[32], *StringPtr, **StringHandle;
	enum { noErr };
	typedef uInt32		ResType;

#endif

/*
NOTE: When you change these Manager Error Codes, make corresponding changes
to the resource file.  Resources STR# 10001, and MLbl 6042 must
stay consistent with these codes.
*/

enum {					/* Manager Error Codes */
	/* noErr,	*/
	mgArgErr=1,
	mFullErr,			/* Memory Mgr	2-3		*/
	mZoneErr,

	fEOF,				/* File Mgr		4-12	*/
	fIsOpen,
	fIOErr,
	fNotFound,
	fNoPerm,
	fDiskFull,
	fDupPath,
	fTMFOpen,
	fNotEnabled,

	rFNotFound,			/* Resource Mgr 13-15	*/
	rAddFailed,
	rNotFound,

	iNotFound,			/* Image Mgr	16-17	*/
	iMemoryErr,

	dPenNotExist,		/* Draw Mgr		18		*/

	cfgBadType,			/* Config Mgr	19-22	*/
	cfgTokenNotFound,
	cfgParseError,
	cfgAllocError,

	ecLVSBFormatError,	/* extCode Mgr	23		*/
	ecLVSBOffsetError,	/* extCode Mgr	24		*/
	ecLVSBNoCodeError,	/* extCode Mgr	25		*/

	wNullWindow,		/* Window Mgr	26-27	*/
	wDestroyMixup,

	menuNullMenu,		/* Menu Mgr		28		*/

	pAbortJob,			/* Print Mgr	29-35	*/
	pBadPrintRecord,
	pDriverError,
	pWindowsError,
	pMemoryError,
	pDialogError,
	pMiscError,

	dvInvalidRefnum,	/* Device Mgr	36-41	*/
	dvDeviceNotFound,
	dvParamErr,
	dvUnitErr,
	dvOpenErr,
	dvAbortErr,

	bogusError,			/* generic error 42 */
	cancelError,		/* cancelled by user 43 */

	OMObjLowErr,		/* object message dispatcher errors 44-52 */
	OMObjHiErr,
	OMObjNotInHeapErr,
	OMOHeapNotKnownErr,
	OMBadDPIdErr,
	OMNoDPinTabErr,
	OMMsgOutOfRangeErr,
	OMMethodNullErr,
	OMUnknownMsgErr,

	mgNotSupported,

	ncBadAddressErr,		/* Net Connection errors 54-66 */
	ncInProgress,
	ncTimeOutErr,
	ncBusyErr,
	ncNotSupportedErr,
	ncNetErr,
	ncAddrInUseErr,
	ncSysOutOfMem,
	ncSysConnAbortedErr,	/* 62 */
	ncConnRefusedErr,
	ncNotConnectedErr,
	ncAlreadyConnectedErr,
	ncConnClosedErr,		/* 66 */

	amInitErr,				/* (Inter-)Application Message Manager 67- */

	occBadOccurrenceErr,	/* 68  Occurrence Mgr errors */
	occWaitOnUnBoundHdlrErr,
	occFunnyQOverFlowErr,

	fDataLogTypeConflict,	/* 71 */
	unused1 ,
	amUnrecognizedType,
	mCorruptErr,
	ecLVSBErrorMakingTempDLL,
	ecLVSBOldCIN,			/* ExtCode Mgr	76*/

	dragSktNotFound,		/* Drag Manager 77 - 80*/
	dropLoadErr,
	oleRegisterErr,
	oleReleaseErr,

	fmtTypeMismatch,		/* String processing (printf, scanf) errors */
	fmtUnknownConversion,
	fmtTooFew,
	fmtTooMany,
	fmtScanError,

	mgErrSentinel,

	kAppErrorBase = 1000
	};


typedef int32	MgErr;

typedef struct Point32 {
	int32	v, h;
	} Point32;

typedef struct Rect32 {
	int32	top, left, bottom, right;
	} Rect32;

typedef enum {	iB=1, iW, iL, iQ, uB, uW, uL, uQ, fS, fD, fX, cS, cD, cX } NumType;

#define Private(x)	typedef struct x ## _t { void *p; } *x

#undef NULL
#undef TRUE
#undef FALSE
#define NULL		0L
#define TRUE		1L
#define FALSE		0L

/* private file manager path type - declared here for use in constant table */
Private(Path);

typedef struct {
	float32 re, im;
	} cmplx64;

typedef struct {
	float64 re, im;
	} cmplx128;

typedef struct {
	floatExt	re, im;
	} cmplxExt;

typedef struct {
	int32	cnt;		/* number of bytes that follow */
	uChar	str[1];		/* cnt bytes */
	} LStr, *LStrPtr, **LStrHandle;

typedef uChar		*UPtr, **UHandle;
typedef uChar		*PStr, *CStr;

typedef struct {
	int32	cnt;		/* number of pascal strings that follow */
	uChar	str[1];		/* cnt bytes of concatenated pascal strings */
	} CPStr, *CPStrPtr, **CPStrHandle;

/*** The Support Manager ***/

#define HiNibble(x)		(uInt8)(((x)>>4) & 0x0F)
#define LoNibble(x)		(uInt8)((x) & 0x0F)
#define HiByte(x)		((int8)((int16)(x)>>8))
#define LoByte(x)		((int8)(x))
#define Word(hi,lo)		(((int16)(hi)<<8) | ((int16)(uInt8)(lo)))
#define Hi16(x)			((int16)((int32)(x)>>16))
#define Lo16(x)			((int16)(x))
#define Long(hi,lo)		(((int32)(hi)<<16) | ((int32)(uInt16)(lo)))

#define Cat4Chrs(c1,c2,c3,c4)	(((int32)(uInt8)(c1)<<24)|((int32)(uInt8)(c2)<<16)|((int32)(uInt8)(c3)<<8)|((int32)(uInt8)(c4)))
#define Cat2Chrs(c1,c2)			(((int16)(uInt8)(c1)<<8)|((int16)(uInt8)(c2)))

#if BigEndian
#define RTToL(c1,c2,c3,c4)	Cat4Chrs(c1,c2,c3,c4)
#define RTToW(c1,c2)		Cat2Chrs(c1,c2)
#else
#define RTToL(c1,c2,c3,c4)	Cat4Chrs(c4,c3,c2,c1)
#define RTToW(c1,c2)		Cat2Chrs(c2,c1)
#endif

#define Offset(type, field)		((int32)&((type*)0)->field)

#if (Processor==kX86) || Mac
#define GetAWord(p)			(*(int16*)(p))
#define SetAWord(p,x)		(*(int16*)(p)= x)
#define GetALong(p)			(*(int32*)(p))
#define SetALong(p,x)		(*(int32*)(p)= x)
#else
int32		GetALong(void *);
int32		SetALong(void *, int32);
int16		GetAWord(void *);
int16		SetAWord(void *, int16);
#endif

int32		Abs(int32);
int32		Min(int32, int32);
int32		Max(int32, int32);
int32		Pin(int32, int32, int32);
void		RandomGen(float64*);
Bool32		IsDigit(uChar);
Bool32		IsAlpha(uChar);
Bool32		IsPunct(uChar);
Bool32		IsLower(uChar);
Bool32		IsUpper(uChar);
int32		ToUpper(int32);
int32		ToLower(int32);
uChar		HexChar(int32);
int32		StrLen(const uChar *);
int32		StrCat(CStr, CStr);
CStr		StrCpy(CStr, CStr);
CStr		StrNCpy(CStr, CStr, int32);
int32		StrCmp(CStr, CStr);
int32		StrNCmp(CStr, CStr, int32);
int32		StrNCaseCmp(CStr, CStr, int32);

/* FileNameCmp compares two PStr's with the same case-sensitivity as */
/* the filesystem. */
/* FileNameNCmp compares two CStr's (to length n) with the same */
/* case-sensitivity as the filesystem. */
/* FileNameIndCmp compares two PStr's (passing pointers to the string */
/* pointers) with the same case-sensitivity as the filesystem. */
#if Mac || MSWin
#define FileNameCmp PStrCaseCmp
#define FileNameNCmp StrNCaseCmp
#define FileNameIndCmp PPStrCaseCmp
#elif Unix
#define FileNameCmp PStrCmp
#define FileNameNCmp StrNCmp
#define FileNameIndCmp PPStrCmp
#endif

#define PStrBuf(b)		(&((PStr)(b))[1])
#define PStrLen(b)		(((PStr)(b))[0])
#define LStrBuf(sp)		(&((sp))->str[0])
#define LStrLen(sp)		(((sp))->cnt)
#define CPStrLen		LStrLen			/* concatenated Pascal vs. LabVIEW strings */
#define CPStrBuf		LStrBuf			/* concatenated Pascal vs. LabVIEW strings */

int32		PStrCat(PStr, PStr);
PStr		PStrCpy(PStr, PStr);
PStr		PStrNCpy(UPtr, UPtr, int32);
int32		PStrCmp(PStr, PStr);
int32		PPStrCmp(PStr*, PStr*);
int32		PStrCaseCmp(PStr, PStr);
int32		PPStrCaseCmp(PStr*, PStr*);
int32		LStrCmp(LStrPtr, LStrPtr);
int32		CPStrSize(CPStrPtr);
int32		CPStrCmp(CPStrPtr, CPStrPtr);
MgErr		CPStrInsert(CPStrHandle, PStr, int32);
void		CPStrRemove(CPStrHandle, int32);
PStr		CPStrIndex(CPStrHandle, int32);
MgErr		CPStrReplace(CPStrHandle, PStr, int32);
int32		BlockCmp(UPtr, UPtr, int32);
int32		PToCStr(PStr, CStr);
int32		CToPStr(CStr, PStr);
int32		LToPStr(LStrPtr, PStr);
int32		PToLStr(PStr, LStrPtr);
MgErr		DbgPrintf(char *buf, ...);
int32		SPrintf(CStr, CStr, ...);
int32		SPrintfp(CStr, PStr, ...);
int32		PPrintf(PStr, CStr, ...);
int32		PPrintfp(PStr, PStr, ...);
MgErr		LStrPrintf(LStrHandle t, CStr fmt, ...);
typedef		int32 (*CompareProcPtr)(void*, void*);
void		QSort(UPtr, int32, int32, CompareProcPtr);
int32		BinSearch(UPtr, int32, int32, UPtr, CompareProcPtr);
uInt32		MilliSecs(void);
uInt32		TimeInSecs(void);

/*** The Memory Manager ***/

typedef struct {
	int32 totFreeSize, maxFreeSize, nFreeBlocks;
	int32 totAllocSize, maxAllocSize;
	int32 nPointers, nUnlockedHdls, nLockedHdls;
	int32 reserved[4];
	} MemStatRec;

MgErr		AZCheckHandle(void*);
MgErr		AZCheckPtr(void*);
MgErr		AZDisposeHandle(void*);
MgErr		AZDisposePtr(void*);
int32		AZGetHandleSize(void*);
MgErr		AZHandAndHand(void*,void*);
MgErr		AZHandToHand(UHandle *);
MgErr		AZHLock(void*);
MgErr		AZHUnlock(void*);
void		AZHPurge(void*);
void		AZHNoPurge(void*);
UHandle		AZNewHandle(int32);
UHandle		AZNewHClr(int32);
UPtr		AZNewPtr(int32);
UPtr		AZNewPClr(int32);
MgErr		AZPtrToHand(void*,void*,int32);
MgErr		AZPtrAndHand(void*,void*,int32);
MgErr		AZPtrToXHand(void*,void*,int32);
UHandle		AZRecoverHandle(void*);
MgErr		AZSetHandleSize(void*, int32);
MgErr		AZSetHSzClr(void*, int32);
int32		AZHeapCheck(Bool32);
int32		AZMaxMem(void);
MgErr		AZMemStats(MemStatRec *msrp);

MgErr		DSCheckHandle(void*);
MgErr		DSCheckPtr(void*);
MgErr		DSDisposeHandle(void*);
MgErr		DSDisposePtr(void*);
int32		DSGetHandleSize(void*);
MgErr		DSHandAndHand(void*,void*);
MgErr		DSHandToHand(UHandle *);
UHandle		DSNewHandle(int32);
UHandle		DSNewHClr(int32);
UPtr		DSNewPtr(int32);
UPtr		DSNewPClr(int32);
MgErr		DSPtrToHand(void*,void*,int32);
MgErr		DSPtrAndHand(void*,void*,int32);
MgErr		DSPtrToXHand(void*,void*,int32);
UHandle		DSRecoverHandle(void*);
MgErr		DSSetHandleSize(void*, int32);
MgErr		DSSetHSzClr(void*, int32);
int32		DSHeapCheck(Bool32);
int32		DSMaxMem(void);
MgErr		DSMemStats(MemStatRec *msrp);
void		ClearMem(void*, int32);
void		MoveBlock(void *src, void *dest, int32);
void		SwapBlock(void *src, void *dest, int32);

/*** The File Manager ***/

enum { openReadWrite, openReadOnly, openWriteOnly, openWriteOnlyTruncate }; /* open modes */
enum { denyReadWrite, denyWriteOnly, denyNeither
#if MSWin && !Win32
		, denyWin3xCompat
#endif
	};		/* deny modes */
enum { fStart=1, fEnd, fCurrent };											/* seek modes */
enum {	fAbsPath,
		fRelPath,
		fNotAPath,
		fUNCPath,								/* uncfilename */
		nPathTypes };							/* path type codes */

Private(File);

typedef struct {			/* file/directory information record */
	int32	type;			/* system specific file type-- 0 for directories */
	int32	creator;		/* system specific file creator-- 0 for directories */
	int32	permissions;	/* system specific file access rights */
	int32	size;			/* file size in bytes (data fork on Mac) or entries in folder */
	int32	rfSize;			/* resource fork size (on Mac only) */
	uInt32	cdate;			/* creation date */
	uInt32	mdate;			/* last modification date */
	Bool32	folder;			/* indicates whether path refers to a folder */
	Bool32	isInvisible; /* indicates whether the file is visible in File Dialog */
	Point	location;		/* system specific geographical location */
	Str255	owner;			/* owner (in pascal string form) of file or folder */
	Str255	group;			/* group (in pascal string form) of file or folder */
	} FInfoRec, *FInfoPtr;

typedef struct {
	uInt32	size;			/* size in bytes of a volume */
	uInt32	used;			/* number of bytes used on volume */
	uInt32	free;			/* number of bytes available for use on volume */
	} VInfoRec;

typedef struct {
	int32 flags, type;
	} FileType;

#define kIsFile				0x01
#define kRecognizedType		0x02
#define kIsLink				0x04
#define kFIsInvisible		0x08
#define kIsTopLevelVI		0x10	/* Used only for VIs in archives */
#define kErrGettingType		0x20	/* error occurred getting type info */

enum {
	kFNotExist = 0L,
	kFIsFile,
	kFIsFolder
	};

MgErr	FCreate(File *fdp, Path path, int32 access, int32 openMode, int32 denyMode, PStr group);
MgErr	FCreateAlways(File *fdp, Path path, int32 access, int32 openMode, int32 denyMode, PStr group);
MgErr	FMOpen(File *fdp, Path path, int32 openMode, int32 denyMode);
MgErr	FMClose(File fd);
MgErr	FMSeek(File fd, int32 ofst, int32 mode);
MgErr	FMTell(File fd, int32 *ofstp);
MgErr	FGetEOF(File fd, int32 *sizep);
MgErr	FSetEOF(File fd, int32 size);
MgErr	FMRead(File fd, int32 inCount, int32 *outCountp, UPtr buffer);
MgErr	FMWrite(File fd, int32 inCount, int32 *outCountp, UPtr buffer);
MgErr	FFlush(File fd);
MgErr	FGetInfo(Path path, FInfoPtr infop);
int32	FExists(Path path);
MgErr	FGetAccessRights(Path path, PStr owner, PStr group, int32 *permPtr);
MgErr	FSetInfo(Path path, FInfoPtr infop);
MgErr	FSetAccessRights(Path path, PStr owner, PStr group, int32 *permPtr);
MgErr	FMove(Path oldPath, Path newPath);
MgErr	FCopy(Path oldPath, Path newPath);
MgErr	FRemove(Path path);
MgErr	FNewDir(Path path, int32 permissions);

typedef CPStr FDirEntRec, *FDirEntPtr, **FDirEntHandle; /* directory list record */

MgErr	FListDir(Path path, FDirEntHandle list, FileType **);
MgErr	FAddPath(Path basePath, Path relPath, Path newPath);
MgErr	FAppendName(Path path, PStr name);
MgErr	FRelPath(Path start, Path end, Path relPath);
MgErr	FName(Path path, StringHandle name);
MgErr	FNamePtr(Path path, PStr name);
MgErr	FDirName(Path path, Path dir);
MgErr	FVolName(Path path, Path vol);
Path	FMakePath(Path path, int32 type, ...);
Path	FEmptyPath(Path);
Path	FNotAPath(Path);
MgErr	FPathToPath(Path *p);
MgErr	FPathCpy(Path dst, Path src);
MgErr	FDisposePath(Path p);
int32	FUnFlattenPath(UPtr fp, Path *pPtr);
int32	FFlattenPath(Path p, UPtr fp);
int32	FDepth(Path path);
LStrHandle	FGetDefGroup(LStrHandle);
Bool32	FStrFitsPat(uChar*, uChar*, int32, int32);
int32	FPathCmp(Path, Path);
UHandle PathToCString(Path );
MgErr	FPathToAZString(Path, LStrHandle*);
MgErr	FPathToDSString(Path, LStrHandle*);
MgErr	FStringToPath(LStrHandle, Path*);
MgErr	FTextToPath(UPtr, int32, Path*);
MgErr	FLockOrUnlockRange(File, int32, int32, int32, Bool32);
MgErr	FGetVolInfo(Path, VInfoRec*);
MgErr	FSetPathType(Path, int32);
MgErr	FGetPathType(Path, int32*);
Bool32	FIsAPath(Path);
Bool32	FIsEmptyPath(Path);
Bool32	FIsAPathOrNotAPath(Path);
Bool32	FIsAPathOfType(Path, int32);
Bool32	FIsAbsPath(Path);
MgErr	FAppPath(Path);

Private(LVRefNum);

Bool32	FIsARefNum(LVRefNum);
MgErr	FNewRefNum(Path, File, LVRefNum*);
MgErr	FDisposeRefNum(LVRefNum);
MgErr	FRefNumToFD(LVRefNum, File*);
MgErr	FRefNumToPath(LVRefNum, Path);
MgErr	FArrToPath(UHandle, Bool32, Path);
MgErr	FPathToArr(Path, Bool32*, UHandle);
int32	FPrintf(File, CStr, ...);  /* moved from support manager area */
CStr	DateCString(uInt32, int32);
CStr	TimeCString(uInt32, int32);
CStr	ASCIITime(uInt32);

typedef struct {	/* overlays ANSI definition for unix, watcom, think, mpw */
	int32	sec;	/* 0:59 */
	int32	min;	/* 0:59 */
	int32	hour;	/* 0:23 */
	int32	mday;	/* day of the month, 1:31 */
	int32	mon;	/* month of the year, 1:12 */
	int32	year;	/* year, 1904:2040 */
	int32	wday;	/* day of the week, 1:7 for Sun:Sat */
	int32	yday;	/* day of year (julian date), 1:366 */
	int32	isdst;	/* 1 if daylight savings time */
	} DateRec;

void	SecsToDate(uInt32, DateRec*);
uInt32	DateToSecs(DateRec*);

/*** The Resource Manager ***/

/* RsrcFile used by memory manager function */
Private(RsrcFile);

/*	Debugging ON section Begin	*/
#ifndef DBG
#define DBG 1
#endif
/*	Debugging ON section End	*/

/*	Debugging OFF section Begin
#undef DBG
#define DBG 0
	Debugging OFF section End	*/

#if DBG
#define		DPrintf(x) DBPrintf x
int32 DBPrintf(const char *fmt, ...);
#else
#define		DPrintf(x)
#endif

/* pubinc.h *=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*/

/* LabVIEW Bool32 representation and values */
typedef uInt16 LVBoolean;
#define LVBooleanTrue	((LVBoolean)0x8000)
#define LVBooleanFalse	((LVBoolean)0x0000)
#define LVTRUE			LVBooleanTrue			/* for CIN users */
#define LVFALSE			LVBooleanFalse

#if Processor==kM68000
	#define CIN pascal
	int32	SetUpGlobal(void);
	void	RestoreGlobal(int32);
	#define ENTERLVSB					\
		int32	savedGlobal;			\
										\
		savedGlobal = SetUpGlobal();
	#define LEAVELVSB					\
		RestoreGlobal(savedGlobal);

#else
	typedef double floatNum;
	#define CIN
	#define ENTERLVSB
	#define LEAVELVSB
#endif

#if Mac
	#if Think
		#define _NOERRORCHECK_ 1	/* Makes Think use 68881 intrinsics for some functions. */
	#endif
	#if (Processor==kM68000)
		double log1p(double x);		/* defined in ansi.c. */
	#endif
	#if PowerPC
		#include <fp.h>
	#else
		#include <math.h>
	#endif
#elif MSWin
	#if FPUASM && !Win32
		void srand(unsigned int);
		int rand(void);
		#pragma aux acos parm caller [] value [8087];
		#pragma aux asin parm caller [] value [8087];
		#pragma aux atan parm caller [] value [8087];
		#pragma aux atan2 parm caller [] value [8087];
		#pragma aux ceil parm caller [] value [8087] modify [eax];
		#pragma aux cos parm caller [] value [8087];
		#pragma aux cosh parm caller [] value [8087];
		#pragma aux exp parm caller [] value [8087];
		#pragma aux fabs parm caller [] value [8087];
		#pragma aux floor parm caller [] value [8087] modify [eax];
		#pragma aux fmod parm caller [] value [8087] modify [eax];
		#pragma aux frexp parm caller [] value [8087];
		#pragma aux ldexp parm caller [] value [8087];
		#pragma aux log parm caller [] value [8087];
		#pragma aux log10 parm caller [] value [8087];
		#pragma aux modf parm caller [] value [8087];
		#pragma aux pow parm caller [] value [8087] modify [ eax edx edi];
		#pragma aux sin parm caller [] value [8087];
		#pragma aux sinh parm caller [] value [8087] modify [eax];
		#pragma aux sqrt parm caller [] value [8087];
		#pragma aux tan parm caller [] value [8087];
		#pragma aux tanh parm caller [] value [8087] modify [eax];
		#define __NO_MATH_OPS
	#endif
	#include <math.h>
	double log1p(double x);
#endif

int32 GetDSStorage(void);
int32 SetDSStorage(int32 newVal);	/* returns old value */
int16 *GetTDPtr(void);
UPtr  GetLVInternals(void);
MgErr SetCINArraySize(UHandle, int32, int32);
MgErr NumericArrayResize(int32, int32, UHandle*, int32);

MgErr CallChain(UHandle);

CIN MgErr CINInit(void);
CIN MgErr CINDispose(void);
CIN MgErr CINAbort(void);
CIN MgErr CINLoad(RsrcFile reserved);
CIN MgErr CINUnload(void);
CIN MgErr CINSave(RsrcFile reserved);

/* CINInit -- Called after the VI is loaded or recompiled. */
#define UseDefaultCINInit CIN MgErr CINInit() { return noErr; }

/* CINDispose -- Called before the VI is unloaded or recompiled.*/
#define UseDefaultCINDispose CIN MgErr CINDispose() \
	{ return noErr; }

/* CINAbort-- Called when the VI is aborted. */
#define UseDefaultCINAbort CIN MgErr CINAbort() { return noErr; }

/* CINLoad -- Called when the VI is loaded. */
#define UseDefaultCINLoad CIN MgErr CINLoad(RsrcFile reserved) \
	{ Unused(reserved); return noErr; }

/* CINUnload -- Called when the VI is unloaded. */
#define UseDefaultCINUnload CIN MgErr CINUnload() \
	{ return noErr; }

/* CINSave -- Called when the VI is saved. */
#define UseDefaultCINSave CIN MgErr CINSave(RsrcFile reserved) \
	{ Unused(reserved); return noErr; }

#endif	/* !PlatformDefinesOnly */

#endif	/* _extcode_H */
