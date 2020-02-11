
# Different versions of CINs
# 1 Watcom CIN with register passing
# 2 Watcom CIN with stack passing
# 3 Microsoft C Win32 SDK compiler
CIN_VERS = 3

!ifndef CPU
CPU=i386
!endif

ASM = masm386 -Mx -Zi -Zd -c -w1 -t -DWIN32 $(ASMINCLUDES)


!include <ntwin32.mak>

!if "$(CPU)" == "PPC"
CCOMP	= $(CC) -nologo -c -W3 -Zi -Od -MT $(CINCLUDES)
OBJEXT= .ppc
ExportFile = $(OBJDIR)\lvsbmain.ppc.exp
!else
!if "$(CC)" == "cl"
CCOMP	= $(CC) -nologo -c -G3 -W3 -Zi -Zp1 -Od -MT $(CINCLUDES)
OBJEXT=
ExportFile = $(OBJDIR)\lvsbmain.exp
!else
!if "$(CC)" == "sc"
CCOMP	= $(CC) -mn -o+time -WD -3 -a1 -c $(CINCLUDES)
OBJEXT = .sym
ExportFile = $(OBJDIR)\lvsbmain.def
!else
!error What compiler are we using?
!endif
!endif
!endif

!ifdef codeDir
CODEDIR2 = -d $(codeDir)
!endif

!ifdef rsrcFile
RF = -r $(rsrcFile)
!endif

!ifndef cinToolsDir
cinToolsDir=$(CINTOOLSDIR)
!endif

!ifndef cinToolsDir
error:
	   @echo ERROR : cinToolsDir not var defined.
	   @echo add it as an environment variable or define it in the makefile.
!endif

!ifndef CINCLUDES
CINCLUDES= -I$(CINTOOLSDIR)
!endif

!ifdef subrNames
LVSBINP	 = lvsbinp.obj
!endif

OBJDIR	 = $(CINTOOLSDIR)\win32
BINDIR	 = $(CINTOOLSDIR)\win32
OBJS	 = $(name).obj $(objFiles) $(OBJDIR)\labview$(OBJEXT).lib $(OBJDIR)\lvsb$(OBJEXT).lib $(OBJDIR)\get$(type)$(OBJEXT).obj

$(name).lsb : $(name).map
	@$(BINDIR)\lvsbutil -c $(name) -t $(type) \
		$(CODEDIR2) $(RF) -v $(CIN_VERS)
	@del $(name).dll >NUL

clean :
	@del $(name).map
	@del $(name).obj
	@del $(name).dll
	@del $(name).lsb

$(name).map : $(OBJS) $(ExportFile)
!ifdef subrNames
	@echo "Building link info for " $(subrNames)
	@$(BINDIR)\genlvinp $(subrNames) >lvsbinp.c
!if "$(CPU)" == "i386"
	@$(CCOMP) lvsbinp.c
!else
	@$(CCOMP) -EP lvsbinp.c > lvsbinp.asm
	@pas -o lvsbinp.obj lvsbinp.asm
!endif
!endif
!if "$(CC)" == "sc"
	@$(link) /NOI /DO /DE /E /PACKF /XN /NT \
		/ENTRY:__DllMainCRTStartup@12 @<<
		$(OBJS) $(LVSBINP)
		$(name).dll
		$(name)._mp
		$(cinLibraries) $(olelibsmt)
		$(ExportFile)
<<
!else
	@$(link) -dll -out:$(name).dll -map:$(name)._mp \
!ifdef DEBUG
		-debug:full -debugtype:cv \
!endif
		$(ExportFile) $(OBJS) $(LVSBINP) $(cinLibraries) $(olelibsmt)
!endif
!ifdef subrNames
!if "$(CPU)" == "i386"
	@find "LVSBStart_" <$(name)._mp > $(name).map
!else
	@find " LVSBHead" <$(name)._mp > $(name).map
!endif
	@find "gLVSB" <$(name)._mp >> $(name).map
	@del lvsbinp.c	>NUL
	@del lvsbinp.obj >NUL
!else
	@echo X >$(name).map
!endif
	@del $(name)._mp >NUL


.c.obj :
	@$(CCOMP) $<
