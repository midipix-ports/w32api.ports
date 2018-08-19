#ifndef _W32_SHELLAPI_H_
#define _W32_SHELLAPI_H_

#include <windef.h>

struct shellapi_appbardata;

typedef struct shellapi_appbardata		APPBARDATA,*PAPPBARDATA;

struct shellapi_appbardata {
	DWORD cbSize;
	HWND hWnd;
	UINT uCallbackMessage;
	UINT uEdge;
	RECT rc;
	LPARAM lParam;
};

__dllimport UINT __stdcall ExtractIconExW(LPCWSTR lpszFile, int nIconIndex, HICON *phiconLarge, HICON *phiconSmall, UINT nIcons);
__dllimport UINT __stdcall DragQueryFileW(HDROP hDrop, UINT iFile, LPWSTR lpszFile, UINT cch);
__dllimport HINSTANCE __stdcall ShellExecuteW(HWND hWnd, LPCWSTR lpOperation, LPCWSTR pFile, LPCWSTR lpParameters, LPCWSTR lpDirectory, INT nShowCmd);

#define ABM_NEW					0x00000000
#define ABM_REMOVE				0x00000001
#define ABM_QUERYPOS				0x00000002
#define ABM_SETPOS				0x00000003
#define ABM_GETSTATE				0x00000004
#define ABM_GETTASKBARPOS			0x00000005
#define ABM_ACTIVATE				0x00000006
#define ABM_GETAUTOHIDEBAR			0x00000007
#define ABM_SETAUTOHIDEBAR			0x00000008
#define ABM_WINDOWPOSCHANGED			0x0000009
#define ABM_SETSTATE				0x0000000a

#define ABS_AUTOHIDE				0x0000001
#define ABS_ALWAYSONTOP				0x0000002

#define ABE_LEFT				0
#define ABE_TOP					1
#define ABE_RIGHT				2
#define ABE_BOTTOM				3

#endif
