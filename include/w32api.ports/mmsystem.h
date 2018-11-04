#ifndef _W32API_MMSYSTEM_H_
#define _W32API_MMSYSTEM_H_

#include <windef.h>
#include <winnt.h>

typedef DWORD MCIERROR;
typedef UINT MMRESULT;

DECLARE_HANDLE(HWAVEOUT);

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

#define MMSYSERR_BASE			0
#define MMSYSERR_NOERROR		0
#define MMSYSERR_ERROR			(MMSYSERR_BASE + 1)
#define MMSYSERR_BADDEVICEID		(MMSYSERR_BASE + 2)
#define MMSYSERR_NOTENABLED		(MMSYSERR_BASE + 3)
#define MMSYSERR_ALLOCATED		(MMSYSERR_BASE + 4)
#define MMSYSERR_INVALHANDLE		(MMSYSERR_BASE + 5)
#define MMSYSERR_NODRIVER		(MMSYSERR_BASE + 6)
#define MMSYSERR_NOMEM			(MMSYSERR_BASE + 7)
#define MMSYSERR_NOTSUPPORTED		(MMSYSERR_BASE + 8)
#define MMSYSERR_BADERRNUM		(MMSYSERR_BASE + 9)
#define MMSYSERR_INVALFLAG		(MMSYSERR_BASE + 10)
#define MMSYSERR_INVALPARAM		(MMSYSERR_BASE + 11)
#define MMSYSERR_HANDLEBUSY		(MMSYSERR_BASE + 12)
#define MMSYSERR_INVALIDALIAS		(MMSYSERR_BASE + 13)
#define MMSYSERR_BADDB			(MMSYSERR_BASE + 14)
#define MMSYSERR_KEYNOTFOUND		(MMSYSERR_BASE + 15)
#define MMSYSERR_READERROR		(MMSYSERR_BASE + 16)
#define MMSYSERR_WRITEERROR		(MMSYSERR_BASE + 17)
#define MMSYSERR_DELETEERROR		(MMSYSERR_BASE + 18)
#define MMSYSERR_VALNOTFOUND		(MMSYSERR_BASE + 19)
#define MMSYSERR_NODRIVERCB		(MMSYSERR_BASE + 20)
#define MMSYSERR_MOREDATA		(MMSYSERR_BASE + 21)
#define MMSYSERR_LASTERROR		(MMSYSERR_BASE + 21)

#define WAVERR_BASE			32
#define WAVERR_BADFORMAT		(WAVERR_BASE + 0)
#define WAVERR_STILLPLAYING		(WAVERR_BASE + 1)
#define WAVERR_UNPREPARED		(WAVERR_BASE + 2)
#define WAVERR_SYNC			(WAVERR_BASE + 3)
#define WAVERR_LASTERROR		(WAVERR_BASE + 3)

#define CALLBACK_EVENT			(uint32_t)(0x00050000)

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
