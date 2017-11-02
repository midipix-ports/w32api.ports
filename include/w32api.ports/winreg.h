#ifndef _W32API_WINREG_H
#define _W32API_WINREG_H

#include <stdint.h>
#include <stddef.h>

#include <windef.h>
#include <winbase.h>
#include <minwinbase.h>

#ifdef __cplusplus
extern "C" {
#endif

/* top-level keys */
#define HKEY_CLASSES_ROOT		((HKEY)0x80000000)
#define HKEY_CURRENT_USER		((HKEY)0x80000001)
#define HKEY_LOCAL_MACHINE		((HKEY)0x80000002)
#define HKEY_USERS			((HKEY)0x80000003)
#define HKEY_PERFORMANCE_DATA		((HKEY)0x80000004)
#define HKEY_CURRENT_CONFIG		((HKEY)0x80000005)
#define HKEY_DYN_DATA			((HKEY)0x80000006)

/* registry options */
#define REG_OPTION_NON_VOLATILE		(0)
#define REG_OPTION_VOLATILE		(1)
#define REG_CREATED_NEW_KEY		(1)
#define REG_OPENED_EXISTING_KEY		(2)
#define REG_NONE			(0)
#define REG_SZ				(1)
#define REG_EXPAND_SZ			(2)
#define REG_BINARY			(3)
#define REG_DWORD_LITTLE_ENDIAN		(4)
#define REG_DWORD			(4)
#define REG_DWORD_BIG_ENDIAN		(5)
#define REG_LINK			(6)
#define REG_MULTI_SZ			(7)
#define REG_RESOURCE_LIST		(8)
#define REG_FULL_RESOURCE_DESCRIPTOR	(9)
#define REG_RESOURCE_REQUIREMENTS_LIST	(10)
#define REG_QWORD_LITTLE_ENDIAN		(11)
#define REG_QWORD			(11)

/* registry notification bits */
#define REG_NOTIFY_CHANGE_NAME		(0x01)
#define REG_NOTIFY_CHANGE_ATTRIBUTES	(0x02)
#define REG_NOTIFY_CHANGE_LAST_SET	(0x04)
#define REG_NOTIFY_CHANGE_SECURITY	(0x08)

/* registry typedefs */
typedef ACCESS_MASK 			REGSAM;
typedef ACCESS_MASK 			*PREGSAM;

/* registry struct definitions */
struct  w32api_value_ent_ansi;
struct  w32api_value_ent_utf8;
struct  w32api_value_ent_utf16;

typedef struct w32api_value_ent_ansi	VALENTA,*PVALENTA;
typedef struct w32api_value_ent_utf8	VALENTM,*PVALENTM;
typedef struct w32api_value_ent_utf16	VALENTW,*PVALENTW;

struct w32api_value_ent_ansi {
        char *		ve_valuename;
        uint32_t	ve_valuelen;
        uint32_t	ve_valueptr;
        uint32_t	ve_type;
};

struct w32api_value_ent_utf8 {
        char *		ve_valuename;
        uint32_t	ve_valuelen;
        uint32_t	ve_valueptr;
        uint32_t	ve_type;
};

struct w32api_value_ent_utf16 {
        uint16_t *	ve_valuename;
        uint32_t	ve_valuelen;
        uint32_t	ve_valueptr;
        uint32_t	ve_type;
};

/* registry interfaces */
typedef BOOL __stdcall win32api_abort_system_shutdown_ansi(
	LPCSTR);

typedef BOOL __stdcall win32api_abort_system_shutdown_utf8(
	LPCSTR);

typedef BOOL __stdcall win32api_abort_system_shutdown_utf16(
	LPCWSTR);


typedef BOOL __stdcall win32api_initiate_system_shutdown_ansi(
	LPSTR,
	LPSTR,
	DWORD,
	BOOL,
	BOOL);

typedef BOOL __stdcall win32api_initiate_system_shutdown_utf8(
	LPSTR,
	LPSTR,
	DWORD,
	BOOL,
	BOOL);

typedef BOOL __stdcall win32api_initiate_system_shutdown_utf16(
	LPWSTR,
	LPWSTR,
	DWORD,
	BOOL,
	BOOL);

typedef LONG __stdcall w32api_reg_connect_registry_ansi(
	LPCSTR,
	HKEY,
	PHKEY);

typedef LONG __stdcall w32api_reg_connect_registry_utf8(
	LPCSTR,
	HKEY,
	PHKEY);

typedef LONG __stdcall w32api_reg_connect_registry_utf16(
	LPCWSTR,
	HKEY,
	PHKEY);


typedef LONG __stdcall w32api_reg_create_key_ansi(
	HKEY,
	LPCSTR,
	PHKEY);

typedef LONG __stdcall w32api_reg_create_key_utf8(
	HKEY,
	LPCSTR,
	PHKEY);

typedef LONG __stdcall w32api_reg_create_key_utf16(
	HKEY,
	LPCWSTR,
	PHKEY);

typedef LONG __stdcall w32api_reg_create_key_ex_ansi(
	HKEY,
	LPCSTR,
	DWORD,
	LPSTR,
	DWORD,
	REGSAM,
	LPSECURITY_ATTRIBUTES,
	PHKEY,PDWORD);

typedef LONG __stdcall w32api_reg_create_key_ex_utf8(
	HKEY,
	LPCSTR,
	DWORD,
	LPSTR,
	DWORD,
	REGSAM,
	LPSECURITY_ATTRIBUTES,
	PHKEY,PDWORD);

typedef LONG __stdcall w32api_reg_create_key_ex_utf16(
	HKEY,
	LPCWSTR,
	DWORD,
	LPWSTR,
	DWORD,
	REGSAM,
	LPSECURITY_ATTRIBUTES,
	PHKEY,PDWORD);

typedef LONG __stdcall w32api_reg_delete_key_ansi(
	HKEY,
	LPCSTR);

typedef LONG __stdcall w32api_reg_delete_key_utf8(
	HKEY,
	LPCSTR);

typedef LONG __stdcall w32api_reg_delete_key_utf16(
	HKEY,
	LPCWSTR);

typedef LONG __stdcall w32api_reg_delete_value_ansi(
	HKEY,
	LPCSTR);

typedef LONG __stdcall w32api_reg_delete_value_utf8(
	HKEY,
	LPCSTR);

typedef LONG __stdcall w32api_reg_delete_value_utf16(
	HKEY,
	LPCWSTR);

typedef LONG __stdcall w32api_reg_enum_key_ansi(
	HKEY,
	DWORD,
	LPSTR,
	DWORD);

typedef LONG __stdcall w32api_reg_enum_key_utf8(
	HKEY,
	DWORD,
	LPSTR,
	DWORD);

typedef LONG __stdcall w32api_reg_enum_key_utf16(
	HKEY,
	DWORD,
	LPWSTR,
	DWORD);

typedef LONG __stdcall w32api_reg_enum_key_ex_ansi(
	HKEY,
	DWORD,
	LPSTR,
	PDWORD,
	PDWORD,
	LPSTR,
	PDWORD,
	PFILETIME);

typedef LONG __stdcall w32api_reg_enum_key_ex_utf8(
	HKEY,
	DWORD,
	LPSTR,
	PDWORD,
	PDWORD,
	LPSTR,
	PDWORD,
	PFILETIME);

typedef LONG __stdcall w32api_reg_enum_key_ex_utf16(
	HKEY,
	DWORD,
	LPWSTR,
	PDWORD,
	PDWORD,
	LPWSTR,
	PDWORD,
	PFILETIME);


typedef LONG __stdcall w32api_reg_enum_value_ansi(
	HKEY,
	DWORD,
	LPSTR,
	PDWORD,
	PDWORD,
	PDWORD,
	LPBYTE,
	PDWORD);

typedef LONG __stdcall w32api_reg_enum_value_utf8(
	HKEY,
	DWORD,
	LPSTR,
	PDWORD,
	PDWORD,
	PDWORD,
	LPBYTE,
	PDWORD);

typedef LONG __stdcall w32api_reg_enum_value_utf16(
	HKEY,
	DWORD,
	LPWSTR,
	PDWORD,
	PDWORD,
	PDWORD,
	LPBYTE,
	PDWORD);

typedef LONG __stdcall w32api_reg_load_key_ansi(
	HKEY,
	LPCSTR,
	LPCSTR);

typedef LONG __stdcall w32api_reg_load_key_utf8(
	HKEY,
	LPCSTR,
	LPCSTR);

typedef LONG __stdcall w32api_reg_load_key_utf16(
	HKEY,
	LPCWSTR,
	LPCWSTR);

typedef LONG __stdcall w32api_reg_unload_key_ansi(
	HKEY,
	LPCSTR);

typedef LONG __stdcall w32api_reg_unload_key_utf8(
	HKEY,
	LPCSTR);

typedef LONG __stdcall w32api_reg_unload_key_utf16(
	HKEY,
	LPCWSTR);


typedef LONG __stdcall w32api_reg_open_key_ansi(
	HKEY,
	LPCSTR,
	PHKEY);

typedef LONG __stdcall w32api_reg_open_key_utf8(
	HKEY,
	LPCSTR,
	PHKEY);

typedef LONG __stdcall w32api_reg_open_key_utf16(
	HKEY,
	LPCWSTR,
	PHKEY);

typedef LONG __stdcall w32api_reg_open_key_ex_ansi(
	HKEY,
	LPCSTR,
	DWORD,
	REGSAM,
	PHKEY);

typedef LONG __stdcall w32api_reg_open_key_ex_utf8(
	HKEY,
	LPCSTR,
	DWORD,
	REGSAM,
	PHKEY);

typedef LONG __stdcall w32api_reg_open_key_ex_utf16(
	HKEY,
	LPCWSTR,
	DWORD,
	REGSAM,
	PHKEY);

typedef LONG __stdcall w32api_reg_query_info_key_ansi(
	HKEY,
	LPSTR,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PFILETIME);

typedef LONG __stdcall w32api_reg_query_info_key_utf8(
	HKEY,
	LPSTR,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PFILETIME);

typedef LONG __stdcall w32api_reg_query_info_key_utf16(
	HKEY,
	LPWSTR,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PDWORD,
	PFILETIME);

typedef LONG __stdcall w32api_reg_query_value_ansi(
	HKEY,
	LPCSTR,
	LPSTR,
	PLONG);

typedef LONG __stdcall w32api_reg_query_value_utf8(
	HKEY,
	LPCSTR,
	LPSTR,
	PLONG);

typedef LONG __stdcall w32api_reg_query_value_utf16(
	HKEY,
	LPCWSTR,
	LPWSTR,
	PLONG);

typedef LONG __stdcall w32api_reg_query_value_ex_ansi(
	HKEY,
	LPCSTR,
	LPDWORD,
	LPDWORD,
	LPBYTE,
	LPDWORD);

typedef LONG __stdcall w32api_reg_query_value_ex_utf8(
	HKEY,
	LPCSTR,
	LPDWORD,
	LPDWORD,
	LPBYTE,
	LPDWORD);

typedef LONG __stdcall w32api_reg_query_value_ex_utf16(
	HKEY,
	LPCWSTR,
	LPDWORD,
	LPDWORD,
	LPBYTE,
	LPDWORD);

typedef LONG __stdcall w32api_reg_query_multiple_values_ansi(
	HKEY,
	PVALENTA,
	DWORD,
	LPSTR,
	LPDWORD);

typedef LONG __stdcall w32api_reg_query_multiple_values_utf8(
	HKEY,
	PVALENTA,
	DWORD,
	LPSTR,
	LPDWORD);

typedef LONG __stdcall w32api_reg_query_multiple_values_utf16(
	HKEY,
	PVALENTW,
	DWORD,
	LPWSTR,
	LPDWORD);

typedef LONG __stdcall w32api_reg_replace_key_ansi(
	HKEY,
	LPCSTR,
	LPCSTR,
	LPCSTR);

typedef LONG __stdcall w32api_reg_replace_key_utf8(
	HKEY,
	LPCSTR,
	LPCSTR,
	LPCSTR);

typedef LONG __stdcall w32api_reg_replace_key_utf16(
	HKEY,
	LPCWSTR,
	LPCWSTR,
	LPCWSTR);

typedef LONG __stdcall w32api_reg_restore_key_ansi(
	HKEY,
	LPCSTR,
	DWORD);

typedef LONG __stdcall w32api_reg_restore_key_utf8(
	HKEY,
	LPCSTR,
	DWORD);

typedef LONG __stdcall w32api_reg_restore_key_utf16(
	HKEY,
	LPCWSTR,
	DWORD);

typedef LONG __stdcall w32api_reg_save_key_ansi(
	HKEY,
	LPCSTR,
	LPSECURITY_ATTRIBUTES);

typedef LONG __stdcall w32api_reg_save_key_utf8(
	HKEY,
	LPCSTR,
	LPSECURITY_ATTRIBUTES);

typedef LONG __stdcall w32api_reg_save_key_utf16(
	HKEY,
	LPCWSTR,
	LPSECURITY_ATTRIBUTES);

typedef LONG __stdcall w32api_reg_set_value_ansi(
	HKEY,
	LPCSTR,
	DWORD,
	LPCSTR,
	DWORD);

typedef LONG __stdcall w32api_reg_set_value_utf8(
	HKEY,
	LPCSTR,
	DWORD,
	LPCSTR,
	DWORD);

typedef LONG __stdcall w32api_reg_set_value_utf16(
	HKEY,
	LPCWSTR,
	DWORD,
	LPCWSTR,
	DWORD);

typedef LONG __stdcall w32api_reg_set_value_ex_ansi(
	HKEY,
	LPCSTR,
	DWORD,
	DWORD,
	const BYTE*,
	DWORD);

typedef LONG __stdcall w32api_reg_set_value_ex_utf8(
	HKEY,
	LPCSTR,
	DWORD,
	DWORD,
	const BYTE*,
	DWORD);

typedef LONG __stdcall w32api_reg_set_value_ex_utf16(
	HKEY,
	LPCWSTR,
	DWORD,
	DWORD,
	const BYTE*,
	DWORD);

typedef LONG __stdcall w32api_reg_set_key_security(
	HKEY,
	SECURITY_INFORMATION,
	PSECURITY_DESCRIPTOR);

typedef LONG __stdcall w32api_reg_get_key_security(
	HKEY,
	SECURITY_INFORMATION,
	PSECURITY_DESCRIPTOR,
	PDWORD);

typedef LONG __stdcall w32api_reg_close_key(
	HKEY);

typedef LONG __stdcall w32api_reg_flush_key(
	HKEY);

typedef LONG __stdcall w32api_reg_notify_change_key_value(
	HKEY,
	BOOL,
	DWORD,
	HANDLE,
	BOOL);


__dllimport win32api_abort_system_shutdown_ansi		AbortSystemShutdownA;
__dllimport win32api_abort_system_shutdown_utf8		AbortSystemShutdownM;
__dllimport win32api_abort_system_shutdown_utf16	AbortSystemShutdownW;

__dllimport win32api_initiate_system_shutdown_ansi	InitiateSystemShutdownA;
__dllimport win32api_initiate_system_shutdown_utf8	InitiateSystemShutdownM;
__dllimport win32api_initiate_system_shutdown_utf16	InitiateSystemShutdownW;

__dllimport w32api_reg_connect_registry_ansi		RegConnectRegistryA;
__dllimport w32api_reg_connect_registry_utf8		RegConnectRegistryM;
__dllimport w32api_reg_connect_registry_utf16		RegConnectRegistryW;

__dllimport w32api_reg_create_key_ansi			RegCreateKeyA;
__dllimport w32api_reg_create_key_utf8			RegCreateKeyM;
__dllimport w32api_reg_create_key_utf16			RegCreateKeyW;

__dllimport w32api_reg_create_key_ex_ansi		RegCreateKeyExA;
__dllimport w32api_reg_create_key_ex_utf8		RegCreateKeyExM;
__dllimport w32api_reg_create_key_ex_utf16		RegCreateKeyExW;

__dllimport w32api_reg_delete_key_ansi			RegDeleteKeyA;
__dllimport w32api_reg_delete_key_utf8			RegDeleteKeyM;
__dllimport w32api_reg_delete_key_utf16			RegDeleteKeyW;

__dllimport w32api_reg_delete_value_ansi		RegDeleteValueA;
__dllimport w32api_reg_delete_value_utf8		RegDeleteValueM;
__dllimport w32api_reg_delete_value_utf16		RegDeleteValueW;

__dllimport w32api_reg_enum_key_ansi			RegEnumKeyA;
__dllimport w32api_reg_enum_key_utf8			RegEnumKeyM;
__dllimport w32api_reg_enum_key_utf16			RegEnumKeyW;

__dllimport w32api_reg_enum_key_ex_ansi			RegEnumKeyExA;
__dllimport w32api_reg_enum_key_ex_utf8			RegEnumKeyExM;
__dllimport w32api_reg_enum_key_ex_utf16		RegEnumKeyExW;

__dllimport w32api_reg_enum_value_ansi			RegEnumValueA;
__dllimport w32api_reg_enum_value_utf8			RegEnumValueM;
__dllimport w32api_reg_enum_value_utf16			RegEnumValueW;

__dllimport w32api_reg_load_key_ansi			RegLoadKeyA;
__dllimport w32api_reg_load_key_utf8			RegLoadKeyM;
__dllimport w32api_reg_load_key_utf16			RegLoadKeyW;

__dllimport w32api_reg_unload_key_ansi			RegUnLoadKeyA;
__dllimport w32api_reg_unload_key_utf8			RegUnLoadKeyM;
__dllimport w32api_reg_unload_key_utf16			RegUnLoadKeyW;

__dllimport w32api_reg_open_key_ansi			RegOpenKeyA;
__dllimport w32api_reg_open_key_utf8			RegOpenKeyM;
__dllimport w32api_reg_open_key_utf16			RegOpenKeyW;

__dllimport w32api_reg_open_key_ex_ansi			RegOpenKeyExA;
__dllimport w32api_reg_open_key_ex_utf8			RegOpenKeyExM;
__dllimport w32api_reg_open_key_ex_utf16		RegOpenKeyExW;

__dllimport w32api_reg_query_info_key_ansi		RegQueryInfoKeyA;
__dllimport w32api_reg_query_info_key_utf8		RegQueryInfoKeyM;
__dllimport w32api_reg_query_info_key_utf16		RegQueryInfoKeyW;

__dllimport w32api_reg_query_value_ansi			RegQueryValueA;
__dllimport w32api_reg_query_value_utf8			RegQueryValueM;
__dllimport w32api_reg_query_value_utf16		RegQueryValueW;

__dllimport w32api_reg_query_value_ex_ansi		RegQueryValueExA;
__dllimport w32api_reg_query_value_ex_utf8		RegQueryValueExM;
__dllimport w32api_reg_query_value_ex_utf16		RegQueryValueExW;

__dllimport w32api_reg_query_multiple_values_ansi	RegQueryMultipleValuesA;
__dllimport w32api_reg_query_multiple_values_utf8	RegQueryMultipleValuesM;
__dllimport w32api_reg_query_multiple_values_utf16	RegQueryMultipleValuesW;

__dllimport w32api_reg_replace_key_ansi			RegReplaceKeyA;
__dllimport w32api_reg_replace_key_utf8			RegReplaceKeyM;
__dllimport w32api_reg_replace_key_utf16		RegReplaceKeyW;

__dllimport w32api_reg_restore_key_ansi			RegRestoreKeyA;
__dllimport w32api_reg_restore_key_utf8			RegRestoreKeyM;
__dllimport w32api_reg_restore_key_utf16		RegRestoreKeyW;

__dllimport w32api_reg_save_key_ansi			RegSaveKeyA;
__dllimport w32api_reg_save_key_utf8			RegSaveKeyM;
__dllimport w32api_reg_save_key_utf16			RegSaveKeyW;

__dllimport w32api_reg_set_value_ansi			RegSetValueA;
__dllimport w32api_reg_set_value_utf8			RegSetValueM;
__dllimport w32api_reg_set_value_utf16			RegSetValueW;

__dllimport w32api_reg_set_value_ex_ansi		RegSetValueExA;
__dllimport w32api_reg_set_value_ex_utf8		RegSetValueExM;
__dllimport w32api_reg_set_value_ex_utf16		RegSetValueExW;

__dllimport w32api_reg_set_key_security			RegSetKeySecurity;
__dllimport w32api_reg_get_key_security			RegGetKeySecurity;

__dllimport w32api_reg_close_key			RegCloseKey;
__dllimport w32api_reg_flush_key			RegFlushKey;
__dllimport w32api_reg_notify_change_key_value		RegNotifyChangeKeyValue;


#ifdef __cplusplus
}
#endif

#endif
