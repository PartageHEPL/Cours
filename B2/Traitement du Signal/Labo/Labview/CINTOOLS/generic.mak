# Different versions of CINs
# 1 Watcom CIN with register passing
# 2 Watcom CIN with stack passing
CIN_VERS = 2

!ifdef subrNames
SUBROBJ = $(name).lob
SUBRGLU = $(name).glu
!endif
!ifeq type CIN
CINOBJ		=  $(cinToolsDir)\win16\cinmain.obj $(cinToolsDir)\win16\cinetc.obj
!endif
!ifdef rsrcFile
RF = -r $(rsrcFile)
!endif

LVSBOBJS	= $(name).obj $(cinToolsDir)\win16\lvsbstrt.obj
ASMOPTS		= -80387 -i $(cinToolsDir)\
COMPOPTS	= /dWIN386 /zw /s /j /7 /i=$(cinToolsDir)\ /i=$(inclDir)\ /i=$(inclDir2)\ /w3 /dCIN_VERS=$(CIN_VERS)

!ifeq CIN_VERS 1
WCOPTS	= $(COMPOPTS) /4r
!else	ifeq CIN_VERS 2
WCOPTS	= $(COMPOPTS) /4s
!else
!error	 Incorrect version of CIN
!endif

WCC			= wcc386 $(WCOPTS)

$(name).lsb : $(name).lnk $(LVSBOBJS) $(SUBROBJ) $(CINOBJ) $(objFiles) $(cinToolsDir)\win16\lvsbutil.exe
	wlink op map=$(name).map op c form pharlap rex n $(name).tmp @$(name).lnk f $(cinToolsDir)\win16\cinetc.obj
	set DOS4G=quiet
	dos4gw $(cinToolsDir)\win16\lvsbutil -c $(name) -t $(type) -d $(codeDir)\ $(RF) -v $(CIN_VERS)

$(name).lnk $(SUBRGLU) : $(name).lvm $(cinToolsDir)\win16\lvextmak.exe
	set DOS4G=quiet
	dos4gw $(cinToolsDir)\win16\lvextmak -f $(name).lvm

!ifdef subrNames
$(name).lob : $(name).glu
	wcc386 /os /s /fo=$(name).lob $(name).glu
!endif

.c.obj :
	del $^&.err
	del $^&.obj
	$(WCC) $<
