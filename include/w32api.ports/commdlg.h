#ifndef _W32API_COMMDLG_H_
#define _W32API_COMMDLG_H_

#include <windef.h>
#include <winuser.h>

typedef UINT_PTR (__stdcall *LPCFHOOKPROC) (HWND,UINT,WPARAM,LPARAM);
typedef UINT_PTR (__stdcall *LPCCHOOKPROC) (HWND,UINT,WPARAM,LPARAM);
typedef UINT_PTR (__stdcall *LPFRHOOKPROC) (HWND,UINT,WPARAM,LPARAM);
typedef UINT_PTR (__stdcall *LPPRINTHOOKPROC) (HWND,UINT,WPARAM,LPARAM);
typedef UINT_PTR (__stdcall *LPSETUPHOOKPROC) (HWND,UINT,WPARAM,LPARAM);
typedef UINT_PTR (__stdcall *LPOFNHOOKPROC) (HWND,UINT,WPARAM,LPARAM);

struct w32api_choosefont_ansi {
    DWORD lStructSize;
    HWND hwndOwner;
    HDC hDC;
    LPLOGFONTW lpLogFont;
    INT iPointSize;
    DWORD Flags;
    COLORREF rgbColors;
    LPARAM lCustData;
    LPCFHOOKPROC lpfnHook;
    LPCWSTR lpTemplateName;
    HINSTANCE hInstance;
    LPWSTR lpszStyle;
    WORD nFontType;
    WORD ___MISSING_ALIGNMENT__;
    INT nSizeMin;
    INT nSizeMax;
};

struct w32api_choosefont_utf8 {
    DWORD lStructSize;
    HWND hwndOwner;
    HDC hDC;
    LPLOGFONTW lpLogFont;
    INT iPointSize;
    DWORD Flags;
    COLORREF rgbColors;
    LPARAM lCustData;
    LPCFHOOKPROC lpfnHook;
    LPCWSTR lpTemplateName;
    HINSTANCE hInstance;
    LPWSTR lpszStyle;
    WORD nFontType;
    WORD ___MISSING_ALIGNMENT__;
    INT nSizeMin;
    INT nSizeMax;
};

struct w32api_choosefont_utf16 {
    DWORD lStructSize;
    HWND hwndOwner;
    HDC hDC;
    LPLOGFONTW lpLogFont;
    INT iPointSize;
    DWORD Flags;
    COLORREF rgbColors;
    LPARAM lCustData;
    LPCFHOOKPROC lpfnHook;
    LPCWSTR lpTemplateName;
    HINSTANCE hInstance;
    LPWSTR lpszStyle;
    WORD nFontType;
    WORD ___MISSING_ALIGNMENT__;
    INT nSizeMin;
    INT nSizeMax;
};

struct w32api_choose_color_ansi {
    DWORD lStructSize;
    HWND hwndOwner;
    HWND hInstance;
    COLORREF rgbResult;
    COLORREF *lpCustColors;
    DWORD Flags;
    LPARAM lCustData;
    LPCCHOOKPROC lpfnHook;
    LPCSTR lpTemplateName;
};

struct w32api_choose_color_utf8 {
    DWORD lStructSize;
    HWND hwndOwner;
    HWND hInstance;
    COLORREF rgbResult;
    COLORREF *lpCustColors;
    DWORD Flags;
    LPARAM lCustData;
    LPCCHOOKPROC lpfnHook;
    LPCSTR lpTemplateName;
};

struct w32api_choose_color_utf16 {
    DWORD lStructSize;
    HWND hwndOwner;
    HWND hInstance;
    COLORREF rgbResult;
    COLORREF *lpCustColors;
    DWORD Flags;
    LPARAM lCustData;
    LPCCHOOKPROC lpfnHook;
    LPCWSTR lpTemplateName;
};

struct w32api_find_replace_ansi {
    DWORD lStructSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    DWORD Flags;
    LPSTR lpstrFindWhat;
    LPSTR lpstrReplaceWith;
    WORD wFindWhatLen;
    WORD wReplaceWithLen;
    LPARAM lCustData;
    LPFRHOOKPROC lpfnHook;
    LPCSTR lpTemplateName;
};

struct w32api_find_replace_utf8 {
    DWORD lStructSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    DWORD Flags;
    LPSTR lpstrFindWhat;
    LPSTR lpstrReplaceWith;
    WORD wFindWhatLen;
    WORD wReplaceWithLen;
    LPARAM lCustData;
    LPFRHOOKPROC lpfnHook;
    LPCSTR lpTemplateName;
};

struct w32api_find_replace_utf16 {
    DWORD lStructSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    DWORD Flags;
    LPWSTR lpstrFindWhat;
    LPWSTR lpstrReplaceWith;
    WORD wFindWhatLen;
    WORD wReplaceWithLen;
    LPARAM lCustData;
    LPFRHOOKPROC lpfnHook;
    LPCWSTR lpTemplateName;
};

struct w32api_print_dlg_ansi {
	DWORD lStructSize;
	HWND hwndOwner;
	HGLOBAL hDevMode;
	HGLOBAL hDevNames;
	HDC hDC;
	DWORD Flags;
	WORD nFromPage;
	WORD nToPage;
	WORD nMinPage;
	WORD nMaxPage;
	WORD nCopies;
	HINSTANCE hInstance;
	LPARAM lCustData;
	LPPRINTHOOKPROC lpfnPrintHook;
	LPSETUPHOOKPROC lpfnSetupHook;
	LPCSTR lpPrintTemplateName;
	LPCSTR lpSetupTemplateName;
	HGLOBAL hPrintTemplate;
	HGLOBAL hSetupTemplate;
};

struct w32api_print_dlg_utf8 {
	DWORD lStructSize;
	HWND hwndOwner;
	HGLOBAL hDevMode;
	HGLOBAL hDevNames;
	HDC hDC;
	DWORD Flags;
	WORD nFromPage;
	WORD nToPage;
	WORD nMinPage;
	WORD nMaxPage;
	WORD nCopies;
	HINSTANCE hInstance;
	LPARAM lCustData;
	LPPRINTHOOKPROC lpfnPrintHook;
	LPSETUPHOOKPROC lpfnSetupHook;
	LPCSTR lpPrintTemplateName;
	LPCSTR lpSetupTemplateName;
	HGLOBAL hPrintTemplate;
	HGLOBAL hSetupTemplate;
};

struct w32api_print_dlg_utf16 {
	DWORD lStructSize;
	HWND hwndOwner;
	HGLOBAL hDevMode;
	HGLOBAL hDevNames;
	HDC hDC;
	DWORD Flags;
	WORD nFromPage;
	WORD nToPage;
	WORD nMinPage;
	WORD nMaxPage;
	WORD nCopies;
	HINSTANCE hInstance;
	LPARAM lCustData;
	LPPRINTHOOKPROC lpfnPrintHook;
	LPSETUPHOOKPROC lpfnSetupHook;
	LPCWSTR lpPrintTemplateName;
	LPCWSTR lpSetupTemplateName;
	HGLOBAL hPrintTemplate;
	HGLOBAL hSetupTemplate;
};

struct w32api_open_file_name_ansi {
	DWORD lStructSize;
	HWND hwndOwner;
	HINSTANCE hInstance;
	LPCSTR lpstrFilter;
	LPSTR lpstrCustomFilter;
	DWORD nMaxCustFilter;
	DWORD nFilterIndex;
	LPSTR lpstrFile;
	DWORD nMaxFile;
	LPSTR lpstrFileTitle;
	DWORD nMaxFileTitle;
	LPCSTR lpstrInitialDir;
	LPCSTR lpstrTitle;
	DWORD Flags;
	WORD nFileOffset;
	WORD nFileExtension;
	LPCSTR lpstrDefExt;
	LPARAM lCustData;
	LPOFNHOOKPROC lpfnHook;
	LPCSTR lpTemplateName;
	void *pvReserved;
	DWORD dwReserved;
	DWORD FlagsEx;
};

struct w32api_open_file_name_utf8 {
	DWORD lStructSize;
	HWND hwndOwner;
	HINSTANCE hInstance;
	LPCSTR lpstrFilter;
	LPSTR lpstrCustomFilter;
	DWORD nMaxCustFilter;
	DWORD nFilterIndex;
	LPSTR lpstrFile;
	DWORD nMaxFile;
	LPSTR lpstrFileTitle;
	DWORD nMaxFileTitle;
	LPCSTR lpstrInitialDir;
	LPCSTR lpstrTitle;
	DWORD Flags;
	WORD nFileOffset;
	WORD nFileExtension;
	LPCSTR lpstrDefExt;
	LPARAM lCustData;
	LPOFNHOOKPROC lpfnHook;
	LPCSTR lpTemplateName;
	void *pvReserved;
	DWORD dwReserved;
	DWORD FlagsEx;
};

struct w32api_open_file_name_utf16 {
	DWORD lStructSize;
	HWND hwndOwner;
	HINSTANCE hInstance;
	LPCWSTR lpstrFilter;
	LPWSTR lpstrCustomFilter;
	DWORD nMaxCustFilter;
	DWORD nFilterIndex;
	LPWSTR lpstrFile;
	DWORD nMaxFile;
	LPWSTR lpstrFileTitle;
	DWORD nMaxFileTitle;
	LPCWSTR lpstrInitialDir;
	LPCWSTR lpstrTitle;
	DWORD Flags;
	WORD nFileOffset;
	WORD nFileExtension;
	LPCWSTR lpstrDefExt;
	LPARAM lCustData;
	LPOFNHOOKPROC lpfnHook;
	LPCWSTR lpTemplateName;
	void *pvReserved;
	DWORD dwReserved;
	DWORD FlagsEx;
};

typedef struct w32api_choosefont_ansi CHOOSEFONTA, *LPCHOOSEFONTA;
typedef struct w32api_choosefont_utf8 CHOOSEFONTM, *LPCHOOSEFONTM;
typedef struct w32api_choosefont_utf16 CHOOSEFONTW, *LPCHOOSEFONTW;

typedef struct w32api_choose_color_ansi CHOOSECOLORA, *LPCHOOSECOLORA;
typedef struct w32api_choose_color_utf8 CHOOSECOLORM, *LPCHOOSECOLORM;
typedef struct w32api_choose_color_utf16 CHOOSECOLORW, *LPCHOOSECOLORW;

typedef struct w32api_find_replace_ansi FINDREPLACEA, *LPFINDREPLACEA;
typedef struct w32api_find_replace_utf8 FINDREPLACEM, *LPFINDREPLACEM;
typedef struct w32api_find_replace_utf16 FINDREPLACEW, *LPFINDREPLACEW;

typedef struct w32api_print_dlg_ansi PRINTDLGA,*LPPRINTDLGA;
typedef struct w32api_print_dlg_utf8 PRINTDLGM,*LPPRINTDLGM;
typedef struct w32api_print_dlg_utf16 PRINTDLGW,*LPPRINTDLGW;

typedef struct w32api_open_file_name_ansi OPENFILENAMEA,*LPOPENFILENAMEA;
typedef struct w32api_open_file_name_utf8 OPENFILENAMEM,*LPOPENFILENAMEM;
typedef struct w32api_open_file_name_utf16 OPENFILENAMEW,*LPOPENFILENAMEW;


__dllimport int __stdcall ChooseFontA(LPCHOOSEFONTA);
__dllimport int __stdcall ChooseFontM(LPCHOOSEFONTM);
__dllimport int __stdcall ChooseFontW(LPCHOOSEFONTW);
__dllimport int __stdcall ChooseColorA(LPCHOOSECOLORA);
__dllimport int __stdcall ChooseColorM(LPCHOOSECOLORM);
__dllimport int __stdcall ChooseColorW(LPCHOOSECOLORW);

#ifdef WINAPI_ANSI_DEFAULT
#define CHOOSEFONT CHOOSEFONTA
#define CHOOSECOLOR CHOOSECOLORA
#define FINDREPLACE FINDREPLACEA

#define ChooseFont ChooseFontA
#define ChooseColor ChooseColorA

#endif

#ifdef WINAPI_UTF8_DEFAULT
#define CHOOSEFONT CHOOSEFONTM
#define CHOOSECOLOR CHOOSECOLORM
#define FINDREPLACE FINDREPLACEM

#define ChooseFont ChooseFontM
#define ChooseColor ChooseColorM

#endif

#ifdef WINAPI_UTF16_DEFAULT
#define CHOOSEFONT CHOOSEFONTW
#define CHOOSECOLOR CHOOSECOLORW
#define FINDREPLACE FINDREPLACEW

#define ChooseFont ChooseFontW
#define ChooseColor ChooseColorW

#endif

#define FINDMSGSTRINGW			(uint16_t[]){'c','o','m','m','d','l','g','_','F','i','n','d','R','e','p','l','a','c','e',0}

#define CF_FORCEFONTEXIST 		(0x10000)

#define CC_RGBINIT 			0x1
#define CC_FULLOPEN 			0x2

#define CF_SCRIPTSONLY 			CF_ANSIONLY
#define CF_ANSIONLY 			(0x400)
#define CF_ENABLEHOOK 			(0x8)
#define CF_APPLY 			(0x200)
#define CF_NOSCRIPTSEL 			(0x800000)
#define CF_SCREENFONTS 			0x1
#define CF_NOVERTFONTS 			(0x1000000)
#define CF_FIXEDPITCHONLY 		(0x4000)
#define CF_INITTOLOGFONTSTRUCT 		(0x40)

#define FR_DOWN				0x1
#define FR_WHOLEWORD			0x2
#define FR_MATCHCASE			0x4
#define FR_FINDNEXT			0x8
#define FR_REPLACE			0x10
#define FR_REPLACEALL			0x20
#define FR_DIALOGTERM			0x40
#define FR_SHOWHELP			0x80
#define FR_ENABLEHOOK			0x100
#define FR_ENABLETEMPLATE		0x200
#define FR_NOUPDOWN			0x400
#define FR_NOMATCHCASE			0x800
#define FR_NOWHOLEWORD			0x1000
#define FR_ENABLETEMPLATEHANDLE		0x2000
#define FR_HIDEUPDOWN			0x4000
#define FR_HIDEMATCHCASE		0x8000
#define FR_HIDEWHOLEWORD		0x10000
#define FR_RAW				0x20000
#define FR_MATCHDIAC			0x20000000
#define FR_MATCHKASHIDA			0x40000000
#define FR_MATCHALEFHAMZA		0x80000000

#define PD_ALLPAGES			0x0
#define PD_SELECTION			0x1
#define PD_PAGENUMS			0x2
#define PD_NOSELECTION			0x4
#define PD_NOPAGENUMS			0x8
#define PD_COLLATE			0x10
#define PD_PRINTTOFILE			0x20
#define PD_PRINTSETUP			0x40
#define PD_NOWARNING			0x80
#define PD_RETURNDC			0x100
#define PD_RETURNIC			0x200
#define PD_RETURNDEFAULT		0x400
#define PD_SHOWHELP			0x800
#define PD_ENABLEPRINTHOOK		0x1000
#define PD_ENABLESETUPHOOK		0x2000
#define PD_ENABLEPRINTTEMPLATE		0x4000
#define PD_ENABLESETUPTEMPLATE		0x8000
#define PD_ENABLEPRINTTEMPLATEHANDLE	0x10000
#define PD_ENABLESETUPTEMPLATEHANDLE	0x20000
#define PD_USEDEVMODECOPIES		0x40000
#define PD_USEDEVMODECOPIESANDCOLLATE	0x40000
#define PD_DISABLEPRINTTOFILE		0x80000
#define PD_HIDEPRINTTOFILE		0x100000
#define PD_NONETWORKBUTTON		0x200000
#define PD_CURRENTPAGE			0x400000
#define PD_NOCURRENTPAGE		0x800000
#define PD_EXCLUSIONFLAGS		0x1000000
#define PD_USELARGETEMPLATE		0x10000000

#define WM_CHOOSEFONT_GETLOGFONT 	(WM_USER + 1)

#define OFN_READONLY			0x1
#define OFN_OVERWRITEPROMPT		0x2
#define OFN_HIDEREADONLY		0x4
#define OFN_NOCHANGEDIR			0x8
#define OFN_SHOWHELP			0x10
#define OFN_ENABLEHOOK			0x20
#define OFN_ENABLETEMPLATE		0x40
#define OFN_ENABLETEMPLATEHANDLE	0x80
#define OFN_NOVALIDATE			0x100
#define OFN_ALLOWMULTISELECT		0x200
#define OFN_EXTENSIONDIFFERENT		0x400
#define OFN_PATHMUSTEXIST		0x800
#define OFN_FILEMUSTEXIST		0x1000
#define OFN_CREATEPROMPT		0x2000
#define OFN_SHAREAWARE			0x4000
#define OFN_NOREADONLYRETURN		0x8000
#define OFN_NOTESTFILECREATE		0x10000
#define OFN_NONETWORKBUTTON		0x20000
#define OFN_NOLONGNAMES			0x40000
#define OFN_EXPLORER			0x80000
#define OFN_NODEREFERENCELINKS		0x100000
#define OFN_LONGNAMES			0x200000
#define OFN_ENABLEINCLUDENOTIFY		0x400000
#define OFN_ENABLESIZING		0x800000
#define OFN_DONTADDTORECENT		0x2000000
#define OFN_FORCESHOWHIDDEN		0x10000000
#define OFN_SHAREFALLTHROUGH		2
#define OFN_SHARENOWARN			1
#define OFN_SHAREWARN			0

#endif
