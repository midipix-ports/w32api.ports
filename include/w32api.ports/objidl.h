#ifndef _W32API_OBJIDL_H_
#define _W32API_OBJIDL_H_

#include <windef.h>
#include <wtypes.h>

#include "basetyps.h"
#include "objfwd.h"
#include "olectlid.h"

enum    w32api_objidl_tymed;
struct  w32api_objidl_dvtargetdevice;
struct  w32api_objidl_formatetc;
struct  w32api_objidl_stdmedium;

typedef enum   w32api_objidl_tymed			TYMED;
typedef struct w32api_objidl_dvtargetdevice		DVTARGETDEVICE;
typedef struct w32api_objidl_formatetc			FORMATETC;
typedef struct w32api_objidl_stgmedium			STGMEDIUM,*LPSTGMEDIUM;

enum w32api_objidl_tymed {
	TYMED_HGLOBAL =		1,
	TYMED_FILE =		2,
	TYMED_ISTREAM =		4,
	TYMED_ISTORAGE =	8,
	TYMED_GDI =		16,
	TYMED_MFPICT =		32,
	TYMED_ENHMF =		64,
	TYMED_NULL =		0
};

struct w32api_objidl_dvtargetdevice {
	DWORD			tdSize;
	WORD			tdDriverNameOffset;
	WORD			tdDeviceNameOffset;
	WORD			tdPortNameOffset;
	WORD			tdExtDevmodeOffset;
	BYTE			tdData[1];
};

struct w32api_objidl_formatetc {
	CLIPFORMAT		cfFormat;
	DVTARGETDEVICE *	ptd;
	DWORD			dwAspect;
	LONG			lindex;
	DWORD			tymed;
};

struct w32api_objidl_stgmedium {
	uint32_t		tymed;
	union {
		HBITMAP hBitmap;
		PVOID hMetaFilePict;
		HENHMETAFILE hEnhMetaFile;
		HGLOBAL hGlobal;
		LPWSTR lpszFileName;
		LPSTREAM pstm;
		LPSTORAGE pstg;
	};

	LPUNKNOWN pUnkForRelease;
};

/* COM interface: IDataObject */
EXTERN_C const IID IID_IDataObject;

typedef struct IAdviseSink	IAdviseSink;
typedef struct IEnumFORMATETC	IEnumFORMATETC;
typedef struct IEnumSTATDATA	IEnumSTATDATA;

#define INTERFACE  IDataObject
DECLARE_INTERFACE_(IDataObject,IUnknown) {
	STDMETHOD	(QueryInterface)	(THIS_ REFIID,PVOID*) PURE;
	STDMETHOD_	(ULONG,AddRef)		(THIS) PURE;
	STDMETHOD_	(ULONG,Release)		(THIS) PURE;
	STDMETHOD	(GetData)		(THIS_ FORMATETC*,STGMEDIUM*) PURE;
	STDMETHOD	(GetDataHere)		(THIS_ FORMATETC*,STGMEDIUM*) PURE;
	STDMETHOD	(QueryGetData)		(THIS_ FORMATETC*) PURE;
	STDMETHOD	(GetCanonicalFormatEtc)	(THIS_ FORMATETC*,FORMATETC*) PURE;
	STDMETHOD	(SetData)		(THIS_ FORMATETC*,STGMEDIUM*,BOOL) PURE;
	STDMETHOD	(EnumFormatEtc)		(THIS_ DWORD,IEnumFORMATETC**) PURE;
	STDMETHOD	(DAdvise)		(THIS_ FORMATETC*,DWORD,IAdviseSink*,PDWORD) PURE;
	STDMETHOD	(DUnadvise)		(THIS_ DWORD) PURE;
	STDMETHOD	(EnumDAdvise)		(THIS_ IEnumSTATDATA**) PURE;
};
#undef INTERFACE

#endif
