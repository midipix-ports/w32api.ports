#ifndef _W32API_SYSINFOAPI_H_
#define _W32API_SYSINFOAPI_H_

#include <windef.h>


__dllimport UINT __stdcall GetSystemDirectoryA(LPSTR lpBuffer, UINT uSize);
__dllimport UINT __stdcall GetSystemDirectoryM(LPSTR lpBuffer, UINT uSize);
__dllimport UINT __stdcall GetSystemDirectoryW(LPWSTR lpBuffer, UINT uSize);
__dllimport DWORD __stdcall GetTickCount(void);


#ifdef WINAPI_ANSI_DEFAULT
#define GetSystemDirectory GetSystemDirectoryA


#endif

#ifdef WINAPI_UTF8_DEFAULT
#define GetSystemDirectory GetSystemDirectoryM


#endif

#ifdef WINAPI_UTF16_DEFAULT
#define GetSystemDirectory GetSystemDirectoryW


#endif



#endif