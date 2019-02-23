#ifndef _W32API_HANDLEAPI_H_
#define _W32API_HANDLEAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <windef.h>


typedef INT __stdcall w32api_handleapi_close_handle(
	HANDLE);

typedef INT __stdcall w32api_handleapi_duplicate_handle(
	HANDLE,
	HANDLE,
	HANDLE,
	LPHANDLE,
	DWORD,
	BOOL,
	DWORD);

typedef INT __stdcall w32api_handleapi_get_handle_information(
	HANDLE,
	LPDWORD);

typedef INT __stdcall w32api_handleapi_set_handle_information(
	HANDLE,
	DWORD,
	DWORD);




__dllimport w32api_handleapi_close_handle						CloseHandle;
__dllimport w32api_handleapi_duplicate_handle						DuplicateHandle;
__dllimport w32api_handleapi_get_handle_information					GetHandleInformation;
__dllimport w32api_handleapi_set_handle_information					SetHandleInformation;




#define INVALID_HANDLE_VALUE ((HANDLE) (LONG_PTR)-1)


#ifdef __cplusplus
}
#endif

#endif /* _W32API_HANDLEAPI_H_ */
