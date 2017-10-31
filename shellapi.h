#ifndef _W32_SHELLAPI_H_
#define _W32_SHELLAPI_H_

#include <windef.h>

__dllimport UINT __stdcall ExtractIconExW(LPCWSTR lpszFile, int nIconIndex, HICON *phiconLarge, HICON *phiconSmall, UINT nIcons);
__dllimport UINT __stdcall DragQueryFileW(HDROP hDrop, UINT iFile, LPWSTR lpszFile, UINT cch);
__dllimport HINSTANCE __stdcall ShellExecuteW(HWND hWnd, LPCWSTR lpOperation, LPCWSTR pFile, LPCWSTR lpParameters, LPCWSTR lpDirectory, INT nShowCmd);

#endif
