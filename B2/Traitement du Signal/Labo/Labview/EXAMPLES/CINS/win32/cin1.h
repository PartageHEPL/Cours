/*
 * Code Interface Node header file
 */

/*
 * prototypes
 */

CIN MgErr CINInit(void);
CIN MgErr CINDispose(void);
CIN MgErr CINAbort(void);
CIN MgErr CINRun(int32 *var1, int32 *var2, int32 *var3);
CIN MgErr CINLoad(RsrcFile rf);
CIN MgErr CINUnload(void);
CIN MgErr CINSave(RsrcFile rf);
