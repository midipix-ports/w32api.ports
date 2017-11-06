#ifndef _W32API_WINUSER_H_
#define _W32API_WINUSER_H_

#include <stdint.h>

#include <windef.h>
#include <winbase.h>
#include <wingdi.h>

#include "msgbox.h"

#ifndef WINVER
#define WINVER 0x0600
#endif

/* misc, clean up later? */
typedef void *HMONITOR;

typedef LRESULT (__stdcall * w32api_wnd_proc)(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef w32api_wnd_proc WNDPROC;


/* winuser flag bits and constants */
#define WH_MSGFILTER			(-1)
#define WH_JOURNALRECORD		(0)
#define WH_JOURNALPLAYBACK		(1)
#define WH_KEYBOARD			(2)
#define WH_GETMESSAGE			(3)
#define WH_CALLWNDPROC			(4)
#define WH_CBT				(5)
#define WH_SYSMSGFILTER			(6)
#define WH_MOUSE			(7)
#define WH_HARDWARE			(8)
#define WH_DEBUG			(9)
#define WH_SHELL			(10)
#define WH_FOREGROUNDIDLE		(11)
#define WH_CALLWNDPROCRET		(12)
#define WH_KEYBOARD_LL			(13)
#define WH_MOUSE_LL			(14)

#define WH_MIN				(-1)
#define WH_MAX				WH_MOUSE_LL
#define WH_MINHOOK			WH_MIN
#define WH_MAXHOOK			WH_MAX

#define GET_WHEEL_DELTA_WPARAM(wParam) 	((short)HIWORD(wParam))

#define BS_GROUPBOX 			(0x00000007)

#define COLOR_BACKGROUND 		1
#define COLOR_WINDOW 			5
#define COLOR_WINDOWTEXT 		8
#define COLOR_INFOBK 			24
#define COLOR_INFOTEXT 			23
#define COLOR_BTNFACE 			15
#define COLOR_3DFACE 			COLOR_BTNFACE

#define SPI_GETCARETWIDTH 		0x2006

#define SB_VERT				1
#define SB_LINEDOWN			1
#define SB_LINEUP			0
#define SB_PAGEDOWN			3
#define SB_PAGEUP			2
#define SB_BOTTOM			7
#define SB_TOP				6
#define SB_THUMBTRACK			5
#define SB_THUMBPOSITION		4

#define SC_CLOSE			0xF060
#define SC_KEYMENU			0xF100
#define SC_MOVE				0xF010
#define SC_RESTORE			0xF120
#define SC_SIZE				0xF000
#define SC_MINIMIZE			0xF020
#define SC_MAXIMIZE			0xF030

#define DS_MODALFRAME 			(0x80)
#define DS_SETFONT 			(0x40)
#define DS_FIXEDSYS 			(0x0008)
#define DS_SHELLFONT 			(DS_SETFONT | DS_FIXEDSYS)

#define SS_OWNERDRAW 			(0x0000000D)

#define ES_PASSWORD 			(0x0020)

#define SIF_RANGE 			0x0001
#define SIF_PAGE 			0x0002
#define SIF_POS 			0x0004
#define SIF_DISABLENOSCROLL		0x0008
#define SIF_TRACKPOS 			0x0010
#define SIF_ALL 			(SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS)

#define CF_TEXT 			1
#define CF_HDROP 			15
#define CF_UNICODETEXT 			13

#define SW_SHOWNORMAL 			1
#define SW_SHOW 			5
#define SW_SHOWNOACTIVATE 		4
#define SW_HIDE 			0
#define SW_SHOWMAXIMIZED 		3
#define SW_RESTORE 			9
#define SW_MAXIMIZE 			3
#define SW_MINIMIZE 			6

#define SM_CXVSCROLL 			2

#define MIIM_STATE			0x00000001
#define MIIM_FTYPE			0x00000100
#define MIIM_DATA			0x00000020
#define MIIM_STRING			0x00000040
#define MIIM_BITMAP			0x00000080


#define MF_STRING			(int32_t)(0x00000000)
#define MF_DISABLED 			(int32_t)(0x00000002)
#define MF_MENUBARBREAK 		(int32_t)(0x00000020)

#define MFT_STRING			MF_STRING

#define MK_CONTROL 			0x0008

#define LB_GETCURSEL 			0x0188
#define LB_GETTEXTLEN 			0x018A
#define LB_GETTEXT 			0x0189
#define LB_GETTEXTLEN 			0x018A
#define LB_RESETCONTENT 		0x0184
#define LB_RESETCONTENT 		0x0184
#define LB_ADDSTRING 			0x0180
#define LB_GETCOUNT 			0x018B
#define LB_SETCURSEL 			0x0186
#define LB_SETTABSTOPS 			0x0192

#define CB_RESETCONTENT 		0x014B
#define CB_ADDSTRING 			0x0143
#define CB_GETLBTEXT 			0x0148
#define CB_GETLBTEXTLEN 		0x0149
#define CB_GETCURSEL 			0x0147

#define EN_CHANGE 			0x0300
#define EN_KILLFOCUS 			0x0200
#define EN_SETFOCUS 			0x0100
#define EN_UPDATE 			0x0400

#define EM_SETSEL 			0x00B1

#define CBN_EDITCHANGE 			5
#define CBN_SELCHANGE 			1
#define CBN_KILLFOCUS 			4
#define CBN_SETFOCUS 			3

#define LBN_SELCHANGE 			1
#define LBN_DBLCLK 			2
#define LBN_KILLFOCUS 			5
#define LBN_SETFOCUS 			4

#define LBS_HASSTRINGS 			(0x0040)
#define LBS_NOTIFY 			(0x0001)
#define LBS_USETABSTOPS 		(0x0080)

#define CBS_DROPDOWN 			(0x0002)
#define CBS_HASSTRINGS 			(0x0200)
#define CBS_DROPDOWNLIST 		(0x0003)

#define BN_CLICKED 			0
#define BN_DOUBLECLICKED 		5
#define BN_DBLCLK 			BN_DOUBLECLICKED
#define BN_KILLFOCUS 			7
#define BN_SETFOCUS 			6
#define BN_PAINT			1

#define BF_ADJUST 			0x2000
#define BF_BOTTOM 			0x0008
#define BF_RIGHT 			0x0004
#define BF_TOP 				0x0002
#define BF_LEFT 			0x0001
#define BF_RECT 			(BF_LEFT | BF_TOP | BF_RIGHT | BF_BOTTOM)

#define BS_NOTIFY 			(0x00004000)
#define BS_AUTOCHECKBOX 		(0x00000003)
#define BS_AUTORADIOBUTTON 		(0x00000009)
#define BS_PUSHBUTTON 			(0x00000000)
#define BS_DEFPUSHBUTTON 		(0x00000001)

#define VK_MENU 			0x12
#define VK_SHIFT 			0x10
#define VK_PACKET 			0xE7
#define VK_OEM_PERIOD 			0xBE
#define VK_OEM_PLUS 			0xBB
#define VK_OEM_102 			0xE2
#define VK_OEM_1 			0xBA
#define VK_SPACE 			0x20
#define VK_NUMPAD9 			0x69
#define VK_DIVIDE 			0x6F
#define VK_MULTIPLY 			0x6A
#define VK_F1 				0x70
#define VK_F2 				0x71
#define VK_F3 				0x72
#define VK_F4 				0x73
#define VK_F5 				0x74
#define VK_F6 				0x75
#define VK_F7 				0x76
#define VK_F8 				0x77
#define VK_F9 				0x78
#define VK_F10 				0x79
#define VK_F11 				0x7A
#define VK_F12 				0x7B
#define VK_F13 				0x7C
#define VK_F14 				0x7D
#define VK_F15 				0x7E
#define VK_F16 				0x7F
#define VK_F17 				0x80
#define VK_F18 				0x81
#define VK_F19 				0x82
#define VK_F20 				0x83
#define VK_F21 				0x84
#define VK_F22 				0x85
#define VK_F23 				0x86
#define VK_F24 				0x87
#define VK_SCROLL 			0x91
#define VK_SNAPSHOT 			0x2C
#define VK_CANCEL 			0x03
#define VK_PAUSE 			0x13
#define VK_TAB 				0x09
#define VK_BACK 			0x08
#define VK_RSHIFT 			0xA1
#define VK_LSHIFT 			0xA0
#define VK_DECIMAL 			0x6E
#define VK_OEM_MINUS 			0xBD
#define VK_NUMPAD0 			0x60
#define VK_ADD 				0x6B
#define VK_SUBTRACT 			0x6D
#define VK_DELETE 			0x2E
#define VK_INSERT 			0x2D
#define VK_NEXT 			0x22
#define VK_DOWN 			0x28
#define VK_END 				0x23
#define VK_RIGHT 			0x27
#define VK_CLEAR 			0x0C
#define VK_LEFT 			0x25
#define VK_PRIOR 			0x21
#define VK_UP 				0x26
#define VK_HOME 			0x24
#define VK_ESCAPE 			0x1B
#define VK_RETURN 			0x0D
#define VK_APPS 			0x5D
#define VK_RCONTROL 			0xA3
#define VK_LMENU 			0xA4
#define VK_NUMLOCK 			0x90
#define VK_RMENU 			0xA5
#define VK_LCONTROL 			0xA2
#define VK_CONTROL 			0x11
#define VK_PROCESSKEY 			0xE5
#define VK_LWIN 			0x5B

#define KF_REPEAT 			0x4000
#define KF_EXTENDED 			0x0100

#define WM_APP 				0x8000
#define WM_VSCROLL 			0x0115
#define WM_SYSCOMMAND 			0x0112
#define WM_PAINT 			0x000F
#define WM_SETTEXT 			0x000C
#define WM_NCHITTEST 			0x0084
#define WM_ERASEBKGND 			0x0014
#define WM_DESTROY 			0x0002
#define WM_SETFONT 			0x0030
#define WM_KEYDOWN 			0x0100
#define WM_SYSKEYDOWN 			0x0104
#define WM_CHAR 			0x0102
#define WM_MBUTTONUP 			0x0208
#define WM_PASTE 			0x0302
#define WM_COMMAND 			0x0111
#define WM_SHOWWINDOW 			0x0018
#define WM_QUIT 			0x0012
#define WM_DRAWITEM 			0x002B
#define WM_GETFONT 			0x0031
#define WM_USER 			0x0400
#define WM_CLOSE 			0x0010
#define WM_NOTIFY 			0x004E
#define WM_INITDIALOG 			0x0110
#define WM_SETICON 			0x0080
#define WM_MENUCHAR 			0x0120
#define WM_MOUSEMOVE 			0x0200
#define WM_NCCREATE 			0x0081
#define WM_NCMOUSEMOVE 			0x00A0
#define WM_MOUSEWHEEL 			0x020A
#define WM_LBUTTONDOWN 			0x0201
#define WM_RBUTTONDOWN 			0x0204
#define WM_MBUTTONDOWN 			0x0207
#define WM_LBUTTONUP 			0x0202
#define WM_RBUTTONUP 			0x0205
#define WM_KEYUP 			0x0101
#define WM_SYSKEYUP 			0x0105
#define WM_SYSCHAR 			0x0106
#define WM_INPUTLANGCHANGEREQUEST 	0x0050
#define WM_INPUTLANGCHANGE 		0x0051
#define WM_IME_NOTIFY 			0x0282
#define WM_IME_STARTCOMPOSITION 	0x010D
#define WM_IME_COMPOSITION 		0x010F
#define WM_INITMENU 			0x0116
#define WM_SIZE 			0x0005
#define WM_SIZING 			0x0214
#define WM_CAPTURECHANGED 		0x0215
#define WM_EXITSIZEMOVE 		0x0232
#define WM_ENTERSIZEMOVE 		0x0231
#define WM_MOVING 			0x0216
#define WM_KILLFOCUS 			0x0008
#define WM_SETFOCUS 			0x0007
#define WM_ACTIVATE 			0x0006
#define WM_FONTCHANGE 			0x001D
#define WM_SYSCOLORCHANGE 		0x0015
#define WM_WINDOWPOSCHANGED		0x0047
#define WM_WININICHANGE 		0x001A
#define WM_THEMECHANGED 		0x031A
#define WM_TIMER 			0x0113
#define WM_XBUTTONDOWN			0x020B
#define WM_XBUTTONUP 			0x020C

#define WMSZ_BOTTOM 			6
#define WMSZ_TOP 			3
#define WMSZ_RIGHT 			2
#define WMSZ_LEFT 			1

#define WA_INACTIVE 			0

#define MONITOR_DEFAULTTONEAREST	0x00000002

#define MNC_CLOSE			1

#define TPM_RIGHTBUTTON 		(0x0002)
#define TPM_TOPALIGN 			(0x0000)
#define TPM_LEFTALIGN 			(0x0000)

#define SPI_GETWHEELSCROLLLINES		(0x0068)
#define SPI_GETNONCLIENTMETRICS		(0x0029)

#define GCLP_HCURSOR 			(-12)
#define GCLP_HICONSM			(-34)

#define GWLP_WNDPROC 			(-4)

#define HBMMENU_CALLBACK		((HBITMAP)(-1))
#define HBMMENU_SYSTEM			((HBITMAP)1)
#define HBMMENU_MBAR_RESTORE		((HBITMAP)2)
#define HBMMENU_MBAR_MINIMIZE		((HBITMAP)3)
#define HBMMENU_MBAR_CLOSE		((HBITMAP)5)
#define HBMMENU_MBAR_CLOSE_D		((HBITMAP)6)
#define HBMMENU_MBAR_MINIMIZE_D		((HBITMAP)7)
#define HBMMENU_POPUP_CLOSE		((HBITMAP)8)
#define HBMMENU_POPUP_RESTORE		((HBITMAP)9)
#define HBMMENU_POPUP_MAXIMIZE		((HBITMAP)10)
#define HBMMENU_POPUP_MINIMIZE		((HBITMAP)11)

#define IDC_IBEAM 			MAKEINTRESOURCE(32513)
#define IDC_ARROW 			MAKEINTRESOURCE(32512)

#define MF_ENABLED 			(0x00000000)
#define MF_SEPARATOR 			(0x00000800)
#define MF_UNCHECKED 			(0x00000000)
#define MF_CHECKED 			(0x00000008)
#define MF_GRAYED 			(0x00000001)

#define MFS_ENABLED			(0)
#define MFS_UNHILITE			(0)
#define MFS_UNCHECKED			(0)
#define MFS_DISABLED			(3)
#define MFS_GRAYED			(3)
#define MFS_CHECKED			(8)
#define MFS_HILITE			(128)
#define MFS_DEFAULT			(4096)

#define SWP_NOSIZE 			0x0001
#define SWP_NOACTIVATE 			0x0010
#define SWP_NOZORDER 			0x0004
#define SWP_NOMOVE 			0x0002
#define SWP_FRAMECHANGED 		0x0020
#define SWP_NOOWNERZORDER 		0x0200
#define SWP_NOCOPYBITS 			0x0100
#define SWP_NOOWNERZORDER 		0x0200
#define SWP_NOREPOSITION 		SWP_NOOWNERZORDER

#define WS_POPUP 			(0x80000000)
#define WS_EX_TOPMOST 			(0x00000008)
#define WS_EX_TOOLWINDOW 		(0x00000080)
#define WS_TABSTOP 			(0x00010000)
#define WS_EX_CLIENTEDGE 		(0x00000200)
#define WS_VISIBLE 			(0x10000000)
#define WS_CHILD 			(0x40000000)
#define WS_VSCROLL 			(0x00200000)
#define WS_THICKFRAME 			(0x00040000)
#define WS_CAPTION 			(0x00C00000)
#define WS_BORDER 			(0x00800000)
#define WS_MAXIMIZEBOX 			(0x00010000)
#define WS_SYSMENU 			(0x00080000)
#define WS_EX_LEFTSCROLLBAR 		(0x00004000)
#define WS_MINIMIZEBOX 			(0x00020000)
#define WS_OVERLAPPED 			(0x00000000)
#define WS_OVERLAPPEDWINDOW 		(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#define WS_EX_LAYERED 			0x00080000
#define WS_GROUP 			(0x00020000)

#define ES_AUTOHSCROLL 			(0x0080)

#define CS_VREDRAW 			0x0001
#define CS_HREDRAW 			0x0002
#define CS_DBLCLKS 			0x0008

#define GWL_STYLE 			(-16)
#define GWL_EXSTYLE 			(-20)

#define PM_REMOVE 			0x0001

#define CW_USEDEFAULT 			((int)0x80000000)

#define STARTF_USESHOWWINDOW 		0x00000001

#define HCBT_ACTIVATE			5
#define HCBT_CREATEWND			3

#define HWND_TOP 			((HWND)0)
#define HWND_BOTTOM 			((HWND)1)
#define HWND_NOTOPMOST			((HWND)-2)
#define HWND_TOPMOST			((HWND)-1)

#define BDR_SUNKENOUTER 		0x0002
#define BDR_RAISEDINNER 		0x0004

#define EDGE_ETCHED 			(BDR_SUNKENOUTER | BDR_RAISEDINNER)

#define IDCANCEL 				2

#define DM_SETDEFID 			(WM_USER+1)

#define HTTRANSPARENT 			(-1)

#define LWA_ALPHA 			0x00000002

#define MONITORINFOF_PRIMARY 		0x00000001

#define ODA_SELECT			0x0002

#define DLGWINDOWEXTRA			30

#define ICON_BIG 			1

#define SIZE_MAXIMIZED 			2
#define SIZE_RESTORED 			0

#define RDW_FRAME 			0x0400
#define RDW_INVALIDATE 			0x0001
#define RDW_UPDATENOW 			0x0100
#define RDW_ALLCHILDREN 		0x0080

#define IDOK 				1

#define FLASHW_TRAY 			0x00000002
#define FLASHW_TIMER 			0x00000004
#define FLASHW_STOP 			0

#define MAKELPARAM(l,h) 		((LPARAM)(DWORD)MAKELONG(l,h))

#define XBUTTON1			0x0001
#define XBUTTON2			0x0002


struct  w32api_nmhdr;
struct  w32api_icon_info;
struct  w32api_monitor_info;
struct  w32api_flash_winfo;
struct  w32api_help_info;
struct  w32api_window_info;
struct  w32api_window_placement;
struct  w32api_msg;
struct  w32api_scroll_info;
struct  w32api_paint_struct;
struct  w32api_draw_item_struct;


struct  w32api_cbt_create_wnd_ansi;
struct  w32api_cbt_create_wnd_utf8;
struct  w32api_cbt_create_wnd_utf16;

struct  w32api_wnd_class_ansi;
struct  w32api_wnd_class_utf8;
struct  w32api_wnd_class_utf16;

struct  w32api_wnd_class_ex_ansi;
struct  w32api_wnd_class_ex_utf8;
struct  w32api_wnd_class_ex_utf16;

struct  w32api_non_client_metrics_ansi;
struct  w32api_non_client_metrics_utf8;
struct  w32api_non_client_metrics_utf16;

struct  w32api_menu_item_info_ansi;
struct  w32api_menu_item_info_utf8;
struct  w32api_menu_item_info_utf16;

struct  w32api_create_struct_ansi;
struct  w32api_create_struct_utf8;
struct  w32api_create_struct_utf16;

struct  w32api_msgboxparams_asni;
struct  w32api_msgboxparams_utf8;
struct  w32api_msgboxparams_utf16;


typedef struct w32api_nmhdr *LPNMHDR;
typedef struct w32api_icon_info	ICONINFO,*PICONINFO,*LPICONINFO;
typedef struct w32api_monitor_info MONITORINFO, *LPMONITORINFO;
typedef struct w32api_flash_winfo FLASHWINFO,*PFLASHWINFO;
typedef struct w32api_help_info HELPINFO,*LPHELPINFO;
typedef struct w32api_window_info WINDOWINFO,*PWINDOWINFO,*LPWINDOWINFO;
typedef struct w32api_window_placement WINDOWPLACEMENT, *PWINDOWPLACEMENT, *LPWINDOWPLACEMENT;
typedef struct w32api_msg MSG, *PMSG, *LPMSG;
typedef struct w32api_scroll_info SCROLLINFO,*LPSCROLLINFO,*LPCSCROLLINFO;
typedef struct w32api_paint_struct PAINTSTRUCT,*PPAINTSTRUCT,*NPPAINTSTRUCT,*LPPAINTSTRUCT;
typedef struct w32api_draw_item_struct DRAWITEMSTRUCT,*PDRAWITEMSTRUCT,*LPDRAWITEMSTRUCT;


typedef struct w32api_wnd_class_ansi WNDCLASSA, *PWNDCLASSA, *NPWNDCLASSA, *LPWNDCLASSA;
typedef struct w32api_wnd_class_utf8 WNDCLASSM, *PWNDCLASSM, *NPWNDCLASSM, *LPWNDCLASSM;
typedef struct w32api_wnd_class_utf16 WNDCLASSW, *PWNDCLASSW, *NPWNDCLASSW, *LPWNDCLASSW;

typedef struct w32api_wnd_class_ex_ansi WNDCLASSEXA, *PWNDCLASSEXA, *NPWNDCLASSEXA, *LPWNDCLASSEXA;
typedef struct w32api_wnd_class_ex_utf8 WNDCLASSEXM, *PWNDCLASSEXM, *NPWNDCLASSEXM, *LPWNDCLASSEXM;
typedef struct w32api_wnd_class_ex_utf16 WNDCLASSEXW, *PWNDCLASSEXW, *NPWNDCLASSEXW, *LPWNDCLASSEXW;

typedef struct w32api_non_client_metrics_ansi NONCLIENTMETRICSA, *PNONCLIENTMETRICSA, *LPNONCLIENTMETRICSA;
typedef struct w32api_non_client_metrics_utf8 NONCLIENTMETRICSM, *PNONCLIENTMETRICSM, *LPNONCLIENTMETRICSM;
typedef struct w32api_non_client_metrics_utf16 NONCLIENTMETRICSW, *PNONCLIENTMETRICSW, *LPNONCLIENTMETRICSW;

typedef struct w32api_msgboxparams_ansi MSGBOXPARAMSA, *PMSGBOXPARAMSA, *LPMSGBOXPARAMSA;
typedef struct w32api_msgboxparams_utf8 MSGBOXPARAMSM, *PMSGBOXPARAMSM, *LPMSGBOXPARAMSM;
typedef struct w32api_msgboxparams_utf16 MSGBOXPARAMSW, *PMSGBOXPARAMSW, *LPMSGBOXPARAMSW;

typedef struct w32api_create_struct_ansi CREATESTRUCTA,*LPCREATESTRUCTA;
typedef struct w32api_create_struct_utf8 CREATESTRUCTM,*LPCREATESTRUCTM;
typedef struct w32api_create_struct_utf16 CREATESTRUCTW,*LPCREATESTRUCTW;

typedef struct w32api_menu_item_info_ansi MENUITEMINFOA,*LPMENUITEMINFOA,*LPCMENUITEMINFOA;
typedef struct w32api_menu_item_info_utf8 MENUITEMINFOM,*LPMENUITEMINFOM,*LPCMENUITEMINFOM;
typedef struct w32api_menu_item_info_utf16 MENUITEMINFOW,*LPMENUITEMINFOW,*LPCMENUITEMINFOW;

typedef struct w32api_cbt_create_wnd_ansi CBT_CREATEWNDA,*LPCBT_CREATEWNDA;
typedef struct w32api_cbt_create_wnd_utf8 CBT_CREATEWNDM,*LPCBT_CREATEWNDM;
typedef struct w32api_cbt_create_wnd_utf16 CBT_CREATEWNDW,*LPCBT_CREATEWNDW;

/* clean me up later? */
typedef LRESULT (__stdcall *HOOKPROC)(int,WPARAM,LPARAM);

typedef int (__stdcall *WNDENUMPROC) (HWND, LPARAM);
typedef int (__stdcall *MONITORENUMPROC) (HMONITOR, HDC, LPRECT, LPARAM);

typedef void (__stdcall *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);
typedef void (__stdcall *TIMERPROC) (HWND, UINT, UINT_PTR, DWORD);
typedef INT_PTR (__stdcall *DLGPROC) (HWND, UINT, WPARAM, LPARAM);
/*  */

struct w32api_nmhdr {
	HWND hwndFrom;
	UINT_PTR idFrom;
	UINT code;
};

struct w32api_icon_info {
	BOOL		fIcon;
	DWORD		xHotspot;
	DWORD		yHotspot;
	HBITMAP		hbmMask;
	HBITMAP		hbmColor;
};

struct w32api_monitor_info {
	DWORD	cbSize;
	RECT	rcMonitor;
	RECT	rcWork;
	DWORD	dwFlags;
};

struct w32api_flash_winfo {
    UINT cbSize;
    HWND hwnd;
    DWORD dwFlags;
    UINT uCount;
    DWORD dwTimeout;
};

struct w32api_help_info {
    UINT cbSize;
    int iContextType;
    int iCtrlId;
    HANDLE hItemHandle;
    DWORD_PTR dwContextId;
    POINT MousePos;
};

struct w32api_window_info {
    DWORD cbSize;
    RECT rcWindow;
    RECT rcClient;
    DWORD dwStyle;
    DWORD dwExStyle;
    DWORD dwWindowStatus;
    UINT cxWindowBorders;
    UINT cyWindowBorders;
    ATOM atomWindowType;
    WORD wCreatorVersion;
};

struct w32api_window_placement {
    UINT length;
    UINT flags;
    UINT showCmd;
    POINT ptMinPosition;
    POINT ptMaxPosition;
    RECT rcNormalPosition;
};

struct w32api_msg {
  HWND   hwnd;
  UINT   message;
  WPARAM wParam;
  LPARAM lParam;
  DWORD  time;
  POINT  pt;
};

struct w32api_scroll_info {
    UINT cbSize;
    UINT fMask;
    int nMin;
    int nMax;
    UINT nPage;
    int nPos;
    int nTrackPos;
};

struct w32api_paint_struct {
    HDC hdc;
    int fErase;
    RECT rcPaint;
    int fRestore;
    int fIncUpdate;
    BYTE rgbReserved[32];
};

struct w32api_draw_item_struct {
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    UINT itemAction;
    UINT itemState;
    HWND hwndItem;
    HDC hDC;
    RECT rcItem;
    ULONG_PTR itemData;
};



//ansi-utf8-utf16 structs
struct  w32api_cbt_create_wnd_ansi {
	LPCREATESTRUCTA lpcs;
	HWND hwndInsertAfter;
};

struct  w32api_cbt_create_wnd_utf8 {
	LPCREATESTRUCTM lpcs;
	HWND hwndInsertAfter;
};

struct  w32api_cbt_create_wnd_utf16 {
	LPCREATESTRUCTW lpcs;
	HWND hwndInsertAfter;
};

struct w32api_msgboxparams_ansi {
    UINT cbSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpszText;
    LPCSTR lpszCaption;
    DWORD dwStyle;
    LPCSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfnMsgBoxCallback;
    DWORD dwLanguageId;
};

struct w32api_msgboxparams_utf8 {
    UINT cbSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpszText;
    LPCSTR lpszCaption;
    DWORD dwStyle;
    LPCSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfnMsgBoxCallback;
    DWORD dwLanguageId;
};

struct w32api_msgboxparams_utf16 {
    UINT cbSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpszText;
    LPCWSTR lpszCaption;
    DWORD dwStyle;
    LPCWSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfnMsgBoxCallback;
    DWORD dwLanguageId;
};

struct w32api_create_struct_ansi {
	LPVOID lpCreateParams;
	HINSTANCE hInstance;
	HMENU hMenu;
	HWND hwndParent;
	int cy;
	int cx;
	int y;
	int x;
	LONG style;
	LPCSTR lpszName;
	LPCSTR lpszClass;
	DWORD dwExStyle;
};

struct w32api_create_struct_utf8 {
	LPVOID lpCreateParams;
	HINSTANCE hInstance;
	HMENU hMenu;
	HWND hwndParent;
	int cy;
	int cx;
	int y;
	int x;
	LONG style;
	LPCSTR lpszName;
	LPCSTR lpszClass;
	DWORD dwExStyle;
};

struct w32api_create_struct_utf16 {
	LPVOID lpCreateParams;
	HINSTANCE hInstance;
	HMENU hMenu;
	HWND hwndParent;
	int cy;
	int cx;
	int y;
	int x;
	LONG style;
	LPCWSTR lpszName;
	LPCWSTR lpszClass;
	DWORD dwExStyle;
};

struct w32api_menu_item_info_ansi {
	UINT cbSize;
	UINT fMask;
	UINT fType;
	UINT fState;
	UINT wID;
	HMENU hSubMenu;
	HBITMAP hbmpChecked;
	HBITMAP hbmpUnchecked;
	ULONG_PTR dwItemData;
	LPSTR dwTypeData;
	UINT cch;
	HBITMAP hbmpItem;
};

struct w32api_menu_item_info_utf8 {
	UINT cbSize;
	UINT fMask;
	UINT fType;
	UINT fState;
	UINT wID;
	HMENU hSubMenu;
	HBITMAP hbmpChecked;
	HBITMAP hbmpUnchecked;
	ULONG_PTR dwItemData;
	LPSTR dwTypeData;
	UINT cch;
	HBITMAP hbmpItem;
};

struct w32api_menu_item_info_utf16 {
	UINT cbSize;
	UINT fMask;
	UINT fType;
	UINT fState;
	UINT wID;
	HMENU hSubMenu;
	HBITMAP hbmpChecked;
	HBITMAP hbmpUnchecked;
	ULONG_PTR dwItemData;
	LPWSTR dwTypeData;
	UINT cch;
	HBITMAP hbmpItem;
};

struct w32api_wnd_class_ansi {
	UINT style;
	WNDPROC lpfnWndProc;
	int cbClsExtra;
	int cbWndExtra;
	HINSTANCE hInstance;
	HICON hIcon;
	HCURSOR hCursor;
	HBRUSH hbrBackground;
	LPCSTR lpszMenuName;
	LPCSTR lpszClassName;
};

struct w32api_wnd_class_utf8 {
	UINT style;
	WNDPROC lpfnWndProc;
	int cbClsExtra;
	int cbWndExtra;
	HINSTANCE hInstance;
	HICON hIcon;
	HCURSOR hCursor;
	HBRUSH hbrBackground;
	LPCSTR lpszMenuName;
	LPCSTR lpszClassName;
};

struct w32api_wnd_class_utf16 {
	UINT style;
	WNDPROC lpfnWndProc;
	int cbClsExtra;
	int cbWndExtra;
	HINSTANCE hInstance;
	HICON hIcon;
	HCURSOR hCursor;
	HBRUSH hbrBackground;
	LPCWSTR lpszMenuName;
	LPCWSTR lpszClassName;
};

struct w32api_wnd_class_ex_ansi {
    UINT cbSize;
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
    HICON hIconSm;
};

struct w32api_wnd_class_ex_utf8 {
    UINT cbSize;
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
    HICON hIconSm;
};

struct w32api_wnd_class_ex_utf16 {
    UINT cbSize;
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
    HICON hIconSm;
};

struct w32api_non_client_metrics_ansi {
    UINT cbSize;
    int iBorderWidth;
    int iScrollWidth;
    int iScrollHeight;
    int iCaptionWidth;
    int iCaptionHeight;
    LOGFONTA lfCaptionFont;
    int iSmCaptionWidth;
    int iSmCaptionHeight;
    LOGFONTA lfSmCaptionFont;
    int iMenuWidth;
    int iMenuHeight;
    LOGFONTA lfMenuFont;
    LOGFONTA lfStatusFont;
    LOGFONTA lfMessageFont;
#if WINVER >= 0x0600
    int iPaddedBorderWidth;
#endif
};

struct w32api_non_client_metrics_utf8 {
    UINT cbSize;
    int iBorderWidth;
    int iScrollWidth;
    int iScrollHeight;
    int iCaptionWidth;
    int iCaptionHeight;
    LOGFONTM lfCaptionFont;
    int iSmCaptionWidth;
    int iSmCaptionHeight;
    LOGFONTM lfSmCaptionFont;
    int iMenuWidth;
    int iMenuHeight;
    LOGFONTM lfMenuFont;
    LOGFONTM lfStatusFont;
    LOGFONTM lfMessageFont;
#if WINVER >= 0x0600
    int iPaddedBorderWidth;
#endif
};

struct w32api_non_client_metrics_utf16 {
    UINT cbSize;
    int iBorderWidth;
    int iScrollWidth;
    int iScrollHeight;
    int iCaptionWidth;
    int iCaptionHeight;
    LOGFONTW lfCaptionFont;
    int iSmCaptionWidth;
    int iSmCaptionHeight;
    LOGFONTW lfSmCaptionFont;
    int iMenuWidth;
    int iMenuHeight;
    LOGFONTW lfMenuFont;
    LOGFONTW lfStatusFont;
    LOGFONTW lfMessageFont;
#if WINVER >= 0x0600
    int iPaddedBorderWidth;
#endif
};

#ifdef WINAPI_ANSI_DEFAULT
#define WNDCLASS WNDCLASSA
#define NONCLIENTMETRICS NONCLIENTMETRICSA
#define MSGBOXPARAMS MSGBOXPARAMSA

#endif

#ifdef WINAPI_UTF8_DEFAULT
#define WNDCLASS WNDCLASSM
#define NONCLIENTMETRICS NONCLIENTMETRICSM
#define MSGBOXPARAMS MSGBOXPARAMSM

#endif

#ifdef WINAPI_UTF16_DEFAULT
#define WNDCLASS WNDCLASSW
#define NONCLIENTMETRICS NONCLIENTMETRICSW
#define MSGBOXPARAMS MSGBOXPARAMSW

#endif


__dllimport int __stdcall EnableWindow(HWND hwnd,BOOL enabled);
__dllimport int __stdcall GetClassNameA(HWND,LPSTR,int);
__dllimport int __stdcall GetClassNameW(HWND,LPWSTR,int);
__dllimport int __stdcall SetScrollInfo(HWND hwnd,int nBar,LPCSCROLLINFO lpsi,int redraw);
__dllimport int __stdcall GetScrollInfo(HWND hwnd,int nBar,LPSCROLLINFO lpsi);
__dllimport int __stdcall ShowWindow(HWND hwnd, int nCmdShow);
__dllimport int __stdcall IsWindowVisible(HWND hwnd);
__dllimport int __stdcall ClientToScreen(HWND hwnd, LPPOINT lpPoint);
__dllimport int __stdcall GetWindowRect(HWND hwnd, LPRECT lpRect);
__dllimport int __stdcall SetWindowPos(HWND hwnd, HWND hwnInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);
__dllimport int __stdcall GetClientRect(HWND hwnd, LPRECT lpRect);
__dllimport int __stdcall SetFocus(HWND hwnd);
__dllimport int __stdcall CreateCaret(HWND hwnd, HBITMAP hBitmap, int nWidth, int nHeight);
__dllimport HWND __stdcall GetDlgItem(HWND hDlg, int nIDDlgItem);
__dllimport int __stdcall MapDialogRect(HWND hDlg, LPRECT lpRect);
__dllimport int __stdcall DrawEdge(HDC hdc, LPRECT qrc, UINT edge, UINT grfFlags);
__dllimport HDC __stdcall BeginPaint(HWND hwnd, LPPAINTSTRUCT lpPaint);
__dllimport int __stdcall EndPaint(HWND hwnd, const PAINTSTRUCT *lpPaint);
__dllimport int __stdcall DestroyWindow(HWND hwnd);
__dllimport unsigned long __stdcall GetSysColor(int nIndex);
__dllimport int __stdcall TranslateMessage(const MSG *lpMsg);
__dllimport short __stdcall GetKeyState(int nVirtKey);
__dllimport int __stdcall InvalidateRect(HWND hWnd, const RECT *lpRect, int bErase);
__dllimport int __stdcall CheckRadioButton(HWND hDlg, int nIDFirstButton, int nIDLastButton, int nIDCheckButton);
__dllimport int __stdcall SetCaretPos(int X, int Y);
__dllimport int __stdcall GetCaretPos(LPPOINT lpPoint);
__dllimport HMONITOR __stdcall MonitorFromPoint(POINT pt, DWORD dwFlags);
__dllimport int __stdcall ToUnicode(UINT wVirtKey, UINT wScanCode, const BYTE *lpKeyState, LPWSTR pwszBuff, int cchBuff, UINT wFlags);
__dllimport int __stdcall GetKeyboardState(PBYTE lpKeyState);
__dllimport int __stdcall ScreenToClient(HWND hWnd, LPPOINT lpPoint);
__dllimport int __stdcall ReleaseCapture(void);
__dllimport UINT __stdcall GetDoubleClickTime(void);
__dllimport long __stdcall GetMessageTime(void);
__dllimport HWND __stdcall WindowFromPoint(POINT Point);
__dllimport int __stdcall ShowCursor(int bShow);
__dllimport HCURSOR __stdcall SetCursor(HCURSOR hCursor);
__dllimport int __stdcall GetCursorPos(LPPOINT lpPoint);
__dllimport UINT_PTR __stdcall SetTimer(HWND hWnd, UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc);
__dllimport int __stdcall CloseClipboard(void);
__dllimport int __stdcall EmptyClipboard(void);
__dllimport int __stdcall OpenClipboard(HWND hWndNewOwner);
__dllimport HANDLE __stdcall SetClipboardData(UINT uFormat, HANDLE hMem);
__dllimport HWND __stdcall GetParent(HWND hWnd);
__dllimport int __stdcall EnableMenuItem(HMENU hMenu, UINT uIDEnableItem, UINT uEnable);
__dllimport int __stdcall IsClipboardFormatAvailable(UINT format);
__dllimport int __stdcall IsZoomed(HWND hWnd);
__dllimport HMENU __stdcall CreatePopupMenu(void);
__dllimport HDC __stdcall GetDC(HWND hWnd);
__dllimport int __stdcall ReleaseDC(HWND hWnd, HDC hDC);
__dllimport HANDLE __stdcall GetClipboardData(UINT uFormat);
__dllimport int __stdcall GetWindowPlacement(HWND hWnd, WINDOWPLACEMENT *lpwndpl);
__dllimport int __stdcall IsIconic(HWND hWnd);
__dllimport int __stdcall GetWindowInfo(HWND hWnd, PWINDOWINFO pwi);
__dllimport UINT __stdcall IsDlgButtonChecked(HWND hDlg, int nIDButton);
__dllimport HWND __stdcall SetCapture(HWND hWnd);
__dllimport HMENU __stdcall GetSystemMenu(HWND hWnd, int bRevert);
__dllimport int __stdcall TrackPopupMenu(HMENU hMenu, UINT uFlags, int x, int y, int nReserved, HWND hWn, const RECT *prcRect);
__dllimport int __stdcall KillTimer(HWND hWnd, UINT_PTR uIDEvent);
__dllimport int __stdcall DestroyCaret(void);
__dllimport int __stdcall ShowCaret(HWND hWnd);
__dllimport int __stdcall RedrawWindow(HWND hWnd, const RECT *lprcUpdate, HRGN hrgnUpdate, UINT flags);
__dllimport int __stdcall MessageBeep(UINT uType);
__dllimport int __stdcall EnumWindows(WNDENUMPROC lpEnumFunc, LPARAM lParam);
__dllimport int __stdcall BringWindowToTop(HWND hWnd);
__dllimport HMONITOR __stdcall MonitorFromWindow(HWND hWnd, DWORD dwFlags);
__dllimport int __stdcall EnumDisplayMonitors(HDC hdc, LPCRECT lprcClip, MONITORENUMPROC lpfnEnum, LPARAM dwData);
__dllimport int __stdcall AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, int bMenu);
__dllimport int __stdcall FlashWindowEx(PFLASHWINFO pfwi);
__dllimport int __stdcall GetSystemMetrics(int nIndex);
__dllimport UINT __stdcall GetCaretBlinkTime(void);
__dllimport int __stdcall SetLayeredWindowAttributes (HWND hwnd, COLORREF crKey, BYTE bAlpha, DWORD dwFlags);
__dllimport HKL __stdcall GetKeyboardLayout(DWORD idThread);
__dllimport BOOL __stdcall UnhookWindowsHookEx(HHOOK hhk);
__dllimport LRESULT __stdcall CallNextHookEx(HHOOK hhk, int nCode, WPARAM wParam, LPARAM lParam);
__dllimport BOOL __stdcall GetIconInfo(HICON hIcon, PICONINFO piconinfo);
__dllimport BOOL __stdcall DestroyMenu(HMENU hMenu);
__dllimport BOOL __stdcall SetForegroundWindow(HWND hWnd);

__dllimport LRESULT __stdcall DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall DefWindowProcM(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall SendMessageM(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall SendMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport HWND __stdcall CreateWindowExA(DWORD dwExStyle, LPCSTR lpClassname, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
__dllimport HWND __stdcall CreateWindowExM(DWORD dwExStyle, LPCSTR lpClassname, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
__dllimport HWND __stdcall CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassname, LPCWSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
__dllimport int __stdcall GetWindowTextLengthA(HWND hWnd);
__dllimport int __stdcall GetWindowTextLengthM(HWND hWnd);
__dllimport int __stdcall GetWindowTextLengthW(HWND hWnd);
__dllimport int __stdcall GetWindowTextA(HWND hWnd, LPSTR lpString, int nMaxCount);
__dllimport int __stdcall GetWindowTextM(HWND hWnd, LPSTR lpString, int nMaxCount);
__dllimport int __stdcall GetWindowTextW(HWND hWnd, LPWSTR lpString, int nMaxCount);
__dllimport unsigned short __stdcall RegisterClassA(const WNDCLASSA *lpWndClass);
__dllimport unsigned short __stdcall RegisterClassM(const WNDCLASSM *lpWndClass);
__dllimport unsigned short __stdcall RegisterClassW(const WNDCLASSW *lpWndClass);
__dllimport int __stdcall SystemParametersInfoA(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni);
__dllimport int __stdcall SystemParametersInfoM(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni);
__dllimport int __stdcall SystemParametersInfoW(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni);
__dllimport int __stdcall SetWindowTextA(HWND hWnd, LPCSTR lpString);
__dllimport int __stdcall SetWindowTextM(HWND hWnd, LPCSTR lpString);
__dllimport int __stdcall SetWindowTextW(HWND hWnd, LPCWSTR lpString);
__dllimport int __stdcall SetDlgItemTextA(HWND hDlg, int nIDDlgItem, LPCSTR lpString);
__dllimport int __stdcall SetDlgItemTextM(HWND hDlg, int nIDDlgItem, LPCSTR lpString);
__dllimport int __stdcall SetDlgItemTextW(HWND hDlg, int nIDDlgItem, LPCWSTR lpString);
__dllimport int __stdcall CheckDlgButton(HWND hDlg, int nIDButton, UINT uCheck);
__dllimport LRESULT __stdcall SendDlgItemMessageA(HWND hDlg, int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall SendDlgItemMessageM(HWND hDlg, int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall SendDlgItemMessageW(HWND hDlg, int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall CallWindowProcA(WNDPROC lpPrevWndFunc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall CallWindowProcM(WNDPROC lpPrevWndFunc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall CallWindowProcW(WNDPROC lpPrevWndFunc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport int __stdcall MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
__dllimport int __stdcall MessageBoxM(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
__dllimport int __stdcall MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType);
__dllimport LRESULT __stdcall DefDlgProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall DefDlgProcM(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall DefDlgProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport int __stdcall MessageBoxIndirectA(const MSGBOXPARAMSA *lpmbp);
__dllimport int __stdcall MessageBoxIndirectM(const MSGBOXPARAMSM *lpmbp);
__dllimport int __stdcall MessageBoxIndirectW(const MSGBOXPARAMSW *lpmbp);
__dllimport UINT __stdcall MapVirtualKeyA(UINT uCode, UINT uMapType);
__dllimport UINT __stdcall MapVirtualKeyM(UINT uCode, UINT uMapType);
__dllimport UINT __stdcall MapVirtualKeyW(UINT uCode, UINT uMapType);
__dllimport HCURSOR __stdcall LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName);
__dllimport HCURSOR __stdcall LoadCursorM(HINSTANCE hInstance, LPCSTR lpCursorName);
__dllimport HCURSOR __stdcall LoadCursorW(HINSTANCE hInstance, LPCWSTR lpCursorName);
__dllimport int __stdcall ModifyMenuA(HMENU hMnu, UINT uPosition, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem);
__dllimport int __stdcall ModifyMenuM(HMENU hMnu, UINT uPosition, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem);
__dllimport int __stdcall ModifyMenuW(HMENU hMnu, UINT uPosition, UINT uFlags, UINT_PTR uIDNewItem, LPCWSTR lpNewItem);
__dllimport HICON __stdcall LoadIconA(HINSTANCE hInstance, LPCSTR lpIconName);
__dllimport HICON __stdcall LoadIconM(HINSTANCE hInstance, LPCSTR lpIconName);
__dllimport HICON __stdcall LoadIconW(HINSTANCE hInstance, LPCWSTR lpIconName);
__dllimport int __stdcall AppendMenuA(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem);
__dllimport int __stdcall AppendMenuM(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem);
__dllimport int __stdcall AppendMenuW(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCWSTR lpNewItem);
__dllimport int __stdcall InsertMenuA(HMENU hMenu, UINT uPosition, UINT uFlags, UINT_PTR uIDNEwItem, LPCSTR lpNewItem);
__dllimport int __stdcall InsertMenuM(HMENU hMenu, UINT uPosition, UINT uFlags, UINT_PTR uIDNEwItem, LPCSTR lpNewItem);
__dllimport int __stdcall InsertMenuW(HMENU hMenu, UINT uPosition, UINT uFlags, UINT_PTR uIDNEwItem, LPCWSTR lpNewItem);
__dllimport ULONG_PTR __stdcall SetClassLongPtrA(HWND hWnd, int nIndex, LONG_PTR dwNewLong);
__dllimport ULONG_PTR __stdcall SetClassLongPtrM(HWND hWnd, int nIndex, LONG_PTR dwNewLong);
__dllimport ULONG_PTR __stdcall SetClassLongPtrW(HWND hWnd, int nIndex, LONG_PTR dwNewLong);
__dllimport LONG_PTR __stdcall SetWindowLongPtrA(HWND, int nIndex, LONG_PTR dwNewLong);
__dllimport LONG_PTR __stdcall SetWindowLongPtrM(HWND, int nIndex, LONG_PTR dwNewLong);
__dllimport LONG_PTR __stdcall SetWindowLongPtrW(HWND, int nIndex, LONG_PTR dwNewLong);
__dllimport LRESULT __stdcall DispatchMessageA(const MSG *lpMsg);
__dllimport LRESULT __stdcall DispatchMessageM(const MSG *lpMsg);
__dllimport LRESULT __stdcall DispatchMessageW(const MSG *lpMsg);
__dllimport int __stdcall IsDialogMessageA(HWND hDlg, LPMSG lpMsg);
__dllimport int __stdcall IsDialogMessageM(HWND hDlg, LPMSG lpMsg);
__dllimport int __stdcall IsDialogMessageW(HWND hDlg, LPMSG lpMsg);
__dllimport HWND __stdcall CreateDialogParamA(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam);
__dllimport HWND __stdcall CreateDialogParamM(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam);
__dllimport HWND __stdcall CreateDialogParamW(HINSTANCE hInstance, LPCWSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam);
__dllimport LRESULT __stdcall SendDlgItemMessageA(HWND hDlg, int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall SendDlgItemMessageM(HWND hDlg, int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport LRESULT __stdcall SendDlgItemMessageW(HWND hDlg, int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam);
__dllimport int __stdcall PeekMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
__dllimport int __stdcall PeekMessageM(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
__dllimport int __stdcall PeekMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
__dllimport int __stdcall GetMonitorInfoA(HMONITOR hMonitor,LPMONITORINFO lpmi);
__dllimport int __stdcall GetMonitorInfoM(HMONITOR hMonitor,LPMONITORINFO lpmi);
__dllimport int __stdcall GetMonitorInfoW(HMONITOR hMonitor,LPMONITORINFO lpmi);
__dllimport LONG __stdcall GetWindowLongA(HWND hWnd, int nIndex);
__dllimport LONG __stdcall GetWindowLongM(HWND hWnd, int nIndex);
__dllimport LONG __stdcall GetWindowLongW(HWND hWnd, int nIndex);
__dllimport LONG __stdcall SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong);
__dllimport LONG __stdcall SetWindowLongM(HWND hWnd, int nIndex, LONG dwNewLong);
__dllimport LONG __stdcall SetWindowLongW(HWND hWnd, int nIndex, LONG dwNewLong);
__dllimport ATOM __stdcall RegisterClassExA(const WNDCLASSEXA *);
__dllimport ATOM __stdcall RegisterClassExM(const WNDCLASSEXM *);
__dllimport ATOM __stdcall RegisterClassExW(const WNDCLASSEXW *);
__dllimport UINT __stdcall RegisterClipboardFormatA(LPCSTR lpszFormat);
__dllimport UINT __stdcall RegisterClipboardFormatM(LPCSTR lpszFormat);
__dllimport UINT __stdcall RegisterClipboardFormatW(LPCWSTR lpszFormat);
__dllimport HHOOK __stdcall SetWindowsHookExA(int,HOOKPROC,HINSTANCE,DWORD);
__dllimport HHOOK __stdcall SetWindowsHookExM(int,HOOKPROC,HINSTANCE,DWORD);
__dllimport HHOOK __stdcall SetWindowsHookExW(int,HOOKPROC,HINSTANCE,DWORD);
__dllimport ULONG_PTR __stdcall GetClassLongPtrA(HWND hWnd, int nIndex);
__dllimport ULONG_PTR __stdcall GetClassLongPtrM(HWND hWnd, int nIndex);
__dllimport ULONG_PTR __stdcall GetClassLongPtrW(HWND hWnd, int nIndex);
__dllimport BOOL __stdcall SetMenuItemInfoA(HMENU hmenu, UINT item, BOOL fByPositon, LPCMENUITEMINFOA lpmii);
__dllimport BOOL __stdcall SetMenuItemInfoM(HMENU hmenu, UINT item, BOOL fByPositon, LPCMENUITEMINFOM lpmii);
__dllimport BOOL __stdcall SetMenuItemInfoW(HMENU hmenu, UINT item, BOOL fByPositon, LPCMENUITEMINFOW lpmii);
__dllimport BOOL __stdcall GetMenuItemInfoA(HMENU hmenu, UINT item, BOOL fByPosition, LPMENUITEMINFOA lpmii);
__dllimport BOOL __stdcall GetMenuItemInfoM(HMENU hmenu, UINT item, BOOL fByPosition, LPMENUITEMINFOM lpmii);
__dllimport BOOL __stdcall GetMenuItemInfoW(HMENU hmenu, UINT item, BOOL fByPosition, LPMENUITEMINFOW lpmii);


#define MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((WORD)(i))))
#define MAKEINTRESOURCEM(i) ((LPSTR)((ULONG_PTR)((WORD)(i))))
#define MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((WORD)(i))))

#define CreateDialogA(hInstance,lpName,hWndParent,lpDialogFunc) CreateDialogParamA(hInstance,lpName,hWndParent,lpDialogFunc,(LPARAM)0)
#define CreateDialogM(hInstance,lpName,hWndParent,lpDialogFunc) CreateDialogParamA(hInstance,lpName,hWndParent,lpDialogFunc,(LPARAM)0)
#define CreateDialogW(hInstance,lpName,hWndParent,lpDialogFunc) CreateDialogParamW(hInstance,lpName,hWndParent,lpDialogFunc,(LPARAM)0)

#ifdef WINAPI_ANSI_DEFAULT
#define DefWindowProc DefWindowProcA
#define SendMessage SendMessageA
#define CreateWindowEx CreateWindowExA
#define GetWindowTextLength GetWindowTextLengthA
#define GetWindowText GetWindowTextA
#define RegisterClass RegisterClassA
#define SystemParametersInfo SystemParametersInfoA
#define SetWindowText SetWindowTextA
#define SetDlgItemText SetDlgItemTextA
#define SendDlgItemMessage SendDlgItemMessageA
#define CallWindowProc CallWindowProcA
#define MessageBox MessageBoxA
#define DefDlgProc DefDlgProcA
#define MessageBoxIndirect MessageBoxIndirectA
#define MapVirtualKey MapVirtualKeyA
#define ModifyMenu ModifyMenuA
#define LoadCursor LoadCursorA
#define LoadIcon LoadIconA
#define AppendMenu AppendMenuA
#define InsertMenu InsertMenuA
#define SetClassLongPtr SetClassLongPtrA
#define SetWindowLongPtr SetWindowLongPtrA
#define DispatchMessage DispatchMessageA
#define IsDialogMessage IsDialogMessageA
#define CreateDialog CreateDialogA
#define SendDlgItemMessage SendDlgItemMessageA
#define PeekMessage PeekMessageA
#define GetMonitorInfo GetMonitorInfoA
#define GetWindowLong GetWindowLongA
#define SetWindowLong SetWindowLongA
#define RegisterClassEx RegisterClassExA
#define RegisterClipboardFormat RegisterClipboardFormatA
#define GetClassLongPtr GetClassLongPtrA


#define MAKEINTRESOURCE MAKEINTRESOURCEA

#endif

#ifdef WINAPI_UTF8_DEFAULT
#define DefWindowProc DefWindowProcM
#define SendMessage SendMessageM
#define CreateWindowEx CreateWindowExM
#define GetWindowTextLength GetWindowTextLengthM
#define GetWindowText GetWindowTextM
#define RegisterClass RegisterClassM
#define SystemParametersInfo SystemParametersInfoM
#define SetWindowText SetWindowTextM
#define SetDlgItemText SetDlgItemTextM
#define SendDlgItemMessage SendDlgItemMessageM
#define CallWindowProc CallWindowProcM
#define MessageBox MessageBoxM
#define DefDlgProc DefDlgProcM
#define MessageBoxIndirect MessageBoxIndirectM
#define MapVirtualKey MapVirtualKeyM
#define ModifyMenu ModifyMenuM
#define LoadCursor LoadCursorM
#define LoadIcon LoadIconM
#define AppendMenu AppendMenuM
#define InsertMenu InsertMenuM
#define SetClassLongPtr SetClassLongPtrM
#define SetWindowLongPtr SetWindowLongPtrM
#define DispatchMessage DispatchMessageM
#define IsDialogMessage IsDialogMessageM
#define CreateDialog CreateDialogM
#define SendDlgItemMessage SendDlgItemMessageM
#define PeekMessage PeekMessageM
#define GetMonitorInfo GetMonitorInfoM
#define GetWindowLong GetWindowLongM
#define SetWindowLong SetWindowLongM
#define RegisterClassEx RegisterClassExM
#define RegisterClipboardFormat RegisterClipboardFormatM
#define GetClassLongPtr GetClassLongPtrM


#define MAKEINTRESOURCE MAKEINTRESOURCEM

#endif

#ifdef WINAPI_UTF16_DEFAULT
#define DefWindowProc DefWindowProcW
#define SendMessage SendMessageW
#define CreateWindowEx CreateWindowExW
#define GetWindowTextLength GetWindowTextLengthW
#define GetWindowText GetWindowTextW
#define RegisterClass RegisterClassW
#define SystemParametersInfo SystemParametersInfoW
#define SetWindowText SetWindowTextW
#define SetDlgItemText SetDlgItemTextW
#define SendDlgItemMessage SendDlgItemMessageW
#define CallWindowProc CallWindowProcW
#define MessageBox MessageBoxW
#define DefDlgProc DefDlgProcW
#define MessageBoxIndirect MessageBoxIndirectW
#define MapVirtualKey MapVirtualKeyW
#define ModifyMenu ModifyMenuW
#define LoadCursor LoadCursorW
#define LoadIcon LoadIconW
#define AppendMenu AppendMenuW
#define InsertMenu InsertMenuW
#define SetClassLongPtr SetClassLongPtrW
#define SetWindowLongPtr SetWindowLongPtrW
#define DispatchMessage DispatchMessageW
#define IsDialogMessage IsDialogMessageW
#define CreateDialog CreateDialogW
#define SendDlgItemMessage SendDlgItemMessageW
#define PeekMessage PeekMessageW
#define GetMonitorInfo GetMonitorInfoW
#define GetWindowLong GetWindowLongW
#define SetWindowLong SetWindowLongW
#define RegisterClassEx RegisterClassExW
#define RegisterClipboardFormat RegisterClipboardFormatW
#define GetClassLongPtr GetClassLongPtrW


#define MAKEINTRESOURCE MAKEINTRESOURCEW

#endif

#endif
