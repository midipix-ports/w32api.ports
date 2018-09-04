#ifndef _W32API_HEAPAPI_H_
#define _W32API_HEAPAPI_H_

#include <windef.h>

__dllimport LPVOID __stdcall HeapAlloc (HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
__dllimport int __stdcall HeapFree (HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
__dllimport HANDLE __stdcall GetProcessHeap (void);

#endif
