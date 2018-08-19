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

#define KEY_ALL_ACCESS 				((STANDARD_RIGHTS_ALL | \
						KEY_QUERY_VALUE | KEY_SET_VALUE | \
						KEY_CREATE_SUB_KEY | KEY_ENUMERATE_SUB_KEYS | \
						KEY_NOTIFY | KEY_CREATE_LINK) & (~SYNCHRONIZE))

#define RtlZeroMemory(destination,length)	memset((destination),0,(length))
#define ZeroMemory				RtlZeroMemory

struct  winnt_security_descriptor;
union   winnt_large_integer;

typedef uint32_t				ACCESS_MASK;
typedef uint32_t				*PACCESS_MASK;

typedef uint32_t				SECURITY_INFORMATION;
typedef uint32_t				*PSECURITY_INFORMATION;

typedef struct winnt_security_descriptor	SECURITY_DESCRIPTOR;
typedef struct winnt_security_descriptor	*PSECURITY_DESCRIPTOR;

typedef DWORD					EXECUTION_STATE;
typedef DWORD					*PEXECUTION_STATE;

typedef union winnt_large_integer		LARGE_INTEGER;

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

#endif
