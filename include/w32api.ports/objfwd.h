#ifndef _W32API_OBJFWD_H_
#define _W32API_OBJFWD_H_

#include <basetyps.h>

/* COM forward declarations */
typedef _COM_interface IAdviseSink		*LPADVISESINK;
typedef _COM_interface IAdviseSink2		*LPADVISESINK2;
typedef _COM_interface IBindCtx			*LPBINDCTX,*LPBC;
typedef _COM_interface IClassActivator		*LPCLASSACTIVATOR;
typedef _COM_interface IClientSecurity		*LPCLIENTSECURITY;
typedef _COM_interface IDataAdviseHolder	*LPDATAADVISEHOLDER;
typedef _COM_interface IDataObject		*LPDATAOBJECT;
typedef _COM_interface IDropSource		*LPDROPSOURCE;
typedef _COM_interface IDropTarget		*LPDROPTARGET;
typedef _COM_interface IEnumFORMATETC		*LPENUMFORMATETC;
typedef _COM_interface IEnumMoniker		*LPENUMMONIKER;
typedef _COM_interface IEnumOLEVERB		*LPENUMOLEVERB;
typedef _COM_interface IEnumOleUndoUnits	*LPENUMOLEUNDOUNITS;
typedef _COM_interface IEnumSTATDATA		*LPENUMSTATDATA;
typedef _COM_interface IEnumSTATPROPSETSTG	*LPENUMSTATPROPSETSTG;
typedef _COM_interface IEnumSTATSTG		*LPENUMSTATSTG;
typedef _COM_interface IEnumString		*LPENUMSTRING;
typedef _COM_interface IEnumUnknown		*LPENUMUNKNOWN;
typedef _COM_interface IExternalConnection	*LPEXTERNALCONNECTION;
typedef _COM_interface IFillLockBytes		*LPFILLLOCKBYTES;
typedef _COM_interface ILayoutStorage		*LPLAYOUTSTORAGE;
typedef _COM_interface ILockBytes		*LPLOCKBYTES;
typedef _COM_interface IMalloc			*LPMALLOC;
typedef _COM_interface IMallocSpy		*LPMALLOCSPY;
typedef _COM_interface IMarshal			*LPMARSHAL;
typedef _COM_interface IMessageFilter		*LPMESSAGEFILTER;
typedef _COM_interface IMoniker			*LPMONIKER;
typedef _COM_interface IOleAdviseHolder		*LPOLEADVISEHOLDER;
typedef _COM_interface IOleCache		*LPOLECACHE;
typedef _COM_interface IOleCache2		*LPOLECACHE2;
typedef _COM_interface IOleCacheControl		*LPOLECACHECONTROL;
typedef _COM_interface IOleClientSite		*LPOLECLIENTSITE;
typedef _COM_interface IOleContainer		*LPOLECONTAINER;
typedef _COM_interface IOleInPlaceActiveObject	*LPOLEINPLACEACTIVEOBJECT;
typedef _COM_interface IOleInPlaceFrame		*LPOLEINPLACEFRAME;
typedef _COM_interface IOleInPlaceUIWindow	*LPOLEINPLACEUIWINDOW;
typedef _COM_interface IOleObject		*LPOLEOBJECT;
typedef _COM_interface IOleWindow		*LPOLEWINDOW;
typedef _COM_interface IParseDisplayName	*LPPARSEDISPLAYNAME;
typedef _COM_interface IPersist			*LPPERSIST;
typedef _COM_interface IPersistFile		*LPPERSISTFILE;
typedef _COM_interface IPersistStorage		*LPPERSISTSTORAGE;
typedef _COM_interface IPersistStream		*LPPERSISTSTREAM;
typedef _COM_interface IProgressNotify		*LPPROGRESSNOTIFY;
typedef _COM_interface IPropertySetStorage	*LPPROPERTYSETSTORAGE;
typedef _COM_interface IPropertyStorage		*LPPROPERTYSTORAGE;
typedef _COM_interface IROTData			*LPROTDATA;
typedef _COM_interface IRootStorage		*LPROOTSTORAGE;
typedef _COM_interface IRpcChannelBuffer	*LPRPCCHANNELBUFFER;
typedef _COM_interface IRpcProxyBuffer		*LPRPCPROXYBUFFER;
typedef _COM_interface IRpcStubBuffer		*LPRPCSTUBBUFFER;
typedef _COM_interface IRunnableObject		*LPRUNNABLEOBJECT;
typedef _COM_interface IRunningObjectTable	*LPRUNNINGOBJECTTABLE;
typedef _COM_interface IServerSecurity		*LPSERVERSECURITY;
typedef _COM_interface IStdMarshalInfo		*LPSTDMARSHALINFO;
typedef _COM_interface IStorage			*LPSTORAGE;
typedef _COM_interface IStream			*LPSTREAM;
typedef _COM_interface IViewObject		*LPVIEWOBJECT;
typedef _COM_interface IViewObject2		*LPVIEWOBJECT2;

#endif
