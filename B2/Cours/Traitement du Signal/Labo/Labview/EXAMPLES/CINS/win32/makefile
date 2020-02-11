

all: cin1.lsb cin2.lsb lsb1.lsb

cin1.lsb : cin1.c cin1.h
	@$(MAKE) /nologo /f $(CINTOOLSDIR)\ntlvsb.mak name=cin1 type=CIN subrNames=lsb1

cin2.lsb : cin2.c cin2.h
	@$(MAKE) /nologo /f $(CINTOOLSDIR)\ntlvsb.mak name=cin2 type=CIN DEBUG=1 

lsb1.lsb	 : lsb1.c
	@$(MAKE) /nologo /f $(CINTOOLSDIR)\ntlvsb.mak name=lsb1  type=LVSB


clean:
	del *.lsb
	del *.obj

