#include <vector>
#include <string>
#include <unordered_map>
#include <Windows.h>

using namespace std;

#include "nlohmann/json.hpp"
using json = nlohmann::json;

#include "jc_moduleid.h"
#include "XorString.h"
#include "jc_default_settings.h"

string KeybindString(const vector<int>& keys)
{
	if (keys.empty())
		return "[NONE]";

	if (keys.size() == 1 && keys[0] == 0)
		return "[NONE]";

	string res{ "[" };
	int i{ 0 };
	for (int key : keys)
	{
		if (i)
			res += "+";
		res += GetKeyName(key, false);
		++i;
	}

	res += "]";

	return res;
}

// 2024/12/5: 由于编译器堆空间不足，不得不将其单拎出来作为一个编译单元。
// 
// 2024/12/10 由于两千多行的默认配置成功让编译器内存爆炸，
// Jackal Client 默认配置单独放到 DefaultSettings.dll 里面

unordered_map<ModuleID, string> module_extra_info_dict
{
	{AntiDebug, "Reaction"},
	{UACBypass, "Method"},
	{Uninstaller, "Victim"},
	{MachineLock, "Exit Condition"},
	{Shutdown, "Method"},
	{PrivateWindow, "Mode"},
	{Topmost, "Operation"},
	{AntiBrowser, "Measures"},
	{AntiWebpage, "Operation"},
	{AntiPopups, "Measures"},
	{AntiTopmost, "Violence Policy"},
	{Tasklist, "Style"},
	{Injector, "Method"},
	{GenshinImpact, "Enable Action"},
	{Run, "Target"},
	{FileDelete, "Mode"},
	{FolderClear, "Filter"},
	{TempClear, "Filter"},
	{DiskMissing, "Missing Drives"},
	{RootProgram, "Policy"},
	{Speedhack, "Speed"},
	{NoCmd, "Method"},
	{NoTaskmgr, "Method"},
	{NoRegedit, "Method"},
	{OnlineTime, "Source"},
	{IPAddress, "Method"},
	{WeatherInfo, "City"},
	{LiveStream, "Chatter Display"},
	{Crosshair, "Crosshair Line Combination Type"},
	{MotionBlur, "Apply Area"},
	{Background, "Filter Type"},
	{TimeDisplay, "Half Hour Notification"},
	{AntiRickroll, "Mode"},
	{AutoClicker, "Click Method"},
	{BridgeAssist, "Mode"},
	{ChatTranslate, "Dest Language"},
	{ChatRestruct, "Pattern"},
	{ClipboardTweaks, "Letter Changes"},
	{MouseWatcher, "Movement Check Mode"},
	{Typewriter, "Source"},
	{KeyDisabler, "Mode"},
	{Volume, "Notify Type"},
	{Musics, "Style"},
	{Screenshot, "Mode"},
	{Shaders, "Style"},
	{Vape, "Logo"},
	{Kill360, "360 Process Detection Method"},
	{Title, "Title Text Mode"},
	{AutoTitle, "Mode"},
	{TitleChanger, "Pattern"},
	{CloseEnhance, "Method"},
	{KeySound, "Alloc Mode"},
	{Speaker, "Spoken Text Mode"},
	{AutoSpeak, "Main Mode"},
	{TimeManager, "Mode"},
	{AutoFocus, "Mode"},
	{BetterAnimation, "Custom Style"},
	{CrackPassword, "Multithread"},
	{Gamma, "Alpha"},
	{PrivacySpy, "Custom Scan Directory"},
	{AutoStart, "Method"},
	{ListTasks, "Style"},
	{BiliFans, "Notify Mode"},
	{BiliFeed, "Style"},
	{BiliHot, "Interface"},
	{BiliNotifier, "Mode"},
	{BiliProfile, "User ID"},
	{BiliComponents, "User ID"},
	{BiliVideo, "AID/BID/Link"},
	{BiliVideoCover, "Mode"},
	{GUIBlur, "Style"},
	{SuperCmd, "Mode"},
	{Mute, "Mode"},
	{BetterLyrics, "Display Mode"},
	{Ambience, "Weather"},
	{SystemProxy, "Proxy Server"},
	{DialogPhysics, "Constant Mode"},
	{LyricsPhysics, "Replace Animation"},
	{TargetESP, "Target"},
};