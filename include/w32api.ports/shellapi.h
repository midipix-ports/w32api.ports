#ifndef _W32_SHELLAPI_H_
#define _W32_SHELLAPI_H_

#include <windef.h>
#include <basetyps.h>

struct shellapi_appbardata;

struct shellapi_notify_icon_data_ansi;
struct shellapi_notify_icon_data_utf8;
struct shellapi_notify_icon_data_utf16;


typedef struct shellapi_appbardata		APPBARDATA,*PAPPBARDATA;

typedef struct shellapi_notify_icon_data_ansi		NOTIFYICONDATAA,*PNOTIFYICONDATAA;
typedef struct shellapi_notify_icon_data_utf8		NOTIFYICONDATAM,*PNOTIFYICONDATAM;
typedef struct shellapi_notify_icon_data_utf16		NOTIFYICONDATAW,*PNOTIFYICONDATAW;

#ifdef WINAPI_ANSI_DEFAULT
typedef struct shellapi_notify_icon_data_ansi           NOTIFYICONDATA,*PNOTIFYICONDATA;
#endif

#ifdef WINAPI_UTF8_DEFAULT
typedef struct shellapi_notify_icon_data_utf8           NOTIFYICONDATA,*PNOTIFYICONDATA;
#endif

#ifdef WINAPI_UTF16_DEFAULT
typedef struct shellapi_notify_icon_data_utf16          NOTIFYICONDATA,*PNOTIFYICONDATA;
#endif



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

__dllimport HICON __stdcall ExtractIconA(HINSTANCE hInst, LPCSTR pszExeFileName, UINT nIconIndex);
__dllimport HICON __stdcall ExtractIconM(HINSTANCE hInst, LPCSTR pszExeFileName, UINT nIconIndex);
__dllimport HICON __stdcall ExtractIconW(HINSTANCE hInst, LPCWSTR pszExeFileName, UINT nIconIndex);
__dllimport UINT __stdcall ExtractIconExW(LPCWSTR lpszFile, int nIconIndex, HICON *phiconLarge, HICON *phiconSmall, UINT nIcons);
__dllimport UINT __stdcall DragQueryFileW(HDROP hDrop, UINT iFile, LPWSTR lpszFile, UINT cch);
__dllimport HINSTANCE __stdcall ShellExecuteA(HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd);
__dllimport HINSTANCE __stdcall ShellExecuteM(HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd);
__dllimport HINSTANCE __stdcall ShellExecuteW(HWND hWnd, LPCWSTR lpOperation, LPCWSTR pFile, LPCWSTR lpParameters, LPCWSTR lpDirectory, INT nShowCmd);
__dllimport int __stdcall Shell_NotifyIconA(DWORD dwMessage, PNOTIFYICONDATAA lpData);
__dllimport int __stdcall Shell_NotifyIconM(DWORD dwMessage, PNOTIFYICONDATAM lpData);
__dllimport int __stdcall Shell_NotifyIconW(DWORD dwMessage, PNOTIFYICONDATAW lpData);


__dllimport UINT_PTR __stdcall SHAppBarMessage(DWORD dwMessage, PAPPBARDATA pData);

#ifdef WINAPI_ANSI_DEFAULT
#define ExtractIcon ExtractIconA
#define ShellExecute ShellExecuteA
#define Shell_NotifyIcon Shell_NotifyIconA
#endif

#ifdef WINAPI_UTF8_DEFAULT
#define ExtractIcon ExtractIconM
#define ShellExecute ShellExecuteM
#define Shell_NotifyIcon Shell_NotifyIconM
#endif

#ifdef WINAPI_UTF16_DEFAULT
#define ExtractIcon ExtractIconW
#define ShellExecute ShellExecuteW
#define Shell_NotifyIcon Shell_NotifyIconW
#endif


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

#define NIM_ADD					0x00000000
#define NIM_MODIFY				0x00000001
#define NIM_DELETE				0x00000002
#define NIM_SETFOCUS				0x00000003
#define NIM_SETVERSION				0x00000004

#define NIF_MESSAGE				0x00000001
#define NIF_ICON				0x00000002
#define NIF_TIP					0x00000004
#define NIF_STATE				0x00000008
#define NIF_INFO				0x00000010
#define NIF_GUID				0x00000020
#define NIF_REALTIME				0x00000040
#define NIF_SHOWTIP				0x00000080

#endif
