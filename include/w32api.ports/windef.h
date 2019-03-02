#ifndef _W32API_WINDEF_H_
#define _W32API_WINDEF_H_

#if    defined(__NT32) && defined(__NT64)
#error please define either __NT32 or __NT64, but not both.
#elif  !defined(__NT32) && !defined(__NT64)
#error either __NT32 or __NT64 must be defined.
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* numeric types */
/* +++++++++++++ */

/* exact-size integers */
typedef signed char 		INT8,	*PINT8;
typedef signed short 		INT16,	*PINT16;
typedef signed int 		INT32,	*PINT32;
typedef long long 		INT64,	*PINT64;

typedef unsigned char 		UINT8,	*PUINT8;
typedef unsigned short 		UINT16,	*PUINT16;
typedef unsigned int 		UINT32,	*PUINT32;
typedef unsigned long long	UINT64,	*PUINT64;

/**
 *  basic numeric types:
 *  LONG and ULONG are always 32 bits
 *  LP pointer prefix is a historical reminiscence of 16-bit days
**/
typedef char 			CHAR,	*PCHAR,		*LPCHAR;
typedef char 			CCHAR,	*PCCHAR,	*LPCCHAR;
typedef char			*PCH,	*LPCH;
typedef short 			SHORT,	*PSHORT,	*LPSHORT;
typedef int			BOOL,	*PBOOL,		*LPBOOL;
typedef int 			INT,	*PINT,		*LPINT;
typedef float 			FLOAT,	*PFLOAT,	*LPFLOAT;
typedef int			LONG,	*PLONG,		*LPLONG;

/* basic unsigned integer types */
typedef unsigned char		BYTE,	*PBYTE,		*LPBYTE;
typedef unsigned char 		UCHAR,	*PUCHAR,	*LPUCHAR;
typedef unsigned short 		USHORT,	*PUSHORT,	*LPUSHORT;
typedef unsigned short 		WORD,	*PWORD,		*LPWORD;
typedef unsigned int 		UINT,	*PUINT,		*LPUINT;
typedef unsigned int		ULONG,	*PULONG,	*LPULONG;
typedef unsigned int		DWORD,	*PDWORD,	*LPDWORD;

/* LONG32,LONG64: (signed) */
typedef signed int 		LONG32,	*PLONG32;
typedef long long 		LONG64,	*PLONG64;

/* LONG32,LONG64: unsigned */
typedef unsigned int 		ULONG32,	*PULONG32;
typedef unsigned int 		DWORD32,	*PDWORD32;

typedef unsigned long long 	ULONG64,	*PULONG64;
typedef unsigned long long	DWORD64,	*PDWORD64;
typedef unsigned long long	DWORDLONG,	*PDWORDLONG;
typedef unsigned long long	QWORD,		*PQWORD;

/* VOID pointer */
typedef void *			PVOID;		/* "anonymous" */
typedef void *			LPVOID;		/* "pointer"   */
typedef const void *		LPCVOID;	/* "legacy"    */

/* LONGLONG, ULONGLONG */
#if defined(__NT32)
	typedef double 			LONGLONG,	*PLONGLONG;
	typedef double 			ULONGLONG,	*PULONGLONG;
#elif defined(__NT64)
	typedef long long 		LONGLONG,	*PLONGLONG;
	typedef unsigned long long	ULONGLONG,	*PULONGLONG;
#endif

#if defined(__NT32)
	/* __NT32 pointers */
	typedef short 			HALF_PTR,	*PHALF_PTR;
	typedef int 			INT_PTR,	*PINT_PTR;
	typedef long			LONG_PTR,	*PLONG_PTR;
	typedef unsigned short 		UHALF_PTR,	*PUHALF_PTR;
	typedef unsigned int 		UINT_PTR,	*PUINT_PTR;
	typedef unsigned long 		ULONG_PTR,	*PULONG_PTR;
	/* exact-size pointers */
	#define POINTER_32		/* native pointer */
	#define POINTER_64	__ptr64	/* sign-extended 32-bit pointer */

#elif defined(__NT64)
	/* __NT64 pointers */
	typedef int 			HALF_PTR,	*PHALF_PTR;
	typedef long long		INT_PTR,	*PINT_PTR;
	typedef long long 		LONG_PTR,	*PLONG_PTR;
	typedef unsigned int 		UHALF_PTR,	*PUHALF_PTR;
	typedef unsigned long long	UINT_PTR,	*PUINT_PTR;
	typedef unsigned long long	ULONG_PTR,	*PULONG_PTR;
	/* exact-size pointers */
	#define POINTER_32	__ptr32	/* truncated pointer */
	#define POINTER_64	__ptr64	/* native pointer */
#endif

/* pointer arithmetic */
typedef ULONG_PTR	SIZE_T;
typedef LONG_PTR	SSIZE_T;

/* pointer synonyms */
#define POINTER_SIGNED 		__sptr
#define POINTER_UNSIGNED 	__uptr
typedef ULONG_PTR 		DWORD_PTR, *PDWORD_PTR;

/* pointers: special uses */
typedef UINT_PTR 	WPARAM;
typedef LONG_PTR 	LPARAM;
typedef LONG_PTR	LRESULT;


/* strings */
/* +++++++ */

/* CHAR  --> char,   	8-bit  character */
/* WCHAR --> char16_t,	16-bit character */
/* do note that wchar_t on midipix is a 32-bit integer */

/* variable strings */
typedef unsigned short 	WCHAR,	*PWCHAR,*LPWCHAR;
typedef WCHAR		*PWCH,	*LPWCH;
typedef CHAR 		*PSTR,	*LPSTR;			/* "ansi"    */
typedef WCHAR		*PWSTR,	*LPWSTR;		/* "unicode" */

/* constant strings */
typedef const char	*PCSTR,		*LPCSTR;	/* "ansi"    */
typedef const char	*PCMBSTR,	*LPCMBSTR;	/* "utf8"    */
typedef const unsigned short	*PCWSTR,	*LPCWSTR;	/* "unicode" */

/* option-dependent string types */
#ifdef UNICODE
	typedef WCHAR 		TCHAR,	*PTCHAR;
	typedef WCHAR 		TBYTE,	*PTBYTE;
	typedef LPWSTR 		PTSTR, 	LPTSTR; 	/* pointer to a variable-size string 	*/
	typedef LPCWSTR 	PCTSTR,	LPCTSTR;	/* pointer to a constant string 	*/
#else
	typedef char 		TCHAR,	*PTCHAR;
	typedef unsigned char	TBYTE,	*PTBYTE;
	typedef LPSTR 		PTSTR, 	LPTSTR; 	/* pointer to a variable-size string    */
	typedef LPCSTR 		PCTSTR,	LPCTSTR;	/* pointer to a constant string 	*/
#endif

/* the _UNICODE_STRING structure */
typedef struct _UNICODE_STRING {
  USHORT  	Length;
  USHORT  	MaximumLength;
  PWSTR  	Buffer;
} UNICODE_STRING;

/* pointers to the _UNICODE_STRING structure */
typedef		UNICODE_STRING *PUNICODE_STRING;	/* use with variable-size utf-16 strings */
typedef const 	UNICODE_STRING *PCUNICODE_STRING; 	/* use with constant utf-16 strings */



/* special API return types */
typedef BYTE 		BOOLEAN,	*PBOOLEAN;	/* test against TRUE or FALSE */
typedef LONG		NTSTATUS,	*PNTSTATUS;	/* test using:
								NT_SUCCESS(Status),
								NT_INFORMATION(Status),
								NT_WARNING(Status),
								NT_ERROR(Status) */
typedef LONG 		HRESULT,	*PHRESULT;	/* test using:
								SUCCEEDED(status),
								FAILED(status) */
typedef INT 		HFILE,		*PHFILE;	/* file descriptor */


/* miscellaneous types */
#define VOID		void
#define CONST		const


/* interpretation of the above API return types */
/* ++++++++++++++++++++++++++++++++++++++++++++ */

/* BOOLEAN */
#define FALSE	0
#define TRUE 	1

/* HRESULT */
#define FAILED(Status) 		((HRESULT)(Status) <  0)
#define SUCCEEDED(Status)	((HRESULT)(Status) >= 0)

/* NTSTATUS   */
/* NT_SUCCESS */
#define NT_SUCCESS(Status)	((((NTSTATUS)(Status) >= 0x00000000) \
					&& ((NTSTATUS)(Status) <= 0x3FFFFFFF)) \
				|| (((NTSTATUS)(Status) >= 0x40000000) \
					&& ((NTSTATUS)(Status) <= 0x7FFFFFFF)))
/* NT_INFORMATION */
#define NT_INFORMATION(Status)	(((NTSTATUS)(Status) >= 0x40000000) \
					&& ((NTSTATUS)(Status) <= 0x7FFFFFFF))
/* NT_WARNING */
#define NT_WARNING(Status)	(((NTSTATUS)(Status) >= 0x80000000) \
					&& ((NTSTATUS)(Status) <= 0xBFFFFFFF))
/* NT_ERROR */
#define NT_ERROR(Status)	(((NTSTATUS)(Status) >= 0xC0000000) \
					&& ((NTSTATUS)(Status) <= 0xFFFFFFFF))

/* API elements not protected by handles */
typedef WORD 		ATOM, 		*PATOM,		*LPATOM;
typedef WORD  		LANGID, 	*PLANGID,	*LPLANGID;
typedef DWORD 		LCID, 		*PLCID,		*LPLCID;
typedef DWORD 		LCTYPE, 	*PLCTYPE,	*LPLCTYPE;
typedef DWORD 		LGRPID, 	*PLGRPID,	*LPLGRPID;
typedef DWORD 		COLORREF, 	*PCOLORREF,	*LPCOLORREF;
typedef LONGLONG 	USN, 		*PUSN,		*LPUSN;


/* handles: opaque pointers; */
typedef PVOID 	HANDLE;		/* referenced objects normally reside in the kernel address space */
typedef HANDLE 	*PHANDLE;	/* pointer to the above HANDLE */
typedef HANDLE 	*LPHANDLE;	/* referenced objects are normally NOT managed by the kernel */

/* handles: primary */
typedef HANDLE HACCEL,			*PHACCEL;
typedef HANDLE HBITMAP,			*PHBITMAP;
typedef HANDLE HBRUSH,			*PHBRUSH;
typedef HANDLE HCOLORSPACE,		*PHCOLORSPACE;
typedef HANDLE HCONV,			*PHCONV;
typedef HANDLE HCONVLIST,		*PHCONVLIST;
typedef HANDLE HDC,			*PHDC;
typedef HANDLE HDDEDATA,		*PHDDEDATA;
typedef HANDLE HDESK,			*PHDESK;
typedef HANDLE HDROP,			*PHDROP;
typedef HANDLE HDWP,			*PHDWP;
typedef HANDLE HENHMETAFILE,		*PHENHMETAFILE;
typedef HANDLE HFONT,			*PHFONT;
typedef HANDLE HGDIOBJ,			*PHGDIOBJ;
typedef HANDLE HGLOBAL,			*PHGLOBAL;
typedef HANDLE HGLRC,			*PHGLRC;
typedef HANDLE HHOOK,			*PHHOOK;
typedef HANDLE HICON,			*PHICON;
typedef HANDLE HINSTANCE,		*PHINSTANCE;
typedef HANDLE HKEY,			*PHKEY;
typedef HANDLE HKL,			*PHKL;
typedef HANDLE HLOCAL,			*PHLOCAL;
typedef HANDLE HMENU,			*PHMENU;
typedef HANDLE HMETAFILE,		*PHMETAFILE;
typedef HANDLE HMONITOR,		*PHMONITOR; 	/* (NTVER >= 0x0500) */
typedef HANDLE HPALETTE,		*PHPALETTE;
typedef HANDLE HPEN,			*PHPEN;
typedef HANDLE HRGN,			*PHRGN;
typedef HANDLE HRSRC,			*PHRSRC;
typedef HANDLE HSZ,			*PHSZ;
typedef HANDLE HWND,			*PHWND;

typedef HANDLE SC_HANDLE,		*PSC_HANDLE;
typedef HANDLE SERVICE_STATUS_HANDLE, 	*PSERVICE_STATUS_HANDLE;
typedef HANDLE WINSTA,			*PWINSTA;


/* handles: secondary */
typedef HICON 				HCURSOR;
typedef HINSTANCE 			HMODULE;
typedef LPVOID 				SC_LOCK;


/* commonly used structs */
struct gdi_luid {
	UINT32 	low;
	INT32 	high;
};

struct gdi_point {
	INT32 	x;
	INT32 	y;
};

struct gdi_points {
	INT16	x;
	INT16	y;
};

struct gdi_rect {
	INT32	left;
	INT32	top;
	INT32	right;
	INT32	bottom;
};

struct gdi_size {
	INT32	cx;
	INT32	cy;
};


typedef struct gdi_luid			LUID,		*PLUID;
typedef struct gdi_point		POINT,	POINTL,	*PPOINT,*PPOINTL,*NPPOINT, *LPPOINT;
typedef struct gdi_points			POINTS,		*PPOINTS,*NPPOINTS,*LPPOINTS;
typedef struct gdi_rect			RECT,	RECTL,	*PRECT,	*PRECTL, *NPRECT,  *LPRECT;
typedef struct gdi_size			SIZE,	SIZEL,	*PSIZE,	*PSIZEL, *NPSIZE,  *LPSIZE;


/* common function type definitions */
typedef INT_PTR	(*FARPROC) ();
typedef INT_PTR (*NEARPROC) ();
typedef INT_PTR (*PROC) ();


/* core function signatures */
#if defined(__NT32)
typedef int(__attribute__((__stdcall__)) * winapi_proc)();
typedef int (*winapi_farproc)();
#endif

#if defined (__NT64)
typedef long long(__attribute__((__stdcall__)) * winapi_proc)();
typedef int (*winapi_farproc)();
#endif

//TEMP
#define CALLBACK __stdcall
#define WINAPI __stdcall
#define WINOLEAPI __stdcall

typedef const RECT *LPCRECT;

#define HIWORD(l) ((WORD) ((((DWORD_PTR) (l)) >> 16) & 0xffff))
#define LOWORD(l) ((WORD) (((DWORD_PTR) (l)) & 0xffff))
#define MAKELONG(a, b) ((LONG) (((WORD) (((DWORD_PTR) (a)) & 0xffff)) | ((DWORD) ((WORD) (((DWORD_PTR) (b)) & 0xffff))) << 16))

#ifdef __cplusplus
}
#endif

#endif
