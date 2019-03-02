#ifndef _W32API_PROCESSENV_H_
#define W32API_PROCESSENV_H_

#include <windef.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef LPCH __stdcall w32api_processenv_get_environment_strings(
	void);

typedef BOOL __stdcall w32api_processenv_set_environment_strings_utf16(
	LPWCH);

typedef BOOL __stdcall w32api_processenv_free_environment_strings_ansi(
	LPCH);

typedef BOOL __stdcall w32api_processenv_free_environment_strings_utf8(
	LPCH);

typedef BOOL __stdcall w32api_processenv_free_environment_strings_utf16(
	LPWCH);

typedef HANDLE __stdcall w32api_processenv_get_std_handle(
	DWORD);

typedef BOOL __stdcall w32api_processenv_set_std_handle(
	DWORD,
	HANDLE);

#if _WIN32_WINNT >= 0x0600
typedef BOOL __stdcall w32api_processenv_set_std_handle_ex(
	DWORD,
	HANDLE,
	PHANDLE);
#endif

typedef LPSTR __stdcall w32api_processenv_get_command_line_ansi(
	void);

typedef LPSTR __stdcall w32api_processenv_get_command_line_utf8(
	void);

typedef LPWSTR __stdcall w32api_processenv_get_command_line_utf16(
	void);

typedef DWORD __stdcall w32api_processenv_get_environment_variable_ansi(
	LPCSTR,
	LPSTR,
	DWORD);

typedef DWORD __stdcall w32api_processenv_get_environment_variable_utf8(
	LPCSTR,
	LPSTR,
	DWORD);

typedef DWORD __stdcall w32api_processenv_get_environment_variable_utf16(
	LPCWSTR,
	LPWSTR,
	DWORD);

typedef BOOL __stdcall w32api_processenv_set_environment_variable_ansi(
	LPCSTR,
	LPCSTR);

typedef BOOL __stdcall w32api_processenv_set_environment_variable_utf8(
	LPCSTR,
	LPCSTR);

typedef BOOL __stdcall w32api_processenv_set_environment_variable_utf16(
	LPCWSTR,
	LPCWSTR);

typedef DWORD __stdcall w32api_processenv_expand_environment_strings_ansi(
	LPCSTR,
	LPSTR,
	DWORD);

typedef DWORD __stdcall w32api_processenv_expand_environment_strings_utf8(
	LPCSTR,
	LPSTR,
	DWORD);

typedef DWORD __stdcall w32api_processenv_expand_environment_strings_utf16(
	LPCWSTR,
	LPWSTR,
	DWORD);

typedef BOOL __stdcall w32api_processenv_set_current_directory_ansi(
	LPCSTR);

typedef BOOL __stdcall w32api_processenv_set_current_directory_utf8(
	LPCSTR);

typedef BOOL __stdcall w32api_processenv_set_current_directory_utf16(
	LPCWSTR);

typedef DWORD __stdcall w32api_processenv_get_current_directory_ansi(
	DWORD,
	LPSTR);

typedef DWORD __stdcall w32api_processenv_get_current_directory_utf8(
	DWORD,
	LPSTR);

typedef DWORD __stdcall w32api_processenv_get_current_directory_utf16(
	DWORD,
	LPWSTR);

typedef DWORD __stdcall w32api_processenv_search_path_ansi(
	LPCSTR,
	LPCSTR,
	LPCSTR,
	DWORD,
	LPSTR,
	LPSTR *);

typedef DWORD __stdcall w32api_processenv_search_path_utf8(
	LPCSTR,
	LPCSTR,
	LPCSTR,
	DWORD,
	LPSTR,
	LPSTR *);

typedef DWORD __stdcall w32api_processenv_search_path_utf16(
	LPCWSTR,
	LPCWSTR,
	LPCWSTR,
	DWORD,
	LPWSTR,
	LPWSTR *);

typedef BOOL __stdcall w32api_processenv_need_current_directory_for_exe_path_ansi(
	LPCSTR);

typedef BOOL __stdcall w32api_processenv_need_current_directory_for_exe_path_utf8(
	LPCSTR);

typedef BOOL __stdcall w32api_processenv_need_current_directory_for_exe_path_utf16(
	LPCWSTR);




__dllimport w32api_processenv_get_environment_strings						GetEnvironmentStrings;
__dllimport w32api_processenv_set_environment_strings_utf16					SetEnvironmentStringsW;
__dllimport w32api_processenv_free_environment_strings_ansi					FreeEnvironmentStringsA;
__dllimport w32api_processenv_free_environment_strings_utf8					FreeEnvironmentStringsM;
__dllimport w32api_processenv_free_environment_strings_utf16					FreeEnvironmentStringsW;
__dllimport w32api_processenv_get_std_handle							GetStdHandle;
__dllimport w32api_processenv_set_std_handle							SetStdHandle;
#if _WIN32_WINNT >= 0x0600
__dllimport w32api_processenv_set_std_handle_ex							SetStdHandleEx;
#endif
__dllimport w32api_processenv_get_command_line_ansi						GetCommandLineA;
__dllimport w32api_processenv_get_command_line_utf8						GetCommandLineM;
__dllimport w32api_processenv_get_command_line_utf16						GetCommandLineW;
__dllimport w32api_processenv_get_environment_variable_ansi					GetEnvironmentVariableA;
__dllimport w32api_processenv_get_environment_variable_utf8					GetEnvironmentVariableM;
__dllimport w32api_processenv_get_environment_variable_utf16					GetEnvironmentVariableW;
__dllimport w32api_processenv_set_environment_variable_ansi					SetEnvironmentVariableA;
__dllimport w32api_processenv_set_environment_variable_utf8					SetEnvironmentVariableM;
__dllimport w32api_processenv_set_environment_variable_utf16					SetEnvironmentVariableW;
__dllimport w32api_processenv_expand_environment_strings_ansi					ExpandEnvironmentStringsA;
__dllimport w32api_processenv_expand_environment_strings_utf8					ExpandEnvironmentStringsM;
__dllimport w32api_processenv_expand_environment_strings_utf16					ExpandEnvironmentStringsW;
__dllimport w32api_processenv_set_current_directory_ansi					SetCurrentDirectoryA;
__dllimport w32api_processenv_set_current_directory_utf8					SetCurrentDirectoryM;
__dllimport w32api_processenv_set_current_directory_utf16					SetCurrentDirectoryW;
__dllimport w32api_processenv_get_current_directory_ansi					GetCurrentDirectoryA;
__dllimport w32api_processenv_get_current_directory_utf8					GetCurrentDirectoryM;
__dllimport w32api_processenv_get_current_directory_utf16					GetCurrentDirectoryW;
__dllimport w32api_processenv_search_path_ansi							SearchPathA;
__dllimport w32api_processenv_search_path_utf8							SearchPathM;
__dllimport w32api_processenv_search_path_utf16							SearchPathW;
__dllimport w32api_processenv_need_current_directory_for_exe_path_ansi				NeedCurrentDirectoryForExePathA;
__dllimport w32api_processenv_need_current_directory_for_exe_path_utf8				NeedCurrentDirectoryForExePathM;
__dllimport w32api_processenv_need_current_directory_for_exe_path_utf16				NeedCurrentDirectoryForExePathW;




#ifdef WINAPI_ANSI_DEFAULT
#define FreeEnvironmentStrings			FreeEnvironmentStringsA
#define GetCommandLine				GetCommandLineA
#define GetEnvironmentVariable			GetEnvironmentVariableA
#define SetEnvironmentVariable			SetEnvironmentVariableA
#define SetCurrentDirectory			SetCurrentDirectoryA
#define GetCurrentDirectory			GetCurrentDirectoryA
#define SearchPath				SearchPathA
#define NeedCurrentDirectoryForExePath		NeedCurrentDirectoryForExePathA
#endif

#ifdef WINAPI_UTF8_DEFAULT
#define FreeEnvironmentStrings			FreeEnvironmentStringsM
#define GetCommandLine				GetCommandLineM
#define GetEnvironmentVariable			GetEnvironmentVariableM
#define SetEnvironmentVariable			SetEnvironmentVariableM
#define SetCurrentDirectory			SetCurrentDirectoryM
#define GetCurrentDirectory			GetCurrentDirectoryM
#define SearchPath				SearchPathM
#define NeedCurrentDirectoryForExePath		NeedCurrentDirectoryForExePathM
#endif

#ifdef WINAPI_UTF16_DEFAULT
#define FreeEnvironmentStrings			FreeEnvironmentStringsW
#define GetCommandLine				GetCommandLineW
#define GetEnvironmentVariable			GetEnvironmentVariableW
#define SetEnvironmentVariable			SetEnvironmentVariableW
#define SetCurrentDirectory			SetCurrentDirectoryW
#define GetCurrentDirectory			GetCurrentDirectoryW
#define SearchPath				SearchPathW
#define NeedCurrentDirectoryForExePath		NeedCurrentDirectoryForExePathW
#endif


#ifdef WINAPI_UTF16_DEFAULT
#define GetEnvironmentStrings			GetEnvironmentStringsW
#define SetEnvironmentStrings			SetEnvironmentStringsW
#else
#define GetEnvironmentStringsA			GetEnvironmentStrings
#endif


#ifdef __cplusplus
}
#endif

#endif /* _W32API_PROCESSÈNV_H_ */
