#ifndef _W32API_IMM_H_
#define _W32API_IMM_H_

#include <stdint.h>
#include <windef.h>
#include <wingdi.h>

typedef uint32_t				HIMC;

#define CFS_POINT 				0x0002

  typedef struct tagCOMPOSITIONFORM {
    DWORD dwStyle;
    POINT ptCurrentPos;
    RECT rcArea;
  } COMPOSITIONFORM,*PCOMPOSITIONFORM,*NPCOMPOSITIONFORM,*LPCOMPOSITIONFORM;

#define IMN_SETOPENSTATUS 			0x0008

#define GCS_RESULTSTR 				0x0800

__dllimport int __stdcall ImmSetCompositionWindow(HIMC, LPCOMPOSITIONFORM);
__dllimport int __stdcall ImmIsIME(HKL);//HKL
__dllimport HIMC __stdcall ImmGetContext(HWND);
__dllimport int __stdcall ImmGetOpenStatus(HIMC);

__dllimport int __stdcall ImmSetCompositionFontA(HIMC, LPLOGFONTA);
__dllimport int __stdcall ImmSetCompositionFontM(HIMC, LPLOGFONTM);
__dllimport int __stdcall ImmSetCompositionFontW(HIMC, LPLOGFONTW);
__dllimport LONG __stdcall ImmGetCompositionStringA(HIMC, DWORD, LPVOID, DWORD);
__dllimport LONG __stdcall ImmGetCompositionStringM(HIMC, DWORD, LPVOID, DWORD);
__dllimport LONG __stdcall ImmGetCompositionStringW(HIMC, DWORD, LPVOID, DWORD);


#ifdef WINAPI_ANSI_DEFAULT
#define ImmSetCompositionFont ImmSetCompositionFontA
#define ImmGetCompositionString ImmGetCompositionStringA

#endif

#ifdef WINAPI_UTF8_DEFAULT
#define ImmSetCompositionFont ImmSetCompositionFontM
#define ImmGetCompositionString ImmGetCompositionStringM

#endif

#ifdef WINAPI_UTF16_DEFAULT
#define ImmSetCompositionFont ImmSetCompositionFontW
#define ImmGetCompositionString ImmGetCompositionStringW

#endif


#endif
