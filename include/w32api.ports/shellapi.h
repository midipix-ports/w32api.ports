#ifndef _W32_SHELLAPI_H_
#define _W32_SHELLAPI_H_

#include <windef.h>

struct shellapi_appbardata;

struct shellapi_notify_icon_data_ansi;
struct shellapi_notify_icon_data_utf8;
struct shellapi_notify_icon_data_utf16;


typedef struct shellapi_appbardata		APPBARDATA,*PAPPBARDATA;

struct shellapi_notify_icon_data_ansi		NOTIFYICONDATAA,*PNOTIFYICONDATAA;
struct shellapi_notify_icon_data_utf8		NOTIFYICONDATAM,*PNOTIFYICONDATAM;
struct shellapi_notify_icon_data_utf16		NOTIFYICONDATAW,*PNOTIFYICONDATAW;


struct shellapi_appbardata {
	DWORD cbSize;
	HWND hWnd;
	UINT uCallbackMessage;
	UINT uEdge;
	RECT rc;
	LPARAM lParam;
};

struct shellapi_notify_icon_data_ansi {
	DWORD cbSize;
	HWND hWnd;
	UINT uID;
	UINT uFlags;
	UINT uCallbackMessage;
	HICON hIcon;
	CHAR szTip[128];
	DWORD dwState;
	DWORD dwStateMask;
	CHAR szInfo[256];
	union {
		UINT uTimeout;
		UINT uVersion;
	};
	CHAR szInfoTitle[64];
	DWORD dwInfoFlags;
	GUID guidItem;
#if NTDDI_VERSION >= 0x06000000
	HICON hBalloonIcon;
#endif
};

struct shellapi_notify_icon_data_utf8 {
	DWORD cbSize;
	HWND hWnd;
	UINT uID;
	UINT uFlags;
	UINT uCallbackMessage;
	HICON hIcon;
	CHAR szTip[128];
	DWORD dwState;
	DWORD dwStateMask;
	CHAR szInfo[256];
	union {
		UINT uTimeout;
		UINT uVersion;
	};
	CHAR szInfoTitle[64];
	DWORD dwInfoFlags;
	GUID guidItem;
#if NTDDI_VERSION >= 0x06000000
	HICON hBalloonIcon;
#endif
};

struct shellapi_notify_icon_data_utf16 {
	DWORD cbSize;
	HWND hWnd;
	UINT uID;
	UINT uFlags;
	UINT uCallbackMessage;
	HICON hIcon;
	WCHAR szTip[128];
	DWORD dwState;
	DWORD dwStateMask;
	WCHAR szInfo[256];
	union {
		UINT uTimeout;
		UINT uVersion;
	};
	WCHAR szInfoTitle[64];
	DWORD dwInfoFlags;
	GUID guidItem;
#if NTDDI_VERSION >= 0x06000000
	HICON hBalloonIcon;
#endif
};

__dllimport UINT __stdcall ExtractIconExW(LPCWSTR lpszFile, int nIconIndex, HICON *phiconLarge, HICON *phiconSmall, UINT nIcons);
__dllimport UINT __stdcall DragQueryFileW(HDROP hDrop, UINT iFile, LPWSTR lpszFile, UINT cch);
__dllimport HINSTANCE __stdcall ShellExecuteW(HWND hWnd, LPCWSTR lpOperation, LPCWSTR pFile, LPCWSTR lpParameters, LPCWSTR lpDirectory, INT nShowCmd);

__dllimport UINT_PTR __stdcall SHAppBarMessage(DWORD dwMessage, PAPPBARDATA pData);


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
