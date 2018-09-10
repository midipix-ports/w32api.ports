#ifndef _W32API_DATETIMEAPI_H_
#define _W32API_DATETIMEAPI_H_

#include <windef.h>
#include <wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif


__dllimport int __stdcall GetTimeFormatEx (LPCWSTR lpLocaleName, DWORD dwFlags, const SYSTEMTIME *lpTime, LPCWSTR lpFormat, LPWSTR lpTimeStr, int cchTime);
__dllimport int __stdcall GetDateFormatEx (LPCWSTR lpLocaleName, DWORD dwFlags, const SYSTEMTIME *lpDate, LPCWSTR lpFormat, LPWSTR lpDateStr, int cchDate, LPCWSTR lpCalendar);

__dllimport int __stdcall GetDateFormatA (LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpDate, LPCSTR lpFormat, LPSTR lpDateStr, int cchDate);
__dllimport int __stdcall GetDateFormatM (LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpDate, LPCSTR lpFormat, LPSTR lpDateStr, int cchDate);
__dllimport int __stdcall GetDateFormatW (LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpDate, LPCWSTR lpFormat, LPWSTR lpDateStr, int cchDate);
__dllimport int __stdcall GetTimeFormatA (LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpTime, LPCSTR lpFormat, LPSTR lpTimeStr, int cchTime);
__dllimport int __stdcall GetTimeFormatM (LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpTime, LPCSTR lpFormat, LPSTR lpTimeStr, int cchTime);
__dllimport int __stdcall GetTimeFormatW (LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpTime, LPCWSTR lpFormat, LPWSTR lpTimeStr, int cchTime);

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

#endif
