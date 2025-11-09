/*********************************************************
* EGE (Easy Graphics Engine)
* FileName      ege.h
* HomePage1     http://misakamm.github.com/xege
* HomePage2     http://misakamm.bitbucket.org/index.htm
* teiba1        http://tieba.baidu.com/f?kw=ege
* teiba2        http://tieba.baidu.com/f?kw=ege%C4%EF
* Blog:         http://misakamm.com
* E-Mail:       mailto:misakamm[at gmail com]
*
* FileName: ege.h
* 在 VC 下模拟 Borland BGI 绘图库，实现简单的绘图之余，扩展了较复杂的绘图能力
*
* 包含并使用本库时，不要包含conio.h头文件
* 这些头文件不应共存，否则可能会编译错误，
* 或者getch被conio.h内的覆盖（由包含次序决定），请注意
* 如需共存，请使用多文件分开包含的模式使用，
* 即不能一个cpp同时包含，但可以分开包含
* 使用本库，必须用C++编译，可支持的编译器：
* VC6/VC2008/VC2010/VC2012/VC2013/MinGW3.4.5/MinGW4.7.1/MinGW4.8.1
*********************************************************/

/****************************************************************************
** 注意事项：
* ★如果需要显示控制台窗口，请在包含本文件的前面加一行define SHOW_CONSOLE
* ★调用Sleep这个API时，或者调用delay，实际均会转化为调用delay_ms，如必需调用API请使用api_sleep
* ★delay_ms(0)能自行判断有没有更新的必要，连续多次但不大量的调用并不会产生帧率的影响
* ★调用delay_ms, delay_fps, getch, getkey, getmouse 时，窗口内容可能会更新，这些函数相当于内置了delay_ms(0)，
*   如果你只需要更新窗口，而不想等待，可以用delay_ms(0)。注意delay只延时而不更新窗口
* ★合理地使用delay_ms/delay_fps函数，可以减少你的程序占用的CPU，否则一个都没有调用同时也没有getch/getmouse的话，程序将占满一个CPU的时间
****************************************************************************/

#ifndef _EGE_H_
#define _EGE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#ifdef _GRAPH_LIB_BUILD_
#ifndef WINVER
#define WINVER 0x0400           // Specifies that the minimum required platform is Windows 95/NT4.
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400     // Specifies that the minimum required platform is Windows 95/NT4.
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410   // Specifies that the minimum required platform is Windows 98.
#endif
#endif

#ifndef __cplusplus
#error You must use C++ compiler, or you need filename with '.cpp' suffix
#endif

#if defined(_INC_CONIO) || defined(_CONIO_H_)
#error can not include "conio.h" before "graphics.h"
#endif

#if defined(_MSC_VER)
#	pragma warning(disable: 4355)
#	ifndef _ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH
#		define _ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH
#	endif
#	ifndef _ALLOW_RUNTIME_LIBRARY_MISMATCH
#		define _ALLOW_RUNTIME_LIBRARY_MISMATCH
#	endif
#endif

#if !defined(_GRAPH_LIB_BUILD_) && !defined(_GRAPH_NO_LIB_)
#	ifdef _MSC_VER
#		ifdef _WIN64 // 64 bit libs
#			if (_MSC_VER >= 2000)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics1664d.lib")
#				else
#					pragma comment(lib,"graphics1664.lib")
#				endif
#			elif (_MSC_VER >= 1910)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics1764d.lib")
#				else
#					pragma comment(lib,"graphics1764.lib")
#				endif
#			elif (_MSC_VER >= 1900)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics1564d.lib")
#				else
#					pragma comment(lib,"graphics1564.lib")
#				endif
#			elif (_MSC_VER >= 1800)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics1364d.lib")
#				else
#					pragma comment(lib,"graphics1364.lib")
#				endif
#			elif (_MSC_VER >= 1700)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics1264d.lib")
#				else
#					pragma comment(lib,"graphics1264.lib")
#				endif
#			elif (_MSC_VER >= 1600)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics1064d.lib")
#				else
#					pragma comment(lib,"graphics1064.lib")
#				endif
#			elif (_MSC_VER >= 1500)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics0864d.lib")
#				else
#					pragma comment(lib,"graphics0864.lib")
#				endif
#			elif (_MSC_VER > 1200)
#				pragma comment(lib,"graphics05.lib")
#			else
#				pragma comment(lib,"graphics.lib")
#			endif
#		else   // 32 bit libs
#			if (_MSC_VER >= 2000)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics16d.lib")
#				else
#					pragma comment(lib,"graphics16.lib")
#				endif
#			elif (_MSC_VER >= 1910)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics17d.lib")
#				else
#					pragma comment(lib,"graphics17.lib")
#				endif
#			elif (_MSC_VER >= 1900)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics15d.lib")
#				else
#					pragma comment(lib,"graphics15.lib")
#				endif
#			elif (_MSC_VER >= 1800)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics13d.lib")
#				else
#					pragma comment(lib,"graphics13.lib")
#				endif
#			elif (_MSC_VER >= 1700)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics12d.lib")
#				else
#					pragma comment(lib,"graphics12.lib")
#				endif
#			elif (_MSC_VER >= 1600)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics10d.lib")
#				else
#					pragma comment(lib,"graphics10.lib")
#				endif
#			elif (_MSC_VER >= 1500)
#				if 0 && defined(_DLL)
#					pragma comment(lib,"graphics08d.lib")
#				else
#					pragma comment(lib,"graphics08.lib")
#				endif
#			elif (_MSC_VER > 1200)
#				pragma comment(lib,"graphics05.lib")
#			else
#				pragma comment(lib,"graphics.lib")
#			endif
#		endif
#		if _MSC_VER >= 1700
#			ifdef _DEBUG
#			else
#			endif
#		elif _MSC_VER >= 1600
#			ifdef _DEBUG
#			else
#			endif
#		elif _MSC_VER > 1200
#			ifdef _DEBUG
//#				pragma comment(linker, "/NODEFAULTLIB:MSVCRTD.lib")
//#				pragma comment(linker, "/NODEFAULTLIB:libcmtd.lib")
//#				pragma comment(linker, "/NODEFAULTLIB:libcpmtd.lib")
#			else
#			endif
#		else
#			ifdef _DEBUG
//#				pragma comment(linker, "/NODEFAULTLIB:MSVCRTD.lib")
//#				pragma comment(linker, "/NODEFAULTLIB:libcd.lib")
//#				pragma comment(linker, "/NODEFAULTLIB:libcmtd.lib")
//#				pragma comment(linker, "/NODEFAULTLIB:libcpmtd.lib")
#			else
//#				pragma comment(linker, "/NODEFAULTLIB:MSVCRT.lib")
//#				pragma comment(linker, "/NODEFAULTLIB:libcmt.lib")
//#				pragma comment(linker, "/NODEFAULTLIB:libcp.lib")
#			endif
#		endif
#	endif
#endif

#if !defined(_GRAPH_LIB_BUILD_) && !defined(_GRAPH_NO_LIB_)
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif

#ifndef _CRT_NON_CONFORMING_SWPRINTFS
#define _CRT_NON_CONFORMING_SWPRINTFS
#endif

#endif

#include "windows.h"

#if defined(_MSC_VER) && _MSC_VER <= 1200 && !defined(SetWindowLongPtr)
#	define SetWindowLongPtrW   SetWindowLongW
#	define GetWindowLongPtrW   GetWindowLongW
#	define GWLP_USERDATA       GWL_USERDATA
#	define GWLP_WNDPROC        GWL_WNDPROC
#endif

#if !defined(_GRAPH_LIB_BUILD_) && !defined(_GRAPH_NO_LIB_)
#if defined(_MSC_VER) && _MSC_VER > 1200
//#	pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' ""version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


#ifndef WM_MOUSEWHEEL
#define WM_MOUSEWHEEL                   0x020A
#endif

#ifdef _GRAPH_LIB_BUILD_
#include <cstdio>
#endif

#ifndef _Cdecl
#	if __STDC__
#		define _Cdecl  __cdecl
#	else
#		define _Cdecl  __cdecl
#	endif
#endif

#ifdef _MSC_VER
#	if defined(_WIN64)
#		define EGEAPI
#	else
#		define EGEAPI _Cdecl
#	endif
#else
#	if defined(__WORDSIZE)
#		if __WORDSIZE > 32
#			define EGEAPI
#		else
#			define EGEAPI _Cdecl
#		endif
#	else
#		define EGEAPI
#	endif
#endif

#ifdef _GRAPH_LIB_BUILD_
#	define EGE_DEPRECATE(text)
#else
#	ifdef _MSC_VER
#		ifdef _CRT_DEPRECATE_TEXT
#			define EGE_DEPRECATE(text) _CRT_DEPRECATE_TEXT("This function is deprecated, more info visit http://tcgraphics.sourceforge.net/")
#		else
#			define EGE_DEPRECATE(text)
#		endif
#	else
#		define EGE_DEPRECATE(text) __attribute__((deprecated))
#	endif
#endif

#define SHOWCONSOLE             1       // 进入图形模式时，保留控制台的显示
#define RGBTOBGR(color)         ((((color) & 0xFF) << 16) | (((color) & 0xFF0000) >> 16) | ((color) & 0xFF00FF00))
#define EGERGB(r, g, b)         ( ((r)<<16) | ((g)<<8) | (b))
#define EGERGBA(r, g, b, a)     ( ((r)<<16) | ((g)<<8) | (b) | ((a)<<24) )
#define EGEARGB(a, r, g, b)     ( ((r)<<16) | ((g)<<8) | (b) | ((a)<<24) )
#define EGEACOLOR(a, color)     ( ((color) & 0xFFFFFF) | ((a)<<24) )
#define EGECOLORA(color, a)     ( ((color) & 0xFFFFFF) | ((a)<<24) )
#define EGEGET_R(c)             ( ((c)>>16) & 0xFF )
#define EGEGET_G(c)             ( ((c)>> 8) & 0xFF )
#define EGEGET_B(c)             ( ((c)) & 0xFF )
#define EGEGET_A(c)             ( ((c)>>24) & 0xFF )
#define EGEGRAY(gray)           ( ((gray)<<16) | ((gray)<<8) | (gray))
#define EGEGRAYA(gray, a)       ( ((gray)<<16) | ((gray)<<8) | (gray) | ((a)<<24) )
#define EGEAGRAY(a, gray)       ( ((gray)<<16) | ((gray)<<8) | (gray) | ((a)<<24) )
#define NAMESPACE_EGE_L         namespace ege {
#define NAMESPACE_EGE_R         }

NAMESPACE_EGE_L

const double PI = 3.1415926535897932384626;

enum graphics_drivers {     /* define graphics drivers */
	DETECT,         /* requests autodetection */
	CGA, MCGA, EGA, EGA64, EGAMONO, IBM8514,/* 1 - 6 */
	HERCMONO, ATT400, VGA, PC3270,          /* 7 - 10 */
	TRUECOLOR, TRUECOLORSIZE,
	CURRENT_DRIVER = -1
};

enum graphics_modes { /* graphics modes for each driver */
	CGAC0       = 0,  /* 320x200 palette 0; 1 page  */
	CGAC1       = 1,  /* 320x200 palette 1; 1 page  */
	CGAC2       = 2,  /* 320x200 palette 2: 1 page  */
	CGAC3       = 3,  /* 320x200 palette 3; 1 page  */
	CGAHI       = 4,  /* 640x200 1 page             */
	MCGAC0      = 0,  /* 320x200 palette 0; 1 page  */
	MCGAC1      = 1,  /* 320x200 palette 1; 1 page  */
	MCGAC2      = 2,  /* 320x200 palette 2; 1 page  */
	MCGAC3      = 3,  /* 320x200 palette 3; 1 page  */
	MCGAMED     = 4,  /* 640x200 1 page             */
	MCGAHI      = 5,  /* 640x480 1 page             */
	EGALO       = 0,  /* 640x200 16 color 4 pages   */
	EGAHI       = 1,  /* 640x350 16 color 2 pages   */
	EGA64LO     = 0,  /* 640x200 16 color 1 page    */
	EGA64HI     = 1,  /* 640x350 4 color  1 page    */
	EGAMONOHI   = 0,  /* 640x350 64K on card, 1 page - 256K on card, 4 pages */
	HERCMONOHI  = 0,  /* 720x348 2 pages            */
	ATT400C0    = 0,  /* 320x200 palette 0; 1 page  */
	ATT400C1    = 1,  /* 320x200 palette 1; 1 page  */
	ATT400C2    = 2,  /* 320x200 palette 2; 1 page  */
	ATT400C3    = 3,  /* 320x200 palette 3; 1 page  */
	ATT400MED   = 4,  /* 640x200 1 page             */
	ATT400HI    = 5,  /* 640x400 1 page             */
	VGALO       = 0,  /* 640x200 16 color 4 pages   */
	VGAMED      = 1,  /* 640x350 16 color 2 pages   */
	VGAHI       = 2,  /* 640x480 16 color 1 page    */
	PC3270HI    = 0,  /* 720x350 1 page             */
	IBM8514LO   = 0,  /* 640x480 256 colors         */
	IBM8514HI   = 1   /*1024x768 256 colors         */
};

enum graphics_errors {      /* graphresult error return codes */
	grOk                =   0,
	grNoInitGraph       =  -1,
	grNotDetected       =  -2,
	grFileNotFound      =  -3,
	grInvalidDriver     =  -4,
	grNoLoadMem         =  -5,
	grNoScanMem         =  -6,
	grNoFloodMem        =  -7,
	grFontNotFound      =  -8,
	grNoFontMem         =  -9,
	grInvalidMode       = -10,
	grError             = -11,   /* generic error */
	grIOerror           = -12,
	grInvalidFont       = -13,
	grInvalidFontNum    = -14,
	grInvalidVersion    = -18,
	grException         = 0x10,  /* ege error */
	grParamError        = 0x11,
	grInvalidRegion     = 0x12,
	grOutOfMemory       = 0x13,
	grNullPointer       = 0x14,
	grAllocError        = 0x15,
	grInvalidMemory     = 0xCDCDCDCD,
};

enum message_event {
	MSG_EVENT_UP            = 0x00,
	MSG_EVENT_DOWN          = 0x01,
	MSG_EVENT_CLICK         = 0x01,
	MSG_EVENT_DBCLICK       = 0x02,
	MSG_EVENT_MOVE          = 0x04,
	MSG_EVENT_WHEEL         = 0x10,
};

enum message_mouse {
	MSG_MOUSE_LEFT      = 0x01,
	MSG_MOUSE_RIGHT     = 0x02,
	MSG_MOUSE_MID       = 0x04,
};

// 颜色
enum COLORS {
	BLACK           = 0,
	BLUE            = EGERGB(0, 0, 0xA8),
	GREEN           = EGERGB(0, 0xA8, 0),
	CYAN            = EGERGB(0, 0xA8, 0xA8),
	RED             = EGERGB(0xA8, 0, 0),
	MAGENTA         = EGERGB(0xA8, 0, 0xA8),
	BROWN           = EGERGB(0xA8, 0xA8, 0),
	LIGHTGRAY       = EGERGB(0xA8, 0xA8, 0xA8),
	DARKGRAY        = EGERGB(0x54, 0x54, 0x54),
	LIGHTBLUE       = EGERGB(0x54, 0x54, 0xFC),
	LIGHTGREEN      = EGERGB(0x54, 0xFC, 0x54),
	LIGHTCYAN       = EGERGB(0x54, 0xFC, 0xFC),
	LIGHTRED        = EGERGB(0xFC, 0x54, 0x54),
	LIGHTMAGENTA    = EGERGB(0xFC, 0x54, 0xFC),
	YELLOW          = EGERGB(0xFC, 0xFC, 0x54),
	WHITE           = EGERGB(0xFC, 0xFC, 0xFC),
};

// 填充模式
enum fill_patterns {/* Fill patterns for get/setfillstyle */
	EMPTY_FILL,     /* fills area in background color */
	SOLID_FILL,     /* fills area in solid fill color */
	LINE_FILL,      /* --- fill */
	LTSLASH_FILL,   /* /// fill */
	SLASH_FILL,     /* /// fill with thick lines */
	BKSLASH_FILL,   /* \\\ fill with thick lines */
	LTBKSLASH_FILL, /* \\\ fill */
	HATCH_FILL,     /* light hatch fill */
	XHATCH_FILL,    /* heavy cross hatch fill */
	INTERLEAVE_FILL,/* interleaving line fill */
	WIDE_DOT_FILL,  /* Widely spaced dot fill */
	CLOSE_DOT_FILL, /* Closely spaced dot fill */
	USER_FILL       /* user defined fill */
};

enum text_just {        /* Horizontal and vertical justification
						for settextjustify */
	LEFT_TEXT   = 0,
	CENTER_TEXT = 1,
	RIGHT_TEXT  = 2,

	BOTTOM_TEXT = 0,
	/* CENTER_TEXT = 1,  already defined above */
	TOP_TEXT    = 2
};

enum line_styles {      /* Line styles for get/setlinestyle */
	SOLID_LINE      = PS_SOLID,
	CENTER_LINE     = PS_DASH,
	DOTTED_LINE     = PS_DOT,
	DASHED_LINE     = PS_DASHDOT,
	NULL_LINE       = PS_NULL,
	USERBIT_LINE    = PS_USERSTYLE,   /* User defined line style */
};

enum key_msg_flag {
	KEYMSG_CHAR_FLAG    = 2,
	KEYMSG_DOWN_FLAG    = 1,
	KEYMSG_UP_FLAG      = 1,

	KEYMSG_CHAR         = 0x40000,
	KEYMSG_DOWN         = 0x10000,
	KEYMSG_UP           = 0x20000,
	KEYMSG_FIRSTDOWN    = 0x80000,
};

enum music_state_flag {
	MUSIC_MODE_NOT_OPEN = 0x0,
	MUSIC_MODE_NOT_READY = 0x20C,
	MUSIC_MODE_PAUSE = 0x211,
	MUSIC_MODE_PLAY = 0x20E,
	MUSIC_MODE_STOP = 0x20D,
	MUSIC_MODE_OPEN = 0x212,
	MUSIC_MODE_SEEK = 0x210,
};

enum initmode_flag {
	INIT_NOBORDER       = 0x1,
	INIT_CHILD          = 0x2,
	INIT_TOPMOST        = 0x4,
	INIT_RENDERMANUAL   = 0x8,
	INIT_NOFORCEEXIT    = 0x10,
	INIT_WITHLOGO       = 0x100,
#if defined(_DEBUG) || defined(DEBUG)
	INIT_DEFAULT    = 0x0,
#else
	INIT_DEFAULT    = INIT_WITHLOGO,
#endif
	INIT_ANIMATION  = INIT_DEFAULT | INIT_RENDERMANUAL | INIT_NOFORCEEXIT,
};

enum rendermode_e {
	RENDER_AUTO,
	RENDER_MANUAL,
};

typedef enum key_code_e {
	key_mouse_l     = 0x01,
	key_mouse_r     = 0x02,
	key_mouse_m     = 0x04,
	key_back        = 0x08,
	key_tab         = 0x09,
	key_enter       = 0x0d,
	key_shift       = 0x10,
	key_control     = 0x11,
	key_menu        = 0x12,
	key_pause       = 0x13,
	key_capslock    = 0x14,
	key_esc         = 0x1b,
	key_space       = 0x20,

	key_pageup      = 0x21,
	key_pagedown    = 0x22,
	key_home        = 0x23,
	key_end         = 0x24,

	key_left        = 0x25,
	key_up          = 0x26,
	key_right       = 0x27,
	key_down        = 0x28,

	key_print       = 0x2a,
	key_snapshot    = 0x2c,
	key_insert      = 0x2d,
	key_delete      = 0x2e,

	key_0           = 0x30,
	key_1           = 0x31,
	key_2           = 0x32,
	key_3           = 0x33,
	key_4           = 0x34,
	key_5           = 0x35,
	key_6           = 0x36,
	key_7           = 0x37,
	key_8           = 0x38,
	key_9           = 0x39,

	key_A           = 0x41,
	key_Z           = 0x5a,
	key_win_l       = 0x5b,
	key_win_r       = 0x5c,

	key_sleep       = 0x5f,

	key_num0        = 0x60,
	key_num1        = 0x61,
	key_num2        = 0x62,
	key_num3        = 0x63,
	key_num4        = 0x64,
	key_num5        = 0x65,
	key_num6        = 0x66,
	key_num7        = 0x67,
	key_num8        = 0x68,
	key_num9        = 0x69,

	key_f1          = 0x70,
	key_f2          = 0x71,
	key_f3          = 0x72,
	key_f4          = 0x73,
	key_f5          = 0x74,
	key_f6          = 0x75,
	key_f7          = 0x76,
	key_f8          = 0x77,
	key_f9          = 0x78,
	key_f10         = 0x79,
	key_f11         = 0x7a,
	key_f12         = 0x7b,

	key_numlock     = 0x90,
	key_scrolllock  = 0x91,

	key_shift_l     = 0xa0,
	key_shift_r     = 0xa1,
	key_control_l   = 0xa2,
	key_control_r   = 0xa3,
	key_menu_l      = 0xa4,
	key_menu_r      = 0xa5,

	key_semicolon   = 0xba,
	key_plus        = 0xbb,
	key_comma       = 0xbc,
	key_minus       = 0xbd,
	key_period      = 0xbe,
	key_slash       = 0xbf,
	key_tilde       = 0xc0,
	key_lbrace      = 0xdb,
	key_backslash   = 0xdc,
	key_rbrace      = 0xdd,
	key_quote       = 0xde,

	key_ime_process = 0xe5,
}key_code_e;

typedef enum key_msg_e {
	key_msg_down    = 1,
	key_msg_up      = 2,
	key_msg_char    = 4,
}key_msg_e;
typedef enum key_flag_e {
	key_flag_shift  = 0x100,
	key_flag_ctrl   = 0x200,
}key_flag_e;

typedef enum mouse_msg_e {
	mouse_msg_down      = 0x10,
	mouse_msg_up        = 0x20,
	mouse_msg_move      = 0x40,
	mouse_msg_wheel     = 0x80,
}mouse_msg_e;
typedef enum mouse_flag_e {
	mouse_flag_left     = 1,
	mouse_flag_right    = 2,
	mouse_flag_mid      = 4,
	mouse_flag_shift    = 0x100,
	mouse_flag_ctrl     = 0x200,
}mouse_flag_e;

typedef enum pattern_type_e {
	pattern_none            = 0,
	pattern_lineargradient  = 1,
	pattern_pathgradient    = 2,
	pattern_texture         = 3,
}pattern_type_e;

typedef unsigned int color_t;

struct viewporttype {
	int left;
	int top;
	int right;
	int bottom;
	int clipflag;
};

struct textsettingstype {
	int font;
	int direction;
	int charsize;
	int horiz;
	int vert;
};

struct linestyletype {
	int linestyle;
	unsigned short upattern;
	int thickness;
};

typedef struct key_msg {
	int             key;
	key_msg_e       msg;
	unsigned int    flags;
}key_msg;

typedef struct mouse_msg {
	int             x;
	int             y;
	mouse_msg_e     msg;
	unsigned int    flags;
	int             wheel;
	bool is_left() { return (flags & mouse_flag_left) != 0; }
	bool is_right() { return (flags & mouse_flag_right) != 0; }
	bool is_mid() { return (flags & mouse_flag_mid) != 0; }
	bool is_down() { return msg == mouse_msg_down; }
	bool is_up() { return msg == mouse_msg_up; }
	bool is_move() { return msg == mouse_msg_move; }
	bool is_wheel() { return msg == mouse_msg_wheel; }
}mouse_msg;

typedef struct ege_point {
	float x;
	float y;
}ege_point;

typedef struct ege_rect {
	float x;
	float y;
	float w;
	float h;
}ege_rect;

typedef struct ege_colpoint {
	float   x;
	float   y;
	color_t color;
}ege_colpoint;

// 鼠标消息
#if defined(__GNUC__)
struct EGE_DEPRECATE(MOUSEMSG) MOUSEMSG {
#else
EGE_DEPRECATE(MOUSEMSG)
struct MOUSEMSG {
#endif
	UINT uMsg;              // 当前鼠标消息
	bool mkCtrl;            // Ctrl 键是否按下
	bool mkShift;           // Shift 键是否按下
	bool mkLButton;         // 鼠标左键是否按下
	bool mkMButton;         // 鼠标中键是否按下
	bool mkRButton;         // 鼠标右键是否按下
	short x;                // 当前鼠标 x 坐标
	short y;                // 当前鼠标 y 坐标
	short wheel;            // 鼠标滚轮滚动值(120为基数)
};

struct msg_createwindow {
	HANDLE hEvent;
	HWND hwnd;
	LPCWSTR classname;
	DWORD style;
	DWORD exstyle;
	unsigned id;
	LPVOID param;
};


// 绘图环境初始化参数
#define INITGRAPH(x, y) struct _initgraph_{_initgraph_(){initgraph(x, y);}\
	~_initgraph_(){closegraph();}}_g_initgraph_
#define INITGRAPH3(x, y, f) struct _initgraph_{_initgraph_(){initgraph(x, y, f);}\
	~_initgraph_(){closegraph();}}_g_initgraph_

//音乐类宏
#define MUSIC_ERROR  0xFFFFFFFF


typedef void (CALLBACK_PROC)();
typedef int (__stdcall MSG_KEY_PROC  )(void*, unsigned, int);
typedef int (__stdcall MSG_MOUSE_PROC)(void*, unsigned, int, int, int);
typedef CALLBACK_PROC       * LPCALLBACK_PROC;
typedef MSG_KEY_PROC        * LPMSG_KEY_PROC;
typedef MSG_MOUSE_PROC      * LPMSG_MOUSE_PROC;

/*
注意：以下函数的注释后带'###'的函数表示未实现
*/

struct VECTOR3D;

// 3d 计算辅助函数
void EGEAPI rotate_point3d_x(VECTOR3D  * pt, float r); //弧度，右手定则
void EGEAPI rotate_point3d_y(VECTOR3D  * pt, float r);
void EGEAPI rotate_point3d_z(VECTOR3D  * pt, float r);

struct VECTOR3D {
	float x, y, z;
	VECTOR3D() {
		x = 0; y = 0; z = 0;
	}
	VECTOR3D(float _x, float _y) {
		x = _x; y = _y; z = 0;
	}
	VECTOR3D(float _x, float _y, float _z) {
		x = _x; y = _y; z = _z;
	}
	VECTOR3D& operator = (const VECTOR3D& _fp)  {
		x = _fp.x; y = _fp.y; z = _fp.z;
		return *this;
	}
	VECTOR3D& operator += (const VECTOR3D& _fp);
	VECTOR3D& operator -= (const VECTOR3D& _fp);
	VECTOR3D operator + (const VECTOR3D& _fp) const;
	VECTOR3D operator - (const VECTOR3D& _fp) const;
	VECTOR3D& operator *= (float f); //缩放
	VECTOR3D operator * (float f) const; //缩放
	float operator * (const VECTOR3D& _fp) const; //点乘
	VECTOR3D operator & (const VECTOR3D& _fp) const; //叉乘
	VECTOR3D& operator &= (const VECTOR3D& _fp); //叉乘
	float GetModule() const;
	float GetSqrModule() const {
		return float(x*x + y*y + z*z);
	}
	VECTOR3D& SetModule(float m) {
		float t = m / GetModule();
		*this *= t;
		return *this;
	}
	VECTOR3D& Rotate(float rad, const VECTOR3D& v); //绕任意轴旋转，右手定则，rad为弧度
	VECTOR3D& Rotate(float rad, float x, float y, float z) {
		VECTOR3D v(x, y, z);
		return Rotate(rad, v);
	}
	VECTOR3D& Rotate(const VECTOR3D& e, const VECTOR3D& s = VECTOR3D(0.0f, 0.0f, 1.0f)); //从s到e之间的夹角确定旋转
	static float GetAngel(const VECTOR3D& e, const VECTOR3D& s = VECTOR3D(0.0f, 0.0f, 1.0f));
};


class IMAGE;
typedef IMAGE *PIMAGE;

// 绘图环境相关函数

void EGEAPI initgraph(int Width, int Height, int Flag = INIT_DEFAULT);    // 初始化图形环境
void EGEAPI initgraph(int* gdriver, int* gmode, char* path);   // 兼容 Borland C++ 3.1 的重载，只使用 640x480x24bit
void EGEAPI closegraph();                                      // 关闭图形环境
bool EGEAPI is_run();   // 判断UI是否退出
void EGEAPI setcaption(LPCSTR  caption);
void EGEAPI setcaption(LPCWSTR caption);

void EGEAPI setrendermode(rendermode_e mode);

// 绘图环境设置
PIMAGE  gettarget();
int     settarget(PIMAGE pbuf); // 用 NULL 设置窗口为绘图目标

void EGEAPI cleardevice(PIMAGE pimg = NULL);                   // 清屏

void EGEAPI getviewport(int *pleft, int *ptop, int *pright, int *pbottom, int *pclip = 0, PIMAGE pimg = NULL); // 获取视图信息
void EGEAPI setviewport(int left, int top, int right, int bottom, int clip = 1, PIMAGE pimg = NULL);           // 设置视图
void EGEAPI clearviewport(PIMAGE pimg = NULL);                                                                 // 清空视图

EGE_DEPRECATE(setactivepage)
void EGEAPI setactivepage(int page); // 设置当前绘图页，即绘图函数默认的输出缓冲，范围0-1，默认为0
EGE_DEPRECATE(setvisualpage)
void EGEAPI setvisualpage(int page); // 设置当前显示页，用于设置显示到窗口上的页，范围0-1，默认为0
EGE_DEPRECATE(swappage)
void EGEAPI swappage();
void EGEAPI window_getviewport(struct viewporttype * viewport);
void EGEAPI window_getviewport(int* left, int* top, int* right, int* bottom);
void EGEAPI window_setviewport(int  left, int  top, int  right, int  bottom);

// 绘图属性
EGE_DEPRECATE(setactivepage)
void EGEAPI getlinestyle(int *plinestyle, unsigned short *pupattern = NULL, int *pthickness = NULL, PIMAGE pimg = NULL); // 获取当前线形
void EGEAPI setlinestyle(int linestyle, unsigned short upattern = 0, int thickness = 1, PIMAGE pimg = NULL);          // 设置当前线形
void EGEAPI setlinewidth(float width, PIMAGE pimg = NULL);          // 设置当前线宽
//EGE_DEPRECATE(setactivepage)
//void getfillstyle(color_t *pcolor, int *ppattern = NULL, PIMAGE pimg = NULL);           // 获取填充类型 ###
EGE_DEPRECATE(setactivepage)
void EGEAPI setfillstyle(int pattern, color_t color, PIMAGE pimg = NULL);  // 设置填充类型

void EGEAPI setwritemode(int mode, PIMAGE pimg = NULL);         // 设置绘图位操作模式

//void EGEAPI graphdefaults(PIMAGE pimg = NULL);                  // 重置所有绘图设置为默认值 ###

// 色彩函数
color_t EGEAPI getcolor(PIMAGE pimg = NULL);                    // 获取当前绘图前景色
color_t EGEAPI getfillcolor(PIMAGE pimg = NULL);                // 获取当前绘图填充色
color_t EGEAPI getbkcolor(PIMAGE pimg = NULL);                  // 获取当前绘图背景色
void EGEAPI setcolor(color_t color, PIMAGE pimg = NULL);        // 设置当前绘图前景色
void EGEAPI setfillcolor(color_t color, PIMAGE pimg = NULL);    // 设置当前绘图填充色
void EGEAPI setbkcolor(color_t color, PIMAGE pimg = NULL);      // 设置当前绘图背景色（设置并做背景色像素替换）
void EGEAPI setbkcolor_f(color_t color, PIMAGE pimg = NULL);    // 快速设置当前绘图背景色（只设置不绘画）
void EGEAPI setfontbkcolor(color_t color, PIMAGE pimg = NULL);  // 设置当前文字背景色
void EGEAPI setbkmode(int iBkMode, PIMAGE pimg = NULL);         // 设置背景混合模式(0=OPAQUE, 1=TRANSPARENT)
void EGEAPI setinitmode(int mode = INIT_DEFAULT, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT); //设置初始化模式，mode=0为普通，1为无边框窗口，xy是初始窗口坐标
int  EGEAPI attachHWND(HWND hWnd);

// 兼容宏
#define RGBtoGRAY   rgb2gray
#define RGBtoHSL    rgb2hsl
#define RGBtoHSV    rgb2hsv
#define HSLtoRGB    hsl2rgb
#define HSVtoRGB    hsv2rgb

// 颜色模型转换函数
color_t     EGEAPI rgb2gray(color_t rgb);
void        EGEAPI rgb2hsl(color_t rgb, float *H, float *S, float *L);
void        EGEAPI rgb2hsv(color_t rgb, float *H, float *S, float *V);
color_t     EGEAPI hsl2rgb(float H, float S, float L);
color_t     EGEAPI hsv2rgb(float H, float S, float V);


// 基本绘图函数

color_t     EGEAPI getpixel  (int x, int y, PIMAGE pimg = NULL);                // 获取点的颜色
void        EGEAPI putpixel  (int x, int y, color_t color, PIMAGE pimg = NULL); // 画点
color_t     EGEAPI getpixel_f(int x, int y, PIMAGE pimg = NULL);                // 获取点的颜色
void        EGEAPI putpixel_f(int x, int y, color_t color, PIMAGE pimg = NULL); // 画点
void        EGEAPI putpixels  (int nPoint, int* pPoints, PIMAGE pimg = NULL);   // 批量画点
void        EGEAPI putpixels_f(int nPoint, int* pPoints, PIMAGE pimg = NULL);   // 批量画点

void EGEAPI moveto(int x, int y, PIMAGE pimg = NULL);                      // 移动当前点(绝对坐标)
void EGEAPI moverel(int dx, int dy, PIMAGE pimg = NULL);                   // 移动当前点(相对坐标)

void EGEAPI line(int x1, int y1, int x2, int y2, PIMAGE pimg = NULL);      // 画线
void EGEAPI linerel(int dx, int dy, PIMAGE pimg = NULL);                   // 画线(至相对坐标)
void EGEAPI lineto(int x, int y, PIMAGE pimg = NULL);                      // 画线(至绝对坐标)
void EGEAPI line_f(float x1, float y1, float x2, float y2, PIMAGE pimg = NULL);  // 画线
void EGEAPI linerel_f(float dx, float dy, PIMAGE pimg = NULL);                   // 画线(至相对坐标)
void EGEAPI lineto_f(float x, float y, PIMAGE pimg = NULL);                      // 画线(至绝对坐标)


void EGEAPI rectangle(int left, int top, int right, int bottom, PIMAGE pimg = NULL);   // 画矩形

//void EGEAPI getarccoords(int *px, int *py, int *pxstart, int *pystart, int *pxend, int *pyend, PIMAGE pimg = NULL);    // 获取圆弧坐标信息 ###
void EGEAPI arc(int x, int y, int stangle, int endangle, int radius, PIMAGE pimg = NULL);                  // 画圆弧
void EGEAPI circle(int x, int y, int radius, PIMAGE pimg = NULL);                                          // 画圆
void EGEAPI pieslice(int x, int y, int stangle, int endangle, int radius, PIMAGE pimg = NULL);             // 画填充圆扇形
void EGEAPI ellipse(int x, int y, int stangle, int endangle, int xradius, int yradius, PIMAGE pimg = NULL);// 画椭圆弧线
void EGEAPI fillellipse(int x, int y, int xradius, int yradius, PIMAGE pimg = NULL);                       // 画填充椭圆
void EGEAPI sector(int x, int y, int stangle, int endangle, int xradius, int yradius, PIMAGE pimg = NULL); // 画填充椭圆扇形

void EGEAPI arcf(float x, float y, float stangle, float endangle, float radius, PIMAGE pimg = NULL);                    // 画圆弧
void EGEAPI circlef(float x, float y, float radius, PIMAGE pimg = NULL);                                                // 画圆
void EGEAPI pieslicef(float x, float y, float stangle, float endangle, float radius, PIMAGE pimg = NULL);               // 画填充圆扇形
void EGEAPI ellipsef(float x, float y, float stangle, float endangle, float xradius, float yradius, PIMAGE pimg = NULL);// 画椭圆弧线
void EGEAPI fillellipsef(float x, float y, float xradius, float yradius, PIMAGE pimg = NULL);                           // 画填充椭圆
void EGEAPI sectorf(float x, float y, float stangle, float endangle, float xradius, float yradius, PIMAGE pimg = NULL); // 画填充椭圆扇形

void EGEAPI bar(int left, int top, int right, int bottom, PIMAGE pimg = NULL);                             // 画无边框填充矩形
void EGEAPI bar3d(int left, int top, int right, int bottom, int depth, int topflag, PIMAGE pimg = NULL);   // 画有边框三维填充矩形

void EGEAPI drawpoly(int numpoints, const int *polypoints, PIMAGE pimg = NULL);     // 画多边形
void EGEAPI drawlines(int numlines, const int *polypoints, PIMAGE pimg = NULL);     // 画多条不连续线（扩展函数）
void EGEAPI drawbezier(int numpoints, const int *polypoints, PIMAGE pimg = NULL);   // 画bezier曲线（扩展函数）
void EGEAPI fillpoly(int numpoints, const int *polypoints, PIMAGE pimg = NULL);     // 画填充的多边形
void EGEAPI fillpoly_gradient(int numpoints, const ege_colpoint* polypoints, PIMAGE pimg = NULL); // 画渐变填充的多边形
void EGEAPI floodfill(int x, int y, int border, PIMAGE pimg = NULL);                // 按边界颜色填充区域
void EGEAPI floodfillsurface(int x, int y, color_t areacolor, PIMAGE pimg = NULL);  // 按起始点颜色填充区域

// 高级绘图函数（带AA）
// ege new_api
void EGEAPI ege_enable_aa(bool enable, PIMAGE pimg = NULL);

void EGEAPI ege_line(float x1, float y1, float x2, float y2, PIMAGE pimg = NULL);
void EGEAPI ege_drawpoly(int numpoints, ege_point* polypoints, PIMAGE pimg = NULL);
void EGEAPI ege_drawcurve(int numpoints, ege_point* polypoints, PIMAGE pimg = NULL);
void EGEAPI ege_rectangle(float x, float y, float w, float h, PIMAGE pimg = NULL);
void EGEAPI ege_ellipse(float x, float y, float w, float h, PIMAGE pimg = NULL);
void EGEAPI ege_pie(float x, float y, float w, float h, float stangle, float sweepAngle, PIMAGE pimg = NULL);

void EGEAPI ege_arc(float x, float y, float w, float h, float stangle, float sweepAngle, PIMAGE pimg = NULL);
void EGEAPI ege_bezier(int numpoints, ege_point* polypoints, PIMAGE pimg = NULL);

void EGEAPI ege_fillpoly(int numpoints, ege_point* polypoints, PIMAGE pimg = NULL);
void EGEAPI ege_fillrect(float x, float y, float w, float h, PIMAGE pimg = NULL);
void EGEAPI ege_fillellipse(float x, float y, float w, float h, PIMAGE pimg = NULL);
void EGEAPI ege_fillpie(float x, float y, float w, float h, float stangle, float sweepAngle, PIMAGE pimg = NULL);

void EGEAPI ege_setpattern_none(PIMAGE pimg = NULL);
void EGEAPI ege_setpattern_lineargradient(float x1, float y1, color_t c1, float x2, float y2, color_t c2, PIMAGE pimg = NULL);
void EGEAPI ege_setpattern_pathgradient(ege_point center, color_t centercolor,
	int count, ege_point* points, int colcount, color_t* pointscolor, PIMAGE pimg = NULL);
void EGEAPI ege_setpattern_ellipsegradient(ege_point center, color_t centercolor,
	float x, float y, float w, float h, color_t color, PIMAGE pimg = NULL);
void EGEAPI ege_setpattern_texture(PIMAGE srcimg, float x, float y, float w, float h, PIMAGE pimg = NULL);

void EGEAPI ege_setalpha(int alpha, PIMAGE pimg = NULL);
void EGEAPI ege_gentexture(bool gen, PIMAGE pimg = NULL);
void EGEAPI ege_puttexture(PIMAGE srcimg, float x, float y, float w, float h, PIMAGE pimg = NULL);
void EGEAPI ege_puttexture(PIMAGE srcimg, ege_rect dest, PIMAGE pimg = NULL);
void EGEAPI ege_puttexture(PIMAGE srcimg, ege_rect dest, ege_rect src, PIMAGE pimg = NULL);
//

//int  EGEAPI Begin2d();
//void EGEAPI EndRender();

//时间函数（以下函数不能在多线程下使用，只能给绘图主线程调用）
void EGEAPI ege_sleep(long ms);     // 至少延迟ms毫秒
void EGEAPI delay(long ms);         // 至少延迟ms毫秒
void EGEAPI delay_ms(long ms);      // 平均延迟ms毫秒
void EGEAPI delay_fps(int fps);    // 平均延迟1000/fps毫秒，用于稳定帧率控制
void EGEAPI delay_fps(long fps);    // 平均延迟1000/fps毫秒，用于稳定帧率控制
void EGEAPI delay_fps(double fps);  // 平均延迟1000/fps毫秒，用于稳定帧率控制
void EGEAPI delay_jfps(int fps);   // 平均延迟1000/fps毫秒，用于稳定逻辑帧率控制，绘图带跳帧
void EGEAPI delay_jfps(long fps);   // 平均延迟1000/fps毫秒，用于稳定逻辑帧率控制，绘图带跳帧
void EGEAPI delay_jfps(double fps); // 平均延迟1000/fps毫秒，用于稳定逻辑帧率控制，绘图带跳帧
// 以下函数可以多线程下使用，非图形(worker)线程的sleep使用这个
void EGEAPI api_sleep(long dwMilliseconds);
double EGEAPI fclock(); // 获取以秒为单位的浮点时间，只用于计时用，精度0.01秒，

// 文字相关函数
void EGEAPI outtext(LPCSTR  textstring, PIMAGE pimg = NULL);                   // 在当前位置输出文字
void EGEAPI outtext(LPCWSTR textstring, PIMAGE pimg = NULL);                   // 在当前位置输出文字
void EGEAPI outtext(CHAR  c, PIMAGE pimg = NULL);                              // 在当前位置输出字符
void EGEAPI outtext(WCHAR c, PIMAGE pimg = NULL);                              // 在当前位置输出字符
void EGEAPI outtextxy(int x, int y, LPCSTR  textstring, PIMAGE pimg = NULL);   // 在指定位置输出文字
void EGEAPI outtextxy(int x, int y, LPCWSTR textstring, PIMAGE pimg = NULL);   // 在指定位置输出文字
void EGEAPI outtextxy(int x, int y, CHAR c, PIMAGE pimg = NULL);               // 在指定位置输出字符
void EGEAPI outtextxy(int x, int y, WCHAR c, PIMAGE pimg = NULL);              // 在指定位置输出字符
void EGEAPI outtextrect(int x, int y, int w, int h, LPCSTR  textstring, PIMAGE pimg = NULL); // 在指定矩形范围输出文字
void EGEAPI outtextrect(int x, int y, int w, int h, LPCWSTR textstring, PIMAGE pimg = NULL); // 在指定矩形范围输出文字
void EGEAPI xyprintf(int x, int y, LPCSTR  fmt, ...); // 在指定位置输出格式化字符串，指定绘图目标调用settarget
void EGEAPI xyprintf(int x, int y, LPCWSTR fmt, ...); // 在指定位置输出格式化字符串，指定绘图目标调用settarget
void EGEAPI rectprintf(int x, int y, int w, int h, LPCSTR  fmt, ...); // 在指定矩形输出格式化字符串，指定绘图目标调用settarget
void EGEAPI rectprintf(int x, int y, int w, int h, LPCWSTR fmt, ...); // 在指定矩形输出格式化字符串，指定绘图目标调用settarget
int  EGEAPI textwidth(LPCSTR  textstring, PIMAGE pimg = NULL);                 // 获取字符串占用的像素宽
int  EGEAPI textwidth(LPCWSTR textstring, PIMAGE pimg = NULL);                 // 获取字符串占用的像素宽
int  EGEAPI textwidth(CHAR  c, PIMAGE pimg = NULL);
int  EGEAPI textwidth(WCHAR c, PIMAGE pimg = NULL);
int  EGEAPI textheight(LPCSTR  textstring, PIMAGE pimg = NULL);                // 获取字符串占用的像素高
int  EGEAPI textheight(LPCWSTR textstring, PIMAGE pimg = NULL);                // 获取字符串占用的像素高
int  EGEAPI textheight(CHAR  c, PIMAGE pimg = NULL);
int  EGEAPI textheight(WCHAR c, PIMAGE pimg = NULL);
void EGEAPI settextjustify(int horiz, int vert, PIMAGE pimg = NULL);

// 设置当前字体样式(详见帮助)
//      nHeight: 字符的平均高度；
//      nWidth: 字符的平均宽度(0 表示自适应)；
//      lpszFace: 字体名称；
//      nEscapement: 字符串的书写角度(单位 0.1 度)；
//      nOrientation: 每个字符的书写角度(单位 0.1 度)；
//      nWeight: 字符的笔画粗细(0 表示默认粗细)；
//      bItalic: 是否斜体；
//      bUnderline: 是否下划线；
//      bStrikeOut: 是否删除线；
//      fbCharSet: 指定字符集；
//      fbOutPrecision: 指定文字的输出精度；
//      fbClipPrecision: 指定文字的剪辑精度；
//      fbQuality: 指定文字的输出质量；
//      fbPitchAndFamily: 指定以常规方式描述字体的字体系列。
void EGEAPI setfont(int nHeight, int nWidth, LPCSTR lpszFace,  PIMAGE pimg = NULL);
void EGEAPI setfont(int nHeight, int nWidth, LPCWSTR lpszFace, PIMAGE pimg = NULL);
void EGEAPI setfont(int nHeight, int nWidth, LPCSTR lpszFace,  int nEscapement, int nOrientation,
					int nWeight, int bItalic, int bUnderline, int bStrikeOut, PIMAGE pimg = NULL);
void EGEAPI setfont(int nHeight, int nWidth, LPCWSTR lpszFace, int nEscapement, int nOrientation,
					int nWeight, int bItalic, int bUnderline, int bStrikeOut, PIMAGE pimg = NULL);
void EGEAPI setfont(int nHeight, int nWidth, LPCSTR lpszFace,  int nEscapement, int nOrientation,
					int nWeight, int bItalic, int bUnderline, int bStrikeOut, BYTE fbCharSet,
					BYTE fbOutPrecision, BYTE fbClipPrecision, BYTE fbQuality, BYTE fbPitchAndFamily, PIMAGE pimg = NULL);
void EGEAPI setfont(int nHeight, int nWidth, LPCWSTR lpszFace, int nEscapement, int nOrientation,
					int nWeight, int bItalic, int bUnderline, int bStrikeOut, BYTE fbCharSet,
					BYTE fbOutPrecision, BYTE fbClipPrecision, BYTE fbQuality, BYTE fbPitchAndFamily, PIMAGE pimg = NULL);
void EGEAPI setfont(const LOGFONTA *font, PIMAGE pimg = NULL); // 设置当前字体样式
void EGEAPI setfont(const LOGFONTW *font, PIMAGE pimg = NULL); // 设置当前字体样式
void EGEAPI getfont(LOGFONTA *font, PIMAGE pimg = NULL);       // 获取当前字体样式
void EGEAPI getfont(LOGFONTW *font, PIMAGE pimg = NULL);       // 获取当前字体样式


//图片函数
#define getmaxx getwidth
#define getmaxy getheight

int EGEAPI getwidth(PIMAGE pimg = NULL);           // 获取图片宽度
int EGEAPI getheight(PIMAGE pimg = NULL);          // 获取图片高度
int EGEAPI getx(PIMAGE pimg = NULL);               // 获取当前 x 坐标
int EGEAPI gety(PIMAGE pimg = NULL);               // 获取当前 y 坐标

PIMAGE      EGEAPI newimage(); // 创建PIMAGE
PIMAGE      EGEAPI newimage(int width, int height); // 创建PIMAGE
void        EGEAPI delimage(PIMAGE pImg); // 创建PIMAGE
color_t*    EGEAPI getbuffer(PIMAGE pImg);

int  EGEAPI resize(PIMAGE pDstImg, int width, int height); //重设尺寸
void EGEAPI getimage(PIMAGE pDstImg, int srcX, int srcY, int srcWidth, int srcHeight);             // 从屏幕获取图像
void EGEAPI getimage(PIMAGE pDstImg, const PIMAGE pSrcImg, int srcX, int srcY, int srcWidth, int srcHeight);   // 从另一个 PIMAGE 对象中获取图像
int  EGEAPI getimage(PIMAGE pDstImg, LPCSTR  pImgFile, int zoomWidth = 0, int zoomHeight = 0);     // 从图片文件获取图像(bmp/jpg/gif/emf/wmf)
int  EGEAPI getimage(PIMAGE pDstImg, LPCWSTR pImgFile, int zoomWidth = 0, int zoomHeight = 0);     // 从图片文件获取图像(bmp/jpg/gif/emf/wmf)
int  EGEAPI getimage(PIMAGE pDstImg, LPCSTR  pResType, LPCSTR  pResName, int zoomWidth = 0, int zoomHeight = 0);   // 从资源文件获取图像(bmp/jpg/gif/emf/wmf)
int  EGEAPI getimage(PIMAGE pDstImg, LPCWSTR pResType, LPCWSTR pResName, int zoomWidth = 0, int zoomHeight = 0);   // 从资源文件获取图像(bmp/jpg/gif/emf/wmf)
void EGEAPI putimage(int dstX, int dstY, const PIMAGE pSrcImg, DWORD dwRop = SRCCOPY);                         // 绘制图像到屏幕
void EGEAPI putimage(int dstX, int dstY, int dstWidth, int dstHeight, const PIMAGE pSrcImg, int srcX, int srcY, DWORD dwRop = SRCCOPY);    // 绘制图像到屏幕(指定宽高)
void EGEAPI putimage(int dstX, int dstY, int dstWidth, int dstHeight, const PIMAGE pSrcImg, int srcX, int srcY, int srcWidth, int srcHeight, DWORD dwRop = SRCCOPY);   // 绘制图像到屏幕(指定源宽高和目标宽高进行拉伸)
void EGEAPI putimage(PIMAGE pDstImg, int dstX, int dstY, const PIMAGE pSrcImg, DWORD dwRop = SRCCOPY);         // 绘制图像到另一图像中
void EGEAPI putimage(PIMAGE pDstImg, int dstX, int dstY, int dstWidth, int dstHeight, const PIMAGE pSrcImg, int srcX, int srcY, DWORD dwRop = SRCCOPY);    // 绘制图像到另一图像中(指定宽高)
void EGEAPI putimage(PIMAGE pDstImg, int dstX, int dstY, int dstWidth, int dstHeight, const PIMAGE pSrcImg, int srcX, int srcY, int srcWidth, int srcHeight, DWORD dwRop = SRCCOPY);   // 绘制图像到另一图像中(指定源宽高和目标宽高进行拉伸)
int  EGEAPI saveimage(PIMAGE pimg, LPCSTR  filename);
int  EGEAPI saveimage(PIMAGE pimg, LPCWSTR filename);
int  EGEAPI savepng(PIMAGE pimg, LPCSTR  filename, int bAlpha = 0);
int  EGEAPI savepng(PIMAGE pimg, LPCWSTR filename, int bAlpha = 0);
int  EGEAPI getimage_pngfile(PIMAGE pimg, LPCSTR  filename);
int  EGEAPI getimage_pngfile(PIMAGE pimg, LPCWSTR filename);

int EGEAPI putimage_transparent(
	PIMAGE imgdest,         // handle to dest
	PIMAGE imgsrc,          // handle to source
	int nXOriginDest,       // x-coord of destination upper-left corner
	int nYOriginDest,       // y-coord of destination upper-left corner
	color_t crTransparent,  // color to make transparent
	int nXOriginSrc = 0,    // x-coord of source upper-left corner
	int nYOriginSrc = 0,    // y-coord of source upper-left corner
	int nWidthSrc = 0,      // width of source rectangle
	int nHeightSrc = 0      // height of source rectangle
);
int EGEAPI putimage_alphablend(
	PIMAGE imgdest,         // handle to dest
	PIMAGE imgsrc,          // handle to source
	int nXOriginDest,       // x-coord of destination upper-left corner
	int nYOriginDest,       // y-coord of destination upper-left corner
	unsigned char alpha,    // alpha
	int nXOriginSrc = 0,    // x-coord of source upper-left corner
	int nYOriginSrc = 0,    // y-coord of source upper-left corner
	int nWidthSrc = 0,      // width of source rectangle
	int nHeightSrc = 0      // height of source rectangle
);
int EGEAPI putimage_alphatransparent(
	PIMAGE imgdest,         // handle to dest
	PIMAGE imgsrc,          // handle to source
	int nXOriginDest,       // x-coord of destination upper-left corner
	int nYOriginDest,       // y-coord of destination upper-left corner
	color_t crTransparent,  // color to make transparent
	unsigned char alpha,    // alpha
	int nXOriginSrc = 0,    // x-coord of source upper-left corner
	int nYOriginSrc = 0,    // y-coord of source upper-left corner
	int nWidthSrc = 0,      // width of source rectangle
	int nHeightSrc = 0      // height of source rectangle
);
int EGEAPI putimage_withalpha(
	PIMAGE imgdest,         // handle to dest
	PIMAGE imgsrc,          // handle to source
	int nXOriginDest,       // x-coord of destination upper-left corner
	int nYOriginDest,       // y-coord of destination upper-left corner
	int nXOriginSrc = 0,    // x-coord of source upper-left corner
	int nYOriginSrc = 0,    // y-coord of source upper-left corner
	int nWidthSrc = 0,      // width of source rectangle
	int nHeightSrc = 0      // height of source rectangle
);
int EGEAPI imagefilter_blurring (
	PIMAGE imgdest,         // handle to dest
	int intensity,
	int alpha,
	int nXOriginDest = 0,
	int nYOriginDest = 0,
	int nWidthDest = 0,
	int nHeightDest = 0
);
int EGEAPI putimage_rotate(
	PIMAGE imgdest,
	PIMAGE imgtexture,
	int nXOriginDest,
	int nYOriginDest,
	float centerx,
	float centery,
	float radian,
	int btransparent = 0,           // transparent (1) or not (0)
	int alpha = -1,                  // in range[0, 256], alpha== -1 means no alpha
	int smooth = 0
);

int EGEAPI putimage_rotatezoom(
	PIMAGE imgdest,
	PIMAGE imgtexture,
	int nXOriginDest,
	int nYOriginDest,
	float centerx,
	float centery,
	float radian,
	float zoom,
	int btransparent = 0,           // transparent (1) or not (0)
	int alpha = -1,                  // in range[0, 256], alpha== -1 means no alpha
	int smooth = 0
);

class PushTarget {
public:
	PushTarget() { m_target = gettarget(); }
	PushTarget(PIMAGE target) { m_target = gettarget(); settarget(target); }
	~PushTarget() { settarget(m_target); }
private:
	PIMAGE m_target;
};

#define CTL_PREINIT(classname, parent) \
	struct preinit_obj { \
		preinit_obj(classname* This, int inheritlevel) { \
			This->pre_init(inheritlevel); \
		} \
	}_preinit_obj; \
	enum inherit_e { inherit_level_e = parent::inherit_level_e + 1, }; \
	static void firstinit(ege::egeControlBase* This) { \
		((classname*)This)->m_inheritlevel = 1; \
	} \
	void pre_init(int inheritlevel) {\
		(void)inheritlevel;

#define CTL_PREINITEND  }
#define CTL_DEFPARAM    int inherit = inherit_level_e, ege::egeControlBase* pParent = NULL
#define CTL_INITBASE(parent)    _preinit_obj(this, inherit_level_e), parent(inherit, (ege::egeControlBase*)pParent)
#define CTL_INIT        InitObject iobj(this, inherit_level_e);\
						ege::PushTarget _pushtarget(buf());

#define EGECTRL_INITEND()     }

class egeControlBase
{
public:
	enum ROP {
		COPY    = SRCCOPY,
		XOR     = SRCINVERT,
		AND     = SRCAND,
		OR      = SRCPAINT,
	};
	enum blendmode_e {
		SOLIDCOPY = 0,
		ALPHABLEND = 1,
	};
	enum inherit_e {
		inherit_level_e = 0,
	};
	// 构造函数可以自定义，但要按需要选择使不使用宏，详见前面代码或者文档示例代码
	egeControlBase();
	egeControlBase(int inherit, egeControlBase* pParent);
	~egeControlBase();

	// 以下虚函数都不要直接相互调用
	virtual LRESULT onMessage(UINT message, WPARAM wParam, LPARAM lParam) { (void)message; (void)wParam; (void)lParam; return 0; }
	// 以下函数如果返回非0则不向子控件传递键盘鼠标消息
	virtual int  onMouse(int x, int y, int flag) { (void)x; (void)y; (void)flag; return 0; }
	virtual int  onKeyDown(int key, int flag) { (void)key; (void)flag; return 0; }
	virtual int  onKeyUp(int key, int flag) { (void)key; (void)flag; return 0; }
	virtual int  onKeyChar(int key, int flag) { (void)key; (void)flag; return 0; }
	// 屏幕更新后会被调用，用于更新逻辑
	virtual int  onUpdate() { return 0; }
	// 以下GetFocus在要获得焦点时调用，返回值一般返回0表示获取键盘输入焦点，返回非0放弃获得输入焦点
	virtual int  onGetFocus() { return 0; }
	// 失去输入焦点时调用
	virtual void onLostFocus() { }
	// 设置尺寸前调用，自定义修正函数
	virtual void onSizing(int *w, int *h) { (void)w; (void)h; }
	// 响应尺寸变化函数
	virtual void onSize(int w, int h) { (void)w; (void)h; }
	// 重绘函数，尽量请画到pimg上，以便能控制绘画目标
	virtual void onDraw(PIMAGE pimg) const { (void)pimg; }
	// 尺寸变化时调用，用于重画过滤缓冲区内容
	virtual void onResetFilter() {
		setbkcolor(BLACK, m_mainFilter);
		cleardevice(m_mainFilter);
	}
	virtual void onAddChild(egeControlBase* pChild) { (void)pChild; }
	virtual void onDelChild(egeControlBase* pChild) { (void)pChild; }
	virtual void onIdle() {} // 保留接口，未用
	// 这里以上的函数可以自行定义（注意声明要一致，不要漏掉OnDraw里的const）
	// 这里以下的public函数可以调用，不可自定义，任何预定义变量都不要直接访问，请使用预定义函数来控制
public:
	PIMAGE buf() { return m_mainbuf; }
	PIMAGE filter() { return m_mainFilter; }
	egeControlBase* parent() { return m_parent; }
	PIMAGE buf() const { return m_mainbuf; }
	PIMAGE filter() const { return m_mainFilter; }
	const egeControlBase* parent() const { return m_parent; }

	void blendmode(int mode) { m_AlphablendMode = mode; }
	void setrop(int rop) { m_rop = rop; } // 请用枚举类型ROP里所定义的

	void directdraw(bool bdraw) { m_bDirectDraw = (bdraw ? 1 : 0); }
	bool isdirectdraw() const { return (m_bDirectDraw != 0); }
	void autoredraw(bool bautoredraw)  { m_bAutoDraw = (bautoredraw ? 1 : 0); }
	bool isautoredraw() const       { return (m_bAutoDraw != 0); }
	void visable(bool bvisable)     { m_bVisable = (bvisable ? 1 : 0); }
	bool isvisable() const          { return (m_bVisable != 0); }
	void enable(bool benable)       { m_bEnable = (benable ? 1 : 0); }
	bool isenable() const           { return (m_bEnable != 0); }
	void capture(bool bcapture)     { m_bCapture = (bcapture ? 1 : 0); }
	bool iscapture() const          { return (m_bCapture != 0); }
	void capmouse(bool bcapmouse)   { m_bCapMouse = (bcapmouse ? 1 : 0); }
	bool iscapmouse() const         { return (m_bCapMouse != 0); }
	bool isfocus() const            { return (m_bInputFocus != 0); }
	void move(int x, int y)         { m_x = x; m_y = y; }
	void size(int w, int h) {
		onSizing(&w, &h);
		m_w = w; m_h = h;
		resize(m_mainbuf, w, h);
		resize(m_mainFilter, w, h);
		onSize(w, h);
		onResetFilter();
	}
	void zorderup();
	void zorderdown();
	void zorderset(int z);

	int getx()      const { return m_x; }
	int gety()      const { return m_y; }
	int getw()      const { return m_w; }
	int geth()      const { return m_h; }
	int width()     const { return m_w; }
	int height()    const { return m_h; }

	int  addchild(egeControlBase* pChild);
	int  delchild(egeControlBase* pChild);
	void draw(PIMAGE pimg);
	void update();
	void mouse(int x, int y, int flag);
	void keymsgdown(unsigned key, int flag);
	void keymsgup(unsigned key, int flag);
	void keymsgchar(unsigned key, int flag);
	bool operator < (const egeControlBase& pbase) const {
		if (m_zOrderLayer != pbase.m_zOrderLayer)
			return m_zOrderLayer < pbase.m_zOrderLayer;
		if (m_zOrder == pbase.m_zOrder)
			return this < &pbase;
		else
			return m_zOrder < pbase.m_zOrder;
	}
protected:
	int allocId();
	int allocZorder();
	class InitObject {
	public:
		InitObject(egeControlBase* pThis, int inherit_level);
		~InitObject();
	private:
		egeControlBase* m_this;
		int m_inherit_level;
	};
	void (* m_preinit_func )(egeControlBase*);
private:
	void init(egeControlBase* parent);
	void fixzorder();
	void sortzorder();
#if _MSC_VER <= 1200
public:
#endif
	void initok();
private:
	PIMAGE   m_mainbuf;      // 主缓冲
	PIMAGE   m_mainFilter;   // 过滤器

private:
	int m_bVisable;     // 是否可见
	int m_bEnable;      // 是否可获得输入（键盘和鼠标）
	int m_bAutoDraw;    // 是否自动绘画到窗口上
	int m_bCapture;     // 是否可获得键盘输入焦点
	int m_bInputFocus;  // 是否已经获得输入焦点
	int m_bCapMouse;    // 是否捕捉鼠标（即使不在所在区域内）
	int m_zOrderLayer;  // Z次序层（值较大者在前，值较小者会被其它控件遮挡）
	int m_zOrder;       // Z次序（值较大者在前，值较小者会被其它控件遮挡）
	int m_allocId;      // 分配id
	int m_allocZorder;  // 分配Z次序

	egeControlBase* m_parent;
	static int s_maxchildid;   // 下一次子控件分配ID值

#ifdef _GRAPH_LIB_BUILD_
public:
#else
private:
#endif
	void* m_childmap;       // 子控件
	void* m_childzorder;    // 子控件排序

protected:
	int m_x, m_y;       // 左上角坐标
	int m_w, m_h;       // 宽高

protected:
	DWORD   m_rop;              // 混合方式
	int     m_AlphablendMode;   // 绘画混合过滤方式
	int     m_bDirectDraw;      // 启用直接绘画
#if _MSC_VER <= 1200
public:
#endif
	int     m_inheritlevel;     // 继承层次
};

// 其它函数

HWND        EGEAPI getHWnd();         // 获取绘图窗口句柄
HINSTANCE   EGEAPI getHInstance();
PVOID       EGEAPI getProcfunc();
int         EGEAPI getGraphicsVer();   // 获取当前版本 ###
float       EGEAPI getfps(); // 获取当前帧率

//随机函数
void            EGEAPI randomize();
unsigned int    EGEAPI random(unsigned int n);
double          EGEAPI randomf();

//高级输入函数
// title 对话框标题， text 对话框提示文字， buf接收输入数据的字符串指针， len指出buf的最大长度，也同时会限制输入内容长度
int EGEAPI inputbox_getline(LPCSTR  title, LPCSTR  text, LPSTR  buf, int len);  //弹出对话框，让用户输入，当前程序运行暂停，返回非0表示输入有效，0为无效
int EGEAPI inputbox_getline(LPCWSTR title, LPCWSTR text, LPWSTR buf, int len);  //弹出对话框，让用户输入，当前程序运行暂停，返回非0表示输入有效，0为无效


//键盘处理函数
int     EGEAPI kbmsg();
key_msg EGEAPI getkey();
EGE_DEPRECATE(getchEx)
int     EGEAPI getchEx(int flag);
EGE_DEPRECATE(kbhitEx)
int     EGEAPI kbhitEx(int flag);
int     EGEAPI keystate(int key);       // 获得键码为key的键（见key_code_e）是否按下，如果key使用鼠标按键的键码，则获得的是鼠标键状态
void    EGEAPI flushkey();              // 清空键盘消息缓冲区

//#ifndef _GRAPH_LIB_BUILD_
#if !defined(_INC_CONIO) && !defined(_CONIO_H_)
#define _INC_CONIO
#define _CONIO_H_
int EGEAPI getch();
int EGEAPI kbhit();
#else
#define getch getchEx
#define kbhit kbhitEx
#endif
//#endif

//鼠标处理函数
int         EGEAPI mousemsg();                  // 检查是否存在鼠标消息
mouse_msg   EGEAPI getmouse();                  // 获取一个鼠标消息。如果没有，就等待
EGE_DEPRECATE(GetMouseMsg)
MOUSEMSG    EGEAPI GetMouseMsg();               // （不推荐使用的函数）获取一个鼠标消息。如果没有，就等待

void        EGEAPI flushmouse();                // 清空鼠标消息缓冲区
int         EGEAPI showmouse(int bShow);        // 设置是否显示鼠标
int         EGEAPI mousepos(int *x, int *y); // 获取当前鼠标位置

/*
callback function define as:
int __stdcall on_msg_key(void* param, unsigned msg, int key);
msg: see 'enum message_event'
key: keycode
return zero means process this message, otherwise means pass it and then process with 'getkey' function
*/
//int message_addkeyhandler(void* param, LPMSG_KEY_PROC func);        //设置键盘回调函数
/*
callback function define as:
int __stdcall on_msg_mouse(void* param, unsigned msg, int key, int x, int y);
msg: see 'enum message_event'
key: see 'enum message_mouse', if msg==MSG_EVENT_WHELL, key is a int number that indicates the distance the wheel is rotated, expressed in multiples or divisions of WHEEL_DELTA, which is 120.
x,y: current mouse (x, y)
return zero means process this message, otherwise means pass it and then process with 'GetMouseMsg' function
*/
//int message_addmousehandler(void* param, LPMSG_MOUSE_PROC func);    //设置鼠标回调函数
int EGEAPI SetCloseHandler(LPCALLBACK_PROC func);


class MUSIC
{
public:
	MUSIC();
	virtual ~MUSIC();
	operator HWND()const{ return (HWND)m_dwCallBack; }
public:
	int   IsOpen() { return (m_DID != MUSIC_ERROR) ? 1 : 0; }
	DWORD OpenFile(LPCSTR  filepath);
	DWORD OpenFile(LPCWSTR filepath);
	DWORD Play(DWORD dwFrom = MUSIC_ERROR, DWORD dwTo = MUSIC_ERROR);
	DWORD Pause();
	DWORD Seek(DWORD dwTo); //播放位置定位，单位为ms
	DWORD SetVolume(float value);
	DWORD Close();
	DWORD Stop();
	DWORD GetPosition();
	DWORD GetLength();
	// 以下函数GetPlayStatus的返回值为以下之一（意义看后缀）：
	// MUSIC_MODE_NOT_OPEN   //没有正确打开
	// MUSIC_MODE_NOT_READY  //设备没准备好 （较少使用）
	// MUSIC_MODE_PAUSE  //暂停中
	// MUSIC_MODE_PLAY   //正在播放
	// MUSIC_MODE_STOP   //成功打开后，或者播放完是这个状态
	// MUSIC_MODE_OPEN   //打开中 （较少使用）
	// MUSIC_MODE_SEEK   //定位中 （较少使用）
	DWORD GetPlayStatus();
private:
	DWORD       m_DID;
	PVOID       m_dwCallBack;
};

/* 压缩函数 */
/* 压缩时dest缓冲区要保证最小大小为sourceLen * 1.001 + 16 */
/* 调用compress/compress2前，*destLen必须有值，表示dest缓冲区的最大大小，返回时这个值表示实际大小 */
/* compress2 的level 从0-9，0不压缩，9最大压缩，compress函数使用默认值6 */
int             EGEAPI ege_compress(void *dest, unsigned long *destLen, const void *source, unsigned long sourceLen);
int             EGEAPI ege_compress2(void *dest, unsigned long *destLen, const void *source, unsigned long sourceLen, int level);
int             EGEAPI ege_uncompress(void *dest, unsigned long *destLen, const void *source, unsigned long sourceLen);
unsigned long   EGEAPI ege_uncompress_size(const void *source, unsigned long sourceLen); /* 返回0表示错误，其它表示大小 */

NAMESPACE_EGE_R

#ifndef _GRAPH_LIB_BUILD_

#if defined(_MSC_VER) && (defined(HIDE_CONSOLE) || !defined(SHOW_CONSOLE))
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif

#define Sleep(ms) delay_ms(ms)

#endif

#if !defined(_MSC_VER)
#define WinMain(...) WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
#elif defined(_CONSOLE)
#if (_MSC_VER > 1200)
#define WinMain(...) main(int argc, char* argv[])
#else
#define WinMain main
#endif
#endif

#endif
