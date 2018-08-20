#ifndef _W32API_WINNT_H_
#define _W32API_WINNT_H_

#include <stdint.h>
#include <windef.h>

#define ES_DISPLAY_REQUIRED			((DWORD)0x00000002)

#define FILE_ATTRIBUTE_READONLY			0x00000001
#define FILE_ATTRIBUTE_HIDDEN			0x00000002
#define FILE_ATTRIBUTE_SYSTEM			0x00000004
#define FILE_ATTRIBUTE_DIRECTORY		0x00000010
#define FILE_ATTRIBUTE_ARCHIVE			0x00000020
#define FILE_ATTRIBUTE_DEVICE			0x00000040
#define FILE_ATTRIBUTE_NORMAL			0x00000080
#define FILE_ATTRIBUTE_TEMPORARY		0x00000100
#define FILE_ATTRIBUTE_SPARSE_FILE		0x00000200
#define FILE_ATTRIBUTE_REPARSE_POINT		0x00000400
#define FILE_ATTRIBUTE_COMPRESSED		0x00000800
#define FILE_ATTRIBUTE_OFFLINE			0x00001000
#define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED	0x00002000
#define FILE_ATTRIBUTE_ENCRYPTED		0x00004000
#define FILE_ATTRIBUTE_INTEGRITY_STREAM		0x00008000
#define FILE_ATTRIBUTE_VIRTUAL			0x00010000
#define FILE_ATTRIBUTE_NO_SCRUB_DATA		0x00020000

#define FILE_SHARE_READ				0x00000001
#define FILE_SHARE_WRITE			0x00000002
#define FILE_SHARE_DELETE			0x00000004
#define FILE_SHARE_VALID_FLAGS			0x00000007

#define DECLARE_HANDLE(name)      \
	struct name##__ {          \
		int unused;         \
	};                           \
                                      \
	typedef struct name##__ * name \
	/* ---------------------------*/

#define STANDARD_RIGHTS_ALL			(uint32_t)(0x001F0000)

#define KEY_QUERY_VALUE				(0x0001)
#define KEY_SET_VALUE				(0x0002)
#define KEY_CREATE_SUB_KEY			(0x0004)
#define KEY_ENUMERATE_SUB_KEYS			(0x0008)
#define KEY_NOTIFY				(0x0010)
#define KEY_CREATE_LINK				(0x0020)

#define SYNCHRONIZE                      	(uint32_t)(0x00100000)

#define LANG_NEUTRAL				0x00
#define LANG_DEFAULT				0x01

#define SUBLANG_NEUTRAL				0x00
#define SUBLANG_DEFAULT				0x01

#define KEY_ALL_ACCESS 				((STANDARD_RIGHTS_ALL | \
						KEY_QUERY_VALUE | KEY_SET_VALUE | \
						KEY_CREATE_SUB_KEY | KEY_ENUMERATE_SUB_KEYS | \
						KEY_NOTIFY | KEY_CREATE_LINK) & (~SYNCHRONIZE))

#define MAKELANGID(p,s)				((((WORD)(s)) << 10) | (WORD)(p))

#define VER_EQUAL				1
#define VER_GREATER				2
#define VER_GREATER_EQUAL			3
#define VER_LESS				4
#define VER_LESS_EQUAL				5
#define VER_AND					6
#define VER_OR					7

#define VER_CONDITION_MASK			7
#define VER_NUM_BITS_PER_CONDITION_MASK		3

#define VER_MINORVERSION			0x0000001
#define VER_MAJORVERSION			0x0000002
#define VER_BUILDNUMBER				0x0000004
#define VER_PLATFORMID				0x0000008
#define VER_SERVICEPACKMINOR			0x0000010
#define VER_SERVICEPACKMAJOR			0x0000020
#define VER_SUITENAME				0x0000040
#define VER_PRODUCT_TYPE			0x0000080

#define VER_NT_WORKSTATION			0x0000001
#define VER_NT_DOMAIN_CONTROLLER		0x0000002
#define VER_NT_SERVER				0x0000003

#define VER_PLATFORM_WIN32s			0
#define VER_PLATFORM_WIN32_WINDOWS		1
#define VER_PLATFORM_WIN32_NT			2

#define VER_SET_CONDITION(_m_,_t_,_c_)		((_m_) = VerSetConditionMask((_m_),(_t_),(_c_)))

#define RtlZeroMemory(destination,length)	memset((destination),0,(length))
#define ZeroMemory				RtlZeroMemory

struct  winnt_security_descriptor;
union   winnt_large_integer;

struct	winnt_io_counters;

struct	winnt_os_version_info_ansi;
struct	winnt_os_version_info_utf8;
struct	winnt_os_version_info_utf16;

struct	winnt_os_version_info_ex_ansi;
struct	winnt_os_version_info_ex_utf8;
struct	winnt_os_version_info_ex_utf16;

typedef uint32_t				ACCESS_MASK;
typedef uint32_t				*PACCESS_MASK;

typedef uint32_t				SECURITY_INFORMATION;
typedef uint32_t				*PSECURITY_INFORMATION;

typedef	struct winnt_security_descriptor	SECURITY_DESCRIPTOR;
typedef	struct winnt_security_descriptor	*PSECURITY_DESCRIPTOR;

typedef	DWORD					EXECUTION_STATE;
typedef	DWORD					*PEXECUTION_STATE;

typedef union winnt_large_integer		LARGE_INTEGER;

typedef struct winnt_io_counters		IO_COUNTERS,*PIO_COUNTERS;

typedef struct winnt_os_version_info_ansi		OSVERSIONINFOA,*POSVERSIONINFOA,*LPOSVERSIONINFOA;
typedef struct winnt_os_version_info_utf8		OSVERSIONINFOM,*POSVERSIONINFOM,*LPOSVERSIONINFOM;
typedef struct winnt_os_version_info_utf16		OSVERSIONINFOW,*POSVERSIONINFOW,*LPOSVERSIONINFOW,RTL_OSVERSIONINFOW,*PRTL_OSVERSIONINFOW;

typedef struct winnt_os_version_info_ex_ansi		OSVERSIONINFOEXA,*POSVERSIONINFOEXA,*LPOSVERSIONINFOEXA;
typedef struct winnt_os_version_info_ex_utf8		OSVERSIONINFOEXM,*POSVERSIONINFOEXM,*LPOSVERSIONINFOEXM;
typedef struct winnt_os_version_info_ex_utf16		OSVERSIONINFOEXW,*POSVERSIONINFOEXW,*LPOSVERSIONINFOEXW,RTL_OSVERSIONINFOEXW,*PRTL_OSVERSIONINFOEXW;

struct winnt_os_version_info_ansi {
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	CHAR szCSDVersion[128];
};

struct winnt_os_version_info_utf8 {
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	CHAR szCSDVersion[128];
};

struct winnt_os_version_info_utf16 {
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	WCHAR szCSDVersion[128];
};


struct winnt_os_version_info_ex_ansi {
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	CHAR szCSDVersion[128];
	WORD wServicePackMajor;
	WORD wServicePackMinor;
	WORD wSuiteMask;
	BYTE wProductType;
	BYTE wReserved;
};

struct winnt_os_version_info_ex_utf8 {
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	CHAR szCSDVersion[128];
	WORD wServicePackMajor;
	WORD wServicePackMinor;
	WORD wSuiteMask;
	BYTE wProductType;
	BYTE wReserved;
};

struct winnt_os_version_info_ex_utf16 {
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	WCHAR szCSDVersion[128];
	WORD wServicePackMajor;
	WORD wServicePackMinor;
	WORD wSuiteMask;
	BYTE wProductType;
	BYTE wReserved;
};

struct winnt_security_descriptor {
        unsigned char   revision;
        unsigned char   sbz_1st;
        uint16_t        control;
        uint32_t        offset_owner;
        uint32_t        offset_group;
        uint32_t        offset_sacl;
        uint32_t        offset_dacl;
};

union winnt_large_integer {
	struct {
		uint32_t	ulow;
		int32_t		ihigh;
	};
	long long		quad;
};

struct winnt_io_counters {
	ULONGLONG ReadOperationCount;
	ULONGLONG WriteOperationCount;
	ULONGLONG OtherOperationCount;
	ULONGLONG ReadTransferCount;
	ULONGLONG WriteTransferCount;
	ULONGLONG OtherTransferCount;
};

__dllimport ULONGLONG __stdcall VerSetConditionMask(ULONGLONG ConditionMask, DWORD TypeMask, BYTE Condition);

#ifdef WINAPI_ANSI_DEFAULT
typedef struct  winnt_os_version_info_ansi		OSVERSIONINFO,*POSVERSIONINFO,*LPOSVERSIONINFO;
typedef struct	winnt_os_version_info_ex_ansi		OSVERSIONINFOEX,*POSVERSIONINFOEX,*LPOSVERSIONINFOEX;
#endif

#ifdef WINAPI_UTF8_DEFAULT
typedef struct winnt_os_version_info_utf8		OSVERSIONINFO,*POSVERSIONINFO,*LPOSVERSIONINFO;
typedef struct  winnt_os_version_info_ex_utf8		OSVERSIONINFOEX,*POSVERSIONINFOEX,*LPOSVERSIONINFOEX;
#endif

#ifdef WINAPI_UTF16_DEFAULT
typedef struct winnt_os_version_info_utf16		OSVERSIONINFO,*POSVERSIONINFO,*LPOSVERSIONINFO;
typedef struct  winnt_os_version_info_ex_utf16		OSVERSIONINFOEX,*POSVERSIONINFOEX,*LPOSVERSIONINFOEX;
#endif


#endif
