#ifndef _W32API_WINSPOOL_H_
#define _W32API_WINSPOOL_H_

#include <windef.h>

#define	SPOOL_PRINTER_ENUM_DEFAULT	0x1
#define	SPOOL_PRINTER_ENUM_LOCAL	0x2
#define	SPOOL_PRINTER_ENUM_CONNECTIONS	0x4
#define	SPOOL_PRINTER_ENUM_FAVORITE	0x4
#define	SPOOL_PRINTER_ENUM_NAME		0x8
#define	SPOOL_PRINTER_ENUM_REMOTE	0x10
#define	SPOOL_PRINTER_ENUM_SHARED	0x20
#define	SPOOL_PRINTER_ENUM_NETWORK	0x40
#define	SPOOL_PRINTER_ENUM_EXPAND	0x4000
#define	SPOOL_PRINTER_ENUM_CONTAINER	0x8000
#define	SPOOL_PRINTER_ENUM_ICON1	0x10000
#define	SPOOL_PRINTER_ENUM_ICON2	0x20000
#define	SPOOL_PRINTER_ENUM_ICON3	0x40000
#define	SPOOL_PRINTER_ENUM_ICON4	0x80000
#define	SPOOL_PRINTER_ENUM_ICON5	0x100000
#define	SPOOL_PRINTER_ENUM_ICON6	0x200000
#define	SPOOL_PRINTER_ENUM_ICON7	0x400000
#define	SPOOL_PRINTER_ENUM_ICON8	0x800000
#define	SPOOL_PRINTER_ENUM_ICONMASK	0xff0000

#define PRINTER_ENUM_DEFAULT		SPOOL_PRINTER_ENUM_DEFAULT
#define PRINTER_ENUM_LOCAL		SPOOL_PRINTER_ENUM_LOCAL
#define PRINTER_ENUM_CONNECTIONS	SPOOL_PRINTER_ENUM_CONNECTIONS
#define PRINTER_ENUM_FAVORITE		SPOOL_PRINTER_ENUM_FAVORITE
#define PRINTER_ENUM_NAME		SPOOL_PRINTER_ENUM_NAME
#define PRINTER_ENUM_REMOTE		SPOOL_PRINTER_ENUM_REMOTE
#define PRINTER_ENUM_SHARED		SPOOL_PRINTER_ENUM_SHARED
#define PRINTER_ENUM_NETWORK		SPOOL_PRINTER_ENUM_NETWORK
#define PRINTER_ENUM_EXPAND		SPOOL_PRINTER_ENUM_EXPAND
#define PRINTER_ENUM_CONTAINER		SPOOL_PRINTER_ENUM_CONTAINER
#define PRINTER_ENUM_ICON1		SPOOL_PRINTER_ENUM_ICON1
#define PRINTER_ENUM_ICON2		SPOOL_PRINTER_ENUM_ICON2
#define PRINTER_ENUM_ICON3		SPOOL_PRINTER_ENUM_ICON3
#define PRINTER_ENUM_ICON4		SPOOL_PRINTER_ENUM_ICON4
#define PRINTER_ENUM_ICON5		SPOOL_PRINTER_ENUM_ICON5
#define PRINTER_ENUM_ICON6		SPOOL_PRINTER_ENUM_ICON6
#define PRINTER_ENUM_ICON7		SPOOL_PRINTER_ENUM_ICON6
#define PRINTER_ENUM_ICON8		SPOOL_PRINTER_ENUM_ICON8
#define PRINTER_ENUM_ICONMASK		SPOOL_PRINTER_ENUM_ICONMASK

struct spool_printer_info_4_ansi {
	LPSTR	pPrinterName;
	LPSTR	pServerName;
	DWORD	Attributes;
};

struct spool_printer_info_4_utf8 {
	LPSTR	pPrinterName;
	LPSTR	pServerName;
	DWORD	Attributes;
};

struct spool_printer_info_4_utf16 {
	LPWSTR	pPrinterName;
	LPWSTR	pServerName;
	DWORD	Attributes;
};

typedef struct spool_printer_info_4_ansi	PRINTER_INFO_4A;
typedef struct spool_printer_info_4_ansi	*PPRINTER_INFO_4A;
typedef struct spool_printer_info_4_ansi	*LPPRINTER_INFO_4A;

typedef struct spool_printer_info_4_utf8	PRINTER_INFO_4M;
typedef struct spool_printer_info_4_utf8	*PPRINTER_INFO_4M;
typedef struct spool_printer_info_4_utf8	*LPPRINTER_INFO_4M;

typedef struct spool_printer_info_4_utf16	PRINTER_INFO_4W;
typedef struct spool_printer_info_4_utf16	*PPRINTER_INFO_4W;
typedef struct spool_printer_info_4_utf16	*LPPRINTER_INFO_4W;

typedef BOOL __stdcall w32api_spool_enum_printers_ansi(
	DWORD,
	LPSTR,
	DWORD,
	PBYTE,
	DWORD,
	PDWORD,
	PDWORD);

typedef BOOL __stdcall w32api_spool_enum_printers_utf8(
	DWORD,
	LPSTR,
	DWORD,
	PBYTE,
	DWORD,
	PDWORD,
	PDWORD);

typedef BOOL __stdcall w32api_spool_enum_printers_utf16(
	DWORD,
	LPWSTR,
	DWORD,
	PBYTE,
	DWORD,
	PDWORD,
	PDWORD);

typedef BOOL __stdcall w32api_spool_get_default_printer_ansi(
	LPSTR,
	LPDWORD);

typedef BOOL __stdcall w32api_spool_get_default_printer_utf8(
	LPSTR,
	LPDWORD);

typedef BOOL __stdcall w32api_spool_get_default_printer_utf16(
	LPWSTR,
	LPDWORD);

__dllimport w32api_spool_enum_printers_ansi		EnumPrintersA;
__dllimport w32api_spool_enum_printers_utf8		EnumPrintersM;
__dllimport w32api_spool_enum_printers_utf16		EnumPrintersW;
__dllimport w32api_spool_get_default_printer_ansi	GetDefaultPrinterA;
__dllimport w32api_spool_get_default_printer_utf8	GetDefaultPrinterM;
__dllimport w32api_spool_get_default_printer_utf16	GetDefaultPrinterW;

#ifdef WINAPI_ANSI_DEFAULT
	#define EnumPrinters				EnumPrintersA
	#define GetDefaultPrinter			GetDefaultPrinterA
#endif

#ifdef WINAPI_UTF8_DEFAULT
	#define EnumPrinters				EnumPrintersM
	#define GetDefaultPrinter			GetDefaultPrinterM
#endif

#ifdef WINAPI_UTF16_DEFAULT
	#define EnumPrinters				EnumPrintersW
	#define GetDefaultPrinter			GetDefaultPrinterW
#endif


#endif
