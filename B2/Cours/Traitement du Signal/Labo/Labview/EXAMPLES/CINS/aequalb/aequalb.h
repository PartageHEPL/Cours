/*
 * Code Interface Node header file
 */

/*
 * prototypes
 */

CIN MgErr CINInit(void);
CIN MgErr CINDispose(void);
CIN MgErr CINAbort(void);
CIN MgErr CINRun(float32 *var1, float32 *var2, LVBoolean *var3);
CIN MgErr CINLoad(RsrcFile rf);
CIN MgErr CINUnload(void);
CIN MgErr CINSave(RsrcFile rf);
