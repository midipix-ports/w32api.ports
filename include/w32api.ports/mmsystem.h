#ifndef _W32API_MMSYSTEM_H_
#define _W32API_MMSYSTEM_H_

#include <windef.h>
#include <winnt.h>

struct mmsystem_wavehdr;
struct mmsystem_wave_format_ex;

typedef struct mmsystem_wavehdr         WAVEHDR,*PWAVEHDR,*NPWAVEHDR,*LPWAVEHDR;
typedef struct mmsystem_wave_format_ex	WAVEFORMATEX,*PWAVEFORMATEX,*NPWAVEFORMATEX,*LPWAVEFORMATEX;

struct mmsystem_wavehdr {
	LPSTR lpData;
	DWORD dwBufferLength;
	DWORD dwBytesRecorded;
	DWORD_PTR dwUser;
	DWORD dwFlags;
	DWORD dwLoops;
	struct wavehdr_tag *lpNext;
	DWORD_PTR reserved;
};

struct mmsystem_wave_format_ex {
	WORD wFormatTag;
	WORD nChannels;
	DWORD nSamplesPerSec;
	DWORD nAvgBytesPerSec;
	WORD nBlockAlign;
	WORD wBitsPerSample;
	WORD cbSize;
};


#define SND_ASYNC	 		0x0001
#define SND_FILENAME 			(uint32_t)(0x00020000)

#define WHDR_DONE			0x00000001
#define WHDR_PREPARED			0x00000002
#define WHDR_BEGINLOOP			0x00000004
#define WHDR_ENDLOOP			0x00000008
#define WHDR_INQUEUE			0x00000010

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
