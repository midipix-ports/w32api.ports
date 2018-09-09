#ifndef _W32API_WINBASE_H_
#define _W32API_WINBASE_H_

#include <windef.h>
#include <winnt.h>
#include <stdint.h>
#include <stdarg.h>
#include <uchar.h>
#include <processthreadsapi.h>

#ifdef __cplusplus
extern "C" {
#endif

#define INVALID_HANDLE_VALUE			(void *)(-1)

#define FORMAT_MESSAGE_MAX_WIDTH_MASK		0x000000FF
#define FORMAT_MESSAGE_ALLOCATE_BUFFER		0x00000100
#define FORMAT_MESSAGE_IGNORE_INSERTS		0x00000200
#define FORMAT_MESSAGE_FROM_STRING		0x00000400
#define FORMAT_MESSAGE_FROM_HMODULE		0x00000800
#define FORMAT_MESSAGE_FROM_SYSTEM		0x00001000
#define FORMAT_MESSAGE_ARGUMENT_ARRAY		0x00002000

#define GMEM_DDESHARE 				0x2000
#define GMEM_MOVEABLE 				0x2

#define MAX_PATH 				0x0104

#define STARTF_TITLEISLINKNAME			0x00000800
#define STARTF_TITLEISAPPID			0x00001000

#define FILE_BEGIN				0
#define FILE_CURRENT				1
#define FILE_END				2
#define FILE_FLAG_WRITE_THROUGH			0x80000000
#define FILE_FLAG_OVERLAPPED			0x40000000
#define FILE_FLAG_NO_BUFFERING			0x20000000
#define FILE_FLAG_RANDOM_ACCESS			0x10000000
#define FILE_FLAG_SEQUENTIAL_SCAN		0x8000000
#define FILE_FLAG_DELETE_ON_CLOSE		0x4000000
#define FILE_FLAG_BACKUP_SEMANTICS		0x2000000
#define FILE_FLAG_POSIX_SEMANTICS		0x1000000
#define FILE_FLAG_SESSION_AWARE			0x800000
#define FILE_FLAG_OPEN_REPARSE_POINT		0x200000
#define FILE_FLAG_OPEN_NO_RECALL		0x100000
#define FILE_FLAG_FIRST_PIPE_INSTANCE		0x80000
#define FILE_FLAG_OPEN_REQUIRING_OPLOCK		0x40000
#define FILE_NAME_NORMALIZED			0x0
#define FILE_NAME_OPENED			0x8
#define FILE_TYPE_UNKNOWN			0x0
#define FILE_TYPE_DISK				0x1
#define FILE_TYPE_CHAR				0x2
#define FILE_TYPE_PIPE				0x3
#define FILE_TYPE_REMOTE			0x8000
#define FILE_SKIP_COMPLETION_PORT_ON_SUCCESS	0x1
#define FILE_SKIP_SET_EVENT_ON_HANDLE		0x2
#define FILE_ENCRYPTABLE			0
#define FILE_IS_ENCRYPTED			1
#define FILE_SYSTEM_ATTR			2
#define FILE_ROOT_DIR				3
#define FILE_SYSTEM_DIR				4
#define FILE_UNKNOWN				5
#define FILE_SYSTEM_NOT_SUPPORT			6
#define FILE_USER_DISALLOWED			7
#define FILE_READ_ONLY				8
#define FILE_DIR_DISALLOWED			9

typedef struct base_file_time        FILETIME;
typedef struct base_file_time       *PFILETIME;

typedef struct base_find_data_ansi   WIN32_FIND_DATAA;
typedef struct base_find_data_ansi  *PWIN32_FIND_DATAA;
typedef struct base_find_data_ansi  *LPWIN32_FIND_DATAA;

typedef struct base_find_data_utf8   WIN32_FIND_DATAM;
typedef struct base_find_data_utf8  *PWIN32_FIND_DATAM;
typedef struct base_find_data_utf8  *LPWIN32_FIND_DATAM;

typedef struct base_find_data_utf16  WIN32_FIND_DATAW;
typedef struct base_find_data_utf16 *PWIN32_FIND_DATAW;
typedef struct base_find_data_utf16 *LPWIN32_FIND_DATAW;


struct base_file_time {
	DWORD	dwLowDateTime;
	DWORD	dwHighDateTime;
};

struct base_find_data_ansi {
	DWORD		dwFileAttributes;
	FILETIME	ftCreationTime;
	FILETIME	ftLastAccessTime;
	FILETIME	ftLastWriteTime;
	DWORD		nFileSizeHigh;
	DWORD		nFileSizeLow;
	DWORD		dwReserved0;
	DWORD		dwReserved1;
	CHAR		cFileName[MAX_PATH];
	CHAR		cAlternateFileName[14];
};

struct base_find_data_utf8 {
	DWORD		dwFileAttributes;
	FILETIME	ftCreationTime;
	FILETIME	ftLastAccessTime;
	FILETIME	ftLastWriteTime;
	DWORD		nFileSizeHigh;
	DWORD		nFileSizeLow;
	DWORD		dwReserved0;
	DWORD		dwReserved1;
	CHAR		cFileName[MAX_PATH];
	CHAR		cAlternateFileName[14];
};

struct base_find_data_utf16 {
	DWORD		dwFileAttributes;
	FILETIME	ftCreationTime;
	FILETIME	ftLastAccessTime;
	FILETIME	ftLastWriteTime;
	DWORD		nFileSizeHigh;
	DWORD		nFileSizeLow;
	DWORD		dwReserved0;
	DWORD		dwReserved1;
	WCHAR		cFileName[MAX_PATH];
	WCHAR		cAlternateFileName[14];
};

typedef DWORD __stdcall w32api_base_get_last_error(void);

typedef HANDLE __stdcall w32api_base_find_first_file_ansi(
	LPCSTR,
	LPWIN32_FIND_DATAA);

typedef HANDLE __stdcall w32api_base_find_first_file_utf8(
	LPCSTR,
	LPWIN32_FIND_DATAM);

typedef HANDLE __stdcall w32api_base_find_first_file_utf16(
	LPCWSTR,
	LPWIN32_FIND_DATAW);

typedef BOOL __stdcall w32api_base_find_next_file_ansi(
	LPCSTR,
	LPWIN32_FIND_DATAA);

typedef BOOL __stdcall w32api_base_find_next_file_utf8(
	LPCSTR,
	LPWIN32_FIND_DATAM);

typedef BOOL __stdcall w32api_base_find_next_file_utf16(
	LPWSTR,
	LPWIN32_FIND_DATAW);

typedef BOOL __stdcall w32api_base_find_close(
	HANDLE);

typedef DWORD __stdcall w32api_base_format_message_ansi(
	DWORD,
	LPCVOID,
	DWORD,
	DWORD,
	LPSTR,
	DWORD,
	va_list *);

typedef DWORD __stdcall w32api_base_format_message_utf8(
	DWORD,
	LPCVOID,
	DWORD,
	DWORD,
	LPSTR,
	DWORD,
	va_list *);

typedef DWORD __stdcall w32api_base_format_message_utf16(
	DWORD,
	LPCVOID,
	DWORD,
	DWORD,
	LPWSTR,
	DWORD,
	va_list *);

__dllimport w32api_base_get_last_error			GetLastError;

__dllexport w32api_base_find_first_file_ansi		FindFirstFileA;
__dllexport w32api_base_find_first_file_utf8		FindFirstFileM;
__dllexport w32api_base_find_first_file_utf16		FindFirstFileW;

__dllexport w32api_base_find_next_file_ansi		FindNextFileA;
__dllexport w32api_base_find_next_file_utf8		FindNextFileM;
__dllexport w32api_base_find_next_file_utf16		FindNextFileW;

__dllexport w32api_base_find_close			FindClose;

__dllimport w32api_base_format_message_ansi		FormatMessageA;
__dllimport w32api_base_format_message_utf8		FormatMessageM;
__dllimport w32api_base_format_message_utf16		FormatMessageW;

typedef struct _STARTUPINFOEXA {
    STARTUPINFOA StartupInfo;
    LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList;
} STARTUPINFOEXA,*LPSTARTUPINFOEXA;

typedef struct _STARTUPINFOEXM {
    STARTUPINFOA StartupInfo;
    LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList;
} STARTUPINFOEXM,*LPSTARTUPINFOEXM;

typedef struct _STARTUPINFOEXW {
    STARTUPINFOW StartupInfo;
    LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList;
} STARTUPINFOEXW,*LPSTARTUPINFOEXW;

__dllimport int __stdcall MulDiv(int nNumber, int nNumerator, int nDenominator);

__dllimport LPVOID __stdcall GlobalLock(HGLOBAL hMem);
__dllimport int __stdcall GlobalUnlock(HGLOBAL hMem);
__dllimport HGLOBAL __stdcall GlobalFree(HGLOBAL hMem);
__dllimport HGLOBAL __stdcall GlobalAlloc(UINT uFlags, SIZE_T dwBytes);
__dllimport HLOCAL __stdcall LocalFree(HLOCAL hMem);
__dllimport HLOCAL __stdcall LocalAlloc(UINT uFlags, SIZE_T uBytes);
__dllimport HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName);
__dllimport HMODULE __stdcall LoadLibraryM(LPCSTR lpLibFileName);
__dllimport HMODULE __stdcall LoadLibraryW(LPCWSTR lpLibFileName);
__dllimport void __stdcall GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
__dllimport void __stdcall GetStartupInfoM(LPSTARTUPINFOM lpStartupInfo);
__dllimport void __stdcall GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
__dllimport int __stdcall VerifyVersionInfoA(LPOSVERSIONINFOEXA lpVersionInformation, DWORD dwTypeMask, DWORDLONG dwlConditionMask);
__dllimport int __stdcall VerifyVersionInfoM(LPOSVERSIONINFOEXM lpVersionInformation, DWORD dwTypeMask, DWORDLONG dwlConditionMask);
__dllimport int __stdcall VerifyVersionInfoW(LPOSVERSIONINFOEXW lpVersionInformation, DWORD dwTypeMask, DWORDLONG dwlConditionMask);


__dllimport DWORD GetCurrentThreadId(void);
__dllimport EXECUTION_STATE __stdcall SetThreadExecutionState(EXECUTION_STATE es);

#ifdef WINAPI_ANSI_DEFAULT
	#define FormatMessage				FormatMessageA
	#define LoadLibrary				LoadLibraryA
	#define GetStartupInfo				GetStartupInfoA
#define VerifyVersionInfo VerifyVersionInfoA

#endif

#ifdef WINAPI_UTF8_DEFAULT
	#define FormatMessage				FormatMessageM
	#define LoadLibrary				LoadLibraryM
	#define GetStartupInfo				GetStartupInfoM
#define VerifyVersionInfo VerifyVersionInfoM
#endif

#ifdef WINAPI_UTF16_DEFAULT
	#define FormatMessage				FormatMessageW
	#define LoadLibrary				LoadLibraryW
	#define GetStartupInfo				GetStartupInfoW
#define VerifyVersionInfo VerifyVersionInfoW
#endif

#ifdef __cplusplus
}
#endif

#endif
