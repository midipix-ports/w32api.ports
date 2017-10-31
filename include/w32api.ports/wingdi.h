#ifndef _W32API_WINGDI_H_
#define _W32API_WINGDI_H_

#include <windef.h>

typedef int ENHMFENUMPROC;
typedef int FONTENUMPROCA;
typedef int ICMENUMPROCA;
typedef int ICMENUMPROCW;
typedef int MFENUMPROC;
typedef int GOBJENUMPROC;
typedef int LINEDDAPROC;
typedef int ABORTPROC;


typedef USHORT	COLOR16;
typedef LONG	FXPT16DOT16;
typedef LONG	FXPT2DOT30;
typedef LONG	LCSCSTYPE;
typedef LONG	LCSGAMUTMATCH;

#define RGB(r,g,b) ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))

#define LOBYTE(w) ((BYTE) (((DWORD_PTR) (w)) & 0xff)) //wrong place
#define GetRValue(rgb) (LOBYTE(rgb))
#define GetGValue(rgb) (LOBYTE(((WORD)(rgb)) >> 8))
#define GetBValue(rgb) (LOBYTE((rgb)>>16))

enum gdi_displayconfig_device_info_type {
	GDI_DISPLAYCONFIG_DEVICE_INFO_GET_SOURCE_NAME		= 1,
	GDI_DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME		= 2,
	GDI_DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_PREFERRED_MODE	= 3,
	GDI_DISPLAYCONFIG_DEVICE_INFO_GET_ADAPTER_NAME		= 4,
	GDI_DISPLAYCONFIG_DEVICE_INFO_SET_TARGET_PERSISTENCE	= 5
};

enum gdi_displayconfig_mode_info_type {
	GDI_DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE	= 1,
	GDI_DISPLAYCONFIG_MODE_INFO_TYPE_TARGET	= 2
};

enum gdi_displayconfig_pixelformat {
	GDI_DISPLAYCONFIG_PIXELFORMAT_8BPP	= 1,
	GDI_DISPLAYCONFIG_PIXELFORMAT_16BPP	= 2,
	GDI_DISPLAYCONFIG_PIXELFORMAT_24BPP	= 3,
	GDI_DISPLAYCONFIG_PIXELFORMAT_32BPP	= 4,
	GDI_DISPLAYCONFIG_PIXELFORMAT_NONGDI	= 5
};

enum gdi_displayconfig_rotation {
	GDI_DISPLAYCONFIG_ROTATION_IDENTITY	= 1,
	GDI_DISPLAYCONFIG_ROTATION_ROTATE90	= 2,
	GDI_DISPLAYCONFIG_ROTATION_ROTATE180	= 3,
	GDI_DISPLAYCONFIG_ROTATION_ROTATE270	= 4
};

enum gdi_displayconfig_scaling {
	GDI_DISPLAYCONFIG_SCALING_IDENTITY			= 1,
	GDI_DISPLAYCONFIG_SCALING_CENTERED			= 2,
	GDI_DISPLAYCONFIG_SCALING_STRETCHED			= 3,
	GDI_DISPLAYCONFIG_SCALING_ASPECTRATIOCENTEREDMAX	= 4,
	GDI_DISPLAYCONFIG_SCALING_CUSTOM			= 5,
	GDI_DISPLAYCONFIG_SCALING_PREFERRED			= 128
};

enum gdi_displayconfig_scanline_ordering {
	GDI_DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED			= 0,
	GDI_DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE			= 1,
	GDI_DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED			= 2,
	GDI_DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST	= 2,
	GDI_DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST	= 3
};

enum gdi_displayconfig_topology_id {
	GDI_DISPLAYCONFIG_TOPOLOGY_INTERNAL	= 1,
	GDI_DISPLAYCONFIG_TOPOLOGY_CLONE	= 2,
	GDI_DISPLAYCONFIG_TOPOLOGY_EXTEND	= 4,
	GDI_DISPLAYCONFIG_TOPOLOGY_EXTERNAL	= 8
};

enum gdi_displayconfig_video_output_technology {
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_OTHER			= (-1),
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HD15			= 0,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SVIDEO			= 1,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPOSITE_VIDEO		= 2,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPONENT_VIDEO		= 3,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DVI				= 4,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HDMI			= 5,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_LVDS			= 6,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_D_JPN			= 8,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDI				= 9,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EXTERNAL	= 10,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EMBEDDED	= 11,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EXTERNAL		= 12,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EMBEDDED		= 13,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDTVDONGLE			= 14,
	GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INTERNAL			= 0x80000000
};




typedef enum gdi_displayconfig_device_info_type		DISPLAYCONFIG_DEVICE_INFO_TYPE;
typedef enum gdi_displayconfig_mode_info_type		DISPLAYCONFIG_MODE_INFO_TYPE;
typedef enum gdi_displayconfig_pixelformat		DISPLAYCONFIG_PIXELFORMAT;
typedef enum gdi_displayconfig_rotation			DISPLAYCONFIG_ROTATION;
typedef enum gdi_displayconfig_scaling			DISPLAYCONFIG_SCALING;
typedef enum gdi_displayconfig_scanline_ordering	DISPLAYCONFIG_SCANLINE_ORDERING;
typedef enum gdi_displayconfig_topology_id		DISPLAYCONFIG_TOPOLOGY_ID;
typedef enum gdi_displayconfig_video_output_technology	DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY;




#define DISPLAYCONFIG_DEVICE_INFO_GET_SOURCE_NAME			GDI_DISPLAYCONFIG_DEVICE_INFO_GET_SOURCE_NAME
#define DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME			GDI_DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME
#define DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_PREFERRED_MODE		GDI_DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_PREFERRED_MODE
#define DISPLAYCONFIG_DEVICE_INFO_GET_ADAPTER_NAME			GDI_DISPLAYCONFIG_DEVICE_INFO_GET_ADAPTER_NAME
#define DISPLAYCONFIG_DEVICE_INFO_SET_TARGET_PERSISTENCE		GDI_DISPLAYCONFIG_DEVICE_INFO_SET_TARGET_PERSISTENCE

#define DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE				GDI_DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE
#define DISPLAYCONFIG_MODE_INFO_TYPE_TARGET				GDI_DISPLAYCONFIG_MODE_INFO_TYPE_TARGET

#define DISPLAYCONFIG_PIXELFORMAT_8BPP					GDI_DISPLAYCONFIG_PIXELFORMAT_8BPP
#define DISPLAYCONFIG_PIXELFORMAT_16BPP					GDI_DISPLAYCONFIG_PIXELFORMAT_16BPP
#define DISPLAYCONFIG_PIXELFORMAT_24BPP					GDI_DISPLAYCONFIG_PIXELFORMAT_24BPP
#define DISPLAYCONFIG_PIXELFORMAT_32BPP					GDI_DISPLAYCONFIG_PIXELFORMAT_32BPP
#define DISPLAYCONFIG_PIXELFORMAT_NONGDI				GDI_DISPLAYCONFIG_PIXELFORMAT_NONGDI

#define DISPLAYCONFIG_ROTATION_IDENTITY					GDI_DISPLAYCONFIG_ROTATION_IDENTITY
#define DISPLAYCONFIG_ROTATION_ROTATE90					GDI_DISPLAYCONFIG_ROTATION_ROTATE90
#define DISPLAYCONFIG_ROTATION_ROTATE180				GDI_DISPLAYCONFIG_ROTATION_ROTATE180
#define DISPLAYCONFIG_ROTATION_ROTATE270				GDI_DISPLAYCONFIG_ROTATION_ROTATE270

#define DISPLAYCONFIG_SCALING_IDENTITY					GDI_DISPLAYCONFIG_SCALING_IDENTITY
#define DISPLAYCONFIG_SCALING_CENTERED					GDI_DISPLAYCONFIG_SCALING_CENTERED
#define DISPLAYCONFIG_SCALING_STRETCHED					GDI_DISPLAYCONFIG_SCALING_STRETCHED
#define DISPLAYCONFIG_SCALING_ASPECTRATIOCENTEREDMAX			GDI_DISPLAYCONFIG_SCALING_ASPECTRATIOCENTEREDMAX
#define DISPLAYCONFIG_SCALING_CUSTOM					GDI_DISPLAYCONFIG_SCALING_CUSTOM
#define DISPLAYCONFIG_SCALING_PREFERRED					GDI_DISPLAYCONFIG_SCALING_PREFERRED

#define DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED			GDI_DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED
#define DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE			GDI_DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE
#define DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED			GDI_DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED
#define DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST	GDI_DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST
#define DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST	GDI_DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST

#define DISPLAYCONFIG_TOPOLOGY_INTERNAL					GDI_DISPLAYCONFIG_TOPOLOGY_INTERNAL
#define DISPLAYCONFIG_TOPOLOGY_CLONE					GDI_DISPLAYCONFIG_TOPOLOGY_CLONE
#define DISPLAYCONFIG_TOPOLOGY_EXTEND					GDI_DISPLAYCONFIG_TOPOLOGY_EXTEND
#define DISPLAYCONFIG_TOPOLOGY_EXTERNAL					GDI_DISPLAYCONFIG_TOPOLOGY_EXTERNAL

#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_OTHER				GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_OTHER
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HD15				GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HD15
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SVIDEO				GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SVIDEO
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPOSITE_VIDEO			GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPOSITE_VIDEO
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPONENT_VIDEO			GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPONENT_VIDEO
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DVI				GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DVI
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HDMI				GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HDMI
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_LVDS				GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_LVDS
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_D_JPN				GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_D_JPN
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDI				GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDI
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EXTERNAL		GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EXTERNAL
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EMBEDDED		GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EMBEDDED
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EXTERNAL			GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EXTERNAL
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EMBEDDED			GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EMBEDDED
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDTVDONGLE			GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDTVDONGLE
#define DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INTERNAL			GDI_DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INTERNAL




union  gdi_aa_ansi;
union  gdi_aa_utf8;
union  gdi_aa_utf16;
struct gdi_abc;
struct gdi_abc_float;
struct gdi_abort_path;
struct gdi_axes_list_ansi;
struct gdi_axes_list_utf8;
struct gdi_axes_list_utf16;
struct gdi_axis_info_ansi;
struct gdi_axis_info_utf8;
struct gdi_axis_info_utf16;
struct gdi_bitmap;
struct gdi_bitmap_core_header;
struct gdi_bitmap_core_info;
struct gdi_bitmap_file_header;
struct gdi_bitmap_info;
struct gdi_bitmap_info_header;
struct gdi_bitmap_v4_header;
struct gdi_bitmap_v5_header;
struct gdi_blend_function;
struct gdi_charset_info;
struct gdi_ciexyz;
struct gdi_color_adjustment;
struct gdi_color_correct_palette;
struct gdi_color_match_to_target;
struct gdi_design_vector;
struct gdi_device_mode_ansi;
struct gdi_device_mode_utf8;
struct gdi_device_mode_utf16;
struct gdi_dib_section;
struct gdi_display_device_ansi;
struct gdi_display_device_utf8;
struct gdi_display_device_utf16;
struct gdi_displayconfig_2d_region;
struct gdi_displayconfig_adapter_name;
struct gdi_displayconfig_device_info_header;
struct gdi_displayconfig_mode_info;
struct gdi_displayconfig_path_info;
struct gdi_displayconfig_path_source_info;
struct gdi_displayconfig_path_target_info;
struct gdi_displayconfig_rational;
struct gdi_displayconfig_set_target_persistence;
struct gdi_displayconfig_source_device_name;
struct gdi_displayconfig_source_mode;
struct gdi_displayconfig_target_device_name;
struct gdi_displayconfig_target_device_name_flags;
struct gdi_displayconfig_target_mode;
struct gdi_displayconfig_target_preferred_mode;
struct gdi_displayconfig_video_signal_info;
struct gdi_doc_info_ansi;
struct gdi_doc_info_utf8;
struct gdi_doc_info_utf16;
struct gdi_draw_pat_rect;
struct gdi_emr;
struct gdi_emr_alpha_blend;
struct gdi_emr_angle_arc;
struct gdi_emr_arc;
struct gdi_emr_bit_blt;
struct gdi_emr_create_brush_indirect;
struct gdi_emr_create_color_space;
struct gdi_emr_create_color_space_utf16;
struct gdi_emr_create_dib_pattern_brush_pt;
struct gdi_emr_create_mono_brush;
struct gdi_emr_create_palette;
struct gdi_emr_create_pen;
struct gdi_emr_ellipse;
struct gdi_emr_eof;
struct gdi_emr_exclude_clip_rect;
struct gdi_emr_ext_create_font_indirect_utf16;
struct gdi_emr_ext_createpen;
struct gdi_emr_ext_escape;
struct gdi_emr_ext_flood_fill;
struct gdi_emr_ext_select_clip_rgn;
struct gdi_emr_ext_text_out_ansi;
struct gdi_emr_ext_text_out_utf8;
struct gdi_emr_fill_path;
struct gdi_emr_fill_rgn;
struct gdi_emr_format;
struct gdi_emr_frame_rgn;
struct gdi_emr_gdi_comment;
struct gdi_emr_gls_bounded_record;
struct gdi_emr_gls_record;
struct gdi_emr_gradient_fill;
struct gdi_emr_invert_rgn;
struct gdi_emr_line_to;
struct gdi_emr_mask_blt;
struct gdi_emr_modify_world_transform;
struct gdi_emr_named_escape;
struct gdi_emr_offset_clip_rgn;
struct gdi_emr_pixel_format;
struct gdi_emr_plg_blt;
struct gdi_emr_poly_draw;
struct gdi_emr_poly_draw_16;
struct gdi_emr_poly_line;
struct gdi_emr_poly_line_16;
struct gdi_emr_poly_poly_line;
struct gdi_emr_poly_poly_line_16;
struct gdi_emr_poly_text_out_ansi;
struct gdi_emr_poly_text_out_utf8;
struct gdi_emr_resize_palette;
struct gdi_emr_restore_dc;
struct gdi_emr_round_rect;
struct gdi_emr_scale_viewport_ext_ex;
struct gdi_emr_select_clip_path;
struct gdi_emr_select_object;
struct gdi_emr_select_palette;
struct gdi_emr_set_arc_direction;
struct gdi_emr_set_color_adjustment;
struct gdi_emr_set_color_space;
struct gdi_emr_set_di_bits_to_device;
struct gdi_emr_set_icm_profile;
struct gdi_emr_set_mapper_flags;
struct gdi_emr_set_miter_limit;
struct gdi_emr_set_palette_entries;
struct gdi_emr_set_pixel_v;
struct gdi_emr_set_text_color;
struct gdi_emr_set_viewport_ext_ex;
struct gdi_emr_set_viewport_org_ex;
struct gdi_emr_set_world_transform;
struct gdi_emr_stretch_blt;
struct gdi_emr_stretch_di_bits;
struct gdi_emr_text;
struct gdi_emr_transparent_blt;
struct gdi_enh_meta_header;
struct gdi_enh_meta_record;
struct gdi_enum_log_font_ansi;
struct gdi_enum_log_font_utf8;
struct gdi_enum_log_font_ex_ansi;
struct gdi_enum_log_font_ex_utf8;
struct gdi_enum_log_font_ex_dv_ansi;
struct gdi_enum_log_font_ex_dv_utf8;
struct gdi_enum_log_font_ex_dv_utf16;
struct gdi_enum_log_font_ex_utf16;
struct gdi_enum_log_font_utf16;
struct gdi_enum_text_metric_ansi;
struct gdi_enum_text_metric_utf8;
struct gdi_enum_text_metric_utf16;
struct gdi_ext_log_font_ansi;
struct gdi_ext_log_font_utf8;
struct gdi_ext_log_font_utf16;
struct gdi_ext_log_pen;
struct gdi_ext_log_pen_32;
struct gdi_fixed;
struct gdi_font_signature;
struct gdi_gcp_results_ansi;
struct gdi_gcp_results_utf8;
struct gdi_gcp_results_utf16;
struct gdi_glyph_metrics;
struct gdi_glyph_metrics_float;
struct gdi_glyph_set;
struct gdi_gradient_rect;
struct gdi_gradient_triangle;
struct gdi_handle_table;
struct gdi_ice_xyz_triple;
struct gdi_kerning_pair;
struct gdi_layer_plane_descriptor;
struct gdi_locale_signature;
struct gdi_log_brush;
struct gdi_log_brush_32;
struct gdi_log_color_space_ansi;
struct gdi_log_color_space_utf8;
struct gdi_log_color_space_utf16;
struct gdi_log_font_ansi;
struct gdi_log_font_utf8;
struct gdi_log_font_utf16;
struct gdi_log_palette;
struct gdi_log_pen;
struct gdi_mat_2;
struct gdi_meta_file_pict;
struct gdi_meta_header;
struct gdi_meta_record;
struct gdi_new_text_metric_ansi;
struct gdi_new_text_metric_utf8;
struct gdi_new_text_metric_ex_ansi;
struct gdi_new_text_metric_ex_utf8;
struct gdi_new_text_metric_ex_utf16;
struct gdi_new_text_metric_utf16;
struct gdi_outline_text_metric_ansi;
struct gdi_outline_text_metric_utf8;
struct gdi_outline_text_metric_utf16;
struct gdi_palette_entry;
struct gdi_panose;
struct gdi_pel_array;
struct gdi_pixel_format_descriptor;
struct gdi_point_float;
struct gdi_point_fx;
struct gdi_poly_text_ansi;
struct gdi_poly_text_utf8;
struct gdi_poly_text_utf16;
struct gdi_ps_feature_cust_paper;
struct gdi_ps_feature_output;
struct gdi_ps_inject_dat_ansi;
struct gdi_ps_inject_dat_utf8;
struct gdi_rasterizer_status;
struct gdi_rgb_quad;
struct gdi_rgb_triple;
struct gdi_rgn_dat_ansi;
struct gdi_rgn_dat_utf8;
struct gdi_rgn_data_header;
struct gdi_text_metric_ansi;
struct gdi_text_metric_utf8;
struct gdi_text_metric_utf16;
struct gdi_trivertex;
struct gdi_tt_poly_curve;
struct gdi_tt_polygon_header;
struct gdi_wcrange;
struct gdi_wgl_swap;
struct gdi_xform;



typedef union  gdi_aa_ansi					__AAA;
typedef union  gdi_aa_utf8					__AAM;
typedef union  gdi_aa_utf16					__AAW;
typedef struct gdi_abc						ABC, *PABC, *NPABC, *LPABC;
typedef struct gdi_abc_float					ABCFLOAT, *PABCFLOAT, *NPABCFLOAT, *LPABCFLOAT;
typedef struct gdi_abort_path					EMRABORTPATH, *PEMRABORTPATH;
typedef struct gdi_abort_path					EMRBEGINPATH, *PEMRBEGINPATH;
typedef struct gdi_abort_path					EMRENDPATH, *PEMRENDPATH;
typedef struct gdi_abort_path					EMRCLOSEFIGURE, *PEMRCLOSEFIGURE;
typedef struct gdi_abort_path					EMRFLATTENPATH, *PEMRFLATTENPATH;
typedef struct gdi_abort_path					EMRWIDENPATH, *PEMRWIDENPATH;
typedef struct gdi_abort_path					EMRSETMETARGN, *PEMRSETMETARGN;
typedef struct gdi_abort_path					EMRSAVEDC, *PEMRSAVEDC;
typedef struct gdi_abort_path					EMRREALIZEPALETTE, *PEMRREALIZEPALETTE;
typedef struct gdi_axes_list_ansi				AXESLISTA, *PAXESLISTA, *LPAXESLISTA;
typedef struct gdi_axes_list_utf8				AXESLISTM, *PAXESLISTM, *LPAXESLISTM;
typedef struct gdi_axes_list_utf16				AXESLISTW, *PAXESLISTW, *LPAXESLISTW;
typedef struct gdi_axis_info_ansi				AXISINFOA, *PAXISINFOA, *LPAXISINFOA;
typedef struct gdi_axis_info_utf8				AXISINFOM, *PAXISINFOM, *LPAXISINFOM;
typedef struct gdi_axis_info_utf16				AXISINFOW, *PAXISINFOW, *LPAXISINFOW;
typedef struct gdi_bitmap					BITMAP, *PBITMAP, *NPBITMAP, *LPBITMAP;
typedef struct gdi_bitmap_core_header				BITMAPCOREHEADER, *LPBITMAPCOREHEADER, *PBITMAPCOREHEADER;
typedef struct gdi_bitmap_core_info				BITMAPCOREINFO, *LPBITMAPCOREINFO, *PBITMAPCOREINFO;
typedef struct gdi_bitmap_file_header				BITMAPFILEHEADER, *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;
typedef struct gdi_bitmap_info					BITMAPINFO, *LPBITMAPINFO, *PBITMAPINFO;
typedef struct gdi_bitmap_info_header				BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;
typedef struct gdi_bitmap_v4_header				BITMAPV4HEADER, *LPBITMAPV4HEADER, *PBITMAPV4HEADER;
typedef struct gdi_bitmap_v5_header				BITMAPV5HEADER, *LPBITMAPV5HEADER, *PBITMAPV5HEADER;
typedef struct gdi_blend_function				BLENDFUNCTION, *PBLENDFUNCTION;
typedef struct gdi_charset_info					CHARSETINFO, *PCHARSETINFO, *NPCHARSETINFO, *LPCHARSETINFO;
typedef struct gdi_ciexyz					CIEXYZ, *LPCIEXYZ;
typedef struct gdi_color_adjustment				COLORADJUSTMENT, *PCOLORADJUSTMENT, *LPCOLORADJUSTMENT;
typedef struct gdi_color_correct_palette			EMRCOLORCORRECTPALETTE, *PEMRCOLORCORRECTPALETTE;
typedef struct gdi_color_match_to_target			EMRCOLORMATCHTOTARGET, *PEMRCOLORMATCHTOTARGET;
typedef struct gdi_design_vector				DESIGNVECTOR, *PDESIGNVECTOR, *LPDESIGNVECTOR;
typedef struct gdi_device_mode_ansi				DEVMODEA, *PDEVMODEA, *NPDEVMODEA, *LPDEVMODEA;
typedef struct gdi_device_mode_utf8				DEVMODEM, *PDEVMODEM, *NPDEVMODEM, *LPDEVMODEM;
typedef struct gdi_device_mode_utf16				DEVMODEW, *PDEVMODEW, *NPDEVMODEW, *LPDEVMODEW;
typedef struct gdi_dib_section					DIBSECTION, *LPDIBSECTION, *PDIBSECTION;
typedef struct gdi_display_device_ansi				DISPLAY_DEVICEA, *PDISPLAY_DEVICEA, *LPDISPLAY_DEVICEA;
typedef struct gdi_display_device_utf8				DISPLAY_DEVICEM, *PDISPLAY_DEVICEM, *LPDISPLAY_DEVICEM;
typedef struct gdi_display_device_utf16				DISPLAY_DEVICEW, *PDISPLAY_DEVICEW, *LPDISPLAY_DEVICEW;
typedef struct gdi_displayconfig_2d_region			DISPLAYCONFIG_2DREGION;
typedef struct gdi_displayconfig_adapter_name			DISPLAYCONFIG_ADAPTER_NAME;
typedef struct gdi_displayconfig_device_info_header		DISPLAYCONFIG_DEVICE_INFO_HEADER;
typedef struct gdi_displayconfig_mode_info			DISPLAYCONFIG_MODE_INFO;
typedef struct gdi_displayconfig_path_info			DISPLAYCONFIG_PATH_INFO;
typedef struct gdi_displayconfig_path_source_info		DISPLAYCONFIG_PATH_SOURCE_INFO;
typedef struct gdi_displayconfig_path_target_info		DISPLAYCONFIG_PATH_TARGET_INFO;
typedef struct gdi_displayconfig_rational			DISPLAYCONFIG_RATIONAL;
typedef struct gdi_displayconfig_set_target_persistence		DISPLAYCONFIG_SET_TARGET_PERSISTENCE;
typedef struct gdi_displayconfig_source_device_name		DISPLAYCONFIG_SOURCE_DEVICE_NAME;
typedef struct gdi_displayconfig_source_mode			DISPLAYCONFIG_SOURCE_MODE;
typedef struct gdi_displayconfig_target_device_name		DISPLAYCONFIG_TARGET_DEVICE_NAME;
typedef struct gdi_displayconfig_target_device_name_flags	DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS;
typedef struct gdi_displayconfig_target_mode			DISPLAYCONFIG_TARGET_MODE;
typedef struct gdi_displayconfig_target_preferred_mode		DISPLAYCONFIG_TARGET_PREFERRED_MODE;
typedef struct gdi_displayconfig_video_signal_info		DISPLAYCONFIG_VIDEO_SIGNAL_INFO;
typedef struct gdi_doc_info_ansi				DOCINFOA, *LPDOCINFOA;
typedef struct gdi_doc_info_utf8				DOCINFOM, *LPDOCINFOM;
typedef struct gdi_doc_info_utf16				DOCINFOW, *LPDOCINFOW;
typedef struct gdi_draw_pat_rect				DRAWPATRECT, *PDRAWPATRECT;
typedef struct gdi_emr						EMR, *PEMR;
typedef struct gdi_emr_alpha_blend				EMRALPHABLEND, *PEMRALPHABLEND;
typedef struct gdi_emr_angle_arc				EMRANGLEARC, *PEMRANGLEARC;
typedef struct gdi_emr_arc					EMRARC, *PEMRARC;
typedef struct gdi_emr_arc					EMRARCTO, *PEMRARCTO;
typedef struct gdi_emr_arc					EMRCHORD, *PEMRCHORD;
typedef struct gdi_emr_arc					EMRPIE, *PEMRPIE;
typedef struct gdi_emr_bit_blt					EMRBITBLT, *PEMRBITBLT;
typedef struct gdi_emr_create_brush_indirect			EMRCREATEBRUSHINDIRECT, *PEMRCREATEBRUSHINDIRECT;
typedef struct gdi_emr_create_color_space			EMRCREATECOLORSPACE, *PEMRCREATECOLORSPACE;
typedef struct gdi_emr_create_color_space_utf16			EMRCREATECOLORSPACEW, *PEMRCREATECOLORSPACEW;
typedef struct gdi_emr_create_dib_pattern_brush_pt		EMRCREATEDIBPATTERNBRUSHPT, *PEMRCREATEDIBPATTERNBRUSHPT;
typedef struct gdi_emr_create_mono_brush			EMRCREATEMONOBRUSH, *PEMRCREATEMONOBRUSH;
typedef struct gdi_emr_create_palette				EMRCREATEPALETTE, *PEMRCREATEPALETTE;
typedef struct gdi_emr_create_pen				EMRCREATEPEN, *PEMRCREATEPEN;
typedef struct gdi_emr_ellipse					EMRELLIPSE, *PEMRELLIPSE;
typedef struct gdi_emr_ellipse					EMRRECTANGLE, *PEMRRECTANGLE;
typedef struct gdi_emr_eof					EMREOF, *PEMREOF;
typedef struct gdi_emr_exclude_clip_rect			EMREXCLUDECLIPRECT, *PEMREXCLUDECLIPRECT;
typedef struct gdi_emr_exclude_clip_rect			EMRINTERSECTCLIPRECT, *PEMRINTERSECTCLIPRECT;
typedef struct gdi_emr_ext_create_font_indirect_utf16		EMREXTCREATEFONTINDIRECTW, *PEMREXTCREATEFONTINDIRECTW;
typedef struct gdi_emr_ext_createpen				EMREXTCREATEPEN, *PEMREXTCREATEPEN;
typedef struct gdi_emr_ext_escape				EMREXTESCAPE, *PEMREXTESCAPE;
typedef struct gdi_emr_ext_escape				EMRDRAWESCAPE, *PEMRDRAWESCAPE;
typedef struct gdi_emr_ext_flood_fill				EMREXTFLOODFILL, *PEMREXTFLOODFILL;
typedef struct gdi_emr_ext_select_clip_rgn			EMREXTSELECTCLIPRGN, *PEMREXTSELECTCLIPRGN;
typedef struct gdi_emr_ext_text_out_ansi			EMREXTTEXTOUTA, *PEMREXTTEXTOUTA;
typedef struct gdi_emr_ext_text_out_ansi			EMREXTTEXTOUTW, *PEMREXTTEXTOUTW;
typedef struct gdi_emr_ext_text_out_utf8			EMREXTTEXTOUTM, *PEMREXTTEXTOUTM;
typedef struct gdi_emr_ext_text_out_utf8			EMREXTTEXTOUTM, *PEMREXTTEXTOUTM;
typedef struct gdi_emr_fill_path				EMRFILLPATH, *PEMRFILLPATH;
typedef struct gdi_emr_fill_path				EMRSTROKEANDFILLPATH, *PEMRSTROKEANDFILLPATH;
typedef struct gdi_emr_fill_path				EMRSTROKEPATH, *PEMRSTROKEPATH;
typedef struct gdi_emr_fill_rgn					EMRFILLRGN, *PEMRFILLRGN;
typedef struct gdi_emr_format					EMRFORMAT, *PEMRFORMAT;
typedef struct gdi_emr_frame_rgn				EMRFRAMERGN, *PEMRFRAMERGN;
typedef struct gdi_emr_gdi_comment				EMRGDICOMMENT, *PEMRGDICOMMENT;
typedef struct gdi_emr_gls_bounded_record			EMRGLSBOUNDEDRECORD, *PEMRGLSBOUNDEDRECORD;
typedef struct gdi_emr_gls_record				EMRGLSRECORD, *PEMRGLSRECORD;
typedef struct gdi_emr_gradient_fill				EMRGRADIENTFILL, *PEMRGRADIENTFILL;
typedef struct gdi_emr_invert_rgn				EMRINVERTRGN, *PEMRINVERTRGN;
typedef struct gdi_emr_invert_rgn				EMRPAINTRGN, *PEMRPAINTRGN;
typedef struct gdi_emr_line_to					EMRLINETO, *PEMRLINETO;
typedef struct gdi_emr_line_to					EMRMOVETOEX, *PEMRMOVETOEX;
typedef struct gdi_emr_mask_blt					EMRMASKBLT, *PEMRMASKBLT;
typedef struct gdi_emr_modify_world_transform			EMRMODIFYWORLDTRANSFORM, *PEMRMODIFYWORLDTRANSFORM;
typedef struct gdi_emr_named_escape				EMRNAMEDESCAPE, *PEMRNAMEDESCAPE;
typedef struct gdi_emr_offset_clip_rgn				EMROFFSETCLIPRGN, *PEMROFFSETCLIPRGN;
typedef struct gdi_emr_pixel_format				EMRPIXELFORMAT, *PEMRPIXELFORMAT;
typedef struct gdi_emr_plg_blt					EMRPLGBLT, *PEMRPLGBLT;
typedef struct gdi_emr_poly_draw				EMRPOLYDRAW, *PEMRPOLYDRAW;
typedef struct gdi_emr_poly_draw_16				EMRPOLYDRAW16, *PEMRPOLYDRAW16;
typedef struct gdi_emr_poly_line				EMRPOLYLINE, *PEMRPOLYLINE;
typedef struct gdi_emr_poly_line				EMRPOLYBEZIER, *PEMRPOLYBEZIER;
typedef struct gdi_emr_poly_line				EMRPOLYGON, *PEMRPOLYGON;
typedef struct gdi_emr_poly_line				EMRPOLYBEZIERTO, *PEMRPOLYBEZIERTO;
typedef struct gdi_emr_poly_line				EMRPOLYLINETO, *PEMRPOLYLINETO;
typedef struct gdi_emr_poly_line_16				EMRPOLYLINE16, *PEMRPOLYLINE16;
typedef struct gdi_emr_poly_line_16				EMRPOLYBEZIER16, *PEMRPOLYBEZIER16;
typedef struct gdi_emr_poly_line_16				EMRPOLYGON16, *PEMRPOLYGON16;
typedef struct gdi_emr_poly_line_16				EMRPOLYBEZIERTO16, *PEMRPOLYBEZIERTO16;
typedef struct gdi_emr_poly_line_16				EMRPOLYLINETO16, *PEMRPOLYLINETO16;
typedef struct gdi_emr_poly_poly_line				EMRPOLYPOLYLINE, *PEMRPOLYPOLYLINE;
typedef struct gdi_emr_poly_poly_line				EMRPOLYPOLYGON, *PEMRPOLYPOLYGON;
typedef struct gdi_emr_poly_poly_line_16			EMRPOLYPOLYLINE16, *PEMRPOLYPOLYLINE16;
typedef struct gdi_emr_poly_poly_line_16			EMRPOLYPOLYGON16, *PEMRPOLYPOLYGON16;
typedef struct gdi_emr_poly_text_out_ansi			EMRPOLYTEXTOUTA, *PEMRPOLYTEXTOUTA;
typedef struct gdi_emr_poly_text_out_ansi			EMRPOLYTEXTOUTW, *PEMRPOLYTEXTOUTW;
typedef struct gdi_emr_poly_text_out_utf8			EMRPOLYTEXTOUTM, *PEMRPOLYTEXTOUTM;
typedef struct gdi_emr_poly_text_out_utf8			EMRPOLYTEXTOUTM, *PEMRPOLYTEXTOUTM;
typedef struct gdi_emr_resize_palette				EMRRESIZEPALETTE, *PEMRRESIZEPALETTE;
typedef struct gdi_emr_restore_dc				EMRRESTOREDC, *PEMRRESTOREDC;
typedef struct gdi_emr_round_rect				EMRROUNDRECT, *PEMRROUNDRECT;
typedef struct gdi_emr_scale_viewport_ext_ex			EMRSCALEVIEWPORTEXTEX, *PEMRSCALEVIEWPORTEXTEX;
typedef struct gdi_emr_scale_viewport_ext_ex			EMRSCALEWINDOWEXTEX, *PEMRSCALEWINDOWEXTEX;
typedef struct gdi_emr_select_clip_path				EMRSELECTCLIPPATH, *PEMRSELECTCLIPPATH;
typedef struct gdi_emr_select_clip_path				EMRSETBKMODE, *PEMRSETBKMODE;
typedef struct gdi_emr_select_clip_path				EMRSETMAPMODE, *PEMRSETMAPMODE;
typedef struct gdi_emr_select_clip_path				EMRSETLAYOUT, *PEMRSETLAYOUT;
typedef struct gdi_emr_select_clip_path				EMRSETPOLYFILLMODE, *PEMRSETPOLYFILLMODE;
typedef struct gdi_emr_select_clip_path				EMRSETROP2, *PEMRSETROP2;
typedef struct gdi_emr_select_clip_path				EMRSETSTRETCHBLTMODE, *PEMRSETSTRETCHBLTMODE;
typedef struct gdi_emr_select_clip_path				EMRSETICMMODE, *PEMRSETICMMODE;
typedef struct gdi_emr_select_clip_path				EMRSETTEXTALIGN, *PEMRSETTEXTALIGN;
typedef struct gdi_emr_select_object				EMRSELECTOBJECT, *PEMRSELECTOBJECT;
typedef struct gdi_emr_select_object				EMRDELETEOBJECT, *PEMRDELETEOBJECT;
typedef struct gdi_emr_select_palette				EMRSELECTPALETTE, *PEMRSELECTPALETTE;
typedef struct gdi_emr_set_arc_direction			EMRSETARCDIRECTION, *PEMRSETARCDIRECTION;
typedef struct gdi_emr_set_color_adjustment			EMRSETCOLORADJUSTMENT, *PEMRSETCOLORADJUSTMENT;
typedef struct gdi_emr_set_color_space				EMRSETCOLORSPACE, *PEMRSETCOLORSPACE;
typedef struct gdi_emr_set_color_space				EMRSELECTCOLORSPACE, *PEMRSELECTCOLORSPACE;
typedef struct gdi_emr_set_color_space				EMRDELETECOLORSPACE, *PEMRDELETECOLORSPACE;
typedef struct gdi_emr_set_di_bits_to_device			EMRSETDIBITSTODEVICE, *PEMRSETDIBITSTODEVICE;
typedef struct gdi_emr_set_icm_profile				*PEMRSETICMPROFILE;
typedef struct gdi_emr_set_icm_profile				EMRSETICMPROFILEA, *PEMRSETICMPROFILEA;
typedef struct gdi_emr_set_icm_profile				EMRSETICMPROFILEW, *PEMRSETICMPROFILEW;
typedef struct gdi_emr_set_mapper_flags				EMRSETMAPPERFLAGS, *PEMRSETMAPPERFLAGS;
typedef struct gdi_emr_set_miter_limit				EMRSETMITERLIMIT, *PEMRSETMITERLIMIT;
typedef struct gdi_emr_set_palette_entries			EMRSETPALETTEENTRIES, *PEMRSETPALETTEENTRIES;
typedef struct gdi_emr_set_pixel_v				EMRSETPIXELV, *PEMRSETPIXELV;
typedef struct gdi_emr_set_text_color				EMRSETBKCOLOR, *PEMRSETBKCOLOR;
typedef struct gdi_emr_set_text_color				EMRSETTEXTCOLOR, *PEMRSETTEXTCOLOR;
typedef struct gdi_emr_set_viewport_ext_ex			EMRSETVIEWPORTEXTEX, *PEMRSETVIEWPORTEXTEX;
typedef struct gdi_emr_set_viewport_ext_ex			EMRSETWINDOWEXTEX, *PEMRSETWINDOWEXTEX;
typedef struct gdi_emr_set_viewport_org_ex			EMRSETVIEWPORTORGEX, *PEMRSETVIEWPORTORGEX;
typedef struct gdi_emr_set_viewport_org_ex			EMRSETWINDOWORGEX, *PEMRSETWINDOWORGEX;
typedef struct gdi_emr_set_viewport_org_ex			EMRSETBRUSHORGEX, *PEMRSETBRUSHORGEX;
typedef struct gdi_emr_set_world_transform			EMRSETWORLDTRANSFORM, *PEMRSETWORLDTRANSFORM;
typedef struct gdi_emr_stretch_blt				EMRSTRETCHBLT, *PEMRSTRETCHBLT;
typedef struct gdi_emr_stretch_di_bits				EMRSTRETCHDIBITS, *PEMRSTRETCHDIBITS;
typedef struct gdi_emr_text					EMRTEXT, *PEMRTEXT;
typedef struct gdi_emr_transparent_blt				EMRTRANSPARENTBLT, *PEMRTRANSPARENTBLT;
typedef struct gdi_enh_meta_header				ENHMETAHEADER, *PENHMETAHEADER, *LPENHMETAHEADER;
typedef struct gdi_enh_meta_record				ENHMETARECORD, *PENHMETARECORD, *LPENHMETARECORD;
typedef struct gdi_enum_log_font_ansi				ENUMLOGFONTA, *LPENUMLOGFONTA;
typedef struct gdi_enum_log_font_utf8				ENUMLOGFONTM, *LPENUMLOGFONTM;
typedef struct gdi_enum_log_font_ex_ansi			ENUMLOGFONTEXA, *LPENUMLOGFONTEXA;
typedef struct gdi_enum_log_font_ex_utf8			ENUMLOGFONTEXM, *LPENUMLOGFONTEXM;
typedef struct gdi_enum_log_font_ex_dv_ansi			ENUMLOGFONTEXDVA, *PENUMLOGFONTEXDVA, *LPENUMLOGFONTEXDVA;
typedef struct gdi_enum_log_font_ex_dv_utf8			ENUMLOGFONTEXDVM, *PENUMLOGFONTEXDVM, *LPENUMLOGFONTEXDVM;
typedef struct gdi_enum_log_font_ex_dv_utf16			ENUMLOGFONTEXDVW, *PENUMLOGFONTEXDVW, *LPENUMLOGFONTEXDVW;
typedef struct gdi_enum_log_font_ex_utf16			ENUMLOGFONTEXW, *LPENUMLOGFONTEXW;
typedef struct gdi_enum_log_font_utf16				ENUMLOGFONTW, *LPENUMLOGFONTW;
typedef struct gdi_enum_text_metric_ansi			ENUMTEXTMETRICA, *PENUMTEXTMETRICA, *LPENUMTEXTMETRICA;
typedef struct gdi_enum_text_metric_utf8			ENUMTEXTMETRICM, *PENUMTEXTMETRICM, *LPENUMTEXTMETRICM;
typedef struct gdi_enum_text_metric_utf16			ENUMTEXTMETRICW, *PENUMTEXTMETRICW, *LPENUMTEXTMETRICW;
typedef struct gdi_ext_log_font_ansi				EXTLOGFONTA, *PEXTLOGFONTA, *NPEXTLOGFONTA, *LPEXTLOGFONTA;
typedef struct gdi_ext_log_font_utf8				EXTLOGFONTM, *PEXTLOGFONTM, *NPEXTLOGFONTM, *LPEXTLOGFONTM;
typedef struct gdi_ext_log_font_utf16				EXTLOGFONTW, *PEXTLOGFONTW, *NPEXTLOGFONTW, *LPEXTLOGFONTW;
typedef struct gdi_ext_log_pen					EXTLOGPEN, *PEXTLOGPEN, *NPEXTLOGPEN, *LPEXTLOGPEN;
typedef struct gdi_ext_log_pen_32				EXTLOGPEN32, *PEXTLOGPEN32, *NPEXTLOGPEN32, *LPEXTLOGPEN32;
typedef struct gdi_fixed					FIXED;
typedef struct gdi_font_signature				FONTSIGNATURE, *PFONTSIGNATURE, *LPFONTSIGNATURE;
typedef struct gdi_gcp_results_ansi				GCP_RESULTSA, *LPGCP_RESULTSA;
typedef struct gdi_gcp_results_utf8				GCP_RESULTSM, *LPGCP_RESULTSM;
typedef struct gdi_gcp_results_utf16				GCP_RESULTSW, *LPGCP_RESULTSW;
typedef struct gdi_glyph_metrics				GLYPHMETRICS, *LPGLYPHMETRICS;
typedef struct gdi_glyph_metrics_float				GLYPHMETRICSFLOAT, *PGLYPHMETRICSFLOAT, *LPGLYPHMETRICSFLOAT;
typedef struct gdi_glyph_set					GLYPHSET, *PGLYPHSET, *LPGLYPHSET;
typedef struct gdi_gradient_rect				GRADIENT_RECT, *PGRADIENT_RECT, *LPGRADIENT_RECT;
typedef struct gdi_gradient_triangle				GRADIENT_TRIANGLE, *PGRADIENT_TRIANGLE, *LPGRADIENT_TRIANGLE;
typedef struct gdi_handle_table					HANDLETABLE, *PHANDLETABLE, *LPHANDLETABLE;
typedef struct gdi_ice_xyz_triple				CIEXYZTRIPLE, *LPCIEXYZTRIPLE;
typedef struct gdi_kerning_pair					KERNINGPAIR, *LPKERNINGPAIR;
typedef struct gdi_layer_plane_descriptor			LAYERPLANEDESCRIPTOR, *PLAYERPLANEDESCRIPTOR, *LPLAYERPLANEDESCRIPTOR;
typedef struct gdi_locale_signature				LOCALESIGNATURE, *PLOCALESIGNATURE, *LPLOCALESIGNATURE;
typedef struct gdi_log_brush					LOGBRUSH, *PLOGBRUSH, *NPLOGBRUSH, *LPLOGBRUSH;
typedef struct gdi_log_brush					PATTERN, *PPATTERN, *NPPATTERN, *LPPATTERN;
typedef struct gdi_log_brush_32					LOGBRUSH32, *PLOGBRUSH32, *NPLOGBRUSH32, *LPLOGBRUSH32;
typedef struct gdi_log_color_space_ansi				LOGCOLORSPACEA, *LPLOGCOLORSPACEA;
typedef struct gdi_log_color_space_utf8				LOGCOLORSPACEM, *LPLOGCOLORSPACEM;
typedef struct gdi_log_color_space_utf16			LOGCOLORSPACEW, *LPLOGCOLORSPACEW;
typedef struct gdi_log_font_ansi				LOGFONTA, *PLOGFONTA, *NPLOGFONTA, *LPLOGFONTA;
typedef struct gdi_log_font_utf8				LOGFONTM, *PLOGFONTM, *NPLOGFONTM, *LPLOGFONTM;
typedef struct gdi_log_font_utf16				LOGFONTW, *PLOGFONTW, *NPLOGFONTW, *LPLOGFONTW;
typedef struct gdi_log_palette					LOGPALETTE, *PLOGPALETTE, *NPLOGPALETTE, *LPLOGPALETTE;
typedef struct gdi_log_pen					LOGPEN, *PLOGPEN, *NPLOGPEN, *LPLOGPEN;
typedef struct gdi_mat_2					MAT2, *LPMAT2;
typedef struct gdi_meta_file_pict				METAFILEPICT, *LPMETAFILEPICT;
typedef struct gdi_meta_header					METAHEADER, *PMETAHEADER, *LPMETAHEADER;
typedef struct gdi_meta_record					METARECORD, *PMETARECORD, *LPMETARECORD;
typedef struct gdi_new_text_metric_ansi				NEWTEXTMETRICA, *PNEWTEXTMETRICA, *NPNEWTEXTMETRICA, *LPNEWTEXTMETRICA;
typedef struct gdi_new_text_metric_utf8				NEWTEXTMETRICM, *PNEWTEXTMETRICM, *NPNEWTEXTMETRICM, *LPNEWTEXTMETRICM;
typedef struct gdi_new_text_metric_ex_ansi			NEWTEXTMETRICEXA;
typedef struct gdi_new_text_metric_ex_utf8			NEWTEXTMETRICEXM;
typedef struct gdi_new_text_metric_ex_utf16			NEWTEXTMETRICEXW;
typedef struct gdi_new_text_metric_utf16			NEWTEXTMETRICW, *PNEWTEXTMETRICW, *NPNEWTEXTMETRICW, *LPNEWTEXTMETRICW;
typedef struct gdi_outline_text_metric_ansi			OUTLINETEXTMETRICA, *POUTLINETEXTMETRICA, *NPOUTLINETEXTMETRICA, *LPOUTLINETEXTMETRICA;
typedef struct gdi_outline_text_metric_utf8			OUTLINETEXTMETRICM, *POUTLINETEXTMETRICM, *NPOUTLINETEXTMETRICM, *LPOUTLINETEXTMETRICM;
typedef struct gdi_outline_text_metric_utf16			OUTLINETEXTMETRICW, *POUTLINETEXTMETRICW, *NPOUTLINETEXTMETRICW, *LPOUTLINETEXTMETRICW;
typedef struct gdi_palette_entry				PALETTEENTRY, *PPALETTEENTRY, *LPPALETTEENTRY;
typedef struct gdi_panose					PANOSE, *LPPANOSE;
typedef struct gdi_pel_array					PELARRAY, *PPELARRAY, *NPPELARRAY, *LPPELARRAY;
typedef struct gdi_pixel_format_descriptor			PIXELFORMATDESCRIPTOR, *PPIXELFORMATDESCRIPTOR, *LPPIXELFORMATDESCRIPTOR;
typedef struct gdi_point_float					POINTFLOAT, *PPOINTFLOAT;
typedef struct gdi_point_fx					POINTFX, *LPPOINTFX;
typedef struct gdi_poly_text_ansi				POLYTEXTA, *PPOLYTEXTA, *NPPOLYTEXTA, *LPPOLYTEXTA;
typedef struct gdi_poly_text_utf8				POLYTEXTM, *PPOLYTEXTM, *NPPOLYTEXTM, *LPPOLYTEXTM;
typedef struct gdi_poly_text_utf16				POLYTEXTW, *PPOLYTEXTW, *NPPOLYTEXTW, *LPPOLYTEXTW;
typedef struct gdi_ps_feature_cust_paper			PSFEATURE_CUSTPAPER, *PPSFEATURE_CUSTPAPER;
typedef struct gdi_ps_feature_output				PSFEATURE_OUTPUT, *PPSFEATURE_OUTPUT;
typedef struct gdi_ps_inject_dat_ansi				PSINJECTDATA, *PPSINJECTDATA;
typedef struct gdi_ps_inject_dat_utf8				PSINJECTDATM, *PPSINJECTDATM;
typedef struct gdi_rasterizer_status				RASTERIZER_STATUS, *LPRASTERIZER_STATUS;
typedef struct gdi_rgb_quad					RGBQUAD, *LPRGBQUAD;
typedef struct gdi_rgb_triple					RGBTRIPLE, *PRGBTRIPLE, *NPRGBTRIPLE, *LPRGBTRIPLE;
typedef struct gdi_rgn_dat_ansi					RGNDATA, *PRGNDATA, *NPRGNDATA, *LPRGNDATA;
typedef struct gdi_rgn_dat_utf8					RGNDATM, *PRGNDATM, *NPRGNDATM, *LPRGNDATM;
typedef struct gdi_rgn_data_header				RGNDATAHEADER, *PRGNDATAHEADER;
typedef struct gdi_text_metric_ansi				TEXTMETRICA, *PTEXTMETRICA, *NPTEXTMETRICA, *LPTEXTMETRICA;
typedef struct gdi_text_metric_utf8				TEXTMETRICM, *PTEXTMETRICM, *NPTEXTMETRICM, *LPTEXTMETRICM;
typedef struct gdi_text_metric_utf16				TEXTMETRICW, *PTEXTMETRICW, *NPTEXTMETRICW, *LPTEXTMETRICW;
typedef struct gdi_trivertex					TRIVERTEX, *PTRIVERTEX, *LPTRIVERTEX;
typedef struct gdi_tt_poly_curve				TTPOLYCURVE, *LPTTPOLYCURVE;
typedef struct gdi_tt_polygon_header				TTPOLYGONHEADER, *LPTTPOLYGONHEADER;
typedef struct gdi_wcrange					WCRANGE, *PWCRANGE, *LPWCRANGE;
typedef struct gdi_wgl_swap					WGLSWAP, *PWGLSWAP, *LPWGLSWAP;
typedef struct gdi_xform					XFORM, *PXFORM, *LPXFORM;



union gdi_aa_ansi {
	INT	x;
	PCSTR	y;
};

union gdi_aa_utf8 {
	INT	x;
	PCMBSTR	y;
};

union gdi_aa_utf16 {
	INT	x;
	PCWSTR	y;
};

struct gdi_abc {
	INT	abcA;
	UINT	abcB;
	INT	abcC;
};

struct gdi_abc_float {
	FLOAT	abcfA;
	FLOAT	abcfB;
	FLOAT	abcfC;
};

struct gdi_emr {
	DWORD	iType;
	DWORD	nSize;
};

struct gdi_abort_path {
	EMR	emr;
};

struct gdi_axis_info_ansi {
	LONG	axMinValue;
	LONG	axMaxValue;
	BYTE	axAxisName[16];
};

struct gdi_axis_info_utf8 {
	LONG	axMinValue;
	LONG	axMaxValue;
	BYTE	axAxisName[16];
};

struct gdi_axes_list_ansi {
	DWORD		axlReserved;
	DWORD		axlNumAxes;
	AXISINFOA	axlAxisInfo[16];
};

struct gdi_axes_list_utf8 {
	DWORD		axlReserved;
	DWORD		axlNumAxes;
	AXISINFOM	axlAxisInfo[16];
};

struct gdi_axis_info_utf16 {
	LONG	axMinValue;
	LONG	axMaxValue;
	WCHAR	axAxisName[16];
};

struct gdi_axes_list_utf16 {
	DWORD		axlReserved;
	DWORD		axlNumAxes;
	AXISINFOW	axlAxisInfo[16];
};

struct gdi_bitmap {
	LONG	bmType;
	LONG	bmWidth;
	LONG	bmHeight;
	LONG	bmWidthBytes;
	WORD	bmPlanes;
	WORD	bmBitsPixel;
	LPVOID	bmBits;
};

struct gdi_bitmap_core_header {
	DWORD	bcSize;
	WORD	bcWidth;
	WORD	bcHeight;
	WORD	bcPlanes;
	WORD	bcBitCount;
};

struct gdi_rgb_triple {
	BYTE	rgbtBlue;
	BYTE	rgbtGreen;
	BYTE	rgbtRed;
};

struct gdi_bitmap_core_info {
	BITMAPCOREHEADER	bmciHeader;
	RGBTRIPLE		bmciColors[1];
};

struct gdi_bitmap_file_header {
	WORD	bfType;
	DWORD	bfSize;
	WORD	bfReserved1;
	WORD	bfReserved2;
	DWORD	bfOffBits;
};

struct gdi_bitmap_info_header {
	DWORD	biSize;
	LONG	biWidth;
	LONG	biHeight;
	WORD	biPlanes;
	WORD	biBitCount;
	DWORD	biCompression;
	DWORD	biSizeImage;
	LONG	biXPelsPerMeter;
	LONG	biYPelsPerMeter;
	DWORD	biClrUsed;
	DWORD	biClrImportant;
};

struct gdi_rgb_quad {
	BYTE	rgbBlue;
	BYTE	rgbGreen;
	BYTE	rgbRed;
	BYTE	rgbReserved;
};

struct gdi_bitmap_info {
	BITMAPINFOHEADER	bmiHeader;
	RGBQUAD			bmiColors[1];
};

struct gdi_ciexyz {
	FXPT2DOT30	ciexyzX;
	FXPT2DOT30	ciexyzY;
	FXPT2DOT30	ciexyzZ;
};

struct gdi_ice_xyz_triple {
	CIEXYZ	ciexyzRed;
	CIEXYZ	ciexyzGreen;
	CIEXYZ	ciexyzBlue;
};

struct gdi_bitmap_v4_header {
	DWORD		bV4Size;
	LONG		bV4Width;
	LONG		bV4Height;
	WORD		bV4Planes;
	WORD		bV4BitCount;
	DWORD		bV4V4Compression;
	DWORD		bV4SizeImage;
	LONG		bV4XPelsPerMeter;
	LONG		bV4YPelsPerMeter;
	DWORD		bV4ClrUsed;
	DWORD		bV4ClrImportant;
	DWORD		bV4RedMask;
	DWORD		bV4GreenMask;
	DWORD		bV4BlueMask;
	DWORD		bV4AlphaMask;
	DWORD		bV4CSType;
	CIEXYZTRIPLE	bV4Endpoints;
	DWORD		bV4GammaRed;
	DWORD		bV4GammaGreen;
	DWORD		bV4GammaBlue;
};

struct gdi_bitmap_v5_header {
	DWORD		bV5Size;
	LONG		bV5Width;
	LONG		bV5Height;
	WORD		bV5Planes;
	WORD		bV5BitCount;
	DWORD		bV5Compression;
	DWORD		bV5SizeImage;
	LONG		bV5XPelsPerMeter;
	LONG		bV5YPelsPerMeter;
	DWORD		bV5ClrUsed;
	DWORD		bV5ClrImportant;
	DWORD		bV5RedMask;
	DWORD		bV5GreenMask;
	DWORD		bV5BlueMask;
	DWORD		bV5AlphaMask;
	DWORD		bV5CSType;
	CIEXYZTRIPLE	bV5Endpoints;
	DWORD		bV5GammaRed;
	DWORD		bV5GammaGreen;
	DWORD		bV5GammaBlue;
	DWORD		bV5Intent;
	DWORD		bV5ProfileData;
	DWORD		bV5ProfileSize;
	DWORD		bV5Reserved;
};

struct gdi_blend_function {
	BYTE	BlendOp;
	BYTE	BlendFlags;
	BYTE	SourceConstantAlpha;
	BYTE	AlphaFormat;
};

struct gdi_font_signature {
	DWORD	fsUsb[4];
	DWORD	fsCsb[2];
};

struct gdi_charset_info {
	UINT		ciCharset;
	UINT		ciACP;
	FONTSIGNATURE	fs;
};

struct gdi_color_adjustment {
	WORD	caSize;
	WORD	caFlags;
	WORD	caIlluminantIndex;
	WORD	caRedGamma;
	WORD	caGreenGamma;
	WORD	caBlueGamma;
	WORD	caReferenceBlack;
	WORD	caReferenceWhite;
	SHORT	caContrast;
	SHORT	caBrightness;
	SHORT	caColorfulness;
	SHORT	caRedGreenTint;
};

struct gdi_color_correct_palette {
	EMR	emr;
	DWORD	ihPalette;
	DWORD	nFirstEntry;
	DWORD	nPalEntries;
	DWORD	nReserved;
};

struct gdi_color_match_to_target {
	EMR	emr;
	DWORD	dwAction;
	DWORD	dwFlags;
	DWORD	cbName;
	DWORD	cbData;
	BYTE	Data[1];
};

struct gdi_design_vector {
	DWORD	dvReserved;
	DWORD	dvNumAxes;
	LONG	dvValues[16];
};

struct gdi_device_mode_ansi {
	BYTE	dmDeviceName[32];
	WORD	dmSpecVersion;
	WORD	dmDriverVersion;
	WORD	dmSize;
	WORD	dmDriverExtra;
	DWORD	dmFields;

	union {
		struct {
			SHORT	dmOrientation;
			SHORT	dmPaperSize;
			SHORT	dmPaperLength;
			SHORT	dmPaperWidth;
			SHORT	dmScale;
			SHORT	dmCopies;
			SHORT	dmDefaultSource;
			SHORT	dmPrintQuality;
		};

		struct {
			POINTL	dmPosition;
			DWORD	dmDisplayOrientation;
			DWORD	dmDisplayFixedOutput;
		};
	};

	SHORT	dmColor;
	SHORT	dmDuplex;
	SHORT	dmYResolution;
	SHORT	dmTTOption;
	SHORT	dmCollate;
	BYTE	dmFormName[32];
	WORD	dmLogPixels;
	DWORD	dmBitsPerPel;
	DWORD	dmPelsWidth;
	DWORD	dmPelsHeight;

	union {
		DWORD	dmDisplayFlags;
		DWORD	dmNup;
	};

	DWORD	dmDisplayFrequency;
	DWORD	dmICMMethod;
	DWORD	dmICMIntent;
	DWORD	dmMediaType;
	DWORD	dmDitherType;
	DWORD	dmReserved1;
	DWORD	dmReserved2;
	DWORD	dmPanningWidth;
	DWORD	dmPanningHeight;
};

struct gdi_device_mode_utf8 {
	BYTE	dmDeviceName[32];
	WORD	dmSpecVersion;
	WORD	dmDriverVersion;
	WORD	dmSize;
	WORD	dmDriverExtra;
	DWORD	dmFields;

	union {
		struct {
			SHORT	dmOrientation;
			SHORT	dmPaperSize;
			SHORT	dmPaperLength;
			SHORT	dmPaperWidth;
			SHORT	dmScale;
			SHORT	dmCopies;
			SHORT	dmDefaultSource;
			SHORT	dmPrintQuality;
		};

		struct {
			POINTL	dmPosition;
			DWORD	dmDisplayOrientation;
			DWORD	dmDisplayFixedOutput;
		};
	};

	SHORT	dmColor;
	SHORT	dmDuplex;
	SHORT	dmYResolution;
	SHORT	dmTTOption;
	SHORT	dmCollate;
	BYTE	dmFormName[32];
	WORD	dmLogPixels;
	DWORD	dmBitsPerPel;
	DWORD	dmPelsWidth;
	DWORD	dmPelsHeight;

	union {
		DWORD	dmDisplayFlags;
		DWORD	dmNup;
	};

	DWORD	dmDisplayFrequency;
	DWORD	dmICMMethod;
	DWORD	dmICMIntent;
	DWORD	dmMediaType;
	DWORD	dmDitherType;
	DWORD	dmReserved1;
	DWORD	dmReserved2;
	DWORD	dmPanningWidth;
	DWORD	dmPanningHeight;
};

struct gdi_device_mode_utf16 {
	WCHAR	dmDeviceName[32];
	WORD	dmSpecVersion;
	WORD	dmDriverVersion;
	WORD	dmSize;
	WORD	dmDriverExtra;
	DWORD	dmFields;

	union {
		struct {
			SHORT	dmOrientation;
			SHORT	dmPaperSize;
			SHORT	dmPaperLength;
			SHORT	dmPaperWidth;
			SHORT	dmScale;
			SHORT	dmCopies;
			SHORT	dmDefaultSource;
			SHORT	dmPrintQuality;
		};

		struct {
			POINTL	dmPosition;
			DWORD	dmDisplayOrientation;
			DWORD	dmDisplayFixedOutput;
		};
	};

	SHORT	dmColor;
	SHORT	dmDuplex;
	SHORT	dmYResolution;
	SHORT	dmTTOption;
	SHORT	dmCollate;
	WCHAR	dmFormName[32];
	WORD	dmLogPixels;
	DWORD	dmBitsPerPel;
	DWORD	dmPelsWidth;
	DWORD	dmPelsHeight;

	union {
		DWORD	dmDisplayFlags;
		DWORD	dmNup;
	};

	DWORD	dmDisplayFrequency;
	DWORD	dmICMMethod;
	DWORD	dmICMIntent;
	DWORD	dmMediaType;
	DWORD	dmDitherType;
	DWORD	dmReserved1;
	DWORD	dmReserved2;
	DWORD	dmPanningWidth;
	DWORD	dmPanningHeight;
};

struct gdi_dib_section {
	BITMAP			dsBm;
	BITMAPINFOHEADER	dsBmih;
	DWORD			dsBitfields[3];
	HANDLE			dshSection;
	DWORD			dsOffset;
};

struct gdi_display_device_ansi {
	DWORD	cb;
	CHAR	DeviceName[32];
	CHAR	DeviceString[128];
	DWORD	StateFlags;
	CHAR	DeviceID[128];
	CHAR	DeviceKey[128];
};

struct gdi_display_device_utf8 {
	DWORD	cb;
	CHAR	DeviceName[32];
	CHAR	DeviceString[128];
	DWORD	StateFlags;
	CHAR	DeviceID[128];
	CHAR	DeviceKey[128];
};

struct gdi_display_device_utf16 {
	DWORD	cb;
	WCHAR	DeviceName[32];
	WCHAR	DeviceString[128];
	DWORD	StateFlags;
	WCHAR	DeviceID[128];
	WCHAR	DeviceKey[128];
};

struct gdi_displayconfig_2d_region {
	UINT32	cx;
	UINT32	cy;
};

struct gdi_displayconfig_device_info_header {
	DISPLAYCONFIG_DEVICE_INFO_TYPE	type;
	UINT32				size;
	LUID				adapterId;
	UINT32				id;
};

struct gdi_displayconfig_adapter_name {
	DISPLAYCONFIG_DEVICE_INFO_HEADER	header;
	WCHAR					adapterDevicePath[128];
};

struct gdi_displayconfig_rational {
	UINT32	Numerator;
	UINT32	Denominator;
};

struct gdi_displayconfig_video_signal_info {
	UINT64				pixelRate;
	DISPLAYCONFIG_RATIONAL		hSyncFreq;
	DISPLAYCONFIG_RATIONAL		vSyncFreq;
	DISPLAYCONFIG_2DREGION		activeSize;
	DISPLAYCONFIG_2DREGION		totalSize;
	UINT32				videoStandard;
	DISPLAYCONFIG_SCANLINE_ORDERING	scanLineOrdering;
};

struct gdi_displayconfig_target_mode {
	DISPLAYCONFIG_VIDEO_SIGNAL_INFO	targetVideoSignalInfo;
};

struct gdi_displayconfig_source_mode {
	UINT32				width;
	UINT32				height;
	DISPLAYCONFIG_PIXELFORMAT	pixelFormat;
	POINTL				position;
};

struct gdi_displayconfig_mode_info {
	DISPLAYCONFIG_MODE_INFO_TYPE	infoType;
	UINT32				id;
	LUID				adapterId;

	union {
		DISPLAYCONFIG_TARGET_MODE	targetMode;
		DISPLAYCONFIG_SOURCE_MODE	sourceMode;
	};
};

struct gdi_displayconfig_path_source_info {
	LUID	adapterId;
	UINT32	id;
	UINT32	modeInfoIdx;
	UINT32	statusFlags;
};

struct gdi_displayconfig_path_target_info {
	LUID					adapterId;
	UINT32					id;
	UINT32					modeInfoIdx;
	DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY	outputTechnology;
	DISPLAYCONFIG_ROTATION			rotation;
	DISPLAYCONFIG_SCALING			scaling;
	DISPLAYCONFIG_RATIONAL			refreshRate;
	DISPLAYCONFIG_SCANLINE_ORDERING		scanLineOrdering;
	BOOL					targetAvailable;
	UINT32					statusFlags;
};

struct gdi_displayconfig_path_info {
	DISPLAYCONFIG_PATH_SOURCE_INFO	sourceInfo;
	DISPLAYCONFIG_PATH_TARGET_INFO	targetInfo;
	UINT32				flags;
};

struct gdi_displayconfig_set_target_persistence {
	DISPLAYCONFIG_DEVICE_INFO_HEADER	header;

	union {
		struct {
			UINT32	bootPersistenceOn;
			UINT32	reserved;
		};

		UINT32		value;
	};
};

struct gdi_displayconfig_source_device_name {
	DISPLAYCONFIG_DEVICE_INFO_HEADER	header;
	WCHAR					viewGdiDeviceName[32];
};

struct gdi_displayconfig_target_device_name_flags {

	union {
		struct {
			UINT32	friendlyNameFromEdid;
			UINT32	friendlyNameForced;
			UINT32	edidIdsValid;
			UINT32	reserved;
		};

		UINT32		value;
	};
};

struct gdi_displayconfig_target_device_name {
	DISPLAYCONFIG_DEVICE_INFO_HEADER	header;
	DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS	flags;
	DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY	outputTechnology;
	UINT16					edidManufactureId;
	UINT16					edidProductCodeId;
	UINT32					connectorInstance;
	WCHAR					monitorFriendlyDeviceName[64];
	WCHAR					monitorDevicePath[128];
};

struct gdi_displayconfig_target_preferred_mode {
	DISPLAYCONFIG_DEVICE_INFO_HEADER	header;
	UINT32					width;
	UINT32					height;
	DISPLAYCONFIG_TARGET_MODE		targetMode;
};

struct gdi_doc_info_ansi {
	INT		cbSize;
	LPCSTR		lpszDocName;
	LPCSTR		lpszOutput;
	LPCSTR		lpszDatatype;
	DWORD		fwType;
};

struct gdi_doc_info_utf8 {
	INT		cbSize;
	LPCMBSTR	lpszDocName;
	LPCMBSTR	lpszOutput;
	LPCMBSTR	lpszDatatype;
	DWORD		fwType;
};

struct gdi_doc_info_utf16 {
	INT	cbSize;
	LPCWSTR	lpszDocName;
	LPCWSTR	lpszOutput;
	LPCWSTR	lpszDatatype;
	DWORD	fwType;
};

struct gdi_draw_pat_rect {
	POINT	ptPosition;
	POINT	ptSize;
	WORD	wStyle;
	WORD	wPattern;
};

struct gdi_xform {
	FLOAT	eM11;
	FLOAT	eM12;
	FLOAT	eM21;
	FLOAT	eM22;
	FLOAT	eDx;
	FLOAT	eDy;
};

struct gdi_emr_alpha_blend {
	EMR		emr;
	RECTL		rclBounds;
	LONG		xDest;
	LONG		yDest;
	LONG		cxDest;
	LONG		cyDest;
	DWORD		dwRop;
	LONG		xSrc;
	LONG		ySrc;
	XFORM		xformSrc;
	COLORREF	crBkColorSrc;
	DWORD		iUsageSrc;
	DWORD		offBmiSrc;
	DWORD		cbBmiSrc;
	DWORD		offBitsSrc;
	DWORD		cbBitsSrc;
	LONG		cxSrc;
	LONG		cySrc;
};

struct gdi_emr_angle_arc {
	EMR	emr;
	POINTL	ptlCenter;
	DWORD	nRadius;
	FLOAT	eStartAngle;
	FLOAT	eSweepAngle;
};

struct gdi_emr_arc {
	EMR	emr;
	RECTL	rclBox;
	POINTL	ptlStart;
	POINTL	ptlEnd;
};

struct gdi_emr_bit_blt {
	EMR		emr;
	RECTL		rclBounds;
	LONG		xDest;
	LONG		yDest;
	LONG		cxDest;
	LONG		cyDest;
	DWORD		dwRop;
	LONG		xSrc;
	LONG		ySrc;
	XFORM		xformSrc;
	COLORREF	crBkColorSrc;
	DWORD		iUsageSrc;
	DWORD		offBmiSrc;
	DWORD		cbBmiSrc;
	DWORD		offBitsSrc;
	DWORD		cbBitsSrc;
};

struct gdi_log_brush_32 {
	UINT		lbStyle;
	COLORREF	lbColor;
	ULONG		lbHatch;
};

struct gdi_emr_create_brush_indirect {
	EMR		emr;
	DWORD		ihBrush;
	LOGBRUSH32	lb;
};

struct gdi_log_color_space_ansi {
	DWORD		lcsSignature;
	DWORD		lcsVersion;
	DWORD		lcsSize;
	LCSCSTYPE	lcsCSType;
	LCSGAMUTMATCH	lcsIntent;
	CIEXYZTRIPLE	lcsEndpoints;
	DWORD		lcsGammaRed;
	DWORD		lcsGammaGreen;
	DWORD		lcsGammaBlue;
	CHAR		lcsFilename[260];
};

struct gdi_log_color_space_utf8 {
	DWORD		lcsSignature;
	DWORD		lcsVersion;
	DWORD		lcsSize;
	LCSCSTYPE	lcsCSType;
	LCSGAMUTMATCH	lcsIntent;
	CIEXYZTRIPLE	lcsEndpoints;
	DWORD		lcsGammaRed;
	DWORD		lcsGammaGreen;
	DWORD		lcsGammaBlue;
	CHAR		lcsFilename[260];
};

struct gdi_emr_create_color_space {
	EMR		emr;
	DWORD		ihCS;
	LOGCOLORSPACEA	lcs;
};

struct gdi_log_color_space_utf16 {
	DWORD		lcsSignature;
	DWORD		lcsVersion;
	DWORD		lcsSize;
	LCSCSTYPE	lcsCSType;
	LCSGAMUTMATCH	lcsIntent;
	CIEXYZTRIPLE	lcsEndpoints;
	DWORD		lcsGammaRed;
	DWORD		lcsGammaGreen;
	DWORD		lcsGammaBlue;
	WCHAR		lcsFilename[260];
};

struct gdi_emr_create_color_space_utf16 {
	EMR		emr;
	DWORD		ihCS;
	LOGCOLORSPACEW	lcs;
	DWORD		dwFlags;
	DWORD		cbData;
	BYTE		Data[1];
};

struct gdi_emr_create_dib_pattern_brush_pt {
	EMR	emr;
	DWORD	ihBrush;
	DWORD	iUsage;
	DWORD	offBmi;
	DWORD	cbBmi;
	DWORD	offBits;
	DWORD	cbBits;
};

struct gdi_emr_create_mono_brush {
	EMR	emr;
	DWORD	ihBrush;
	DWORD	iUsage;
	DWORD	offBmi;
	DWORD	cbBmi;
	DWORD	offBits;
	DWORD	cbBits;
};

struct gdi_palette_entry {
	BYTE	peRed;
	BYTE	peGreen;
	BYTE	peBlue;
	BYTE	peFlags;
};

struct gdi_log_palette {
	WORD		palVersion;
	WORD		palNumEntries;
	PALETTEENTRY	palPalEntry[1];
};

struct gdi_emr_create_palette {
	EMR		emr;
	DWORD		ihPal;
	LOGPALETTE	lgpl;
};

struct gdi_log_pen {
	UINT		lopnStyle;
	POINT		lopnWidth;
	COLORREF	lopnColor;
};

struct gdi_emr_create_pen {
	EMR	emr;
	DWORD	ihPen;
	LOGPEN	lopn;
};

struct gdi_emr_ellipse {
	EMR	emr;
	RECTL	rclBox;
};

struct gdi_emr_eof {
	EMR	emr;
	DWORD	nPalEntries;
	DWORD	offPalEntries;
	DWORD	nSizeLast;
};

struct gdi_emr_exclude_clip_rect {
	EMR	emr;
	RECTL	rclClip;
};

struct gdi_log_font_utf16 {
	LONG	lfHeight;
	LONG	lfWidth;
	LONG	lfEscapement;
	LONG	lfOrientation;
	LONG	lfWeight;
	BYTE	lfItalic;
	BYTE	lfUnderline;
	BYTE	lfStrikeOut;
	BYTE	lfCharSet;
	BYTE	lfOutPrecision;
	BYTE	lfClipPrecision;
	BYTE	lfQuality;
	BYTE	lfPitchAndFamily;
	WCHAR	lfFaceName[32];
};

struct gdi_panose {
	BYTE	bFamilyType;
	BYTE	bSerifStyle;
	BYTE	bWeight;
	BYTE	bProportion;
	BYTE	bContrast;
	BYTE	bStrokeVariation;
	BYTE	bArmStyle;
	BYTE	bLetterform;
	BYTE	bMidline;
	BYTE	bXHeight;
};

struct gdi_ext_log_font_utf16 {
	LOGFONTW	elfLogFont;
	WCHAR		elfFullName[64];
	WCHAR		elfStyle[32];
	DWORD		elfVersion;
	DWORD		elfStyleSize;
	DWORD		elfMatch;
	DWORD		elfReserved;
	BYTE		elfVendorId[4];
	DWORD		elfCulture;
	PANOSE		elfPanose;
};

struct gdi_emr_ext_create_font_indirect_utf16 {
	EMR		emr;
	DWORD		ihFont;
	EXTLOGFONTW	elfw;
};

struct gdi_ext_log_pen_32 {
	DWORD		elpPenStyle;
	DWORD		elpWidth;
	UINT		elpBrushStyle;
	COLORREF	elpColor;
	ULONG		elpHatch;
	DWORD		elpNumEntries;
	DWORD		elpStyleEntry[1];
};

struct gdi_emr_ext_createpen {
	EMR		emr;
	DWORD		ihPen;
	DWORD		offBmi;
	DWORD		cbBmi;
	DWORD		offBits;
	DWORD		cbBits;
	EXTLOGPEN32	elp;
};

struct gdi_emr_ext_escape {
	EMR	emr;
	INT	iEscape;
	INT	cbEscData;
	BYTE	EscData[1];
};

struct gdi_emr_ext_flood_fill {
	EMR		emr;
	POINTL		ptlStart;
	COLORREF	crColor;
	DWORD		iMode;
};

struct gdi_emr_ext_select_clip_rgn {
	EMR	emr;
	DWORD	cbRgnData;
	DWORD	iMode;
	BYTE	RgnData[1];
};

struct gdi_emr_text {
	POINTL	ptlReference;
	DWORD	nChars;
	DWORD	offString;
	DWORD	fOptions;
	RECTL	rcl;
	DWORD	offDx;
};

struct gdi_emr_ext_text_out_ansi {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	iGraphicsMode;
	FLOAT	exScale;
	FLOAT	eyScale;
	EMRTEXT	emrtext;
};

struct gdi_emr_ext_text_out_utf8 {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	iGraphicsMode;
	FLOAT	exScale;
	FLOAT	eyScale;
	EMRTEXT	emrtext;
};

struct gdi_emr_fill_path {
	EMR	emr;
	RECTL	rclBounds;
};

struct gdi_emr_fill_rgn {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	cbRgnData;
	DWORD	ihBrush;
	BYTE	RgnData[1];
};

struct gdi_emr_format {
	DWORD	dSignature;
	DWORD	nVersion;
	DWORD	cbData;
	DWORD	offData;
};

struct gdi_emr_frame_rgn {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	cbRgnData;
	DWORD	ihBrush;
	SIZEL	szlStroke;
	BYTE	RgnData[1];
};

struct gdi_emr_gdi_comment {
	EMR	emr;
	DWORD	cbData;
	BYTE	Data[1];
};

struct gdi_emr_gls_bounded_record {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	cbData;
	BYTE	Data[1];
};

struct gdi_emr_gls_record {
	EMR	emr;
	DWORD	cbData;
	BYTE	Data[1];
};

struct gdi_trivertex {
	LONG	x;
	LONG	y;
	COLOR16	Red;
	COLOR16	Green;
	COLOR16	Blue;
	COLOR16	Alpha;
};

struct gdi_emr_gradient_fill {
	EMR		emr;
	RECTL		rclBounds;
	DWORD		nVer;
	DWORD		nTri;
	ULONG		ulMode;
	TRIVERTEX	Ver[1];
};

struct gdi_emr_invert_rgn {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	cbRgnData;
	BYTE	RgnData[1];
};

struct gdi_emr_line_to {
	EMR	emr;
	POINTL	ptl;
};

struct gdi_emr_mask_blt {
	EMR		emr;
	RECTL		rclBounds;
	LONG		xDest;
	LONG		yDest;
	LONG		cxDest;
	LONG		cyDest;
	DWORD		dwRop;
	LONG		xSrc;
	LONG		ySrc;
	XFORM		xformSrc;
	COLORREF	crBkColorSrc;
	DWORD		iUsageSrc;
	DWORD		offBmiSrc;
	DWORD		cbBmiSrc;
	DWORD		offBitsSrc;
	DWORD		cbBitsSrc;
	LONG		xMask;
	LONG		yMask;
	DWORD		iUsageMask;
	DWORD		offBmiMask;
	DWORD		cbBmiMask;
	DWORD		offBitsMask;
	DWORD		cbBitsMask;
};

struct gdi_emr_modify_world_transform {
	EMR	emr;
	XFORM	xform;
	DWORD	iMode;
};

struct gdi_emr_named_escape {
	EMR	emr;
	INT	iEscape;
	INT	cbDriver;
	INT	cbEscData;
	BYTE	EscData[1];
};

struct gdi_emr_offset_clip_rgn {
	EMR	emr;
	POINTL	ptlOffset;
};

struct gdi_pixel_format_descriptor {
	WORD	nSize;
	WORD	nVersion;
	DWORD	dwFlags;
	BYTE	iPixelType;
	BYTE	cColorBits;
	BYTE	cRedBits;
	BYTE	cRedShift;
	BYTE	cGreenBits;
	BYTE	cGreenShift;
	BYTE	cBlueBits;
	BYTE	cBlueShift;
	BYTE	cAlphaBits;
	BYTE	cAlphaShift;
	BYTE	cAccumBits;
	BYTE	cAccumRedBits;
	BYTE	cAccumGreenBits;
	BYTE	cAccumBlueBits;
	BYTE	cAccumAlphaBits;
	BYTE	cDepthBits;
	BYTE	cStencilBits;
	BYTE	cAuxBuffers;
	BYTE	iLayerType;
	BYTE	bReserved;
	DWORD	dwLayerMask;
	DWORD	dwVisibleMask;
	DWORD	dwDamageMask;
};

struct gdi_emr_pixel_format {
	EMR			emr;
	PIXELFORMATDESCRIPTOR	pfd;
};

struct gdi_emr_plg_blt {
	EMR		emr;
	RECTL		rclBounds;
	POINTL		aptlDest[3];
	LONG		xSrc;
	LONG		ySrc;
	LONG		cxSrc;
	LONG		cySrc;
	XFORM		xformSrc;
	COLORREF	crBkColorSrc;
	DWORD		iUsageSrc;
	DWORD		offBmiSrc;
	DWORD		cbBmiSrc;
	DWORD		offBitsSrc;
	DWORD		cbBitsSrc;
	LONG		xMask;
	LONG		yMask;
	DWORD		iUsageMask;
	DWORD		offBmiMask;
	DWORD		cbBmiMask;
	DWORD		offBitsMask;
	DWORD		cbBitsMask;
};

struct gdi_emr_poly_draw {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	cptl;
	POINTL	aptl[1];
	BYTE	abTypes[1];
};

struct gdi_emr_poly_draw_16 {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	cpts;
	POINTS	apts[1];
	BYTE	abTypes[1];
};

struct gdi_emr_poly_line {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	cptl;
	POINTL	aptl[1];
};

struct gdi_emr_poly_line_16 {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	cpts;
	POINTS	apts[1];
};

struct gdi_emr_poly_poly_line {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	nPolys;
	DWORD	cptl;
	DWORD	aPolyCounts[1];
	POINTL	aptl[1];
};

struct gdi_emr_poly_poly_line_16 {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	nPolys;
	DWORD	cpts;
	DWORD	aPolyCounts[1];
	POINTS	apts[1];
};

struct gdi_emr_poly_text_out_ansi {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	iGraphicsMode;
	FLOAT	exScale;
	FLOAT	eyScale;
	LONG	cStrings;
	EMRTEXT	aemrtext[1];
};

struct gdi_emr_poly_text_out_utf8 {
	EMR	emr;
	RECTL	rclBounds;
	DWORD	iGraphicsMode;
	FLOAT	exScale;
	FLOAT	eyScale;
	LONG	cStrings;
	EMRTEXT	aemrtext[1];
};

struct gdi_emr_resize_palette {
	EMR	emr;
	DWORD	ihPal;
	DWORD	cEntries;
};

struct gdi_emr_restore_dc {
	EMR	emr;
	LONG	iRelative;
};

struct gdi_emr_round_rect {
	EMR	emr;
	RECTL	rclBox;
	SIZEL	szlCorner;
};

struct gdi_emr_scale_viewport_ext_ex {
	EMR	emr;
	LONG	xNum;
	LONG	xDenom;
	LONG	yNum;
	LONG	yDenom;
};

struct gdi_emr_select_clip_path {
	EMR	emr;
	DWORD	iMode;
};

struct gdi_emr_select_object {
	EMR	emr;
	DWORD	ihObject;
};

struct gdi_emr_select_palette {
	EMR	emr;
	DWORD	ihPal;
};

struct gdi_emr_set_arc_direction {
	EMR	emr;
	DWORD	iArcDirection;
};

struct gdi_emr_set_color_adjustment {
	EMR		emr;
	COLORADJUSTMENT	ColorAdjustment;
};

struct gdi_emr_set_color_space {
	EMR	emr;
	DWORD	ihCS;
};

struct gdi_emr_set_di_bits_to_device {
	EMR	emr;
	RECTL	rclBounds;
	LONG	xDest;
	LONG	yDest;
	LONG	xSrc;
	LONG	ySrc;
	LONG	cxSrc;
	LONG	cySrc;
	DWORD	offBmiSrc;
	DWORD	cbBmiSrc;
	DWORD	offBitsSrc;
	DWORD	cbBitsSrc;
	DWORD	iUsageSrc;
	DWORD	iStartScan;
	DWORD	cScans;
};

struct gdi_emr_set_icm_profile {
	EMR	emr;
	DWORD	dwFlags;
	DWORD	cbName;
	DWORD	cbData;
	BYTE	Data[1];
};

struct gdi_emr_set_mapper_flags {
	EMR	emr;
	DWORD	dwFlags;
};

struct gdi_emr_set_miter_limit {
	EMR	emr;
	FLOAT	eMiterLimit;
};

struct gdi_emr_set_palette_entries {
	EMR		emr;
	DWORD		ihPal;
	DWORD		iStart;
	DWORD		cEntries;
	PALETTEENTRY	aPalEntries[1];
};

struct gdi_emr_set_pixel_v {
	EMR		emr;
	POINTL		ptlPixel;
	COLORREF	crColor;
};

struct gdi_emr_set_text_color {
	EMR		emr;
	COLORREF	crColor;
};

struct gdi_emr_set_viewport_ext_ex {
	EMR	emr;
	SIZEL	szlExtent;
};

struct gdi_emr_set_viewport_org_ex {
	EMR	emr;
	POINTL	ptlOrigin;
};

struct gdi_emr_set_world_transform {
	EMR	emr;
	XFORM	xform;
};

struct gdi_emr_stretch_blt {
	EMR		emr;
	RECTL		rclBounds;
	LONG		xDest;
	LONG		yDest;
	LONG		cxDest;
	LONG		cyDest;
	DWORD		dwRop;
	LONG		xSrc;
	LONG		ySrc;
	XFORM		xformSrc;
	COLORREF	crBkColorSrc;
	DWORD		iUsageSrc;
	DWORD		offBmiSrc;
	DWORD		cbBmiSrc;
	DWORD		offBitsSrc;
	DWORD		cbBitsSrc;
	LONG		cxSrc;
	LONG		cySrc;
};

struct gdi_emr_stretch_di_bits {
	EMR	emr;
	RECTL	rclBounds;
	LONG	xDest;
	LONG	yDest;
	LONG	xSrc;
	LONG	ySrc;
	LONG	cxSrc;
	LONG	cySrc;
	DWORD	offBmiSrc;
	DWORD	cbBmiSrc;
	DWORD	offBitsSrc;
	DWORD	cbBitsSrc;
	DWORD	iUsageSrc;
	DWORD	dwRop;
	LONG	cxDest;
	LONG	cyDest;
};

struct gdi_emr_transparent_blt {
	EMR		emr;
	RECTL		rclBounds;
	LONG		xDest;
	LONG		yDest;
	LONG		cxDest;
	LONG		cyDest;
	DWORD		dwRop;
	LONG		xSrc;
	LONG		ySrc;
	XFORM		xformSrc;
	COLORREF	crBkColorSrc;
	DWORD		iUsageSrc;
	DWORD		offBmiSrc;
	DWORD		cbBmiSrc;
	DWORD		offBitsSrc;
	DWORD		cbBitsSrc;
	LONG		cxSrc;
	LONG		cySrc;
};

struct gdi_enh_meta_header {
	DWORD	iType;
	DWORD	nSize;
	RECTL	rclBounds;
	RECTL	rclFrame;
	DWORD	dSignature;
	DWORD	nVersion;
	DWORD	nBytes;
	DWORD	nRecords;
	WORD	nHandles;
	WORD	sReserved;
	DWORD	nDescription;
	DWORD	offDescription;
	DWORD	nPalEntries;
	SIZEL	szlDevice;
	SIZEL	szlMillimeters;
	DWORD	cbPixelFormat;
	DWORD	offPixelFormat;
	DWORD	bOpenGL;
	SIZEL	szlMicrometers;
};

struct gdi_enh_meta_record {
	DWORD	iType;
	DWORD	nSize;
	DWORD	dParm[1];
};

struct gdi_log_font_ansi {
	LONG	lfHeight;
	LONG	lfWidth;
	LONG	lfEscapement;
	LONG	lfOrientation;
	LONG	lfWeight;
	BYTE	lfItalic;
	BYTE	lfUnderline;
	BYTE	lfStrikeOut;
	BYTE	lfCharSet;
	BYTE	lfOutPrecision;
	BYTE	lfClipPrecision;
	BYTE	lfQuality;
	BYTE	lfPitchAndFamily;
	CHAR	lfFaceName[32];
};

struct gdi_log_font_utf8 {
	LONG	lfHeight;
	LONG	lfWidth;
	LONG	lfEscapement;
	LONG	lfOrientation;
	LONG	lfWeight;
	BYTE	lfItalic;
	BYTE	lfUnderline;
	BYTE	lfStrikeOut;
	BYTE	lfCharSet;
	BYTE	lfOutPrecision;
	BYTE	lfClipPrecision;
	BYTE	lfQuality;
	BYTE	lfPitchAndFamily;
	CHAR	lfFaceName[32];
};

struct gdi_enum_log_font_ansi {
	LOGFONTA	elfLogFont;
	BYTE		elfFullName[64];
	BYTE		elfStyle[32];
};

struct gdi_enum_log_font_utf8 {
	LOGFONTM	elfLogFont;
	BYTE		elfFullName[64];
	BYTE		elfStyle[32];
};

struct gdi_enum_log_font_ex_ansi {
	LOGFONTA	elfLogFont;
	BYTE		elfFullName[64];
	BYTE		elfStyle[32];
	BYTE		elfScript[32];
};

struct gdi_enum_log_font_ex_utf8 {
	LOGFONTM	elfLogFont;
	BYTE		elfFullName[64];
	BYTE		elfStyle[32];
	BYTE		elfScript[32];
};

struct gdi_enum_log_font_ex_dv_ansi {
	ENUMLOGFONTEXA	elfEnumLogfontEx;
	DESIGNVECTOR	elfDesignVector;
};

struct gdi_enum_log_font_ex_dv_utf8 {
	ENUMLOGFONTEXM	elfEnumLogfontEx;
	DESIGNVECTOR	elfDesignVector;
};

struct gdi_enum_log_font_ex_utf16 {
	LOGFONTW	elfLogFont;
	WCHAR		elfFullName[64];
	WCHAR		elfStyle[32];
	WCHAR		elfScript[32];
};

struct gdi_enum_log_font_ex_dv_utf16 {
	ENUMLOGFONTEXW	elfEnumLogfontEx;
	DESIGNVECTOR	elfDesignVector;
};

struct gdi_enum_log_font_utf16 {
	LOGFONTW	elfLogFont;
	WCHAR		elfFullName[64];
	WCHAR		elfStyle[32];
};

struct gdi_new_text_metric_ansi {
	LONG	tmHeight;
	LONG	tmAscent;
	LONG	tmDescent;
	LONG	tmInternalLeading;
	LONG	tmExternalLeading;
	LONG	tmAveCharWidth;
	LONG	tmMaxCharWidth;
	LONG	tmWeight;
	LONG	tmOverhang;
	LONG	tmDigitizedAspectX;
	LONG	tmDigitizedAspectY;
	BYTE	tmFirstChar;
	BYTE	tmLastChar;
	BYTE	tmDefaultChar;
	BYTE	tmBreakChar;
	BYTE	tmItalic;
	BYTE	tmUnderlined;
	BYTE	tmStruckOut;
	BYTE	tmPitchAndFamily;
	BYTE	tmCharSet;
	DWORD	ntmFlags;
	UINT	ntmSizeEM;
	UINT	ntmCellHeight;
	UINT	ntmAvgWidth;
};

struct gdi_new_text_metric_utf8 {
	LONG	tmHeight;
	LONG	tmAscent;
	LONG	tmDescent;
	LONG	tmInternalLeading;
	LONG	tmExternalLeading;
	LONG	tmAveCharWidth;
	LONG	tmMaxCharWidth;
	LONG	tmWeight;
	LONG	tmOverhang;
	LONG	tmDigitizedAspectX;
	LONG	tmDigitizedAspectY;
	BYTE	tmFirstChar;
	BYTE	tmLastChar;
	BYTE	tmDefaultChar;
	BYTE	tmBreakChar;
	BYTE	tmItalic;
	BYTE	tmUnderlined;
	BYTE	tmStruckOut;
	BYTE	tmPitchAndFamily;
	BYTE	tmCharSet;
	DWORD	ntmFlags;
	UINT	ntmSizeEM;
	UINT	ntmCellHeight;
	UINT	ntmAvgWidth;
};

struct gdi_new_text_metric_ex_ansi {
	NEWTEXTMETRICA	ntmTm;
	FONTSIGNATURE	ntmFontSig;
};

struct gdi_new_text_metric_ex_utf8 {
	NEWTEXTMETRICM	ntmTm;
	FONTSIGNATURE	ntmFontSig;
};

struct gdi_enum_text_metric_ansi {
	NEWTEXTMETRICEXA	etmNewTextMetricEx;
	AXESLISTA		etmAxesList;
};

struct gdi_enum_text_metric_utf8 {
	NEWTEXTMETRICEXM	etmNewTextMetricEx;
	AXESLISTM		etmAxesList;
};

struct gdi_new_text_metric_utf16 {
	LONG	tmHeight;
	LONG	tmAscent;
	LONG	tmDescent;
	LONG	tmInternalLeading;
	LONG	tmExternalLeading;
	LONG	tmAveCharWidth;
	LONG	tmMaxCharWidth;
	LONG	tmWeight;
	LONG	tmOverhang;
	LONG	tmDigitizedAspectX;
	LONG	tmDigitizedAspectY;
	WCHAR	tmFirstChar;
	WCHAR	tmLastChar;
	WCHAR	tmDefaultChar;
	WCHAR	tmBreakChar;
	BYTE	tmItalic;
	BYTE	tmUnderlined;
	BYTE	tmStruckOut;
	BYTE	tmPitchAndFamily;
	BYTE	tmCharSet;
	DWORD	ntmFlags;
	UINT	ntmSizeEM;
	UINT	ntmCellHeight;
	UINT	ntmAvgWidth;
};

struct gdi_new_text_metric_ex_utf16 {
	NEWTEXTMETRICW	ntmTm;
	FONTSIGNATURE	ntmFontSig;
};

struct gdi_enum_text_metric_utf16 {
	NEWTEXTMETRICEXW	etmNewTextMetricEx;
	AXESLISTW		etmAxesList;
};

struct gdi_ext_log_font_ansi {
	LOGFONTA	elfLogFont;
	BYTE		elfFullName[64];
	BYTE		elfStyle[32];
	DWORD		elfVersion;
	DWORD		elfStyleSize;
	DWORD		elfMatch;
	DWORD		elfReserved;
	BYTE		elfVendorId[4];
	DWORD		elfCulture;
	PANOSE		elfPanose;
};

struct gdi_ext_log_font_utf8 {
	LOGFONTM	elfLogFont;
	BYTE		elfFullName[64];
	BYTE		elfStyle[32];
	DWORD		elfVersion;
	DWORD		elfStyleSize;
	DWORD		elfMatch;
	DWORD		elfReserved;
	BYTE		elfVendorId[4];
	DWORD		elfCulture;
	PANOSE		elfPanose;
};

struct gdi_ext_log_pen {
	DWORD		elpPenStyle;
	DWORD		elpWidth;
	UINT		elpBrushStyle;
	COLORREF	elpColor;
	ULONG_PTR	elpHatch;
	DWORD		elpNumEntries;
	DWORD		elpStyleEntry[1];
};

struct gdi_fixed {
	WORD	fract;
	SHORT	value;
};

struct gdi_gcp_results_ansi {
	DWORD	lStructSize;
	LPSTR	lpOutString;
	UINT *	lpOrder;
	INT *	lpDx;
	INT *	lpCaretPos;
	LPSTR	lpClass;
	LPWSTR	lpGlyphs;
	UINT	nGlyphs;
	INT	nMaxFit;
};

struct gdi_gcp_results_utf8 {
	DWORD	lStructSize;
	LPSTR	lpOutString;
	UINT *	lpOrder;
	INT *	lpDx;
	INT *	lpCaretPos;
	LPSTR	lpClass;
	LPWSTR	lpGlyphs;
	UINT	nGlyphs;
	INT	nMaxFit;
};

struct gdi_gcp_results_utf16 {
	DWORD	lStructSize;
	LPWSTR	lpOutString;
	UINT *	lpOrder;
	INT *	lpDx;
	INT *	lpCaretPos;
	LPSTR	lpClass;
	LPWSTR	lpGlyphs;
	UINT	nGlyphs;
	INT	nMaxFit;
};

struct gdi_glyph_metrics {
	UINT	gmBlackBoxX;
	UINT	gmBlackBoxY;
	POINT	gmptGlyphOrigin;
	SHORT	gmCellIncX;
	SHORT	gmCellIncY;
};

struct gdi_point_float {
	FLOAT	x;
	FLOAT	y;
};

struct gdi_glyph_metrics_float {
	FLOAT		gmfBlackBoxX;
	FLOAT		gmfBlackBoxY;
	POINTFLOAT	gmfptGlyphOrigin;
	FLOAT		gmfCellIncX;
	FLOAT		gmfCellIncY;
};

struct gdi_wcrange {
	WCHAR	wcLow;
	USHORT	cGlyphs;
};

struct gdi_glyph_set {
	DWORD	cbThis;
	DWORD	flAccel;
	DWORD	cGlyphsSupported;
	DWORD	cRanges;
	WCRANGE	ranges[1];
};

struct gdi_gradient_rect {
	ULONG	UpperLeft;
	ULONG	LowerRight;
};

struct gdi_gradient_triangle {
	ULONG	Vertex1;
	ULONG	Vertex2;
	ULONG	Vertex3;
};

struct gdi_handle_table {
	HGDIOBJ	objectHandle[1];
};

struct gdi_kerning_pair {
	WORD	wFirst;
	WORD	wSecond;
	INT	iKernAmount;
};

struct gdi_layer_plane_descriptor {
	WORD		nSize;
	WORD		nVersion;
	DWORD		dwFlags;
	BYTE		iPixelType;
	BYTE		cColorBits;
	BYTE		cRedBits;
	BYTE		cRedShift;
	BYTE		cGreenBits;
	BYTE		cGreenShift;
	BYTE		cBlueBits;
	BYTE		cBlueShift;
	BYTE		cAlphaBits;
	BYTE		cAlphaShift;
	BYTE		cAccumBits;
	BYTE		cAccumRedBits;
	BYTE		cAccumGreenBits;
	BYTE		cAccumBlueBits;
	BYTE		cAccumAlphaBits;
	BYTE		cDepthBits;
	BYTE		cStencilBits;
	BYTE		cAuxBuffers;
	BYTE		iLayerPlane;
	BYTE		bReserved;
	COLORREF	crTransparent;
};

struct gdi_locale_signature {
	DWORD	lsUsb[4];
	DWORD	lsCsbDefault[2];
	DWORD	lsCsbSupported[2];
};

struct gdi_log_brush {
	UINT		lbStyle;
	COLORREF	lbColor;
	ULONG_PTR	lbHatch;
};

struct gdi_mat_2 {
	FIXED	eM11;
	FIXED	eM12;
	FIXED	eM21;
	FIXED	eM22;
};

struct gdi_meta_file_pict {
	LONG		mm;
	LONG		xExt;
	LONG		yExt;
	HMETAFILE	hMF;
};

struct gdi_meta_header {
	WORD	mtType;
	WORD	mtHeaderSize;
	WORD	mtVersion;
	DWORD	mtSize;
	WORD	mtNoObjects;
	DWORD	mtMaxRecord;
	WORD	mtNoParameters;
};

struct gdi_meta_record {
	DWORD	rdSize;
	WORD	rdFunction;
	WORD	rdParm[1];
};

struct gdi_text_metric_ansi {
	LONG	tmHeight;
	LONG	tmAscent;
	LONG	tmDescent;
	LONG	tmInternalLeading;
	LONG	tmExternalLeading;
	LONG	tmAveCharWidth;
	LONG	tmMaxCharWidth;
	LONG	tmWeight;
	LONG	tmOverhang;
	LONG	tmDigitizedAspectX;
	LONG	tmDigitizedAspectY;
	BYTE	tmFirstChar;
	BYTE	tmLastChar;
	BYTE	tmDefaultChar;
	BYTE	tmBreakChar;
	BYTE	tmItalic;
	BYTE	tmUnderlined;
	BYTE	tmStruckOut;
	BYTE	tmPitchAndFamily;
	BYTE	tmCharSet;
};

struct gdi_text_metric_utf8 {
	LONG	tmHeight;
	LONG	tmAscent;
	LONG	tmDescent;
	LONG	tmInternalLeading;
	LONG	tmExternalLeading;
	LONG	tmAveCharWidth;
	LONG	tmMaxCharWidth;
	LONG	tmWeight;
	LONG	tmOverhang;
	LONG	tmDigitizedAspectX;
	LONG	tmDigitizedAspectY;
	BYTE	tmFirstChar;
	BYTE	tmLastChar;
	BYTE	tmDefaultChar;
	BYTE	tmBreakChar;
	BYTE	tmItalic;
	BYTE	tmUnderlined;
	BYTE	tmStruckOut;
	BYTE	tmPitchAndFamily;
	BYTE	tmCharSet;
};

struct gdi_outline_text_metric_ansi {
	UINT		otmSize;
	TEXTMETRICA	otmTextMetrics;
	BYTE		otmFiller;
	PANOSE		otmPanoseNumber;
	UINT		otmfsSelection;
	UINT		otmfsType;
	INT		otmsCharSlopeRise;
	INT		otmsCharSlopeRun;
	INT		otmItalicAngle;
	UINT		otmEMSquare;
	INT		otmAscent;
	INT		otmDescent;
	UINT		otmLineGap;
	UINT		otmsCapEmHeight;
	UINT		otmsXHeight;
	RECT		otmrcFontBox;
	INT		otmMacAscent;
	INT		otmMacDescent;
	UINT		otmMacLineGap;
	UINT		otmusMinimumPPEM;
	POINT		otmptSubscriptSize;
	POINT		otmptSubscriptOffset;
	POINT		otmptSuperscriptSize;
	POINT		otmptSuperscriptOffset;
	UINT		otmsStrikeoutSize;
	INT		otmsStrikeoutPosition;
	INT		otmsUnderscoreSize;
	INT		otmsUnderscorePosition;
	PSTR		otmpFamilyName;
	PSTR		otmpFaceName;
	PSTR		otmpStyleName;
	PSTR		otmpFullName;
};

struct gdi_outline_text_metric_utf8 {
	UINT		otmSize;
	TEXTMETRICM	otmTextMetrics;
	BYTE		otmFiller;
	PANOSE		otmPanoseNumber;
	UINT		otmfsSelection;
	UINT		otmfsType;
	INT		otmsCharSlopeRise;
	INT		otmsCharSlopeRun;
	INT		otmItalicAngle;
	UINT		otmEMSquare;
	INT		otmAscent;
	INT		otmDescent;
	UINT		otmLineGap;
	UINT		otmsCapEmHeight;
	UINT		otmsXHeight;
	RECT		otmrcFontBox;
	INT		otmMacAscent;
	INT		otmMacDescent;
	UINT		otmMacLineGap;
	UINT		otmusMinimumPPEM;
	POINT		otmptSubscriptSize;
	POINT		otmptSubscriptOffset;
	POINT		otmptSuperscriptSize;
	POINT		otmptSuperscriptOffset;
	UINT		otmsStrikeoutSize;
	INT		otmsStrikeoutPosition;
	INT		otmsUnderscoreSize;
	INT		otmsUnderscorePosition;
	PSTR		otmpFamilyName;
	PSTR		otmpFaceName;
	PSTR		otmpStyleName;
	PSTR		otmpFullName;
};

struct gdi_text_metric_utf16 {
	LONG	tmHeight;
	LONG	tmAscent;
	LONG	tmDescent;
	LONG	tmInternalLeading;
	LONG	tmExternalLeading;
	LONG	tmAveCharWidth;
	LONG	tmMaxCharWidth;
	LONG	tmWeight;
	LONG	tmOverhang;
	LONG	tmDigitizedAspectX;
	LONG	tmDigitizedAspectY;
	WCHAR	tmFirstChar;
	WCHAR	tmLastChar;
	WCHAR	tmDefaultChar;
	WCHAR	tmBreakChar;
	BYTE	tmItalic;
	BYTE	tmUnderlined;
	BYTE	tmStruckOut;
	BYTE	tmPitchAndFamily;
	BYTE	tmCharSet;
};

struct gdi_outline_text_metric_utf16 {
	UINT		otmSize;
	TEXTMETRICW	otmTextMetrics;
	BYTE		otmFiller;
	PANOSE		otmPanoseNumber;
	UINT		otmfsSelection;
	UINT		otmfsType;
	INT		otmsCharSlopeRise;
	INT		otmsCharSlopeRun;
	INT		otmItalicAngle;
	UINT		otmEMSquare;
	INT		otmAscent;
	INT		otmDescent;
	UINT		otmLineGap;
	UINT		otmsCapEmHeight;
	UINT		otmsXHeight;
	RECT		otmrcFontBox;
	INT		otmMacAscent;
	INT		otmMacDescent;
	UINT		otmMacLineGap;
	UINT		otmusMinimumPPEM;
	POINT		otmptSubscriptSize;
	POINT		otmptSubscriptOffset;
	POINT		otmptSuperscriptSize;
	POINT		otmptSuperscriptOffset;
	UINT		otmsStrikeoutSize;
	INT		otmsStrikeoutPosition;
	INT		otmsUnderscoreSize;
	INT		otmsUnderscorePosition;
	PSTR		otmpFamilyName;
	PSTR		otmpFaceName;
	PSTR		otmpStyleName;
	PSTR		otmpFullName;
};

struct gdi_pel_array {
	LONG	paXCount;
	LONG	paYCount;
	LONG	paXExt;
	LONG	paYExt;
	BYTE	paRGBs;
};

struct gdi_point_fx {
	FIXED	x;
	FIXED	y;
};

struct gdi_poly_text_ansi {
	INT		x;
	INT		y;
	UINT		n;
	LPCSTR		lpstr;
	UINT		uiFlags;
	RECT		rcl;
	INT *		pdx;
};

struct gdi_poly_text_utf8 {
	INT		x;
	INT		y;
	UINT		n;
	LPCMBSTR	lpstr;
	UINT		uiFlags;
	RECT		rcl;
	INT *		pdx;
};

struct gdi_poly_text_utf16 {
	INT	x;
	INT	y;
	UINT	n;
	LPCWSTR	lpstr;
	UINT	uiFlags;
	RECT	rcl;
	INT *	pdx;
};

struct gdi_ps_feature_cust_paper {
	LONG	lOrientation;
	LONG	lWidth;
	LONG	lHeight;
	LONG	lWidthOffset;
	LONG	lHeightOffset;
};

struct gdi_ps_feature_output {
	BOOL	bPageIndependent;
	BOOL	bSetPageDevice;
};

struct gdi_ps_inject_dat_ansi {
	DWORD	DataBytes;
	WORD	InjectionPoint;
	WORD	PageNumber;
};

struct gdi_ps_inject_dat_utf8 {
	DWORD	DataBytes;
	WORD	InjectionPoint;
	WORD	PageNumber;
};

struct gdi_rasterizer_status {
	SHORT	nSize;
	SHORT	wFlags;
	SHORT	nLanguageID;
};

struct gdi_rgn_data_header {
	DWORD	dwSize;
	DWORD	iType;
	DWORD	nCount;
	DWORD	nRgnSize;
	RECT	rcBound;
};

struct gdi_rgn_dat_ansi {
	RGNDATAHEADER	rdh;
	CHAR		Buffer[1];
};

struct gdi_rgn_dat_utf8 {
	RGNDATAHEADER	rdh;
	CHAR		Buffer[1];
};

struct gdi_tt_poly_curve {
	WORD	wType;
	WORD	cpfx;
	POINTFX	apfx[1];
};

struct gdi_tt_polygon_header {
	DWORD	cb;
	DWORD	dwType;
	POINTFX	pfxStart;
};

struct gdi_wgl_swap {
	HDC	hdc;
	UINT	uiFlags;
};




#ifdef WINAPI_ANSI_DEFAULT
typedef union  gdi_aa__ansi			__AA;
typedef struct gdi_axes_list_ansi		AXESLIST;
typedef struct gdi_axis_info_ansi		AXISINFO;
typedef struct gdi_device_mode_ansi		DEVMODE;
typedef struct gdi_display_device_ansi		DISPLAY_DEVICE;
typedef struct gdi_doc_info_ansi		DOCINFO;
typedef struct gdi_emr_set_icm_pr_ansi		EMRSETICMPROFILE;
typedef struct gdi_enum_log_font_ansi		ENUMLOGFONT;
typedef struct gdi_enum_log_font_ex_ansi	ENUMLOGFONTEX;
typedef struct gdi_enum_log_font_ex_dv_ansi	ENUMLOGFONTEXDV;
typedef struct gdi_enum_text_metric_ansi	ENUMTEXTMETRIC;
typedef struct gdi_ext_log_font_ansi		EXTLOGFONT;
typedef struct gdi_gcp_results_ansi		GCP_RESULTS;
typedef struct gdi_log_color_space_ansi		LOGCOLORSPACE;
typedef struct gdi_log_font_ansi		LOGFONT;
typedef struct gdi_new_text_metric_ansi		NEWTEXTMETRIC;
typedef struct gdi_new_text_metric_ex_ansi	NEWTEXTMETRICEX;
typedef struct gdi_outline_text_metric_ansi	OUTLINETEXTMETRIC;
typedef struct gdi_poly_text_ansi		POLYTEXT;
typedef struct gdi_text_metric_ansi		TEXTMETRIC;
#endif




#ifdef WINAPI_UTF8_DEFAULT
typedef union  gdi_aa__utf8			__AA;
typedef struct gdi_axes_list_utf8		AXESLIST;
typedef struct gdi_axis_info_utf8		AXISINFO;
typedef struct gdi_device_mode_utf8		DEVMODE;
typedef struct gdi_display_device_utf8		DISPLAY_DEVICE;
typedef struct gdi_doc_info_utf8		DOCINFO;
typedef struct gdi_emr_set_icm_pr_utf8		EMRSETICMPROFILE;
typedef struct gdi_enum_log_font_utf8		ENUMLOGFONT;
typedef struct gdi_enum_log_font_ex_utf8	ENUMLOGFONTEX;
typedef struct gdi_enum_log_font_ex_dv_utf8	ENUMLOGFONTEXDV;
typedef struct gdi_enum_text_metric_utf8	ENUMTEXTMETRIC;
typedef struct gdi_ext_log_font_utf8		EXTLOGFONT;
typedef struct gdi_gcp_results_utf8		GCP_RESULTS;
typedef struct gdi_log_color_space_utf8		LOGCOLORSPACE;
typedef struct gdi_log_font_utf8		LOGFONT;
typedef struct gdi_new_text_metric_utf8		NEWTEXTMETRIC;
typedef struct gdi_new_text_metric_ex_utf8	NEWTEXTMETRICEX;
typedef struct gdi_outline_text_metric_utf8	OUTLINETEXTMETRIC;
typedef struct gdi_poly_text_utf8		POLYTEXT;
typedef struct gdi_text_metric_utf8		TEXTMETRIC;
#endif




#ifdef WINAPI_UTF16_DEFAULT
typedef union  gdi_aa__utf16			__AA;
typedef struct gdi_axes_list_utf16		AXESLIST;
typedef struct gdi_axis_info_utf16		AXISINFO;
typedef struct gdi_device_mode_utf16		DEVMODE;
typedef struct gdi_display_device_utf16		DISPLAY_DEVICE;
typedef struct gdi_doc_info_utf16		DOCINFO;
typedef struct gdi_emr_set_icm_pr_utf16		EMRSETICMPROFILE;
typedef struct gdi_enum_log_font_utf16		ENUMLOGFONT;
typedef struct gdi_enum_log_font_ex_utf16	ENUMLOGFONTEX;
typedef struct gdi_enum_log_font_ex_dv_utf16	ENUMLOGFONTEXDV;
typedef struct gdi_enum_text_metric_utf16	ENUMTEXTMETRIC;
typedef struct gdi_ext_log_font_utf16		EXTLOGFONT;
typedef struct gdi_gcp_results_utf16		GCP_RESULTS;
typedef struct gdi_log_color_space_utf16	LOGCOLORSPACE;
typedef struct gdi_log_font_utf16		LOGFONT;
typedef struct gdi_new_text_metric_utf16	NEWTEXTMETRIC;
typedef struct gdi_new_text_metric_ex_utf16	NEWTEXTMETRICEX;
typedef struct gdi_outline_text_metric_utf16	OUTLINETEXTMETRIC;
typedef struct gdi_poly_text_utf16		POLYTEXT;
typedef struct gdi_text_metric_utf16		TEXTMETRIC;
#endif



typedef int FONTENUMPROCW(const LOGFONTW *, const TEXTMETRICW *, DWORD, LPARAM);

typedef INT __stdcall w32api_gdi_abort_doc(
	HDC);

typedef BOOL __stdcall w32api_gdi_abort_path(
	HDC);

typedef HANDLE __stdcall w32api_gdi_add_font_mem_resource_ex(
	PVOID,
	DWORD,
	PVOID,
	DWORD *);

typedef INT __stdcall w32api_gdi_add_font_resource_ansi(
	LPCSTR);

typedef INT __stdcall w32api_gdi_add_font_resource_utf8(
	LPCMBSTR);

typedef INT __stdcall w32api_gdi_add_font_resource_utf16(
	LPCWSTR);

typedef INT __stdcall w32api_gdi_add_font_resource_ex_ansi(
	LPCSTR,
	DWORD,
	PVOID);

typedef INT __stdcall w32api_gdi_add_font_resource_ex_utf8(
	LPCMBSTR,
	DWORD,
	PVOID);

typedef INT __stdcall w32api_gdi_add_font_resource_ex_utf16(
	LPCWSTR,
	DWORD,
	PVOID);

typedef BOOL __stdcall w32api_gdi_alpha_blend(
	HDC,
	INT,
	INT,
	INT,
	INT,
	HDC,
	INT,
	INT,
	INT,
	INT,
	BLENDFUNCTION);

typedef BOOL __stdcall w32api_gdi_alpha_blend(
	HDC,
	INT,
	INT,
	INT,
	INT,
	HDC,
	INT,
	INT,
	INT,
	INT,
	BLENDFUNCTION);

typedef BOOL __stdcall w32api_gdi_angle_arc(
	HDC,
	INT,
	INT,
	DWORD,
	FLOAT,
	FLOAT);

typedef BOOL __stdcall w32api_gdi_animate_palette(
	HPALETTE,
	UINT,
	UINT,
	PALETTEENTRY *);

typedef BOOL __stdcall w32api_gdi_arc(
	HDC,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT);

typedef BOOL __stdcall w32api_gdi_arc_to(
	HDC,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT);

typedef BOOL __stdcall w32api_gdi_begin_path(
	HDC);

typedef BOOL __stdcall w32api_gdi_bit_blt(
	HDC,
	INT,
	INT,
	INT,
	INT,
	HDC,
	INT,
	INT,
	DWORD);

typedef BOOL __stdcall w32api_gdi_cancel_dc(
	HDC);

typedef BOOL __stdcall w32api_gdi_check_colors_in_gamut(
	HDC,
	LPRGBTRIPLE,
	LPVOID,
	DWORD);

typedef INT __stdcall w32api_gdi_choose_pixel_format(
	HDC,
	PIXELFORMATDESCRIPTOR *);

typedef BOOL __stdcall w32api_gdi_chord(
	HDC,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT);

typedef HENHMETAFILE __stdcall w32api_gdi_close_enh_meta_file(
	HDC);

typedef BOOL __stdcall w32api_gdi_close_figure(
	HDC);

typedef HMETAFILE __stdcall w32api_gdi_close_meta_file(
	HDC);

typedef BOOL __stdcall w32api_gdi_color_correct_palette(
	HDC,
	HPALETTE,
	DWORD,
	DWORD);

typedef BOOL __stdcall w32api_gdi_color_match_to_target(
	HDC,
	HDC,
	DWORD);

typedef INT __stdcall w32api_gdi_combine_rgn(
	HRGN,
	HRGN,
	HRGN,
	INT);

typedef BOOL __stdcall w32api_gdi_combine_transform(
	LPXFORM,
	XFORM *,
	XFORM *);

typedef BOOL __stdcall w32api_gdi_comment(
	HDC,
	UINT,
	BYTE *);

typedef HENHMETAFILE __stdcall w32api_gdi_copy_enh_meta_file_ansi(
	HENHMETAFILE,
	LPCSTR);

typedef HENHMETAFILE __stdcall w32api_gdi_copy_enh_meta_file_utf8(
	HENHMETAFILE,
	LPCMBSTR);

typedef HENHMETAFILE __stdcall w32api_gdi_copy_enh_meta_file_utf16(
	HENHMETAFILE,
	LPCWSTR);

typedef HMETAFILE __stdcall w32api_gdi_copy_meta_file_ansi(
	HMETAFILE,
	LPCSTR);

typedef HMETAFILE __stdcall w32api_gdi_copy_meta_file_utf8(
	HMETAFILE,
	LPCMBSTR);

typedef HMETAFILE __stdcall w32api_gdi_copy_meta_file_utf16(
	HMETAFILE,
	LPCWSTR);

typedef HBITMAP __stdcall w32api_gdi_create_bitmap(
	INT,
	INT,
	UINT,
	UINT,
	void *);

typedef HBITMAP __stdcall w32api_gdi_create_bitmap_indirect(
	BITMAP *);

typedef HBRUSH __stdcall w32api_gdi_create_brush_indirect(
	LOGBRUSH *);

typedef HCOLORSPACE __stdcall w32api_gdi_create_color_space_ansi(
	LPLOGCOLORSPACEA);

typedef HCOLORSPACE __stdcall w32api_gdi_create_color_space_utf8(
	LPLOGCOLORSPACEA);

typedef HCOLORSPACE __stdcall w32api_gdi_create_color_space_utf16(
	LPLOGCOLORSPACEW);

typedef HBITMAP __stdcall w32api_gdi_create_compatible_bitmap(
	HDC,
	INT,
	INT);

typedef HDC __stdcall w32api_gdi_create_compatible_dc(
	HDC);

typedef HDC __stdcall w32api_gdi_create_dc_ansi(
	LPCSTR,
	LPCSTR,
	LPCSTR,
	DEVMODEA *);

typedef HDC __stdcall w32api_gdi_create_dc_utf8(
	LPCMBSTR,
	LPCMBSTR,
	LPCMBSTR,
	DEVMODEA *);

typedef HDC __stdcall w32api_gdi_create_dc_utf16(
	LPCWSTR,
	LPCWSTR,
	LPCWSTR,
	DEVMODEW *);

typedef HBITMAP __stdcall w32api_gdi_create_di_bitmap(
	HDC,
	BITMAPINFOHEADER *,
	DWORD,
	void *,
	BITMAPINFO *,
	UINT);

typedef HBRUSH __stdcall w32api_gdi_create_dib_pattern_brush(
	HGLOBAL,
	UINT);

typedef HBRUSH __stdcall w32api_gdi_create_dib_pattern_brush_pt(
	void *,
	UINT);

typedef HBITMAP __stdcall w32api_gdi_create_dib_section(
	HDC,
	BITMAPINFO *,
	UINT,
	void * *,
	HANDLE,
	DWORD);

typedef HBITMAP __stdcall w32api_gdi_create_discardable_bitmap(
	HDC,
	INT,
	INT);

typedef HRGN __stdcall w32api_gdi_create_elliptic_rgn(
	INT,
	INT,
	INT,
	INT);

typedef HRGN __stdcall w32api_gdi_create_elliptic_rgn_indirect(
	RECT *);

typedef HDC __stdcall w32api_gdi_create_enh_meta_file_ansi(
	HDC,
	LPCSTR,
	RECT *,
	LPCSTR);

typedef HDC __stdcall w32api_gdi_create_enh_meta_file_utf8(
	HDC,
	LPCMBSTR,
	RECT *,
	LPCMBSTR);

typedef HDC __stdcall w32api_gdi_create_enh_meta_file_utf16(
	HDC,
	LPCWSTR,
	RECT *,
	LPCWSTR);

typedef HFONT __stdcall w32api_gdi_create_font_ansi(
	INT,
	INT,
	INT,
	INT,
	INT,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	LPCSTR);

typedef HFONT __stdcall w32api_gdi_create_font_utf8(
	INT,
	INT,
	INT,
	INT,
	INT,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	LPCMBSTR);

typedef HFONT __stdcall w32api_gdi_create_font_utf16(
	INT,
	INT,
	INT,
	INT,
	INT,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	DWORD,
	LPCWSTR);

typedef HFONT __stdcall w32api_gdi_create_font_indirect_ansi(
	LOGFONTA *);

typedef HFONT __stdcall w32api_gdi_create_font_indirect_utf8(
	LOGFONTA *);

typedef HFONT __stdcall w32api_gdi_create_font_indirect_utf16(
	LOGFONTW *);

typedef HFONT __stdcall w32api_gdi_create_font_indirect_ex_ansi(
	ENUMLOGFONTEXDVA *);

typedef HFONT __stdcall w32api_gdi_create_font_indirect_ex_utf8(
	ENUMLOGFONTEXDVA *);

typedef HFONT __stdcall w32api_gdi_create_font_indirect_ex_utf16(
	ENUMLOGFONTEXDVW *);

typedef HPALETTE __stdcall w32api_gdi_create_halftone_palette(
	HDC);

typedef HBRUSH __stdcall w32api_gdi_create_hatch_brush(
	INT,
	COLORREF);

typedef HDC __stdcall w32api_gdi_create_ic_ansi(
	LPCSTR,
	LPCSTR,
	LPCSTR,
	DEVMODEA *);

typedef HDC __stdcall w32api_gdi_create_ic_utf8(
	LPCMBSTR,
	LPCMBSTR,
	LPCMBSTR,
	DEVMODEA *);

typedef HDC __stdcall w32api_gdi_create_ic_utf16(
	LPCWSTR,
	LPCWSTR,
	LPCWSTR,
	DEVMODEW *);

typedef HDC __stdcall w32api_gdi_create_meta_file_ansi(
	LPCSTR);

typedef HDC __stdcall w32api_gdi_create_meta_file_utf8(
	LPCMBSTR);

typedef HDC __stdcall w32api_gdi_create_meta_file_utf16(
	LPCWSTR);

typedef HPALETTE __stdcall w32api_gdi_create_palette(
	LOGPALETTE *);

typedef HBRUSH __stdcall w32api_gdi_create_pattern_brush(
	HBITMAP);

typedef HPEN __stdcall w32api_gdi_create_pen(
	INT,
	INT,
	COLORREF);

typedef HPEN __stdcall w32api_gdi_create_pen_indirect(
	LOGPEN *);

typedef HRGN __stdcall w32api_gdi_create_poly_polygon_rgn(
	POINT *,
	INT *,
	INT,
	INT);

typedef HRGN __stdcall w32api_gdi_create_polygon_rgn(
	POINT *,
	INT,
	INT);

typedef HRGN __stdcall w32api_gdi_create_rect_rgn(
	INT,
	INT,
	INT,
	INT);

typedef HRGN __stdcall w32api_gdi_create_rect_rgn_indirect(
	RECT *);

typedef HRGN __stdcall w32api_gdi_create_round_rect_rgn(
	INT,
	INT,
	INT,
	INT,
	INT,
	INT);

typedef BOOL __stdcall w32api_gdi_create_scalable_font_resource_ansi(
	DWORD,
	LPCSTR,
	LPCSTR,
	LPCSTR);

typedef BOOL __stdcall w32api_gdi_create_scalable_font_resource_utf8(
	DWORD,
	LPCMBSTR,
	LPCMBSTR,
	LPCMBSTR);

typedef BOOL __stdcall w32api_gdi_create_scalable_font_resource_utf16(
	DWORD,
	LPCWSTR,
	LPCWSTR,
	LPCWSTR);

typedef HBRUSH __stdcall w32api_gdi_create_solid_brush(
	COLORREF);

typedef BOOL __stdcall w32api_gdi_d_pto_lp(
	HDC,
	LPPOINT,
	INT);

typedef BOOL __stdcall w32api_gdi_delete_color_space(
	HCOLORSPACE);

typedef BOOL __stdcall w32api_gdi_delete_dc(
	HDC);

typedef BOOL __stdcall w32api_gdi_delete_enh_meta_file(
	HENHMETAFILE);

typedef BOOL __stdcall w32api_gdi_delete_meta_file(
	HMETAFILE);

typedef BOOL __stdcall w32api_gdi_delete_object(
	HGDIOBJ);

typedef INT __stdcall w32api_gdi_describe_pixel_format(
	HDC,
	INT,
	UINT,
	LPPIXELFORMATDESCRIPTOR);

typedef INT __stdcall w32api_gdi_device_capabilities_ansi(
	LPCSTR,
	LPCSTR,
	WORD,
	LPSTR,
	DEVMODEA *);

typedef INT __stdcall w32api_gdi_device_capabilities_utf8(
	LPCMBSTR,
	LPCMBSTR,
	WORD,
	LPSTR,
	DEVMODEA *);

typedef INT __stdcall w32api_gdi_device_capabilities_utf16(
	LPCWSTR,
	LPCWSTR,
	WORD,
	LPWSTR,
	DEVMODEW *);

typedef INT __stdcall w32api_gdi_draw_escape(
	HDC,
	INT,
	INT,
	LPCSTR);

typedef BOOL __stdcall w32api_gdi_ellipse(
	HDC,
	INT,
	INT,
	INT,
	INT);

typedef INT __stdcall w32api_gdi_end_doc(
	HDC);

typedef INT __stdcall w32api_gdi_end_page(
	HDC);

typedef BOOL __stdcall w32api_gdi_end_path(
	HDC);

typedef BOOL __stdcall w32api_gdi_enum_enh_meta_file(
	HDC,
	HENHMETAFILE,
	ENHMFENUMPROC,
	LPVOID,
	RECT *);

typedef INT __stdcall w32api_gdi_enum_font_families_ansi(
	HDC,
	LPCSTR,
	FONTENUMPROCA,
	LPARAM);

typedef INT __stdcall w32api_gdi_enum_font_families_utf8(
	HDC,
	LPCMBSTR,
	FONTENUMPROCA,
	LPARAM);

typedef INT __stdcall w32api_gdi_enum_font_families_utf16(
	HDC,
	LPCWSTR,
	FONTENUMPROCW,
	LPARAM);

typedef INT __stdcall w32api_gdi_enum_font_families_ex_ansi(
	HDC,
	LPLOGFONTA,
	FONTENUMPROCA,
	LPARAM,
	DWORD);

typedef INT __stdcall w32api_gdi_enum_font_families_ex_utf8(
	HDC,
	LPLOGFONTA,
	FONTENUMPROCA,
	LPARAM,
	DWORD);

typedef INT __stdcall w32api_gdi_enum_font_families_ex_utf16(
	HDC,
	LPLOGFONTW,
	FONTENUMPROCW,
	LPARAM,
	DWORD);

typedef INT __stdcall w32api_gdi_enum_fonts_ansi(
	HDC,
	LPCSTR,
	FONTENUMPROCA,
	LPARAM);

typedef INT __stdcall w32api_gdi_enum_fonts_utf8(
	HDC,
	LPCMBSTR,
	FONTENUMPROCA,
	LPARAM);

typedef INT __stdcall w32api_gdi_enum_fonts_utf16(
	HDC,
	LPCWSTR,
	FONTENUMPROCW,
	LPARAM);

typedef INT __stdcall w32api_gdi_enum_icm_profiles_ansi(
	HDC,
	ICMENUMPROCA,
	LPARAM);

typedef INT __stdcall w32api_gdi_enum_icm_profiles_utf8(
	HDC,
	ICMENUMPROCA,
	LPARAM);

typedef INT __stdcall w32api_gdi_enum_icm_profiles_utf16(
	HDC,
	ICMENUMPROCW,
	LPARAM);

typedef BOOL __stdcall w32api_gdi_enum_meta_file(
	HDC,
	HMETAFILE,
	MFENUMPROC,
	LPARAM);

typedef INT __stdcall w32api_gdi_enum_objects(
	HDC,
	INT,
	GOBJENUMPROC,
	LPVOID);

typedef BOOL __stdcall w32api_gdi_equal_rgn(
	HRGN,
	HRGN);

typedef INT __stdcall w32api_gdi_escape(
	HDC,
	INT,
	INT,
	LPCSTR,
	LPVOID);

typedef INT __stdcall w32api_gdi_exclude_clip_rect(
	HDC,
	INT,
	INT,
	INT,
	INT);

typedef HPEN __stdcall w32api_gdi_ext_create_pen(
	DWORD,
	DWORD,
	LOGBRUSH *,
	DWORD,
	DWORD *);

typedef HRGN __stdcall w32api_gdi_ext_create_region(
	XFORM *,
	DWORD,
	RGNDATA *);

typedef INT __stdcall w32api_gdi_ext_escape(
	HDC,
	INT,
	INT,
	LPCSTR,
	INT,
	LPSTR);

typedef BOOL __stdcall w32api_gdi_ext_flood_fill(
	HDC,
	INT,
	INT,
	COLORREF,
	UINT);

typedef INT __stdcall w32api_gdi_ext_select_clip_rgn(
	HDC,
	HRGN,
	INT);

typedef BOOL __stdcall w32api_gdi_ext_text_out_ansi(
	HDC,
	INT,
	INT,
	UINT,
	RECT *,
	LPCSTR,
	UINT,
	INT *);

typedef BOOL __stdcall w32api_gdi_ext_text_out_utf8(
	HDC,
	INT,
	INT,
	UINT,
	RECT *,
	LPCMBSTR,
	UINT,
	INT *);

typedef BOOL __stdcall w32api_gdi_ext_text_out_utf16(
	HDC,
	INT,
	INT,
	UINT,
	RECT *,
	LPCWSTR,
	UINT,
	INT *);

typedef BOOL __stdcall w32api_gdi_fill_path(
	HDC);

typedef BOOL __stdcall w32api_gdi_fill_rgn(
	HDC,
	HRGN,
	HBRUSH);

typedef BOOL __stdcall w32api_gdi_fix_brush_org_ex(
	HDC,
	INT,
	INT,
	LPPOINT);

typedef BOOL __stdcall w32api_gdi_flatten_path(
	HDC);

typedef BOOL __stdcall w32api_gdi_flood_fill(
	HDC,
	INT,
	INT,
	COLORREF);

typedef BOOL __stdcall w32api_gdi_flush(void);

typedef BOOL __stdcall w32api_gdi_frame_rgn(
	HDC,
	HRGN,
	HBRUSH,
	INT,
	INT);

typedef INT __stdcall w32api_gdi_get_arc_direction(
	HDC);

typedef BOOL __stdcall w32api_gdi_get_aspect_ratio_filter_ex(
	HDC,
	LPSIZE);

typedef DWORD __stdcall w32api_gdi_get_batch_limit(void);

typedef LONG __stdcall w32api_gdi_get_bitmap_bits(
	HBITMAP,
	LONG,
	LPVOID);

typedef BOOL __stdcall w32api_gdi_get_bitmap_dimension_ex(
	HBITMAP,
	LPSIZE);

typedef COLORREF __stdcall w32api_gdi_get_bk_color(
	HDC);

typedef INT __stdcall w32api_gdi_get_bk_mode(
	HDC);

typedef UINT __stdcall w32api_gdi_get_bounds_rect(
	HDC,
	LPRECT,
	UINT);

typedef BOOL __stdcall w32api_gdi_get_brush_org_ex(
	HDC,
	LPPOINT);

typedef BOOL __stdcall w32api_gdi_get_char_abc_widths_ansi(
	HDC,
	UINT,
	UINT,
	LPABC);

typedef BOOL __stdcall w32api_gdi_get_char_abc_widths_utf8(
	HDC,
	UINT,
	UINT,
	LPABC);

typedef BOOL __stdcall w32api_gdi_get_char_abc_widths_utf16(
	HDC,
	UINT,
	UINT,
	LPABC);

typedef BOOL __stdcall w32api_gdi_get_char_abc_widths_float_ansi(
	HDC,
	UINT,
	UINT,
	LPABCFLOAT);

typedef BOOL __stdcall w32api_gdi_get_char_abc_widths_float_utf8(
	HDC,
	UINT,
	UINT,
	LPABCFLOAT);

typedef BOOL __stdcall w32api_gdi_get_char_abc_widths_float_utf16(
	HDC,
	UINT,
	UINT,
	LPABCFLOAT);

typedef BOOL __stdcall w32api_gdi_get_char_abc_widths_i(
	HDC,
	UINT,
	UINT,
	LPWORD,
	LPABC);

typedef BOOL __stdcall w32api_gdi_get_char_width_ansi(
	HDC,
	UINT,
	UINT,
	LPINT);

typedef BOOL __stdcall w32api_gdi_get_char_width_utf8(
	HDC,
	UINT,
	UINT,
	LPINT);

typedef BOOL __stdcall w32api_gdi_get_char_width_utf16(
	HDC,
	UINT,
	UINT,
	LPINT);

typedef BOOL __stdcall w32api_gdi_get_char_width32_ansi(
	HDC,
	UINT,
	UINT,
	LPINT);

typedef BOOL __stdcall w32api_gdi_get_char_width32_utf8(
	HDC,
	UINT,
	UINT,
	LPINT);

typedef BOOL __stdcall w32api_gdi_get_char_width32_utf16(
	HDC,
	UINT,
	UINT,
	LPINT);

typedef BOOL __stdcall w32api_gdi_get_char_width_float_ansi(
	HDC,
	UINT,
	UINT,
	PFLOAT);

typedef BOOL __stdcall w32api_gdi_get_char_width_float_utf8(
	HDC,
	UINT,
	UINT,
	PFLOAT);

typedef BOOL __stdcall w32api_gdi_get_char_width_float_utf16(
	HDC,
	UINT,
	UINT,
	PFLOAT);

typedef BOOL __stdcall w32api_gdi_get_char_width_i(
	HDC,
	UINT,
	UINT,
	LPWORD,
	LPINT);

typedef DWORD __stdcall w32api_gdi_get_character_placement_ansi(
	HDC,
	LPCSTR,
	INT,
	INT,
	LPGCP_RESULTSA,
	DWORD);

typedef DWORD __stdcall w32api_gdi_get_character_placement_utf8(
	HDC,
	LPCMBSTR,
	INT,
	INT,
	LPGCP_RESULTSA,
	DWORD);

typedef DWORD __stdcall w32api_gdi_get_character_placement_utf16(
	HDC,
	LPCWSTR,
	INT,
	INT,
	LPGCP_RESULTSW,
	DWORD);

typedef INT __stdcall w32api_gdi_get_clip_box(
	HDC,
	LPRECT);

typedef INT __stdcall w32api_gdi_get_clip_rgn(
	HDC,
	HRGN);

typedef BOOL __stdcall w32api_gdi_get_color_adjustment(
	HDC,
	LPCOLORADJUSTMENT);

typedef HCOLORSPACE __stdcall w32api_gdi_get_color_space(
	HDC);

typedef HGDIOBJ __stdcall w32api_gdi_get_current_object(
	HDC,
	UINT);

typedef BOOL __stdcall w32api_gdi_get_current_position_ex(
	HDC,
	LPPOINT);

typedef COLORREF __stdcall w32api_gdi_get_dc_brush_color(
	HDC);

typedef BOOL __stdcall w32api_gdi_get_dc_org_ex(
	HDC,
	LPPOINT);

typedef COLORREF __stdcall w32api_gdi_get_dc_pen_color(
	HDC);

typedef INT __stdcall w32api_gdi_get_device_caps(
	HDC,
	INT);

typedef BOOL __stdcall w32api_gdi_get_device_gamma_ramp(
	HDC,
	LPVOID);

typedef INT __stdcall w32api_gdi_get_di_bits(
	HDC,
	HBITMAP,
	UINT,
	UINT,
	LPVOID,
	LPBITMAPINFO,
	UINT);

typedef UINT __stdcall w32api_gdi_get_dib_color_table(
	HDC,
	UINT,
	UINT,
	RGBQUAD *);

typedef HENHMETAFILE __stdcall w32api_gdi_get_enh_meta_file_ansi(
	LPCSTR);

typedef HENHMETAFILE __stdcall w32api_gdi_get_enh_meta_file_utf8(
	LPCMBSTR);

typedef HENHMETAFILE __stdcall w32api_gdi_get_enh_meta_file_utf16(
	LPCWSTR);

typedef UINT __stdcall w32api_gdi_get_enh_meta_file_bits(
	HENHMETAFILE,
	UINT,
	LPBYTE);

typedef UINT __stdcall w32api_gdi_get_enh_meta_file_description_ansi(
	HENHMETAFILE,
	UINT,
	LPSTR);

typedef UINT __stdcall w32api_gdi_get_enh_meta_file_description_utf8(
	HENHMETAFILE,
	UINT,
	LPSTR);

typedef UINT __stdcall w32api_gdi_get_enh_meta_file_description_utf16(
	HENHMETAFILE,
	UINT,
	LPWSTR);

typedef UINT __stdcall w32api_gdi_get_enh_meta_file_header(
	HENHMETAFILE,
	UINT,
	LPENHMETAHEADER);

typedef UINT __stdcall w32api_gdi_get_enh_meta_file_palette_entries(
	HENHMETAFILE,
	UINT,
	LPPALETTEENTRY);

typedef UINT __stdcall w32api_gdi_get_enh_meta_file_pixel_format(
	HENHMETAFILE,
	UINT,
	PIXELFORMATDESCRIPTOR *);

typedef DWORD __stdcall w32api_gdi_get_font_data(
	HDC,
	DWORD,
	DWORD,
	PVOID,
	DWORD);

typedef DWORD __stdcall w32api_gdi_get_font_language_info(
	HDC);

typedef DWORD __stdcall w32api_gdi_get_font_unicode_ranges(
	HDC,
	LPGLYPHSET);

typedef DWORD __stdcall w32api_gdi_get_glyph_indices_ansi(
	HDC,
	LPCSTR,
	INT,
	LPWORD,
	DWORD);

typedef DWORD __stdcall w32api_gdi_get_glyph_indices_utf8(
	HDC,
	LPCMBSTR,
	INT,
	LPWORD,
	DWORD);

typedef DWORD __stdcall w32api_gdi_get_glyph_indices_utf16(
	HDC,
	LPCWSTR,
	INT,
	LPWORD,
	DWORD);

typedef DWORD __stdcall w32api_gdi_get_glyph_outline_ansi(
	HDC,
	UINT,
	UINT,
	LPGLYPHMETRICS,
	DWORD,
	LPVOID,
	MAT2 *);

typedef DWORD __stdcall w32api_gdi_get_glyph_outline_utf8(
	HDC,
	UINT,
	UINT,
	LPGLYPHMETRICS,
	DWORD,
	LPVOID,
	MAT2 *);

typedef DWORD __stdcall w32api_gdi_get_glyph_outline_utf16(
	HDC,
	UINT,
	UINT,
	LPGLYPHMETRICS,
	DWORD,
	LPVOID,
	MAT2 *);

typedef INT __stdcall w32api_gdi_get_graphics_mode(
	HDC);

typedef BOOL __stdcall w32api_gdi_get_icm_profile_ansi(
	HDC,
	LPDWORD,
	LPSTR);

typedef BOOL __stdcall w32api_gdi_get_icm_profile_utf8(
	HDC,
	LPDWORD,
	LPSTR);

typedef BOOL __stdcall w32api_gdi_get_icm_profile_utf16(
	HDC,
	LPDWORD,
	LPWSTR);

typedef DWORD __stdcall w32api_gdi_get_kerning_pairs_ansi(
	HDC,
	DWORD,
	LPKERNINGPAIR);

typedef DWORD __stdcall w32api_gdi_get_kerning_pairs_utf8(
	HDC,
	DWORD,
	LPKERNINGPAIR);

typedef DWORD __stdcall w32api_gdi_get_kerning_pairs_utf16(
	HDC,
	DWORD,
	LPKERNINGPAIR);

typedef DWORD __stdcall w32api_gdi_get_layout(
	HDC);

typedef BOOL __stdcall w32api_gdi_get_log_color_space_ansi(
	HCOLORSPACE,
	LPLOGCOLORSPACEA,
	DWORD);

typedef BOOL __stdcall w32api_gdi_get_log_color_space_utf8(
	HCOLORSPACE,
	LPLOGCOLORSPACEA,
	DWORD);

typedef BOOL __stdcall w32api_gdi_get_log_color_space_utf16(
	HCOLORSPACE,
	LPLOGCOLORSPACEW,
	DWORD);

typedef INT __stdcall w32api_gdi_get_map_mode(
	HDC);

typedef HMETAFILE __stdcall w32api_gdi_get_meta_file_ansi(
	LPCSTR);

typedef HMETAFILE __stdcall w32api_gdi_get_meta_file_utf8(
	LPCMBSTR);

typedef HMETAFILE __stdcall w32api_gdi_get_meta_file_utf16(
	LPCWSTR);

typedef UINT __stdcall w32api_gdi_get_meta_file_bits_ex(
	HMETAFILE,
	UINT,
	LPVOID);

typedef INT __stdcall w32api_gdi_get_meta_rgn(
	HDC,
	HRGN);

typedef BOOL __stdcall w32api_gdi_get_miter_limit(
	HDC,
	PFLOAT);

typedef COLORREF __stdcall w32api_gdi_get_nearest_color(
	HDC,
	COLORREF);

typedef UINT __stdcall w32api_gdi_get_nearest_palette_index(
	HPALETTE,
	COLORREF);

typedef INT __stdcall w32api_gdi_get_object_ansi(
	HANDLE,
	INT,
	LPVOID);

typedef INT __stdcall w32api_gdi_get_object_utf8(
	HANDLE,
	INT,
	LPVOID);

typedef INT __stdcall w32api_gdi_get_object_utf16(
	HANDLE,
	INT,
	LPVOID);

typedef DWORD __stdcall w32api_gdi_get_object_type(
	HGDIOBJ);

typedef UINT __stdcall w32api_gdi_get_outline_text_metrics_ansi(
	HDC,
	UINT,
	LPOUTLINETEXTMETRICA);

typedef UINT __stdcall w32api_gdi_get_outline_text_metrics_utf8(
	HDC,
	UINT,
	LPOUTLINETEXTMETRICA);

typedef UINT __stdcall w32api_gdi_get_outline_text_metrics_utf16(
	HDC,
	UINT,
	LPOUTLINETEXTMETRICW);

typedef UINT __stdcall w32api_gdi_get_palette_entries(
	HPALETTE,
	UINT,
	UINT,
	LPPALETTEENTRY);

typedef INT __stdcall w32api_gdi_get_path(
	HDC,
	LPPOINT,
	LPBYTE,
	INT);

typedef COLORREF __stdcall w32api_gdi_get_pixel(
	HDC,
	INT,
	INT);

typedef INT __stdcall w32api_gdi_get_pixel_format(
	HDC);

typedef INT __stdcall w32api_gdi_get_poly_fill_mode(
	HDC);

typedef INT __stdcall w32api_gdi_get_random_rgn(
	HDC,
	HRGN,
	INT);

typedef BOOL __stdcall w32api_gdi_get_rasterizer_caps(
	LPRASTERIZER_STATUS,
	UINT);

typedef DWORD __stdcall w32api_gdi_get_region_data(
	HRGN,
	DWORD,
	LPRGNDATA);

typedef INT __stdcall w32api_gdi_get_rgn_box(
	HRGN,
	LPRECT);

typedef INT __stdcall w32api_gdi_get_rop2(
	HDC);

typedef HGDIOBJ __stdcall w32api_gdi_get_stock_object(
	INT);

typedef INT __stdcall w32api_gdi_get_stretch_blt_mode(
	HDC);

typedef UINT __stdcall w32api_gdi_get_system_palette_entries(
	HDC,
	UINT,
	UINT,
	LPPALETTEENTRY);

typedef UINT __stdcall w32api_gdi_get_system_palette_use(
	HDC);

typedef UINT __stdcall w32api_gdi_get_text_align(
	HDC);

typedef INT __stdcall w32api_gdi_get_text_character_extra(
	HDC);

typedef INT __stdcall w32api_gdi_get_text_charset(
	HDC);

typedef INT __stdcall w32api_gdi_get_text_charset_info(
	HDC,
	LPFONTSIGNATURE,
	DWORD);

typedef COLORREF __stdcall w32api_gdi_get_text_color(
	HDC);

typedef BOOL __stdcall w32api_gdi_get_text_extent_ex_point_ansi(
	HDC,
	LPCSTR,
	INT,
	INT,
	LPINT,
	LPINT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_get_text_extent_ex_point_utf8(
	HDC,
	LPCMBSTR,
	INT,
	INT,
	LPINT,
	LPINT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_get_text_extent_ex_point_utf16(
	HDC,
	LPCWSTR,
	INT,
	INT,
	LPINT,
	LPINT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_get_text_extent_ex_point_i(
	HDC,
	LPWORD,
	INT,
	INT,
	LPINT,
	LPINT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_get_text_extent_point_ansi(
	HDC,
	LPCSTR,
	INT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_get_text_extent_point_utf8(
	HDC,
	LPCMBSTR,
	INT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_get_text_extent_point_utf16(
	HDC,
	LPCWSTR,
	INT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_get_text_extent_point32_ansi(
	HDC,
	LPCSTR,
	INT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_get_text_extent_point32_utf8(
	HDC,
	LPCMBSTR,
	INT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_get_text_extent_point32_utf16(
	HDC,
	LPCWSTR,
	INT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_get_text_extent_point_i(
	HDC,
	LPWORD,
	INT,
	LPSIZE);

typedef INT __stdcall w32api_gdi_get_text_face_ansi(
	HDC,
	INT,
	LPSTR);

typedef INT __stdcall w32api_gdi_get_text_face_utf8(
	HDC,
	INT,
	LPSTR);

typedef INT __stdcall w32api_gdi_get_text_face_utf16(
	HDC,
	INT,
	LPWSTR);

typedef BOOL __stdcall w32api_gdi_get_text_metrics_ansi(
	HDC,
	LPTEXTMETRICA);

typedef BOOL __stdcall w32api_gdi_get_text_metrics_utf8(
	HDC,
	LPTEXTMETRICA);

typedef BOOL __stdcall w32api_gdi_get_text_metrics_utf16(
	HDC,
	LPTEXTMETRICW);

typedef BOOL __stdcall w32api_gdi_get_viewport_ext_ex(
	HDC,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_get_viewport_org_ex(
	HDC,
	LPPOINT);

typedef UINT __stdcall w32api_gdi_get_win_meta_file_bits(
	HENHMETAFILE,
	UINT,
	LPBYTE,
	INT,
	HDC);

typedef BOOL __stdcall w32api_gdi_get_window_ext_ex(
	HDC,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_get_window_org_ex(
	HDC,
	LPPOINT);

typedef BOOL __stdcall w32api_gdi_get_world_transform(
	HDC,
	LPXFORM);

typedef BOOL __stdcall w32api_gdi_gradient_fill(
	HDC,
	PTRIVERTEX,
	ULONG,
	PVOID,
	ULONG,
	ULONG);

typedef BOOL __stdcall w32api_gdi_gradient_fill(
	HDC,
	PTRIVERTEX,
	ULONG,
	PVOID,
	ULONG,
	ULONG);

typedef INT __stdcall w32api_gdi_intersect_clip_rect(
	HDC,
	INT,
	INT,
	INT,
	INT);

typedef BOOL __stdcall w32api_gdi_invert_rgn(
	HDC,
	HRGN);

typedef BOOL __stdcall w32api_gdi_l_pto_dp(
	HDC,
	LPPOINT,
	INT);

typedef BOOL __stdcall w32api_gdi_line_dd_ansi(
	INT,
	INT,
	INT,
	INT,
	LINEDDAPROC,
	LPARAM);

typedef BOOL __stdcall w32api_gdi_line_dd_utf8(
	INT,
	INT,
	INT,
	INT,
	LINEDDAPROC,
	LPARAM);

typedef BOOL __stdcall w32api_gdi_line_to(
	HDC,
	INT,
	INT);

typedef BOOL __stdcall w32api_gdi_mask_blt(
	HDC,
	INT,
	INT,
	INT,
	INT,
	HDC,
	INT,
	INT,
	HBITMAP,
	INT,
	INT,
	DWORD);

typedef BOOL __stdcall w32api_gdi_modify_world_transform(
	HDC,
	XFORM *,
	DWORD);

typedef BOOL __stdcall w32api_gdi_move_to_ex(
	HDC,
	INT,
	INT,
	LPPOINT);

typedef INT __stdcall w32api_gdi_offset_clip_rgn(
	HDC,
	INT,
	INT);

typedef INT __stdcall w32api_gdi_offset_rgn(
	HRGN,
	INT,
	INT);

typedef BOOL __stdcall w32api_gdi_offset_viewport_org_ex(
	HDC,
	INT,
	INT,
	LPPOINT);

typedef BOOL __stdcall w32api_gdi_offset_window_org_ex(
	HDC,
	INT,
	INT,
	LPPOINT);

typedef BOOL __stdcall w32api_gdi_paint_rgn(
	HDC,
	HRGN);

typedef BOOL __stdcall w32api_gdi_pat_blt(
	HDC,
	INT,
	INT,
	INT,
	INT,
	DWORD);

typedef HRGN __stdcall w32api_gdi_path_to_region(
	HDC);

typedef BOOL __stdcall w32api_gdi_pie(
	HDC,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT);

typedef BOOL __stdcall w32api_gdi_play_enh_meta_file(
	HDC,
	HENHMETAFILE,
	RECT *);

typedef BOOL __stdcall w32api_gdi_play_enh_meta_file_record(
	HDC,
	LPHANDLETABLE,
	ENHMETARECORD *,
	UINT);

typedef BOOL __stdcall w32api_gdi_play_meta_file(
	HDC,
	HMETAFILE);

typedef BOOL __stdcall w32api_gdi_play_meta_file_record(
	HDC,
	LPHANDLETABLE,
	LPMETARECORD,
	UINT);

typedef BOOL __stdcall w32api_gdi_plg_blt(
	HDC,
	POINT *,
	HDC,
	INT,
	INT,
	INT,
	INT,
	HBITMAP,
	INT,
	INT);

typedef BOOL __stdcall w32api_gdi_poly_bezier(
	HDC,
	POINT *,
	DWORD);

typedef BOOL __stdcall w32api_gdi_poly_bezier_to(
	HDC,
	POINT *,
	DWORD);

typedef BOOL __stdcall w32api_gdi_poly_draw(
	HDC,
	POINT *,
	BYTE *,
	INT);

typedef BOOL __stdcall w32api_gdi_poly_polygon(
	HDC,
	POINT *,
	INT *,
	INT);

typedef BOOL __stdcall w32api_gdi_poly_polyline(
	HDC,
	POINT *,
	DWORD *,
	DWORD);

typedef BOOL __stdcall w32api_gdi_poly_text_out_ansi(
	HDC,
	POLYTEXTA *,
	INT);

typedef BOOL __stdcall w32api_gdi_poly_text_out_utf8(
	HDC,
	POLYTEXTA *,
	INT);

typedef BOOL __stdcall w32api_gdi_poly_text_out_utf16(
	HDC,
	POLYTEXTW *,
	INT);

typedef BOOL __stdcall w32api_gdi_polygon(
	HDC,
	POINT *,
	INT);

typedef BOOL __stdcall w32api_gdi_polyline(
	HDC,
	POINT *,
	INT);

typedef BOOL __stdcall w32api_gdi_polyline_to(
	HDC,
	POINT *,
	DWORD);

typedef BOOL __stdcall w32api_gdi_pt_in_region(
	HRGN,
	INT,
	INT);

typedef BOOL __stdcall w32api_gdi_pt_visible(
	HDC,
	INT,
	INT);

typedef UINT __stdcall w32api_gdi_realize_palette(
	HDC);

typedef BOOL __stdcall w32api_gdi_rect_in_region(
	HRGN,
	RECT *);

typedef BOOL __stdcall w32api_gdi_rect_visible(
	HDC,
	RECT *);

typedef BOOL __stdcall w32api_gdi_rectangle(
	HDC,
	INT,
	INT,
	INT,
	INT);

typedef BOOL __stdcall w32api_gdi_remove_font_mem_resource_ex(
	HANDLE);

typedef BOOL __stdcall w32api_gdi_remove_font_resource_ansi(
	LPCSTR);

typedef BOOL __stdcall w32api_gdi_remove_font_resource_utf8(
	LPCMBSTR);

typedef BOOL __stdcall w32api_gdi_remove_font_resource_utf16(
	LPCWSTR);

typedef BOOL __stdcall w32api_gdi_remove_font_resource_ex_ansi(
	LPCSTR,
	DWORD,
	PVOID);

typedef BOOL __stdcall w32api_gdi_remove_font_resource_ex_utf8(
	LPCMBSTR,
	DWORD,
	PVOID);

typedef BOOL __stdcall w32api_gdi_remove_font_resource_ex_utf16(
	LPCWSTR,
	DWORD,
	PVOID);

typedef HDC __stdcall w32api_gdi_reset_dc_ansi(
	HDC,
	DEVMODEA *);

typedef HDC __stdcall w32api_gdi_reset_dc_utf8(
	HDC,
	DEVMODEA *);

typedef HDC __stdcall w32api_gdi_reset_dc_utf16(
	HDC,
	DEVMODEW *);

typedef BOOL __stdcall w32api_gdi_resize_palette(
	HPALETTE,
	UINT);

typedef BOOL __stdcall w32api_gdi_restore_dc(
	HDC,
	INT);

typedef BOOL __stdcall w32api_gdi_round_rect(
	HDC,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT);

typedef INT __stdcall w32api_gdi_save_dc(
	HDC);

typedef BOOL __stdcall w32api_gdi_scale_viewport_ext_ex(
	HDC,
	INT,
	INT,
	INT,
	INT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_scale_window_ext_ex(
	HDC,
	INT,
	INT,
	INT,
	INT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_select_clip_path(
	HDC,
	INT);

typedef INT __stdcall w32api_gdi_select_clip_rgn(
	HDC,
	HRGN);

typedef HGDIOBJ __stdcall w32api_gdi_select_object(
	HDC,
	HGDIOBJ);

typedef HPALETTE __stdcall w32api_gdi_select_palette(
	HDC,
	HPALETTE,
	BOOL);

typedef INT __stdcall w32api_gdi_set_abort_proc(
	HDC,
	ABORTPROC);

typedef INT __stdcall w32api_gdi_set_arc_direction(
	HDC,
	INT);

typedef DWORD __stdcall w32api_gdi_set_batch_limit(
	DWORD);

typedef LONG __stdcall w32api_gdi_set_bitmap_bits(
	HBITMAP,
	DWORD,
	void *);

typedef BOOL __stdcall w32api_gdi_set_bitmap_dimension_ex(
	HBITMAP,
	INT,
	INT,
	LPSIZE);

typedef COLORREF __stdcall w32api_gdi_set_bk_color(
	HDC,
	COLORREF);

typedef INT __stdcall w32api_gdi_set_bk_mode(
	HDC,
	INT);

typedef UINT __stdcall w32api_gdi_set_bounds_rect(
	HDC,
	RECT *,
	UINT);

typedef BOOL __stdcall w32api_gdi_set_brush_org_ex(
	HDC,
	INT,
	INT,
	LPPOINT);

typedef BOOL __stdcall w32api_gdi_set_color_adjustment(
	HDC,
	COLORADJUSTMENT *);

typedef HCOLORSPACE __stdcall w32api_gdi_set_color_space(
	HDC,
	HCOLORSPACE);

typedef COLORREF __stdcall w32api_gdi_set_dc_brush_color(
	HDC,
	COLORREF);

typedef COLORREF __stdcall w32api_gdi_set_dc_pen_color(
	HDC,
	COLORREF);

typedef BOOL __stdcall w32api_gdi_set_device_gamma_ramp(
	HDC,
	LPVOID);

typedef INT __stdcall w32api_gdi_set_di_bits(
	HDC,
	HBITMAP,
	UINT,
	UINT,
	void *,
	BITMAPINFO *,
	UINT);

typedef INT __stdcall w32api_gdi_set_di_bits_to_device(
	HDC,
	INT,
	INT,
	DWORD,
	DWORD,
	INT,
	INT,
	UINT,
	UINT,
	void *,
	BITMAPINFO *,
	UINT);

typedef UINT __stdcall w32api_gdi_set_dib_color_table(
	HDC,
	UINT,
	UINT,
	RGBQUAD *);

typedef HENHMETAFILE __stdcall w32api_gdi_set_enh_meta_file_bits(
	UINT,
	BYTE *);

typedef INT __stdcall w32api_gdi_set_graphics_mode(
	HDC,
	INT);

typedef INT __stdcall w32api_gdi_set_icm_mode(
	HDC,
	INT);

typedef BOOL __stdcall w32api_gdi_set_icm_profile_ansi(
	HDC,
	LPSTR);

typedef BOOL __stdcall w32api_gdi_set_icm_profile_utf8(
	HDC,
	LPSTR);

typedef BOOL __stdcall w32api_gdi_set_icm_profile_utf16(
	HDC,
	LPWSTR);

typedef DWORD __stdcall w32api_gdi_set_layout(
	HDC,
	DWORD);

typedef INT __stdcall w32api_gdi_set_map_mode(
	HDC,
	INT);

typedef DWORD __stdcall w32api_gdi_set_mapper_flags(
	HDC,
	DWORD);

typedef HMETAFILE __stdcall w32api_gdi_set_meta_file_bits_ex(
	UINT,
	BYTE *);

typedef INT __stdcall w32api_gdi_set_meta_rgn(
	HDC);

typedef BOOL __stdcall w32api_gdi_set_miter_limit(
	HDC,
	FLOAT,
	PFLOAT);

typedef UINT __stdcall w32api_gdi_set_palette_entries(
	HPALETTE,
	UINT,
	UINT,
	PALETTEENTRY *);

typedef COLORREF __stdcall w32api_gdi_set_pixel(
	HDC,
	INT,
	INT,
	COLORREF);

typedef BOOL __stdcall w32api_gdi_set_pixel_format(
	HDC,
	INT,
	PIXELFORMATDESCRIPTOR *);

typedef BOOL __stdcall w32api_gdi_set_pixel_v(
	HDC,
	INT,
	INT,
	COLORREF);

typedef INT __stdcall w32api_gdi_set_poly_fill_mode(
	HDC,
	INT);

typedef BOOL __stdcall w32api_gdi_set_rect_rgn(
	HRGN,
	INT,
	INT,
	INT,
	INT);

typedef INT __stdcall w32api_gdi_set_rop2(
	HDC,
	INT);

typedef INT __stdcall w32api_gdi_set_stretch_blt_mode(
	HDC,
	INT);

typedef UINT __stdcall w32api_gdi_set_system_palette_use(
	HDC,
	UINT);

typedef UINT __stdcall w32api_gdi_set_text_align(
	HDC,
	UINT);

typedef INT __stdcall w32api_gdi_set_text_character_extra(
	HDC,
	INT);

typedef COLORREF __stdcall w32api_gdi_set_text_color(
	HDC,
	COLORREF);

typedef BOOL __stdcall w32api_gdi_set_text_justification(
	HDC,
	INT,
	INT);

typedef BOOL __stdcall w32api_gdi_set_viewport_ext_ex(
	HDC,
	INT,
	INT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_set_viewport_org_ex(
	HDC,
	INT,
	INT,
	LPPOINT);

typedef HENHMETAFILE __stdcall w32api_gdi_set_win_meta_file_bits(
	UINT,
	BYTE *,
	HDC,
	METAFILEPICT *);

typedef BOOL __stdcall w32api_gdi_set_window_ext_ex(
	HDC,
	INT,
	INT,
	LPSIZE);

typedef BOOL __stdcall w32api_gdi_set_window_org_ex(
	HDC,
	INT,
	INT,
	LPPOINT);

typedef BOOL __stdcall w32api_gdi_set_world_transform(
	HDC,
	XFORM *);

typedef INT __stdcall w32api_gdi_start_doc_ansi(
	HDC,
	DOCINFOA *);

typedef INT __stdcall w32api_gdi_start_doc_utf8(
	HDC,
	DOCINFOA *);

typedef INT __stdcall w32api_gdi_start_doc_utf16(
	HDC,
	DOCINFOW *);

typedef INT __stdcall w32api_gdi_start_page(
	HDC);

typedef BOOL __stdcall w32api_gdi_stretch_blt(
	HDC,
	INT,
	INT,
	INT,
	INT,
	HDC,
	INT,
	INT,
	INT,
	INT,
	DWORD);

typedef INT __stdcall w32api_gdi_stretch_di_bits(
	HDC,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT,
	INT,
	void *,
	BITMAPINFO *,
	UINT,
	DWORD);

typedef BOOL __stdcall w32api_gdi_stroke_and_fill_path(
	HDC);

typedef BOOL __stdcall w32api_gdi_stroke_path(
	HDC);

typedef BOOL __stdcall w32api_gdi_swap_buffers(
	HDC);

typedef BOOL __stdcall w32api_gdi_text_out_ansi(
	HDC,
	INT,
	INT,
	LPCSTR,
	INT);

typedef BOOL __stdcall w32api_gdi_text_out_utf8(
	HDC,
	INT,
	INT,
	LPCMBSTR,
	INT);

typedef BOOL __stdcall w32api_gdi_text_out_utf16(
	HDC,
	INT,
	INT,
	LPCWSTR,
	INT);

typedef BOOL __stdcall w32api_gdi_translate_charset_info(
	DWORD *,
	LPCHARSETINFO,
	DWORD);

typedef BOOL __stdcall w32api_gdi_transparent_blt(
	HDC,
	INT,
	INT,
	INT,
	INT,
	HDC,
	INT,
	INT,
	INT,
	INT,
	UINT);

typedef BOOL __stdcall w32api_gdi_transparent_blt(
	HDC,
	INT,
	INT,
	INT,
	INT,
	HDC,
	INT,
	INT,
	INT,
	INT,
	UINT);

typedef BOOL __stdcall w32api_gdi_unrealize_object(
	HGDIOBJ);

typedef BOOL __stdcall w32api_gdi_update_colors(
	HDC);

typedef BOOL __stdcall w32api_gdi_update_icm_reg_key_ansi(
	DWORD,
	LPSTR,
	LPSTR,
	UINT);

typedef BOOL __stdcall w32api_gdi_update_icm_reg_key_utf8(
	DWORD,
	LPSTR,
	LPSTR,
	UINT);

typedef BOOL __stdcall w32api_gdi_update_icm_reg_key_utf16(
	DWORD,
	LPWSTR,
	LPWSTR,
	UINT);

typedef BOOL __stdcall w32api_gdi_wgl_copy_context(
	HGLRC,
	HGLRC,
	UINT);

typedef HGLRC __stdcall w32api_gdi_wgl_create_context(
	HDC);

typedef HGLRC __stdcall w32api_gdi_wgl_create_layer_context(
	HDC,
	INT);

typedef BOOL __stdcall w32api_gdi_wgl_delete_context(
	HGLRC);

typedef BOOL __stdcall w32api_gdi_wgl_describe_layer_plane(
	HDC,
	INT,
	INT,
	UINT,
	LPLAYERPLANEDESCRIPTOR);

typedef HGLRC __stdcall w32api_gdi_wgl_get_current_context(void);

typedef HDC __stdcall w32api_gdi_wgl_get_current_dc(void);

typedef INT __stdcall w32api_gdi_wgl_get_layer_palette_entries(
	HDC,
	INT,
	INT,
	INT,
	COLORREF *);

typedef PROC __stdcall w32api_gdi_wgl_get_proc_address(
	LPCSTR);

typedef BOOL __stdcall w32api_gdi_wgl_make_current(
	HDC,
	HGLRC);

typedef BOOL __stdcall w32api_gdi_wgl_realize_layer_palette(
	HDC,
	INT,
	BOOL);

typedef INT __stdcall w32api_gdi_wgl_set_layer_palette_entries(
	HDC,
	INT,
	INT,
	INT,
	COLORREF *);

typedef BOOL __stdcall w32api_gdi_wgl_share_lists(
	HGLRC,
	HGLRC);

typedef BOOL __stdcall w32api_gdi_wgl_swap_layer_buffers(
	HDC,
	UINT);

typedef DWORD __stdcall w32api_gdi_wgl_swap_multiple_buffers(
	UINT,
	WGLSWAP *);

typedef BOOL __stdcall w32api_gdi_wgl_use_font_bitmaps_ansi(
	HDC,
	DWORD,
	DWORD,
	DWORD);

typedef BOOL __stdcall w32api_gdi_wgl_use_font_bitmaps_utf8(
	HDC,
	DWORD,
	DWORD,
	DWORD);

typedef BOOL __stdcall w32api_gdi_wgl_use_font_bitmaps_utf16(
	HDC,
	DWORD,
	DWORD,
	DWORD);

typedef BOOL __stdcall w32api_gdi_wgl_use_font_outlines_ansi(
	HDC,
	DWORD,
	DWORD,
	DWORD,
	FLOAT,
	FLOAT,
	INT,
	LPGLYPHMETRICSFLOAT);

typedef BOOL __stdcall w32api_gdi_wgl_use_font_outlines_utf8(
	HDC,
	DWORD,
	DWORD,
	DWORD,
	FLOAT,
	FLOAT,
	INT,
	LPGLYPHMETRICSFLOAT);

typedef BOOL __stdcall w32api_gdi_wgl_use_font_outlines_utf16(
	HDC,
	DWORD,
	DWORD,
	DWORD,
	FLOAT,
	FLOAT,
	INT,
	LPGLYPHMETRICSFLOAT);

typedef BOOL __stdcall w32api_gdi_widen_path(
	HDC);




__dllimport w32api_gdi_abort_doc				 	AbortDoc;
__dllimport w32api_gdi_abort_path				 	AbortPath;
__dllimport w32api_gdi_add_font_mem_resource_ex			 	AddFontMemResourceEx;
__dllimport w32api_gdi_add_font_resource_ansi			 	AddFontResourceA;
__dllimport w32api_gdi_add_font_resource_utf8			 	AddFontResourceM;
__dllimport w32api_gdi_add_font_resource_utf16			 	AddFontResourceW;
__dllimport w32api_gdi_add_font_resource_ex_ansi		 	AddFontResourceExA;
__dllimport w32api_gdi_add_font_resource_ex_utf8		 	AddFontResourceExM;
__dllimport w32api_gdi_add_font_resource_ex_utf16		 	AddFontResourceExW;
__dllimport w32api_gdi_alpha_blend				 	GdiAlphaBlend;
__dllimport w32api_gdi_alpha_blend				 	AlphaBlend;
__dllimport w32api_gdi_angle_arc				 	AngleArc;
__dllimport w32api_gdi_animate_palette				 	AnimatePalette;
__dllimport w32api_gdi_arc					 	Arc;
__dllimport w32api_gdi_arc_to					 	ArcTo;
__dllimport w32api_gdi_begin_path				 	BeginPath;
__dllimport w32api_gdi_bit_blt					 	BitBlt;
__dllimport w32api_gdi_cancel_dc				 	CancelDC;
__dllimport w32api_gdi_check_colors_in_gamut			 	CheckColorsInGamut;
__dllimport w32api_gdi_choose_pixel_format			 	ChoosePixelFormat;
__dllimport w32api_gdi_chord					 	Chord;
__dllimport w32api_gdi_close_enh_meta_file			 	CloseEnhMetaFile;
__dllimport w32api_gdi_close_figure				 	CloseFigure;
__dllimport w32api_gdi_close_meta_file				 	CloseMetaFile;
__dllimport w32api_gdi_color_correct_palette			 	ColorCorrectPalette;
__dllimport w32api_gdi_color_match_to_target			 	ColorMatchToTarget;
__dllimport w32api_gdi_combine_rgn				 	CombineRgn;
__dllimport w32api_gdi_combine_transform			 	CombineTransform;
__dllimport w32api_gdi_comment					 	GdiComment;
__dllimport w32api_gdi_copy_enh_meta_file_ansi			 	CopyEnhMetaFileA;
__dllimport w32api_gdi_copy_enh_meta_file_utf8			 	CopyEnhMetaFileM;
__dllimport w32api_gdi_copy_enh_meta_file_utf16			 	CopyEnhMetaFileW;
__dllimport w32api_gdi_copy_meta_file_ansi			 	CopyMetaFileA;
__dllimport w32api_gdi_copy_meta_file_utf8			 	CopyMetaFileM;
__dllimport w32api_gdi_copy_meta_file_utf16			 	CopyMetaFileW;
__dllimport w32api_gdi_create_bitmap				 	CreateBitmap;
__dllimport w32api_gdi_create_bitmap_indirect			 	CreateBitmapIndirect;
__dllimport w32api_gdi_create_brush_indirect			 	CreateBrushIndirect;
__dllimport w32api_gdi_create_color_space_ansi			 	CreateColorSpaceA;
__dllimport w32api_gdi_create_color_space_utf8			 	CreateColorSpaceM;
__dllimport w32api_gdi_create_color_space_utf16			 	CreateColorSpaceW;
__dllimport w32api_gdi_create_compatible_bitmap			 	CreateCompatibleBitmap;
__dllimport w32api_gdi_create_compatible_dc			 	CreateCompatibleDC;
__dllimport w32api_gdi_create_dc_ansi				 	CreateDCA;
__dllimport w32api_gdi_create_dc_utf8				 	CreateDCM;
__dllimport w32api_gdi_create_dc_utf16				 	CreateDCW;
__dllimport w32api_gdi_create_di_bitmap				 	CreateDIBitmap;
__dllimport w32api_gdi_create_dib_pattern_brush			 	CreateDIBPatternBrush;
__dllimport w32api_gdi_create_dib_pattern_brush_pt		 	CreateDIBPatternBrushPt;
__dllimport w32api_gdi_create_dib_section			 	CreateDIBSection;
__dllimport w32api_gdi_create_discardable_bitmap		 	CreateDiscardableBitmap;
__dllimport w32api_gdi_create_elliptic_rgn			 	CreateEllipticRgn;
__dllimport w32api_gdi_create_elliptic_rgn_indirect		 	CreateEllipticRgnIndirect;
__dllimport w32api_gdi_create_enh_meta_file_ansi		 	CreateEnhMetaFileA;
__dllimport w32api_gdi_create_enh_meta_file_utf8		 	CreateEnhMetaFileM;
__dllimport w32api_gdi_create_enh_meta_file_utf16		 	CreateEnhMetaFileW;
__dllimport w32api_gdi_create_font_ansi				 	CreateFontA;
__dllimport w32api_gdi_create_font_utf8				 	CreateFontM;
__dllimport w32api_gdi_create_font_utf16			 	CreateFontW;
__dllimport w32api_gdi_create_font_indirect_ansi		 	CreateFontIndirectA;
__dllimport w32api_gdi_create_font_indirect_utf8		 	CreateFontIndirectM;
__dllimport w32api_gdi_create_font_indirect_utf16		 	CreateFontIndirectW;
__dllimport w32api_gdi_create_font_indirect_ex_ansi		 	CreateFontIndirectExA;
__dllimport w32api_gdi_create_font_indirect_ex_utf8		 	CreateFontIndirectExM;
__dllimport w32api_gdi_create_font_indirect_ex_utf16		 	CreateFontIndirectExW;
__dllimport w32api_gdi_create_halftone_palette			 	CreateHalftonePalette;
__dllimport w32api_gdi_create_hatch_brush			 	CreateHatchBrush;
__dllimport w32api_gdi_create_ic_ansi				 	CreateICA;
__dllimport w32api_gdi_create_ic_utf8				 	CreateICM;
__dllimport w32api_gdi_create_ic_utf16				 	CreateICW;
__dllimport w32api_gdi_create_meta_file_ansi			 	CreateMetaFileA;
__dllimport w32api_gdi_create_meta_file_utf8			 	CreateMetaFileM;
__dllimport w32api_gdi_create_meta_file_utf16			 	CreateMetaFileW;
__dllimport w32api_gdi_create_palette				 	CreatePalette;
__dllimport w32api_gdi_create_pattern_brush			 	CreatePatternBrush;
__dllimport w32api_gdi_create_pen				 	CreatePen;
__dllimport w32api_gdi_create_pen_indirect			 	CreatePenIndirect;
__dllimport w32api_gdi_create_poly_polygon_rgn			 	CreatePolyPolygonRgn;
__dllimport w32api_gdi_create_polygon_rgn			 	CreatePolygonRgn;
__dllimport w32api_gdi_create_rect_rgn				 	CreateRectRgn;
__dllimport w32api_gdi_create_rect_rgn_indirect			 	CreateRectRgnIndirect;
__dllimport w32api_gdi_create_round_rect_rgn			 	CreateRoundRectRgn;
__dllimport w32api_gdi_create_scalable_font_resource_ansi	 	CreateScalableFontResourceA;
__dllimport w32api_gdi_create_scalable_font_resource_utf8	 	CreateScalableFontResourceM;
__dllimport w32api_gdi_create_scalable_font_resource_utf16	 	CreateScalableFontResourceW;
__dllimport w32api_gdi_create_solid_brush			 	CreateSolidBrush;
__dllimport w32api_gdi_d_pto_lp					 	DPtoLP;
__dllimport w32api_gdi_delete_color_space			 	DeleteColorSpace;
__dllimport w32api_gdi_delete_dc				 	DeleteDC;
__dllimport w32api_gdi_delete_enh_meta_file			 	DeleteEnhMetaFile;
__dllimport w32api_gdi_delete_meta_file				 	DeleteMetaFile;
__dllimport w32api_gdi_delete_object				 	DeleteObject;
__dllimport w32api_gdi_describe_pixel_format			 	DescribePixelFormat;
__dllimport w32api_gdi_device_capabilities_ansi			 	DeviceCapabilitiesA;
__dllimport w32api_gdi_device_capabilities_utf8			 	DeviceCapabilitiesM;
__dllimport w32api_gdi_device_capabilities_utf16		 	DeviceCapabilitiesW;
__dllimport w32api_gdi_draw_escape				 	DrawEscape;
__dllimport w32api_gdi_ellipse					 	Ellipse;
__dllimport w32api_gdi_end_doc					 	EndDoc;
__dllimport w32api_gdi_end_page					 	EndPage;
__dllimport w32api_gdi_end_path					 	EndPath;
__dllimport w32api_gdi_enum_enh_meta_file			 	EnumEnhMetaFile;
__dllimport w32api_gdi_enum_font_families_ansi			 	EnumFontFamiliesA;
__dllimport w32api_gdi_enum_font_families_utf8			 	EnumFontFamiliesM;
__dllimport w32api_gdi_enum_font_families_utf16			 	EnumFontFamiliesW;
__dllimport w32api_gdi_enum_font_families_ex_ansi		 	EnumFontFamiliesExA;
__dllimport w32api_gdi_enum_font_families_ex_utf8		 	EnumFontFamiliesExM;
__dllimport w32api_gdi_enum_font_families_ex_utf16		 	EnumFontFamiliesExW;
__dllimport w32api_gdi_enum_fonts_ansi				 	EnumFontsA;
__dllimport w32api_gdi_enum_fonts_utf8				 	EnumFontsM;
__dllimport w32api_gdi_enum_fonts_utf16				 	EnumFontsW;
__dllimport w32api_gdi_enum_icm_profiles_ansi			 	EnumICMProfilesA;
__dllimport w32api_gdi_enum_icm_profiles_utf8			 	EnumICMProfilesM;
__dllimport w32api_gdi_enum_icm_profiles_utf16			 	EnumICMProfilesW;
__dllimport w32api_gdi_enum_meta_file				 	EnumMetaFile;
__dllimport w32api_gdi_enum_objects				 	EnumObjects;
__dllimport w32api_gdi_equal_rgn				 	EqualRgn;
__dllimport w32api_gdi_escape					 	Escape;
__dllimport w32api_gdi_exclude_clip_rect			 	ExcludeClipRect;
__dllimport w32api_gdi_ext_create_pen				 	ExtCreatePen;
__dllimport w32api_gdi_ext_create_region			 	ExtCreateRegion;
__dllimport w32api_gdi_ext_escape				 	ExtEscape;
__dllimport w32api_gdi_ext_flood_fill				 	ExtFloodFill;
__dllimport w32api_gdi_ext_select_clip_rgn			 	ExtSelectClipRgn;
__dllimport w32api_gdi_ext_text_out_ansi			 	ExtTextOutA;
__dllimport w32api_gdi_ext_text_out_utf8			 	ExtTextOutM;
__dllimport w32api_gdi_ext_text_out_utf16			 	ExtTextOutW;
__dllimport w32api_gdi_fill_path				 	FillPath;
__dllimport w32api_gdi_fill_rgn					 	FillRgn;
__dllimport w32api_gdi_fix_brush_org_ex				 	FixBrushOrgEx;
__dllimport w32api_gdi_flatten_path				 	FlattenPath;
__dllimport w32api_gdi_flood_fill				 	FloodFill;
__dllimport w32api_gdi_flush					 	GdiFlush;
__dllimport w32api_gdi_frame_rgn				 	FrameRgn;
__dllimport w32api_gdi_get_arc_direction			 	GetArcDirection;
__dllimport w32api_gdi_get_aspect_ratio_filter_ex		 	GetAspectRatioFilterEx;
__dllimport w32api_gdi_get_batch_limit				 	GdiGetBatchLimit;
__dllimport w32api_gdi_get_bitmap_bits				 	GetBitmapBits;
__dllimport w32api_gdi_get_bitmap_dimension_ex			 	GetBitmapDimensionEx;
__dllimport w32api_gdi_get_bk_color				 	GetBkColor;
__dllimport w32api_gdi_get_bk_mode				 	GetBkMode;
__dllimport w32api_gdi_get_bounds_rect				 	GetBoundsRect;
__dllimport w32api_gdi_get_brush_org_ex				 	GetBrushOrgEx;
__dllimport w32api_gdi_get_char_abc_widths_ansi			 	GetCharABCWidthsA;
__dllimport w32api_gdi_get_char_abc_widths_utf8			 	GetCharABCWidthsM;
__dllimport w32api_gdi_get_char_abc_widths_utf16		 	GetCharABCWidthsW;
__dllimport w32api_gdi_get_char_abc_widths_float_ansi		 	GetCharABCWidthsFloatA;
__dllimport w32api_gdi_get_char_abc_widths_float_utf8		 	GetCharABCWidthsFloatM;
__dllimport w32api_gdi_get_char_abc_widths_float_utf16		 	GetCharABCWidthsFloatW;
__dllimport w32api_gdi_get_char_abc_widths_i			 	GetCharABCWidthsI;
__dllimport w32api_gdi_get_char_width_ansi			 	GetCharWidthA;
__dllimport w32api_gdi_get_char_width_utf8			 	GetCharWidthM;
__dllimport w32api_gdi_get_char_width_utf16			 	GetCharWidthW;
__dllimport w32api_gdi_get_char_width32_ansi			 	GetCharWidth32A;
__dllimport w32api_gdi_get_char_width32_utf8			 	GetCharWidth32M;
__dllimport w32api_gdi_get_char_width32_utf16			 	GetCharWidth32W;
__dllimport w32api_gdi_get_char_width_float_ansi		 	GetCharWidthFloatA;
__dllimport w32api_gdi_get_char_width_float_utf8		 	GetCharWidthFloatM;
__dllimport w32api_gdi_get_char_width_float_utf16		 	GetCharWidthFloatW;
__dllimport w32api_gdi_get_char_width_i				 	GetCharWidthI;
__dllimport w32api_gdi_get_character_placement_ansi		 	GetCharacterPlacementA;
__dllimport w32api_gdi_get_character_placement_utf8		 	GetCharacterPlacementM;
__dllimport w32api_gdi_get_character_placement_utf16		 	GetCharacterPlacementW;
__dllimport w32api_gdi_get_clip_box				 	GetClipBox;
__dllimport w32api_gdi_get_clip_rgn				 	GetClipRgn;
__dllimport w32api_gdi_get_color_adjustment			 	GetColorAdjustment;
__dllimport w32api_gdi_get_color_space				 	GetColorSpace;
__dllimport w32api_gdi_get_current_object			 	GetCurrentObject;
__dllimport w32api_gdi_get_current_position_ex			 	GetCurrentPositionEx;
__dllimport w32api_gdi_get_dc_brush_color			 	GetDCBrushColor;
__dllimport w32api_gdi_get_dc_org_ex				 	GetDCOrgEx;
__dllimport w32api_gdi_get_dc_pen_color				 	GetDCPenColor;
__dllimport w32api_gdi_get_device_caps				 	GetDeviceCaps;
__dllimport w32api_gdi_get_device_gamma_ramp			 	GetDeviceGammaRamp;
__dllimport w32api_gdi_get_di_bits				 	GetDIBits;
__dllimport w32api_gdi_get_dib_color_table			 	GetDIBColorTable;
__dllimport w32api_gdi_get_enh_meta_file_ansi			 	GetEnhMetaFileA;
__dllimport w32api_gdi_get_enh_meta_file_utf8			 	GetEnhMetaFileM;
__dllimport w32api_gdi_get_enh_meta_file_utf16			 	GetEnhMetaFileW;
__dllimport w32api_gdi_get_enh_meta_file_bits			 	GetEnhMetaFileBits;
__dllimport w32api_gdi_get_enh_meta_file_description_ansi	 	GetEnhMetaFileDescriptionA;
__dllimport w32api_gdi_get_enh_meta_file_description_utf8	 	GetEnhMetaFileDescriptionM;
__dllimport w32api_gdi_get_enh_meta_file_description_utf16	 	GetEnhMetaFileDescriptionW;
__dllimport w32api_gdi_get_enh_meta_file_header			 	GetEnhMetaFileHeader;
__dllimport w32api_gdi_get_enh_meta_file_palette_entries	 	GetEnhMetaFilePaletteEntries;
__dllimport w32api_gdi_get_enh_meta_file_pixel_format		 	GetEnhMetaFilePixelFormat;
__dllimport w32api_gdi_get_font_data				 	GetFontData;
__dllimport w32api_gdi_get_font_language_info			 	GetFontLanguageInfo;
__dllimport w32api_gdi_get_font_unicode_ranges			 	GetFontUnicodeRanges;
__dllimport w32api_gdi_get_glyph_indices_ansi			 	GetGlyphIndicesA;
__dllimport w32api_gdi_get_glyph_indices_utf8			 	GetGlyphIndicesM;
__dllimport w32api_gdi_get_glyph_indices_utf16			 	GetGlyphIndicesW;
__dllimport w32api_gdi_get_glyph_outline_ansi			 	GetGlyphOutlineA;
__dllimport w32api_gdi_get_glyph_outline_utf8			 	GetGlyphOutlineM;
__dllimport w32api_gdi_get_glyph_outline_utf16			 	GetGlyphOutlineW;
__dllimport w32api_gdi_get_graphics_mode			 	GetGraphicsMode;
__dllimport w32api_gdi_get_icm_profile_ansi			 	GetICMProfileA;
__dllimport w32api_gdi_get_icm_profile_utf8			 	GetICMProfileM;
__dllimport w32api_gdi_get_icm_profile_utf16			 	GetICMProfileW;
__dllimport w32api_gdi_get_kerning_pairs_ansi			 	GetKerningPairsA;
__dllimport w32api_gdi_get_kerning_pairs_utf8			 	GetKerningPairsM;
__dllimport w32api_gdi_get_kerning_pairs_utf16			 	GetKerningPairsW;
__dllimport w32api_gdi_get_layout				 	GetLayout;
__dllimport w32api_gdi_get_log_color_space_ansi			 	GetLogColorSpaceA;
__dllimport w32api_gdi_get_log_color_space_utf8			 	GetLogColorSpaceM;
__dllimport w32api_gdi_get_log_color_space_utf16		 	GetLogColorSpaceW;
__dllimport w32api_gdi_get_map_mode				 	GetMapMode;
__dllimport w32api_gdi_get_meta_file_ansi			 	GetMetaFileA;
__dllimport w32api_gdi_get_meta_file_utf8			 	GetMetaFileM;
__dllimport w32api_gdi_get_meta_file_utf16			 	GetMetaFileW;
__dllimport w32api_gdi_get_meta_file_bits_ex			 	GetMetaFileBitsEx;
__dllimport w32api_gdi_get_meta_rgn				 	GetMetaRgn;
__dllimport w32api_gdi_get_miter_limit				 	GetMiterLimit;
__dllimport w32api_gdi_get_nearest_color			 	GetNearestColor;
__dllimport w32api_gdi_get_nearest_palette_index		 	GetNearestPaletteIndex;
__dllimport w32api_gdi_get_object_ansi				 	GetObjectA;
__dllimport w32api_gdi_get_object_utf8				 	GetObjectM;
__dllimport w32api_gdi_get_object_utf16				 	GetObjectW;
__dllimport w32api_gdi_get_object_type				 	GetObjectType;
__dllimport w32api_gdi_get_outline_text_metrics_ansi		 	GetOutlineTextMetricsA;
__dllimport w32api_gdi_get_outline_text_metrics_utf8		 	GetOutlineTextMetricsM;
__dllimport w32api_gdi_get_outline_text_metrics_utf16		 	GetOutlineTextMetricsW;
__dllimport w32api_gdi_get_palette_entries			 	GetPaletteEntries;
__dllimport w32api_gdi_get_path					 	GetPath;
__dllimport w32api_gdi_get_pixel				 	GetPixel;
__dllimport w32api_gdi_get_pixel_format				 	GetPixelFormat;
__dllimport w32api_gdi_get_poly_fill_mode			 	GetPolyFillMode;
__dllimport w32api_gdi_get_random_rgn				 	GetRandomRgn;
__dllimport w32api_gdi_get_rasterizer_caps			 	GetRasterizerCaps;
__dllimport w32api_gdi_get_region_data				 	GetRegionData;
__dllimport w32api_gdi_get_rgn_box				 	GetRgnBox;
__dllimport w32api_gdi_get_rop2					 	GetROP2;
__dllimport w32api_gdi_get_stock_object				 	GetStockObject;
__dllimport w32api_gdi_get_stretch_blt_mode			 	GetStretchBltMode;
__dllimport w32api_gdi_get_system_palette_entries		 	GetSystemPaletteEntries;
__dllimport w32api_gdi_get_system_palette_use			 	GetSystemPaletteUse;
__dllimport w32api_gdi_get_text_align				 	GetTextAlign;
__dllimport w32api_gdi_get_text_character_extra			 	GetTextCharacterExtra;
__dllimport w32api_gdi_get_text_charset				 	GetTextCharset;
__dllimport w32api_gdi_get_text_charset_info			 	GetTextCharsetInfo;
__dllimport w32api_gdi_get_text_color				 	GetTextColor;
__dllimport w32api_gdi_get_text_extent_ex_point_ansi		 	GetTextExtentExPointA;
__dllimport w32api_gdi_get_text_extent_ex_point_utf8		 	GetTextExtentExPointM;
__dllimport w32api_gdi_get_text_extent_ex_point_utf16		 	GetTextExtentExPointW;
__dllimport w32api_gdi_get_text_extent_ex_point_i		 	GetTextExtentExPointI;
__dllimport w32api_gdi_get_text_extent_point_ansi		 	GetTextExtentPointA;
__dllimport w32api_gdi_get_text_extent_point_utf8		 	GetTextExtentPointM;
__dllimport w32api_gdi_get_text_extent_point_utf16		 	GetTextExtentPointW;
__dllimport w32api_gdi_get_text_extent_point32_ansi		 	GetTextExtentPoint32A;
__dllimport w32api_gdi_get_text_extent_point32_utf8		 	GetTextExtentPoint32M;
__dllimport w32api_gdi_get_text_extent_point32_utf16		 	GetTextExtentPoint32W;
__dllimport w32api_gdi_get_text_extent_point_i			 	GetTextExtentPointI;
__dllimport w32api_gdi_get_text_face_ansi			 	GetTextFaceA;
__dllimport w32api_gdi_get_text_face_utf8			 	GetTextFaceM;
__dllimport w32api_gdi_get_text_face_utf16			 	GetTextFaceW;
__dllimport w32api_gdi_get_text_metrics_ansi			 	GetTextMetricsA;
__dllimport w32api_gdi_get_text_metrics_utf8			 	GetTextMetricsM;
__dllimport w32api_gdi_get_text_metrics_utf16			 	GetTextMetricsW;
__dllimport w32api_gdi_get_viewport_ext_ex			 	GetViewportExtEx;
__dllimport w32api_gdi_get_viewport_org_ex			 	GetViewportOrgEx;
__dllimport w32api_gdi_get_win_meta_file_bits			 	GetWinMetaFileBits;
__dllimport w32api_gdi_get_window_ext_ex			 	GetWindowExtEx;
__dllimport w32api_gdi_get_window_org_ex			 	GetWindowOrgEx;
__dllimport w32api_gdi_get_world_transform			 	GetWorldTransform;
__dllimport w32api_gdi_gradient_fill				 	GdiGradientFill;
__dllimport w32api_gdi_gradient_fill				 	GradientFill;
__dllimport w32api_gdi_intersect_clip_rect			 	IntersectClipRect;
__dllimport w32api_gdi_invert_rgn				 	InvertRgn;
__dllimport w32api_gdi_l_pto_dp					 	LPtoDP;
__dllimport w32api_gdi_line_dd_ansi				 	LineDDA;
__dllimport w32api_gdi_line_dd_utf8				 	LineDDM;
__dllimport w32api_gdi_line_to					 	LineTo;
__dllimport w32api_gdi_mask_blt					 	MaskBlt;
__dllimport w32api_gdi_modify_world_transform			 	ModifyWorldTransform;
__dllimport w32api_gdi_move_to_ex				 	MoveToEx;
__dllimport w32api_gdi_offset_clip_rgn				 	OffsetClipRgn;
__dllimport w32api_gdi_offset_rgn				 	OffsetRgn;
__dllimport w32api_gdi_offset_viewport_org_ex			 	OffsetViewportOrgEx;
__dllimport w32api_gdi_offset_window_org_ex			 	OffsetWindowOrgEx;
__dllimport w32api_gdi_paint_rgn				 	PaintRgn;
__dllimport w32api_gdi_pat_blt					 	PatBlt;
__dllimport w32api_gdi_path_to_region				 	PathToRegion;
__dllimport w32api_gdi_pie					 	Pie;
__dllimport w32api_gdi_play_enh_meta_file			 	PlayEnhMetaFile;
__dllimport w32api_gdi_play_enh_meta_file_record		 	PlayEnhMetaFileRecord;
__dllimport w32api_gdi_play_meta_file				 	PlayMetaFile;
__dllimport w32api_gdi_play_meta_file_record			 	PlayMetaFileRecord;
__dllimport w32api_gdi_plg_blt					 	PlgBlt;
__dllimport w32api_gdi_poly_bezier				 	PolyBezier;
__dllimport w32api_gdi_poly_bezier_to				 	PolyBezierTo;
__dllimport w32api_gdi_poly_draw				 	PolyDraw;
__dllimport w32api_gdi_poly_polygon				 	PolyPolygon;
__dllimport w32api_gdi_poly_polyline				 	PolyPolyline;
__dllimport w32api_gdi_poly_text_out_ansi			 	PolyTextOutA;
__dllimport w32api_gdi_poly_text_out_utf8			 	PolyTextOutM;
__dllimport w32api_gdi_poly_text_out_utf16			 	PolyTextOutW;
__dllimport w32api_gdi_polygon					 	Polygon;
__dllimport w32api_gdi_polyline					 	Polyline;
__dllimport w32api_gdi_polyline_to				 	PolylineTo;
__dllimport w32api_gdi_pt_in_region				 	PtInRegion;
__dllimport w32api_gdi_pt_visible				 	PtVisible;
__dllimport w32api_gdi_realize_palette				 	RealizePalette;
__dllimport w32api_gdi_rect_in_region				 	RectInRegion;
__dllimport w32api_gdi_rect_visible				 	RectVisible;
__dllimport w32api_gdi_rectangle				 	Rectangle;
__dllimport w32api_gdi_remove_font_mem_resource_ex		 	RemoveFontMemResourceEx;
__dllimport w32api_gdi_remove_font_resource_ansi		 	RemoveFontResourceA;
__dllimport w32api_gdi_remove_font_resource_utf8		 	RemoveFontResourceM;
__dllimport w32api_gdi_remove_font_resource_utf16		 	RemoveFontResourceW;
__dllimport w32api_gdi_remove_font_resource_ex_ansi		 	RemoveFontResourceExA;
__dllimport w32api_gdi_remove_font_resource_ex_utf8		 	RemoveFontResourceExM;
__dllimport w32api_gdi_remove_font_resource_ex_utf16		 	RemoveFontResourceExW;
__dllimport w32api_gdi_reset_dc_ansi				 	ResetDCA;
__dllimport w32api_gdi_reset_dc_utf8				 	ResetDCM;
__dllimport w32api_gdi_reset_dc_utf16				 	ResetDCW;
__dllimport w32api_gdi_resize_palette				 	ResizePalette;
__dllimport w32api_gdi_restore_dc				 	RestoreDC;
__dllimport w32api_gdi_round_rect				 	RoundRect;
__dllimport w32api_gdi_save_dc					 	SaveDC;
__dllimport w32api_gdi_scale_viewport_ext_ex			 	ScaleViewportExtEx;
__dllimport w32api_gdi_scale_window_ext_ex			 	ScaleWindowExtEx;
__dllimport w32api_gdi_select_clip_path				 	SelectClipPath;
__dllimport w32api_gdi_select_clip_rgn				 	SelectClipRgn;
__dllimport w32api_gdi_select_object				 	SelectObject;
__dllimport w32api_gdi_select_palette				 	SelectPalette;
__dllimport w32api_gdi_set_abort_proc				 	SetAbortProc;
__dllimport w32api_gdi_set_arc_direction			 	SetArcDirection;
__dllimport w32api_gdi_set_batch_limit				 	GdiSetBatchLimit;
__dllimport w32api_gdi_set_bitmap_bits				 	SetBitmapBits;
__dllimport w32api_gdi_set_bitmap_dimension_ex			 	SetBitmapDimensionEx;
__dllimport w32api_gdi_set_bk_color				 	SetBkColor;
__dllimport w32api_gdi_set_bk_mode				 	SetBkMode;
__dllimport w32api_gdi_set_bounds_rect				 	SetBoundsRect;
__dllimport w32api_gdi_set_brush_org_ex				 	SetBrushOrgEx;
__dllimport w32api_gdi_set_color_adjustment			 	SetColorAdjustment;
__dllimport w32api_gdi_set_color_space				 	SetColorSpace;
__dllimport w32api_gdi_set_dc_brush_color			 	SetDCBrushColor;
__dllimport w32api_gdi_set_dc_pen_color				 	SetDCPenColor;
__dllimport w32api_gdi_set_device_gamma_ramp			 	SetDeviceGammaRamp;
__dllimport w32api_gdi_set_di_bits				 	SetDIBits;
__dllimport w32api_gdi_set_di_bits_to_device			 	SetDIBitsToDevice;
__dllimport w32api_gdi_set_dib_color_table			 	SetDIBColorTable;
__dllimport w32api_gdi_set_enh_meta_file_bits			 	SetEnhMetaFileBits;
__dllimport w32api_gdi_set_graphics_mode			 	SetGraphicsMode;
__dllimport w32api_gdi_set_icm_mode				 	SetICMMode;
__dllimport w32api_gdi_set_icm_profile_ansi			 	SetICMProfileA;
__dllimport w32api_gdi_set_icm_profile_utf8			 	SetICMProfileM;
__dllimport w32api_gdi_set_icm_profile_utf16			 	SetICMProfileW;
__dllimport w32api_gdi_set_layout				 	SetLayout;
__dllimport w32api_gdi_set_map_mode				 	SetMapMode;
__dllimport w32api_gdi_set_mapper_flags				 	SetMapperFlags;
__dllimport w32api_gdi_set_meta_file_bits_ex			 	SetMetaFileBitsEx;
__dllimport w32api_gdi_set_meta_rgn				 	SetMetaRgn;
__dllimport w32api_gdi_set_miter_limit				 	SetMiterLimit;
__dllimport w32api_gdi_set_palette_entries			 	SetPaletteEntries;
__dllimport w32api_gdi_set_pixel				 	SetPixel;
__dllimport w32api_gdi_set_pixel_format				 	SetPixelFormat;
__dllimport w32api_gdi_set_pixel_v				 	SetPixelV;
__dllimport w32api_gdi_set_poly_fill_mode			 	SetPolyFillMode;
__dllimport w32api_gdi_set_rect_rgn				 	SetRectRgn;
__dllimport w32api_gdi_set_rop2					 	SetROP2;
__dllimport w32api_gdi_set_stretch_blt_mode			 	SetStretchBltMode;
__dllimport w32api_gdi_set_system_palette_use			 	SetSystemPaletteUse;
__dllimport w32api_gdi_set_text_align				 	SetTextAlign;
__dllimport w32api_gdi_set_text_character_extra			 	SetTextCharacterExtra;
__dllimport w32api_gdi_set_text_color				 	SetTextColor;
__dllimport w32api_gdi_set_text_justification			 	SetTextJustification;
__dllimport w32api_gdi_set_viewport_ext_ex			 	SetViewportExtEx;
__dllimport w32api_gdi_set_viewport_org_ex			 	SetViewportOrgEx;
__dllimport w32api_gdi_set_win_meta_file_bits			 	SetWinMetaFileBits;
__dllimport w32api_gdi_set_window_ext_ex			 	SetWindowExtEx;
__dllimport w32api_gdi_set_window_org_ex			 	SetWindowOrgEx;
__dllimport w32api_gdi_set_world_transform			 	SetWorldTransform;
__dllimport w32api_gdi_start_doc_ansi				 	StartDocA;
__dllimport w32api_gdi_start_doc_utf8				 	StartDocM;
__dllimport w32api_gdi_start_doc_utf16				 	StartDocW;
__dllimport w32api_gdi_start_page				 	StartPage;
__dllimport w32api_gdi_stretch_blt				 	StretchBlt;
__dllimport w32api_gdi_stretch_di_bits				 	StretchDIBits;
__dllimport w32api_gdi_stroke_and_fill_path			 	StrokeAndFillPath;
__dllimport w32api_gdi_stroke_path				 	StrokePath;
__dllimport w32api_gdi_swap_buffers				 	SwapBuffers;
__dllimport w32api_gdi_text_out_ansi				 	TextOutA;
__dllimport w32api_gdi_text_out_utf8				 	TextOutM;
__dllimport w32api_gdi_text_out_utf16				 	TextOutW;
__dllimport w32api_gdi_translate_charset_info			 	TranslateCharsetInfo;
__dllimport w32api_gdi_transparent_blt				 	GdiTransparentBlt;
__dllimport w32api_gdi_transparent_blt				 	TransparentBlt;
__dllimport w32api_gdi_unrealize_object				 	UnrealizeObject;
__dllimport w32api_gdi_update_colors				 	UpdateColors;
__dllimport w32api_gdi_update_icm_reg_key_ansi			 	UpdateICMRegKeyA;
__dllimport w32api_gdi_update_icm_reg_key_utf8			 	UpdateICMRegKeyM;
__dllimport w32api_gdi_update_icm_reg_key_utf16			 	UpdateICMRegKeyW;
__dllimport w32api_gdi_wgl_copy_context				 	wglCopyContext;
__dllimport w32api_gdi_wgl_create_context			 	wglCreateContext;
__dllimport w32api_gdi_wgl_create_layer_context			 	wglCreateLayerContext;
__dllimport w32api_gdi_wgl_delete_context			 	wglDeleteContext;
__dllimport w32api_gdi_wgl_describe_layer_plane			 	wglDescribeLayerPlane;
__dllimport w32api_gdi_wgl_get_current_context			 	wglGetCurrentContext;
__dllimport w32api_gdi_wgl_get_current_dc			 	wglGetCurrentDC;
__dllimport w32api_gdi_wgl_get_layer_palette_entries		 	wglGetLayerPaletteEntries;
__dllimport w32api_gdi_wgl_get_proc_address			 	wglGetProcAddress;
__dllimport w32api_gdi_wgl_make_current				 	wglMakeCurrent;
__dllimport w32api_gdi_wgl_realize_layer_palette		 	wglRealizeLayerPalette;
__dllimport w32api_gdi_wgl_set_layer_palette_entries		 	wglSetLayerPaletteEntries;
__dllimport w32api_gdi_wgl_share_lists				 	wglShareLists;
__dllimport w32api_gdi_wgl_swap_layer_buffers			 	wglSwapLayerBuffers;
__dllimport w32api_gdi_wgl_swap_multiple_buffers		 	wglSwapMultipleBuffers;
__dllimport w32api_gdi_wgl_use_font_bitmaps_ansi		 	wglUseFontBitmapsA;
__dllimport w32api_gdi_wgl_use_font_bitmaps_utf8		 	wglUseFontBitmapsM;
__dllimport w32api_gdi_wgl_use_font_bitmaps_utf16		 	wglUseFontBitmapsW;
__dllimport w32api_gdi_wgl_use_font_outlines_ansi		 	wglUseFontOutlinesA;
__dllimport w32api_gdi_wgl_use_font_outlines_utf8		 	wglUseFontOutlinesM;
__dllimport w32api_gdi_wgl_use_font_outlines_utf16		 	wglUseFontOutlinesW;
__dllimport w32api_gdi_widen_path				 	WidenPath;




#ifdef WINAPI_ANSI_DEFAULT
#define AddFontResource			AddFontResourceA
#define AddFontResourceEx		AddFontResourceExA
#define CopyEnhMetaFile			CopyEnhMetaFileA
#define CopyMetaFile			CopyMetaFileA
#define CreateColorSpace		CreateColorSpaceA
#define CreateDC			CreateDCA
#define CreateEnhMetaFile		CreateEnhMetaFileA
#define CreateFont			CreateFontA
#define CreateFontIndirect		CreateFontIndirectA
#define CreateFontIndirectEx		CreateFontIndirectExA
#define CreateIC			CreateICA
#define CreateMetaFile			CreateMetaFileA
#define CreateScalableFontResource	CreateScalableFontResourceA
#define DeviceCapabilities		DeviceCapabilitiesA
#define EnumFontFamilies		EnumFontFamiliesA
#define EnumFontFamiliesEx		EnumFontFamiliesExA
#define EnumFonts			EnumFontsA
#define EnumICMProfiles			EnumICMProfilesA
#define ExtTextOut			ExtTextOutA
#define GetCharABCWidths		GetCharABCWidthsA
#define GetCharABCWidthsFloat		GetCharABCWidthsFloatA
#define GetCharWidth			GetCharWidthA
#define GetCharWidth32			GetCharWidth32A
#define GetCharWidthFloat		GetCharWidthFloatA
#define GetCharacterPlacement		GetCharacterPlacementA
#define GetEnhMetaFile			GetEnhMetaFileA
#define GetEnhMetaFileDescription	GetEnhMetaFileDescriptionA
#define GetGlyphIndices			GetGlyphIndicesA
#define GetGlyphOutline			GetGlyphOutlineA
#define GetICMProfile			GetICMProfileA
#define GetKerningPairs			GetKerningPairsA
#define GetLogColorSpace		GetLogColorSpaceA
#define GetMetaFile			GetMetaFileA
#define GetObject			GetObjectA
#define GetOutlineTextMetrics		GetOutlineTextMetricsA
#define GetTextExtentExPoint		GetTextExtentExPointA
#define GetTextExtentPoint		GetTextExtentPointA
#define GetTextExtentPoint32		GetTextExtentPoint32A
#define GetTextFace			GetTextFaceA
#define GetTextMetrics			GetTextMetricsA
#define LineDD				LineDDA
#define PolyTextOut			PolyTextOutA
#define RemoveFontResource		RemoveFontResourceA
#define RemoveFontResourceEx		RemoveFontResourceExA
#define ResetDC				ResetDCA
#define SetICMProfile			SetICMProfileA
#define StartDoc			StartDocA
#define TextOut				TextOutA
#define UpdateICMRegKey			UpdateICMRegKeyA
#define wglUseFontBitmaps		wglUseFontBitmapsA
#define wglUseFontOutlines		wglUseFontOutlinesA
#endif




#ifdef WINAPI_UTF8_DEFAULT
#define AddFontResource			AddFontResourceM
#define AddFontResourceEx		AddFontResourceExM
#define CopyEnhMetaFile			CopyEnhMetaFileM
#define CopyMetaFile			CopyMetaFileM
#define CreateColorSpace		CreateColorSpaceM
#define CreateDC			CreateDCM
#define CreateEnhMetaFile		CreateEnhMetaFileM
#define CreateFont			CreateFontM
#define CreateFontIndirect		CreateFontIndirectM
#define CreateFontIndirectEx		CreateFontIndirectExM
#define CreateIC			CreateICM
#define CreateMetaFile			CreateMetaFileM
#define CreateScalableFontResource	CreateScalableFontResourceM
#define DeviceCapabilities		DeviceCapabilitiesM
#define EnumFontFamilies		EnumFontFamiliesM
#define EnumFontFamiliesEx		EnumFontFamiliesExM
#define EnumFonts			EnumFontsM
#define EnumICMProfiles			EnumICMProfilesM
#define ExtTextOut			ExtTextOutM
#define GetCharABCWidths		GetCharABCWidthsM
#define GetCharABCWidthsFloat		GetCharABCWidthsFloatM
#define GetCharWidth			GetCharWidthM
#define GetCharWidth32			GetCharWidth32M
#define GetCharWidthFloat		GetCharWidthFloatM
#define GetCharacterPlacement		GetCharacterPlacementM
#define GetEnhMetaFile			GetEnhMetaFileM
#define GetEnhMetaFileDescription	GetEnhMetaFileDescriptionM
#define GetGlyphIndices			GetGlyphIndicesM
#define GetGlyphOutline			GetGlyphOutlineM
#define GetICMProfile			GetICMProfileM
#define GetKerningPairs			GetKerningPairsM
#define GetLogColorSpace		GetLogColorSpaceM
#define GetMetaFile			GetMetaFileM
#define GetObject			GetObjectM
#define GetOutlineTextMetrics		GetOutlineTextMetricsM
#define GetTextExtentExPoint		GetTextExtentExPointM
#define GetTextExtentPoint		GetTextExtentPointM
#define GetTextExtentPoint32		GetTextExtentPoint32M
#define GetTextFace			GetTextFaceM
#define GetTextMetrics			GetTextMetricsM
#define LineDD				LineDDM
#define PolyTextOut			PolyTextOutM
#define RemoveFontResource		RemoveFontResourceM
#define RemoveFontResourceEx		RemoveFontResourceExM
#define ResetDC				ResetDCM
#define SetICMProfile			SetICMProfileM
#define StartDoc			StartDocM
#define TextOut				TextOutM
#define UpdateICMRegKey			UpdateICMRegKeyM
#define wglUseFontBitmaps		wglUseFontBitmapsM
#define wglUseFontOutlines		wglUseFontOutlinesM
#endif




#ifdef WINAPI_UTF16_DEFAULT
#define AddFontResource			AddFontResourceW
#define AddFontResourceEx		AddFontResourceExW
#define CopyEnhMetaFile			CopyEnhMetaFileW
#define CopyMetaFile			CopyMetaFileW
#define CreateColorSpace		CreateColorSpaceW
#define CreateDC			CreateDCW
#define CreateEnhMetaFile		CreateEnhMetaFileW
#define CreateFont			CreateFontW
#define CreateFontIndirect		CreateFontIndirectW
#define CreateFontIndirectEx		CreateFontIndirectExW
#define CreateIC			CreateICW
#define CreateMetaFile			CreateMetaFileW
#define CreateScalableFontResource	CreateScalableFontResourceW
#define DeviceCapabilities		DeviceCapabilitiesW
#define EnumFontFamilies		EnumFontFamiliesW
#define EnumFontFamiliesEx		EnumFontFamiliesExW
#define EnumFonts			EnumFontsW
#define EnumICMProfiles			EnumICMProfilesW
#define ExtTextOut			ExtTextOutW
#define GetCharABCWidths		GetCharABCWidthsW
#define GetCharABCWidthsFloat		GetCharABCWidthsFloatW
#define GetCharWidth			GetCharWidthW
#define GetCharWidth32			GetCharWidth32W
#define GetCharWidthFloat		GetCharWidthFloatW
#define GetCharacterPlacement		GetCharacterPlacementW
#define GetEnhMetaFile			GetEnhMetaFileW
#define GetEnhMetaFileDescription	GetEnhMetaFileDescriptionW
#define GetGlyphIndices			GetGlyphIndicesW
#define GetGlyphOutline			GetGlyphOutlineW
#define GetICMProfile			GetICMProfileW
#define GetKerningPairs			GetKerningPairsW
#define GetLogColorSpace		GetLogColorSpaceW
#define GetMetaFile			GetMetaFileW
#define GetObject			GetObjectW
#define GetOutlineTextMetrics		GetOutlineTextMetricsW
#define GetTextExtentExPoint		GetTextExtentExPointW
#define GetTextExtentPoint		GetTextExtentPointW
#define GetTextExtentPoint32		GetTextExtentPoint32W
#define GetTextFace			GetTextFaceW
#define GetTextMetrics			GetTextMetricsW
#define LineDD				LineDDW
#define PolyTextOut			PolyTextOutW
#define RemoveFontResource		RemoveFontResourceW
#define RemoveFontResourceEx		RemoveFontResourceExW
#define ResetDC				ResetDCW
#define SetICMProfile			SetICMProfileW
#define StartDoc			StartDocW
#define TextOut				TextOutW
#define UpdateICMRegKey			UpdateICMRegKeyW
#define wglUseFontBitmaps		wglUseFontBitmapsW
#define wglUseFontOutlines		wglUseFontOutlinesW
#endif



#define GDI_ABORTDOC						(0x2)
#define GDI_ABSOLUTE						(0x1)
#define GDI_AC_SRC_ALPHA					(0x1)
#define GDI_AC_SRC_OVER						(0x0)
#define GDI_AD_CLOCKWISE					(0x2)
#define GDI_AD_COUNTERCLOCKWISE					(0x1)
#define GDI_ALTERNATE						(0x1)
#define GDI_ANSI_CHARSET					(0x0)
#define GDI_ANSI_FIXED_FONT					(0xb)
#define GDI_ANSI_VAR_FONT					(0xc)
#define GDI_ANTIALIASED_QUALITY					(0x4)
#define GDI_ARABIC_CHARSET					(0xb2)
#define GDI_ASPECTX						(0x28)
#define GDI_ASPECTXY						(0x2c)
#define GDI_ASPECTY						(0x2a)
#define GDI_ASPECT_FILTERING					(0x1)
#define GDI_BALTIC_CHARSET					(0xba)
#define GDI_BANDINFO						(0x18)
#define GDI_BEGIN_PATH						(0x1000)
#define GDI_BITSPIXEL						(0xc)
#define GDI_BI_BITFIELDS					(0x3)
#define GDI_BI_JPEG						(0x4)
#define GDI_BI_PNG						(0x5)
#define GDI_BI_RGB						(0x0)
#define GDI_BI_RLE4						(0x2)
#define GDI_BI_RLE8						(0x1)
#define GDI_BKMODE_LAST						(0x2)
#define GDI_BLACKNESS						(DWORD)(0x42)
#define GDI_BLACKONWHITE					(0x1)
#define GDI_BLACK_BRUSH						(0x4)
#define GDI_BLACK_PEN						(0x7)
#define GDI_BLTALIGNMENT					(0x77)
#define GDI_BS_DIBPATTERN					(0x5)
#define GDI_BS_DIBPATTERN8X8					(0x8)
#define GDI_BS_DIBPATTERNPT					(0x6)
#define GDI_BS_HATCHED						(0x2)
#define GDI_BS_HOLLOW						BS_NULL
#define GDI_BS_INDEXED						(0x4)
#define GDI_BS_MONOPATTERN					(0x9)
#define GDI_BS_NULL						(0x1)
#define GDI_BS_PATTERN						(0x3)
#define GDI_BS_PATTERN8X8					(0x7)
#define GDI_BS_SOLID						(0x0)
#define GDI_CAPTUREBLT						(DWORD)(0x40000000)
#define GDI_CA_LOG_FILTER					(0x2)
#define GDI_CA_NEGATIVE						(0x1)
#define GDI_CBM_INIT						(0x4)
#define GDI_CCHDEVICENAME					(0x20)
#define GDI_CCHFORMNAME						(0x20)
#define GDI_CC_CHORD						(0x4)
#define GDI_CC_CIRCLES						(0x1)
#define GDI_CC_ELLIPSES						(0x8)
#define GDI_CC_INTERIORS					(0x80)
#define GDI_CC_NONE						(0x0)
#define GDI_CC_PIE						(0x2)
#define GDI_CC_ROUNDRECT					(0x100)
#define GDI_CC_STYLED						(0x20)
#define GDI_CC_WIDE						(0x10)
#define GDI_CC_WIDESTYLED					(0x40)
#define GDI_CHECKJPEGFORMAT					(0x1017)
#define GDI_CHECKPNGFORMAT					(0x1018)
#define GDI_CHINESEBIG5_CHARSET					(0x88)
#define GDI_CLEARTYPE_NATURAL_QUALITY				(0x6)
#define GDI_CLEARTYPE_QUALITY					(0x5)
#define GDI_CLIPCAPS						(0x24)
#define GDI_CLIP_CHARACTER_PRECIS				(0x1)
#define GDI_CLIP_DEFAULT_PRECIS					(0x0)
#define GDI_CLIP_DFA_DISABLE					((0x4)<<(0x4))
#define GDI_CLIP_EMBEDDED					((0x8)<<(0x4))
#define GDI_CLIP_LH_ANGLES					((0x1)<<(0x4))
#define GDI_CLIP_MASK						(0xf)
#define GDI_CLIP_STROKE_PRECIS					(0x2)
#define GDI_CLIP_TO_PATH					(0x1001)
#define GDI_CLIP_TT_ALWAYS					((0x2)<<(0x4))
#define GDI_CLOSECHANNEL					(0x1010)
#define GDI_CLR_INVALID						(0xffffffff)
#define GDI_CM_CMYK_COLOR					(0x4)
#define GDI_CM_DEVICE_ICM					(0x1)
#define GDI_CM_GAMMA_RAMP					(0x2)
#define GDI_CM_IN_GAMUT						(0x0)
#define GDI_CM_NONE						(0x0)
#define GDI_CM_OUT_OF_GAMUT					(0xff)
#define GDI_COLORMATCHTOTARGET_EMBEDED				(0x1)
#define GDI_COLORMGMTCAPS					(0x79)
#define GDI_COLORONCOLOR					(0x3)
#define GDI_COLORRES						(0x6c)
#define GDI_COLOR_ADJ_MAX					(SHORT)(0x64)
#define GDI_COLOR_ADJ_MIN					(SHORT)-(0x64)
#define GDI_COMPLEXREGION					(0x3)
#define GDI_CP_NONE						(0x0)
#define GDI_CP_RECTANGLE					(0x1)
#define GDI_CP_REGION						(0x2)
#define GDI_CREATECOLORSPACE_EMBEDED				(0x1)
#define GDI_CS_DELETE_TRANSFORM					(0x3)
#define GDI_CS_DISABLE						(0x2)
#define GDI_CS_ENABLE						(0x1)
#define GDI_CURVECAPS						(0x1c)
#define GDI_DCBA_FACEDOWNCENTER					(0x101)
#define GDI_DCBA_FACEDOWNLEFT					(0x102)
#define GDI_DCBA_FACEDOWNNONE					(0x100)
#define GDI_DCBA_FACEDOWNRIGHT					(0x103)
#define GDI_DCBA_FACEUPCENTER					(0x1)
#define GDI_DCBA_FACEUPLEFT					(0x2)
#define GDI_DCBA_FACEUPNONE					(0x0)
#define GDI_DCBA_FACEUPRIGHT					(0x3)
#define GDI_DCB_ACCUMULATE					(0x2)
#define GDI_DCB_DIRTY						DCB_ACCUMULATE
#define GDI_DCB_DISABLE						(0x8)
#define GDI_DCB_ENABLE						(0x4)
#define GDI_DCB_RESET						(0x1)
#define GDI_DCB_SET						(DCB_RESET|DCB_ACCUMULATE)
#define GDI_DCTT_BITMAP						(0x1)
#define GDI_DCTT_DOWNLOAD					(0x2)
#define GDI_DCTT_DOWNLOAD_OUTLINE				(0x8)
#define GDI_DCTT_SUBDEV						(0x4)
#define GDI_DC_BINADJUST					(0x13)
#define GDI_DC_BINNAMES						(0xc)
#define GDI_DC_BINS						(0x6)
#define GDI_DC_BRUSH						(0x12)
#define GDI_DC_COLLATE						(0x16)
#define GDI_DC_COLORDEVICE					(0x20)
#define GDI_DC_COPIES						(0x12)
#define GDI_DC_DATATYPE_PRODUCED				(0x15)
#define GDI_DC_DRIVER						(0xb)
#define GDI_DC_DUPLEX						(0x7)
#define GDI_DC_EMF_COMPLIANT					(0x14)
#define GDI_DC_ENUMRESOLUTIONS					(0xd)
#define GDI_DC_EXTRA						(0x9)
#define GDI_DC_FIELDS						(0x1)
#define GDI_DC_FILEDEPENDENCIES					(0xe)
#define GDI_DC_MANUFACTURER					(0x17)
#define GDI_DC_MAXEXTENT					(0x5)
#define GDI_DC_MEDIAREADY					(0x1d)
#define GDI_DC_MEDIATYPENAMES					(0x22)
#define GDI_DC_MEDIATYPES					(0x23)
#define GDI_DC_MINEXTENT					(0x4)
#define GDI_DC_MODEL						(0x18)
#define GDI_DC_NUP						(0x21)
#define GDI_DC_ORIENTATION					(0x11)
#define GDI_DC_PAPERNAMES					(0x10)
#define GDI_DC_PAPERS						(0x2)
#define GDI_DC_PAPERSIZE					(0x3)
#define GDI_DC_PEN						(0x13)
#define GDI_DC_PERSONALITY					(0x19)
#define GDI_DC_PRINTERMEM					(0x1c)
#define GDI_DC_PRINTRATE					(0x1a)
#define GDI_DC_PRINTRATEPPM					(0x1f)
#define GDI_DC_PRINTRATEUNIT					(0x1b)
#define GDI_DC_SIZE						(0x8)
#define GDI_DC_STAPLE						(0x1e)
#define GDI_DC_TRUETYPE						(0xf)
#define GDI_DC_VERSION						(0xa)
#define GDI_DEFAULT_CHARSET					(0x1)
#define GDI_DEFAULT_GUI_FONT					(0x11)
#define GDI_DEFAULT_PALETTE					(0xf)
#define GDI_DEFAULT_PITCH					(0x0)
#define GDI_DEFAULT_QUALITY					(0x0)
#define GDI_DESKTOPHORZRES					(0x76)
#define GDI_DESKTOPVERTRES					(0x75)
#define GDI_DEVICEDATA						(0x13)
#define GDI_DEVICE_DEFAULT_FONT					(0xe)
#define GDI_DEVICE_FONTTYPE					(0x2)
#define GDI_DIB_PAL_COLORS					(0x1)
#define GDI_DIB_RGB_COLORS					(0x0)
#define GDI_DISPLAYCONFIG_MAXPATH				(0x400)
#define GDI_DISPLAYCONFIG_PATH_ACTIVE				(0x1)
#define GDI_DISPLAYCONFIG_PATH_MODE_IDX_INVALID			(0xffffffff)
#define GDI_DISPLAYCONFIG_SOURCE_IN_USE				(0x1)
#define GDI_DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_BOOT	(0x4)
#define GDI_DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_PATH	(0x8)
#define GDI_DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_SYSTEM	(0x10)
#define GDI_DISPLAYCONFIG_TARGET_FORCIBLE			(0x2)
#define GDI_DISPLAYCONFIG_TARGET_IN_USE				(0x1)
#define GDI_DISPLAY_DEVICE_ACTIVE				(0x1)
#define GDI_DISPLAY_DEVICE_ATTACHED				(0x2)
#define GDI_DISPLAY_DEVICE_ATTACHED_TO_DESKTOP			(0x1)
#define GDI_DISPLAY_DEVICE_DISCONNECT				(0x2000000)
#define GDI_DISPLAY_DEVICE_MIRRORING_DRIVER			(0x8)
#define GDI_DISPLAY_DEVICE_MODESPRUNED				(0x8000000)
#define GDI_DISPLAY_DEVICE_MULTI_DRIVER				(0x2)
#define GDI_DISPLAY_DEVICE_PRIMARY_DEVICE			(0x4)
#define GDI_DISPLAY_DEVICE_REMOTE				(0x4000000)
#define GDI_DISPLAY_DEVICE_REMOVABLE				(0x20)
#define GDI_DISPLAY_DEVICE_TS_COMPATIBLE			(0x200000)
#define GDI_DISPLAY_DEVICE_UNSAFE_MODES_ON			(0x80000)
#define GDI_DISPLAY_DEVICE_VGA_COMPATIBLE			(0x10)
#define GDI_DI_APPBANDING					(0x1)
#define GDI_DI_ROPS_READ_DESTINATION				(0x2)
#define GDI_DKGRAY_BRUSH					(0x3)
#define GDI_DMBIN_AUTO						(0x7)
#define GDI_DMBIN_CASSETTE					(0xe)
#define GDI_DMBIN_ENVELOPE					(0x5)
#define GDI_DMBIN_ENVMANUAL					(0x6)
#define GDI_DMBIN_FIRST						DMBIN_UPPER
#define GDI_DMBIN_FORMSOURCE					(0xf)
#define GDI_DMBIN_LARGECAPACITY					(0xb)
#define GDI_DMBIN_LARGEFMT					(0xa)
#define GDI_DMBIN_LAST						DMBIN_FORMSOURCE
#define GDI_DMBIN_LOWER						(0x2)
#define GDI_DMBIN_MANUAL					(0x4)
#define GDI_DMBIN_MIDDLE					(0x3)
#define GDI_DMBIN_ONLYONE					(0x1)
#define GDI_DMBIN_SMALLFMT					(0x9)
#define GDI_DMBIN_TRACTOR					(0x8)
#define GDI_DMBIN_UPPER						(0x1)
#define GDI_DMBIN_USER						(0x100)
#define GDI_DMCOLLATE_FALSE					(0x0)
#define GDI_DMCOLLATE_TRUE					(0x1)
#define GDI_DMCOLOR_COLOR					(0x2)
#define GDI_DMCOLOR_MONOCHROME					(0x1)
#define GDI_DMDFO_CENTER					(0x2)
#define GDI_DMDFO_DEFAULT					(0x0)
#define GDI_DMDFO_STRETCH					(0x1)
#define GDI_DMDISPLAYFLAGS_TEXTMODE				(0x4)
#define GDI_DMDITHER_COARSE					(0x2)
#define GDI_DMDITHER_ERRORDIFFUSION				(0x5)
#define GDI_DMDITHER_FINE					(0x3)
#define GDI_DMDITHER_GRAYSCALE					(0xa)
#define GDI_DMDITHER_LINEART					(0x4)
#define GDI_DMDITHER_NONE					(0x1)
#define GDI_DMDITHER_RESERVED6					(0x6)
#define GDI_DMDITHER_RESERVED7					(0x7)
#define GDI_DMDITHER_RESERVED8					(0x8)
#define GDI_DMDITHER_RESERVED9					(0x9)
#define GDI_DMDITHER_USER					(0x100)
#define GDI_DMDO_180						(0x2)
#define GDI_DMDO_270						(0x3)
#define GDI_DMDO_90						(0x1)
#define GDI_DMDO_DEFAULT					(0x0)
#define GDI_DMDUP_HORIZONTAL					(0x3)
#define GDI_DMDUP_SIMPLEX					(0x1)
#define GDI_DMDUP_VERTICAL					(0x2)
#define GDI_DMICMMETHOD_DEVICE					(0x4)
#define GDI_DMICMMETHOD_DRIVER					(0x3)
#define GDI_DMICMMETHOD_NONE					(0x1)
#define GDI_DMICMMETHOD_SYSTEM					(0x2)
#define GDI_DMICMMETHOD_USER					(0x100)
#define GDI_DMICM_ABS_COLORIMETRIC				(0x4)
#define GDI_DMICM_COLORIMETRIC					(0x3)
#define GDI_DMICM_CONTRAST					(0x2)
#define GDI_DMICM_SATURATE					(0x1)
#define GDI_DMICM_USER						(0x100)
#define GDI_DMMEDIA_GLOSSY					(0x3)
#define GDI_DMMEDIA_STANDARD					(0x1)
#define GDI_DMMEDIA_TRANSPARENCY				(0x2)
#define GDI_DMMEDIA_USER					(0x100)
#define GDI_DMNUP_ONEUP						(0x2)
#define GDI_DMNUP_SYSTEM					(0x1)
#define GDI_DMORIENT_LANDSCAPE					(0x2)
#define GDI_DMORIENT_PORTRAIT					(0x1)
#define GDI_DMPAPER_10X11					(0x2d)
#define GDI_DMPAPER_10X14					(0x10)
#define GDI_DMPAPER_11X17					(0x11)
#define GDI_DMPAPER_12X11					(0x5a)
#define GDI_DMPAPER_15X11					(0x2e)
#define GDI_DMPAPER_9X11					(0x2c)
#define GDI_DMPAPER_A2						(0x42)
#define GDI_DMPAPER_A3						(0x8)
#define GDI_DMPAPER_A3_EXTRA					(0x3f)
#define GDI_DMPAPER_A3_EXTRA_TRANSVERSE				(0x44)
#define GDI_DMPAPER_A3_ROTATED					(0x4c)
#define GDI_DMPAPER_A3_TRANSVERSE				(0x43)
#define GDI_DMPAPER_A4						(0x9)
#define GDI_DMPAPER_A4SMALL					(0xa)
#define GDI_DMPAPER_A4_EXTRA					(0x35)
#define GDI_DMPAPER_A4_PLUS					(0x3c)
#define GDI_DMPAPER_A4_ROTATED					(0x4d)
#define GDI_DMPAPER_A4_TRANSVERSE				(0x37)
#define GDI_DMPAPER_A5						(0xb)
#define GDI_DMPAPER_A5_EXTRA					(0x40)
#define GDI_DMPAPER_A5_ROTATED					(0x4e)
#define GDI_DMPAPER_A5_TRANSVERSE				(0x3d)
#define GDI_DMPAPER_A6						(0x46)
#define GDI_DMPAPER_A6_ROTATED					(0x53)
#define GDI_DMPAPER_A_PLUS					(0x39)
#define GDI_DMPAPER_B4						(0xc)
#define GDI_DMPAPER_B4_JIS_ROTATED				(0x4f)
#define GDI_DMPAPER_B5						(0xd)
#define GDI_DMPAPER_B5_EXTRA					(0x41)
#define GDI_DMPAPER_B5_JIS_ROTATED				(0x50)
#define GDI_DMPAPER_B5_TRANSVERSE				(0x3e)
#define GDI_DMPAPER_B6_JIS					(0x58)
#define GDI_DMPAPER_B6_JIS_ROTATED				(0x59)
#define GDI_DMPAPER_B_PLUS					(0x3a)
#define GDI_DMPAPER_CSHEET					(0x18)
#define GDI_DMPAPER_DBL_JAPANESE_POSTCARD			(0x45)
#define GDI_DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED		(0x52)
#define GDI_DMPAPER_DSHEET					(0x19)
#define GDI_DMPAPER_ENV_10					(0x14)
#define GDI_DMPAPER_ENV_11					(0x15)
#define GDI_DMPAPER_ENV_12					(0x16)
#define GDI_DMPAPER_ENV_14					(0x17)
#define GDI_DMPAPER_ENV_9					(0x13)
#define GDI_DMPAPER_ENV_B4					(0x21)
#define GDI_DMPAPER_ENV_B5					(0x22)
#define GDI_DMPAPER_ENV_B6					(0x23)
#define GDI_DMPAPER_ENV_C3					(0x1d)
#define GDI_DMPAPER_ENV_C4					(0x1e)
#define GDI_DMPAPER_ENV_C5					(0x1c)
#define GDI_DMPAPER_ENV_C6					(0x1f)
#define GDI_DMPAPER_ENV_C65					(0x20)
#define GDI_DMPAPER_ENV_DL					(0x1b)
#define GDI_DMPAPER_ENV_INVITE					(0x2f)
#define GDI_DMPAPER_ENV_ITALY					(0x24)
#define GDI_DMPAPER_ENV_MONARCH					(0x25)
#define GDI_DMPAPER_ENV_PERSONAL				(0x26)
#define GDI_DMPAPER_ESHEET					(0x1a)
#define GDI_DMPAPER_EXECUTIVE					(0x7)
#define GDI_DMPAPER_FANFOLD_LGL_GERMAN				(0x29)
#define GDI_DMPAPER_FANFOLD_STD_GERMAN				(0x28)
#define GDI_DMPAPER_FANFOLD_US					(0x27)
#define GDI_DMPAPER_FIRST					DMPAPER_LETTER
#define GDI_DMPAPER_FOLIO					(0xe)
#define GDI_DMPAPER_ISO_B4					(0x2a)
#define GDI_DMPAPER_JAPANESE_POSTCARD				(0x2b)
#define GDI_DMPAPER_JAPANESE_POSTCARD_ROTATED			(0x51)
#define GDI_DMPAPER_JENV_CHOU3					(0x49)
#define GDI_DMPAPER_JENV_CHOU3_ROTATED				(0x56)
#define GDI_DMPAPER_JENV_CHOU4					(0x4a)
#define GDI_DMPAPER_JENV_CHOU4_ROTATED				(0x57)
#define GDI_DMPAPER_JENV_KAKU2					(0x47)
#define GDI_DMPAPER_JENV_KAKU2_ROTATED				(0x54)
#define GDI_DMPAPER_JENV_KAKU3					(0x48)
#define GDI_DMPAPER_JENV_KAKU3_ROTATED				(0x55)
#define GDI_DMPAPER_JENV_YOU4					(0x5b)
#define GDI_DMPAPER_JENV_YOU4_ROTATED				(0x5c)
#define GDI_DMPAPER_LAST					DMPAPER_PENV_10_ROTATED
#define GDI_DMPAPER_LEDGER					(0x4)
#define GDI_DMPAPER_LEGAL					(0x5)
#define GDI_DMPAPER_LEGAL_EXTRA					(0x33)
#define GDI_DMPAPER_LETTER					(0x1)
#define GDI_DMPAPER_LETTERSMALL					(0x2)
#define GDI_DMPAPER_LETTER_EXTRA				(0x32)
#define GDI_DMPAPER_LETTER_EXTRA_TRANSVERSE			(0x38)
#define GDI_DMPAPER_LETTER_PLUS					(0x3b)
#define GDI_DMPAPER_LETTER_ROTATED				(0x4b)
#define GDI_DMPAPER_LETTER_TRANSVERSE				(0x36)
#define GDI_DMPAPER_NOTE					(0x12)
#define GDI_DMPAPER_P16K					(0x5d)
#define GDI_DMPAPER_P16K_ROTATED				(0x6a)
#define GDI_DMPAPER_P32K					(0x5e)
#define GDI_DMPAPER_P32KBIG					(0x5f)
#define GDI_DMPAPER_P32KBIG_ROTATED				(0x6c)
#define GDI_DMPAPER_P32K_ROTATED				(0x6b)
#define GDI_DMPAPER_PENV_1					(0x60)
#define GDI_DMPAPER_PENV_10					(0x69)
#define GDI_DMPAPER_PENV_10_ROTATED				(0x76)
#define GDI_DMPAPER_PENV_1_ROTATED				(0x6d)
#define GDI_DMPAPER_PENV_2					(0x61)
#define GDI_DMPAPER_PENV_2_ROTATED				(0x6e)
#define GDI_DMPAPER_PENV_3					(0x62)
#define GDI_DMPAPER_PENV_3_ROTATED				(0x6f)
#define GDI_DMPAPER_PENV_4					(0x63)
#define GDI_DMPAPER_PENV_4_ROTATED				(0x70)
#define GDI_DMPAPER_PENV_5					(0x64)
#define GDI_DMPAPER_PENV_5_ROTATED				(0x71)
#define GDI_DMPAPER_PENV_6					(0x65)
#define GDI_DMPAPER_PENV_6_ROTATED				(0x72)
#define GDI_DMPAPER_PENV_7					(0x66)
#define GDI_DMPAPER_PENV_7_ROTATED				(0x73)
#define GDI_DMPAPER_PENV_8					(0x67)
#define GDI_DMPAPER_PENV_8_ROTATED				(0x74)
#define GDI_DMPAPER_PENV_9					(0x68)
#define GDI_DMPAPER_PENV_9_ROTATED				(0x75)
#define GDI_DMPAPER_QUARTO					(0xf)
#define GDI_DMPAPER_RESERVED_48					(0x30)
#define GDI_DMPAPER_RESERVED_49					(0x31)
#define GDI_DMPAPER_STATEMENT					(0x6)
#define GDI_DMPAPER_TABLOID					(0x3)
#define GDI_DMPAPER_TABLOID_EXTRA				(0x34)
#define GDI_DMPAPER_USER					(0x100)
#define GDI_DMRES_DRAFT						(-(0x1))
#define GDI_DMRES_HIGH						(-(0x4))
#define GDI_DMRES_LOW						(-(0x2))
#define GDI_DMRES_MEDIUM					(-(0x3))
#define GDI_DMTT_BITMAP						(0x1)
#define GDI_DMTT_DOWNLOAD					(0x2)
#define GDI_DMTT_DOWNLOAD_OUTLINE				(0x4)
#define GDI_DMTT_SUBDEV						(0x3)
#define GDI_DM_BITSPERPEL					(0x40000)
#define GDI_DM_COLLATE						(0x8000)
#define GDI_DM_COLOR						(0x800)
#define GDI_DM_COPIES						(0x100)
#define GDI_DM_COPY						(0x2)
#define GDI_DM_DEFAULTSOURCE					(0x200)
#define GDI_DM_DISPLAYFIXEDOUTPUT				(0x20000000)
#define GDI_DM_DISPLAYFLAGS					(0x200000)
#define GDI_DM_DISPLAYFREQUENCY					(0x400000)
#define GDI_DM_DISPLAYORIENTATION				(0x80)
#define GDI_DM_DITHERTYPE					(0x4000000)
#define GDI_DM_DUPLEX						(0x1000)
#define GDI_DM_FORMNAME						(0x10000)
#define GDI_DM_ICMINTENT					(0x1000000)
#define GDI_DM_ICMMETHOD					(0x800000)
#define GDI_DM_INTERLACED					(0x2)
#define GDI_DM_IN_BUFFER					DM_MODIFY
#define GDI_DM_IN_PROMPT					DM_PROMPT
#define GDI_DM_LOGPIXELS					(0x20000)
#define GDI_DM_MEDIATYPE					(0x2000000)
#define GDI_DM_MODIFY						(0x8)
#define GDI_DM_NUP						(0x40)
#define GDI_DM_ORIENTATION					(0x1)
#define GDI_DM_OUT_BUFFER					DM_COPY
#define GDI_DM_OUT_DEFAULT					DM_UPDATE
#define GDI_DM_PANNINGHEIGHT					(0x10000000)
#define GDI_DM_PANNINGWIDTH					(0x8000000)
#define GDI_DM_PAPERLENGTH					(0x4)
#define GDI_DM_PAPERSIZE					(0x2)
#define GDI_DM_PAPERWIDTH					(0x8)
#define GDI_DM_PELSHEIGHT					(0x100000)
#define GDI_DM_PELSWIDTH					(0x80000)
#define GDI_DM_POSITION						(0x20)
#define GDI_DM_PRINTQUALITY					(0x400)
#define GDI_DM_PROMPT						(0x4)
#define GDI_DM_SCALE						(0x10)
#define GDI_DM_SPECVERSION					(0x401)
#define GDI_DM_TTOPTION						(0x4000)
#define GDI_DM_UPDATE						(0x1)
#define GDI_DM_YRESOLUTION					(0x2000)
#define GDI_DOWNLOADFACE					(0x202)
#define GDI_DOWNLOADHEADER					(0x100f)
#define GDI_DRAFTMODE						(0x7)
#define GDI_DRAFT_QUALITY					(0x1)
#define GDI_DRAWPATTERNRECT					(0x19)
#define GDI_DRIVERVERSION					(0x0)
#define GDI_DSTINVERT						(DWORD)(0x550009)
#define GDI_DT_CHARSTREAM					(0x4)
#define GDI_DT_DISPFILE						(0x6)
#define GDI_DT_METAFILE						(0x5)
#define GDI_DT_PLOTTER						(0x0)
#define GDI_DT_RASCAMERA					(0x3)
#define GDI_DT_RASDISPLAY					(0x1)
#define GDI_DT_RASPRINTER					(0x2)
#define GDI_EASTEUROPE_CHARSET					(0xee)
#define GDI_ELF_CULTURE_LATIN					(0x0)
#define GDI_ELF_VENDOR_SIZE					(0x4)
#define GDI_ELF_VERSION						(0x0)
#define GDI_EMR_ABORTPATH					(0x44)
#define GDI_EMR_ALPHABLEND					(0x72)
#define GDI_EMR_ANGLEARC					(0x29)
#define GDI_EMR_ARC						(0x2d)
#define GDI_EMR_ARCTO						(0x37)
#define GDI_EMR_BEGINPATH					(0x3b)
#define GDI_EMR_BITBLT						(0x4c)
#define GDI_EMR_CHORD						(0x2e)
#define GDI_EMR_CLOSEFIGURE					(0x3d)
#define GDI_EMR_COLORCORRECTPALETTE				(0x6f)
#define GDI_EMR_COLORMATCHTOTARGETW				(0x79)
#define GDI_EMR_CREATEBRUSHINDIRECT				(0x27)
#define GDI_EMR_CREATECOLORSPACE				(0x63)
#define GDI_EMR_CREATECOLORSPACEW				(0x7a)
#define GDI_EMR_CREATEDIBPATTERNBRUSHPT				(0x5e)
#define GDI_EMR_CREATEMONOBRUSH					(0x5d)
#define GDI_EMR_CREATEPALETTE					(0x31)
#define GDI_EMR_CREATEPEN					(0x26)
#define GDI_EMR_DELETECOLORSPACE				(0x65)
#define GDI_EMR_DELETEOBJECT					(0x28)
#define GDI_EMR_ELLIPSE						(0x2a)
#define GDI_EMR_ENDPATH						(0x3c)
#define GDI_EMR_EOF						(0xe)
#define GDI_EMR_EXCLUDECLIPRECT					(0x1d)
#define GDI_EMR_EXTCREATEFONTINDIRECTW				(0x52)
#define GDI_EMR_EXTCREATEPEN					(0x5f)
#define GDI_EMR_EXTFLOODFILL					(0x35)
#define GDI_EMR_EXTSELECTCLIPRGN				(0x4b)
#define GDI_EMR_EXTTEXTOUTA					(0x53)
#define GDI_EMR_EXTTEXTOUTW					(0x54)
#define GDI_EMR_FILLPATH					(0x3e)
#define GDI_EMR_FILLRGN						(0x47)
#define GDI_EMR_FLATTENPATH					(0x41)
#define GDI_EMR_FRAMERGN					(0x48)
#define GDI_EMR_GDICOMMENT					(0x46)
#define GDI_EMR_GLSBOUNDEDRECORD				(0x67)
#define GDI_EMR_GLSRECORD					(0x66)
#define GDI_EMR_GRADIENTFILL					(0x76)
#define GDI_EMR_HEADER						(0x1)
#define GDI_EMR_INTERSECTCLIPRECT				(0x1e)
#define GDI_EMR_INVERTRGN					(0x49)
#define GDI_EMR_LINETO						(0x36)
#define GDI_EMR_MASKBLT						(0x4e)
#define GDI_EMR_MAX						(0x7a)
#define GDI_EMR_MIN						(0x1)
#define GDI_EMR_MODIFYWORLDTRANSFORM				(0x24)
#define GDI_EMR_MOVETOEX					(0x1b)
#define GDI_EMR_OFFSETCLIPRGN					(0x1a)
#define GDI_EMR_PAINTRGN					(0x4a)
#define GDI_EMR_PIE						(0x2f)
#define GDI_EMR_PIXELFORMAT					(0x68)
#define GDI_EMR_PLGBLT						(0x4f)
#define GDI_EMR_POLYBEZIER					(0x2)
#define GDI_EMR_POLYBEZIER16					(0x55)
#define GDI_EMR_POLYBEZIERTO					(0x5)
#define GDI_EMR_POLYBEZIERTO16					(0x58)
#define GDI_EMR_POLYDRAW					(0x38)
#define GDI_EMR_POLYDRAW16					(0x5c)
#define GDI_EMR_POLYGON						(0x3)
#define GDI_EMR_POLYGON16					(0x56)
#define GDI_EMR_POLYLINE					(0x4)
#define GDI_EMR_POLYLINE16					(0x57)
#define GDI_EMR_POLYLINETO					(0x6)
#define GDI_EMR_POLYLINETO16					(0x59)
#define GDI_EMR_POLYPOLYGON					(0x8)
#define GDI_EMR_POLYPOLYGON16					(0x5b)
#define GDI_EMR_POLYPOLYLINE					(0x7)
#define GDI_EMR_POLYPOLYLINE16					(0x5a)
#define GDI_EMR_POLYTEXTOUTA					(0x60)
#define GDI_EMR_POLYTEXTOUTW					(0x61)
#define GDI_EMR_REALIZEPALETTE					(0x34)
#define GDI_EMR_RECTANGLE					(0x2b)
#define GDI_EMR_RESERVED_105					(0x69)
#define GDI_EMR_RESERVED_106					(0x6a)
#define GDI_EMR_RESERVED_107					(0x6b)
#define GDI_EMR_RESERVED_108					(0x6c)
#define GDI_EMR_RESERVED_109					(0x6d)
#define GDI_EMR_RESERVED_110					(0x6e)
#define GDI_EMR_RESERVED_117					(0x75)
#define GDI_EMR_RESERVED_119					(0x77)
#define GDI_EMR_RESERVED_120					(0x78)
#define GDI_EMR_RESIZEPALETTE					(0x33)
#define GDI_EMR_RESTOREDC					(0x22)
#define GDI_EMR_ROUNDRECT					(0x2c)
#define GDI_EMR_SAVEDC						(0x21)
#define GDI_EMR_SCALEVIEWPORTEXTEX				(0x1f)
#define GDI_EMR_SCALEWINDOWEXTEX				(0x20)
#define GDI_EMR_SELECTCLIPPATH					(0x43)
#define GDI_EMR_SELECTOBJECT					(0x25)
#define GDI_EMR_SELECTPALETTE					(0x30)
#define GDI_EMR_SETARCDIRECTION					(0x39)
#define GDI_EMR_SETBKCOLOR					(0x19)
#define GDI_EMR_SETBKMODE					(0x12)
#define GDI_EMR_SETBRUSHORGEX					(0xd)
#define GDI_EMR_SETCOLORADJUSTMENT				(0x17)
#define GDI_EMR_SETCOLORSPACE					(0x64)
#define GDI_EMR_SETDIBITSTODEVICE				(0x50)
#define GDI_EMR_SETICMMODE					(0x62)
#define GDI_EMR_SETICMPROFILEA					(0x70)
#define GDI_EMR_SETICMPROFILEW					(0x71)
#define GDI_EMR_SETLAYOUT					(0x73)
#define GDI_EMR_SETMAPMODE					(0x11)
#define GDI_EMR_SETMAPPERFLAGS					(0x10)
#define GDI_EMR_SETMETARGN					(0x1c)
#define GDI_EMR_SETMITERLIMIT					(0x3a)
#define GDI_EMR_SETPALETTEENTRIES				(0x32)
#define GDI_EMR_SETPIXELV					(0xf)
#define GDI_EMR_SETPOLYFILLMODE					(0x13)
#define GDI_EMR_SETROP2						(0x14)
#define GDI_EMR_SETSTRETCHBLTMODE				(0x15)
#define GDI_EMR_SETTEXTALIGN					(0x16)
#define GDI_EMR_SETTEXTCOLOR					(0x18)
#define GDI_EMR_SETVIEWPORTEXTEX				(0xb)
#define GDI_EMR_SETVIEWPORTORGEX				(0xc)
#define GDI_EMR_SETWINDOWEXTEX					(0x9)
#define GDI_EMR_SETWINDOWORGEX					(0xa)
#define GDI_EMR_SETWORLDTRANSFORM				(0x23)
#define GDI_EMR_STRETCHBLT					(0x4d)
#define GDI_EMR_STRETCHDIBITS					(0x51)
#define GDI_EMR_STROKEANDFILLPATH				(0x3f)
#define GDI_EMR_STROKEPATH					(0x40)
#define GDI_EMR_TRANSPARENTBLT					(0x74)
#define GDI_EMR_WIDENPATH					(0x42)
#define GDI_ENABLEDUPLEX					(0x1c)
#define GDI_ENABLEPAIRKERNING					(0x301)
#define GDI_ENABLERELATIVEWIDTHS				(0x300)
#define GDI_ENCAPSULATED_POSTSCRIPT				(0x1014)
#define GDI_ENDDOC						(0xb)
#define GDI_END_PATH						(0x1002)
#define GDI_ENHMETA_SIGNATURE					(0x464d4520)
#define GDI_ENHMETA_STOCK_OBJECT				(0x80000000)
#define GDI_ENUMPAPERBINS					(0x1f)
#define GDI_ENUMPAPERMETRICS					(0x22)
#define GDI_EPSPRINTING						(0x21)
#define GDI_EPS_SIGNATURE					(0x46535045)
#define GDI_ERROR						((0xffffffff))
#define GDI_ETO_CLIPPED						(0x4)
#define GDI_ETO_GLYPH_INDEX					(0x10)
#define GDI_ETO_IGNORELANGUAGE					(0x1000)
#define GDI_ETO_NUMERICSLATIN					(0x800)
#define GDI_ETO_NUMERICSLOCAL					(0x400)
#define GDI_ETO_OPAQUE						(0x2)
#define GDI_ETO_PDY						(0x2000)
#define GDI_ETO_REVERSE_INDEX_MAP				(0x10000)
#define GDI_ETO_RTLREADING					(0x80)
#define GDI_EXTTEXTOUT						(0x200)
#define GDI_EXT_DEVICE_CAPS					(0x1003)
#define GDI_FEATURESETTING_CUSTPAPER				(0x3)
#define GDI_FEATURESETTING_MIRROR				(0x4)
#define GDI_FEATURESETTING_NEGATIVE				(0x5)
#define GDI_FEATURESETTING_NUP					(0x0)
#define GDI_FEATURESETTING_OUTPUT				(0x1)
#define GDI_FEATURESETTING_PRIVATE_BEGIN			(0x1000)
#define GDI_FEATURESETTING_PRIVATE_END				(0x1fff)
#define GDI_FEATURESETTING_PROTOCOL				(0x6)
#define GDI_FEATURESETTING_PSLEVEL				(0x2)
#define GDI_FF_DECORATIVE					((0x5)<<(0x4))
#define GDI_FF_DONTCARE						((0x0)<<(0x4))
#define GDI_FF_MODERN						((0x3)<<(0x4))
#define GDI_FF_ROMAN						((0x1)<<(0x4))
#define GDI_FF_SCRIPT						((0x4)<<(0x4))
#define GDI_FF_SWISS						((0x2)<<(0x4))
#define GDI_FIXED_PITCH						(0x1)
#define GDI_FLI_GLYPHS						(0x40000)
#define GDI_FLI_MASK						(0x103b)
#define GDI_FLOODFILLBORDER					(0x0)
#define GDI_FLOODFILLSURFACE					(0x1)
#define GDI_FLUSHOUTPUT						(0x6)
#define GDI_FONTMAPPER_MAX					(0xa)
#define GDI_FR_NOT_ENUM						(0x20)
#define GDI_FR_PRIVATE						(0x10)
#define GDI_FS_ARABIC						(0x40)
#define GDI_FS_BALTIC						(0x80)
#define GDI_FS_CHINESESIMP					(0x40000)
#define GDI_FS_CHINESETRAD					(0x100000)
#define GDI_FS_CYRILLIC						(0x4)
#define GDI_FS_GREEK						(0x8)
#define GDI_FS_HEBREW						(0x20)
#define GDI_FS_JISJAPAN						(0x20000)
#define GDI_FS_JOHAB						(0x200000)
#define GDI_FS_LATIN1						(0x1)
#define GDI_FS_LATIN2						(0x2)
#define GDI_FS_SYMBOL						(0x80000000)
#define GDI_FS_THAI						(0x10000)
#define GDI_FS_TURKISH						(0x10)
#define GDI_FS_VIETNAMESE					(0x100)
#define GDI_FS_WANSUNG						(0x80000)
#define GDI_FW_BLACK						FW_HEAVY
#define GDI_FW_BOLD						(0x2bc)
#define GDI_FW_DEMIBOLD						FW_SEMIBOLD
#define GDI_FW_DONTCARE						(0x0)
#define GDI_FW_EXTRABOLD					(0x320)
#define GDI_FW_EXTRALIGHT					(0xc8)
#define GDI_FW_HEAVY						(0x384)
#define GDI_FW_LIGHT						(0x12c)
#define GDI_FW_MEDIUM						(0x1f4)
#define GDI_FW_NORMAL						(0x190)
#define GDI_FW_REGULAR						FW_NORMAL
#define GDI_FW_SEMIBOLD						(0x258)
#define GDI_FW_THIN						(0x64)
#define GDI_FW_ULTRABOLD					FW_EXTRABOLD
#define GDI_FW_ULTRALIGHT					FW_EXTRALIGHT
#define GDI_GB2312_CHARSET					(0x86)
#define GDI_GCPCLASS_ARABIC					(0x2)
#define GDI_GCPCLASS_HEBREW					(0x2)
#define GDI_GCPCLASS_LATIN					(0x1)
#define GDI_GCPCLASS_LATINNUMBER				(0x5)
#define GDI_GCPCLASS_LATINNUMERICSEPARATOR			(0x7)
#define GDI_GCPCLASS_LATINNUMERICTERMINATOR			(0x6)
#define GDI_GCPCLASS_LOCALNUMBER				(0x4)
#define GDI_GCPCLASS_NEUTRAL					(0x3)
#define GDI_GCPCLASS_NUMERICSEPARATOR				(0x8)
#define GDI_GCPCLASS_POSTBOUNDLTR				(0x20)
#define GDI_GCPCLASS_POSTBOUNDRTL				(0x10)
#define GDI_GCPCLASS_PREBOUNDLTR				(0x80)
#define GDI_GCPCLASS_PREBOUNDRTL				(0x40)
#define GDI_GCPGLYPH_LINKAFTER					(0x4000)
#define GDI_GCPGLYPH_LINKBEFORE					(0x8000)
#define GDI_GCP_CLASSIN						(0x80000)
#define GDI_GCP_DBCS						(0x1)
#define GDI_GCP_DIACRITIC					(0x100)
#define GDI_GCP_DISPLAYZWG					(0x400000)
#define GDI_GCP_ERROR						(0x8000)
#define GDI_GCP_GLYPHSHAPE					(0x10)
#define GDI_GCP_JUSTIFY						(0x10000)
#define GDI_GCP_JUSTIFYIN					(0x200000)
#define GDI_GCP_KASHIDA						(0x400)
#define GDI_GCP_LIGATE						(0x20)
#define GDI_GCP_MAXEXTENT					(0x100000)
#define GDI_GCP_NEUTRALOVERRIDE					(0x2000000)
#define GDI_GCP_NUMERICOVERRIDE					(0x1000000)
#define GDI_GCP_NUMERICSLATIN					(0x4000000)
#define GDI_GCP_NUMERICSLOCAL					(0x8000000)
#define GDI_GCP_REORDER						(0x2)
#define GDI_GCP_SYMSWAPOFF					(0x800000)
#define GDI_GCP_USEKERNING					(0x8)
#define GDI_GDICOMMENT_BEGINGROUP				(0x2)
#define GDI_GDICOMMENT_ENDGROUP					(0x3)
#define GDI_GDICOMMENT_IDENTIFIER				(0x43494447)
#define GDI_GDICOMMENT_MULTIFORMATS				(0x40000004)
#define GDI_GDICOMMENT_UNICODE_END				(0x80)
#define GDI_GDICOMMENT_UNICODE_STRING				(0x40)
#define GDI_GDICOMMENT_WINDOWS_METAFILE				(0x80000001)
#define GDI_GDIPLUS_TS_QUERYVER					(0x101a)
#define GDI_GDIPLUS_TS_RECORD					(0x101b)
#define GDI_GETCOLORTABLE					(0x5)
#define GDI_GETDEVICEUNITS					(0x2a)
#define GDI_GETEXTENDEDTEXTMETRICS				(0x100)
#define GDI_GETEXTENTTABLE					(0x101)
#define GDI_GETFACENAME						(0x201)
#define GDI_GETPAIRKERNTABLE					(0x102)
#define GDI_GETPENWIDTH						(0x10)
#define GDI_GETPHYSPAGESIZE					(0xc)
#define GDI_GETPRINTINGOFFSET					(0xd)
#define GDI_GETSCALINGFACTOR					(0xe)
#define GDI_GETSETPAPERBINS					(0x1d)
#define GDI_GETSETPAPERMETRICS					(0x23)
#define GDI_GETSETPRINTORIENT					(0x1e)
#define GDI_GETSETSCREENPARAMS					(0xc00)
#define GDI_GETTECHNOLGY					(0x14)
#define GDI_GETTECHNOLOGY					(0x14)
#define GDI_GETTRACKKERNTABLE					(0x103)
#define GDI_GETVECTORBRUSHSIZE					(0x1b)
#define GDI_GETVECTORPENSIZE					(0x1a)
#define GDI_GET_PS_FEATURESETTING				(0x1019)
#define GDI_GGI_MARK_NONEXISTING_GLYPHS				(0x1)
#define GDI_GGO_BEZIER						(0x3)
#define GDI_GGO_BITMAP						(0x1)
#define GDI_GGO_GLYPH_INDEX					(0x80)
#define GDI_GGO_GRAY2_BITMAP					(0x4)
#define GDI_GGO_GRAY4_BITMAP					(0x5)
#define GDI_GGO_GRAY8_BITMAP					(0x6)
#define GDI_GGO_METRICS						(0x0)
#define GDI_GGO_NATIVE						(0x2)
#define GDI_GGO_UNHINTED					(0x100)
#define GDI_GM_ADVANCED						(0x2)
#define GDI_GM_COMPATIBLE					(0x1)
#define GDI_GM_LAST						(0x2)
#define GDI_GRADIENT_FILL_OP_FLAG				(0xff)
#define GDI_GRADIENT_FILL_RECT_H				(0x0)
#define GDI_GRADIENT_FILL_RECT_V				(0x1)
#define GDI_GRADIENT_FILL_TRIANGLE				(0x2)
#define GDI_GRAY_BRUSH						(0x2)
#define GDI_GREEK_CHARSET					(0xa1)
#define GDI_GS_8BIT_INDICES					(0x1)
#define GDI_HALFTONE						(0x4)
#define GDI_HANGEUL_CHARSET					(0x81)
#define GDI_HANGUL_CHARSET					(0x81)
#define GDI_HEBREW_CHARSET					(0xb1)
#define GDI_HGDI_ERROR						(LongToHandle((0xffffffff)))
#define GDI_HOLLOW_BRUSH					NULL_BRUSH
#define GDI_HORZRES						(0x8)
#define GDI_HORZSIZE						(0x4)
#define GDI_HS_API_MAX						(0xc)
#define GDI_HS_BDIAGONAL					(0x3)
#define GDI_HS_CROSS						(0x4)
#define GDI_HS_DIAGCROSS					(0x5)
#define GDI_HS_FDIAGONAL					(0x2)
#define GDI_HS_HORIZONTAL					(0x0)
#define GDI_HS_VERTICAL						(0x1)
#define GDI_ICM_ADDPROFILE					(0x1)
#define GDI_ICM_DELETEPROFILE					(0x2)
#define GDI_ICM_DONE_OUTSIDEDC					(0x4)
#define GDI_ICM_OFF						(0x1)
#define GDI_ICM_ON						(0x2)
#define GDI_ICM_QUERY						(0x3)
#define GDI_ICM_QUERYMATCH					(0x7)
#define GDI_ICM_QUERYPROFILE					(0x3)
#define GDI_ICM_REGISTERICMATCHER				(0x5)
#define GDI_ICM_SETDEFAULTPROFILE				(0x4)
#define GDI_ICM_UNREGISTERICMATCHER				(0x6)
#define GDI_ILLUMINANT_A					(0x1)
#define GDI_ILLUMINANT_B					(0x2)
#define GDI_ILLUMINANT_C					(0x3)
#define GDI_ILLUMINANT_D50					(0x4)
#define GDI_ILLUMINANT_D55					(0x5)
#define GDI_ILLUMINANT_D65					(0x6)
#define GDI_ILLUMINANT_D75					(0x7)
#define GDI_ILLUMINANT_DAYLIGHT					ILLUMINANT_C
#define GDI_ILLUMINANT_DEVICE_DEFAULT				(0x0)
#define GDI_ILLUMINANT_F2					(0x8)
#define GDI_ILLUMINANT_FLUORESCENT				ILLUMINANT_F2
#define GDI_ILLUMINANT_MAX_INDEX				ILLUMINANT_F2
#define GDI_ILLUMINANT_NTSC					ILLUMINANT_C
#define GDI_ILLUMINANT_TUNGSTEN					ILLUMINANT_A
#define GDI_JOHAB_CHARSET					(0x82)
#define GDI_LAYOUT_BITMAPORIENTATIONPRESERVED			(0x8)
#define GDI_LAYOUT_BTT						(0x2)
#define GDI_LAYOUT_ORIENTATIONMASK				(LAYOUT_RTL|LAYOUT_BTT|LAYOUT_VBH)
#define GDI_LAYOUT_RTL						(0x1)
#define GDI_LAYOUT_VBH						(0x4)
#define GDI_LCS_CALIBRATED_RGB					(0x0)
#define GDI_LCS_GM_ABS_COLORIMETRIC				(0x8)
#define GDI_LCS_GM_BUSINESS					(0x1)
#define GDI_LCS_GM_GRAPHICS					(0x2)
#define GDI_LCS_GM_IMAGES					(0x4)
#define GDI_LCS_SIGNATURE					'PSOC'
#define GDI_LCS_S_RGB						'sRGB'
#define GDI_LCS_WINDOWS_COLOR_SPACE				'Win '
#define GDI_LC_INTERIORS					(0x80)
#define GDI_LC_MARKER						(0x4)
#define GDI_LC_NONE						(0x0)
#define GDI_LC_POLYLINE						(0x2)
#define GDI_LC_POLYMARKER					(0x8)
#define GDI_LC_STYLED						(0x20)
#define GDI_LC_WIDE						(0x10)
#define GDI_LC_WIDESTYLED					(0x40)
#define GDI_LF_FACESIZE						(0x20)
#define GDI_LF_FULLFACESIZE					(0x40)
#define GDI_LINECAPS						(0x1e)
#define GDI_LOGPIXELSX						(0x58)
#define GDI_LOGPIXELSY						(0x5a)
#define GDI_LPD_DOUBLEBUFFER					(0x1)
#define GDI_LPD_SHARE_ACCUM					(0x100)
#define GDI_LPD_SHARE_DEPTH					(0x40)
#define GDI_LPD_SHARE_STENCIL					(0x80)
#define GDI_LPD_STEREO						(0x2)
#define GDI_LPD_SUPPORT_GDI					(0x10)
#define GDI_LPD_SUPPORT_OPENGL					(0x20)
#define GDI_LPD_SWAP_COPY					(0x400)
#define GDI_LPD_SWAP_EXCHANGE					(0x200)
#define GDI_LPD_TRANSPARENT					(0x1000)
#define GDI_LPD_TYPE_COLORINDEX					(0x1)
#define GDI_LPD_TYPE_RGBA					(0x0)
#define GDI_LTGRAY_BRUSH					(0x1)
#define GDI_MAC_CHARSET						(0x4d)
#define GDI_MAXSTRETCHBLTMODE					(0x4)
#define GDI_MERGECOPY						(DWORD)(0xc000ca)
#define GDI_MERGEPAINT						(DWORD)(0xbb0226)
#define GDI_METAFILE_DRIVER					(0x801)
#define GDI_META_ANIMATEPALETTE					(0x436)
#define GDI_META_ARC						(0x817)
#define GDI_META_BITBLT						(0x922)
#define GDI_META_CHORD						(0x830)
#define GDI_META_CREATEBRUSHINDIRECT				(0x2fc)
#define GDI_META_CREATEFONTINDIRECT				(0x2fb)
#define GDI_META_CREATEPALETTE					(0xf7)
#define GDI_META_CREATEPATTERNBRUSH				(0x1f9)
#define GDI_META_CREATEPENINDIRECT				(0x2fa)
#define GDI_META_CREATEREGION					(0x6ff)
#define GDI_META_DELETEOBJECT					(0x1f0)
#define GDI_META_DIBBITBLT					(0x940)
#define GDI_META_DIBCREATEPATTERNBRUSH				(0x142)
#define GDI_META_DIBSTRETCHBLT					(0xb41)
#define GDI_META_ELLIPSE					(0x418)
#define GDI_META_ESCAPE						(0x626)
#define GDI_META_EXCLUDECLIPRECT				(0x415)
#define GDI_META_EXTFLOODFILL					(0x548)
#define GDI_META_EXTTEXTOUT					(0xa32)
#define GDI_META_FILLREGION					(0x228)
#define GDI_META_FLOODFILL					(0x419)
#define GDI_META_FRAMEREGION					(0x429)
#define GDI_META_INTERSECTCLIPRECT				(0x416)
#define GDI_META_INVERTREGION					(0x12a)
#define GDI_META_LINETO						(0x213)
#define GDI_META_MOVETO						(0x214)
#define GDI_META_OFFSETCLIPRGN					(0x220)
#define GDI_META_OFFSETVIEWPORTORG				(0x211)
#define GDI_META_OFFSETWINDOWORG				(0x20f)
#define GDI_META_PAINTREGION					(0x12b)
#define GDI_META_PATBLT						(0x61d)
#define GDI_META_PIE						(0x81a)
#define GDI_META_POLYGON					(0x324)
#define GDI_META_POLYLINE					(0x325)
#define GDI_META_POLYPOLYGON					(0x538)
#define GDI_META_REALIZEPALETTE					(0x35)
#define GDI_META_RECTANGLE					(0x41b)
#define GDI_META_RESIZEPALETTE					(0x139)
#define GDI_META_RESTOREDC					(0x127)
#define GDI_META_ROUNDRECT					(0x61c)
#define GDI_META_SAVEDC						(0x1e)
#define GDI_META_SCALEVIEWPORTEXT				(0x412)
#define GDI_META_SCALEWINDOWEXT					(0x410)
#define GDI_META_SELECTCLIPREGION				(0x12c)
#define GDI_META_SELECTOBJECT					(0x12d)
#define GDI_META_SELECTPALETTE					(0x234)
#define GDI_META_SETBKCOLOR					(0x201)
#define GDI_META_SETBKMODE					(0x102)
#define GDI_META_SETDIBTODEV					(0xd33)
#define GDI_META_SETLAYOUT					(0x149)
#define GDI_META_SETMAPMODE					(0x103)
#define GDI_META_SETMAPPERFLAGS					(0x231)
#define GDI_META_SETPALENTRIES					(0x37)
#define GDI_META_SETPIXEL					(0x41f)
#define GDI_META_SETPOLYFILLMODE				(0x106)
#define GDI_META_SETRELABS					(0x105)
#define GDI_META_SETROP2					(0x104)
#define GDI_META_SETSTRETCHBLTMODE				(0x107)
#define GDI_META_SETTEXTALIGN					(0x12e)
#define GDI_META_SETTEXTCHAREXTRA				(0x108)
#define GDI_META_SETTEXTCOLOR					(0x209)
#define GDI_META_SETTEXTJUSTIFICATION				(0x20a)
#define GDI_META_SETVIEWPORTEXT					(0x20e)
#define GDI_META_SETVIEWPORTORG					(0x20d)
#define GDI_META_SETWINDOWEXT					(0x20c)
#define GDI_META_SETWINDOWORG					(0x20b)
#define GDI_META_STRETCHBLT					(0xb23)
#define GDI_META_STRETCHDIB					(0xf43)
#define GDI_META_TEXTOUT					(0x521)
#define GDI_MFCOMMENT						(0xf)
#define GDI_MILCORE_TS_QUERYVER_RESULT_FALSE			(0x0)
#define GDI_MILCORE_TS_QUERYVER_RESULT_TRUE			(0x7fffffff)
#define GDI_MM_ANISOTROPIC					(0x8)
#define GDI_MM_HIENGLISH					(0x5)
#define GDI_MM_HIMETRIC						(0x3)
#define GDI_MM_ISOTROPIC					(0x7)
#define GDI_MM_LOENGLISH					(0x4)
#define GDI_MM_LOMETRIC						(0x2)
#define GDI_MM_MAX						MM_ANISOTROPIC
#define GDI_MM_MAX_AXES_NAMELEN					(0x10)
#define GDI_MM_MAX_FIXEDSCALE					MM_TWIPS
#define GDI_MM_MAX_NUMAXES					(0x10)
#define GDI_MM_MIN						MM_TEXT
#define GDI_MM_TEXT						(0x1)
#define GDI_MM_TWIPS						(0x6)
#define GDI_MONO_FONT						(0x8)
#define GDI_MOUSETRAILS						(0x27)
#define GDI_MWT_IDENTITY					(0x1)
#define GDI_MWT_LEFTMULTIPLY					(0x2)
#define GDI_MWT_MAX						MWT_RIGHTMULTIPLY
#define GDI_MWT_MIN						MWT_IDENTITY
#define GDI_MWT_RIGHTMULTIPLY					(0x3)
#define GDI_NEWFRAME						(0x1)
#define GDI_NEXTBAND						(0x3)
#define GDI_NOMIRRORBITMAP					(DWORD)(0x80000000)
#define GDI_NONANTIALIASED_QUALITY				(0x3)
#define GDI_NOTSRCCOPY						(DWORD)(0x330008)
#define GDI_NOTSRCERASE						(DWORD)(0x1100a6)
#define GDI_NTM_BOLD						(0x20)
#define GDI_NTM_DSIG						(0x200000)
#define GDI_NTM_ITALIC						(0x1)
#define GDI_NTM_MULTIPLEMASTER					(0x80000)
#define GDI_NTM_NONNEGATIVE_AC					(0x10000)
#define GDI_NTM_PS_OPENTYPE					(0x20000)
#define GDI_NTM_REGULAR						(0x40)
#define GDI_NTM_TT_OPENTYPE					(0x40000)
#define GDI_NTM_TYPE1						(0x100000)
#define GDI_NULLREGION						(0x1)
#define GDI_NULL_BRUSH						(0x5)
#define GDI_NULL_PEN						(0x8)
#define GDI_NUMBRUSHES						(0x10)
#define GDI_NUMCOLORS						(0x18)
#define GDI_NUMFONTS						(0x16)
#define GDI_NUMMARKERS						(0x14)
#define GDI_NUMPENS						(0x12)
#define GDI_NUMRESERVED						(0x6a)
#define GDI_OBJ_BITMAP						(0x7)
#define GDI_OBJ_BRUSH						(0x2)
#define GDI_OBJ_COLORSPACE					(0xe)
#define GDI_OBJ_DC						(0x3)
#define GDI_OBJ_ENHMETADC					(0xc)
#define GDI_OBJ_ENHMETAFILE					(0xd)
#define GDI_OBJ_EXTPEN						(0xb)
#define GDI_OBJ_FONT						(0x6)
#define GDI_OBJ_LAST						OBJ_COLORSPACE
#define GDI_OBJ_MEMDC						(0xa)
#define GDI_OBJ_METADC						(0x4)
#define GDI_OBJ_METAFILE					(0x9)
#define GDI_OBJ_PAL						(0x5)
#define GDI_OBJ_PEN						(0x1)
#define GDI_OBJ_REGION						(0x8)
#define GDI_OEM_CHARSET						(0xff)
#define GDI_OEM_FIXED_FONT					(0xa)
#define GDI_OPAQUE						(0x2)
#define GDI_OPENCHANNEL						(0x100e)
#define GDI_OUT_CHARACTER_PRECIS				(0x2)
#define GDI_OUT_DEFAULT_PRECIS					(0x0)
#define GDI_OUT_DEVICE_PRECIS					(0x5)
#define GDI_OUT_OUTLINE_PRECIS					(0x8)
#define GDI_OUT_PS_ONLY_PRECIS					(0xa)
#define GDI_OUT_RASTER_PRECIS					(0x6)
#define GDI_OUT_SCREEN_OUTLINE_PRECIS				(0x9)
#define GDI_OUT_STRING_PRECIS					(0x1)
#define GDI_OUT_STROKE_PRECIS					(0x3)
#define GDI_OUT_TT_ONLY_PRECIS					(0x7)
#define GDI_OUT_TT_PRECIS					(0x4)
#define GDI_PANOSE_COUNT					(0xa)
#define GDI_PAN_ANY						(0x0)
#define GDI_PAN_ARMSTYLE_INDEX					(0x6)
#define GDI_PAN_BENT_ARMS_DOUBLE_SERIF				(0xb)
#define GDI_PAN_BENT_ARMS_HORZ					(0x7)
#define GDI_PAN_BENT_ARMS_SINGLE_SERIF				(0xa)
#define GDI_PAN_BENT_ARMS_VERT					(0x9)
#define GDI_PAN_BENT_ARMS_WEDGE					(0x8)
#define GDI_PAN_CONTRAST_HIGH					(0x8)
#define GDI_PAN_CONTRAST_INDEX					(0x4)
#define GDI_PAN_CONTRAST_LOW					(0x4)
#define GDI_PAN_CONTRAST_MEDIUM					(0x6)
#define GDI_PAN_CONTRAST_MEDIUM_HIGH				(0x7)
#define GDI_PAN_CONTRAST_MEDIUM_LOW				(0x5)
#define GDI_PAN_CONTRAST_NONE					(0x2)
#define GDI_PAN_CONTRAST_VERY_HIGH				(0x9)
#define GDI_PAN_CONTRAST_VERY_LOW				(0x3)
#define GDI_PAN_CULTURE_LATIN					(0x0)
#define GDI_PAN_FAMILYTYPE_INDEX				(0x0)
#define GDI_PAN_FAMILY_DECORATIVE				(0x4)
#define GDI_PAN_FAMILY_PICTORIAL				(0x5)
#define GDI_PAN_FAMILY_SCRIPT					(0x3)
#define GDI_PAN_FAMILY_TEXT_DISPLAY				(0x2)
#define GDI_PAN_LETTERFORM_INDEX				(0x7)
#define GDI_PAN_LETT_NORMAL_BOXED				(0x4)
#define GDI_PAN_LETT_NORMAL_CONTACT				(0x2)
#define GDI_PAN_LETT_NORMAL_FLATTENED				(0x5)
#define GDI_PAN_LETT_NORMAL_OFF_CENTER				(0x7)
#define GDI_PAN_LETT_NORMAL_ROUNDED				(0x6)
#define GDI_PAN_LETT_NORMAL_SQUARE				(0x8)
#define GDI_PAN_LETT_NORMAL_WEIGHTED				(0x3)
#define GDI_PAN_LETT_OBLIQUE_BOXED				(0xb)
#define GDI_PAN_LETT_OBLIQUE_CONTACT				(0x9)
#define GDI_PAN_LETT_OBLIQUE_FLATTENED				(0xc)
#define GDI_PAN_LETT_OBLIQUE_OFF_CENTER				(0xe)
#define GDI_PAN_LETT_OBLIQUE_ROUNDED				(0xd)
#define GDI_PAN_LETT_OBLIQUE_SQUARE				(0xf)
#define GDI_PAN_LETT_OBLIQUE_WEIGHTED				(0xa)
#define GDI_PAN_MIDLINE_CONSTANT_POINTED			(0x9)
#define GDI_PAN_MIDLINE_CONSTANT_SERIFED			(0xa)
#define GDI_PAN_MIDLINE_CONSTANT_TRIMMED			(0x8)
#define GDI_PAN_MIDLINE_HIGH_POINTED				(0x6)
#define GDI_PAN_MIDLINE_HIGH_SERIFED				(0x7)
#define GDI_PAN_MIDLINE_HIGH_TRIMMED				(0x5)
#define GDI_PAN_MIDLINE_INDEX					(0x8)
#define GDI_PAN_MIDLINE_LOW_POINTED				(0xc)
#define GDI_PAN_MIDLINE_LOW_SERIFED				(0xd)
#define GDI_PAN_MIDLINE_LOW_TRIMMED				(0xb)
#define GDI_PAN_MIDLINE_STANDARD_POINTED			(0x3)
#define GDI_PAN_MIDLINE_STANDARD_SERIFED			(0x4)
#define GDI_PAN_MIDLINE_STANDARD_TRIMMED			(0x2)
#define GDI_PAN_NO_FIT						(0x1)
#define GDI_PAN_PROPORTION_INDEX				(0x3)
#define GDI_PAN_PROP_CONDENSED					(0x6)
#define GDI_PAN_PROP_EVEN_WIDTH					(0x4)
#define GDI_PAN_PROP_EXPANDED					(0x5)
#define GDI_PAN_PROP_MODERN					(0x3)
#define GDI_PAN_PROP_MONOSPACED					(0x9)
#define GDI_PAN_PROP_OLD_STYLE					(0x2)
#define GDI_PAN_PROP_VERY_CONDENSED				(0x8)
#define GDI_PAN_PROP_VERY_EXPANDED				(0x7)
#define GDI_PAN_SERIFSTYLE_INDEX				(0x1)
#define GDI_PAN_SERIF_BONE					(0x8)
#define GDI_PAN_SERIF_COVE					(0x2)
#define GDI_PAN_SERIF_EXAGGERATED				(0x9)
#define GDI_PAN_SERIF_FLARED					(0xe)
#define GDI_PAN_SERIF_NORMAL_SANS				(0xb)
#define GDI_PAN_SERIF_OBTUSE_COVE				(0x3)
#define GDI_PAN_SERIF_OBTUSE_SANS				(0xc)
#define GDI_PAN_SERIF_OBTUSE_SQUARE_COVE			(0x5)
#define GDI_PAN_SERIF_PERP_SANS					(0xd)
#define GDI_PAN_SERIF_ROUNDED					(0xf)
#define GDI_PAN_SERIF_SQUARE					(0x6)
#define GDI_PAN_SERIF_SQUARE_COVE				(0x4)
#define GDI_PAN_SERIF_THIN					(0x7)
#define GDI_PAN_SERIF_TRIANGLE					(0xa)
#define GDI_PAN_STRAIGHT_ARMS_DOUBLE_SERIF			(0x6)
#define GDI_PAN_STRAIGHT_ARMS_HORZ				(0x2)
#define GDI_PAN_STRAIGHT_ARMS_SINGLE_SERIF			(0x5)
#define GDI_PAN_STRAIGHT_ARMS_VERT				(0x4)
#define GDI_PAN_STRAIGHT_ARMS_WEDGE				(0x3)
#define GDI_PAN_STROKEVARIATION_INDEX				(0x5)
#define GDI_PAN_STROKE_GRADUAL_DIAG				(0x2)
#define GDI_PAN_STROKE_GRADUAL_HORZ				(0x5)
#define GDI_PAN_STROKE_GRADUAL_TRAN				(0x3)
#define GDI_PAN_STROKE_GRADUAL_VERT				(0x4)
#define GDI_PAN_STROKE_INSTANT_VERT				(0x8)
#define GDI_PAN_STROKE_RAPID_HORZ				(0x7)
#define GDI_PAN_STROKE_RAPID_VERT				(0x6)
#define GDI_PAN_WEIGHT_BLACK					(0xa)
#define GDI_PAN_WEIGHT_BOLD					(0x8)
#define GDI_PAN_WEIGHT_BOOK					(0x5)
#define GDI_PAN_WEIGHT_DEMI					(0x7)
#define GDI_PAN_WEIGHT_HEAVY					(0x9)
#define GDI_PAN_WEIGHT_INDEX					(0x2)
#define GDI_PAN_WEIGHT_LIGHT					(0x3)
#define GDI_PAN_WEIGHT_MEDIUM					(0x6)
#define GDI_PAN_WEIGHT_NORD					(0xb)
#define GDI_PAN_WEIGHT_THIN					(0x4)
#define GDI_PAN_WEIGHT_VERY_LIGHT				(0x2)
#define GDI_PAN_XHEIGHT_CONSTANT_LARGE				(0x4)
#define GDI_PAN_XHEIGHT_CONSTANT_SMALL				(0x2)
#define GDI_PAN_XHEIGHT_CONSTANT_STD				(0x3)
#define GDI_PAN_XHEIGHT_DUCKING_LARGE				(0x7)
#define GDI_PAN_XHEIGHT_DUCKING_SMALL				(0x5)
#define GDI_PAN_XHEIGHT_DUCKING_STD				(0x6)
#define GDI_PAN_XHEIGHT_INDEX					(0x9)
#define GDI_PASSTHROUGH						(0x13)
#define GDI_PATCOPY						(DWORD)(0xf00021)
#define GDI_PATINVERT						(DWORD)(0x5a0049)
#define GDI_PATPAINT						(DWORD)(0xfb0a09)
#define GDI_PC_EXPLICIT						(0x2)
#define GDI_PC_INTERIORS					(0x80)
#define GDI_PC_NOCOLLAPSE					(0x4)
#define GDI_PC_NONE						(0x0)
#define GDI_PC_PATHS						(0x200)
#define GDI_PC_POLYGON						(0x1)
#define GDI_PC_POLYPOLYGON					(0x100)
#define GDI_PC_RECTANGLE					(0x2)
#define GDI_PC_RESERVED						(0x1)
#define GDI_PC_SCANLINE						(0x8)
#define GDI_PC_STYLED						(0x20)
#define GDI_PC_TRAPEZOID					(0x4)
#define GDI_PC_WIDE						(0x10)
#define GDI_PC_WIDESTYLED					(0x40)
#define GDI_PC_WINDPOLYGON					(0x4)
#define GDI_PDEVICESIZE						(0x1a)
#define GDI_PFD_DEPTH_DONTCARE					(0x20000000)
#define GDI_PFD_DIRECT3D_ACCELERATED				(0x4000)
#define GDI_PFD_DOUBLEBUFFER					(0x1)
#define GDI_PFD_DOUBLEBUFFER_DONTCARE				(0x40000000)
#define GDI_PFD_DRAW_TO_BITMAP					(0x8)
#define GDI_PFD_DRAW_TO_WINDOW					(0x4)
#define GDI_PFD_GENERIC_ACCELERATED				(0x1000)
#define GDI_PFD_GENERIC_FORMAT					(0x40)
#define GDI_PFD_MAIN_PLANE					(0x0)
#define GDI_PFD_NEED_PALETTE					(0x80)
#define GDI_PFD_NEED_SYSTEM_PALETTE				(0x100)
#define GDI_PFD_OVERLAY_PLANE					(0x1)
#define GDI_PFD_STEREO						(0x2)
#define GDI_PFD_STEREO_DONTCARE					(0x80000000)
#define GDI_PFD_SUPPORT_COMPOSITION				(0x8000)
#define GDI_PFD_SUPPORT_DIRECTDRAW				(0x2000)
#define GDI_PFD_SUPPORT_GDI					(0x10)
#define GDI_PFD_SUPPORT_OPENGL					(0x20)
#define GDI_PFD_SWAP_COPY					(0x400)
#define GDI_PFD_SWAP_EXCHANGE					(0x200)
#define GDI_PFD_SWAP_LAYER_BUFFERS				(0x800)
#define GDI_PFD_TYPE_COLORINDEX					(0x1)
#define GDI_PFD_TYPE_RGBA					(0x0)
#define GDI_PFD_UNDERLAY_PLANE					(-(0x1))
#define GDI_PHYSICALHEIGHT					(0x6f)
#define GDI_PHYSICALOFFSETX					(0x70)
#define GDI_PHYSICALOFFSETY					(0x71)
#define GDI_PHYSICALWIDTH					(0x6e)
#define GDI_PLANES						(0xe)
#define GDI_POLYFILL_LAST					(0x2)
#define GDI_POLYGONALCAPS					(0x20)
#define GDI_POSTSCRIPT_DATA					(0x25)
#define GDI_POSTSCRIPT_IDENTIFY					(0x1015)
#define GDI_POSTSCRIPT_IGNORE					(0x26)
#define GDI_POSTSCRIPT_INJECTION				(0x1016)
#define GDI_POSTSCRIPT_PASSTHROUGH				(0x1013)
#define GDI_PRINTRATEUNIT_CPS					(0x2)
#define GDI_PRINTRATEUNIT_IPM					(0x4)
#define GDI_PRINTRATEUNIT_LPM					(0x3)
#define GDI_PRINTRATEUNIT_PPM					(0x1)
#define GDI_PROFILE_EMBEDDED					'MBED'
#define GDI_PROFILE_LINKED					'LINK'
#define GDI_PROOF_QUALITY					(0x2)
#define GDI_PR_JOBSTATUS					(0x0)
#define GDI_PSIDENT_GDICENTRIC					(0x0)
#define GDI_PSIDENT_PSCENTRIC					(0x1)
#define GDI_PSINJECT_BEGINDEFAULTS				(0xc)
#define GDI_PSINJECT_BEGINPAGESETUP				(0x65)
#define GDI_PSINJECT_BEGINPROLOG				(0xe)
#define GDI_PSINJECT_BEGINSETUP					(0x10)
#define GDI_PSINJECT_BEGINSTREAM				(0x1)
#define GDI_PSINJECT_BOUNDINGBOX				(0x9)
#define GDI_PSINJECT_COMMENTS					(0xb)
#define GDI_PSINJECT_DLFONT					(0xdddddddd)
#define GDI_PSINJECT_DOCNEEDEDRES				(0x5)
#define GDI_PSINJECT_DOCSUPPLIEDRES				(0x6)
#define GDI_PSINJECT_DOCUMENTPROCESSCOLORS			(0xa)
#define GDI_PSINJECT_DOCUMENTPROCESSCOLORSATEND			(0x15)
#define GDI_PSINJECT_ENDDEFAULTS				(0xd)
#define GDI_PSINJECT_ENDPAGECOMMENTS				(0x6b)
#define GDI_PSINJECT_ENDPAGESETUP				(0x66)
#define GDI_PSINJECT_ENDPROLOG					(0xf)
#define GDI_PSINJECT_ENDSETUP					(0x11)
#define GDI_PSINJECT_ENDSTREAM					(0x14)
#define GDI_PSINJECT_EOF					(0x13)
#define GDI_PSINJECT_ORIENTATION				(0x8)
#define GDI_PSINJECT_PAGEBBOX					(0x6a)
#define GDI_PSINJECT_PAGENUMBER					(0x64)
#define GDI_PSINJECT_PAGEORDER					(0x7)
#define GDI_PSINJECT_PAGES					(0x4)
#define GDI_PSINJECT_PAGESATEND					(0x3)
#define GDI_PSINJECT_PAGETRAILER				(0x67)
#define GDI_PSINJECT_PLATECOLOR					(0x68)
#define GDI_PSINJECT_PSADOBE					(0x2)
#define GDI_PSINJECT_SHOWPAGE					(0x69)
#define GDI_PSINJECT_TRAILER					(0x12)
#define GDI_PSINJECT_VMRESTORE					(0xc9)
#define GDI_PSINJECT_VMSAVE					(0xc8)
#define GDI_PSPROTOCOL_ASCII					(0x0)
#define GDI_PSPROTOCOL_BCP					(0x1)
#define GDI_PSPROTOCOL_BINARY					(0x3)
#define GDI_PSPROTOCOL_TBCP					(0x2)
#define GDI_PS_ALTERNATE					(0x8)
#define GDI_PS_COSMETIC						(0x0)
#define GDI_PS_DASH						(0x1)
#define GDI_PS_DASHDOT						(0x3)
#define GDI_PS_DASHDOTDOT					(0x4)
#define GDI_PS_DOT						(0x2)
#define GDI_PS_ENDCAP_FLAT					(0x200)
#define GDI_PS_ENDCAP_MASK					(0xf00)
#define GDI_PS_ENDCAP_ROUND					(0x0)
#define GDI_PS_ENDCAP_SQUARE					(0x100)
#define GDI_PS_GEOMETRIC					(0x10000)
#define GDI_PS_INSIDEFRAME					(0x6)
#define GDI_PS_JOIN_BEVEL					(0x1000)
#define GDI_PS_JOIN_MASK					(0xf000)
#define GDI_PS_JOIN_MITER					(0x2000)
#define GDI_PS_JOIN_ROUND					(0x0)
#define GDI_PS_NULL						(0x5)
#define GDI_PS_SOLID						(0x0)
#define GDI_PS_STYLE_MASK					(0xf)
#define GDI_PS_TYPE_MASK					(0xf0000)
#define GDI_PS_USERSTYLE					(0x7)
#define GDI_PT_BEZIERTO						(0x4)
#define GDI_PT_CLOSEFIGURE					(0x1)
#define GDI_PT_LINETO						(0x2)
#define GDI_PT_MOVETO						(0x6)
#define GDI_QDC_ALL_PATHS					(0x1)
#define GDI_QDC_DATABASE_CURRENT				(0x4)
#define GDI_QDC_ONLY_ACTIVE_PATHS				(0x2)
#define GDI_QDI_DIBTOSCREEN					(0x4)
#define GDI_QDI_GETDIBITS					(0x2)
#define GDI_QDI_SETDIBITS					(0x1)
#define GDI_QDI_STRETCHDIB					(0x8)
#define GDI_QUERYDIBSUPPORT					(0xc01)
#define GDI_QUERYESCSUPPORT					(0x8)
#define GDI_R2_BLACK						(0x1)
#define GDI_R2_COPYPEN						(0xd)
#define GDI_R2_LAST						(0x10)
#define GDI_R2_MASKNOTPEN					(0x3)
#define GDI_R2_MASKPEN						(0x9)
#define GDI_R2_MASKPENNOT					(0x5)
#define GDI_R2_MERGENOTPEN					(0xc)
#define GDI_R2_MERGEPEN						(0xf)
#define GDI_R2_MERGEPENNOT					(0xe)
#define GDI_R2_NOP						(0xb)
#define GDI_R2_NOT						(0x6)
#define GDI_R2_NOTCOPYPEN					(0x4)
#define GDI_R2_NOTMASKPEN					(0x8)
#define GDI_R2_NOTMERGEPEN					(0x2)
#define GDI_R2_NOTXORPEN					(0xa)
#define GDI_R2_WHITE						(0x10)
#define GDI_R2_XORPEN						(0x7)
#define GDI_RASTERCAPS						(0x26)
#define GDI_RASTER_FONTTYPE					(0x1)
#define GDI_RC_BANDING						(0x2)
#define GDI_RC_BIGFONT						(0x400)
#define GDI_RC_BITBLT						(0x1)
#define GDI_RC_BITMAP64						(0x8)
#define GDI_RC_DEVBITS						(0x8000)
#define GDI_RC_DIBTODEV						(0x200)
#define GDI_RC_DI_BITMAP					(0x80)
#define GDI_RC_FLOODFILL					(0x1000)
#define GDI_RC_GDI20_OUTPUT					(0x10)
#define GDI_RC_GDI20_STATE					(0x20)
#define GDI_RC_NONE
#define GDI_RC_OP_DX_OUTPUT					(0x4000)
#define GDI_RC_PALETTE						(0x100)
#define GDI_RC_SAVEBITMAP					(0x40)
#define GDI_RC_SCALING						(0x4)
#define GDI_RC_STRETCHBLT					(0x800)
#define GDI_RC_STRETCHDIB					(0x2000)
#define GDI_RDH_RECTANGLES					(0x1)
#define GDI_REFERENCE_BLACK_MAX					(WORD)(0xfa0)
#define GDI_REFERENCE_BLACK_MIN					(WORD)(0x0)
#define GDI_REFERENCE_WHITE_MAX					(WORD)(0x2710)
#define GDI_REFERENCE_WHITE_MIN					(WORD)(0x1770)
#define GDI_RELATIVE						(0x2)
#define GDI_RESTORE_CTM						(0x1004)
#define GDI_RGB_GAMMA_MAX					(WORD)(0xfde8)
#define GDI_RGB_GAMMA_MIN					(WORD)(0x9c4)
#define GDI_RGN_AND						(0x1)
#define GDI_RGN_COPY						(0x5)
#define GDI_RGN_DIFF						(0x4)
#define GDI_RGN_ERROR						ERROR
#define GDI_RGN_MAX						RGN_COPY
#define GDI_RGN_MIN						RGN_AND
#define GDI_RGN_OR						(0x2)
#define GDI_RGN_XOR						(0x3)
#define GDI_RUSSIAN_CHARSET					(0xcc)
#define GDI_SAVE_CTM						(0x1005)
#define GDI_SB_CONST_ALPHA					(0x1)
#define GDI_SB_GRAD_RECT					(0x10)
#define GDI_SB_GRAD_TRI						(0x20)
#define GDI_SB_NONE						(0x0)
#define GDI_SB_PIXEL_ALPHA					(0x2)
#define GDI_SB_PREMULT_ALPHA					(0x4)
#define GDI_SCALINGFACTORX					(0x72)
#define GDI_SCALINGFACTORY					(0x73)
#define GDI_SDC_ALLOW_CHANGES					(0x400)
#define GDI_SDC_ALLOW_PATH_ORDER_CHANGES			(0x2000)
#define GDI_SDC_APPLY						(0x80)
#define GDI_SDC_FORCE_MODE_ENUMERATION				(0x1000)
#define GDI_SDC_NO_OPTIMIZATION					(0x100)
#define GDI_SDC_PATH_PERSIST_IF_REQUIRED			(0x800)
#define GDI_SDC_SAVE_TO_DATABASE				(0x200)
#define GDI_SDC_TOPOLOGY_CLONE					(0x2)
#define GDI_SDC_TOPOLOGY_EXTEND					(0x4)
#define GDI_SDC_TOPOLOGY_EXTERNAL				(0x8)
#define GDI_SDC_TOPOLOGY_INTERNAL				(0x1)
#define GDI_SDC_TOPOLOGY_SUPPLIED				(0x10)
#define GDI_SDC_USE_DATABASE_CURRENT				(SDC_TOPOLOGY_INTERNAL|SDC_TOPOLOGY_CLONE|SDC_TOPOLOGY_EXTEND|SDC_TOPOLOGY_EXTERNAL)
#define GDI_SDC_USE_SUPPLIED_DISPLAY_CONFIG			(0x20)
#define GDI_SDC_VALIDATE					(0x40)
#define GDI_SELECTPAPERSOURCE					(0x12)
#define GDI_SETABORTPROC					(0x9)
#define GDI_SETALLJUSTVALUES					(0x303)
#define GDI_SETCHARSET						(0x304)
#define GDI_SETCOLORTABLE					(0x4)
#define GDI_SETCOPYCOUNT					(0x11)
#define GDI_SETDIBSCALING					(0x20)
#define GDI_SETICMPROFILE_EMBEDED				(0x1)
#define GDI_SETKERNTRACK					(0x302)
#define GDI_SETLINECAP						(0x15)
#define GDI_SETLINEJOIN						(0x16)
#define GDI_SETMITERLIMIT					(0x17)
#define GDI_SET_ARC_DIRECTION					(0x1006)
#define GDI_SET_BACKGROUND_COLOR				(0x1007)
#define GDI_SET_BOUNDS						(0x100d)
#define GDI_SET_CLIP_BOX					(0x100c)
#define GDI_SET_MIRROR_MODE					(0x100e)
#define GDI_SET_POLY_MODE					(0x1008)
#define GDI_SET_SCREEN_ANGLE					(0x1009)
#define GDI_SET_SPREAD						(0x100a)
#define GDI_SHADEBLENDCAPS					(0x78)
#define GDI_SHIFTJIS_CHARSET					(0x80)
#define GDI_SIMPLEREGION					(0x2)
#define GDI_SIZEPALETTE						(0x68)
#define GDI_SPCLPASSTHROUGH2					(0x11d8)
#define GDI_SP_APPABORT						(-(0x2))
#define GDI_SP_ERROR						(-(0x1))
#define GDI_SP_NOTREPORTED					(0x4000)
#define GDI_SP_OUTOFDISK					(-(0x4))
#define GDI_SP_OUTOFMEMORY					(-(0x5))
#define GDI_SP_USERABORT					(-(0x3))
#define GDI_SRCAND						(DWORD)(0x8800c6)
#define GDI_SRCCOPY						(DWORD)(0xcc0020)
#define GDI_SRCERASE						(DWORD)(0x440328)
#define GDI_SRCINVERT						(DWORD)(0x660046)
#define GDI_SRCPAINT						(DWORD)(0xee0086)
#define GDI_STAMP_AXESLIST					((0x8000000)+'a'+('l'<<(0x8)))
#define GDI_STAMP_DESIGNVECTOR					((0x8000000)+'d'+('v'<<(0x8)))
#define GDI_STARTDOC						(0xa)
#define GDI_STOCK_LAST						(0x13)
#define GDI_STRETCHBLT						(0x800)
#define GDI_STRETCH_ANDSCANS					BLACKONWHITE
#define GDI_STRETCH_DELETESCANS					COLORONCOLOR
#define GDI_STRETCH_HALFTONE					HALFTONE
#define GDI_STRETCH_ORSCANS					WHITEONBLACK
#define GDI_SYMBOL_CHARSET					(0x2)
#define GDI_SYSPAL_ERROR					(0x0)
#define GDI_SYSPAL_NOSTATIC					(0x2)
#define GDI_SYSPAL_NOSTATIC256					(0x3)
#define GDI_SYSPAL_STATIC					(0x1)
#define GDI_SYSRGN						(0x4)
#define GDI_SYSTEM_FIXED_FONT					(0x10)
#define GDI_SYSTEM_FONT						(0xd)
#define GDI_TA_BASELINE						(0x18)
#define GDI_TA_BOTTOM						(0x8)
#define GDI_TA_CENTER						(0x6)
#define GDI_TA_LEFT						(0x0)
#define GDI_TA_MASK						(TA_BASELINE+TA_CENTER+TA_UPDATECP+TA_RTLREADING)
#define GDI_TA_NOUPDATECP					(0x0)
#define GDI_TA_RIGHT						(0x2)
#define GDI_TA_RTLREADING					(0x100)
#define GDI_TA_TOP						(0x0)
#define GDI_TA_UPDATECP						(0x1)
#define GDI_TCI_SRCCHARSET					(0x1)
#define GDI_TCI_SRCCODEPAGE					(0x2)
#define GDI_TCI_SRCFONTSIG					(0x3)
#define GDI_TCI_SRCLOCALE					(0x1000)
#define GDI_TC_CP_STROKE					(0x4)
#define GDI_TC_CR_90						(0x8)
#define GDI_TC_CR_ANY						(0x10)
#define GDI_TC_EA_DOUBLE					(0x200)
#define GDI_TC_IA_ABLE						(0x400)
#define GDI_TC_OP_CHARACTER					(0x1)
#define GDI_TC_OP_STROKE					(0x2)
#define GDI_TC_RA_ABLE						(0x2000)
#define GDI_TC_RESERVED						(0x8000)
#define GDI_TC_SA_CONTIN					(0x100)
#define GDI_TC_SA_DOUBLE					(0x40)
#define GDI_TC_SA_INTEGER					(0x80)
#define GDI_TC_SCROLLBLT					(0x10000)
#define GDI_TC_SF_X_YINDEP					(0x20)
#define GDI_TC_SO_ABLE						(0x1000)
#define GDI_TC_UA_ABLE						(0x800)
#define GDI_TC_VA_ABLE						(0x4000)
#define GDI_TECHNOLOGY						(0x2)
#define GDI_TEXTCAPS						(0x22)
#define GDI_THAI_CHARSET					(0xde)
#define GDI_TMPF_DEVICE						(0x8)
#define GDI_TMPF_FIXED_PITCH					(0x1)
#define GDI_TMPF_TRUETYPE					(0x4)
#define GDI_TMPF_VECTOR						(0x2)
#define GDI_TRANSFORM_CTM					(0x100b)
#define GDI_TRANSPARENT						(0x1)
#define GDI_TRUETYPE_FONTTYPE					(0x4)
#define GDI_TT_AVAILABLE					(0x1)
#define GDI_TT_ENABLED						(0x2)
#define GDI_TT_POLYGON_TYPE					(0x18)
#define GDI_TT_PRIM_CSPLINE					(0x3)
#define GDI_TT_PRIM_LINE					(0x1)
#define GDI_TT_PRIM_QSPLINE					(0x2)
#define GDI_TURKISH_CHARSET					(0xa2)
#define GDI_VARIABLE_PITCH					(0x2)
#define GDI_VERTRES						(0xa)
#define GDI_VERTSIZE						(0x6)
#define GDI_VIETNAMESE_CHARSET					(0xa3)
#define GDI_VREFRESH						(0x74)
#define GDI_VTA_BASELINE					TA_BASELINE
#define GDI_VTA_BOTTOM						TA_RIGHT
#define GDI_VTA_CENTER						TA_CENTER
#define GDI_VTA_LEFT						TA_BOTTOM
#define GDI_VTA_RIGHT						TA_TOP
#define GDI_VTA_TOP						TA_LEFT
#define GDI_WGL_FONT_LINES					(0x0)
#define GDI_WGL_FONT_POLYGONS					(0x1)
#define GDI_WGL_SWAPMULTIPLE_MAX				(0x10)
#define GDI_WGL_SWAP_MAIN_PLANE					(0x1)
#define GDI_WGL_SWAP_OVERLAY1					(0x2)
#define GDI_WGL_SWAP_OVERLAY10					(0x400)
#define GDI_WGL_SWAP_OVERLAY11					(0x800)
#define GDI_WGL_SWAP_OVERLAY12					(0x1000)
#define GDI_WGL_SWAP_OVERLAY13					(0x2000)
#define GDI_WGL_SWAP_OVERLAY14					(0x4000)
#define GDI_WGL_SWAP_OVERLAY15					(0x8000)
#define GDI_WGL_SWAP_OVERLAY2					(0x4)
#define GDI_WGL_SWAP_OVERLAY3					(0x8)
#define GDI_WGL_SWAP_OVERLAY4					(0x10)
#define GDI_WGL_SWAP_OVERLAY5					(0x20)
#define GDI_WGL_SWAP_OVERLAY6					(0x40)
#define GDI_WGL_SWAP_OVERLAY7					(0x80)
#define GDI_WGL_SWAP_OVERLAY8					(0x100)
#define GDI_WGL_SWAP_OVERLAY9					(0x200)
#define GDI_WGL_SWAP_UNDERLAY1					(0x10000)
#define GDI_WGL_SWAP_UNDERLAY10					(0x2000000)
#define GDI_WGL_SWAP_UNDERLAY11					(0x4000000)
#define GDI_WGL_SWAP_UNDERLAY12					(0x8000000)
#define GDI_WGL_SWAP_UNDERLAY13					(0x10000000)
#define GDI_WGL_SWAP_UNDERLAY14					(0x20000000)
#define GDI_WGL_SWAP_UNDERLAY15					(0x40000000)
#define GDI_WGL_SWAP_UNDERLAY2					(0x20000)
#define GDI_WGL_SWAP_UNDERLAY3					(0x40000)
#define GDI_WGL_SWAP_UNDERLAY4					(0x80000)
#define GDI_WGL_SWAP_UNDERLAY5					(0x100000)
#define GDI_WGL_SWAP_UNDERLAY6					(0x200000)
#define GDI_WGL_SWAP_UNDERLAY7					(0x400000)
#define GDI_WGL_SWAP_UNDERLAY8					(0x800000)
#define GDI_WGL_SWAP_UNDERLAY9					(0x1000000)
#define GDI_WHITENESS						(DWORD)(0xff0062)
#define GDI_WHITEONBLACK					(0x2)
#define GDI_WHITE_BRUSH						(0x0)
#define GDI_WHITE_PEN						(0x6)
#define GDI_WINDING						(0x2)




#define ABORTDOC						GDI_ABORTDOC
#define ABSOLUTE						GDI_ABSOLUTE
#define AC_SRC_ALPHA						GDI_AC_SRC_ALPHA
#define AC_SRC_OVER						GDI_AC_SRC_OVER
#define AD_CLOCKWISE						GDI_AD_CLOCKWISE
#define AD_COUNTERCLOCKWISE					GDI_AD_COUNTERCLOCKWISE
#define ALTERNATE						GDI_ALTERNATE
#define ANSI_CHARSET						GDI_ANSI_CHARSET
#define ANSI_FIXED_FONT						GDI_ANSI_FIXED_FONT
#define ANSI_VAR_FONT						GDI_ANSI_VAR_FONT
#define ANTIALIASED_QUALITY					GDI_ANTIALIASED_QUALITY
#define ARABIC_CHARSET						GDI_ARABIC_CHARSET
#define ASPECTX							GDI_ASPECTX
#define ASPECTXY						GDI_ASPECTXY
#define ASPECTY							GDI_ASPECTY
#define ASPECT_FILTERING					GDI_ASPECT_FILTERING
#define BALTIC_CHARSET						GDI_BALTIC_CHARSET
#define BANDINFO						GDI_BANDINFO
#define BEGIN_PATH						GDI_BEGIN_PATH
#define BITSPIXEL						GDI_BITSPIXEL
#define BI_BITFIELDS						GDI_BI_BITFIELDS
#define BI_JPEG							GDI_BI_JPEG
#define BI_PNG							GDI_BI_PNG
#define BI_RGB							GDI_BI_RGB
#define BI_RLE4							GDI_BI_RLE4
#define BI_RLE8							GDI_BI_RLE8
#define BKMODE_LAST						GDI_BKMODE_LAST
#define BLACKNESS						GDI_BLACKNESS
#define BLACKONWHITE						GDI_BLACKONWHITE
#define BLACK_BRUSH						GDI_BLACK_BRUSH
#define BLACK_PEN						GDI_BLACK_PEN
#define BLTALIGNMENT						GDI_BLTALIGNMENT
#define BS_DIBPATTERN						GDI_BS_DIBPATTERN
#define BS_DIBPATTERN8X8					GDI_BS_DIBPATTERN8X8
#define BS_DIBPATTERNPT						GDI_BS_DIBPATTERNPT
#define BS_HATCHED						GDI_BS_HATCHED
#define BS_HOLLOW						GDI_BS_HOLLOW
#define BS_INDEXED						GDI_BS_INDEXED
#define BS_MONOPATTERN						GDI_BS_MONOPATTERN
#define BS_NULL							GDI_BS_NULL
#define BS_PATTERN						GDI_BS_PATTERN
#define BS_PATTERN8X8						GDI_BS_PATTERN8X8
#define BS_SOLID						GDI_BS_SOLID
#define CAPTUREBLT						GDI_CAPTUREBLT
#define CA_LOG_FILTER						GDI_CA_LOG_FILTER
#define CA_NEGATIVE						GDI_CA_NEGATIVE
#define CBM_INIT						GDI_CBM_INIT
#define CCHDEVICENAME						GDI_CCHDEVICENAME
#define CCHFORMNAME						GDI_CCHFORMNAME
#define CC_CHORD						GDI_CC_CHORD
#define CC_CIRCLES						GDI_CC_CIRCLES
#define CC_ELLIPSES						GDI_CC_ELLIPSES
#define CC_INTERIORS						GDI_CC_INTERIORS
#define CC_NONE							GDI_CC_NONE
#define CC_PIE							GDI_CC_PIE
#define CC_ROUNDRECT						GDI_CC_ROUNDRECT
#define CC_STYLED						GDI_CC_STYLED
#define CC_WIDE							GDI_CC_WIDE
#define CC_WIDESTYLED						GDI_CC_WIDESTYLED
#define CHECKJPEGFORMAT						GDI_CHECKJPEGFORMAT
#define CHECKPNGFORMAT						GDI_CHECKPNGFORMAT
#define CHINESEBIG5_CHARSET					GDI_CHINESEBIG5_CHARSET
#define CLEARTYPE_NATURAL_QUALITY				GDI_CLEARTYPE_NATURAL_QUALITY
#define CLEARTYPE_QUALITY					GDI_CLEARTYPE_QUALITY
#define CLIPCAPS						GDI_CLIPCAPS
#define CLIP_CHARACTER_PRECIS					GDI_CLIP_CHARACTER_PRECIS
#define CLIP_DEFAULT_PRECIS					GDI_CLIP_DEFAULT_PRECIS
#define CLIP_DFA_DISABLE					GDI_CLIP_DFA_DISABLE
#define CLIP_EMBEDDED						GDI_CLIP_EMBEDDED
#define CLIP_LH_ANGLES						GDI_CLIP_LH_ANGLES
#define CLIP_MASK						GDI_CLIP_MASK
#define CLIP_STROKE_PRECIS					GDI_CLIP_STROKE_PRECIS
#define CLIP_TO_PATH						GDI_CLIP_TO_PATH
#define CLIP_TT_ALWAYS						GDI_CLIP_TT_ALWAYS
#define CLOSECHANNEL						GDI_CLOSECHANNEL
#define CLR_INVALID						GDI_CLR_INVALID
#define CM_CMYK_COLOR						GDI_CM_CMYK_COLOR
#define CM_DEVICE_ICM						GDI_CM_DEVICE_ICM
#define CM_GAMMA_RAMP						GDI_CM_GAMMA_RAMP
#define CM_IN_GAMUT						GDI_CM_IN_GAMUT
#define CM_NONE							GDI_CM_NONE
#define CM_OUT_OF_GAMUT						GDI_CM_OUT_OF_GAMUT
#define COLORMATCHTOTARGET_EMBEDED				GDI_COLORMATCHTOTARGET_EMBEDED
#define COLORMGMTCAPS						GDI_COLORMGMTCAPS
#define COLORONCOLOR						GDI_COLORONCOLOR
#define COLORRES						GDI_COLORRES
#define COLOR_ADJ_MAX						GDI_COLOR_ADJ_MAX
#define COLOR_ADJ_MIN						GDI_COLOR_ADJ_MIN
#define COMPLEXREGION						GDI_COMPLEXREGION
#define CP_NONE							GDI_CP_NONE
#define CP_RECTANGLE						GDI_CP_RECTANGLE
#define CP_REGION						GDI_CP_REGION
#define CREATECOLORSPACE_EMBEDED				GDI_CREATECOLORSPACE_EMBEDED
#define CS_DELETE_TRANSFORM					GDI_CS_DELETE_TRANSFORM
#define CS_DISABLE						GDI_CS_DISABLE
#define CS_ENABLE						GDI_CS_ENABLE
#define CURVECAPS						GDI_CURVECAPS
#define DCBA_FACEDOWNCENTER					GDI_DCBA_FACEDOWNCENTER
#define DCBA_FACEDOWNLEFT					GDI_DCBA_FACEDOWNLEFT
#define DCBA_FACEDOWNNONE					GDI_DCBA_FACEDOWNNONE
#define DCBA_FACEDOWNRIGHT					GDI_DCBA_FACEDOWNRIGHT
#define DCBA_FACEUPCENTER					GDI_DCBA_FACEUPCENTER
#define DCBA_FACEUPLEFT						GDI_DCBA_FACEUPLEFT
#define DCBA_FACEUPNONE						GDI_DCBA_FACEUPNONE
#define DCBA_FACEUPRIGHT					GDI_DCBA_FACEUPRIGHT
#define DCB_ACCUMULATE						GDI_DCB_ACCUMULATE
#define DCB_DIRTY						GDI_DCB_DIRTY
#define DCB_DISABLE						GDI_DCB_DISABLE
#define DCB_ENABLE						GDI_DCB_ENABLE
#define DCB_RESET						GDI_DCB_RESET
#define DCB_SET							GDI_DCB_SET
#define DCTT_BITMAP						GDI_DCTT_BITMAP
#define DCTT_DOWNLOAD						GDI_DCTT_DOWNLOAD
#define DCTT_DOWNLOAD_OUTLINE					GDI_DCTT_DOWNLOAD_OUTLINE
#define DCTT_SUBDEV						GDI_DCTT_SUBDEV
#define DC_BINADJUST						GDI_DC_BINADJUST
#define DC_BINNAMES						GDI_DC_BINNAMES
#define DC_BINS							GDI_DC_BINS
#define DC_BRUSH						GDI_DC_BRUSH
#define DC_COLLATE						GDI_DC_COLLATE
#define DC_COLORDEVICE						GDI_DC_COLORDEVICE
#define DC_COPIES						GDI_DC_COPIES
#define DC_DATATYPE_PRODUCED					GDI_DC_DATATYPE_PRODUCED
#define DC_DRIVER						GDI_DC_DRIVER
#define DC_DUPLEX						GDI_DC_DUPLEX
#define DC_EMF_COMPLIANT					GDI_DC_EMF_COMPLIANT
#define DC_ENUMRESOLUTIONS					GDI_DC_ENUMRESOLUTIONS
#define DC_EXTRA						GDI_DC_EXTRA
#define DC_FIELDS						GDI_DC_FIELDS
#define DC_FILEDEPENDENCIES					GDI_DC_FILEDEPENDENCIES
#define DC_MANUFACTURER						GDI_DC_MANUFACTURER
#define DC_MAXEXTENT						GDI_DC_MAXEXTENT
#define DC_MEDIAREADY						GDI_DC_MEDIAREADY
#define DC_MEDIATYPENAMES					GDI_DC_MEDIATYPENAMES
#define DC_MEDIATYPES						GDI_DC_MEDIATYPES
#define DC_MINEXTENT						GDI_DC_MINEXTENT
#define DC_MODEL						GDI_DC_MODEL
#define DC_NUP							GDI_DC_NUP
#define DC_ORIENTATION						GDI_DC_ORIENTATION
#define DC_PAPERNAMES						GDI_DC_PAPERNAMES
#define DC_PAPERS						GDI_DC_PAPERS
#define DC_PAPERSIZE						GDI_DC_PAPERSIZE
#define DC_PEN							GDI_DC_PEN
#define DC_PERSONALITY						GDI_DC_PERSONALITY
#define DC_PRINTERMEM						GDI_DC_PRINTERMEM
#define DC_PRINTRATE						GDI_DC_PRINTRATE
#define DC_PRINTRATEPPM						GDI_DC_PRINTRATEPPM
#define DC_PRINTRATEUNIT					GDI_DC_PRINTRATEUNIT
#define DC_SIZE							GDI_DC_SIZE
#define DC_STAPLE						GDI_DC_STAPLE
#define DC_TRUETYPE						GDI_DC_TRUETYPE
#define DC_VERSION						GDI_DC_VERSION
#define DEFAULT_CHARSET						GDI_DEFAULT_CHARSET
#define DEFAULT_GUI_FONT					GDI_DEFAULT_GUI_FONT
#define DEFAULT_PALETTE						GDI_DEFAULT_PALETTE
#define DEFAULT_PITCH						GDI_DEFAULT_PITCH
#define DEFAULT_QUALITY						GDI_DEFAULT_QUALITY
#define DESKTOPHORZRES						GDI_DESKTOPHORZRES
#define DESKTOPVERTRES						GDI_DESKTOPVERTRES
#define DEVICEDATA						GDI_DEVICEDATA
#define DEVICE_DEFAULT_FONT					GDI_DEVICE_DEFAULT_FONT
#define DEVICE_FONTTYPE						GDI_DEVICE_FONTTYPE
#define DIB_PAL_COLORS						GDI_DIB_PAL_COLORS
#define DIB_RGB_COLORS						GDI_DIB_RGB_COLORS
#define DISPLAYCONFIG_MAXPATH					GDI_DISPLAYCONFIG_MAXPATH
#define DISPLAYCONFIG_PATH_ACTIVE				GDI_DISPLAYCONFIG_PATH_ACTIVE
#define DISPLAYCONFIG_PATH_MODE_IDX_INVALID			GDI_DISPLAYCONFIG_PATH_MODE_IDX_INVALID
#define DISPLAYCONFIG_SOURCE_IN_USE				GDI_DISPLAYCONFIG_SOURCE_IN_USE
#define DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_BOOT		GDI_DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_BOOT
#define DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_PATH		GDI_DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_PATH
#define DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_SYSTEM		GDI_DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_SYSTEM
#define DISPLAYCONFIG_TARGET_FORCIBLE				GDI_DISPLAYCONFIG_TARGET_FORCIBLE
#define DISPLAYCONFIG_TARGET_IN_USE				GDI_DISPLAYCONFIG_TARGET_IN_USE
#define DISPLAY_DEVICE_ACTIVE					GDI_DISPLAY_DEVICE_ACTIVE
#define DISPLAY_DEVICE_ATTACHED					GDI_DISPLAY_DEVICE_ATTACHED
#define DISPLAY_DEVICE_ATTACHED_TO_DESKTOP			GDI_DISPLAY_DEVICE_ATTACHED_TO_DESKTOP
#define DISPLAY_DEVICE_DISCONNECT				GDI_DISPLAY_DEVICE_DISCONNECT
#define DISPLAY_DEVICE_MIRRORING_DRIVER				GDI_DISPLAY_DEVICE_MIRRORING_DRIVER
#define DISPLAY_DEVICE_MODESPRUNED				GDI_DISPLAY_DEVICE_MODESPRUNED
#define DISPLAY_DEVICE_MULTI_DRIVER				GDI_DISPLAY_DEVICE_MULTI_DRIVER
#define DISPLAY_DEVICE_PRIMARY_DEVICE				GDI_DISPLAY_DEVICE_PRIMARY_DEVICE
#define DISPLAY_DEVICE_REMOTE					GDI_DISPLAY_DEVICE_REMOTE
#define DISPLAY_DEVICE_REMOVABLE				GDI_DISPLAY_DEVICE_REMOVABLE
#define DISPLAY_DEVICE_TS_COMPATIBLE				GDI_DISPLAY_DEVICE_TS_COMPATIBLE
#define DISPLAY_DEVICE_UNSAFE_MODES_ON				GDI_DISPLAY_DEVICE_UNSAFE_MODES_ON
#define DISPLAY_DEVICE_VGA_COMPATIBLE				GDI_DISPLAY_DEVICE_VGA_COMPATIBLE
#define DI_APPBANDING						GDI_DI_APPBANDING
#define DI_ROPS_READ_DESTINATION				GDI_DI_ROPS_READ_DESTINATION
#define DKGRAY_BRUSH						GDI_DKGRAY_BRUSH
#define DMBIN_AUTO						GDI_DMBIN_AUTO
#define DMBIN_CASSETTE						GDI_DMBIN_CASSETTE
#define DMBIN_ENVELOPE						GDI_DMBIN_ENVELOPE
#define DMBIN_ENVMANUAL						GDI_DMBIN_ENVMANUAL
#define DMBIN_FIRST						GDI_DMBIN_FIRST
#define DMBIN_FORMSOURCE					GDI_DMBIN_FORMSOURCE
#define DMBIN_LARGECAPACITY					GDI_DMBIN_LARGECAPACITY
#define DMBIN_LARGEFMT						GDI_DMBIN_LARGEFMT
#define DMBIN_LAST						GDI_DMBIN_LAST
#define DMBIN_LOWER						GDI_DMBIN_LOWER
#define DMBIN_MANUAL						GDI_DMBIN_MANUAL
#define DMBIN_MIDDLE						GDI_DMBIN_MIDDLE
#define DMBIN_ONLYONE						GDI_DMBIN_ONLYONE
#define DMBIN_SMALLFMT						GDI_DMBIN_SMALLFMT
#define DMBIN_TRACTOR						GDI_DMBIN_TRACTOR
#define DMBIN_UPPER						GDI_DMBIN_UPPER
#define DMBIN_USER						GDI_DMBIN_USER
#define DMCOLLATE_FALSE						GDI_DMCOLLATE_FALSE
#define DMCOLLATE_TRUE						GDI_DMCOLLATE_TRUE
#define DMCOLOR_COLOR						GDI_DMCOLOR_COLOR
#define DMCOLOR_MONOCHROME					GDI_DMCOLOR_MONOCHROME
#define DMDFO_CENTER						GDI_DMDFO_CENTER
#define DMDFO_DEFAULT						GDI_DMDFO_DEFAULT
#define DMDFO_STRETCH						GDI_DMDFO_STRETCH
#define DMDISPLAYFLAGS_TEXTMODE					GDI_DMDISPLAYFLAGS_TEXTMODE
#define DMDITHER_COARSE						GDI_DMDITHER_COARSE
#define DMDITHER_ERRORDIFFUSION					GDI_DMDITHER_ERRORDIFFUSION
#define DMDITHER_FINE						GDI_DMDITHER_FINE
#define DMDITHER_GRAYSCALE					GDI_DMDITHER_GRAYSCALE
#define DMDITHER_LINEART					GDI_DMDITHER_LINEART
#define DMDITHER_NONE						GDI_DMDITHER_NONE
#define DMDITHER_RESERVED6					GDI_DMDITHER_RESERVED6
#define DMDITHER_RESERVED7					GDI_DMDITHER_RESERVED7
#define DMDITHER_RESERVED8					GDI_DMDITHER_RESERVED8
#define DMDITHER_RESERVED9					GDI_DMDITHER_RESERVED9
#define DMDITHER_USER						GDI_DMDITHER_USER
#define DMDO_180						GDI_DMDO_180
#define DMDO_270						GDI_DMDO_270
#define DMDO_90							GDI_DMDO_90
#define DMDO_DEFAULT						GDI_DMDO_DEFAULT
#define DMDUP_HORIZONTAL					GDI_DMDUP_HORIZONTAL
#define DMDUP_SIMPLEX						GDI_DMDUP_SIMPLEX
#define DMDUP_VERTICAL						GDI_DMDUP_VERTICAL
#define DMICMMETHOD_DEVICE					GDI_DMICMMETHOD_DEVICE
#define DMICMMETHOD_DRIVER					GDI_DMICMMETHOD_DRIVER
#define DMICMMETHOD_NONE					GDI_DMICMMETHOD_NONE
#define DMICMMETHOD_SYSTEM					GDI_DMICMMETHOD_SYSTEM
#define DMICMMETHOD_USER					GDI_DMICMMETHOD_USER
#define DMICM_ABS_COLORIMETRIC					GDI_DMICM_ABS_COLORIMETRIC
#define DMICM_COLORIMETRIC					GDI_DMICM_COLORIMETRIC
#define DMICM_CONTRAST						GDI_DMICM_CONTRAST
#define DMICM_SATURATE						GDI_DMICM_SATURATE
#define DMICM_USER						GDI_DMICM_USER
#define DMMEDIA_GLOSSY						GDI_DMMEDIA_GLOSSY
#define DMMEDIA_STANDARD					GDI_DMMEDIA_STANDARD
#define DMMEDIA_TRANSPARENCY					GDI_DMMEDIA_TRANSPARENCY
#define DMMEDIA_USER						GDI_DMMEDIA_USER
#define DMNUP_ONEUP						GDI_DMNUP_ONEUP
#define DMNUP_SYSTEM						GDI_DMNUP_SYSTEM
#define DMORIENT_LANDSCAPE					GDI_DMORIENT_LANDSCAPE
#define DMORIENT_PORTRAIT					GDI_DMORIENT_PORTRAIT
#define DMPAPER_10X11						GDI_DMPAPER_10X11
#define DMPAPER_10X14						GDI_DMPAPER_10X14
#define DMPAPER_11X17						GDI_DMPAPER_11X17
#define DMPAPER_12X11						GDI_DMPAPER_12X11
#define DMPAPER_15X11						GDI_DMPAPER_15X11
#define DMPAPER_9X11						GDI_DMPAPER_9X11
#define DMPAPER_A2						GDI_DMPAPER_A2
#define DMPAPER_A3						GDI_DMPAPER_A3
#define DMPAPER_A3_EXTRA					GDI_DMPAPER_A3_EXTRA
#define DMPAPER_A3_EXTRA_TRANSVERSE				GDI_DMPAPER_A3_EXTRA_TRANSVERSE
#define DMPAPER_A3_ROTATED					GDI_DMPAPER_A3_ROTATED
#define DMPAPER_A3_TRANSVERSE					GDI_DMPAPER_A3_TRANSVERSE
#define DMPAPER_A4						GDI_DMPAPER_A4
#define DMPAPER_A4SMALL						GDI_DMPAPER_A4SMALL
#define DMPAPER_A4_EXTRA					GDI_DMPAPER_A4_EXTRA
#define DMPAPER_A4_PLUS						GDI_DMPAPER_A4_PLUS
#define DMPAPER_A4_ROTATED					GDI_DMPAPER_A4_ROTATED
#define DMPAPER_A4_TRANSVERSE					GDI_DMPAPER_A4_TRANSVERSE
#define DMPAPER_A5						GDI_DMPAPER_A5
#define DMPAPER_A5_EXTRA					GDI_DMPAPER_A5_EXTRA
#define DMPAPER_A5_ROTATED					GDI_DMPAPER_A5_ROTATED
#define DMPAPER_A5_TRANSVERSE					GDI_DMPAPER_A5_TRANSVERSE
#define DMPAPER_A6						GDI_DMPAPER_A6
#define DMPAPER_A6_ROTATED					GDI_DMPAPER_A6_ROTATED
#define DMPAPER_A_PLUS						GDI_DMPAPER_A_PLUS
#define DMPAPER_B4						GDI_DMPAPER_B4
#define DMPAPER_B4_JIS_ROTATED					GDI_DMPAPER_B4_JIS_ROTATED
#define DMPAPER_B5						GDI_DMPAPER_B5
#define DMPAPER_B5_EXTRA					GDI_DMPAPER_B5_EXTRA
#define DMPAPER_B5_JIS_ROTATED					GDI_DMPAPER_B5_JIS_ROTATED
#define DMPAPER_B5_TRANSVERSE					GDI_DMPAPER_B5_TRANSVERSE
#define DMPAPER_B6_JIS						GDI_DMPAPER_B6_JIS
#define DMPAPER_B6_JIS_ROTATED					GDI_DMPAPER_B6_JIS_ROTATED
#define DMPAPER_B_PLUS						GDI_DMPAPER_B_PLUS
#define DMPAPER_CSHEET						GDI_DMPAPER_CSHEET
#define DMPAPER_DBL_JAPANESE_POSTCARD				GDI_DMPAPER_DBL_JAPANESE_POSTCARD
#define DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED			GDI_DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED
#define DMPAPER_DSHEET						GDI_DMPAPER_DSHEET
#define DMPAPER_ENV_10						GDI_DMPAPER_ENV_10
#define DMPAPER_ENV_11						GDI_DMPAPER_ENV_11
#define DMPAPER_ENV_12						GDI_DMPAPER_ENV_12
#define DMPAPER_ENV_14						GDI_DMPAPER_ENV_14
#define DMPAPER_ENV_9						GDI_DMPAPER_ENV_9
#define DMPAPER_ENV_B4						GDI_DMPAPER_ENV_B4
#define DMPAPER_ENV_B5						GDI_DMPAPER_ENV_B5
#define DMPAPER_ENV_B6						GDI_DMPAPER_ENV_B6
#define DMPAPER_ENV_C3						GDI_DMPAPER_ENV_C3
#define DMPAPER_ENV_C4						GDI_DMPAPER_ENV_C4
#define DMPAPER_ENV_C5						GDI_DMPAPER_ENV_C5
#define DMPAPER_ENV_C6						GDI_DMPAPER_ENV_C6
#define DMPAPER_ENV_C65						GDI_DMPAPER_ENV_C65
#define DMPAPER_ENV_DL						GDI_DMPAPER_ENV_DL
#define DMPAPER_ENV_INVITE					GDI_DMPAPER_ENV_INVITE
#define DMPAPER_ENV_ITALY					GDI_DMPAPER_ENV_ITALY
#define DMPAPER_ENV_MONARCH					GDI_DMPAPER_ENV_MONARCH
#define DMPAPER_ENV_PERSONAL					GDI_DMPAPER_ENV_PERSONAL
#define DMPAPER_ESHEET						GDI_DMPAPER_ESHEET
#define DMPAPER_EXECUTIVE					GDI_DMPAPER_EXECUTIVE
#define DMPAPER_FANFOLD_LGL_GERMAN				GDI_DMPAPER_FANFOLD_LGL_GERMAN
#define DMPAPER_FANFOLD_STD_GERMAN				GDI_DMPAPER_FANFOLD_STD_GERMAN
#define DMPAPER_FANFOLD_US					GDI_DMPAPER_FANFOLD_US
#define DMPAPER_FIRST						GDI_DMPAPER_FIRST
#define DMPAPER_FOLIO						GDI_DMPAPER_FOLIO
#define DMPAPER_ISO_B4						GDI_DMPAPER_ISO_B4
#define DMPAPER_JAPANESE_POSTCARD				GDI_DMPAPER_JAPANESE_POSTCARD
#define DMPAPER_JAPANESE_POSTCARD_ROTATED			GDI_DMPAPER_JAPANESE_POSTCARD_ROTATED
#define DMPAPER_JENV_CHOU3					GDI_DMPAPER_JENV_CHOU3
#define DMPAPER_JENV_CHOU3_ROTATED				GDI_DMPAPER_JENV_CHOU3_ROTATED
#define DMPAPER_JENV_CHOU4					GDI_DMPAPER_JENV_CHOU4
#define DMPAPER_JENV_CHOU4_ROTATED				GDI_DMPAPER_JENV_CHOU4_ROTATED
#define DMPAPER_JENV_KAKU2					GDI_DMPAPER_JENV_KAKU2
#define DMPAPER_JENV_KAKU2_ROTATED				GDI_DMPAPER_JENV_KAKU2_ROTATED
#define DMPAPER_JENV_KAKU3					GDI_DMPAPER_JENV_KAKU3
#define DMPAPER_JENV_KAKU3_ROTATED				GDI_DMPAPER_JENV_KAKU3_ROTATED
#define DMPAPER_JENV_YOU4					GDI_DMPAPER_JENV_YOU4
#define DMPAPER_JENV_YOU4_ROTATED				GDI_DMPAPER_JENV_YOU4_ROTATED
#define DMPAPER_LAST						GDI_DMPAPER_LAST
#define DMPAPER_LEDGER						GDI_DMPAPER_LEDGER
#define DMPAPER_LEGAL						GDI_DMPAPER_LEGAL
#define DMPAPER_LEGAL_EXTRA					GDI_DMPAPER_LEGAL_EXTRA
#define DMPAPER_LETTER						GDI_DMPAPER_LETTER
#define DMPAPER_LETTERSMALL					GDI_DMPAPER_LETTERSMALL
#define DMPAPER_LETTER_EXTRA					GDI_DMPAPER_LETTER_EXTRA
#define DMPAPER_LETTER_EXTRA_TRANSVERSE				GDI_DMPAPER_LETTER_EXTRA_TRANSVERSE
#define DMPAPER_LETTER_PLUS					GDI_DMPAPER_LETTER_PLUS
#define DMPAPER_LETTER_ROTATED					GDI_DMPAPER_LETTER_ROTATED
#define DMPAPER_LETTER_TRANSVERSE				GDI_DMPAPER_LETTER_TRANSVERSE
#define DMPAPER_NOTE						GDI_DMPAPER_NOTE
#define DMPAPER_P16K						GDI_DMPAPER_P16K
#define DMPAPER_P16K_ROTATED					GDI_DMPAPER_P16K_ROTATED
#define DMPAPER_P32K						GDI_DMPAPER_P32K
#define DMPAPER_P32KBIG						GDI_DMPAPER_P32KBIG
#define DMPAPER_P32KBIG_ROTATED					GDI_DMPAPER_P32KBIG_ROTATED
#define DMPAPER_P32K_ROTATED					GDI_DMPAPER_P32K_ROTATED
#define DMPAPER_PENV_1						GDI_DMPAPER_PENV_1
#define DMPAPER_PENV_10						GDI_DMPAPER_PENV_10
#define DMPAPER_PENV_10_ROTATED					GDI_DMPAPER_PENV_10_ROTATED
#define DMPAPER_PENV_1_ROTATED					GDI_DMPAPER_PENV_1_ROTATED
#define DMPAPER_PENV_2						GDI_DMPAPER_PENV_2
#define DMPAPER_PENV_2_ROTATED					GDI_DMPAPER_PENV_2_ROTATED
#define DMPAPER_PENV_3						GDI_DMPAPER_PENV_3
#define DMPAPER_PENV_3_ROTATED					GDI_DMPAPER_PENV_3_ROTATED
#define DMPAPER_PENV_4						GDI_DMPAPER_PENV_4
#define DMPAPER_PENV_4_ROTATED					GDI_DMPAPER_PENV_4_ROTATED
#define DMPAPER_PENV_5						GDI_DMPAPER_PENV_5
#define DMPAPER_PENV_5_ROTATED					GDI_DMPAPER_PENV_5_ROTATED
#define DMPAPER_PENV_6						GDI_DMPAPER_PENV_6
#define DMPAPER_PENV_6_ROTATED					GDI_DMPAPER_PENV_6_ROTATED
#define DMPAPER_PENV_7						GDI_DMPAPER_PENV_7
#define DMPAPER_PENV_7_ROTATED					GDI_DMPAPER_PENV_7_ROTATED
#define DMPAPER_PENV_8						GDI_DMPAPER_PENV_8
#define DMPAPER_PENV_8_ROTATED					GDI_DMPAPER_PENV_8_ROTATED
#define DMPAPER_PENV_9						GDI_DMPAPER_PENV_9
#define DMPAPER_PENV_9_ROTATED					GDI_DMPAPER_PENV_9_ROTATED
#define DMPAPER_QUARTO						GDI_DMPAPER_QUARTO
#define DMPAPER_RESERVED_48					GDI_DMPAPER_RESERVED_48
#define DMPAPER_RESERVED_49					GDI_DMPAPER_RESERVED_49
#define DMPAPER_STATEMENT					GDI_DMPAPER_STATEMENT
#define DMPAPER_TABLOID						GDI_DMPAPER_TABLOID
#define DMPAPER_TABLOID_EXTRA					GDI_DMPAPER_TABLOID_EXTRA
#define DMPAPER_USER						GDI_DMPAPER_USER
#define DMRES_DRAFT						GDI_DMRES_DRAFT
#define DMRES_HIGH						GDI_DMRES_HIGH
#define DMRES_LOW						GDI_DMRES_LOW
#define DMRES_MEDIUM						GDI_DMRES_MEDIUM
#define DMTT_BITMAP						GDI_DMTT_BITMAP
#define DMTT_DOWNLOAD						GDI_DMTT_DOWNLOAD
#define DMTT_DOWNLOAD_OUTLINE					GDI_DMTT_DOWNLOAD_OUTLINE
#define DMTT_SUBDEV						GDI_DMTT_SUBDEV
#define DM_BITSPERPEL						GDI_DM_BITSPERPEL
#define DM_COLLATE						GDI_DM_COLLATE
#define DM_COLOR						GDI_DM_COLOR
#define DM_COPIES						GDI_DM_COPIES
#define DM_COPY							GDI_DM_COPY
#define DM_DEFAULTSOURCE					GDI_DM_DEFAULTSOURCE
#define DM_DISPLAYFIXEDOUTPUT					GDI_DM_DISPLAYFIXEDOUTPUT
#define DM_DISPLAYFLAGS						GDI_DM_DISPLAYFLAGS
#define DM_DISPLAYFREQUENCY					GDI_DM_DISPLAYFREQUENCY
#define DM_DISPLAYORIENTATION					GDI_DM_DISPLAYORIENTATION
#define DM_DITHERTYPE						GDI_DM_DITHERTYPE
#define DM_DUPLEX						GDI_DM_DUPLEX
#define DM_FORMNAME						GDI_DM_FORMNAME
#define DM_ICMINTENT						GDI_DM_ICMINTENT
#define DM_ICMMETHOD						GDI_DM_ICMMETHOD
#define DM_INTERLACED						GDI_DM_INTERLACED
#define DM_IN_BUFFER						GDI_DM_IN_BUFFER
#define DM_IN_PROMPT						GDI_DM_IN_PROMPT
#define DM_LOGPIXELS						GDI_DM_LOGPIXELS
#define DM_MEDIATYPE						GDI_DM_MEDIATYPE
#define DM_MODIFY						GDI_DM_MODIFY
#define DM_NUP							GDI_DM_NUP
#define DM_ORIENTATION						GDI_DM_ORIENTATION
#define DM_OUT_BUFFER						GDI_DM_OUT_BUFFER
#define DM_OUT_DEFAULT						GDI_DM_OUT_DEFAULT
#define DM_PANNINGHEIGHT					GDI_DM_PANNINGHEIGHT
#define DM_PANNINGWIDTH						GDI_DM_PANNINGWIDTH
#define DM_PAPERLENGTH						GDI_DM_PAPERLENGTH
#define DM_PAPERSIZE						GDI_DM_PAPERSIZE
#define DM_PAPERWIDTH						GDI_DM_PAPERWIDTH
#define DM_PELSHEIGHT						GDI_DM_PELSHEIGHT
#define DM_PELSWIDTH						GDI_DM_PELSWIDTH
#define DM_POSITION						GDI_DM_POSITION
#define DM_PRINTQUALITY						GDI_DM_PRINTQUALITY
#define DM_PROMPT						GDI_DM_PROMPT
#define DM_SCALE						GDI_DM_SCALE
#define DM_SPECVERSION						GDI_DM_SPECVERSION
#define DM_TTOPTION						GDI_DM_TTOPTION
#define DM_UPDATE						GDI_DM_UPDATE
#define DM_YRESOLUTION						GDI_DM_YRESOLUTION
#define DOWNLOADFACE						GDI_DOWNLOADFACE
#define DOWNLOADHEADER						GDI_DOWNLOADHEADER
#define DRAFTMODE						GDI_DRAFTMODE
#define DRAFT_QUALITY						GDI_DRAFT_QUALITY
#define DRAWPATTERNRECT						GDI_DRAWPATTERNRECT
#define DRIVERVERSION						GDI_DRIVERVERSION
#define DSTINVERT						GDI_DSTINVERT
#define DT_CHARSTREAM						GDI_DT_CHARSTREAM
#define DT_DISPFILE						GDI_DT_DISPFILE
#define DT_METAFILE						GDI_DT_METAFILE
#define DT_PLOTTER						GDI_DT_PLOTTER
#define DT_RASCAMERA						GDI_DT_RASCAMERA
#define DT_RASDISPLAY						GDI_DT_RASDISPLAY
#define DT_RASPRINTER						GDI_DT_RASPRINTER
#define EASTEUROPE_CHARSET					GDI_EASTEUROPE_CHARSET
#define ELF_CULTURE_LATIN					GDI_ELF_CULTURE_LATIN
#define ELF_VENDOR_SIZE						GDI_ELF_VENDOR_SIZE
#define ELF_VERSION						GDI_ELF_VERSION
#define EMR_ABORTPATH						GDI_EMR_ABORTPATH
#define EMR_ALPHABLEND						GDI_EMR_ALPHABLEND
#define EMR_ANGLEARC						GDI_EMR_ANGLEARC
#define EMR_ARC							GDI_EMR_ARC
#define EMR_ARCTO						GDI_EMR_ARCTO
#define EMR_BEGINPATH						GDI_EMR_BEGINPATH
#define EMR_BITBLT						GDI_EMR_BITBLT
#define EMR_CHORD						GDI_EMR_CHORD
#define EMR_CLOSEFIGURE						GDI_EMR_CLOSEFIGURE
#define EMR_COLORCORRECTPALETTE					GDI_EMR_COLORCORRECTPALETTE
#define EMR_COLORMATCHTOTARGETW					GDI_EMR_COLORMATCHTOTARGETW
#define EMR_CREATEBRUSHINDIRECT					GDI_EMR_CREATEBRUSHINDIRECT
#define EMR_CREATECOLORSPACE					GDI_EMR_CREATECOLORSPACE
#define EMR_CREATECOLORSPACEW					GDI_EMR_CREATECOLORSPACEW
#define EMR_CREATEDIBPATTERNBRUSHPT				GDI_EMR_CREATEDIBPATTERNBRUSHPT
#define EMR_CREATEMONOBRUSH					GDI_EMR_CREATEMONOBRUSH
#define EMR_CREATEPALETTE					GDI_EMR_CREATEPALETTE
#define EMR_CREATEPEN						GDI_EMR_CREATEPEN
#define EMR_DELETECOLORSPACE					GDI_EMR_DELETECOLORSPACE
#define EMR_DELETEOBJECT					GDI_EMR_DELETEOBJECT
#define EMR_ELLIPSE						GDI_EMR_ELLIPSE
#define EMR_ENDPATH						GDI_EMR_ENDPATH
#define EMR_EOF							GDI_EMR_EOF
#define EMR_EXCLUDECLIPRECT					GDI_EMR_EXCLUDECLIPRECT
#define EMR_EXTCREATEFONTINDIRECTW				GDI_EMR_EXTCREATEFONTINDIRECTW
#define EMR_EXTCREATEPEN					GDI_EMR_EXTCREATEPEN
#define EMR_EXTFLOODFILL					GDI_EMR_EXTFLOODFILL
#define EMR_EXTSELECTCLIPRGN					GDI_EMR_EXTSELECTCLIPRGN
#define EMR_EXTTEXTOUTA						GDI_EMR_EXTTEXTOUTA
#define EMR_EXTTEXTOUTW						GDI_EMR_EXTTEXTOUTW
#define EMR_FILLPATH						GDI_EMR_FILLPATH
#define EMR_FILLRGN						GDI_EMR_FILLRGN
#define EMR_FLATTENPATH						GDI_EMR_FLATTENPATH
#define EMR_FRAMERGN						GDI_EMR_FRAMERGN
#define EMR_GDICOMMENT						GDI_EMR_GDICOMMENT
#define EMR_GLSBOUNDEDRECORD					GDI_EMR_GLSBOUNDEDRECORD
#define EMR_GLSRECORD						GDI_EMR_GLSRECORD
#define EMR_GRADIENTFILL					GDI_EMR_GRADIENTFILL
#define EMR_HEADER						GDI_EMR_HEADER
#define EMR_INTERSECTCLIPRECT					GDI_EMR_INTERSECTCLIPRECT
#define EMR_INVERTRGN						GDI_EMR_INVERTRGN
#define EMR_LINETO						GDI_EMR_LINETO
#define EMR_MASKBLT						GDI_EMR_MASKBLT
#define EMR_MAX							GDI_EMR_MAX
#define EMR_MIN							GDI_EMR_MIN
#define EMR_MODIFYWORLDTRANSFORM				GDI_EMR_MODIFYWORLDTRANSFORM
#define EMR_MOVETOEX						GDI_EMR_MOVETOEX
#define EMR_OFFSETCLIPRGN					GDI_EMR_OFFSETCLIPRGN
#define EMR_PAINTRGN						GDI_EMR_PAINTRGN
#define EMR_PIE							GDI_EMR_PIE
#define EMR_PIXELFORMAT						GDI_EMR_PIXELFORMAT
#define EMR_PLGBLT						GDI_EMR_PLGBLT
#define EMR_POLYBEZIER						GDI_EMR_POLYBEZIER
#define EMR_POLYBEZIER16					GDI_EMR_POLYBEZIER16
#define EMR_POLYBEZIERTO					GDI_EMR_POLYBEZIERTO
#define EMR_POLYBEZIERTO16					GDI_EMR_POLYBEZIERTO16
#define EMR_POLYDRAW						GDI_EMR_POLYDRAW
#define EMR_POLYDRAW16						GDI_EMR_POLYDRAW16
#define EMR_POLYGON						GDI_EMR_POLYGON
#define EMR_POLYGON16						GDI_EMR_POLYGON16
#define EMR_POLYLINE						GDI_EMR_POLYLINE
#define EMR_POLYLINE16						GDI_EMR_POLYLINE16
#define EMR_POLYLINETO						GDI_EMR_POLYLINETO
#define EMR_POLYLINETO16					GDI_EMR_POLYLINETO16
#define EMR_POLYPOLYGON						GDI_EMR_POLYPOLYGON
#define EMR_POLYPOLYGON16					GDI_EMR_POLYPOLYGON16
#define EMR_POLYPOLYLINE					GDI_EMR_POLYPOLYLINE
#define EMR_POLYPOLYLINE16					GDI_EMR_POLYPOLYLINE16
#define EMR_POLYTEXTOUTA					GDI_EMR_POLYTEXTOUTA
#define EMR_POLYTEXTOUTW					GDI_EMR_POLYTEXTOUTW
#define EMR_REALIZEPALETTE					GDI_EMR_REALIZEPALETTE
#define EMR_RECTANGLE						GDI_EMR_RECTANGLE
#define EMR_RESERVED_105					GDI_EMR_RESERVED_105
#define EMR_RESERVED_106					GDI_EMR_RESERVED_106
#define EMR_RESERVED_107					GDI_EMR_RESERVED_107
#define EMR_RESERVED_108					GDI_EMR_RESERVED_108
#define EMR_RESERVED_109					GDI_EMR_RESERVED_109
#define EMR_RESERVED_110					GDI_EMR_RESERVED_110
#define EMR_RESERVED_117					GDI_EMR_RESERVED_117
#define EMR_RESERVED_119					GDI_EMR_RESERVED_119
#define EMR_RESERVED_120					GDI_EMR_RESERVED_120
#define EMR_RESIZEPALETTE					GDI_EMR_RESIZEPALETTE
#define EMR_RESTOREDC						GDI_EMR_RESTOREDC
#define EMR_ROUNDRECT						GDI_EMR_ROUNDRECT
#define EMR_SAVEDC						GDI_EMR_SAVEDC
#define EMR_SCALEVIEWPORTEXTEX					GDI_EMR_SCALEVIEWPORTEXTEX
#define EMR_SCALEWINDOWEXTEX					GDI_EMR_SCALEWINDOWEXTEX
#define EMR_SELECTCLIPPATH					GDI_EMR_SELECTCLIPPATH
#define EMR_SELECTOBJECT					GDI_EMR_SELECTOBJECT
#define EMR_SELECTPALETTE					GDI_EMR_SELECTPALETTE
#define EMR_SETARCDIRECTION					GDI_EMR_SETARCDIRECTION
#define EMR_SETBKCOLOR						GDI_EMR_SETBKCOLOR
#define EMR_SETBKMODE						GDI_EMR_SETBKMODE
#define EMR_SETBRUSHORGEX					GDI_EMR_SETBRUSHORGEX
#define EMR_SETCOLORADJUSTMENT					GDI_EMR_SETCOLORADJUSTMENT
#define EMR_SETCOLORSPACE					GDI_EMR_SETCOLORSPACE
#define EMR_SETDIBITSTODEVICE					GDI_EMR_SETDIBITSTODEVICE
#define EMR_SETICMMODE						GDI_EMR_SETICMMODE
#define EMR_SETICMPROFILEA					GDI_EMR_SETICMPROFILEA
#define EMR_SETICMPROFILEW					GDI_EMR_SETICMPROFILEW
#define EMR_SETLAYOUT						GDI_EMR_SETLAYOUT
#define EMR_SETMAPMODE						GDI_EMR_SETMAPMODE
#define EMR_SETMAPPERFLAGS					GDI_EMR_SETMAPPERFLAGS
#define EMR_SETMETARGN						GDI_EMR_SETMETARGN
#define EMR_SETMITERLIMIT					GDI_EMR_SETMITERLIMIT
#define EMR_SETPALETTEENTRIES					GDI_EMR_SETPALETTEENTRIES
#define EMR_SETPIXELV						GDI_EMR_SETPIXELV
#define EMR_SETPOLYFILLMODE					GDI_EMR_SETPOLYFILLMODE
#define EMR_SETROP2						GDI_EMR_SETROP2
#define EMR_SETSTRETCHBLTMODE					GDI_EMR_SETSTRETCHBLTMODE
#define EMR_SETTEXTALIGN					GDI_EMR_SETTEXTALIGN
#define EMR_SETTEXTCOLOR					GDI_EMR_SETTEXTCOLOR
#define EMR_SETVIEWPORTEXTEX					GDI_EMR_SETVIEWPORTEXTEX
#define EMR_SETVIEWPORTORGEX					GDI_EMR_SETVIEWPORTORGEX
#define EMR_SETWINDOWEXTEX					GDI_EMR_SETWINDOWEXTEX
#define EMR_SETWINDOWORGEX					GDI_EMR_SETWINDOWORGEX
#define EMR_SETWORLDTRANSFORM					GDI_EMR_SETWORLDTRANSFORM
#define EMR_STRETCHBLT						GDI_EMR_STRETCHBLT
#define EMR_STRETCHDIBITS					GDI_EMR_STRETCHDIBITS
#define EMR_STROKEANDFILLPATH					GDI_EMR_STROKEANDFILLPATH
#define EMR_STROKEPATH						GDI_EMR_STROKEPATH
#define EMR_TRANSPARENTBLT					GDI_EMR_TRANSPARENTBLT
#define EMR_WIDENPATH						GDI_EMR_WIDENPATH
#define ENABLEDUPLEX						GDI_ENABLEDUPLEX
#define ENABLEPAIRKERNING					GDI_ENABLEPAIRKERNING
#define ENABLERELATIVEWIDTHS					GDI_ENABLERELATIVEWIDTHS
#define ENCAPSULATED_POSTSCRIPT					GDI_ENCAPSULATED_POSTSCRIPT
#define ENDDOC							GDI_ENDDOC
#define END_PATH						GDI_END_PATH
#define ENHMETA_SIGNATURE					GDI_ENHMETA_SIGNATURE
#define ENHMETA_STOCK_OBJECT					GDI_ENHMETA_STOCK_OBJECT
#define ENUMPAPERBINS						GDI_ENUMPAPERBINS
#define ENUMPAPERMETRICS					GDI_ENUMPAPERMETRICS
#define EPSPRINTING						GDI_EPSPRINTING
#define EPS_SIGNATURE						GDI_EPS_SIGNATURE
#define ETO_CLIPPED						GDI_ETO_CLIPPED
#define ETO_GLYPH_INDEX						GDI_ETO_GLYPH_INDEX
#define ETO_IGNORELANGUAGE					GDI_ETO_IGNORELANGUAGE
#define ETO_NUMERICSLATIN					GDI_ETO_NUMERICSLATIN
#define ETO_NUMERICSLOCAL					GDI_ETO_NUMERICSLOCAL
#define ETO_OPAQUE						GDI_ETO_OPAQUE
#define ETO_PDY							GDI_ETO_PDY
#define ETO_REVERSE_INDEX_MAP					GDI_ETO_REVERSE_INDEX_MAP
#define ETO_RTLREADING						GDI_ETO_RTLREADING
#define EXTTEXTOUT						GDI_EXTTEXTOUT
#define EXT_DEVICE_CAPS						GDI_EXT_DEVICE_CAPS
#define FEATURESETTING_CUSTPAPER				GDI_FEATURESETTING_CUSTPAPER
#define FEATURESETTING_MIRROR					GDI_FEATURESETTING_MIRROR
#define FEATURESETTING_NEGATIVE					GDI_FEATURESETTING_NEGATIVE
#define FEATURESETTING_NUP					GDI_FEATURESETTING_NUP
#define FEATURESETTING_OUTPUT					GDI_FEATURESETTING_OUTPUT
#define FEATURESETTING_PRIVATE_BEGIN				GDI_FEATURESETTING_PRIVATE_BEGIN
#define FEATURESETTING_PRIVATE_END				GDI_FEATURESETTING_PRIVATE_END
#define FEATURESETTING_PROTOCOL					GDI_FEATURESETTING_PROTOCOL
#define FEATURESETTING_PSLEVEL					GDI_FEATURESETTING_PSLEVEL
#define FF_DECORATIVE						GDI_FF_DECORATIVE
#define FF_DONTCARE						GDI_FF_DONTCARE
#define FF_MODERN						GDI_FF_MODERN
#define FF_ROMAN						GDI_FF_ROMAN
#define FF_SCRIPT						GDI_FF_SCRIPT
#define FF_SWISS						GDI_FF_SWISS
#define FIXED_PITCH						GDI_FIXED_PITCH
#define FLI_GLYPHS						GDI_FLI_GLYPHS
#define FLI_MASK						GDI_FLI_MASK
#define FLOODFILLBORDER						GDI_FLOODFILLBORDER
#define FLOODFILLSURFACE					GDI_FLOODFILLSURFACE
#define FLUSHOUTPUT						GDI_FLUSHOUTPUT
#define FONTMAPPER_MAX						GDI_FONTMAPPER_MAX
#define FR_NOT_ENUM						GDI_FR_NOT_ENUM
#define FR_PRIVATE						GDI_FR_PRIVATE
#define FS_ARABIC						GDI_FS_ARABIC
#define FS_BALTIC						GDI_FS_BALTIC
#define FS_CHINESESIMP						GDI_FS_CHINESESIMP
#define FS_CHINESETRAD						GDI_FS_CHINESETRAD
#define FS_CYRILLIC						GDI_FS_CYRILLIC
#define FS_GREEK						GDI_FS_GREEK
#define FS_HEBREW						GDI_FS_HEBREW
#define FS_JISJAPAN						GDI_FS_JISJAPAN
#define FS_JOHAB						GDI_FS_JOHAB
#define FS_LATIN1						GDI_FS_LATIN1
#define FS_LATIN2						GDI_FS_LATIN2
#define FS_SYMBOL						GDI_FS_SYMBOL
#define FS_THAI							GDI_FS_THAI
#define FS_TURKISH						GDI_FS_TURKISH
#define FS_VIETNAMESE						GDI_FS_VIETNAMESE
#define FS_WANSUNG						GDI_FS_WANSUNG
#define FW_BLACK						GDI_FW_BLACK
#define FW_BOLD							GDI_FW_BOLD
#define FW_DEMIBOLD						GDI_FW_DEMIBOLD
#define FW_DONTCARE						GDI_FW_DONTCARE
#define FW_EXTRABOLD						GDI_FW_EXTRABOLD
#define FW_EXTRALIGHT						GDI_FW_EXTRALIGHT
#define FW_HEAVY						GDI_FW_HEAVY
#define FW_LIGHT						GDI_FW_LIGHT
#define FW_MEDIUM						GDI_FW_MEDIUM
#define FW_NORMAL						GDI_FW_NORMAL
#define FW_REGULAR						GDI_FW_REGULAR
#define FW_SEMIBOLD						GDI_FW_SEMIBOLD
#define FW_THIN							GDI_FW_THIN
#define FW_ULTRABOLD						GDI_FW_ULTRABOLD
#define FW_ULTRALIGHT						GDI_FW_ULTRALIGHT
#define GB2312_CHARSET						GDI_GB2312_CHARSET
#define GCPCLASS_ARABIC						GDI_GCPCLASS_ARABIC
#define GCPCLASS_HEBREW						GDI_GCPCLASS_HEBREW
#define GCPCLASS_LATIN						GDI_GCPCLASS_LATIN
#define GCPCLASS_LATINNUMBER					GDI_GCPCLASS_LATINNUMBER
#define GCPCLASS_LATINNUMERICSEPARATOR				GDI_GCPCLASS_LATINNUMERICSEPARATOR
#define GCPCLASS_LATINNUMERICTERMINATOR				GDI_GCPCLASS_LATINNUMERICTERMINATOR
#define GCPCLASS_LOCALNUMBER					GDI_GCPCLASS_LOCALNUMBER
#define GCPCLASS_NEUTRAL					GDI_GCPCLASS_NEUTRAL
#define GCPCLASS_NUMERICSEPARATOR				GDI_GCPCLASS_NUMERICSEPARATOR
#define GCPCLASS_POSTBOUNDLTR					GDI_GCPCLASS_POSTBOUNDLTR
#define GCPCLASS_POSTBOUNDRTL					GDI_GCPCLASS_POSTBOUNDRTL
#define GCPCLASS_PREBOUNDLTR					GDI_GCPCLASS_PREBOUNDLTR
#define GCPCLASS_PREBOUNDRTL					GDI_GCPCLASS_PREBOUNDRTL
#define GCPGLYPH_LINKAFTER					GDI_GCPGLYPH_LINKAFTER
#define GCPGLYPH_LINKBEFORE					GDI_GCPGLYPH_LINKBEFORE
#define GCP_CLASSIN						GDI_GCP_CLASSIN
#define GCP_DBCS						GDI_GCP_DBCS
#define GCP_DIACRITIC						GDI_GCP_DIACRITIC
#define GCP_DISPLAYZWG						GDI_GCP_DISPLAYZWG
#define GCP_ERROR						GDI_GCP_ERROR
#define GCP_GLYPHSHAPE						GDI_GCP_GLYPHSHAPE
#define GCP_JUSTIFY						GDI_GCP_JUSTIFY
#define GCP_JUSTIFYIN						GDI_GCP_JUSTIFYIN
#define GCP_KASHIDA						GDI_GCP_KASHIDA
#define GCP_LIGATE						GDI_GCP_LIGATE
#define GCP_MAXEXTENT						GDI_GCP_MAXEXTENT
#define GCP_NEUTRALOVERRIDE					GDI_GCP_NEUTRALOVERRIDE
#define GCP_NUMERICOVERRIDE					GDI_GCP_NUMERICOVERRIDE
#define GCP_NUMERICSLATIN					GDI_GCP_NUMERICSLATIN
#define GCP_NUMERICSLOCAL					GDI_GCP_NUMERICSLOCAL
#define GCP_REORDER						GDI_GCP_REORDER
#define GCP_SYMSWAPOFF						GDI_GCP_SYMSWAPOFF
#define GCP_USEKERNING						GDI_GCP_USEKERNING
#define GDICOMMENT_BEGINGROUP					GDI_GDICOMMENT_BEGINGROUP
#define GDICOMMENT_ENDGROUP					GDI_GDICOMMENT_ENDGROUP
#define GDICOMMENT_IDENTIFIER					GDI_GDICOMMENT_IDENTIFIER
#define GDICOMMENT_MULTIFORMATS					GDI_GDICOMMENT_MULTIFORMATS
#define GDICOMMENT_UNICODE_END					GDI_GDICOMMENT_UNICODE_END
#define GDICOMMENT_UNICODE_STRING				GDI_GDICOMMENT_UNICODE_STRING
#define GDICOMMENT_WINDOWS_METAFILE				GDI_GDICOMMENT_WINDOWS_METAFILE
#define GDIPLUS_TS_QUERYVER					GDI_GDIPLUS_TS_QUERYVER
#define GDIPLUS_TS_RECORD					GDI_GDIPLUS_TS_RECORD
#define GETCOLORTABLE						GDI_GETCOLORTABLE
#define GETDEVICEUNITS						GDI_GETDEVICEUNITS
#define GETEXTENDEDTEXTMETRICS					GDI_GETEXTENDEDTEXTMETRICS
#define GETEXTENTTABLE						GDI_GETEXTENTTABLE
#define GETFACENAME						GDI_GETFACENAME
#define GETPAIRKERNTABLE					GDI_GETPAIRKERNTABLE
#define GETPENWIDTH						GDI_GETPENWIDTH
#define GETPHYSPAGESIZE						GDI_GETPHYSPAGESIZE
#define GETPRINTINGOFFSET					GDI_GETPRINTINGOFFSET
#define GETSCALINGFACTOR					GDI_GETSCALINGFACTOR
#define GETSETPAPERBINS						GDI_GETSETPAPERBINS
#define GETSETPAPERMETRICS					GDI_GETSETPAPERMETRICS
#define GETSETPRINTORIENT					GDI_GETSETPRINTORIENT
#define GETSETSCREENPARAMS					GDI_GETSETSCREENPARAMS
#define GETTECHNOLGY						GDI_GETTECHNOLGY
#define GETTECHNOLOGY						GDI_GETTECHNOLOGY
#define GETTRACKKERNTABLE					GDI_GETTRACKKERNTABLE
#define GETVECTORBRUSHSIZE					GDI_GETVECTORBRUSHSIZE
#define GETVECTORPENSIZE					GDI_GETVECTORPENSIZE
#define GET_PS_FEATURESETTING					GDI_GET_PS_FEATURESETTING
#define GGI_MARK_NONEXISTING_GLYPHS				GDI_GGI_MARK_NONEXISTING_GLYPHS
#define GGO_BEZIER						GDI_GGO_BEZIER
#define GGO_BITMAP						GDI_GGO_BITMAP
#define GGO_GLYPH_INDEX						GDI_GGO_GLYPH_INDEX
#define GGO_GRAY2_BITMAP					GDI_GGO_GRAY2_BITMAP
#define GGO_GRAY4_BITMAP					GDI_GGO_GRAY4_BITMAP
#define GGO_GRAY8_BITMAP					GDI_GGO_GRAY8_BITMAP
#define GGO_METRICS						GDI_GGO_METRICS
#define GGO_NATIVE						GDI_GGO_NATIVE
#define GGO_UNHINTED						GDI_GGO_UNHINTED
#define GM_ADVANCED						GDI_GM_ADVANCED
#define GM_COMPATIBLE						GDI_GM_COMPATIBLE
#define GM_LAST							GDI_GM_LAST
#define GRADIENT_FILL_OP_FLAG					GDI_GRADIENT_FILL_OP_FLAG
#define GRADIENT_FILL_RECT_H					GDI_GRADIENT_FILL_RECT_H
#define GRADIENT_FILL_RECT_V					GDI_GRADIENT_FILL_RECT_V
#define GRADIENT_FILL_TRIANGLE					GDI_GRADIENT_FILL_TRIANGLE
#define GRAY_BRUSH						GDI_GRAY_BRUSH
#define GREEK_CHARSET						GDI_GREEK_CHARSET
#define GS_8BIT_INDICES						GDI_GS_8BIT_INDICES
#define HALFTONE						GDI_HALFTONE
#define HANGEUL_CHARSET						GDI_HANGEUL_CHARSET
#define HANGUL_CHARSET						GDI_HANGUL_CHARSET
#define HEBREW_CHARSET						GDI_HEBREW_CHARSET
#define HGDI_ERROR						GDI_HGDI_ERROR
#define HOLLOW_BRUSH						GDI_HOLLOW_BRUSH
#define HORZRES							GDI_HORZRES
#define HORZSIZE						GDI_HORZSIZE
#define HS_API_MAX						GDI_HS_API_MAX
#define HS_BDIAGONAL						GDI_HS_BDIAGONAL
#define HS_CROSS						GDI_HS_CROSS
#define HS_DIAGCROSS						GDI_HS_DIAGCROSS
#define HS_FDIAGONAL						GDI_HS_FDIAGONAL
#define HS_HORIZONTAL						GDI_HS_HORIZONTAL
#define HS_VERTICAL						GDI_HS_VERTICAL
#define ICM_ADDPROFILE						GDI_ICM_ADDPROFILE
#define ICM_DELETEPROFILE					GDI_ICM_DELETEPROFILE
#define ICM_DONE_OUTSIDEDC					GDI_ICM_DONE_OUTSIDEDC
#define ICM_OFF							GDI_ICM_OFF
#define ICM_ON							GDI_ICM_ON
#define ICM_QUERY						GDI_ICM_QUERY
#define ICM_QUERYMATCH						GDI_ICM_QUERYMATCH
#define ICM_QUERYPROFILE					GDI_ICM_QUERYPROFILE
#define ICM_REGISTERICMATCHER					GDI_ICM_REGISTERICMATCHER
#define ICM_SETDEFAULTPROFILE					GDI_ICM_SETDEFAULTPROFILE
#define ICM_UNREGISTERICMATCHER					GDI_ICM_UNREGISTERICMATCHER
#define ILLUMINANT_A						GDI_ILLUMINANT_A
#define ILLUMINANT_B						GDI_ILLUMINANT_B
#define ILLUMINANT_C						GDI_ILLUMINANT_C
#define ILLUMINANT_D50						GDI_ILLUMINANT_D50
#define ILLUMINANT_D55						GDI_ILLUMINANT_D55
#define ILLUMINANT_D65						GDI_ILLUMINANT_D65
#define ILLUMINANT_D75						GDI_ILLUMINANT_D75
#define ILLUMINANT_DAYLIGHT					GDI_ILLUMINANT_DAYLIGHT
#define ILLUMINANT_DEVICE_DEFAULT				GDI_ILLUMINANT_DEVICE_DEFAULT
#define ILLUMINANT_F2						GDI_ILLUMINANT_F2
#define ILLUMINANT_FLUORESCENT					GDI_ILLUMINANT_FLUORESCENT
#define ILLUMINANT_MAX_INDEX					GDI_ILLUMINANT_MAX_INDEX
#define ILLUMINANT_NTSC						GDI_ILLUMINANT_NTSC
#define ILLUMINANT_TUNGSTEN					GDI_ILLUMINANT_TUNGSTEN
#define JOHAB_CHARSET						GDI_JOHAB_CHARSET
#define LAYOUT_BITMAPORIENTATIONPRESERVED			GDI_LAYOUT_BITMAPORIENTATIONPRESERVED
#define LAYOUT_BTT						GDI_LAYOUT_BTT
#define LAYOUT_ORIENTATIONMASK					GDI_LAYOUT_ORIENTATIONMASK
#define LAYOUT_RTL						GDI_LAYOUT_RTL
#define LAYOUT_VBH						GDI_LAYOUT_VBH
#define LCS_CALIBRATED_RGB					GDI_LCS_CALIBRATED_RGB
#define LCS_GM_ABS_COLORIMETRIC					GDI_LCS_GM_ABS_COLORIMETRIC
#define LCS_GM_BUSINESS						GDI_LCS_GM_BUSINESS
#define LCS_GM_GRAPHICS						GDI_LCS_GM_GRAPHICS
#define LCS_GM_IMAGES						GDI_LCS_GM_IMAGES
#define LCS_SIGNATURE						GDI_LCS_SIGNATURE
#define LCS_sRGB						GDI_LCS_S_RGB
#define LCS_WINDOWS_COLOR_SPACE					GDI_LCS_WINDOWS_COLOR_SPACE
#define LC_INTERIORS						GDI_LC_INTERIORS
#define LC_MARKER						GDI_LC_MARKER
#define LC_NONE							GDI_LC_NONE
#define LC_POLYLINE						GDI_LC_POLYLINE
#define LC_POLYMARKER						GDI_LC_POLYMARKER
#define LC_STYLED						GDI_LC_STYLED
#define LC_WIDE							GDI_LC_WIDE
#define LC_WIDESTYLED						GDI_LC_WIDESTYLED
#define LF_FACESIZE						GDI_LF_FACESIZE
#define LF_FULLFACESIZE						GDI_LF_FULLFACESIZE
#define LINECAPS						GDI_LINECAPS
#define LOGPIXELSX						GDI_LOGPIXELSX
#define LOGPIXELSY						GDI_LOGPIXELSY
#define LPD_DOUBLEBUFFER					GDI_LPD_DOUBLEBUFFER
#define LPD_SHARE_ACCUM						GDI_LPD_SHARE_ACCUM
#define LPD_SHARE_DEPTH						GDI_LPD_SHARE_DEPTH
#define LPD_SHARE_STENCIL					GDI_LPD_SHARE_STENCIL
#define LPD_STEREO						GDI_LPD_STEREO
#define LPD_SUPPORT_GDI						GDI_LPD_SUPPORT_GDI
#define LPD_SUPPORT_OPENGL					GDI_LPD_SUPPORT_OPENGL
#define LPD_SWAP_COPY						GDI_LPD_SWAP_COPY
#define LPD_SWAP_EXCHANGE					GDI_LPD_SWAP_EXCHANGE
#define LPD_TRANSPARENT						GDI_LPD_TRANSPARENT
#define LPD_TYPE_COLORINDEX					GDI_LPD_TYPE_COLORINDEX
#define LPD_TYPE_RGBA						GDI_LPD_TYPE_RGBA
#define LTGRAY_BRUSH						GDI_LTGRAY_BRUSH
#define MAC_CHARSET						GDI_MAC_CHARSET
#define MAXSTRETCHBLTMODE					GDI_MAXSTRETCHBLTMODE
#define MERGECOPY						GDI_MERGECOPY
#define MERGEPAINT						GDI_MERGEPAINT
#define METAFILE_DRIVER						GDI_METAFILE_DRIVER
#define META_ANIMATEPALETTE					GDI_META_ANIMATEPALETTE
#define META_ARC						GDI_META_ARC
#define META_BITBLT						GDI_META_BITBLT
#define META_CHORD						GDI_META_CHORD
#define META_CREATEBRUSHINDIRECT				GDI_META_CREATEBRUSHINDIRECT
#define META_CREATEFONTINDIRECT					GDI_META_CREATEFONTINDIRECT
#define META_CREATEPALETTE					GDI_META_CREATEPALETTE
#define META_CREATEPATTERNBRUSH					GDI_META_CREATEPATTERNBRUSH
#define META_CREATEPENINDIRECT					GDI_META_CREATEPENINDIRECT
#define META_CREATEREGION					GDI_META_CREATEREGION
#define META_DELETEOBJECT					GDI_META_DELETEOBJECT
#define META_DIBBITBLT						GDI_META_DIBBITBLT
#define META_DIBCREATEPATTERNBRUSH				GDI_META_DIBCREATEPATTERNBRUSH
#define META_DIBSTRETCHBLT					GDI_META_DIBSTRETCHBLT
#define META_ELLIPSE						GDI_META_ELLIPSE
#define META_ESCAPE						GDI_META_ESCAPE
#define META_EXCLUDECLIPRECT					GDI_META_EXCLUDECLIPRECT
#define META_EXTFLOODFILL					GDI_META_EXTFLOODFILL
#define META_EXTTEXTOUT						GDI_META_EXTTEXTOUT
#define META_FILLREGION						GDI_META_FILLREGION
#define META_FLOODFILL						GDI_META_FLOODFILL
#define META_FRAMEREGION					GDI_META_FRAMEREGION
#define META_INTERSECTCLIPRECT					GDI_META_INTERSECTCLIPRECT
#define META_INVERTREGION					GDI_META_INVERTREGION
#define META_LINETO						GDI_META_LINETO
#define META_MOVETO						GDI_META_MOVETO
#define META_OFFSETCLIPRGN					GDI_META_OFFSETCLIPRGN
#define META_OFFSETVIEWPORTORG					GDI_META_OFFSETVIEWPORTORG
#define META_OFFSETWINDOWORG					GDI_META_OFFSETWINDOWORG
#define META_PAINTREGION					GDI_META_PAINTREGION
#define META_PATBLT						GDI_META_PATBLT
#define META_PIE						GDI_META_PIE
#define META_POLYGON						GDI_META_POLYGON
#define META_POLYLINE						GDI_META_POLYLINE
#define META_POLYPOLYGON					GDI_META_POLYPOLYGON
#define META_REALIZEPALETTE					GDI_META_REALIZEPALETTE
#define META_RECTANGLE						GDI_META_RECTANGLE
#define META_RESIZEPALETTE					GDI_META_RESIZEPALETTE
#define META_RESTOREDC						GDI_META_RESTOREDC
#define META_ROUNDRECT						GDI_META_ROUNDRECT
#define META_SAVEDC						GDI_META_SAVEDC
#define META_SCALEVIEWPORTEXT					GDI_META_SCALEVIEWPORTEXT
#define META_SCALEWINDOWEXT					GDI_META_SCALEWINDOWEXT
#define META_SELECTCLIPREGION					GDI_META_SELECTCLIPREGION
#define META_SELECTOBJECT					GDI_META_SELECTOBJECT
#define META_SELECTPALETTE					GDI_META_SELECTPALETTE
#define META_SETBKCOLOR						GDI_META_SETBKCOLOR
#define META_SETBKMODE						GDI_META_SETBKMODE
#define META_SETDIBTODEV					GDI_META_SETDIBTODEV
#define META_SETLAYOUT						GDI_META_SETLAYOUT
#define META_SETMAPMODE						GDI_META_SETMAPMODE
#define META_SETMAPPERFLAGS					GDI_META_SETMAPPERFLAGS
#define META_SETPALENTRIES					GDI_META_SETPALENTRIES
#define META_SETPIXEL						GDI_META_SETPIXEL
#define META_SETPOLYFILLMODE					GDI_META_SETPOLYFILLMODE
#define META_SETRELABS						GDI_META_SETRELABS
#define META_SETROP2						GDI_META_SETROP2
#define META_SETSTRETCHBLTMODE					GDI_META_SETSTRETCHBLTMODE
#define META_SETTEXTALIGN					GDI_META_SETTEXTALIGN
#define META_SETTEXTCHAREXTRA					GDI_META_SETTEXTCHAREXTRA
#define META_SETTEXTCOLOR					GDI_META_SETTEXTCOLOR
#define META_SETTEXTJUSTIFICATION				GDI_META_SETTEXTJUSTIFICATION
#define META_SETVIEWPORTEXT					GDI_META_SETVIEWPORTEXT
#define META_SETVIEWPORTORG					GDI_META_SETVIEWPORTORG
#define META_SETWINDOWEXT					GDI_META_SETWINDOWEXT
#define META_SETWINDOWORG					GDI_META_SETWINDOWORG
#define META_STRETCHBLT						GDI_META_STRETCHBLT
#define META_STRETCHDIB						GDI_META_STRETCHDIB
#define META_TEXTOUT						GDI_META_TEXTOUT
#define MFCOMMENT						GDI_MFCOMMENT
#define MILCORE_TS_QUERYVER_RESULT_FALSE			GDI_MILCORE_TS_QUERYVER_RESULT_FALSE
#define MILCORE_TS_QUERYVER_RESULT_TRUE				GDI_MILCORE_TS_QUERYVER_RESULT_TRUE
#define MM_ANISOTROPIC						GDI_MM_ANISOTROPIC
#define MM_HIENGLISH						GDI_MM_HIENGLISH
#define MM_HIMETRIC						GDI_MM_HIMETRIC
#define MM_ISOTROPIC						GDI_MM_ISOTROPIC
#define MM_LOENGLISH						GDI_MM_LOENGLISH
#define MM_LOMETRIC						GDI_MM_LOMETRIC
#define MM_MAX							GDI_MM_MAX
#define MM_MAX_AXES_NAMELEN					GDI_MM_MAX_AXES_NAMELEN
#define MM_MAX_FIXEDSCALE					GDI_MM_MAX_FIXEDSCALE
#define MM_MAX_NUMAXES						GDI_MM_MAX_NUMAXES
#define MM_MIN							GDI_MM_MIN
#define MM_TEXT							GDI_MM_TEXT
#define MM_TWIPS						GDI_MM_TWIPS
#define MONO_FONT						GDI_MONO_FONT
#define MOUSETRAILS						GDI_MOUSETRAILS
#define MWT_IDENTITY						GDI_MWT_IDENTITY
#define MWT_LEFTMULTIPLY					GDI_MWT_LEFTMULTIPLY
#define MWT_MAX							GDI_MWT_MAX
#define MWT_MIN							GDI_MWT_MIN
#define MWT_RIGHTMULTIPLY					GDI_MWT_RIGHTMULTIPLY
#define NEWFRAME						GDI_NEWFRAME
#define NEXTBAND						GDI_NEXTBAND
#define NOMIRRORBITMAP						GDI_NOMIRRORBITMAP
#define NONANTIALIASED_QUALITY					GDI_NONANTIALIASED_QUALITY
#define NOTSRCCOPY						GDI_NOTSRCCOPY
#define NOTSRCERASE						GDI_NOTSRCERASE
#define NTM_BOLD						GDI_NTM_BOLD
#define NTM_DSIG						GDI_NTM_DSIG
#define NTM_ITALIC						GDI_NTM_ITALIC
#define NTM_MULTIPLEMASTER					GDI_NTM_MULTIPLEMASTER
#define NTM_NONNEGATIVE_AC					GDI_NTM_NONNEGATIVE_AC
#define NTM_PS_OPENTYPE						GDI_NTM_PS_OPENTYPE
#define NTM_REGULAR						GDI_NTM_REGULAR
#define NTM_TT_OPENTYPE						GDI_NTM_TT_OPENTYPE
#define NTM_TYPE1						GDI_NTM_TYPE1
#define NULLREGION						GDI_NULLREGION
#define NULL_BRUSH						GDI_NULL_BRUSH
#define NULL_PEN						GDI_NULL_PEN
#define NUMBRUSHES						GDI_NUMBRUSHES
#define NUMCOLORS						GDI_NUMCOLORS
#define NUMFONTS						GDI_NUMFONTS
#define NUMMARKERS						GDI_NUMMARKERS
#define NUMPENS							GDI_NUMPENS
#define NUMRESERVED						GDI_NUMRESERVED
#define OBJ_BITMAP						GDI_OBJ_BITMAP
#define OBJ_BRUSH						GDI_OBJ_BRUSH
#define OBJ_COLORSPACE						GDI_OBJ_COLORSPACE
#define OBJ_DC							GDI_OBJ_DC
#define OBJ_ENHMETADC						GDI_OBJ_ENHMETADC
#define OBJ_ENHMETAFILE						GDI_OBJ_ENHMETAFILE
#define OBJ_EXTPEN						GDI_OBJ_EXTPEN
#define OBJ_FONT						GDI_OBJ_FONT
#define OBJ_MEMDC						GDI_OBJ_MEMDC
#define OBJ_METADC						GDI_OBJ_METADC
#define OBJ_METAFILE						GDI_OBJ_METAFILE
#define OBJ_PAL							GDI_OBJ_PAL
#define OBJ_PEN							GDI_OBJ_PEN
#define OBJ_REGION						GDI_OBJ_REGION
#define OEM_CHARSET						GDI_OEM_CHARSET
#define OEM_FIXED_FONT						GDI_OEM_FIXED_FONT
#define OPAQUE							GDI_OPAQUE
#define OPENCHANNEL						GDI_OPENCHANNEL
#define OUT_CHARACTER_PRECIS					GDI_OUT_CHARACTER_PRECIS
#define OUT_DEFAULT_PRECIS					GDI_OUT_DEFAULT_PRECIS
#define OUT_DEVICE_PRECIS					GDI_OUT_DEVICE_PRECIS
#define OUT_OUTLINE_PRECIS					GDI_OUT_OUTLINE_PRECIS
#define OUT_PS_ONLY_PRECIS					GDI_OUT_PS_ONLY_PRECIS
#define OUT_RASTER_PRECIS					GDI_OUT_RASTER_PRECIS
#define OUT_SCREEN_OUTLINE_PRECIS				GDI_OUT_SCREEN_OUTLINE_PRECIS
#define OUT_STRING_PRECIS					GDI_OUT_STRING_PRECIS
#define OUT_STROKE_PRECIS					GDI_OUT_STROKE_PRECIS
#define OUT_TT_ONLY_PRECIS					GDI_OUT_TT_ONLY_PRECIS
#define OUT_TT_PRECIS						GDI_OUT_TT_PRECIS
#define PANOSE_COUNT						GDI_PANOSE_COUNT
#define PAN_ANY							GDI_PAN_ANY
#define PAN_ARMSTYLE_INDEX					GDI_PAN_ARMSTYLE_INDEX
#define PAN_BENT_ARMS_DOUBLE_SERIF				GDI_PAN_BENT_ARMS_DOUBLE_SERIF
#define PAN_BENT_ARMS_HORZ					GDI_PAN_BENT_ARMS_HORZ
#define PAN_BENT_ARMS_SINGLE_SERIF				GDI_PAN_BENT_ARMS_SINGLE_SERIF
#define PAN_BENT_ARMS_VERT					GDI_PAN_BENT_ARMS_VERT
#define PAN_BENT_ARMS_WEDGE					GDI_PAN_BENT_ARMS_WEDGE
#define PAN_CONTRAST_HIGH					GDI_PAN_CONTRAST_HIGH
#define PAN_CONTRAST_INDEX					GDI_PAN_CONTRAST_INDEX
#define PAN_CONTRAST_LOW					GDI_PAN_CONTRAST_LOW
#define PAN_CONTRAST_MEDIUM					GDI_PAN_CONTRAST_MEDIUM
#define PAN_CONTRAST_MEDIUM_HIGH				GDI_PAN_CONTRAST_MEDIUM_HIGH
#define PAN_CONTRAST_MEDIUM_LOW					GDI_PAN_CONTRAST_MEDIUM_LOW
#define PAN_CONTRAST_NONE					GDI_PAN_CONTRAST_NONE
#define PAN_CONTRAST_VERY_HIGH					GDI_PAN_CONTRAST_VERY_HIGH
#define PAN_CONTRAST_VERY_LOW					GDI_PAN_CONTRAST_VERY_LOW
#define PAN_CULTURE_LATIN					GDI_PAN_CULTURE_LATIN
#define PAN_FAMILYTYPE_INDEX					GDI_PAN_FAMILYTYPE_INDEX
#define PAN_FAMILY_DECORATIVE					GDI_PAN_FAMILY_DECORATIVE
#define PAN_FAMILY_PICTORIAL					GDI_PAN_FAMILY_PICTORIAL
#define PAN_FAMILY_SCRIPT					GDI_PAN_FAMILY_SCRIPT
#define PAN_FAMILY_TEXT_DISPLAY					GDI_PAN_FAMILY_TEXT_DISPLAY
#define PAN_LETTERFORM_INDEX					GDI_PAN_LETTERFORM_INDEX
#define PAN_LETT_NORMAL_BOXED					GDI_PAN_LETT_NORMAL_BOXED
#define PAN_LETT_NORMAL_CONTACT					GDI_PAN_LETT_NORMAL_CONTACT
#define PAN_LETT_NORMAL_FLATTENED				GDI_PAN_LETT_NORMAL_FLATTENED
#define PAN_LETT_NORMAL_OFF_CENTER				GDI_PAN_LETT_NORMAL_OFF_CENTER
#define PAN_LETT_NORMAL_ROUNDED					GDI_PAN_LETT_NORMAL_ROUNDED
#define PAN_LETT_NORMAL_SQUARE					GDI_PAN_LETT_NORMAL_SQUARE
#define PAN_LETT_NORMAL_WEIGHTED				GDI_PAN_LETT_NORMAL_WEIGHTED
#define PAN_LETT_OBLIQUE_BOXED					GDI_PAN_LETT_OBLIQUE_BOXED
#define PAN_LETT_OBLIQUE_CONTACT				GDI_PAN_LETT_OBLIQUE_CONTACT
#define PAN_LETT_OBLIQUE_FLATTENED				GDI_PAN_LETT_OBLIQUE_FLATTENED
#define PAN_LETT_OBLIQUE_OFF_CENTER				GDI_PAN_LETT_OBLIQUE_OFF_CENTER
#define PAN_LETT_OBLIQUE_ROUNDED				GDI_PAN_LETT_OBLIQUE_ROUNDED
#define PAN_LETT_OBLIQUE_SQUARE					GDI_PAN_LETT_OBLIQUE_SQUARE
#define PAN_LETT_OBLIQUE_WEIGHTED				GDI_PAN_LETT_OBLIQUE_WEIGHTED
#define PAN_MIDLINE_CONSTANT_POINTED				GDI_PAN_MIDLINE_CONSTANT_POINTED
#define PAN_MIDLINE_CONSTANT_SERIFED				GDI_PAN_MIDLINE_CONSTANT_SERIFED
#define PAN_MIDLINE_CONSTANT_TRIMMED				GDI_PAN_MIDLINE_CONSTANT_TRIMMED
#define PAN_MIDLINE_HIGH_POINTED				GDI_PAN_MIDLINE_HIGH_POINTED
#define PAN_MIDLINE_HIGH_SERIFED				GDI_PAN_MIDLINE_HIGH_SERIFED
#define PAN_MIDLINE_HIGH_TRIMMED				GDI_PAN_MIDLINE_HIGH_TRIMMED
#define PAN_MIDLINE_INDEX					GDI_PAN_MIDLINE_INDEX
#define PAN_MIDLINE_LOW_POINTED					GDI_PAN_MIDLINE_LOW_POINTED
#define PAN_MIDLINE_LOW_SERIFED					GDI_PAN_MIDLINE_LOW_SERIFED
#define PAN_MIDLINE_LOW_TRIMMED					GDI_PAN_MIDLINE_LOW_TRIMMED
#define PAN_MIDLINE_STANDARD_POINTED				GDI_PAN_MIDLINE_STANDARD_POINTED
#define PAN_MIDLINE_STANDARD_SERIFED				GDI_PAN_MIDLINE_STANDARD_SERIFED
#define PAN_MIDLINE_STANDARD_TRIMMED				GDI_PAN_MIDLINE_STANDARD_TRIMMED
#define PAN_NO_FIT						GDI_PAN_NO_FIT
#define PAN_PROPORTION_INDEX					GDI_PAN_PROPORTION_INDEX
#define PAN_PROP_CONDENSED					GDI_PAN_PROP_CONDENSED
#define PAN_PROP_EVEN_WIDTH					GDI_PAN_PROP_EVEN_WIDTH
#define PAN_PROP_EXPANDED					GDI_PAN_PROP_EXPANDED
#define PAN_PROP_MODERN						GDI_PAN_PROP_MODERN
#define PAN_PROP_MONOSPACED					GDI_PAN_PROP_MONOSPACED
#define PAN_PROP_OLD_STYLE					GDI_PAN_PROP_OLD_STYLE
#define PAN_PROP_VERY_CONDENSED					GDI_PAN_PROP_VERY_CONDENSED
#define PAN_PROP_VERY_EXPANDED					GDI_PAN_PROP_VERY_EXPANDED
#define PAN_SERIFSTYLE_INDEX					GDI_PAN_SERIFSTYLE_INDEX
#define PAN_SERIF_BONE						GDI_PAN_SERIF_BONE
#define PAN_SERIF_COVE						GDI_PAN_SERIF_COVE
#define PAN_SERIF_EXAGGERATED					GDI_PAN_SERIF_EXAGGERATED
#define PAN_SERIF_FLARED					GDI_PAN_SERIF_FLARED
#define PAN_SERIF_NORMAL_SANS					GDI_PAN_SERIF_NORMAL_SANS
#define PAN_SERIF_OBTUSE_COVE					GDI_PAN_SERIF_OBTUSE_COVE
#define PAN_SERIF_OBTUSE_SANS					GDI_PAN_SERIF_OBTUSE_SANS
#define PAN_SERIF_OBTUSE_SQUARE_COVE				GDI_PAN_SERIF_OBTUSE_SQUARE_COVE
#define PAN_SERIF_PERP_SANS					GDI_PAN_SERIF_PERP_SANS
#define PAN_SERIF_ROUNDED					GDI_PAN_SERIF_ROUNDED
#define PAN_SERIF_SQUARE					GDI_PAN_SERIF_SQUARE
#define PAN_SERIF_SQUARE_COVE					GDI_PAN_SERIF_SQUARE_COVE
#define PAN_SERIF_THIN						GDI_PAN_SERIF_THIN
#define PAN_SERIF_TRIANGLE					GDI_PAN_SERIF_TRIANGLE
#define PAN_STRAIGHT_ARMS_DOUBLE_SERIF				GDI_PAN_STRAIGHT_ARMS_DOUBLE_SERIF
#define PAN_STRAIGHT_ARMS_HORZ					GDI_PAN_STRAIGHT_ARMS_HORZ
#define PAN_STRAIGHT_ARMS_SINGLE_SERIF				GDI_PAN_STRAIGHT_ARMS_SINGLE_SERIF
#define PAN_STRAIGHT_ARMS_VERT					GDI_PAN_STRAIGHT_ARMS_VERT
#define PAN_STRAIGHT_ARMS_WEDGE					GDI_PAN_STRAIGHT_ARMS_WEDGE
#define PAN_STROKEVARIATION_INDEX				GDI_PAN_STROKEVARIATION_INDEX
#define PAN_STROKE_GRADUAL_DIAG					GDI_PAN_STROKE_GRADUAL_DIAG
#define PAN_STROKE_GRADUAL_HORZ					GDI_PAN_STROKE_GRADUAL_HORZ
#define PAN_STROKE_GRADUAL_TRAN					GDI_PAN_STROKE_GRADUAL_TRAN
#define PAN_STROKE_GRADUAL_VERT					GDI_PAN_STROKE_GRADUAL_VERT
#define PAN_STROKE_INSTANT_VERT					GDI_PAN_STROKE_INSTANT_VERT
#define PAN_STROKE_RAPID_HORZ					GDI_PAN_STROKE_RAPID_HORZ
#define PAN_STROKE_RAPID_VERT					GDI_PAN_STROKE_RAPID_VERT
#define PAN_WEIGHT_BLACK					GDI_PAN_WEIGHT_BLACK
#define PAN_WEIGHT_BOLD						GDI_PAN_WEIGHT_BOLD
#define PAN_WEIGHT_BOOK						GDI_PAN_WEIGHT_BOOK
#define PAN_WEIGHT_DEMI						GDI_PAN_WEIGHT_DEMI
#define PAN_WEIGHT_HEAVY					GDI_PAN_WEIGHT_HEAVY
#define PAN_WEIGHT_INDEX					GDI_PAN_WEIGHT_INDEX
#define PAN_WEIGHT_LIGHT					GDI_PAN_WEIGHT_LIGHT
#define PAN_WEIGHT_MEDIUM					GDI_PAN_WEIGHT_MEDIUM
#define PAN_WEIGHT_NORD						GDI_PAN_WEIGHT_NORD
#define PAN_WEIGHT_THIN						GDI_PAN_WEIGHT_THIN
#define PAN_WEIGHT_VERY_LIGHT					GDI_PAN_WEIGHT_VERY_LIGHT
#define PAN_XHEIGHT_CONSTANT_LARGE				GDI_PAN_XHEIGHT_CONSTANT_LARGE
#define PAN_XHEIGHT_CONSTANT_SMALL				GDI_PAN_XHEIGHT_CONSTANT_SMALL
#define PAN_XHEIGHT_CONSTANT_STD				GDI_PAN_XHEIGHT_CONSTANT_STD
#define PAN_XHEIGHT_DUCKING_LARGE				GDI_PAN_XHEIGHT_DUCKING_LARGE
#define PAN_XHEIGHT_DUCKING_SMALL				GDI_PAN_XHEIGHT_DUCKING_SMALL
#define PAN_XHEIGHT_DUCKING_STD					GDI_PAN_XHEIGHT_DUCKING_STD
#define PAN_XHEIGHT_INDEX					GDI_PAN_XHEIGHT_INDEX
#define PASSTHROUGH						GDI_PASSTHROUGH
#define PATCOPY							GDI_PATCOPY
#define PATINVERT						GDI_PATINVERT
#define PATPAINT						GDI_PATPAINT
#define PC_EXPLICIT						GDI_PC_EXPLICIT
#define PC_INTERIORS						GDI_PC_INTERIORS
#define PC_NOCOLLAPSE						GDI_PC_NOCOLLAPSE
#define PC_NONE							GDI_PC_NONE
#define PC_PATHS						GDI_PC_PATHS
#define PC_POLYGON						GDI_PC_POLYGON
#define PC_POLYPOLYGON						GDI_PC_POLYPOLYGON
#define PC_RECTANGLE						GDI_PC_RECTANGLE
#define PC_RESERVED						GDI_PC_RESERVED
#define PC_SCANLINE						GDI_PC_SCANLINE
#define PC_STYLED						GDI_PC_STYLED
#define PC_TRAPEZOID						GDI_PC_TRAPEZOID
#define PC_WIDE							GDI_PC_WIDE
#define PC_WIDESTYLED						GDI_PC_WIDESTYLED
#define PC_WINDPOLYGON						GDI_PC_WINDPOLYGON
#define PDEVICESIZE						GDI_PDEVICESIZE
#define PFD_DEPTH_DONTCARE					GDI_PFD_DEPTH_DONTCARE
#define PFD_DIRECT3D_ACCELERATED				GDI_PFD_DIRECT3D_ACCELERATED
#define PFD_DOUBLEBUFFER					GDI_PFD_DOUBLEBUFFER
#define PFD_DOUBLEBUFFER_DONTCARE				GDI_PFD_DOUBLEBUFFER_DONTCARE
#define PFD_DRAW_TO_BITMAP					GDI_PFD_DRAW_TO_BITMAP
#define PFD_DRAW_TO_WINDOW					GDI_PFD_DRAW_TO_WINDOW
#define PFD_GENERIC_ACCELERATED					GDI_PFD_GENERIC_ACCELERATED
#define PFD_GENERIC_FORMAT					GDI_PFD_GENERIC_FORMAT
#define PFD_MAIN_PLANE						GDI_PFD_MAIN_PLANE
#define PFD_NEED_PALETTE					GDI_PFD_NEED_PALETTE
#define PFD_NEED_SYSTEM_PALETTE					GDI_PFD_NEED_SYSTEM_PALETTE
#define PFD_OVERLAY_PLANE					GDI_PFD_OVERLAY_PLANE
#define PFD_STEREO						GDI_PFD_STEREO
#define PFD_STEREO_DONTCARE					GDI_PFD_STEREO_DONTCARE
#define PFD_SUPPORT_COMPOSITION					GDI_PFD_SUPPORT_COMPOSITION
#define PFD_SUPPORT_DIRECTDRAW					GDI_PFD_SUPPORT_DIRECTDRAW
#define PFD_SUPPORT_GDI						GDI_PFD_SUPPORT_GDI
#define PFD_SUPPORT_OPENGL					GDI_PFD_SUPPORT_OPENGL
#define PFD_SWAP_COPY						GDI_PFD_SWAP_COPY
#define PFD_SWAP_EXCHANGE					GDI_PFD_SWAP_EXCHANGE
#define PFD_SWAP_LAYER_BUFFERS					GDI_PFD_SWAP_LAYER_BUFFERS
#define PFD_TYPE_COLORINDEX					GDI_PFD_TYPE_COLORINDEX
#define PFD_TYPE_RGBA						GDI_PFD_TYPE_RGBA
#define PFD_UNDERLAY_PLANE					GDI_PFD_UNDERLAY_PLANE
#define PHYSICALHEIGHT						GDI_PHYSICALHEIGHT
#define PHYSICALOFFSETX						GDI_PHYSICALOFFSETX
#define PHYSICALOFFSETY						GDI_PHYSICALOFFSETY
#define PHYSICALWIDTH						GDI_PHYSICALWIDTH
#define PLANES							GDI_PLANES
#define POLYFILL_LAST						GDI_POLYFILL_LAST
#define POLYGONALCAPS						GDI_POLYGONALCAPS
#define POSTSCRIPT_DATA						GDI_POSTSCRIPT_DATA
#define POSTSCRIPT_IDENTIFY					GDI_POSTSCRIPT_IDENTIFY
#define POSTSCRIPT_IGNORE					GDI_POSTSCRIPT_IGNORE
#define POSTSCRIPT_INJECTION					GDI_POSTSCRIPT_INJECTION
#define POSTSCRIPT_PASSTHROUGH					GDI_POSTSCRIPT_PASSTHROUGH
#define PRINTRATEUNIT_CPS					GDI_PRINTRATEUNIT_CPS
#define PRINTRATEUNIT_IPM					GDI_PRINTRATEUNIT_IPM
#define PRINTRATEUNIT_LPM					GDI_PRINTRATEUNIT_LPM
#define PRINTRATEUNIT_PPM					GDI_PRINTRATEUNIT_PPM
#define PROFILE_EMBEDDED					GDI_PROFILE_EMBEDDED
#define PROFILE_LINKED						GDI_PROFILE_LINKED
#define PROOF_QUALITY						GDI_PROOF_QUALITY
#define PR_JOBSTATUS						GDI_PR_JOBSTATUS
#define PSIDENT_GDICENTRIC					GDI_PSIDENT_GDICENTRIC
#define PSIDENT_PSCENTRIC					GDI_PSIDENT_PSCENTRIC
#define PSINJECT_BEGINDEFAULTS					GDI_PSINJECT_BEGINDEFAULTS
#define PSINJECT_BEGINPAGESETUP					GDI_PSINJECT_BEGINPAGESETUP
#define PSINJECT_BEGINPROLOG					GDI_PSINJECT_BEGINPROLOG
#define PSINJECT_BEGINSETUP					GDI_PSINJECT_BEGINSETUP
#define PSINJECT_BEGINSTREAM					GDI_PSINJECT_BEGINSTREAM
#define PSINJECT_BOUNDINGBOX					GDI_PSINJECT_BOUNDINGBOX
#define PSINJECT_COMMENTS					GDI_PSINJECT_COMMENTS
#define PSINJECT_DLFONT						GDI_PSINJECT_DLFONT
#define PSINJECT_DOCNEEDEDRES					GDI_PSINJECT_DOCNEEDEDRES
#define PSINJECT_DOCSUPPLIEDRES					GDI_PSINJECT_DOCSUPPLIEDRES
#define PSINJECT_DOCUMENTPROCESSCOLORS				GDI_PSINJECT_DOCUMENTPROCESSCOLORS
#define PSINJECT_DOCUMENTPROCESSCOLORSATEND			GDI_PSINJECT_DOCUMENTPROCESSCOLORSATEND
#define PSINJECT_ENDDEFAULTS					GDI_PSINJECT_ENDDEFAULTS
#define PSINJECT_ENDPAGECOMMENTS				GDI_PSINJECT_ENDPAGECOMMENTS
#define PSINJECT_ENDPAGESETUP					GDI_PSINJECT_ENDPAGESETUP
#define PSINJECT_ENDPROLOG					GDI_PSINJECT_ENDPROLOG
#define PSINJECT_ENDSETUP					GDI_PSINJECT_ENDSETUP
#define PSINJECT_ENDSTREAM					GDI_PSINJECT_ENDSTREAM
#define PSINJECT_EOF						GDI_PSINJECT_EOF
#define PSINJECT_ORIENTATION					GDI_PSINJECT_ORIENTATION
#define PSINJECT_PAGEBBOX					GDI_PSINJECT_PAGEBBOX
#define PSINJECT_PAGENUMBER					GDI_PSINJECT_PAGENUMBER
#define PSINJECT_PAGEORDER					GDI_PSINJECT_PAGEORDER
#define PSINJECT_PAGES						GDI_PSINJECT_PAGES
#define PSINJECT_PAGESATEND					GDI_PSINJECT_PAGESATEND
#define PSINJECT_PAGETRAILER					GDI_PSINJECT_PAGETRAILER
#define PSINJECT_PLATECOLOR					GDI_PSINJECT_PLATECOLOR
#define PSINJECT_PSADOBE					GDI_PSINJECT_PSADOBE
#define PSINJECT_SHOWPAGE					GDI_PSINJECT_SHOWPAGE
#define PSINJECT_TRAILER					GDI_PSINJECT_TRAILER
#define PSINJECT_VMRESTORE					GDI_PSINJECT_VMRESTORE
#define PSINJECT_VMSAVE						GDI_PSINJECT_VMSAVE
#define PSPROTOCOL_ASCII					GDI_PSPROTOCOL_ASCII
#define PSPROTOCOL_BCP						GDI_PSPROTOCOL_BCP
#define PSPROTOCOL_BINARY					GDI_PSPROTOCOL_BINARY
#define PSPROTOCOL_TBCP						GDI_PSPROTOCOL_TBCP
#define PS_ALTERNATE						GDI_PS_ALTERNATE
#define PS_COSMETIC						GDI_PS_COSMETIC
#define PS_DASH							GDI_PS_DASH
#define PS_DASHDOT						GDI_PS_DASHDOT
#define PS_DASHDOTDOT						GDI_PS_DASHDOTDOT
#define PS_DOT							GDI_PS_DOT
#define PS_ENDCAP_FLAT						GDI_PS_ENDCAP_FLAT
#define PS_ENDCAP_MASK						GDI_PS_ENDCAP_MASK
#define PS_ENDCAP_ROUND						GDI_PS_ENDCAP_ROUND
#define PS_ENDCAP_SQUARE					GDI_PS_ENDCAP_SQUARE
#define PS_GEOMETRIC						GDI_PS_GEOMETRIC
#define PS_INSIDEFRAME						GDI_PS_INSIDEFRAME
#define PS_JOIN_BEVEL						GDI_PS_JOIN_BEVEL
#define PS_JOIN_MASK						GDI_PS_JOIN_MASK
#define PS_JOIN_MITER						GDI_PS_JOIN_MITER
#define PS_JOIN_ROUND						GDI_PS_JOIN_ROUND
#define PS_NULL							GDI_PS_NULL
#define PS_SOLID						GDI_PS_SOLID
#define PS_STYLE_MASK						GDI_PS_STYLE_MASK
#define PS_TYPE_MASK						GDI_PS_TYPE_MASK
#define PS_USERSTYLE						GDI_PS_USERSTYLE
#define PT_BEZIERTO						GDI_PT_BEZIERTO
#define PT_CLOSEFIGURE						GDI_PT_CLOSEFIGURE
#define PT_LINETO						GDI_PT_LINETO
#define PT_MOVETO						GDI_PT_MOVETO
#define QDC_ALL_PATHS						GDI_QDC_ALL_PATHS
#define QDC_DATABASE_CURRENT					GDI_QDC_DATABASE_CURRENT
#define QDC_ONLY_ACTIVE_PATHS					GDI_QDC_ONLY_ACTIVE_PATHS
#define QDI_DIBTOSCREEN						GDI_QDI_DIBTOSCREEN
#define QDI_GETDIBITS						GDI_QDI_GETDIBITS
#define QDI_SETDIBITS						GDI_QDI_SETDIBITS
#define QDI_STRETCHDIB						GDI_QDI_STRETCHDIB
#define QUERYDIBSUPPORT						GDI_QUERYDIBSUPPORT
#define QUERYESCSUPPORT						GDI_QUERYESCSUPPORT
#define R2_BLACK						GDI_R2_BLACK
#define R2_COPYPEN						GDI_R2_COPYPEN
#define R2_LAST							GDI_R2_LAST
#define R2_MASKNOTPEN						GDI_R2_MASKNOTPEN
#define R2_MASKPEN						GDI_R2_MASKPEN
#define R2_MASKPENNOT						GDI_R2_MASKPENNOT
#define R2_MERGENOTPEN						GDI_R2_MERGENOTPEN
#define R2_MERGEPEN						GDI_R2_MERGEPEN
#define R2_MERGEPENNOT						GDI_R2_MERGEPENNOT
#define R2_NOP							GDI_R2_NOP
#define R2_NOT							GDI_R2_NOT
#define R2_NOTCOPYPEN						GDI_R2_NOTCOPYPEN
#define R2_NOTMASKPEN						GDI_R2_NOTMASKPEN
#define R2_NOTMERGEPEN						GDI_R2_NOTMERGEPEN
#define R2_NOTXORPEN						GDI_R2_NOTXORPEN
#define R2_WHITE						GDI_R2_WHITE
#define R2_XORPEN						GDI_R2_XORPEN
#define RASTERCAPS						GDI_RASTERCAPS
#define RASTER_FONTTYPE						GDI_RASTER_FONTTYPE
#define RC_BANDING						GDI_RC_BANDING
#define RC_BIGFONT						GDI_RC_BIGFONT
#define RC_BITBLT						GDI_RC_BITBLT
#define RC_BITMAP64						GDI_RC_BITMAP64
#define RC_DEVBITS						GDI_RC_DEVBITS
#define RC_DIBTODEV						GDI_RC_DIBTODEV
#define RC_DI_BITMAP						GDI_RC_DI_BITMAP
#define RC_FLOODFILL						GDI_RC_FLOODFILL
#define RC_GDI20_OUTPUT						GDI_RC_GDI20_OUTPUT
#define RC_GDI20_STATE						GDI_RC_GDI20_STATE
#define RC_NONE							GDI_RC_NONE
#define RC_OP_DX_OUTPUT						GDI_RC_OP_DX_OUTPUT
#define RC_PALETTE						GDI_RC_PALETTE
#define RC_SAVEBITMAP						GDI_RC_SAVEBITMAP
#define RC_SCALING						GDI_RC_SCALING
#define RC_STRETCHBLT						GDI_RC_STRETCHBLT
#define RC_STRETCHDIB						GDI_RC_STRETCHDIB
#define RDH_RECTANGLES						GDI_RDH_RECTANGLES
#define REFERENCE_BLACK_MAX					GDI_REFERENCE_BLACK_MAX
#define REFERENCE_BLACK_MIN					GDI_REFERENCE_BLACK_MIN
#define REFERENCE_WHITE_MAX					GDI_REFERENCE_WHITE_MAX
#define REFERENCE_WHITE_MIN					GDI_REFERENCE_WHITE_MIN
#define RELATIVE						GDI_RELATIVE
#define RESTORE_CTM						GDI_RESTORE_CTM
#define RGB_GAMMA_MAX						GDI_RGB_GAMMA_MAX
#define RGB_GAMMA_MIN						GDI_RGB_GAMMA_MIN
#define RGN_AND							GDI_RGN_AND
#define RGN_COPY						GDI_RGN_COPY
#define RGN_DIFF						GDI_RGN_DIFF
#define RGN_ERROR						GDI_RGN_ERROR
#define RGN_MAX							GDI_RGN_MAX
#define RGN_MIN							GDI_RGN_MIN
#define RGN_OR							GDI_RGN_OR
#define RGN_XOR							GDI_RGN_XOR
#define RUSSIAN_CHARSET						GDI_RUSSIAN_CHARSET
#define SAVE_CTM						GDI_SAVE_CTM
#define SB_CONST_ALPHA						GDI_SB_CONST_ALPHA
#define SB_GRAD_RECT						GDI_SB_GRAD_RECT
#define SB_GRAD_TRI						GDI_SB_GRAD_TRI
#define SB_NONE							GDI_SB_NONE
#define SB_PIXEL_ALPHA						GDI_SB_PIXEL_ALPHA
#define SB_PREMULT_ALPHA					GDI_SB_PREMULT_ALPHA
#define SCALINGFACTORX						GDI_SCALINGFACTORX
#define SCALINGFACTORY						GDI_SCALINGFACTORY
#define SDC_ALLOW_CHANGES					GDI_SDC_ALLOW_CHANGES
#define SDC_ALLOW_PATH_ORDER_CHANGES				GDI_SDC_ALLOW_PATH_ORDER_CHANGES
#define SDC_APPLY						GDI_SDC_APPLY
#define SDC_FORCE_MODE_ENUMERATION				GDI_SDC_FORCE_MODE_ENUMERATION
#define SDC_NO_OPTIMIZATION					GDI_SDC_NO_OPTIMIZATION
#define SDC_PATH_PERSIST_IF_REQUIRED				GDI_SDC_PATH_PERSIST_IF_REQUIRED
#define SDC_SAVE_TO_DATABASE					GDI_SDC_SAVE_TO_DATABASE
#define SDC_TOPOLOGY_CLONE					GDI_SDC_TOPOLOGY_CLONE
#define SDC_TOPOLOGY_EXTEND					GDI_SDC_TOPOLOGY_EXTEND
#define SDC_TOPOLOGY_EXTERNAL					GDI_SDC_TOPOLOGY_EXTERNAL
#define SDC_TOPOLOGY_INTERNAL					GDI_SDC_TOPOLOGY_INTERNAL
#define SDC_TOPOLOGY_SUPPLIED					GDI_SDC_TOPOLOGY_SUPPLIED
#define SDC_USE_DATABASE_CURRENT				GDI_SDC_USE_DATABASE_CURRENT
#define SDC_USE_SUPPLIED_DISPLAY_CONFIG				GDI_SDC_USE_SUPPLIED_DISPLAY_CONFIG
#define SDC_VALIDATE						GDI_SDC_VALIDATE
#define SELECTPAPERSOURCE					GDI_SELECTPAPERSOURCE
#define SETABORTPROC						GDI_SETABORTPROC
#define SETALLJUSTVALUES					GDI_SETALLJUSTVALUES
#define SETCHARSET						GDI_SETCHARSET
#define SETCOLORTABLE						GDI_SETCOLORTABLE
#define SETCOPYCOUNT						GDI_SETCOPYCOUNT
#define SETDIBSCALING						GDI_SETDIBSCALING
#define SETICMPROFILE_EMBEDED					GDI_SETICMPROFILE_EMBEDED
#define SETKERNTRACK						GDI_SETKERNTRACK
#define SETLINECAP						GDI_SETLINECAP
#define SETLINEJOIN						GDI_SETLINEJOIN
#define SETMITERLIMIT						GDI_SETMITERLIMIT
#define SET_ARC_DIRECTION					GDI_SET_ARC_DIRECTION
#define SET_BACKGROUND_COLOR					GDI_SET_BACKGROUND_COLOR
#define SET_BOUNDS						GDI_SET_BOUNDS
#define SET_CLIP_BOX						GDI_SET_CLIP_BOX
#define SET_MIRROR_MODE						GDI_SET_MIRROR_MODE
#define SET_POLY_MODE						GDI_SET_POLY_MODE
#define SET_SCREEN_ANGLE					GDI_SET_SCREEN_ANGLE
#define SET_SPREAD						GDI_SET_SPREAD
#define SHADEBLENDCAPS						GDI_SHADEBLENDCAPS
#define SHIFTJIS_CHARSET					GDI_SHIFTJIS_CHARSET
#define SIMPLEREGION						GDI_SIMPLEREGION
#define SIZEPALETTE						GDI_SIZEPALETTE
#define SPCLPASSTHROUGH2					GDI_SPCLPASSTHROUGH2
#define SP_APPABORT						GDI_SP_APPABORT
#define SP_ERROR						GDI_SP_ERROR
#define SP_NOTREPORTED						GDI_SP_NOTREPORTED
#define SP_OUTOFDISK						GDI_SP_OUTOFDISK
#define SP_OUTOFMEMORY						GDI_SP_OUTOFMEMORY
#define SP_USERABORT						GDI_SP_USERABORT
#define SRCAND							GDI_SRCAND
#define SRCCOPY							GDI_SRCCOPY
#define SRCERASE						GDI_SRCERASE
#define SRCINVERT						GDI_SRCINVERT
#define SRCPAINT						GDI_SRCPAINT
#define STAMP_AXESLIST						GDI_STAMP_AXESLIST
#define STAMP_DESIGNVECTOR					GDI_STAMP_DESIGNVECTOR
#define STARTDOC						GDI_STARTDOC
#define STOCK_LAST						GDI_STOCK_LAST
#define STRETCHBLT						GDI_STRETCHBLT
#define STRETCH_ANDSCANS					GDI_STRETCH_ANDSCANS
#define STRETCH_DELETESCANS					GDI_STRETCH_DELETESCANS
#define STRETCH_HALFTONE					GDI_STRETCH_HALFTONE
#define STRETCH_ORSCANS						GDI_STRETCH_ORSCANS
#define SYMBOL_CHARSET						GDI_SYMBOL_CHARSET
#define SYSPAL_ERROR						GDI_SYSPAL_ERROR
#define SYSPAL_NOSTATIC						GDI_SYSPAL_NOSTATIC
#define SYSPAL_NOSTATIC256					GDI_SYSPAL_NOSTATIC256
#define SYSPAL_STATIC						GDI_SYSPAL_STATIC
#define SYSRGN							GDI_SYSRGN
#define SYSTEM_FIXED_FONT					GDI_SYSTEM_FIXED_FONT
#define SYSTEM_FONT						GDI_SYSTEM_FONT
#define TA_BASELINE						GDI_TA_BASELINE
#define TA_BOTTOM						GDI_TA_BOTTOM
#define TA_CENTER						GDI_TA_CENTER
#define TA_LEFT							GDI_TA_LEFT
#define TA_MASK							GDI_TA_MASK
#define TA_NOUPDATECP						GDI_TA_NOUPDATECP
#define TA_RIGHT						GDI_TA_RIGHT
#define TA_RTLREADING						GDI_TA_RTLREADING
#define TA_TOP							GDI_TA_TOP
#define TA_UPDATECP						GDI_TA_UPDATECP
#define TCI_SRCCHARSET						GDI_TCI_SRCCHARSET
#define TCI_SRCCODEPAGE						GDI_TCI_SRCCODEPAGE
#define TCI_SRCFONTSIG						GDI_TCI_SRCFONTSIG
#define TCI_SRCLOCALE						GDI_TCI_SRCLOCALE
#define TC_CP_STROKE						GDI_TC_CP_STROKE
#define TC_CR_90						GDI_TC_CR_90
#define TC_CR_ANY						GDI_TC_CR_ANY
#define TC_EA_DOUBLE						GDI_TC_EA_DOUBLE
#define TC_IA_ABLE						GDI_TC_IA_ABLE
#define TC_OP_CHARACTER						GDI_TC_OP_CHARACTER
#define TC_OP_STROKE						GDI_TC_OP_STROKE
#define TC_RA_ABLE						GDI_TC_RA_ABLE
#define TC_RESERVED						GDI_TC_RESERVED
#define TC_SA_CONTIN						GDI_TC_SA_CONTIN
#define TC_SA_DOUBLE						GDI_TC_SA_DOUBLE
#define TC_SA_INTEGER						GDI_TC_SA_INTEGER
#define TC_SCROLLBLT						GDI_TC_SCROLLBLT
#define TC_SF_X_YINDEP						GDI_TC_SF_X_YINDEP
#define TC_SO_ABLE						GDI_TC_SO_ABLE
#define TC_UA_ABLE						GDI_TC_UA_ABLE
#define TC_VA_ABLE						GDI_TC_VA_ABLE
#define TECHNOLOGY						GDI_TECHNOLOGY
#define TEXTCAPS						GDI_TEXTCAPS
#define THAI_CHARSET						GDI_THAI_CHARSET
#define TMPF_DEVICE						GDI_TMPF_DEVICE
#define TMPF_FIXED_PITCH					GDI_TMPF_FIXED_PITCH
#define TMPF_TRUETYPE						GDI_TMPF_TRUETYPE
#define TMPF_VECTOR						GDI_TMPF_VECTOR
#define TRANSFORM_CTM						GDI_TRANSFORM_CTM
#define TRANSPARENT						GDI_TRANSPARENT
#define TRUETYPE_FONTTYPE					GDI_TRUETYPE_FONTTYPE
#define TT_AVAILABLE						GDI_TT_AVAILABLE
#define TT_ENABLED						GDI_TT_ENABLED
#define TT_POLYGON_TYPE						GDI_TT_POLYGON_TYPE
#define TT_PRIM_CSPLINE						GDI_TT_PRIM_CSPLINE
#define TT_PRIM_LINE						GDI_TT_PRIM_LINE
#define TT_PRIM_QSPLINE						GDI_TT_PRIM_QSPLINE
#define TURKISH_CHARSET						GDI_TURKISH_CHARSET
#define VARIABLE_PITCH						GDI_VARIABLE_PITCH
#define VERTRES							GDI_VERTRES
#define VERTSIZE						GDI_VERTSIZE
#define VIETNAMESE_CHARSET					GDI_VIETNAMESE_CHARSET
#define VREFRESH						GDI_VREFRESH
#define VTA_BASELINE						GDI_VTA_BASELINE
#define VTA_BOTTOM						GDI_VTA_BOTTOM
#define VTA_CENTER						GDI_VTA_CENTER
#define VTA_LEFT						GDI_VTA_LEFT
#define VTA_RIGHT						GDI_VTA_RIGHT
#define VTA_TOP							GDI_VTA_TOP
#define WGL_FONT_LINES						GDI_WGL_FONT_LINES
#define WGL_FONT_POLYGONS					GDI_WGL_FONT_POLYGONS
#define WGL_SWAPMULTIPLE_MAX					GDI_WGL_SWAPMULTIPLE_MAX
#define WGL_SWAP_MAIN_PLANE					GDI_WGL_SWAP_MAIN_PLANE
#define WGL_SWAP_OVERLAY1					GDI_WGL_SWAP_OVERLAY1
#define WGL_SWAP_OVERLAY10					GDI_WGL_SWAP_OVERLAY10
#define WGL_SWAP_OVERLAY11					GDI_WGL_SWAP_OVERLAY11
#define WGL_SWAP_OVERLAY12					GDI_WGL_SWAP_OVERLAY12
#define WGL_SWAP_OVERLAY13					GDI_WGL_SWAP_OVERLAY13
#define WGL_SWAP_OVERLAY14					GDI_WGL_SWAP_OVERLAY14
#define WGL_SWAP_OVERLAY15					GDI_WGL_SWAP_OVERLAY15
#define WGL_SWAP_OVERLAY2					GDI_WGL_SWAP_OVERLAY2
#define WGL_SWAP_OVERLAY3					GDI_WGL_SWAP_OVERLAY3
#define WGL_SWAP_OVERLAY4					GDI_WGL_SWAP_OVERLAY4
#define WGL_SWAP_OVERLAY5					GDI_WGL_SWAP_OVERLAY5
#define WGL_SWAP_OVERLAY6					GDI_WGL_SWAP_OVERLAY6
#define WGL_SWAP_OVERLAY7					GDI_WGL_SWAP_OVERLAY7
#define WGL_SWAP_OVERLAY8					GDI_WGL_SWAP_OVERLAY8
#define WGL_SWAP_OVERLAY9					GDI_WGL_SWAP_OVERLAY9
#define WGL_SWAP_UNDERLAY1					GDI_WGL_SWAP_UNDERLAY1
#define WGL_SWAP_UNDERLAY10					GDI_WGL_SWAP_UNDERLAY10
#define WGL_SWAP_UNDERLAY11					GDI_WGL_SWAP_UNDERLAY11
#define WGL_SWAP_UNDERLAY12					GDI_WGL_SWAP_UNDERLAY12
#define WGL_SWAP_UNDERLAY13					GDI_WGL_SWAP_UNDERLAY13
#define WGL_SWAP_UNDERLAY14					GDI_WGL_SWAP_UNDERLAY14
#define WGL_SWAP_UNDERLAY15					GDI_WGL_SWAP_UNDERLAY15
#define WGL_SWAP_UNDERLAY2					GDI_WGL_SWAP_UNDERLAY2
#define WGL_SWAP_UNDERLAY3					GDI_WGL_SWAP_UNDERLAY3
#define WGL_SWAP_UNDERLAY4					GDI_WGL_SWAP_UNDERLAY4
#define WGL_SWAP_UNDERLAY5					GDI_WGL_SWAP_UNDERLAY5
#define WGL_SWAP_UNDERLAY6					GDI_WGL_SWAP_UNDERLAY6
#define WGL_SWAP_UNDERLAY7					GDI_WGL_SWAP_UNDERLAY7
#define WGL_SWAP_UNDERLAY8					GDI_WGL_SWAP_UNDERLAY8
#define WGL_SWAP_UNDERLAY9					GDI_WGL_SWAP_UNDERLAY9
#define WHITENESS						GDI_WHITENESS
#define WHITEONBLACK						GDI_WHITEONBLACK
#define WHITE_BRUSH						GDI_WHITE_BRUSH
#define WHITE_PEN						GDI_WHITE_PEN
#define WINDING							GDI_WINDING

#endif
