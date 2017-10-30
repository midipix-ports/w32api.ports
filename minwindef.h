#ifndef _W32API_MINWINDEF_H_
#define _W32API_MINWINDEF_H_

#include <windef.h>

#define HIWORD(l) ((WORD) ((((DWORD_PTR) (l)) >> 16) & 0xffff))
#define LOWORD(l) ((WORD) (((DWORD_PTR) (l)) & 0xffff))
#define MAKELONG(a, b) ((LONG) (((WORD) (((DWORD_PTR) (a)) & 0xffff)) | ((DWORD) ((WORD) (((DWORD_PTR) (b)) & 0xffff))) << 16))

#endif
