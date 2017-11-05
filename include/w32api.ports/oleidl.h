#ifndef _W32API_OLEIDL_H_
#define _W32API_OLEIDL_H_

#include <stdint.h>

#include <windef.h>
#include <winerror.h>
#include <winnt.h>

#include "basetyps.h"
#include "objfwd.h"
#include "olectlid.h"

#define DROPEFFECT_NONE 			(0)
#define DROPEFFECT_COPY 			(1)
#define DROPEFFECT_MOVE 			(2)
#define DROPEFFECT_LINK 			(4)


/* COM interface: IDropTarget */
EXTERN_C const IID IID_IDropTarget;

#define INTERFACE  IDropTarget
DECLARE_INTERFACE_(IDropTarget,IUnknown) {
        STDMETHOD	(QueryInterface)(THIS_ REFIID,PVOID *) PURE;
        STDMETHOD_	(ULONG,AddRef)	(THIS) PURE;
        STDMETHOD_	(ULONG,Release)	(THIS) PURE;
        STDMETHOD	(DragEnter)	(THIS_ LPDATAOBJECT,DWORD,POINTL,PDWORD) PURE;
        STDMETHOD	(DragOver)	(THIS_ DWORD,POINTL,PDWORD) PURE;
        STDMETHOD	(DragLeave)	(THIS) PURE;
        STDMETHOD	(Drop)		(THIS_ LPDATAOBJECT,DWORD,POINTL,PDWORD) PURE;
};
#undef INTERFACE

#endif
