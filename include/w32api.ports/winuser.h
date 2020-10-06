#ifndef _W32API_WINUSER_H_
#define _W32API_WINUSER_H_


#include <windef.h>
#include <winnt.h>
#include <wingdi.h>
#include <stdarg.h>

#include <basetyps.h>
#include <minwinbase.h>


#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAX_PATH
#define MAX_PATH 260
#endif


/* miscellaneous winuser types */
typedef UINT32 POINTER_FLAGS;
typedef UINT32 TOUCH_FLAGS;
typedef UINT32 TOUCH_MASK;
typedef UINT32 PEN_FLAGS;
typedef UINT32 PEN_MASK;


typedef HANDLE HRAWINPUT;
typedef HANDLE HTOUCHINPUT;
typedef HANDLE HWINSTA;
typedef HANDLE HWINEVENTHOOK;
typedef HANDLE HGESTUREINFO;
typedef HANDLE HPOWERNOTIFY;
typedef HPOWERNOTIFY *PHPOWERNOTIFY;
typedef PVOID HDEVNOTIFY;
typedef HDEVNOTIFY *PHDEVNOTIFY;
typedef HANDLE HDWP;
typedef DWORD HELPPOLY;


typedef FARPROC DLGPROC;
typedef FARPROC TIMERPROC;
typedef FARPROC GRAYSTRINGPROC;

typedef BOOL (__stdcall * WNDENUMPROC)(
	HWND,
	LPARAM);

typedef FARPROC HOOKPROC;
typedef FARPROC SENDASYNCPROC;
typedef FARPROC DRAWSTATEPROC;

typedef FARPROC EDITWORDBREAKPROCA;
typedef FARPROC EDITWORDBREAKPROCM;
typedef FARPROC EDITWORDBREAKPROCW;

typedef FARPROC PROPENUMPROCA;
typedef FARPROC PROPENUMPROCM;
typedef FARPROC PROPENUMPROCW;

typedef FARPROC PROPENUMPROCEXA;
typedef FARPROC PROPENUMPROCEXM;
typedef FARPROC PROPENUMPROCEXW;

typedef FARPROC NAMEENUMPROCA;
typedef FARPROC NAMEENUMPROCM;
typedef FARPROC NAMEENUMPROCW;

typedef FARPROC WINSTAENUMPROCA;
typedef FARPROC WINSTAENUMPROCM;
typedef FARPROC WINSTAENUMPROCW;

typedef FARPROC DESKTOPENUMPROCA;
typedef FARPROC DESKTOPENUMPROCM;
typedef FARPROC DESKTOPENUMPROCW;

typedef void MENUTEMPLATEA;
typedef void MENUTEMPLATEM;
typedef void MENUTEMPLATEW;

typedef PVOID LPMENUTEMPLATEA;
typedef PVOID LPMENUTEMPLATEM;
typedef PVOID LPMENUTEMPLATEW;



typedef LRESULT (__stdcall * WNDPROC)(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef BOOL (__stdcall * MONITORENUMPROC)(
	HMONITOR,
	HDC,
	LPRECT,
	LPARAM);



#if (_WIN32_WINNT >= 0x0502)
  extern const GUID GUID_POWERSCHEME_PERSONALITY;
  extern const GUID GUID_MIN_POWER_SAVINGS;
  extern const GUID GUID_MAX_POWER_SAVINGS;
  extern const GUID GUID_TYPICAL_POWER_SAVINGS;
  extern const GUID GUID_ACDC_POWER_SOURCE;
  extern const GUID GUID_BATTERY_PERCENTAGE_REMAINING;
  extern const GUID GUID_IDLE_BACKGROUND_TASK;
  extern const GUID GUID_SYSTEM_AWAYMODE;
  extern const GUID GUID_MONITOR_POWER_ON;
#endif



#ifdef WINAPI_ANSI_DEFAULT
#define EDITWORDBREAKPROC EDITWORDBREAKPROCA
#define PROPENUMPROC PROPENUMPROCA
#define PROPENUMPROCEX PROPENUMPROCEXA
#define NAMEENUMPROC NAMEENUMPROCA
#define MENUTEMPLATE MENUTEMPLATEA
#define WINSTAENUMPROC WINSTAENUMPROCA
#define DESKTOPENUMPROC DESKTOPENUMPROCA
#define LPMENUTEMPLATE LPMENUTEMPLATEA
#endif

#ifdef WINAPI_UTF8_DEFAULT
#define EDITWORDBREAKPROC EDITWORDBREAKPROCM
#define PROPENUMPROC PROPENUMPROCM
#define PROPENUMPROCEX PROPENUMPROCEXM
#define NAMEENUMPROC NAMEENUMPROCM
#define MENUTEMPLATE MENUTEMPLATEM
#define WINSTAENUMPROC WINSTAENUMPROCM
#define DESKTOPENUMPROC DESKTOPENUMPROCM
#define LPMENUTEMPLATE LPMENUTEMPLATEM
#endif

#ifdef WINAPI_UTF16_DEFAULT
#define EDITWORDBREAKPROC EDITWORDBREAKPROCW
#define PROPENUMPROC PROPENUMPROCW
#define PROPENUMPROCEX PROPENUMPROCEXW
#define NAMEENUMPROC NAMEENUMPROCW
#define MENUTEMPLATE MENUTEMPLATEW
#define WINSTAENUMPROC WINSTAENUMPROCW
#define DESKTOPENUMPROC DESKTOPENUMPROCW
#define LPMENUTEMPLATE LPMENUTEMPLATEW
#endif




enum winuser_pointer_input_type {
	PT_POINTER = 0x00000001,
	PT_TOUCH = 0x00000002,
	PT_PEN = 0x00000003,
	PT_MOUSE = 0x00000004,
};

enum winuser_feedback_type {
	FEEDBACK_TOUCH_CONTACTVISUALIZATION = 1,
	FEEDBACK_PEN_BARRELVISUALIZATION = 2,
	FEEDBACK_PEN_TAP = 3,
	FEEDBACK_PEN_DOUBLETAP = 4,
	FEEDBACK_PEN_PRESSANDHOLD = 5,
	FEEDBACK_PEN_RIGHTTAP = 6,
	FEEDBACK_TOUCH_TAP = 7,
	FEEDBACK_TOUCH_DOUBLETAP = 8,
	FEEDBACK_TOUCH_PRESSANDHOLD = 9,
	FEEDBACK_TOUCH_RIGHTTAP = 10,
	FEEDBACK_GESTURE_PRESSANDTAP = 11,
	FEEDBACK_MAX = 0xffffffff
};

enum winuser_pointer_button_change_type {
	POINTER_CHANGE_NONE,
	POINTER_CHANGE_FIRSTBUTTON_DOWN,
	POINTER_CHANGE_FIRSTBUTTON_UP,
	POINTER_CHANGE_SECONDBUTTON_DOWN,
	POINTER_CHANGE_SECONDBUTTON_UP,
	POINTER_CHANGE_THIRDBUTTON_DOWN,
	POINTER_CHANGE_THIRDBUTTON_UP,
	POINTER_CHANGE_FOURTHBUTTON_DOWN,
	POINTER_CHANGE_FOURTHBUTTON_UP,
	POINTER_CHANGE_FIFTHBUTTON_DOWN,
	POINTER_CHANGE_FIFTHBUTTON_UP,
};

enum winuser_pointer_device_type {
	POINTER_DEVICE_TYPE_INTEGRATED_PEN = 0x00000001,
	POINTER_DEVICE_TYPE_EXTERNAL_PEN = 0x00000002,
	POINTER_DEVICE_TYPE_TOUCH = 0x00000003,
	POINTER_DEVICE_TYPE_MAX = 0xffffffff
};

enum winuser_pointer_device_cursor_type {
	POINTER_DEVICE_CURSOR_TYPE_UNKNOWN = 0x00000000,
	POINTER_DEVICE_CURSOR_TYPE_TIP = 0x00000001,
	POINTER_DEVICE_CURSOR_TYPE_ERASER = 0x00000002,
	POINTER_DEVICE_CURSOR_TYPE_MAX = 0xffffffff
};

enum winuser_input_message_device_type {
	IMDT_UNAVAILABLE = 0x00000000,
	IMDT_KEYBOARD = 0x00000001,
	IMDT_MOUSE = 0x00000002,
	IMDT_TOUCH = 0x00000004,
	IMDT_PEN = 0x00000008,
};

enum winuser_input_message_origin_id {
	IMO_UNAVAILABLE = 0x00000000,
	IMO_HARDWARE = 0x00000001,
	IMO_INJECTED = 0x00000002,
	IMO_SYSTEM = 0x00000004,
};

enum winuser_ar_state {
	AR_ENABLED = 0x0,
	AR_DISABLED = 0x1,
	AR_SUPPRESSED = 0x2,
	AR_REMOTESESSION = 0x4,
	AR_MULTIMON = 0x8,
	AR_NOSENSOR = 0x10,
	AR_NOT_SUPPORTED = 0x20,
	AR_DOCKED = 0x40,
	AR_LAPTOP = 0x80
};

enum winuser_orientation_preference {
	ORIENTATION_PREFERENCE_NONE = 0x0,
	ORIENTATION_PREFERENCE_LANDSCAPE = 0x1,
	ORIENTATION_PREFERENCE_PORTRAIT = 0x2,
	ORIENTATION_PREFERENCE_LANDSCAPE_FLIPPED = 0x4,
	ORIENTATION_PREFERENCE_PORTRAIT_FLIPPED = 0x8
};




typedef enum winuser_pointer_input_type		POINTER_INPUT_TYPE;
typedef enum winuser_feedback_type		FEEDBACK_TYPE;
typedef enum winuser_pointer_button_change_type	POINTER_BUTTON_CHANGE_TYPE;
typedef enum winuser_pointer_device_type	POINTER_DEVICE_TYPE;
typedef enum winuser_pointer_device_cursor_type	POINTER_DEVICE_CURSOR_TYPE;
typedef enum winuser_input_message_device_type	INPUT_MESSAGE_DEVICE_TYPE;
typedef enum winuser_input_message_origin_id	INPUT_MESSAGE_ORIGIN_ID;
typedef enum winuser_ar_state			AR_STATE, *PAR_STATE;
typedef enum winuser_orientation_preference	ORIENTATION_PREFERENCE;




struct winuser_cbt_create_wnd_ansi;
struct winuser_cbt_create_wnd_utf8;
struct winuser_cbt_create_wnd_utf16;
struct winuser_cbt_activate_struct;
struct wwinuser_wts_session_notification;
struct winuser_shell_hook_info;
struct winuser_event_msg;
struct winuser_cwp_struct;
struct winuser_cwp_ret_struct;
struct winuser_kb_dll_hook_struct;
struct winuser_ms_ll_hook_struct;
struct winuser_debug_hook_info;
struct winuser_mouse_hook_struct;
struct winuser_mouse_hook_struct_ex;
struct winuser_hardware_hook_struct;
struct winuser_mouse_move_point;
struct winuser_user_object_flags;
struct winuser_wnd_class_ex_ansi;
struct winuser_wnd_class_ex_utf8;
struct winuser_wnd_class_ex_utf16;
struct winuser_wnd_class_ansi;
struct winuser_wnd_class_utf8;
struct winuser_wnd_class_utf16;
struct winuser_msg;
struct winuser_min_max_info;
struct winuser_copy_data_struct;
struct winuser_mdi_next_menu;
struct winuser_power_broadcast_setting;
struct winuser_window_pos;
struct winuser_nc_calc_size_params;
struct winuser_track_mouse_event;
struct winuser_accel;
struct winuser_paint_struct;
struct winuser_create_struct_ansi;
struct winuser_create_struct_utf8;
struct winuser_create_struct_utf16;
struct winuser_window_placement;
struct winuser_nmhdr;
struct winuser_style_struct;
struct winuser_measure_item_struct;
struct winuser_draw_item_struct;
struct winuser_delete_item_struct;
struct winuser_compare_item_struct;
struct winuser_bsm_info;
struct winuser_update_layered_window_info;
struct winuser_flash_w_info;
struct winuser_dlg_template;
struct winuser_dlg_item_template;
struct winuser_mouse_input;
struct winuser_keybd_input;
struct winuser_hardware_input;
struct winuser_input;
struct winuser_touch_input;
struct winuser_pointer_info;
struct winuser_pointer_touch_info;
struct winuser_pointer_pen_info;
struct winuser_touch_hit_testing_proximity_evaluation;
struct winuser_touch_hit_testing_input;
struct winuser_last_input_info;
struct winuser_tpm_params;
struct winuser_menu_info;
struct winuser_menu_get_object_info;
struct winuser_menu_item_info_ansi;
struct winuser_menu_item_info_utf8;
struct winuser_menu_item_info_utf16;
struct winuser_drop_struct;
struct winuser_cursor_shape;
struct winuser_icon_info_ex_ansi;
struct winuser_icon_info_ex_utf8;
struct winuser_icon_info_ex_utf16;
struct winuser_scroll_info;
struct winuser_mdi_create_struct_ansi;
struct winuser_mdi_create_struct_utf8;
struct winuser_mdi_create_struct_utf16;
struct winuser_client_create_struct;
struct winuser_multi_key_help_ansi;
struct winuser_multi_key_help_utf8;
struct winuser_multi_key_help_utf16;
struct winuser_help_win_info_ansi;
struct winuser_help_win_info_utf8;
struct winuser_help_win_info_utf16;
struct winuser_touch_prediction_parameters;
struct winuser_non_client_metrics_ansi;
struct winuser_non_client_metrics_utf8;
struct winuser_non_client_metrics_utf16;
struct winuser_minimized_metrics;
struct winuser_icon_metrics_ansi;
struct winuser_icon_metrics_utf8;
struct winuser_icon_metrics_utf16;
struct winuser_animation_info;
struct winuser_serial_keys_ansi;
struct winuser_serial_keys_utf8;
struct winuser_serial_keys_utf16;
struct winuser_high_contrast_ansi;
struct winuser_high_contrast_utf8;
struct winuser_high_contrast_utf16;
struct winuser_sticky_keys;
struct winuser_mouse_keys;
struct winuser_access_timeout;
struct winuser_sounds_entry_ansi;
struct winuser_sounds_entry_utf8;
struct winuser_sounds_entry_utf16;
struct winuser_toggle_keys;
struct winuser_monitor_info;
struct winuser_audio_description;
struct winuser_monitor_info_ex_ansi;
struct winuser_monitor_info_ex_utf8;
struct winuser_monitor_info_ex_utf16;
struct winuser_gui_thread_info;
struct winuser_cursor_info;
struct winuser_window_info;
struct winuser_title_bar_info_ex;
struct winuser_menu_bar_info;
struct winuser_title_bar_info;
struct winuser_scroll_bar_info;
struct winuser_combo_box_info;
struct winuser_alt_tab_info;
struct winuser_raw_input_header;
struct winuser_raw_mouse;
struct winuser_raw_keyboard;
struct winuser_raw_hid;
struct winuser_raw_input;
struct winuser_rid_device_info_mouse;
struct winuser_rid_device_info_keyboard;
struct winuser_rid_device_info_hid;
struct winuser_rid_device_info;
struct winuser_raw_input_device;
struct winuser_raw_input_device_list;
struct winuser_pointer_device_info;
struct winuser_pointer_device_property;
struct winuser_pointer_device_cursor_info;
struct winuser_change_filter_struct;
struct winuser_gesture_info;
struct winuser_gesture_notify_struct;
struct winuser_gesture_config;
struct winuser_input_message_source;
struct winuser_input_transform;
struct winuser_video_parameters;



typedef struct winuser_cbt_create_wnd_ansi					CBT_CREATEWNDA, *LPCBT_CREATEWNDA;
typedef struct winuser_cbt_create_wnd_utf8					CBT_CREATEWNDM, *LPCBT_CREATEWNDM;
typedef struct winuser_cbt_create_wnd_utf16					CBT_CREATEWNDW, *LPCBT_CREATEWNDW;
typedef struct winuser_cbt_activate_struct					CBTACTIVATESTRUCT, *LPCBTACTIVATESTRUCT;
typedef struct winuser_wts_session_notification					WTSSESSION_NOTIFICATION, *PWTSSESSION_NOTIFICATION;
typedef struct winuser_shell_hook_info						SHELLHOOKINFO, *LPSHELLHOOKINFO;
typedef struct winuser_event_msg						EVENTMSG, *PEVENTMSGMSG, *NPEVENTMSGMSG, *LPEVENTMSGMSG, *PEVENTMSG, *NPEVENTMSG, *LPEVENTMSG;
typedef struct winuser_cwp_struct						CWPSTRUCT, *PCWPSTRUCT, *NPCWPSTRUCT, *LPCWPSTRUCT;
typedef struct winuser_cwp_ret_struct						CWPRETSTRUCT, *PCWPRETSTRUCT, *NPCWPRETSTRUCT, *LPCWPRETSTRUCT;
typedef struct winuser_kb_dll_hook_struct					KBDLLHOOKSTRUCT, *LPKBDLLHOOKSTRUCT, *PKBDLLHOOKSTRUCT;
typedef struct winuser_ms_ll_hook_struct					MSLLHOOKSTRUCT, *LPMSLLHOOKSTRUCT, *PMSLLHOOKSTRUCT;
typedef struct winuser_debug_hook_info						DEBUGHOOKINFO, *PDEBUGHOOKINFO, *NPDEBUGHOOKINFO, *LPDEBUGHOOKINFO;
typedef struct winuser_mouse_hook_struct					MOUSEHOOKSTRUCT, *LPMOUSEHOOKSTRUCT, *PMOUSEHOOKSTRUCT;
typedef struct winuser_mouse_hook_struct_ex					MOUSEHOOKSTRUCTEX, *LPMOUSEHOOKSTRUCTEX, *PMOUSEHOOKSTRUCTEX;
typedef struct winuser_hardware_hook_struct					HARDWAREHOOKSTRUCT, *LPHARDWAREHOOKSTRUCT, *PHARDWAREHOOKSTRUCT;
typedef struct winuser_mouse_move_point						MOUSEMOVEPOINT, *PMOUSEMOVEPOINT, *LPMOUSEMOVEPOINT;
typedef struct winuser_user_object_flags					USEROBJECTFLAGS, *PUSEROBJECTFLAGS;
typedef struct winuser_wnd_class_ex_ansi					WNDCLASSEXA, *PWNDCLASSEXA, *NPWNDCLASSEXA, *LPWNDCLASSEXA;
typedef struct winuser_wnd_class_ex_utf8					WNDCLASSEXM, *PWNDCLASSEXM, *NPWNDCLASSEXM, *LPWNDCLASSEXM;
typedef struct winuser_wnd_class_ex_utf16					WNDCLASSEXW, *PWNDCLASSEXW, *NPWNDCLASSEXW, *LPWNDCLASSEXW;
typedef struct winuser_wnd_class_ansi						WNDCLASSA, *PWNDCLASSA, *NPWNDCLASSA, *LPWNDCLASSA;
typedef struct winuser_wnd_class_utf8						WNDCLASSM, *PWNDCLASSM, *NPWNDCLASSM, *LPWNDCLASSM;
typedef struct winuser_wnd_class_utf16						WNDCLASSW, *PWNDCLASSW, *NPWNDCLASSW, *LPWNDCLASSW;
typedef struct winuser_msg							MSG, *PMSG, *NPMSG, *LPMSG;
typedef struct winuser_min_max_info						MINMAXINFO, *PMINMAXINFO, *LPMINMAXINFO;
typedef struct winuser_copy_data_struct						COPYDATASTRUCT, *PCOPYDATASTRUCT;
typedef struct winuser_mdi_next_menu						MDINEXTMENU, *PMDINEXTMENU, *LPMDINEXTMENU;
typedef struct winuser_power_broadcast_setting					POWERBROADCAST_SETTING, *PPOWERBROADCAST_SETTING;
typedef struct winuser_window_pos						WINDOWPOS, *LPWINDOWPOS, *PWINDOWPOS;
typedef struct winuser_nc_calc_size_params					NCCALCSIZE_PARAMS, *LPNCCALCSIZE_PARAMS;
typedef struct winuser_track_mouse_event					TRACKMOUSEEVENT, *LPTRACKMOUSEEVENT;
typedef struct winuser_accel							ACCEL, *LPACCEL;
typedef struct winuser_paint_struct						PAINTSTRUCT, *PPAINTSTRUCT, *NPPAINTSTRUCT, *LPPAINTSTRUCT;
typedef struct winuser_create_struct_ansi					CREATESTRUCTA, *LPCREATESTRUCTA;
typedef struct winuser_create_struct_utf8					CREATESTRUCTM, *LPCREATESTRUCTM;
typedef struct winuser_create_struct_utf16					CREATESTRUCTW, *LPCREATESTRUCTW;
typedef struct winuser_window_placement						WINDOWPLACEMENT, *PWINDOWPLACEMENT, *LPWINDOWPLACEMENT;
typedef struct winuser_nmhdr							NMHDR, *LPNMHDR;
typedef struct winuser_style_struct						STYLESTRUCT, *LPSTYLESTRUCT;
typedef struct winuser_measure_item_struct					MEASUREITEMSTRUCT, *PMEASUREITEMSTRUCT, *LPMEASUREITEMSTRUCT;
typedef struct winuser_draw_item_struct						DRAWITEMSTRUCT, *PDRAWITEMSTRUCT, *LPDRAWITEMSTRUCT;
typedef struct winuser_delete_item_struct					DELETEITEMSTRUCT, *PDELETEITEMSTRUCT, *LPDELETEITEMSTRUCT;
typedef struct winuser_compare_item_struct					COMPAREITEMSTRUCT, *PCOMPAREITEMSTRUCT, *LPCOMPAREITEMSTRUCT;
typedef struct winuser_bsm_info							BSMINFO, *PBSMINFO;
typedef struct winuser_update_layered_window_info				UPDATELAYEREDWINDOWINFO, *PUPDATELAYEREDWINDOWINFO;
typedef struct winuser_flash_w_info						FLASHWINFO, *PFLASHWINFO;
typedef struct winuser_dlg_template						DLGTEMPLATE, *LPDLGTEMPLATEA, *LPDLGTEMPLATEM, *LPDLGTEMPLATEW;
typedef const struct winuser_dlg_template					*LPCDLGTEMPLATEA, *LPCDLGTEMPLATEM, *LPCDLGTEMPLATEW;
typedef struct winuser_dlg_item_template					DLGITEMTEMPLATE, *PDLGITEMTEMPLATEA, *PDLGITEMTEMPLATEM, *PDLGITEMTEMPLATEW, *LPDLGITEMTEMPLATEA, *LPDLGITEMTEMPLATEM, *LPDLGITEMTEMPLATEW;
typedef struct winuser_mouse_input						MOUSEINPUT, *PMOUSEINPUT, *LPMOUSEINPUT;
typedef struct winuser_keybd_input						KEYBDINPUT, *PKEYBDINPUT, *LPKEYBDINPUT;
typedef struct winuser_hardware_input						HARDWAREINPUT, *PHARDWAREINPUT, *LPHARDWAREINPUT;
typedef struct winuser_input							INPUT, *PINPUT, *LPINPUT;
typedef struct winuser_touch_input						TOUCHINPUT, *PTOUCHINPUT;
typedef const struct winuser_touch_input					*PCTOUCHINPUT;
typedef struct winuser_pointer_info						POINTER_INFO;
typedef struct winuser_pointer_touch_info					POINTER_TOUCH_INFO;
typedef struct winuser_pointer_pen_info						POINTER_PEN_INFO;
typedef struct winuser_touch_hit_testing_proximity_evaluation			TOUCH_HIT_TESTING_PROXIMITY_EVALUATION, *PTOUCH_HIT_TESTING_PROXIMITY_EVALUATION;
typedef struct winuser_touch_hit_testing_input					TOUCH_HIT_TESTING_INPUT, *PTOUCH_HIT_TESTING_INPUT;
typedef struct winuser_last_input_info						LASTINPUTINFO, *PLASTINPUTINFO;
typedef struct winuser_tpm_params						TPMPARAMS, *LPTPMPARAMS;
typedef struct winuser_menu_info						MENUINFO, *LPMENUINFO;
typedef const struct winuser_menu_info						*LPCMENUINFO;
typedef struct winuser_menu_get_object_info					MENUGETOBJECTINFO, *PMENUGETOBJECTINFO;
typedef struct winuser_menu_item_info_ansi					MENUITEMINFOA, *LPMENUITEMINFOA;
typedef struct winuser_menu_item_info_utf8					MENUITEMINFOM, *LPMENUITEMINFOM;
typedef struct winuser_menu_item_info_utf16					MENUITEMINFOW, *LPMENUITEMINFOW;
typedef const struct winuser_menu_item_info_ansi				*LPCMENUITEMINFOA;
typedef const struct winuser_menu_item_info_utf8				*LPCMENUITEMINFOM;
typedef const struct winuser_menu_item_info_utf16				*LPCMENUITEMINFOW;
typedef struct winuser_drop_struct						DROPSTRUCT, *PDROPSTRUCT, *LPDROPSTRUCT;
typedef struct winuser_draw_text_params						DRAWTEXTPARAMS, *LPDRAWTEXTPARAMS;
typedef struct winuser_help_info						HELPINFO, *LPHELPINFO;
typedef struct winuser_msg_box_params_ansi					MSGBOXPARAMSA, *PMSGBOXPARAMSA, *LPMSGBOXPARAMSA;
typedef struct winuser_msg_box_params_utf8					MSGBOXPARAMSM, *PMSGBOXPARAMSM, *LPMSGBOXPARAMSM;
typedef struct winuser_msg_box_params_utf16					MSGBOXPARAMSW, *PMSGBOXPARAMSW, *LPMSGBOXPARAMSW;
typedef struct winuser_menu_item_template_header				MENUITEMTEMPLATEHEADER, *PMENUITEMTEMPLATEHEADER;
typedef struct winuser_menu_item_template					MENUITEMTEMPLATE, *PMENUITEMTEMPLATE;
typedef struct winuser_icon_info						ICONINFO, *PICONINFO;
typedef struct winuser_cursor_shape						CURSORSHAPE, *LPCURSORSHAPE;
typedef struct winuser_icon_info_ex_ansi					ICONINFOEXA, *PICONINFOEXA;
typedef struct winuser_icon_info_ex_utf8					ICONINFOEXM, *PICONINFOEXM;
typedef struct winuser_icon_info_ex_utf16					ICONINFOEXW, *PICONINFOEXW;
typedef struct winuser_scroll_info						SCROLLINFO, *LPSCROLLINFO;
typedef const struct winuser_scroll_info					*LPCSCROLLINFO;
typedef struct winuser_mdi_create_struct_ansi					MDICREATESTRUCTA, *LPMDICREATESTRUCTA;
typedef struct winuser_mdi_create_struct_utf8					MDICREATESTRUCTM, *LPMDICREATESTRUCTM;
typedef struct winuser_mdi_create_struct_utf16					MDICREATESTRUCTW, *LPMDICREATESTRUCTW;
typedef struct winuser_client_create_struct					CLIENTCREATESTRUCT, *LPCLIENTCREATESTRUCT;
typedef struct winuser_multi_key_help_ansi					MULTIKEYHELPA, *PMULTIKEYHELPA, *LPMULTIKEYHELPA;
typedef struct winuser_multi_key_help_utf8					MULTIKEYHELPM, *PMULTIKEYHELPM, *LPMULTIKEYHELPM;
typedef struct winuser_multi_key_help_utf16					MULTIKEYHELPW, *PMULTIKEYHELPW, *LPMULTIKEYHELPW;
typedef struct winuser_help_win_info_ansi					HELPWININFOA, *PHELPWININFOA, *LPHELPWININFOA;
typedef struct winuser_help_win_info_utf8					HELPWININFOM, *PHELPWININFOM, *LPHELPWININFOM;
typedef struct winuser_help_win_info_utf16					HELPWININFOW, *PHELPWININFOW, *LPHELPWININFOW;
typedef struct winuser_touch_prediction_parameters				TOUCHPREDICTIONPARAMETERS, *PTOUCHPREDICTIONPARAMETERS;
typedef struct winuser_non_client_metrics_ansi					NONCLIENTMETRICSA, *PNONCLIENTMETRICSA, *LPNONCLIENTMETRICSA;
typedef struct winuser_non_client_metrics_utf8					NONCLIENTMETRICSM, *PNONCLIENTMETRICSM, *LPNONCLIENTMETRICSM;
typedef struct winuser_non_client_metrics_utf16					NONCLIENTMETRICSW, *PNONCLIENTMETRICSW, *LPNONCLIENTMETRICSW;
typedef struct winuser_minimized_metrics					MINIMIZEDMETRICS, *PMINIMIZEDMETRICS, *LPMINIMIZEDMETRICS;
typedef struct winuser_icon_metrics_ansi					ICONMETRICSA, *PICONMETRICSA, *LPICONMETRICSA;
typedef struct winuser_icon_metrics_utf8					ICONMETRICSM, *PICONMETRICSM, *LPICONMETRICSM;
typedef struct winuser_icon_metrics_utf16					ICONMETRICSW, *PICONMETRICSW, *LPICONMETRICSW;
typedef struct winuser_animation_info						ANIMATIONINFO, *LPANIMATIONINFO;
typedef struct winuser_serial_keys_ansi						SERIALKEYSA, *LPSERIALKEYSA;
typedef struct winuser_serial_keys_utf8						SERIALKEYSM, *LPSERIALKEYSM;
typedef struct winuser_serial_keys_utf16					SERIALKEYSW, *LPSERIALKEYSW;
typedef struct winuser_high_contrast_ansi					HIGHCONTRASTA, *LPHIGHCONTRASTA;
typedef struct winuser_high_contrast_utf8					HIGHCONTRASTM, *LPHIGHCONTRASTM;
typedef struct winuser_high_contrast_utf16					HIGHCONTRASTW, *LPHIGHCONTRASTW;
typedef struct winuser_sticky_keys						STICKYKEYS, *LPSTICKYKEYS;
typedef struct winuser_mouse_keys						MOUSEKEYS, *LPMOUSEKEYS;
typedef struct winuser_access_timeout						ACCESSTIMEOUT, *LPACCESSTIMEOUT;
typedef struct winuser_sounds_entry_ansi					SOUNDSENTRYA, *LPSOUNDSENTRYA;
typedef struct winuser_sounds_entry_utf8					SOUNDSENTRYM, *LPSOUNDSENTRYM;
typedef struct winuser_sounds_entry_utf16					SOUNDSENTRYW, *LPSOUNDSENTRYW;
typedef struct winuser_toggle_keys						TOGGLEKEYS, *LPTOGGLEKEYS;
typedef struct winuser_monitor_info						MONITORINFO, *LPMONITORINFO;
typedef struct winuser_audio_description					AUDIODESCRIPTION, *LPAUDIODESCRIPTION;
typedef struct winuser_monitor_info_ex_ansi					MONITORINFOEXA, *LPMONITORINFOEXA;
typedef struct winuser_monitor_info_ex_utf8					MONITORINFOEXM, *LPMONITORINFOEXM;
typedef struct winuser_monitor_info_ex_utf16					MONITORINFOEXW, *LPMONITORINFOEXW;
typedef struct winuser_gui_thread_info						GUITHREADINFO, *PGUITHREADINFO, *LPGUITHREADINFO;
typedef struct winuser_cursor_info						CURSORINFO, *PCURSORINFO, *LPCURSORINFO;
typedef struct winuser_window_info						WINDOWINFO, *PWINDOWINFO, *LPWINDOWINFO;
typedef struct winuser_title_bar_info_ex					TITLEBARINFOEX, *PTITLEBARINFOEX, *LPTITLEBARINFOEX;
typedef struct winuser_menu_bar_info						MENUBARINFO, *PMENUBARINFO, *LPMENUBARINFO;
typedef struct winuser_title_bar_info						TITLEBARINFO, *PTITLEBARINFO, *LPTITLEBARINFO;
typedef struct winuser_scroll_bar_info						SCROLLBARINFO, *PSCROLLBARINFO, *LPSCROLLBARINFO;
typedef struct winuser_combo_box_info						COMBOBOXINFO, *PCOMBOBOXINFO, *LPCOMBOBOXINFO;
typedef struct winuser_alt_tab_info						ALTTABINFO, *PALTTABINFO, *LPALTTABINFO;
typedef struct winuser_raw_input_header						RAWINPUTHEADER, *PRAWINPUTHEADER, *LPRAWINPUTHEADER;
typedef struct winuser_raw_mouse						RAWMOUSE, *PRAWMOUSE, *LPRAWMOUSE;
typedef struct winuser_raw_keyboard						RAWKEYBOARD, *PRAWKEYBOARD, *LPRAWKEYBOARD;
typedef struct winuser_raw_hid							RAWHID, *PRAWHID, *LPRAWHID;
typedef struct winuser_raw_input						RAWINPUT, *PRAWINPUT, *LPRAWINPUT;
typedef struct winuser_rid_device_info_mouse					RID_DEVICE_INFO_MOUSE, *PRID_DEVICE_INFO_MOUSE;
typedef struct winuser_rid_device_info_keyboard					RID_DEVICE_INFO_KEYBOARD, *PRID_DEVICE_INFO_KEYBOARD;
typedef struct winuser_rid_device_info_hid					RID_DEVICE_INFO_HID, *PRID_DEVICE_INFO_HID;
typedef struct winuser_rid_device_info						RID_DEVICE_INFO, *PRID_DEVICE_INFO, *LPRID_DEVICE_INFO;
typedef struct winuser_raw_input_device						RAWINPUTDEVICE, *PRAWINPUTDEVICE, *LPRAWINPUTDEVICE;
typedef const struct winuser_raw_input_device					*PCRAWINPUTDEVICE;
typedef struct winuser_raw_input_device_list					RAWINPUTDEVICELIST, *PRAWINPUTDEVICELIST;
typedef struct winuser_pointer_device_info					POINTER_DEVICE_INFO;
typedef struct winuser_pointer_device_property					POINTER_DEVICE_PROPERTY;
typedef struct winuser_pointer_device_cursor_info				POINTER_DEVICE_CURSOR_INFO;
typedef struct winuser_change_filter_struct					CHANGEFILTERSTRUCT, *PCHANGEFILTERSTRUCT;
typedef struct winuser_gesture_info						GESTUREINFO, *PGESTUREINFO;
typedef const struct winuser_gesture_info					*PCGESTUREINFO;
typedef struct winuser_gesture_notify_struct					GESTURENOTIFYSTRUCT, *PGESTURENOTIFYSTRUCT;
typedef struct winuser_gesture_config						GESTURECONFIG, *PGESTURECONFIG;
typedef struct winuser_input_message_source					INPUT_MESSAGE_SOURCE;
typedef struct winuser_input_transform						INPUT_TRANSFORM;
typedef struct winuser_video_parameters						VIDEOPARAMETERS, *PVIDEOPARAMETERS, *LPVIDEOPARAMETERS;



typedef void (__stdcall * MSGBOXCALLBACK)(
	LPHELPINFO	lpHelpInfo);

typedef void (__stdcall * WINEVENTPROC)(
	HWINEVENTHOOK	hWinEventHook,
	DWORD		event,
	HWND		hwnd,
	LONG		idObject,
	LONG		idChild,
	DWORD		idEventThread,
	DWORD		dwmsEventTime);

typedef BOOLEAN (__stdcall * PREGISTERCLASSNAMEW)(
	LPCWSTR);



struct winuser_cbt_create_wnd_ansi {
	struct winuser_create_struct_ansi *lpcs;
	HWND hwndInsertAfter;
};

struct winuser_cbt_create_wnd_utf8 {
	struct winuser_create_struct_utf8 *lpcs;
	HWND hwndInsertAfter;
};

struct winuser_cbt_create_wnd_utf16 {
	struct winuser_create_struct_utf16 *lpcs;
	HWND hwndInsertAfter;
};

struct winuser_cbt_activate_struct {
	BOOL fMouse;
	HWND hWndActive;
};

struct winuser_wts_session_notification {
	DWORD cbSize;
	DWORD dwSessionId;
};

struct winuser_shell_hook_info {
	HWND hwnd;
	RECT rc;
};

struct winuser_event_msg {
	UINT message;
	UINT paramL;
	UINT paramH;
	DWORD time;
	HWND hwnd;
};

struct winuser_cwp_struct {
	LPARAM lParam;
	WPARAM wParam;
	UINT message;
	HWND hwnd;
};

struct winuser_cwp_ret_struct {
	LRESULT lResult;
	LPARAM lParam;
	WPARAM wParam;
	UINT message;
	HWND hwnd;
};

struct winuser_kb_dll_hook_struct {
	DWORD vkCode;
	DWORD scanCode;
	DWORD flags;
	DWORD time;
	ULONG_PTR dwExtraInfo;
};

struct winuser_ms_ll_hook_struct {
	POINT pt;
	DWORD mouseData;
	DWORD flags;
	DWORD time;
	ULONG_PTR dwExtraInfo;
};

struct winuser_debug_hook_info {
	DWORD idThread;
	DWORD idThreadInstaller;
	LPARAM lParam;
	WPARAM wParam;
	int code;
};

struct winuser_mouse_hook_struct {
	POINT pt;
	HWND hwnd;
	UINT wHitTestCode;
	ULONG_PTR dwExtraInfo;
};

#ifdef __cplusplus
struct winuser_mouse_hook_struct_ex : public winuser_MOUSEHOOKSTRUCT {
	DWORD mouseData;
};
#else
struct winuser_mouse_hook_struct_ex {
	MOUSEHOOKSTRUCT __unnamed;
	DWORD mouseData;
};
#endif

struct winuser_hardware_hook_struct {
	HWND hwnd;
	UINT message;
	WPARAM wParam;
	LPARAM lParam;
};

struct winuser_mouse_move_point {
	int x;
	int y;
	DWORD time;
	ULONG_PTR dwExtraInfo;
};

struct winuser_user_object_flags {
	BOOL fInherit;
	BOOL fReserved;
	DWORD dwFlags;
};

struct winuser_wnd_class_ex_ansi {
	UINT cbSize;
	UINT style;
	WNDPROC lpfnWndProc;
	int cbClsExtra;
	int cbWndExtra;
	HINSTANCE hInstance;
	HICON hIcon;
	HCURSOR hCursor;
	HBRUSH hbrBackground;
	LPCSTR lpszMenuName;
	LPCSTR lpszClassName;
	HICON hIconSm;
};

struct winuser_wnd_class_ex_utf8 {
	UINT cbSize;
	UINT style;
	WNDPROC lpfnWndProc;
	int cbClsExtra;
	int cbWndExtra;
	HINSTANCE hInstance;
	HICON hIcon;
	HCURSOR hCursor;
	HBRUSH hbrBackground;
	LPCSTR lpszMenuName;
	LPCSTR lpszClassName;
	HICON hIconSm;
};

struct winuser_wnd_class_ex_utf16 {
	UINT cbSize;
	UINT style;
	WNDPROC lpfnWndProc;
	int cbClsExtra;
	int cbWndExtra;
	HINSTANCE hInstance;
	HICON hIcon;
	HCURSOR hCursor;
	HBRUSH hbrBackground;
	LPCWSTR lpszMenuName;
	LPCWSTR lpszClassName;
	HICON hIconSm;
};

struct winuser_wnd_class_ansi {
	UINT style;
	WNDPROC lpfnWndProc;
	int cbClsExtra;
	int cbWndExtra;
	HINSTANCE hInstance;
	HICON hIcon;
	HCURSOR hCursor;
	HBRUSH hbrBackground;
	LPCSTR lpszMenuName;
	LPCSTR lpszClassName;
};

struct winuser_wnd_class_utf8 {
	UINT style;
	WNDPROC lpfnWndProc;
	int cbClsExtra;
	int cbWndExtra;
	HINSTANCE hInstance;
	HICON hIcon;
	HCURSOR hCursor;
	HBRUSH hbrBackground;
	LPCSTR lpszMenuName;
	LPCSTR lpszClassName;
};

struct winuser_wnd_class_utf16 {
	UINT style;
	WNDPROC lpfnWndProc;
	int cbClsExtra;
	int cbWndExtra;
	HINSTANCE hInstance;
	HICON hIcon;
	HCURSOR hCursor;
	HBRUSH hbrBackground;
	LPCWSTR lpszMenuName;
	LPCWSTR lpszClassName;
};

struct winuser_msg {
	HWND hwnd;
	UINT message;
	WPARAM wParam;
	LPARAM lParam;
	DWORD time;
	POINT pt;
};

struct winuser_min_max_info {
	POINT ptReserved;
	POINT ptMaxSize;
	POINT ptMaxPosition;
	POINT ptMinTrackSize;
	POINT ptMaxTrackSize;
};

struct winuser_copy_data_struct {
	ULONG_PTR dwData;
	DWORD cbData;
	PVOID lpData;
};

struct winuser_mdi_next_menu {
	HMENU hmenuIn;
	HMENU hmenuNext;
	HWND hwndNext;
};

struct winuser_power_broadcast_setting {
	GUID PowerSetting;
	DWORD DataLength;
	UCHAR Data[1];
};

struct winuser_window_pos {
	HWND hwnd;
	HWND hwndInsertAfter;
	int x;
	int y;
	int cx;
	int cy;
	UINT flags;
};

struct winuser_nc_calc_size_params {
	RECT rgrc[3];
	PWINDOWPOS lppos;
};
  
struct winuser_track_mouse_event {
	DWORD cbSize;
	DWORD dwFlags;
	HWND hwndTrack;
	DWORD dwHoverTime;
};
  
struct winuser_accel {
	BYTE fVirt;
	WORD key;
	WORD cmd;
};

struct winuser_paint_struct {
	HDC hdc;
	BOOL fErase;
	RECT rcPaint;
	BOOL fRestore;
	BOOL fIncUpdate;
	BYTE rgbReserved[32];
};

struct winuser_create_struct_ansi {
	LPVOID lpCreateParams;
	HINSTANCE hInstance;
	HMENU hMenu;
	HWND hwndParent;
	int cy;
	int cx;
	int y;
	int x;
	LONG style;
	LPCSTR lpszName;
	LPCSTR lpszClass;
	DWORD dwExStyle;
};

struct winuser_create_struct_utf8 {
	LPVOID lpCreateParams;
	HINSTANCE hInstance;
	HMENU hMenu;
	HWND hwndParent;
	int cy;
	int cx;
	int y;
	int x;
	LONG style;
	LPCSTR lpszName;
	LPCSTR lpszClass;
	DWORD dwExStyle;
};

struct winuser_create_struct_utf16 {
	LPVOID lpCreateParams;
	HINSTANCE hInstance;
	HMENU hMenu;
	HWND hwndParent;
	int cy;
	int cx;
	int y;
	int x;
	LONG style;
	LPCWSTR lpszName;
	LPCWSTR lpszClass;
	DWORD dwExStyle;
};

struct winuser_window_placement {
	UINT length;
	UINT flags;
	UINT showCmd;
	POINT ptMinPosition;
	POINT ptMaxPosition;
	RECT rcNormalPosition;
};

struct winuser_nmhdr {
	HWND hwndFrom;
	UINT_PTR idFrom;
	UINT code;
};

struct winuser_style_struct {
	DWORD styleOld;
	DWORD styleNew;
};

struct winuser_measure_item_struct {
	UINT CtlType;
	UINT CtlID;
	UINT itemID;
	UINT itemWidth;
	UINT itemHeight;
	ULONG_PTR itemData;
};

struct winuser_draw_item_struct {
	UINT CtlType;
	UINT CtlID;
	UINT itemID;
	UINT itemAction;
	UINT itemState;
	HWND hwndItem;
	HDC hDC;
	RECT rcItem;
	ULONG_PTR itemData;
};

struct winuser_delete_item_struct {
	UINT CtlType;
	UINT CtlID;
	UINT itemID;
	HWND hwndItem;
	ULONG_PTR itemData;
};

struct winuser_compare_item_struct {
	UINT CtlType;
	UINT CtlID;
	HWND hwndItem;
	UINT itemID1;
	ULONG_PTR itemData1;
	UINT itemID2;
	ULONG_PTR itemData2;
	DWORD dwLocaleId;
};

struct winuser_bsm_info {
	UINT cbSize;
	HDESK hdesk;
	HWND hwnd;
	LUID luid;
};

struct winuser_update_layered_window_info {
	DWORD cbSize;
	HDC hdcDst;
	const POINT *pptDst;
	const SIZE *psize;
	HDC hdcSrc;
	const POINT *pptSrc;
	COLORREF crKey;
	const BLENDFUNCTION *pblend;
	DWORD dwFlags;
	const RECT *prcDirty;
};

struct winuser_flash_w_info {
	UINT cbSize;
	HWND hwnd;
	DWORD dwFlags;
	UINT uCount;
	DWORD dwTimeout;
};

#pragma pack(push,2)

struct winuser_dlg_template {
	DWORD style;
	DWORD dwExtendedStyle;
	WORD cdit;
	short x;
	short y;
	short cx;
	short cy;
};

struct winuser_dlg_item_template {
	DWORD style;
	DWORD dwExtendedStyle;
	short x;
	short y;
	short cx;
	short cy;
	WORD id;
};

#pragma pack(pop)

struct winuser_mouse_input {
	LONG dx;
	LONG dy;
	DWORD mouseData;
	DWORD dwFlags;
	DWORD time;
	ULONG_PTR dwExtraInfo;
};

struct winuser_keybd_input {
	WORD wVk;
	WORD wScan;
	DWORD dwFlags;
	DWORD time;
	ULONG_PTR dwExtraInfo;
};

struct winuser_hardware_input {
	DWORD uMsg;
	WORD wParamL;
	WORD wParamH;
};

struct winuser_input {
	DWORD type;
	union {
		MOUSEINPUT mi;
		KEYBDINPUT ki;
		HARDWAREINPUT hi;
	};
};

struct winuser_touch_input {
	LONG x;
	LONG y;
	HANDLE hSource;
	DWORD dwID;
	DWORD dwFlags;
	DWORD dwMask;
	DWORD dwTime;
	ULONG_PTR dwExtraInfo;
	DWORD cxContact;
	DWORD cyContact;
};
  
struct winuser_pointer_info {
	POINTER_INPUT_TYPE pointerType;
	UINT32 pointerId;
	UINT32 frameId;
	POINTER_FLAGS pointerFlags;
	HANDLE sourceDevice;
	HWND hwndTarget;
	POINT ptPixelLocation;
	POINT ptHimetricLocation;
	POINT ptPixelLocationRaw;
	POINT ptHimetricLocationRaw;
	DWORD dwTime;
	UINT32 historyCount;
	INT32 InputData;
	DWORD dwKeyStates;
	UINT64 PerformanceCount;
	POINTER_BUTTON_CHANGE_TYPE ButtonChangeType;
};

struct winuser_pointer_touch_info {
	POINTER_INFO pointerInfo;
	TOUCH_FLAGS touchFlags;
	TOUCH_MASK touchMask;
	RECT rcContact;
	RECT rcContactRaw;
	UINT32 orientation;
	UINT32 pressure;
};

struct winuser_pointer_pen_info {
	POINTER_INFO pointerInfo;
	PEN_FLAGS penFlags;
	PEN_MASK penMask;
	UINT32 pressure;
	UINT32 rotation;
	INT32 tiltX;
	INT32 tiltY;
};

struct winuser_touch_hit_testing_proximity_evaluation {
	UINT16 score;
	POINT adjustedPoint;
};

struct winuser_touch_hit_testing_input {
	UINT32 pointerId;
	POINT point;
	RECT boundingBox;
	RECT nonOccludedBoundingBox;
	UINT32 orientation;
};

struct winuser_last_input_info {
	UINT cbSize;
	DWORD dwTime;
};

struct winuser_tpm_params {
	UINT cbSize;
	RECT rcExclude;
};

struct winuser_menu_info {
	DWORD cbSize;
	DWORD fMask;
	DWORD dwStyle;
	UINT cyMax;
	HBRUSH hbrBack;
	DWORD dwContextHelpID;
	ULONG_PTR dwMenuData;
};

struct winuser_menu_get_object_info {
	DWORD dwFlags;
	UINT uPos;
	HMENU hmenu;
	PVOID riid;
	PVOID pvObj;
};

struct winuser_menu_item_info_ansi {
	UINT cbSize;
	UINT fMask;
	UINT fType;
	UINT fState;
	UINT wID;
	HMENU hSubMenu;
	HBITMAP hbmpChecked;
	HBITMAP hbmpUnchecked;
	ULONG_PTR dwItemData;
	LPSTR dwTypeData;
	UINT cch;
	HBITMAP hbmpItem;
};

struct winuser_menu_item_info_utf8 {
	UINT cbSize;
	UINT fMask;
	UINT fType;
	UINT fState;
	UINT wID;
	HMENU hSubMenu;
	HBITMAP hbmpChecked;
	HBITMAP hbmpUnchecked;
	ULONG_PTR dwItemData;
	LPSTR dwTypeData;
	UINT cch;
	HBITMAP hbmpItem;
};

struct winuser_menu_item_info_utf16 {
	UINT cbSize;
	UINT fMask;
	UINT fType;
	UINT fState;
	UINT wID;
	HMENU hSubMenu;
	HBITMAP hbmpChecked;
	HBITMAP hbmpUnchecked;
	ULONG_PTR dwItemData;
	LPWSTR dwTypeData;
	UINT cch;
	HBITMAP hbmpItem;
};

struct winuser_drop_struct {
	HWND hwndSource;
	HWND hwndSink;
	DWORD wFmt;
	ULONG_PTR dwData;
	POINT ptDrop;
	DWORD dwControlData;
};

struct winuser_draw_text_params {
	UINT cbSize;
	int iTabLength;
	int iLeftMargin;
	int iRightMargin;
	UINT uiLengthDrawn;
};

struct winuser_help_info {
	UINT cbSize;
	int iContextType;
	int iCtrlId;
	HANDLE hItemHandle;
	DWORD_PTR dwContextId;
	POINT MousePos;
};

struct winuser_msg_box_params_ansi {
	UINT cbSize;
	HWND hwndOwner;
	HINSTANCE hInstance;
	LPCSTR lpszText;
	LPCSTR lpszCaption;
	DWORD dwStyle;
	LPCSTR lpszIcon;
	DWORD_PTR dwContextHelpId;
	MSGBOXCALLBACK lpfnMsgBoxCallback;
	DWORD dwLanguageId;
};

struct winuser_msg_box_params_utf8 {
	UINT cbSize;
	HWND hwndOwner;
	HINSTANCE hInstance;
	LPCSTR lpszText;
	LPCSTR lpszCaption;
	DWORD dwStyle;
	LPCSTR lpszIcon;
	DWORD_PTR dwContextHelpId;
	MSGBOXCALLBACK lpfnMsgBoxCallback;
	DWORD dwLanguageId;
};

struct winuser_msg_box_params_utf16 {
	UINT cbSize;
	HWND hwndOwner;
	HINSTANCE hInstance;
	LPCWSTR lpszText;
	LPCWSTR lpszCaption;
	DWORD dwStyle;
	LPCWSTR lpszIcon;
	DWORD_PTR dwContextHelpId;
	MSGBOXCALLBACK lpfnMsgBoxCallback;
	DWORD dwLanguageId;
};

struct winuser_menu_item_template_header {
	WORD versionNumber;
	WORD offset;
};

struct winuser_menu_item_template {
	WORD mtOption;
	WORD mtID;
	WCHAR mtString[1];
};

struct winuser_icon_info {
	BOOL fIcon;
	DWORD xHotspot;
	DWORD yHotspot;
	HBITMAP hbmMask;
	HBITMAP hbmColor;
};

struct winuser_cursor_shape {
	int xHotSpot;
	int yHotSpot;
	int cx;
	int cy;
	int cbWidth;
	BYTE Planes;
	BYTE BitsPixel;
};

struct winuser_icon_info_ex_ansi {
	DWORD cbSize;
	BOOL fIcon;
	DWORD xHotspot;
	DWORD yHotspot;
	HBITMAP hbmMask;
	HBITMAP hbmColor;
	WORD wResID;
	CHAR szModName[MAX_PATH];
	CHAR szResName[MAX_PATH];
};

struct winuser_icon_info_ex_utf8 {
	DWORD cbSize;
	BOOL fIcon;
	DWORD xHotspot;
	DWORD yHotspot;
	HBITMAP hbmMask;
	HBITMAP hbmColor;
	WORD wResID;
	CHAR szModName[MAX_PATH];
	CHAR szResName[MAX_PATH];
};

struct winuser_icon_info_ex_utf16 {
	DWORD cbSize;
	BOOL fIcon;
	DWORD xHotspot;
	DWORD yHotspot;
	HBITMAP hbmMask;
	HBITMAP hbmColor;
	WORD wResID;
	WCHAR szModName[MAX_PATH];
	WCHAR szResName[MAX_PATH];
};

struct winuser_scroll_info {
	UINT cbSize;
	UINT fMask;
	int nMin;
	int nMax;
	UINT nPage;
	int nPos;
	int nTrackPos;
};

struct winuser_mdi_create_struct_ansi {
	LPCSTR szClass;
	LPCSTR szTitle;
	HANDLE hOwner;
	int x;
	int y;
	int cx;
	int cy;
	DWORD style;
	LPARAM lParam;
};

struct winuser_mdi_create_struct_utf8 {
	LPCSTR szClass;
	LPCSTR szTitle;
	HANDLE hOwner;
	int x;
	int y;
	int cx;
	int cy;
	DWORD style;
	LPARAM lParam;
};

struct winuser_mdi_create_struct_utf16 {
	LPCWSTR szClass;
	LPCWSTR szTitle;
	HANDLE hOwner;
	int x;
	int y;
	int cx;
	int cy;
	DWORD style;
	LPARAM lParam;
};

struct winuser_client_create_struct {
	HANDLE hWindowMenu;
	UINT idFirstChild;
};

struct winuser_multi_key_help_ansi {
	DWORD mkSize;
	CHAR mkKeylist;
	CHAR szKeyphrase[1];
};

struct winuser_multi_key_help_utf8 {
	DWORD mkSize;
	CHAR mkKeylist;
	CHAR szKeyphrase[1];
};

struct winuser_multi_key_help_utf16 {
	DWORD mkSize;
	WCHAR mkKeylist;
	WCHAR szKeyphrase[1];
};

struct winuser_help_win_info_ansi {
	int wStructSize;
	int x;
	int y;
	int dx;
	int dy;
	int wMax;
	CHAR rgchMember[2];
};

struct winuser_help_win_info_utf8 {
	int wStructSize;
	int x;
	int y;
	int dx;
	int dy;
	int wMax;
	CHAR rgchMember[2];
};

struct winuser_help_win_info_utf16 {
	int wStructSize;
	int x;
	int y;
	int dx;
	int dy;
	int wMax;
	WCHAR rgchMember[2];
};

struct winuser_touch_prediction_parameters {
	UINT cbSize;
	UINT dwLatency;
	UINT dwSampleTime;
	UINT bUseHWTimeStamp;
};

struct winuser_non_client_metrics_ansi {
	UINT cbSize;
	int iBorderWidth;
	int iScrollWidth;
	int iScrollHeight;
	int iCaptionWidth;
	int iCaptionHeight;
	LOGFONTA lfCaptionFont;
	int iSmCaptionWidth;
	int iSmCaptionHeight;
	LOGFONTA lfSmCaptionFont;
	int iMenuWidth;
	int iMenuHeight;
	LOGFONTA lfMenuFont;
	LOGFONTA lfStatusFont;
	LOGFONTA lfMessageFont;
#if WINVER >= 0x0600
	int iPaddedBorderWidth;
#endif
};

struct winuser_non_client_metrics_utf8 {
	UINT cbSize;
	int iBorderWidth;
	int iScrollWidth;
	int iScrollHeight;
	int iCaptionWidth;
	int iCaptionHeight;
	LOGFONTA lfCaptionFont;
	int iSmCaptionWidth;
	int iSmCaptionHeight;
	LOGFONTA lfSmCaptionFont;
	int iMenuWidth;
	int iMenuHeight;
	LOGFONTA lfMenuFont;
	LOGFONTA lfStatusFont;
	LOGFONTA lfMessageFont;
#if WINVER >= 0x0600
	int iPaddedBorderWidth;
#endif
};

struct winuser_non_client_metrics_utf16 {
	UINT cbSize;
	int iBorderWidth;
	int iScrollWidth;
	int iScrollHeight;
	int iCaptionWidth;
	int iCaptionHeight;
	LOGFONTW lfCaptionFont;
	int iSmCaptionWidth;
	int iSmCaptionHeight;
	LOGFONTW lfSmCaptionFont;
	int iMenuWidth;
	int iMenuHeight;
	LOGFONTW lfMenuFont;
	LOGFONTW lfStatusFont;
	LOGFONTW lfMessageFont;
#if WINVER >= 0x0600
	int iPaddedBorderWidth;
#endif
};

struct winuser_minimized_metrics {
	UINT cbSize;
	int iWidth;
	int iHorzGap;
	int iVertGap;
	int iArrange;
};

struct winuser_icon_metrics_ansi {
	UINT cbSize;
	int iHorzSpacing;
	int iVertSpacing;
	int iTitleWrap;
	LOGFONTA lfFont;
};

struct winuser_icon_metrics_utf8 {
	UINT cbSize;
	int iHorzSpacing;
	int iVertSpacing;
	int iTitleWrap;
	LOGFONTA lfFont;
};

struct winuser_icon_metrics_utf16 {
	UINT cbSize;
	int iHorzSpacing;
	int iVertSpacing;
	int iTitleWrap;
	LOGFONTW lfFont;
};

struct winuser_animation_info {
	UINT cbSize;
	int iMinAnimate;
};

struct winuser_serial_keys_ansi {
	UINT cbSize;
	DWORD dwFlags;
	LPSTR lpszActivePort;
	LPSTR lpszPort;
	UINT iBaudRate;
	UINT iPortState;
	UINT iActive;
};

struct winuser_serial_keys_utf8 {
	UINT cbSize;
	DWORD dwFlags;
	LPSTR lpszActivePort;
	LPSTR lpszPort;
	UINT iBaudRate;
	UINT iPortState;
	UINT iActive;
};

struct winuser_serial_keys_utf16 {
	UINT cbSize;
	DWORD dwFlags;
	LPWSTR lpszActivePort;
	LPWSTR lpszPort;
	UINT iBaudRate;
	UINT iPortState;
	UINT iActive;
};

struct winuser_high_contrast_ansi {
	UINT cbSize;
	DWORD dwFlags;
	LPSTR lpszDefaultScheme;
};

struct winuser_high_contrast_utf8 {
	UINT cbSize;
	DWORD dwFlags;
	LPSTR lpszDefaultScheme;
};

struct winuser_high_contrast_utf16 {
	UINT cbSize;
	DWORD dwFlags;
	LPWSTR lpszDefaultScheme;
};

struct winuser_sticky_keys {
	UINT cbSize;
	DWORD dwFlags;
};

struct winuser_mouse_keys {
	UINT cbSize;
	DWORD dwFlags;
	DWORD iMaxSpeed;
	DWORD iTimeToMaxSpeed;
	DWORD iCtrlSpeed;
	DWORD dwReserved1;
	DWORD dwReserved2;
};

struct winuser_access_timeout {
	UINT cbSize;
	DWORD dwFlags;
	DWORD iTimeOutMSec;
};

struct winuser_sounds_entry_ansi {
	UINT cbSize;
	DWORD dwFlags;
	DWORD iFSTextEffect;
	DWORD iFSTextEffectMSec;
	DWORD iFSTextEffectColorBits;
	DWORD iFSGrafEffect;
	DWORD iFSGrafEffectMSec;
	DWORD iFSGrafEffectColor;
	DWORD iWindowsEffect;
	DWORD iWindowsEffectMSec;
	LPSTR lpszWindowsEffectDLL;
	DWORD iWindowsEffectOrdinal;
};

struct winuser_sounds_entry_utf8 {
	UINT cbSize;
	DWORD dwFlags;
	DWORD iFSTextEffect;
	DWORD iFSTextEffectMSec;
	DWORD iFSTextEffectColorBits;
	DWORD iFSGrafEffect;
	DWORD iFSGrafEffectMSec;
	DWORD iFSGrafEffectColor;
	DWORD iWindowsEffect;
	DWORD iWindowsEffectMSec;
	LPSTR lpszWindowsEffectDLL;
	DWORD iWindowsEffectOrdinal;
};

struct winuser_sounds_entry_utf16 {
	UINT cbSize;
	DWORD dwFlags;
	DWORD iFSTextEffect;
	DWORD iFSTextEffectMSec;
	DWORD iFSTextEffectColorBits;
	DWORD iFSGrafEffect;
	DWORD iFSGrafEffectMSec;
	DWORD iFSGrafEffectColor;
	DWORD iWindowsEffect;
	DWORD iWindowsEffectMSec;
	LPWSTR lpszWindowsEffectDLL;
	DWORD iWindowsEffectOrdinal;
};

struct winuser_toggle_keys {
	UINT cbSize;
	DWORD dwFlags;
};

struct winuser_monitor_info {
	DWORD cbSize;
	RECT rcMonitor;
	RECT rcWork;
	DWORD dwFlags;
};

struct winuser_audio_description {
	UINT cbSize;
	BOOL Enabled;
	LCID Locale;
};

#ifdef __cplusplus
struct winuser_monitor_info_ex_ansi : public winuser_monitor_info {
	CHAR szDevice[CCHDEVICENAME];
};

struct winuser_monitor_info_ex_utf8 : public winuser_monitor_info {
	CHAR szDevice[CCHDEVICENAME];
};

struct winuser_monitor_info_ex_utf16 : public winuser_monitor_info {
	WCHAR szDevice[CCHDEVICENAME];
};
#else
struct winuser_monitor_info_ex_ansi {
	struct {
		DWORD cbSize;
		RECT rcMonitor;
		RECT rcWork;
		DWORD dwFlags;
	};
	CHAR szDevice[CCHDEVICENAME];
};

struct winuser_monitor_info_ex_utf8 {
	struct {
		DWORD cbSize;
		RECT rcMonitor;
		RECT rcWork;
		DWORD dwFlags;
	};
	CHAR szDevice[CCHDEVICENAME];
};

struct winuser_monitor_info_ex_utf16 {
	struct {
		DWORD cbSize;
		RECT rcMonitor;
		RECT rcWork;
		DWORD dwFlags;
	};
	WCHAR szDevice[CCHDEVICENAME];
};
#endif

struct winuser_gui_thread_info {
	DWORD cbSize;
	DWORD flags;
	HWND hwndActive;
	HWND hwndFocus;
	HWND hwndCapture;
	HWND hwndMenuOwner;
	HWND hwndMoveSize;
	HWND hwndCaret;
	RECT rcCaret;
};

struct winuser_cursor_info {
	DWORD cbSize;
	DWORD flags;
	HCURSOR hCursor;
	POINT ptScreenPos;
};

struct winuser_window_info {
	DWORD cbSize;
	RECT rcWindow;
	RECT rcClient;
	DWORD dwStyle;
	DWORD dwExStyle;
	DWORD dwWindowStatus;
	UINT cxWindowBorders;
	UINT cyWindowBorders;
	ATOM atomWindowType;
	WORD wCreatorVersion;
};

struct winuser_title_bar_info_ex {
	DWORD cbSize;
	RECT rcTitleBar;
	DWORD rgstate[6];
	RECT rgrect[6];
};

struct winuser_menu_bar_info {
	DWORD cbSize;
	RECT rcBar;
	HMENU hMenu;
	HWND hwndMenu;
	BOOL fBarFocused:1;
	BOOL fFocused:1;
};

struct winuser_title_bar_info {
	DWORD cbSize;
	RECT rcTitleBar;
	DWORD rgstate[6];
};

struct winuser_scroll_bar_info {
	DWORD cbSize;
	RECT rcScrollBar;
	int dxyLineButton;
	int xyThumbTop;
	int xyThumbBottom;
	int reserved;
	DWORD rgstate[6];
};

struct winuser_combo_box_info {
	DWORD cbSize;
	RECT rcItem;
	RECT rcButton;
	DWORD stateButton;
	HWND hwndCombo;
	HWND hwndItem;
	HWND hwndList;
};

struct winuser_alt_tab_info {
	DWORD cbSize;
	int cItems;
	int cColumns;
	int cRows;
	int iColFocus;
	int iRowFocus;
	int cxItem;
	int cyItem;
	POINT ptStart;
};

struct winuser_raw_input_header {
	DWORD dwType;
	DWORD dwSize;
	HANDLE hDevice;
	WPARAM wParam;
};

struct winuser_raw_mouse {
	USHORT usFlags;
	union {
		ULONG ulButtons;
		struct {
			USHORT usButtonFlags;
			USHORT usButtonData;
		};
	};
	ULONG ulRawButtons;
	LONG lLastX;
	LONG lLastY;
	ULONG ulExtraInformation;
};

struct winuser_raw_keyboard {
	USHORT MakeCode;
	USHORT Flags;
	USHORT Reserved;
	USHORT VKey;
	UINT Message;
	ULONG ExtraInformation;
};

struct winuser_raw_hid {
	DWORD dwSizeHid;
	DWORD dwCount;
	BYTE bRawData[1];
};

struct winuser_raw_input {
	RAWINPUTHEADER header;
	union {
		RAWMOUSE mouse;
		RAWKEYBOARD keyboard;
		RAWHID hid;
	} data;
};

struct winuser_rid_device_info_mouse {
	DWORD dwId;
	DWORD dwNumberOfButtons;
	DWORD dwSampleRate;
	BOOL fHasHorizontalWheel;
};

struct winuser_rid_device_info_keyboard {
	DWORD dwType;
	DWORD dwSubType;
	DWORD dwKeyboardMode;
	DWORD dwNumberOfFunctionKeys;
	DWORD dwNumberOfIndicators;
	DWORD dwNumberOfKeysTotal;
};

struct winuser_rid_device_info_hid {
	DWORD dwVendorId;
	DWORD dwProductId;
	DWORD dwVersionNumber;
	USHORT usUsagePage;
	USHORT usUsage;
};

struct winuser_rid_device_info {
	DWORD cbSize;
	DWORD dwType;
	union {
		RID_DEVICE_INFO_MOUSE mouse;
		RID_DEVICE_INFO_KEYBOARD keyboard;
		RID_DEVICE_INFO_HID hid;
	};
};
  
struct winuser_raw_input_device {
	USHORT usUsagePage;
	USHORT usUsage;
	DWORD dwFlags;
	HWND hwndTarget;
};

struct winuser_raw_input_device_list {
	HANDLE hDevice;
	DWORD dwType;
};

struct winuser_pointer_device_info {
	DWORD displayOrientation;
	HANDLE device;
	POINTER_DEVICE_TYPE pointerDeviceType;
	HMONITOR monitor;
	ULONG startingCursorId;
	USHORT maxActiveContacts;
	WCHAR productString[520];
};

struct winuser_pointer_device_property {
	INT32 logicalMin;
	INT32 logicalMax;
	INT32 physicalMin;
	INT32 physicalMax;
	UINT32 unit;
	UINT32 unitExponent;
	USHORT usagePageId;
	USHORT usageId;
};

struct winuser_pointer_device_cursor_info {
	UINT32 cursorId;
	POINTER_DEVICE_CURSOR_TYPE cursor;
};

struct winuser_change_filter_struct {
	DWORD cbSize;
	DWORD ExtStatus;
};

struct winuser_gesture_info {
	UINT cbSize;
	DWORD dwFlags;
	DWORD dwID;
	HWND hwndTarget;
	POINTS ptsLocation;
	DWORD dwInstanceID;
	DWORD dwSequenceID;
	ULONGLONG ullArguments;
	UINT cbExtraArgs;
};

struct winuser_gesture_notify_struct {
	UINT cbSize;
	DWORD dwFlags;
	HWND hwndTarget;
	POINTS ptsLocation;
	DWORD dwInstanceID;
};

struct winuser_gesture_config {
	DWORD dwID;
	DWORD dwWant;
	DWORD dwBlock;
};

struct winuser_input_message_source {
	INPUT_MESSAGE_DEVICE_TYPE deviceType;
	INPUT_MESSAGE_ORIGIN_ID originId;
};

struct winuser_input_transform {
	union {
		struct {
			float _11;
			float _12;
			float _13;
			float _14;
			float _21;
			float _22;
			float _23;
			float _24;
			float _31;
			float _32;
			float _33;
			float _34;
			float _41;
			float _42;
			float _43;
			float _44;
		};
	float  m[4][4];
	};
};

struct winuser_video_parameters {
	GUID Guid;
	ULONG dwOffset;
	ULONG dwCommand;
	ULONG dwFlags;
	ULONG dwMode;
	ULONG dwTVStandard;
	ULONG dwAvailableModes;
	ULONG dwAvailableTVStandard;
	ULONG dwFlickerFilter;
	ULONG dwOverScanX;
	ULONG dwOverScanY;
	ULONG dwMaxUnscaledX;
	ULONG dwMaxUnscaledY;
	ULONG dwPositionX;
	ULONG dwPositionY;
	ULONG dwBrightness;
	ULONG dwContrast;
	ULONG dwCPType;
	ULONG dwCPCommand;
	ULONG dwCPStandard;
	ULONG dwCPKey;
	ULONG bCP_APSTriggerBits;
	UCHAR bOEMCopyProtection[256];
};




#ifdef WINAPI_ANSI_DEFAULT
typedef struct winuser_cbt_create_wnd_ansi			CBT_CREATEWND;
typedef struct winuser_wnd_class_ex_ansi			WNDCLASSEX;
typedef struct winuser_wnd_class_ansi				WNDCLASS;
typedef struct winuser_create_struct_ansi			CREATESTRUCT;
typedef struct winuser_menu_item_info_ansi			MENUITEMINFO;
typedef struct winuser_msg_box_params_ansi			MSGBOXPARAMS;
typedef struct winuser_icon_info_ex_ansi			ICONINFOEX;
typedef struct winuser_mdi_create_struct_ansi			MDICREATESTRUCT;
typedef struct winuser_multi_key_help_ansi			MULTIKEYHELP;
typedef struct winuser_help_win_info_ansi			HELPWININFO;
typedef struct winuser_non_client_metrics_ansi			NONCLIENTMETRICS;
typedef struct winuser_icon_metrics_ansi			ICONMETRICS;
typedef struct winuser_serial_keys_ansi				SERIALKEYS;
typedef struct winuser_high_contrast_ansi			HIGHCONTRAST;
typedef struct winuser_sounds_entry_ansi			SOUNDSENTRY;
typedef struct winuser_monitor_info_ex_ansi			MONITORINFOEX;
#endif

#ifdef WINAPI_UTF8_DEFAULT
typedef struct winuser_cbt_create_wnd_utf8			CBT_CREATEWND;
typedef struct winuser_wnd_class_ex_utf8			WNDCLASSEX;
typedef struct winuser_wnd_class_utf8				WNDCLASS;
typedef struct winuser_create_struct_utf8			CREATESTRUCT;
typedef struct winuser_menu_item_info_utf8			MENUITEMINFO;
typedef struct winuser_msg_box_params_utf8			MSGBOXPARAMS;
typedef struct winuser_icon_info_ex_utf8			ICONINFOEX;
typedef struct winuser_mdi_create_struct_utf8			MDICREATESTRUCT;
typedef struct winuser_multi_key_help_utf8			MULTIKEYHELP;
typedef struct winuser_help_win_info_utf8			HELPWININFO;
typedef struct winuser_non_client_metrics_utf8			NONCLIENTMETRICS;
typedef struct winuser_icon_metrics_utf8			ICONMETRICS;
typedef struct winuser_serial_keys_utf8				SERIALKEYS;
typedef struct winuser_high_contrast_utf8			HIGHCONTRAST;
typedef struct winuser_sounds_entry_utf8			SOUNDSENTRY;
typedef struct winuser_monitor_info_ex_utf8			MONITORINFOEX;
#endif

#ifdef WINAPI_UTF16_DEFAULT
typedef struct winuser_cbt_create_wnd_utf16			CBT_CREATEWND;
typedef struct winuser_wnd_class_ex_utf16			WNDCLASSEX;
typedef struct winuser_wnd_class_utf16				WNDCLASS;
typedef struct winuser_create_struct_utf16			CREATESTRUCT;
typedef struct winuser_menu_item_info_utf16			MENUITEMINFO;
typedef struct winuser_msg_box_params_utf16			MSGBOXPARAMS;
typedef struct winuser_icon_info_ex_utf16			ICONINFOEX;
typedef struct winuser_mdi_create_struct_utf16			MDICREATESTRUCT;
typedef struct winuser_multi_key_help_utf16			MULTIKEYHELP;
typedef struct winuser_help_win_info_utf16			HELPWININFO;
typedef struct winuser_non_client_metrics_utf16			NONCLIENTMETRICS;
typedef struct winuser_icon_metrics_utf16			ICONMETRICS;
typedef struct winuser_serial_keys_utf16			SERIALKEYS;
typedef struct winuser_high_contrast_utf16			HIGHCONTRAST;
typedef struct winuser_sounds_entry_utf16			SOUNDSENTRY;
typedef struct winuser_monitor_info_ex_utf16			MONITORINFOEX;
#endif




typedef int __stdcall w32api_user_wvsprintf_ansi(
	LPSTR,
	LPCSTR,
	va_list);

typedef int __stdcall w32api_user_wvsprintf_utf8(
	LPSTR,
	LPCSTR,
	va_list);

typedef int __stdcall w32api_user_wvsprintf_utf16(
	LPWSTR,
	LPCWSTR,
	va_list);

typedef int __cdecl w32api_user_wsprintf_ansi(
	LPSTR,
	LPCSTR,
	...);

typedef int __cdecl w32api_user_wsprintf_utf8(
	LPSTR,
	LPCSTR,
	...);

typedef int __cdecl w32api_user_wsprintf_utf16(
	LPWSTR,
	LPCWSTR,
	...);

typedef HKL __stdcall w32api_user_load_keyboard_layout_ansi(
	LPCSTR,
	UINT);
	
typedef HKL __stdcall w32api_user_load_keyboard_layout_utf8(
	LPCSTR,
	UINT);

typedef HKL __stdcall w32api_user_load_keyboard_layout_utf16(
	LPCWSTR,
	UINT);

typedef HKL __stdcall w32api_user_activate_keyboard_layout(
	HKL,
	UINT);

typedef int __stdcall w32api_user_to_unicode_ex(
	UINT,
	UINT,
	const BYTE *,
	LPWSTR,
	int,
	UINT,
	HKL);

typedef BOOL __stdcall w32api_user_unload_keyboard_layout(
	HKL);

typedef BOOL __stdcall w32api_user_get_keyboard_layout_name_ansi(
	LPSTR);

typedef BOOL __stdcall w32api_user_get_keyboard_layout_name_utf8(
	LPSTR);

typedef BOOL __stdcall w32api_user_get_keyboard_layout_name_utf16(
	LPWSTR);

typedef int __stdcall w32api_user_get_keyboard_layout_list(
	int,
	HKL *);

typedef HKL __stdcall w32api_user_get_keyboard_layout(
	DWORD);

typedef int __stdcall w32api_user_get_mouse_move_points_ex(
	UINT,
	LPMOUSEMOVEPOINT,
	LPMOUSEMOVEPOINT,
	int,
	DWORD);

typedef HDESK __stdcall w32api_user_create_desktop_ansi(
	LPCSTR,
	LPCSTR,
	LPDEVMODEA,
	DWORD,
	ACCESS_MASK,
	LPSECURITY_ATTRIBUTES);

typedef HDESK __stdcall w32api_user_create_desktop_utf8(
	LPCSTR,
	LPCSTR,
	LPDEVMODEM,
	DWORD,
	ACCESS_MASK,
	LPSECURITY_ATTRIBUTES);

typedef HDESK __stdcall w32api_user_create_desktop_utf16(
	LPCWSTR,
	LPCWSTR,
	LPDEVMODEW,
	DWORD,
	ACCESS_MASK,
	LPSECURITY_ATTRIBUTES);

typedef HDESK __stdcall w32api_user_create_desktop_ex_ansi(
	LPCSTR,
	LPCSTR,
	DEVMODEA *,
	DWORD,
	ACCESS_MASK,
	LPSECURITY_ATTRIBUTES,
	ULONG,
	PVOID);

typedef HDESK __stdcall w32api_user_create_desktop_ex_utf8(
	LPCSTR,
	LPCSTR,
	DEVMODEM *,
	DWORD,
	ACCESS_MASK,
	LPSECURITY_ATTRIBUTES,
	ULONG,
	PVOID);


typedef HDESK __stdcall w32api_user_create_desktop_ex_utf16(
	LPCWSTR,
	LPCWSTR,
	DEVMODEW *,
	DWORD,
	ACCESS_MASK,
	LPSECURITY_ATTRIBUTES,
	ULONG,
	PVOID);

typedef HDESK __stdcall w32api_user_open_desktop_ansi(
	LPCSTR,
	DWORD,
	BOOL,
	ACCESS_MASK);

typedef HDESK __stdcall w32api_user_open_desktop_utf8(
	LPCSTR,
	DWORD,
	BOOL,
	ACCESS_MASK);

typedef HDESK __stdcall w32api_user_open_desktop_utf16(
	LPCWSTR,
	DWORD,
	BOOL,
	ACCESS_MASK);

typedef HDESK __stdcall w32api_user_open_input_desktop(
	DWORD,
	BOOL,
	ACCESS_MASK);

typedef BOOL __stdcall w32api_user_enum_desktops_ansi(
	HWINSTA,
	DESKTOPENUMPROCA,
	LPARAM);

typedef BOOL __stdcall w32api_user_enum_desktops_utf8(
	HWINSTA,
	DESKTOPENUMPROCM,
	LPARAM);

typedef BOOL __stdcall w32api_user_enum_desktops_utf16(
	HWINSTA,
	DESKTOPENUMPROCW,
	LPARAM);

typedef BOOL __stdcall w32api_user_enum_desktop_windows(
	HDESK,
	WNDENUMPROC,
	LPARAM);

typedef BOOL __stdcall w32api_user_switch_desktop(
	HDESK);

typedef BOOL __stdcall w32api_user_set_thread_desktop(
	HDESK);

typedef BOOL __stdcall w32api_user_close_desktop(
	HDESK);

typedef HDESK __stdcall w32api_user_get_thread_desktop(
	DWORD);

typedef HWINSTA __stdcall w32api_user_create_window_station_ansi(
	LPCSTR,
	DWORD,
	ACCESS_MASK,
	LPSECURITY_ATTRIBUTES);

typedef HWINSTA __stdcall w32api_user_create_window_station_utf8(
	LPCSTR,
	DWORD,
	ACCESS_MASK,
	LPSECURITY_ATTRIBUTES);

typedef HWINSTA __stdcall w32api_user_create_window_station_utf16(
	LPCWSTR,
	DWORD,
	ACCESS_MASK,
	LPSECURITY_ATTRIBUTES);

typedef HWINSTA __stdcall w32api_user_open_window_station_ansi(
	LPCSTR,
	BOOL,
	ACCESS_MASK);

typedef HWINSTA __stdcall w32api_user_open_window_station_utf8(
	LPCSTR,
	BOOL,
	ACCESS_MASK);

typedef HWINSTA __stdcall w32api_user_open_window_station_utf16(
	LPCWSTR,
	BOOL,
	ACCESS_MASK);

typedef BOOL __stdcall w32api_user_enum_window_stations_ansi(
	WINSTAENUMPROCA,
	LPARAM);

typedef BOOL __stdcall w32api_user_enum_window_stations_utf8(
	WINSTAENUMPROCM,
	LPARAM);
	
typedef BOOL __stdcall w32api_user_enum_window_stations_utf16(
	WINSTAENUMPROCW,
	LPARAM);

typedef BOOL __stdcall w32api_user_close_window_station(
	HWINSTA);

typedef BOOL __stdcall w32api_user_set_process_window_station(
	HWINSTA);

typedef HWINSTA __stdcall w32api_user_get_process_window_station(
	void);

typedef BOOL __stdcall w32api_user_set_user_object_security(
	HANDLE,
	PSECURITY_INFORMATION,
	PSECURITY_DESCRIPTOR);

typedef BOOL __stdcall w32api_user_get_user_object_security(
	HANDLE,
	PSECURITY_INFORMATION,
	PSECURITY_DESCRIPTOR,
	DWORD,
	LPDWORD);

typedef BOOL __stdcall w32api_user_get_user_object_information_ansi(
	HANDLE,
	int,
	PVOID,
	DWORD,
	LPDWORD);
	
typedef BOOL __stdcall w32api_user_get_user_object_information_utf8(
	HANDLE,
	int,
	PVOID,
	DWORD,
	LPDWORD);

typedef BOOL __stdcall w32api_user_get_user_object_information_utf16(
	HANDLE,
	int,
	PVOID,
	DWORD,
	LPDWORD);

typedef BOOL __stdcall w32api_user_set_user_object_information_ansi(
	HANDLE,
	int,
	PVOID,
	DWORD);

typedef BOOL __stdcall w32api_user_set_user_object_information_utf8(
	HANDLE,
	int,
	PVOID,
	DWORD);

typedef BOOL __stdcall w32api_user_set_user_object_information_utf16(
	HANDLE,
	int,
	PVOID,
	DWORD);

typedef BOOL __stdcall w32api_user_is_hung_app_window(
	HWND);

typedef void __stdcall w32api_user_disable_process_windows_ghosting(
	void);

typedef BOOL __stdcall w32api_user_get_scroll_bar_info(
	HWND,
	LONG,
	PSCROLLBARINFO);

typedef UINT __stdcall w32api_user_register_window_Message_ansi(
	LPCSTR);

typedef UINT __stdcall w32api_user_register_window_message_utf8(
	LPCSTR);

typedef UINT __stdcall w32api_user_register_window_message_utf16(
	LPCWSTR);

typedef BOOL __stdcall w32api_user_track_mouse_event(
	LPTRACKMOUSEEVENT);

typedef BOOL __stdcall w32api_user_draw_edge(
	HDC,
	LPRECT,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_draw_frame_control(
	HDC,
	LPRECT,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_draw_caption(
	HWND,
	HDC,
	const RECT *,
	UINT);

typedef BOOL __stdcall w32api_user_draw_animated_rects(
	HWND,
	int,
	const RECT *,
	const RECT *);

typedef BOOL __stdcall w32api_user_get_message_ansi(
	LPMSG,
	HWND,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_get_message_utf8(
	LPMSG,
	HWND,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_get_message_utf16(
	LPMSG,
	HWND,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_translate_message(
	const MSG *);

typedef LRESULT __stdcall w32api_user_dispatch_message_ansi(
	const MSG *);

typedef LRESULT __stdcall w32api_user_dispatch_message_utf8(
	const MSG *);

typedef LRESULT __stdcall w32api_user_dispatch_message_utf16(
	const MSG *);

typedef BOOL __stdcall w32api_user_set_message_queue(
	int);

typedef BOOL __stdcall w32api_user_peek_message_ansi(
	LPMSG,
	HWND,
	UINT,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_peek_message_utf8(
	LPMSG,
	HWND,
	UINT,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_peek_message_utf16(
	LPMSG,
	HWND,
	UINT,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_register_hot_key(
	HWND,
	int,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_unregister_hot_key(
	HWND,
	int);

typedef BOOL __stdcall w32api_user_exit_windows_ex(
	UINT,
	DWORD);

typedef BOOL __stdcall w32api_user_swap_mouse_button(
	BOOL);

typedef DWORD __stdcall w32api_user_get_message_pos(
	void);

typedef LONG __stdcall w32api_user_get_message_time(
	void);

typedef LPARAM __stdcall w32api_user_get_message_extra_info(
	void);

typedef DWORD __stdcall w32api_user_get_unpredicted_message_pos(
	void);

typedef BOOL __stdcall w32api_user_is_wow64_message(
	void);

typedef LPARAM __stdcall w32api_user_set_message_extra_info(
	LPARAM);

typedef LRESULT __stdcall w32api_user_send_message_ansi(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_send_message_utf8(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_send_message_utf16(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_send_message_timeout_ansi(
	HWND,
	UINT,
	WPARAM,
	LPARAM,
	UINT,
	UINT,
	PDWORD_PTR);
	
typedef LRESULT __stdcall w32api_user_send_message_timeout_utf8(
	HWND,
	UINT,
	WPARAM,
	LPARAM,
	UINT,
	UINT,
	PDWORD_PTR);

typedef LRESULT __stdcall w32api_user_send_message_timeout_utf16(
	HWND,
	UINT,
	WPARAM,
	LPARAM,
	UINT,
	UINT,
	PDWORD_PTR);

typedef BOOL __stdcall w32api_user_send_notify_message_ansi(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef BOOL __stdcall w32api_user_send_notify_message_utf8(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef BOOL __stdcall w32api_user_send_notify_message_utf16(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef BOOL __stdcall w32api_user_send_message_callback_ansi(
	HWND,
	UINT,
	WPARAM,
	LPARAM,
	SENDASYNCPROC,
	ULONG_PTR);

typedef BOOL __stdcall w32api_user_send_message_callback_utf8(
	HWND,
	UINT,
	WPARAM,
	LPARAM,
	SENDASYNCPROC,
	ULONG_PTR);

typedef BOOL __stdcall w32api_user_send_message_callback_utf16(
	HWND,
	UINT,
	WPARAM,
	LPARAM,
	SENDASYNCPROC,
	ULONG_PTR);

typedef LONG __stdcall w32api_user_broadcast_system_message_ex_ansi(
	DWORD,
	LPDWORD,
	UINT,
	WPARAM,
	LPARAM,
	PBSMINFO);

typedef LONG __stdcall w32api_user_broadcast_system_message_ex_utf8(
	DWORD,
	LPDWORD,
	UINT,
	WPARAM,
	LPARAM,
	PBSMINFO);

typedef LONG __stdcall w32api_user_broadcast_system_message_ex_utf16(
	DWORD,
	LPDWORD,
	UINT,
	WPARAM,
	LPARAM,
	PBSMINFO);

typedef LONG __stdcall w32api_user_broadcast_system_message_ansi(
	DWORD,
	LPDWORD,
	UINT,
	WPARAM,
	LPARAM);

typedef LONG __stdcall w32api_user_broadcast_system_message_utf8(
	DWORD,
	LPDWORD,
	UINT,
	WPARAM,
	LPARAM);

typedef LONG __stdcall w32api_user_broadcast_system_message_utf16(
	DWORD,
	LPDWORD,
	UINT,
	WPARAM,
	LPARAM);

typedef HPOWERNOTIFY __stdcall w32api_user_register_power_setting_notification(
	HANDLE,
	LPCGUID,
	DWORD);

typedef BOOL __stdcall w32api_user_unregister_power_setting_notification(
	HPOWERNOTIFY);

typedef HPOWERNOTIFY __stdcall w32api_user_register_suspend_resume_notification(
	HANDLE,
	DWORD);

typedef BOOL __stdcall w32api_user_unregister_suspend_resume_notification(
	HPOWERNOTIFY);

typedef BOOL __stdcall w32api_user_post_message_ansi(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef BOOL __stdcall w32api_user_post_message_utf8(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef BOOL __stdcall w32api_user_post_message_utf16(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef BOOL __stdcall w32api_user_post_thread_message_ansi(
	DWORD,
	UINT,
	WPARAM,
	LPARAM);

typedef BOOL __stdcall w32api_user_post_thread_message_utf8(
	DWORD,
	UINT,
	WPARAM,
	LPARAM);

typedef BOOL __stdcall w32api_user_post_thread_message_utf16(
	DWORD,
	UINT,
	WPARAM,
	LPARAM);

typedef BOOL __stdcall w32api_user_attach_thread_input(
	DWORD,
	DWORD,
	BOOL);

typedef BOOL __stdcall w32api_user_reply_message(
	LRESULT);

typedef BOOL __stdcall w32api_user_wait_message(
	void);

typedef DWORD __stdcall w32api_user_wait_for_input_idle(
	HANDLE,
	DWORD);

typedef LRESULT __stdcall w32api_user_def_window_proc_ansi(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_def_window_proc_utf8(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_def_window_proc_utf16(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef void __stdcall w32api_user_post_quit_message(
	int);

typedef BOOL __stdcall w32api_user_in_send_message(
	void);

typedef DWORD __stdcall w32api_user_in_send_message_ex(
	LPVOID);

typedef UINT __stdcall w32api_user_get_double_click_time(
	void);

typedef BOOL __stdcall w32api_user_set_double_click_time(
	UINT);

typedef ATOM __stdcall w32api_user_register_class_ansi(
	const WNDCLASSA *);

typedef ATOM __stdcall w32api_user_register_class_utf8(
	const WNDCLASSM *);

typedef ATOM __stdcall w32api_user_register_class_utf16(
	const WNDCLASSW *);

typedef BOOL __stdcall w32api_user_unregister_class_ansi(
	LPCSTR,
	HINSTANCE);

typedef BOOL __stdcall w32api_user_unregister_class_utf8(
	LPCSTR,
	HINSTANCE);

typedef BOOL __stdcall w32api_user_unregister_class_utf16(
	LPCWSTR,
	HINSTANCE);

typedef BOOL __stdcall w32api_user_get_class_info_ansi(
	HINSTANCE,
	LPCSTR,
	LPWNDCLASSA);

typedef BOOL __stdcall w32api_user_get_class_info_utf8(
	HINSTANCE,
	LPCSTR,
	LPWNDCLASSM);

typedef BOOL __stdcall w32api_user_get_class_info_utf16(
	HINSTANCE,
	LPCWSTR,
	LPWNDCLASSW);

typedef ATOM __stdcall w32api_user_register_class_ex_ansi(
	const WNDCLASSEXA *);

typedef ATOM __stdcall w32api_user_register_class_ex_utf8(
	const WNDCLASSEXM *);

typedef ATOM __stdcall w32api_user_register_class_ex_utf16(
	const WNDCLASSEXW *);

typedef BOOL __stdcall w32api_user_get_class_info_ex_ansi(
	HINSTANCE,
	LPCSTR,
	LPWNDCLASSEXA);

typedef BOOL __stdcall w32api_user_get_class_info_ex_ansi(
	HINSTANCE,
	LPCSTR,
	LPWNDCLASSEXA);

typedef BOOL __stdcall w32api_user_get_class_info_ex_utf8(
	HINSTANCE,
	LPCSTR,
	LPWNDCLASSEXM);

typedef BOOL __stdcall w32api_user_get_class_info_ex_utf16(
	HINSTANCE,
	LPCWSTR,
	LPWNDCLASSEXW);

typedef LRESULT __stdcall w32api_user_call_window_proc_ansi(
	FARPROC,
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_call_window_proc_utf8(
	FARPROC,
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_call_window_proc_utf16(
	FARPROC,
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef HDEVNOTIFY __stdcall w32api_user_register_device_notification_ansi(
	HANDLE,
	LPVOID,
	DWORD);

typedef HDEVNOTIFY __stdcall w32api_user_register_device_notification_utf8(
	HANDLE,
	LPVOID,
	DWORD);

typedef HDEVNOTIFY __stdcall w32api_user_register_device_notification_utf16(
	HANDLE,
	LPVOID,
	DWORD);

typedef BOOL __stdcall w32api_user_unregister_device_notification(
	HDEVNOTIFY);

typedef HWND __stdcall w32api_user_create_window_ex_ansi(
	DWORD,
	LPCSTR,
	LPCSTR,
	DWORD,
	int,
	int,
	int,
	int,
	HWND,
	HMENU,
	HINSTANCE,
	LPVOID);

typedef HWND __stdcall w32api_user_create_window_ex_utf8(DWORD dwExStyle,
	LPCSTR,
	LPCSTR,
	DWORD,
	int,
	int,
	int,
	int,
	HWND,
	HMENU,
	HINSTANCE,
	LPVOID);

typedef HWND __stdcall w32api_user_create_window_ex_utf16(
	DWORD,
	LPCWSTR,
	LPCWSTR,
	DWORD,
	int,
	int,
	int,
	int,
	HWND,
	HMENU,
	HINSTANCE,
	LPVOID);

typedef BOOL __stdcall w32api_user_is_window(
	HWND);

typedef BOOL __stdcall w32api_user_is_menu(
	HMENU);

typedef BOOL __stdcall w32api_user_is_child(
	HWND,
	HWND);

typedef BOOL __stdcall w32api_user_destroy_window(
	HWND);

typedef BOOL __stdcall w32api_user_show_window(
	HWND,
	int);

typedef BOOL __stdcall w32api_user_animate_window(
	HWND,
	DWORD,
	DWORD);

typedef BOOL __stdcall w32api_user_update_layered_window(
	HWND,
	HDC,
	POINT *,
	SIZE *,
	HDC,
	POINT *,
	COLORREF,
	BLENDFUNCTION *,
	DWORD);

typedef BOOL __stdcall w32api_user_update_layered_window_indirect(
	HWND,
	const UPDATELAYEREDWINDOWINFO *);

typedef BOOL __stdcall w32api_user_get_layered_window_attributes(
	HWND,
	COLORREF *,
	BYTE *,
	DWORD *);

typedef BOOL __stdcall w32api_user_print_window(
	HWND,
	HDC,
	UINT);

typedef BOOL __stdcall w32api_user_set_layered_window_attributes(
	HWND,
	COLORREF,
	BYTE,
	DWORD);

typedef BOOL __stdcall w32api_user_show_window_async(
	HWND,
	int);

typedef BOOL __stdcall w32api_user_flash_window(
	HWND,
	BOOL);

typedef BOOL __stdcall w32api_user_flash_window_ex(
	PFLASHWINFO);

typedef BOOL __stdcall w32api_user_show_owned_popups(
	HWND,
	BOOL);

typedef BOOL __stdcall w32api_user_open_icon(
	HWND);

typedef BOOL __stdcall w32api_user_close_window(
	HWND);

typedef BOOL __stdcall w32api_user_move_window(
	HWND,
	int,
	int,
	int,
	int,
	BOOL);

typedef BOOL __stdcall w32api_user_set_window_pos(
	HWND,
	HWND,
	int,
	int,
	int,
	int,
	UINT);

typedef BOOL __stdcall w32api_user_get_window_placement(
	HWND,
	WINDOWPLACEMENT *);

typedef BOOL __stdcall w32api_user_set_window_placement(
	HWND,
	const WINDOWPLACEMENT *);

typedef BOOL __stdcall w32api_user_get_window_display_affinity(
	HWND,
	DWORD *);

typedef BOOL __stdcall w32api_user_set_window_display_affinity(
	HWND,
	DWORD);

typedef HDWP __stdcall w32api_user_begin_defer_window_pos(
	int);

typedef HDWP __stdcall w32api_user_defer_window_pos(
	HDWP,
	HWND,
	HWND,
	int,
	int,
	int,
	int,
	UINT);

typedef BOOL __stdcall w32api_user_end_defer_window_pos(
	HDWP);

typedef BOOL __stdcall w32api_user_is_window_visible(
	HWND);

typedef BOOL __stdcall w32api_user_is_iconic(
	HWND);

typedef BOOL __stdcall w32api_user_any_popup(
	void);

typedef BOOL __stdcall w32api_user_bring_window_to_top(
	HWND);

typedef BOOL __stdcall w32api_user_is_zoomed(
	HWND);

typedef HWND __stdcall w32api_user_create_dialog_param_ansi(
	HINSTANCE,
	LPCSTR,
	HWND,
	DLGPROC,
	LPARAM);

typedef HWND __stdcall w32api_user_create_dialog_param_utf8(
	HINSTANCE,
	LPCSTR,
	HWND,
	DLGPROC,
	LPARAM);

typedef HWND __stdcall w32api_user_create_dialog_param_utf16(
	HINSTANCE,
	LPCWSTR,
	HWND,
	DLGPROC,
	LPARAM);

typedef HWND __stdcall w32api_user_create_dialog_indirect_param_ansi(
	HINSTANCE,
	LPCDLGTEMPLATEA,
	HWND,
	DLGPROC,
	LPARAM);

typedef HWND __stdcall w32api_user_create_dialog_indirect_param_utf8(
	HINSTANCE,
	LPCDLGTEMPLATEM,
	HWND,
	DLGPROC,
	LPARAM);

typedef HWND __stdcall w32api_user_create_dialog_indirect_param_utf16(
	HINSTANCE,
	LPCDLGTEMPLATEW,
	HWND,
	DLGPROC,
	LPARAM);

typedef INT_PTR __stdcall w32api_user_dialog_box_param_ansi(
	HINSTANCE,
	LPCSTR,
	HWND,
	DLGPROC,
	LPARAM);

typedef INT_PTR __stdcall w32api_user_dialog_box_param_utf8(
	HINSTANCE,
	LPCSTR,
	HWND,
	DLGPROC,
	LPARAM);

typedef INT_PTR __stdcall w32api_user_dialog_box_param_utf16(
	HINSTANCE,
	LPCWSTR,
	HWND,
	DLGPROC,
	LPARAM);

typedef INT_PTR __stdcall w32api_user_dialog_box_indirect_param_ansi(
	HINSTANCE,
	LPCDLGTEMPLATEA,
	HWND,
	DLGPROC,
	LPARAM);

typedef INT_PTR __stdcall w32api_user_dialog_box_indirect_param_utf8(
	HINSTANCE,
	LPCDLGTEMPLATEM,
	HWND,
	DLGPROC,
	LPARAM);

typedef INT_PTR __stdcall w32api_user_dialog_box_indirect_param_utf16(
	HINSTANCE,
	LPCDLGTEMPLATEW,
	HWND,
	DLGPROC,
	LPARAM);

typedef BOOL __stdcall w32api_user_end_dialog(
	HWND,
	INT_PTR);

typedef HWND __stdcall w32api_user_get_dlg_item(
	HWND,
	int);

typedef BOOL __stdcall w32api_user_set_dlg_item_int(
	HWND,
	int,
	UINT,
	BOOL);

typedef UINT __stdcall w32api_user_get_dlg_item_int(
	HWND,
	int,
	BOOL *,
	BOOL);

typedef BOOL __stdcall w32api_user_set_dlg_item_text_ansi(
	HWND,
	int,
	LPCSTR);

typedef BOOL __stdcall w32api_user_set_dlg_item_text_utf8(
	HWND,
	int,
	LPCSTR);

typedef BOOL __stdcall w32api_user_set_dlg_item_text_utf16(
	HWND,
	int,
	LPCWSTR);

typedef UINT __stdcall w32api_user_get_dlg_item_text_ansi(
	HWND,
	int,
	LPSTR,
	int);

typedef UINT __stdcall w32api_user_get_dlg_item_text_utf8(
	HWND,
	int,
	LPSTR,
	int);

typedef UINT __stdcall w32api_user_get_dlg_item_text_utf16(
	HWND,
	int,
	LPWSTR,
	int);

typedef BOOL __stdcall w32api_user_check_dlg_button(
	HWND,
	int,
	UINT);

typedef BOOL __stdcall w32api_user_check_radio_button(
	HWND,
	int,
	int,
	int);

typedef UINT __stdcall w32api_user_is_dlg_button_checked(
	HWND,
	int);

typedef LRESULT __stdcall w32api_user_send_dlg_item_message_ansi(
	HWND,
	int,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_send_dlg_item_message_utf8(
	HWND,
	int,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_send_dlg_item_message_utf16(
	HWND,
	int,
	UINT,
	WPARAM,
	LPARAM);

typedef HWND __stdcall w32api_user_get_next_dlg_group_item(
	HWND,
	HWND,
	BOOL);

typedef HWND __stdcall w32api_user_get_next_dlg_tab_item(
	HWND,
	HWND,
	BOOL);

typedef int __stdcall w32api_user_get_dlg_ctrl_id(
	HWND);

typedef long __stdcall w32api_user_get_dialog_base_units(
	void);

typedef LRESULT __stdcall w32api_user_def_dlg_proc_ansi(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_def_dlg_proc_utf8(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_def_dlg_proc_utf16(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef BOOL __stdcall w32api_user_call_msg_filter_ansi(
	LPMSG,
	int);

typedef BOOL __stdcall w32api_user_call_msg_filter_utf8(
	LPMSG,
	int);

typedef BOOL __stdcall w32api_user_call_msg_filter_utf16(
	LPMSG,
	int);

typedef BOOL __stdcall w32api_user_open_clipboard(
	HWND);

typedef BOOL __stdcall w32api_user_close_clipboard(
	void);

typedef DWORD __stdcall w32api_user_get_clipboard_sequence_number(
	void);

typedef HWND __stdcall w32api_user_get_clipboard_owner(
	void);

typedef HWND __stdcall w32api_user_set_clipboard_viewer(
	HWND);

typedef HWND __stdcall w32api_user_get_clipboard_viewer(
	void);

typedef BOOL __stdcall w32api_user_change_clipboard_chain(
	HWND,
	HWND);

typedef HANDLE __stdcall w32api_user_set_clipboard_data(
	UINT,
	HANDLE);

typedef HANDLE __stdcall w32api_user_get_clipboard_data(
	UINT);

typedef UINT __stdcall w32api_user_register_clipboard_format_ansi(
	LPCSTR);

typedef UINT __stdcall w32api_user_register_clipboard_format_utf8(
	LPCSTR);

typedef UINT __stdcall w32api_user_register_clipboard_format_utf16(
	LPCWSTR);

typedef int __stdcall w32api_user_count_clipboard_formats(
	void);

typedef UINT __stdcall w32api_user_enum_clipboard_formats(
	UINT);

typedef int __stdcall w32api_user_get_clipboard_format_name_ansi(
	UINT,
	LPSTR,
	int);

typedef int __stdcall w32api_user_get_clipboard_format_name_utf8(
	UINT,
	LPSTR,
	int);

typedef int __stdcall w32api_user_get_clipboard_format_name_utf16(
	UINT,
	LPWSTR,
	int);

typedef BOOL __stdcall w32api_user_empty_clipboard(
	void);

typedef BOOL __stdcall w32api_user_is_clipboard_format_available(
	UINT);

typedef int __stdcall w32api_user_get_priority_clipboard_format(
	UINT *,
	int);

typedef HWND __stdcall w32api_user_get_open_clipboard_window(
	void);

typedef BOOL __stdcall w32api_user_add_clipboard_format_listener(
	HWND);

typedef BOOL __stdcall w32api_user_remove_clipboard_format_listener(
	HWND);

typedef BOOL __stdcall w32api_user_get_updated_clipboard_formats(
	PUINT,
	UINT,
	PUINT);

typedef BOOL __stdcall w32api_user_char_to_oem_ansi(
	LPCSTR,
	LPSTR);

typedef BOOL __stdcall w32api_user_char_to_oem_utf8(
	LPCSTR,
	LPSTR);

typedef BOOL __stdcall w32api_user_char_to_oem_utf16(
	LPCWSTR,
	LPSTR);

typedef BOOL __stdcall w32api_user_oem_to_char_ansi(
	LPCSTR,
	LPSTR);

typedef BOOL __stdcall w32api_user_oem_to_char_utf8(
	LPCSTR,
	LPSTR);

typedef BOOL __stdcall w32api_user_oem_to_char_utf16(
	LPCSTR,
	LPWSTR);

typedef BOOL __stdcall w32api_user_char_to_oem_buff_ansi(
	LPCSTR,
	LPSTR,
	DWORD);

typedef BOOL __stdcall w32api_user_char_to_oem_buff_utf8(
	LPCSTR,
	LPSTR,
	DWORD);

typedef BOOL __stdcall w32api_user_char_to_oem_buff_utf16(
	LPCWSTR,
	LPSTR,
	DWORD);

typedef BOOL __stdcall w32api_user_oem_to_char_buff_ansi(
	LPCSTR,
	LPSTR,
	DWORD);

typedef BOOL __stdcall w32api_user_oem_to_char_buff_utf8(
	LPCSTR,
	LPSTR,
	DWORD);

typedef BOOL __stdcall w32api_user_oem_to_char_buff_utf16(
	LPCSTR,
	LPWSTR,
	DWORD);

typedef LPSTR __stdcall w32api_user_char_upper_ansi(
	LPSTR);

typedef LPSTR __stdcall w32api_user_char_upper_utf8(
	LPSTR);

typedef LPWSTR __stdcall w32api_user_char_upper_utf16(
	LPWSTR);

typedef DWORD __stdcall w32api_user_char_upper_buff_ansi(
	LPSTR,
	DWORD);

typedef DWORD __stdcall w32api_user_char_upper_buff_utf8(
	LPSTR,
	DWORD);

typedef DWORD __stdcall w32api_user_char_upper_buff_utf16(
	LPWSTR,
	DWORD);

typedef LPSTR __stdcall w32api_user_char_lower_ansi(
	LPSTR);

typedef LPSTR __stdcall w32api_user_char_lower_utf8(
	LPSTR);

typedef LPWSTR __stdcall w32api_user_char_lower_utf16(
	LPWSTR);

typedef DWORD __stdcall w32api_user_char_lower_buff_ansi(
	LPSTR,
	DWORD);

typedef DWORD __stdcall w32api_user_char_lower_buff_utf8(
	LPSTR,
	DWORD);

typedef DWORD __stdcall w32api_user_char_lower_buff_utf16(
	LPWSTR,
	DWORD);

typedef LPSTR __stdcall w32api_user_char_next_ansi(
	LPCSTR);

typedef LPSTR __stdcall w32api_user_char_next_utf8(
	LPCSTR);

typedef LPWSTR __stdcall w32api_user_char_next_utf16(
	LPCWSTR);

typedef LPSTR __stdcall w32api_user_char_prev_ansi(
	LPCSTR,
	LPCSTR);

typedef LPSTR __stdcall w32api_user_char_prev_utf8(
	LPCSTR,
	LPCSTR);

typedef LPWSTR __stdcall w32api_user_char_prev_utf16(
	LPCWSTR,
	LPCWSTR);

typedef LPSTR __stdcall w32api_user_char_next_ex_ansi(
	WORD,
	LPCSTR,
	DWORD);

typedef LPSTR __stdcall w32api_user_char_prev_ex_ansi(
	WORD,
	LPCSTR,
	LPCSTR,
	DWORD);

typedef BOOL __stdcall w32api_user_is_char_alpha_ansi(
	CHAR);

typedef BOOL __stdcall w32api_user_is_char_alpha_utf8(
	CHAR);

typedef BOOL __stdcall w32api_user_is_char_alpha_utf16(
	WCHAR);

typedef BOOL __stdcall w32api_user_is_char_alpha_numeric_ansi(
	CHAR);

typedef BOOL __stdcall w32api_user_is_char_alpha_numeric_utf8(
	CHAR);

typedef BOOL __stdcall w32api_user_is_char_alpha_numeric_utf16(
	WCHAR);

typedef BOOL __stdcall w32api_user_is_char_upper_ansi(
	CHAR);

typedef BOOL __stdcall w32api_user_is_char_upper_utf8(
	CHAR);

typedef BOOL __stdcall w32api_user_is_char_upper_utf16(
	WCHAR);

typedef BOOL __stdcall w32api_user_is_char_lower_ansi(
	CHAR);

typedef BOOL __stdcall w32api_user_is_char_lower_utf8(
	CHAR);

typedef BOOL __stdcall w32api_user_is_char_lower_utf16(
	WCHAR);

typedef HWND __stdcall w32api_user_set_focus(
	HWND);

typedef HWND __stdcall w32api_user_get_active_window(
	void);

typedef HWND __stdcall w32api_user_get_focus(
	void);

typedef UINT __stdcall w32api_user_get_kb_code_page(
	void);

typedef SHORT __stdcall w32api_user_get_key_state(
	int);

typedef SHORT __stdcall w32api_user_get_async_key_state(
	int);

typedef BOOL __stdcall w32api_user_get_keyboard_state(
	PBYTE);

typedef BOOL __stdcall w32api_user_set_keyboard_state(
	LPBYTE);

typedef int __stdcall w32api_user_GetKeyNameText_ansi(
	LONG,
	LPSTR,
	int);

typedef int __stdcall w32api_user_get_key_name_text_utf8(
	LONG,
	LPSTR,
	int);

typedef int __stdcall w32api_user_get_key_name_text_utf16(
	LONG,
	LPWSTR,
	int);

typedef int __stdcall w32api_user_get_keyboard_type(
	int);

typedef int __stdcall w32api_user_to_ascii(
	UINT,
	UINT,
	const BYTE *,
	LPWORD,
	UINT);

typedef int __stdcall w32api_user_to_ascii_ex(
	UINT,
	UINT,
	const BYTE *,
	LPWORD,
	UINT,
	HKL);

typedef int __stdcall w32api_user_to_unicode(
	UINT,
	UINT,
	const BYTE *,
	LPWSTR,
	int,
	UINT);

typedef DWORD __stdcall w32api_user_oem_key_scan(
	WORD);

typedef SHORT __stdcall w32api_user_vk_key_scan_ansi(
	CHAR);

typedef SHORT __stdcall w32api_user_vk_key_scan_utf8(
	CHAR);

typedef SHORT __stdcall w32api_user_vk_key_scan_utf16(
	WCHAR);

typedef SHORT __stdcall w32api_user_vk_key_scan_ex_ansi(
	CHAR,
	HKL);

typedef SHORT __stdcall w32api_user_vk_key_scan_ex_utf8(
	CHAR,
	HKL);

typedef SHORT __stdcall w32api_user_vk_key_scan_ex_utf16(
	WCHAR,
	HKL);

typedef void __stdcall w32api_user_keybd_event(
	BYTE,
	BYTE,
	DWORD,
	ULONG_PTR);

typedef void __stdcall w32api_user_mouse_event(
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	ULONG_PTR);

typedef UINT __stdcall w32api_user_send_input(
	UINT,
	LPINPUT,
	int);

typedef BOOL __stdcall w32api_user_get_touch_input_info(
	HTOUCHINPUT,
	UINT,
	PTOUCHINPUT,
	int);

typedef BOOL __stdcall w32api_user_close_touch_input_handle(
	HTOUCHINPUT);

typedef BOOL __stdcall w32api_user_register_touch_window(
	HWND,
	ULONG);

typedef BOOL __stdcall w32api_user_unregister_touch_window(
	HWND);

typedef BOOL __stdcall w32api_user_is_touch_window(
	HWND,
	PULONG);

typedef BOOL __stdcall w32api_user_initialize_touch_injection(
	UINT32,
	DWORD);

typedef BOOL __stdcall w32api_user_inject_touch_input(
	UINT32,
	const POINTER_TOUCH_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_type(
	UINT32,
	POINTER_INPUT_TYPE *);

typedef BOOL __stdcall w32api_user_get_pointer_cursor_id(
	UINT32,
	UINT32 *);

typedef BOOL __stdcall w32api_user_get_pointer_info(
	UINT32,
	POINTER_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_info_history(
	UINT32,
	UINT32 *,
	POINTER_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_frame_info(
	UINT32,
	UINT32 *,
	POINTER_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_frame_info_history(
	UINT32,
	UINT32 *,
	UINT32 *,
	POINTER_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_touch_info(
	UINT32,
	POINTER_TOUCH_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_touch_info_history(
	UINT32,
	UINT32 *,
	POINTER_TOUCH_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_frame_touch_info(
	UINT32,
	UINT32 *,
	POINTER_TOUCH_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_frame_touch_info_history(
	UINT32,
	UINT32 *,
	UINT32 *,
	POINTER_TOUCH_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_pen_info(
	UINT32,
	POINTER_PEN_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_pen_info_history(
	UINT32,
	UINT32 *,
	POINTER_PEN_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_frame_pen_info(
	UINT32,
	UINT32 *,
	POINTER_PEN_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_frame_pen_info_history(
	UINT32,
	UINT32 *,
	UINT32 *,
	POINTER_PEN_INFO *);

typedef BOOL __stdcall w32api_user_skip_pointer_frame_messages(
	UINT32);

typedef BOOL __stdcall w32api_user_register_pointer_input_target(
	HWND,
	POINTER_INPUT_TYPE);

typedef BOOL __stdcall w32api_user_unregister_pointer_input_target(
	HWND,
	POINTER_INPUT_TYPE);

typedef BOOL __stdcall w32api_user_enable_mouse_in_pointer(
	BOOL);

typedef BOOL __stdcall w32api_user_is_mouse_in_pointer_enabled(
	void);

typedef BOOL __stdcall w32api_user_register_touch_hit_testing_window(
	HWND,
	ULONG);

typedef BOOL __stdcall w32api_user_evaluate_proximity_to_rect(
	const RECT *,
	const TOUCH_HIT_TESTING_INPUT *,
	TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *);

typedef BOOL __stdcall w32api_user_evaluate_proximity_to_polygon(
	UINT32,
	const POINT *,
	const TOUCH_HIT_TESTING_INPUT *,
	TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *);

typedef LRESULT __stdcall w32api_user_pack_touch_hit_testing_proximity_evaluation(
	const TOUCH_HIT_TESTING_INPUT *,
	const TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *);

typedef BOOL __stdcall w32api_user_get_window_feedback_setting(
	HWND,
	FEEDBACK_TYPE,
	DWORD,
	UINT32 *,
	void *);

typedef BOOL __stdcall w32api_user_set_window_feedback_setting(
	HWND,
	FEEDBACK_TYPE,
	DWORD,
	UINT32,
	const void *);

typedef BOOL __stdcall w32api_user_get_last_input_info(
	PLASTINPUTINFO);

typedef UINT __stdcall w32api_user_map_virtual_key_ansi(
	UINT,
	UINT);

typedef UINT __stdcall w32api_user_map_virtual_key_utf8(
	UINT,
	UINT);

typedef UINT __stdcall w32api_user_map_virtual_key_utf16(
	UINT,
	UINT);

typedef UINT __stdcall w32api_user_map_virtual_key_ex_ansi(
	UINT,
	UINT,
	HKL);

typedef UINT __stdcall w32api_user_map_virtual_key_ex_utf8(
	UINT,
	UINT,
	HKL);

typedef UINT __stdcall w32api_user_map_virtual_key_ex_utf16(
	UINT,
	UINT,
	HKL);

typedef BOOL __stdcall w32api_user_get_input_state(
	void);

typedef DWORD __stdcall w32api_user_GetQueueStatus(
	UINT);

typedef HWND __stdcall w32api_user_get_capture(
	void);

typedef HWND __stdcall w32api_user_set_capture(
	HWND);

typedef BOOL __stdcall w32api_user_release_capture(
	void);

typedef DWORD __stdcall w32api_user_msg_wait_for_multiple_objects(
	DWORD,
	const HANDLE *,
	BOOL,
	DWORD,
	DWORD);

typedef DWORD __stdcall w32api_user_msg_wait_for_multiple_objects_ex(
	DWORD,
	const HANDLE *,
	DWORD,
	DWORD,
	DWORD);

typedef UINT_PTR __stdcall w32api_user_set_timer(
	HWND,
	UINT_PTR,
	UINT,
	TIMERPROC);

typedef BOOL __stdcall w32api_user_kill_timer(
	HWND,
	UINT_PTR);

typedef BOOL __stdcall w32api_user_is_window_unicode(
	HWND);

typedef BOOL __stdcall w32api_user_enable_window(
	HWND,
	BOOL);

typedef BOOL __stdcall w32api_user_is_window_enabled(
	HWND);

typedef HACCEL __stdcall w32api_user_load_accelerators_ansi(
	HINSTANCE,
	LPCSTR);

typedef HACCEL __stdcall w32api_user_load_accelerators_utf8(
	HINSTANCE,
	LPCSTR);

typedef HACCEL __stdcall w32api_user_load_accelerators_utf16(
	HINSTANCE,
	LPCWSTR);

typedef HACCEL __stdcall w32api_user_create_accelerator_table_ansi(
	LPACCEL,
	int);

typedef HACCEL __stdcall w32api_user_create_accelerator_table_utf8(
	LPACCEL,
	int);

typedef HACCEL __stdcall w32api_user_create_accelerator_table_utf16(
	LPACCEL,
	int);

typedef BOOL __stdcall w32api_user_destroy_accelerator_table(
	HACCEL);

typedef int __stdcall w32api_user_copy_accelerator_table_ansi(
	HACCEL,
	LPACCEL,
	int);

typedef int __stdcall w32api_user_copy_accelerator_table_utf8(
	HACCEL,
	LPACCEL,
	int);

typedef int __stdcall w32api_user_copy_accelerator_table_utf16(
	HACCEL,
	LPACCEL,
	int);

typedef int __stdcall w32api_user_translate_accelerator_ansi(
	HWND,
	HACCEL,
	LPMSG);

typedef int __stdcall w32api_user_translate_accelerator_utf8(
	HWND,
	HACCEL,
	LPMSG);

typedef int __stdcall w32api_user_translate_accelerator_utf16(
	HWND,
	HACCEL,
	LPMSG);

typedef UINT_PTR __stdcall w32api_user_set_coalescable_timer(
	HWND,
	UINT_PTR,
	UINT,
	TIMERPROC,
	ULONG);

typedef int __stdcall w32api_user_get_system_metrics(
	int);

typedef HMENU __stdcall w32api_user_load_menu_ansi(
	HINSTANCE,
	LPCSTR);

typedef HMENU __stdcall w32api_user_load_menu_utf8(
	HINSTANCE,
	LPCSTR);

typedef HMENU __stdcall w32api_user_load_menu_utf16(
	HINSTANCE,
	LPCWSTR);

typedef HMENU __stdcall w32api_user_load_menu_indirect_ansi(
	const MENUTEMPLATEA *);

typedef HMENU __stdcall w32api_user_load_menu_indirect_utf8(
	const MENUTEMPLATEM *);

typedef HMENU __stdcall w32api_user_load_menu_indirect_utf16(
	const MENUTEMPLATEW *);

typedef HMENU __stdcall w32api_user_get_menu(
	HWND);

typedef BOOL __stdcall w32api_user_set_menu(
	HWND,
	HMENU);

typedef BOOL __stdcall w32api_user_change_menu_ansi(
	HMENU,
	UINT,
	LPCSTR,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_change_menu_utf8(
	HMENU,
	UINT,
	LPCSTR,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_change_menu_utf16(
	HMENU,
	UINT,
	LPCWSTR,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_hilite_menu_item(
	HWND,
	HMENU,
	UINT,
	UINT);

typedef int __stdcall w32api_user_get_menu_string_ansi(
	HMENU,
	UINT,
	LPSTR,
	int,
	UINT);

typedef int __stdcall w32api_user_get_menu_string_utf8(
	HMENU,
	UINT,
	LPSTR,
	int,
	UINT);

typedef int __stdcall w32api_user_get_menu_string_utf16(
	HMENU,
	UINT,
	LPWSTR,
	int,
	UINT);

typedef UINT __stdcall w32api_user_get_menu_state(
	HMENU,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_draw_menu_bar(
	HWND);

typedef HMENU __stdcall w32api_user_get_system_menu(
	HWND,
	BOOL);

typedef HMENU __stdcall w32api_user_create_menu(
	void);

typedef HMENU __stdcall w32api_user_create_popup_menu(
	void);

typedef BOOL __stdcall w32api_user_destroy_menu(
	HMENU);

typedef DWORD __stdcall w32api_user_check_menu_item(
	HMENU,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_enable_menu_item(
	HMENU,
	UINT,
	UINT);

typedef HMENU __stdcall w32api_user_get_sub_menu(
	HMENU,
	int);

typedef UINT __stdcall w32api_user_get_menu_item_id(
	HMENU,
	int);

typedef int __stdcall w32api_user_get_menu_item_count(
	HMENU);

typedef BOOL __stdcall w32api_user_insert_menu_ansi(
	HMENU,
	UINT,
	UINT,
	UINT_PTR,
	LPCSTR);

typedef BOOL __stdcall w32api_user_insert_menu_utf8(
	HMENU,
	UINT,
	UINT,
	UINT_PTR,
	LPCSTR);

typedef BOOL __stdcall w32api_user_insert_menu_utf16(
	HMENU,
	UINT,
	UINT,
	UINT_PTR,
	LPCWSTR);

typedef BOOL __stdcall w32api_user_append_menu_ansi(
	HMENU,
	UINT,
	UINT_PTR,
	LPCSTR);

typedef BOOL __stdcall w32api_user_append_menu_utf8(
	HMENU,
	UINT,
	UINT_PTR,
	LPCSTR);

typedef BOOL __stdcall w32api_user_append_menu_utf16(
	HMENU,
	UINT,
	UINT_PTR,
	LPCWSTR);

typedef BOOL __stdcall w32api_user_modify_menu_ansi(
	HMENU,
	UINT,
	UINT,
	UINT_PTR,
	LPCSTR);

typedef BOOL __stdcall w32api_user_modify_menu_utf8(
	HMENU,
	UINT,
	UINT,
	UINT_PTR,
	LPCSTR);

typedef BOOL __stdcall w32api_user_modify_menu_utf16(
	HMENU,
	UINT,
	UINT,
	UINT_PTR,
	LPCWSTR);

typedef BOOL __stdcall w32api_user_remove_menu(
	HMENU,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_delete_menu(
	HMENU,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_set_menu_item_bitmaps(
	HMENU,
	UINT,
	UINT,
	HBITMAP,
	HBITMAP);

typedef LONG __stdcall w32api_user_get_menu_check_mark_dimensions(
	void);

typedef BOOL __stdcall w32api_user_track_popup_menu(
	HMENU,
	UINT,
	int,
	int,
	int,
	HWND,
	const RECT *);

typedef BOOL __stdcall w32api_user_track_popup_menu_ex(
	HMENU,
	UINT,
	int,
	int,
	HWND,
	LPTPMPARAMS);

typedef BOOL __stdcall w32api_user_get_menu_info(
	HMENU,
	LPMENUINFO);

typedef BOOL __stdcall w32api_user_set_menu_info(
	HMENU,
	LPCMENUINFO);

typedef BOOL __stdcall w32api_user_end_menu(
	void);

typedef BOOL __stdcall w32api_user_calculate_popup_window_position(
	const POINT *,
	const SIZE *,
	UINT,
	RECT *,
	RECT *);

typedef BOOL __stdcall w32api_user_insert_menu_item_ansi(
	HMENU,
	UINT,
	BOOL,
	LPCMENUITEMINFOA);

typedef BOOL __stdcall w32api_user_insert_menu_item_utf8(
	HMENU,
	UINT,
	BOOL,
	LPCMENUITEMINFOM);

typedef BOOL __stdcall w32api_user_insert_menu_item_utf16(
	HMENU,
	UINT,
	BOOL,
	LPCMENUITEMINFOW);

typedef BOOL __stdcall w32api_user_get_menu_item_info_ansi(
	HMENU,
	UINT,
	BOOL,
	LPMENUITEMINFOA);

typedef BOOL __stdcall w32api_user_get_menu_item_info_utf8(
	HMENU,
	UINT,
	BOOL,
	LPMENUITEMINFOM);

typedef BOOL __stdcall w32api_user_get_menu_item_info_utf16(
	HMENU,
	UINT,
	BOOL,
	LPMENUITEMINFOW);

typedef BOOL __stdcall w32api_user_set_menu_item_info_ansi(
	HMENU,
	UINT,
	BOOL,
	LPCMENUITEMINFOA);

typedef BOOL __stdcall w32api_user_set_menu_item_info_utf8(
	HMENU,
	UINT,
	BOOL,
	LPCMENUITEMINFOM);

typedef BOOL __stdcall w32api_user_set_menu_item_info_utf16(
	HMENU,
	UINT,
	BOOL,
	LPCMENUITEMINFOW);

typedef UINT __stdcall w32api_user_get_menu_default_item(
	HMENU,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_set_menu_default_item(
	HMENU,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_get_menu_item_rect(
	HWND,
	HMENU,
	UINT,
	LPRECT);

typedef int __stdcall w32api_user_menu_item_from_point(
	HWND,
	HMENU,
	POINT);

typedef DWORD __stdcall w32api_user_drag_object(
	HWND,
	HWND,
	UINT,
	ULONG_PTR,
	HCURSOR);

typedef BOOL __stdcall w32api_user_drag_detect(
	HWND,
	POINT);

typedef BOOL __stdcall w32api_user_draw_icon(
	HDC,
	int,
	int,
	HICON);

typedef int __stdcall w32api_user_draw_text_ansi(
	HDC,
	LPCSTR,
	int,
	LPRECT,
	UINT);

typedef int __stdcall w32api_user_draw_text_utf8(
	HDC,
	LPCSTR,
	int,
	LPRECT,
	UINT);

typedef int __stdcall w32api_user_draw_text_utf16(
	HDC,
	LPCWSTR,
	int,
	LPRECT,
	UINT);

typedef int __stdcall w32api_user_draw_text_ex_ansi(
	HDC,
	LPSTR,
	int,
	LPRECT,
	UINT,
	LPDRAWTEXTPARAMS);

typedef int __stdcall w32api_user_draw_text_ex_utf8(
	HDC,
	LPSTR,
	int,
	LPRECT,
	UINT,
	LPDRAWTEXTPARAMS);

typedef int __stdcall w32api_user_draw_text_ex_utf16(
	HDC,
	LPWSTR,
	int,
	LPRECT,
	UINT,
	LPDRAWTEXTPARAMS);

typedef BOOL __stdcall w32api_user_gray_string_ansi(
	HDC,
	HBRUSH,
	GRAYSTRINGPROC,
	LPARAM,
	int,
	int,
	int,
	int,
	int);

typedef BOOL __stdcall w32api_user_gray_string_utf8(
	HDC,
	HBRUSH,
	GRAYSTRINGPROC,
	LPARAM,
	int,
	int,
	int,
	int,
	int);

typedef BOOL __stdcall w32api_user_gray_string_utf16(
	HDC,
	HBRUSH,
	GRAYSTRINGPROC,
	LPARAM,
	int,
	int,
	int,
	int,
	int);

typedef BOOL __stdcall w32api_user_draw_state_ansi(
	HDC,
	HBRUSH,
	DRAWSTATEPROC,
	LPARAM,
	WPARAM,
	int,
	int,
	int,
	int,
	UINT);

typedef BOOL __stdcall w32api_user_draw_state_utf8(
	HDC,
	HBRUSH,
	DRAWSTATEPROC,
	LPARAM,
	WPARAM,
	int,
	int,
	int,
	int,
	UINT);

typedef BOOL __stdcall w32api_user_draw_state_utf16(
	HDC,
	HBRUSH,
	DRAWSTATEPROC,
	LPARAM,
	WPARAM,
	int,
	int,
	int,
	int,
	UINT);

typedef LONG __stdcall w32api_user_tabbed_text_out_ansi(HDC,
	int x,
	int y,
	LPCSTR,
	int,
	int,
	const INT *,
	int);

typedef LONG __stdcall w32api_user_tabbed_text_out_utf8(
	HDC,
	int,
	int,
	LPCSTR,
	int,
	int,
	const INT *,
	int);

typedef LONG __stdcall w32api_user_tabbed_text_out_utf16(
	HDC,
	int,
	int,
	LPCWSTR,
	int,
	int,
	const INT *,
	int);

typedef DWORD __stdcall w32api_user_get_tabbed_text_extent_ansi(
	HDC,
	LPCSTR,
	int,
	int,
	const INT *);

typedef DWORD __stdcall w32api_user_get_tabbed_text_extent_utf8(
	HDC,
	LPCSTR,
	int,
	int,
	const INT *);

typedef DWORD __stdcall w32api_user_get_tabbed_text_extent_utf16(
	HDC,
	LPCWSTR,
	int,
	int,
	const INT *);

typedef BOOL __stdcall w32api_user_update_window(
	HWND);

typedef HWND __stdcall w32api_user_set_active_window(
	HWND);

typedef HWND __stdcall w32api_user_get_foreground_window(
	void);

typedef BOOL __stdcall w32api_user_paint_desktop(
	HDC);

typedef void __stdcall w32api_user_switch_to_this_window(
	HWND,
	BOOL);

typedef BOOL __stdcall w32api_user_SetForegroundWindow(
	HWND);

typedef BOOL __stdcall w32api_user_allow_set_foreground_window(
	DWORD);

typedef BOOL __stdcall w32api_user_lock_set_foreground_window(
	UINT);

typedef HWND __stdcall w32api_user_window_from_dc(
	HDC);

typedef HDC __stdcall w32api_user_get_dc(
	HWND);

typedef HDC __stdcall w32api_user_get_dc_ex(
	HWND,
	HRGN,
	DWORD);

typedef HDC __stdcall w32api_user_get_window_dc(
	HWND);

typedef int __stdcall w32api_user_release_dc(
	HWND,
	HDC);

typedef HDC __stdcall w32api_user_begin_paint(
	HWND,
	LPPAINTSTRUCT);

typedef BOOL __stdcall w32api_user_end_paint(
	HWND,
	const PAINTSTRUCT *);

typedef BOOL __stdcall w32api_user_get_update_rect(
	HWND,
	LPRECT,
	BOOL);

typedef int __stdcall w32api_user_get_update_rgn(
	HWND,
	HRGN,
	BOOL);

typedef int __stdcall w32api_user_set_window_rgn(
	HWND,
	HRGN,
	BOOL);

typedef int __stdcall w32api_user_get_window_rgn(
	HWND,
	HRGN);

typedef int __stdcall w32api_user_get_window_rgn_box(
	HWND,
	LPRECT);

typedef int __stdcall w32api_user_exclude_update_rgn(
	HDC,
	HWND);

typedef BOOL __stdcall w32api_user_invalidate_rect(
	HWND,
	const RECT *,
	BOOL);

typedef BOOL __stdcall w32api_user_validate_rect(
	HWND,
	const RECT *);

typedef BOOL __stdcall w32api_user_invalidate_rgn(
	HWND,
	HRGN,
	BOOL);

typedef BOOL __stdcall w32api_user_validate_rgn(
	HWND,
	HRGN);

typedef BOOL __stdcall w32api_user_redraw_window(
	HWND,
	const RECT *,
	HRGN,
	UINT);

typedef BOOL __stdcall w32api_user_lock_window_update(
	HWND);

typedef BOOL __stdcall w32api_user_scroll_window(
	HWND,
	int,
	int,
	const RECT *,
	const RECT *);

typedef BOOL __stdcall w32api_user_scroll_dc(
	HDC,
	int,
	int,
	const RECT *,
	const RECT *,
	HRGN,
	LPRECT);

typedef int __stdcall w32api_user_scroll_window_ex(
	HWND,
	int,
	int,
	const RECT *,
	const RECT *,
	HRGN,
	LPRECT,
	UINT);

typedef int __stdcall w32api_user_set_scroll_pos(
	HWND,
	int,
	int,
	BOOL);

typedef int __stdcall w32api_user_get_scroll_pos(
	HWND,
	int);

typedef BOOL __stdcall w32api_user_set_scroll_range(
	HWND,
	int,
	int,
	int,
	BOOL);

typedef BOOL __stdcall w32api_user_get_scroll_range(
	HWND,
	int,
	LPINT,
	LPINT);

typedef BOOL __stdcall w32api_user_show_scroll_bar(
	HWND,
	int,
	BOOL);

typedef BOOL __stdcall w32api_user_enable_scroll_bar(
	HWND,
	UINT,
	UINT);

typedef BOOL __stdcall w32api_user_set_prop_ansi(
	HWND,
	LPCSTR,
	HANDLE);

typedef BOOL __stdcall w32api_user_set_prop_utf8(
	HWND,
	LPCSTR,
	HANDLE);

typedef BOOL __stdcall w32api_user_set_prop_utf16(
	HWND,
	LPCWSTR,
	HANDLE);

typedef HANDLE __stdcall w32api_user_get_prop_ansi(
	HWND,
	LPCSTR);

typedef HANDLE __stdcall w32api_user_get_prop_utf8(
	HWND,
	LPCSTR);

typedef HANDLE __stdcall w32api_user_get_prop_utf16(
	HWND,
	LPCWSTR);

typedef HANDLE __stdcall w32api_user_remove_prop_ansi(
	HWND,
	LPCSTR);

typedef HANDLE __stdcall w32api_user_remove_prop_utf8(
	HWND,
	LPCSTR);

typedef HANDLE __stdcall w32api_user_remove_prop_utf16(
	HWND,
	LPCWSTR);

typedef int __stdcall w32api_user_enum_props_ex_ansi(
	HWND,
	PROPENUMPROCEXA,
	LPARAM);

typedef int __stdcall w32api_user_enum_props_ex_utf8(
	HWND,
	PROPENUMPROCEXM,
	LPARAM);

typedef int __stdcall w32api_user_enum_props_ex_utf16(
	HWND,
	PROPENUMPROCEXW,
	LPARAM);

typedef int __stdcall w32api_user_enum_props_ansi(
	HWND,
	PROPENUMPROCA);

typedef int __stdcall w32api_user_enum_props_utf8(
	HWND,
	PROPENUMPROCM);

typedef int __stdcall w32api_user_enum_props_utf16(
	HWND,
	PROPENUMPROCW);

typedef BOOL __stdcall w32api_user_set_window_text_ansi(
	HWND,
	LPCSTR);

typedef BOOL __stdcall w32api_user_set_window_text_utf8(
	HWND,
	LPCSTR);

typedef BOOL __stdcall w32api_user_set_window_text_utf16(
	HWND,
	LPCWSTR);

typedef int __stdcall w32api_user_get_window_text_ansi(
	HWND,
	LPSTR,
	int);

typedef int __stdcall w32api_user_get_window_text_utf8(
	HWND,
	LPSTR,
	int);

typedef int __stdcall w32api_user_get_window_text_utf16(
	HWND,
	LPWSTR,
	int);

typedef int __stdcall w32api_user_get_window_text_length_ansi(
	HWND);

typedef int __stdcall w32api_user_get_window_text_length_utf8(
	HWND);

typedef int __stdcall w32api_user_get_window_text_length_utf16(
	HWND);

typedef BOOL __stdcall w32api_user_get_client_rect(
	HWND,
	LPRECT);

typedef BOOL __stdcall w32api_user_get_window_rect(
	HWND,
	LPRECT);

typedef BOOL __stdcall w32api_user_adjust_window_rect(
	LPRECT,
	DWORD,
	BOOL);

typedef BOOL __stdcall w32api_user_adjust_window_rect_ex(
	LPRECT,
	DWORD,
	BOOL,
	DWORD);

typedef BOOL __stdcall w32api_user_set_window_context_help_id(
	HWND,
	DWORD);

typedef DWORD __stdcall w32api_user_get_window_context_help_id(
	HWND);

typedef BOOL __stdcall w32api_user_set_menu_context_help_id(
	HMENU,
	DWORD);

typedef DWORD __stdcall w32api_user_get_menu_context_help_id(
	HMENU);

typedef int __stdcall w32api_user_message_box_ansi(
	HWND,
	LPCSTR,
	LPCSTR,
	UINT);

typedef int __stdcall w32api_user_message_box_utf8(
	HWND,
	LPCSTR,
	LPCSTR,
	UINT);

typedef int __stdcall w32api_user_message_box_utf16(
	HWND,
	LPCWSTR,
	LPCWSTR,
	UINT);

typedef int __stdcall w32api_user_message_box_ex_ansi(
	HWND,
	LPCSTR,
	LPCSTR,
	UINT,
	WORD);

typedef int __stdcall w32api_user_message_box_ex_utf8(
	HWND,
	LPCSTR,
	LPCSTR,
	UINT,
	WORD);

typedef int __stdcall w32api_user_message_box_ex_utf16(
	HWND,
	LPCWSTR,
	LPCWSTR,
	UINT,
	WORD);

typedef int __stdcall w32api_user_message_box_indirect_ansi(
	const MSGBOXPARAMSA *);

typedef int __stdcall w32api_user_message_box_indirect_utf8(
	const MSGBOXPARAMSM *);

typedef int __stdcall w32api_user_message_box_indirect_utf16(
	const MSGBOXPARAMSW *);

typedef BOOL __stdcall w32api_user_message_beep(
	UINT);

typedef int __stdcall w32api_user_show_cursor(
	BOOL);

typedef BOOL __stdcall w32api_user_set_cursor_pos(
	int,
	int);

typedef HCURSOR __stdcall w32api_user_set_cursor(
	HCURSOR);

typedef BOOL __stdcall w32api_user_get_cursor_pos(
	LPPOINT);

typedef BOOL __stdcall w32api_user_clip_cursor(
	const RECT *);

typedef BOOL __stdcall w32api_user_get_clip_cursor(
	LPRECT);

typedef HCURSOR __stdcall w32api_user_get_cursor(
	void);

typedef BOOL __stdcall w32api_user_create_caret(
	HWND,
	HBITMAP,
	int,
	int);

typedef UINT __stdcall w32api_user_get_caret_blink_time(
	void);

typedef BOOL __stdcall w32api_user_set_caret_blink_time(
	UINT);

typedef BOOL __stdcall w32api_user_destroy_caret(
	void);

typedef BOOL __stdcall w32api_user_hide_caret(
	HWND);

typedef BOOL __stdcall w32api_user_show_caret(
	HWND);

typedef BOOL __stdcall w32api_user_set_caret_pos(
	int,
	int);

typedef BOOL __stdcall w32api_user_get_caret_pos(
	LPPOINT);

typedef BOOL __stdcall w32api_user_client_to_screen(
	HWND,
	LPPOINT);

typedef BOOL __stdcall w32api_user_screen_to_client(
	HWND,
	LPPOINT);

typedef int __stdcall w32api_user_map_window_points(
	HWND,
	HWND,
	LPPOINT,
	UINT);

typedef HWND __stdcall w32api_user_window_from_point(
	POINT);

typedef HWND __stdcall w32api_user_child_window_from_point(
	HWND,
	POINT);

typedef HWND __stdcall w32api_user_child_window_from_point_ex(
	HWND,
	POINT,
	UINT);

typedef BOOL __stdcall w32api_user_set_physical_cursor_pos(
	int,
	int);

typedef BOOL __stdcall w32api_user_get_physical_cursor_pos(
	LPPOINT);

typedef BOOL __stdcall w32api_user_logical_to_physical_point(
	HWND,
	LPPOINT);

typedef BOOL __stdcall w32api_user_physical_to_logical_point(
	HWND,
	LPPOINT);

typedef HWND __stdcall w32api_user_window_from_physical_point(
	POINT);

typedef DWORD __stdcall w32api_user_get_sys_color(
	int);

typedef HBRUSH __stdcall w32api_user_get_sys_color_brush(
	int);

typedef BOOL __stdcall w32api_user_set_sys_colors(
	int,
	const INT *,
	const COLORREF *);

typedef BOOL __stdcall w32api_user_draw_focus_rect(
	HDC,
	const RECT *);

typedef int __stdcall w32api_user_fill_rect(
	HDC,
	const RECT *,
	HBRUSH);

typedef int __stdcall w32api_user_frame_rect(
	HDC,
	const RECT *,
	HBRUSH);

typedef BOOL __stdcall w32api_user_invert_rect(
	HDC,
	const RECT *);

typedef BOOL __stdcall w32api_user_set_rect(
	LPRECT,
	int,
	int,
	int,
	int);

typedef BOOL __stdcall w32api_user_set_rect_empty(
	LPRECT);

typedef BOOL __stdcall w32api_user_copy_rect(
	LPRECT,
	const RECT *);

typedef BOOL __stdcall w32api_user_inflate_rect(
	LPRECT,
	int,
	int);

typedef BOOL __stdcall w32api_user_intersect_rect(
	LPRECT,
	const RECT *,
	const RECT *);

typedef BOOL __stdcall w32api_user_union_rect(
	LPRECT,
	const RECT *,
	const RECT *);

typedef BOOL __stdcall w32api_user_subtract_rect(
	LPRECT,
	const RECT *,
	const RECT *);

typedef BOOL __stdcall w32api_user_offset_rect(
	LPRECT,
	int,
	int);

typedef BOOL __stdcall w32api_user_is_rect_empty(
	const RECT *);

typedef BOOL __stdcall w32api_user_equal_rect(
	const RECT *,
	const RECT *);

typedef BOOL __stdcall w32api_user_pt_in_rect(
	const RECT *,
	POINT);

typedef WORD __stdcall w32api_user_get_window_word(
	HWND,
	int);

typedef WORD __stdcall w32api_user_set_window_word(
	HWND,
	int,
	WORD);

typedef LONG __stdcall w32api_user_get_window_long_ansi(
	HWND,
	int);

typedef LONG __stdcall w32api_user_get_window_long_utf8(
	HWND,
	int);

typedef LONG __stdcall w32api_user_get_window_long_utf16(
	HWND,
	int);

typedef LONG __stdcall w32api_user_set_window_long_ansi(
	HWND,
	int,
	LONG);

typedef LONG __stdcall w32api_user_set_window_long_utf8(
	HWND,
	int,
	LONG);

typedef LONG __stdcall w32api_user_set_window_long_utf16(
	HWND,
	int,
	LONG);

typedef WORD __stdcall w32api_user_get_class_word(
	HWND,
	int);

typedef WORD __stdcall w32api_user_set_class_word(
	HWND,
	int,
	WORD);

typedef DWORD __stdcall w32api_user_get_class_long_ansi(
	HWND,
	int);

typedef DWORD __stdcall w32api_user_get_class_long_utf8(
	HWND,
	int);

typedef DWORD __stdcall w32api_user_get_class_long_utf16(
	HWND,
	int);

typedef DWORD __stdcall w32api_user_set_class_long_ansi(
	HWND,
	int,
	LONG);

typedef DWORD __stdcall w32api_user_set_class_long_utf8(
	HWND,
	int,
	LONG);

typedef DWORD __stdcall w32api_user_set_class_long_utf16(
	HWND,
	int,
	LONG);

typedef BOOL __stdcall w32api_user_get_process_default_layout(
	DWORD *);

typedef BOOL __stdcall w32api_user_set_process_default_layout(
	DWORD);

typedef HWND __stdcall w32api_user_get_desktop_window(
	void);

typedef HWND __stdcall w32api_user_get_parent(
	HWND);

typedef HWND __stdcall w32api_user_set_parent(HWND,
	HWND);

typedef BOOL __stdcall w32api_user_enum_child_windows(
	HWND,
	WNDENUMPROC,
	LPARAM);

typedef HWND __stdcall w32api_user_find_window_ansi(
	LPCSTR,
	LPCSTR);

typedef HWND __stdcall w32api_user_find_window_utf8(
	LPCSTR,
	LPCSTR);

typedef HWND __stdcall w32api_user_find_window_utf16(
	LPCWSTR,
	LPCWSTR);

typedef HWND __stdcall w32api_user_find_window_ex_ansi(
	HWND,
	HWND,
	LPCSTR,
	LPCSTR);

typedef HWND __stdcall w32api_user_find_window_ex_utf8(
	HWND,
	HWND,
	LPCSTR,
	LPCSTR);

typedef HWND __stdcall w32api_user_find_window_ex_utf16(
	HWND,
	HWND,
	LPCWSTR,
	LPCWSTR);

typedef HWND __stdcall w32api_user_get_shell_window(
	void);

typedef BOOL __stdcall w32api_user_register_shell_hook_window(
	HWND);

typedef BOOL __stdcall w32api_user_deregister_shell_hook_window(
	HWND);

typedef BOOL __stdcall w32api_user_enum_windows(
	WNDENUMPROC,
	LPARAM);

typedef BOOL __stdcall w32api_user_enum_thread_windows(
	DWORD,
	WNDENUMPROC,
	LPARAM);

typedef int __stdcall w32api_user_get_class_name_ansi(
	HWND,
	LPSTR,
	int);

typedef int __stdcall w32api_user_get_class_name_utf8(
	HWND,
	LPSTR,
	int);

typedef int __stdcall w32api_user_get_class_name_utf16(
	HWND,
	LPWSTR,
	int);

typedef HWND __stdcall w32api_user_get_top_window(
	HWND);

typedef DWORD __stdcall w32api_user_get_window_thread_process_id(
	HWND,
	LPDWORD);

typedef BOOL __stdcall w32api_user_is_gui_thread(
	BOOL);

typedef HWND __stdcall w32api_user_get_last_active_popup(
	HWND);

typedef HWND __stdcall w32api_user_get_window(
	HWND,
	UINT);

typedef HOOKPROC __stdcall w32api_user_set_windows_hook_ansi(
	int,
	HOOKPROC);

typedef HOOKPROC __stdcall w32api_user_set_windows_hook_utf8(
	int,
	HOOKPROC);

typedef HOOKPROC __stdcall w32api_user_set_windows_hook_utf16(
	int,
	HOOKPROC);

typedef BOOL __stdcall w32api_user_unhook_windows_hook(
	int,
	HOOKPROC);

typedef HHOOK __stdcall w32api_user_set_windows_hook_ex_ansi(
	int,
	HOOKPROC,
	HINSTANCE,
	DWORD);

typedef HHOOK __stdcall w32api_user_set_windows_hook_ex_utf8(
	int,
	HOOKPROC,
	HINSTANCE,
	DWORD);

typedef HHOOK __stdcall w32api_user_set_windows_hook_ex_utf16(
	int,
	HOOKPROC,
	HINSTANCE,
	DWORD);

typedef BOOL __stdcall w32api_user_unhook_windows_hook_ex(
	HHOOK);

typedef LRESULT __stdcall w32api_user_call_next_hook_ex(
	HHOOK,
	int,
	WPARAM,
	LPARAM);

typedef BOOL __stdcall w32api_user_check_menu_radio_item(
	HMENU,
	UINT,
	UINT,
	UINT,
	UINT);

typedef HBITMAP __stdcall w32api_user_load_bitmap_ansi(
	HINSTANCE,
	LPCSTR);

typedef HBITMAP __stdcall w32api_user_load_bitmap_utf8(
	HINSTANCE,
	LPCSTR);

typedef HBITMAP __stdcall w32api_user_load_bitmap_utf16(
	HINSTANCE,
	LPCWSTR);

typedef HCURSOR __stdcall w32api_user_load_cursor_ansi(
	HINSTANCE,
	LPCSTR);

typedef HCURSOR __stdcall w32api_user_load_cursor_utf8(
	HINSTANCE,
	LPCSTR);

typedef HCURSOR __stdcall w32api_user_load_cursor_utf16(
	HINSTANCE,
	LPCWSTR);

typedef HCURSOR __stdcall w32api_user_load_cursor_from_file_ansi(
	LPCSTR);

typedef HCURSOR __stdcall w32api_user_load_cursor_from_file_utf8(
	LPCSTR);

typedef HCURSOR __stdcall w32api_user_load_cursor_from_file_utf16(
	LPCWSTR);

typedef HCURSOR __stdcall w32api_user_create_cursor(
	HINSTANCE,
	int,
	int,
	int,
	int,
	const void *,
	const void *);

typedef BOOL __stdcall w32api_user_destroy_cursor(
	HCURSOR);

typedef BOOL __stdcall w32api_user_set_system_cursor(
	HCURSOR,
	DWORD);

typedef HICON __stdcall w32api_user_load_icon_ansi(
	HINSTANCE,
	LPCSTR);

typedef HICON __stdcall w32api_user_load_icon_utf8(
	HINSTANCE,
	LPCSTR);

typedef HICON __stdcall w32api_user_load_icon_utf16(
	HINSTANCE,
	LPCWSTR);

typedef UINT __stdcall w32api_user_private_extract_icons_ansi(
	LPCSTR,
	int,
	int,
	int,
	HICON *,
	UINT *,
	UINT,
	UINT);

typedef UINT __stdcall w32api_user_private_extract_icons_utf8(
	LPCSTR,
	int,
	int,
	int,
	HICON *,
	UINT *,
	UINT,
	UINT);

typedef UINT __stdcall w32api_user_private_extract_icons_utf16(
	LPCWSTR,
	int,
	int,
	int,
	HICON *,
	UINT *,
	UINT,
	UINT);

typedef HICON __stdcall w32api_user_create_icon(
	HINSTANCE,
	int,
	int,
	BYTE,
	BYTE,
	const BYTE *,
	const BYTE *);

typedef BOOL __stdcall w32api_user_destroy_icon(
	HICON);

typedef int __stdcall w32api_user_lookup_icon_id_from_directory(
	PBYTE,
	BOOL);

typedef int __stdcall w32api_user_lookup_icon_id_from_directory_ex(
	PBYTE,
	BOOL,
	int,
	int,
	UINT);

typedef HICON __stdcall w32api_user_create_icon_from_resource(
	PBYTE,
	DWORD,
	BOOL,
	DWORD);

typedef HICON __stdcall w32api_user_create_icon_from_resource_ex(
	PBYTE,
	DWORD,
	BOOL,
	DWORD,
	int,
	int,
	UINT);

typedef HANDLE __stdcall w32api_user_load_image_ansi(
	HINSTANCE,
	LPCSTR,
	UINT,
	int,
	int,
	UINT);

typedef HANDLE __stdcall w32api_user_load_image_utf8(
	HINSTANCE,
	LPCSTR,
	UINT,
	int,
	int,
	UINT);

typedef HANDLE __stdcall w32api_user_load_image_utf16(
	HINSTANCE,
	LPCWSTR,
	UINT,
	int,
	int,
	UINT);

typedef HANDLE __stdcall w32api_user_copy_image(
	HANDLE,
	UINT,
	int,
	int,
	UINT);

typedef BOOL __stdcall w32api_user_draw_icon_ex(
	HDC,
	int,
	int,
	HICON,
	int,
	int,
	UINT,
	HBRUSH,
	UINT);

typedef HICON __stdcall w32api_user_create_icon_indirect(
	PICONINFO);

typedef HICON __stdcall w32api_user_copy_icon(
	HICON);

typedef BOOL __stdcall w32api_user_get_icon_info(
	HICON,
	PICONINFO);

typedef BOOL __stdcall w32api_user_get_icon_info_ex_ansi(
	HICON,
	PICONINFOEXA);

typedef BOOL __stdcall w32api_user_get_icon_info_ex_utf8(
	HICON,
	PICONINFOEXM);

typedef BOOL __stdcall w32api_user_get_icon_info_ex_utf16(
	HICON,
	PICONINFOEXW);

typedef int __stdcall w32api_user_load_string_ansi(
	HINSTANCE,
	UINT,
	LPSTR,
	int);

typedef int __stdcall w32api_user_load_string_utf8(
	HINSTANCE,
	UINT,
	LPSTR,
	int);

typedef int __stdcall w32api_user_load_string_utf16(
	HINSTANCE,
	UINT,
	LPWSTR,
	int);

typedef BOOL __stdcall w32api_user_is_dialog_message_ansi(
	HWND,
	LPMSG);

typedef BOOL __stdcall w32api_user_is_dialog_message_utf8(
	HWND,
	LPMSG);

typedef BOOL __stdcall w32api_user_is_dialog_message_utf16(
	HWND,
	LPMSG);

typedef BOOL __stdcall w32api_user_map_dialog_rect(
	HWND,
	LPRECT);

typedef int __stdcall w32api_user_dlg_dir_list_ansi(
	HWND,
	LPSTR,
	int,
	int,
	UINT);

typedef int __stdcall w32api_user_dlg_dir_list_utf8(
	HWND,
	LPSTR,
	int,
	int,
	UINT);

typedef int __stdcall w32api_user_dlg_dir_list_utf16(
	HWND,
	LPWSTR,
	int,
	int,
	UINT);

typedef BOOL __stdcall w32api_user_dlg_dir_select_ex_ansi(
	HWND,
	LPSTR,
	int,
	int);

typedef BOOL __stdcall w32api_user_dlg_dir_select_ex_utf8(
	HWND,
	LPSTR,
	int,
	int);

typedef BOOL __stdcall w32api_user_dlg_dir_select_ex_utf16(
	HWND,
	LPWSTR,
	int,
	int);

typedef int __stdcall w32api_user_dlg_dir_list_combo_box_ansi(
	HWND,
	LPSTR,
	int,
	int,
	UINT);

typedef int __stdcall w32api_user_dlg_dir_list_combo_box_utf8(
	HWND,
	LPSTR,
	int,
	int,
	UINT);

typedef int __stdcall w32api_user_dlg_dir_list_combo_box_utf16(
	HWND,
	LPWSTR,
	int,
	int,
	UINT);

typedef BOOL __stdcall w32api_user_dlg_dir_select_combo_box_ex_ansi(
	HWND,
	LPSTR,
	int,
	int);

typedef BOOL __stdcall w32api_user_dlg_dir_select_combo_box_ex_utf8(
	HWND,
	LPSTR,
	int,
	int);

typedef BOOL __stdcall w32api_user_dlg_dir_select_combo_box_ex_utf16(
	HWND,
	LPWSTR,
	int,
	int);

typedef int __stdcall w32api_user_set_scroll_info(
	HWND,
	int,
	LPCSCROLLINFO,
	BOOL);

typedef BOOL __stdcall w32api_user_get_scroll_info(
	HWND,
	int,
	LPSCROLLINFO);

typedef LRESULT __stdcall w32api_user_def_frame_proc_ansi(
	HWND,
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_def_frame_proc_utf8(
	HWND,
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_def_frame_proc_utf16(
	HWND,
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_def_mdi_child_proc_ansi(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_def_mdi_child_proc_utf8(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef LRESULT __stdcall w32api_user_def_mdi_child_proc_utf16(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

typedef BOOL __stdcall w32api_user_translate_mdi_sys_accel(
	HWND,
	LPMSG);

typedef UINT __stdcall w32api_user_arrange_iconic_windows(
	HWND);

typedef HWND __stdcall w32api_user_create_mdi_window_ansi(
	LPCSTR,
	LPCSTR,
	DWORD,
	int,
	int,
	int,
	int,
	HWND,
	HINSTANCE,
	LPARAM);

typedef HWND __stdcall w32api_user_create_mdi_window_utf8(
	LPCSTR,
	LPCSTR,
	DWORD,
	int,
	int,
	int,
	int,
	HWND,
	HINSTANCE,
	LPARAM);

typedef HWND __stdcall w32api_user_create_mdi_window_utf16(
	LPCWSTR,
	LPCWSTR,
	DWORD,
	int,
	int,
	int,
	int,
	HWND,
	HINSTANCE,
	LPARAM);

typedef WORD __stdcall w32api_user_tile_windows(
	HWND,
	UINT,
	const RECT *,
	UINT,
	const HWND *);

typedef WORD __stdcall w32api_user_cascade_windows(
	HWND,
	UINT,
	const RECT *,
	UINT,
	const HWND *);

typedef BOOL __stdcall w32api_user_win_help_ansi(
	HWND,
	LPCSTR,
	UINT,
	ULONG_PTR);

typedef BOOL __stdcall w32api_user_win_help_utf8(
	HWND,
	LPCSTR,
	UINT,
	ULONG_PTR);

typedef BOOL __stdcall w32api_user_win_help_utf16(
	HWND,
	LPCWSTR,
	UINT,
	ULONG_PTR);

typedef DWORD __stdcall w32api_user_get_gui_resources(
	HANDLE,
	DWORD);

typedef LONG __stdcall w32api_user_change_display_settings_ansi(
	LPDEVMODEA,
	DWORD);

typedef LONG __stdcall w32api_user_change_display_settings_utf8(
	LPDEVMODEM,
	DWORD);

typedef LONG __stdcall w32api_user_change_display_settings_utf16(
	LPDEVMODEW,
	DWORD);

typedef LONG __stdcall w32api_user_change_display_settings_ex_ansi(
	LPCSTR,
	LPDEVMODEA,
	HWND,
	DWORD,
	LPVOID);

typedef LONG __stdcall w32api_user_change_display_settings_ex_utf8(
	LPCSTR,
	LPDEVMODEM,
	HWND,
	DWORD,
	LPVOID);

typedef LONG __stdcall w32api_user_change_display_settings_ex_utf16(
	LPCWSTR,
	LPDEVMODEW,
	HWND,
	DWORD,
	LPVOID);

typedef BOOL __stdcall w32api_user_enum_display_settings_ansi(
	LPCSTR,
	DWORD,
	LPDEVMODEA);

typedef BOOL __stdcall w32api_user_enum_display_settings_utf8(
	LPCSTR,
	DWORD,
	LPDEVMODEM);

typedef BOOL __stdcall w32api_user_enum_display_settings_utf16(
	LPCWSTR,
	DWORD,
	LPDEVMODEW);

typedef BOOL __stdcall w32api_user_enum_display_settings_ex_ansi(
	LPCSTR,
	DWORD,
	LPDEVMODEA,
	DWORD);

typedef BOOL __stdcall w32api_user_enum_display_settings_ex_utf8(
	LPCSTR,
	DWORD,
	LPDEVMODEM,
	DWORD);

typedef BOOL __stdcall w32api_user_enum_display_settings_ex_utf16(
	LPCWSTR,
	DWORD,
	LPDEVMODEW,
	DWORD);

typedef BOOL __stdcall w32api_user_enum_display_devices_ansi(
	LPCSTR,
	DWORD,
	PDISPLAY_DEVICEA,
	DWORD);

typedef BOOL __stdcall w32api_user_enum_display_devices_utf8(
	LPCSTR,
	DWORD,
	PDISPLAY_DEVICEM,
	DWORD);

typedef BOOL __stdcall w32api_user_enum_display_devices_utf16(
	LPCWSTR,
	DWORD,
	PDISPLAY_DEVICEW,
	DWORD);

typedef LONG __stdcall w32api_user_get_display_config_buffer_sizes(
	UINT32,
	UINT32 *,
	UINT32 *);

typedef LONG __stdcall w32api_user_set_display_config(
	UINT32,
	DISPLAYCONFIG_PATH_INFO *,
	UINT32,
	DISPLAYCONFIG_MODE_INFO *,
	UINT32);

typedef LONG __stdcall w32api_user_query_display_config(
	UINT32,
	UINT32 *,
	DISPLAYCONFIG_PATH_INFO *,
	UINT32 *,
	DISPLAYCONFIG_MODE_INFO *,
	DISPLAYCONFIG_TOPOLOGY_ID *);

typedef LONG __stdcall w32api_user_display_config_get_device_info(
	DISPLAYCONFIG_DEVICE_INFO_HEADER *);

typedef LONG __stdcall w32api_user_display_config_set_device_info(
	DISPLAYCONFIG_DEVICE_INFO_HEADER *);

typedef BOOL __stdcall w32api_user_system_parameters_info_ansi(
	UINT,
	UINT,
	PVOID,
	UINT);

typedef BOOL __stdcall w32api_user_system_parameters_info_utf8(
	UINT,
	UINT,
	PVOID,
	UINT);

typedef BOOL __stdcall w32api_user_system_parameters_info_utf16(
	UINT,
	UINT,
	PVOID,
	UINT);

typedef void __stdcall w32api_user_set_debug_error_level(
	DWORD);

typedef void __stdcall w32api_user_set_last_error_ex(
	DWORD,
	DWORD);

typedef int __stdcall w32api_user_internal_get_window_text(
	HWND,
	LPWSTR,
	int);

typedef BOOL __stdcall w32api_user_cancel_shutdown(
	void);

typedef HMONITOR __stdcall w32api_user_monitor_from_point(
	POINT,
	DWORD);

typedef HMONITOR __stdcall w32api_user_monitor_from_rect(
	LPCRECT,
	DWORD);

typedef HMONITOR __stdcall w32api_user_monitor_from_window(
	HWND,
	DWORD);

typedef BOOL __stdcall w32api_user_end_task(
	HWND,
	BOOL,
	BOOL);

typedef BOOL __stdcall w32api_user_sound_sentry(
	void);

typedef BOOL __stdcall w32api_user_get_monitor_info_ansi(
	HMONITOR,
	LPMONITORINFO);

typedef BOOL __stdcall w32api_user_get_monitor_info_utf8(
	HMONITOR,
	LPMONITORINFO);

typedef BOOL __stdcall w32api_user_get_monitor_info_utf16(
	HMONITOR,
	LPMONITORINFO);

typedef BOOL __stdcall w32api_user_enum_display_monitors(
	HDC,
	LPCRECT,
	MONITORENUMPROC,
	LPARAM);

typedef void __stdcall w32api_user_notify_win_event(
	DWORD,
	HWND,
	LONG,
	LONG);

typedef HWINEVENTHOOK __stdcall w32api_user_set_win_event_hook(
	DWORD,
	DWORD,
	HMODULE,
	WINEVENTPROC,
	DWORD,
	DWORD,
	DWORD);

typedef BOOL __stdcall w32api_user_is_win_event_hook_installed(
	DWORD);

typedef BOOL __stdcall w32api_user_unhook_win_event(
	HWINEVENTHOOK);

typedef BOOL __stdcall w32api_user_get_gui_thread_info(
	DWORD,
	PGUITHREADINFO);

typedef BOOL __stdcall w32api_user_block_input(
	BOOL);

typedef UINT __stdcall w32api_user_get_window_module_file_name_ansi(
	HWND,
	LPSTR,
	UINT);

typedef UINT __stdcall w32api_user_get_window_module_file_name_utf8(
	HWND,
	LPSTR,
	UINT);

typedef UINT __stdcall w32api_user_get_window_module_file_name_utf16(
	HWND,
	LPWSTR,
	UINT);

typedef BOOL __stdcall w32api_user_set_process_dpi_aware(
	void);

typedef BOOL __stdcall w32api_user_is_process_dpi_aware(
	void);

typedef BOOL __stdcall w32api_user_get_cursor_info(
	PCURSORINFO);

typedef BOOL __stdcall w32api_user_get_window_info(
	HWND,
	PWINDOWINFO);

typedef BOOL __stdcall w32api_user_get_title_bar_info(
	HWND,
	PTITLEBARINFO);

typedef BOOL __stdcall w32api_user_get_menu_bar_info(
	HWND,
	LONG,
	LONG,
	PMENUBARINFO);

typedef BOOL __stdcall w32api_user_get_combo_box_info(
	HWND,
	PCOMBOBOXINFO);

typedef HWND __stdcall w32api_user_get_ancestor(
	HWND,
	UINT);

typedef HWND __stdcall w32api_user_real_child_window_from_point(
	HWND,
	POINT);

typedef UINT __stdcall w32api_user_real_get_window_class_ansi(
	HWND,
	LPSTR,
	UINT);

typedef UINT __stdcall w32api_user_real_get_window_class_utf8(
	HWND,
	LPSTR,
	UINT);

typedef UINT __stdcall w32api_user_real_get_window_class_utf16(
	HWND,
	LPWSTR,
	UINT);

typedef BOOL __stdcall w32api_user_get_alt_tab_info_ansi(
	HWND,
	int,
	PALTTABINFO,
	LPSTR,
	UINT);

typedef BOOL __stdcall w32api_user_get_alt_tab_info_utf8(
	HWND,
	int,
	PALTTABINFO,
	LPSTR,
	UINT);

typedef BOOL __stdcall w32api_user_get_alt_tab_info_utf16(
	HWND,
	int,
	PALTTABINFO,
	LPWSTR,
	UINT);

typedef DWORD __stdcall w32api_user_get_list_box_info(
	HWND);

typedef BOOL __stdcall w32api_user_lock_work_station(
	void);

typedef BOOL __stdcall w32api_user_user_handle_grant_access(
	HANDLE,
	HANDLE,
	BOOL);

typedef UINT __stdcall w32api_user_get_raw_input_data(
	HRAWINPUT,
	UINT,
	LPVOID,
	PUINT,
	UINT);

typedef UINT __stdcall w32api_user_get_raw_input_device_info_ansi(
	HANDLE,
	UINT,
	LPVOID,
	PUINT);

typedef UINT __stdcall w32api_user_get_raw_input_device_info_utf8(
	HANDLE,
	UINT,
	LPVOID,
	PUINT);

typedef UINT __stdcall w32api_user_get_raw_input_device_info_utf16(
	HANDLE,
	UINT,
	LPVOID,
	PUINT);

typedef UINT __stdcall w32api_user_get_raw_input_buffer(
	PRAWINPUT,
	PUINT,
	UINT);

typedef BOOL __stdcall w32api_user_register_raw_input_devices(
	PCRAWINPUTDEVICE,
	UINT,
	UINT);

typedef UINT __stdcall w32api_user_get_registered_raw_input_devices(
	PRAWINPUTDEVICE,
	PUINT,
	UINT);

typedef UINT __stdcall w32api_user_get_raw_input_device_list(
	PRAWINPUTDEVICELIST,
	PUINT,
	UINT);

typedef LRESULT __stdcall w32api_user_def_raw_input_proc(
	PRAWINPUT *,
	INT,
	UINT);

typedef BOOL __stdcall w32api_user_get_pointer_devices(
	UINT32 *,
	POINTER_DEVICE_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_device(
	HANDLE,
	POINTER_DEVICE_INFO *);

typedef BOOL __stdcall w32api_user_get_pointer_device_properties(
	HANDLE,
	UINT32 *,
	POINTER_DEVICE_PROPERTY *);

typedef BOOL __stdcall w32api_user_register_pointer_device_notifications(
	HWND,
	BOOL);

typedef BOOL __stdcall w32api_user_get_pointer_device_rects(
	HANDLE,
	RECT *,
	RECT *);

typedef BOOL __stdcall w32api_user_get_pointer_device_cursors(
	HANDLE,
	UINT32 *,
	POINTER_DEVICE_CURSOR_INFO *);

typedef BOOL __stdcall w32api_user_get_raw_pointer_device_data(
	UINT32,
	UINT32,
	UINT32,
	POINTER_DEVICE_PROPERTY *,
	LONG *);

typedef BOOL __stdcall w32api_user_change_window_message_filter(
	UINT,
	DWORD);

typedef BOOL __stdcall w32api_user_change_window_message_filter_ex(
	HWND,
	UINT,
	DWORD,
	PCHANGEFILTERSTRUCT);

typedef BOOL __stdcall w32api_user_get_gesture_info(
	HGESTUREINFO,
	PGESTUREINFO);

typedef BOOL __stdcall w32api_user_get_gesture_extra_args(
	HGESTUREINFO,
	UINT,
	PBYTE);

typedef BOOL __stdcall w32api_user_close_gesture_info_handle(
	HGESTUREINFO);

typedef BOOL __stdcall w32api_user_set_gesture_config(
	HWND,
	DWORD,
	UINT,
	PGESTURECONFIG,
	UINT);

typedef BOOL __stdcall w32api_user_get_gesture_config(
	HWND,
	DWORD,
	DWORD,
	PUINT,
	PGESTURECONFIG,
	UINT);

typedef BOOL __stdcall w32api_user_shutdown_block_reason_create(
	HWND,
	LPCWSTR);

typedef BOOL __stdcall w32api_user_shutdown_block_reason_query(
	HWND,
	LPWSTR,
	DWORD *);

typedef BOOL __stdcall w32api_user_shutdown_block_reason_destroy(
	HWND);

typedef BOOL __stdcall w32api_user_get_current_input_message_source(
	INPUT_MESSAGE_SOURCE *);

typedef BOOL __stdcall w32api_user_get_cimssm(
	INPUT_MESSAGE_SOURCE *);

typedef BOOL __stdcall w32api_user_get_auto_rotation_state(
	PAR_STATE);

typedef BOOL __stdcall w32api_user_get_display_auto_rotation_preferences(
	ORIENTATION_PREFERENCE *);

typedef BOOL __stdcall w32api_user_get_display_auto_rotation_preferences_by_process_id(
	DWORD,
	ORIENTATION_PREFERENCE *,
	BOOL *);

typedef BOOL __stdcall w32api_user_set_display_auto_rotation_preferences(
	ORIENTATION_PREFERENCE);

typedef BOOL __stdcall w32api_user_is_immersive_process(
	HANDLE);

typedef BOOL __stdcall w32api_user_set_process_restriction_exemption(
	BOOL);

typedef BOOL __stdcall w32api_user_get_pointer_input_transform(
	UINT32,
	UINT32,
	UINT32 *);

typedef BOOL __stdcall w32api_user_is_mouse_pointer_enabled(
	void);



#ifdef __NT64
typedef LONG_PTR __stdcall w32api_user_get_window_long_ptr_ansi(
	HWND,
	int);

typedef LONG_PTR __stdcall w32api_user_get_window_long_ptr_utf8(
	HWND,
	int);

typedef LONG_PTR __stdcall w32api_user_get_window_long_ptr_utf16(
	HWND,
	int);

typedef LONG_PTR __stdcall w32api_user_set_window_long_ptr_ansi(
	HWND,
	int,
	LONG_PTR);

typedef LONG_PTR __stdcall w32api_user_set_window_long_ptr_utf8(
	HWND,
	int,
	LONG_PTR);

typedef LONG_PTR __stdcall w32api_user_set_window_long_ptr_utf16(
	HWND,
	int,
	LONG_PTR);
	
typedef ULONG_PTR __stdcall w32api_user_get_class_long_ptr_ansi(
	HWND,
	int);

typedef ULONG_PTR __stdcall w32api_user_get_class_long_ptr_utf8(
	HWND,
	int);
	
typedef ULONG_PTR __stdcall w32api_user_get_class_long_ptr_utf16(
	HWND,
	int);

typedef ULONG_PTR __stdcall w32api_user_set_class_long_ptr_ansi(
	HWND,
	int,
	LONG_PTR);

typedef ULONG_PTR __stdcall w32api_user_set_class_long_ptr_utf8(
	HWND,
	int,
	LONG_PTR);

typedef ULONG_PTR __stdcall w32api_user_set_class_long_ptr_utf16(
	HWND,
	int,
	LONG_PTR);

#else
#define GetWindowLongPtrA GetWindowLongA
#define GetWindowLongPtrM GetWindowLongM
#define GetWindowLongPtrW GetWindowLongW
#define SetWindowLongPtrA SetWindowLongA
#define SetWindowLongPtrM SetWindowLongM
#define SetWindowLongPtrW SetWindowLongW

#define GetClassLongPtrA GetClassLongA
#define GetClassLongPtrM GetClassLongM
#define GetClassLongPtrW GetClassLongW
#define SetClassLongPtrA SetClassLongA
#define SetClassLongPtrM SetClassLongM
#define SetClassLongPtrW SetClassLongW
#endif



__dllimport w32api_user_wvsprintf_ansi						wvsprintfA;
__dllimport w32api_user_wvsprintf_utf8						wvsprintfM;
__dllimport w32api_user_wvsprintf_utf16						wvsprintfW;
__dllimport w32api_user_wsprintf_ansi						wsprintfA;
__dllimport w32api_user_wsprintf_utf8						wsprintfM;
__dllimport w32api_user_wsprintf_utf16						wsprintfW;
__dllimport w32api_user_load_keyboard_layout_ansi				LoadKeyboardLayoutA;
__dllimport w32api_user_load_keyboard_layout_utf8				LoadKeyboardLayoutM;
__dllimport w32api_user_load_keyboard_layout_utf16				LoadKeyboardLayoutW;
__dllimport w32api_user_activate_keyboard_layout				ActivateKeyboardLayout;
__dllimport w32api_user_to_unicode_ex						ToUnicodeEx;
__dllimport w32api_user_unload_keyboard_layout					UnloadKeyboardLayout;
__dllimport w32api_user_get_keyboard_layout_name_ansi				GetKeyboardLayoutNameA;
__dllimport w32api_user_get_keyboard_layout_name_utf8				GetKeyboardLayoutNameM;
__dllimport w32api_user_get_keyboard_layout_name_utf16				GetKeyboardLayoutNameW;
__dllimport w32api_user_get_keyboard_layout_list				GetKeyboardLayoutList;
__dllimport w32api_user_get_keyboard_layout					GetKeyboardLayout;
__dllimport w32api_user_get_mouse_move_points_ex				GetMouseMovePointsEx;
__dllimport w32api_user_create_desktop_ansi					CreateDesktopA;
__dllimport w32api_user_create_desktop_utf8					CreateDesktopM;
__dllimport w32api_user_create_desktop_utf16					CreateDesktopW;
__dllimport w32api_user_create_desktop_ex_ansi					CreateDesktopExA;
__dllimport w32api_user_create_desktop_ex_utf8					CreateDesktopExM;
__dllimport w32api_user_create_desktop_ex_utf16					CreateDesktopExW;
__dllimport w32api_user_open_desktop_ansi					OpenDesktopA;
__dllimport w32api_user_open_desktop_utf8					OpenDesktopM;
__dllimport w32api_user_open_desktop_utf16					OpenDesktopW;
__dllimport w32api_user_open_input_desktop					OpenInputDesktop;
__dllimport w32api_user_enum_desktops_ansi					EnumDesktopsA;
__dllimport w32api_user_enum_desktops_utf8					EnumDesktopsM;
__dllimport w32api_user_enum_desktops_utf16					EnumDesktopsW;
__dllimport w32api_user_enum_desktop_windows					EnumDesktopWindows;
__dllimport w32api_user_switch_desktop						SwitchDesktop;
__dllimport w32api_user_set_thread_desktop					SetThreadDesktop;
__dllimport w32api_user_close_desktop						CloseDesktop;
__dllimport w32api_user_get_thread_desktop					GetThreadDesktop;
__dllimport w32api_user_create_window_station_ansi				CreateWindowStationA;
__dllimport w32api_user_create_window_station_utf8				CreateWindowStationM;
__dllimport w32api_user_create_window_station_utf16				CreateWindowStationW;
__dllimport w32api_user_open_window_station_ansi				OpenWindowStationA;
__dllimport w32api_user_open_window_station_utf8				OpenWindowStationM;
__dllimport w32api_user_open_window_station_utf16				OpenWindowStationW;
__dllimport w32api_user_enum_window_stations_ansi				EnumWindowStationsA;
__dllimport w32api_user_enum_window_stations_utf8				EnumWindowStationsM;
__dllimport w32api_user_enum_window_stations_utf16				EnumWindowStationsW;
__dllimport w32api_user_close_window_station					CloseWindowStation;
__dllimport w32api_user_set_process_window_station				SetProcessWindowStation;
__dllimport w32api_user_get_process_window_station				GetPorcessWindowStation;
__dllimport w32api_user_set_user_object_security				SetUserObjectSecurity;
__dllimport w32api_user_get_user_object_security				GetUserObjectSecurity;
__dllimport w32api_user_get_user_object_information_ansi			GetUserObjectInformationA;
__dllimport w32api_user_get_user_object_information_utf8			GetUserObjectInformationM;
__dllimport w32api_user_get_user_object_information_utf16			GetUserObjectInformationW;
__dllimport w32api_user_set_user_object_information_ansi			SetUserObjectInformationA;
__dllimport w32api_user_set_user_object_information_utf8			SetUserObjectInformationM;
__dllimport w32api_user_set_user_object_information_utf16			SetUserObjectInformationW;
__dllimport w32api_user_is_hung_app_window					IsHungAppWindow;
__dllimport w32api_user_disable_process_windows_ghosting			DisableProcessWindowsGhosting;
__dllimport w32api_user_get_scroll_bar_info					GetScrollBarInfo;
__dllimport w32api_user_register_window_Message_ansi				RegisterWindowMessageA;
__dllimport w32api_user_register_window_message_utf8				RegisterWindowMessageM;
__dllimport w32api_user_register_window_message_utf16				RegisterWindowMessageW;
__dllimport w32api_user_track_mouse_event					TrackMouseEvent;
__dllimport w32api_user_draw_edge						DrawEdge;
__dllimport w32api_user_draw_frame_control					DrawFrameControl;
__dllimport w32api_user_draw_caption						DrawCaption;
__dllimport w32api_user_draw_animated_rects					DrawAnimatedRects;
__dllimport w32api_user_get_message_ansi					GetMessageA;
__dllimport w32api_user_get_message_utf8					GetMessageM;
__dllimport w32api_user_get_message_utf16					GetMessageW;
__dllimport w32api_user_translate_message					TranslateMessage;
__dllimport w32api_user_dispatch_message_ansi					DispatchMessageA;
__dllimport w32api_user_dispatch_message_utf8					DispatchMessageM;
__dllimport w32api_user_dispatch_message_utf16					DispatchMessageW;
__dllimport w32api_user_set_message_queue					SetMessageQueue;
__dllimport w32api_user_peek_message_ansi					PeekMessageA;
__dllimport w32api_user_peek_message_utf8					PeekMessageM;
__dllimport w32api_user_peek_message_utf16					PeekMessageW;
__dllimport w32api_user_register_hot_key					RegisterHotKey;
__dllimport w32api_user_unregister_hot_key					UnregisterHotKey;
__dllimport w32api_user_exit_windows_ex						ExitWindowsEx;
__dllimport w32api_user_swap_mouse_button					SwapMouseButton;
__dllimport w32api_user_get_message_pos						GetMessagePos;
__dllimport w32api_user_get_message_time					GetMessageTime;
__dllimport w32api_user_get_message_extra_info					GetMessageExtraInfo;
__dllimport w32api_user_get_unpredicted_message_pos				GetUnpredictedMessagePos;
__dllimport w32api_user_is_wow64_message					IsWow64Message;
__dllimport w32api_user_set_message_extra_info					SetMessageExtraInfo;
__dllimport w32api_user_send_message_ansi					SendMessageA;
__dllimport w32api_user_send_message_utf8					SendMessageM;
__dllimport w32api_user_send_message_utf16					SendMessageW;
__dllimport w32api_user_send_message_timeout_ansi				SendMessageTimeoutA;
__dllimport w32api_user_send_message_timeout_utf8				SendMessageTimeoutM;
__dllimport w32api_user_send_message_timeout_utf16				SendMessageTimeoutW;
__dllimport w32api_user_send_notify_message_ansi				SendNotifyMessageA;
__dllimport w32api_user_send_notify_message_utf8				SendNotifyMessageM;
__dllimport w32api_user_send_notify_message_utf16				SendNotifyMessageW;
__dllimport w32api_user_send_message_callback_ansi				SendMessageCallbackA;
__dllimport w32api_user_send_message_callback_utf8				SendMessageCallbackM;
__dllimport w32api_user_send_message_callback_utf16				SendMessageCallbackW;
__dllimport w32api_user_broadcast_system_message_ex_ansi			BroadcastSystemMessageExA;
__dllimport w32api_user_broadcast_system_message_ex_utf8			BroadcastSystemMessageExM;
__dllimport w32api_user_broadcast_system_message_ex_utf16			BroadcastSystemMessageExW;
__dllimport w32api_user_broadcast_system_message_ansi				BroadcastSystemMessageA;
__dllimport w32api_user_broadcast_system_message_utf8				BroadcastSystemMessageM;
__dllimport w32api_user_broadcast_system_message_utf16				BroadcastSystemMessageW;
__dllimport w32api_user_register_power_setting_notification			RegisterPowerSettingNotification;
__dllimport w32api_user_unregister_power_setting_notification			UnregisterPowerSettingNotification;
__dllimport w32api_user_register_suspend_resume_notification			RegisterSuspsendResumeNotification;
__dllimport w32api_user_unregister_suspend_resume_notification			UnregisterSuspendResumeNotification;
__dllimport w32api_user_post_message_ansi					PostMessageA;
__dllimport w32api_user_post_message_utf8					PostMessageM;
__dllimport w32api_user_post_message_utf16					PostMessageW;
__dllimport w32api_user_post_thread_message_ansi				PostThreadMessageA;
__dllimport w32api_user_post_thread_message_utf8				PostThreadMessageM;
__dllimport w32api_user_post_thread_message_utf16				PostThreadMessageW;
__dllimport w32api_user_attach_thread_input					AttachThreadInput;
__dllimport w32api_user_reply_message						ReplyMessage;
__dllimport w32api_user_wait_message						WaitMessage;
__dllimport w32api_user_wait_for_input_idle					WaitForInputIdle;
__dllimport w32api_user_def_window_proc_ansi					DefWindowProcA;
__dllimport w32api_user_def_window_proc_utf8					DefWindowProcM;
__dllimport w32api_user_def_window_proc_utf16					DefWindowProcW;
__dllimport w32api_user_post_quit_message					PostQuitMessage;
__dllimport w32api_user_in_send_message						InSendMessage;
__dllimport w32api_user_in_send_message_ex					InSendMessageEx;
__dllimport w32api_user_get_double_click_time					GetDoubleClickTime;
__dllimport w32api_user_set_double_click_time					SetDoubleClickTime;
__dllimport w32api_user_register_class_ansi					RegisterClassA;
__dllimport w32api_user_register_class_utf8					RegisterClassM;
__dllimport w32api_user_register_class_utf16					RegisterClassW;
__dllimport w32api_user_unregister_class_ansi					UnregisterClassA;
__dllimport w32api_user_unregister_class_utf8					UnregisterClassM;
__dllimport w32api_user_unregister_class_utf16					UnregisterClassW;
__dllimport w32api_user_get_class_info_ansi					GetClassInfoA;
__dllimport w32api_user_get_class_info_utf8					GetClassInfoM;
__dllimport w32api_user_get_class_info_utf16					GetClassInfoW;
__dllimport w32api_user_register_class_ex_ansi					RegisterClassExA;
__dllimport w32api_user_register_class_ex_utf8					RegisterClassExM;
__dllimport w32api_user_register_class_ex_utf16					RegisterClassExW;
__dllimport w32api_user_get_class_info_ex_ansi					GetClassInfoExA;
__dllimport w32api_user_get_class_info_ex_utf8					GetClassInfoExM;
__dllimport w32api_user_get_class_info_ex_utf16					GetClassInfoExW;
__dllimport w32api_user_call_window_proc_ansi					CallWindowProcA;
__dllimport w32api_user_call_window_proc_utf8					CallWindowProcM;
__dllimport w32api_user_call_window_proc_utf16					CallWindowProcW;
__dllimport w32api_user_register_device_notification_ansi			RegisterDeviceNotificationA;
__dllimport w32api_user_register_device_notification_utf8			RegisterDeviceNotificationM;
__dllimport w32api_user_register_device_notification_utf16			RegisterDeviceNotificationW;
__dllimport w32api_user_unregister_device_notification				UnregisterDeviceNotification;
__dllimport w32api_user_create_window_ex_ansi					CreateWindowExA;
__dllimport w32api_user_create_window_ex_utf8					CreateWindowExM;
__dllimport w32api_user_create_window_ex_utf16					CreateWindowExW;
__dllimport w32api_user_is_window						IsWindow;
__dllimport w32api_user_is_menu							IsMenu;
__dllimport w32api_user_is_child						IsChild;
__dllimport w32api_user_destroy_window						DestroyWindow;
__dllimport w32api_user_show_window						ShowWindow;
__dllimport w32api_user_animate_window						AnimateWindow;
__dllimport w32api_user_update_layered_window					UpdateLayeredWindow;
__dllimport w32api_user_update_layered_window_indirect				UpdateLayeredWindowIndirect;
__dllimport w32api_user_get_layered_window_attributes				GetLayeredWindowAttributes;
__dllimport w32api_user_print_window						PrintWindow;
__dllimport w32api_user_set_layered_window_attributes				SetLayeredWindowAttributes;
__dllimport w32api_user_show_window_async					ShowWindowAsync;
__dllimport w32api_user_flash_window						FlashWindow;
__dllimport w32api_user_flash_window_ex						FlashWindowEx;
__dllimport w32api_user_show_owned_popups					ShowOwnedPopups;
__dllimport w32api_user_open_icon						OpenIcon;
__dllimport w32api_user_close_window						CloseWindow;
__dllimport w32api_user_move_window						MoveWindow;
__dllimport w32api_user_set_window_pos						SetWindowPos;
__dllimport w32api_user_get_window_placement					GetWindowPlacement;
__dllimport w32api_user_set_window_placement					SetWindowPlacement;
__dllimport w32api_user_get_window_display_affinity				GetWindowDisplayAffinity;
__dllimport w32api_user_set_window_display_affinity				SetWindowDisplayAffinity;
__dllimport w32api_user_begin_defer_window_pos					BeginDeferWindowPos;
__dllimport w32api_user_defer_window_pos					DeferWindowPos;
__dllimport w32api_user_end_defer_window_pos					EndDeferWindowPos;
__dllimport w32api_user_is_window_visible					IsWindowVisible;
__dllimport w32api_user_is_iconic						IsIconic;
__dllimport w32api_user_any_popup						AnyPopup;
__dllimport w32api_user_bring_window_to_top					BringWindowToTop;
__dllimport w32api_user_is_zoomed						IsZoomed;
__dllimport w32api_user_create_dialog_param_ansi				CreateDialogParamA;
__dllimport w32api_user_create_dialog_param_utf8				CreateDialogParamM;
__dllimport w32api_user_create_dialog_param_utf16				CreateDialogParamW;
__dllimport w32api_user_create_dialog_indirect_param_ansi			CreateDialogIndirectParamA;
__dllimport w32api_user_create_dialog_indirect_param_utf8			CreateDialogIndirectParamM;
__dllimport w32api_user_create_dialog_indirect_param_utf16			CreateDialogIndirectParamW;
__dllimport w32api_user_dialog_box_param_ansi					DialogBoxParamA;
__dllimport w32api_user_dialog_box_param_utf8					DialogBoxParamM;
__dllimport w32api_user_dialog_box_param_utf16					DialogBoxParamW;
__dllimport w32api_user_dialog_box_indirect_param_ansi				DialogBoxIndirectParamA;
__dllimport w32api_user_dialog_box_indirect_param_utf8				DialogBoxIndirectParamM;
__dllimport w32api_user_dialog_box_indirect_param_utf16				DialogBoxIndirectParamW;
__dllimport w32api_user_end_dialog						EndDialog;
__dllimport w32api_user_get_dlg_item						GetDlgItem;
__dllimport w32api_user_set_dlg_item_int					SetDlgItemInt;
__dllimport w32api_user_get_dlg_item_int					GetDlgItemInt;
__dllimport w32api_user_set_dlg_item_text_ansi					SetDlgItemTextA;
__dllimport w32api_user_set_dlg_item_text_utf8					SetDlgItemTextM;
__dllimport w32api_user_set_dlg_item_text_utf16					SetDlgItemTextW;
__dllimport w32api_user_get_dlg_item_text_ansi					GetDlgItemTextA;
__dllimport w32api_user_get_dlg_item_text_utf8					GetDlgItemTextM;
__dllimport w32api_user_get_dlg_item_text_utf16					GetDlgItemTextW;
__dllimport w32api_user_check_dlg_button					CheckDlgButton;
__dllimport w32api_user_check_radio_button					CheckRadioButton;
__dllimport w32api_user_is_dlg_button_checked					IsDlgButtonChecked;
__dllimport w32api_user_send_dlg_item_message_ansi				SendDlgItemMessageA;
__dllimport w32api_user_send_dlg_item_message_utf8				SendDlgItemMessageM;
__dllimport w32api_user_send_dlg_item_message_utf16				SendDlgItemMessageW;
__dllimport w32api_user_get_next_dlg_group_item					GetNextDlgGroupItem;
__dllimport w32api_user_get_next_dlg_tab_item					GetNextDlgTabItem;
__dllimport w32api_user_get_dlg_ctrl_id						GetDlgCtrlID;
__dllimport w32api_user_get_dialog_base_units					GetDialogBaseUnits;
__dllimport w32api_user_def_dlg_proc_ansi					DefDlgProcA;
__dllimport w32api_user_def_dlg_proc_utf8					DefDlgProcM;
__dllimport w32api_user_def_dlg_proc_utf16					DefDlgProcW;
__dllimport w32api_user_call_msg_filter_ansi					CallMsgFilterA;
__dllimport w32api_user_call_msg_filter_utf8					CallMsgFilterM;
__dllimport w32api_user_call_msg_filter_utf16					CallMsgFilterW;
__dllimport w32api_user_open_clipboard						OpenClipboard;
__dllimport w32api_user_close_clipboard						CloseClipboard;
__dllimport w32api_user_get_clipboard_sequence_number				GetClipboardSequenceNumber;
__dllimport w32api_user_get_clipboard_owner					GetClipboardOwner;
__dllimport w32api_user_set_clipboard_viewer					SetClipboardViewer;
__dllimport w32api_user_get_clipboard_viewer					GetClipboardViewer;
__dllimport w32api_user_change_clipboard_chain					ChangeClipboardChain;
__dllimport w32api_user_set_clipboard_data					SetClipboardData;
__dllimport w32api_user_get_clipboard_data					GetClipboardData;
__dllimport w32api_user_register_clipboard_format_ansi				RegisterClipboardFormatA;
__dllimport w32api_user_register_clipboard_format_utf8				RegisterClipboardFormatM;
__dllimport w32api_user_register_clipboard_format_utf16				RegisterClipboardFormatW;
__dllimport w32api_user_count_clipboard_formats					CountClipboardFormats;
__dllimport w32api_user_enum_clipboard_formats					EnumClipboardFormats;
__dllimport w32api_user_get_clipboard_format_name_ansi				GetClipboardFormatNameA;
__dllimport w32api_user_get_clipboard_format_name_utf8				GetClipboardFormatNameM;
__dllimport w32api_user_get_clipboard_format_name_utf16				GetClipboardFormatNameW;
__dllimport w32api_user_empty_clipboard						EmptyClipboard;	
__dllimport w32api_user_is_clipboard_format_available				IsClipboardFormatAvailable;
__dllimport w32api_user_get_priority_clipboard_format				GetPriorityClipboardFormat;
__dllimport w32api_user_get_open_clipboard_window				GetOpenClipboardWindow;
__dllimport w32api_user_add_clipboard_format_listener				AddClipboardFormatListener;
__dllimport w32api_user_remove_clipboard_format_listener			RemoveClipboardFormatListener;
__dllimport w32api_user_get_updated_clipboard_formats				GetUpdatedClipboardFormats;
__dllimport w32api_user_char_to_oem_ansi					CharToOemA;
__dllimport w32api_user_char_to_oem_utf8					CharToOemM;
__dllimport w32api_user_char_to_oem_utf16					CharToOemW;
__dllimport w32api_user_oem_to_char_ansi					OemToCharA;
__dllimport w32api_user_oem_to_char_utf8					OemToCharM;
__dllimport w32api_user_oem_to_char_utf16					OemToCharW;
__dllimport w32api_user_char_to_oem_buff_ansi					CharToOemBuffA;
__dllimport w32api_user_char_to_oem_buff_utf8					CharToOemBuffM;
__dllimport w32api_user_char_to_oem_buff_utf16					CharToOemBuffW;
__dllimport w32api_user_oem_to_char_buff_ansi					OemToCharBuffA;
__dllimport w32api_user_oem_to_char_buff_utf8					OemToCharBuffM;
__dllimport w32api_user_oem_to_char_buff_utf16					OemToCharBuffW;
__dllimport w32api_user_char_upper_ansi						CharUpperA;
__dllimport w32api_user_char_upper_utf8						CharUpperM;
__dllimport w32api_user_char_upper_utf16					CharUpperW;
__dllimport w32api_user_char_upper_buff_ansi					CharUpperBuffA;
__dllimport w32api_user_char_upper_buff_utf8					CharUpperBuffM;
__dllimport w32api_user_char_upper_buff_utf16					CharUpperBuffW;
__dllimport w32api_user_char_lower_ansi						CharLowerA;
__dllimport w32api_user_char_lower_utf8						CharLowerM;
__dllimport w32api_user_char_lower_utf16					CharLowerW;
__dllimport w32api_user_char_lower_buff_ansi					CharLowerBuffA;
__dllimport w32api_user_char_lower_buff_utf8					CharLowerBuffM;
__dllimport w32api_user_char_lower_buff_utf16					CharLowerBuffW;
__dllimport w32api_user_char_next_ansi						CharNextA;
__dllimport w32api_user_char_next_utf8						CharNextM;
__dllimport w32api_user_char_next_utf16						CharNextW;
__dllimport w32api_user_char_prev_ansi						CharPrevA;
__dllimport w32api_user_char_prev_utf8						CharPrevM;
__dllimport w32api_user_char_prev_utf16						CharPrevW;
__dllimport w32api_user_char_next_ex_ansi					CharNextExA;
__dllimport w32api_user_char_prev_ex_ansi					CharPrevExA;
__dllimport w32api_user_is_char_alpha_ansi					IsCharAlphaA;
__dllimport w32api_user_is_char_alpha_utf8					IsCharAlphaM;
__dllimport w32api_user_is_char_alpha_utf16					IsCharAlphaW;
__dllimport w32api_user_is_char_alpha_numeric_ansi				IsCharAlphaNumericA;
__dllimport w32api_user_is_char_alpha_numeric_utf8				IsCharAlphaNumericM;
__dllimport w32api_user_is_char_alpha_numeric_utf16				IsCharAlphaNumericW;
__dllimport w32api_user_is_char_upper_ansi					IsCharUpperA;
__dllimport w32api_user_is_char_upper_utf8					IsCharUpperM;
__dllimport w32api_user_is_char_upper_utf16					IsCharUpperW;
__dllimport w32api_user_is_char_lower_ansi					IsCharLowerA;
__dllimport w32api_user_is_char_lower_utf8					IsCharLowerM;
__dllimport w32api_user_is_char_lower_utf16					IsCharLowerW;
__dllimport w32api_user_set_focus						SetFocus;
__dllimport w32api_user_get_active_window					GetActiveWindow;
__dllimport w32api_user_get_focus						GetFocus;
__dllimport w32api_user_get_kb_code_page					GetKBCodePage;
__dllimport w32api_user_get_key_state						GetKeyState;
__dllimport w32api_user_get_async_key_state					GetAsyncKeyState;
__dllimport w32api_user_get_keyboard_state					GetKeyboardState;
__dllimport w32api_user_set_keyboard_state					SetKeyboardState;
__dllimport w32api_user_GetKeyNameText_ansi					GetKeyNameTextA;
__dllimport w32api_user_get_key_name_text_utf8					GetKeyNameTextM;
__dllimport w32api_user_get_key_name_text_utf16					GetKeyNameTextW;
__dllimport w32api_user_get_keyboard_type					GetKeyboardType;
__dllimport w32api_user_to_ascii						ToAscii;
__dllimport w32api_user_to_ascii_ex						ToAsciiEx;
__dllimport w32api_user_to_unicode						ToUnicode;
__dllimport w32api_user_oem_key_scan						OemKeyScan;
__dllimport w32api_user_vk_key_scan_ansi					VkScanA;
__dllimport w32api_user_vk_key_scan_utf8					VkScanM;
__dllimport w32api_user_vk_key_scan_utf16					VkScanW;
__dllimport w32api_user_vk_key_scan_ex_ansi					VkKeyScanExA;
__dllimport w32api_user_vk_key_scan_ex_utf8					VkKeyScanExM;
__dllimport w32api_user_vk_key_scan_ex_utf16					VkKeyScanExW;
__dllimport w32api_user_keybd_event						KeybdEvent;
__dllimport w32api_user_mouse_event						MouseEvent;
__dllimport w32api_user_send_input						SendInput;
__dllimport w32api_user_get_touch_input_info					GetTouchInputInfo;
__dllimport w32api_user_close_touch_input_handle				CloseTouchInputHandle;
__dllimport w32api_user_register_touch_window					RegisterTouchWindow;
__dllimport w32api_user_unregister_touch_window					UnregisterTouchWindow;
__dllimport w32api_user_is_touch_window						IsTouchWindow;
__dllimport w32api_user_initialize_touch_injection				InitializeTouchInjection;
__dllimport w32api_user_inject_touch_input					InjectTouchInput;
__dllimport w32api_user_get_pointer_type					GetPointerType;
__dllimport w32api_user_get_pointer_cursor_id					GetPointerCursorId;
__dllimport w32api_user_get_pointer_info					GetPointerInfo;
__dllimport w32api_user_get_pointer_info_history				GetPointerInfoHistory;
__dllimport w32api_user_get_pointer_frame_info					GetPointerFrameInfo;
__dllimport w32api_user_get_pointer_frame_info_history				GetPointerFrameInfoHistory;
__dllimport w32api_user_get_pointer_touch_info					GetPointerTouchInfo;
__dllimport w32api_user_get_pointer_touch_info_history				GetPointerTouchInfoHistory;
__dllimport w32api_user_get_pointer_frame_touch_info				GetPointerFrameTouchInfo;
__dllimport w32api_user_get_pointer_frame_touch_info_history			GetPointerFrameTouchInfoHistory;
__dllimport w32api_user_get_pointer_pen_info					GetPointerPenInfo;
__dllimport w32api_user_get_pointer_pen_info_history				GetPointerPenInfoHistory;
__dllimport w32api_user_get_pointer_frame_pen_info				GetPointerFramePenInfo;
__dllimport w32api_user_get_pointer_frame_pen_info_history			GetPointerFramePenInfoHistory;
__dllimport w32api_user_skip_pointer_frame_messages				SkipPointerFrameMessages;
__dllimport w32api_user_register_pointer_input_target				RegisterPointerInputTarget;
__dllimport w32api_user_unregister_pointer_input_target				UnregisterPointerInputTarget;
__dllimport w32api_user_enable_mouse_in_pointer					EnableMouseInPointer;
__dllimport w32api_user_is_mouse_in_pointer_enabled				IsMouseInPointerEnabled;
__dllimport w32api_user_register_touch_hit_testing_window			RegisterTouchHitTestingWindow;
__dllimport w32api_user_evaluate_proximity_to_rect				EvaluateProximityToRect;
__dllimport w32api_user_evaluate_proximity_to_polygon				EvaluateProximityToPolygon;
__dllimport w32api_user_pack_touch_hit_testing_proximity_evaluation		PackTouchHitTestingProximityEvaluation;
__dllimport w32api_user_get_window_feedback_setting				GetWindowFeedbackSetting;
__dllimport w32api_user_set_window_feedback_setting				SetWindowFeedbackSetting;
__dllimport w32api_user_get_last_input_info					GetLastInputInfo;
__dllimport w32api_user_map_virtual_key_ansi					MapVirtualKeyA;
__dllimport w32api_user_map_virtual_key_utf8					MapVirtualKeyM;
__dllimport w32api_user_map_virtual_key_utf16					MapVirtualKeyW;
__dllimport w32api_user_map_virtual_key_ex_ansi					MapVirtualKeyExA;
__dllimport w32api_user_map_virtual_key_ex_utf8					MapVirtualKeyExM;
__dllimport w32api_user_map_virtual_key_ex_utf16				MapVirtualKeyExW;
__dllimport w32api_user_get_input_state						GetInputState;
__dllimport w32api_user_GetQueueStatus						GetQueueStatus;
__dllimport w32api_user_get_capture						GetCapture;
__dllimport w32api_user_set_capture						SetCapture;
__dllimport w32api_user_release_capture						ReleaseCapture;
__dllimport w32api_user_msg_wait_for_multiple_objects				MsgWaitForMultipleObjects;
__dllimport w32api_user_msg_wait_for_multiple_objects_ex			MsgWaitForMultipleObjectsEx;
__dllimport w32api_user_set_timer						SetTimer;
__dllimport w32api_user_kill_timer						KillTimer;
__dllimport w32api_user_is_window_unicode					IsWindowUnicode;
__dllimport w32api_user_enable_window						EnableWindow;
__dllimport w32api_user_is_window_enabled					IsWindowEnabled;
__dllimport w32api_user_load_accelerators_ansi					LoadAcceleratorsA;
__dllimport w32api_user_load_accelerators_utf8					LoadAcceleratorsM;
__dllimport w32api_user_load_accelerators_utf16					LoadAcceleratorsW;
__dllimport w32api_user_create_accelerator_table_ansi				CreateAcceleratorTableA;
__dllimport w32api_user_create_accelerator_table_utf8				CreateAcceleratorTableM;
__dllimport w32api_user_create_accelerator_table_utf16				CreateAcceleratorTableW;
__dllimport w32api_user_destroy_accelerator_table				DestroyAccelerator;
__dllimport w32api_user_copy_accelerator_table_ansi				CopyAcceleratorTableA;
__dllimport w32api_user_copy_accelerator_table_utf8				CopyAcceleratorTableM;
__dllimport w32api_user_copy_accelerator_table_utf16				CopyAcceleratorTableW;
__dllimport w32api_user_translate_accelerator_ansi				TranslateAcceleratorA;
__dllimport w32api_user_translate_accelerator_utf8				TranslateAcceleratorM;
__dllimport w32api_user_translate_accelerator_utf16				TranslateAcceleratorW;
__dllimport w32api_user_set_coalescable_timer					SetCoalescableTimer;
__dllimport w32api_user_get_system_metrics					GetSystemMetrics;
__dllimport w32api_user_load_menu_ansi						LoadMenuA;
__dllimport w32api_user_load_menu_utf8						LoadMenuM;
__dllimport w32api_user_load_menu_utf16						LoadMenuW;
__dllimport w32api_user_load_menu_indirect_ansi					LoadMenuIndirectA;
__dllimport w32api_user_load_menu_indirect_utf8					LoadMenuIndirectM;
__dllimport w32api_user_load_menu_indirect_utf16				LoadMenuIndirectW;
__dllimport w32api_user_get_menu						GetMenu;
__dllimport w32api_user_set_menu						SetMenu;
__dllimport w32api_user_change_menu_ansi					ChangeMenuA;
__dllimport w32api_user_change_menu_utf8					ChangeMenuM;
__dllimport w32api_user_change_menu_utf16					ChangeMenuW;
__dllimport w32api_user_hilite_menu_item					HiliteMenuItem;
__dllimport w32api_user_get_menu_string_ansi					GetMenuStringA;
__dllimport w32api_user_get_menu_string_utf8					GetMenuStringM;
__dllimport w32api_user_get_menu_string_utf16					GetMenuStringW;
__dllimport w32api_user_get_menu_state						GetMenuState;
__dllimport w32api_user_draw_menu_bar						DrawMenuBar;
__dllimport w32api_user_get_system_menu						GetSystemMenu;
__dllimport w32api_user_create_menu						CreateMenu;
__dllimport w32api_user_create_popup_menu					CreatePopupMenu;
__dllimport w32api_user_destroy_menu						DestroyMenu;
__dllimport w32api_user_check_menu_item						CheckMenuItem;
__dllimport w32api_user_enable_menu_item					EnableMenuItem;
__dllimport w32api_user_get_sub_menu						GetSubMenu;
__dllimport w32api_user_get_menu_item_id					GetMenuItemID;
__dllimport w32api_user_get_menu_item_count					GetMenuItemCount;
__dllimport w32api_user_insert_menu_ansi					InsertMenuA;
__dllimport w32api_user_insert_menu_utf8					InsertMenuM;
__dllimport w32api_user_insert_menu_utf16					InsertMenuW;
__dllimport w32api_user_append_menu_ansi					AppendMenuA;
__dllimport w32api_user_append_menu_utf8					AppendMenuM;
__dllimport w32api_user_append_menu_utf16					AppendMenuW;
__dllimport w32api_user_modify_menu_ansi					ModifyMenuA;
__dllimport w32api_user_modify_menu_utf8					ModifyMenuM;
__dllimport w32api_user_modify_menu_utf16					ModifyMenuW;
__dllimport w32api_user_remove_menu						RemoveMenu;
__dllimport w32api_user_delete_menu						DeleteMenu;
__dllimport w32api_user_set_menu_item_bitmaps					SetMenuItemBitmaps;
__dllimport w32api_user_get_menu_check_mark_dimensions				GetCheckMarkDimensions;
__dllimport w32api_user_track_popup_menu					TrackPopupMenu;
__dllimport w32api_user_track_popup_menu_ex					TrackPopupMenuEx;
__dllimport w32api_user_get_menu_info						GetMenuInfo;
__dllimport w32api_user_set_menu_info						SetMenuInfo;
__dllimport w32api_user_end_menu						EndMenu;
__dllimport w32api_user_calculate_popup_window_position				CalculatePopupWindowPosition;
__dllimport w32api_user_insert_menu_item_ansi					InsertMenuItemA;
__dllimport w32api_user_insert_menu_item_utf8					InsertMenuItemM;
__dllimport w32api_user_insert_menu_item_utf16					InsertMenuItemW;
__dllimport w32api_user_get_menu_item_info_ansi					GetMenuItemInfoA;
__dllimport w32api_user_get_menu_item_info_utf8					GetMenuItemInfoM;
__dllimport w32api_user_get_menu_item_info_utf16				GetMenuItemInfoW;
__dllimport w32api_user_set_menu_item_info_ansi					SetMenuItemInfoA;
__dllimport w32api_user_set_menu_item_info_utf8					SetMenuItemInfoM;
__dllimport w32api_user_set_menu_item_info_utf16				SetMenuItemInfoW;
__dllimport w32api_user_get_menu_default_item					GetMenuDefaultItem;
__dllimport w32api_user_set_menu_default_item					SetMenuDefaultItem;
__dllimport w32api_user_get_menu_item_rect					GetMenuItemRect;
__dllimport w32api_user_menu_item_from_point					MenuItemFromPoint;
__dllimport w32api_user_drag_object						DragObject;
__dllimport w32api_user_drag_detect						DragDetect;
__dllimport w32api_user_draw_icon						DrawIcon;
__dllimport w32api_user_draw_text_ansi						DrawTextA;
__dllimport w32api_user_draw_text_utf8						DrawTextM;
__dllimport w32api_user_draw_text_utf16						DrawTextW;
__dllimport w32api_user_draw_text_ex_ansi					DrawTextExA;
__dllimport w32api_user_draw_text_ex_utf8					DrawTextExM;
__dllimport w32api_user_draw_text_ex_utf16					DrawTextExW;
__dllimport w32api_user_gray_string_ansi					GrayStringA;
__dllimport w32api_user_gray_string_utf8					GrayStringM;
__dllimport w32api_user_gray_string_utf16					GrayStringW;
__dllimport w32api_user_draw_state_ansi						DrawStateA;
__dllimport w32api_user_draw_state_utf8						DrawStateM;
__dllimport w32api_user_draw_state_utf16					DrawStateW;
__dllimport w32api_user_tabbed_text_out_ansi					TabbedTextOutA;
__dllimport w32api_user_tabbed_text_out_utf8					TabbedTextOutM;
__dllimport w32api_user_tabbed_text_out_utf16					TabbedTextOutW;
__dllimport w32api_user_get_tabbed_text_extent_ansi				GetTabbedTextExtentA;
__dllimport w32api_user_get_tabbed_text_extent_utf8				GetTabbedTextExtentM;
__dllimport w32api_user_get_tabbed_text_extent_utf16				GetTabbedTextExtentW;
__dllimport w32api_user_update_window						UpdateWindow;
__dllimport w32api_user_set_active_window					SetActiveWindow;
__dllimport w32api_user_get_foreground_window					GetForegroundWindow;
__dllimport w32api_user_paint_desktop						PaintDesktop;
__dllimport w32api_user_switch_to_this_window					SwitchToThisWindow;
__dllimport w32api_user_SetForegroundWindow					SetForegroundWindow;
__dllimport w32api_user_allow_set_foreground_window				AllowSetForegroundWindow;
__dllimport w32api_user_lock_set_foreground_window				LockSetForegroundWindow;
__dllimport w32api_user_window_from_dc						WindowFromDC;
__dllimport w32api_user_get_dc							GetDC;
__dllimport w32api_user_get_dc_ex						GetDCEx;
__dllimport w32api_user_get_window_dc						GetWindowDC;
__dllimport w32api_user_release_dc						ReleaseDC;
__dllimport w32api_user_begin_paint						BeginPaint;
__dllimport w32api_user_end_paint						EndPaint;
__dllimport w32api_user_get_update_rect						GetUpdateRect;
__dllimport w32api_user_get_update_rgn						GetUpdateRgn;
__dllimport w32api_user_set_window_rgn						SetWindowRgn;
__dllimport w32api_user_get_window_rgn						GetWindowRgn;
__dllimport w32api_user_get_window_rgn_box					GetWindowRgnBox;
__dllimport w32api_user_exclude_update_rgn					ExcludeUpdateRgn;
__dllimport w32api_user_invalidate_rect						InvalidateRect;
__dllimport w32api_user_validate_rect						ValidateRect;
__dllimport w32api_user_invalidate_rgn						InvalidateRgn;
__dllimport w32api_user_validate_rgn						ValidateRgn;
__dllimport w32api_user_redraw_window						RedrawWindow;
__dllimport w32api_user_lock_window_update					LockWindowUpdate;
__dllimport w32api_user_scroll_window						ScrollWindow;
__dllimport w32api_user_scroll_dc						ScrollDC;
__dllimport w32api_user_scroll_window_ex					ScrollWindowEx;
__dllimport w32api_user_set_scroll_pos						SetScrollPos;
__dllimport w32api_user_get_scroll_pos						GetScrollPos;
__dllimport w32api_user_set_scroll_range					SetScrollRange;
__dllimport w32api_user_get_scroll_range					GetScrollRange;
__dllimport w32api_user_show_scroll_bar						ShowScrollBar;
__dllimport w32api_user_enable_scroll_bar					EnableScrollBar;
__dllimport w32api_user_set_prop_ansi						SetPropA;
__dllimport w32api_user_set_prop_utf8						SetPropM;
__dllimport w32api_user_set_prop_utf16						SetPropW;
__dllimport w32api_user_get_prop_ansi						GetPropA;
__dllimport w32api_user_get_prop_utf8						GetPropM;
__dllimport w32api_user_get_prop_utf16						GetPropW;
__dllimport w32api_user_remove_prop_ansi					RemovePropA;
__dllimport w32api_user_remove_prop_utf8					RemovePropM;
__dllimport w32api_user_remove_prop_utf16					RemovePropW;
__dllimport w32api_user_enum_props_ex_ansi					EnumPropsExA;
__dllimport w32api_user_enum_props_ex_utf8					EnumPropsExM;
__dllimport w32api_user_enum_props_ex_utf16					EnumPropsExW;
__dllimport w32api_user_enum_props_ansi						EnumPropsA;
__dllimport w32api_user_enum_props_utf8						EnumPropsM;	
__dllimport w32api_user_enum_props_utf16					EnumPropsW;
__dllimport w32api_user_set_window_text_ansi					SetWindowTextA;
__dllimport w32api_user_set_window_text_utf8					SetWindowTextM;
__dllimport w32api_user_set_window_text_utf16					SetWindowTextW;
__dllimport w32api_user_get_window_text_ansi					GetWindowTextA;
__dllimport w32api_user_get_window_text_utf8					GetWindowTextM;
__dllimport w32api_user_get_window_text_utf16					GetWindowTextW;
__dllimport w32api_user_get_window_text_length_ansi				GetWindowTextLengthA;
__dllimport w32api_user_get_window_text_length_utf8				GetWindowTextLengthM;
__dllimport w32api_user_get_window_text_length_utf16				GetWindowTextLengthW;
__dllimport w32api_user_get_client_rect						GetClientRect;
__dllimport w32api_user_get_window_rect						GetWindowRect;
__dllimport w32api_user_adjust_window_rect					AdjustWindowRect;
__dllimport w32api_user_adjust_window_rect_ex					AdjustWindowRectEx;
__dllimport w32api_user_set_window_context_help_id				SetWindowContextHelpID;
__dllimport w32api_user_get_window_context_help_id				GetWindowContextHelpID;
__dllimport w32api_user_set_menu_context_help_id				SetMenuContextHelpID;
__dllimport w32api_user_get_menu_context_help_id				GetMenuContextHelpID;
__dllimport w32api_user_message_box_ansi					MessageBoxA;
__dllimport w32api_user_message_box_utf8					MessageBoxM;
__dllimport w32api_user_message_box_utf16					MessageBoxW;
__dllimport w32api_user_message_box_ex_ansi					MessageBoxExA;
__dllimport w32api_user_message_box_ex_utf8					MessageBoxExM;
__dllimport w32api_user_message_box_ex_utf16					MessageBoxExW;
__dllimport w32api_user_message_box_indirect_ansi				MessageBoxIndirectA;
__dllimport w32api_user_message_box_indirect_utf8				MessageBoxIndirectM;
__dllimport w32api_user_message_box_indirect_utf16				MessageBoxIndirectW;
__dllimport w32api_user_message_beep						MessageBeep;
__dllimport w32api_user_show_cursor						ShowCursor;
__dllimport w32api_user_set_cursor_pos						SetCursorPos;
__dllimport w32api_user_set_cursor						SetCursor;
__dllimport w32api_user_get_cursor_pos						GetCursorPos;
__dllimport w32api_user_clip_cursor						ClipCursor;
__dllimport w32api_user_get_clip_cursor						GetClipCursor;
__dllimport w32api_user_get_cursor						GetCursor;
__dllimport w32api_user_create_caret						CreateCaret;
__dllimport w32api_user_get_caret_blink_time					GetCaretBlinkTime;
__dllimport w32api_user_set_caret_blink_time					SetCaretBlinkTime;
__dllimport w32api_user_destroy_caret						DestroyCaret;
__dllimport w32api_user_hide_caret						HideCaret;
__dllimport w32api_user_show_caret						ShowCaret;
__dllimport w32api_user_set_caret_pos						SetCaretPos;
__dllimport w32api_user_get_caret_pos						GetCaretPos;
__dllimport w32api_user_client_to_screen					ClientToScreen;
__dllimport w32api_user_screen_to_client					ScreenToClient;
__dllimport w32api_user_map_window_points					MapWindowPoints;
__dllimport w32api_user_window_from_point					WindowFromPoint;
__dllimport w32api_user_child_window_from_point					ChildWindowFromPoint;
__dllimport w32api_user_child_window_from_point_ex				ChildWindowFromFromEx;
__dllimport w32api_user_set_physical_cursor_pos					SetPhysicalCursorPos;
__dllimport w32api_user_get_physical_cursor_pos					GetPhysicalCursorPos;
__dllimport w32api_user_logical_to_physical_point				LogicalToPhysicalPoint;
__dllimport w32api_user_physical_to_logical_point				PhysicalToLogicalPoint;
__dllimport w32api_user_window_from_physical_point				WindowFromPhysicalPoint;
__dllimport w32api_user_get_sys_color						GetSysColor;
__dllimport w32api_user_get_sys_color_brush					GetSysColorBrush;
__dllimport w32api_user_set_sys_colors						SetSysColors;
__dllimport w32api_user_draw_focus_rect						DrawFocusRect;
__dllimport w32api_user_fill_rect						FillRect;
__dllimport w32api_user_frame_rect						FrameRect;
__dllimport w32api_user_invert_rect						InvertRect;
__dllimport w32api_user_set_rect						SetRect;
__dllimport w32api_user_set_rect_empty						SetRectEmpty;
__dllimport w32api_user_copy_rect						CopyRect;
__dllimport w32api_user_inflate_rect						InflateRect;
__dllimport w32api_user_intersect_rect						IntersectRect;
__dllimport w32api_user_union_rect						UnionRect;
__dllimport w32api_user_subtract_rect						SubtractRect;
__dllimport w32api_user_offset_rect						OffsetRect;
__dllimport w32api_user_is_rect_empty						IsRectEmpty;
__dllimport w32api_user_equal_rect						EqualRect;
__dllimport w32api_user_pt_in_rect						PtInRect;
__dllimport w32api_user_get_window_word						GetWindowWord;
__dllimport w32api_user_set_window_word						SetWindowWord;
__dllimport w32api_user_get_window_long_ansi					GetWindowLongA;
__dllimport w32api_user_get_window_long_utf8					GetWindowLongM;
__dllimport w32api_user_get_window_long_utf16					GetWindowLongW;
__dllimport w32api_user_set_window_long_ansi					SetWindowLongA;
__dllimport w32api_user_set_window_long_utf8					SetWindowLongM;
__dllimport w32api_user_set_window_long_utf16					SetWindowLongW;
__dllimport w32api_user_get_class_word						GetClassWord;
__dllimport w32api_user_set_class_word						SetClassWord;
__dllimport w32api_user_get_class_long_ansi					GetClassLongA;
__dllimport w32api_user_get_class_long_utf8					GetClassLongM;
__dllimport w32api_user_get_class_long_utf16					GetClassLongW;
__dllimport w32api_user_set_class_long_ansi					SetClassLongA;
__dllimport w32api_user_set_class_long_utf8					SetClassLongM;
__dllimport w32api_user_set_class_long_utf16					SetClassLongW;
__dllimport w32api_user_get_process_default_layout				GetProcessDefaultLayout;
__dllimport w32api_user_set_process_default_layout				SetProcessDefaultLayout;
__dllimport w32api_user_get_desktop_window					GetDesktopWindow;
__dllimport w32api_user_get_parent						GetParent;
__dllimport w32api_user_set_parent						SetParent;
__dllimport w32api_user_enum_child_windows					EnumChildWindows;
__dllimport w32api_user_find_window_ansi					FindWindowA;
__dllimport w32api_user_find_window_utf8					FindWindowM;
__dllimport w32api_user_find_window_utf16					FindWindowW;
__dllimport w32api_user_find_window_ex_ansi					FindWindowExA;
__dllimport w32api_user_find_window_ex_utf8					FindWindowExM;
__dllimport w32api_user_find_window_ex_utf16					FindWindowExW;
__dllimport w32api_user_get_shell_window					GetShellWindow;
__dllimport w32api_user_register_shell_hook_window				RegisterShellHookWindow;
__dllimport w32api_user_deregister_shell_hook_window				DeregisterShellHookWindow;
__dllimport w32api_user_enum_windows						EnumWindows;
__dllimport w32api_user_enum_thread_windows					EnumThreadWindows;
__dllimport w32api_user_get_class_name_ansi					GetClassNameA;
__dllimport w32api_user_get_class_name_utf8					GetClassNameM;
__dllimport w32api_user_get_class_name_utf16					GetClassNameW;
__dllimport w32api_user_get_top_window						GetTopWindow;
__dllimport w32api_user_get_window_thread_process_id				GetWindowThreadProcessID;
__dllimport w32api_user_is_gui_thread						IsGUIThread;
__dllimport w32api_user_get_last_active_popup					GetLastActivePopup;
__dllimport w32api_user_get_window						GetWindow;
__dllimport w32api_user_set_windows_hook_ansi					SetWindowHookA;
__dllimport w32api_user_set_windows_hook_utf8					SetWindowHookM;
__dllimport w32api_user_set_windows_hook_utf16					SetWindowHookW;
__dllimport w32api_user_unhook_windows_hook					UnhookWindowsHook;
__dllimport w32api_user_set_windows_hook_ex_ansi				SetWindowsHookExA;
__dllimport w32api_user_set_windows_hook_ex_utf8				SetWindowsHookExM;
__dllimport w32api_user_set_windows_hook_ex_utf16				SetWindowsHookExW;
__dllimport w32api_user_unhook_windows_hook_ex					UnhookWindowsHookEx;
__dllimport w32api_user_call_next_hook_ex					CallNextHookEx;
__dllimport w32api_user_check_menu_radio_item					CheckMenuRadioItem;
__dllimport w32api_user_load_bitmap_ansi					LoadBitmapA;
__dllimport w32api_user_load_bitmap_utf8					LoadBitmapM;
__dllimport w32api_user_load_bitmap_utf16					LoadBitmapW;
__dllimport w32api_user_load_cursor_ansi					LoadCursorA;
__dllimport w32api_user_load_cursor_utf8					LoadCursorM;
__dllimport w32api_user_load_cursor_utf16					LoadCursorW;
__dllimport w32api_user_load_cursor_from_file_ansi				LoadCursorFromFileA;
__dllimport w32api_user_load_cursor_from_file_utf8				LoadCursorFromFileM;
__dllimport w32api_user_load_cursor_from_file_utf16				LoadCursorFromFileW;
__dllimport w32api_user_create_cursor						CreateCursor;
__dllimport w32api_user_destroy_cursor						DestroyCursor;
__dllimport w32api_user_set_system_cursor					SetSystemCursor;
__dllimport w32api_user_load_icon_ansi						LoadIconA;
__dllimport w32api_user_load_icon_utf8						LoadIconM;
__dllimport w32api_user_load_icon_utf16						LoadIconW;
__dllimport w32api_user_private_extract_icons_ansi				PrivateExtractIconsA;
__dllimport w32api_user_private_extract_icons_utf8				PrivateExtractIconsM;
__dllimport w32api_user_private_extract_icons_utf16				PrivateExtractIconsW;
__dllimport w32api_user_create_icon						CreateIcon;
__dllimport w32api_user_destroy_icon						DestroyIcon;
__dllimport w32api_user_lookup_icon_id_from_directory				LookupIconIDFromDirectory;
__dllimport w32api_user_lookup_icon_id_from_directory_ex			LookupIconIDFromDirectoryEx;
__dllimport w32api_user_create_icon_from_resource				CreateIconFromResource;
__dllimport w32api_user_create_icon_from_resource_ex				CreateIconFromResourceEx;
__dllimport w32api_user_load_image_ansi						LoadImageA;
__dllimport w32api_user_load_image_utf8						LoadImageM;
__dllimport w32api_user_load_image_utf16					LoadImageW;
__dllimport w32api_user_copy_image						CopyImage;
__dllimport w32api_user_draw_icon_ex						DrawIconEx;
__dllimport w32api_user_create_icon_indirect					CreateIconIndirect;
__dllimport w32api_user_copy_icon						CopyIcon;
__dllimport w32api_user_get_icon_info						GetIconInfo;
__dllimport w32api_user_get_icon_info_ex_ansi					GetIconInfoExA;
__dllimport w32api_user_get_icon_info_ex_utf8					GetIconInfoExM;
__dllimport w32api_user_get_icon_info_ex_utf16					GetIconInfoExW;
__dllimport w32api_user_load_string_ansi					LoadStringA;
__dllimport w32api_user_load_string_utf8					LoadStringM;
__dllimport w32api_user_load_string_utf16					LoadStringW;
__dllimport w32api_user_is_dialog_message_ansi					IsDialogMessageA;
__dllimport w32api_user_is_dialog_message_utf8					IsDialogMessageM;
__dllimport w32api_user_is_dialog_message_utf16					IsDialogMessageW;
__dllimport w32api_user_map_dialog_rect						MapDialogRect;
__dllimport w32api_user_dlg_dir_list_ansi					DlgDirListA;
__dllimport w32api_user_dlg_dir_list_utf8					DlgDirListM;
__dllimport w32api_user_dlg_dir_list_utf16					DlgDirListW;
__dllimport w32api_user_dlg_dir_select_ex_ansi					DlgDirSelectExA;
__dllimport w32api_user_dlg_dir_select_ex_utf8					DlgDirSelectExM;
__dllimport w32api_user_dlg_dir_select_ex_utf16					DlgDirSelectExW;
__dllimport w32api_user_dlg_dir_list_combo_box_ansi				DlgDirListComboBoxA;
__dllimport w32api_user_dlg_dir_list_combo_box_utf8				DlgDirListComboBoxM;
__dllimport w32api_user_dlg_dir_list_combo_box_utf16				DlgDirListComboBoxW;
__dllimport w32api_user_dlg_dir_select_combo_box_ex_ansi			DlgDirSelectComboBoxExA;
__dllimport w32api_user_dlg_dir_select_combo_box_ex_utf8			DlgDirSelectComboBoxExM;
__dllimport w32api_user_dlg_dir_select_combo_box_ex_utf16			DlgDirSelectComboBoxExW;
__dllimport w32api_user_set_scroll_info						SetScrollInfo;
__dllimport w32api_user_get_scroll_info						GetScrollInfo;
__dllimport w32api_user_def_frame_proc_ansi					DefFrameProcA;
__dllimport w32api_user_def_frame_proc_utf8					DefFrameProcM;
__dllimport w32api_user_def_frame_proc_utf16					DefFrameProcW;
__dllimport w32api_user_def_mdi_child_proc_ansi					DefMDIChildProcA;
__dllimport w32api_user_def_mdi_child_proc_utf8					DefMDIChildProcM;
__dllimport w32api_user_def_mdi_child_proc_utf16				DefMDIChildProcW;
__dllimport w32api_user_translate_mdi_sys_accel					TranslateMDISysAccel;
__dllimport w32api_user_arrange_iconic_windows					ArrangeIconicWindows;
__dllimport w32api_user_create_mdi_window_ansi					CreateMDIWindowA;
__dllimport w32api_user_create_mdi_window_utf8					CreateMDIWindowM;
__dllimport w32api_user_create_mdi_window_utf16					CreateMDIWindowW;
__dllimport w32api_user_tile_windows						TileWindows;
__dllimport w32api_user_cascade_windows						CascadeWindows;
__dllimport w32api_user_win_help_ansi						WinHelpA;
__dllimport w32api_user_win_help_utf8						WinHelpM;
__dllimport w32api_user_win_help_utf16						WinHelpW;
__dllimport w32api_user_get_gui_resources					GetGUIResources;
__dllimport w32api_user_change_display_settings_ansi				ChangeDisplaySettingsA;
__dllimport w32api_user_change_display_settings_utf8				ChangeDisplaySettingsM;
__dllimport w32api_user_change_display_settings_utf16				ChangeDisplaySettingsW;
__dllimport w32api_user_change_display_settings_ex_ansi				ChangeDisplaySettingsExA;
__dllimport w32api_user_change_display_settings_ex_utf8				ChangeDisplaySettingsExM;
__dllimport w32api_user_change_display_settings_ex_utf16			ChangeDisplaySettingsExW;
__dllimport w32api_user_enum_display_settings_ansi				EnumDisplaySettingsA;
__dllimport w32api_user_enum_display_settings_utf8				EnumDisplaySettingsM;
__dllimport w32api_user_enum_display_settings_utf16				EnumDisplaySettingsW;
__dllimport w32api_user_enum_display_settings_ex_ansi				EnumDisplaySettingsExA;
__dllimport w32api_user_enum_display_settings_ex_utf8				EnumDisplaySettingsExM;
__dllimport w32api_user_enum_display_settings_ex_utf16				EnumDisplaySettingsExW;
__dllimport w32api_user_enum_display_devices_ansi				EnumDisplayDevicesA;
__dllimport w32api_user_enum_display_devices_utf8				EnumDisplayDevicesM;
__dllimport w32api_user_enum_display_devices_utf16				EnumDisplayDevicesW;
__dllimport w32api_user_get_display_config_buffer_sizes				GetDisplayConfigBufferSizes;
__dllimport w32api_user_set_display_config					SetDisplayConfig;
__dllimport w32api_user_query_display_config					QueryDisplayConfig;
__dllimport w32api_user_display_config_get_device_info				DisplayConfigGetDeviceInfo;
__dllimport w32api_user_display_config_set_device_info				DisplayConfigSetDeviceInfo;
__dllimport w32api_user_system_parameters_info_ansi				SystemParametersInfoA;
__dllimport w32api_user_system_parameters_info_utf8				SystemParametersInfoM;
__dllimport w32api_user_system_parameters_info_utf16				SystemParametersInfoW;
__dllimport w32api_user_set_debug_error_level					SetDebugErrorLevel;
__dllimport w32api_user_set_last_error_ex					SetLastErrorEx;
__dllimport w32api_user_internal_get_window_text				InternalGetWindowText;
__dllimport w32api_user_cancel_shutdown						CancelShutdown;
__dllimport w32api_user_monitor_from_point					MonitorFromPoint;
__dllimport w32api_user_monitor_from_rect					MonitorFromRect;
__dllimport w32api_user_monitor_from_window					MonitorFromWindow;
__dllimport w32api_user_end_task						EndTask;
__dllimport w32api_user_sound_sentry						SoundSentry;
__dllimport w32api_user_get_monitor_info_ansi					GetMonitorInfoA;
__dllimport w32api_user_get_monitor_info_utf8					GetMonitorInfoM;
__dllimport w32api_user_get_monitor_info_utf16					GetMonitorInfoW;
__dllimport w32api_user_enum_display_monitors					EnumDisplayMonitors;
__dllimport w32api_user_notify_win_event					NotifyWinEvent;
__dllimport w32api_user_set_win_event_hook					SetWinEventHook;
__dllimport w32api_user_is_win_event_hook_installed				IsWinEventHookInstalled;
__dllimport w32api_user_unhook_win_event					UnhookWinEvent;
__dllimport w32api_user_get_gui_thread_info					GetGUIThreadInfo;
__dllimport w32api_user_block_input						BlockInput;
__dllimport w32api_user_get_window_module_file_name_ansi			GetWindowModuleFileNameA;
__dllimport w32api_user_get_window_module_file_name_utf8			GetWindowModuleFileNameM;
__dllimport w32api_user_get_window_module_file_name_utf16			GetWindowModuleFileNameW;
__dllimport w32api_user_set_process_dpi_aware					SetProcessDPIAware;
__dllimport w32api_user_is_process_dpi_aware					IsProcessDPIAware;
__dllimport w32api_user_get_cursor_info						GetCursorInfo;
__dllimport w32api_user_get_window_info						GetWindowInfo;
__dllimport w32api_user_get_title_bar_info					GetTitleBarInfo;
__dllimport w32api_user_get_menu_bar_info					GetMenuBarInfo;
__dllimport w32api_user_get_combo_box_info					GetComboBoxInfo;
__dllimport w32api_user_get_ancestor						GetAncestor;
__dllimport w32api_user_real_child_window_from_point				RealChildWindowFromPoint;
__dllimport w32api_user_real_get_window_class_ansi				RealGetWindowClassA;
__dllimport w32api_user_real_get_window_class_utf8				RealGetWindowClassM;
__dllimport w32api_user_real_get_window_class_utf16				RealGetWindowClassW;
__dllimport w32api_user_get_alt_tab_info_ansi					GetAltTabInfoA;
__dllimport w32api_user_get_alt_tab_info_utf8					GetAltTabInfoM;
__dllimport w32api_user_get_alt_tab_info_utf16					GetAltTabInfoW;
__dllimport w32api_user_get_list_box_info					GetListBoxInfo;
__dllimport w32api_user_lock_work_station					LockWorkStation;
__dllimport w32api_user_user_handle_grant_access				HandleGrantAccess;
__dllimport w32api_user_get_raw_input_data					GetRawInputData;
__dllimport w32api_user_get_raw_input_device_info_ansi				GetRawInputDeviceInfoA;
__dllimport w32api_user_get_raw_input_device_info_utf8				GetRawInputDeviceInfoM;
__dllimport w32api_user_get_raw_input_device_info_utf16				GetRawInputDeviceInfoW;
__dllimport w32api_user_get_raw_input_buffer					GetRawInputBuffer;
__dllimport w32api_user_register_raw_input_devices				RegisterRawInputDevices;
__dllimport w32api_user_get_registered_raw_input_devices			GetRegisteredRawInputDevices;
__dllimport w32api_user_get_raw_input_device_list				GetRawInputDeviceList;
__dllimport w32api_user_def_raw_input_proc					GetRawInputProc;
__dllimport w32api_user_get_pointer_devices					GetPointerDevices;
__dllimport w32api_user_get_pointer_device					GetPointerDevice;
__dllimport w32api_user_get_pointer_device_properties				GetPointerDeviceProperties;
__dllimport w32api_user_register_pointer_device_notifications			RegisterPointerDeviceNotifications;
__dllimport w32api_user_get_pointer_device_rects				GetPointerDeviceRects;
__dllimport w32api_user_get_pointer_device_cursors				GetPointerDeviceCursors;
__dllimport w32api_user_get_raw_pointer_device_data				GetRawPointerDeviceData;
__dllimport w32api_user_change_window_message_filter				ChangeWindowMessageFilter;
__dllimport w32api_user_change_window_message_filter_ex				ChangeWindowMessageFilterEx;
__dllimport w32api_user_get_gesture_info					GetGestureInfo;
__dllimport w32api_user_get_gesture_extra_args					GetGestureExtraArgs;
__dllimport w32api_user_close_gesture_info_handle				CloseGestureInfoHandle;
__dllimport w32api_user_set_gesture_config					SetGestureConfig;
__dllimport w32api_user_get_gesture_config					GetGestureConfig;
__dllimport w32api_user_shutdown_block_reason_create				ShutdownBlockReasonCreate;
__dllimport w32api_user_shutdown_block_reason_query				ShutdownBlockReasonQuery;
__dllimport w32api_user_shutdown_block_reason_destroy				ShutdownBlockReasonDestroy;
__dllimport w32api_user_get_current_input_message_source			GetCurrentInputMessageSource;
__dllimport w32api_user_get_cimssm						GetCIMSSM;
__dllimport w32api_user_get_auto_rotation_state					GetAutoRotationState;
__dllimport w32api_user_get_display_auto_rotation_preferences			GetDisplayAutoRotationPreferences;
__dllimport w32api_user_get_display_auto_rotation_preferences_by_process_id	GetDisplayAutoRotationPreferencesByProcessID;
__dllimport w32api_user_set_display_auto_rotation_preferences			SetDisplayAutoRotationPreferences;
__dllimport w32api_user_is_immersive_process					IsImmersiveProcess;
__dllimport w32api_user_set_process_restriction_exemption			SetProcessRestrictionExemption;
__dllimport w32api_user_get_pointer_input_transform				GetPointerInputTransform;
__dllimport w32api_user_is_mouse_pointer_enabled				IsMousePointerEnabled;
#ifdef __NT64
__dllimport w32api_user_get_window_long_ptr_ansi				GetWindowLongPtrA;
__dllimport w32api_user_get_window_long_ptr_utf8				GetWindowLongPtrM;
__dllimport w32api_user_get_window_long_ptr_utf16				GetWindowLongPtrW;
__dllimport w32api_user_set_window_long_ptr_ansi				SetWindowLongPtrA;
__dllimport w32api_user_set_window_long_ptr_utf8				SetWindowLongPtrM;
__dllimport w32api_user_set_window_long_ptr_utf16				SetWindowLongPtrW;
__dllimport w32api_user_get_class_long_ptr_ansi					GetClassLongPtrA;
__dllimport w32api_user_get_class_long_ptr_utf8					GetClassLongPtrM;
__dllimport w32api_user_get_class_long_ptr_utf16				GetClassLongPtrW;
__dllimport w32api_user_set_class_long_ptr_ansi					SetClassLongPtrA;
__dllimport w32api_user_set_class_long_ptr_utf8					SetClassLongPtrM;
__dllimport w32api_user_set_class_long_ptr_utf16				SetClassLongPtrW;
#endif



#ifdef WINAPI_ANSI_DEFAULT
#define wvsprintf				wvsprintfA
#define wsprintf				wsprintfA
#define LoadKeyboardLayout			LoadKeyboardLayoutA
#define GetKeyboardLayoutName			GetKeyboardLayoutNameA
#define CreateDesktop				CreateDesktopA
#define CreateDesktopEx				CreateDesktopExA
#define OpenDesktop				OpenDesktopA
#define EnumDesktops				EnumDesktopsA
#define CreateWindowStation			CreateWindowStationA
#define OpenWindowStation			OpenWindowStationA
#define EnumWindowStations			EnumWindowStationsA
#define GetUserObjectInformation		GetUserObjectInformationM
#define SetUserObjectInformation		SetUserObjectInformationA
#define RegisterWindowMessage			RegisterWindowMessageA
#define GetMessage				GetMessageA
#define DispatchMessage				DispatchMessageA
#define PeekMessage				PeekMessageA
#define SendMessage				SendMessageA
#define SendMessageTimeout			SendMessageTimeoutA
#define SendNotifyMessage			SendNotifyMessageA
#define SendMessageCallback			SendMessageCallbackA
#define BroadcastSystemMessageEx		BroadcastSystemMessageExA
#define BroadcastSystemMessage			BroadcastSystemMessageA
#define PostMessage				PostMessageA
#define PostThreadMessage			PostThreadMessageA
#define DefWindowProc				DefWindowProcA
#define RegisterClass				RegisterClassA
#define UnregisterClass				UnregisterClassA
#define GetClassInfo				GetClassInfoA
#define RegisterClassEx				RegisterClassExA
#define GetClassInfoEx				GetClassInfoExA
#define CallWindowProc				CallWindowProcA
#define RegisterDeviceNotification		RegisterDeviceNotificationA
#define CreateWindowEx				CreateWindowExA
#define CreateDialogParam			CreateDialogParamA
#define CreateDialogIndirectParam		CreateDialogIndirectParamA
#define DialogBoxParam				DialogBoxParamA
#define DialogBoxIndirectParam			DialogBoxIndirectParamA
#define SetDlgItemText				SetDlgItemTextA
#define GetDlgItemText				GetDlgItemTextA
#define SendDlgItemMessage			SendDlgItemMessageA
#define DefDlgProc				DefDlgProcA
#define CallMsgFilter				CallMsgFilterA
#define RegisterClipboardFormat			RegisterClipboardFormatA
#define GetClipboardFormatName			GetClipboardFormatNameA
#define CharToOem				CharToOemA
#define OemToChar				OemToCharA
#define CharToOemBuff				CharToOemBuffA
#define OemToCharBuff				OemToCharBuffA
#define CharUpper				CharUpperA
#define CharUpperBuff				CharUpperBuffA
#define CharLower				CharLowerA
#define CharLowerBuff				CharLowerBuffA
#define CharNext				CharNextA
#define CharPrev				CharPrevA
#define IsCharAlpha				IsCharAlphaA
#define IsCharAlphaNumeric			IsCharAlphaNumericA
#define IsCharUpper				IsCharUpperA
#define IsCharLower				IsCharLowerA
#define GetKeyNameText				GetKeyNameTextA
#define VkScanM					VkScanA
#define VkKeyScanEx				VkKeyScanExA
#define MapVirtualKey				MapVirtualKeyA
#define MapVirtualKeyEx				MapVirtualKeyExA
#define LoadAccelerators			LoadAcceleratorsA
#define CreateAcceleratorTable			CreateAcceleratorTableA
#define CopyAcceleratorTable			CopyAcceleratorTableA
#define TranslateAccelerator			TranslateAcceleratorA
#define LoadMenu				LoadMenuA
#define LoadMenuIndirect			LoadMenuIndirectA
#define ChangeMenu				ChangeMenuA
#define GetMenuString				GetMenuStringA
#define InsertMenu				InsertMenuA
#define AppendMenu				AppendMenuA
#define ModifyMenu				ModifyMenuA
#define InsertMenuItem				InsertMenuItemA
#define GetMenuItemInfo				GetMenuItemInfoA
#define SetMenuItemInfo				SetMenuItemInfoA
#define DrawText				DrawTextA
#define DrawTextEx				DrawTextExA
#define GrayString				GrayStringA
#define DrawState				DrawStateA
#define TabbedTextOut				TabbedTextOutA
#define GetTabbedTextExtent			GetTabbedTextExtentA
#define SetProp					SetPropA
#define GetProp					GetPropA
#define RemoveProp				RemovePropA
#define EnumPropsEx				EnumPropsExA
#define EnumProps				EnumPropsA
#define SetWindowText				SetWindowTextA
#define GetWindowText				GetWindowTextA
#define GetWindowTextLength			GetWindowTextLengthA
#define MessageBox				MessageBoxA
#define MessageBoxEx				MessageBoxExA
#define MessageBoxIndirect			MessageBoxIndirectA
#define GetWindowLong				GetWindowLongA
#define SetWindowLong				SetWindowLongA
#define GetClassLong				GetClassLongA
#define SetClassLong				SetClassLongA
#define FindWindow				FindWindowA
#define FindWindowEx				FindWindowExA
#define GetClassName				GetClassNameA
#define SetWindowHook				SetWindowHookA
#define SetWindowsHookEx			SetWindowsHookExA
#define LoadBitmap				LoadBitmapA
#define LoadCursor				LoadCursorA
#define LoadCursorFromFile			LoadCursorFromFileA
#define LoadIcon				LoadIconA
#define PrivateExtractIcons			PrivateExtractIconsA
#define LoadImage				LoadImageA
#define GetIconInfoEx				GetIconInfoExA
#define LoadString				LoadStringA
#define IsDialogMessage				IsDialogMessageA
#define DlgDirList				DlgDirListA
#define DlgDirSelectEx				DlgDirSelectExA
#define DlgDirListComboBox			DlgDirListComboBoxA
#define DlgDirSelectComboBoxEx			DlgDirSelectComboBoxExA
#define DefFrameProc				DefFrameProcA
#define DefMDIChildProc				DefMDIChildProcA
#define CreateMDIWindow				CreateMDIWindowA
#define WinHelp					WinHelpA
#define ChangeDisplaySettings			ChangeDisplaySettingsA
#define ChangeDisplaySettingsEx			ChangeDisplaySettingsExA
#define EnumDisplaySettings			EnumDisplaySettingsA
#define EnumDisplaySettingsEx			EnumDisplaySettingsExA
#define EnumDisplayDevices			EnumDisplayDevicesA
#define SystemParametersInfo			SystemParametersInfoA
#define GetMonitorInfo				GetMonitorInfoA
#define GetWindowModuleFileName			GetWindowModuleFileNameA
#define RealGetWindowClass			RealGetWindowClassA
#define GetAltTabInfo				GetAltTabInfoA
#define GetRawInputDeviceInfo			GetRawInputDeviceInfoA
#define GetWindowLongPtr			GetWindowLongPtrA
#define SetWindowLongPtr			SetWindowLongPtrA
#define GetClassLongPtr				GetClassLongPtrA
#define SetClassLongPtr				SetClassLongPtrA
#endif



#ifdef WINAPI_UTF8_DEFAULT
#define wvsprintf				wvsprintfM
#define wsprintf				wsprintfM
#define LoadKeyboardLayout			LoadKeyboardLayoutM
#define GetKeyboardLayoutName			GetKeyboardLayoutNameM
#define CreateDesktop				CreateDesktopM
#define CreateDesktopEx				CreateDesktopExM
#define OpenDesktop				OpenDesktopM
#define EnumDesktops				EnumDesktopsM
#define CreateWindowStation			CreateWindowStationM
#define OpenWindowStation			OpenWindowStationM
#define EnumWindowStations			EnumWindowStationsM
#define GetUserObjectInformation		GetUserObjectInformationM
#define SetUserObjectInformation		SetUserObjectInformationM
#define RegisterWindowMessage			RegisterWindowMessageM
#define GetMessage				GetMessageM
#define DispatchMessage				DispatchMessageM
#define PeekMessage				PeekMessageM
#define SendMessage				SendMessageM
#define SendMessageTimeout			SendMessageTimeoutM
#define SendNotifyMessage			SendNotifyMessageM
#define SendMessageCallback			SendMessageCallbackM
#define BroadcastSystemMessageEx		BroadcastSystemMessageExM
#define BroadcastSystemMessage			BroadcastSystemMessageM
#define PostMessage				PostMessageM
#define PostThreadMessage			PostThreadMessageM
#define DefWindowProc				DefWindowProcM
#define RegisterClass				RegisterClassM
#define UnregisterClass				UnregisterClassM
#define GetClassInfo				GetClassInfoM
#define RegisterClassEx				RegisterClassExM
#define GetClassInfoEx				GetClassInfoExM
#define CallWindowProc				CallWindowProcM
#define RegisterDeviceNotification		RegisterDeviceNotificationM
#define CreateWindowEx				CreateWindowExM
#define CreateDialogParam			CreateDialogParamM
#define CreateDialogIndirectParam		CreateDialogIndirectParamM
#define DialogBoxParam				DialogBoxParamM
#define DialogBoxIndirectParam			DialogBoxIndirectParamM
#define SetDlgItemText				SetDlgItemTextM
#define GetDlgItemText				GetDlgItemTextM
#define SendDlgItemMessage			SendDlgItemMessageM
#define DefDlgProc				DefDlgProcM
#define CallMsgFilter				CallMsgFilterM
#define RegisterClipboardFormat			RegisterClipboardFormatM
#define GetClipboardFormatName			GetClipboardFormatNameM
#define CharToOem				CharToOemM
#define OemToChar				OemToCharM
#define CharToOemBuff				CharToOemBuffM
#define OemToCharBuff				OemToCharBuffM
#define CharUpper				CharUpperM
#define CharUpperBuff				CharUpperBuffM
#define CharLower				CharLowerM
#define CharLowerBuff				CharLowerBuffM
#define CharNext				CharNextM
#define CharPrev				CharPrevM
#define IsCharAlpha				IsCharAlphaM
#define IsCharAlphaNumeric			IsCharAlphaNumericM
#define IsCharUpper				IsCharUpperM
#define IsCharLower				IsCharLowerM
#define GetKeyNameText				GetKeyNameTextM
#define VkScanM					VkScanM
#define VkKeyScanEx				VkKeyScanExM
#define MapVirtualKey				MapVirtualKeyM
#define MapVirtualKeyEx				MapVirtualKeyExM
#define LoadAccelerators			LoadAcceleratorsM
#define CreateAcceleratorTable			CreateAcceleratorTableM
#define CopyAcceleratorTable			CopyAcceleratorTableM
#define TranslateAccelerator			TranslateAcceleratorM
#define LoadMenu				LoadMenuM
#define LoadMenuIndirect			LoadMenuIndirectM
#define ChangeMenu				ChangeMenuM
#define GetMenuString				GetMenuStringM
#define InsertMenu				InsertMenuM
#define AppendMenu				AppendMenuM
#define ModifyMenu				ModifyMenuM
#define InsertMenuItem				InsertMenuItemM
#define GetMenuItemInfo				GetMenuItemInfoM
#define SetMenuItemInfo				SetMenuItemInfoM
#define DrawText				DrawTextM
#define DrawTextEx				DrawTextExM
#define GrayString				GrayStringM
#define DrawState				DrawStateM
#define TabbedTextOut				TabbedTextOutM
#define GetTabbedTextExtent			GetTabbedTextExtentM
#define SetProp					SetPropM
#define GetProp					GetPropM
#define RemoveProp				RemovePropM
#define EnumPropsEx				EnumPropsExM
#define EnumProps				EnumPropsM
#define SetWindowText				SetWindowTextM
#define GetWindowText				GetWindowTextM
#define GetWindowTextLength			GetWindowTextLengthM
#define MessageBox				MessageBoxM
#define MessageBoxEx				MessageBoxExM
#define MessageBoxIndirect			MessageBoxIndirectM
#define GetWindowLong				GetWindowLongM
#define SetWindowLong				SetWindowLongM
#define GetClassLong				GetClassLongM
#define SetClassLong				SetClassLongM
#define FindWindow				FindWindowM
#define FindWindowEx				FindWindowExM
#define GetClassName				GetClassNameM
#define SetWindowHook				SetWindowHookM
#define SetWindowsHookEx			SetWindowsHookExM
#define LoadBitmap				LoadBitmapM
#define LoadCursor				LoadCursorM
#define LoadCursorFromFile			LoadCursorFromFileM
#define LoadIcon				LoadIconM
#define PrivateExtractIcons			PrivateExtractIconsM
#define LoadImage				LoadImageM
#define GetIconInfoEx				GetIconInfoExM
#define LoadString				LoadStringM
#define IsDialogMessage				IsDialogMessageM
#define DlgDirList				DlgDirListM
#define DlgDirSelectEx				DlgDirSelectExM
#define DlgDirListComboBox			DlgDirListComboBoxM
#define DlgDirSelectComboBoxEx			DlgDirSelectComboBoxExM
#define DefFrameProc				DefFrameProcM
#define DefMDIChildProc				DefMDIChildProcM
#define CreateMDIWindow				CreateMDIWindowM
#define WinHelp					WinHelpM
#define ChangeDisplaySettings			ChangeDisplaySettingsM
#define ChangeDisplaySettingsEx			ChangeDisplaySettingsExM
#define EnumDisplaySettings			EnumDisplaySettingsM
#define EnumDisplaySettingsEx			EnumDisplaySettingsExM
#define EnumDisplayDevices			EnumDisplayDevicesM
#define SystemParametersInfo			SystemParametersInfoM
#define GetMonitorInfo				GetMonitorInfoM
#define GetWindowModuleFileName			GetWindowModuleFileNameM
#define RealGetWindowClass			RealGetWindowClassM
#define GetAltTabInfo				GetAltTabInfoM
#define GetRawInputDeviceInfo			GetRawInputDeviceInfoM
#define GetWindowLongPtr			GetWindowLongPtrM
#define SetWindowLongPtr			SetWindowLongPtrM
#define GetClassLongPtr				GetClassLongPtrM
#define SetClassLongPtr				SetClassLongPtrM
#endif



#ifdef WINAPI_UTF16_DEFAULT
#define wvsprintf				wvsprintfW
#define wsprintf				wsprintfW
#define LoadKeyboardLayout			LoadKeyboardLayoutW
#define GetKeyboardLayoutName			GetKeyboardLayoutNameW
#define CreateDesktop				CreateDesktopW
#define CreateDesktopEx				CreateDesktopExW
#define OpenDesktop				OpenDesktopW
#define EnumDesktops				EnumDesktopsW
#define CreateWindowStation			CreateWindowStationW
#define OpenWindowStation			OpenWindowStationW
#define EnumWindowStations			EnumWindowStationsW
#define GetUserObjectInformation		GetUserObjectInformationM
#define SetUserObjectInformation		SetUserObjectInformationW
#define RegisterWindowMessage			RegisterWindowMessageW
#define GetMessage				GetMessageW
#define DispatchMessage				DispatchMessageW
#define PeekMessage				PeekMessageW
#define SendMessage				SendMessageW
#define SendMessageTimeout			SendMessageTimeoutW
#define SendNotifyMessage			SendNotifyMessageW
#define SendMessageCallback			SendMessageCallbackW
#define BroadcastSystemMessageEx		BroadcastSystemMessageExW
#define BroadcastSystemMessage			BroadcastSystemMessageW
#define PostMessage				PostMessageW
#define PostThreadMessage			PostThreadMessageW
#define DefWindowProc				DefWindowProcW
#define RegisterClass				RegisterClassW
#define UnregisterClass				UnregisterClassW
#define GetClassInfo				GetClassInfoW
#define RegisterClassEx				RegisterClassExW
#define GetClassInfoEx				GetClassInfoExW
#define CallWindowProc				CallWindowProcW
#define RegisterDeviceNotification		RegisterDeviceNotificationW
#define CreateWindowEx				CreateWindowExW
#define CreateDialogParam			CreateDialogParamW
#define CreateDialogIndirectParam		CreateDialogIndirectParamW
#define DialogBoxParam				DialogBoxParamW
#define DialogBoxIndirectParam			DialogBoxIndirectParamW
#define SetDlgItemText				SetDlgItemTextW
#define GetDlgItemText				GetDlgItemTextW
#define SendDlgItemMessage			SendDlgItemMessageW
#define DefDlgProc				DefDlgProcW
#define CallMsgFilter				CallMsgFilterW
#define RegisterClipboardFormat			RegisterClipboardFormatW
#define GetClipboardFormatName			GetClipboardFormatNameW
#define CharToOem				CharToOemW
#define OemToChar				OemToCharW
#define CharToOemBuff				CharToOemBuffW
#define OemToCharBuff				OemToCharBuffW
#define CharUpper				CharUpperW
#define CharUpperBuff				CharUpperBuffW
#define CharLower				CharLowerW
#define CharLowerBuff				CharLowerBuffW
#define CharNext				CharNextW
#define CharPrev				CharPrevW
#define IsCharAlpha				IsCharAlphaW
#define IsCharAlphaNumeric			IsCharAlphaNumericW
#define IsCharUpper				IsCharUpperW
#define IsCharLower				IsCharLowerW
#define GetKeyNameText				GetKeyNameTextW
#define VkScanM					VkScanW
#define VkKeyScanEx				VkKeyScanExW
#define MapVirtualKey				MapVirtualKeyW
#define MapVirtualKeyEx				MapVirtualKeyExW
#define LoadAccelerators			LoadAcceleratorsW
#define CreateAcceleratorTable			CreateAcceleratorTableW
#define CopyAcceleratorTable			CopyAcceleratorTableW
#define TranslateAccelerator			TranslateAcceleratorW
#define LoadMenu				LoadMenuW
#define LoadMenuIndirect			LoadMenuIndirectW
#define ChangeMenu				ChangeMenuW
#define GetMenuString				GetMenuStringW
#define InsertMenu				InsertMenuW
#define AppendMenu				AppendMenuW
#define ModifyMenu				ModifyMenuW
#define InsertMenuItem				InsertMenuItemW
#define GetMenuItemInfo				GetMenuItemInfoW
#define SetMenuItemInfo				SetMenuItemInfoW
#define DrawText				DrawTextW
#define DrawTextEx				DrawTextExW
#define GrayString				GrayStringW
#define DrawState				DrawStateW
#define TabbedTextOut				TabbedTextOutW
#define GetTabbedTextExtent			GetTabbedTextExtentW
#define SetProp					SetPropW
#define GetProp					GetPropW
#define RemoveProp				RemovePropW
#define EnumPropsEx				EnumPropsExW
#define EnumProps				EnumPropsW
#define SetWindowText				SetWindowTextW
#define GetWindowText				GetWindowTextW
#define GetWindowTextLength			GetWindowTextLengthW
#define MessageBox				MessageBoxW
#define MessageBoxEx				MessageBoxExW
#define MessageBoxIndirect			MessageBoxIndirectW
#define GetWindowLong				GetWindowLongW
#define SetWindowLong				SetWindowLongW
#define GetClassLong				GetClassLongW
#define SetClassLong				SetClassLongW
#define FindWindow				FindWindowW
#define FindWindowEx				FindWindowExW
#define GetClassName				GetClassNameW
#define SetWindowHook				SetWindowHookW
#define SetWindowsHookEx			SetWindowsHookExW
#define LoadBitmap				LoadBitmapW
#define LoadCursor				LoadCursorW
#define LoadCursorFromFile			LoadCursorFromFileW
#define LoadIcon				LoadIconW
#define PrivateExtractIcons			PrivateExtractIconsW
#define LoadImage				LoadImageW
#define GetIconInfoEx				GetIconInfoExW
#define LoadString				LoadStringW
#define IsDialogMessage				IsDialogMessageW
#define DlgDirList				DlgDirListW
#define DlgDirSelectEx				DlgDirSelectExW
#define DlgDirListComboBox			DlgDirListComboBoxW
#define DlgDirSelectComboBoxEx			DlgDirSelectComboBoxExW
#define DefFrameProc				DefFrameProcW
#define DefMDIChildProc				DefMDIChildProcW
#define CreateMDIWindow				CreateMDIWindowW
#define WinHelp					WinHelpW
#define ChangeDisplaySettings			ChangeDisplaySettingsW
#define ChangeDisplaySettingsEx			ChangeDisplaySettingsExW
#define EnumDisplaySettings			EnumDisplaySettingsW
#define EnumDisplaySettingsEx			EnumDisplaySettingsExW
#define EnumDisplayDevices			EnumDisplayDevicesW
#define SystemParametersInfo			SystemParametersInfoW
#define GetMonitorInfo				GetMonitorInfoW
#define GetWindowModuleFileName			GetWindowModuleFileNameW
#define RealGetWindowClass			RealGetWindowClassW
#define GetAltTabInfo				GetAltTabInfoW
#define GetRawInputDeviceInfo			GetRawInputDeviceInfoW
#define GetWindowLongPtr			GetWindowLongPtrW
#define SetWindowLongPtr			SetWindowLongPtrW
#define GetClassLongPtr				GetClassLongPtrW
#define SetClassLongPtr				SetClassLongPtrW
#endif


#define MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((WORD)(i))))
#define MAKEINTRESOURCEM(i) ((LPSTR)((ULONG_PTR)((WORD)(i))))
#define MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((WORD)(i))))

#define PostAppMessageA(idThread, wMsg, wParam, lParam) PostThreadMessageA ((DWORD)idThread, wMsg, wParam, lParam)
#define PostAppMessageM(idThread, wMsg, wParam, lParam) PostThreadMessageM ((DWORD)idThread, wMsg, wParam, lParam)
#define PostAppMessageW(idThread, wMsg, wParam, lParam) PostThreadMessageW ((DWORD)idThread, wMsg, wParam, lParam)

#define CreateWindowA(lpClassName,lpWindowName,dwStyle,x,y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam) CreateWindowExA((DWORD)0,lpClassName,lpWindowName,dwStyle,x,y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam)
#define CreateWindowM(lpClassName,lpWindowName,dwStyle,x,y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam) CreateWindowExM((DWORD)0,lpClassName,lpWindowName,dwStyle,x,y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam)
#define CreateWindowW(lpClassName,lpWindowName,dwStyle,x,y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam) CreateWindowExW((DWORD)0,lpClassName,lpWindowName,dwStyle,x,y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam)

#define CreateDialogA(hInstance,lpName,hWndParent,lpDialogFunc) CreateDialogParamA(hInstance,lpName,hWndParent,lpDialogFunc,(LPARAM)0)
#define CreateDialogM(hInstance,lpName,hWndParent,lpDialogFunc) CreateDialogParamM(hInstance,lpName,hWndParent,lpDialogFunc,(LPARAM)0)
#define CreateDialogW(hInstance,lpName,hWndParent,lpDialogFunc) CreateDialogParamW(hInstance,lpName,hWndParent,lpDialogFunc,(LPARAM)0)
#define CreateDialogIndirectA(hInstance,lpTemplate,hWndParent,lpDialogFunc) CreateDialogIndirectParamA(hInstance,lpTemplate,hWndParent,lpDialogFunc,(LPARAM)0)
#define CreateDialogIndirectM(hInstance,lpTemplate,hWndParent,lpDialogFunc) CreateDialogIndirectParamM(hInstance,lpTemplate,hWndParent,lpDialogFunc,(LPARAM)0)
#define CreateDialogIndirectW(hInstance,lpTemplate,hWndParent,lpDialogFunc) CreateDialogIndirectParamW(hInstance,lpTemplate,hWndParent,lpDialogFunc,(LPARAM)0)

#define DialogBoxA(hInstance,lpTemplate,hWndParent,lpDialogFunc) DialogBoxParamA(hInstance,lpTemplate,hWndParent,lpDialogFunc,(LPARAM)0)
#define DialogBoxM(hInstance,lpTemplate,hWndParent,lpDialogFunc) DialogBoxParamM(hInstance,lpTemplate,hWndParent,lpDialogFunc,(LPARAM)0)
#define DialogBoxW(hInstance,lpTemplate,hWndParent,lpDialogFunc) DialogBoxParamW(hInstance,lpTemplate,hWndParent,lpDialogFunc,(LPARAM)0)
#define DialogBoxIndirectA(hInstance,lpTemplate,hWndParent,lpDialogFunc) DialogBoxIndirectParamA(hInstance,lpTemplate,hWndParent,lpDialogFunc,(LPARAM)0)
#define DialogBoxIndirectM(hInstance,lpTemplate,hWndParent,lpDialogFunc) DialogBoxIndirectParamM(hInstance,lpTemplate,hWndParent,lpDialogFunc,(LPARAM)0)
#define DialogBoxIndirectW(hInstance,lpTemplate,hWndParent,lpDialogFunc) DialogBoxIndirectParamW(hInstance,lpTemplate,hWndParent,lpDialogFunc,(LPARAM)0)

#ifdef WINAPI_ANSI_DEFAULT
#define PostAppMessage			PostAppMessageA
#define CreateWindow			CreateWindowA
#define CreateDialog			CreateDialogA
#define CreateDialogIndirect		CreateDialogIndirectA
#define DialogBox			DialogBoxA
#define DialogBoxIndirect		DialogBoxIndirectA
#define MAKEINTRESOURCE			MAKEINTRESOURCEA
#endif

#ifdef WINAPI_UTF8_DEFAULT
#define PostAppMessage			PostAppMessageM
#define CreateWindow			CreateWindowM
#define CreateDialog			CreateDialogM
#define CreateDialogIndirect		CreateDialogIndirectM
#define DialogBox			DialogBoxM
#define DialogBoxIndirect		DialogBoxIndirectM
#define MAKEINTRESOURCE			MAKEINTRESOURCEM
#endif

#ifdef WINAPI_UTF16_DEFAULT
#define PostAppMessage			PostAppMessageW
#define CreateWindow			CreateWindowW
#define CreateDialog			CreateDialogW
#define CreateDialogIndirect		CreateDialogIndirectW
#define DialogBox			DialogBoxW
#define DialogBoxIndirect		DialogBoxIndirectW
#define MAKEINTRESOURCE			MAKEINTRESOURCEW
#endif

#define EnumTaskWindows(hTask,lpfn,lParam) EnumThreadWindows(HandleToUlong(hTask),lpfn,lParam)
#define GetNextWindow(hWnd,wCmd) GetWindow(hWnd,wCmd)
#define GetSysModalWindow() (NULL)
#define SetSysModalWindow(hWnd) (NULL)
#define GetWindowTask(hWnd) ((HANDLE)(DWORD_PTR)GetWindowThreadProcessId(hWnd,NULL))
#define DefHookProc(nCode, wParam, lParam, phhk) CallNextHookEx ((HHOOK) *phhk, nCode, wParam, lParam)
#define CopyCursor(pcur) ((HCURSOR)CopyIcon((HICON)(pcur)))


#define IS_INTRESOURCE(_r) ((((ULONG_PTR)(_r)) >> 16)==0)



#define RT_CURSOR MAKEINTRESOURCE(1)
#define RT_BITMAP MAKEINTRESOURCE(2)
#define RT_ICON MAKEINTRESOURCE(3)
#define RT_MENU MAKEINTRESOURCE(4)
#define RT_DIALOG MAKEINTRESOURCE(5)
#define RT_STRING MAKEINTRESOURCE(6)
#define RT_FONTDIR MAKEINTRESOURCE(7)
#define RT_FONT MAKEINTRESOURCE(8)
#define RT_ACCELERATOR MAKEINTRESOURCE(9)
#define RT_RCDATA MAKEINTRESOURCE(10)
#define RT_MESSAGETABLE MAKEINTRESOURCE(11)

#define DIFFERENCE 11
#define RT_GROUP_CURSOR MAKEINTRESOURCE ((ULONG_PTR) (RT_CURSOR) + DIFFERENCE)
#define RT_GROUP_ICON MAKEINTRESOURCE ((ULONG_PTR) (RT_ICON) + DIFFERENCE)
#define RT_VERSION MAKEINTRESOURCE(16)
#define RT_DLGINCLUDE MAKEINTRESOURCE(17)
#define RT_PLUGPLAY MAKEINTRESOURCE(19)
#define RT_VXD MAKEINTRESOURCE(20)
#define RT_ANICURSOR MAKEINTRESOURCE(21)
#define RT_ANIICON MAKEINTRESOURCE(22)
#define RT_HTML MAKEINTRESOURCE(23)
#define RT_MANIFEST MAKEINTRESOURCE(24)

#define CREATEPROCESS_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#define ISOLATIONAWARE_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(2)
#define ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(3)
#define MINIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#define MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(16)

#define SETWALLPAPER_DEFAULT ((LPWSTR)-1)

#define SB_HORZ 0
#define SB_VERT 1
#define SB_CTL 2
#define SB_BOTH 3

#define SB_LINEUP 0
#define SB_LINELEFT 0
#define SB_LINEDOWN 1
#define SB_LINERIGHT 1
#define SB_PAGEUP 2
#define SB_PAGELEFT 2
#define SB_PAGEDOWN 3
#define SB_PAGERIGHT 3
#define SB_THUMBPOSITION 4
#define SB_THUMBTRACK 5
#define SB_TOP 6
#define SB_LEFT 6
#define SB_BOTTOM 7
#define SB_RIGHT 7
#define SB_ENDSCROLL 8

#define SW_HIDE 0
#define SW_SHOWNORMAL 1
#define SW_NORMAL 1
#define SW_SHOWMINIMIZED 2
#define SW_SHOWMAXIMIZED 3
#define SW_MAXIMIZE 3
#define SW_SHOWNOACTIVATE 4
#define SW_SHOW 5
#define SW_MINIMIZE 6
#define SW_SHOWMINNOACTIVE 7
#define SW_SHOWNA 8
#define SW_RESTORE 9
#define SW_SHOWDEFAULT 10
#define SW_FORCEMINIMIZE 11
#define SW_MAX 11

#define HIDE_WINDOW 0
#define SHOW_OPENWINDOW 1
#define SHOW_ICONWINDOW 2
#define SHOW_FULLSCREEN 3
#define SHOW_OPENNOACTIVATE 4

#define SW_PARENTCLOSING 1
#define SW_OTHERZOOM 2
#define SW_PARENTOPENING 3
#define SW_OTHERUNZOOM 4

#define AW_HOR_POSITIVE 0x00000001
#define AW_HOR_NEGATIVE 0x00000002
#define AW_VER_POSITIVE 0x00000004
#define AW_VER_NEGATIVE 0x00000008
#define AW_CENTER 0x00000010
#define AW_HIDE 0x00010000
#define AW_ACTIVATE 0x00020000
#define AW_SLIDE 0x00040000
#define AW_BLEND 0x00080000

#define KF_EXTENDED 0x0100
#define KF_DLGMODE 0x0800
#define KF_MENUMODE 0x1000
#define KF_ALTDOWN 0x2000
#define KF_REPEAT 0x4000
#define KF_UP 0x8000

#define VK_LBUTTON 0x01
#define VK_RBUTTON 0x02
#define VK_CANCEL 0x03
#define VK_MBUTTON 0x04
#define VK_XBUTTON1 0x05
#define VK_XBUTTON2 0x06
#define VK_BACK 0x08
#define VK_TAB 0x09
#define VK_CLEAR 0x0C
#define VK_RETURN 0x0D
#define VK_SHIFT 0x10
#define VK_CONTROL 0x11
#define VK_MENU 0x12
#define VK_PAUSE 0x13
#define VK_CAPITAL 0x14
#define VK_KANA 0x15
#define VK_HANGEUL 0x15
#define VK_HANGUL 0x15
#define VK_JUNJA 0x17
#define VK_FINAL 0x18
#define VK_HANJA 0x19
#define VK_KANJI 0x19
#define VK_ESCAPE 0x1B
#define VK_CONVERT 0x1C
#define VK_NONCONVERT 0x1D
#define VK_ACCEPT 0x1E
#define VK_MODECHANGE 0x1F
#define VK_SPACE 0x20
#define VK_PRIOR 0x21
#define VK_NEXT 0x22
#define VK_END 0x23
#define VK_HOME 0x24
#define VK_LEFT 0x25
#define VK_UP 0x26
#define VK_RIGHT 0x27
#define VK_DOWN 0x28
#define VK_SELECT 0x29
#define VK_PRINT 0x2A
#define VK_EXECUTE 0x2B
#define VK_SNAPSHOT 0x2C
#define VK_INSERT 0x2D
#define VK_DELETE 0x2E
#define VK_HELP 0x2F

#define VK_LWIN 0x5B
#define VK_RWIN 0x5C
#define VK_APPS 0x5D
#define VK_SLEEP 0x5F
#define VK_NUMPAD0 0x60
#define VK_NUMPAD1 0x61
#define VK_NUMPAD2 0x62
#define VK_NUMPAD3 0x63
#define VK_NUMPAD4 0x64
#define VK_NUMPAD5 0x65
#define VK_NUMPAD6 0x66
#define VK_NUMPAD7 0x67
#define VK_NUMPAD8 0x68
#define VK_NUMPAD9 0x69
#define VK_MULTIPLY 0x6A
#define VK_ADD 0x6B
#define VK_SEPARATOR 0x6C
#define VK_SUBTRACT 0x6D
#define VK_DECIMAL 0x6E
#define VK_DIVIDE 0x6F
#define VK_F1 0x70
#define VK_F2 0x71
#define VK_F3 0x72
#define VK_F4 0x73
#define VK_F5 0x74
#define VK_F6 0x75
#define VK_F7 0x76
#define VK_F8 0x77
#define VK_F9 0x78
#define VK_F10 0x79
#define VK_F11 0x7A
#define VK_F12 0x7B
#define VK_F13 0x7C
#define VK_F14 0x7D
#define VK_F15 0x7E
#define VK_F16 0x7F
#define VK_F17 0x80
#define VK_F18 0x81
#define VK_F19 0x82
#define VK_F20 0x83
#define VK_F21 0x84
#define VK_F22 0x85
#define VK_F23 0x86
#define VK_F24 0x87
#define VK_NUMLOCK 0x90
#define VK_SCROLL 0x91
#define VK_OEM_NEC_EQUAL 0x92
#define VK_OEM_FJ_JISHO 0x92
#define VK_OEM_FJ_MASSHOU 0x93
#define VK_OEM_FJ_TOUROKU 0x94
#define VK_OEM_FJ_LOYA 0x95
#define VK_OEM_FJ_ROYA 0x96
#define VK_LSHIFT 0xA0
#define VK_RSHIFT 0xA1
#define VK_LCONTROL 0xA2
#define VK_RCONTROL 0xA3
#define VK_LMENU 0xA4
#define VK_RMENU 0xA5
#define VK_BROWSER_BACK 0xA6
#define VK_BROWSER_FORWARD 0xA7
#define VK_BROWSER_REFRESH 0xA8
#define VK_BROWSER_STOP 0xA9
#define VK_BROWSER_SEARCH 0xAA
#define VK_BROWSER_FAVORITES 0xAB
#define VK_BROWSER_HOME 0xAC
#define VK_VOLUME_MUTE 0xAD
#define VK_VOLUME_DOWN 0xAE
#define VK_VOLUME_UP 0xAF
#define VK_MEDIA_NEXT_TRACK 0xB0
#define VK_MEDIA_PREV_TRACK 0xB1
#define VK_MEDIA_STOP 0xB2
#define VK_MEDIA_PLAY_PAUSE 0xB3
#define VK_LAUNCH_MAIL 0xB4
#define VK_LAUNCH_MEDIA_SELECT 0xB5
#define VK_LAUNCH_APP1 0xB6
#define VK_LAUNCH_APP2 0xB7
#define VK_OEM_1 0xBA
#define VK_OEM_PLUS 0xBB
#define VK_OEM_COMMA 0xBC
#define VK_OEM_MINUS 0xBD
#define VK_OEM_PERIOD 0xBE
#define VK_OEM_2 0xBF
#define VK_OEM_3 0xC0
#define VK_OEM_4 0xDB
#define VK_OEM_5 0xDC
#define VK_OEM_6 0xDD
#define VK_OEM_7 0xDE
#define VK_OEM_8 0xDF
#define VK_OEM_AX 0xE1
#define VK_OEM_102 0xE2
#define VK_ICO_HELP 0xE3
#define VK_ICO_00 0xE4
#define VK_PROCESSKEY 0xE5
#define VK_ICO_CLEAR 0xE6
#define VK_PACKET 0xE7
#define VK_OEM_RESET 0xE9
#define VK_OEM_JUMP 0xEA
#define VK_OEM_PA1 0xEB
#define VK_OEM_PA2 0xEC
#define VK_OEM_PA3 0xED
#define VK_OEM_WSCTRL 0xEE
#define VK_OEM_CUSEL 0xEF
#define VK_OEM_ATTN 0xF0
#define VK_OEM_FINISH 0xF1
#define VK_OEM_COPY 0xF2
#define VK_OEM_AUTO 0xF3
#define VK_OEM_ENLW 0xF4
#define VK_OEM_BACKTAB 0xF5
#define VK_ATTN 0xF6
#define VK_CRSEL 0xF7
#define VK_EXSEL 0xF8
#define VK_EREOF 0xF9
#define VK_PLAY 0xFA
#define VK_ZOOM 0xFB
#define VK_NONAME 0xFC
#define VK_PA1 0xFD
#define VK_OEM_CLEAR 0xFE

#define WH_MIN (-1)
#define WH_MSGFILTER (-1)
#define WH_JOURNALRECORD 0
#define WH_JOURNALPLAYBACK 1
#define WH_KEYBOARD 2
#define WH_GETMESSAGE 3
#define WH_CALLWNDPROC 4
#define WH_CBT 5
#define WH_SYSMSGFILTER 6
#define WH_MOUSE 7
#define WH_HARDWARE 8
#define WH_DEBUG 9
#define WH_SHELL 10
#define WH_FOREGROUNDIDLE 11
#define WH_CALLWNDPROCRET 12

#define WH_KEYBOARD_LL 13
#define WH_MOUSE_LL 14

#define WH_MAX 14

#define WH_MINHOOK WH_MIN
#define WH_MAXHOOK WH_MAX

#define HC_ACTION 0
#define HC_GETNEXT 1
#define HC_SKIP 2
#define HC_NOREMOVE 3
#define HC_NOREM HC_NOREMOVE
#define HC_SYSMODALON 4
#define HC_SYSMODALOFF 5

#define HCBT_MOVESIZE 0
#define HCBT_MINMAX 1
#define HCBT_QS 2
#define HCBT_CREATEWND 3
#define HCBT_DESTROYWND 4
#define HCBT_ACTIVATE 5
#define HCBT_CLICKSKIPPED 6
#define HCBT_KEYSKIPPED 7
#define HCBT_SYSCOMMAND 8
#define HCBT_SETFOCUS 9

#define WTS_CONSOLE_CONNECT 0x1
#define WTS_CONSOLE_DISCONNECT 0x2
#define WTS_REMOTE_CONNECT 0x3
#define WTS_REMOTE_DISCONNECT 0x4
#define WTS_SESSION_LOGON 0x5
#define WTS_SESSION_LOGOFF 0x6
#define WTS_SESSION_LOCK 0x7
#define WTS_SESSION_UNLOCK 0x8
#define WTS_SESSION_REMOTE_CONTROL 0x9
#define WTS_SESSION_CREATE 0xa
#define WTS_SESSION_TERMINATE 0xb

#define MSGF_DIALOGBOX 0
#define MSGF_MESSAGEBOX 1
#define MSGF_MENU 2
#define MSGF_SCROLLBAR 5
#define MSGF_NEXTWINDOW 6
#define MSGF_MAX 8
#define MSGF_USER 4096

#define HSHELL_WINDOWCREATED 1
#define HSHELL_WINDOWDESTROYED 2
#define HSHELL_ACTIVATESHELLWINDOW 3
#define HSHELL_WINDOWACTIVATED 4
#define HSHELL_GETMINRECT 5
#define HSHELL_REDRAW 6
#define HSHELL_TASKMAN 7
#define HSHELL_LANGUAGE 8
#define HSHELL_SYSMENU 9
#define HSHELL_ENDTASK 10
#define HSHELL_ACCESSIBILITYSTATE 11
#define HSHELL_APPCOMMAND 12
#define HSHELL_WINDOWREPLACED 13
#define HSHELL_WINDOWREPLACING 14
#define HSHELL_MONITORCHANGED 16

#define HSHELL_HIGHBIT 0x8000
#define HSHELL_FLASH (HSHELL_REDRAW|HSHELL_HIGHBIT)
#define HSHELL_RUDEAPPACTIVATED (HSHELL_WINDOWACTIVATED|HSHELL_HIGHBIT)

#define ACCESS_STICKYKEYS 0x0001
#define ACCESS_FILTERKEYS 0x0002
#define ACCESS_MOUSEKEYS 0x0003

#define APPCOMMAND_BROWSER_BACKWARD 1
#define APPCOMMAND_BROWSER_FORWARD 2
#define APPCOMMAND_BROWSER_REFRESH 3
#define APPCOMMAND_BROWSER_STOP 4
#define APPCOMMAND_BROWSER_SEARCH 5
#define APPCOMMAND_BROWSER_FAVORITES 6
#define APPCOMMAND_BROWSER_HOME 7
#define APPCOMMAND_VOLUME_MUTE 8
#define APPCOMMAND_VOLUME_DOWN 9
#define APPCOMMAND_VOLUME_UP 10
#define APPCOMMAND_MEDIA_NEXTTRACK 11
#define APPCOMMAND_MEDIA_PREVIOUSTRACK 12
#define APPCOMMAND_MEDIA_STOP 13
#define APPCOMMAND_MEDIA_PLAY_PAUSE 14
#define APPCOMMAND_LAUNCH_MAIL 15
#define APPCOMMAND_LAUNCH_MEDIA_SELECT 16
#define APPCOMMAND_LAUNCH_APP1 17
#define APPCOMMAND_LAUNCH_APP2 18
#define APPCOMMAND_BASS_DOWN 19
#define APPCOMMAND_BASS_BOOST 20
#define APPCOMMAND_BASS_UP 21
#define APPCOMMAND_TREBLE_DOWN 22
#define APPCOMMAND_TREBLE_UP 23
#define APPCOMMAND_MICROPHONE_VOLUME_MUTE 24
#define APPCOMMAND_MICROPHONE_VOLUME_DOWN 25
#define APPCOMMAND_MICROPHONE_VOLUME_UP 26
#define APPCOMMAND_HELP 27
#define APPCOMMAND_FIND 28
#define APPCOMMAND_NEW 29
#define APPCOMMAND_OPEN 30
#define APPCOMMAND_CLOSE 31
#define APPCOMMAND_SAVE 32
#define APPCOMMAND_PRINT 33
#define APPCOMMAND_UNDO 34
#define APPCOMMAND_REDO 35
#define APPCOMMAND_COPY 36
#define APPCOMMAND_CUT 37
#define APPCOMMAND_PASTE 38
#define APPCOMMAND_REPLY_TO_MAIL 39
#define APPCOMMAND_FORWARD_MAIL 40
#define APPCOMMAND_SEND_MAIL 41
#define APPCOMMAND_SPELL_CHECK 42
#define APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE 43
#define APPCOMMAND_MIC_ON_OFF_TOGGLE 44
#define APPCOMMAND_CORRECTION_LIST 45
#define APPCOMMAND_MEDIA_PLAY 46
#define APPCOMMAND_MEDIA_PAUSE 47
#define APPCOMMAND_MEDIA_RECORD 48
#define APPCOMMAND_MEDIA_FAST_FORWARD 49
#define APPCOMMAND_MEDIA_REWIND 50
#define APPCOMMAND_MEDIA_CHANNEL_UP 51
#define APPCOMMAND_MEDIA_CHANNEL_DOWN 52
#define APPCOMMAND_DELETE 53
#define APPCOMMAND_DWM_FLIP3D 54

#define FAPPCOMMAND_MOUSE 0x8000
#define FAPPCOMMAND_KEY 0
#define FAPPCOMMAND_OEM 0x1000
#define FAPPCOMMAND_MASK 0xF000

#define GET_APPCOMMAND_LPARAM(lParam) ((short)(HIWORD(lParam) & ~FAPPCOMMAND_MASK))
#define GET_DEVICE_LPARAM(lParam) ((WORD)(HIWORD(lParam) & FAPPCOMMAND_MASK))
#define GET_MOUSEORKEY_LPARAM GET_DEVICE_LPARAM
#define GET_FLAGS_LPARAM(lParam) (LOWORD(lParam))
#define GET_KEYSTATE_LPARAM(lParam) GET_FLAGS_LPARAM(lParam)


#define LLKHF_EXTENDED (KF_EXTENDED >> 8)
#define LLKHF_INJECTED 0x00000010
#define LLKHF_ALTDOWN (KF_ALTDOWN >> 8)
#define LLKHF_UP (KF_UP >> 8)

#define LLMHF_INJECTED 0x00000001

#define HKL_PREV 0
#define HKL_NEXT 1

#define KLF_ACTIVATE 0x00000001
#define KLF_SUBSTITUTE_OK 0x00000002
#define KLF_REORDER 0x00000008
#define KLF_REPLACELANG 0x00000010
#define KLF_NOTELLSHELL 0x00000080
#define KLF_SETFORPROCESS 0x00000100
#define KLF_SHIFTLOCK 0x00010000
#define KLF_RESET 0x40000000

#define INPUTLANGCHANGE_SYSCHARSET 0x0001
#define INPUTLANGCHANGE_FORWARD 0x0002
#define INPUTLANGCHANGE_BACKWARD 0x0004

#define KL_NAMELENGTH 9


#define GMMP_USE_DISPLAY_POINTS 1
#define GMMP_USE_HIGH_RESOLUTION_POINTS 2


#define DESKTOP_READOBJECTS (int32_t)(0x0001)
#define DESKTOP_CREATEWINDOW (int32_t)(0x0002)
#define DESKTOP_CREATEMENU (int32_t)(0x0004)
#define DESKTOP_HOOKCONTROL (int32_t)(0x0008)
#define DESKTOP_JOURNALRECORD (int32_t)(0x0010)
#define DESKTOP_JOURNALPLAYBACK (int32_t)(0x0020)
#define DESKTOP_ENUMERATE (int32_t)(0x0040)
#define DESKTOP_WRITEOBJECTS (int32_t)(0x0080)
#define DESKTOP_SWITCHDESKTOP (int32_t)(0x0100)

#define DF_ALLOWOTHERACCOUNTHOOK (int32_t)(0x0001)

#define WINSTA_ENUMDESKTOPS (int32_t)(0x0001)
#define WINSTA_READATTRIBUTES (int32_t)(0x0002)
#define WINSTA_ACCESSCLIPBOARD (int32_t)(0x0004)
#define WINSTA_CREATEDESKTOP (int32_t)(0x0008)
#define WINSTA_WRITEATTRIBUTES (int32_t)(0x0010)
#define WINSTA_ACCESSGLOBALATOMS (int32_t)(0x0020)
#define WINSTA_EXITWINDOWS (int32_t)(0x0040)
#define WINSTA_ENUMERATE (int32_t)(0x0100)
#define WINSTA_READSCREEN (int32_t)(0x0200)
#define WINSTA_ALL_ACCESS (WINSTA_ENUMDESKTOPS | WINSTA_READATTRIBUTES | WINSTA_ACCESSCLIPBOARD | WINSTA_CREATEDESKTOP | WINSTA_WRITEATTRIBUTES | WINSTA_ACCESSGLOBALATOMS | WINSTA_EXITWINDOWS | WINSTA_ENUMERATE | WINSTA_READSCREEN)

#define CWF_CREATE_ONLY 0x00000001

#define WSF_VISIBLE (int32_t)(0x0001)

#define UOI_FLAGS 1
#define UOI_NAME 2
#define UOI_TYPE 3
#define UOI_USER_SID 4
#define UOI_HEAPSIZE 5
#define UOI_IO 6


#define POINTSTOPOINT(pt,pts) { (pt).x = (LONG)(SHORT)LOWORD(*(LONG*)&pts); (pt).y = (LONG)(SHORT)HIWORD(*(LONG*)&pts); }

#define POINTTOPOINTS(pt) (MAKELONG((short)((pt).x),(short)((pt).y)))
#define MAKEWPARAM(l,h) ((WPARAM)(DWORD)MAKELONG(l,h))
#define MAKELPARAM(l,h) ((LPARAM)(DWORD)MAKELONG(l,h))
#define MAKELRESULT(l,h) ((LRESULT)(DWORD)MAKELONG(l,h))

#ifndef __NT64
#define GWL_WNDPROC (-4)
#define GWL_HINSTANCE (-6)
#define GWL_HWNDPARENT (-8)
#define GWL_USERDATA (-21)
#endif
#define GWL_STYLE (-16)
#define GWL_EXSTYLE (-20)
#define GWL_ID (-12)

#define GWLP_WNDPROC (-4)
#define GWLP_HINSTANCE (-6)
#define GWLP_HWNDPARENT (-8)
#define GWLP_USERDATA (-21)
#define GWLP_ID (-12)

#ifndef __NT64
#define GCL_MENUNAME (-8)
#define GCL_HBRBACKGROUND (-10)
#define GCL_HCURSOR (-12)
#define GCL_HICON (-14)
#define GCL_HMODULE (-16)
#define GCL_WNDPROC (-24)
#define GCL_HICONSM (-34)
#endif
#define GCL_CBWNDEXTRA (-18)
#define GCL_CBCLSEXTRA (-20)
#define GCL_STYLE (-26)
#define GCW_ATOM (-32)

#define GCLP_MENUNAME (-8)
#define GCLP_HBRBACKGROUND (-10)
#define GCLP_HCURSOR (-12)
#define GCLP_HICON (-14)
#define GCLP_HMODULE (-16)
#define GCLP_WNDPROC (-24)
#define GCLP_HICONSM (-34)

#define WM_NULL 0x0000
#define WM_CREATE 0x0001
#define WM_DESTROY 0x0002
#define WM_MOVE 0x0003
#define WM_SIZE 0x0005

#define WM_ACTIVATE 0x0006

#define WA_INACTIVE 0
#define WA_ACTIVE 1
#define WA_CLICKACTIVE 2

#define WM_SETFOCUS 0x0007
#define WM_KILLFOCUS 0x0008
#define WM_ENABLE 0x000A
#define WM_SETREDRAW 0x000B
#define WM_SETTEXT 0x000C
#define WM_GETTEXT 0x000D
#define WM_GETTEXTLENGTH 0x000E
#define WM_PAINT 0x000F
#define WM_CLOSE 0x0010
#define WM_QUERYENDSESSION 0x0011
#define WM_QUERYOPEN 0x0013
#define WM_ENDSESSION 0x0016
#define WM_QUIT 0x0012
#define WM_ERASEBKGND 0x0014
#define WM_SYSCOLORCHANGE 0x0015
#define WM_SHOWWINDOW 0x0018
#define WM_WININICHANGE 0x001A
#define WM_SETTINGCHANGE WM_WININICHANGE
#define WM_DEVMODECHANGE 0x001B
#define WM_ACTIVATEAPP 0x001C
#define WM_FONTCHANGE 0x001D
#define WM_TIMECHANGE 0x001E
#define WM_CANCELMODE 0x001F
#define WM_SETCURSOR 0x0020
#define WM_MOUSEACTIVATE 0x0021
#define WM_CHILDACTIVATE 0x0022
#define WM_QUEUESYNC 0x0023
#define WM_GETMINMAXINFO 0x0024


#define WM_PAINTICON 0x0026
#define WM_ICONERASEBKGND 0x0027
#define WM_NEXTDLGCTL 0x0028
#define WM_SPOOLERSTATUS 0x002A
#define WM_DRAWITEM 0x002B
#define WM_MEASUREITEM 0x002C
#define WM_DELETEITEM 0x002D
#define WM_VKEYTOITEM 0x002E
#define WM_CHARTOITEM 0x002F
#define WM_SETFONT 0x0030
#define WM_GETFONT 0x0031
#define WM_SETHOTKEY 0x0032
#define WM_GETHOTKEY 0x0033
#define WM_QUERYDRAGICON 0x0037
#define WM_COMPAREITEM 0x0039
#define WM_GETOBJECT 0x003D
#define WM_COMPACTING 0x0041
#define WM_COMMNOTIFY 0x0044
#define WM_WINDOWPOSCHANGING 0x0046
#define WM_WINDOWPOSCHANGED 0x0047
#define WM_POWER 0x0048

#define PWR_OK 1
#define PWR_FAIL (-1)
#define PWR_SUSPENDREQUEST 1
#define PWR_SUSPENDRESUME 2
#define PWR_CRITICALRESUME 3

#define WM_COPYDATA 0x004A
#define WM_CANCELJOURNAL 0x004B
#define WM_NOTIFY 0x004E
#define WM_INPUTLANGCHANGEREQUEST 0x0050
#define WM_INPUTLANGCHANGE 0x0051
#define WM_TCARD 0x0052
#define WM_HELP 0x0053
#define WM_USERCHANGED 0x0054
#define WM_NOTIFYFORMAT 0x0055

#define NFR_ANSI 1
#define NFR_UNICODE 2
#define NF_QUERY 3
#define NF_REQUERY 4

#define WM_CONTEXTMENU 0x007B
#define WM_STYLECHANGING 0x007C
#define WM_STYLECHANGED 0x007D
#define WM_DISPLAYCHANGE 0x007E
#define WM_GETICON 0x007F
#define WM_SETICON 0x0080

#define WM_NCCREATE 0x0081
#define WM_NCDESTROY 0x0082
#define WM_NCCALCSIZE 0x0083
#define WM_NCHITTEST 0x0084
#define WM_NCPAINT 0x0085
#define WM_NCACTIVATE 0x0086
#define WM_GETDLGCODE 0x0087
#define WM_SYNCPAINT 0x0088
#define WM_NCMOUSEMOVE 0x00A0
#define WM_NCLBUTTONDOWN 0x00A1
#define WM_NCLBUTTONUP 0x00A2
#define WM_NCLBUTTONDBLCLK 0x00A3
#define WM_NCRBUTTONDOWN 0x00A4
#define WM_NCRBUTTONUP 0x00A5
#define WM_NCRBUTTONDBLCLK 0x00A6
#define WM_NCMBUTTONDOWN 0x00A7
#define WM_NCMBUTTONUP 0x00A8
#define WM_NCMBUTTONDBLCLK 0x00A9
#define WM_NCXBUTTONDOWN 0x00AB
#define WM_NCXBUTTONUP 0x00AC
#define WM_NCXBUTTONDBLCLK 0x00AD
#define WM_INPUT_DEVICE_CHANGE 0x00fe
#define WM_INPUT 0x00FF
#define WM_KEYFIRST 0x0100
#define WM_KEYDOWN 0x0100
#define WM_KEYUP 0x0101
#define WM_CHAR 0x0102
#define WM_DEADCHAR 0x0103
#define WM_SYSKEYDOWN 0x0104
#define WM_SYSKEYUP 0x0105
#define WM_SYSCHAR 0x0106
#define WM_SYSDEADCHAR 0x0107
#define WM_UNICHAR 0x0109
#define WM_KEYLAST 0x0109
#define UNICODE_NOCHAR 0xFFFF
#define WM_IME_STARTCOMPOSITION 0x010D
#define WM_IME_ENDCOMPOSITION 0x010E
#define WM_IME_COMPOSITION 0x010F
#define WM_IME_KEYLAST 0x010F
#define WM_INITDIALOG 0x0110
#define WM_COMMAND 0x0111
#define WM_SYSCOMMAND 0x0112
#define WM_TIMER 0x0113
#define WM_HSCROLL 0x0114
#define WM_VSCROLL 0x0115
#define WM_INITMENU 0x0116
#define WM_INITMENUPOPUP 0x0117
#define WM_MENUSELECT 0x011F
#define WM_GESTURE 0x0119
#define WM_GESTURENOTIFY 0x011A
#define WM_MENUCHAR 0x0120
#define WM_ENTERIDLE 0x0121
#define WM_MENURBUTTONUP 0x0122
#define WM_MENUDRAG 0x0123
#define WM_MENUGETOBJECT 0x0124
#define WM_UNINITMENUPOPUP 0x0125
#define WM_MENUCOMMAND 0x0126
#define WM_CHANGEUISTATE 0x0127
#define WM_UPDATEUISTATE 0x0128
#define WM_QUERYUISTATE 0x0129

#define UIS_SET 1
#define UIS_CLEAR 2
#define UIS_INITIALIZE 3

#define UISF_HIDEFOCUS 0x1
#define UISF_HIDEACCEL 0x2
#define UISF_ACTIVE 0x4

#define WM_CTLCOLORMSGBOX 0x0132
#define WM_CTLCOLOREDIT 0x0133
#define WM_CTLCOLORLISTBOX 0x0134
#define WM_CTLCOLORBTN 0x0135
#define WM_CTLCOLORDLG 0x0136
#define WM_CTLCOLORSCROLLBAR 0x0137
#define WM_CTLCOLORSTATIC 0x0138
#define MN_GETHMENU 0x01E1

#define WM_MOUSEFIRST 0x0200
#define WM_MOUSEMOVE 0x0200
#define WM_LBUTTONDOWN 0x0201
#define WM_LBUTTONUP 0x0202
#define WM_LBUTTONDBLCLK 0x0203
#define WM_RBUTTONDOWN 0x0204
#define WM_RBUTTONUP 0x0205
#define WM_RBUTTONDBLCLK 0x0206
#define WM_MBUTTONDOWN 0x0207
#define WM_MBUTTONUP 0x0208
#define WM_MBUTTONDBLCLK 0x0209
#define WM_MOUSEWHEEL 0x020A
#define WM_XBUTTONDOWN 0x020B
#define WM_XBUTTONUP 0x020C
#define WM_XBUTTONDBLCLK 0x020D
#define WM_MOUSEHWHEEL 0x020e

#if _WIN32_WINNT >= 0x0600
#define WM_MOUSELAST 0x020e
#else
#define WM_MOUSELAST 0x020d
#endif

#define WHEEL_DELTA 120
#define GET_WHEEL_DELTA_WPARAM(wParam) ((short)HIWORD(wParam))

#define WHEEL_PAGESCROLL (UINT_MAX)

#define GET_KEYSTATE_WPARAM(wParam) (LOWORD(wParam))
#define GET_NCHITTEST_WPARAM(wParam) ((short)LOWORD(wParam))
#define GET_XBUTTON_WPARAM(wParam) (HIWORD(wParam))

#define XBUTTON1 0x0001
#define XBUTTON2 0x0002

#define WM_PARENTNOTIFY 0x0210
#define WM_ENTERMENULOOP 0x0211
#define WM_EXITMENULOOP 0x0212
#define WM_NEXTMENU 0x0213
#define WM_SIZING 0x0214
#define WM_CAPTURECHANGED 0x0215
#define WM_MOVING 0x0216
#define WM_POWERBROADCAST 0x0218

#define PBT_APMQUERYSUSPEND 0x0000
#define PBT_APMQUERYSTANDBY 0x0001

#define PBT_APMQUERYSUSPENDFAILED 0x0002
#define PBT_APMQUERYSTANDBYFAILED 0x0003

#define PBT_APMSUSPEND 0x0004
#define PBT_APMSTANDBY 0x0005

#define PBT_APMRESUMECRITICAL 0x0006
#define PBT_APMRESUMESUSPEND 0x0007
#define PBT_APMRESUMESTANDBY 0x0008

#define PBTF_APMRESUMEFROMFAILURE 0x00000001

#define PBT_APMBATTERYLOW 0x0009
#define PBT_APMPOWERSTATUSCHANGE 0x000A

#define PBT_APMOEMEVENT 0x000B
#define PBT_APMRESUMEAUTOMATIC 0x0012
#define PBT_POWERSETTINGCHANGE 32787

#define WM_DEVICECHANGE 0x0219

#define WM_MDICREATE 0x0220
#define WM_MDIDESTROY 0x0221
#define WM_MDIACTIVATE 0x0222
#define WM_MDIRESTORE 0x0223
#define WM_MDINEXT 0x0224
#define WM_MDIMAXIMIZE 0x0225
#define WM_MDITILE 0x0226
#define WM_MDICASCADE 0x0227
#define WM_MDIICONARRANGE 0x0228
#define WM_MDIGETACTIVE 0x0229

#define WM_MDISETMENU 0x0230
#define WM_ENTERSIZEMOVE 0x0231
#define WM_EXITSIZEMOVE 0x0232
#define WM_DROPFILES 0x0233
#define WM_MDIREFRESHMENU 0x0234
#define WM_POINTERDEVICECHANGE 0x238
#define WM_POINTERDEVICEINRANGE 0x239
#define WM_POINTERDEVICEOUTOFRANGE 0x23a
#define WM_TOUCH 0x0240
#define WM_NCPOINTERUPDATE 0x0241
#define WM_NCPOINTERDOWN 0x0242
#define WM_NCPOINTERUP 0x0243
#define WM_POINTERUPDATE 0x0245
#define WM_POINTERDOWN 0x0246
#define WM_POINTERUP 0x0247
#define WM_POINTERENTER 0x0249
#define WM_POINTERLEAVE 0x024a
#define WM_POINTERACTIVATE 0x024b
#define WM_POINTERCAPTURECHANGED 0x024c
#define WM_TOUCHHITTESTING 0x024d
#define WM_POINTERWHEEL 0x024e
#define WM_POINTERHWHEEL 0x024f

#define WM_IME_SETCONTEXT 0x0281
#define WM_IME_NOTIFY 0x0282
#define WM_IME_CONTROL 0x0283
#define WM_IME_COMPOSITIONFULL 0x0284
#define WM_IME_SELECT 0x0285
#define WM_IME_CHAR 0x0286
#define WM_IME_REQUEST 0x0288
#define WM_IME_KEYDOWN 0x0290
#define WM_IME_KEYUP 0x0291

#define WM_MOUSEHOVER 0x02A1
#define WM_MOUSELEAVE 0x02A3
#define WM_NCMOUSEHOVER 0x02A0
#define WM_NCMOUSELEAVE 0x02A2
#define WM_WTSSESSION_CHANGE 0x02B1
#define WM_TABLET_FIRST 0x02c0
#define WM_TABLET_LAST 0x02df
#define WM_CUT 0x0300
#define WM_COPY 0x0301
#define WM_PASTE 0x0302
#define WM_CLEAR 0x0303
#define WM_UNDO 0x0304
#define WM_RENDERFORMAT 0x0305
#define WM_RENDERALLFORMATS 0x0306
#define WM_DESTROYCLIPBOARD 0x0307
#define WM_DRAWCLIPBOARD 0x0308
#define WM_PAINTCLIPBOARD 0x0309
#define WM_VSCROLLCLIPBOARD 0x030A
#define WM_SIZECLIPBOARD 0x030B
#define WM_ASKCBFORMATNAME 0x030C
#define WM_CHANGECBCHAIN 0x030D
#define WM_HSCROLLCLIPBOARD 0x030E
#define WM_QUERYNEWPALETTE 0x030F
#define WM_PALETTEISCHANGING 0x0310
#define WM_PALETTECHANGED 0x0311
#define WM_HOTKEY 0x0312
#define WM_PRINT 0x0317
#define WM_PRINTCLIENT 0x0318
#define WM_APPCOMMAND 0x0319
#define WM_THEMECHANGED 0x031A
#define WM_CLIPBOARDUPDATE 0x031d
#define WM_DWMCOMPOSITIONCHANGED 0x031e
#define WM_DWMNCRENDERINGCHANGED 0x031f
#define WM_DWMCOLORIZATIONCOLORCHANGED 0x0320
#define WM_DWMWINDOWMAXIMIZEDCHANGE 0x0321
#define WM_DWMSENDICONICTHUMBNAIL 0x0323
#define WM_DWMSENDICONICLIVEPREVIEWBITMAP 0x0326
#define WM_GETTITLEBARINFOEX 0x033f

#define WM_HANDHELDFIRST 0x0358
#define WM_HANDHELDLAST 0x035F
#define WM_AFXFIRST 0x0360
#define WM_AFXLAST 0x037F
#define WM_PENWINFIRST 0x0380
#define WM_PENWINLAST 0x038F
#define WM_APP 0x8000
#define WM_USER 0x0400

#define WMSZ_LEFT 1
#define WMSZ_RIGHT 2
#define WMSZ_TOP 3
#define WMSZ_TOPLEFT 4
#define WMSZ_TOPRIGHT 5
#define WMSZ_BOTTOM 6
#define WMSZ_BOTTOMLEFT 7
#define WMSZ_BOTTOMRIGHT 8

#define HTERROR (-2)
#define HTTRANSPARENT (-1)
#define HTNOWHERE 0
#define HTCLIENT 1
#define HTCAPTION 2
#define HTSYSMENU 3
#define HTGROWBOX 4
#define HTSIZE HTGROWBOX
#define HTMENU 5
#define HTHSCROLL 6
#define HTVSCROLL 7
#define HTMINBUTTON 8
#define HTMAXBUTTON 9
#define HTLEFT 10
#define HTRIGHT 11
#define HTTOP 12
#define HTTOPLEFT 13
#define HTTOPRIGHT 14
#define HTBOTTOM 15
#define HTBOTTOMLEFT 16
#define HTBOTTOMRIGHT 17
#define HTBORDER 18
#define HTREDUCE HTMINBUTTON
#define HTZOOM HTMAXBUTTON
#define HTSIZEFIRST HTLEFT
#define HTSIZELAST HTBOTTOMRIGHT
#define HTOBJECT 19
#define HTCLOSE 20
#define HTHELP 21

#define SMTO_NORMAL 0x0000
#define SMTO_BLOCK 0x0001
#define SMTO_ABORTIFHUNG 0x0002
#define SMTO_NOTIMEOUTIFNOTHUNG 0x0008
#define SMTO_ERRORONEXIT 0x0020

#define MA_ACTIVATE 1
#define MA_ACTIVATEANDEAT 2
#define MA_NOACTIVATE 3
#define MA_NOACTIVATEANDEAT 4

#define ICON_SMALL 0
#define ICON_BIG 1
#define ICON_SMALL2 2


#define SIZE_RESTORED 0
#define SIZE_MINIMIZED 1
#define SIZE_MAXIMIZED 2
#define SIZE_MAXSHOW 3
#define SIZE_MAXHIDE 4

#define SIZENORMAL SIZE_RESTORED
#define SIZEICONIC SIZE_MINIMIZED
#define SIZEFULLSCREEN SIZE_MAXIMIZED
#define SIZEZOOMSHOW SIZE_MAXSHOW
#define SIZEZOOMHIDE SIZE_MAXHIDE

#define WVR_ALIGNTOP 0x0010
#define WVR_ALIGNLEFT 0x0020
#define WVR_ALIGNBOTTOM 0x0040
#define WVR_ALIGNRIGHT 0x0080
#define WVR_HREDRAW 0x0100
#define WVR_VREDRAW 0x0200
#define WVR_REDRAW (WVR_HREDRAW | WVR_VREDRAW)
#define WVR_VALIDRECTS 0x0400

#define MK_LBUTTON 0x0001
#define MK_RBUTTON 0x0002
#define MK_SHIFT 0x0004
#define MK_CONTROL 0x0008
#define MK_MBUTTON 0x0010
#define MK_XBUTTON1 0x0020
#define MK_XBUTTON2 0x0040

#define TME_HOVER 0x00000001
#define TME_LEAVE 0x00000002
#define TME_NONCLIENT 0x00000010
#define TME_QUERY 0x40000000
#define TME_CANCEL 0x80000000

#define HOVER_DEFAULT 0xFFFFFFFF

#define WS_OVERLAPPED (int32_t)(0x00000000)
#define WS_CHILD (int32_t)(0x40000000)
#define WS_MINIMIZE (int32_t)(0x20000000)
#define WS_VISIBLE (int32_t)(0x10000000)
#define WS_DISABLED (int32_t)(0x08000000)
#define WS_CLIPSIBLINGS (int32_t)(0x04000000)
#define WS_CLIPCHILDREN (int32_t)(0x02000000)
#define WS_MAXIMIZE (int32_t)(0x01000000)
#define WS_BORDER (int32_t)(0x00800000)
#define WS_DLGFRAME (int32_t)(0x00400000)
#define WS_VSCROLL (int32_t)(0x00200000)
#define WS_HSCROLL (int32_t)(0x00100000)
#define WS_POPUP (int32_t)(0x80000000)
#define WS_CAPTION (int32_t)(0x00C00000)
#define WS_SYSMENU (int32_t)(0x00080000)
#define WS_THICKFRAME (int32_t)(0x00040000)
#define WS_GROUP (int32_t)(0x00020000)
#define WS_TABSTOP (int32_t)(0x00010000)
#define WS_MINIMIZEBOX (int32_t)(0x00020000)
#define WS_MAXIMIZEBOX (int32_t)(0x00010000)
#define WS_TILED WS_OVERLAPPED
#define WS_ICONIC WS_MINIMIZE
#define WS_SIZEBOX WS_THICKFRAME
#define WS_TILEDWINDOW WS_OVERLAPPEDWINDOW

#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#define WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#define WS_CHILDWINDOW (WS_CHILD)

#define WS_EX_DLGMODALFRAME (int32_t)(0x00000001)
#define WS_EX_NOPARENTNOTIFY (int32_t)(0x00000004)
#define WS_EX_TOPMOST (int32_t)(0x00000008)
#define WS_EX_ACCEPTFILES (int32_t)(0x00000010)
#define WS_EX_TRANSPARENT (int32_t)(0x00000020)
#define WS_EX_MDICHILD (int32_t)(0x00000040)
#define WS_EX_TOOLWINDOW (int32_t)(0x00000080)
#define WS_EX_WINDOWEDGE (int32_t)(0x00000100)
#define WS_EX_CLIENTEDGE (int32_t)(0x00000200)
#define WS_EX_CONTEXTHELP (int32_t)(0x00000400)
#define WS_EX_RIGHT (int32_t)(0x00001000)
#define WS_EX_LEFT (int32_t)(0x00000000)
#define WS_EX_RTLREADING (int32_t)(0x00002000)
#define WS_EX_LTRREADING (int32_t)(0x00000000)
#define WS_EX_LEFTSCROLLBAR (int32_t)(0x00004000)
#define WS_EX_RIGHTSCROLLBAR (int32_t)(0x00000000)
#define WS_EX_CONTROLPARENT (int32_t)(0x00010000)
#define WS_EX_STATICEDGE (int32_t)(0x00020000)
#define WS_EX_APPWINDOW (int32_t)(0x00040000)

#define WS_EX_OVERLAPPEDWINDOW (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#define WS_EX_PALETTEWINDOW (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)
#define WS_EX_LAYERED 0x00080000
#define WS_EX_NOINHERITLAYOUT (int32_t)(0x00100000)
#define WS_EX_NOREDIRECTIONBITMAP (int32_t)(0x00200000)
#define WS_EX_LAYOUTRTL (int32_t)(0x00400000)
#define WS_EX_COMPOSITED (int32_t)(0x02000000)
#define WS_EX_NOACTIVATE (int32_t)(0x08000000)

#define CS_VREDRAW 0x0001
#define CS_HREDRAW 0x0002
#define CS_DBLCLKS 0x0008
#define CS_OWNDC 0x0020
#define CS_CLASSDC 0x0040
#define CS_PARENTDC 0x0080
#define CS_NOCLOSE 0x0200
#define CS_SAVEBITS 0x0800
#define CS_BYTEALIGNCLIENT 0x1000
#define CS_BYTEALIGNWINDOW 0x2000
#define CS_GLOBALCLASS 0x4000
#define CS_IME 0x00010000
#define CS_DROPSHADOW 0x00020000

#define PRF_CHECKVISIBLE (int32_t)(0x00000001)
#define PRF_NONCLIENT (int32_t)(0x00000002)
#define PRF_CLIENT (int32_t)(0x00000004)
#define PRF_ERASEBKGND (int32_t)(0x00000008)
#define PRF_CHILDREN (int32_t)(0x00000010)
#define PRF_OWNED (int32_t)(0x00000020)

#define BDR_RAISEDOUTER 0x0001
#define BDR_SUNKENOUTER 0x0002
#define BDR_RAISEDINNER 0x0004
#define BDR_SUNKENINNER 0x0008

#define BDR_OUTER (BDR_RAISEDOUTER | BDR_SUNKENOUTER)
#define BDR_INNER (BDR_RAISEDINNER | BDR_SUNKENINNER)
#define BDR_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#define BDR_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)

#define EDGE_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#define EDGE_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#define EDGE_ETCHED (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#define EDGE_BUMP (BDR_RAISEDOUTER | BDR_SUNKENINNER)

#define BF_LEFT 0x0001
#define BF_TOP 0x0002
#define BF_RIGHT 0x0004
#define BF_BOTTOM 0x0008

#define BF_TOPLEFT (BF_TOP | BF_LEFT)
#define BF_TOPRIGHT (BF_TOP | BF_RIGHT)
#define BF_BOTTOMLEFT (BF_BOTTOM | BF_LEFT)
#define BF_BOTTOMRIGHT (BF_BOTTOM | BF_RIGHT)
#define BF_RECT (BF_LEFT | BF_TOP | BF_RIGHT | BF_BOTTOM)

#define BF_DIAGONAL 0x0010

#define BF_DIAGONAL_ENDTOPRIGHT (BF_DIAGONAL | BF_TOP | BF_RIGHT)
#define BF_DIAGONAL_ENDTOPLEFT (BF_DIAGONAL | BF_TOP | BF_LEFT)
#define BF_DIAGONAL_ENDBOTTOMLEFT (BF_DIAGONAL | BF_BOTTOM | BF_LEFT)
#define BF_DIAGONAL_ENDBOTTOMRIGHT (BF_DIAGONAL | BF_BOTTOM | BF_RIGHT)

#define BF_MIDDLE 0x0800
#define BF_SOFT 0x1000
#define BF_ADJUST 0x2000
#define BF_FLAT 0x4000
#define BF_MONO 0x8000


#define DFC_CAPTION 1
#define DFC_MENU 2
#define DFC_SCROLL 3
#define DFC_BUTTON 4
#define DFC_POPUPMENU 5

#define DFCS_CAPTIONCLOSE 0x0000
#define DFCS_CAPTIONMIN 0x0001
#define DFCS_CAPTIONMAX 0x0002
#define DFCS_CAPTIONRESTORE 0x0003
#define DFCS_CAPTIONHELP 0x0004

#define DFCS_MENUARROW 0x0000
#define DFCS_MENUCHECK 0x0001
#define DFCS_MENUBULLET 0x0002
#define DFCS_MENUARROWRIGHT 0x0004
#define DFCS_SCROLLUP 0x0000
#define DFCS_SCROLLDOWN 0x0001
#define DFCS_SCROLLLEFT 0x0002
#define DFCS_SCROLLRIGHT 0x0003
#define DFCS_SCROLLCOMBOBOX 0x0005
#define DFCS_SCROLLSIZEGRIP 0x0008
#define DFCS_SCROLLSIZEGRIPRIGHT 0x0010

#define DFCS_BUTTONCHECK 0x0000
#define DFCS_BUTTONRADIOIMAGE 0x0001
#define DFCS_BUTTONRADIOMASK 0x0002
#define DFCS_BUTTONRADIO 0x0004
#define DFCS_BUTTON3STATE 0x0008
#define DFCS_BUTTONPUSH 0x0010

#define DFCS_INACTIVE 0x0100
#define DFCS_PUSHED 0x0200
#define DFCS_CHECKED 0x0400

#define DFCS_TRANSPARENT 0x0800
#define DFCS_HOT 0x1000

#define DFCS_ADJUSTRECT 0x2000
#define DFCS_FLAT 0x4000
#define DFCS_MONO 0x8000

#define DC_ACTIVE 0x0001
#define DC_SMALLCAP 0x0002
#define DC_ICON 0x0004
#define DC_TEXT 0x0008
#define DC_INBUTTON 0x0010
#define DC_GRADIENT 0x0020
#define DC_BUTTONS 0x1000

#define IDANI_OPEN 1
#define IDANI_CAPTION 3

#define CF_TEXT 1
#define CF_BITMAP 2
#define CF_METAFILEPICT 3
#define CF_SYLK 4
#define CF_DIF 5
#define CF_TIFF 6
#define CF_OEMTEXT 7
#define CF_DIB 8
#define CF_PALETTE 9
#define CF_PENDATA 10
#define CF_RIFF 11
#define CF_WAVE 12
#define CF_UNICODETEXT 13
#define CF_ENHMETAFILE 14
#define CF_HDROP 15
#define CF_LOCALE 16
#define CF_DIBV5 17
#define CF_MAX 18

#define CF_OWNERDISPLAY 0x0080
#define CF_DSPTEXT 0x0081
#define CF_DSPBITMAP 0x0082
#define CF_DSPMETAFILEPICT 0x0083
#define CF_DSPENHMETAFILE 0x008E

#define CF_PRIVATEFIRST 0x0200
#define CF_PRIVATELAST 0x02FF

#define CF_GDIOBJFIRST 0x0300
#define CF_GDIOBJLAST 0x03FF

#define FVIRTKEY TRUE
#define FNOINVERT 0x02
#define FSHIFT 0x04
#define FCONTROL 0x08
#define FALT 0x10

#define WPF_SETMINPOSITION 0x0001
#define WPF_RESTORETOMAXIMIZED 0x0002
#define WPF_ASYNCWINDOWPLACEMENT 0x0004

#define ODT_MENU 1
#define ODT_LISTBOX 2
#define ODT_COMBOBOX 3
#define ODT_BUTTON 4
#define ODT_STATIC 5

#define ODA_DRAWENTIRE 0x0001
#define ODA_SELECT 0x0002
#define ODA_FOCUS 0x0004

#define ODS_SELECTED 0x0001
#define ODS_GRAYED 0x0002
#define ODS_DISABLED 0x0004
#define ODS_CHECKED 0x0008
#define ODS_FOCUS 0x0010
#define ODS_DEFAULT 0x0020
#define ODS_COMBOBOXEDIT 0x1000
#define ODS_HOTLIGHT 0x0040
#define ODS_INACTIVE 0x0080
#define ODS_NOACCEL 0x0100
#define ODS_NOFOCUSRECT 0x0200

#define PM_NOREMOVE 0x0000
#define PM_REMOVE 0x0001
#define PM_NOYIELD 0x0002

#define PM_QS_INPUT (QS_INPUT << 16)
#define PM_QS_POSTMESSAGE ((QS_POSTMESSAGE | QS_HOTKEY | QS_TIMER) << 16)
#define PM_QS_PAINT (QS_PAINT << 16)
#define PM_QS_SENDMESSAGE (QS_SENDMESSAGE << 16)

#define MOD_ALT 0x0001
#define MOD_CONTROL 0x0002
#define MOD_SHIFT 0x0004
#define MOD_WIN 0x0008
#define MOD_NOREPEAT 0x4000

#define IDHOT_SNAPWINDOW (-1)
#define IDHOT_SNAPDESKTOP (-2)

#define ENDSESSION_CLOSEAPP 0x00000001
#define ENDSESSION_CRITICAL 0x40000000
#define ENDSESSION_LOGOFF 0x80000000

#define EWX_LOGOFF 0x00000000
#define EWX_SHUTDOWN 0x00000001
#define EWX_REBOOT 0x00000002
#define EWX_FORCE 0x00000004
#define EWX_POWEROFF 0x00000008
#define EWX_FORCEIFHUNG 0x00000010
#define EWX_QUICKRESOLVE 0x00000020
#define EWX_RESTARTAPPS 0x00000040
#define EWX_HYBRID_SHUTDOWN 0x00400000
#define EWX_BOOTOPTIONS 0x01000000

#define ExitWindows(dwReserved,Code) ExitWindowsEx(EWX_LOGOFF,0xFFFFFFFF)

#define BSM_ALLCOMPONENTS 0x00000000
#define BSM_VXDS 0x00000001
#define BSM_NETDRIVER 0x00000002
#define BSM_INSTALLABLEDRIVERS 0x00000004
#define BSM_APPLICATIONS 0x00000008
#define BSM_ALLDESKTOPS 0x00000010

#define BSF_QUERY 0x00000001
#define BSF_IGNORECURRENTTASK 0x00000002
#define BSF_FLUSHDISK 0x00000004
#define BSF_NOHANG 0x00000008
#define BSF_POSTMESSAGE 0x00000010
#define BSF_FORCEIFHUNG 0x00000020
#define BSF_NOTIMEOUTIFNOTHUNG 0x00000040
#define BSF_ALLOWSFW 0x00000080
#define BSF_SENDNOTIFYMESSAGE 0x00000100
#define BSF_RETURNHDESK 0x00000200
#define BSF_LUID 0x00000400

#define BROADCAST_QUERY_DENY 0x424D5144

#define DEVICE_NOTIFY_WINDOW_HANDLE 0x00000000
#define DEVICE_NOTIFY_SERVICE_HANDLE 0x00000001
#define DEVICE_NOTIFY_ALL_INTERFACE_CLASSES 0x00000004

#define CW_USEDEFAULT ((int)0x80000000)

#define HWND_BROADCAST ((HWND)0xffff)
#define HWND_MESSAGE ((HWND)-3)
#define HWND_DESKTOP ((HWND)0)

#define ISMEX_NOSEND 0x00000000
#define ISMEX_SEND 0x00000001
#define ISMEX_NOTIFY 0x00000002
#define ISMEX_CALLBACK 0x00000004
#define ISMEX_REPLIED 0x00000008

#define PW_CLIENTONLY 0x00000001


#define LWA_COLORKEY 0x00000001
#define LWA_ALPHA 0x00000002

#define ULW_COLORKEY 0x00000001
#define ULW_ALPHA 0x00000002
#define ULW_OPAQUE 0x00000004
#define ULW_EX_NORESIZE 0x00000008

#define FLASHW_STOP 0
#define FLASHW_CAPTION 0x00000001
#define FLASHW_TRAY 0x00000002
#define FLASHW_ALL (FLASHW_CAPTION | FLASHW_TRAY)
#define FLASHW_TIMER 0x00000004
#define FLASHW_TIMERNOFG 0x0000000c

#define WDA_NONE 0x00000000
#define WDA_MONITOR 0x00000001

#define SWP_NOSIZE 0x0001
#define SWP_NOMOVE 0x0002
#define SWP_NOZORDER 0x0004
#define SWP_NOREDRAW 0x0008
#define SWP_NOACTIVATE 0x0010
#define SWP_FRAMECHANGED 0x0020
#define SWP_SHOWWINDOW 0x0040
#define SWP_HIDEWINDOW 0x0080
#define SWP_NOCOPYBITS 0x0100
#define SWP_NOOWNERZORDER 0x0200
#define SWP_NOSENDCHANGING 0x0400

#define SWP_DRAWFRAME SWP_FRAMECHANGED
#define SWP_NOREPOSITION SWP_NOOWNERZORDER
#define SWP_DEFERERASE 0x2000
#define SWP_ASYNCWINDOWPOS 0x4000

#define HWND_TOP ((HWND)0)
#define HWND_BOTTOM ((HWND)1)
#define HWND_TOPMOST ((HWND)-1)
#define HWND_NOTOPMOST ((HWND)-2)

#define DLGWINDOWEXTRA 30

#define AnsiToOem CharToOemA
#define OemToAnsi OemToCharA
#define AnsiToOemBuff CharToOemBuffA
#define OemToAnsiBuff OemToCharBuffA
#define AnsiUpper CharUpperA
#define AnsiUpperBuff CharUpperBuffA
#define AnsiLower CharLowerA
#define AnsiLowerBuff CharLowerBuffA
#define AnsiNext CharNextA
#define AnsiPrev CharPrevA

#define KEYEVENTF_EXTENDEDKEY 0x0001
#define KEYEVENTF_KEYUP 0x0002
#define KEYEVENTF_UNICODE 0x0004
#define KEYEVENTF_SCANCODE 0x0008

#define MOUSEEVENTF_MOVE 0x0001
#define MOUSEEVENTF_LEFTDOWN 0x0002
#define MOUSEEVENTF_LEFTUP 0x0004
#define MOUSEEVENTF_RIGHTDOWN 0x0008
#define MOUSEEVENTF_RIGHTUP 0x0010
#define MOUSEEVENTF_MIDDLEDOWN 0x0020
#define MOUSEEVENTF_MIDDLEUP 0x0040
#define MOUSEEVENTF_XDOWN 0x0080
#define MOUSEEVENTF_XUP 0x0100
#define MOUSEEVENTF_WHEEL 0x0800
#define MOUSEEVENTF_HWHEEL 0x01000
#define MOUSEEVENTF_MOVE_NOCOALESCE 0x2000
#define MOUSEEVENTF_VIRTUALDESK 0x4000
#define MOUSEEVENTF_ABSOLUTE 0x8000

#define INPUT_MOUSE 0
#define INPUT_KEYBOARD 1
#define INPUT_HARDWARE 2

#define TOUCH_COORD_TO_PIXEL(l) ((l) / 100)

#define TOUCHEVENTF_MOVE 0x0001
#define TOUCHEVENTF_DOWN 0x0002
#define TOUCHEVENTF_UP 0x0004
#define TOUCHEVENTF_INRANGE 0x0008
#define TOUCHEVENTF_PRIMARY 0x0010
#define TOUCHEVENTF_NOCOALESCE 0x0020
#define TOUCHEVENTF_PEN 0x0040
#define TOUCHEVENTF_PALM 0x0080

#define TOUCHINPUTMASKF_TIMEFROMSYSTEM 0x0001
#define TOUCHINPUTMASKF_EXTRAINFO 0x0002
#define TOUCHINPUTMASKF_CONTACTAREA 0x0004

#define TWF_FINETOUCH (0x00000001)
#define TWF_WANTPALM (0x00000002)

#define POINTER_FLAG_NONE 0x00000000
#define POINTER_FLAG_NEW 0x00000001
#define POINTER_FLAG_INRANGE 0x00000002
#define POINTER_FLAG_INCONTACT 0x00000004
#define POINTER_FLAG_FIRSTBUTTON 0x00000010
#define POINTER_FLAG_SECONDBUTTON 0x00000020
#define POINTER_FLAG_THIRDBUTTON 0x00000040
#define POINTER_FLAG_FOURTHBUTTON 0x00000080
#define POINTER_FLAG_FIFTHBUTTON 0x00000100
#define POINTER_FLAG_PRIMARY 0x00002000
#define POINTER_FLAG_CONFIDENCE 0x00004000
#define POINTER_FLAG_CANCELED 0x00008000
#define POINTER_FLAG_DOWN 0x00010000
#define POINTER_FLAG_UPDATE 0x00020000
#define POINTER_FLAG_UP 0x00040000
#define POINTER_FLAG_WHEEL 0x00080000
#define POINTER_FLAG_HWHEEL 0x00100000
#define POINTER_FLAG_CAPTURECHANGED 0x00200000

#define POINTER_MOD_SHIFT (0x0004)
#define POINTER_MOD_CTRL (0x0008)

#define TOUCH_FLAG_NONE 0x00000000

#define TOUCH_MASK_NONE 0x00000000
#define TOUCH_MASK_CONTACTAREA 0x00000001
#define TOUCH_MASK_ORIENTATION 0x00000002
#define TOUCH_MASK_PRESSURE 0x00000004

#define PEN_FLAG_NONE 0x00000000
#define PEN_FLAG_BARREL 0x00000001
#define PEN_FLAG_INVERTED 0x00000002
#define PEN_FLAG_ERASER 0x00000004

#define PEN_MASK_NONE 0x00000000
#define PEN_MASK_PRESSURE 0x00000001
#define PEN_MASK_ROTATION 0x00000002
#define PEN_MASK_TILT_X 0x00000004
#define PEN_MASK_TILT_Y 0x00000008

#define POINTER_MESSAGE_FLAG_NEW 0x00000001
#define POINTER_MESSAGE_FLAG_INRANGE 0x00000002
#define POINTER_MESSAGE_FLAG_INCONTACT 0x00000004
#define POINTER_MESSAGE_FLAG_FIRSTBUTTON 0x00000010
#define POINTER_MESSAGE_FLAG_SECONDBUTTON 0x00000020
#define POINTER_MESSAGE_FLAG_THIRDBUTTON 0x00000040
#define POINTER_MESSAGE_FLAG_FOURTHBUTTON 0x00000080
#define POINTER_MESSAGE_FLAG_FIFTHBUTTON 0x00000100
#define POINTER_MESSAGE_FLAG_PRIMARY 0x00002000
#define POINTER_MESSAGE_FLAG_CONFIDENCE 0x00004000
#define POINTER_MESSAGE_FLAG_CANCELED 0x00008000

#define GET_POINTERID_WPARAM(wParam) (LOWORD (wParam))
#define IS_POINTER_FLAG_SET_WPARAM(wParam, flag) (((DWORD)HIWORD (wParam) &(flag)) == (flag))
#define IS_POINTER_NEW_WPARAM(wParam) IS_POINTER_FLAG_SET_WPARAM (wParam, POINTER_MESSAGE_FLAG_NEW)
#define IS_POINTER_INRANGE_WPARAM(wParam) IS_POINTER_FLAG_SET_WPARAM (wParam, POINTER_MESSAGE_FLAG_INRANGE)
#define IS_POINTER_INCONTACT_WPARAM(wParam) IS_POINTER_FLAG_SET_WPARAM (wParam, POINTER_MESSAGE_FLAG_INCONTACT)
#define IS_POINTER_FIRSTBUTTON_WPARAM(wParam) IS_POINTER_FLAG_SET_WPARAM (wParam, POINTER_MESSAGE_FLAG_FIRSTBUTTON)
#define IS_POINTER_SECONDBUTTON_WPARAM(wParam) IS_POINTER_FLAG_SET_WPARAM (wParam, POINTER_MESSAGE_FLAG_SECONDBUTTON)
#define IS_POINTER_THIRDBUTTON_WPARAM(wParam) IS_POINTER_FLAG_SET_WPARAM (wParam, POINTER_MESSAGE_FLAG_THIRDBUTTON)
#define IS_POINTER_FOURTHBUTTON_WPARAM(wParam) IS_POINTER_FLAG_SET_WPARAM (wParam, POINTER_MESSAGE_FLAG_FOURTHBUTTON)
#define IS_POINTER_FIFTHBUTTON_WPARAM(wParam) IS_POINTER_FLAG_SET_WPARAM (wParam, POINTER_MESSAGE_FLAG_FIFTHBUTTON)
#define IS_POINTER_PRIMARY_WPARAM(wParam) IS_POINTER_FLAG_SET_WPARAM (wParam, POINTER_MESSAGE_FLAG_PRIMARY)
#define HAS_POINTER_CONFIDENCE_WPARAM(wParam) IS_POINTER_FLAG_SET_WPARAM (wParam, POINTER_MESSAGE_FLAG_CONFIDENCE)
#define IS_POINTER_CANCELED_WPARAM(wParam) IS_POINTER_FLAG_SET_WPARAM (wParam, POINTER_MESSAGE_FLAG_CANCELED)

#define PA_ACTIVATE MA_ACTIVATE
#define PA_NOACTIVATE MA_NOACTIVATE

#define MAX_TOUCH_COUNT 256

#define TOUCH_FEEDBACK_DEFAULT 0x1
#define TOUCH_FEEDBACK_INDIRECT 0x2
#define TOUCH_FEEDBACK_NONE 0x3

#define TOUCH_HIT_TESTING_DEFAULT 0x0
#define TOUCH_HIT_TESTING_CLIENT 0x1
#define TOUCH_HIT_TESTING_NONE 0x2

#define TOUCH_HIT_TESTING_PROXIMITY_CLOSEST 0x0
#define TOUCH_HIT_TESTING_PROXIMITY_FARTHEST 0xfff

#define GWFS_INCLUDE_ANCESTORS 0x00000001

#define MAPVK_VK_TO_VSC (0)
#define MAPVK_VSC_TO_VK (1)
#define MAPVK_VK_TO_CHAR (2)
#define MAPVK_VSC_TO_VK_EX (3)
#define MAPVK_VK_TO_VSC_EX (4)

#define MWMO_WAITALL 0x0001
#define MWMO_ALERTABLE 0x0002
#define MWMO_INPUTAVAILABLE 0x0004

#define QS_KEY 0x0001
#define QS_MOUSEMOVE 0x0002
#define QS_MOUSEBUTTON 0x0004
#define QS_POSTMESSAGE 0x0008
#define QS_TIMER 0x0010
#define QS_PAINT 0x0020
#define QS_SENDMESSAGE 0x0040
#define QS_HOTKEY 0x0080
#define QS_ALLPOSTMESSAGE 0x0100
#define QS_RAWINPUT 0x0400
#define QS_TOUCH 0x0800
#define QS_POINTER 0x1000

#define QS_MOUSE (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#if _WIN32_WINNT >= 0x602
#define QS_INPUT (QS_MOUSE | QS_KEY | QS_RAWINPUT | QS_TOUCH | QS_POINTER)
#else
#define QS_INPUT (QS_MOUSE | QS_KEY | QS_RAWINPUT)
#endif
#define QS_ALLEVENTS (QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)
#define QS_ALLINPUT (QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE)

#define USER_TIMER_MAXIMUM 0x7FFFFFFF
#define USER_TIMER_MINIMUM 0x0000000A

#define TIMERV_DEFAULT_COALESCING (0)
#define TIMERV_NO_COALESCING (0xffffffff)

#define TIMERV_COALESCING_MIN (1)
#define TIMERV_COALESCING_MAX (0x7ffffff5)

#define SM_CXSCREEN 0
#define SM_CYSCREEN 1
#define SM_CXVSCROLL 2
#define SM_CYHSCROLL 3
#define SM_CYCAPTION 4
#define SM_CXBORDER 5
#define SM_CYBORDER 6
#define SM_CXDLGFRAME 7
#define SM_CYDLGFRAME 8
#define SM_CYVTHUMB 9
#define SM_CXHTHUMB 10
#define SM_CXICON 11
#define SM_CYICON 12
#define SM_CXCURSOR 13
#define SM_CYCURSOR 14
#define SM_CYMENU 15
#define SM_CXFULLSCREEN 16
#define SM_CYFULLSCREEN 17
#define SM_CYKANJIWINDOW 18
#define SM_MOUSEPRESENT 19
#define SM_CYVSCROLL 20
#define SM_CXHSCROLL 21
#define SM_DEBUG 22
#define SM_SWAPBUTTON 23
#define SM_RESERVED1 24
#define SM_RESERVED2 25
#define SM_RESERVED3 26
#define SM_RESERVED4 27
#define SM_CXMIN 28
#define SM_CYMIN 29
#define SM_CXSIZE 30
#define SM_CYSIZE 31
#define SM_CXFRAME 32
#define SM_CYFRAME 33
#define SM_CXMINTRACK 34
#define SM_CYMINTRACK 35
#define SM_CXDOUBLECLK 36
#define SM_CYDOUBLECLK 37
#define SM_CXICONSPACING 38
#define SM_CYICONSPACING 39
#define SM_MENUDROPALIGNMENT 40
#define SM_PENWINDOWS 41
#define SM_DBCSENABLED 42
#define SM_CMOUSEBUTTONS 43

#define SM_CXFIXEDFRAME SM_CXDLGFRAME
#define SM_CYFIXEDFRAME SM_CYDLGFRAME
#define SM_CXSIZEFRAME SM_CXFRAME
#define SM_CYSIZEFRAME SM_CYFRAME

#define SM_SECURE 44
#define SM_CXEDGE 45
#define SM_CYEDGE 46
#define SM_CXMINSPACING 47
#define SM_CYMINSPACING 48
#define SM_CXSMICON 49
#define SM_CYSMICON 50
#define SM_CYSMCAPTION 51
#define SM_CXSMSIZE 52
#define SM_CYSMSIZE 53
#define SM_CXMENUSIZE 54
#define SM_CYMENUSIZE 55
#define SM_ARRANGE 56
#define SM_CXMINIMIZED 57
#define SM_CYMINIMIZED 58
#define SM_CXMAXTRACK 59
#define SM_CYMAXTRACK 60
#define SM_CXMAXIMIZED 61
#define SM_CYMAXIMIZED 62
#define SM_NETWORK 63
#define SM_CLEANBOOT 67
#define SM_CXDRAG 68
#define SM_CYDRAG 69
#define SM_SHOWSOUNDS 70
#define SM_CXMENUCHECK 71
#define SM_CYMENUCHECK 72
#define SM_SLOWMACHINE 73
#define SM_MIDEASTENABLED 74
#define SM_MOUSEWHEELPRESENT 75
#define SM_XVIRTUALSCREEN 76
#define SM_YVIRTUALSCREEN 77
#define SM_CXVIRTUALSCREEN 78
#define SM_CYVIRTUALSCREEN 79
#define SM_CMONITORS 80
#define SM_SAMEDISPLAYFORMAT 81
#define SM_IMMENABLED 82
#define SM_CXFOCUSBORDER 83
#define SM_CYFOCUSBORDER 84
#define SM_TABLETPC 86
#define SM_MEDIACENTER 87
#define SM_STARTER 88
#define SM_SERVERR2 89
#define SM_MOUSEHORIZONTALWHEELPRESENT 91
#define SM_CXPADDEDBORDER 92
#define SM_DIGITIZER 94
#define SM_MAXIMUMTOUCHES 95

#if WINVER <= 0x501
#define SM_CMETRICS 91
#elif WINVER == 0x600
#define SM_CMETRICS 93
#else
#define SM_CMETRICS 97
#endif

#define SM_REMOTESESSION 0x1000
#define SM_SHUTTINGDOWN 0x2000
#define SM_REMOTECONTROL 0x2001
#define SM_CARETBLINKINGENABLED 0x2002
#define SM_CONVERTIBLESLATEMODE 0x2003
#define SM_SYSTEMDOCKED 0x2004

#define PMB_ACTIVE 0x00000001

#define MNC_IGNORE 0
#define MNC_CLOSE 1
#define MNC_EXECUTE 2
#define MNC_SELECT 3

#define MNS_NOCHECK 0x80000000
#define MNS_MODELESS 0x40000000
#define MNS_DRAGDROP 0x20000000
#define MNS_AUTODISMISS 0x10000000
#define MNS_NOTIFYBYPOS 0x08000000
#define MNS_CHECKORBMP 0x04000000

#define MIM_MAXHEIGHT 0x00000001
#define MIM_BACKGROUND 0x00000002
#define MIM_HELPID 0x00000004
#define MIM_MENUDATA 0x00000008
#define MIM_STYLE 0x00000010
#define MIM_APPLYTOSUBMENUS 0x80000000

#define MND_CONTINUE 0
#define MND_ENDMENU 1

#define MNGOF_TOPGAP 0x00000001
#define MNGOF_BOTTOMGAP 0x00000002

#define MNGO_NOINTERFACE 0x00000000
#define MNGO_NOERROR 0x00000001

#define MIIM_STATE 0x00000001
#define MIIM_ID 0x00000002
#define MIIM_SUBMENU 0x00000004
#define MIIM_CHECKMARKS 0x00000008
#define MIIM_TYPE 0x00000010
#define MIIM_DATA 0x00000020
#define MIIM_STRING 0x00000040
#define MIIM_BITMAP 0x00000080
#define MIIM_FTYPE 0x00000100

#define HBMMENU_CALLBACK ((HBITMAP) -1)
#define HBMMENU_SYSTEM ((HBITMAP) 1)
#define HBMMENU_MBAR_RESTORE ((HBITMAP) 2)
#define HBMMENU_MBAR_MINIMIZE ((HBITMAP) 3)
#define HBMMENU_MBAR_CLOSE ((HBITMAP) 5)
#define HBMMENU_MBAR_CLOSE_D ((HBITMAP) 6)
#define HBMMENU_MBAR_MINIMIZE_D ((HBITMAP) 7)
#define HBMMENU_POPUP_CLOSE ((HBITMAP) 8)
#define HBMMENU_POPUP_RESTORE ((HBITMAP) 9)
#define HBMMENU_POPUP_MAXIMIZE ((HBITMAP) 10)
#define HBMMENU_POPUP_MINIMIZE ((HBITMAP) 11)

#define GMDI_USEDISABLED (int32_t)(0x0001)
#define GMDI_GOINTOPOPUPS (int32_t)(0x0002)

#define TPM_LEFTBUTTON (int32_t)(0x0000)
#define TPM_RIGHTBUTTON (int32_t)(0x0002)
#define TPM_LEFTALIGN (int32_t)(0x0000)
#define TPM_CENTERALIGN (int32_t)(0x0004)
#define TPM_RIGHTALIGN (int32_t)(0x0008)
#define TPM_TOPALIGN (int32_t)(0x0000)
#define TPM_VCENTERALIGN (int32_t)(0x0010)
#define TPM_BOTTOMALIGN (int32_t)(0x0020)

#define TPM_HORIZONTAL (int32_t)(0x0000)
#define TPM_VERTICAL (int32_t)(0x0040)
#define TPM_NONOTIFY (int32_t)(0x0080)
#define TPM_RETURNCMD (int32_t)(0x0100)
#define TPM_RECURSE (int32_t)(0x0001)
#define TPM_HORPOSANIMATION (int32_t)(0x0400)
#define TPM_HORNEGANIMATION (int32_t)(0x0800)
#define TPM_VERPOSANIMATION (int32_t)(0x1000)
#define TPM_VERNEGANIMATION (int32_t)(0x2000)
#define TPM_NOANIMATION (int32_t)(0x4000)
#define TPM_LAYOUTRTL (int32_t)(0x8000)
#define TPM_WORKAREA (int32_t)(0x10000)

#define DOF_EXECUTABLE 0x8001
#define DOF_DOCUMENT 0x8002
#define DOF_DIRECTORY 0x8003
#define DOF_MULTIPLE 0x8004
#define DOF_PROGMAN 0x0001
#define DOF_SHELLDATA 0x0002

#define DO_DROPFILE (int32_t)(0x454C4946)
#define DO_PRINTFILE (int32_t)(0x544E5250)

#define DT_TOP 0x00000000
#define DT_LEFT 0x00000000
#define DT_CENTER 0x00000001
#define DT_RIGHT 0x00000002
#define DT_VCENTER 0x00000004
#define DT_BOTTOM 0x00000008
#define DT_WORDBREAK 0x00000010
#define DT_SINGLELINE 0x00000020
#define DT_EXPANDTABS 0x00000040
#define DT_TABSTOP 0x00000080
#define DT_NOCLIP 0x00000100
#define DT_EXTERNALLEADING 0x00000200
#define DT_CALCRECT 0x00000400
#define DT_NOPREFIX 0x00000800
#define DT_INTERNAL 0x00001000
#define DT_EDITCONTROL 0x00002000
#define DT_PATH_ELLIPSIS 0x00004000
#define DT_END_ELLIPSIS 0x00008000
#define DT_MODIFYSTRING 0x00010000
#define DT_RTLREADING 0x00020000
#define DT_WORD_ELLIPSIS 0x00040000
#define DT_NOFULLWIDTHCHARBREAK 0x00080000
#define DT_HIDEPREFIX 0x00100000
#define DT_PREFIXONLY 0x00200000

#define DST_COMPLEX 0x0000
#define DST_TEXT 0x0001
#define DST_PREFIXTEXT 0x0002
#define DST_ICON 0x0003
#define DST_BITMAP 0x0004

#define DSS_NORMAL 0x0000
#define DSS_UNION 0x0010
#define DSS_DISABLED 0x0020
#define DSS_MONO 0x0080
#define DSS_HIDEPREFIX 0x0200
#define DSS_PREFIXONLY 0x0400
#define DSS_RIGHT 0x8000

#define ASFW_ANY ((DWORD)-1)

#define LSFW_LOCK 1
#define LSFW_UNLOCK 2

#define DCX_WINDOW (int32_t)(0x00000001)
#define DCX_CACHE (int32_t)(0x00000002)
#define DCX_NORESETATTRS (int32_t)(0x00000004)
#define DCX_CLIPCHILDREN (int32_t)(0x00000008)
#define DCX_CLIPSIBLINGS (int32_t)(0x00000010)
#define DCX_PARENTCLIP (int32_t)(0x00000020)
#define DCX_EXCLUDERGN (int32_t)(0x00000040)
#define DCX_INTERSECTRGN (int32_t)(0x00000080)
#define DCX_EXCLUDEUPDATE (int32_t)(0x00000100)
#define DCX_INTERSECTUPDATE (int32_t)(0x00000200)
#define DCX_LOCKWINDOWUPDATE (int32_t)(0x00000400)

#define DCX_VALIDATE (int32_t)(0x00200000)

#define RDW_INVALIDATE 0x0001
#define RDW_INTERNALPAINT 0x0002
#define RDW_ERASE 0x0004

#define RDW_VALIDATE 0x0008
#define RDW_NOINTERNALPAINT 0x0010
#define RDW_NOERASE 0x0020

#define RDW_NOCHILDREN 0x0040
#define RDW_ALLCHILDREN 0x0080

#define RDW_UPDATENOW 0x0100
#define RDW_ERASENOW 0x0200

#define RDW_FRAME 0x0400
#define RDW_NOFRAME 0x0800

#define SW_SCROLLCHILDREN 0x0001
#define SW_INVALIDATE 0x0002
#define SW_ERASE 0x0004
#define SW_SMOOTHSCROLL 0x0010

#define ESB_ENABLE_BOTH 0x0000
#define ESB_DISABLE_BOTH 0x0003
#define ESB_DISABLE_LEFT 0x0001
#define ESB_DISABLE_RIGHT 0x0002

#define ESB_DISABLE_UP 0x0001
#define ESB_DISABLE_DOWN 0x0002

#define ESB_DISABLE_LTUP ESB_DISABLE_LEFT
#define ESB_DISABLE_RTDN ESB_DISABLE_RIGHT

#define HELPINFO_WINDOW 0x0001
#define HELPINFO_MENUITEM 0x0002

#define MB_OK (int32_t)(0x00000000)
#define MB_OKCANCEL (int32_t)(0x00000001)
#define MB_ABORTRETRYIGNORE (int32_t)(0x00000002)
#define MB_YESNOCANCEL (int32_t)(0x00000003)
#define MB_YESNO (int32_t)(0x00000004)
#define MB_RETRYCANCEL (int32_t)(0x00000005)
#define MB_CANCELTRYCONTINUE (int32_t)(0x00000006)
#define MB_ICONHAND (int32_t)(0x00000010)
#define MB_ICONQUESTION (int32_t)(0x00000020)
#define MB_ICONEXCLAMATION (int32_t)(0x00000030)
#define MB_ICONASTERISK (int32_t)(0x00000040)
#define MB_USERICON (int32_t)(0x00000080)
#define MB_ICONWARNING MB_ICONEXCLAMATION
#define MB_ICONERROR MB_ICONHAND
#define MB_ICONINFORMATION MB_ICONASTERISK
#define MB_ICONSTOP MB_ICONHAND
#define MB_DEFBUTTON1 (int32_t)(0x00000000)
#define MB_DEFBUTTON2 (int32_t)(0x00000100)
#define MB_DEFBUTTON3 (int32_t)(0x00000200)
#define MB_DEFBUTTON4 (int32_t)(0x00000300)
#define MB_APPLMODAL (int32_t)(0x00000000)
#define MB_SYSTEMMODAL (int32_t)(0x00001000)
#define MB_TASKMODAL (int32_t)(0x00002000)
#define MB_HELP (int32_t)(0x00004000)
#define MB_NOFOCUS (int32_t)(0x00008000)
#define MB_SETFOREGROUND (int32_t)(0x00010000)
#define MB_DEFAULT_DESKTOP_ONLY (int32_t)(0x00020000)
#define MB_TOPMOST (int32_t)(0x00040000)
#define MB_RIGHT (int32_t)(0x00080000)
#define MB_RTLREADING (int32_t)(0x00100000)
#define MB_SERVICE_NOTIFICATION (int32_t)(0x00200000)
#define MB_SERVICE_NOTIFICATION_NT3X (int32_t)(0x00040000)
#define MB_TYPEMASK (int32_t)(0x0000000F)
#define MB_ICONMASK (int32_t)(0x000000F0)
#define MB_DEFMASK (int32_t)(0x00000F00)
#define MB_MODEMASK (int32_t)(0x00003000)
#define MB_MISCMASK (int32_t)(0x0000C000)

#define CWP_ALL 0x0000
#define CWP_SKIPINVISIBLE 0x0001
#define CWP_SKIPDISABLED 0x0002
#define CWP_SKIPTRANSPARENT 0x0004

#define CTLCOLOR_MSGBOX 0
#define CTLCOLOR_EDIT 1
#define CTLCOLOR_LISTBOX 2
#define CTLCOLOR_BTN 3
#define CTLCOLOR_DLG 4
#define CTLCOLOR_SCROLLBAR 5
#define CTLCOLOR_STATIC 6
#define CTLCOLOR_MAX 7

#define COLOR_SCROLLBAR 0
#define COLOR_BACKGROUND 1
#define COLOR_ACTIVECAPTION 2
#define COLOR_INACTIVECAPTION 3
#define COLOR_MENU 4
#define COLOR_WINDOW 5
#define COLOR_WINDOWFRAME 6
#define COLOR_MENUTEXT 7
#define COLOR_WINDOWTEXT 8
#define COLOR_CAPTIONTEXT 9
#define COLOR_ACTIVEBORDER 10
#define COLOR_INACTIVEBORDER 11
#define COLOR_APPWORKSPACE 12
#define COLOR_HIGHLIGHT 13
#define COLOR_HIGHLIGHTTEXT 14
#define COLOR_BTNFACE 15
#define COLOR_BTNSHADOW 16
#define COLOR_GRAYTEXT 17
#define COLOR_BTNTEXT 18
#define COLOR_INACTIVECAPTIONTEXT 19
#define COLOR_BTNHIGHLIGHT 20

#define COLOR_3DDKSHADOW 21
#define COLOR_3DLIGHT 22
#define COLOR_INFOTEXT 23
#define COLOR_INFOBK 24
#define COLOR_HOTLIGHT 26
#define COLOR_GRADIENTACTIVECAPTION 27
#define COLOR_GRADIENTINACTIVECAPTION 28
#define COLOR_MENUHILIGHT 29
#define COLOR_MENUBAR 30

#define COLOR_DESKTOP COLOR_BACKGROUND
#define COLOR_3DFACE COLOR_BTNFACE
#define COLOR_3DSHADOW COLOR_BTNSHADOW
#define COLOR_3DHIGHLIGHT COLOR_BTNHIGHLIGHT
#define COLOR_3DHILIGHT COLOR_BTNHIGHLIGHT
#define COLOR_BTNHILIGHT COLOR_BTNHIGHLIGHT

#define GW_HWNDFIRST 0
#define GW_HWNDLAST 1
#define GW_HWNDNEXT 2
#define GW_HWNDPREV 3
#define GW_OWNER 4
#define GW_CHILD 5
#define GW_ENABLEDPOPUP 6
#define GW_MAX 6

#define MF_INSERT (int32_t)(0x00000000)
#define MF_CHANGE (int32_t)(0x00000080)
#define MF_APPEND (int32_t)(0x00000100)
#define MF_DELETE (int32_t)(0x00000200)
#define MF_REMOVE (int32_t)(0x00001000)
#define MF_BYCOMMAND (int32_t)(0x00000000)
#define MF_BYPOSITION (int32_t)(0x00000400)
#define MF_SEPARATOR (int32_t)(0x00000800)
#define MF_ENABLED (int32_t)(0x00000000)
#define MF_GRAYED (int32_t)(0x00000001)
#define MF_DISABLED (int32_t)(0x00000002)
#define MF_UNCHECKED (int32_t)(0x00000000)
#define MF_CHECKED (int32_t)(0x00000008)
#define MF_USECHECKBITMAPS (int32_t)(0x00000200)
#define MF_STRING (int32_t)(0x00000000)
#define MF_BITMAP (int32_t)(0x00000004)
#define MF_OWNERDRAW (int32_t)(0x00000100)
#define MF_POPUP (int32_t)(0x00000010)
#define MF_MENUBARBREAK (int32_t)(0x00000020)
#define MF_MENUBREAK (int32_t)(0x00000040)
#define MF_UNHILITE (int32_t)(0x00000000)
#define MF_HILITE (int32_t)(0x00000080)
#define MF_DEFAULT (int32_t)(0x00001000)
#define MF_SYSMENU (int32_t)(0x00002000)
#define MF_HELP (int32_t)(0x00004000)
#define MF_RIGHTJUSTIFY (int32_t)(0x00004000)
#define MF_MOUSESELECT (int32_t)(0x00008000)
#define MF_END (int32_t)(0x00000080)

#define MFT_STRING MF_STRING
#define MFT_BITMAP MF_BITMAP
#define MFT_MENUBARBREAK MF_MENUBARBREAK
#define MFT_MENUBREAK MF_MENUBREAK
#define MFT_OWNERDRAW MF_OWNERDRAW
#define MFT_RADIOCHECK (int32_t)(0x00000200)
#define MFT_SEPARATOR MF_SEPARATOR
#define MFT_RIGHTORDER (int32_t)(0x00002000)
#define MFT_RIGHTJUSTIFY MF_RIGHTJUSTIFY

#define MFS_GRAYED (int32_t)(0x00000003)
#define MFS_DISABLED MFS_GRAYED
#define MFS_CHECKED MF_CHECKED
#define MFS_HILITE MF_HILITE
#define MFS_ENABLED MF_ENABLED
#define MFS_UNCHECKED MF_UNCHECKED
#define MFS_UNHILITE MF_UNHILITE
#define MFS_DEFAULT MF_DEFAULT

#define MF_END (int32_t)(0x00000080)

#define SC_SIZE 0xF000
#define SC_MOVE 0xF010
#define SC_MINIMIZE 0xF020
#define SC_MAXIMIZE 0xF030
#define SC_NEXTWINDOW 0xF040
#define SC_PREVWINDOW 0xF050
#define SC_CLOSE 0xF060
#define SC_VSCROLL 0xF070
#define SC_HSCROLL 0xF080
#define SC_MOUSEMENU 0xF090
#define SC_KEYMENU 0xF100
#define SC_ARRANGE 0xF110
#define SC_RESTORE 0xF120
#define SC_TASKLIST 0xF130
#define SC_SCREENSAVE 0xF140
#define SC_HOTKEY 0xF150
#define SC_DEFAULT 0xF160
#define SC_MONITORPOWER 0xF170
#define SC_CONTEXTHELP 0xF180
#define SC_SEPARATOR 0xF00F
#define SCF_ISSECURE 0x00000001

#define GET_SC_WPARAM(wParam) ((int)wParam &0xfff0)

#define SC_ICON SC_MINIMIZE
#define SC_ZOOM SC_MAXIMIZE

#define IDC_ARROW MAKEINTRESOURCE(32512)
#define IDC_IBEAM MAKEINTRESOURCE(32513)
#define IDC_WAIT MAKEINTRESOURCE(32514)
#define IDC_CROSS MAKEINTRESOURCE(32515)
#define IDC_UPARROW MAKEINTRESOURCE(32516)
#define IDC_SIZE MAKEINTRESOURCE(32640)
#define IDC_ICON MAKEINTRESOURCE(32641)
#define IDC_SIZENWSE MAKEINTRESOURCE(32642)
#define IDC_SIZENESW MAKEINTRESOURCE(32643)
#define IDC_SIZEWE MAKEINTRESOURCE(32644)
#define IDC_SIZENS MAKEINTRESOURCE(32645)
#define IDC_SIZEALL MAKEINTRESOURCE(32646)
#define IDC_NO MAKEINTRESOURCE(32648)
#define IDC_HAND MAKEINTRESOURCE(32649)
#define IDC_APPSTARTING MAKEINTRESOURCE(32650)
#define IDC_HELP MAKEINTRESOURCE(32651)

#define IMAGE_BITMAP 0
#define IMAGE_ICON 1
#define IMAGE_CURSOR 2
#define IMAGE_ENHMETAFILE 3

#define LR_DEFAULTCOLOR 0x0000
#define LR_MONOCHROME 0x0001
#define LR_COLOR 0x0002
#define LR_COPYRETURNORG 0x0004
#define LR_COPYDELETEORG 0x0008
#define LR_LOADFROMFILE 0x0010
#define LR_LOADTRANSPARENT 0x0020
#define LR_DEFAULTSIZE 0x0040
#define LR_VGACOLOR 0x0080
#define LR_LOADMAP3DCOLORS 0x1000
#define LR_CREATEDIBSECTION 0x2000
#define LR_COPYFROMRESOURCE 0x4000
#define LR_SHARED 0x8000

#define DI_MASK 0x0001
#define DI_IMAGE 0x0002
#define DI_NORMAL 0x0003
#define DI_COMPAT 0x0004
#define DI_DEFAULTSIZE 0x0008
#define DI_NOMIRROR 0x0010

#define RES_ICON 1
#define RES_CURSOR 2

#define OBM_CLOSE 32754
#define OBM_UPARROW 32753
#define OBM_DNARROW 32752
#define OBM_RGARROW 32751
#define OBM_LFARROW 32750
#define OBM_REDUCE 32749
#define OBM_ZOOM 32748
#define OBM_RESTORE 32747
#define OBM_REDUCED 32746
#define OBM_ZOOMD 32745
#define OBM_RESTORED 32744
#define OBM_UPARROWD 32743
#define OBM_DNARROWD 32742
#define OBM_RGARROWD 32741
#define OBM_LFARROWD 32740
#define OBM_MNARROW 32739
#define OBM_COMBO 32738
#define OBM_UPARROWI 32737
#define OBM_DNARROWI 32736
#define OBM_RGARROWI 32735
#define OBM_LFARROWI 32734

#define OBM_OLD_CLOSE 32767
#define OBM_SIZE 32766
#define OBM_OLD_UPARROW 32765
#define OBM_OLD_DNARROW 32764
#define OBM_OLD_RGARROW 32763
#define OBM_OLD_LFARROW 32762
#define OBM_BTSIZE 32761
#define OBM_CHECK 32760
#define OBM_CHECKBOXES 32759
#define OBM_BTNCORNERS 32758
#define OBM_OLD_REDUCE 32757
#define OBM_OLD_ZOOM 32756
#define OBM_OLD_RESTORE 32755

#define OCR_NORMAL 32512
#define OCR_IBEAM 32513
#define OCR_WAIT 32514
#define OCR_CROSS 32515
#define OCR_UP 32516
#define OCR_SIZE 32640
#define OCR_ICON 32641
#define OCR_SIZENWSE 32642
#define OCR_SIZENESW 32643
#define OCR_SIZEWE 32644
#define OCR_SIZENS 32645
#define OCR_SIZEALL 32646
#define OCR_ICOCUR 32647
#define OCR_NO 32648
#define OCR_HAND 32649
#define OCR_APPSTARTING 32650

#define OIC_SAMPLE 32512
#define OIC_HAND 32513
#define OIC_QUES 32514
#define OIC_BANG 32515
#define OIC_NOTE 32516
#define OIC_WINLOGO 32517
#define OIC_WARNING OIC_BANG
#define OIC_ERROR OIC_HAND
#define OIC_INFORMATION OIC_NOTE
#define OIC_SHIELD 32518

#define ORD_LANGDRIVER 1

#define IDI_APPLICATION MAKEINTRESOURCE(32512)
#define IDI_HAND MAKEINTRESOURCE(32513)
#define IDI_QUESTION MAKEINTRESOURCE(32514)
#define IDI_EXCLAMATION MAKEINTRESOURCE(32515)
#define IDI_ASTERISK MAKEINTRESOURCE(32516)
#define IDI_WINLOGO MAKEINTRESOURCE(32517)
#define IDI_SHIELD MAKEINTRESOURCE (32518)

#define IDI_WARNING IDI_EXCLAMATION
#define IDI_ERROR IDI_HAND
#define IDI_INFORMATION IDI_ASTERISK

#define IDOK 1
#define IDCANCEL 2
#define IDABORT 3
#define IDRETRY 4
#define IDIGNORE 5
#define IDYES 6
#define IDNO 7
#define IDCLOSE 8
#define IDHELP 9
#define IDTRYAGAIN 10
#define IDCONTINUE 11
#define IDTIMEOUT 32000

#define ES_LEFT (int32_t)(0x0000)
#define ES_CENTER (int32_t)(0x0001)
#define ES_RIGHT (int32_t)(0x0002)
#define ES_MULTILINE (int32_t)(0x0004)
#define ES_UPPERCASE (int32_t)(0x0008)
#define ES_LOWERCASE (int32_t)(0x0010)
#define ES_PASSWORD (int32_t)(0x0020)
#define ES_AUTOVSCROLL (int32_t)(0x0040)
#define ES_AUTOHSCROLL (int32_t)(0x0080)
#define ES_NOHIDESEL (int32_t)(0x0100)
#define ES_OEMCONVERT (int32_t)(0x0400)
#define ES_READONLY (int32_t)(0x0800)
#define ES_WANTRETURN (int32_t)(0x1000)
#define ES_NUMBER (int32_t)(0x2000)

#define EN_SETFOCUS 0x0100
#define EN_KILLFOCUS 0x0200
#define EN_CHANGE 0x0300
#define EN_UPDATE 0x0400
#define EN_ERRSPACE 0x0500
#define EN_MAXTEXT 0x0501
#define EN_HSCROLL 0x0601
#define EN_VSCROLL 0x0602
#define EN_ALIGN_LTR_EC 0x0700
#define EN_ALIGN_RTL_EC 0x0701

#define EC_LEFTMARGIN 0x0001
#define EC_RIGHTMARGIN 0x0002
#define EC_USEFONTINFO 0xffff

#define EMSIS_COMPOSITIONSTRING 0x0001

#define EIMES_GETCOMPSTRATONCE 0x0001
#define EIMES_CANCELCOMPSTRINFOCUS 0x0002
#define EIMES_COMPLETECOMPSTRKILLFOCUS 0x0004

#define EM_GETSEL 0x00B0
#define EM_SETSEL 0x00B1
#define EM_GETRECT 0x00B2
#define EM_SETRECT 0x00B3
#define EM_SETRECTNP 0x00B4
#define EM_SCROLL 0x00B5
#define EM_LINESCROLL 0x00B6
#define EM_SCROLLCARET 0x00B7
#define EM_GETMODIFY 0x00B8
#define EM_SETMODIFY 0x00B9
#define EM_GETLINECOUNT 0x00BA
#define EM_LINEINDEX 0x00BB
#define EM_SETHANDLE 0x00BC
#define EM_GETHANDLE 0x00BD
#define EM_GETTHUMB 0x00BE
#define EM_LINELENGTH 0x00C1
#define EM_REPLACESEL 0x00C2
#define EM_GETLINE 0x00C4
#define EM_LIMITTEXT 0x00C5
#define EM_CANUNDO 0x00C6
#define EM_UNDO 0x00C7
#define EM_FMTLINES 0x00C8
#define EM_LINEFROMCHAR 0x00C9
#define EM_SETTABSTOPS 0x00CB
#define EM_SETPASSWORDCHAR 0x00CC
#define EM_EMPTYUNDOBUFFER 0x00CD
#define EM_GETFIRSTVISIBLELINE 0x00CE
#define EM_SETREADONLY 0x00CF
#define EM_SETWORDBREAKPROC 0x00D0
#define EM_GETWORDBREAKPROC 0x00D1
#define EM_GETPASSWORDCHAR 0x00D2
#define EM_SETMARGINS 0x00D3
#define EM_GETMARGINS 0x00D4
#define EM_SETLIMITTEXT EM_LIMITTEXT
#define EM_GETLIMITTEXT 0x00D5
#define EM_POSFROMCHAR 0x00D6
#define EM_CHARFROMPOS 0x00D7
#define EM_SETIMESTATUS 0x00D8
#define EM_GETIMESTATUS 0x00D9

#define WB_LEFT 0
#define WB_RIGHT 1
#define WB_ISDELIMITER 2

#define BS_PUSHBUTTON (int32_t)(0x00000000)
#define BS_DEFPUSHBUTTON (int32_t)(0x00000001)
#define BS_CHECKBOX (int32_t)(0x00000002)
#define BS_AUTOCHECKBOX (int32_t)(0x00000003)
#define BS_RADIOBUTTON (int32_t)(0x00000004)
#define BS_3STATE (int32_t)(0x00000005)
#define BS_AUTO3STATE (int32_t)(0x00000006)
#define BS_GROUPBOX (int32_t)(0x00000007)
#define BS_USERBUTTON (int32_t)(0x00000008)
#define BS_AUTORADIOBUTTON (int32_t)(0x00000009)
#define BS_PUSHBOX (int32_t)(0x0000000A)
#define BS_OWNERDRAW (int32_t)(0x0000000B)
#define BS_TYPEMASK (int32_t)(0x0000000F)
#define BS_LEFTTEXT (int32_t)(0x00000020)
#define BS_TEXT (int32_t)(0x00000000)
#define BS_ICON (int32_t)(0x00000040)
#define BS_BITMAP (int32_t)(0x00000080)
#define BS_LEFT (int32_t)(0x00000100)
#define BS_RIGHT (int32_t)(0x00000200)
#define BS_CENTER (int32_t)(0x00000300)
#define BS_TOP (int32_t)(0x00000400)
#define BS_BOTTOM (int32_t)(0x00000800)
#define BS_VCENTER (int32_t)(0x00000C00)
#define BS_PUSHLIKE (int32_t)(0x00001000)
#define BS_MULTILINE (int32_t)(0x00002000)
#define BS_NOTIFY (int32_t)(0x00004000)
#define BS_FLAT (int32_t)(0x00008000)
#define BS_RIGHTBUTTON BS_LEFTTEXT

#define BN_CLICKED 0
#define BN_PAINT 1
#define BN_HILITE 2
#define BN_UNHILITE 3
#define BN_DISABLE 4
#define BN_DOUBLECLICKED 5
#define BN_PUSHED BN_HILITE
#define BN_UNPUSHED BN_UNHILITE
#define BN_DBLCLK BN_DOUBLECLICKED
#define BN_SETFOCUS 6
#define BN_KILLFOCUS 7

#define BM_GETCHECK 0x00F0
#define BM_SETCHECK 0x00F1
#define BM_GETSTATE 0x00F2
#define BM_SETSTATE 0x00F3
#define BM_SETSTYLE 0x00F4
#define BM_CLICK 0x00F5
#define BM_GETIMAGE 0x00F6
#define BM_SETIMAGE 0x00F7
#define BM_SETDONTCLICK 0x00f8

#define BST_UNCHECKED 0x0000
#define BST_CHECKED 0x0001
#define BST_INDETERMINATE 0x0002
#define BST_PUSHED 0x0004
#define BST_FOCUS 0x0008

#define SS_LEFT (int32_t)(0x00000000)
#define SS_CENTER (int32_t)(0x00000001)
#define SS_RIGHT (int32_t)(0x00000002)
#define SS_ICON (int32_t)(0x00000003)
#define SS_BLACKRECT (int32_t)(0x00000004)
#define SS_GRAYRECT (int32_t)(0x00000005)
#define SS_WHITERECT (int32_t)(0x00000006)
#define SS_BLACKFRAME (int32_t)(0x00000007)
#define SS_GRAYFRAME (int32_t)(0x00000008)
#define SS_WHITEFRAME (int32_t)(0x00000009)
#define SS_USERITEM (int32_t)(0x0000000A)
#define SS_SIMPLE (int32_t)(0x0000000B)
#define SS_LEFTNOWORDWRAP (int32_t)(0x0000000C)
#define SS_OWNERDRAW (int32_t)(0x0000000D)
#define SS_BITMAP (int32_t)(0x0000000E)
#define SS_ENHMETAFILE (int32_t)(0x0000000F)
#define SS_ETCHEDHORZ (int32_t)(0x00000010)
#define SS_ETCHEDVERT (int32_t)(0x00000011)
#define SS_ETCHEDFRAME (int32_t)(0x00000012)
#define SS_TYPEMASK (int32_t)(0x0000001F)
#define SS_REALSIZECONTROL (int32_t)(0x00000040)
#define SS_NOPREFIX (int32_t)(0x00000080)
#define SS_NOTIFY (int32_t)(0x00000100)
#define SS_CENTERIMAGE (int32_t)(0x00000200)
#define SS_RIGHTJUST (int32_t)(0x00000400)
#define SS_REALSIZEIMAGE (int32_t)(0x00000800)
#define SS_SUNKEN (int32_t)(0x00001000)
#define SS_EDITCONTROL (int32_t)(0x00002000)
#define SS_ENDELLIPSIS (int32_t)(0x00004000)
#define SS_PATHELLIPSIS (int32_t)(0x00008000)
#define SS_WORDELLIPSIS (int32_t)(0x0000C000)
#define SS_ELLIPSISMASK (int32_t)(0x0000C000)

#define STM_SETICON 0x0170
#define STM_GETICON 0x0171
#define STM_SETIMAGE 0x0172
#define STM_GETIMAGE 0x0173
#define STN_CLICKED 0
#define STN_DBLCLK 1
#define STN_ENABLE 2
#define STN_DISABLE 3

#define STM_MSGMAX 0x0174

#define WC_DIALOG (MAKEINTATOM(0x8002))

#ifndef __NT64
#define DWL_MSGRESULT 0
#define DWL_DLGPROC 4
#define DWL_USER 8
#endif

#define DWLP_MSGRESULT 0
#define DWLP_DLGPROC DWLP_MSGRESULT + sizeof(LRESULT)
#define DWLP_USER DWLP_DLGPROC + sizeof(DLGPROC)

#define DDL_READWRITE 0x0000
#define DDL_READONLY 0x0001
#define DDL_HIDDEN 0x0002
#define DDL_SYSTEM 0x0004
#define DDL_DIRECTORY 0x0010
#define DDL_ARCHIVE 0x0020

#define DDL_POSTMSGS 0x2000
#define DDL_DRIVES 0x4000
#define DDL_EXCLUSIVE 0x8000


#define DS_ABSALIGN (int32_t)(0x01)
#define DS_SYSMODAL (int32_t)(0x02)
#define DS_LOCALEDIT (int32_t)(0x20)

#define DS_SETFONT (int32_t)(0x40)
#define DS_MODALFRAME (int32_t)(0x80)
#define DS_NOIDLEMSG (int32_t)(0x100)
#define DS_SETFOREGROUND (int32_t)(0x200)

#define DS_3DLOOK (int32_t)(0x0004)
#define DS_FIXEDSYS (int32_t)(0x0008)
#define DS_NOFAILCREATE (int32_t)(0x0010)
#define DS_CONTROL (int32_t)(0x0400)
#define DS_CENTER (int32_t)(0x0800)
#define DS_CENTERMOUSE (int32_t)(0x1000)
#define DS_CONTEXTHELP (int32_t)(0x2000)

#define DS_SHELLFONT (DS_SETFONT | DS_FIXEDSYS)

#define DM_GETDEFID (WM_USER+0)
#define DM_SETDEFID (WM_USER+1)
#define DM_REPOSITION (WM_USER+2)

#define DC_HASDEFID 0x534B

#define DLGC_WANTARROWS 0x0001
#define DLGC_WANTTAB 0x0002
#define DLGC_WANTALLKEYS 0x0004
#define DLGC_WANTMESSAGE 0x0004
#define DLGC_HASSETSEL 0x0008
#define DLGC_DEFPUSHBUTTON 0x0010
#define DLGC_UNDEFPUSHBUTTON 0x0020
#define DLGC_RADIOBUTTON 0x0040
#define DLGC_WANTCHARS 0x0080
#define DLGC_STATIC 0x0100
#define DLGC_BUTTON 0x2000

#define LB_CTLCODE (int32_t)(0)

#define LB_OKAY 0
#define LB_ERR (-1)
#define LB_ERRSPACE (-2)

#define LBN_ERRSPACE (-2)
#define LBN_SELCHANGE 1
#define LBN_DBLCLK 2
#define LBN_SELCANCEL 3
#define LBN_SETFOCUS 4
#define LBN_KILLFOCUS 5

#define LB_ADDSTRING 0x0180
#define LB_INSERTSTRING 0x0181
#define LB_DELETESTRING 0x0182
#define LB_SELITEMRANGEEX 0x0183
#define LB_RESETCONTENT 0x0184
#define LB_SETSEL 0x0185
#define LB_SETCURSEL 0x0186
#define LB_GETSEL 0x0187
#define LB_GETCURSEL 0x0188
#define LB_GETTEXT 0x0189
#define LB_GETTEXTLEN 0x018A
#define LB_GETCOUNT 0x018B
#define LB_SELECTSTRING 0x018C
#define LB_DIR 0x018D
#define LB_GETTOPINDEX 0x018E
#define LB_FINDSTRING 0x018F
#define LB_GETSELCOUNT 0x0190
#define LB_GETSELITEMS 0x0191
#define LB_SETTABSTOPS 0x0192
#define LB_GETHORIZONTALEXTENT 0x0193
#define LB_SETHORIZONTALEXTENT 0x0194
#define LB_SETCOLUMNWIDTH 0x0195
#define LB_ADDFILE 0x0196
#define LB_SETTOPINDEX 0x0197
#define LB_GETITEMRECT 0x0198
#define LB_GETITEMDATA 0x0199
#define LB_SETITEMDATA 0x019A
#define LB_SELITEMRANGE 0x019B
#define LB_SETANCHORINDEX 0x019C
#define LB_GETANCHORINDEX 0x019D
#define LB_SETCARETINDEX 0x019E
#define LB_GETCARETINDEX 0x019F
#define LB_SETITEMHEIGHT 0x01A0
#define LB_GETITEMHEIGHT 0x01A1
#define LB_FINDSTRINGEXACT 0x01A2
#define LB_SETLOCALE 0x01A5
#define LB_GETLOCALE 0x01A6
#define LB_SETCOUNT 0x01A7
#define LB_INITSTORAGE 0x01A8
#define LB_ITEMFROMPOINT 0x01A9
#define LB_GETLISTBOXINFO 0x01B2
#define LB_MSGMAX 0x01B3

#define LBS_NOTIFY (int32_t)(0x0001)
#define LBS_SORT (int32_t)(0x0002)
#define LBS_NOREDRAW (int32_t)(0x0004)
#define LBS_MULTIPLESEL (int32_t)(0x0008)
#define LBS_OWNERDRAWFIXED (int32_t)(0x0010)
#define LBS_OWNERDRAWVARIABLE (int32_t)(0x0020)
#define LBS_HASSTRINGS (int32_t)(0x0040)
#define LBS_USETABSTOPS (int32_t)(0x0080)
#define LBS_NOINTEGRALHEIGHT (int32_t)(0x0100)
#define LBS_MULTICOLUMN (int32_t)(0x0200)
#define LBS_WANTKEYBOARDINPUT (int32_t)(0x0400)
#define LBS_EXTENDEDSEL (int32_t)(0x0800)
#define LBS_DISABLENOSCROLL (int32_t)(0x1000)
#define LBS_NODATA (int32_t)(0x2000)
#define LBS_NOSEL (int32_t)(0x4000)
#define LBS_COMBOBOX (int32_t)(0x8000)

#define LBS_STANDARD (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)

#define CB_OKAY 0
#define CB_ERR (-1)
#define CB_ERRSPACE (-2)

#define CBN_ERRSPACE (-1)
#define CBN_SELCHANGE 1
#define CBN_DBLCLK 2
#define CBN_SETFOCUS 3
#define CBN_KILLFOCUS 4
#define CBN_EDITCHANGE 5
#define CBN_EDITUPDATE 6
#define CBN_DROPDOWN 7
#define CBN_CLOSEUP 8
#define CBN_SELENDOK 9
#define CBN_SELENDCANCEL 10

#define CBS_SIMPLE (int32_t)(0x0001)
#define CBS_DROPDOWN (int32_t)(0x0002)
#define CBS_DROPDOWNLIST (int32_t)(0x0003)
#define CBS_OWNERDRAWFIXED (int32_t)(0x0010)
#define CBS_OWNERDRAWVARIABLE (int32_t)(0x0020)
#define CBS_AUTOHSCROLL (int32_t)(0x0040)
#define CBS_OEMCONVERT (int32_t)(0x0080)
#define CBS_SORT (int32_t)(0x0100)
#define CBS_HASSTRINGS (int32_t)(0x0200)
#define CBS_NOINTEGRALHEIGHT (int32_t)(0x0400)
#define CBS_DISABLENOSCROLL (int32_t)(0x0800)
#define CBS_UPPERCASE (int32_t)(0x2000)
#define CBS_LOWERCASE (int32_t)(0x4000)

#define CB_GETEDITSEL 0x0140
#define CB_LIMITTEXT 0x0141
#define CB_SETEDITSEL 0x0142
#define CB_ADDSTRING 0x0143
#define CB_DELETESTRING 0x0144
#define CB_DIR 0x0145
#define CB_GETCOUNT 0x0146
#define CB_GETCURSEL 0x0147
#define CB_GETLBTEXT 0x0148
#define CB_GETLBTEXTLEN 0x0149
#define CB_INSERTSTRING 0x014A
#define CB_RESETCONTENT 0x014B
#define CB_FINDSTRING 0x014C
#define CB_SELECTSTRING 0x014D
#define CB_SETCURSEL 0x014E
#define CB_SHOWDROPDOWN 0x014F
#define CB_GETITEMDATA 0x0150
#define CB_SETITEMDATA 0x0151
#define CB_GETDROPPEDCONTROLRECT 0x0152
#define CB_SETITEMHEIGHT 0x0153
#define CB_GETITEMHEIGHT 0x0154
#define CB_SETEXTENDEDUI 0x0155
#define CB_GETEXTENDEDUI 0x0156
#define CB_GETDROPPEDSTATE 0x0157
#define CB_FINDSTRINGEXACT 0x0158
#define CB_SETLOCALE 0x0159
#define CB_GETLOCALE 0x015A
#define CB_GETTOPINDEX 0x015b
#define CB_SETTOPINDEX 0x015c
#define CB_GETHORIZONTALEXTENT 0x015d
#define CB_SETHORIZONTALEXTENT 0x015e
#define CB_GETDROPPEDWIDTH 0x015f
#define CB_SETDROPPEDWIDTH 0x0160
#define CB_INITSTORAGE 0x0161
#define CB_GETCOMBOBOXINFO 0x0164
#define CB_MSGMAX 0x0165

#define SBS_HORZ (int32_t)(0x0000)
#define SBS_VERT (int32_t)(0x0001)
#define SBS_TOPALIGN (int32_t)(0x0002)
#define SBS_LEFTALIGN (int32_t)(0x0002)
#define SBS_BOTTOMALIGN (int32_t)(0x0004)
#define SBS_RIGHTALIGN (int32_t)(0x0004)
#define SBS_SIZEBOXTOPLEFTALIGN (int32_t)(0x0002)
#define SBS_SIZEBOXBOTTOMRIGHTALIGN (int32_t)(0x0004)
#define SBS_SIZEBOX (int32_t)(0x0008)
#define SBS_SIZEGRIP (int32_t)(0x0010)

#define SBM_SETPOS 0x00E0
#define SBM_GETPOS 0x00E1
#define SBM_SETRANGE 0x00E2
#define SBM_SETRANGEREDRAW 0x00E6
#define SBM_GETRANGE 0x00E3
#define SBM_ENABLE_ARROWS 0x00E4
#define SBM_SETSCROLLINFO 0x00E9
#define SBM_GETSCROLLINFO 0x00EA
#define SBM_GETSCROLLBARINFO 0x00EB

#define SIF_RANGE 0x0001
#define SIF_PAGE 0x0002
#define SIF_POS 0x0004
#define SIF_DISABLENOSCROLL 0x0008
#define SIF_TRACKPOS 0x0010
#define SIF_ALL (SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS)

#define MDIS_ALLCHILDSTYLES 0x0001

#define MDITILE_VERTICAL 0x0000
#define MDITILE_HORIZONTAL 0x0001
#define MDITILE_SKIPDISABLED 0x0002
#define MDITILE_ZORDER 0x0004

#define HELP_CONTEXT 0x0001
#define HELP_QUIT 0x0002
#define HELP_INDEX 0x0003
#define HELP_CONTENTS 0x0003
#define HELP_HELPONHELP 0x0004
#define HELP_SETINDEX 0x0005
#define HELP_SETCONTENTS 0x0005
#define HELP_CONTEXTPOPUP 0x0008
#define HELP_FORCEFILE 0x0009
#define HELP_KEY 0x0101
#define HELP_COMMAND 0x0102
#define HELP_PARTIALKEY 0x0105
#define HELP_MULTIKEY 0x0201
#define HELP_SETWINPOS 0x0203
#define HELP_CONTEXTMENU 0x000a
#define HELP_FINDER 0x000b
#define HELP_WM_HELP 0x000c
#define HELP_SETPOPUP_POS 0x000d

#define HELP_TCARD 0x8000
#define HELP_TCARD_DATA 0x0010
#define HELP_TCARD_OTHER_CALLER 0x0011

#define IDH_NO_HELP 28440
#define IDH_MISSING_CONTEXT 28441
#define IDH_GENERIC_HELP_BUTTON 28442
#define IDH_OK 28443
#define IDH_CANCEL 28444
#define IDH_HELP 28445

#define GR_GDIOBJECTS 0
#define GR_USEROBJECTS 1
#define GR_GDIOBJECTS_PEAK 2
#define GR_USEROBJECTS_PEAK 4

#define GR_GLOBAL ((HANDLE)-2)

#define SPI_GETBEEP 0x0001
#define SPI_SETBEEP 0x0002
#define SPI_GETMOUSE 0x0003
#define SPI_SETMOUSE 0x0004
#define SPI_GETBORDER 0x0005
#define SPI_SETBORDER 0x0006
#define SPI_GETKEYBOARDSPEED 0x000A
#define SPI_SETKEYBOARDSPEED 0x000B
#define SPI_LANGDRIVER 0x000C
#define SPI_ICONHORIZONTALSPACING 0x000D
#define SPI_GETSCREENSAVETIMEOUT 0x000E
#define SPI_SETSCREENSAVETIMEOUT 0x000F
#define SPI_GETSCREENSAVEACTIVE 0x0010
#define SPI_SETSCREENSAVEACTIVE 0x0011
#define SPI_GETGRIDGRANULARITY 0x0012
#define SPI_SETGRIDGRANULARITY 0x0013
#define SPI_SETDESKWALLPAPER 0x0014
#define SPI_SETDESKPATTERN 0x0015
#define SPI_GETKEYBOARDDELAY 0x0016
#define SPI_SETKEYBOARDDELAY 0x0017
#define SPI_ICONVERTICALSPACING 0x0018
#define SPI_GETICONTITLEWRAP 0x0019
#define SPI_SETICONTITLEWRAP 0x001A
#define SPI_GETMENUDROPALIGNMENT 0x001B
#define SPI_SETMENUDROPALIGNMENT 0x001C
#define SPI_SETDOUBLECLKWIDTH 0x001D
#define SPI_SETDOUBLECLKHEIGHT 0x001E
#define SPI_GETICONTITLELOGFONT 0x001F
#define SPI_SETDOUBLECLICKTIME 0x0020
#define SPI_SETMOUSEBUTTONSWAP 0x0021
#define SPI_SETICONTITLELOGFONT 0x0022
#define SPI_GETFASTTASKSWITCH 0x0023
#define SPI_SETFASTTASKSWITCH 0x0024
#define SPI_SETDRAGFULLWINDOWS 0x0025
#define SPI_GETDRAGFULLWINDOWS 0x0026
#define SPI_GETNONCLIENTMETRICS 0x0029
#define SPI_SETNONCLIENTMETRICS 0x002A
#define SPI_GETMINIMIZEDMETRICS 0x002B
#define SPI_SETMINIMIZEDMETRICS 0x002C
#define SPI_GETICONMETRICS 0x002D
#define SPI_SETICONMETRICS 0x002E
#define SPI_SETWORKAREA 0x002F
#define SPI_GETWORKAREA 0x0030
#define SPI_SETPENWINDOWS 0x0031

#define SPI_GETHIGHCONTRAST 0x0042
#define SPI_SETHIGHCONTRAST 0x0043
#define SPI_GETKEYBOARDPREF 0x0044
#define SPI_SETKEYBOARDPREF 0x0045
#define SPI_GETSCREENREADER 0x0046
#define SPI_SETSCREENREADER 0x0047
#define SPI_GETANIMATION 0x0048
#define SPI_SETANIMATION 0x0049
#define SPI_GETFONTSMOOTHING 0x004A
#define SPI_SETFONTSMOOTHING 0x004B
#define SPI_SETDRAGWIDTH 0x004C
#define SPI_SETDRAGHEIGHT 0x004D
#define SPI_SETHANDHELD 0x004E
#define SPI_GETLOWPOWERTIMEOUT 0x004F
#define SPI_GETPOWEROFFTIMEOUT 0x0050
#define SPI_SETLOWPOWERTIMEOUT 0x0051
#define SPI_SETPOWEROFFTIMEOUT 0x0052
#define SPI_GETLOWPOWERACTIVE 0x0053
#define SPI_GETPOWEROFFACTIVE 0x0054
#define SPI_SETLOWPOWERACTIVE 0x0055
#define SPI_SETPOWEROFFACTIVE 0x0056
#define SPI_SETCURSORS 0x0057
#define SPI_SETICONS 0x0058
#define SPI_GETDEFAULTINPUTLANG 0x0059
#define SPI_SETDEFAULTINPUTLANG 0x005A
#define SPI_SETLANGTOGGLE 0x005B
#define SPI_GETWINDOWSEXTENSION 0x005C
#define SPI_SETMOUSETRAILS 0x005D
#define SPI_GETMOUSETRAILS 0x005E
#define SPI_SETSCREENSAVERRUNNING 0x0061
#define SPI_SCREENSAVERRUNNING SPI_SETSCREENSAVERRUNNING
#define SPI_GETFILTERKEYS 0x0032
#define SPI_SETFILTERKEYS 0x0033
#define SPI_GETTOGGLEKEYS 0x0034
#define SPI_SETTOGGLEKEYS 0x0035
#define SPI_GETMOUSEKEYS 0x0036
#define SPI_SETMOUSEKEYS 0x0037
#define SPI_GETSHOWSOUNDS 0x0038
#define SPI_SETSHOWSOUNDS 0x0039
#define SPI_GETSTICKYKEYS 0x003A
#define SPI_SETSTICKYKEYS 0x003B
#define SPI_GETACCESSTIMEOUT 0x003C
#define SPI_SETACCESSTIMEOUT 0x003D
#define SPI_GETSERIALKEYS 0x003E
#define SPI_SETSERIALKEYS 0x003F
#define SPI_GETSOUNDSENTRY 0x0040
#define SPI_SETSOUNDSENTRY 0x0041
#define SPI_GETSNAPTODEFBUTTON 0x005F
#define SPI_SETSNAPTODEFBUTTON 0x0060
#define SPI_GETMOUSEHOVERWIDTH 0x0062
#define SPI_SETMOUSEHOVERWIDTH 0x0063
#define SPI_GETMOUSEHOVERHEIGHT 0x0064
#define SPI_SETMOUSEHOVERHEIGHT 0x0065
#define SPI_GETMOUSEHOVERTIME 0x0066
#define SPI_SETMOUSEHOVERTIME 0x0067
#define SPI_GETWHEELSCROLLLINES 0x0068
#define SPI_SETWHEELSCROLLLINES 0x0069
#define SPI_GETMENUSHOWDELAY 0x006A
#define SPI_SETMENUSHOWDELAY 0x006B
#define SPI_GETWHEELSCROLLCHARS 0x006C
#define SPI_SETWHEELSCROLLCHARS 0x006D
#define SPI_GETSHOWIMEUI 0x006E
#define SPI_SETSHOWIMEUI 0x006F
#define SPI_GETMOUSESPEED 0x0070
#define SPI_SETMOUSESPEED 0x0071
#define SPI_GETSCREENSAVERRUNNING 0x0072
#define SPI_GETDESKWALLPAPER 0x0073
#define SPI_GETAUDIODESCRIPTION 0x0074
#define SPI_SETAUDIODESCRIPTION 0x0075
#define SPI_GETSCREENSAVESECURE 0x0076
#define SPI_SETSCREENSAVESECURE 0x0077
#define SPI_GETHUNGAPPTIMEOUT 0x0078
#define SPI_SETHUNGAPPTIMEOUT 0x0079
#define SPI_GETWAITTOKILLTIMEOUT 0x007a
#define SPI_SETWAITTOKILLTIMEOUT 0x007b
#define SPI_GETWAITTOKILLSERVICETIMEOUT 0x007c
#define SPI_SETWAITTOKILLSERVICETIMEOUT 0x007d
#define SPI_GETMOUSEDOCKTHRESHOLD 0x007e
#define SPI_SETMOUSEDOCKTHRESHOLD 0x007f
#define SPI_GETPENDOCKTHRESHOLD 0x0080
#define SPI_SETPENDOCKTHRESHOLD 0x0081
#define SPI_GETWINARRANGING 0x0082
#define SPI_SETWINARRANGING 0x0083
#define SPI_GETMOUSEDRAGOUTTHRESHOLD 0x0084
#define SPI_SETMOUSEDRAGOUTTHRESHOLD 0x0085
#define SPI_GETPENDRAGOUTTHRESHOLD 0x0086
#define SPI_SETPENDRAGOUTTHRESHOLD 0x0087
#define SPI_GETMOUSESIDEMOVETHRESHOLD 0x0088
#define SPI_SETMOUSESIDEMOVETHRESHOLD 0x0089
#define SPI_GETPENSIDEMOVETHRESHOLD 0x008a
#define SPI_SETPENSIDEMOVETHRESHOLD 0x008b
#define SPI_GETDRAGFROMMAXIMIZE 0x008c
#define SPI_SETDRAGFROMMAXIMIZE 0x008d
#define SPI_GETSNAPSIZING 0x008e
#define SPI_SETSNAPSIZING 0x008f
#define SPI_GETDOCKMOVING 0x0090
#define SPI_SETDOCKMOVING 0x0091
#define SPI_GETTOUCHPREDICTIONPARAMETERS 0x009c
#define SPI_SETTOUCHPREDICTIONPARAMETERS 0x009d
#define SPI_GETLOGICALDPIOVERRIDE 0x009e
#define SPI_SETLOGICALDPIOVERRIDE 0x009f
#define SPI_GETMOUSECORNERCLIPLENGTH 0x00a0
#define SPI_SETMOUSECORNERCLIPLENGTH 0x00a1
#define SPI_GETMENURECT 0x00a2
#define SPI_SETMENURECT 0x00a3

#define SPI_GETACTIVEWINDOWTRACKING 0x1000
#define SPI_SETACTIVEWINDOWTRACKING 0x1001
#define SPI_GETMENUANIMATION 0x1002
#define SPI_SETMENUANIMATION 0x1003
#define SPI_GETCOMBOBOXANIMATION 0x1004
#define SPI_SETCOMBOBOXANIMATION 0x1005
#define SPI_GETLISTBOXSMOOTHSCROLLING 0x1006
#define SPI_SETLISTBOXSMOOTHSCROLLING 0x1007
#define SPI_GETGRADIENTCAPTIONS 0x1008
#define SPI_SETGRADIENTCAPTIONS 0x1009
#define SPI_GETKEYBOARDCUES 0x100A
#define SPI_SETKEYBOARDCUES 0x100B
#define SPI_GETMENUUNDERLINES SPI_GETKEYBOARDCUES
#define SPI_SETMENUUNDERLINES SPI_SETKEYBOARDCUES
#define SPI_GETACTIVEWNDTRKZORDER 0x100C
#define SPI_SETACTIVEWNDTRKZORDER 0x100D
#define SPI_GETHOTTRACKING 0x100E
#define SPI_SETHOTTRACKING 0x100F
#define SPI_GETMENUFADE 0x1012
#define SPI_SETMENUFADE 0x1013
#define SPI_GETSELECTIONFADE 0x1014
#define SPI_SETSELECTIONFADE 0x1015
#define SPI_GETTOOLTIPANIMATION 0x1016
#define SPI_SETTOOLTIPANIMATION 0x1017
#define SPI_GETTOOLTIPFADE 0x1018
#define SPI_SETTOOLTIPFADE 0x1019
#define SPI_GETCURSORSHADOW 0x101A
#define SPI_SETCURSORSHADOW 0x101B
#define SPI_GETMOUSESONAR 0x101C
#define SPI_SETMOUSESONAR 0x101D
#define SPI_GETMOUSECLICKLOCK 0x101E
#define SPI_SETMOUSECLICKLOCK 0x101F
#define SPI_GETMOUSEVANISH 0x1020
#define SPI_SETMOUSEVANISH 0x1021
#define SPI_GETFLATMENU 0x1022
#define SPI_SETFLATMENU 0x1023
#define SPI_GETDROPSHADOW 0x1024
#define SPI_SETDROPSHADOW 0x1025
#define SPI_GETBLOCKSENDINPUTRESETS 0x1026
#define SPI_SETBLOCKSENDINPUTRESETS 0x1027
#define SPI_GETUIEFFECTS 0x103E
#define SPI_SETUIEFFECTS 0x103F
#define SPI_GETDISABLEOVERLAPPEDCONTENT 0x1040
#define SPI_SETDISABLEOVERLAPPEDCONTENT 0x1041
#define SPI_GETCLIENTAREAANIMATION 0x1042
#define SPI_SETCLIENTAREAANIMATION 0x1043
#define SPI_GETCLEARTYPE 0x1048
#define SPI_SETCLEARTYPE 0x1049
#define SPI_GETSPEECHRECOGNITION 0x104a
#define SPI_SETSPEECHRECOGNITION 0x104b
#define SPI_GETCARETBROWSING 0x104c
#define SPI_SETCARETBROWSING 0x104d
#define SPI_GETTHREADLOCALINPUTSETTINGS 0x104e
#define SPI_SETTHREADLOCALINPUTSETTINGS 0x104f
#define SPI_GETSYSTEMLANGUAGEBAR 0x1050
#define SPI_SETSYSTEMLANGUAGEBAR 0x1051
#define SPI_GETFOREGROUNDLOCKTIMEOUT 0x2000
#define SPI_SETFOREGROUNDLOCKTIMEOUT 0x2001
#define SPI_GETACTIVEWNDTRKTIMEOUT 0x2002
#define SPI_SETACTIVEWNDTRKTIMEOUT 0x2003
#define SPI_GETFOREGROUNDFLASHCOUNT 0x2004
#define SPI_SETFOREGROUNDFLASHCOUNT 0x2005
#define SPI_GETCARETWIDTH 0x2006
#define SPI_SETCARETWIDTH 0x2007
#define SPI_GETMOUSECLICKLOCKTIME 0x2008
#define SPI_SETMOUSECLICKLOCKTIME 0x2009
#define SPI_GETFONTSMOOTHINGTYPE 0x200A
#define SPI_SETFONTSMOOTHINGTYPE 0x200B

#define FE_FONTSMOOTHINGSTANDARD 0x0001
#define FE_FONTSMOOTHINGCLEARTYPE 0x0002
#define FE_FONTSMOOTHINGDOCKING 0x8000

#define SPI_GETFONTSMOOTHINGCONTRAST 0x200C
#define SPI_SETFONTSMOOTHINGCONTRAST 0x200D
#define SPI_GETFOCUSBORDERWIDTH 0x200E
#define SPI_SETFOCUSBORDERWIDTH 0x200F
#define SPI_GETFOCUSBORDERHEIGHT 0x2010
#define SPI_SETFOCUSBORDERHEIGHT 0x2011
#define SPI_GETFONTSMOOTHINGORIENTATION 0x2012
#define SPI_SETFONTSMOOTHINGORIENTATION 0x2013
#define SPI_GETMINIMUMHITRADIUS 0x2014
#define SPI_SETMINIMUMHITRADIUS 0x2015
#define SPI_GETMESSAGEDURATION 0x2016
#define SPI_SETMESSAGEDURATION 0x2017
#define SPI_GETCONTACTVISUALIZATION 0x2018
#define SPI_SETCONTACTVISUALIZATION 0x2019
#define SPI_GETGESTUREVISUALIZATION 0x201a
#define SPI_SETGESTUREVISUALIZATION 0x201b

#define CONTACTVISUALIZATION_OFF 0x0000
#define CONTACTVISUALIZATION_ON 0x0001
#define CONTACTVISUALIZATION_PRESENTATIONMODE 0x0002

#define GESTUREVISUALIZATION_OFF 0x0000
#define GESTUREVISUALIZATION_ON 0x001f
#define GESTUREVISUALIZATION_TAP 0x0001
#define GESTUREVISUALIZATION_DOUBLETAP 0x0002
#define GESTUREVISUALIZATION_PRESSANDTAP 0x0004
#define GESTUREVISUALIZATION_PRESSANDHOLD 0x0008
#define GESTUREVISUALIZATION_RIGHTTAP 0x0010

#define MAX_TOUCH_PREDICTION_FILTER_TAPS 3

#define TOUCHPREDICTIONPARAMETERS_DEFAULT_LATENCY 8
#define TOUCHPREDICTIONPARAMETERS_DEFAULT_SAMPLETIME 8
#define TOUCHPREDICTIONPARAMETERS_DEFAULT_USE_HW_TIMESTAMP 1
#define TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_DELTA 0.001f
#define TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_LAMBDA_MIN 0.9f
#define TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_LAMBDA_MAX 0.999f
#define TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_LAMBDA_LEARNING_RATE 0.001f
#define TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_EXPO_SMOOTH_ALPHA 0.99f

#define MAX_LOGICALDPIOVERRIDE 2
#define MIN_LOGICALDPIOVERRIDE -2

#define FE_FONTSMOOTHINGORIENTATIONBGR 0x0000
#define FE_FONTSMOOTHINGORIENTATIONRGB 0x0001

#define SPIF_UPDATEINIFILE 0x0001
#define SPIF_SENDWININICHANGE 0x0002
#define SPIF_SENDCHANGE SPIF_SENDWININICHANGE

#define METRICS_USEDEFAULT -1

#define ARW_BOTTOMLEFT (int32_t)(0x0000)
#define ARW_BOTTOMRIGHT (int32_t)(0x0001)
#define ARW_TOPLEFT (int32_t)(0x0002)
#define ARW_TOPRIGHT (int32_t)(0x0003)
#define ARW_STARTMASK (int32_t)(0x0003)
#define ARW_STARTRIGHT (int32_t)(0x0001)
#define ARW_STARTTOP (int32_t)(0x0002)

#define ARW_LEFT (int32_t)(0x0000)
#define ARW_RIGHT (int32_t)(0x0000)
#define ARW_UP (int32_t)(0x0004)
#define ARW_DOWN (int32_t)(0x0004)
#define ARW_HIDE (int32_t)(0x0008)

#define SERKF_SERIALKEYSON 0x00000001
#define SERKF_AVAILABLE 0x00000002
#define SERKF_INDICATOR 0x00000004

#define HCF_HIGHCONTRASTON 0x00000001
#define HCF_AVAILABLE 0x00000002
#define HCF_HOTKEYACTIVE 0x00000004
#define HCF_CONFIRMHOTKEY 0x00000008
#define HCF_HOTKEYSOUND 0x00000010
#define HCF_INDICATOR 0x00000020
#define HCF_HOTKEYAVAILABLE 0x00000040
#define HCF_LOGONDESKTOP 0x00000100
#define HCF_DEFAULTDESKTOP 0x00000200

#define CDS_UPDATEREGISTRY 0x00000001
#define CDS_TEST 0x00000002
#define CDS_FULLSCREEN 0x00000004
#define CDS_GLOBAL 0x00000008
#define CDS_SET_PRIMARY 0x00000010
#define CDS_VIDEOPARAMETERS 0x00000020
#define CDS_ENABLE_UNSAFE_MODES 0x00000100
#define CDS_DISABLE_UNSAFE_MODES 0x00000200
#define CDS_RESET 0x40000000
#define CDS_RESET_EX 0x20000000
#define CDS_NORESET 0x10000000

#define VP_COMMAND_GET 0x0001
#define VP_COMMAND_SET 0x0002

#define VP_FLAGS_TV_MODE 0x0001
#define VP_FLAGS_TV_STANDARD 0x0002
#define VP_FLAGS_FLICKER 0x0004
#define VP_FLAGS_OVERSCAN 0x0008
#define VP_FLAGS_MAX_UNSCALED 0x0010
#define VP_FLAGS_POSITION 0x0020
#define VP_FLAGS_BRIGHTNESS 0x0040
#define VP_FLAGS_CONTRAST 0x0080
#define VP_FLAGS_COPYPROTECT 0x0100

#define VP_MODE_WIN_GRAPHICS 0x0001
#define VP_MODE_TV_PLAYBACK 0x0002

#define VP_TV_STANDARD_NTSC_M 0x0001
#define VP_TV_STANDARD_NTSC_M_J 0x0002
#define VP_TV_STANDARD_PAL_B 0x0004
#define VP_TV_STANDARD_PAL_D 0x0008
#define VP_TV_STANDARD_PAL_H 0x0010
#define VP_TV_STANDARD_PAL_I 0x0020
#define VP_TV_STANDARD_PAL_M 0x0040
#define VP_TV_STANDARD_PAL_N 0x0080
#define VP_TV_STANDARD_SECAM_B 0x0100
#define VP_TV_STANDARD_SECAM_D 0x0200
#define VP_TV_STANDARD_SECAM_G 0x0400
#define VP_TV_STANDARD_SECAM_H 0x0800
#define VP_TV_STANDARD_SECAM_K 0x1000
#define VP_TV_STANDARD_SECAM_K1 0x2000
#define VP_TV_STANDARD_SECAM_L 0x4000
#define VP_TV_STANDARD_WIN_VGA 0x8000
#define VP_TV_STANDARD_NTSC_433 0x00010000
#define VP_TV_STANDARD_PAL_G 0x00020000
#define VP_TV_STANDARD_PAL_60 0x00040000
#define VP_TV_STANDARD_SECAM_L1 0x00080000

#define VP_CP_TYPE_APS_TRIGGER 0x0001
#define VP_CP_TYPE_MACROVISION 0x0002
#define VP_CP_CMD_ACTIVATE 0x0001
#define VP_CP_CMD_DEACTIVATE 0x0002
#define VP_CP_CMD_CHANGE 0x0004

#define DISP_CHANGE_SUCCESSFUL 0
#define DISP_CHANGE_RESTART 1
#define DISP_CHANGE_FAILED -1
#define DISP_CHANGE_BADMODE -2
#define DISP_CHANGE_NOTUPDATED -3
#define DISP_CHANGE_BADFLAGS -4
#define DISP_CHANGE_BADPARAM -5
#define DISP_CHANGE_BADDUALVIEW -6

#define ENUM_CURRENT_SETTINGS ((DWORD)-1)
#define ENUM_REGISTRY_SETTINGS ((DWORD)-2)

#define EDS_RAWMODE 0x00000002

#define EDD_GET_DEVICE_INTERFACE_NAME 0x00000001

#define FKF_FILTERKEYSON 0x00000001
#define FKF_AVAILABLE 0x00000002
#define FKF_HOTKEYACTIVE 0x00000004
#define FKF_CONFIRMHOTKEY 0x00000008
#define FKF_HOTKEYSOUND 0x00000010
#define FKF_INDICATOR 0x00000020
#define FKF_CLICKON 0x00000040

#define SKF_STICKYKEYSON 0x00000001
#define SKF_AVAILABLE 0x00000002
#define SKF_HOTKEYACTIVE 0x00000004
#define SKF_CONFIRMHOTKEY 0x00000008
#define SKF_HOTKEYSOUND 0x00000010
#define SKF_INDICATOR 0x00000020
#define SKF_AUDIBLEFEEDBACK 0x00000040
#define SKF_TRISTATE 0x00000080
#define SKF_TWOKEYSOFF 0x00000100
#define SKF_LALTLATCHED 0x10000000
#define SKF_LCTLLATCHED 0x04000000
#define SKF_LSHIFTLATCHED 0x01000000
#define SKF_RALTLATCHED 0x20000000
#define SKF_RCTLLATCHED 0x08000000
#define SKF_RSHIFTLATCHED 0x02000000
#define SKF_LWINLATCHED 0x40000000
#define SKF_RWINLATCHED 0x80000000
#define SKF_LALTLOCKED 0x00100000
#define SKF_LCTLLOCKED 0x00040000
#define SKF_LSHIFTLOCKED 0x00010000
#define SKF_RALTLOCKED 0x00200000
#define SKF_RCTLLOCKED 0x00080000
#define SKF_RSHIFTLOCKED 0x00020000
#define SKF_LWINLOCKED 0x00400000
#define SKF_RWINLOCKED 0x00800000

#define MKF_MOUSEKEYSON 0x00000001
#define MKF_AVAILABLE 0x00000002
#define MKF_HOTKEYACTIVE 0x00000004
#define MKF_CONFIRMHOTKEY 0x00000008
#define MKF_HOTKEYSOUND 0x00000010
#define MKF_INDICATOR 0x00000020
#define MKF_MODIFIERS 0x00000040
#define MKF_REPLACENUMBERS 0x00000080
#define MKF_LEFTBUTTONSEL 0x10000000
#define MKF_RIGHTBUTTONSEL 0x20000000
#define MKF_LEFTBUTTONDOWN 0x01000000
#define MKF_RIGHTBUTTONDOWN 0x02000000
#define MKF_MOUSEMODE 0x80000000

#define ATF_TIMEOUTON 0x00000001
#define ATF_ONOFFFEEDBACK 0x00000002

#define SSGF_NONE 0
#define SSGF_DISPLAY 3

#define SSTF_NONE 0
#define SSTF_CHARS 1
#define SSTF_BORDER 2
#define SSTF_DISPLAY 3

#define SSWF_NONE 0
#define SSWF_TITLE 1
#define SSWF_WINDOW 2
#define SSWF_DISPLAY 3
#define SSWF_CUSTOM 4

#define SSF_SOUNDSENTRYON 0x00000001
#define SSF_AVAILABLE 0x00000002
#define SSF_INDICATOR 0x00000004

#define TKF_TOGGLEKEYSON 0x00000001
#define TKF_AVAILABLE 0x00000002
#define TKF_HOTKEYACTIVE 0x00000004
#define TKF_CONFIRMHOTKEY 0x00000008
#define TKF_HOTKEYSOUND 0x00000010
#define TKF_INDICATOR 0x00000020

#define SLE_ERROR 0x00000001
#define SLE_MINORERROR 0x00000002
#define SLE_WARNING 0x00000003

#define MONITOR_DEFAULTTONULL 0x00000000
#define MONITOR_DEFAULTTOPRIMARY 0x00000001
#define MONITOR_DEFAULTTONEAREST 0x00000002

#define MONITORINFOF_PRIMARY 0x00000001

#define WINEVENT_OUTOFCONTEXT 0x0000
#define WINEVENT_SKIPOWNTHREAD 0x0001
#define WINEVENT_SKIPOWNPROCESS 0x0002
#define WINEVENT_INCONTEXT 0x0004

#define CHILDID_SELF 0
#define INDEXID_OBJECT 0
#define INDEXID_CONTAINER 0

#define OBJID_WINDOW ((LONG)0x00000000)
#define OBJID_SYSMENU ((LONG)0xFFFFFFFF)
#define OBJID_TITLEBAR ((LONG)0xFFFFFFFE)
#define OBJID_MENU ((LONG)0xFFFFFFFD)
#define OBJID_CLIENT ((LONG)0xFFFFFFFC)
#define OBJID_VSCROLL ((LONG)0xFFFFFFFB)
#define OBJID_HSCROLL ((LONG)0xFFFFFFFA)
#define OBJID_SIZEGRIP ((LONG)0xFFFFFFF9)
#define OBJID_CARET ((LONG)0xFFFFFFF8)
#define OBJID_CURSOR ((LONG)0xFFFFFFF7)
#define OBJID_ALERT ((LONG)0xFFFFFFF6)
#define OBJID_SOUND ((LONG)0xFFFFFFF5)
#define OBJID_QUERYCLASSNAMEIDX ((LONG)0xFFFFFFF4)
#define OBJID_NATIVEOM ((LONG)0xFFFFFFF0)

#define EVENT_MIN 0x00000001
#define EVENT_MAX 0x7FFFFFFF

#define EVENT_SYSTEM_SOUND 0x0001
#define EVENT_SYSTEM_ALERT 0x0002
#define EVENT_SYSTEM_FOREGROUND 0x0003
#define EVENT_SYSTEM_MENUSTART 0x0004
#define EVENT_SYSTEM_MENUEND 0x0005
#define EVENT_SYSTEM_MENUPOPUPSTART 0x0006
#define EVENT_SYSTEM_MENUPOPUPEND 0x0007
#define EVENT_SYSTEM_CAPTURESTART 0x0008
#define EVENT_SYSTEM_CAPTUREEND 0x0009
#define EVENT_SYSTEM_MOVESIZESTART 0x000A
#define EVENT_SYSTEM_MOVESIZEEND 0x000B
#define EVENT_SYSTEM_CONTEXTHELPSTART 0x000C
#define EVENT_SYSTEM_CONTEXTHELPEND 0x000D
#define EVENT_SYSTEM_DRAGDROPSTART 0x000E
#define EVENT_SYSTEM_DRAGDROPEND 0x000F
#define EVENT_SYSTEM_DIALOGSTART 0x0010
#define EVENT_SYSTEM_DIALOGEND 0x0011
#define EVENT_SYSTEM_SCROLLINGSTART 0x0012
#define EVENT_SYSTEM_SCROLLINGEND 0x0013
#define EVENT_SYSTEM_SWITCHSTART 0x0014
#define EVENT_SYSTEM_SWITCHEND 0x0015
#define EVENT_SYSTEM_MINIMIZESTART 0x0016
#define EVENT_SYSTEM_MINIMIZEEND 0x0017
#define EVENT_SYSTEM_DESKTOPSWITCH 0x0020
#define EVENT_SYSTEM_SWITCHER_APPGRABBED 0x0024
#define EVENT_SYSTEM_SWITCHER_APPOVERTARGET 0x0025
#define EVENT_SYSTEM_SWITCHER_APPDROPPED 0x0026
#define EVENT_SYSTEM_SWITCHER_CANCELLED 0x0027
#define EVENT_SYSTEM_IME_KEY_NOTIFICATION 0x0029
#define EVENT_SYSTEM_END 0x00ff
#define EVENT_OEM_DEFINED_START 0x0101
#define EVENT_OEM_DEFINED_END 0x01ff
#define EVENT_UIA_EVENTID_START 0x4e00
#define EVENT_UIA_EVENTID_END 0x4eff
#define EVENT_UIA_PROPID_START 0x7500
#define EVENT_UIA_PROPID_END 0x75ff

#define EVENT_CONSOLE_CARET 0x4001
#define EVENT_CONSOLE_UPDATE_REGION 0x4002
#define EVENT_CONSOLE_UPDATE_SIMPLE 0x4003
#define EVENT_CONSOLE_UPDATE_SCROLL 0x4004
#define EVENT_CONSOLE_LAYOUT 0x4005
#define EVENT_CONSOLE_START_APPLICATION 0x4006
#define EVENT_CONSOLE_END_APPLICATION 0x4007

#ifdef __NT64
#define CONSOLE_APPLICATION_16BIT 0x0000
#else
#define CONSOLE_APPLICATION_16BIT 0x0001
#endif
#define CONSOLE_CARET_SELECTION 0x0001
#define CONSOLE_CARET_VISIBLE 0x0002
#define EVENT_CONSOLE_END 0x40ff

#define EVENT_OBJECT_CREATE 0x8000
#define EVENT_OBJECT_DESTROY 0x8001
#define EVENT_OBJECT_SHOW 0x8002
#define EVENT_OBJECT_HIDE 0x8003
#define EVENT_OBJECT_REORDER 0x8004
#define EVENT_OBJECT_FOCUS 0x8005
#define EVENT_OBJECT_SELECTION 0x8006
#define EVENT_OBJECT_SELECTIONADD 0x8007
#define EVENT_OBJECT_SELECTIONREMOVE 0x8008
#define EVENT_OBJECT_SELECTIONWITHIN 0x8009
#define EVENT_OBJECT_STATECHANGE 0x800A
#define EVENT_OBJECT_LOCATIONCHANGE 0x800B
#define EVENT_OBJECT_NAMECHANGE 0x800C
#define EVENT_OBJECT_DESCRIPTIONCHANGE 0x800D
#define EVENT_OBJECT_VALUECHANGE 0x800E
#define EVENT_OBJECT_PARENTCHANGE 0x800F
#define EVENT_OBJECT_HELPCHANGE 0x8010
#define EVENT_OBJECT_DEFACTIONCHANGE 0x8011
#define EVENT_OBJECT_ACCELERATORCHANGE 0x8012
#define EVENT_OBJECT_INVOKED 0x8013
#define EVENT_OBJECT_TEXTSELECTIONCHANGED 0x8014
#define EVENT_OBJECT_CONTENTSCROLLED 0x8015
#define EVENT_SYSTEM_ARRANGMENTPREVIEW 0x8016
#define EVENT_OBJECT_CLOAKED 0x8017
#define EVENT_OBJECT_UNCLOAKED 0x8018
#define EVENT_OBJECT_LIVEREGIONCHANGED 0x8019
#define EVENT_OBJECT_HOSTEDOBJECTSINVALIDATED 0x8020
#define EVENT_OBJECT_DRAGSTART 0x8021
#define EVENT_OBJECT_DRAGCANCEL 0x8022
#define EVENT_OBJECT_DRAGCOMPLETE 0x8023
#define EVENT_OBJECT_DRAGENTER 0x8024
#define EVENT_OBJECT_DRAGLEAVE 0x8025
#define EVENT_OBJECT_DRAGDROPPED 0x8026
#define EVENT_OBJECT_IME_SHOW 0x8027
#define EVENT_OBJECT_IME_HIDE 0x8028
#define EVENT_OBJECT_IME_CHANGE 0x8029
#define EVENT_OBJECT_END 0x80ff

#define EVENT_AIA_START 0xa000
#define EVENT_AIA_END 0xafff

#define SOUND_SYSTEM_STARTUP 1
#define SOUND_SYSTEM_SHUTDOWN 2
#define SOUND_SYSTEM_BEEP 3
#define SOUND_SYSTEM_ERROR 4
#define SOUND_SYSTEM_QUESTION 5
#define SOUND_SYSTEM_WARNING 6
#define SOUND_SYSTEM_INFORMATION 7
#define SOUND_SYSTEM_MAXIMIZE 8
#define SOUND_SYSTEM_MINIMIZE 9
#define SOUND_SYSTEM_RESTOREUP 10
#define SOUND_SYSTEM_RESTOREDOWN 11
#define SOUND_SYSTEM_APPSTART 12
#define SOUND_SYSTEM_FAULT 13
#define SOUND_SYSTEM_APPEND 14
#define SOUND_SYSTEM_MENUCOMMAND 15
#define SOUND_SYSTEM_MENUPOPUP 16
#define CSOUND_SYSTEM 16

#define ALERT_SYSTEM_INFORMATIONAL 1
#define ALERT_SYSTEM_WARNING 2
#define ALERT_SYSTEM_ERROR 3
#define ALERT_SYSTEM_QUERY 4
#define ALERT_SYSTEM_CRITICAL 5
#define CALERT_SYSTEM 6

#define GUI_CARETBLINKING 0x00000001
#define GUI_INMOVESIZE 0x00000002
#define GUI_INMENUMODE 0x00000004
#define GUI_SYSTEMMENUMODE 0x00000008
#define GUI_POPUPMENUMODE 0x00000010
#ifdef __NT64
#define GUI_16BITTASK 0x00000000
#else
#define GUI_16BITTASK 0x00000020
#endif

#define USER_DEFAULT_SCREEN_DPI 96

#define STATE_SYSTEM_UNAVAILABLE 0x00000001
#define STATE_SYSTEM_SELECTED 0x00000002
#define STATE_SYSTEM_FOCUSED 0x00000004
#define STATE_SYSTEM_PRESSED 0x00000008
#define STATE_SYSTEM_CHECKED 0x00000010
#define STATE_SYSTEM_MIXED 0x00000020
#define STATE_SYSTEM_INDETERMINATE STATE_SYSTEM_MIXED
#define STATE_SYSTEM_READONLY 0x00000040
#define STATE_SYSTEM_HOTTRACKED 0x00000080
#define STATE_SYSTEM_DEFAULT 0x00000100
#define STATE_SYSTEM_EXPANDED 0x00000200
#define STATE_SYSTEM_COLLAPSED 0x00000400
#define STATE_SYSTEM_BUSY 0x00000800
#define STATE_SYSTEM_FLOATING 0x00001000
#define STATE_SYSTEM_MARQUEED 0x00002000
#define STATE_SYSTEM_ANIMATED 0x00004000
#define STATE_SYSTEM_INVISIBLE 0x00008000
#define STATE_SYSTEM_OFFSCREEN 0x00010000
#define STATE_SYSTEM_SIZEABLE 0x00020000
#define STATE_SYSTEM_MOVEABLE 0x00040000
#define STATE_SYSTEM_SELFVOICING 0x00080000
#define STATE_SYSTEM_FOCUSABLE 0x00100000
#define STATE_SYSTEM_SELECTABLE 0x00200000
#define STATE_SYSTEM_LINKED 0x00400000
#define STATE_SYSTEM_TRAVERSED 0x00800000
#define STATE_SYSTEM_MULTISELECTABLE 0x01000000
#define STATE_SYSTEM_EXTSELECTABLE 0x02000000
#define STATE_SYSTEM_ALERT_LOW 0x04000000
#define STATE_SYSTEM_ALERT_MEDIUM 0x08000000
#define STATE_SYSTEM_ALERT_HIGH 0x10000000
#define STATE_SYSTEM_PROTECTED 0x20000000
#define STATE_SYSTEM_VALID 0x3FFFFFFF

#define CCHILDREN_TITLEBAR 5
#define CCHILDREN_SCROLLBAR 5

#define CURSOR_SHOWING 0x00000001
#define CURSOR_SUPPRESSED 0x00000002

#define WS_ACTIVECAPTION 0x0001

#define GA_PARENT 1
#define GA_ROOT 2
#define GA_ROOTOWNER 3

#define GET_RAWINPUT_CODE_WPARAM(wParam) ((wParam) & 0xff)

#define RIM_INPUT 0
#define RIM_INPUTSINK 1

#define RIM_TYPEMOUSE 0
#define RIM_TYPEKEYBOARD 1
#define RIM_TYPEHID 2

#define RI_MOUSE_LEFT_BUTTON_DOWN 0x0001
#define RI_MOUSE_LEFT_BUTTON_UP 0x0002
#define RI_MOUSE_RIGHT_BUTTON_DOWN 0x0004
#define RI_MOUSE_RIGHT_BUTTON_UP 0x0008
#define RI_MOUSE_MIDDLE_BUTTON_DOWN 0x0010
#define RI_MOUSE_MIDDLE_BUTTON_UP 0x0020
#define RI_MOUSE_BUTTON_4_DOWN 0x0040
#define RI_MOUSE_BUTTON_4_UP 0x0080
#define RI_MOUSE_BUTTON_5_DOWN 0x0100
#define RI_MOUSE_BUTTON_5_UP 0x0200
#define RI_MOUSE_WHEEL 0x0400

#define RI_MOUSE_BUTTON_1_DOWN RI_MOUSE_LEFT_BUTTON_DOWN
#define RI_MOUSE_BUTTON_1_UP RI_MOUSE_LEFT_BUTTON_UP
#define RI_MOUSE_BUTTON_2_DOWN RI_MOUSE_RIGHT_BUTTON_DOWN
#define RI_MOUSE_BUTTON_2_UP RI_MOUSE_RIGHT_BUTTON_UP
#define RI_MOUSE_BUTTON_3_DOWN RI_MOUSE_MIDDLE_BUTTON_DOWN
#define RI_MOUSE_BUTTON_3_UP RI_MOUSE_MIDDLE_BUTTON_UP

#define MOUSE_MOVE_RELATIVE 0
#define MOUSE_MOVE_ABSOLUTE 1
#define MOUSE_VIRTUAL_DESKTOP 0x02
#define MOUSE_ATTRIBUTES_CHANGED 0x04
#define MOUSE_MOVE_NOCOALESCE 0x08

#define KEYBOARD_OVERRUN_MAKE_CODE 0xFF

#define RI_KEY_MAKE 0
#define RI_KEY_BREAK 1
#define RI_KEY_E0 2
#define RI_KEY_E1 4
#define RI_KEY_TERMSRV_SET_LED 8
#define RI_KEY_TERMSRV_SHADOW 0x10

#ifdef __NT64
#define RAWINPUT_ALIGN(x) (((x) + sizeof(QWORD) - 1) & ~(sizeof(QWORD) - 1))
#else
#define RAWINPUT_ALIGN(x) (((x) + sizeof(DWORD) - 1) & ~(sizeof(DWORD) - 1))
#endif

#define NEXTRAWINPUTBLOCK(ptr) ((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->header.dwSize)))

#define RID_INPUT 0x10000003
#define RID_HEADER 0x10000005

#define RIDI_PREPARSEDDATA 0x20000005
#define RIDI_DEVICENAME 0x20000007
#define RIDI_DEVICEINFO 0x2000000b

#define RIDEV_REMOVE 0x00000001
#define RIDEV_EXCLUDE 0x00000010
#define RIDEV_PAGEONLY 0x00000020
#define RIDEV_NOLEGACY 0x00000030
#define RIDEV_INPUTSINK 0x00000100
#define RIDEV_CAPTUREMOUSE 0x00000200
#define RIDEV_NOHOTKEYS 0x00000200
#define RIDEV_APPKEYS 0x00000400
#define RIDEV_EXINPUTSINK 0x00001000
#define RIDEV_DEVNOTIFY 0x00002000

#define RIDEV_EXMODEMASK 0x000000F0
#define RIDEV_EXMODE(mode) ((mode) & RIDEV_EXMODEMASK)

#define GIDC_ARRIVAL 1
#define GIDC_REMOVAL 2

#if _WIN32_WINNT >= 0x0601
#define GET_DEVICE_CHANGE_WPARAM(wParam) (LOWORD (wParam))
#else
#define GET_DEVICE_CHANGE_LPARAM(lParam) (LOWORD (lParam))
#endif

#define POINTER_DEVICE_PRODUCT_STRING_MAX 520
#define PDC_ARRIVAL 0x001
#define PDC_REMOVAL 0x002
#define PDC_ORIENTATION_0 0x004
#define PDC_ORIENTATION_90 0x008
#define PDC_ORIENTATION_180 0x010
#define PDC_ORIENTATION_270 0x020
#define PDC_MODE_DEFAULT 0x040
#define PDC_MODE_CENTERED 0x080
#define PDC_MAPPING_CHANGE 0x100
#define PDC_RESOLUTION 0x200
#define PDC_ORIGIN 0x400
#define PDC_MODE_ASPECTRATIOPRESERVED 0x800

#define MSGFLT_ADD 1
#define MSGFLT_REMOVE 2

#define MSGFLTINFO_NONE (0)
#define MSGFLTINFO_ALREADYALLOWED_FORWND (1)
#define MSGFLTINFO_ALREADYDISALLOWED_FORWND (2)
#define MSGFLTINFO_ALLOWED_HIGHER (3)

#define MSGFLT_RESET (0)
#define MSGFLT_ALLOW (1)
#define MSGFLT_DISALLOW (2)

#define GF_BEGIN 0x00000001
#define GF_INERTIA 0x00000002
#define GF_END 0x00000004

#define GID_BEGIN 1
#define GID_END 2
#define GID_ZOOM 3
#define GID_PAN 4
#define GID_ROTATE 5
#define GID_TWOFINGERTAP 6
#define GID_PRESSANDTAP 7
#define GID_ROLLOVER GID_PRESSANDTAP

#define GID_ROTATE_ANGLE_TO_ARGUMENT(_arg_) ((USHORT) ((((_arg_) + 2.0 *3.14159265) / (4.0 *3.14159265)) *65535.0))
#define GID_ROTATE_ANGLE_FROM_ARGUMENT(_arg_) ((((double) (_arg_) / 65535.0) *4.0 *3.14159265) - 2.0 *3.14159265)

#define GC_ALLGESTURES 0x00000001
#define GC_ZOOM 0x00000001

#define GC_PAN 0x00000001
#define GC_PAN_WITH_SINGLE_FINGER_VERTICALLY 0x00000002
#define GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY 0x00000004
#define GC_PAN_WITH_GUTTER 0x00000008
#define GC_PAN_WITH_INERTIA 0x00000010

#define GC_ROTATE 0x00000001
#define GC_TWOFINGERTAP 0x00000001
#define GC_PRESSANDTAP 0x00000001
#define GC_ROLLOVER GC_PRESSANDTAP

#define GESTURECONFIGMAXCOUNT 256

#define GCF_INCLUDE_ANCESTORS 0x00000001

#define NID_INTEGRATED_TOUCH 0x00000001
#define NID_EXTERNAL_TOUCH 0x00000002
#define NID_INTEGRATED_PEN 0x00000004
#define NID_EXTERNAL_PEN 0x00000008
#define NID_MULTI_INPUT 0x00000040
#define NID_READY 0x00000080

#define MAX_STR_BLOCKREASON 256

#if 0
/* missing bits. */
DEFINE_ENUM_FLAG_OPERATORS (AR_STATE);
DEFINE_ENUM_FLAG_OPERATORS (ORIENTATION_PREFERENCE);
#endif

#ifdef __cplusplus
}
#endif
#endif /* _W32API_WINUSER_H_ */
