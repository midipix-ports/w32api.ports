#ifndef _W32API_MMSYSTEM_H_
#define _W32API_MMSYSTEM_H_

#include <windef.h>

#define SND_ASYNC	 		0x0001
#define SND_FILENAME 			(0x00020000)//__MSABI_LONG(0x00020000)

__stdcall int __stdcall PlaySoundA(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
__stdcall int __stdcall PlaySoundM(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
__stdcall int __stdcall PlaySoundW(LPCWSTR pszSound, HMODULE hmod, DWORD fdwSound);

#ifdef WINAPI_ANSI_DEFAULT
#define PlaySound PlaySoundA


#endif

#ifdef WINAPI_UTF8_DEFAULT
#define PlaySound PlaySoundM


#endif

#ifdef WINAPI_UTF16_DEFAULT
#define PlaySound PlaySoundW


#endif

#endif
