#ifndef _W32API_PROCESSTHREADSAPI_H_
#define _W32API_PROCESSTHREADSAPI_H_

#include <windef.h>
#include <minwinbase.h>

typedef struct _PROC_THREAD_ATTRIBUTE_LIST *PPROC_THREAD_ATTRIBUTE_LIST, *LPPROC_THREAD_ATTRIBUTE_LIST;

struct processthreadsapi_startupinfo_ansi;
struct processthreadsapi_startupinfo_utf8;
struct processthreadsapi_startupinfo_utf16;

struct processthreadsapi_process_information;


typedef struct processthreadsapi_startupinfo_ansi		STARTUPINFOA, *LPSTARTUPINFOA;
typedef struct processthreadsapi_startupinfo_utf8		STARTUPINFOM, *LPSTARTUPINFOM;
typedef struct processthreadsapi_startupinfo_utf16		STARTUPINFOW, *LPSTARTUPINFOW;

typedef struct processthreadsapi_process_information		PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;


struct processthreadsapi_process_information {
	HANDLE hProcess;
	HANDLE hThread;
	DWORD dwProcessId;
	DWORD dwThreadId;
};

struct processthreadsapi_startupinfo_ansi {
	DWORD cb;
	LPSTR lpReserved;
	LPSTR lpDesktop;
	LPSTR lpTitle;
	DWORD dwX;
	DWORD dwY;
	DWORD dwXSize;
	DWORD dwYSize;
	DWORD dwXCountChars;
	DWORD dwYCountChars;
	DWORD dwFillAttribute;
	DWORD dwFlags;
	WORD wShowWindow;
	WORD cbReserved2;
	LPBYTE lpReserved2;
	HANDLE hStdInput;
	HANDLE hStdOutput;
	HANDLE hStdError;
};

struct processthreadsapi_startupinfo_utf8 {
	DWORD cb;
	LPSTR lpReserved;
	LPSTR lpDesktop;
	LPSTR lpTitle;
	DWORD dwX;
	DWORD dwY;
	DWORD dwXSize;
	DWORD dwYSize;
	DWORD dwXCountChars;
	DWORD dwYCountChars;
	DWORD dwFillAttribute;
	DWORD dwFlags;
	WORD wShowWindow;
	WORD cbReserved2;
	LPBYTE lpReserved2;
	HANDLE hStdInput;
	HANDLE hStdOutput;
	HANDLE hStdError;
};

struct processthreadsapi_startupinfo_utf16 {
	DWORD cb;
	LPWSTR lpReserved;
	LPWSTR lpDesktop;
	LPWSTR lpTitle;
	DWORD dwX;
	DWORD dwY;
	DWORD dwXSize;
	DWORD dwYSize;
	DWORD dwXCountChars;
	DWORD dwYCountChars;
	DWORD dwFillAttribute;
	DWORD dwFlags;
	WORD wShowWindow;
	WORD cbReserved2;
	LPBYTE lpReserved2;
	HANDLE hStdInput;
	HANDLE hStdOutput;
	HANDLE hStdError;
};

__dllimport HANDLE __stdcall CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
__dllimport DWORD __stdcall GetCurrentProcessId(void);


#ifdef WINAPI_ANSI_DEFAULT
typedef struct processthreadsapi_startupinfo_ansi		STARTUPINFO, *LPSTARTUPINFO;
#endif


#ifdef WINAPI_UTF8_DEFAULT
typedef struct processthreadsapi_startupinfo_utf8		STARTUPINFO, *LPSTARTUPINFO;
#endif


#ifdef WINAPI_UTF16_DEFAULT
typedef struct processthreadsapi_startupinfo_utf16		STARTUPINFO, *LPSTARTUPINFO;
#endif


#endif
