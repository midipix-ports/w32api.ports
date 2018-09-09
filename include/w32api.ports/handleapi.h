#ifndef _W32API_HANDLEAPI_H_
#define _W32API_HANDLEAPI_H_

#include <windef.h>

#define INVALID_HANDLE_VALUE ((HANDLE) (LONG_PTR)-1)

__dllimport int __stdcall CloseHandle(HANDLE hObject);
__dllimport int __stdcall DuplicateHandle(HANDLE hSourceProcessHandle, HANDLE hSourceHandle, HANDLE hTargetProcessHandle, LPHANDLE lpTargetHandle, DWORD dwDesiredAccess, int bInheritHandle, DWORD dwOptions);
__dllimport int __stdcall GetHandleInformation(HANDLE hObject, LPDWORD lpdwFlags);
__dllimport int __stdcall SetHandleInformation(HANDLE hObject, DWORD dwMask, DWORD dwFlags);

#endif
