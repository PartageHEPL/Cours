/*
 * Code Interface Node header file
 */

/*
 * prototypes
 */

CIN MgErr CINInit(void);
CIN MgErr CINDispose(void);
CIN MgErr CINAbort(void);
CIN MgErr CINRun(LStrHandle var1, LStrHandle var2);
CIN MgErr CINLoad(RsrcFile rf);
CIN MgErr CINUnload(void);
CIN MgErr CINSave(RsrcFile rf);
