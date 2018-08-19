#ifndef _W32API_LIBLOADERAPI_H_
#define _W32API_LIBLOADERAPI_H_

#include <windef.h>

__dllimport FARPROC __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
__dllimport HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName);
__dllimport HMODULE __stdcall GetModuleHandleM(LPCSTR lpModuleName);
__dllimport HMODULE __stdcall GetModuleHandleW(LPCWSTR lpModuleName);
__dllimport HMODULE __stdcall LoadLibraryExA(LPCSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);
__dllimport HMODULE __stdcall LoadLibraryExM(LPCSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);
__dllimport HMODULE __stdcall LoadLibraryExW(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);

__dllimport int __stdcall FreeLibrary(HMODULE lib);


#ifdef WINAPI_ANSI_DEFAULT
#define GetModuleHandle GetModuleHandleA
#define LoadLibraryEx LoadLibraryExA

#endif

#ifdef WINAPI_UTF8_DEFAULT
#define GetModuleHandle GetModuleHandleM
#define LoadLibraryEx LoadLibraryExM

#endif

#ifdef WINAPI_UTF16_DEFAULT
#define GetModuleHandle GetModuleHandleW
#define LoadLibraryEx LoadLibraryExW

#endif


#endif
