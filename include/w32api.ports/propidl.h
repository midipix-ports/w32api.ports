#ifndef _W32API_PROPIDL_H_
#define _W32API_PROPIDL_H_

#include <windef.h>
#include <wtypes.h>
#include <basetyps.h>

/* prop struct forward declarations */
struct w32api_prop_variant;

/* prop struct typedefs */
typedef struct w32api_prop_variant		PROPVARIANT;

/* prop const struct typedefs */
typedef const struct w32api_prop_variant	*REFPROPVARIANT;

/* prop struct definitions */
struct w32api_prop_variant {
	VARTYPE		vt;
	WORD		wReserved1;
	WORD		wReserved2;
	WORD		wReserved3;

	union {
		CHAR			cVal;
		UCHAR			bVal;
		SHORT			iVal;
		USHORT			uiVal;
		LONG			lVal;
		ULONG			ulVal;
		INT			intVal;
		UINT			uintVal;
		FLOAT			fltVal;
		DOUBLE			dblVal;
		CLSID			*puuid;
		LPSTR			pszVal;
		LPWSTR			pwszVal;
		IUnknown		*punkVal;
		CHAR			*pcVal;
		UCHAR			*pbVal;
		SHORT			*piVal;
		USHORT			*puiVal;
		LONG			*plVal;
		ULONG			*pulVal;
		INT			*pintVal;
		UINT			*puintVal;
		FLOAT			*pfltVal;
		DOUBLE			*pdblVal;
		IUnknown		**ppunkVal;
		PROPVARIANT		*pvarVal;
	};
};

#endif
