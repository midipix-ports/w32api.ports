#ifndef _W32API_WTYPES_H_
#define _W32API_WTYPES_H_

#include <stdint.h>
#include <sys/types.h>

#include <windef.h>
#include <basetyps.h>

/* scalar typedefs */
typedef long double		DOUBLE;
typedef USHORT			VARTYPE;
typedef WORD			CLIPFORMAT;
typedef CLIPFORMAT		*LPCLIPFORMAT;

typedef LPSTR			LPOLESTR;
typedef LPCSTR			LPCOLESTR;
typedef LPWSTR			LPOLEWSTR;
typedef LPCWSTR			LPCOLEWSTR;

/* enum and struct forward declarations */
enum   w32api_var_enum;
enum   w32api_wtypes_dvaspect;
struct w32api_wtypes_property_key;


/* enum and struct typedefs */
typedef enum   w32api_var_enum				VARENUM;
typedef enum   w32api_wtypes_dvaspect			DVASPECT;
typedef struct w32api_wtypes_property_key		PROPERTYKEY;

/* const struct typedefs */
typedef const struct w32api_wtypes_property_key		*REFPROPERTYKEY;

/* enum and struct definitions */
enum w32api_var_enum {
	VT_EMPTY,
	VT_NULL,
	VT_I2,
	VT_I4,
	VT_R4,
	VT_R8,
	VT_CY,
	VT_DATE,
	VT_BSTR,
	VT_DISPATCH,
	VT_ERROR,
	VT_BOOL,
	VT_VARIANT,
	VT_UNKNOWN,
	VT_DECIMAL,
	VT_UNUSED_15,
	VT_I1,
	VT_UI1,
	VT_UI2,
	VT_UI4,
	VT_I8,
	VT_UI8,
	VT_INT,
	VT_UINT,
	VT_VOID,
	VT_HRESULT,
	VT_PTR,
	VT_SAFEARRAY,
	VT_CARRAY,
	VT_USERDEFINED,
	VT_LPSTR,
	VT_LPWSTR,
	VT_UNUSED_32,
	VT_UNUSED_33,
	VT_UNUSED_34,
	VT_UNUSED_35,
	VT_RECORD,
	VT_INT_PTR,
	VT_UINT_PTR,
	/* oh no, more are coming! */
	VT_FILETIME		= 64,
	VT_BLOB,
	VT_STREAM,
	VT_STORAGE,
	VT_STREAMED_OBJECT,
	VT_STORED_OBJECT,
	VT_BLOB_OBJECT,
	VT_CF,
	VT_CLSID,
	VT_VERSIONED_STREAM,
	VT_BSTR_BLOB		= 0xfff,
	VT_VECTOR		= 0x1000,
	VT_ARRAY		= 0x2000,
	VT_BYREF		= 0x4000,
};

enum w32api_wtypes_dvaspect {
	DVASPECT_CONTENT = 1,
	DVASPECT_THUMBNAIL = 2,
	DVASPECT_ICON = 4,
	DVASPECT_DOCPRINT = 8
};

struct w32api_wtypes_property_key {
	GUID  fmtid;
	DWORD pid;
};

#endif
