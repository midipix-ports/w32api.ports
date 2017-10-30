#ifndef _W32API_WINDOWSX_H_
#define _W32API_WINDOWSX_H_

#include <windef.h>

#define GET_X_LPARAM(lp) 			((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp) 			((int)(short)HIWORD(lp))

#endif