#ifndef _W32API_BASETYPS_H_
#define _W32API_BASETYPS_H_

#include <stdint.h>
#include <windef.h>

#ifdef CINTERFACE
#error <basetyps.h>: CINTERFACE PREPROCESSING MODE IS NOT YET SUPPORTED!
#endif

#ifdef __cplusplus

#include "basetypes_cxx.h"

#else

/*****************/
/* COM in sane C */
/*****************/
#ifndef EXTERN_C
#define EXTERN_C extern
#endif

#ifndef _COM_INTERFACE
#define _COM_INTERFACE	struct
#endif

#ifndef _COM_interface
#define _COM_interface	struct
#endif

#ifndef CONST_VTABLE
#define CONST_VTABLE
#endif

#define PURE
#define THIS			INTERFACE *
#define THIS_			INTERFACE *,

#define IENUM_THIS(T)		T*
#define IENUM_THIS_(T)		T*,

#define STDMETHOD(m)		HRESULT(__stdcall * m)
#define STDMETHOD_(t,m)		t(__stdcall * m)

#define DECLARE_INTERFACE(i)                                    \
	CONST_VTABLE struct i##Vtbl;                           \
	typedef struct i {                                    \
		CONST_VTABLE struct i##Vtbl * lpVtbl;        \
	} i;                                                \
	                                                   \
	typedef struct i##Vtbl i##Vtbl;                   \
	struct i##Vtbl                                   \

#define DECLARE_INTERFACE_(i,b)	DECLARE_INTERFACE(i)

#endif


/* IID struct definitions */
struct  w32api_guid;
struct  w32api_iid_iunknown;
struct  w32api_iid_iclass_factory;

typedef struct w32api_guid			GUID,*LPGUID,*REFGUID;
typedef struct w32api_guid			IID,*LPIID;
typedef struct w32api_guid			CLSID;
typedef struct w32api_guid			FMTID,*LPFMTID,*REFFMTID;

typedef struct IUnknown				*LPUNKNOWN;
typedef struct IClassFactory			*LPCLASSFACTORY;

typedef const  struct w32api_guid		*REFIID;
typedef const  struct w32api_guid		*LPCLSID,*REFCLSID;
typedef const  struct w32api_guid		*LPCGUID;

struct w32api_guid {
        uint32_t        data1;
        uint16_t        data2;
        uint16_t        data3;
        unsigned char   data4[8];
};


/* COM interface: IUnknown */
EXTERN_C const IID IID_IUnknown;

#define INTERFACE  IUnknown
DECLARE_INTERFACE (IUnknown) {
	STDMETHOD	(QueryInterface)	(THIS_ REFIID,PVOID*) PURE;
	STDMETHOD_	(ULONG,AddRef)		(THIS) PURE;
	STDMETHOD_	(ULONG,Release)		(THIS) PURE;
};
#undef INTERFACE


/* COM interface: IDataObject */
EXTERN_C const IID IID_IClassFactory;

#define INTERFACE  IClassFactory
DECLARE_INTERFACE_(IClassFactory,IUnknown) {
	STDMETHOD	(QueryInterface)	(THIS_ REFIID,PVOID*) PURE;
	STDMETHOD_	(ULONG,AddRef)		(THIS) PURE;
	STDMETHOD_	(ULONG,Release)		(THIS) PURE;
	STDMETHOD	(CreateInstance)	(THIS_ LPUNKNOWN,REFIID,PVOID*) PURE;
	STDMETHOD	(LockServer)		(THIS_ BOOL) PURE;
};
#undef INTERFACE


#endif
