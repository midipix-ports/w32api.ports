#ifndef _W32API_GUIDDEF_H_
#define _W32API_GUIDDEF_H_

#include <stdint.h>
#include <basetyps.h>

#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
	const GUID name = \
	{ l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }



#endif

