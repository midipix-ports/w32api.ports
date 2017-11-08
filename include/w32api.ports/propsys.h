#ifndef _W32API_PROPSYS_H_
#define _W32API_PROPSYS_H_

#include <basetyps.h>
#include <propidl.h>

/* COM interface: IPropertyStore */
EXTERN_C const IID IID_IPropertyStore;

struct  IPropertyStore;
typedef struct IPropertyStore	*LPPROPERTYSTORE;

#define INTERFACE  IPropertyStore
DECLARE_INTERFACE_(IPropertyStore,IUnknown) {
	STDMETHOD	(QueryInterface)	(THIS_ REFIID,PVOID *) PURE;
	STDMETHOD_	(ULONG,AddRef)		(THIS) PURE;
	STDMETHOD_	(ULONG,Release)		(THIS) PURE;
	STDMETHOD	(GetCount)		(THIS_ DWORD *) PURE;
	STDMETHOD	(GetAt)			(THIS_ DWORD,PROPERTYKEY *) PURE;
	STDMETHOD	(GetValue)		(THIS_ REFPROPERTYKEY,PROPVARIANT *) PURE;
	STDMETHOD	(SetValue)		(THIS_ REFPROPERTYKEY,REFPROPVARIANT) PURE;
	STDMETHOD	(Commit)		(THIS) PURE;
};
#undef INTERFACE

#endif
