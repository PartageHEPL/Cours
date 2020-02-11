/*
 * Code Interface Node header file
 */

/*
 * typedefs
 */

typedef struct {
	int32 dimSizes[2];
	float64 arg1[1];
	} TD1;
typedef TD1 **TD1Hdl;

/*
 * prototypes
 */

CIN MgErr CINInit(void);
CIN MgErr CINDispose(void);
CIN MgErr CINAbort(void);
CIN MgErr CINRun(TD1Hdl var1, TD1Hdl var2, TD1Hdl var3, LVBoolean *var4);
CIN MgErr CINLoad(RsrcFile rf);
CIN MgErr CINUnload(void);
CIN MgErr CINSave(RsrcFile rf);
