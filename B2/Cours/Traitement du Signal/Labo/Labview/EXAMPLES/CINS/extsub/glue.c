long gLVSBsum='LVSB';
void sum(void);
void sum(void) {
	asm {
		move.l	gLVSBsum, a0
		jmp		(a0)
		}
	}