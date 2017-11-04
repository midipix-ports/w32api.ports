#ifndef _W32API_WTYPES_H_
#define _W32API_WTYPES_H_

#include <windef.h>

typedef WORD				CLIPFORMAT;
typedef CLIPFORMAT			*LPCLIPFORMAT;

typedef const RECT			*LPCRECT;


typedef enum wtypes_dvaspect		DVASPECT;

enum wtypes_dvaspect {
	DVASPECT_CONTENT = 1,
	DVASPECT_THUMBNAIL = 2,
	DVASPECT_ICON = 4,
	DVASPECT_DOCPRINT = 8
};

#endif
