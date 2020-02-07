/*
 * Code Interface Node header file
 */

/*
 * typedefs
 */

typedef struct {
	int32 dimSize;
	float64 arg1[1];
	} TD1;
typedef TD1 **TD1Hdl;

/*
 * prototypes
 */

CIN MgErr CINInit(void);
CIN MgErr CINDispose(void);
CIN MgErr CINAbort(void);
CIN MgErr CINRun(TD1Hdl var1, float64 *var2);
CIN MgErr CINLoad(RsrcFile rf);
CIN MgErr CINUnload(void);
CIN MgErr CINSave(RsrcFile rf);
