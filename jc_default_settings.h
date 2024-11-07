// encoding=utf-8
#pragma once

#define COMBOBOX(defval, ...)	\
							{{"Options", __VA_ARGS__}, {"Selected", defval}}



#define MAKE_COMBOBOX(name, defval, ...)	\
						{name,						\
							{		\
								{"Options", __VA_ARGS__},\
								{"Selected", defval}		\
							}\
						}

//#define MAKE_COMBOBOX(name, options, defval)		\
//					{name, json::parse("{\"Options\":"s + unquote(#options) + ",\"Selected\":"s + #defval + "}")}
					//{name, {{"Options", options}, {"Selected", defval}}}

#define IS_COMBOBOX(js) (js.is_object() && js.contains("Options") && js.contains("Selected"))
//(js.size() == 2)
//(js.size() == 2 && js[0].items()[0] == "Options" && js[1].items()[0] == "Selected")

#define GET_COMBOBOX(js) (js["Selected"])

#define SET_COMBOBOX(js, value) do { js["Selected"] = value; } while(0)

#define GET_COMBOBOX_OPTIONS(js) (js["Options"])

#define IS_KEYBIND(js)	(js.is_object() && js.contains("Keybind"))

#define GET_KEYBIND_RAW(js)  (js["Keybind"].get<vector<int>>())

string KeybindString(const vector<int>& keys)
{
	if (keys.empty())
		return "[NONE]";

	string res{ "[" };
	int i{ 0 };
	for (int key : keys)
	{
		if (i)
			res += "+";
		res += GetKeyName(key);
		++i;
	}

	res += "]";

	return res;
}

#define GET_KEYBIND(js)	KeybindString(js["Keybind"].get<vector<int>>())

#define SET_KEYBIND(js, keys) do {	js["Keybind"] = keys;	} while (0)

unordered_map<string, json> config_default_jsons
{
	{"Modules",
		{
			//{"Anti Capture",
			//	{
			//		//{"Console Does", true},
			//		//{"Black Mode", false}
			//	}
			//},

			{"Anti Close",
				{
					{"Notify Close Message", true}
				}
			},

			{"Anti Debug",
				{
					{"Active Defense", true},
					{"Check Cooldown", 500},
					{"Related File Detection", true},

					/*{"Reaction",
						{
							{"Options", {"Warn", "Exit", "Self Destruct", "Extinction"}},
							{"Selected", "Exit"}
						}
					},*/

    				MAKE_COMBOBOX("Reaction", "Exit",
						{"Warn", "Exit", "Self Destruct", "Extinction"})

					/*{"Immediate Exit", true},
					{"Self Destruct (EXE)", false},
					{"Extinction (Entire Client)", false}*/
				}
			},

			{"Anti Inject",
				{
					{"Async", true},
					{"Check Cooldown", 2000U},
					{"Exclude Verified", false},
					{"Monitor Modules", true},
					{"Auto Unload", true},
					{"Exit If Unload Failed", false},
				}
			},

			{"Anti Intercept",
				{
					{"Keep Alive", false}
				}
			},

			{"Anti MouseHook",
				{
					{"bind", {{"Keybind", {VK_RMENU, 'M'}}}}
				}
			},

			{"Anti Taskkill",
				{
					{"Check Tskill.exe", false},
					{"Only Threat For Client", true},
					{"Notify Success", true},
					{"Notify Failure", true},
				}
			},

			{"Admin",
				{
					{"Exit After Run", true},
					{"bind", {{"Keybind", {VK_RMENU, 'A'}}}},
				}
			},

			{"System",
				{
					{"Use NSudo", false},
					{"Exit After Run", true},
				}
			},

			{"Trusted Installer",
				{
					{"Use NSudo", false},
					{"Exit After Run", false},
				}
			},

			{"UAC Bypass",
				{
					{"Exit After Run", true},

					MAKE_COMBOBOX("Method", "Computerdefaults Legit",
						{"Computerdefaults", 
						"Computerdefaults Legit", 
						"Fodhelper", 
						"Fodhelper Legit",
						"Cmstp",
						"Sdclt",
						"Sdclt Legit",
						"Slui",
						"Slui Legit",
						}),

					{"Legit Transparent Window", true},
					{"bind", {{"Keybind", {VK_RMENU, 'U'}}}}
				}
			},

			{"Auto UAC", 
				{
					{"Notify", true},
					{"Quit After Click", true},
					{"Mouse Move Acceleration", 0.3f},
				}
			},

			{"Crack Password",
				{
					{"Async", true},
					{"Multithread", true},
					{"Memorize Prev Password", true},
					{"HUD", true},
					{"HUD Show Current Password Attempt", true},
					{"Use Strong Password Dictionary", true},
					{"Try Birthdays", true},
					{"Notify Password", true},
					{"Notify Speed", true},

					MAKE_COMBOBOX("Account Lockout Threshold Policy",
						"Query",
						{"Ignore", "Safe", "Query"}),

					{"Threshold Setting Confirmation MessageBox Timeout (ms)", 20000},

					MAKE_COMBOBOX("Threshold Setting Default Option", "Cancel",
						{"Yes", "No", "Cancel"}),
				}
			},

			{"Set Password",
				{
					{"Async", true},
					{"Async Single Instance", true},
					{"Just Clear", true},
					{"Or Custom Password:", "123456"},
					{"Auto Fill Username", true},
					{"Or Custom Username:", "Administrator"},
					{"Close Menu", true}
				}
			},

			{"Reg Monitor",
				{
					MAKE_COMBOBOX("HKEY", "HKEY_LOCAL_MACHINE",
						{
                            "HKEY_LOCAL_MACHINE", "HKEY_CURRENT_USER", "HKEY_CLASSES_ROOT", "HKEY_CURRENT_CONFIG", "HKEY_USERS"
						}),

					{"Path", ""s},
					{"Item Filter RegExp", ""s},
					{"Key Filter RegExp", ""s},
					{"Value Filter RegExp", ""s},
					{"Cooldown (ms)", 1000U},
				}
			},

			{"List Hijacks",
				{
					{"Async", true},
					{"Auto Console", true},

					MAKE_COMBOBOX("Notify Mode", "Console Output",
						{"Console Output", "Notify"})
				}
			},

			{"Kill Hijacks",
				{
					{"Async", true},
				}
			},

			{"Uninstaller",
				{
					MAKE_COMBOBOX("Victim", "None",
						{"None", "360", "Huorong"}),
					{"Transparent Window", true},
					{"Notify Steps", true},
				}
			},

			{"Interceptor",
				{
					
				}
			},

#define MAKE_GATEKEEPER_ITEM(name, defval)	\
				MAKE_COMBOBOX(name, defval, {"Allow", "Query", "Deny"})

			{"Gatekeeper",
				{
					{"Use Loader to Inject (Suggested)", true},
					{"Check Working Cooldown", 5000U},
					{"Disable When Quit", true},
					//{"Confirmation Popups", true},
					MAKE_GATEKEEPER_ITEM("Admin", "Allow"),
					MAKE_GATEKEEPER_ITEM("Shutdown", "Query"),
					MAKE_GATEKEEPER_ITEM("Reboot", "Query"),
					MAKE_GATEKEEPER_ITEM("Logoff", "Query"),
					MAKE_GATEKEEPER_ITEM("Win + L", "Query"),
					MAKE_GATEKEEPER_ITEM("Ctrl + Shift + Esc", "Allow"),
					MAKE_GATEKEEPER_ITEM("Ctrl + Alt + Del", "Query"),
					MAKE_GATEKEEPER_ITEM("Sticky Keys", "Query"),
					MAKE_GATEKEEPER_ITEM("Filter Keys", "Query"),
					MAKE_GATEKEEPER_ITEM("Magnifier", "Query"),
					MAKE_GATEKEEPER_ITEM("Narrator", "Query"),
					MAKE_GATEKEEPER_ITEM("Projection Menu", "Query"),
					MAKE_GATEKEEPER_ITEM("Accessibility", "Query"),
				}
			},

			{"No Firewall",
				{
					{"Masquerade", true},
					{"Domain", true},
					{"Private", true},
					{"Public", true},
				}
			},

			{"Privileges",
				{
					{"Notify", true},
					{"bind", {{"Keybind", {VK_RMENU, 'P'}}}}
				}
			},

			{ "Shutdown",
				{
					{"Force", false},
					{"Power Off", true},
				
					MAKE_COMBOBOX("Method", "WINAPI",
						{"Command", "WINAPI", "NTAPI"})

					/*{"Method",
						{
							{"Options", {"Command", "WINAPI", "NTAPI"}},
							{"Selected", "WINAPI"}
						}
					}*/
				}
			},
			//{"Use Private API (Violence)", false}
			//MAKE_COMBOBOX("Method", ({"Command", "WINAPI", "NTAPI"}), "WINAPI")}

			{ "Reboot",
				{
					{"Force", false}
				}
			},

			{ "Logoff",
				{
					{"Force", false}
				}
			},

			{ "Crash",
				{
					{"Custom Win32 Error Code", 5},
				}
			},

			{"Window ESP",
				{
					{"Box Alpha", 0.5f},
					{"Update Cooldown", 250U},
					{"Exclude Invisible", true},
					{"Exclude Foreground", true},
					{"Exclude Pointed", true},
				}
			},

			{"Window Highlight",
				{
					{"Easing", true},
					{"Easing Speed (0~1)", 0.2f},
					{"Only Foreground", false},
					{"Aura Target Highlight", true},
					{"Endangered Excla Mark", true},
				}
			},

			{"Window Master",
				{
					{"HUD Font Size", 20},
					{"HUD Line Gap", 5},
					
					MAKE_COMBOBOX("HUD Background", "Fancy",
					{"Off", "Simple", "Fancy"}),

					{"Easing", true},
					{"Easing Speed (0~1)", 0.1},	// 缓动速率

					MAKE_COMBOBOX("HUD Color", "Rainbow",
					{"White", "Green", "Magenta", "Aqua-Pink", "Green-Red", "Rainbow", "Colorful",}),

					MAKE_COMBOBOX("Target", "Foreground",
						{"Foreground", "PointAt"}),

					MAKE_COMBOBOX("Privacy Mode", "Invisible (>= Win10)",
						{"Black", "Invisible (>= Win10)"}),

					/*{"Show Texts", true}*/
					MAKE_COMBOBOX("HUD", "Follow",
						{"Off", "Follow", "BottomRight", "BottomLeft"}),
				}
			},

			{"Private Window",
				{
					{"Async", true},

					MAKE_COMBOBOX("Mode", "Invisible (>= Win10)",
						{"Black", "Invisible (>= Win10)"}),

					{"QQ NT", true},
					{"WeChat", true},
					{"Edge", true},
				}
			},

			{"Anti Browser",
				{
					{"Async", true},

					MAKE_COMBOBOX("Filter", "OpenUrl Browser", 
						{"Any Browser", "OpenUrl Browser", "OpenHttpUrl Browser",
						"OpenUrl Process", "OpenHttpUrl Process",
						}),

					MAKE_COMBOBOX("Measures", "Kill",
						{"Warn", "Kill", "SilentKill", "KillParent", "KillFamily"}),

					{"Check Cooldown", 1000U},
				}
			},

			{"Anti Popups",
				{
					MAKE_COMBOBOX("Ad Process Policy", "Warn & AutoKill",
						{"Ignore", "Warn", "AutoKill", "Warn & AutoKill"}),

					/*MAKE_COMBOBOX("Confirm", "Off",
						{"Off", "HUD", "HUDTimeout", "Msgbox", "MsgboxTimeout", }),*/

					MAKE_COMBOBOX("BottomRight Judge Policy", "Size and Title or Blacklist",
						{
							"Size",
							"Title",
							"Size and Title",
							"Size or Blacklist",
							"Title or Blacklist",
							"Size and Title or Blacklist",
						}),

					MAKE_COMBOBOX("Measures", "Chain",
						{"Chain", "Close", "Destroy", "EndSession", "KillProcess"}
						),

					{"Ad Window Title Keywords List", "每日;今日;新闻;优选;精选;推荐;热搜;软件管家;贴士;小助手;奖励;公测;一刀;贪玩;上线;News;Free Trial"},
					{"Chain Allow LegitMouseClick", true},
					{"Check Cooldown", 250U},
					{"Exclude Maximized", true},
					{"Exclude MessageBox", true},
					{"Exclude SystemProcess", true},
					{"Exclude WinToast", true},
					{"Use Additional Blacklist", true},
				}
			},

			{"Anti Topmost",
				{
					{"Only Check Foreground", false},
					{"Auto Untopmost", true},
					{"Auto Bottom", true},
					
					MAKE_COMBOBOX("Violence Policy", "Off",
						{"Off", "Close Window", "Kill Process"}
					),

					{"Notify Kill", true},

					/*{"Violence Policy",
						{
							{"Options", {"Off", "Close Window", "Kill Process"}},
							{"Selected", "Off"}
						}
					},*/

				/*	{"Auto Kill", false},
					{"Kill Process Instead of Window", true},*/
				}
			},

			{"Close Enhance",
				{
					{"Exclude Self", true},
				}
			},

			{"Tasklist",
				{
					{"Async", true},
					{"Auto Console", true},
					{"Use Record", false},

					MAKE_COMBOBOX("Style", "Normal",
						 {"Vanilla", "Normal", "Command Lines"})

					/*{"Style",
						{
							{"Options", {"Vanilla", "Normal", "Command Lines"}},
							{"Selected", "Normal"}
						}
					}*/
					/*{"Use Vanilla", false},
					{"Display Command Line", true},*/
				}
			},

			{"List Modules",
				{
					{"Async", true},
					{"Auto Console", true},
					{"PID (0 for self)", 0},
					{"Verify", true},
				}
			},

			{ "List Trays",
				{
					{"Async", true},
					{"Auto Console", true},
				}
			},

			{"List Services",
				{
					{"Async", true},
					{"Auto Console", true},
					MAKE_COMBOBOX("Style", "Normal",
					{"Vanilla", "Vanilla (Only Win32)", "Vanilla (Only Drivers)", "Vanilla Custom", "Normal", "Simple"}),
					{"Vanilla Enum Custom Command", "sc query" },
				}
			},

			{ "List Drivers",
				{
					{"Async", true},
					{"Auto Console", true},
					{"Verify", true},
				}
			},

			{"Injector",
				{
					MAKE_COMBOBOX("Method", "NtCreateThreadEx",
						{
							"CreateRemoteThread",
							"NtCreateThreadEx",
							"QueueUserAPC",
						}),

					MAKE_COMBOBOX("Execution Policy", "Async",
						{"Sync", "Async", "Async NoWait"}),

					MAKE_COMBOBOX("Operation", "InjectDll",
							{"InjectDll", "UninjectDll"}),

					MAKE_COMBOBOX("Process Architecture", "Both",
						{"Both", "x64", "x86"}),

					{"Exclude Self", true},
					{"Process Name (Empty For Any)", "cmd.exe"},
					{"Process Id (Zero For Any)", 0},
					{"Dll Path", ""},
					{"Max Process Count", 8},
				}
			},

			{"Remote Run",
				{
					MAKE_COMBOBOX("Execution Policy", "Async",
						{"Sync", "Async", "Async NoWait"}),

					MAKE_COMBOBOX("Process Architecture", "Both",
						{"Both", "x64", "x86"}),

					{"Exclude Self", true},
					{"Process Name (Empty For Any)", "cmd.exe"},
					{"Process Id (Zero For Any)", 0},
					{"Command Line", "cmd.exe /c echo Jackal On Crack! && pause"},
					{"Max Process Count", 8},
				}
			},


			{"Speedhack",
				{
					{"Process Name (Empty For Any)", "javaw.exe"},
					{"Process Id (Zero For Any)", 0},
					{"Speed", 0.5f},
					{"Anti Unload", false},
					{ "Speed Change Step", 0.1f},
					{ "Speed Up Keybind", {{"Keybind", {VK_RMENU, 187}}} },		// RAlt + =
					{ "Speed Down Keybind", {{"Keybind", {VK_RMENU, 189}}} },	// RAlt + -
					/*{" Pause/Resume Keybind",},*/
				}
			},

			{"Genshin Impact",
				{
					MAKE_COMBOBOX("Enable Action",
						"Install & Start",
						{"Fake", "Start", "Install & Start"}
						),

					{"Auto Boot", false},	// 开机启动原神
					{"Boot Sound", true},	// 是否开启专属启动音效

					MAKE_COMBOBOX("Disable Action",
						"Kill Process",
					{"Close Window", "Kill Process", "Close Window & Uninstall", "Kill Process & Uninstall"}
					)
				}
			},

			{"Window Tags",
				{
					{"Easing", true},
					{"Easing Speed (0~1)", 0.2f},
					{"Aim Foreground Window Only", false},
					{"Aura Target Highlight", true},
					{"Show Process Info", true},
					{"Show Parent Info", true},
					{"Text Background", true},
				}
			},

			{"Max Aura",
				{
					{"Cooldown (ms)", 400U},
				}
			},

			{ "Min Aura",
				{
					{"Cooldown (ms)", 400U},
				}
			},

			{ "Freeze Aura",
				{
					{"Cooldown (ms)", 400U},
				}
			},

			{ "Uncross Aura",
				{
					{"Cooldown (ms)", 400U},
				}
			},

			{ "Ruin Aura",
				{
					{"Cooldown (ms)", 400U},
				}
			},

			{"Aim Assist",
				{
					{"Smoothness", 0.8f},
				}
			},

			{"Kill Aura Legit",
				{
					{"Smoothness", 0.8f}
				}
			},

			{"Trigger Bot",
				{
					{"Cooldown (ms)", 400U},
					{"Notify", true}
				}
			},

			{"Ruler",
				{
					{"Show Size", true},			
					{"Mark Sides", true},
					{"Measure Distances", true}
				}
			},

			{"Process Kill",
				{
					{"Kill Name", "1.exe"},
					{"Kill PID",  0},
					{"Notify Kill", true},
					{"Disable After Attempt", false},
					{"Keep", true},
				}
			},

			{"Process Freeze",
				{
					{"Freeze Name", "1.exe"},
					{"Freeze PID",  0},
					{"Notify Freeze", true},
					{"Disable After Attempt", false},
					{"Keep", true},
				}
			},

			{"Run",
				{
					{"Target", "cmd.exe"},
					{"Parameters", ""},
					{"Directory", ""},
					{"Hidden", false},
					{"Watch", false},
				}
			},

			{"Open URL",
				{
					{"URL", string(XorStringA("https://space.bilibili.com/3494361276877525"))},
				}
			},

			{"Cmd",
				{
					{"Run As Admin", false}
				}
			},

			{"PowerShell",
				{
					{"Run As Admin", false}
				}
			},

			{"Perfmon",
				{
					{"Parameters", "/reS"},
				}
			},

			{"PPL Butcher",
				{
					{"Only Kill Invalid", false},
				}
			},

			{"File Delete",
				{
					{"Path", "null"},
					{"Keep", false},
					{"Notify", true},
					MAKE_COMBOBOX("Mode", "Normal",
						{"Normal", "Command", "Supreme"})
				}	
			},

			{ "File Create",
				{
					{"Path", ""},
					{"Keep", false},
					{"Notify", true},
					{"UNC Path", true},
					{"Create Folder", false},
					{"Readonly", false},
					{"Hidden", false},
					{"System", false}
				}
			},

			{ "File Monitor",
				{
					{"Folder", "D:\\"},
					//{"Filter", "*.*"},
					{"Console Output", true},
					{"Log (Client)", false},
					{"Log (Seperate)", false},
					{"Notify", false},
					{"Monitor Create", true},
					{"Monitor Delete", true},
					{"Monitor Modify", true},
					{"Monitor Rename", true},
					{"Exclude Client Files", true},
					{"Exclude Recent", true},
					{"Exclude Prefetch", true},
					{"Ext Blacklist", ".log;.pf;.tmp;.db;.qqxlog;.db-wal;.lck"},
					{"Cooldown", 100U},
				}
			},
				
			{ "Folder Clear",
				{
					{"Async", true},
					{"Keep", false},
					{"Confirm Once", true},
					{"Path", "null"},
					{"Filter", "*.*"},
					{"Notify Errors", true},
					{"Notify Result", true},
				}
			},

			{"Temp Clear",
				{
					{"Async", true},
					{"Keep", false},
					{"Filter", "*.*"},
					{"Notify Errors", true},
					{"Notify Result", true},
				}
			},

			{"Recycler Clear",
				{
					{"Async", true},
					{"Sound", true},
					{"Confirm", true},
					{"Progress Bar", true},
				}
			},

			{"Root Program",
				{
					MAKE_COMBOBOX("Policy", "Monitor",
						{"Monitor", "Prevention", "Settle"}),
					MAKE_COMBOBOX("Monitor Reaction", "Notify Delete",
						{"Notify", "Delete", "Notify Delete"}),
					MAKE_COMBOBOX("Prevention Format", "Both",
						{".exe", ".com", "Both"}),
					MAKE_COMBOBOX("Settle Program", "Cmd",
						{"Cmd", "Client", "PowerShell", "Custom"}),
					MAKE_COMBOBOX("Settle Format", ".exe",
						{".exe", ".com"}),
					{"Settle Custom Source Path", ""},
				}
			},

			{"Privacy Spy",
				{
					{"Async", true},
					{"Auto Console", true},
					{"Custom Scan Directory", "D:\\"},
					{"Skip Readonly Files", true},
					{"Skip Hidden Files", true},
					{"Skip System Files", true},
					{"IDCard Valid Year Min", 1914},
					{"IDCard Valid Year Max", 2024},
					{"IDCard Strict Validify", true},
					{"Person Name Character Max Count", 3},
					{"Filter File Extensions", true},
					{"Included File Extensions", ".txt;.doc;.ppt;.xls;.docx;.pptx;.xlsx;.wps;.zip;.rar;.7z;.gz;.c;.cpp;.java;.cs;.exe;.jpg;.png;.bmp"},
				}
			},

			{"Self Uninstall",
				{
					MAKE_COMBOBOX("Batch Terminal", "Hide",
						{"Show", "Minimize", "Hide"})
				}
			},

			{"Self Backup",
				{
					{"Async", true}
				}
			},

			{ "Self Restore",
				{
					{"Async", true}
				}
			},

			{"Auto Restore",
				{
					{"Only Backup Folder", true}	//若为 false， 程序将在启动时备份并更新清单
				}
			},

			{"No Cmd",
				{
					MAKE_COMBOBOX("Method", "WINAPI", {"WINAPI", "Reg"}),
					{"Keep", false}
				}
			},

			{"No Taskmgr",
				{
					MAKE_COMBOBOX("Method", "WINAPI", {"WINAPI", "Reg"}),
					{"Keep", false}
				}
			},

			{"No Regedit",
				{
					MAKE_COMBOBOX("Method", "WINAPI", {"WINAPI", "Reg"}),
					{"Keep", false}
				}
			},

			{"No UAC",
				{
					{"Bypass Explorer Notify", true},	// 绕过资源管理器通知
					{"Highest Level When UAC Enabled", false},	//当UAC启用时，是否开到最高级别（默认是第二级别）
					{"Keep", false },		//防止被外界手动关闭
					{"Keep Mode Notify Action", true}
				}
			},

			{"IP Address",
				{
					{"Async", true},

					MAKE_COMBOBOX("Method", "WinSocket",
						{"WinSocket", "Command"}),

					MAKE_COMBOBOX("External IP Address Source URL", "https://api.ip.sb/ip",
						{
						"https://api.ip.sb/ip",
						"http://www.ipchicken.com",
						"http://whatismyipaddress.com",
						"http://api.ipify.org"
						}),

					{"Connect Timeout (s)", 5L},
					{"Output Verbose Connection Info", false},
					{"Query External IP", true},
					{"Query External IP Position", true},
					{"Use HTTPS When Query Position", true},
					{"Output Local IP Details", true},
				}
			},

			{"IP Horror", 
				{
					{"Async", true},
					{"Copy to Clipboard", true},
					{"Target IP Address", "127.0.0.1"},
				}
			},

			{"Wall Check",
				{
					{"Website", "www.youtube.com"},
					{"Connect Timeout (s)", 10L}
				}
			},

			{"Weather",
				{
					{"Async", true},
					{"Use Custom QWeather ApiKey", false},
					{"Custom QWeather ApiKey", ""},
					MAKE_COMBOBOX("City", "Auto Locate",
						{"Auto Locate", "Custom"}),

					{"Custom City", "北京市"},
					{"Connect Timeout (s)", 10L},
				}
			},

			{"Live Stream",
				{
					{"Room ID", 31196635},
					{"Max Allowed Chatter Delay (s)", 300},	

					MAKE_COMBOBOX("Chatter Color", "White",
						{"White", "Red", "Green", "Blue", "Aqua-Pink", "Green-Red", "Colorful", "Rainbow"}),

					MAKE_COMBOBOX("Chatter Display", "Chatter Classical",
						{"Off", "Chatter Classical", "Notify"}),

					MAKE_COMBOBOX("Chatter Taboo Filter", "Block",
						{"Off", "Block", "Filtered", "Replace (Unsafe)"}),

					MAKE_COMBOBOX("Chatter Remote Execution (Riskful)", "Disabled",
						{"Disabled", "Wormwake"}),

					{"Chatter Remote Execution Username Whitelist (Sep with Semicolon)", "Wormwaker;Worrnwaker"},
					{"Chatter Remote Execution Display", false},
					{"Chatter Remote Execution Notify", true},
				}
			},

			{"QQ Inspect",
				{
					{"Async", true},
					{"Auto Console", true},
					{"Close Menu", true},
					{"Notify Basic Info", false},
					{"Notify Others", false},
				}
			},

			{"ScreenSaver",
				{
					{"Use Custom Program", false},
					{"Your Custom Program", "null"},
					{"Display On Client", true},
					{"Disable ForceTopmost", true},
					{"Disable Night", true},
					{"Disable Lightness", false},
					{"Close Client Menu", true},
					{"Mute", true},
					{"Key Locker (Press END to quit)", false},
					{"Mouse Disabler (Press END to quit)", false},
				}
			},

			{"No ScreenSaver",
				{
					{"Check Process", true},
					{"Kill Process", false}
				}
			},

			{"Crosshair",
				{
					{"Advance Mode Show HUD", true},
					{"Advance Mode Hotkey", {{"Keybind", {VK_LMENU, VK_RMENU}}}},
					{"Advance Mode Allow No Focus", false},
					{"Crosshair Line Width", 2},
					{"Crosshair Line Opacity (0~1)", 0.9f},

					MAKE_COMBOBOX("Crosshair Line Color", "Rainbow",
						{"White", "Red", "Green", "Blue", "Magenta", "Colorful", "Rainbow"}),

					{"Crosshair Line Wave Color", true},

					MAKE_COMBOBOX("Crosshair Line Combination Type", "Plus", 
						{"Horizontal", "Vertical", "Plus", "X", "Plus & X"}
						),
					{"Coord Font Size", 30},
					{"HUD Font Size", 25},
					{"HUD Line Gap", 5},
					{"HUD Opacity (0~1)", 0.9f}
				}
			},

			{"Keystrokes",
				{
					{"X Rate", 0.01f},
					{"Y Rate", 0.01f},
					{"Box Size", 54},
					{"Font Size", 24},
					{"Space", true},
					{"Shift", true},
					{"Mouse Buttons", true},
					{"Show CPS", true},
					{"Give Way to Mouse", true},
				}
			},

			{"Keystrokes2",
				{
					//{"Instant Tips", true},
					{"Y Rate", 0.8f},
					{"Easing Speed (0~1)", 0.1f},
					{"Key Display Max Count", 16U},
					{"Bigger Pressed", true},
					{"Give Way to Mouse", true},
					{"Show Number Below", true},
					{"Number Display Recent", true},
					{"Number Color Show Recent", true},
				}
			},

			{"Clipboard ESP",
				{
					{"Font Size", 20},
					{"Line Gap", 3},
					{"Max Lines Shown", 25},
					{"Text Background", true},
					{"Show Format", true},
					{"Show Line Number", true},	
					{"Show Text Stats", true}
				}
			},

			{"Motion Blur",
				{
					MAKE_COMBOBOX("Apply Area", "Screen",
						{"Client Only", "Screen"}),

					{"Update Cooldown", 40},
					{"Frame Count", 3},
				}
			},

			{"Background",
				{
					MAKE_COMBOBOX("Filter Type", "Off",
						{"Off", "Red", "Green", "Blue", "Rainbow"}),

					{"Filter Opacity (0~1)", 0.5f},
					{"Lightness (0~1)", 0.5f},

					MAKE_COMBOBOX("When to Apply Filter", "Menu On",
						{"Always", "Menu On", "Menu Off"}),

					{"Screen Compensation", false},

					MAKE_COMBOBOX("When to Apply Screen Compensation", "Always",
						{"Always", "Menu On", "Menu Off"}),

					{"Screen Compensation Cooldown (ms)", 250U},
				}
			},

			{"Time Display",
				{
					{"Font Size", 35},
					{"X Rate", 0.05f},
					{"Y Rate", 0.8f},
					{"Half Hour Notify", true},
					{"Half Hour Highlight", true},
					{"Rainbow Color", true},
					{"Whiter", true},
					{"Wave Color", true},
					{"Transparent", true},
					{"Text Background", true},
					{"Show In Menu", true}
				}
			},

			{"Totem",
				{
					{"Transparent Color Key (For Cutout)", "16;16;16"},
					{"Transparent Color Alpha", 0},

					MAKE_COMBOBOX("Chatter New Advancement", "Only First Time",
					{"Off", "Only First Time", "Always"}),
				}
			},

			{"Auto Totem",
				{
					{"Gatekeeper Deny", true},
					{"Gatekeeper Deny After Query", true},
					{"AntiClose Defend Success", true},
					{"AntiTaskkill Defend Success", true},
					{"AntiDebug Defend Success", true},
					{"AntiInject Defend Success", true},
				}
			},

			{"Watermark",
				{
					{"Size", 80},
					{"Menu Off Alpha", 0.3f},
					{"Menu On Alpha", 0.2f},
				}
			},

			{"Lightness",
				{
					{"Alpha", 255},
					{"Set Once", false},
					{"Disable When Quit", true},
				}
			},

			{"Night",
				{
					{"Mask Alpha Rate", 0.6f},
					MAKE_COMBOBOX("When", "Menu On",
						{"Menu On", "Menu Off", "Always"})
				}
			},

			{"Anti AFK",
				{
					{"Move Cooldown", 2000L},
					{"Move Duration", 3000L},
				}
			},

			{"Anti Rickroll",
				{
					{"Async", true},
					{"Check Cooldown", 200U},

					MAKE_COMBOBOX("Mode", "Simple",
						{"Simple", "Violence"}),

					{"Notify", true},
					{"Simple Allow Kill Process", false},
				}
			},

			{"Auto Clicker",
				{
					{"CPS", 20U},
					{"Gap Random Deviation (%%)", 10U},
					{"Click Internal Gap", 5U},

					MAKE_COMBOBOX("Target Key", "Left Button",
						{"Left Button", 
						 "Right Button",
						 "Middle Button",
						 "Custom"}),

					{"Custom Key Code", 0},

					{"Keep Target Window Active", true},

					MAKE_COMBOBOX("Hotkey", "Side Button 1",
						{"Side Button 1",
						 "Side Button 2",
						 "Grave ~",
						 "Q", "R", "Z", "X", "C", "V"
						}),

					MAKE_COMBOBOX("Trigger Mode", "Hotkey Toggle",
					{"Hotkey Toggle", "Hotkey Hold", 
					//"TargetKey Toggle", "TargetKey Hold",
					//"Additional Clicks"
					}),

					MAKE_COMBOBOX("Click Point Setting", "Manual",
						{"Manual", "Locked", "Shake", "Shake Locked"}),

					MAKE_COMBOBOX("Click Method", "Window Message",
						{"Simulation", "Window Message"}),

					//{"TargetKey Hold Threshould Time", 700U},
					//{"Additional Click Duration (ms)", 1000U},
					{"Stop When Menu On", true},

				}
			},

			{"Bridge Assist",
				{
					{"Check Window", true},

					MAKE_COMBOBOX("Trigger Condition", "S & D",
						{"S", "S & A", "S & D"}),

					{"BPS", 2.30f},
					
					MAKE_COMBOBOX("Mode", "Sneak",
					{"Simple", "Sneak"}),

					{"Sneak Reshift Gap", 50U},
					{"Right Internal Gap", 10U},
					{"Shift Internal Gap", 100U},
					{"Place Sound", true},
				}
			},

			{"Chat Ask",
				{
					{"Async", true},
					{"Use EnvVar ApiKey: DASHSCOPE_API_KEY", true},
					{"Your Custom ApiKey", "null"},
					{"Remove Markdown Format", true},
				} 
			},

			{"Chat Translate",
				{
					MAKE_COMBOBOX("Dest Language", "Chinese-English",
						{"English", "Chinese", "Chinese-English", "Classical Chinese",
						"Japanese", "French", "German"}),
}
			},

			{"Chat Restruct",
				{
					MAKE_COMBOBOX("Pattern", "AddSpace",
						{"AddSpace", "Reverse", "Shuffle",
						"ExpandSentence", "Abbreviate", "MachineTranslative",
						"Stammer", "Childlike", "Spoken", "Emojis"
						})
				}
			},

			{"Clipboard Tweaks",
				{
					/*MAKE_COMBOBOX("Change", "Off",
						{
							"Off", 
							"Remove Markdown Format", 
							"Remove Numbers",
							"Remove URL",
							"Remove URL Parameters",
							"Upper Case",
							"Lower Case",
							"Annoying Case",
							"Fancy Letters",
							"Add Spaces",
							"Reverse",
							"Shuffle",
							
						}),*/
					{"Remove Markdown", false},
					{"Remove Numbers", false},
					{"Remove URL", false},
					{"Remove URL Arguments", true},
					{"Taboo Super Filter", false},
					//{"URL Deep Scan", false},

					MAKE_COMBOBOX("Letter Changes", "Off",
					{"Off", "Upper Case", "Lower Case", "Annoying Case", "Fancy Letters"}),
					{"Add Spaces", false},

					MAKE_COMBOBOX("Punctuation Changes", "Off",
					{"Off", "Remove", "To English", "To Chinese"}),

					/*{"Tip URL", true},
					{"Tip Social Numbers", true},*/
				}
			},

			{"Mouse Teleport",
				{
					{"Edge Teleport", true}
				}
			},

			{"Mouse Watcher",
				{
					MAKE_COMBOBOX("Movement Check", "Ignore",
						{"Ignore", "Warn", "Warn & Restore", "Restore"}),

					MAKE_COMBOBOX("Movement Check Mode", "Simple",
						{"Simple", "Strict"}),

					MAKE_COMBOBOX("HUD", "Fancy",
						{"Off", "Simple", "Fancy"}),

					MAKE_COMBOBOX("HUD Color", "White",
						{"White", "Green", "Magenta", "Aqua-Pink", "Green-Red", "Rainbow", "Colorful",}),

					{"HUD Font Size", 20},
					{"HUD Line Gap", 5},
					{"HUD X Rate", 0.01f},
					{"HUD Y Rate", 0.44f},

					{"Sample Cooldown", 10U},
					{"Acceleration Threshold", 60.0f},
				}
			},

		/*	{"Mouse Disabler",
				{
					{"End Key Quit", true}
				} 
			},*/

			{"Snap Tap",
				{
					{"A & D", true},
					{"W & S", true},
					{"Left & Right Arrows", true},
                    {"Up & Down Arrows", true},
					{"Custom Keys", false},
					{"Custom Key Pairs (e.g. Z&X;J&K)", ""},
				}
			},

			{"Toggle Key",
				{
					{"Left Mouse Button", false},
					{"Right Mouse Button", false},
					{"A, W, S, D", false},
					{"A, W, S, D Opposite Stop", true},
					{"Alpha Keys", false},
					{"Num Keys", false},
					{"Left Modifier Keys", false},
					{"Arrow Keys", false},
					{"Arrow Keys Opposite Stop", true},
					{"Additional Custom Keys (Code Sep with Semicolon)", ""}
				}
			},

			{"Typewriter",
				{
					{"HUD", true},

					{"Focus Window", true},

					MAKE_COMBOBOX("Source", "Clipboard",
						{"Fixed", "Clipboard", "File", "AI Answer"}),

					{"Source Fixed", "An apple a day keeps the doctor away."},
					{"Source File Path", ""},
					{"Source AI Ask", "Please tell me Li Bai's famous poem in Chinese."},

					MAKE_COMBOBOX("Timing Mode", "Smart",	// 节奏模式
						{"Instant", "Fixed", "Smart"}),

					{"Timer", 1.0f},						// 变速
					{"Fixed Delay", 100U},
					{"Key Internal Gap", 10U},

					MAKE_COMBOBOX("Auto Send", "Off",		// 自动发送
						{"Off", "Sentence", "Sentence (Entire)", "Fixed Length", "Clock"}),

					MAKE_COMBOBOX("Auto Send Key", "Ctrl + Enter",
						{"Enter", "Ctrl + Enter"}),

                    {"Send Fixed Length", 10U},
					{"Send Period (ms)", 1000U},

				}
			},

			{"Key Disabler",
				{
					//{"Key Locker Mode (Press End to end)", false}
					MAKE_COMBOBOX("Mode", "Locker (Press End to escape)",
						{"Win", "LCtrl, Win, LAlt", "Locker (Press End to escape)"}),
				}
			},

			{"Key Logger",
				{
					{"Console Output", true},
					{"Log Output", true}
				}
			},

			{"No IMC",
				{
					{"Restore", true}
				}
			},

			{"Meme Trigger",
				{
					MAKE_COMBOBOX("Hotkey", "RCtrl + A~Z",
						{"RCtrl + A~Z",
						"RShift + A~Z",
						"RCtrl/RShift + A~Z",
						"RCtrl + RShift + A~Z"}),

					{"Disable ForceTopmost", true},
					{"Minimize Client", true},
				}
			},

			{"Volume",
				{
					/*MAKE_COMBOBOX("Vol+", "Ctrl+Shift+Up",
						{"Off", "Ctrl+Shift+Up", "Ctrl+Alt+Plus"}),

					MAKE_COMBOBOX("Vol-", "Ctrl+Shift+Down",
						{"Off", "Ctrl+Shift+Down", "Ctrl+Alt+Minus"}),

					MAKE_COMBOBOX("Mute", "Ctrl+Shift+M",
						{"Off", "Ctrl+Shift+M", "Ctrl+Alt+0"}),
					*/

					{"Vol+", {{"Keybind", {VK_LCONTROL, VK_LSHIFT, VK_UP}}}},
					{"Vol-", {{"Keybind", {VK_LCONTROL, VK_LSHIFT, VK_DOWN}}}},
					{"Mute", {{"Keybind", {VK_LCONTROL, VK_LSHIFT, 'M'}}}},

					MAKE_COMBOBOX("Volume Mode", "System",
								{"System", "Process"}),

					MAKE_COMBOBOX("System Volume HUD", "Temp",
								{"Off", "Temp", "Always"}),

					MAKE_COMBOBOX("System Volume HUD Style", "Bottom",
								{"Bottom", "Bottom Big", "Giant", "Rainbow Giant"}),

					MAKE_COMBOBOX("Process Volume HUD", "Temp",
								{"Off", "Temp", "Always"}),

					MAKE_COMBOBOX("Process Volume HUD Style", "Bottom",
								{"Bottom", "Giant", "Rainbow Giant"}),

					MAKE_COMBOBOX("Notify Type", "Off",
						{"Off", "Console Output", "Notify"}),

					MAKE_COMBOBOX("Wheel System Volume Adjust", "Off",
						{"Off", "LAlt", "RAlt", "Mouse On Taskbar"}),

					MAKE_COMBOBOX("Wheel Process Volume Adjust", "Off",
						{"Off", "LAlt", "RAlt", "Mouse On Caption"}),

					{"Wheel Volume Step", 5U},

					{"Step (%%)", 5U},

					{"Temp HUD Duration (ms)", 3000U},
				}
			},

			{"Music",
				{
					{"Filename", "FunkyStars.mp3"},

					MAKE_COMBOBOX("When", "Menu On",
					{"Menu On", "Menu Off", "Always"}),

					MAKE_COMBOBOX("Style", "Normal",
					{"Normal", "Damaged"}),
				}
			},

			{"Mute",
				{
					{"Restore Volume", true}
				},
			},

			{"Active",
				{
					{"Cooldown", 0},
				}
			},

			{"Force Topmost",
				{
					{"Cooldown", 25},
					{"Use SW_RESTORE", false},
					{"bind", {{"Keybind", {VK_RMENU, 'F'}}}}
				}
			},

			{"Screenshot",
				{
					MAKE_COMBOBOX("Mode", "Tool", 
						{"Instant", "Tool"}),

					{"Close Vanilla Snipping Tool", true},
					{"Notify Close", true},

					MAKE_COMBOBOX("Exclude Client", "Shift Key",
						{"Off", "Shift Key", "Always"}),

					// 已经帮你绑好了
					{"bind", {{"Keybind", {VK_LCONTROL, VK_SNAPSHOT}}}},

					/*MAKE_COMBOBOX("Format", ".png",
						{".png", ".jpg", ".bmp", ".webp", ".avif"})*/
				}
			},

			{"Console",
				{
					{"Random Title", true},
					{"Disable QuickEdit", true},
					{"Disable Close", true},
					{"bind", {{"Keybind", {VK_RMENU, 'C'}}}}
				}
			},

			{"Restart",
				{
					{"Run As User", false},
					{"Generate Arguments", true},
					{"bind", {{"Keybind", {VK_RMENU, 'R'}}}}
				}
			},

			{"Exit",
				{
					{"bind", {{"Keybind", {VK_RMENU, VK_DELETE}}}}
				}
			},

			{"Remote Kill HR",
				{
					{"Hidden Cmd", false},
					{"Exclude Myself", true},
					{"Exclude Low PID", true},
				}
			},

			{"Shader",
				{
					MAKE_COMBOBOX("Apply Area", "Client Only",
						{"Client Only", "Screen"}),

					MAKE_COMBOBOX("Style", "bloom",
						{"bloom",
						 "bloom_time",
						"blur",
						"cross_hatching",
						"cross_stitching",
						"dispersion",
						"dream_vision",
						"flash_shake",
						"jitter_focus",
						"mvp",
						"old",
						"pixelizer_time",
						"shadow_glitch",
						"sobel"}),

					{"Screen Mode Update Cooldown", 100U},
				}
			},

			{"Vape",
				{
					MAKE_COMBOBOX("Color", "White",		// Rainbow++ 将会使用着色器进行染色
					{	"White",
						"Rainbow",
						"Rainbow++"
					}),

					MAKE_COMBOBOX("Logo", "Vape",
						{"Vape", "LiquidBounce", "Custom"}),

					{"Custom Logo Path", ""},
					
				}
			},

			{"Close AV",
				{
					{"Huorong", true},
					{"360", true},
				}
			}

			/*{"Taskbar Pin",
				{
					{"Verb Method (< Win 10)", false}
				}
			}*/
		},
	},

	{"Config",

		{
			MAKE_COMBOBOX("Freeze Client", "Off",
				{"Off", "Always", "When Hidden"}),

			{"Single Instance",	true},
			{"Disable Log", false},
			{"Simplified Log", false},
			{"Auto Toggle As Prev Run", true},
			{"Save Module Toggle Data", true},
			{"Save Data More Frequently", false},
			/*{"Disable DPI Scaling", true},*/
			{"Use Client Exception Filter", true},
#ifdef APP_DEBUG_VERSION
			{"Block Unsafe Modules", true},
#else
			{"Block Unsafe Modules", true},
#endif
			{"Block Driver Modules", true},
			{"Admin Modules Check Admin", true},
			{"Disallow WMI ProcessKill", true},
			{"Lock Module Toggle", false},
			{"Lock Module Options", false},
			{"Block Module Options", false},
			{"Float Options Digits", 3U},
			{"String Preview Length", 16U},
			{"Options Cross Toggle Close", false},
			{"Output Notification", true},
			{"Log Notification", true},
			{"Check Module Toggle Cooldown (ms)", 2000U},
			{"Process List Update Freq (Hz)", 15.0f},
			{"Disable Keybind When Hidden", false},

			MAKE_COMBOBOX("File Size Unit Base", "1000",
					{"1000", "1024"}),

			{"Always Run", true},
			{"Always Admin", false},

			MAKE_COMBOBOX("GetProcAddress", "Default",
			{"Default", "Manual"}),
			/*{"Esc Key Exit", false},*/
		},
	},

	{"GUI",

		{
			{"Opacity (0~1)", 1.0f},
			{"Rainbow GUI", false},
			{"Outline", true},
			{"Display Module Option Default Value", true},
			{"Module Option Wheel Sensitivity", 12.0f},
			{"Top Tab Font Size", 20},
			{"Module Font Size", 20},
			{"Module Height", 25},
			{"ClickGUI Global Scale", 100.0},
			{"Hacked Module Names", false},

			MAKE_COMBOBOX("Module Name Alignment", "Center",
			{"Center", "Left", "Right"}),

			MAKE_COMBOBOX("Enabled Module Color", "Red",
			{"Red", "Green", "Blue", "Aqua-Pink", "Green-Red", "Colorful", "Rainbow"}),
			
			MAKE_COMBOBOX("Module Background Color", "Transparent", 
			{"Transparent", "Black", "Red", "Green", "Blue", "Aqua-Pink", "Green-Red", "Colorful", "Rainbow"}),

			{"Module Background Blackness (0~1)", 0.9f},
			
			{"Description Font Size", 25},
			// {"Modules Column Top", 40},
		//	{"Support RCtrl Toggle", true},
			MAKE_COMBOBOX("Menu Toggle Key", "RCtrl/RShift",
				{"RCtrl", "RShift", "RCtrl/RShift"}),

			{"Always Focused", false},
			{"Show FPS", true},
			{"Show Module Description", true},
			{"Save Tabs Status Data", true},

			MAKE_COMBOBOX("Launcher UI Style", "Default",
			{"Default", "Vape"}),

			/*{"Font Name", "Minecraft Unpixelated.ttf"},*/
			MAKE_COMBOBOX("Font", "Metropolis-Medium.ttf",
			{"Minecraft AE Pixel.ttf",
			"crafters-delight.ttf",
			"fs-roundcraft.ttf",
			//"msyh.ttc",
			//"DingTalk JinBuTi.ttf",
			"HarmonyOS_SansSC_Medium.ttf",
			"Metropolis-Medium.ttf",
			/*"Nirmala.ttf",*/
			//"ubuntu.ttf",
		/*	"STXIHEI.ttf",*/
			//"segmono_boot.ttf",
	/*		"segoeui.ttf",*/
	/*		"Tahoma.ttf",*/
			"Unifont.ttf",
			}),

			{"Chinese", false},

			MAKE_COMBOBOX("Esc Key Action", "Close Menu",
			{"Off", "Close Menu", "Exit"})
		}
	},

	{"HUD",

		{
			{"Enabled", true},
			{"Show Arraylist",	true},
			{"Arraylist Font Size", 30},
			{"Arraylist Line Gap", 5},
			{"Arraylist Top", 40},
			MAKE_COMBOBOX("Arraylist Position", "Right", {"Left", "Right"}),
			{"Arraylist Side Margin", 40},
			{"Arraylist Side Bar", false},
		/*	{"Rainbow Modules", true},
#ifdef APP_DEBUG_VERSION
			{"Rainbow Enhance", false},
#else
			{"Rainbow Enhance", true},
#endif*/
			MAKE_COMBOBOX("Arraylist Color", 
			"Rainbow",		// Rainbow++ 将会使用着色器进行染色
			{	"White", 
				"Green",
				"Magenta",
				"Aqua-Pink",
				"Green-Red",
				"Colorful",
				"Rainbow", 
				"Rainbow++"
			}
			),

			{"Arraylist Background", false},
			{"Sort By Length", true},
			{"Use Display Length", true},
			{"Disable Notification", false},

			MAKE_COMBOBOX("Notify Style", "Metro",
			{"WinToast", "Metro", "Chatter"}),

			{"Notify Font Size", 25},
			{"Notify Min Width", 200},
			{"Notify Height", 45},
			{"Notify Stay Time (0~1)", 0.3},
			{"Notify Opacity (0~1)", 0.9f},
			{"Notify Right Margin", 80},
			{"Notify Bottom Margin", 150},
			{"Notify Line Gap", 10},
			{"Chatter Line Gap", 10},
			{"Chatter Show Duration", 10000U},
			{"Chatter Font Size", 30},
			{"Chatter Opacity (0~1)", 0.8f},
			{"Notify WinToast Attempt to Jump Queue", true},
			{"Notify AntiSpam", false},
			{"Notify AntiSpam Min Similarity (0~1)", 0.8f},
			{"Enable Some Tray Tips", true},

			{"Notification Sound", true},
			{"Sound When Hidden", false},

#define MAKE_SOUNDITEM(name, defval)	\
			MAKE_COMBOBOX(name, defval, {"toast.wav", "bassattack.wav", "pling.wav", "bell.wav", "icechime.wav", "totem.wav"})

			MAKE_SOUNDITEM("Sound (Info)", "toast.wav"),
			MAKE_SOUNDITEM("Sound (Warn)", "pling.wav"),
			MAKE_SOUNDITEM("Sound (Error)", "bassattack.wav"),
			MAKE_SOUNDITEM("Sound (Success)", "icechime.wav"),

			{"Notify Font Reload", false},
			{"Show Font Extra Chars", false},
			{"Rainbow Speed", 60.0f},
			/*{"Welcome Splash", false}*/
			//{"Superb Notify", false},
			/*MAKE_COMBOBOX("Startup Interface", "Classical",
				{"Off", "Zoom", "Classical", "Fade"}),*/
		}
	},
};