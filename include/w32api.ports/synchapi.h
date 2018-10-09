#ifndef W32API_SYNCHAPI_H_
#define W32API_SYNCHAPI_H_

#include <windef.h>
#include <minwinbase.h>

__dllimport DWORD __stdcall SleepEx(DWORD dwMilliseconds, int bAlertable);
__dllimport void __stdcall Sleep(DWORD dwMilliseconds);

__dllimport HANDLE __stdcall CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes, int bManualReset, int bInitialState, LPCSTR lpName);
__dllimport HANDLE __stdcall CreateEventM(LPSECURITY_ATTRIBUTES lpEventAttributes, int bManualReset, int bInitialState, LPCSTR lpName);
__dllimport HANDLE __stdcall CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes, int bManualReset, int bInitialState, LPCWSTR lpName);

#ifdef WINAPI_ANSI_DEFAULT
#define CreateEvent CreateEventA
#endif

#ifdef WINAPI_UTF8_DEFAULT
#define CreateEvent CreateEventM
#endif

#ifdef WINAPI_UTF16_DEFAULT
#define CreateEvent CreateEventW
#endif


#endif
