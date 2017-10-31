#ifndef _W32API_OBJIDL_H_
#define _W32API_OBJIDL_H_

#include <windef.h>

typedef enum tagTYMED {
    TYMED_HGLOBAL = 1,
    TYMED_FILE = 2,
    TYMED_ISTREAM = 4,
    TYMED_ISTORAGE = 8,
    TYMED_GDI = 16,
    TYMED_MFPICT = 32,
    TYMED_ENHMF = 64,
    TYMED_NULL = 0
} TYMED;

#endif
