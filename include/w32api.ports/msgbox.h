#ifndef _W32API_MSGBOX_H_
#define _W32API_MSGBOX_H_

#define MB_DEFMASK			(3840)
#define MB_SYSTEMMODAL			(4096)

#define MB_HELP				(0x4000)
#define MB_TASKMODAL			(0x2000)
#define MB_SETFOREGROUND		(0x10000)
#define MB_DEFAULT_DESKTOP_ONLY		(0x20000)
#define MB_TOPMOST			(0x40000)
#define MB_RIGHT			(0x80000)
#define MB_RTLREADING			(0x100000)
#define MB_SERVICE_NOTIFICATION		(0x200000)

#define MB_ABORTRETRYIGNORE		(2)
#define MB_APPLMODAL			(0)
#define MB_CANCELTRYCONTINUE		(6)

#define MB_DEFBUTTON1			(0)
#define MB_DEFBUTTON2			(256)
#define MB_DEFBUTTON3			(512)
#define MB_DEFBUTTON4			(0x300)

#define MB_ICONASTERISK			(64)
#define MB_ICONERROR			(16)
#define MB_ICONEXCLAMATION		(0x30)
#define MB_ICONHAND			(16)
#define MB_ICONINFORMATION		(64)
#define MB_ICONMASK			(240)
#define MB_ICONQUESTION			(32)
#define MB_ICONSTOP			(16)
#define MB_ICONWARNING			(0x30)

#define MB_OK				(0)
#define MB_OKCANCEL			(1)
#define MB_RETRYCANCEL			(5)

#define MB_TYPEMASK			(15)
#define MB_USERICON			(128)
#define MB_YESNO			(4)
#define MB_YESNOCANCEL			(3)

#define MB_MISCMASK			(0x0000C000)
#define MB_MODEMASK			(0x00003000)
#define MB_NOFOCUS			(0x00008000)

#endif
