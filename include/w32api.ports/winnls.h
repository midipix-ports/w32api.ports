#ifndef _W32API_WINNLS_H_
#define _W32API_WINNLS_H_

#include <windef.h>
#include <winbase.h>

#define NLS_CP_ACP			0
#define NLS_CP_OEMCP			1
#define NLS_CP_UTF8			65001

#define NLS_LOCALE_SYSTEM_DEFAULT	0x00000800
#define NLS_LOCALE_USER_DEFAULT		0x00000400
#define NLS_LOCALE_SISO639LANGNAME	0x00000059
#define NLS_LOCALE_SISO3166CTRYNAME	0x0000005a

#define NLS_MB_USEGLYPHCHARS		0x00000004
#define NLS_MB_ERR_INVALID_CHARS	0x00000008
#define NLS_WC_NO_BEST_FIT_CHARS	0x00000400

#define NLS_MAX_LEADBYTES		12
#define NLS_MAX_DEFAULTCHAR		2

#define CP_ACP				NLS_CP_ACP
#define CP_OEMCP			NLS_CP_OEMCP
#define CP_UTF8				NLS_CP_UTF8

#define LOCALE_SYSTEM_DEFAULT		NLS_LOCALE_SYSTEM_DEFAULT
#define LOCALE_USER_DEFAULT		NLS_LOCALE_USER_DEFAULT
#define LOCALE_SISO639LANGNAME		NLS_LOCALE_SISO639LANGNAME
#define LOCALE_SISO3166CTRYNAME		NLS_LOCALE_SISO3166CTRYNAME

#define MB_USEGLYPHCHARS		NLS_MB_USEGLYPHCHARS
#define MB_ERR_INVALID_CHARS		NLS_MB_ERR_INVALID_CHARS
#define WC_NO_BEST_FIT_CHARS		NLS_WC_NO_BEST_FIT_CHARS

#define MAX_LEADBYTES			NLS_MAX_LEADBYTES
#define MAX_DEFAULTCHAR			NLS_MAX_DEFAULTCHAR

#define					MAP_PRECOMPOSED 0x00000020

static inline int w32api_nls_is_high_surrogate(unsigned short c)
{
	return (((c) & 0xFC00) == 0xD800);
}

static inline int w32api_nls_is_low_surrogate(unsigned short c)
{
	return (((c) & 0xFC00) == 0xDC00);
}

static inline int w32api_nls_is_surrogate_pair(
	unsigned short high,
	unsigned short low)
{
	return (w32api_nls_is_high_surrogate(high)
		&& w32api_nls_is_low_surrogate(low));
}

#define IS_HIGH_SURROGATE	w32api_nls_is_high_surrogate
#define IS_LOW_SURROGATE	w32api_nls_is_low_surrogate
#define IS_SURROGATE_PAIR	w32api_nls_is_surrogate_pair

struct nls_cpinfo {
	UINT	MaxCharSize;
	BYTE	DefaultChar[MAX_DEFAULTCHAR];
	BYTE	LeadByte[MAX_LEADBYTES];
};

struct nls_cpinfoex_ansi {
	UINT	MaxCharSize;
	BYTE	DefaultChar[MAX_DEFAULTCHAR];
	BYTE	LeadByte[MAX_LEADBYTES];
	WCHAR	UnicodeDefaultChar;
	UINT	CodePage;
	CHAR	CodePageName[MAX_PATH];
};

struct nls_cpinfoex_utf8 {
	UINT	MaxCharSize;
	BYTE	DefaultChar[MAX_DEFAULTCHAR];
	BYTE	LeadByte[MAX_LEADBYTES];
	WCHAR	UnicodeDefaultChar;
	UINT	CodePage;
	CHAR	CodePageName[MAX_PATH];
};

struct nls_cpinfoex_utf16 {
	UINT	MaxCharSize;
	BYTE	DefaultChar[MAX_DEFAULTCHAR];
	BYTE	LeadByte[MAX_LEADBYTES];
	WCHAR	UnicodeDefaultChar;
	UINT	CodePage;
	WCHAR	CodePageName[MAX_PATH];
};

typedef struct nls_cpinfo		CPINFO,    *LPCPINFO;
typedef struct nls_cpinfoex_ansi	CPINFOEXA, *LPCPINFOEXA;
typedef struct nls_cpinfoex_utf8	CPINFOEXM, *LPCPINFOEXM;
typedef struct nls_cpinfoex_utf16	CPINFOEXW, *LPCPINFOEXW;

#ifdef WINAPI_ANSI_DEFAULT
	typedef struct nls_cpinfoex_ansi	CPINFOEX, *LPCPINFOEX;
#endif

#ifdef WINAPI_UTF8_DEFAULT
	typedef struct nls_cpinfoex_utf8	CPINFOEX, *LPCPINFOEX;
#endif

#ifdef WINAPI_UTF16_DEFAULT
	typedef struct nls_cpinfoex_utf16	CPINFOEX, *LPCPINFOEX;
#endif

typedef UINT     __stdcall w32api_nls_get_ansi_cp(void);
typedef UINT     __stdcall w32api_nls_get_oem_cp(void);
typedef LANGID   __stdcall w32api_nls_get_system_default_ui_language(void);
typedef LANGID   __stdcall w32api_nls_get_user_default_ui_language(void);

typedef BOOL __stdcall w32api_nls_get_cp_info(
	UINT,
	LPCPINFO);

typedef int __stdcall w32api_nls_get_locale_info_ansi(
	LCID,
	LCTYPE,
	LPSTR,
	int);

typedef int __stdcall w32api_nls_get_locale_info_utf8(
	LCID,
	LCTYPE,
	LPSTR,
	int);

typedef int __stdcall w32api_nls_get_locale_info_utf16(
	LCID,
	LCTYPE,
	LPWSTR,
	int);

typedef BOOL __stdcall w32api_nls_get_cp_info_ex_ansi(
	UINT,
	DWORD,
	LPCPINFOEXA);

typedef BOOL __stdcall w32api_nls_get_cp_info_ex_utf8(
	UINT,
	DWORD,
	LPCPINFOEXA);

typedef BOOL __stdcall w32api_nls_get_cp_info_ex_utf16(
	UINT,
	DWORD,
	LPCPINFOEXW);

__dllimport w32api_nls_get_ansi_cp			GetACP;
__dllimport w32api_nls_get_oem_cp			GetOEMCP;
__dllimport w32api_nls_get_cp_info			GetCPInfo;
__dllimport w32api_nls_get_system_default_ui_language	GetSystemDefaultUILanguage;
__dllimport w32api_nls_get_user_default_ui_language	GetUserDefaultUILanguage;

__dllimport w32api_nls_get_cp_info_ex_ansi		GetCPInfoExA;
__dllimport w32api_nls_get_cp_info_ex_utf8		GetCPInfoExM;
__dllimport w32api_nls_get_cp_info_ex_utf16		GetCPInfoExW;

__dllimport w32api_nls_get_locale_info_ansi		GetLocaleInfoA;
__dllimport w32api_nls_get_locale_info_utf8		GetLocaleInfoM;
__dllimport w32api_nls_get_locale_info_utf16		GetLocaleInfoW;

__dllimport int __stdcall FoldStringA(DWORD dwMapFlags, LPCSTR lpSrcStr, int cchSrc, LPSTR lpDestStr, int cchDest);
__dllimport int __stdcall FoldStringM(DWORD dwMapFlags, LPCSTR lpSrcStr, int cchSrc, LPSTR lpDestStr, int cchDest);
__dllimport int __stdcall FoldStringW(DWORD dwMapFlags, LPCWSTR lpSrcStr, int ccSrc, LPWSTR lpDestStr, int cchDest);

#ifdef WINAPI_ANSI_DEFAULT
	#define GetCPInfoEx				GetCPInfoExA
	#define GetLocaleInfo				GetLocaleInfoA

	#define FoldString				FoldStringA
#endif

#ifdef WINAPI_UTF8_DEFAULT
	#define GetCPInfoEx				GetCPInfoExM
	#define GetLocaleInfo				GetLocaleInfoM

	#define FoldString				FoldStringM
#endif

#ifdef WINAPI_UTF16_DEFAULT
	#define GetCPInfoEx				GetCPInfoExW
	#define GetLocaleInfo				GetLocaleInfoW

	#define FoldString				FoldStringW
#endif

#endif
