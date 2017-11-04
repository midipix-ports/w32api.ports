#ifndef _W32API_OBJIDL_H_
#define _W32API_OBJIDL_H_

#include <windef.h>
#include <wtypes.h>


typedef enum objidl_tymed			TYMED;
typedef struct objidl_dvtargetdevice		DVTARGETDEVICE;
typedef struct objidl_formatetc			FORMATETC;


enum objidl_tymed {
	TYMED_HGLOBAL =		1,
	TYMED_FILE =		2,
	TYMED_ISTREAM =		4,
	TYMED_ISTORAGE =	8,
	TYMED_GDI =		16,
	TYMED_MFPICT =		32,
	TYMED_ENHMF =		64,
	TYMED_NULL =		0
};

struct objidl_dvtargetdevice {
	DWORD			tdSize;
	WORD			tdDriverNameOffset;
	WORD			tdDeviceNameOffset;
	WORD			tdPortNameOffset;
	WORD			tdExtDevmodeOffset;
	BYTE			tdData[1];
};

struct objidl_formatetc {
	CLIPFORMAT		cfFormat;
	DVTARGETDEVICE *	ptd;
	DWORD			dwAspect;
	LONG			lindex;
	DWORD			tymed;
};

#endif
