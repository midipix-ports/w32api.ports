#ifndef _OBJBASE_H_
#define _OBJBASE_H_

#include <windef.h>
#include <basetyps.h>
#include <objidl.h>

typedef int32_t __stdcall w32api_co_create_instance(
	REFCLSID,
	LPUNKNOWN,
	DWORD,
	REFIID,
	PVOID*);

typedef int32_t __stdcall w32api_co_create_instance_ex(
	REFCLSID,
	IUnknown*,
	DWORD,
	COSERVERINFO*,
	DWORD,MULTI_QI*);

__dllimport w32api_co_create_instance		CoCreateInstance;
__dllimport w32api_co_create_instance_ex	CoCreateInstanceEx;

#endif
