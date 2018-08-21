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
    };
    union {
	DWORD	dwRBitMask;
	DWORD	dwYBitMask;
	DWORD	dwStencilBitDepth;
	DWORD	dwLuminanceBitMask;
	DWORD	dwBumpDuBitMask;
    };
    union {
	DWORD	dwGBitMask;
	DWORD	dwUBitMask;
	DWORD	dwZBitMask;
	DWORD	dwBumpDvBitMask;
    };
    union {
	DWORD   dwBBitMask;
	DWORD   dwVBitMask;
	DWORD	dwStencilBitMask;
	DWORD	dwBumpLuminanceBitMask;
    };
    union {
    	DWORD	dwRGBAlphaBitMask;
    	DWORD	dwYUVAlphaBitMask;
	DWORD	dwLuminanceAlphaBitMask;
	DWORD	dwRGBZBitMask;
	DWORD	dwYUVZBitMask;
    };
};

struct ddraw_dd_scaps_2 {
	DWORD	dwCaps;
	DWORD   dwCaps2;
	DWORD   dwCaps3;
	union {
	  DWORD dwCaps4;
	  DWORD dwVolumeDepth;
	};
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
	};
	union {
	  DWORD dwBackBufferCount;
	  DWORD dwDepth;
	};
	union {
		DWORD	dwMipMapCount;
		DWORD	dwRefreshRate;
		DWORD   dwSrcVBHandle;
	};
	DWORD	dwAlphaBitDepth;
	DWORD	dwReserved;
	LPVOID	lpSurface;
	union {
		DDCOLORKEY	ddckCKDestOverlay;
		DWORD 		dwEmptyFaceColor;
	};
	DDCOLORKEY	ddckCKDestBlt;
	DDCOLORKEY	ddckCKSrcOverlay;
	DDCOLORKEY	ddckCKSrcBlt;

	union {
		DDPIXELFORMAT	ddpfPixelFormat;
		DWORD 		dwFVF;
	};
	DDSCAPS2	ddsCaps;
	DWORD		dwTextureStage;
};

#endif
