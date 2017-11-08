#ifndef _W32API_SHLOBJ_H_
#define _W32API_SHLOBJ_H_

#include <winbase.h>
#include <basetyps.h>
#include <shlguid.h>

typedef struct _SHITEMID {
	USHORT	cb;
	BYTE	abID[1];
} SHITEMID, * LPSHITEMID;

typedef struct _ITEMIDLIST {
	SHITEMID mkid;
} ITEMIDLIST,*LPITEMIDLIST;

typedef const ITEMIDLIST *LPCITEMIDLIST;


/* COM interface:  IShellLinkW*/
EXTERN_C const IID IID_IShellLinkW;

#define INTERFACE  IShellLinkW
DECLARE_INTERFACE_(IShellLinkW,IUnknown) {
	STDMETHOD	(QueryInterface)	(THIS_ REFIID,PVOID*) PURE;
	STDMETHOD_	(ULONG,AddRef)		(THIS) PURE;
	STDMETHOD_	(ULONG,Release)		(THIS) PURE;
	STDMETHOD	(GetPath)		(THIS_ LPWSTR,int,WIN32_FIND_DATAW*,DWORD) PURE;
	STDMETHOD	(GetIDList)		(THIS_ LPITEMIDLIST*) PURE;
	STDMETHOD	(SetIDList)		(THIS_ LPCITEMIDLIST) PURE;
	STDMETHOD	(GetDescription)	(THIS_ LPWSTR,int) PURE;
	STDMETHOD	(SetDescription)	(THIS_ LPCWSTR) PURE;
	STDMETHOD	(GetWorkingDirectory)	(THIS_ LPWSTR,int) PURE;
	STDMETHOD	(SetWorkingDirectory)	(THIS_ LPCWSTR) PURE;
	STDMETHOD	(GetArguments)		(THIS_ LPWSTR,int) PURE;
	STDMETHOD	(SetArguments)		(THIS_ LPCWSTR) PURE;
	STDMETHOD	(GetHotkey)		(THIS_ PWORD) PURE;
	STDMETHOD	(SetHotkey)		(THIS_ WORD) PURE;
	STDMETHOD	(GetShowCmd)		(THIS_ int*) PURE;
	STDMETHOD	(SetShowCmd)		(THIS_ int) PURE;
	STDMETHOD	(GetIconLocation)	(THIS_ LPWSTR,int,int*) PURE;
	STDMETHOD	(SetIconLocation)	(THIS_ LPCWSTR,int) PURE;
	STDMETHOD	(SetRelativePath)	(THIS_ LPCWSTR ,DWORD) PURE;
	STDMETHOD	(Resolve)		(THIS_ HWND,DWORD) PURE;
	STDMETHOD	(SetPath)		(THIS_ LPCWSTR) PURE;
};
#undef INTERFACE

#endif
