#pragma once

#define clrequ(c1, c2)	(ColorToInt(c1)==ColorToInt(c2))

Color g_back_color{ BLACK };
Color g_fore_color{ WHITE };
Color g_fill_color{ BLUE };
int g_fs{ 32 };
int g_linewidth{ 1 };
float g_spacing{ 0.0f };
char g_fontname[80]{ 0 };
Image* g_pimg_buffer{ nullptr };

inline bool is_run()
{
	return !WindowShouldClose();
}
inline HWND GetRaylibWindow(void)
{
	//return FindWindowA("GLFW30", nullptr);
	return (HWND)GetWindowHandle();
}
Vector2 MakeVector2(double x, double y)
{
	return Vector2{ float(x), float(y) };
}
Rectangle MakeRectangle(float left, float top, float right, float bottom)
{
	return Rectangle{ left, top, right - left, bottom - top };
}
Rectangle MakeRectangle0(float left, float top, float width, float height)
{
	return Rectangle{ left, top, width, height };
}
void settarget(Image* pimg)
{
	g_pimg_buffer = pimg;
}
inline void rectangle(int left, int top, int right, int bottom)
{
	DrawRectangleLines(left, top, right - left, bottom - top, g_fore_color);
}
inline void bar(int left, int top, int right, int bottom)
{
	DrawRectangle(left, top, right - left, bottom - top, g_fill_color);
}
inline void ege_fillrect(int left, int top, int width, int height)
{
	DrawRectangle(left, top, width, height, g_fill_color);
}
inline void rectangle_stroke(int left, int top, int right, int bottom)
{
	DrawRectangle(left, top, right - left, bottom - top, g_fill_color);
	DrawRectangleLines(left, top, right - left, bottom - top, g_fore_color);
}

inline void setlinewidth(int w)
{
	g_linewidth = w;
}
void setcolor(Color color)
{
	g_fore_color = color;
}
inline Color getcolor()
{
	return g_fore_color;
}
void setbkcolor(Color bkcolor)
{
	g_back_color = bkcolor;
}
inline Color getbkcolor()
{
	return g_back_color;
}
void setfillcolor(Color fillcolor)
{
	g_fill_color = fillcolor;
}
inline Color getfillcolor()
{
	return g_fill_color;
}
void setfont(int fs, int width, const char* fontName)
{
	g_fs = fs;
	strncpy(g_fontname, fontName, 80);
}
int getwidth(Image* pimg)
{
	if (!pimg)
		return g.uix;
	return pimg->width;
}
int getheight(Image* pimg)
{
	if (!pimg)
		return g.uiy;
	return pimg->height;
}
inline void api_sleep(int ms)
{
	WaitTime(ms / 1000.0);
}

///////////////////////////////////////////////////////////
//                  Color 颜色系列                        //
///////////////////////////////////////////////////////////

#define LIGHTRED RAYRGB(0xFC, 0x54, 0x54)
//橙黄系列
#define IVORY RAYRGB(255,255,240)	//极淡黄 
#define CORNSILK RAYRGB(255,248,220)	//淡黄 
//#define GOLD RAYRGB(255,215,0)
//#define ORANGE RAYRGB(255,165,0)

//绿色系列
//#define DARKGREEN RAYRGB(0,100,0)

//蓝系列
#define POWDERBLUE RAYRGB(176,224,230)
#define AQUA RAYRGB(0,0xFC,0xFC)
#define ROYALBLUE RAYRGB(65,105,225)
#define STEELBLUE RAYRGB(70,130,180)
#define CADETBLUE RAYRGB(95,158,160)
#define LIGHTBLUE1 RAYRGB(191,239,255)
#define LIGHTCYAN1 RAYRGB(224,255,255)
#define TURQUOISE RAYRGB(64,224,208)	//青色 
#define CYAN RAYRGB(0,0xA8,0xA8)

//粉紫系列
//#define PINK RAYRGB(255,105,180)
#define LIGHTPINK RAYRGB(255,182,193)
//#define MAROON RAYRGB(176,48,96)
//#define VIOLET RAYRGB(238,130,238)
#define PLUM RAYRGB(221,160,221)
//#define PURPLE RAYRGB(160,32,240)

//黑白系列
#define GRAY_11 RAYRGB(28,28,28)
#define DIMGRAY RAYRGB(105,105,105)
#define SLATEGRAY RAYRGB(112,128,144)	//略带蓝色

#define LIKE_GRAYSCALE_THRESHOLD 10.0

bool LikeGrayscaleColor(Color color)
{
	double avg = (color.r + color.g + color.b) / 3.0;
	if (abs(color.r - avg) + abs(color.g - avg) + abs(color.b - avg) > LIKE_GRAYSCALE_THRESHOLD)
		return false;
	return true;
}

Color CJZAPI Color16ToRGB(UINT u16Clr)
{
	switch (u16Clr)
	{
	case 0: {
		return RAYRGB(0, 0, 0);		//黑 
		break;
	}
	case 1: {
		return RAYRGB(0, 0, 128);	//深蓝 
		break;
	}
	case 2: {
		return RAYRGB(0, 128, 0);	//草绿 
		break;
	}
	case 3: {
		return RAYRGB(0, 128, 128);	//青色 
		break;
	}
	case 4: {
		return RAYRGB(128, 0, 0);	//Dark Red
		break;
	}
	case 5: {
		return RAYRGB(128, 0, 128);	//Dark Magenta
		break;
	}
	case 6: {
		return RAYRGB(128, 128, 0);	//Brown
		break;
	}
	case 7: {
		return RAYRGB(192, 192, 192);	//浅灰 
		break;
	}
	case 8: {
		return RAYRGB(128, 128, 128);	//深灰 
		break;
	}
	case 9: {
		return RAYRGB(0, 0, 255);	//海蓝 
		break;
	}
	case 10: {
		return RAYRGB(0, 255, 0);	//淡绿 
		break;
	}
	case 11: {
		return RAYRGB(0, 255, 255);	//淡蓝 
		break;
	}
	case 12: {
		return RAYRGB(255, 0, 0);	//血红 
		break;
	}
	case 13: {
		return RAYRGB(255, 0, 255);	//Magenta 紫色 
		break;
	}
	case 14: {
		return RAYRGB(255, 255, 0);	//淡黄 
		break;
	}
	case 15: {
		return RAYRGB(255, 255, 255);	//白 
		break;
	}
	default: {
		return RAYRGB(0, 0, 0);
		break;
	}
	}
}
inline Color CJZAPI RateColor(Color orig, float rate)
{
	return RAYRGBA(Clamp(int(RAYGET_R(orig) * rate), 0, 255),
		Clamp(int(RAYGET_G(orig) * rate), 0, 255),
		Clamp(int(RAYGET_B(orig) * rate), 0, 255),
		orig.a);
}

Color CJZAPI StepColor(Color startColor, Color endColor, double rate) {
	// 获取起始颜色分量
	auto startR = RAYGET_R(startColor);
	auto startG = RAYGET_G(startColor);
	auto startB = RAYGET_B(startColor);
	auto startA = RAYGET_A(startColor);

	// 获取结束颜色分量
	auto endR = RAYGET_R(endColor);
	auto endG = RAYGET_G(endColor);
	auto endB = RAYGET_B(endColor);
	auto endA = RAYGET_A(endColor);

	// 计算过渡颜色分量
	auto newR = (startR + (endR - startR) * rate);
	auto newG = (startG + (endG - startG) * rate);
	auto newB = (startB + (endB - startB) * rate);
	auto newA = (startA + (endA - startA) * rate);

	// 构造过渡颜色
	Color resultColor = RAYRGBA(newR, newG, newB, newA);
	return resultColor;
}

#define WVC_AMP 12
#define WVC_OMEGA 13.0
#define WVC_PHASE0 0
clock_t lastWvBeg = 0;
inline Color WaveColor(Color originClr, float phi = 0.0f) {	//originClr将成为最大值
	//闪烁的颜色 赋予游戏文字灵性
	short val = WVC_AMP * sin(WVC_OMEGA * ((clock() - lastWvBeg) / 1000.0) + WVC_PHASE0 + phi) - WVC_AMP * 2;
	short r = RAYGET_R(originClr) + val, g = RAYGET_G(originClr) + val, b = RAYGET_B(originClr) + val;
	auto a = RAYGET_A(originClr);
	ClampA<short>(r, 2, 255);
	ClampA<short>(g, 2, 255);
	ClampA<short>(b, 2, 255);
	return RAYRGBA(r, g, b, a);
}

inline Color InvertedColor(Color color)
{
	return RAYRGBA(255 - RAYGET_R(color), 255 - RAYGET_G(color), 255 - RAYGET_B(color), RAYGET_A(color));
}

// 主函数：返回随时间变化的彩虹色
Color RainbowColor(float phase0 = 0.0f, float speed = 30.0f) {
	// 假设时间按秒计算，这里使用系统时间或其他适当的时间源
	double timeInSeconds = clock() / 1000.0;

	// 初始相位
	double initial_phase = phase0 * 360.0;

	// 色相按时间变化，加上初始相位
	double hue = fmod(timeInSeconds * speed + initial_phase, 360.0);  // 假设每秒变化30度

	// 饱和度和亮度保持不变
	double saturation = 1.0;
	double value = 1.0;

	// 将HSV颜色转换为RGB并返回
	return ColorFromHSV(hue, saturation, value);
}

// 定义一个颜色映射，存储每个字符串对应的颜色
static unordered_map<string, Color> colorMap;

// 函数：生成饱和度最高的随机颜色
Color GetHighSaturationColor() {
	// 使用 C++ 随机数引擎生成随机的 RGB 分量
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 255);

	// 随机选择一个颜色分量作为最大值，其余两个分量设置为较小值
	int r = dis(gen);
	int g = dis(gen);
	int b = dis(gen);

	if (r >= g && r >= b) {
		g = dis(gen) / 2;  // 降低 g 的值
		b = dis(gen) / 2;  // 降低 b 的值
	}
	else if (g >= r && g >= b) {
		r = dis(gen) / 2;  // 降低 r 的值
		b = dis(gen) / 2;  // 降低 b 的值
	}
	else {
		r = dis(gen) / 2;  // 降低 r 的值
		g = dis(gen) / 2;  // 降低 g 的值
	}

	// 返回最终的 RGB 颜色值
	return RAYRGB(r, g, b);
}

// 函数：根据字符串返回对应颜色
Color GetStringColor(string_view s) {
	// 查找字符串是否已经有对应的颜色
	auto it = colorMap.find(string(s));
	if (it != colorMap.end()) {
		// 如果已存在，直接返回存储的颜色
		return it->second;
	}
	else {
		// 否则生成一个新的颜色并存储
		Color newColor = GetHighSaturationColor();
		colorMap[string(s)] = newColor;
		return newColor;
	}
}


// 模板函数：计算正弦颜色并将其映射到指定范围
Color SinColor(Color colorA, Color colorB, clock_t periodTime = 2000L, float phase0 = 0.0f) {
	//// 获取当前时间
	//clock_t currentTime = clock();

	//// 计算周期内的时间
	//double normalizedTime = static_cast<double>(currentTime % periodTime) / periodTime;

	//// 计算正弦值并将其映射到[0, 1]
	//double sinValue = 0.5 * (1.0 + std::sin(2.0 * PI * normalizedTime));

	//// 计算颜色分量的差值
	//Color deltaColor;
	//deltaColor.r = colorB.r - colorA.r;
	//deltaColor.g = colorB.g - colorA.g;
	//deltaColor.b = colorB.b - colorA.b;
	//deltaColor.a = colorB.a - colorA.a;

	//// 计算正弦颜色
	//Color sinColor;
	//sinColor.r = colorA.r + static_cast<unsigned char>(deltaColor.r * sinValue);
	//sinColor.g = colorA.g + static_cast<unsigned char>(deltaColor.g * sinValue);
	//sinColor.b = colorA.b + static_cast<unsigned char>(deltaColor.b * sinValue);
	//sinColor.a = colorA.a + static_cast<unsigned char>(deltaColor.a * sinValue);

	//return sinColor;

	return StepColor(colorA, colorB, SinValue(0.0f, 1.0f, periodTime, phase0));
}

Color LighterColor(Color color)
{
	return StepColor(color, RAYRGBA(255, 255, 255, color.a), 0.5);
}
Color DoLighterColor(Color color, bool enabled)
{
	return enabled ? StepColor(color, RAYRGBA(255, 255, 255, color.a), 0.5) : color;
}
Color DarkerColor(Color color)
{
	return StepColor(color, RAYRGBA(0, 0, 0, color.a), 0.5);
}
Color DoDarkerColor(Color color, bool enabled)
{
	return enabled ? StepColor(color, RAYRGBA(0, 0, 0, color.a), 0.5) : color;
}
inline Color ColorAlpha2(Color color, float alpha)
{
	return ColorAlpha(color, Lerp(0.0f, color.a / 255.0f, alpha));
}

Color FadeInOutColor(Color bodyColor, clock_t deltaTime, clock_t totalTime, clock_t inTime, clock_t outTime, Color endColor = BLACK)
{
	if (deltaTime >= inTime && deltaTime <= totalTime - outTime)
		return bodyColor;
	if (deltaTime >= totalTime || deltaTime <= 0L)
		return endColor;
	if (deltaTime <= inTime)
		return StepColor(endColor, bodyColor, deltaTime / double(inTime));
	return StepColor(bodyColor, endColor, (deltaTime - (totalTime - outTime)) / double(outTime));
}
//Color GetColorInYear(float phase0 = 0.0f, float alpha = 1.0f) {
//	// 计算颜色
//	Color color;
//	constexpr double frequency = 1.0 / 365.0; // 控制颜色变化的速度，可以根据需要调整
//
//	// 根据相位调整起始点
//	int adjday = static_cast<int>(phase0 * 365);
//	color.r = static_cast<unsigned char>((1 + sin(frequency * (adjday + g.yday))) * 127.5);
//	color.g = static_cast<unsigned char>((1 + sin(frequency * (adjday + g.yday + 2))) * 127.5);
//	color.b = static_cast<unsigned char>((1 + sin(frequency * (adjday + g.yday + 4))) * 127.5);
//	color.a = 255 * alpha;
//	return color;
//}


///////////////////////////////////////////////////////////
//                  Display 显示系列                      //
///////////////////////////////////////////////////////////

inline void cls(Image* pimg = nullptr, Color color = BLANK)
{
	if (!pimg)
	{
		BeginDrawing();
		ClearBackground(color);
	}
	else
		ImageClearBackground(pimg, color);
}

int textwidth(const char* str, int fs = g_fs, float spacing = g_spacing)
{
	return MeasureTextEx(g.font, str, fs, spacing).x;
	//return TextLength(str) * (g_fs + g_spacing);
}
inline int textheight(...)
{
	return g_fs;
	//return MeasureTextEx(g.font, str, g_fs, g_spacing).y;
}

Rectangle ZoomingRect(const Rectangle& rt, double rate)
{
	float midx = rt.x + rt.width / 2.0f;
	float midy = rt.y + rt.height / 2.0f;
	Rectangle rt2;
	rt2.width = EaseOutCubic(rate) * rt.width;
	rt2.height = EaseOutCubic(rate) * rt.height;
	rt2.x = midx - rt2.width / 2.0f;
	rt2.y = midy - rt2.height / 2.0f;
	return rt2;
}

void CheckExtraFontChars(const string& s)
{
	//<!> UTF-8
	bool changed{ false };

	/*bool show{ false };*/

	for (size_t i = 0; i < s.length(); ++i)
	{
		// 检查当前字符是否是中文字符
		/*bool go{ false };*/

		if ((unsigned char)(s[i]) >= 0xE0 && (unsigned char)(s[i]) <= 0xEF)
		{
			/*go = true;
			show = true;*/

			int garbage;
			int codePoint = GetCodepoint(s.substr(i, 3).c_str(), &garbage);

			//SetColor(10);
			//printf("%s ", s.substr(i, 3).c_str());
			/*((s[i] & 0x0F) << 12) | ((s[i + 1] & 0x3F) << 6) | (s[i + 2] & 0x3F);*/

			bool notfound{ true };
			for (int j : g.extra_chars_codepoints)
				if (j == codePoint)
				{
					notfound = false;
					break;
				}

			//if (g.chn_codepoints.find(codePoint) == g.chn_codepoints.end()) 
			if (notfound)
			{
				//g.notify.WarningMessage("AddExtraChar, codepoint = " + str(codePoint) + " utf8str = " + str(CodepointToUTF8(codePoint, &garbage)));

				changed = true;

				//DebugLog("ADD CODEPOINT="+str(codePoint)+" CHAR="+s.substr(i, 3)+ '\n');
				g.AddExtraChar(codePoint, CodepointToUTF8(codePoint, &garbage));
			}

			// 由于中文字符占用3个字节，因此增加索引i的值
			i += 2;
		}
		/*if (show)
		{
			DebugLog(sprintf2("%d %c %02X %s", i, s[i], (unsigned char)(s[i]),
				go?"Yes":"No"));
		}*/

	}

	/*if (show)
		DebugLog("WHOLE:  " + s);*/

	if (changed)
	{
		//<!>
		ReloadFont();
	}
}

void outtextxy(int x, int y, const char* text)
{
	CheckExtraFontChars(text);
	DrawTextEx(g.font, text, MakeVector2(x, y), g_fs, g_spacing, g_fore_color);
}
int xyprintf(int x, int y, const char* szFormat, ...)
{
	char buffer[1024]{ 0 };

	va_list va;
	va_start(va, szFormat);
	int ret = vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	//DrawText(buffer, x, y, g_fs, g_fore_color);

	CheckExtraFontChars(buffer);
	DrawTextEx(g.font, buffer, MakeVector2(x, y), g_fs, g_spacing, g_fore_color);
	return ret;
}
void scrollouttextxy(int x, int y, int w, const char* text)
{
	constexpr int space_cnt = 6;

	string s0{ text };
	string s{ text };
	if (MeasureTextEx(g.font, s.c_str(), g_fs, g_spacing).x > w)
	{
		int i = (clock() / 200L);
		/*int max_cnt = w / g_fs * 2;*/
		int back_cnt = s0.length() - i % s0.length();
		s = s0.substr(i % s.length(), back_cnt);

		int len2 = MeasureTextEx(g.font, s.c_str(), g_fs, g_spacing).x
			+ g_fs / 2 * space_cnt;
		if (w > len2)
		{
			//int fore_cnt = (w - len2) / g_fs;
			s += string(space_cnt, ' ');
			//s += s0.substr(0, fore_cnt);
			s += s0;	//为了省事，去使用ScissorMode裁剪掉出去的部分
		}

	}
	CheckExtraFontChars(s);
	DrawTextEx(g.font, s.c_str(), MakeVector2(x, y), g_fs, g_spacing, g_fore_color);

}
int scrollprintf(int x, int y, int w, const char* szFormat, ...)
{	//横向滚动
	char buffer[1024]{ 0 };

	va_list va;
	va_start(va, szFormat);
	int ret = vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);

	scrollouttextxy(x, y, w, buffer);

	return ret;
}

int xyprintf(Image* pimg, int x, int y, const char* szFormat, ...)
{

	char buffer[1024]{ 0 };

	va_list va;
	va_start(va, szFormat);
	int ret = vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	//DrawText(buffer, x, y, g_fs, g_fore_color);

	CheckExtraFontChars(buffer);
	//DrawTextEx(g.font, buffer, MakeVector2(x, y), g_fs, g_spacing, g_fore_color);
	ImageDrawTextEx(pimg, g.font, buffer, MakeVector2(x, y), g_fs, g_spacing, g_fore_color);
	return ret;
}

inline short KnowItsLen(u_char c) {
	short ret = 0;
	if (c > 0x7f)	ret = 2;
	else			ret = 1;
	return ret;
}

void CJZAPI midprinty(const string& strText, int y, int left = 0, int right = g.uix)
{
	xyprintf((left + right) / 2.0 - textwidth(strText.c_str()) / 2.0, y, strText.c_str());
}

void CJZAPI alignprint(const string& strText, int y, int left = 0, int right = g.uix, const string& align = "Center")
{
	if (align == "Left")
	{
		xyprintf(left + 10, y, strText.c_str());
	}
	else if (align == "Right")
	{
		int w = MeasureTextEx(g.font, strText.c_str(), g_fs, g_spacing).x;
        xyprintf(right - w - 10, y, strText.c_str());
	}
	else if (align == "Center")
	{
		midprinty(strText, y, left, right);
	}
}

void CJZAPI scrollmidprinty(const string& strText, int y, int w, int left = 0, int right = g.uix)
{
	scrollouttextxy((left + right) / 2.0 - min(w, textwidth(strText.c_str())) / 2.0, y, w, strText.c_str());
}
#define _OFFSET_X 0
void CJZAPI midprinty_shadow(const string& strText, int y, int midx = g.uix / 2, int shadow_distance = 1)
{
	Color color = getcolor();
	setcolor(RAYRGBA(1, 1, 1, color.a));

	int fy = textheight('1');	//font height
	int sx = textwidth(strText.c_str());
	int x = midx - sx / 2 + _OFFSET_X;
	xyprintf(x + shadow_distance, y + shadow_distance, "%s", strText.c_str());

	setcolor(color);
	midprinty(strText, y, midx, midx);
}
void CJZAPI scrollmidprinty_shadow(const string& strText, int y, int w, int midx = g.uix / 2, int shadow_distance = 1)
{
	Color color = getcolor();
	setcolor(RAYRGBA(1, 1, 1, color.a));

	int fy = textheight('1');	//font height
	int sx = textwidth(strText.c_str());
	int x = midx - sx / 2 + _OFFSET_X;
	scrollouttextxy(x + shadow_distance, y + shadow_distance, w, strText.c_str());

	setcolor(color);
	scrollmidprinty(strText, y, w, midx, midx);
}

void CJZAPI midprinty_stroke(const string& strText, int y, int midx = g.uix / 2, int stroke_distance = 1)
{
	Color color = getcolor();
	setcolor(RAYRGBA(1, 1, 1, color.a));

	int fy = textheight('1');	//font height
	int sx = textwidth(strText.c_str());
	int x = midx - sx / 2 + _OFFSET_X;
	xyprintf(x - stroke_distance, y - stroke_distance, "%s", strText.c_str());
	xyprintf(x - stroke_distance, y + stroke_distance, "%s", strText.c_str());
	xyprintf(x + stroke_distance, y - stroke_distance, "%s", strText.c_str());
	xyprintf(x + stroke_distance, y + stroke_distance, "%s", strText.c_str());

	setcolor(color);
	midprinty(strText, y, midx, midx);
}
void CJZAPI scrollmidprinty_stroke(const string& strText, int y, int w, int midx = g.uix / 2, int stroke_distance = 1)
{
	Color color = getcolor();
	setcolor(RAYRGBA(1, 1, 1, color.a));

	int fy = textheight('1');	//font height
	int sx = textwidth(strText.c_str());
	int x = midx - sx / 2 + _OFFSET_X;
	scrollouttextxy(x - stroke_distance, y - stroke_distance, w, "%s");
	scrollouttextxy(x - stroke_distance, y + stroke_distance, w, "%s");
	scrollouttextxy(x + stroke_distance, y - stroke_distance, w, "%s");
	scrollouttextxy(x + stroke_distance, y + stroke_distance, w, "%s");

	setcolor(color);
	scrollmidprinty(strText, y, w, midx, midx);
}
int CJZAPI xyprintf_shadow(int x, int y, const char* szFormat, ...)
{
	constexpr int shadow_distance{ 1 };
	char buffer[4096]{ "\0" };
	va_list va;
	va_start(va, szFormat);
	int ret = _vsnprintf(buffer, 4096, szFormat, va);
	va_end(va);

	Color ocolor{ getcolor() };
	setcolor(RAYRGBA(1, 1, 1, ocolor.a));
	xyprintf(x + shadow_distance, y + shadow_distance, buffer);

	//DebugLog(buffer);
	setcolor(ocolor);
	xyprintf(x, y, buffer);
	return strlen(buffer);
}
int CJZAPI scrollprintf_shadow(int x, int y, int w, const char* szFormat, ...)
{
	constexpr int shadow_distance{ 1 };
	char buffer[4096]{ "\0" };
	va_list va;
	va_start(va, szFormat);
	int ret = _vsnprintf(buffer, 4096, szFormat, va);
	va_end(va);

	Color ocolor{ getcolor() };
	setcolor(RAYRGBA(1, 1, 1, ocolor.a));
	scrollouttextxy(x + shadow_distance, y + shadow_distance, w, buffer);

	//DebugLog(buffer);
	setcolor(ocolor);
	scrollouttextxy(x, y, w, buffer);
	return strlen(buffer);
}
int CJZAPI xyprintf_shadow(Image* pimg, int x, int y, const char* szFormat, ...)
{
	constexpr int shadow_distance{ 1 };
	char buffer[4096]{ "\0" };
	va_list va;
	va_start(va, szFormat);
	int ret = _vsnprintf(buffer, 4096, szFormat, va);
	va_end(va);

	Color ocolor{ getcolor() };
	setcolor(RAYRGBA(1, 1, 1, ocolor.a));
	xyprintf(pimg, x + shadow_distance, y + shadow_distance, buffer);

	//DebugLog(buffer);
	setcolor(ocolor);
	xyprintf(pimg, x, y, buffer);
	return strlen(buffer);
}
int CJZAPI xyprintf_stroke(int x, int y, const char* szFormat, ...)
{
	constexpr int stroke_distance{ 1 };
	char buffer[4096]{ "\0" };
	va_list va;
	va_start(va, szFormat);
	int ret = _vsnprintf(buffer, 4096, szFormat, va);
	va_end(va);

	Color ocolor{ getcolor() };
	setcolor(RAYRGBA(1, 1, 1, ocolor.a));
	xyprintf(x - stroke_distance, y - stroke_distance, buffer);
	xyprintf(x - stroke_distance, y + stroke_distance, buffer);
	xyprintf(x + stroke_distance, y - stroke_distance, buffer);
	xyprintf(x + stroke_distance, y + stroke_distance, buffer);

	//DebugLog(buffer);
	setcolor(ocolor);
	xyprintf(x, y, buffer);
	return strlen(buffer);
}
int CJZAPI xyprintf_stroke(Image* pimg, int x, int y, const char* szFormat, ...)
{
	constexpr int stroke_distance{ 1 };
	char buffer[4096]{ "\0" };
	va_list va;
	va_start(va, szFormat);
	int ret = _vsnprintf(buffer, 4096, szFormat, va);
	va_end(va);

	Color ocolor{ getcolor() };
	setcolor(RAYRGBA(1, 1, 1, ocolor.a));
	xyprintf(pimg, x - stroke_distance, y - stroke_distance, buffer);
	xyprintf(pimg, x - stroke_distance, y + stroke_distance, buffer);
	xyprintf(pimg, x + stroke_distance, y - stroke_distance, buffer);
	xyprintf(pimg, x + stroke_distance, y + stroke_distance, buffer);

	//DebugLog(buffer);
	setcolor(ocolor);
	xyprintf(pimg, x, y, buffer);
	return strlen(buffer);
}
int centerprintf(const char* szFormat, ...)
{
	va_list va;
	va_start(va, szFormat);
	char buffer[1024] = "\0";
	int res = _vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	int x = g.uix / 2 - textwidth(buffer) / 2;
	int y = g.uiy / 2 - textheight(buffer) / 2;
	xyprintf(x, y, buffer);
	return res;
}
int centerprintf(Image* pimg, const char* szFormat, ...)
{
	va_list va;
	va_start(va, szFormat);
	char buffer[1024] = "\0";
	int res = _vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	int x = g.uix / 2 - textwidth(buffer) / 2;
	int y = g.uiy / 2 - textheight(buffer) / 2;
	xyprintf(pimg, x, y, buffer);
	return res;
}
int centerprintf_shadow(const char* szFormat, ...)
{
	va_list va;
	va_start(va, szFormat);
	char buffer[1024] = "\0";
	int res = _vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	int x = g.uix / 2 - textwidth(buffer) / 2;
	int y = g.uiy / 2 - textheight(buffer) / 2;
	xyprintf_shadow(x, y, buffer);
	return res;
}
int centerprintf_shadow(Image* pimg, const char* szFormat, ...)
{
	va_list va;
	va_start(va, szFormat);
	char buffer[1024] = "\0";
	int res = _vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	int x = g.uix / 2 - textwidth(buffer) / 2;
	int y = g.uiy / 2 - textheight(buffer) / 2;
	xyprintf_shadow(pimg, x, y, buffer);
	return res;
}
int midprintf(int y, const char* szFormat, ...)
{
	va_list va;
	va_start(va, szFormat);
	char buffer[1024] = "\0";
	int res = _vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	int x = g.uix / 2 - textwidth(buffer) / 2;
	DrawTextEx(g.font, buffer, MakeVector2(x, y), g_fs, g_spacing, g_fore_color);
	//xyprintf(x, y, buffer);
	return res;
}
int midprintf(Image* pimg, int y, const char* szFormat, ...)
{
	if (!pimg)
		return 0;
	va_list va;
	va_start(va, szFormat);
	char buffer[1024] = "\0";
	int res = _vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	int x = g.uix / 2 - textwidth(buffer) / 2;
	ImageDrawTextEx(pimg, g.font, buffer, MakeVector2(x, y), g_fs, g_spacing, g_fore_color);
	//xyprintf(x, y, buffer);
	return res;
}

inline HFONT CJZAPI CreateFontA(int height, int width, LPCSTR lpFamilyName)
{
	return CreateFont(height, width, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, lpFamilyName);
}
//[[depreciated]] void BeginDraw()
//{
//	g.hdc = BeginPaint(g.hwnd, &g.ps);
//	g.hFontText = CreateFontA(g_fs, 0, "微软雅黑");
//	SelectObject(g.hdcBuffer, g.hFontText);
//	SetBkMode(g.hdcBuffer, TRANSPARENT);
//}
//[[depreciated]] void EndDraw()
//{
//	DeleteObject(g.hFontText);
//	EndPaint(g.hwnd, &g.ps);
//}
//[[depreciated]] void LoadGDI()
//{
//	g.hdcBuffer = CreateCompatibleDC(NULL);
//}
//[[depreciated]] void UnloadGDI()
//{
//	if (g.hdcBuffer)
//		DeleteDC(g.hdcBuffer), g.hdcBuffer = nullptr;
//	if (g.hBitmap)
//		DeleteObject(g.hBitmap), g.hBitmap = nullptr;
//}
//[[depreciated]] void BeginGDIDraw()
//{
//	BeginDraw();
//
//	// 获取客户区域的大小
//	RECT rcClient;
//	GetClientRect(g.hwnd, &rcClient);
//	int clientWidth = rcClient.right - rcClient.left;
//	int clientHeight = rcClient.bottom - rcClient.top;
//
//	// 创建双缓冲
//	if (g.hBitmap)
//		DeleteObject(g.hBitmap);
//	g.hBitmap = CreateCompatibleBitmap(g.hdc, clientWidth, clientHeight);
//	SelectObject(g.hdcBuffer, g.hBitmap);
//}
//[[depreciated]] void EndGDIDraw()
//{
//	// 获取客户区域的大小
//	RECT rcClient;
//	GetClientRect(g.hwnd, &rcClient);
//	int clientWidth = rcClient.right - rcClient.left;
//	int clientHeight = rcClient.bottom - rcClient.top;
//
//	// 将缓冲区的内容一次性绘制到屏幕上
//	BitBlt(g.hdc, 0, 0, clientWidth, clientHeight, g.hdcBuffer, 0, 0, SRCCOPY);
//	EndDraw();
//}
//
//[[depreciated]] void rawouttextxy(int x, int y, int fs, const char* fontname, const char* szText)
//{
//	BeginPaint(g.hwnd, &g.ps);
//	HDC hdc = g.hdc;
//	HFONT hFont = CreateFontA(fs, 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, fontname);
//	SelectObject(hdc, hFont);
//	SetBkMode(hdc, TRANSPARENT);
//	SetTextColor(hdc, RGB(g_fore_color.r, g_fore_color.g, g_fore_color.b));
//	TextOutA(hdc, x, y, szText, strlen(szText));
//	DeleteObject(hFont);
//	EndPaint(g.hwnd, &g.ps);
//}
//[[depreciated]] int rawxyprintf(int x, int y, int fs, const char* fontname, const char* szFormat, ...)
//{
//	va_list va;
//	va_start(va, szFormat);
//	char buffer[1024] = "\0";
//	int res = _vsnprintf(buffer, 1024, szFormat, va);
//	va_end(va);
//
//	rawouttextxy(x, y, fs, fontname, buffer);
//
//	return res;
//}

inline bool MyIsWindowFocused()
{
	return (g.hwnd == GetForegroundWindow());
}
void CopyImageData(Image* imgDst, Image* imgSrc)
{
	for (int y = 0; y < imgSrc->height; ++y)
		for (int x = 0; x < imgSrc->width; ++x)
		{
			((Color*)(imgDst->data))[y * imgSrc->width + x] = ((Color*)(imgSrc->data))[y * imgSrc->width + x];
		}
}
void MyImageFlipHorizontal(Image* pimg)
{
	Image img = ImageCopy(*pimg);
	ImageFlipHorizontal(&img);
	CopyImageData(pimg, &img);
	UnloadImage(img);
}
void MyImageFlipVertical(Image* pimg)
{
	Image img = ImageCopy(*pimg);
	ImageFlipVertical(&img);
	CopyImageData(pimg, &img);
	UnloadImage(img);
}
void FlipImage(Image* pimg, DIR2 dir)
{
	if (!pimg || !IsImageReady(*pimg))
		return;

	if (dir == HORIZ)
		MyImageFlipHorizontal(pimg);
	else
		MyImageFlipVertical(pimg);
}
void MyImageColorTint(Image* pimg, Color tint)
{
	if (!pimg || !IsImageReady(*pimg))
		return;
	Image img = ImageCopy(*pimg);
	ImageColorTint(&img, tint);
	CopyImageData(pimg, &img);
	UnloadImage(img);
}
void MyImageColorBrightness(Image* pimg, int brightness)
{
	if (!pimg || !IsImageReady(*pimg))
		return;
	Image img = ImageCopy(*pimg);
	ImageColorBrightness(&img, brightness);
	CopyImageData(pimg, &img);
	UnloadImage(img);
}
//void DarkenImage(Image* pimg, Lightness lightness)
//{
//	MyImageColorBrightness(pimg, lightness - 255);
//}
void SemialphaImage(Image* pimg)
{
	MyImageColorTint(pimg, RAYRGBA(255, 255, 255, 127));
}
void SetImageAlpha(Image* pimg, int alpha)
{
	MyImageColorTint(pimg, ColorAlpha(RAYWHITE, alpha / 255.0f));
}

#define ROT_COEFF 60.0
#define ROT_PHASE ( - PI / 2.0f)

inline float RotationFormula(float rotation)
{
	return (PI / 2.0f - rotation + ROT_PHASE) * ROT_COEFF;
}
//#define NO_QUICKDRAW_TEXTURE_CHECK
void QuickDraw(const Image* pimgSrc, double x, double y, float alpha_rat = 1.0, Color tint = WHITE)
{
	if (!pimgSrc)	return;
	Texture texture = LoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!IsTextureReady(texture))
		return;
#endif

	DrawTexture(texture, x, y, ColorAlpha(tint, alpha_rat));

	
		g.frame_textures.push_back(texture);
}
void QuickDraw(const Image* pimgSrc, double x, double y, double src_x, double src_y, double src_w, double src_h, float alpha_rat = 1.0, Color tint = WHITE)
{
	if (!pimgSrc)	return;
	Texture texture = LoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!IsTextureReady(texture))
		return;
#endif
	DrawTexturePro(texture, MakeRectangle0(src_x, src_y, src_w, src_h), MakeRectangle0(x, y, src_w, src_h),
		Vector2{ 0.5f * pimgSrc->width, 0.5f * pimgSrc->height }, 0.0f, ColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}
void QuickDraw(const Image* pimgSrc, double dst_x, double dst_y, double dst_w, double dst_h, double src_x, double src_y, double src_w, double src_h, float alpha_rat = 1.0, Color tint = WHITE)
{
	if (!pimgSrc)	return;

	//QuickDraw(pimgSrc, dst_x, dst_y, alpha_rat);

	Texture texture = LoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!IsTextureReady(texture))
		return;
#endif
	DrawTexturePro(texture, MakeRectangle0(src_x, src_y, src_w, src_h), MakeRectangle0(dst_x, dst_y, dst_w, dst_h),
		//Vector2{ 0.5f * pimgSrc->width, 0.5f * pimgSrc->height }, 
		Vector2{ 0.0f, 0.0f },
		0.0f, ColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}
void QuickDrawRotate(const Image* pimgSrc, double x, double y, float rotation, float alpha_rat = 1.0, Color tint = WHITE)
{
	if (!pimgSrc)	return;
	Texture texture = LoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!IsTextureReady(texture))
		return;
#endif
	DrawTextureEx(texture, MakeVector2(x, y), RotationFormula(rotation), 1.0f, ColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}
void QuickDrawRotateEx(const Image* pimgSrc, double x, double y, float rotation, float center_x = 0.5f, float center_y = 0.5f, float alpha_rat = 1.0, Color tint = WHITE)
{
	if (!pimgSrc)	return;
	Texture texture = LoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!IsTextureReady(texture))
		return;
#endif
	DrawTexturePro(texture, MakeRectangle0(0, 0, pimgSrc->width, pimgSrc->height),
		MakeRectangle0(x, y, pimgSrc->width, pimgSrc->height),
		Vector2{ center_x * pimgSrc->width, center_y * pimgSrc->height },
		RotationFormula(rotation), ColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}
void QuickDrawZoom(const Image* pimgSrc, double x, double y, float scale, float alpha_rat = 1.0, Color tint = WHITE)
{
	if (!pimgSrc)	return;
	Texture texture = LoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!IsTextureReady(texture))
		return;
#endif
	DrawTextureEx(texture, MakeVector2(x, y), 0.0f, scale, ColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}
void QuickDrawRotateZoom(const Image* pimgSrc, double x, double y, float rotation, float scale, float alpha_rat = 1.0, Color tint = WHITE)
{
	if (!pimgSrc)	return;
	Texture texture = LoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!IsTextureReady(texture))
		return;
#endif
	DrawTextureEx(texture, MakeVector2(x, y),
		RotationFormula(rotation), scale, ColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}
void QuickDrawRotateZoomEx(const Image* pimgSrc, double x, double y, float center_x, float center_y, float rotation, float scale, float alpha_rat = 1.0, Color tint = WHITE)
{
	if (!pimgSrc)	return;
	Texture texture = LoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!IsTextureReady(texture))
		return;
#endif
	DrawTexturePro(texture, MakeRectangle0(0, 0, pimgSrc->width, pimgSrc->height),
		MakeRectangle0(x, y, pimgSrc->width * scale, pimgSrc->height * scale), Vector2{ center_x * pimgSrc->width, center_y * pimgSrc->height },
		RotationFormula(rotation), ColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}

///////////////////////////////////////////////////////////
//                  Control 控制系列                      //
///////////////////////////////////////////////////////////

inline bool IsFocused()
{
	return GetForegroundWindow() == g.hwnd;
}

void OnMouseWheel(int delta);

LRESULT CALLBACK RawInputProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (uMsg == WM_INPUT) {
		RAWINPUT raw;
		UINT size = sizeof(raw);
		GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, &raw, &size, sizeof(RAWINPUTHEADER));
		if (raw.header.dwType == RIM_TYPEMOUSE) {
			if (raw.data.mouse.usButtonFlags == RI_MOUSE_WHEEL) {
				short wheelDelta = static_cast<short>(raw.data.mouse.usButtonData);
				if (wheelDelta > 0) {
					OnMouseWheel(-1);
				}
				else {
					OnMouseWheel(1);
				}
			}
		}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

DWORD MouseWheelDetectionProc(LPVOID none);

Image TakeRealScreenshot(int left, int top, int width, int height)
{
	// 创建内存位图
	HDC hdc = GetDC(0);
	HDC hMemDC = CreateCompatibleDC(hdc);
	HBITMAP hBitmap = CreateCompatibleBitmap(hdc, g.uix, g.uiy);
	SelectObject(hMemDC, hBitmap);

	// 将窗口内容复制到内存位图
	BitBlt(hMemDC, left, top, width, height, hdc, 0, 0, SRCCOPY);

	// 获取像素数据
	BYTE* pixels = new BYTE[int(g.uix * g.uiy * 4)]; // RGBA格式，每个像素占4字节
	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = g.uix;
	bmi.bmiHeader.biHeight = -g.uiy; // 负表示顶部到底部扫描
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;
	GetDIBits(hMemDC, hBitmap, 0, g.uiy, pixels, &bmi, DIB_RGB_COLORS);

	Image img = GenImageColor(g.uix, g.uiy, BLANK);

	for (int y = 0; y < g.uiy; ++y)
		for (int x = 0; x < g.uix; ++x)
		{
			ImageDrawPixel(&img, x, y,
				RAYRGB(
					pixels[4 * int(y * g.uix + x) + 2],
					pixels[4 * int(y * g.uix + x) + 1],
					pixels[4 * int(y * g.uix + x)]));
		}

	delete[] pixels;
	DeleteObject(hBitmap);
	DeleteDC(hMemDC);

	return img;
}