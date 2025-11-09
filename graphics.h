/*********************************************************
* EGE (Easy Graphics Engine)
* FileName      graphics.h
* HomePage1     http://misakamm.github.com/xege
* HomePage2     http://misakamm.bitbucket.org/index.htm
* teiba1        http://tieba.baidu.com/f?kw=ege
* teiba2        http://tieba.baidu.com/f?kw=ege%C4%EF
* Blog:         http://misakamm.com
* E-Mail:       mailto:misakamm[at gmail com]
*
* FileName: graphics.h
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
* ★调用delay_ms, delay_fps, getch, GetMouseMsg 时，窗口内容可能会更新，这些函数相当于内置了delay_ms(0)，
*   如果你只需要更新窗口，而不想等待，可以用delay_ms(0),Sleep(0)或者delay(0)
* ★如果你使用了锁定模式绘图，那可以使用WindowFlush代替delay(0)，但不能代替非0的delay
* ★合理地使用delay函数，可以减少你的程序占用的CPU，否则一个delay都没有调用的话，程序将占满一个CPU的时间
* ★setfillstyle函数的自定义填充模式未实现，但一般应用足够
****************************************************************************/

#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#ifndef __cplusplus
#error You must use C++ compiler, or you need filename with '.cpp' suffix
#endif

#include "ege.h"
using namespace ege;

#endif
