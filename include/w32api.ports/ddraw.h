#ifndef _W32API_DDRAW_H_
#define _W32API_DDRAW_H_

#include <windef.h>


struct ddraw_dd_surface_desc_2;
struct ddraw_dd_color_key;
struct ddraw_dd_pixel_format;
struct ddraw_dd_scaps_2;

typedef struct ddraw_dd_surface_desc_2				DDSURFACEDESC2,*LPDDSURFACEDESC2;
typedef struct ddraw_dd_color_key				DDCOLORKEY,*LPDDCOLORKEY;
typedef struct ddraw_dd_pixel_format				DDPIXELFORMAT,*LPDDPIXELFORMAT;
typedef struct ddraw_dd_scaps_2					DDSCAPS2,*LPDDSCAPS2;


struct ddraw_dd_color_key
{
	DWORD	dwColorSpaceLowValue;
	DWORD	dwColorSpaceHighValue;
};

struct ddraw_dd_pixel_format {
    DWORD	dwSize;
    DWORD	dwFlags;
    DWORD	dwFourCC;
    union {
	DWORD	dwRGBBitCount;
	DWORD	dwYUVBitCount;
	DWORD	dwZBufferBitDepth;
	DWORD	dwAlphaBitDepth;
	DWORD	dwLuminanceBitCount;
	DWORD	dwBumpBitCount;
    } u1;
    union {
	DWORD	dwRBitMask;
	DWORD	dwYBitMask;
	DWORD	dwStencilBitDepth;
	DWORD	dwLuminanceBitMask;
	DWORD	dwBumpDuBitMask;
    } u2;
    union {
	DWORD	dwGBitMask;
	DWORD	dwUBitMask;
	DWORD	dwZBitMask;
	DWORD	dwBumpDvBitMask;
    } u3;
    union {
	DWORD   dwBBitMask;
	DWORD   dwVBitMask;
	DWORD	dwStencilBitMask;
	DWORD	dwBumpLuminanceBitMask;
    } u4;
    union {
    	DWORD	dwRGBAlphaBitMask;
    	DWORD	dwYUVAlphaBitMask;
	DWORD	dwLuminanceAlphaBitMask;
	DWORD	dwRGBZBitMask;
	DWORD	dwYUVZBitMask;
    } u5;
};

struct ddraw_dd_scaps_2 {
	DWORD	dwCaps;
	DWORD   dwCaps2;
	DWORD   dwCaps3;
	union {
	  DWORD dwCaps4;
	  DWORD dwVolumeDepth;
	} u1;
};

struct ddraw_dd_surface_desc_2
{
	DWORD	dwSize;
	DWORD	dwFlags;
	DWORD	dwHeight;
	DWORD	dwWidth;
	union {
		LONG	lPitch;
		DWORD   dwLinearSize;
	} u1;
	union {
	  DWORD dwBackBufferCount;
	  DWORD dwDepth;
	} u5;
	union {
		DWORD	dwMipMapCount;
		DWORD	dwRefreshRate;
		DWORD   dwSrcVBHandle;
	} u2;
	DWORD	dwAlphaBitDepth;
	DWORD	dwReserved;
	LPVOID	lpSurface;
	union {
		DDCOLORKEY	ddckCKDestOverlay;
		DWORD 		dwEmptyFaceColor;
	} u3;
	DDCOLORKEY	ddckCKDestBlt;
	DDCOLORKEY	ddckCKSrcOverlay;
	DDCOLORKEY	ddckCKSrcBlt;

	union {
		DDPIXELFORMAT	ddpfPixelFormat;
		DWORD 		dwFVF;
	} u4;
	DDSCAPS2	ddsCaps;
	DWORD		dwTextureStage;
};

#endif
