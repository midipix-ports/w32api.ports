#ifndef _W32API_OLE2_H_
#define _W32API_OLE2_H_

#include <stdint.h>
#include <windef.h>
#include <oleidl.h>


typedef UINT __stdcall w32api_register_clipboard_format_ansi(
	LPCSTR);

typedef UINT __stdcall w32api_register_clipboard_format_utf8(
	LPCSTR);

typedef UINT __stdcall w32api_register_clipboard_format_utf16(
	LPCWSTR);

typedef int32_t __stdcall w32api_ole_initialize(
	PVOID);

typedef int32_t __stdcall w32api_register_drag_drop(
	HWND,
	LPDROPTARGET);


__dllimport w32api_register_clipboard_format_ansi	RegisterClipboardFormatA;
__dllimport w32api_register_clipboard_format_utf8	RegisterClipboardFormatM;
__dllimport w32api_register_clipboard_format_utf16	RegisterClipboardFormatW;

__dllimport w32api_ole_initialize			OleInitialize;
__dllimport w32api_register_drag_drop			RegisterDragDrop;


#endif
