#ifndef _W32API_COMMCTRL_H_
#define _W32API_COMMCTRL_H_

#include <windef.h>

typedef struct _TREEITEM *HTREEITEM;


  typedef struct tagTVITEMA {
    UINT mask;
    HTREEITEM hItem;
    UINT state;
    UINT stateMask;
    LPSTR pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    LPARAM lParam;
  } TVITEMA,*LPTVITEMA;

  typedef struct tagTVITEMM {
    UINT mask;
    HTREEITEM hItem;
    UINT state;
    UINT stateMask;
    LPSTR pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    LPARAM lParam;
  } TVITEMM,*LPTVITEMM;

  typedef struct tagTVITEMW {
    UINT mask;
    HTREEITEM hItem;
    UINT state;
    UINT stateMask;
    LPWSTR pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    LPARAM lParam;
  } TVITEMW,*LPTVITEMW;

  typedef struct tagTVITEMEXA {
    UINT mask;
    HTREEITEM hItem;
    UINT state;
    UINT stateMask;
    LPSTR pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    LPARAM lParam;
    int iIntegral;
//#if _WIN32_IE >= 0x0600
    UINT uStateEx;
    HWND hwnd;
    int iExpandedImage;
//#endif
//#if NTDDI_VERSION >= 0x06010000
    int iReserved;
//#endif
  } TVITEMEXA,*LPTVITEMEXA;

  typedef struct tagTVITEMEXM {
    UINT mask;
    HTREEITEM hItem;
    UINT state;
    UINT stateMask;
    LPSTR pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    LPARAM lParam;
    int iIntegral;
//#if _WIN32_IE >= 0x0600
    UINT uStateEx;
    HWND hwnd;
    int iExpandedImage;
//#endif
//#if NTDDI_VERSION >= 0x06010000
    int iReserved;
//#endif
  } TVITEMEXM,*LPTVITEMEXM;

  typedef struct tagTVITEMEXW {
    UINT mask;
    HTREEITEM hItem;
    UINT state;
    UINT stateMask;
    LPWSTR pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    LPARAM lParam;
    int iIntegral;
//#if _WIN32_IE >= 0x0600
    UINT uStateEx;
    HWND hwnd;
    int iExpandedImage;
//#endif
//#if NTDDI_VERSION >= 0x06010000
    int iReserved;
//#endif
  } TVITEMEXW,*LPTVITEMEXW;

struct w32api_tvinsertstruct_ansi {
    HTREEITEM hParent;
    HTREEITEM hInsertAfter;
    union {
      TVITEMEXA itemex;
      TVITEMA item;
    };
};

struct w32api_tvinsertstruct_utf8 {
    HTREEITEM hParent;
    HTREEITEM hInsertAfter;
    union {
      TVITEMEXM itemex;
      TVITEMM item;
    };
};

struct w32api_tvinsertstruct_utf16 {
    HTREEITEM hParent;
    HTREEITEM hInsertAfter;
    union {
      TVITEMEXW itemex;
      TVITEMW item;
    };
};

typedef struct w32api_tvinsertstruct_ansi TVINSERTSTRUCTA, *LPTVINSERTSTRUCTA;
typedef struct w32api_tvinsertstruct_utf8 TVINSERTSTRUCTM, *LPTVINSERTSTRUCTM;
typedef struct w32api_tvinsertstruct_utf16 TVINSERTSTRUCTW, *LPTVINSERTSTRUCTW;

#define TV_INSERTSTRUCTA TVINSERTSTRUCTA
#define TV_INSERTSTRUCTM TVINSERTSTRUCTM
#define TV_INSERTSTRUCTW TVINSERTSTRUCTW

#define TV_FIRST 			0x1100

#define TVIF_TEXT 			0x1
#define TVIF_PARAM 			0x4

#define TVE_COLLAPSE 			0x1
#define TVE_EXPAND 			0x2

#define TVI_ROOT 			((HTREEITEM)(ULONG_PTR)-0x10000)

#define TVS_HASBUTTONS 			0x1
#define TVS_HASLINES 			0x2
#define TVS_DISABLEDRAGDROP 		0x10
#define TVS_LINESATROOT 		0x4
#define TVS_SHOWSELALWAYS 		0x20

#define TVN_FIRST 			(0U-400U)
#define TVN_SELCHANGEDA 		(TVN_FIRST-2)
//#define TVN_SLCHANGEDM		//don't know what's supposed to go here. FIXME
#define TVN_SELCHANGEDW 		(TVN_FIRST-51)

#define TVM_INSERTITEMA 		(TV_FIRST+0)
//define TVN_INSERTITEMM		//don't know what's supposed to go here. FIXME
#define TVM_INSERTITEMW 		(TV_FIRST+50)

#define TVM_GETITEMA 			(TV_FIRST+12)
//defien TVM_GETITEMM			//don't know what's supposed to go here. FIXME
#define TVM_GETITEMW 			(TV_FIRST+62)
#define TVM_EXPAND 			(TV_FIRST+2)
#define TVM_SELECTITEM 			(TV_FIRST+11)
#define TVM_GETNEXTITEM 		(TV_FIRST+10)

#define WC_TREEVIEWA 			"SysTreeView32"
#define WC_TREEVIEWM			"SysTreeView32"
#define WC_TREEVIEWW 			L"SysTreeView32" //not entirely sure FIXME

#define TVGN_CARET 			0x9

__dllimport void __stdcall InitCommonControls(void);

#ifdef WINAPI_ANSI_DEFAULT
#define WC_TREEVIEW WC_TREEVIEWA
#define TVINSERTSTRUCT TVINSERTSTRUCTA
#define TVITEMEX TVITEMEXA
#define TVITEM TVITEMA
#define TV_ITEM TVITEMA
#define TVN_SELCHANGED TVN_SELCHANGEDA
#define TVM_INSERTITEM TVM_INSERTITEMA
#define TVM_GETITEM TVM_GETITEMA
#define LPTV_INSERTSTRUCT LPTVINSERTSTRUCTA

#endif

#ifdef WINAPI_UTF8_DEFAULT
#define WC_TREEVIEW WC_TREEVIEWM
#define TVINSERTSTRUCT TVINSERTSTRUCTM
#define TVITEMEX TVITEMEXM
#define TVITEM TVITEMM
#define TV_ITEM TVITEMM
#define LPTV_INSERTSTRUCT LPTVINSERTSTRUCTM


#endif

#ifdef WINAPI_UTF16_DEFAULT
#define WC_TREEVIEW WC_TREEVIEWW
#define TVINSERTSTRUCT TVINSERTSTRUCTW
#define TVITEMEX TVITEMEXW
#define TVITEM TVITEMW
#define TV_ITEM TVITEMW
#define TVN_SELCHANGED TVN_SELCHANGEDW
#define TVM_INSERTITEM TVM_INSERTITEMW
#define TVM_GETITEM TVM_GETITEMW
#define LPTV_INSERTSTRUCT LPTVINSERTSTRUCTW


#endif

#define SNDMSG SendMessage
#define TreeView_InsertItem(hwnd,lpis) (HTREEITEM)SNDMSG((hwnd),TVM_INSERTITEM,0,(LPARAM)(LPTV_INSERTSTRUCT)(lpis))
#define TreeView_Expand(hwnd,hitem,code) (int)SNDMSG((hwnd),TVM_EXPAND,(WPARAM)(code),(LPARAM)(HTREEITEM)(hitem))
#define TreeView_SelectItem(hwnd,hitem) TreeView_Select(hwnd,hitem,TVGN_CARET)
#define TreeView_GetSelection(hwnd) TreeView_GetNextItem(hwnd,NULL,TVGN_CARET)
#define TreeView_GetItem(hwnd,pitem) (int)SNDMSG((hwnd),TVM_GETITEM,0,(LPARAM)(TV_ITEM *)(pitem))
#define TreeView_Select(hwnd,hitem,code) (int)SNDMSG((hwnd),TVM_SELECTITEM,(WPARAM)(code),(LPARAM)(HTREEITEM)(hitem))
#define TreeView_GetNextItem(hwnd,hitem,code) (HTREEITEM)SNDMSG((hwnd),TVM_GETNEXTITEM,(WPARAM)(code),(LPARAM)(HTREEITEM)(hitem))


#endif
