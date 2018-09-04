#ifndef _W32API_SYSINFOAPI_H_
#define _W32API_SYSINFOAPI_H_

#include <windef.h>


__dllimport UINT __stdcall GetSystemDirectoryA(LPSTR lpBuffer, UINT uSize);
__dllimport UINT __stdcall GetSystemDirectoryM(LPSTR lpBuffer, UINT uSize);
__dllimport UINT __stdcall GetSystemDirectoryW(LPWSTR lpBuffer, UINT uSize);
__dllimport int __stdcall GetVersionExA(LPOSVERSIONINFOA lpVersionInformation);
__dllimport int __stdcall GetVersionExM(LPOSVERSIONINFOM lpVersionInformation);
__dllimport int __stdcall GetVersionExW(LPOSVERSIONINFOW lpVersionInformation);

__dllimport DWORD __stdcall GetTickCount(void);
__dllimport void __stdcall GetLocalTime(LPSYSTEMTIME lpSystemTime);


#ifdef WINAPI_ANSI_DEFAULT
#define GetSystemDirectory GetSystemDirectoryA
#define GetVersionEx GetVersionExA

#endif

#ifdef WINAPI_UTF8_DEFAULT
#define GetSystemDirectory GetSystemDirectoryM
#define GetVersionEx GetVersionExM

#endif

#ifdef WINAPI_UTF16_DEFAULT
#define GetSystemDirectory GetSystemDirectoryW
#define GetVersionEx GetVersionExW

#endif



#endif
