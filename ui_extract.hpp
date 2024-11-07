
#define KEYSTROKE_BG_COLOR		RAYRGBA(1, 1, 1, 235)
#define KEYSTROKE_OUTLINE_COLOR	RainbowColor(g.rainbow_speed)

Color GetKeyCountColor(int cnt)
{
	if (cnt < 5)
		return DARKGRAY;
	if (cnt < 10)
		return RAYRGB(176, 196, 222);
	if (cnt < 15)
		return RAYRGB(0, 206, 209);
	if (cnt < 20)
		return RAYRGB(30, 144, 255);
	if (cnt < 30)
		return RAYRGB(127, 255, 212);
	if (cnt < 60)
		return RAYRGB(0, 255, 127);
	if (cnt < 80)
		return RAYRGB(0, 238, 0);	//GREEN
	if (cnt < 90)
		return RAYRGB(192, 255, 62);
	if (cnt < 100)
		return RAYRGB(255, 236, 139);
	if (cnt < 120)
		return RAYRGB(255, 215, 0);	//GOLD
	if (cnt < 150)
		return RAYRGB(255, 185, 15);
	if (cnt < 180)
		return RAYRGB(255, 130, 71);
	if (cnt < 200)
		return RAYRGB(255, 0, 0);	//RED
	if (cnt < 250)
		return RAYRGB(205, 16, 118);
	if (cnt < 300)
		return RAYRGB(255, 0, 255);
	return Choice({ RAYWHITE, DARKGRAY });
}

void DrawKeyBox(BYTE key, const char* name, int fs, int left, int top, int right, int bottom, int num = 0, int heat = 0)
{
	Color color;
	if (KEY_DOWN(key))
		color = StepColor(RainbowColor(g.rainbow_speed), WHITE, 0.5f);
	else
		color = KEYSTROKE_BG_COLOR;

	bool mouseIn = (g.mcx >= left && g.mcx <= right && g.mcy >= top && g.mcy <= bottom);

	if (mouseIn)
		color = ColorAlpha2(color, 0.1f);

	setfillcolor(color);
	setcolor(mouseIn ? ColorAlpha2(KEYSTROKE_OUTLINE_COLOR, 0.1f) : KEYSTROKE_OUTLINE_COLOR);

	rectangle_stroke(left + (KEY_DOWN(key) ? 2 : 0), top + (KEY_DOWN(key) ? 2 : 0), right + (KEY_DOWN(key) ? 2 : 0), bottom + (KEY_DOWN(key) ? 2 : 0));

	setfont(fs, 0, g.fontname.c_str());
	if (KEY_DOWN(key))
		color = StepColor(InvertedColor(RainbowColor(g.rainbow_speed)), BLACK, 0.8f);
	else
		color = RainbowColor(g.rainbow_speed);

	if (mouseIn)
		color = ColorAlpha2(color, 0.1f);
	setcolor(color);

	string text{ name };
	//int x = left + (KEY_DOWN(key) ? 2 : 0) + (right - left) / 2.0f - text.length() * fs / 4.0f;
	int y = top + (KEY_DOWN(key) ? 2 : 0) + (bottom - top) / 2.0f - fs / 2.0f;

	//xyprintf_shadow(x, y, text.c_str());
	midprinty_shadow(text, y, (left + right) / 2);

	if (heat > 0)
	{
		static int num_fs = 13;
		setfont(num_fs, 0, g.fontname.c_str());
		Color clr;
		if (KEY_DOWN(key))
			clr = BLACK;
		else
			clr = GetKeyCountColor(heat);

		if (mouseIn)
			clr = ColorAlpha2(clr, 0.1f);

		setcolor(WaveColor(clr));
		midprinty_shadow(str(num), bottom - num_fs - 1, (left + right) / 2);
	}
}
void DrawMouseKeys(int left, int top)
{
	static const int box_w = 85;
	static const int box_h = 45;
	static const int box_gap = 15;
	static const int fs = 15;
	static const int small_fs = 10;

	if (!MODBOOL("Keystrokes", "Mouse Buttons"))
		return;

	bool mouseIn1 = (g.mcx >= left && g.mcx <= left + box_w && g.mcy >= top && g.mcy <= top + box_h);
	bool mouseIn2 = (g.mcx >= left + box_w + box_gap && g.mcx <= left + box_w * 2 + box_gap && g.mcy >= top && g.mcy <= top + box_h);

	Color color;
	if (KEY_DOWN(VK_LBUTTON))
		color = StepColor(RainbowColor(g.rainbow_speed), WHITE, 0.5f);
	else
		color = KEYSTROKE_BG_COLOR;

	if (mouseIn1)
		color = ColorAlpha2(color, 0.1f);

	setfillcolor(color);
	setcolor(mouseIn1 ? ColorAlpha2(KEYSTROKE_OUTLINE_COLOR, 0.1f) : KEYSTROKE_OUTLINE_COLOR);

	rectangle_stroke(left + (KEY_DOWN(VK_LBUTTON) ? 2 : 0), top + (KEY_DOWN(VK_LBUTTON) ? 2 : 0), left + (KEY_DOWN(VK_LBUTTON) ? 2 : 0) + box_w, top + box_h + (KEY_DOWN(VK_LBUTTON) ? 2 : 0));

	if (KEY_DOWN(VK_RBUTTON))
		color = StepColor(RainbowColor(g.rainbow_speed), WHITE, 0.5f);
	else
		color = KEYSTROKE_BG_COLOR;

	if (mouseIn2)
		color = ColorAlpha2(color, 0.1f);

	setfillcolor(color);
	setcolor(mouseIn2 ? ColorAlpha2(KEYSTROKE_OUTLINE_COLOR, 0.1f) : KEYSTROKE_OUTLINE_COLOR);
	rectangle_stroke(left + (KEY_DOWN(VK_RBUTTON) ? 2 : 0) + box_w + box_gap, top + (KEY_DOWN(VK_RBUTTON) ? 2 : 0), left + (KEY_DOWN(VK_RBUTTON) ? 2 : 0) + box_w * 2 + box_gap, top + box_h + (KEY_DOWN(VK_RBUTTON) ? 2 : 0));

	setfont(small_fs, 0, g.fontname.c_str());

	int x, y;
	string text;

	if (MODBOOL("Keystrokes", "Show CPS"))
	{
		color = RainbowColor(g.rainbow_speed, 0.2f);
		if (mouseIn1)
			color = ColorAlpha2(color, 0.1f);
		setcolor(color);

		text = sprintf2("%d CPS", GetCPS(0));
		x = left + (KEY_DOWN(VK_LBUTTON) ? 2 : 0) + box_w / 2.0f - text.length() * small_fs / 4.0f - 3;
		y = top + (KEY_DOWN(VK_LBUTTON) ? 2 : 0) + box_h * 0.75f - small_fs / 2.0f;
		xyprintf_shadow(x, y, text.c_str());

		color = RainbowColor(g.rainbow_speed, 0.2f);
		if (mouseIn2)
			color = ColorAlpha2(color, 0.1f);
		setcolor(color);

		text = sprintf2("%d CPS", GetCPS(1));
		x = box_gap + (KEY_DOWN(VK_RBUTTON) ? 2 : 0) + box_w + left + box_w / 2.0f - text.length() * small_fs / 4.0f - 3;
		y = top + (KEY_DOWN(VK_RBUTTON) ? 2 : 0) + box_h * 0.75f - small_fs / 2.0f;
		xyprintf_shadow(x, y, text.c_str());
	}

	{
		setfont(fs, 0, g.fontname.c_str());
		color = RainbowColor(g.rainbow_speed, 0.5f);


		if (mouseIn1)
			color = ColorAlpha2(color, 0.1f);
		setcolor(color);

		text = "LMB";
		x = left + (KEY_DOWN(VK_LBUTTON) ? 2 : 0) + box_w / 2.0f - text.length() * fs / 4.0f - 4;
		y = top + (KEY_DOWN(VK_LBUTTON) ? 2 : 0) + box_h * 0.22f;
		xyprintf_shadow(x, y, text.c_str());

		color = RainbowColor(g.rainbow_speed, 0.5f);
		if (mouseIn2)
			color = ColorAlpha2(color, 0.1f);
		setcolor(color);

		text = "RMB";
		x = box_gap + (KEY_DOWN(VK_RBUTTON) ? 2 : 0) + box_w + left + box_w / 2.0f - text.length() * fs / 4.0f - 4;
		y = top + (KEY_DOWN(VK_RBUTTON) ? 2 : 0) + box_h * 0.22f;
		xyprintf_shadow(x, y, text.c_str());
	}
}
void DrawKeystrokes()
{
	int _left = g.uix * MODFLOAT("Keystrokes", "X Rate");
	int _top = g.uiy * MODFLOAT("Keystrokes", "Y Rate");
	static const int _pen_size = 2;

	int box_w, box_h;
	box_w = box_h = MODINT("Keystrokes", "Box Size");
	static const int box_gap = 10;
	static const int space_h = 35;
	int fs = MODINT("Keystrokes", "Font Size");

	if (g.mcx >= _left && g.mcx <= _left + box_w * 3 + box_gap * 2
		&& g.mcy >= _top && g.mcy <= _top + box_h * 4 + box_gap * 3 + space_h * 2
		&& MODBOOL("Keystrokes", "Give Way to Mouse"))
	{
		_left = g.uix * (1.0f - MODFLOAT("Keystrokes", "X Rate"));
		ClampA(_left, 0, g.uix - g.wnd_x - box_w * 3 - box_gap * 2 - 30);
	}

	DrawKeyBox('A', "A", fs, _left, _top + box_h + box_gap, _left + box_w, _top + box_h + box_gap + box_h);
	DrawKeyBox('W', "W", fs, _left + box_w + box_gap, _top, _left + box_w * 2 + box_gap, _top + box_h);
	DrawKeyBox('S', "S", fs, _left + box_w + box_gap, _top + box_h + box_gap, _left + box_w * 2 + box_gap, _top + box_h + box_gap + box_h);
	DrawKeyBox('D', "D", fs, _left + box_w * 2 + box_gap * 2, _top + box_h + box_gap, _left + box_w * 3 + box_gap * 2, _top + box_h + box_gap + box_h);


	if (MODBOOL("Keystrokes", "Space"))
		DrawKeyBox(' ', "--", fs, _left, _top + box_h * 2 + box_gap * 2, _left + box_w * 3 + box_gap * 2, _top + box_h * 2 + box_gap * 2 + space_h);
	if (MODBOOL("Keystrokes", "Space"))
		DrawKeyBox(VK_SHIFT, "Shift", fs * 0.75, _left, _top + box_h * 2 + box_gap * 3 + space_h, _left + box_w * 3 + box_gap * 2, _top + box_h * 2 + box_gap * 3 + space_h * 2);

	DrawMouseKeys(_left, _top + box_h * 3 + box_gap * 3 + space_h * 2);
}

int DecideKeyFontSize(int base, const string& name)
{
	int len = name.size();
	switch (len)
	{
	case 1:
		return base;
	case 2:
		return base * 0.9;
	case 3:
		return base * 0.8;
	case 4:
		return base * 0.7;
	}
	return base * (1.0 / len * 3.3);
}

void DrawKeystrokes2()
{
	for (int i = 0; i < g.keystrokes2.keystats.stage.size(); ++i)
	{
		DrawKeyBox(g.keystrokes2.keystats.stage[i].key,
			g.keystrokes2.keystats.stage[i].kname.c_str(),
			g.keystrokes2.keystats.stage[i].fs,
			g.keystrokes2.keystats.stage[i].x,
			g.keystrokes2.keystats.stage[i].y,
			g.keystrokes2.keystats.stage[i].x + g.keystrokes2.keystats.stage[i].w,
			g.keystrokes2.keystats.stage[i].y + g.keystrokes2.keystats.stage[i].h,
			g.keystrokes2.keystats.stage[i].num, g.keystrokes2.keystats.stage[i].heat
		);

		/*setfont(20, 0, g.fontname.c_str());
		setcolor(WHITE);
		xyprintf(g.keystrokes2.keystats.stage[i].dst_x,
			g.keystrokes2.keystats.stage[i].dst_y,
			g.keystrokes2.keystats.stage[i].kname.c_str());*/
	}

	/*string s;
	for (auto& k : g.keystrokes2.keystats.stage)
	{
		s += k.kname + " ";
	}
	midprinty_shadow(s, g.uiy * 0.9);*/
}
void DrawTypewriter()
{
	constexpr int fs = 20;

	string text{ "Typewriter" };
	Color clr1{ WHITE };

	HWND hwnd = GetForegroundWindow();

	if (g.typewriter.running)
	{
		text = "Running";
		clr1 = GREEN;
	}
	else if (g.typewriter.cut.empty() || !IsWindow(g.typewriter.hwnd))
	{
		text = "Stopped";
		clr1 = RED;
	}
	else {
		text = "Paused";
		clr1 = GOLD;
	}

	if (text != "Stopped" && hwnd != g.typewriter.hwnd)
		return;

	setfont(fs, 0, g.fontname.c_str());
	setcolor(WaveColor(WHITE));
	midprinty_shadow(text, g.wnd_y + GetWindowTop(hwnd) + fs * 1.5,
		g.wnd_x + GetWindowMidX(hwnd));

	setcolor(WaveColor(clr1));
	int x = g.wnd_x + GetWindowLeft(hwnd);
	int y = g.wnd_y + GetWindowBottom(hwnd) - fs * 3;

	if ("Stopped" == text)
		xyprintf_shadow(x, y, "[Alt+1] Init");
	else
		xyprintf_shadow(x, y, "[Alt+1] Stop");

	if ("Running" == text)
		xyprintf_shadow(x, y + fs, "[Alt+2] Pause");
	else if ("Paused" == text)
	{
		xyprintf_shadow(x, y + fs, "[Alt+2] Resume");
	}

	if ("Stopped" != text)
	{
		double prog = Clamp(100.0 * g.typewriter.i / g.typewriter.cut.size(), 0.0, 100.0);
		setcolor(WaveColor(StepColor(RED, GREEN, prog / 100.0)));
		xyprintf_shadow(x, y + fs * 2, "Progress %d / %zu (%.2f%%)", g.typewriter.i, g.typewriter.cut.size(),
			prog);
	}
}

void DrawTimeDisplay()
{
	string timestr = GetTimeString();

	int fs = g.config.module_config["Time Display"].contains("Font Size") ?
		MODINT("Time Display", "Font Size") : 35;

	//Log(g.config.module_config["Time Display"].dump());

	//int fs = 35;
	int left = g.uix * MODFLOAT("Time Display", "X Rate");
	int top = g.uiy * MODFLOAT("Time Display", "Y Rate");

	setfont(fs, 0, g.fontname.c_str());

	if (MODBOOL("Time Display", "Text Background"))
	{
		int w = MeasureTextEx(g.font, timestr.c_str(), fs, 0).x + 15;
		DrawRectangle(left - 10, top - 10, w, fs + 20, ColorAlpha2(StepColor(RainbowColor(0.7f, g.rainbow_speed), BLACK, 0.9f), SinValue(0.5f, 0.9f, 6000L)));
	}

	if (IsHalfHourTime() && MODBOOL("Time Display", "Half Hour Highlight"))
		setcolor(ColorAlpha2(RED, 0.8f));
	else
	{
		//static clock_t lastUpdateColor = clock() - 3000L;
		Color clr = WHITE;

		//if (clock() - lastUpdateColor > 3000L)
		{
			// lastUpdateColor = clock();

			if (MODBOOL("Time Display", "Rainbow Color"))
				clr = RainbowColor(0.2f, g.rainbow_speed);
			else
				clr = RAYRGB(190, 190, 190);

			if (MODBOOL("Time Display", "Whiter"))
			{
				clr = StepColor(clr, RAYWHITE, 0.5f);
			}

			if (MODBOOL("Time Display", "Wave Color"))
				clr = WaveColor(clr);

			if (MODBOOL("Time Display", "Transparent"))
				clr = ColorAlpha2(clr,
					SinValue(0.5f, 0.7f, 4000L));
		}

		setcolor(clr);
	}

	xyprintf_stroke(left, top, timestr.c_str());
}
void DrawRuler()
{
	POINT pt{ g.mx, g.my };
	HWND hwnd = WindowFromPoint(pt);
	HWND hwnd_child = ChildWindowFromPoint(hwnd, pt);

	HWND hwnd1 = ValidHandle(hwnd_child) ? hwnd_child : hwnd;

	int w = GetWindowWidth(hwnd1);
	int h = GetWindowHeight(hwnd1);
	int left = GetWindowLeft(hwnd1);
	int top = GetWindowTop(hwnd1);

	DrawLine(g.mcx, top, g.mcx, top + h, WaveColor(RED));
	DrawLine(left, g.mcy, left + w, g.mcy, WaveColor(RED));

	constexpr int fs = 18;

	if (MODBOOL("Ruler", "Show Size"))
	{
		setfont(fs, 0, g.fontname.c_str());
		setcolor(WaveColor(AQUA));
		xyprintf_stroke(g.mcx + 20, g.mcy + 50, "w=%d", w);
		setcolor(WaveColor(GOLD));
		xyprintf_stroke(g.mcx + 20, g.mcy + fs + 50, "h=%d", h);
	}

	if (MODBOOL("Ruler", "Mark Sides"))
	{
		setcolor(WaveColor(RAYWHITE));
		xyprintf_stroke(left + 30, g.mcy - fs - 5, "left=%d", left);
		xyprintf_stroke(left + w - 200, g.mcy + 10, "right=%d", left + w);
		xyprintf_stroke(g.mcx + 10, top + 15, "top=%d", top);
		xyprintf_stroke(g.mcx - 160, top + h - fs - 20, "bottom=%d", top + h);
	}

	if (MODBOOL("Ruler", "Measure Distances"))
	{
		setcolor(ColorAlpha2(StepColor(RainbowColor(0.5f, g.rainbow_speed), AQUA, 0.6f), 0.5f));
		midprinty_stroke(str(g.mcx - left), g.mcy - fs - 10, (left + g.mcx) / 2);
		midprinty_stroke(str(left + w - g.mcx), g.mcy - fs - 10, (left + w + g.mcx) / 2);

		setcolor(ColorAlpha2(StepColor(RainbowColor(0.5f, g.rainbow_speed), GOLD, 0.6f), 0.5f));
		xyprintf_stroke(g.mcx - 90, (top + g.mcy) / 2 - fs / 2, str(g.mcy - top).c_str());
		xyprintf_stroke(g.mcx - 90, (top + h + g.mcy) / 2 - fs / 2, str(top + h - g.mcy).c_str());
	}
}

void DrawWatermark(bool faded)
{
	//constexpr int fs = 80;
	setfont(MODINT("Watermark", "Size"), 0, g.fontname.c_str());
	setcolor(ColorAlpha2(StepColor(RainbowColor(0.9f, g.rainbow_speed), RAYWHITE, 0.9f),
		//0.02f : SinValue(0.02f, 0.05f, 30000L)
		//0.2f : 0.3f//SinValue(0.25f, 0.35f, 30000L)
		MODFLOAT("Watermark", faded ? "Menu On Alpha" : "Menu Off Alpha")
	));

	centerprintf("W O R M W A K E R");
}
void DrawSpotlight()
{
	constexpr Color mask_color = RAYRGBA(1, 1, 1, 190);
	constexpr clock_t anim_duration = 500L;
	constexpr float final_radius = 72.0f;

	DrawRectangle(0, 0, g.uix, g.uiy, mask_color);

	double rat = Clamp(double(clock() - g.lastSpotlightToggle) / anim_duration, 0.0, 1.0);
	if (!g.spotlight_on)
		rat = 1.0 - rat;

	Color circle_color = StepColor(mask_color, ColorAlpha2(RAYWHITE, 0.7f), rat);
	float r = Lerp(g.uix / 2.0f, final_radius, EaseOutCubic(rat));

	DrawCircle(g.mcx, g.mcy, r, circle_color);
}

#define RAINBOW_ENHANCE_MASK_COLOR	RAYRGB(255, 255, 255)


Color GetNamedColor(const string& str, const string& colorMode, int i, float rainbow_step /*= 0.01f*/, float double_color_step /*= 0.07f*/)
{
	if ("Transparent" == colorMode)
		return BLANK;
	else if ("Black" == colorMode)
		return BLACK;
	else if ("Rainbow++" == colorMode)
		return(RAINBOW_ENHANCE_MASK_COLOR);
	else if ("Rainbow" == colorMode)
		return(RainbowColor(fmod(rainbow_step * i, 1.0f), g.rainbow_speed));
	else if ("Colorful" == colorMode)
		return GetStringColor(str);
	else if ("Magenta" == colorMode)
		return(MAGENTA);
	else if ("White" == colorMode)
		return(RAYWHITE);
	else if ("Green" == colorMode)
		return GREEN;
	else if ("Red" == colorMode)
		return LIGHTRED;
	else if ("Blue" == colorMode)
		return BLUE;
	else if ("Aqua-Pink" == colorMode)
		return(SinColor(
			//RAYRGB(152, 245, 255), 
			AQUA,
			//RAYRGB(255, 182, 193),
			PINK,
			120000.0 / g.rainbow_speed, fmod(double_color_step * i, 1.0f)));
	else if ("Green-Red" == colorMode)
		return(SinColor(GREEN, RED,
			120000.0 / g.rainbow_speed, fmod(double_color_step * i, 1.0f)));
	return(BLACK);
}

Color GetVapeLogoColor(const string& s)
{
	if ("White" == s)
		return RAYWHITE;
	if ("Rainbow++" == s)
		return WHITE;
	if ("Rainbow" == s)
		return RainbowColor(0.0f, g.rainbow_speed);
	return AQUA;
}

void DrawArraylistHUD()
{
	int i = 0;
	setfont(g.hud_fs, 0, g.fontname.c_str());
	/*bool rainbow = g.config.hud_config.at("Rainbow Modules").get<bool>();
	bool rainbow_enhance = g.config.hud_config["Rainbow Enhance"].get<bool>();*/
	string colorMode = GET_COMBOBOX(g.config.hud_config["Arraylist Color"]).get<string>();
	string vapeColorMode = MODCOMBOBOX("Vape", "Color");

	bool drawBar = g.config.hud_config["Arraylist Side Bar"].get<bool>();
	bool draw_bg = g.config.hud_config["Arraylist Background"].get<bool>();
	int hud_right = g.uix - g.config.hud_config["Arraylist Side Margin"].get<int>();
	int hud_top0 = g.config.hud_config["Arraylist Top"].get<int>();
	int hud_top = hud_top0;

	/*double rat = Clamp(double(clock() - g.app_start) / 3000L, 0.0, 1.0);
	int hud_right = Lerp(g.uix - g.wnd_x, g.uix - g.config.hud_config["Modules Right Gap"].get<int>(),
		EaseOutCubic(rat));*/

	bool vape = ModuleOn(Vape);

	if (vape)
	{
		auto tex = GetVapeLogo();
		int vape_w = tex.width;
		int vape_h = tex.height;

		hud_top += vape_h + 25;

		if ("Rainbow++" == vapeColorMode)
		{
			BeginTextureMode(g.rt_rainbow);
			ClearBackground(BLANK);
		}
		else {
			BeginTextureMode(g.rt);
		}

		double rat0 = Clamp(double(clock() - g.app_start) / 8000L, 0.0, 1.0);
		DrawTexture(tex, Lerp(g.uix - g.wnd_x, hud_right - vape_w, EaseOutCubic(rat0)), hud_top0,
			GetVapeLogoColor(vapeColorMode));

		EndTextureMode();
	}

	constexpr int bar_w = 5;
	constexpr Color bg_color = RAYRGBA(2, 2, 2, 230);

	if ("Rainbow++" == colorMode)
	{
		BeginTextureMode(g.rt_rainbow);
		if ("Rainbow++" != vapeColorMode)
			ClearBackground(BLANK);

		//DrawRectangle(0, 0, g.uix, g.uiy, BLACK);
	}
	else {
		BeginTextureMode(g.rt);
	}


	if (g.config.hud_config["Sort By Length"].get<bool>())
	{
		vector<string> items;

		for (const auto& md : g.module_data)
		{
			if (md.enabled)
			{
				items.push_back(GetModuleName(md.id));
			}
		}

		if (g.config.hud_config["Use Display Length"].get<bool>())
		{		//use display length
			sort(items.begin(), items.end(),
				[](const auto& s1, const auto& s2)
			{
				int L1 = MeasureTextEx(g.font, s1.c_str(), g.hud_fs, g_spacing).x;
				int L2 = MeasureTextEx(g.font, s2.c_str(), g.hud_fs, g_spacing).x;
				return L1 > L2
					|| L1 == L2 && s1 > s2;
			});
		}
		else {	//use string length
			sort(items.begin(), items.end(),
				[](const auto& s1, const auto& s2)
			{
				return s1.length() > s2.length()
					|| s1.length() == s2.length() && s1 > s2;
			});
		}

		for (const auto& item : items)
		{
			Color clr = GetNamedColor(item, colorMode, i);
			setcolor(clr);

			double rat = Clamp(double(clock() - g.app_start - 80 * i) / 3000L, 0.0, 1.0);
			int _x = Lerp(g.uix - g.wnd_x, hud_right, EaseOutCubic(rat));

			int w = MeasureTextEx(g.font, item.c_str(), g.hud_fs, g_spacing).x + 40;
			if (draw_bg)
				DrawRectangle(_x - w - 10, hud_top + g.hud_v_add * i - 5, w + (drawBar ? 10 : 0), g.hud_v_add, bg_color);

			xyprintf_shadow(_x - w, hud_top + g.hud_v_add * i, item.c_str());

			if (drawBar)
				DrawRectangle(_x, hud_top + g.hud_v_add * i, bar_w, g.hud_fs, clr);
			++i;
		}
	}
	else {	//sort by module id

		for (const auto& md : g.module_data)
		{
			if (md.enabled)
			{
				Color clr = GetNamedColor(GetModuleName(md.id), colorMode, i);
				setcolor(clr);

				double rat = Clamp(double(clock() - g.app_start - 80 * i) / 3000L, 0.0, 1.0);
				int _x = Lerp(g.uix - g.wnd_x, hud_right, EaseOutCubic(rat));

				int w = MeasureTextEx(g.font, GetModuleName(md.id).c_str(), g.hud_fs, g_spacing).x + 40;
				if (draw_bg)
					DrawRectangle(_x - w - 10, hud_top + g.hud_v_add * i - 5, w + (drawBar ? 10 : 0), g.hud_fs, bg_color);

				xyprintf_shadow(_x - w, hud_top + g.hud_v_add * i, GetModuleName(md.id).c_str());

				if (drawBar)
					DrawRectangle(_x, hud_top + g.hud_v_add * i, bar_w, g.hud_fs, clr);

				++i;
			}
		}
	}

	//if (rainbow && rainbow_enhance)
	//{	// just for test
	//	DrawRectangle(200, 300, 200, 300, RAINBOW_ENHANCE_MASK_COLOR);
	//}

	EndTextureMode();
}

void DrawClipboard()
{
	static int left = 200;
	int fs = MODINT("Clipboard ESP", "Font Size");
	int v_add = fs + MODINT("Clipboard ESP", "Line Gap");

	g.clipbd_data = strrpc(g.clipbd_data, "\r", "");
	vector<string> lines = CutLine(g.clipbd_data, '\n');

	for (auto& line : lines)
		UTF82ANSI(line);

	int max_line_shown = MODINT("Clipboard ESP", "Max Lines Shown");
	size_t line_cnt = min<size_t>(max_line_shown, lines.size());
	int h = (line_cnt + 3) * v_add;
	int top = g.uiy * 0.3 - h / 2;

	bool bg = MODBOOL("Clipboard ESP", "Text Background");
	constexpr Color bg_color = RAYRGBA(2, 2, 2, 150);

	bool show_num = MODBOOL("Clipboard ESP", "Show Line Number");
	bool show_stats = MODBOOL("Clipboard ESP", "Show Text Stats");

	if (MODBOOL("Clipboard ESP", "Show Format"))
	{

		string type{ "UNKNOWN" };

		switch (g.clipbd_format)
		{
		case 0: {
			type = "------------";
			break;
		}
		case CF_TEXT: {
			type = "--- TEXT ---";
			break;
		}
		case CF_UNICODETEXT: {
			type = "--- UNICODE ---";
			break;
		}
		case CF_DIB: {
			type = "--- DIB ---";
			break;
		}
		case CF_BITMAP: {
			type = "--- BITMAP ---";
			break;
		}
		case CF_HDROP: {
			type = "--- HDROP ---";
			break;
		}
		default: {
			type = "--- FORMAT " + str(g.clipbd_format) + " ---";
			break;
		}
		}

		setfont(fs, 0, g.fontname.c_str());
		setcolor(WaveColor(RED));
		xyprintf_shadow(left, top, type.c_str());
	}

	for (int i = 0; i < line_cnt; ++i)
	{
		if (show_num)
		{
			if (bg)
			{
				DrawRectangle(left - fs * 2.5, top + (i + 2) * v_add, fs / 2 * (str(i).size()) + fs, fs,
					bg_color);
			}
			setcolor(RainbowColor(fmod(0.06f * i, 1.0f), g.rainbow_speed));
			xyprintf(left - fs * 2, top + (i + 2) * v_add, "%d", i + 1);
		}

		if (bg)
		{
			int bw = MeasureTextEx(g.font, lines[i].c_str(), fs, 0).x + 10;
			DrawRectangle(left, top + (i + 2) * v_add, bw, fs,
				bg_color);
		}
		setcolor(StepColor(RainbowColor(0.5f, g.rainbow_speed), GOLD, 0.7));
		xyprintf_shadow(left, top + (i + 2) * v_add, lines[i].c_str());
	}

	if (lines.size() > line_cnt)
	{
		setcolor(SinColor(LIGHTRED, GREEN, 10000L));
		xyprintf_shadow(left, top + (line_cnt + 1) * v_add, "+ %zu LINES MORE", lines.size() - line_cnt);
	}

	if (g.clipbd_format == CF_TEXT
		&& MODBOOL("Clipboard ESP", "Show Text Stats")
		)
	{
		setcolor(WaveColor(BLUE));
		xyprintf_shadow(left, top + h + 10, "SIZE=%zu  LINES=%zu",
			g.clipbd_data.size(),
			lines.size()
		);
	}
}

Color GetEnabledModuleColor(const string& name, int index)
{
	string mode = GET_COMBOBOX(g.config.gui_config["Enabled Module Color"]).get<string>();
	return StepColor(GetNamedColor(name, mode, index), BLACK, 0.6f);
}
Color GetModuleBackgroundColor(const string& name, int index)
{
	string mode = GET_COMBOBOX(g.config.gui_config["Module Background Color"]).get<string>();
	if ("Black" == mode)
		return RAYRGB(1, 1, 1);
	if ("Transparent" == mode)
		return BLANK;
	return StepColor(GetNamedColor(name, mode, index), RAYRGBA(1, 1, 1, 190),
		Clamp(g.config.gui_config["Module Background Blackness (0~1)"].get<float>(), 0.0f, 1.0f));
}

#define MODULE_OPTION_W			550
#define MODULE_OPTION_TITLE_FS	25
#define MODULE_OPTION_CROSS_FS	25
#define MODULE_OPTION_FS		20
#define MODULE_OPTION_V_ADD		32
#define MODULE_OPTION_MAX_H		(int)(g.uiy * 0.6)

void DrawOptionsRaw(const string& title, json& data, bool enabled = false)
{
	int cross_fs = MODULE_OPTION_CROSS_FS * g.gui_scale;
	int title_fs = MODULE_OPTION_TITLE_FS * g.gui_scale;
	int fs = MODULE_OPTION_FS * g.gui_scale;
	int v_add = MODULE_OPTION_V_ADD * g.gui_scale;

	double rat = Clamp((clock() - g.lastModuleOptionToggle) / double(MODULE_OPTION_ANIM_TIME), 0.0, 1.0);
	if (!g.module_option_open || !g.option_open)
		rat = 1.0 - rat;

	g.module_option_pdata = &data;

	size_t key_cnt = data.size();

	//if (data.contains("Enabled") && g.top_tab_i == 0
	//	//&& clock() - g.lastModuleOptionToggle >= MODULE_OPTION_ANIM_TIME
	//	&& g.module_option_open
	//	)
	//{
	//	// key_cnt--;	// 不然坐标有问题

	//	// 直接删除
	//	for (auto& [key, value] : data.items())
	//	{
	//		if (key == "Enabled")
	//		{
	//			data.erase(key);
	//		}
	//	}
	//}

	int w = MODULE_OPTION_W * g.gui_scale;
	int h = key_cnt * v_add + title_fs + 200 * g.gui_scale;
	ClampA<int>(h, 0, MODULE_OPTION_MAX_H * g.gui_scale);
	int top = Lerp<int>(g.uiy + 60 * g.gui_scale, g.uiy / 2 - h / 2, EaseOutCubic(rat));

	DrawRectangle(g.uix / 2 - w / 2, top - 20 * g.gui_scale, w, h,
		ColorAlpha2(RAYRGBA(1, 1, 1, ModuleOn(Shaders) ? SinValue(170, 200, 10000L) : SinValue(245, 250, 10000L)), EaseOutCubic(rat)));
	DrawRectangleLines(g.uix / 2 - w / 2, top - 20 * g.gui_scale, w, h,
		StepColor(RainbowColor(0.3f, g.rainbow_speed), RAYRGB(180, 180, 180), 0.6f));

	setfont(cross_fs, 0, g.fontname.c_str());
	if (g.module_option_cross_hover)
		setcolor(GREEN);
	else
		setcolor(SinColor(RED, GOLD, 12000L));
	xyprintf(g.uix / 2 + w / 2 - cross_fs - 5 * g.gui_scale, top, "X");

	setfont(title_fs, 0, g.fontname.c_str());

	if (enabled)
		setcolor(SinColor(GREEN, GOLD, 12000L));
	else
		setcolor(WaveColor(RAYWHITE));

	midprinty_shadow(DICT(title), top);

	int opt_top = top + title_fs * 2;

	int i{ 0 };
	setfont(fs, 0, g.fontname.c_str());
	if (data.empty())
	{
		setcolor(StepColor(LIGHTRED, GOLD, SinValue(0.3f, 0.7f, 12000L)));
		midprinty(DICT("Nothing To Set"), top + h / 2 - fs * 0.2);
	}
	else {

#define MODULE_OPTION_RESET_W 85
#define MODULE_OPTION_RESET_H 35
#define MODULE_OPTION_RESET_BOTTOM_GAP 40
		//#define MODULE_OPTION_BUTTON_GAP 20
		//#define MODULE_OPTION_BIND_H 35

				//DrawBindBox(top + h - MODULE_OPTION_RESET_H - MODULE_OPTION_RESET_BOTTOM_GAP - MODULE_OPTION_BUTTON_GAP - MODULE_OPTION_BIND_H);

		DrawRectangleLines(g.uix / 2 - MODULE_OPTION_RESET_W / 2, top + h - MODULE_OPTION_RESET_H * g.gui_scale - MODULE_OPTION_RESET_BOTTOM_GAP * g.gui_scale,
			MODULE_OPTION_RESET_W * g.gui_scale, MODULE_OPTION_RESET_H * g.gui_scale,
			g.module_option_reset_hover ? SinColor(RED, MAGENTA, 6000L) : CYAN);

		setcolor(g.module_option_reset_hover ? WaveColor(CYAN) : RAYRGB(210, 210, 210));
		midprinty(DICT("Reset"), top + h - MODULE_OPTION_RESET_BOTTOM_GAP * g.gui_scale - MODULE_OPTION_RESET_H * g.gui_scale + 5);

		//xyprintf(100, top, "top:%d ---", top);
		//xyprintf(100, opt_top, "opt_top:%d ---", top);
		//xyprintf(100, opt_top + h, "opt_top + h:%d ---", top);
		//xyprintf(100, opt_top + h - g.module_option_wheel, "opt_top + h - wheel:%d ---", top);

		int saved_i{ -1 };

		for (const auto& [key, val] : data.items())
		{
			if (sequ(key, "Enabled") && g.top_tab_i == 0)
			{
				// ++i;
				continue;
			}

			if (val.is_null() || val.is_discarded())
				continue;

			bool hover = !g.module_option_key_hover.empty() && sequ(g.module_option_key_hover, key);
			bool editing = g.module_option_editing && sequ(g.module_option_edit_key, key);

			//Draw Key
			if (editing)
				setcolor(WaveColor(RAYRGB(200, 200, 200)));
			else if (hover)
			{
				setcolor(RAYRGB(255, 255, 255));
			}
			else
				setcolor(RAYRGB(230, 230, 230));

			int _y = opt_top + v_add * i - g.module_option_wheel;

			//xyprintf(100, _y, "%d ---", _y);

			// 超出指定区域
			//if (_y < opt_top - fs 
			// //|| _y >= opt_top + h - MODULE_OPTION_RESET_BOTTOM_GAP - MODULE_OPTION_RESET_H - fs
			//	)
			//	continue;
			if (_y < opt_top
				|| _y >= opt_top - 90 * g.gui_scale + h
				- MODULE_OPTION_RESET_BOTTOM_GAP * g.gui_scale - MODULE_OPTION_RESET_H * g.gui_scale)
			{
				++i;
				continue;
			}

			xyprintf(g.uix / 2 - w / 2 + 15 * g.gui_scale, _y,
				DICTC(key));

			//Draw Value
			if (editing)
			{	//该值正在编辑中

				int vw = MeasureTextEx(g.font, g.module_option_edit_value_tmp.c_str(), fs, 0).x + 10;

				DrawRectangle(g.uix / 2 + w / 2 - vw - 18 * g.gui_scale - fs, _y, vw + fs + 10 * g.gui_scale, fs + 3 * g.gui_scale,
					RAYRGBA(1, 1, 10, 240));

				if (IS_COMBOBOX(val))
				{
					saved_i = i;
					// draw it later
				}
				else {

					DrawRectangleLines(g.uix / 2 + w / 2 - vw - 18 * g.gui_scale - fs, _y, vw + fs + 10 * g.gui_scale, fs + 3 * g.gui_scale,
						ColorAlpha2(RainbowColor(0.5f, g.rainbow_speed),
							SinValue(0.5f, 0.8f, 3000L)));

					setcolor(WaveColor(YELLOW));
					xyprintf(g.uix / 2 + w / 2 - vw - 13 * g.gui_scale, _y + 3 * g.gui_scale,
						"%s",
						g.module_option_edit_value_tmp.c_str()
					);

					setcolor(SinColor(BLUE, AQUA, 3000L));
					xyprintf(g.uix / 2 + w / 2 - 21 * g.gui_scale, _y + 3 * g.gui_scale,
						"%c",
						clock() / 500L % 2 == 0 ? '|' : ' ');


					if (g.config.gui_config["Display Module Option Default Value"].get<bool>())
					{
						string sdefval;

						if (IS_KEYBIND(val))
						{
							if (!(*g.module_option_default_pdata).contains(g.module_option_edit_key))
								sdefval = "[NONE]";
							else
								sdefval = GET_KEYBIND(GetDefaultConfigValue(g.module_option_edit_key));
						}
						else
							sdefval = GetDefaultConfigValue(g.module_option_edit_key).dump();

						setcolor(SinColor(GOLD, RainbowColor(0.1f, g.rainbow_speed), 10000L));
						xyprintf_shadow(g.uix / 2 + w / 2 + 20 * g.gui_scale, _y + 3 * g.gui_scale, "%s: %s",
							DICTC("Default"),
							sdefval.c_str()
						);
					}
				}

				++i;
				continue;
			}

#define BOOLBOX_PX	21
			switch (val.type())
			{
			case nlohmann::json_abi_v3_11_3::detail::value_t::boolean: {
				// 布尔值
				int boolbox_px = BOOLBOX_PX * g.gui_scale;
				Color boolbox_color = StepColor(GREEN, LIGHTRED, SinValue(0.0f, 1.0f, 60000L));

				DrawRectangleLines(g.uix / 2 + w / 2 - boolbox_px - 25 * g.gui_scale,
					_y - 4 * g.gui_scale, boolbox_px, boolbox_px,
					hover ? MAGENTA : RAYRGB(180, 180, 180));

				if (val.get<bool>())
				{
					int gap = 3 * g.gui_scale;
					DrawRectangle(g.uix / 2 + w / 2 - boolbox_px - 25 * g.gui_scale + gap,
						_y - 4 * g.gui_scale + gap, boolbox_px - 2 * gap, boolbox_px - 2 * gap,
						hover ? InvertedColor(boolbox_color) : boolbox_color);
				}
				break;
			}

			case nlohmann::json_abi_v3_11_3::detail::value_t::number_integer: {
				int value = val.get<int>();
				int vw = MeasureTextEx(g.font, str(value).c_str(), fs, 0).x + 10;

				setcolor(hover ? GOLD : RAYRGB(200, 200, 200));
				xyprintf(g.uix / 2 + w / 2 - vw - 13 * g.gui_scale,
					_y + 3 * g.gui_scale, "%d", value
				);
				break;
			}
			case nlohmann::json_abi_v3_11_3::detail::value_t::number_unsigned: {
				unsigned value = val.get<unsigned>();
				int vw = MeasureTextEx(g.font, str(value).c_str(), fs, 0).x + 10;

				setcolor(hover ? ORANGE : RAYRGB(255, 250, 205));
				xyprintf(g.uix / 2 + w / 2 - vw - 13 * g.gui_scale,
					_y + 3 * g.gui_scale, "%u", value
				);
				break;
			}
			case nlohmann::json_abi_v3_11_3::detail::value_t::number_float: {
				float value = val.get<float>();
				int vw = MeasureTextEx(g.font, sprintf2("%.2f", value).c_str(), fs, 0).x + 10;

				setcolor(hover ? AQUA : RAYRGB(190, 220, 220));
				xyprintf(g.uix / 2 + w / 2 - vw - 13 * g.gui_scale,
					_y + 3 * g.gui_scale, "%.2f", value
				);
				break;
			}
			case nlohmann::json_abi_v3_11_3::detail::value_t::string: {
				string text = val.get<string>();
				if (text.length() > g.config.config_config["String Preview Length"].get<unsigned>())
				{	// 裁切
					text = text.substr(0, g.config.config_config["String Preview Length"].get<unsigned>()) + "...";
				}

				int vw = MeasureTextEx(g.font, text.c_str(), fs, 0).x + 15;

				setcolor(hover ? PINK : WaveColor(RAYRGB(180, 180, 180)));
				xyprintf(g.uix / 2 + w / 2 - vw - 13 * g.gui_scale,
					_y + 3 * g.gui_scale, "%s", text.c_str());
				break;
			}

			default: {

				if (IS_COMBOBOX(val))
				{
					// ComboBox
					string text = GET_COMBOBOX(val).get<string>();

					int vw = MeasureTextEx(g.font, DICTC(text), fs, 0).x + 15;

					setcolor(hover ? GOLD : CORNSILK);
					xyprintf(g.uix / 2 + w / 2 - vw - 13 * g.gui_scale,
						_y + 3 * g.gui_scale, "%s", DICTC(text));
				}
				else if (IS_KEYBIND(val))
				{	// 按键绑定
					string text = GET_KEYBIND(val);

					int vw = MeasureTextEx(g.font, text.c_str(), fs, 0).x + 15;

					if (text != "[NONE]")
						setcolor(hover ? MAGENTA : RainbowColor(0.8f, g.rainbow_speed));
					else
						setcolor(hover ? RainbowColor(0.8f, g.rainbow_speed) : RAYRGB(150, 150, 150));

					xyprintf(g.uix / 2 + w / 2 - vw - 13 * g.gui_scale,
						_y + 3 * g.gui_scale, "%s", DICTC(text));
				}
				else {

					setcolor(hover ? RED : GOLD);
					xyprintf(g.uix / 2 + w / 2 - 50 * g.gui_scale,
						_y + 10 * g.gui_scale, "[...]");
				}
				break;
			}
			}
			++i;
		}

		if (saved_i != -1)
		{
			i = saved_i;

			auto& val = data[g.module_option_edit_key];

			int vw = MeasureTextEx(g.font, DICTC(g.module_option_edit_value_tmp), fs, 0).x + 10;
			auto& arr = GET_COMBOBOX_OPTIONS(val);

			/*int bw = vw + fs + 48;
			int bleft = g.uix / 2 + w / 2 - vw - 58 - fs;*/
			int max_vw = vw;

			for (const auto& a : arr)
			{
				int tmp = MeasureTextEx(g.font, DICTC(a.get<string>()), fs, 0).x + 10;

				max_vw = max(tmp, max_vw);
			}

			int cb_v_add = v_add * 0.8;
			int bw = max_vw + fs + 40 * g.gui_scale;
			g.module_option_combo_w = bw;

			int bh = cb_v_add * arr.size() + 30 * g.gui_scale;
			int bleft = g.uix / 2 + w / 2 - bw - fs;
			g.module_option_combo_left = bleft;

			int btop = opt_top + v_add * i + fs + 3 * g.gui_scale - g.module_option_wheel;

			DrawRectangleLines(g.uix / 2 + w / 2 - vw - 18 * g.gui_scale - fs, opt_top + v_add * i - g.module_option_wheel, vw + fs + 10, fs + 3,
				ColorAlpha2(CYAN,
					SinValue(0.5f, 0.8f, 3000L)));

			setcolor(WaveColor(GOLD));
			xyprintf(g.uix / 2 + w / 2 - vw - 13 * g.gui_scale, opt_top + v_add * i + 3 * g.gui_scale - g.module_option_wheel,
				"%s",
				DICTC(g.module_option_edit_value_tmp)
			);

			string sel = GET_COMBOBOX(val);

			int k = 0;

			DrawRectangle(bleft, btop, bw, bh,
				RAYRGB(12, 12, 12));

			DrawRectangleLines(bleft, btop, bw, bh,
				RAYRGB(120, 120, 120));

			setfont(fs, 0, g.fontname.c_str());

			if (-1 != g.module_option_combo_opt_hover)
			{
				DrawRectangle(bleft + 3 * g.gui_scale, btop + (g.module_option_combo_opt_hover) * cb_v_add + 5 * g.gui_scale,
					bw - 4 * g.gui_scale, cb_v_add - 3 * g.gui_scale,
					RAYRGB(30, 40, 40));
			}

			for (auto& item : arr)
			{
				/*if (item == sel)
					continue;*/

				bool hover = k == g.module_option_combo_opt_hover;
				bool isdefault = (item.get<string>() == GetDefaultConfigValue(g.module_option_edit_key)["Selected"].get<string>()
					&& g.config.gui_config["Display Module Option Default Value"].get<bool>());

				Color clr = RAYRGB(190, 190, 190);

				if (hover)
					clr = GREEN;
				else if (isdefault)
					clr = MAGENTA;

				setcolor(clr);

				string s = DICT(item.get<string>());

				if (isdefault)
					s = "-  " + s;

				vw = MeasureTextEx(g.font, s.c_str(), fs, 0).x + 10;

				xyprintf(g.uix / 2 + w / 2 - vw - 25 * g.gui_scale,
					btop + k * cb_v_add + 8 * g.gui_scale,
					"%s",
					//hover ? (str(k) + ".  ").c_str() : "   ",
					s.c_str()
				);

				if (hover)
				{
					setcolor(StepColor(RainbowColor(0.9f, g.rainbow_speed), RED, 0.8));
					xyprintf(bleft + 5 * g.gui_scale, btop + k * cb_v_add + 8 * g.gui_scale, "[");
					xyprintf(bleft + bw - fs / 2, btop + k * cb_v_add + 8 * g.gui_scale, "]");
				}

				++k;
			}
		}
	}
}

void DrawAbout()
{
	double rat = Clamp((clock() - g.lastModuleOptionToggle) / double(MODULE_OPTION_ANIM_TIME), 0.0, 1.0);
	if (!g.module_option_open || !g.option_open)
		rat = 1.0 - rat;

	int title_fs = 60 * g.gui_scale;
	int title_top = g.uiy * 0.1;
	int about_top = title_top + title_fs + 30;
	int about_fs = 27 * g.gui_scale;
	int about_v_add = about_fs + 5;

	float fsk = Lerp(3.0f, 1.0f, EaseOutCubic(rat));
	setfont(fsk * title_fs, 0, g.fontname.c_str());
	setcolor(ColorAlpha2(SinColor(GREEN, GOLD, 6000L, 0.5f), rat));
	midprinty(DICT("About"), title_top + title_fs * (1.0f - fsk));

	vector<string> lines
	{
		"",
		"Jackal Client",
#ifdef APP_DEBUG_VERSION
		"[DEBUG VERSION]",
#endif
#ifdef _WIN64
		"[x64 VERSION]",
#endif
		DICT("A Free Powerful Windows Hacktool"),
		DICT("Version") + ": " CURRENT_VERSION,
		DICT("Compile Timestamp") + ": " __DATE__ " " __TIME__,
		DICT("Author") + ": @Wormwaker",
		DICT("Bilibili") + ": @Wormwaker [https://space.bilibili.com/3494361276877525]",
		DICT("QQ Fan Group") + ": 196218959 [" + DICT("You must follow me on bilibili!") + "]",
		"Github: noexcept2005 [https://github.com/noexcept2005]",
		DICT("Project Start Date") + ": 2024/8/10",
		"",
		DICT("* Be careful when using unsafe modules (even Driver-used Modules)"),
		DICT("* If you want to use Malware Modules, you MUST be RESPONSIBLE for your actions"),
		DICT("* If you love it very much, you can donate by charging on Bilibili for me :D"),
	};

	vector<string> operations
	{
		"",
		"[F1] " + DICT("Browse") + " Readme.txt",
		"[F2] " + DICT("Browse") + DICT("Development History") + " History.txt",
		"[F3] " + DICT("See some information...?"),
		"[F4] " + DICT("Forward my Bilibili Profile"),
		"[F5] " + DICT("Forward my Github Profile"),
	};


	for (int i = 1; i < lines.size(); ++i)
	{
		const string& line = lines[i];
		float fsk2 = Lerp(2.0f, 1.0f, EaseOutCubic(fmod(rat - 0.05f * i, 1.0f)));
		int y = about_top + i * about_v_add + about_fs * (1.0f - fsk2);

		setfont(fsk2 * about_fs, 0, g.fontname.c_str());
		setcolor(ColorAlpha2(SinColor(YELLOW, ROYALBLUE, 20000L, fmod(0.01f * i, 1.0f)), rat));
		//setcolor(GOLD);
		midprinty(line, Lerp(80, 0, EaseOutCubic(fmod(rat - 0.035f * i, 1.0f))) + y);
	}

	int operations_top = g.uiy * 0.7;
	int operations_fs = about_fs;
	int operations_v_add = operations_fs + 5;

	for (int i = 1; i < operations.size(); ++i)
	{
		const string& line = operations[i];
		float fsk2 = Lerp(5.0f, 1.0f, EaseOutCubic(fmod(rat - 0.1f * i, 1.0f)));
		int y = operations_top + i * operations_v_add + operations_fs * (1.0f - fsk2);

		setfont(fsk2 * operations_fs, 0, g.fontname.c_str());
		setcolor(ColorAlpha2(SinColor(PINK, GREEN, 16000L, fmod(0.03f * i, 1.0f)), rat));
		//setcolor(BLUE);
		midprinty(line, Lerp(50, 0, EaseOutCubic(fmod(rat - 0.05f * i, 1.0f))) + y);
	}
}
void DrawOptions(const string& name, ModuleID mid = g.module_option_id)
{
	if (name == "About")
	{
		DrawAbout();
		return;
	}

	if (sequ(name, "Modules"))
	{
		if (mid == EmptyModule)
			return;

		constexpr int desc_fs = 30;
		if (g.config.gui_config["Show Module Description"].get<bool>()
			&& module_descriptions.find(mid) != module_descriptions.end())
		{
			setfont(desc_fs * g.gui_scale, 0, g.fontname.c_str());
			if (ModuleOn(mid))
				setcolor(StepColor(RainbowColor(0.7f, g.rainbow_speed), GOLD, 0.6f));
			else
				setcolor(RAYRGB(190, 190, 190));

			int w = MeasureTextEx(g.font, GetModuleDescription(mid).c_str(), desc_fs * g.gui_scale, g_spacing).x;
			DrawRectangleRounded(MakeRectangle0(g.uix / 2 - w / 2, g.uiy - 205, w + 20, desc_fs * g.gui_scale + 10), 0.2f, 3,
				StepColor(InvertedColor(RainbowColor(0.8f, g.rainbow_speed)), BLACK, 0.96f));
			DrawRectangleRoundedLines(MakeRectangle0(g.uix / 2 - w / 2, g.uiy - 205, w + 20, desc_fs * g.gui_scale + 10), 0.2f, 3,
				2.0f,
				StepColor(RainbowColor(0.2f, g.rainbow_speed), WHITE, 0.85f));

			midprinty_shadow(GetModuleDescription(mid), g.uiy - 200);
		}

		g.module_option_default_pdata = &config_default_jsons["Modules"][module_names[mid]];
		DrawOptionsRaw(GetModuleName(mid), g.config.module_config[module_names[mid]], ModuleOn(mid));
	}
	else {

		g.module_option_default_pdata = &config_default_jsons[name];

		if (sequ(name, "Config"))
		{
			DrawOptionsRaw(name, g.config.config_config, true);
		}
		else if (sequ(name, "GUI"))
		{
			DrawOptionsRaw(name, g.config.gui_config, true);
		}
		else if (sequ(name, "HUD"))
		{
			DrawOptionsRaw(name, g.config.hud_config, true);
		}
	}
}


#define LIBRARY_ANIM_TIME	800L
#define LIBRARY_MODULE_LEFT 60
#define LIBRARY_MODULE_TOP	150

void DrawLibraryModules(double rat)
{
	constexpr int left = LIBRARY_MODULE_LEFT;
	constexpr int top = LIBRARY_MODULE_TOP;
	constexpr int bottom_gap = 110;
	constexpr int h_gap = 15;

	if (g.library_col_widthes.empty())
	{
		g.library_row_cnt = (g.uiy - top - bottom_gap) / g.module_h;

		g.library_col_widthes.resize(g.library_row_cnt);
		g.library_col_lefts.resize(g.library_row_cnt);

		int _left = left;
		for (int x = 0; x < ceil(g.library_modules.size() / (double)g.library_row_cnt); ++x)
		{
			g.library_col_lefts[x] = _left;
			int wmax = 0;
			for (int y = 0; y < g.library_row_cnt; ++y)
			{
				if (x * g.library_row_cnt + y >= g.library_modules.size())
					break;
				int w = MeasureTextEx(g.font, GetModuleName(g.library_modules[x * g.library_row_cnt + y]).c_str(), g.module_fs, 0).x + 20;
				wmax = max(wmax, w);
			}
			g.library_col_widthes[x] = wmax;
			_left += wmax + h_gap;
		}
	}

	constexpr int title_fs = 30;

	setfont(title_fs * g.gui_scale, 0, g.fontname.c_str());
	setcolor(ColorAlpha2(SinColor(GREEN, GOLD, 120000L), rat));
	xyprintf_shadow(Lerp(-100, left, EaseOutCubic(rat)), top - 50, "LIBRARY");

	setfont(g.module_fs * g.gui_scale, 0, g.fontname.c_str());
	setcolor(ColorAlpha2(g.tab_color, rat));

	string align = GET_COMBOBOX(g.config.gui_config["Module Name Alignment"]).get<string>();

	constexpr clock_t delay_per_module = 20L;

	int j = 0;
	for (int x = 0; x < ceil(g.library_modules.size() / (double)g.library_row_cnt); ++x)
	{
		for (int y = 0; y < g.library_row_cnt; ++y)
		{
			if (x * g.library_row_cnt + y >= g.library_modules.size())
				break;

			double rat3 = Clamp(double(clock() - g.lastOpenToggle - delay_per_module * j) / LIBRARY_ANIM_TIME, 0.0, 1.0);
			ModuleID mid = g.library_modules[x * g.library_row_cnt + y];
			int _x = g.library_col_lefts[x] + Lerp(-200, 0, EaseOutCubic(rat3));
			int _y = top + g.module_h * g.gui_scale * y;

			if (g.module_data[mid].enabled)
			{
				Color enabledClr = GetEnabledModuleColor(GetModuleName(mid), x * g.library_row_cnt + y);
				auto rat2 = g.module_data[mid].GetShowRate();
				DrawRectangle(_x, _y, g.library_col_widthes[x] * g.gui_scale, g.module_h * g.gui_scale, ColorAlpha2(enabledClr, rat * rat2));
				DrawRectangle(_x, _y, 5 * g.gui_scale, g.module_h * g.gui_scale * EaseInOutExpo(rat2), ColorAlpha2(g.module_bar_color, rat));
			}
			else if (g.module_hover == j)
			{
				Color hoverClr = g.bg_hover_color;
				DrawRectangle(_x, _y, g.library_col_widthes[x] * g.gui_scale, g.module_h * g.gui_scale, ColorAlpha2(hoverClr, rat));
			}
			else {
				Color bgClr = GetModuleBackgroundColor(GetModuleName(mid), x * g.library_row_cnt + y);
				DrawRectangle(_x, _y, g.library_col_widthes[x] * g.gui_scale, g.module_h * g.gui_scale, ColorAlpha2(bgClr, rat));
			}

			//midprintf(g.tab_tops[i] + g.module_h + g.module_h * j, module_names[md].c_str());
			//xyprintf(_x + 10, _y + 3, GetModuleName(mid).c_str());

			alignprint(GetModuleName(mid), _y + 3, _x, _x + g.library_col_widthes[x] * g.gui_scale, align);

			++j;
		}
	}

	setfont(g.module_fs * g.gui_scale, 0, g.fontname.c_str());
	if (g.library_modules.empty())
	{
		setcolor(WaveColor(StepColor(RainbowColor(0.8f, g.rainbow_speed), AQUA, 0.6f)));
		xyprintf_shadow(Lerp(-300, left, EaseOutCubic(rat)), g.uiy - bottom_gap, DICTC("NO MODULES YET"));
	}
	else
	{
		setcolor(WaveColor(AQUA));
		xyprintf_shadow(Lerp(-300, left, EaseOutCubic(rat)), g.uiy - bottom_gap, DICTC("%zu MODULES"), g.library_modules.size());
	}

	if (g.config.gui_config["Show Module Description"].get<bool>()
		&& g.module_hover != -1 && module_descriptions.find(g.library_modules[g.module_hover]) != module_descriptions.end())
	{
		setfont(g.modesc_fs * g.gui_scale, 0, g.fontname.c_str());
		setcolor(ColorAlpha2(StepColor(RainbowColor(0.8f, g.rainbow_speed), RAYWHITE, 0.9f), rat));
		int w = MeasureTextEx(g.font, GetModuleDescription(g.library_modules[g.module_hover]).c_str(), g.modesc_fs * g.gui_scale, g_spacing).x;

		DrawRectangleRounded(MakeRectangle0(Lerp(-300, left, EaseOutCubic(rat)),
			g.uiy - bottom_gap * g.gui_scale + g.module_fs * g.gui_scale,
			w + 20, g.modesc_fs * g.gui_scale + 10),
			0.3f, 3,
			ColorAlpha2(StepColor(InvertedColor(RainbowColor(0.8f, g.rainbow_speed)), BLACK, 0.85f),
				rat));

		DrawRectangleRoundedLines(MakeRectangle0(Lerp(-300, left, EaseOutCubic(rat)),
			g.uiy - bottom_gap * g.gui_scale + g.module_fs * g.gui_scale,
			w + 20, g.modesc_fs * g.gui_scale + 10),
			0.3f, 3, 2.0f,
			ColorAlpha2(StepColor(RainbowColor(0.2f, g.rainbow_speed), WHITE, 0.85f),
				rat));

		xyprintf(Lerp(-300, left, EaseOutCubic(rat)), g.uiy - bottom_gap * g.gui_scale + g.module_fs * g.gui_scale + 3, GetModuleDescription(g.library_modules[g.module_hover]).c_str());
	}
}

void DrawNormalModules(double rat)
{
	constexpr float roundness = 0.2f;
	constexpr int segments = 3;
	constexpr float thickness = 2.0f;

	constexpr float roundness2 = 0.5f;
	constexpr int segments2 = 6;

	bool rainbow_gui = g.config.gui_config["Rainbow GUI"].get<bool>();
	bool gui_outline = g.config.gui_config["Outline"].get<bool>();
	string align = GET_COMBOBOX(g.config.gui_config["Module Name Alignment"]).get<string>();

	int i = 0;
	for (const auto& col : g.tab_cols)
	{
		const auto& tab = g.tabs[col];

		//绘制选项卡

		int x = g.tab_lefts[i];
		Color themeClr = rainbow_gui ? StepColor(RainbowColor(0.0f, g.rainbow_speed), BLACK, 0.3f) : g.theme_color;


		if (g.tab_open[i])
		{

			if (gui_outline)
			{
				/*DrawRectangleLines(x, g.tab_tops[i] + g.module_h, g.tab_widthes[i],
					tab.size() * g.module_h,
					ColorAlpha2(themeClr, rat));*/

					/*DrawRectangleRoundedLines(MakeRectangle0(x, g.tab_tops[i], g.tab_widthes[i],
						(1 + tab.size()) * g.module_h), roundness, segments, thickness,
						ColorAlpha2(themeClr, rat));*/

						// 绘制整个圆角矩形
				DrawRectangleRounded(MakeRectangle0(x - thickness, g.tab_tops[i], g.tab_widthes[i] * g.gui_scale + thickness * 2 * g.gui_scale,
					(1 + tab.size()) * g.module_h * g.gui_scale + g.module_h * 0.5 * g.gui_scale), roundness, segments,
					ColorAlpha2(themeClr, rat));
			}

			/*DrawRectangle(x, g.tab_tops[i] + g.module_h, g.tab_widthes[i],
				tab.size() * g.module_h, ColorAlpha2(g.bg_color, rat));*/
			DrawRectangleRounded(MakeRectangle0(x, g.tab_tops[i] + g.module_h * g.gui_scale, g.tab_widthes[i] * g.gui_scale,
				(tab.size()) * g.module_h * g.gui_scale), roundness, segments, ColorAlpha2(g.bg_color, rat));

		}

		//DrawRectangle(x, g.tab_tops[i], g.tab_widthes[i], g.module_h, ColorAlpha2(g.quitting ? RAYRGBA(150, 150, 150, 180) : themeClr, rat));

		if (!gui_outline || !g.tab_open[i])
		{
			DrawRectangleRounded(MakeRectangle0(x, g.tab_tops[i], g.tab_widthes[i] * g.gui_scale, g.module_h * g.gui_scale), roundness2, segments2, ColorAlpha2(g.quitting ? RAYRGBA(150, 150, 150, 180) : themeClr, rat));
		}

		setfont(g.module_fs * g.gui_scale, 0, g.fontname.c_str());
		setcolor(ColorAlpha2(g.tab_color, rat));
		//midprintf(g.tab_tops[i], tab.first.c_str());

		alignprint(col, g.tab_tops[i], x, x + g.tab_widthes[i] * g.gui_scale, align);

		// 未展开的选项卡
		if (!g.tab_open[i])
		{
			++i;
			continue;
		}

		//绘制每个选项卡下的模块
		int j = 0;
		for (const auto& md : tab)
		{
			if (g.module_data[md].enabled)
			{
				Color enabledClr = GetEnabledModuleColor(GetModuleName(md), j);
				auto rat2 = g.module_data[md].GetShowRate();
				DrawRectangle(x, g.tab_tops[i] + g.module_h * g.gui_scale + g.module_h * j * g.gui_scale, g.tab_widthes[i] * g.gui_scale, g.module_h * g.gui_scale, ColorAlpha2(enabledClr, rat * rat2));
				DrawRectangle(x, g.tab_tops[i] + g.module_h * g.gui_scale + g.module_h * j * g.gui_scale, 5, g.module_h * g.gui_scale * EaseInOutExpo(rat2), ColorAlpha2(g.module_bar_color, rat));
			}
			else if (g.tab_hover == i && g.module_hover == j)
			{
				DrawRectangle(x, g.tab_tops[i] + g.module_h * g.gui_scale + g.module_h * j * g.gui_scale, g.tab_widthes[i] * g.gui_scale, g.module_h * g.gui_scale, ColorAlpha2(g.bg_hover_color, rat));
			}
			else {
				Color bgClr = GetModuleBackgroundColor(GetModuleName(md), j);
				DrawRectangle(x, g.tab_tops[i] + g.module_h * g.gui_scale + g.module_h * j * g.gui_scale, g.tab_widthes[i] * g.gui_scale, g.module_h * g.gui_scale, ColorAlpha2(bgClr, rat));
			}

			if (AdminRequiredModule(md) && !g.admin)
				setcolor(ColorAlpha2(g.tab_admin_color, rat));
			else
				setcolor(ColorAlpha2(g.tab_color, rat));
			//midprintf(g.tab_tops[j] + g.module_h + g.module_h * j, module_names[md].c_str());

			alignprint(GetModuleName(md), g.tab_tops[i] + g.module_h * g.gui_scale + g.module_h * g.gui_scale * j + 2, x, x + g.tab_widthes[i] * g.gui_scale, align);

			++j;
		}

		++i;
	}
}

void DrawExtraChars()
{
	setfont(20, 0, g.fontname.c_str());
	int h_cnt = (g.uix - 20) / 20;
	string s = g.extra_chars;
	for (int i = 0; i < ceil(g.extra_chars.size() / 3.0f / h_cnt) && !s.empty(); ++i)
	{
		setcolor(RainbowColor(fmod(i * 0.03f, 1.0f), g.rainbow_speed));
		xyprintf_shadow(10, g.uiy - 25 * (i + 1), "%s", s.c_str());
		s = strxhead(s, h_cnt * 3);
	}
}

void RenderWindowESP()
{
	static vector<pair<HWND, Rectangle>> rects;
	static clock_t lastUpdateRects = clock();

	if (clock() - lastUpdateRects > MODUNSIGNED("Window ESP", "Update Cooldown")) {
		EnumWindows([](HWND hwnd, LPARAM lParam) -> BOOL
		{
			RECT rect;
			GetWindowRect(hwnd, &rect);
			((vector<pair<HWND, Rectangle>> *)lParam)->emplace_back(hwnd, Rectangle{ float(rect.left), float(rect.top), float(rect.right - rect.left), float(rect.bottom - rect.top) });
			return TRUE;
		}, reinterpret_cast<LPARAM>(&rects));
	}

	bool exclude_fg = MODBOOL("Window ESP", "Exclude Foreground");
	bool exclude_pointed = MODBOOL("Window ESP", "Exclude Pointed");
	bool exclude_inv = MODBOOL("Window ESP", "Exclude Invisible");
	float alpha = MODFLOAT("Window ESP", "Box Alpha");

	HWND hwnd_fg = GetForegroundWindow();
	HWND hwnd_ptd = WindowFromPoint(g.mpt);

	int i{ 0 };
	for (auto& rect : rects)
	{
		if (exclude_inv && !IsWindowVisible(rect.first)
			|| exclude_fg && rect.first == hwnd_fg
			|| exclude_pointed && rect.first == hwnd_ptd)
			continue;

		Color clr = ColorAlpha2(RainbowColor(fmod(0.1 * i, 1.0), g.rainbow_speed), alpha);
		DrawRectangleLines(rect.second.x, rect.second.y, rect.second.width, rect.second.height,
			clr);

		++i;
	}
}

#define MALWARE_WARNING_DURATION			1000L
#define MALWARE_WARNING_BOX_DURATION		3000L
#define MALWARE_WARNING_BUTTON_DURATION		5000L
#define MALWARE_WARNING_TIMEDOWN			10000L

void DrawMalwareWarning()
{
	constexpr int title_fs = 55;
	constexpr int fs = 35;
	constexpr int v_add = 50;

	double rat = Clamp(double(clock() - g.lastWarning) / MALWARE_WARNING_DURATION, 0.0, 1.0);
	double rat2 = Clamp(double(clock() - g.lastWarning) / MALWARE_WARNING_BOX_DURATION, 0.0, 1.0);
	double rat_btn = Clamp(double(clock() - g.lastWarning) / MALWARE_WARNING_BUTTON_DURATION, 0.0, 1.0);

	DrawRectangle(0, 0, g.uix, g.uiy,
		RAYRGBA(1, 1, 1, 200 * EaseOutCubic(rat)));

	DrawRectangleLinesEx(MakeRectangle0(0, 0, g.uix, g.uiy), 5.0f * rat2,
		ColorAlpha2(SinColor(RED, RAYRGB(255, 69, 0), 8000L), rat2));

	setfont(title_fs, 0, g.fontname.c_str());
	setcolor(ColorAlpha2(ORANGE, rat2));
	constexpr int title_y = 120;

	midprinty("MALWARE WARNING", Lerp(-title_fs, title_y, EaseOutCubic(rat)));

	setfont(fs, 0, g.fontname.c_str());
	setcolor(ColorAlpha2(WaveColor(RAYRGB(200, 200, 200)), rat2));

	static const list<string> texts
	{
		"These modules are involved in MALWARE Behaviours.",
		"Unless you know what you are doing",
		"DO NOT use these modules.",
		"You can test these modules in virtual machines, however.",
		"Anyhow, never do anything ILLEGAL.",
		"If you DO, you are RESPONSIBLE for your ACTIONS.",
		"ANY USE OF THESE MALWARE MODULES IS",
		"ENTIRELY AT YOUR OWN RISK",
	};


	int i{ 0 };
	for (const auto& line : texts)
	{
		midprinty_shadow(line,
			title_y + title_fs + 80 + i * v_add + Lerp(80, 0, EaseOutCubic(rat2)));
		++i;
	}

	constexpr int btn_fs = 50;
	static int btn_top = g.uiy - 350;

	setfont(btn_fs, 0, g.fontname.c_str());
	int sec = (clock() - g.lastWarning) / 1000L;
	if (sec < MALWARE_WARNING_TIMEDOWN / 1000L)
	{
		setcolor(ColorAlpha2(WaveColor(BLUE), rat_btn));
		midprinty_shadow("[Y] i understand (" + str(MALWARE_WARNING_TIMEDOWN / 1000L - sec) + ")", Lerp(g.uiy, btn_top, EaseOutCubic(rat_btn)));
	}
	else {
		setcolor(ColorAlpha2(WaveColor(RAYRGB(192, 255, 62)), rat_btn));
		midprinty_shadow("[Y] I UNDERSTAND", Lerp(g.uiy, btn_top, EaseOutCubic(rat_btn)));
	}

	setcolor(ColorAlpha2(WaveColor(SinColor(RED, MAGENTA, 6000L)), rat_btn));
	midprinty_shadow("[Esc] NO THANKS", Lerp(g.uiy + 200, btn_top + btn_fs + 40, EaseOutCubic(rat_btn)));

}

#define SEARCH_INPUT_BAR_BLINK_TIME 500L
#define SEARCH_MODULES_ROW_CNT 4U
#define SEARCH_TITLE_FS 50
#define SEARCH_TITLE_TOP 180
#define SEARCH_INPUT_W 400
#define SEARCH_INPUT_FS 30
#define SEARCH_INPUT_H	50
#define SEARCH_MODULE_W 280
#define SEARCH_MODULE_H 70
#define SEARCH_MODULE_W_GAP 100
#define SEARCH_MODULE_H_GAP 60

void DrawSearch()
{
	constexpr int fs = SEARCH_TITLE_FS;
	constexpr int title_y0 = SEARCH_TITLE_TOP;
	constexpr int input_y0 = title_y0 + fs + 50;
	constexpr int input_w = SEARCH_INPUT_W;
	constexpr int input_fs = SEARCH_INPUT_FS;
	constexpr int input_h = SEARCH_INPUT_H;

	double rat = Clamp(double(clock() - g.lastSearchToggle) / 1000.0, 0.0, 1.0);
	if (!g.search_open)
		rat = 1.0 - rat;

	// 绘制标题
	setfont(fs, 0, g.fontname.c_str());
	setcolor(ColorAlpha2(StepColor(RainbowColor(0.4f, g.rainbow_speed), WHITE, 0.95f), rat));

	int title_y = Lerp(-fs, title_y0, EaseOutCubic(rat));
	midprinty_shadow(DICTC("Search"), title_y);

	// 绘制搜索框
	int input_y = Lerp(-fs, input_y0, EaseOutCubic(rat));
	Rectangle rt{ g.uix / 2 - input_w / 2, input_y, input_w, input_h };
	DrawRectangleRounded(rt, 0.2f, 3, ColorAlpha2(RAYRGBA(0, 0, 5, 200), rat));

	Color lineClr = g.search_string.empty() ? RED : (g.search_results.empty() ? SinColor(LIGHTRED, GOLD, 4000L) : SinColor(BLUE, ROYALBLUE));
	DrawRectangleRoundedLines(rt, 0.2f, 3, 2.0f, ColorAlpha2(lineClr, rat));

	// 绘制搜索文本
	if (!g.search_string.empty())
	{

		Color inputClr{ WaveColor(WHITE) };
		if (g.search_results.empty())
			inputClr = WaveColor(YELLOW);
		else if (g.search_results.size() == 1)
			inputClr = GREEN;
		else {
			bool fullMatch = false;
			for (const auto& name : module_names)
			{
				if (sequ(name, strip(g.search_string)))
				{
					fullMatch = true;
					break;
				}
			}

			if (fullMatch)
				inputClr = SinColor(GOLD, MAGENTA, 2000L);
		}

		setfont(input_fs, 0, g.fontname.c_str());
		setcolor(ColorAlpha2(inputClr, rat));
		midprinty_shadow(g.search_string, input_y + input_h / 2 - input_fs / 2);
	}

	// 绘制闪烁的光标
	if (clock() / SEARCH_INPUT_BAR_BLINK_TIME % 2 == 0)
	{
		int bar_x = g.uix / 2 - input_fs / 2;
		if (!g.search_string.empty())
			bar_x = g.uix / 2 + MeasureTextEx(g.font, g.search_string.c_str(), input_fs, g_spacing).x / 2;

		setfont(input_fs, 0, g.fontname.c_str());
		setcolor(ColorAlpha2(RainbowColor(0.8f, g.rainbow_speed), rat));
		xyprintf_shadow(bar_x, input_y + input_h / 2 - input_fs / 2, "_");
	}

	// 绘制搜索结果
	if (!g.search_results.empty())
	{
		setfont(22, 0, g.fontname.c_str());
		setcolor(ColorAlpha2(SinColor(MAGENTA, PURPLE, 4000L), rat));
		midprinty(str(g.search_results.size()) + " "s + DICT("Results"), input_y + input_h + 15);

		int modules_top = input_y + input_h + 100;

		constexpr int module_fs = 24;
		constexpr int module_w = SEARCH_MODULE_W;
		constexpr int module_w_gap = SEARCH_MODULE_W_GAP;
		constexpr int module_h = SEARCH_MODULE_H;
		constexpr int module_h_gap = SEARCH_MODULE_H_GAP;

		size_t row_cnt = ceil(double(g.search_results.size()) / SEARCH_MODULES_ROW_CNT);
		int left = g.uix / 2 - SEARCH_MODULES_ROW_CNT * module_w / 2 - (SEARCH_MODULES_ROW_CNT - 1) * module_w_gap / 2;

		for (int y = 0; y < row_cnt; ++y)
		{
			for (int x = 0; x < SEARCH_MODULES_ROW_CNT; ++x)
			{
				if (y * SEARCH_MODULES_ROW_CNT + x >= g.search_results.size())
					break;

				ModuleID mid = g.search_results[y * SEARCH_MODULES_ROW_CNT + x];
				bool hovered = (g.module_hover == mid);
				bool fullMatch = sequ(module_names[mid], strip(g.search_string));
				int _x = left + x * (module_w + module_w_gap);
				int _y = modules_top + y * (module_h + module_h_gap) - g.search_wheel;

				if (_y < modules_top - module_h || _y >= g.uiy)
					break;

				double rat2 = 1.0;
				if (_y < modules_top + 10)
				{
					rat2 = Clamp(1.0 - double(modules_top + 10 - _y) / (10 + module_h), 0.0, 1.0);
				}
				else if (_y > g.uiy - 100)
				{
					rat2 = Clamp(1.0 - (_y - g.uiy + 100) / 100.0, 0.0, 1.0);
				}

				Color modBgColor = (ModuleOn(mid) ? StepColor(RainbowColor(0.85f, g.rainbow_speed), RAYRGBA(250, 1, 1, 210), 0.9f) : RAYRGBA(0, 0, 0, 200));
				if (fullMatch)
					modBgColor = StepColor(RainbowColor(0.1f, g.rainbow_speed), modBgColor, 0.8f);
				Color modOutlineColor = fullMatch ? WaveColor(StepColor(RainbowColor(0.6f), GREEN, 0.85f)) : (ModuleOn(mid) ? RAYRGBA(78, 238, 148, 230) : SinColor(RAYRGBA(193, 255, 193, 220), RAYRGBA(255, 192, 203, 200), 5000L));
				Color modColor = (ModuleOn(mid) ? SinColor(RAYRGBA(187, 255, 255, 250), RAYRGBA(255, 228, 181, 250), 2000L) : StepColor(RainbowColor(0.3f, g.rainbow_speed), RAYRGBA(250, 250, 250, 235), 0.9f));

				if (hovered)
				{
					modBgColor = StepColor(modBgColor, RAYRGBA(255, 255, 255, 205), 0.1f);
				}

				Rectangle rt{ _x, _y, module_w, module_h };
				DrawRectangleRounded(rt, 0.2f, 3, ColorAlpha2(modBgColor, rat * rat2));
				DrawRectangleRoundedLines(rt, 0.2f, 3, 2.0f, ColorAlpha2(modOutlineColor, rat * rat2));

				setfont(module_fs * (hovered ? 1.1f : 1.0f), 0, g.fontname.c_str());
				setcolor(ColorAlpha2(modColor, rat * rat2));
				xyprintf_shadow(_x + 15, _y + module_h / 2 - module_fs / 2,
					GetModuleName(mid).c_str());
			}
		}
	}
	else {
		constexpr int tip_fs = 25;

		setfont(tip_fs, 0, g.fontname.c_str());
		setcolor(ColorAlpha2(SinColor(PINK, AQUA), rat * 0.8));
		midprinty_shadow(DICT("No Results"), Lerp(g.uiy, input_y0 + input_h + 100, EaseOutCubic(rat)));
	}
}

void MouseWatch::RenderHUD() const
{
	string style = MODCOMBOBOX("Mouse Watcher", "HUD");
	if ("Off" == style)
		return;

	double xrate = MODFLOAT("Mouse Watcher", "HUD X Rate");
	double yrate = MODFLOAT("Mouse Watcher", "HUD Y Rate");

	int fs = MODINT("Mouse Watcher", "HUD Font Size");
	int v_add = fs + MODINT("Mouse Watcher", "HUD Line Gap");

	int hud_left = xrate * g.uix;
	int hud_top = yrate * g.uiy;
	int hud_w = 220;

	list<string> lines
	{
		"Mouse Watcher",
		sprintf2("X=%d   Y=%d", g.mx, g.my),
		sprintf2("RX=%d   RY=%d", g.mrx, g.mry),
		sprintf2("CPS   %d  |  %d", left_cps, right_cps),
		sprintf2("Velocity  %.3f", prev_v),
		sprintf2("Accel     %.3f", prev_a),
	};

	int hud_h = lines.size() * v_add + 10;

	string bgStyle = MODCOMBOBOX("Mouse Watcher", "HUD");
	// Draw Window Master HUD
	if ("Fancy" == bgStyle)
	{
		DrawRectangleRounded(MakeRectangle0(hud_left - 18, hud_top - 10, hud_w + 5, hud_h),
			0.1f, 4, RAYRGBA(10, 5, 2, SinValue(254, 240, 10000L)));
		DrawRectangleRoundedLines(MakeRectangle0(hud_left - 18, hud_top - 10, hud_w + 5, hud_h),
			0.1f, 4, 2.0f, StepColor(RainbowColor(0.6f, g.rainbow_speed), WHITE, 0.75f));
	}

	string colorStyle = MODCOMBOBOX("Mouse Watcher", "HUD Color");
	setfont(fs, 0, g.fontname.c_str());
	int i{ 0 };
	for (const auto& line : lines)
	{
		int x = hud_left;
		int y = hud_top + i * v_add;

		Color clr = GetNamedColor(line, colorStyle, i);
		setcolor(clr);

		if ("Simple" == bgStyle)
		{
			int w = min<int>(hud_w, MeasureTextEx(g.font, line.c_str(), fs, g_spacing).x) + 15;
			DrawRectangleRounded(MakeRectangle0(x, y, w, fs + 3),
				0.1f, 2, RAYRGBA(2, 2, 2, SinValue(240, 254, 10000L)));
		}

		xyprintf_shadow(x, y, line.c_str());

		++i;
	}
}
void ApplyMotionBlur()
{
	if (!ModuleOn(MotionBlur))
		return;

	if (g.tex_screenshot_frames.empty())
		return;

	int i = 0;
	size_t cnt = g.tex_screenshot_frames.size();
	constexpr float lambda = 0.5f;
	for (auto iter = g.tex_screenshot_frames.rbegin();
		iter != g.tex_screenshot_frames.rend();
		++iter)
	{
		//// 指数衰减
		//float rat = 
		//	Clamp(exp(-lambda * i), 0.0f, 1.0f);
		float rat = (cnt == 1U ? 0.3f : (1.0 - (i / float(cnt - 1))));

		DrawTexture(*iter, 0, 0, ColorAlpha2(WHITE, rat));
		++i;
	}
}
void ApplyScreenShader()
{
	if (!ModuleOn(Shaders) && !ModuleOn(Background))
		return;

	if (ModuleOn(Shaders) && "Screen" != MODCOMBOBOX("Shader", "Apply Area")
		|| ModuleOn(Background) && !MODBOOL("Background", "Screen Compensation"))
		return;

	if (!ModuleOn(Shaders))
	{
		string when = MODCOMBOBOX("Background", "When to Apply Screen Compensation");
		if (when == "Menu On" && !g.option_open
			|| when == "Menu Off" && g.option_open)
			return;
	}

	if (!IsTextureReady(g.tex_screenshader))
		return;

	DrawTexture(g.tex_screenshader, 0, 0, WHITE);
}

void DrawCrackPasswordHUD()
{
	if (!MODBOOL("Crack Password", "HUD"))
		return;

	constexpr int w = 700;
	constexpr int h = 40;
	constexpr int fs = 35;
	constexpr int fs2 = 45;
	static int midy = g.uiy * 0.8;
	static int y1 = midy - fs - h / 2 - 15;

	constexpr float roundness = 0.1f;
	constexpr int segments = 2;

	Color color = SinColor(AQUA, PINK, 10000L);
	Color lineColor = SinColor(AQUA, PINK, 10000L);

	int left = g.uix / 2 - w / 2;
	int top = midy - h / 2;

	double rat = Clamp(g.pwdcrack_cur / double(g.pwdcrack_total), 0.0, 1.0);

	auto rt = MakeRectangle0(left, top, w, h);
	auto rt2 = MakeRectangle0(left, top, w * rat, h);

	DrawRectangleRounded(rt, roundness, segments, RAYRGBA(1, 1, 1, 130));
	DrawRectangleRounded(rt2, roundness, segments, color);
	DrawRectangleRoundedLines(rt, roundness, segments, 2.0f, lineColor);

	setfont(fs, 0, g.fontname.c_str());
	setcolor(WaveColor(StepColor(RED, GREEN, rat)));
	string s = DICT("CRACKING PASSWORD...");
	string s2 = sprintf2("%d / %d  (%.2f)", g.pwdcrack_cur.load(), g.pwdcrack_total.load(),
		rat * 100.0);


	midprinty_shadow(s, y1);
	setcolor(SinColor(GOLD, RainbowColor(0.9f, g.rainbow_speed), 5000L));
	xyprintf_shadow(left + w * rat + 20, top + 3, s2.c_str());

	if (MODBOOL("Crack Password", "HUD Show Current Password Attempt"))
	{
		string s3 = string(g.pwdcrack_curpwd);
		setfont(fs2, 0, g.fontname.c_str());
		setcolor(SinColor(GRAY, RainbowColor(0.2f, g.rainbow_speed), 10000L));
		midprinty_shadow(s3, top + h + 15);
	}
}

void DrawVolumeHUD()
{
	string sysVolHud = MODCOMBOBOX("Volume", "System Volume HUD");
	string procVolHud = MODCOMBOBOX("Volume", "Process Volume HUD");
	clock_t tempDuration = MODUNSIGNED("Volume", "Temp HUD Duration (ms)");

	bool drawSysVolHud = (sysVolHud == "Always"
		|| (sysVolHud == "Temp" && clock() - g.lastSysVolAdjust < tempDuration));

	bool drawProcVolHud = (procVolHud == "Always"
		|| (procVolHud == "Temp" && clock() - g.lastProcVolAdjust < tempDuration));

	if (drawSysVolHud)
	{
		constexpr clock_t fadeTime = 200L;
		double rat = 1.0;

		if (sysVolHud == "Temp")
		{
			if (clock() - g.lastSysVolAdjust < fadeTime)
				rat = Clamp(double(clock() - g.lastSysVolAdjust) / double(fadeTime), 0.0, 1.0);
			else if (clock() - g.lastSysVolAdjust > tempDuration - fadeTime)
				rat = Clamp(double(tempDuration - (clock() - g.lastSysVolAdjust)) / double(fadeTime), 0.0, 1.0);
		}

		string style = MODCOMBOBOX("Volume", "System Volume HUD Style");

		if ("Bottom" == style)
		{
			constexpr int fs = 30;
			setfont(fs, 0, g.fontname.c_str());
			setcolor(WaveColor(ColorAlpha2(GOLD, rat)));
			midprinty_stroke(sprintf2("%s %d%%%%", DICTC("System Volume"), GetSystemVolume()), g.uiy * 0.9);
		}
		else if ("Bottom Big" == style)
		{
			int vol = GetSystemVolume();
			string s = sprintf2("%s %d%%%%", DICTC("System Volume"), vol);
			int fs = g.uix / s.length() * 1.3;
			setfont(fs, 0, g.fontname.c_str());
			setcolor(WaveColor(ColorAlpha2(WHITE, rat)));
			centerprintf(s.c_str());

			int w = g.uix * 0.6;
			int h = 150;
			int midy = g.uiy - h - 100;
			auto rt1 = MakeRectangle0(g.uix * 0.5 - w * 0.5, midy - h * 0.5, w, h);
			auto rt2 = MakeRectangle0(g.uix * 0.5 - w * 0.5, midy - h * 0.5, w * vol / 100, h);
			constexpr auto roundness = 0.2f;
			constexpr auto segments = 3;
			constexpr auto barOpa = 0.7;
			Color clr = ColorAlpha2(RainbowColor(0.9f, g.rainbow_speed), rat * barOpa);
			DrawRectangleRounded(rt2, roundness, segments, clr);
			DrawRectangleRoundedLines(rt1, roundness, segments, 8.0f, clr);
		}
		else if ("Giant" == style)
		{
			constexpr double opa = 0.5;
			int fs = g.uiy * 0.7;
			setfont(fs, 0, g.fontname.c_str());
			setcolor(WaveColor(ColorAlpha2(WHITE, rat * opa)));
			midprinty(sprintf2("%d%%%%", GetSystemVolume()), g.uiy / 2 - fs / 2);
		}
		else if ("Rainbow Giant" == style)
		{
			constexpr double opa = 0.5;
			Color clr1 = ColorAlpha2(RainbowColor(0.2f, g.rainbow_speed), rat * opa);
			Color clr2 = ColorAlpha2(RainbowColor(0.4f, g.rainbow_speed), rat * opa);
			auto r = GetSystemVolume() / 100.0f;
			DrawRectangleGradientH(0, g.uiy * (1.0 - r), g.uix, g.uiy * r,
				clr1, clr2);
			int fs = g.uiy * 0.7;
			setfont(fs, 0, g.fontname.c_str());
			setcolor(WaveColor(ColorAlpha2(WHITE, rat)));
			midprinty(sprintf2("%d%%%%", GetSystemVolume()), g.uiy / 2 - fs / 2);
		}
	}

	if (drawProcVolHud)
	{
		constexpr clock_t fadeTime = 200L;
		double rat = 1.0;

		if (procVolHud == "Temp")
		{
			if (clock() - g.lastProcVolAdjust < fadeTime)
				rat = Clamp(double(clock() - g.lastProcVolAdjust) / double(fadeTime), 0.0, 1.0);
			else if (clock() - g.lastProcVolAdjust > tempDuration - fadeTime)
				rat = Clamp(double(tempDuration - (clock() - g.lastProcVolAdjust)) / double(fadeTime), 0.0, 1.0);
		}

		DWORD pid = GetWindowPID(GetForegroundWindow());
		string style = MODCOMBOBOX("Volume", "Process Volume HUD Style");
		int vol = GetProcessVolume(pid, true);
		auto rt = GetWindowRect(GetForegroundWindow());

		if ("Bottom" == style)
		{
			constexpr int fs = 30;
			setfont(fs, 0, g.fontname.c_str());
			setcolor(WaveColor(ColorAlpha2(GOLD, rat)));
			midprinty_stroke(sprintf2("%s %d%%%%", DICTC("Process Volume"), vol), rt.bottom - fs * 2,
				(rt.left + rt.right) / 2);
		}
		else if ("Giant" == style)
		{
			constexpr double opa = 0.5;
			int fs = (rt.bottom - rt.top) * 0.5;
			setfont(fs, 0, g.fontname.c_str());
			setcolor(WaveColor(ColorAlpha2(WHITE, rat * opa)));
			midprinty(sprintf2("%d%%%%", vol), (rt.top + rt.bottom) / 2 - fs / 2,
				rt.left, rt.right);
		}
		else if ("Rainbow Giant" == style)
		{
			constexpr double opa = 0.5;
			Color clr1 = ColorAlpha2(RainbowColor(0.6f, g.rainbow_speed), rat * opa);
			Color clr2 = ColorAlpha2(RainbowColor(0.8f, g.rainbow_speed), rat * opa);
			auto r = vol / 100.0f;
			DrawRectangleGradientH(rt.left, rt.top + (rt.bottom - rt.top) * (1.0 - r),
				rt.right - rt.left, (rt.bottom - rt.top) * r,
				clr1, clr2);
			int fs = (rt.bottom - rt.top) * 0.5;
			setfont(fs, 0, g.fontname.c_str());
			setcolor(WaveColor(ColorAlpha2(WHITE, rat * opa)));
			midprinty(sprintf2("%d%%%%", vol), (rt.top + rt.bottom) / 2 - fs / 2,
				rt.left, rt.right);
		}
	}
}

//void DrawWelcomeSplash()
//{
//	const char* text = "Jackal Client " CURRENT_VERSION;
//
//	double rat0 = Clamp(double(clock() - g.app_start) / 2000L, 0.0, 1.0);
//	setfont(Lerp(120, 60, EaseOutCubic(rat0)), 0, g.fontname.c_str());
//	setcolor(Fade(RainbowColor(0.5f, 10.0f), 1.0 - rat0));
//	centerprintf_shadow(text);
//
//	setfont(Lerp(90, 50, EaseOutCubic(rat0)), 0, g.fontname.c_str());
//	setcolor(Fade(StepColor(GRAY, RainbowColor(0.9f, 10.0f), rat0), 1.0 - rat0));
//	midprinty_shadow("by: @Wormwaker", g.uiy * 0.7);
//}
void DrawStartupInterface()
{
	string style = GET_COMBOBOX(g.config.hud_config["Startup Interface"]).get<string>();

	if ("Off" == style)
		return;

	constexpr clock_t duration = 3000L;
	double rat0 = Clamp(double(clock() - g.app_start) / duration, 0.0, 1.0);

	if ("Zoom" == style)
	{

	}
}

void AppDraw()
{
	if (!g.loaded || g.quitting)
		return;

	//XCPT_L
	double rat = Clamp((clock() - g.lastOpenToggle) / 150.0, 0.0, 1.0);
	if (!g.option_open)
		rat = 1.0 - rat;

	if (g.quitting)
		rat = 0.6;

	BeginTextureMode(g.rt);
	ClearBackground(BLANK);

	bool hud_enabled = g.config.hud_config["Enabled"].get<bool>();

	if (g.on_screenshot)
	{
		if (IsTextureReady(g.tex_screenshot))
		{
			constexpr int tag_fs = 20;

			DrawTexture(g.tex_screenshot, 0, 0, RAYRGB(150, 150, 150));

			if (g.screenshot_dragging)
			{
				int left1 = min<int>(g.screenshot_pt1.x, g.mcx);
				int top1 = min<int>(g.screenshot_pt1.y, g.mcy);
				int right1 = max<int>(g.screenshot_pt1.x, g.mcx);
				int bottom1 = max<int>(g.screenshot_pt1.y, g.mcy);

				DrawTexturePro(g.tex_screenshot,
					MakeRectangle0(left1 + g.wnd_x, top1 + g.wnd_y, abs(g.mcx - g.screenshot_pt1.x - g.wnd_x), abs(g.mcy - g.screenshot_pt1.y - g.wnd_y)),
					MakeRectangle0(left1 + g.wnd_x, top1 + g.wnd_y, abs(g.mcx - g.screenshot_pt1.x - g.wnd_x), abs(g.mcy - g.screenshot_pt1.y - g.wnd_y)),
					{ 0.0f, 0.0f },
					0.0f,
					WHITE);

				DrawRectangleLinesEx(MakeRectangle0(left1 + g.wnd_x, top1 + g.wnd_y, abs(g.mcx - g.screenshot_pt1.x - g.wnd_x), abs(g.mcy - g.screenshot_pt1.y - g.wnd_y)),
					3.0f, RainbowColor(0.0f, g.rainbow_speed));


				setfont(tag_fs, 0, g.fontname.c_str());
				setcolor(WaveColor(RAYRGBA(150, 150, 150, 220)));
				if (g.mcx != left1 || g.mcy != top1)
					xyprintf_stroke(left1 - 1, top1 - tag_fs - 15, "(%d, %d)", left1, top1);
				if (g.mcx != right1 || g.mcy != bottom1)
					xyprintf_stroke(right1 - 50, bottom1 + 15, "(%d, %d)", right1, bottom1);
				if (g.mcx != left1 || g.mcy != bottom1)
					xyprintf_stroke(left1 + 1, bottom1 + 15, "(%d, %d)", left1, bottom1);
				if (g.mcx != right1 || g.mcy != top1)
					xyprintf_stroke(right1 - 50, top1 - tag_fs - 15, "(%d, %d)", right1, top1);

				setcolor(ORANGE);
				xyprintf_shadow(g.mcx + 5, g.mcy + 20 + tag_fs, "%d x %d", abs(g.mx - g.screenshot_pt1.x), abs(g.my - g.screenshot_pt1.y));

				if (abs(g.mx - g.screenshot_pt1.x) * abs(g.my - g.screenshot_pt1.y) == 0)
				{
					setcolor(WaveColor(SinColor(RED, YELLOW, 3000L)));
					xyprintf_shadow(g.mcx + 5, g.mcy + 30 + tag_fs * 2, "<!> Empty Area Causes Screenshot Failure");
				}

			}
			else {
				DrawLine(g.mcx, 0, g.mcx, g.uiy, SinColor(GREEN, RED, 10000L, 0.5f));
				DrawLine(0, g.mcy, g.uix, g.mcy, SinColor(GREEN, RED, 10000L, 0.5f));
			}



			static const vector<string> tips0
			{
				"[Esc/RMB] Cancel Screenshot",
				"[LMB] Start to Select",
				"[Ctrl+A] Use Fullscreen",
				"[Space] Toggle These Tips"
			};

			static const vector<string> tips_dragging
			{
				"[Esc] Cancel Screenshot",
				"[RMB] Reselect Area",
				"[Ctrl+A] Use Fullscreen",
				"[Space] Toggle These Tips"
			};

			setfont(tag_fs, 0, g.fontname.c_str());
			setcolor(WaveColor(WHITE));
			xyprintf(g.mcx + 5, g.mcy + 5, "(%d, %d)", g.mcx, g.mcy);

			if (g.screenshot_show_tips)
			{
				const auto& tips = (g.screenshot_dragging ? tips_dragging : tips0);

				constexpr int fs = 20;
				constexpr int v_add = 23;
				int left = 50;
				int top = g.uiy - tips.size() * v_add - 200;

				setfont(fs + 5, 0, g.fontname.c_str());
				setcolor(WHITE);
				xyprintf_shadow(left, top, "Screenshot Tool");

				int i{ 0 };
				setfont(fs, 0, g.fontname.c_str());
				if (g.screenshot_dragging)
					setcolor(SinColor(MAGENTA, RED, 5000L));
				else
					setcolor(SinColor(GOLD, GREEN, 10000L));

				for (auto const& tip : tips)
				{
					xyprintf(left, top + fs + 8 + v_add * i, tip.c_str());
					++i;
				}
			}

		}
	}
	else
	{

		/*setfont(50, 0, g.fontname.c_str());
		setcolor(RainbowColor());
		centerprintf("Jackal Client");

		return;*/
		/*setfont(20, 0, g.fontname.c_str());
		setcolor(RainbowColor());
		centerprintf(str(GetSystemVolume()).c_str());*/

		//if (!g.option_open)
#ifdef APP_DEBUG_VERSION
	//if (!g.option_open)
		{
			setfont(20, 0, g.fontname.c_str());
			setcolor(RainbowColor(0.0f, g.rainbow_speed));
			xyprintf_stroke(10, g.uiy - 25, (XorStringA("Jackal Client ") + string(CURRENT_VERSION) + XorStringA(" Debug Version.  by @Wormwaker")).c_str());
		}
#endif

		if (g.warning_ui && g.option_open)
		{
			DrawMalwareWarning();
		}
		else {

			if (hud_enabled)
			{

				/*if (g.config.hud_config["Show Font Extra Chars"].get<bool>())
					DrawExtraChars();*/

				if (ModuleOn(Watermark))
				{
					DrawWatermark(g.option_open);
				}
			}

			if (g.option_open || clock() - g.lastOpenToggle < OPTION_TOGGLE_ANIM_TIME)
			{
				setfont(20 * g.gui_scale, 0, g.fontname.c_str());
				setcolor(ColorAlpha2(RainbowColor(), rat));
				xyprintf_shadow(10, 10, "Jackal Client " CURRENT_VERSION);

				if (g.config.gui_config["Show FPS"].get<bool>())
				{
					setcolor(ColorAlpha2(WaveColor(GREEN), rat));
					xyprintf_shadow(280, 10, "%d FPS", GetFPS());
				}

				if (g.top_tab_i == 0)
				{
					if (g.search_open || clock() - g.lastSearchToggle < SEARCH_TOGGLE_ANIM_TIME)
					{
						DrawSearch();
					}

					if (g.module_option_open || clock() - g.lastModuleOptionToggle < MODULE_OPTION_ANIM_TIME)
					{
						if (g.module_option_top_tab == 0)
							DrawOptions("Modules", g.module_option_id);
						else
							DrawOptions(g.top_tab_cols[g.module_option_top_tab], AntiAFK);
					}

					if (!g.module_option_open)
					{
						if (!g.search_open)
						{

							setfont(g.module_fs, 0, g.fontname.c_str());

							if (g.library_open)
							{
								DrawLibraryModules(rat);
							}
							else {
								DrawNormalModules(rat);
							}
						}
					}
				}
				else if (g.top_tab_i == 1)
				{	//Config
					DrawOptions("Config");
				}
				else if (g.top_tab_i == 2)
				{	//GUI
					DrawOptions("GUI");
				}
				else if (g.top_tab_i == 3)
				{	//HUD
					DrawOptions("HUD");
				}
				else if (g.top_tab_i == 4)
				{	//HUD
					DrawOptions("About");
				}

				setfont(g.top_tab_fs, 0, g.fontname.c_str());
				//Draw Top Tabs
				for (int j = 0; j < g.top_tab_cols.size(); ++j)
				{
					Color color;

					if (j == g.top_tab_i)
						color = g.bg_select_color;
					else if (j == g.top_tab_hover)
						color = g.bg_hover_color;
					else
						color = g.bg_color;

					DrawRectangle(g.top_tab_lefts[j], 0, g.top_tab_widthes[j], g.top_tab_height, ColorAlpha2(color, rat));

					setcolor(ColorAlpha2(g.top_tab_color, rat));
					midprinty(g.top_tab_cols[j], g.top_tab_height * g.gui_scale / 2 - g.top_tab_fs * g.gui_scale / 2, g.top_tab_lefts[j], g.top_tab_lefts[j] + g.top_tab_widthes[j]);
				}

				if (g.tab_hover != -1 && g.module_hover != -1)
				{
					const auto& md = g.tabs[g.tab_cols[g.tab_hover]][g.module_hover];
					if (g.config.gui_config["Show Module Description"].get<bool>()
						&& !g.search_open
						&& module_descriptions.find(md) != module_descriptions.end())
					{
						setfont(g.modesc_fs * g.gui_scale, 0, g.fontname.c_str());
						setcolor(ColorAlpha2(StepColor(RainbowColor(0.8f, g.rainbow_speed), RAYWHITE, 0.9f), rat));
						int w = MeasureTextEx(g.font, GetModuleDescription(md).c_str(), g.modesc_fs * g.gui_scale, g_spacing).x;

						DrawRectangleRounded(MakeRectangle0(g.uix / 2 - w / 2, g.uiy - 205, w + 20, g.modesc_fs * g.gui_scale + 10),
							0.3f, 3,
							ColorAlpha2(StepColor(InvertedColor(RainbowColor(0.8f, g.rainbow_speed)), BLACK, 0.8f), rat));
						DrawRectangleRoundedLines(MakeRectangle0(g.uix / 2 - w / 2, g.uiy - 205, w + 20, g.modesc_fs * g.gui_scale + 10),
							0.3f, 3, 2.0f,
							ColorAlpha2(StepColor(RainbowColor(0.2f, g.rainbow_speed), WHITE, 0.8f), rat));

						midprinty_shadow(GetModuleDescription(md), g.uiy - 200);
					}
				}


				if (KEY_DOWN2(VK_RSHIFT))
				{
					setfont(30 * g.gui_scale, 0, g.fontname.c_str());
					setcolor(RainbowColor(g.rainbow_speed, 0.9f));
					midprinty_shadow("...", g.uiy * 0.8);
				}
			}
			else if (hud_enabled) {
				// hud
				if (ModuleOn(WindowESP))
				{
					RenderWindowESP();
				}

				if (ModuleOn(CrackPassword))
				{
					DrawCrackPasswordHUD();
				}

				if (ModuleOn(Volume))
				{
					DrawVolumeHUD();
				}

				if (ModuleOn(WindowHighlight))
				{

					DrawRectangleLinesEx(MakeRectangle(g.wndhilite_rect.left, g.wndhilite_rect.top, g.wndhilite_rect.right, g.wndhilite_rect.bottom),
						g.wndhilite_draw_exclamark ? 5.0f : 3.0f,
						//RainbowColor(0.0f, g.rainbow_speed) 
						g.wndhilite_color
					);

					if (g.wndhilite_draw_exclamark)
					{
						constexpr int fs = 100;
						setfont(fs, 0, g.fontname.c_str());
						setcolor(clock() / 200L % 2 == 0 ? YELLOW : RED);
						midprinty_shadow("!", (g.wndhilite_rect.top + g.wndhilite_rect.bottom) / 2.0f - fs / 2.0f,
							(g.wndhilite_rect.left + g.wndhilite_rect.right) / 2.0f);
					}
				}

				if (ModuleOn(MouseWatcher))
				{
					g.mouseWatch.RenderHUD();
				}

				if (ModuleOn(WindowMaster)
					//&& MODBOOL("Window Master", "Show Texts")
					)
				{
					string hud = MODCOMBOBOX("Window Master", "HUD");

					if (hud != "Off")
					{
						HWND hwnd = GetWindowMasterTarget();

						DWORD pid = GetWindowPID(hwnd);
						string procname = GetProcessName(pid);

						int wnd_w = GetWindowWidth(hwnd);
						int wnd_h = GetWindowHeight(hwnd);
						int wnd_bottom = 400;
						int wnd_right = 400;
						int box_w = 280, box_h = 0;

						wnd_bottom = GetWindowBottom(hwnd);
						wnd_right = GetWindowRight(hwnd);

						int fs = MODINT("Window Master", "HUD Font Size");
						int v_add = fs + MODINT("Window Master", "HUD Line Gap");

						int box_left0, box_top0;

						static vector<string> lines
						{
							"[Alt+F1] Privacy/U",
							"[Alt+F2] Kill Process",
							"[Alt+F3] Destroy",
							"[Alt+F5] Freeze/U",
							"[Alt+F6] Process Freeze/U",
							"[Alt+F7] Topmost/U",
							"[Alt+F8] Update",
							"[Alt+F9] LockUpdate",
							"[Alt+F10] Hide/Show",
							"[Alt+F11] EndSession(F)",
							"[Alt+F12] Sink",
						};

						for (const auto& line : lines)
						{
							box_w = max<int>(box_w,
								MeasureTextEx(g.font, DICTC(line), fs, 0).x + 20);
						}
						box_h = v_add * lines.size() + 50;

						box_left0 = wnd_right - box_w;

						if (box_left0 <= wnd_right - wnd_w * 0.4)
							box_left0 = wnd_right - wnd_w * 0.4;
						if (box_left0 + box_w >= g.uix - 30)
							box_left0 = g.uix - box_w - 30;
						if (box_left0 < 10)
							box_left0 = 10;

						box_top0 = wnd_bottom - box_h;

						if (box_top0 >= wnd_bottom - wnd_w * 0.4)
							box_top0 = wnd_bottom + 50;
						if (box_top0 + box_h >= g.uiy - 100)
							box_top0 = g.uiy - box_h - 100;
						if (box_top0 < 10)
							box_top0 = 10;

						if ("Follow" == hud)
						{
							if (g.mcx >= box_left0 && g.mcy >= box_top0
								&& g.mcx <= box_left0 + box_w && g.mcy <= box_top0 + box_h)
							{
								box_top0 = g.uiy - 50 - box_h;
								box_left0 = g.uix - 50 - box_w;

								if (g.mcx >= box_left0 && g.mcy >= box_top0
									&& g.mcx <= box_left0 + box_w && g.mcy <= box_top0 + box_h)
								{
									box_top0 = g.uiy - 50 - box_h;
									box_left0 = 50;
								}
							}
						}
						else if ("BottomRight" == hud)
						{
							box_top0 = g.uiy - 50 - box_h;
							box_left0 = g.uix - 50 - box_w;
						}
						else if ("BottomLeft" == hud)
						{
							box_top0 = g.uiy - 50 - box_h;
							box_left0 = 50;
						}

						static int box_left{ 0 }, box_top{ 0 };

						double speed = MODFLOAT("Window Master", "Easing Speed (0~1)");
						if (MODBOOL("Window Master", "Easing"))
						{	// 开启缓动
							box_left = box_left + (box_left0 - box_left) * Clamp(speed, 0.0, 1.0);
							box_top = box_top + (box_top0 - box_top) * Clamp(speed, 0.0, 1.0);
						}
						else {
							box_left = box_left0;
							box_top = box_top0;
						}

						string bgStyle = MODCOMBOBOX("Window Master", "HUD Background");
						string style = MODCOMBOBOX("Window Master", "HUD Color");

						// Draw Window Master HUD
						if ("Fancy" == bgStyle)
						{
							DrawRectangleRounded(MakeRectangle0(box_left - 18, box_top - 10, box_w + 5, box_h),
								0.1f, 4, RAYRGBA(4, 5, 10, SinValue(254, 240, 10000L)));
							DrawRectangleRoundedLines(MakeRectangle0(box_left - 18, box_top - 10, box_w + 5, box_h),
								0.1f, 4, 2.0f, StepColor(RainbowColor(0.4f, g.rainbow_speed), WHITE, 0.75f));
						}

						setfont(fs, 0, g.fontname.c_str());
						setcolor(StepColor(RainbowColor(0.0f, g.rainbow_speed), YELLOW, 0.5f));
						xyprintf_shadow(box_left, box_top, "%s (%d)", procname.c_str(), pid);

						for (int i = 0; i < lines.size(); i++)
						{
							if ("Simple" == bgStyle)
							{
								int w = min<int>(box_w, MeasureTextEx(g.font, DICTC(lines[i]), fs, g_spacing).x) + 20;
								DrawRectangleRounded(MakeRectangle0(box_left, box_top + v_add * (i + 1), w, fs + 3),
									0.1f, 2, RAYRGBA(2, 2, 2, SinValue(254, 240, 10000L)));
							}
							Color clr = GetNamedColor(lines[i], style, i, 0.06f, 0.12f);
							setcolor(clr);
							xyprintf_shadow(box_left, box_top + v_add * (i + 1), DICTC(lines[i]));
						}
					}
				}

				if (ModuleOn(WindowTags))
				{
					HWND hwnd = nullptr;
					if ((ModuleOn(KillAura) || ModuleOn(KillAuraLegit))
						&& ValidHandle(g.hwnd_killaura_target)
						&& ExistWindow(g.hwnd_killaura_target)
						&& MODBOOL("Window Tags", "Aura Target Highlight")
						)
					{
						hwnd = g.hwnd_killaura_target;

						RECT rt = GetWindowRect(hwnd);
						string title = GetWindowTitle(hwnd);
						string classname = GetWindowClassName(hwnd);
						DWORD pid = GetWindowPID(hwnd);

						constexpr Color box_color = RAYRGBA(2, 2, 2, 230);
						Color box_outline_color = RainbowColor(0.5f, g.rainbow_speed);

						constexpr int box_fs = 18;

						int box_text_w = max(MeasureTextEx(g.font, title.c_str(), box_fs, g_spacing).x,
							MeasureTextEx(g.font, classname.c_str(), box_fs, g_spacing).x
						);
						int box_left = Lerp<int>(g.mcx, (rt.left + rt.right) / 2.0f - box_text_w / 2.0f - 15, 0.8f);
						int box_top = Lerp<int>(g.mcy, rt.top + 40, 0.8f);

						int box_w = box_text_w + 60;
						int box_h = box_fs * 3.8;

						DrawRectangleRounded(MakeRectangle0(box_left, box_top, box_w, box_h),
							3.0f, 2, box_color);
						DrawRectangleLinesEx(MakeRectangle0(box_left, box_top, box_w, box_h),
							2.0f, box_outline_color);

						setfont(box_fs, 0, g.fontname.c_str());
						setcolor(WHITE);
						midprinty(title, box_top + 10, box_left, box_left + box_w);

						setcolor(RainbowColor(0.5f, g.rainbow_speed));
						midprinty(classname, box_top + 13 + box_fs, box_left, box_left + box_w);

						setcolor(WaveColor(LIGHTGRAY));
						midprinty(str(pid), box_top + 17 + box_fs * 2, box_left, box_left + box_w);
					}
					else {
						if (MODBOOL("Window Tags", "Aim Foreground Window Only"))
							hwnd = GetForegroundWindow();
						else
							hwnd = WindowFromPoint(g.mpt);

						if (hwnd)
						{
							constexpr int gap = 40;
							constexpr int fs = 18;

							RECT rt = GetWindowRect(hwnd);
							g.wndtags_dst_left = rt.left;
							g.wndtags_dst_top = rt.top;

							string title = GetWindowTitle(hwnd);
							string classname = GetWindowClassName(hwnd);

							bool draw_bg = MODBOOL("Window Tags", "Text Background");
							//bool draw_bg = true;
							Color bg_color = ColorAlpha2(RAYRGB(2, 2, 2), SinValue(0.5, 0.8, 4000L));

							if (draw_bg)
							{
								int w = MeasureTextEx(g.font, title.c_str(), fs, g_spacing).x + 20;
								DrawRectangle(g.wndtags_left + 10, g.wndtags_top + gap + fs - 2, w, fs, bg_color);
							}

							setfont(fs, 0, g.fontname.c_str());
							if (IsWindowEnabled(hwnd))
								setcolor(RainbowColor(0.0f, g.rainbow_speed));
							else
								setcolor(WaveColor(AQUA));

							xyprintf_shadow(g.wndtags_left + 20, g.wndtags_top + gap + fs, title.c_str());

							//static clock_t lastTitleOutput = clock();
							//if (clock() - lastTitleOutput > 1000)
							//{
							//	lastTitleOutput = clock();
							//	SetColor(14);
							//	cout << "TITLE: " << title << endl;
							//}

							if (draw_bg)
							{
								int w = MeasureTextEx(g.font, classname.c_str(), fs, g_spacing).x + 20;
								DrawRectangle(g.wndtags_left + 10, g.wndtags_top + gap + 2 * fs - 2, w, fs, bg_color);
							}

							if (IsWindowEnabled(hwnd))
								setcolor(ColorAlpha2(RainbowColor(0.5f, g.rainbow_speed), 0.7f));
							else
								setcolor(StepColor(BLUE, RainbowColor(0.5f, g.rainbow_speed), 0.3f));
							xyprintf_shadow(g.wndtags_left + 20, g.wndtags_top + gap + 2 * fs, classname.c_str());

							bool yes{ false };
							if (MODBOOL("Window Tags", "Show Process Info"))
							{
								yes = true;
								DWORD pid = GetWindowPID(hwnd);
								string procname = GetProcessName(pid);
								string s = sprintf2("%s (%d)", procname.c_str(), pid);

								if (draw_bg)
								{
									int w = MeasureTextEx(g.font, s.c_str(), fs, g_spacing).x + 20;
									DrawRectangle(g.wndtags_left + 10, g.wndtags_top + gap + 3 * fs - 2, w, fs, bg_color);
								}

								setcolor(RAYRGBA(190, 190, 190, 200));
								xyprintf_shadow(g.wndtags_left + 20, g.wndtags_top + gap + 3 * fs, s.c_str());
							}

							if (MODBOOL("Window Tags", "Show Parent Info"))
							{
								static DWORD pid = 0L;
								static string procname{ "" };
								static HWND lastHWND = nullptr;

								if (hwnd != lastHWND)
								{
									pid = GetProcessParentPID(GetWindowPID(hwnd));
									procname = GetProcessName(pid);
								}

								string s = sprintf2("PARENT: %s (%d)", procname.c_str(), pid);

								if (draw_bg)
								{
									int w = MeasureTextEx(g.font, s.c_str(), fs, g_spacing).x + 20;
									DrawRectangle(g.wndtags_left + 10, g.wndtags_top + gap + (yes ? 4 : 3) * fs - 2, w, fs, bg_color);
								}

								setcolor(RAYRGBA(140, 140, 140, 210));
								xyprintf_shadow(g.wndtags_left + 20, g.wndtags_top + gap + (yes ? 4 : 3) * fs, s.c_str());
							}
						}
					}


				}

				if (ModuleOn(ClipboardESP))
				{
					DrawClipboard();
				}

				if (ModuleOn(Ruler))
				{
					DrawRuler();
				}

				if (ModuleOn(Keystrokes))
				{
					DrawKeystrokes();
				}
				if (ModuleOn(Keystrokes2))
				{
					DrawKeystrokes2();
				}

				if (ModuleOn(Typewriter)
					&& MODBOOL("Typewriter", "HUD"))
				{
					DrawTypewriter();
				}

				if (ModuleOn(Spotlight)
					&&
					(g.spotlight_on || clock() - g.lastSpotlightToggle < 500L))
				{
					DrawSpotlight();
				}

				if (ModuleOn(Crosshair))
				{
					Color lineColor = Fade(GetNamedColor(sprintf2("%.1f", g.mcx / (float)g.mcy),
						MODCOMBOBOX("Crosshair", "Crosshair Line Color"),
						0),
						MODFLOAT("Crosshair", "Crosshair Line Opacity (0~1)"));

					if (MODBOOL("Crosshair", "Crosshair Line Wave Color"))
						lineColor = WaveColor(lineColor, 0.5f);

					if (!KEY_DOWN('C'))
					{
						int thick = MODINT("Crosshair", "Crosshair Line Width");
						string type = MODCOMBOBOX("Crosshair", "Crosshair Line Combination Type");

						if ("Plus" == type || "Plus & X" == type)
						{
							DrawLineEx(MakeVector2(0.0f, g.mcy), MakeVector2(g.uix, g.mcy), thick, lineColor);
							DrawLineEx(MakeVector2(g.mcx, 0.0f), MakeVector2(g.mcx, g.uiy), thick, lineColor);
						}
						if ("Plus" == type);
						else if ("X" == type || "Plus & X" == type)
						{
							// 计算鼠标位置到屏幕边缘的距离
							float leftDistance = g.mcx; // 到左边缘的距离
							float rightDistance = g.uix - g.mcx; // 到右边缘的距离
							float topDistance = g.mcy; // 到上边缘的距离
							float bottomDistance = g.uiy - g.mcy; // 到下边缘的距离

							// 计算 X 形线的长度，以最小的边距为准
							float length = std::max({ leftDistance, rightDistance, topDistance, bottomDistance });

							// 鼠标坐标为中心点
							float centerX = g.mcx;
							float centerY = g.mcy;

							// 绘制 X 型线
							DrawLineEx(MakeVector2(centerX - length, centerY - length), MakeVector2(centerX + length, centerY + length), thick, lineColor); // 从左上到右下
							DrawLineEx(MakeVector2(centerX + length, centerY - length), MakeVector2(centerX - length, centerY + length), thick, lineColor); // 从右上到左下
						}
						else if ("Horizontal" == type)
						{
							DrawLineEx(MakeVector2(0.0f, g.mcy), MakeVector2(g.uix, g.mcy), thick, lineColor);
						}
						else if ("Vertical" == type)
						{
							DrawLineEx(MakeVector2(g.mcx, 0.0f), MakeVector2(g.mcx, g.uiy), thick, lineColor);
						}
					}

					if (!g.crosshair_advance)
					{
						double rat = Clamp((clock() - g.lastCrosshairToggle) / 3000.0, 0.0, 1.0);
						setfont(30, 0, g.fontname.c_str());
						setcolor(Fade(WaveColor(RainbowColor(0.3f, g.rainbow_speed)), 1.0 - rat));
						midprinty_shadow("[RAlt] Advanced Mode", g.uiy * 0.7);
					}
					else {
						int fs = MODINT("Crosshair", "Coord Font Size");
						string scoord = sprintf2("(%d, %d)", g.mcx, g.mcy);

						setfont(fs, 0, g.fontname.c_str());
						setcolor(Fade(StepColor(RainbowColor(0.5f, g.rainbow_speed), WHITE, 0.5f), 0.7f));

						int tw = MeasureTextEx(g.font, scoord.c_str(), fs, g_spacing).x;

						int x = g.mcx + 20;
						int y = g.mcy + 20;
						if (x >= g.uix - g.wnd_x - tw - 15)
							x = g.uix - g.wnd_x - tw - 16;
						if (y >= g.uiy - g.wnd_y - fs - 5)
							y = g.uiy - g.wnd_y - fs - 6;
						xyprintf_shadow(x, y, scoord.c_str());

						static const int top = g.uiy * 0.7;
						int ins_fs = MODINT("Crosshair", "HUD Font Size");
						int ins_v_add = ins_fs = MODINT("Crosshair", "HUD Line Gap");

						static const vector<string> ins_texts
						{
							"[RAlt] Close Advanced Mode",
							"[C] Copy RGB Color",
							"[Ctrl+C] Copy Mouse Coordinate",
							"[Arrows] Move Mouse Slightly",
						};

						if (MODBOOL("Crosshair", "Advance Mode Show HUD"))
						{
							float opa = MODFLOAT("Crosshair", "HUD Opacity (0~1)");
							setfont(ins_fs, 0, g.fontname.c_str());

							if (MyIsWindowFocused() || MODBOOL("Crosshair", "Advance Mode Allow No Focus"))
							{
								for (int i = 0; i < ins_texts.size(); ++i)
								{
									setcolor(ColorAlpha2(StepColor(RainbowColor(fmod(0.7f + i * 0.06f, 1.0f), g.rainbow_speed), WHITE, 0.5f), opa));
									xyprintf_shadow(10, top + ins_v_add * i, ins_texts[i].c_str());
								}
							}
							else {
								setcolor(ColorAlpha2(StepColor(RainbowColor(0.7f, g.rainbow_speed), RED, 0.5f), opa));
								xyprintf_shadow(10, top, "No Focus");
							}

						}
					}
				}
				else {
					//SetMouseCursor(MOUSE_CURSOR_ARROW);
				}

				if (ModuleOn(SecurityESP))
				{
					size_t av_cnt = g.securitySit.antivirus.size();
					size_t mal_cnt = g.securitySit.malware.size();

					constexpr int fs = 20;
					constexpr int v_add = 25;
					int h = v_add * (av_cnt + mal_cnt + 2);
					constexpr double f = 0.81;
					static int left = g.uix * f;

					int top = g.uiy / 2 - h / 2;

					setfont(fs, 0, g.fontname.c_str());
					if (mal_cnt > 0)
					{
						setcolor(WaveColor(LIGHTRED));
						xyprintf_shadow(left, top, "-! MALWARE (%zu) !-", mal_cnt);
					}
					else {
						setcolor(WaveColor(LIGHTRED));
						xyprintf_shadow(left, top, "NO MALWARE");
					}

					for (int i = 0; i < g.securitySit.malware.size(); ++i)
					{
						if (fabs(g.mcy - (top + v_add * (i + 1))) < fs * 0.8
							&& fabs(g.mcx - left - g.uix * (1.0 - f) / 2.0) < g.uix * (1.0 - f) / 2.0)
						{
							setcolor(StepColor(WaveColor(BLUE), RainbowColor(fmod(0.5f + 0.04f * i, 1.0f), g.rainbow_speed), 0.2f));
							xyprintf_shadow(left, top + v_add * (i + 1), "%s",
								procProfiles[g.securitySit.malware[i].name].desc.c_str());
						}
						else
						{
							setcolor(StepColor(WaveColor(RED), RainbowColor(fmod(0.5f + 0.04f * i, 1.0f), g.rainbow_speed), 0.3f));
							xyprintf_shadow(left, top + v_add * (i + 1), "%s (%d)",
								g.securitySit.malware[i].name.c_str(),
								g.securitySit.malware[i].pid);
						}
					}

					if (av_cnt > 0)
					{
						setcolor(WaveColor(LIGHTRED));
						xyprintf_shadow(left, top + (mal_cnt + 2) * v_add, "-$ ANTIVIRUS (%zu) $-", av_cnt);
					}
					else {
						setcolor(WaveColor(LIGHTRED));
						xyprintf_shadow(left, top + (mal_cnt + 2) * v_add, "NO ANTIVIRUS");
					}

					for (int i = 0; i < g.securitySit.antivirus.size(); ++i)
					{

						if (fabs(g.mcy - (top + (mal_cnt + 2) * v_add + v_add * (i + 1))) < fs * 0.8
							&& fabs(g.mcx - left - g.uix * (1.0 - f) / 2.0) < g.uix * (1.0 - f) / 2.0)
						{
							setcolor(StepColor(WaveColor(GREEN), RainbowColor(fmod(0.5f + 0.04f * i, 1.0f), g.rainbow_speed), 0.2f));
							xyprintf_shadow(left, top + (mal_cnt + 2) * v_add + v_add * (i + 1), "%s",
								get<2>(g.securitySit.antivirus[i]).c_str());
						}
						else
						{
							setcolor(StepColor(WaveColor(GOLD), RainbowColor(fmod(0.5f + 0.04f * i, 1.0f), g.rainbow_speed), 0.3f));
							xyprintf_shadow(left, top + (mal_cnt + 2) * v_add + v_add * (i + 1), "%s (%d)",
								get<0>(g.securitySit.antivirus[i]).c_str(),
								get<1>(g.securitySit.antivirus[i])
								//procProfiles[get<0>(g.securitySit.antivirus[i])].rank
							);
						}
					}
				}

				if (ModuleOn(PPLESP) && ModuleOn(RTCore64))
				{
					static int left = 90;
					constexpr int fs = 20;
					constexpr int v_add = 23;
					int top = g.uiy / 2 - (g.pplSit.ppl.size() + 4) / 2.0 * v_add;

					setfont(fs, 0, g.fontname.c_str());
					setcolor(SinColor(GREEN, GOLD, 60000L));
					xyprintf_shadow(left, top, "PPL LIST");

					int i = 0;
					for (auto& p : g.pplSit.ppl)
					{
						string s = sprintf2("%s  (%d)", p.name.c_str(), p.pid);
						int w = MeasureTextEx(g.font, s.c_str(), fs, 0).x + 10;

						DrawRectangle(left, top + v_add * (2 + i), w, fs, RAYRGBA(2, 2, 2, SinValue(150, 190, 8000L)));

						setcolor(StepColor(RainbowColor(fmod(0.05 * i, 1.0), g.rainbow_speed), RED, SinValue(0.5f, 0.85f, 10000L)));
						xyprintf_shadow(left, top + v_add * (2 + i), s.c_str());
						++i;
					}

					setcolor(WaveColor(BLUE));
					if (g.pplSit.ppl.empty())
						xyprintf_shadow(left, top + v_add * (g.pplSit.ppl.size() + 3), "(NOTHING)");
					else
						xyprintf_shadow(left, top + v_add * (g.pplSit.ppl.size() + 3), "%zu  PROCESSES", g.pplSit.ppl.size());
				}

			}

			if (hud_enabled)
			{
				g.notify.Render();
				//HWND hwnd = FindWindowA("Windows.UI.Core.CoreWindow", nullptr/*"新通知"*/);
				//if (IsWindowVisible(hwnd))
				//{
				//	RECT rt = GetWindowRect(hwnd);
				//	DrawRectangleLines(rt.left, rt.top, rt.right - rt.left, rt.bottom - rt.top, RED);
				//}

				if (ModuleOn(TimeDisplay)
					&& (!g.option_open || MODBOOL("Time Display", "Show In Menu")))
				{
					DrawTimeDisplay();
				}

				/*if (g.config.hud_config["Welcome Splash"].get<bool>()
					&& clock() - g.app_start < 2000L)
				{
					DrawWelcomeSplash();
				}*/
				//DrawStartupInterface();
			}
		}
	}

	EndTextureMode();

	if (hud_enabled && g.config.hud_config.at("Show Arraylist").get<bool>())
	{
		DrawArraylistHUD();
	}

	if (!hud_enabled
		|| !g.config.hud_config.at("Show Arraylist").get<bool>()
		|| "Rainbow++" != GET_COMBOBOX(g.config.hud_config["Arraylist Color"]).get<string>()
		&& ("Rainbow++" != MODCOMBOBOX("Vape", "Color")
			|| !ModuleOn(Vape))
		)
	{
		BeginTextureMode(g.rt_rainbow);
		ClearBackground(BLANK);
		EndTextureMode();
	}

	ApplyMotionBlur();
	ApplyScreenShader();

	BeginDrawing();
	ClearBackground(BLANK);

	if (ModuleOn(Night))
	{
		string when = MODCOMBOBOX("Night", "When");

		if (when == "Always" || when == "Menu On" && g.option_open || when == "Menu Off" && !g.option_open)
		{
			float rattmp = 0.0f;
			if (when == "Always")
				rattmp = 1.0f;
			else
				rattmp = rat;

			DrawTexturePro(g.rt_mask.texture, MakeRectangle0(0, 0, g.uix, -g.uiy),
				MakeRectangle0(0, 0, g.uix, g.uiy), { 0.0f, 0.0f }, 0.0f,
				ColorAlpha2(WHITE,
					MODFLOAT("Night", "Mask Alpha Rate") * rattmp));
		}
	}
	if (ModuleOn(Background))
	{
		string style = MODCOMBOBOX("Background", "Filter Type");
		string when = MODCOMBOBOX("Background", "When to Apply Filter");

		if (style != "Off"
			&& (when == "Always"
				|| when == "Menu On" && g.option_open
				|| when == "Menu Off" && !g.option_open))
		{
			Color clr = GetNamedColor("Background", style, 0);
			clr = ColorAlpha2(ColorAlpha(clr, MODFLOAT("Background", "Lightness (0~1)")), MODFLOAT("Background", "Filter Opacity (0~1)"));

			float rattmp = 0.0f;
			if (when == "Always")
				rattmp = 1.0f;
			else
				rattmp = rat;

			DrawTexturePro(g.rt_mask.texture, MakeRectangle0(0, 0, g.uix, -g.uiy),
				MakeRectangle0(0, 0, g.uix, g.uiy), { 0.0f, 0.0f }, 0.0f,
				clr);
		}
	}

#define RAINBOW_ENHANCE_SPEED_COEFF	0.003
	if (/*g.config.hud_config["Rainbow Modules"].get<bool>()
	&& g.config.hud_config["Rainbow Enhance"].get<bool>()*/
		"Rainbow++" == GET_COMBOBOX(g.config.hud_config["Arraylist Color"]).get<string>()
		|| ModuleOn(Vape) && "Rainbow++" == MODCOMBOBOX("Vape", "Color")
		)
	{
		BeginTextureMode(g.rt);

		static int timeLoc = GetShaderLocation(g.shaders["rainbow.fs"], "time");
		float timeVal = (clock() - g.app_start) / 1000.0f;
		SetShaderValue(g.shaders["rainbow.fs"], timeLoc, &timeVal, SHADER_UNIFORM_FLOAT);

		static int speedLoc = GetShaderLocation(g.shaders["rainbow.fs"], "speed");
		float speed = g.rainbow_speed * RAINBOW_ENHANCE_SPEED_COEFF;
		SetShaderValue(g.shaders["rainbow.fs"], speedLoc, &speed, SHADER_UNIFORM_FLOAT);

		BeginShaderMode(g.shaders["rainbow.fs"]);

		DrawTexturePro(g.rt_rainbow.texture, MakeRectangle0(0, 0, g.uix, -g.uiy),
			MakeRectangle0(0, 0, g.uix, g.uiy), { 0.0f, 0.0f }, 0.0f,
			WHITE);

		EndShaderMode();

		EndTextureMode();
	}

	if (ModuleOn(Shaders) && !g.on_screenshot
		&& g.config.module_config["Shader"].contains("Style"))
	{
		string filename = GetCurrentShaderFilename();
		auto& shader = g.shaders[filename];

		if (ShaderNeedTime(filename))
		{
			int timeLoc = GetShaderLocation(shader, "time");
			float timeVal = (clock() - g.lastShaderToggle) / 1000.0;
			SetShaderValue(shader, timeLoc, &timeVal, SHADER_UNIFORM_FLOAT);
		}
		if (ShaderNeedResolution(filename))
		{
			int resLoc = GetShaderLocation(shader, "resolution");
			float resVal[2] = { g.uix, g.uiy };
			SetShaderValue(shader, resLoc, resVal, SHADER_UNIFORM_VEC2);
		}
		BeginShaderMode(shader);
	}

	DrawTexturePro(g.rt.texture, MakeRectangle0(0, 0, g.uix, -g.uiy),
		MakeRectangle0(0, 0, g.uix, g.uiy), { 0.0f, 0.0f }, 0.0f, WHITE);

	if (ModuleOn(Shaders) && !g.on_screenshot)
	{
		EndShaderMode();
	}

	EndDrawing();

	//XCPT_R
}


void DisplayClientCharacterDrawing()
{
	SetColor(Choice({ 2, 3, 10, 11, 14, 15 }));

	string style = Choice({ "ANSI Regular", "ANSI Shadow", "Colossal", "Roman", "Sub-Zero", "3D-ASCII", "Larry 3D" });

	// Generated by https://www.perfcode.com/tools/generator/ascii-art
	if ("Roman" == style)
	{

		printf(R"(
  oooo       .o.         .oooooo.   oooo    oooo       .o.       ooooo                       
   `888      .888.       d8P'  `Y8b  `888   .8P'       .888.      `888'                       
    888     .8"888.     888           888  d8'        .8"888.      888                        
    888    .8' `888.    888           88888[         .8' `888.     888                        
    888   .88ooo8888.   888           888`88b.      .88ooo8888.    888                        
    888  .8'     `888.  `88b    ooo   888  `88b.   .8'     `888.   888       o                
.o. 88P o88o     o8888o  `Y8bood8P'  o888o  o888o o88o     o8888o o888ooooood8                
`Y888P                                                                                        
                                                                                              
                                                                                              
                      .oooooo.   ooooo        ooooo oooooooooooo ooooo      ooo ooooooooooooo 
                     d8P'  `Y8b  `888'        `888' `888'     `8 `888b.     `8' 8'   888   `8 
                    888           888          888   888          8 `88b.    8       888      
                    888           888          888   888oooo8     8   `88b.  8       888      
                    888           888          888   888    "     8     `88b.8       888      
                    `88b    ooo   888       o  888   888       o  8       `888       888      
                     `Y8bood8P'  o888ooooood8 o888o o888ooooood8 o8o        `8      o888o     
	)");
	}
	else if ("Sub-Zero" == style)
	{
		printf(R"(
   __     ______     ______     __  __     ______     __                 
  /\ \   /\  __ \   /\  ___\   /\ \/ /    /\  __ \   /\ \                
 _\_\ \  \ \  __ \  \ \ \____  \ \  _"-.  \ \  __ \  \ \ \____           
/\_____\  \ \_\ \_\  \ \_____\  \ \_\ \_\  \ \_\ \_\  \ \_____\          
\/_____/   \/_/\/_/   \/_____/   \/_/\/_/   \/_/\/_/   \/_____/          
                                                                         
             ______     __         __     ______     __   __     ______  
            /\  ___\   /\ \       /\ \   /\  ___\   /\ "-.\ \   /\__  _\ 
            \ \ \____  \ \ \____  \ \ \  \ \  __\   \ \ \-.  \  \/_/\ \/ 
             \ \_____\  \ \_____\  \ \_\  \ \_____\  \ \_\\"\_\    \ \_\ 
              \/_____/   \/_____/   \/_/   \/_____/   \/_/ \/_/     \/_/ 
                                                                         
)");
	}
	else if ("3D-ASCII" == style)
	{
		printf(R"(
    ___  ________  ________  ___  __    ________  ___                   
   |\  \|\   __  \|\   ____\|\  \|\  \ |\   __  \|\  \                  
   \ \  \ \  \|\  \ \  \___|\ \  \/  /|\ \  \|\  \ \  \                 
 __ \ \  \ \   __  \ \  \    \ \   ___  \ \   __  \ \  \                
|\  \\_\  \ \  \ \  \ \  \____\ \  \\ \  \ \  \ \  \ \  \____           
\ \________\ \__\ \__\ \_______\ \__\\ \__\ \__\ \__\ \_______\         
 \|________|\|__|\|__|\|_______|\|__| \|__|\|__|\|__|\|_______|         
                                                                        
                                                                        
                                                                        
              ________  ___       ___  _______   ________   _________   
             |\   ____\|\  \     |\  \|\  ___ \ |\   ___  \|\___   ___\ 
             \ \  \___|\ \  \    \ \  \ \   __/|\ \  \\ \  \|___ \  \_| 
              \ \  \    \ \  \    \ \  \ \  \_|/_\ \  \\ \  \   \ \  \  
               \ \  \____\ \  \____\ \  \ \  \_|\ \ \  \\ \  \   \ \  \ 
                \ \_______\ \_______\ \__\ \_______\ \__\\ \__\   \ \__\
                 \|_______|\|_______|\|__|\|_______|\|__| \|__|    \|__|
                                                                        
                                                                        
                                                                        
)");
	}
	else if ("Larry 3D" == style)
	{
		printf(R"(
 _____  ______  ____     __  __   ______  __                     
/\___ \/\  _  \/\  _`\  /\ \/\ \ /\  _  \/\ \                    
\/__/\ \ \ \L\ \ \ \/\_\\ \ \/'/'\ \ \L\ \ \ \                   
   _\ \ \ \  __ \ \ \/_/_\ \ , <  \ \  __ \ \ \  __              
  /\ \_\ \ \ \/\ \ \ \L\ \\ \ \\`\ \ \ \/\ \ \ \L\ \             
  \ \____/\ \_\ \_\ \____/ \ \_\ \_\\ \_\ \_\ \____/             
   \/___/  \/_/\/_/\/___/   \/_/\/_/ \/_/\/_/\/___/              
                                                                 
                                                                 
               ____     __     ______   ____    __  __  ______   
              /\  _`\  /\ \   /\__  _\ /\  _`\ /\ \/\ \/\__  _\  
              \ \ \/\_\\ \ \  \/_/\ \/ \ \ \L\_\ \ `\\ \/_/\ \/  
               \ \ \/_/_\ \ \  __\ \ \  \ \  _\L\ \ , ` \ \ \ \  
                \ \ \L\ \\ \ \L\ \\_\ \__\ \ \L\ \ \ \`\ \ \ \ \ 
                 \ \____/ \ \____//\_____\\ \____/\ \_\ \_\ \ \_\
                  \/___/   \/___/ \/_____/ \/___/  \/_/\/_/  \/_/
                                                                 
                                                                 
)");
	}
	else if ("ANSI Regular" == style)
	{
		printf(R"(
     ██  █████   ██████ ██   ██  █████  ██                    
     ██ ██   ██ ██      ██  ██  ██   ██ ██                    
     ██ ███████ ██      █████   ███████ ██                    
██   ██ ██   ██ ██      ██  ██  ██   ██ ██                    
 █████  ██   ██  ██████ ██   ██ ██   ██ ███████               
                                                              
                                                              
                 ██████ ██      ██ ███████ ███    ██ ████████ 
                ██      ██      ██ ██      ████   ██    ██    
                ██      ██      ██ █████   ██ ██  ██    ██    
                ██      ██      ██ ██      ██  ██ ██    ██    
                 ██████ ███████ ██ ███████ ██   ████    ██    
                                                              
                                                              
)");
	}
	else if ("ANSI Shadow" == style)
	{
		printf(R"(
     ██╗ █████╗  ██████╗██╗  ██╗ █████╗ ██╗                   
     ██║██╔══██╗██╔════╝██║ ██╔╝██╔══██╗██║                   
     ██║███████║██║     █████╔╝ ███████║██║                   
██   ██║██╔══██║██║     ██╔═██╗ ██╔══██║██║                   
╚█████╔╝██║  ██║╚██████╗██║  ██╗██║  ██║███████╗              
 ╚════╝ ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝              
                                                              
                 ██████╗██╗     ██╗███████╗███╗   ██╗████████╗
                ██╔════╝██║     ██║██╔════╝████╗  ██║╚══██╔══╝
                ██║     ██║     ██║█████╗  ██╔██╗ ██║   ██║   
                ██║     ██║     ██║██╔══╝  ██║╚██╗██║   ██║   
                ╚██████╗███████╗██║███████╗██║ ╚████║   ██║   
                 ╚═════╝╚══════╝╚═╝╚══════╝╚═╝  ╚═══╝   ╚═╝   
                                                              
)");
	}
	else if ("Colossal" == style)
	{
		printf(R"(
  888888        d8888  .d8888b.  888    d8P         d8888 888                       
    "88b       d88888 d88P  Y88b 888   d8P         d88888 888                       
     888      d88P888 888    888 888  d8P         d88P888 888                       
     888     d88P 888 888        888d88K         d88P 888 888                       
     888    d88P  888 888        8888888b       d88P  888 888                       
     888   d88P   888 888    888 888  Y88b     d88P   888 888                       
     88P  d8888888888 Y88b  d88P 888   Y88b   d8888888888 888                       
     888 d88P     888  "Y8888P"  888    Y88b d88P     888 88888888                  
   .d88P                                                                            
 .d88P"                                                                             
888P"                                                                               
                      .d8888b.  888      8888888 8888888888 888b    888 88888888888 
                     d88P  Y88b 888        888   888        8888b   888     888     
                     888    888 888        888   888        88888b  888     888     
                     888        888        888   8888888    888Y88b 888     888     
                     888        888        888   888        888 Y88b888     888     
                     888    888 888        888   888        888  Y88888     888     
                     Y88b  d88P 888        888   888        888   Y8888     888     
                      "Y8888P"  88888888 8888888 8888888888 888    Y888     888     
                                                                                    
                                                                                    
                                                                                    
)");
	}
}