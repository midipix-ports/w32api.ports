#ifndef _W32API_WINERROR_H_
#define _W32API_WINERROR_H_

typedef signed int HRESULT;

#ifdef  RC_INVOKED
#define _HRESULT_TYPEDEF_(_sc) _sc
#else
#ifdef  __WIDL__
#define _HRESULT_TYPEDEF_(_sc) ((HRESULT)_sc)
#endif
#endif

#define WINERR_INSUFFICIENT_BUFFER	(int32_t)122

#define ERROR_INSUFFICIENT_BUFFER	WINERR_INSUFFICIENT_BUFFER
#define ERROR_CANCELLED 		(1223)

#define S_OK 				((HRESULT)0x00000000)

#define E_ACCESSDENIED 			_HRESULT_TYPEDEF_(0x80070005)

#endif
