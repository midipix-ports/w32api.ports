#ifndef _W32API_DATETIMEAPI_H_
#define _W32API_DATETIMEAPI_H_

#include <windef.h>
#include <wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef int __stdcall w32api_datetimeapi_get_time_format_ex(
	LPCWSTR,
	DWORD,
	const SYSTEMTIME *,
	LPCWSTR,
	LPWSTR,
	int);

typedef int __stdcall w32api_datetimeapi_get_date_format_ex(
	LPCWSTR,
	DWORD,
	const SYSTEMTIME *,
	LPCWSTR,
	LPWSTR,
	int,
	LPCWSTR);

typedef int __stdcall w32api_datetimeapi_get_date_format_ansi(
	LCID,
	DWORD,
	const SYSTEMTIME *,
	LPCSTR,
	LPSTR,
	int);

typedef int __stdcall w32api_datetimeapi_get_date_format_utf8(
	LCID,
	DWORD,
	const SYSTEMTIME *,
	LPCSTR,
	LPSTR,
	int);

typedef int __stdcall w32api_datetimeapi_get_date_format_utf16(
	LCID,
	DWORD,
	const SYSTEMTIME *,
	LPCWSTR,
	LPWSTR,
	int);

typedef int __stdcall w32api_datetimeapi_get_time_format_ansi(
	LCID,
	DWORD,
	const SYSTEMTIME *,
	LPCSTR,
	LPSTR,
	int);

typedef int __stdcall w32api_datetimeapi_get_time_format_utf8(
	LCID,
	DWORD,
	const SYSTEMTIME *,
	LPCSTR,
	LPSTR,
	int);

typedef int __stdcall w32api_datetimeapi_get_time_format_utf16(
	LCID,
	DWORD,
	const SYSTEMTIME *,
	LPCWSTR,
	LPWSTR,
	int);




__dllimport w32api_datetimeapi_get_time_format_ex					GetTimeFormatEx;
__dllimport w32api_datetimeapi_get_date_format_ex					GetDateFormatEx;
__dllimport w32api_datetimeapi_get_date_format_ansi					GetDateFormatA;
__dllimport w32api_datetimeapi_get_date_format_utf8					GetDateFormatM;
__dllimport w32api_datetimeapi_get_date_format_utf16					GetDateFormatW;
__dllimport w32api_datetimeapi_get_time_format_ansi					GetTimeFormatA;
__dllimport w32api_datetimeapi_get_time_format_utf8					GetTimeFormatM;
__dllimport w32api_datetimeapi_get_time_format_utf16					GetTimeFormatW;



#ifdef WINAPI_ANSI_DEFAULT
#define GetDateFormat GetDateFormatA
#define GetTimeFormat GetTimeFormatA
#endif

#ifdef WINAPI_UTF8_DEFAULT
#define GetDateFormat GetDateFormatM
#define GetTimeFormat GetTimeFormatM
#endif

#ifdef WINAPI_UTF16_DEFAULT
#define GetDateFormat GetDateFormatW
#define GetTimeFormat GetTimeFormatW
#endif


#ifdef __cplusplus
}
#endif

#endif /* _W32API_DATETIMEAPI_H_ */
