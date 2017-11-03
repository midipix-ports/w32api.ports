#ifndef _W32API_USP10_H_
#define _W32API_USP10_H_

#include <stdint.h>

#include <windef.h>
#include <winerror.h>

/* usp ssa bits */
#define SSA_GLYPHS				0x00000080
#define SSA_FALLBACK				0x00000020
#define SSA_LINK				0x00001000

/* usp hresult definitions */
#define USP_E_SCRIPT_NOT_IN_FONT		MAKE_HRESULT (SEVERITY_ERROR, FACILITY_ITF, 0x200)

/* usp typedefs */
typedef void *					SCRIPT_STRING_ANALYSIS;

/* usp struct definitions */
struct  w32api_script_control;
struct  w32api_script_state;
struct  w32api_script_tabdef;

typedef struct w32api_script_control		SCRIPT_CONTROL,*PSCRIPT_CONTROL;
typedef struct w32api_script_state		SCRIPT_STATE,*PSCRIPT_STATE;
typedef struct w32api_script_tabdef		SCRIPT_TABDEF,*PSCRIPT_TABDEF;

struct w32api_script_control {
	uint32_t	uDefaultLanguage :16;
	uint32_t	fContextDigits :1;
	uint32_t	fInvertPreBoundDir :1;
	uint32_t	fInvertPostBoundDir :1;
	uint32_t	fLinkStringBefore :1;
	uint32_t	fLinkStringAfter :1;
	uint32_t	fNeutralOverride :1;
	uint32_t	fNumericOverride :1;
	uint32_t	fLegacyBidiClass :1;
	uint32_t	fReserved :8;
};

struct w32api_script_state {
	int32_t		uBidiLevel :5;
	int32_t		fOverrideDirection :1;
	int32_t		fInhibitSymSwap :1;
	int32_t		fCharShape :1;
	int32_t		fDigitSubstitute :1;
	int32_t		fInhibitLigate :1;
	int32_t		fDisplayZWG :1;
	int32_t		fArabicNumContext :1;
	int32_t		fGcpClusters :1;
	int32_t		fReserved :1;
	int32_t		fEngineReserved :2;
};

struct w32api_script_tabdef {
	int32_t		cTabStops;
	int32_t		iScale;
	int32_t *	pTabStops;
	int32_t		iTabOrigin;
};

/* usp interface signatures */
typedef int32_t __stdcall w32api_script_string_out(
	SCRIPT_STRING_ANALYSIS,
	int,
	int,
	UINT,
	const RECT *,
	int,
	int,
	BOOL);

typedef int32_t __stdcall w32api_script_string_free(
	SCRIPT_STRING_ANALYSIS *);

typedef int32_t __stdcall w32api_script_string_analyse(
	HDC,const void *,
	int,
	int,
	int,
	DWORD,
	int,
	SCRIPT_CONTROL *,
	SCRIPT_STATE *,
	const int *,
	SCRIPT_TABDEF *,
	const BYTE *,
	SCRIPT_STRING_ANALYSIS *);

__dllimport w32api_script_string_out		ScriptStringOut;
__dllimport w32api_script_string_free		ScriptStringFree;
__dllimport w32api_script_string_analyse	ScriptStringAnalyse;

#endif
