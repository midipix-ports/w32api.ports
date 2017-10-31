#ifndef _W32API_LIBLOADERAPI_H_
#define _W32API_LIBLOADERAPI_H_

#include <windef.h>

__dllimport FARPROC __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
__dllimport HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName);
__dllimport HMODULE __stdcall GetModuleHandleM(LPCSTR lpModuleName);
__dllimport HMODULE __stdcall GetModuleHandleW(LPCWSTR lpModuleName);


#ifdef WINAPI_ANSI_DEFAULT
#define GetModuleHandle GetModuleHandleA


#endif

#ifdef WINAPI_UTF8_DEFAULT
#define GetModuleHandle GetModuleHandleM


#endif

#ifdef WINAPI_UTF16_DEFAULT
#define GetModuleHandle GetModuleHandleW


#endif


#endif
