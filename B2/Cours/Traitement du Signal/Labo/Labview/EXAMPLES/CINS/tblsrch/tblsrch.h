/*
 * Code Interface Node header file
 */

/*
 * typedefs
 */

typedef struct {
	int16 arg1;
	LStrHandle arg2;
	} TD2;

typedef struct {
	int32 dimSize;
	TD2 arg1[1];
	} TD1;
typedef TD1 **TD1Hdl;

/*
 * prototypes
 */

CIN MgErr CINInit(void);
CIN MgErr CINDispose(void);
CIN MgErr CINAbort(void);
CIN MgErr CINRun(TD1Hdl var1, TD2 *var2, LVBoolean *var3, int32 *var4);
CIN MgErr CINLoad(RsrcFile rf);
CIN MgErr CINUnload(void);
CIN MgErr CINSave(RsrcFile rf);
