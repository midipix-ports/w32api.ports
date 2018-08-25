#ifndef W32API_SYNCHAPI_H_
#define W32API_SYNCHAPI_H_

#include <windef.h>

__dllimport DWORD __stdcall SleepEx(DWORD dwMilliseconds, int bAlertable);
__dllimport void __stdcall Sleep(DWORD dwMilliseconds);


#endif
