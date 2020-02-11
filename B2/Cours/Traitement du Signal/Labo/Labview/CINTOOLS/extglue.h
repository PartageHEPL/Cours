#define PlatformDefinesOnly
#include "extcode.h"

#if PowerPC
#include "ksppc.h"

#define ExternalSubGlue(subrName)			\
	.reldata ;								\
	.align 2 ;								\
	.globl gLVSB##subrName;					\
gLVSB##subrName:							\
	.long	0xFECE0001;						\
LEAF_ENTRY(subrName);						\
	lwz		r11, [toc]gLVSB##subrName(rtoc);\
	b		CallExtSub						\

#define CommonGlue							\
	.globl CallExtSub;						\
CallExtSub:									\
	lwz		r11, 0(r11)				;\
	stw		r31, 4(r1)				;\
	lwz		r12, 0(r11)				;\
	mflr	r31						;\
	mtctr	r12						;\
	stw		rtoc, 8(r1)				;\
	lwz		rtoc, 4(r11)			;\
	bctrl							;\
									;\
	mtlr	r31						;\
	lwz		r31, 4(r1)				;\
	lwz		r2, 8(r1)				;\
	blr								;\

#elif Win32

#define ExternalSubGlue(subrName)	\
long gLVSB##subrName = 'BSLV';		\
void subrName(void);				\
void subrName(void){				\
	__asm { pop edi				}	\
	__asm { pop esi				}	\
	__asm { pop ebx				}	\
	__asm { leave				}	\
	__asm { push gLVSB##subrName}	\
	__asm { ret 0				}	\
	}								\

#define CommonGlue

#elif OpSystem == kMSWin31

#define ExternalSubGlue(subrName)	\
long gLVSB##subrName='LVSB';		\
void subrName(void);				\
void subrName(void) {				\
	asm {							\
		move.l	gLVSB##subrName, a0 \
		jmp		(a0)				\
		}							\
	}								\

#define CommonGlue

#endif
