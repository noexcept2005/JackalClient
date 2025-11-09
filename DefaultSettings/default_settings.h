#pragma once


#define NAMED_COLOR_BASE_LIST \
"Black", "Gray", "White", "Red", "Gold", "Yellow", "Green", "Dark Green", "Aqua", "Blue", "Magenta", "Pink", "Purple", "Pink-Magenta", "Red-Orange", "White-Gray", "Aqua-Blue", "Aqua-Pink", "Green-Red", "Astrolfo", "Colorful", "Rainbow"

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

#define MAKE_SOUNDITEM(name, defval)	\
						MAKE_COMBOBOX(name, defval, \
						{"Off", "toast.wav", "bassattack.wav", "pling.wav", "pling_low.wav", "bell.wav", "icechime.wav", \
						"teleport.wav", "totem.wav", "enable.wav", "disable.wav", "rise_enable.wav", "rise_disable.wav", "quickmacro_enable.wav", "quickmacro_disable.wav", "sigma_enable.wav", "sigma_disable.wav", "steam_toast.wav", "steam_show_modal.wav", "steam_menu_in.wav", "steam_menu_out.wav", "steam_warning.wav", "steam_confirm_negative.wav", "steam_confirm_positive.wav",\
						"thunder1.wav", "thunder2.wav", "thunder3.wav", "thunder4.wav"\
						}	\
						)

#define WORMWAKER_MID  XorStringA("3494361276877525")
#define WORRNWAKER_MID  XorStringA("3546682383928268")

json config_default_jsons
{
	{"Modules",
		{

			{"Anti Close",
				{
					{"Notify Close Message", true}
				}
			},

			{"Anti Debug",
				{
					{"Async", true},
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

			{"Auto Start",
				{
					{"Async", true},
					{"Check Cooldown (ms)", 30000L},

					MAKE_COMBOBOX("Method", "Registry",
						{"Registry", "Service", "Scheduled Task"}
						),

					{"Registry Value Name", "JackalClient"},
					//{"Service Name", "JackalClient"},
					{"Service Description", "Jackal Client Auto Start Service"},
					{"Service Display Name", "Jackal Client Service"},
					{"Service Stopping Timeout (s)", 10},
					{"Scheduled Task Name", "JackalClient"},
					{"Extra Arguments", ""},
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
					MAKE_COMBOBOX("System Privilege Check Method", "Whoami",
						{"Membership", "Whoami"}),

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

					{"Close Menu", true},
					{"Legit Transparent Window", true},
					{"Cmstp Window Search Timeout (ms)", 10000},
					{"Safe Check", true},
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
					{"Hide HUD When Menu On", false},
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

			{"Crash Key",
				{
					MAKE_COMBOBOX("Keyboard Device", "All",
						{"All", "PS/2", "USB", "Hyper-V"}),
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

					MAKE_COMBOBOX("Mode", "Auto",
						{"Auto", "Manual"}),

					MAKE_COMBOBOX("Uninstall Start Method", "Injection",
						{"Execute", "Parent Spoof", "Cmd Legit", "Explorer Legit", "Injection"}),

					{"Transparent Window", false},
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
	   {"Comm File Check Cooldown (ms)", 200L},
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

{"Machine Lock",
	{
		{"Title", "计算机已锁定"},
		{"Subtitle", "你需要输入密码"},

		{"Title Display", true},
		{"Subtitle Display", true},

		{"Background Color", "40;0;0;250"},
		{"Title Color", "yellow"},
		{"Subtitle Color", "aqua"},
		{"Password Color", "green"},

		{"Title Font Size", 180},
		{"Subtitle Font Size", 100},
		{"Password Font Size", 220},

		{"Mute", true},
		{"Disable IMC", true},
		{"Keep Active", true},
		{"Force Topmost", true},
		{"Hide Taskbar", true},
		{"Disable KeyLogger", true},
		{"Disable Logoff", true},
		{"Pause Keystrokes2", true},

		MAKE_COMBOBOX("Mouse Lock", "Allow Move",
			{"Off", "Allow Move", "Disable All"}),

		{"Keyboard Lock (Ctrl, Win, Alt)", true},
		{"Disable Client Other Control", true},
		{"Disable Client Other HUD", true},

		MAKE_COMBOBOX("Emergency Escape Method", "Custom Hotkey (Notice Keyboard Lock)",
			{"Off", "Esc (Press 20 seconds)", "Custom Hotkey (Notice Keyboard Lock)"}),

		{"Custom Escape Hotkey", {{"Keybind", {VK_OEM_3}}}},

		MAKE_COMBOBOX("Exit Condition", "Password",
			{"Password", "Wait Duration"/*, "Wait Until"*/}),

		{"Password (Must Alpha or Num)", "0721"},
		/*{"Password Attempt Threshold", 3U},
		{"Password Attempt Freeze Duration (min)", 5U},*/

		{"Wait Duration (min)", 30U},
		//{"Wait Until (HH:MM)", "00:00"},

		{"AUTO ENABLE WHEN CLIENT LAUNCHED", false},
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
			MAKE_COMBOBOX("Method", "WINAPI",
			{"Command", "WINAPI"}),

			{"Force", false}
		}
	},

	{ "Log Off",
		{
			MAKE_COMBOBOX("Method", "WINAPI",
			{"Command", "WINAPI"}),
			
			{"Force", false}
		}
	},

	{ "Crash",
		{
			{"Custom Win32 Error Code", 5},
		}
	},

		{"Message Blocker",
			{
				{"Notify", true},
				{"Disable When Quit", true},
				{"Output Messages", true},

				{"Ignore WM_PAINT", true},
				{"Ignore WM_TIMER", false},
				{"Ignore WM_QUIT", false},

				{"Overlay", true},
				MAKE_COMBOBOX("Overlay Color", "Red",
					{NAMED_COLOR_BASE_LIST}),
				{"Overlay Opacity (0~1)", 0.2f},
				{"Hide HUD When Menu On", false},

				MAKE_COMBOBOX("Target Window", "Foreground",
					{"Foreground", "PointAt"}),

					/*{"Auto Disable", false},
					TODO:	blink hud...
					*/
			}
		},

		{"Window ESP",
			{
				{"Box Alpha", 0.5f},
				{"Update Cooldown", 250U},
				{"Exclude Invisible", true},
				{"Exclude Foreground", true},
				{"Exclude Pointed", true},
				{"Hide HUD When Menu On", true},
			}
		},

		{"Window Highlight",
			{
				{"Easing", true},
				{"Easing Speed (0~1)", 0.2f},
				{"Only Foreground", false},
				{"Aura Target Highlight", true},
				{"Endangered Excla Mark", true},
				{"Hide When Menu On", true},

				{"Dark Background", true},
				{"Dark Background Alpha (0~1)", 0.5f},
			}
		},

		{"Opacity Changer",
			{
				MAKE_COMBOBOX("HUD", "Giant",
					{"Off", "Giant", "Rainbow Giant"}),

				MAKE_COMBOBOX("Shortcut", "Wheel on Side",
					{"Wheel on Side", "HotKey + Wheel"}),

				MAKE_COMBOBOX("Wheel Side", "Left",
					{"Left", "Top", "Right", "Bottom"}),

				MAKE_COMBOBOX("Target Window", "Foreground",
					{"Foreground", "PointAt"}),

				{"Wheel Hotkey", {{"Keybind", {VK_LMENU}}}},
				

				{"Hide HUD When Menu On", false},
				{"Temp HUD Duration (ms)", 3000L},
				{"Temp HUD Animation Duration (ms)", 300L},
				{"Step (%%)", 10U},
			}
		},

			{ "Window Master",
				{
					{"Hide HUD When Menu On", true},
					{"HUD Font Size", 20},
					{"HUD Line Gap", 5},

					MAKE_COMBOBOX("HUD Background", "Fancy",
					{"Off", "Simple", "Fancy"}),

					{"Easing", true},
					{"Easing Speed (0~1)", 0.1},	// 缓动速率

					MAKE_COMBOBOX("HUD Color", "Rainbow",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Target", "Foreground",
						{"Foreground", "PointAt"}),

					MAKE_COMBOBOX("Privacy Mode", "Invisible (>= Win10)",
						{"Black", "Invisible (>= Win10)"}),

						/*{"Show Texts", true}*/
					MAKE_COMBOBOX("HUD", "Follow",
							{"Off", "Follow", "BottomRight", "BottomLeft"}),

					MAKE_COMBOBOX("HUD Paging", "Off",
						{"Off", "Multiple Pages", "Only Show Page 1"}),

					{"HUD Item Count Per Page", 11U},
					{ "HUD Next Page", {{"Keybind", {VK_LMENU, VK_RIGHT}}} },
					{ "HUD Prev Page", {{"Keybind", {VK_LMENU, VK_LEFT}}} },

					{"Phantom Window Opacity (0~1)", 0.1f},

					{ "Privacy/U Keybind", {{"Keybind", {VK_LMENU, VK_F1}}} },
					{ "Privacy Overlay/U Keybind", {{"Keybind", {VK_LMENU, VK_F2}}} },
					{ "Toggle Phantom Window Keybind", {{"Keybind", {0}} }},
					{ "Kill Process Keybind", {{"Keybind", {VK_LMENU, VK_F3}} }},
					{ "EndTask Keybind", {{"Keybind", {VK_LMENU, VK_F9}}} },
					{ "Freeze/U Keybind", {{"Keybind", {VK_LMENU, VK_F6}}} },
					{ "Process Freeze/U Keybind", {{"Keybind", {VK_LMENU, VK_F7}}} },
					{ "Topmost/U Keybind", {{"Keybind", {VK_LMENU, VK_F8}}} },
					{ "Hide/Show Keybind", {{"Keybind", {VK_LMENU, VK_F5}}} },
					{ "Destroy Keybind", {{"Keybind", {VK_LMENU, VK_F11}}} },
					{ "Update Keybind", {{"Keybind", {0}}} },
					{ "Lock Update Keybind", {{"Keybind", {VK_LMENU, VK_F10}}} },
					{ "EndSession Keybind", {{"Keybind", {VK_LMENU, VK_F12}}} },
					{ "Sink Keybind", {{"Keybind", {0}}} },

				}
			},

			{"Private Window",
				{
					{"Async", true},

					MAKE_COMBOBOX("Mode", "Invisible (>= Win10)",
						{"Black", "Invisible (>= Win10)"}),

					MAKE_COMBOBOX("Policy", "Simple Check",
						{"Set Once", "Simple Check", "Complete Check", "Blatant Apply"}),

					{"Keep Checking Cooldown (ms)", 1000U},

					{"QQ NT", true},
					{"WeChat", true},
					{"WeChat New", true},
					{"Edge", true},
					{"Steam", true},
					{"Bilibili Desktop", true},

					{"Edge Overlay Mode", false},
					{"Clear Overlay Windows When Disabling", false},
					{"Record Window When Failed", true}
				}
			},

			{"Console ESP",
				{
					{"Check Cooldown (ms)", 500U},
					{"Monitor Console Created", true},
					{"Monitor Console Destroyed", true},
					{"Monitor Console Content", true},

					{"Process Blacklist (Sep With Semicolon)", "cmd.exe;git.exe;tesseract.exe;MSBuild.exe;JackalClient.exe;AppProvisioningPlugin.exe;clash-core-service.exe;postgres.exe"},

					MAKE_COMBOBOX("Notify Mode (Created/Destroyed)", "Console Output",
						{"Off", "Console Output", "Notify", "Chatter", "Actionbar", "Title", "Speak"}),

					MAKE_COMBOBOX("Notify Mode (Content)", "Console Output",
						{"Off", "Console Output", "File Output", "Notify", "Chatter", "Actionbar", "Title", "Speak"}),

					MAKE_COMBOBOX("Actionbar Color (Created)", "Dark Green",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Actionbar Color (Destroyed)", "Red",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Actionbar Color (Content)", "Colorful",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Chatter Color (Created)", "Dark Green",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Chatter Color (Destroyed)", "Red",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Chatter Color (Content)", "Gray",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Title Color (Created)", "Dark Green",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Title Color (Destroyed)", "Red",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Title Color (Content)", "Gray",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Target Mode (Content)", "Single",
						{"Single", "All"}),

					MAKE_COMBOBOX("Target Single Process (Content)", "", {""}),
				}
			},

			{"Topmost",
				{
					MAKE_COMBOBOX("Target", "Foreground",
						{"Foreground", "PointAt"}),

					MAKE_COMBOBOX("Operation", "Auto",
						{"Auto", "Topmost", "Untopmost"}),

					{"Notify", true},
				}
			},

			{"Title Changer",
				{
					{"Keep", true},
					{"Check Cooldown", 250L},

					MAKE_COMBOBOX("Pattern", "Fixed",
						{"Clear", "Fixed", "Random", "Timestamp", "Word Replace"}),

					MAKE_COMBOBOX("Target", "Foreground",
						{"Foreground", "PointAt"}),

					{"Fixed Title", "Chrome Legacy Window"},

					{"Word Replace Old", "C:\\"},
					{"Word Replace New", "D:\\"},
				}
			},

			{"Messenger",
				{
					{"Show Parameter Details", true},

					{"Blacklist Enabled", true},
					{"Blacklist (Sep With Semicolon)", "WM_MOUSEFIRST;WM_NCHITTEST;WM_SETCURSOR;WM_GETTEXT;WM_WINDOWPOSCHANGING;WM_WINDOWPOSCHANGED"},

					{"Whitelist Enabled", false},
					{"Whitelist (Sep With Semicolon)", ""},

					MAKE_COMBOBOX("Notify Mode", "Notify",
					{"Console Output", "Notify", "Chatter", "Actionbar", "Title"}),
				}
			},

			{"Better Animation",
				{
					{"Animation Duration (ms)", 300L},
					{"Toggle NoAnimation Module", true},

					MAKE_COMBOBOX("Custom Style", "Fade",
						{"Fade", "Color Transition"/*, "Image Transition"*/}),

					{"Color Transition", "1;1;1"},
					//{"Image Path", ""},

					MAKE_COMBOBOX("Notify Mode", "Notify",
						{"Off", "Notify", "Chatter", "Actionbar"}),

					{"Check Cooldown (ms)", 10L},
				}
			},

			{"Target ESP",
				{
					MAKE_COMBOBOX("Target", "PointAt",
						{"Target HUD", "Foreground", "PointAt", "it (Pronoun)"}),

					{"Rotation Speed", 5.0f},
					{"Rotation Amplitude", 150.0f},
					{"Easing Speed (0~1)", 0.05f},
					{"Scale", 1.0f},
					{"Opacity (0~1)", 0.9f},
					{"Fade In Time (ms)", 1200L},
					{"Fade Out Time (ms)", 5000L},
					{"Show Temporarily", true},
					{"Show Duration (ms)", 5000L},

					MAKE_COMBOBOX("Color", "White",
						{NAMED_COLOR_BASE_LIST})
				}
			},

			{"Target HUD",
				{
					MAKE_COMBOBOX("Target", "Foreground",
						{"Foreground", "PointAt", "it (Pronoun)"}),

					MAKE_COMBOBOX("HUD Position", "Follow",
						{"Follow", "Fixed"}),

					MAKE_COMBOBOX("HUD Background Color", "Black",
						{"Transparent", NAMED_COLOR_BASE_LIST}),

					{"HUD Background Darkness (0~1)", 0.85f},
					{"HUD Round Corners", true},
					{"HUD Shadow", true},
					{"HUD Shadow Thickness", 15.0f},

					MAKE_COMBOBOX("HUD Shadow Color", "Black",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("HUD Outline Color", "Dark Green",
						{"Transparent", NAMED_COLOR_BASE_LIST}),

					{"Give Way to Mouse", true},

					{"Background Image", false},
					{"Background Image Path", ""},
					//{"Background Image Scale", 1.0f},
					{"Background Image Opacity (0~1)", 0.5f},
					{"Background Image Moving Speed", 0.5f},

					{"Fixed X Rate", 0.85f},
					{"Fixed Y Rate", 0.65f},

					{"Easing", true},
					{"Easing Speed (0~1)", 0.2f},
					{"Fade Time (ms)", 500L},

					MAKE_COMBOBOX("Style", "Default",
						{"Default"}),
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

			{"IRC",
				{
					{"Async While Getting Username", true},

					{"Message Fetch Interval (ms)", 5000L},
					{"Message Fetch Timeout (s)", 20},
					{"Message Send Timeout (s)", 20},

					{"Old Messages Threshold (s)", 60},
					{"Ignore Old Messages", true},
					{"Cancel Sending When As Guest", true},
					{"Cancel Sending Repeated Message", true},
					{"Auto Change Name When Name Missing", true},

					MAKE_COMBOBOX("Notify My Mentions", "Notify",
					{"Off", "Notify", "Chatter", "Title", "Actionbar", "WinToast"}),
					
					MAKE_COMBOBOX("Message Notify Type", "Notify",
					{"Off", "Notify", "Chatter", "Actionbar", "Title", "Island"}),

					MAKE_COMBOBOX("Text Database Update Method", "POST",
					{"Old", "GET", "POST"}),

					MAKE_COMBOBOX("Quick Send Style", "Bottom Chat",
					{"Off", "Bottom Chat", "Input Box"}),

					{"Quick Send Hotkey", {{"Keybind", {VK_LCONTROL, VK_LMENU, '0'}}}},

					{"Message Length Limit Via GET", 39},

					{"Speak Message", true},

					{"Blatant Send", false},
					{"Console Output", true},
					{"Fast Send With # Prefix Command", true},

					{"Taboo Filter", true},
					{"Debug Output", false},
				}
			},

			{"Anti Webpage",
				{
					{"Async", true},
					{"Only On Browser", true},

					{"Title Keywords 1 Enabled", true},
					{"Title Keywords 1", "传奇;一刀;贪玩;霸主;鬼服;福利;0氪;免费送;打金服;上线即领"},

					{"Title Keywords 2 Enabled", true},
					{"Title Keywords 2", "博彩;新澳;荷官;超高赔率"},

					{"Title Keywords 3 Enabled", true},
					{"Title Keywords 3", "page not found;404 not found;502 bad gateway"},

					{"Title Keywords Custom Enabled", false},
					{"Title Keywords Custom", ""},

					MAKE_COMBOBOX("Target Window", "Foreground",
						{"Foreground", "PointAt"}),

					MAKE_COMBOBOX("Notify Mode", "Notify",
						{"Off", "Notify", "Chatter"}),

					{"Chatter Color", "255;203;0;230"},

					MAKE_COMBOBOX("Operation", "Close Page",
						{"Off", "Close Page", "Close Window"}),

					{"Ctrl+W Internal Delay (ms)", 100},

					/*MAKE_COMBOBOX("Mute Mode", "System - Auto Toggle",
						{"System - Direct", "System - Enable Mute Module", "System - Auto Toggle",
						 "Browser - Direct", "Browser - Auto Toggle",
							}),*/

					{"Check Cooldown", 500U},
				}
			},

			{"Auto Live Chatter",
				{
					MAKE_COMBOBOX("Send Time Mode", "Off",
						{"Off", "Periodic"}),

					{"Periodic Interval (ms)", 60000L},
					
					MAKE_COMBOBOX("Send Content Mode", "Fixed",
						{"Fixed", "List Random Element", "List Loop", "Prefab", "File Lines"}),

					MAKE_COMBOBOX("Prefab Type", "Aphorism",
						{"Aphorism", "Idiom Solitaire", "Ask Solitaire"}),

					{"Fixed Content", "给主播点个关注~"},
					{"List Content (Sep With Semicolon)", ""},
					{"List Current Index", 0},
					{"File Source Path", ""},
					{"Room ID", 31196635},

					MAKE_COMBOBOX("Clipboard Quick Send", "Off",
						{"Off", "Send", "Copy and Send", "Select All, Copy and Send"}),

					{"Clipboard Quick Send Key", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_ADD}}}},

					{"Clipboard Quick Send Confirm", false},
					{"Clipboard Quick Send Confirm Time (s)", 5},
					{"Clipboard Quick Send Prevent Repeat", true},
					{"Clipboard Quick Send Apply Text Processor", false},

					{"Chatter Split Cooldown Min (ms)", 1000},
					{"Chatter Split Cooldown Max (ms)", 2000},
				}
			},

			{"Tcp Monitor",
				{
					{"Check Cooldown (ms)", 1000L},

					{"Filter Processes", true},
					{"Process Name Whitelist (Empty For Any)", ""},
					{"Process Name Blacklist (Empty For Disabled)", "JackalClient.exe"},
					{"Process Id Whitelist (Zero For Any)", "0"},
					{"Process Id Blacklist (Zero For Disabled)", "0"},

					MAKE_COMBOBOX("Notify Mode", "Chatter",
					 {"Notify", "Chatter", "Actionbar"}),

					MAKE_COMBOBOX("Chatter Color (New Connection)", "Gold",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Chatter Color (Closed Connection)", "Purple",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Chatter Type", "Random",
					{"Scroll", "Top", "Bottom", "Reverse", "Horizontal", "Vertical", "Random"}),	// 弹幕类型

					{"Filter Ports", false},
					{"Ports Whitelist (e.g. 4-10,80)", "80,443"},
					{"Ports Blacklist (e.g. 4-10,80)", ""},
					MAKE_COMBOBOX("Port Type", "Remote",
						{"Remote", "Local"}),

					{"Filter IPs", false},
					{"Exclude LAN IP", true},
					{"IP Whitelist (Sep With Semicolon)", ""},
					{"IP Blacklist (Sep With Semicolon)", ""},
					MAKE_COMBOBOX("IP Type", "Remote",
						{"Remote", "Local"}),

					{"Show IP Addresses", true},
					{"Query External IP Position", false},
				}
			},

			{"Tcp Killer",
				{
					MAKE_COMBOBOX("Mode", "Once", {"Once", "Keep"}),

					{"Keep Mode Cooldown (ms)", 200U},

					{"Filter Processes", false},
					{"Process Name (Empty For Any)", ""},
					{"Process Id (Zero For Any)", 0},
					{"Max Disconnection Count", 65535},

					MAKE_COMBOBOX("Notify", "Smart",
					 {"Off", "Only Error", "Smart", "All"}),

					MAKE_COMBOBOX("Notify Mode", "Notify",
					 {"Notify", "Chatter", "Actionbar"}),

					{"Filter Ports", true},
					{"Ports Whitelist (e.g. 4-10,80)", "80,443"},
					{"Ports Blacklist (e.g. 4-10,80)", ""},
					MAKE_COMBOBOX("Port Type", "Remote",
						{"Remote", "Local"}),

					{"Filter IPs", false},
					{"Exclude LAN IP", true},
					{"IP Whitelist (Sep With Semicolon)", ""},
					{"IP Blacklist (Sep With Semicolon)", ""},
					MAKE_COMBOBOX("IP Type", "Remote",
						{"Remote", "Local"}),
				}
			},

			{"Anti 360Ad",
				{
					{"Kill 360 Ad Processes", true},
					{"Remove 360 Suspended Ball", true},

					{"MultiTip.exe", true},
					{"sesvcr.exe", true},
					{"360SpeedldHealth.exe", true},

				}
			},

				{"Anti Popups",
					{
						MAKE_COMBOBOX("Ad Process Policy", "Warn & AutoKill",
							{"Ignore", "Warn", "AutoKill", "Warn & AutoKill"}),

							/*MAKE_COMBOBOX("Confirm", "Off",
								{"Off", "HUD", "HUDTimeout", "Msgbox", "MsgboxTimeout", }),*/

						MAKE_COMBOBOX("BottomRight Judge Policy", "Size or Blacklist",
							{
								"Size",
								"Title",
								"Size and Title",
								"Size or Blacklist",
								"Title or Blacklist",
								"Size and Title or Blacklist",
							}),

						MAKE_COMBOBOX("Others Judge Policy", "Title or Blacklist",
							{
								"Title",
								"Blacklist",
								"Title or Blacklist",
							}),

						MAKE_COMBOBOX("Measures", "Chain",
							{"Chain", "Close", "Destroy", "EndSession", "KillProcess"}
							),

						{"Ad Window Title Keywords List", "每日;开通会员;游戏中心;今日;新闻;优选;精选;推荐;热搜;软件管家;贴士;小助手;奖励;特惠;公测;一刀;贪玩;上线;News;Free Trial"},
						{"Chain Allow LegitMouseClick", true},
						{"Chain LegitMouseClick Internal Delay (ms)", 200},
						{"Chain LegitMouseClick X Margin Min", 14},
						{"Chain LegitMouseClick X Margin Max", 22},
						{"Chain LegitMouseClick Y Margin Min", 14},
						{"Chain LegitMouseClick Y Margin Max", 22},
						{"Chain Allow Move Window Out", true},
						{"Check Cooldown", 250U},
						{"Exclude Maximized", false},
						{"Exclude MessageBox", true},
						{"Exclude SystemProcess", true},
						{"Exclude WinToast", true},

						{"Blacklist Processes (Sep With Semicolon)", "mini.lohaslady.exe;FlashHelperService.exe;MultiTip.exe;sesvcr.exe;360SpeedldHealth.exe;360SpeedIdHealth.exe;360SpeedIdHealthEx.exe;Tgmn.exe;Tnuser.exe;Svnpnd.exe;SGNews.exe;biz_helper.exe;SOGOUSmartAssistant.exe;DesktopAssistant.exe;LenovoAppStore.exe;aipiclaunch.exe;SoftMgr.exe"},
						{"Whitelist Processes Enabled", true},
						{"Whitelist Processes (Sep With Semicolon)", "哔哩哔哩.exe;explorer.exe;Snipaste.exe;steam.exe;steamwebhelper.exe"},
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

{"Hide Taskbar",
	{
		{"Notify", false},
	}
},

{"Auto Translate",
	{
		{"Async", true},

		MAKE_COMBOBOX("Target", "Foreground",
			{"Screen", "Foreground", "PointAt"}),

		{"Screen Mode Exclude Client", true},

		MAKE_COMBOBOX("Action", "Translate",
			{"Translate", "Recognize"}),

		MAKE_COMBOBOX("Source Language", "English",
			{/*"Non-chinese", */"English", "Chinese"}),

		MAKE_COMBOBOX("Text Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Text Color (Pointed At)", "Green",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Translation Result Color", "Yellow",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Text Background Color", "Red",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Text Background Color (Pointed At)", "Dark Green",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Translation Result Background Color", "Black",
			{NAMED_COLOR_BASE_LIST}),

		{"Translation Max Thread Count", 20},

		MAKE_COMBOBOX("Texts Pointed At", "Raw",
			{"Hidden", "Raw", "Result"}),

		{"Show Texts", true},
		{"Text Background", true},
		{"Text Background Opacity (0~1)", 0.5f},
		{"Text Background Opacity (Mouse Pointed At) (0~1)", 0.5f},
		{"Text Min Size", 20},
		{"Text Max Size", 80},
		{"Translation Result Min Size", 30},
		{"Translation Result Max Size", 100},
		{"Text Opacity (0~1)", 0.8f},

		{"Recognize Min Confidence (0~100)", 80.0f},

		/*MAKE_COMBOBOX("Dest Language", "Chinese",
			{"Chinese", "English"}),*/

		MAKE_COMBOBOX("Trigger Mode", "Periodic",
			{"Periodic", "On Window Change", "Manual"}),

		{"Merge Texts Into Groups", true},
		{"Merge Texts Vertical Gap Threshold", 0.5f},
		{"Merge Texts Horizontal Gap Threshold", 3.0f},

		{"Recognize Cooldown (ms)", 3000L},
		{"Toggle Texts Hotkey", {{"Keybind", {0}}}},
		{"Trigger Hotkey", {{"Keybind", {0}}}},
		{"Re-merge Texts Hotkey", {{"Keybind", {0}}}},
		{"Clear Hotkey", {{"Keybind", {VK_CAPITAL}}}},
	}
},

{"Auto Focus",
	{
		MAKE_COMBOBOX("Mode", "PointAt",
			{"PointAt", "Foreground Locked"}),

		MAKE_COMBOBOX("Notify", "Off",
			{"Off", "Notify", "Chatter", "Actionbar"}),

		{"Disable When Menu On", false},
		{"Disable When Quit", false},
		{"Check Cooldown (ms)", 200},
		{"Restore Window While Focusing", false},
	}
},

{"Close Enhance",
	{
		MAKE_COMBOBOX("Method", "EndSession",
			{"EndSession", "KillProcess", "EndTask"}),

		{"Exclude Self", true},
	}
},

{"Dialog Physics",
	{
		MAKE_COMBOBOX("Constant Mode", "Float",
			{"Off", "Fall", "Bounce", "Float"}),

		/*MAKE_COMBOBOX("Start Position", "Off",
			{"Off", "Random", "Up", "Down", "Left", "Right"}),*/

		MAKE_COMBOBOX("Collision", "Omnidirectional",
			{"Off", "Orthogonal", "Omnidirectional"}),

		{"Gravity", 9.8f},
		{"Basic Friction", 0.03f},
		{"Step", 0.1f},
		{"Dialog Bounce Damping", 0.6f},

		{"Pause When Menu On", true},

		{"Drag Inertia", 20.0f},
		{"Drag Spring K", 20.0f},
		{"Drag Damping", 3.0f},

		{"Initial Velocity", false},
		{"Initial Min Velocity", 4.0f},
		{"Initial Max Velocity", 8.0f},
		{"Initial Random Degree", true},
		{"Initial Custom Degree", 1.57f},
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

	 {"List Tasks",
		{
			{"Async", true},
			{"Auto Console", true},

			MAKE_COMBOBOX("Style", "Normal",
				{"Normal", "Vanilla (List)", "Vanilla (XML)", "Vanilla (CSV)"}),
		}
	},

	 { "List Drivers",
		 {
			 {"Async", true},
			 {"Auto Console", true},
			 {"Verify", true},
		 }
	 },

	 {"Elevator",
		 {
			 {"Process Name (Empty For Any)", "JackalClient.exe"},
			 {"Process Id (Zero For Any)", 0},
			 {"Max Process Count", 8},
		 }
	 },

	 {"Force Terminator",
		 {
			 {"Async", true},
			 {"Close Menu", false},
			 {"Confirm Before Termination", false},
			 {"Process Name (Empty For Any)", "JackalClient.exe"},
			 {"Process Id (Zero For Any)", 0},
			 {"Max Process Count", 8},
		 }
	 },

	 {"Injector",
		 {
			 MAKE_COMBOBOX("Method", "NtCreateThreadEx",
				 {
					 "CreateRemoteThread",
					 "NtCreateThreadEx",
					 "QueueUserAPC",
					 "Reflective",
					 "Reflective (External)",
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

			 MAKE_COMBOBOX("Injection Architecture", "Auto",
				 {"Auto", "x64", "x86"}),

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

			 /*MAKE_COMBOBOX("Style", "Simple",
				 {"Simple", ""}),*/

			 //{"Aim Foreground Window Only", false},

			 MAKE_COMBOBOX("Target", "PointAt",
				{"PointAt", "Foreground"}),

			 {"Aura Target Highlight", true},
			 {"Give Way to Mouse", true},
			 {"Show Handle Value", true},
			 {"Show Process Info", true},
			 {"Show Parent Info", true},
			 {"Show Position", false},
			 {"Show Z-Order Band", false},
			 {"Show Size", false},
			 {"Special Z-Order Anti-Obstruction", true},
			 {"Font Size", 18},
			 {"Text Background", true},
			 {"Opacity Min (0~1)", 0.75f},
			 {"Opacity Max (0~1)", 0.9f},
			 {"Hide When Menu On", true},
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
			 MAKE_COMBOBOX("Line Color", "Red",
				 {NAMED_COLOR_BASE_LIST}),

			 {"Line Width", 2},
			 {"Info Font Size", 20},
			 {"Show Size", true},
			 {"Mark Sides", true},
			 {"Measure Distances", true},
			 {"Hide When Menu On", true},
		 }
	 },

	 {"Process ESP",
		{
			MAKE_COMBOBOX("New Process Notify Mode",
				"Notify",
				{"Off", "Notify", "Chatter", "Title"}),

			MAKE_COMBOBOX("Exited Process Notify Mode",
				"Notify",
				{"Off", "Notify", "Chatter", "Title"}),

			{"New Process Parent Display", true},
			{"New Process Notify Blacklist Enabled", false},
			{"New Process Notify Blacklist (Regex Sep With Semicolon)", "loader\\.exe;conhost\\.exe;tesseract\\.exe"},
			{"New Process Notify Whitelist Enabled", false},
			{"New Process Notify Whitelist (Regex Sep With Semicolon)", "cmd\\.exe;explorer\\.exe;Hips[a-zA-Z]+\\.exe;360[a-zA-Z0-9]+\\.exe"},

			//{"Exited Process Parent Display", true},
			{"Exited Process Notify Blacklist Enabled", false},
			{"Exited Process Notify Blacklist (Regex Sep With Semicolon)", "loader\\.exe;conhost\\.exe;tesseract\\.exe"},
			{"Exited Process Notify Whitelist Enabled", false},
			{"Exited Process Notify Whitelist (Regex Sep With Semicolon)", "cmd\\.exe;explorer\\.exe;Hips[a-zA-Z]+\\.exe;360[a-zA-Z0-9]+\\.exe"},

			{"Check Cooldown (ms)", 0L},
		}
	 },

	 {"Process Kill",
		 {

			 MAKE_COMBOBOX("Method", "Chain",
				 {"Chain", "Normal", "Thread Killer", "Thread Patcher", "Winsta", "Debugger", "Job", "WMI", "Kernel"}),

			 {"Kill Names (Sep with Semicolon)", "1.exe"},
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

	 { "Regedit",
		 {
			 {"No Wow64 Redirection", true},
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

	 {"Quick Run",
		{
			MAKE_COMBOBOX("Execution", "system & pause",
				{"ShellExecute", "system", "system & pause"}),

			{"Scan Skip Readonly Files", false},
			{"Scan Skip Hidden Files", false},
			{"Scan Skip System Files", false},

			{"Confirm Before Scanning", true},

			{"Output While Scanning", true},
			{"Output Error", false},

			 MAKE_COMBOBOX("Scan Policy", "Lazy",
				 {"Lazy", "Launch", "Daily"}),

			 //{"SAVED PROGRAMS", ""},
			 
		}
	 },

	 {"Open URL",
		 {
			 {"URL", string(XorStringA("https://space.bilibili.com/3494361276877525"))},
		 }
	 },

	 {"Cmd",
		 {
			 {"Run As Admin", false},
			 {"No Wow64 Redirection", true},
		 }
	 },

	 {"Super Cmd",
		{
			MAKE_COMBOBOX("Mode", "System",
				{"Admin", "Admin UAC Bypass", "System", "Trusted Installer"}),

			{"SetPrivileges Waiting Start Timeout (ms)", 5000L},
			{"Enable Privileges", true},
			{"No Wow64 Redirection", true},
		}
	 },

	 {"PowerShell",
		 {
			 {"Run As Admin", false},
			 {"No Wow64 Redirection", true},
		 }
	 },

	 {"Perfmon",
		 {
			 {"Parameters", "/reS"},
			 {"No Wow64 Redirection", true},
		 }
	 },

	 {"Taskmgr",
		 {
			 {"No Wow64 Redirection", true}
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

	 {"Rubbish Clean",
		 {
			 {"Async", true},
			 {"Auto Console", true},
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

	 {"File Manager",
		{
			{"Async File Enum", true},

			MAKE_COMBOBOX("Icon Style", "Character",
				{"Off", "Character", "Normal", "Test"}),

			MAKE_COMBOBOX("File Operation API", "COM",
				{"COM", "Win32"}),

			MAKE_COMBOBOX("Multiple File Open", "Allow",
				{"Off", "Allow"}),

			{"Info Font Size", 25},
			{"File Enum Min Cooldown (ms)", 500L},
			{"File Enum Max Cooldown (ms)", 10000L},
			{"Slow File Enum Item Size Threshold", 50},
			{"Stop File Enum Item Size Threshold", 200},
			{"File Attributes Update Cooldown (ms)", 1000L},
			{"Directory Status Update Cooldown (ms)", 3000L},
			{"File Item Font Size", 35},
			{"File Item Line Gap", 5},
			{"Move Selection Cooldown (ms)", 100L},
			{"Wheel Sensitivity", 200.0f},
			{"Sort Files", true},
			{"File Filter", "*.*"},

			{"Check Directory Is Empty", true},

			{"Show Hidden Files", true},
			{"Show System Files", true},
			{"Show Modified Time", true},
			{"Show Attributes", true},
			{"Show File Size", true},

			//{"Clear Selected Before Using Shift", true},

			{"Drive Enum Cooldown (ms)", 1000L},
			{"Drive Enum Larger Cooldown (ms)", 3000L},
			{"Drive Icon Size", 50},
			{"Drive Font Size", 30},

			MAKE_COMBOBOX("Drive Space Bar Style", "Classic",
				{"Classic", "Absolute"}),

			MAKE_COMBOBOX("Drive Space Text Format", "Free / Total",
				{"Free / Total", "Used / Total"}),

			{"Drive Space Bar Absolute Coefficient (px/GB)", 1.1f},
			{"Drive Space Bar Width", 300},
			{"Drive Space Bar Height", 25},
			{"Drive Space Bar Color Start", "86;156;214;220"},
			{"Drive Space Bar Color End", "255;0;0;220"},
			{"Drive Show Serial Number", true},
			{"Drive Show Volume Label", true},
			{"Drive Show File System", true},

			{"Calc Selected Total Size", true},

			//{"Calc Selected Folder Total Size", true},
			MAKE_COMBOBOX("Calc Selected Folder Size", "Off",
				{"Off", "Async", "Sync"}),

			/*MAKE_COMBOBOX("Calc File Size Execution Policy", "Sync",
				{"Sync", "Async"}),*/
			
			MAKE_COMBOBOX("Deletion Confirmation", "Only Force",
				{"Off", "Only Force", "Always"}),

			MAKE_COMBOBOX("Sort By", "Name",
				{"Name", "Type", "Size", "Modified Time"}),

			MAKE_COMBOBOX("Sort Order", "Ascending",
				{"Ascending", "Descending"}),

			MAKE_COMBOBOX("UAC Bypass Method", "Computerdefaults Legit",
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

			{"Selected Item Background Color", "66;90;123;200"},
			{"Hovered Item Background Color", "239;200;244;90"},
			{"Selected Item Outline Color", "18;74;143;200"},
			{"Hovered Item Outline Color", "151;4;148;200"},

			{"Menu Outline Color", "255;185;15;255"},
			{"Menu Background Color 1", "16;78;139;220"},
			{"Menu Background Color 2", "69;139;0;220"},
			{"Menu Background Darkness (0~1)", 0.8f},

			{"Menu Basic Alpha (0~1)", 0.4f},
			{"Menu Mask Alpha (0~1)", 0.3f},
			{"Menu Shadow", true},
			{"Menu Shadow Thickness", 30.0f},
			MAKE_COMBOBOX("Menu Shadow Color", "Black",
			{NAMED_COLOR_BASE_LIST}),

			{"Menu Font Size", 30},
			{"Menu Line Gap", 10},
			{"Menu Animation Duration (ms)", 200L},
			{"Menu Easing Speed (0~1)", 0.1f},

			{"Enable Night Module", true},

			{"Go to Parent Folder Hotkey", {{"Keybind", {VK_BACK}}}},
			{"Cancel Selection Hotkey", {{"Keybind", {VK_ESCAPE}}}},
		}
	},

	 {"Disk Missing",
		 {
			 {"Keep", true},
			 {"Signal Cooldown (ms)", 80L},

			 MAKE_COMBOBOX("Missing Drives", "System Drive",
				 {"System Drive", "All", "Custom"}),

			 {"Custom Missing Drives", "D;E"},
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
			 {"Skip Folders", false},
			 {"Skip Readonly Files", true},
			 {"Skip Hidden Files", true},
			 {"Skip System Files", true},
			 {"IDCard Valid Year Min", 1914},
			 {"IDCard Valid Year Max", 2024},
			 {"IDCard Strict Validify", true},
			 {"Person Name Character Max Count", 3},
			 {"Filter File Extensions", true},
			 {"Included File Extensions", ".txt;.md;.rtf;.doc;.ppt;.xls;.docx;.pptx;.xlsx;.wps;.zip;.rar;.7z;.gz;.c;.cpp;.h;.hpp;.java;.py;.cs;.exe;.sln;.jpg;.png;.bmp;.mp3;.m4a;.mp4;.html;.htm;.css;.js;.db"},

			 {"Scan Disk Privacy", true},
			 {"Confirm Before Scanning", true},
			 {"Find Other Privacy", true},
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

	 {"Online Time",
		 {
			 {"Connect Timeout (s)", 3L},

			 MAKE_COMBOBOX("Source", "Taobao",
				 {"Taobao", "Time.is", "Suning"}),
		 }
	 },

	 {"IP Address",
		 {
			 {"Async", true},
			 {"Auto Console", true},

			 MAKE_COMBOBOX("Method", "Curl",
				 {"Curl", "Command"}),

			 MAKE_COMBOBOX("External IP Address Source URL", "https://api.ip.sb/ip",
				 {
				 "https://api.ip.sb/ip",
				 "http://www.ipchicken.com",
				 "http://whatismyipaddress.com",
				 "http://api.ipify.org"
				 }),

		     MAKE_COMBOBOX("IP Location Query Source", "Vore.top",
				{
					"Vore.top",
					"PearAPI",
					"IQIYI"
				}),

			 {"Connect Timeout (s)", 5L},
			 {"Output Verbose Connection Info", false},
			 {"Query External IP", true},
			 {"Query External IP Position", true},
			 {"AI Generated Description of IP Position", false},
			 {"Use HTTPS When Query Position", true},
			 {"Output Local IP Details", true},
		 }
	 },

	 {"IP Horror",
		 {
			 {"Async", true},
			 {"Auto Console", true},
			 {"Copy to Clipboard", true},
			 {"Log Destination Info", true},
			 {"Target IP Address", "127.0.0.1"},

			 MAKE_COMBOBOX("Method", "V1",
			 {"V1", "AI Normal", "AI Mesugaki", "AI Catgirl"})
		 }
	 },

	 {"Phone Area",
		 {
			 {"Auto Console", true},
			 {"Phone Number (actually just need first 7 digits)", 1234567LL},
			 {"Connect Timeout (s)", 4L},
			 {"Notify", false},
		 }
	 },

	/*{"Wall Check",
		{
			{"Website", "www.youtube.com"},
			{"Connect Timeout (s)", 10L}
		}
	},*/

	{"Weather Info",
		{
			{"Async", true},
			{"Auto Console", true},
			{"Use Custom QWeather ApiKey", false},
			{"Custom QWeather ApiKey", ""},
			{"Use Custom QWeather ApiHost", false},
			{"Custom QWeather ApiHost", ""},

			MAKE_COMBOBOX("City", "Auto Locate",
				{"Auto Locate", "Custom"}),

			{"Custom City", "北京市"},
			{"Connect Timeout (s)", 10L},
		}
	},

	//{"Bili Cookies",
	//	{
	//		{"Connect Timeout (s)", 3L},
	//	}
	//},
	{"Bili Console",
		{
			{"Auto Console", true},
			{"Debug Output", false},

			{"Draw Periodically", false},
			{"Draw Cooldown (ms)", 500L},
			{"Update Periodically", false},
			{"Update Cooldown (ms)", 180000L},

			{"Use Chinese Number Format", true},

			{"User Medal Wall Display", true},
			{"User Medal Wall X", 110},
			{"User Medal Wall Y", 3},
			{"Show User Space Notice", true},
			{"Show User Like Videos", true},
			{"Show User Coin Videos", true},
			{"Show User Top Video", true},
			{"Show User Masterpieces", true},
			{"Show User Favorite Folders", true},

			{"Single Coin Quantity", 2U},
			{"Like When Coin", true},
		}
	},

	 {"Bili Fans",
		 {
			 {"Async", true},
			 {"User IDs (Sep With Semicolon)", WORMWAKER_MID},
			 {"Update Cooldown (s)", 60L},
			 {"Connect Timeout (s)", 5L},
			 {"HUD", false},
			 {"Hide HUD When Menu On", true},

			 MAKE_COMBOBOX("Action On Failure", "Pause Temporarily", 
			   {"Ignore", "Pause Temporarily", "Disable Module"}),

			 {"Threshold Max", 16U},

			{"Pause Duration (s)", 30L},
			 
			 MAKE_COMBOBOX("HUD Color", "Colorful",
				{NAMED_COLOR_BASE_LIST}),

			{"HUD User Index (Sep With Semicolon)", ""},
			{"HUD Font Size", 30},
			{"HUD Line Gap", 5},
			{"HUD Opacity (0~1)", 0.8f},

			 MAKE_COMBOBOX("HUD Format", "Fans: Number",
				 {"Number", "Fans: Number", "Number Fans", "Name Fans: Number", "Name: Number", "Name: Number Fans"}),

			 MAKE_COMBOBOX("Notify Mode", "Notify",
			 {"Off", "Notify", "Console Output", "Actionbar", "Chatter", "Title", "WinToast", "Speak"}),

			 {"Notify Fans Increase", true},
			 {"Notify Fans Decrease", true},
			 {"Custom Fans Increase Sound", "levelup.wav"},
			 {"Custom Fans Decrease Sound", "pling_low.wav"},
			 //{"Notify Prefixes (Sep With Semicolon)", "UP"},

			 {"HUD X Rate", 0.8f},
			 {"HUD Y Rate", 0.75f},

			 //{"PREV DATA", "{}"},
		 }
	 },

	 {"Bili Feed",
		{
			{"Async", true},
			{"Auto Console", true},
			{"Connect Timeout (s)", 5L},
			{"Limit", 100U},

			MAKE_COMBOBOX("Style", "Simple",
				{"Simple", "List", "Fancy"}),
		}
	},

	 {"Bili Hot",
		{
			{"Async", true},
			{"Auto Console", true},
			{"Connect Timeout (s)", 5L},
			{"Limit", 20U},

			MAKE_COMBOBOX("Interface", "Standard",
				{"Standard", "Mobile"}),

			{"Show Heat Score (Standard)", true},
			{"Show Top (Mobile)", true},
		}
	 },

	{"Bili Notifier",
		{
			{"Async", true},

			MAKE_COMBOBOX("Mode", "Notify",
				{"Off", "Notify", "Chatter", "Actionbar", "Title", "WinToast"}
				),

			{"Query Cooldown (s)", 5L},
			{"Connect Timeout (s)", 4L},

			{"Ignore Negative Changes", true},

			{"Notify Ats", true},
			{"Notify Chats", true},
			{"Notify Likes", true},
			{"Notify Comments", true},
			{"Notify Coins", true},
			{"Notify Danmaku", true},
			{"Notify Favorites", true},
			{"Notify Uploader Helper Messages", true},
			{"Notify System Messages", true},

			{"PREVIOUS DATA", "{\"at\":0,\"chat\":0,\"coin\":0,\"danmu\":0,\"favorite\":0,\"like\":0,\"recv_like\":0,\"recv_reply\":0,\"reply\":0,\"sys_msg\":0,\"up\":0}"}
		}
	},

			{"Bili Components",
				{
					{"User ID", WORMWAKER_MID},
					{"Output", true},
				}
			},

			{"Bili Profile",
				{
					{"Async", true},
					{"Auto Console", true},
					{"User ID", WORMWAKER_MID},
					{"Connect Timeout (s)", 5L},
					{"Show Like Videos", true},
					{"Show Coin Videos", true},
					{"Show Top Video", true},
					{"Show Masterpieces", true},
					{"Show Space Notice", true},
					{"Show Favourite Folders", true},
					//{"Show Collect Folders", true},
					{"Like Videos Max Shown", 3},
					{"Coin Videos Max Shown", 3},
					{"Masterpieces Max Shown", 3},
				}
			},

			{"Bili Video Cover",
				{
					{"Async", true},
					
					MAKE_COMBOBOX("Mode", "Clipboard Forward", 
					{"Clipboard Forward", "Clipboard Output Link", "Clipboard Download Image"}),

					{"Keep", false},

				}
			},

			{"Bili Video",
				{
					{"Async", true},
					{"Auto Console", true},
					{"AID/BID/Link", ""},

					MAKE_COMBOBOX("Mode", "Once",
						{"Once", "Monitor"}),

					{"No Decrease Notification", false},

					{"Speak Changes", false},

					MAKE_COMBOBOX("Notify Mode", "Chatter",
						{"Off", "Notify", "Chatter", "Actionbar", "Title", "WinToast"}),

					{"Connect Timeout (s)", 4L},
					{"Query Cooldown (s)", 1L},
				}
			},

			{"Bili Settings",
				{
					{"Black Capture When Login", false},
					{"Close Menu When Login", true},
					{"Debug Output", false},
					{"Login QR Code Scale", 6.0f},

					/*{"Cookies (DO NOT LEAK)", ""},
					{"Cookies Json (DO NOT LEAK)", "{}"},
					{"REFRESH TOKEN", ""},*/
				}
			},

			{"Web Settings",
				{
					MAKE_COMBOBOX("Network Online Status Change Notify Mode", "Notify",
						{"Off", "Notify", "Title", "Chatter", "WinToast"}),

					{"Network Check Cooldown (ms)", 5000U},
					{"Network Check Website", "http://captive.apple.com/"},
					{"Network Module Force Online", true},

					MAKE_COMBOBOX("Output Curl Error", "Always",
						{"Off", "Non Timeout", "Always"}),
				}
			},

			{"AI Settings",
				{
					MAKE_COMBOBOX("AI Type", "PearAPI",
						{"Spark", "Dashscope", "ChatAnywhere", "PearAPI", "Custom"}),

					{"AI Role Prompt", "You are a helpful assistant."},
					{"AI Temperature", 0.3f},
					{"AI Top P", 0.8f},

					MAKE_COMBOBOX("Command /chat Mode Without Arguments", 
						"Input Box",
						{"Input Box", "Clipboard"}),

					{"Command /chat Prompt Prefix", ""},
					{"Command /chat Show Session", true},
					{"Command /chat Force Stream", true},

					{"Dashscope Use EnvVar ApiKey: DASHSCOPE_API_KEY", true},
					{"Dashscope API Key", "sk-"},

					{"Spark Use EnvVar ApiKey: SPARK_API_KEY", true},
					{"Spark API Key", ""},

					{"ChatAnywhere Use EnvVar ApiKey: CHATANYWHERE_API_KEY", true},
					{"ChatAnywhere API Key", "sk-"},

					{"Custom AI Use EnvVar ApiKey", false},
					{"Custom AI Use EnvVar ApiKey Name", ""},
					{"Custom AI API Key", ""},
					{"Custom AI Base URL", "https://"},
					{"Custom AI Model", ""},

					MAKE_COMBOBOX("Dashscope Model", "qwen-turbo",
					{"qwen-turbo", "qwen-long", "qwen-max", "qwen-plus", "qwen-math-plus", "qwen-coder-plus", "qwen-coder-turbo"}),

					MAKE_COMBOBOX("Spark Model", "Spark Lite",
						{ "Spark 4.0 Ultra", "Spark Max", "Spark Max-32K", "Spark Pro", "Spark Pro-128K", "Spark Lite"}),

					MAKE_COMBOBOX("PearAPI Model", "Deepseek r3",
						{ "Deepseek r3" }),

					MAKE_COMBOBOX("ChatAnywhere Model", "gpt-3.5-turbo",
						{"gpt-3.5-turbo", "gpt-4o-mini", "gpt-4.1-mini", "gpt-4.1-nano", "gpt-5-mini", "gpt-5-nano", "deepseek-r1", "deepseek-v3", "deepseek-v3-2-exp", "gpt-5", "gpt-4o", "gpt-4.1"}),

					MAKE_COMBOBOX("Response Console Output Format", "Markdown",
						{"Markdown", "Markdown With Marks", "Raw", "Plaintext"}),

					{"Debug Output", false},

					MAKE_COMBOBOX("Chat History Default Storage Policy", "Temporary",
						{"Temporary", "Records", "Files"}),

					{"Chat History Sessions Saved in Records (Sep With Semicolon)", ""},
					{"Chat History Sessions Saved in Files (Sep With Semicolon)", "livestream"},
				}
			},

			{"Agent",
				{
					MAKE_COMBOBOX("Current Instruction", "Run",
						{"Run", "Pause", "Stop"}),

					{ "Pause Task Hotkey", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_NUMPAD0}}} },

					{"Correct JSON Format", true},
					{"Max Allowed Asks", 100},
					{"Max Allowed File Operations", 100},
					{"Max Allowed Commands", 50},
					{"Max Allowed Repeated Commands", 3},

					MAKE_COMBOBOX("Command Confirmation", "MessageBox",
					{"Always Allow", "AI Basic Check", "MessageBox", "Console"}),

					MAKE_COMBOBOX("File Confirmation", "AI Basic Check",
					{"Always Allow", "AI Basic Check", "MessageBox", "Console"}),

					{"MessageBox Confirm Timeout Enabled", true},
					{"MessageBox Confirm Timeout (ms)", 60000L},

					MAKE_COMBOBOX("MessageBox Confirm Timeout Operation", "Cancel",
						{"Accept", "Decline", "Cancel"}),

					{"Output Real Ask", true},
					{"Allow Tool Preparation Missing", false}
				}
			},

			{"Live Stream",
				{
					{"Room ID", 31196635},
					{"Max Allowed Chatter Delay (s)", 20U},
					{"Single Chatter Length Limit", 40U},

					MAKE_COMBOBOX("Chatter Color", "White",
						{"White", NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Chatter Display", "Chatter",
						{"Off", "Chatter", "Notify", "Title", "Actionbar"}),

					{"Chatter Horizontal Reverse", false},

					MAKE_COMBOBOX("Actionbar Color", "Colorful",
						{NAMED_COLOR_BASE_LIST}),

					{"Chatter Console Output", true},
					{"Chatter Console Output Timestamp", true},
					{"Chatter Console Output Wealth & Medal", true},

					{"Chatter File Output", false},
					{"Chatter File Output Format", "{{content}}`{{nickname}}"},
					{"Chatter File Output Path", "output\\Chatters.txt"},

					{"Chatter User Whitelist Enabled", false},
					{"Chatter User Whitelist (Sep With Semicolon)", "Wormwaker;Worrnwaker"},
					{"Chatter User Blacklist Enabled", false},
					{"Chatter User Blacklist (Sep With Semicolon)", ""},

					MAKE_COMBOBOX("Title Color", "White",
						{NAMED_COLOR_BASE_LIST}),

					{"Title Font Size", 150},

					{"Chatter Custom Filter Enabled", false},
					{"Chatter Custom Filter Keywords (Sep With Semicolon)", ""},

					MAKE_COMBOBOX("Chatter Taboo Filter", "Block",
						{"Off", "Block", "Filtered", "Replace (Unsafe)"}),

					MAKE_COMBOBOX("Chatter Remote Execution (Riskful)", "Disabled",
						{"Disabled", "Wormwake"}),

					{"Chatter Remote Execution Username Whitelist (Sep with Semicolon)", "Wormwaker;Worrnwaker"},
					
					MAKE_COMBOBOX("Chatter Remote Execution Privileges Policy", "Admin & Normal",
					{"Everyone Admin", "Admin & Normal", "Only Admin", "Everyone Normal"}),

					{"Chatter Remote Execution Display", false},
					{"Chatter Remote Execution Notify", true},

					MAKE_COMBOBOX("Chatter Speaker", "Off",
						{"Off", "Username & Text", "Only Text"}),

					{"Chatter Speaker User Whitelist Enabled", false},
					{"Chatter Speaker User Whitelist (Sep With Semicolon)", "Wormwaker;Worrnwaker"},
					{"Chatter Speaker User Blacklist Enabled", false},
					{"Chatter Speaker User Blacklist (Sep With Semicolon)", ""},

					MAKE_COMBOBOX("Chatter Translator", "Off",
						{"Off", "Chinese", "English", "Exchange"}),

					{"Chatter Speaker Skip Emoji", true},

					{"Chatter Speaker Async", true},

					MAKE_SOUNDITEM("Chatter Sound", "Off"),

					{"Chatter Triggers Enabled", false},
					{"Chatter Trigger Disable Speaker", true},
					{"Chatter Triggers Using Regex", true},
					{"Chatter Triggers Config Path", "config\\liveStreamChatterTriggers.ini"},

					MAKE_COMBOBOX("Chatter AI Response", "Off",
					{"Off", "Notify", "Speak", "Chatter", "Title", "Actionbar", "Real Chatter"}),

					MAKE_COMBOBOX("Chatter AI Response Chatter Type", "Top",
					{"Scroll", "Top", "Bottom", "Reverse", "Horizontal", "Vertical", "Random"}),	// 弹幕类型

					MAKE_COMBOBOX("Chatter AI Response Chatter Color", "Red",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Chatter AI Response Title Color", "Red",
						{NAMED_COLOR_BASE_LIST}),

					{"Chatter AI Response Prefix", true},
					{"Chatter AI Response Prompt", "请用简要的语言回复这条直播间弹幕，最好不要超过20字，但是不要复述弹幕："},
					{"Chatter AI Response Prompt (With Contexts)", "请用简要的语言和直播间弹幕进行对话，每次你的输出一定不要超过40字，我将会给你 用户名:消息 的形式，一定要区分不同用户的消息。下面开始对话。"},
					{"Chatter AI Response Cooldown (ms)", 5000L},
					{"Chatter AI Response Contexts Enabled", true},
					{"Chatter AI Response User Blacklist Enabled", true},
					{"Chatter AI Response User Blacklist (Sep With Semicolon)", "Wormwaker;Worrnwaker"},

					{"Connect Timeout (s)", 8L},

					MAKE_COMBOBOX("Notify Audience Enter", "Off",
						{"Off", "Notify", "Chatter", "Speak", "Title", "Actionbar"}),

					MAKE_COMBOBOX("Notify Audience Enter Chatter Color", "Colorful",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Notify Audience Leave", "Off",
						{"Off", "Notify", "Chatter", "Speak", "Title", "Actionbar"}),

					MAKE_COMBOBOX("Notify Audience Leave Chatter Color", "Black",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Audience Enter Preset", "Enter",
						{"Enter", "Welcome", "Join"}),

					MAKE_COMBOBOX("Audience Leave Preset", "Leave",
						{ "Leave", "Depart"}),

					{"Notify Audience Face Download", false},

					{"HUD", true},
					{"HUD X Rate", 0.05f},
					{"HUD Y Rate", 0.2f},
					{"HUD Information Font Size", 30},
					{"HUD Show Basic Information", true},
					{"HUD Show Online Audience", true},
					{"HUD Online Audience Update Cooldown (ms)", 8000L},
					{"HUD Online Audience Max Count", 8U},
					{"HUD Online Audience Nickname Font Size", 20},
					{"HUD Online Audience Face", true},
					{"HUD Online Audience Face Update Cooldown (d)", 7},
					{"HUD Online Audience Line Gap", 35},
					{"HUD Online Audience Background", true},
					{"HUD Online Audience Background Opacity (0~1)", 0.5f},
				}
			},

			{"QQ Bot",
				{
					{"Scan Cooldown (ms)", 5000L},
					{"Others Message Max X Rate", 0.4f},
					{"Own Message Min X Rate", 0.41f},
					{"Recognize Min Confidence (0~100)", 80.0f},
				}
			},

			{"QQ Inspect",
				{
					{"Async", true},
					{"Auto Console", true},
					{"Connect Timeout (s)", 3L},
					{"Close Menu", true},
					{"Notify Basic Info", false},
					{"Notify Others", false},
					{"Output Steps", false},
					{"Output Verbose Connection Info", false},
					{"Scan Port Min", 4300},
					{"Scan Port Max", 4305},
				}
			},

			{"QQ Bind Query",
				{
					{"Async", true},
					{"Auto Console", true},
					{"QQ Number", "114514"},
					{"Query Microblog", true},
					{"Connect Timeout (s)", 3L},
				}
			},

			{"System Proxy",
				{
					{"Proxy Server", ""},
					{"Proxy Override", ""},
					{"Options Sync Cooldown (ms)", 10000L},
					{"Notify", true},
					//{"Config Auto Sync", true},
				}
			},

			{"ScreenSaver",
				{
					{"Use Custom Program", false},
					{"Your Custom Program", "null"},
					{"Display On Client", true},
					{"Disable ForceTopmost", true},
					{"Disable Night", true},
					{"Disable Gamma", false},
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

			{"No Animation",
				{
					{"Async When Enabling", false},
					{"Async When Disabling", false},
				}
			},

			{"Mouse ESP",
				{
					{"Visibility Check", true},
					{"Circle", false},
					{"Circle Radius", 25.0f},
					{"Circle Opacity (0~1)", 0.3f},
					
					{"Box", true},
					{"Box Easing", false},
					{"Box Easing Speed (0~1)", 0.2f},
					{"Box Line Width", 2},
					{"Box Width Rate", 1.0f},
					{"Box Height Rate", 1.2f},
					{"Box Opacity (0~1)", 0.8f},
					{"Box Rounded Corners", true},

					{"Coordinates", false},
					{"Coordinates Font Size", 30},
					{"Coordinates Opacity (0~1)", 0.5f},
					{"Coordinates X Offset", 5},
					{"Coordinates Y Offset", 5},

					MAKE_COMBOBOX("CPS Display", "Off",
					{"Off", "CPS Left | Right", "Left | Right", "Left", "Right"}),

					{"CPS Opacity (0~1)", 0.5f},
					{"CPS Font Size", 30},

					MAKE_COMBOBOX("Box Color", "Rainbow",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Circle Color", "Yellow",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Circle Color (Left Click)", "Blue",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Circle Color (Right Click)", "Pink",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Circle Color (Middle Click)", "Red",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Coordinates Color", "Rainbow",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("CPS Color", "Aqua-Pink",
					{NAMED_COLOR_BASE_LIST}),
				}
			},

			{"Mouse Trails",
				{
					{"Async When Enabling", false},
					{"Async When Disabling", false},
				}
			},

			{"Spotlight",
				{
					{"Mask Alpha (0~1)", 0.75f},
					{"Circle Alpha (0~1)", 0.7f},

					{"Animation Duration (ms)", 700L},
					{"Circle Radius", 75.0f},

					MAKE_COMBOBOX("Mask Color", "Black",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Circle Color", "White",
					{NAMED_COLOR_BASE_LIST}),
				}
			},

			{"Crosshair",
				{
					{"Advanced Mode", false},
					{"Advanced Mode Show HUD", true},
					{"Advanced Mode Hotkey", {{"Keybind", {VK_LMENU, VK_RMENU}}}},
					{"Advanced Mode Allow No Focus", false},
					{"Crosshair Line Width", 2},
					{"Crosshair Line Opacity (0~1)", 0.9f},
					{"Crosshair Hollow Enabled", true},
					{"Crosshair Hollow Radius", 80},

					MAKE_COMBOBOX("Crosshair Line Color", "Rainbow",
						{"White", "Red", "Green", "Blue", "Magenta", "Colorful", "Rainbow"}),

					{"Crosshair Line Wave Color", true},

					MAKE_COMBOBOX("Crosshair Line Combination Type", "Plus",
						{"Horizontal", "Vertical", "Plus", "X", "Plus & X"}
						),

					{"Coord Font Size", 30},
					{"HUD Font Size", 25},
					{"HUD Line Gap", 5},
					{"HUD Opacity (0~1)", 0.9f},
					{"Hide When Menu On", false},
				}
			},

			{"Keystrokes",
				{
					MAKE_COMBOBOX("Text Color", "Rainbow",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Outline Color", "Rainbow",
						{NAMED_COLOR_BASE_LIST}),

					{"X Rate", 0.9f},
					{"Y Rate", 0.7f},
					{"Box Size", 54},
					{"Box Gap", 15},
					{"Box Opacity (0~1)", 1.0f},
					{"Font Size", 43},
					{"Space", true},
					{"Shift", true},
					{"Mouse Buttons", true},
					{"Hide When Menu On", false},
					{"Show CPS", true},
					{"Give Way to Mouse", true},
					{"Easing Speed (0~1)", 0.1f},
					{"Round Corners", false},
					{"Shadow", true},
					{"Shadow Thickness", 20.0f},

					MAKE_COMBOBOX("Shadow Color", "Black", {NAMED_COLOR_BASE_LIST})
				}
			},

{"Keystrokes2",
	{
		//{"Instant Tips", true},
		{"Box Width", 55},
		{"Box Height", 70},
		{"Box Gap", 15},
		{"Box Opacity (0~1)", 1.0f},

		MAKE_COMBOBOX("Text Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Outline Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),

		{"Font Size Rate", 1.5},
		{"Bigger Font Size Of Single Char Key", false},
		{"X Rate", 0.5f},
		{"Y Rate", 0.87f},

		MAKE_COMBOBOX("Alignment", "Center",
			{"Center", "Left", "Right"}),

		{"Hide When Menu On", false},
		{"Easing Speed (0~1)", 0.1f},
		{"Key Display Max Count", 10U},
		{"Bigger Pressed", true},
		{"Give Way to Mouse", true},
		{"Give Way to Mouse Distance", 200.0},
		{"Show Number Below", true},
		{"Number Display Recent", true},
		{"Number Color Show Recent", true},
		{"Hide Mouse Buttons", false},
		{"Hide F13-F24", true},
		{"Toggle KeyReaction Module", true},

		{"Round Corners", false},
		{"Shadow", true},
		{"Shadow Thickness", 20.0f},

		MAKE_COMBOBOX("Rain Effect", "Off", 
		{"Off", "Rise", "Fall"}),

		MAKE_COMBOBOX("Rain Effect Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),

		{"Rain Effect Opacity (0~1)", 0.5f},
		{"Rain Effect Whiteness (0~1)", 0.8f},
		{"Rain Effect Width Rate (0~1)", 0.8f},
		{"Rain Effect Height", 250},
		{"Rain Effect Fade Height", 60},
		{"Rain Effect Speed", 10.0f},

		MAKE_COMBOBOX("Shadow Color", "Black", {NAMED_COLOR_BASE_LIST})
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
		{"Show Text Stats", true},
		{"Hide When Menu On", true},
		{"X Rate", 0.16},
		{"Mid Y Rate", 0.3},
	}
},

{"Security ESP",
	{
		{"Hide When Menu On", true},
		{"Show Description When Mouse Hovering", true},

		MAKE_COMBOBOX("Title Color", "Red",
		{NAMED_COLOR_BASE_LIST}),

		{"HUD Font Size", 30},
		{"HUD Line Gap", 5},
		{"X Rate", 0.8},
		{"Mid Y Rate", 0.5},
	}
},

{"PPL ESP",
	{
		{"Hide When Menu On", true},
	}
},

{"Minecraft",
	{
		MAKE_COMBOBOX("Crosshair", "Vanilla",
			{"Off", "Vanilla"}),

		MAKE_COMBOBOX("Crosshair Color", "Smart",
			{"Smart", NAMED_COLOR_BASE_LIST}),

		{"Crosshair Scale", 1.0f},
		{"Crosshair Opacity (0~1)", 1.0f},
		

		{"Hide When In Minecraft", false},
		{"Hand Enabled", true},
		{"Hand Scale", 6.0f},
		{"Hand Texture Name", "iron_sword.png"},
		{"Hand X Addition", 0.0f},
		{"Hand Y Addition", 0.0f},
		{"Hand Move X Range", 400.0f},
		{"Hand Move Y Range", 1000.0f},
		{"Hand Rotation Base (Degrees)", -150.0f},
		{"Hand Rotation Turn Coefficient (0~1)", 0.35f},
		{"Hand Opacity (0~1)", 1.0f},

		MAKE_COMBOBOX("Hand Left Click Action", "Wield",
			{"Off", "Wield"}),

		{"Hand Wield Action Rotation Changes (Degrees)", 25.0f},
		{"Hand Left Click Action Duration (ms)", 400L},

		MAKE_COMBOBOX("Hand Right Click Action", "Block",
			{"Off", "Block"}),

		{"Hand Block Action Rotation Changes (Degrees)", -45.0f},
	}
},

{"Motion Blur",
	{
		/*MAKE_COMBOBOX("Mode", "Accumulation",
			{"Superposition", "Accumulation"}
			),*/

		MAKE_COMBOBOX("Apply Area", "Screen",
			{"Client Only", "Screen"}),

		//{"Accumulation Alpha Blend (0~1)", 0.2f},

		MAKE_COMBOBOX("Apply Model", "Exponential",
			{"Gaussian", "Exponential"}),

		{"Update Cooldown", 40},
		{"Frame Count", 5},
		{"Gaussian Sigma", 0.9f},
		{"Exponential Lambda", 0.5f},
		{"Darken When Blur", false},
		{"Gaussian Darken Amount (0~1)", 0.4f},
		{"Exponential Darken Amount (0~1)", 0.45f},

		{"Blur Enabled", true},
		{"Blur Strength", 2.0f},
		{"Blur Samples", 5},
		{"Blur Once", true},
		{"Blur Alpha Boost (0~1)", 0.0f},
		{"Blur Brightness Boost (0~1)", 0.3f},

		{"Redraw Client Texture", true},
		{"Test 1", true},

		MAKE_COMBOBOX("Blur Direction", "Both",
			{"Off", "Horizontal", "Vertical", "Both"})
	}
},

{"Background",
	{
		MAKE_COMBOBOX("Filter Type", "Off",
			{"Off", NAMED_COLOR_BASE_LIST}),

		{"Filter Opacity (0~1)", 0.5f},
		{"Lightness (0~1)", 0.5f},
		{"Hide Filter When No Focus", true},

		MAKE_COMBOBOX("When to Apply Filter", "Menu On",
			{"Always", "Menu On", "Menu Off"}),

		{"Screen Compensation", false},
		{"Screen Compensation Faster", true},

		MAKE_COMBOBOX("When to Apply Screen Compensation", "Always",
			{"Always", "Menu On", "Menu Off"}),

		{"Screen Compensation Cooldown (ms)", 250U},
	}
},

{"GUI Blur",
	{
		MAKE_COMBOBOX("Style",					// 风格（在修复开启时三种模式貌似完全一样）
		"Mica",
		{"Off", "Mica", "Acrylic", "Test"}),

		{"Fix", true},							// 修复（请开启该选项）

		MAKE_COMBOBOX("Dark Mode", "On",		// 深色模式
			{"Off", "On", "Auto"}),

		{"Hide When No Focus", true},			// 无焦点时隐藏
	}
},

{"Custom HUD",
	{
		{"Global Scale", 1.0f},
		{"Default Font Size", 30},
		{"Hide HUD When Menu On", true},
		{"Shell Mover Speed", 10},
		{"Elements", "[]"},
	}
},

{"Island",
	{
		{"Font Size", 40},
		{"Width Addition", 40},
		{"Height Addition", 15},
		{"Easing Speed (0~1)", 0.1},
		{"Show Brand", true},
		{"Show User", true},
		{"Local User", true},
		{"Show FPS", true},
		{"Show Time", true},
		{"Show Volume", false},
		{"Show Web", true},
		{"Show Game", true},

		MAKE_COMBOBOX("Show Location", "Off",
			{"Off", "Short", "Details"}),

		{"Show Other", true},

		{"Hide When Idle", false},
		{"Sync Notify Status", true},
		{"Sync Progress Status", true},
		{"Sync Title Status", true},
		{"Sync Actionbar Status", false},
		
		{"Outline Thickness", 3.0f},
		{"Outline Darkness (0~1)", 0.2f},
		{"Round Corners", true},
		{"Roundness", 0.3f},
		{"Background", true},
		{"Background Darkness (0~1)", 0.6f},
		{"Background Opacity (0~1)", 0.9f},
		{"Shadow", false},
		{"Shadow Thickness", 10.0f},
		{"Show Icon", true},
		{"Give Way to Mouse", true},
		{"Give Way to Mouse Intensity", 0.5f},

		{"Location Update Cooldown (ms)", 30000L},

		{"Line Height Scale", 1.5f},
		{"Icon Opacity (0~1)", 1.0f},
		{"Clip Strictly", true},
		{"Fade Duration (ms)", 500L},
		{"Fade Color", true},
		{"Gradient Color", true},
		{"Background Image", false},
		{"Background Image Path", ""},
		{"Background Image Scale", 1.0f},
		{"Background Image Opacity (0~1)", 0.5f},
		{"Background Image Moving Speed", 0.5f},
		{"Lyrics Text Color", "255;109;194;255"},
		{"Lyrics Animation Duration (ms)", 500L},
		{"Lyrics Effect Duration (ms)", 1000L},
		{"Lyrics Garble", "·"},

		MAKE_COMBOBOX("Lyrics Effect", "Off",
		{"Off", "Garble Slide", "Garble Dissolved", "Unfold"}),

		MAKE_COMBOBOX("Lyrics Decorations", "Off",
		{"Off", "Prefix", "Suffix", "Prefix + Suffix"}),

		MAKE_COMBOBOX("Lyrics Decoration Type", "Slash",
		{"Slash", "Sharp", "Circle", "Chinese Number", "Chinese Number II"}),

		MAKE_COMBOBOX("Outline Color", "Red",
			{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Background Color", "Black",
			{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Shadow Color", "Black",
			{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Idle Text Color", "White",
			{NAMED_COLOR_BASE_LIST}),

		{"Notify Success Text Color", "84;255;159"},
		{"Notify Error Text Color", "255;114;86"},
		{"Notify Info Text Color", "127;127;127"},
		{"Notify Warning Text Color", "255;222;173"},

		{"Vibration Frequency", 3.0f},
		{"Vibration Amplitude", 2.0f},
		{"Y Rate", 0.12f}
	}
},

{"Time Display",
	{
		{"Font Size", 50},
		{"X Rate", 0.05f},
		{"Y Rate", 0.8f},
		//{"Half Hour Notify", true},

		{"Online Time", false},
		{"Online Time Update Cooldown (ms)", 60000L},

		MAKE_COMBOBOX("Half Hour Notification", "Notify",
		 {"Off", "Notify", "Chatter", "WinToast", "Title", "Actionbar"}),

		MAKE_COMBOBOX("Half Hour Title Color", "Aqua-Blue",
			{NAMED_COLOR_BASE_LIST}),

		{"Half Hour Title Font Size", 200},

		{"Half Hour Highlight", true},

		MAKE_COMBOBOX("Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("New Day Notification", "Title",
		{"Off", "Notify", "Chatter", "WinToast", "Title", "Actionbar"}),

		MAKE_COMBOBOX("New Day Title Color", "White",
			{NAMED_COLOR_BASE_LIST}),

		{"New Day Title Font Size", 300},

		{"Whiter", true},
		{"Wave Color", true},
		{"Transparent", true},
		{"Text Background", false},
		{"Hide When Menu On", false}
	}
},

{"Arraylist",
	{
		{"Hide When Menu On", false},
		{"Give Way to Mouse", true},
		{"Give Way to Mouse Distance", 80.0f},
		{"Font Size", 36},
		{"Line Gap", 9},
		{"Top", 60},

		MAKE_COMBOBOX("Global Position", "Screen",
			{"Screen", "Foreground", "PointAt"}),

		MAKE_COMBOBOX("Position", "Right", {"Left", "Right"}),

		{"Side Margin", 12},
		{"Side Bar", false},
		{"Easing Speed (0~1)", 0.2f},
		{"Removed Item Offset Y", 0.0f},
		{"Opacity Min (0~1)", 0.66f},
		{"Opacity Max (0~1)", 0.72f},
		{"Opacity Period (ms)", 3000L},
		//{"Animation Duration", 2000L},

		{"Show Combat", true},
		{"Show Window", true},
		{"Show Process", true},
		{"Show Registry", true},
		{"Show Control", true},
		{"Show Web", true},
		{"Show Render", true},
		{"Show Misc", true},
		{"Show Drivers", true},
		{"Show Info", true},

		MAKE_COMBOBOX("Info Color", "White-Gray",
			{NAMED_COLOR_BASE_LIST}),

		{"Info Gap", 20},
		/*	{"Rainbow Modules", true},
#ifdef APP_DEBUG_VERSION
			{"Rainbow Enhance", false},
#else
			{"Rainbow Enhance", true},
#endif*/
			MAKE_COMBOBOX("Text Color",
			"Rainbow",		// Rainbow++ 将会使用着色器进行染色
			{	NAMED_COLOR_BASE_LIST,
				"Rainbow++"
			}
			),

			{"Background", true},
			{"Background Outline", true},
			{"Background Shadow", true},
			{"Background Shadow Thickness", 20},
			{"Background Round Corners", false},
			{"Background Opacity Min (0~1)", 0.56f},
			{"Background Opacity Max (0~1)", 0.57f},
			{"Background Opacity Period (ms)", 2000L},

			MAKE_COMBOBOX("Background Color", "Black",
				{"Transparent", NAMED_COLOR_BASE_LIST}),

			MAKE_COMBOBOX("Background Shadow Color", "Black",
				{NAMED_COLOR_BASE_LIST}),

			{"Background Color Darkness (0~1)", 0.9f},

			MAKE_COMBOBOX("Background Outline Color", "Transparent",
				{"Transparent", NAMED_COLOR_BASE_LIST}),

			{"Sort By Length", true},
			{"Use Display Length", true},
	}
},

{"Ambience",
	{
		MAKE_COMBOBOX("Weather", "Off",
			{"Off", "Rainy", "Thundery"}),

		{"Weather Cycle", true},
		{"Lightning Display", true},
		{"Lightning Display Duration (ms)", 5000L},
		MAKE_COMBOBOX("Precipitation Display Position", "Screen",
			{"Screen", "Foreground", "Background"}),
		{"Precipitation Amount Scale", 1.0f},
		{"Precipitation Fall Speed", 1.0f},
		{"Precipitation Angle (rad)", 8.168f},
		{"Precipitation Increase Speed", 10.0f},
		{"Precipitation Decrease Speed", 5.0f},
		{"Precipitation Sound Volume", 100},
		{"Thunder Sound Volume", 100},

		{"Rain Shape", "/"},
		{"Mouse Camera Mode", false},
		{"Mouse Camera X Rate", 1.0f},
		{"Mouse Camera Y Rate", 1.0f},

		MAKE_COMBOBOX("Precipitation Mouse Circle", "Off",
			{"Off", "Hide", "Fade", "Lighten", "Darken"}),

		{"Precipitation Mouse Circle Radius", 200.0f},

		MAKE_COMBOBOX("Rain Color", "Blue",
			{NAMED_COLOR_BASE_LIST}),
	}
},

{"Auto Danmaku",
	{
		MAKE_COMBOBOX("File Selection Mode", "Single File",
			{"Single File", "Single File Loop", "Folder Random Select", "Folder Sequential Select", "Folder Loop Select"}),

		{"Path", "danmaku_172423516.xml"},
		{"File Selection Max Attempts", 5},
		{"Recursive Selection in Folder", false},
		{"List Current Index", 0},

		{"File Gap Duration (ms)", 0L},
		{"Correct /n to NewLine", true},
		
		{"Notify Danmaku File Name", true},
		//{"Show Advanced Danmaku", true},
		{"Show Top Danmaku", true},
		{"Show Bottom Danmaku", true},
		{"Show Reverse Danmaku", true},
		{"Horizontal Reverse", false},
		{"Vertical Reverse", false},
		//{"Advanced Danmaku Global Opacity (0~1)", 1.0f},

		MAKE_COMBOBOX("Danmaku Font Size Mode", "Auto",
			{"Fixed", "Auto", "Manual"}),

		MAKE_COMBOBOX("White Danmaku Color", "White",
			{NAMED_COLOR_BASE_LIST}),

		{"White Danmaku Color Frozen", false},

		{"Danmaku Font Size Manual Scale", 1.0f},
		{"Lazy Danmaku Pushing", false},

		{"Hotkey (Next Danmaku File)", {{"Keybind", {VK_LCONTROL, VK_LMENU, '2'}}}},
	}
},

{"Auto Title",
	{
		MAKE_COMBOBOX("Mode", "Periodic",
			{"Periodic", "Random", "Smart"}),

		{"Periodic Interval (ms)", 10000L},
		{"Random Min Interval (ms)", 20000L},
		{"Random Max Interval (ms)", 120000L},
		{"Smart Mode Speed", 1.0f},
	}
},

{"Actionbar",
	{
		{"Module Status Auto Switch", true},

//		{"No Fade Animation", false},
		{"Auto Focus", false},
		{"Check Topmost", true},
		{"Draw Prev Text During Animation", true},
		{"Fixed Text", "NEVER GONNA GIVE YOU UP"},
		{"Hide When Menu On", false},
		{"Y Rate", 0.8f},

		MAKE_COMBOBOX("Text Background", "Simple",
			{"Off", "Simple", "Fancy"}),

		MAKE_COMBOBOX("Text Animation", "Slide (Left)",
		{"Off", "Fade", 
		"Slide (Left)", "Slide (Right)", "Slide (Top)", "Slide (Bottom)", "Enlarge", "Enlarge II", "Shrink", "Shrink II"}),

		{"Text Animation Duration (ms)", 1600L},

		{"Text Base Opacity (0~1)", 1.0f},
		{"Text Duration", 4500L},
		{"Text Font Size", 36},

		MAKE_COMBOBOX("Text Color", "Green",
			{NAMED_COLOR_BASE_LIST}),

	}
},

{"Fancy Text",
	{
		{"Async", true},
		{"Hide When Menu On", false},
		{"Module Status Auto Switch", true},

		{"Show Duration (ms)", 3000L},
		{"Scale", 100},

		//{"Debug Output", false},

		{"Fixed Text", "阿诺头顶怎么尖尖的"},

		MAKE_COMBOBOX("Cut Words", "Single",
			{"Single", "Double", "Bili Suggestion", "API", "API 2"}
		),

		MAKE_COMBOBOX("Color", "Colorful",
		{NAMED_COLOR_BASE_LIST}
			),

		{"Random Rotation", true},
		{"Random Rotation Start Coefficient", 1.0f},
		{"Random Rotation End Coefficient", 1.0f},

		//{"Fog Intensity", 1.0f},
		{"Fog Enabled", false},
		{"Fog Opacity (0~1)", 0.6f},

		MAKE_COMBOBOX("Fog Color", "Black",
		{"Transparent", NAMED_COLOR_BASE_LIST}),

		{"Parallax Intensity", 0.8f},

		{"Fade In Duration (ms)", 500L},
		{"Fade Out Duration (ms)", 800L},
		{"Opacity Min (0~1)", 0.7f},
		{"Opacity Max (0~1)", 0.9f},
		{"Opacity Period (ms)", 6000L},
	}
},

{"Title",
	{
		{"Module Status Auto Switch", true},
		{"Hide When Menu On", false},

		MAKE_COMBOBOX("Title Text Mode", "Fixed",
			{"Fixed", "List Random Element", "List Loop", "Clipboard Text"}),

		{"Main Title Enabled", true},
		{"Subtitle Enabled", false},

		{"Fixed Subtitle Text", "yee~"},

		{"Fixed Title Text", "L"},
		{"Title Text List", "你好，陌生人;GRW团队招生了;无论你是跑酷大神;还是生存大师;还是PVP大佬;又或是起床大佬;还是PVP大佬;又或是建筑大佬;还是PVP大佬;又或是红石大佬;还是PVP大佬;还是什么都不知道的小白;还是PVP大佬;还是PVP大佬"},
		{"List Current Index", 0},

		MAKE_COMBOBOX("Title Color", "White",
			{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Subtitle Color", "White",
			{NAMED_COLOR_BASE_LIST}),
		{"Title Base Opacity (0~1)", 1.0f},

		MAKE_COMBOBOX("Title Size", "Auto",
			{"Auto", "Fixed"}),

		{"Auto Title Size Scale", 1.0f},
		{"Check Topmost", true},
		{"Auto Focus", false},
		{"Console Output", true},

		{"Fixed Title Size", 200},
		{"Fixed Subtitle Size", 90},
		{"Title Duration", 5000L},
		{"Title Stay Time (0~1)", 0.5f},
		{"Title Subtitle Line Gap", 30}
	}
},

{"Totem",
	{
		{"Cooldown (ms)", 5000L},
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
		{"AutoMute Triggered", true},
	}
},

{ "Anti Capture",
	{
		{"HUD", true},
		{"Hide When Menu On", false},

		MAKE_COMBOBOX("HUD Alignment", "Center",
			{"Left", "Center", "Right"}),

		{"HUD X Rate", 0.5f},
		{"HUD Y Rate", 0.55f},
		{"HUD Font Size", 30},
		{"HUD Text", "////// Anti Capture Enabled /////"},
		{"HUD Opacity (0~1)", 0.8f},

		MAKE_COMBOBOX("HUD Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),
	}
},

{"Black Capture",
	{
		{"HUD", true},
		{"Hide When Menu On", false},

		MAKE_COMBOBOX("HUD Alignment", "Center",
			{"Left", "Center", "Right"}),

		{"HUD X Rate", 0.5f},
		{"HUD Y Rate", 0.55f},
		{"HUD Font Size", 30},
		{"HUD Text", "///// Black Capture Enabled /////"},
		{"HUD Opacity (0~1)", 0.8f},

		MAKE_COMBOBOX("HUD Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),
	}
},

{"Better Lyrics",
	{
		{"Async", true},

		/*MAKE_COMBOBOX("Mode", "Memory",
		{"Memory", "Capture"}),*/

		//{"Delete Cache", false},
		{"Line Index", 0},

		{"Exclude Non-lyrics Content", true},

		{"Skip If Includes Enabled", true},
		{"Skip If Includes", "<>[]{}()%@#\\`"},
		{"Skip If Similarity Greater Than", 0.7f},

		{"Remove Letters", false},
		{"Remove Extra Characters", "=."},

		{"Pause When Menu On", true},

		MAKE_COMBOBOX("Notify Music Change", "Actionbar",
		{"Off", "Actionbar", "Notify", "Chatter", "Title", "WinToast"}),

		MAKE_COMBOBOX("Music Player Preset", "Netease Music",
			{"Netease Music", "Kugou Music", "QQ Music", "Custom"}),

		{"Kugou Use Taskbar Lyrics", true},

		{"Window Title", "桌面歌词"},
		{"Window Class Name", "DesktopLyrics"},

		{"Lyrics Auto Correct", true},
		{"Lyrics Fetch Attempt Cooldown (s)", 10},
		{"Lyrics Correction Min Similarity (0~1)", 0.8f},

		{"X Offset", 0},
		{"Y Offset", 70},

		MAKE_COMBOBOX("Display Mode", "Fancy",
			{"Title", "Chatter", "Notify", "Actionbar", "WinToast", "Fancy", "Speak", "Mixed", "MessageBox", "Island", "Bar Graph"}),

		MAKE_COMBOBOX("Chatter Color", "Rainbow",
		{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Chatter Type", "Top",
		{"Scroll", "Top", "Bottom", "Reverse", "Horizontal", "Vertical", "Random"}),	// 弹幕类型

		MAKE_COMBOBOX("Actionbar Color", "Colorful",
		{NAMED_COLOR_BASE_LIST}),
		
		/*{"Language Type", "chi_sim"},*/
		MAKE_COMBOBOX("Language", "Infer From Music Name",
			{"AI Decide", "Infer From Music Name", "chi_sim", "eng", "jpn", "osd", "Custom"}),

		{"Language Candidates (Sep With Semicolon)", "chi_sim;jpn;eng"},

		{"Custom Language", "chi_sim"},

		{"Capture Cooldown (ms)", 700L},

		MAKE_COMBOBOX("Capture Mode", "PrintWindow",		// 捕获模式
			{"PrintWindow", "BitBlt (Screen)"}),

		MAKE_COMBOBOX("Translation", "Off",
			{"Off", "Chinese", "English", "Japanese"}
			),

		MAKE_COMBOBOX("MessageBox Mode", "Background",
			{"Background", "Foreground"}),

		{"MessageBox Duration Coefficient", 1.0f},
		{"MessageBox Set As Tool Window", false},

		MAKE_COMBOBOX("Bar Graph Lyrics Color", "Blue",
		{NAMED_COLOR_BASE_LIST}),

		{"Bar Graph Lyrics Color Jitter", 0.05f},

		{"Bar Graph Lyrics Font Size", 80},
		{"Bar Graph Lyrics Char Extra Gap", 5},
		{"Bar Graph Lyrics Opacity (0~1)", 0.9f},
	}
},

{"Lyrics Physics",
	{
		MAKE_COMBOBOX("Replace Animation", "Push-Over",
		{"Push-Over", "Drop-Replace", "Wave-Push"}),

		// 通用参数（建议）
		{"Lyric Gravity", 580.0f},                 // 重力像素/秒²
		{"Lyric Bounce Coef (0~1)", 0.88f},         // 反弹系数
		{"Lyric Friction (0~1)", 0.15f},            // 顶端摩擦（水平速度衰减）
		{"Lyric Max Rise Impulse", 900.0f},         // 柱子突然长高时给字的向上冲量上限
		{"Lyric Scale Pulse (0~1)", 0.15f},          // 音量脉冲引起的缩放幅度
		{"Bar Collide Height Multiplier", 1.8f},
		//{"Lyric Glow Pulse (0~1)", 0.25f},          // 音量脉冲引起的发光强度（如果你做光效）

		// Push-Over 专属
		{"Push-Over Start X Offset", -120.0f},      // 新字从左侧入场的初始偏移
		{"Push-Over Horizontal Speed", 800.0f},     // 新字水平推进速度
		{"Push-Over Hit Impulse", 170.0f},          // 顶飞旧字的瞬时水平/向上冲量
		{"Push-Over Fadeout Time (s)", 2.0f},      // 旧字被顶飞后淡出时长

		MAKE_COMBOBOX("Push-Over Direction", "Left", {"Left", "Right", "Both"}),

		// Drop-Replace 专属
		{"Drop Start Y Offset", 260.0f},           // 新字从顶端上方出生高度
		{"Drop Soft Landing Coef (0~1)", 0.55f},    // 碰到柱顶时的“软着陆”阻尼
		{"Drop Old Fadeout Time (s)", 0.35f},       // 旧字自由落体后的淡出时长

		// Wave-Push 专属
		{"Wave Speed (bars/sec)", 18.0f},           // 波前推进速度（每秒经过的柱子数）
		{"Wave Width (bars)", 6.0f},                // 波宽：影响同时被触发的列数
		{"Wave Push Impulse", 820.0f},              // 波前推到时对旧字的冲量

		{"Allow Rotation", true},
		{"Rotation Friction (0~1)", 0.15f},
		{"Rotation Bounce Coef (0~1)", 0.35f},

	}
},

{"Tesseract OCR",
	{
		{"Executable Path", ""},
		{"Language", "chi_sim"},
	}
},

{"Watermark",
	{
		{"Size", 80},
		{"Menu Off Alpha", 0.3f},
		{"Menu On Alpha", 0.2f},
		{"Text", "W O R M W A K E R"},
		{"Text Whiteness (0~1)", 0.8f},

		MAKE_COMBOBOX("Text Color", "White",
			{NAMED_COLOR_BASE_LIST}),

		{"Opacity Min (0~1)", 0.5f},
		{"Opacity Max (0~1)", 0.5f},
	}
},

{"Bright",
	{
		{"Percentage (0~100)", 20},

		MAKE_COMBOBOX("Mode", "Lazy",
			{"Once", "Hotkey", "Lazy", "Keep"}),

		{"Hotkey Brightness-", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_OEM_COMMA}}}},
		{"Hotkey Brightness+", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_OEM_PERIOD}}}},
		{"Hotkey Step (%%)", 5},

		MAKE_COMBOBOX("HUD", "Bottom",
			{"Off", "Bottom", "Bottom Big", "Giant", "Giant 2"}),

		{"HUD Duration (ms)", 3000L},
		{"HUD Giant 2 Bar Color", "gold"},

		{"Keeping Cooldown (ms)", 1000L},
	}
},

{"Gamma",
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
			{"Menu On", "Menu Off", "Always"}),

		{"Hide When No Focus", true}
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

{"Anti Spy",
	{
		{"Async", true},
		{"Check Cooldown (ms)", 1000U},

		MAKE_COMBOBOX("Anti Microphone", "Mute",
			{"Off", "Mute", /*"Disable"*/}),

		{"Notify", true},
	}
},

{"Auto Clicker",
	{
		{"Left CPS Min", 7U},
		{"Left CPS Max", 14U},
		{"Left Blatant Mode", false},
	    {"Left Sound", "jclick.wav"},
		{"Right CPS Min", 6U},
		{"Right CPS Max", 11U},
		{"Right Blatant Mode", false},
		{"Right Sound", "nclick.wav"},
		{"Extra Key CPS Min", 8U},
		{"Extra Key CPS Max", 15U},
		{"Extra Key Blatant Mode", false},
		{"Extra Key Sound", "kbhit_2.wav"},

		{"Gap Random Deviation (%%)", 10U},
		{"Click Internal Gap", 5U},

		{"Left Mouse Button Enabled", true},
		{"Right Mouse Button Enabled", true},
		{"Extra Key Enabled", false},

		MAKE_COMBOBOX("Extra Target Key", "Custom",
			{"Left Button",
			 "Right Button",
			 "Middle Button",
			 "Custom"}),

		{"Extra Custom Key Code", 32},

		{"Keep Target Window Active", false},

		/*MAKE_COMBOBOX("Hotkey", "Side Button 1",
			{"Side Button 1",
			 "Side Button 2",
			 "Grave ~",
			 "Q", "R", "Z", "X", "C", "V"
			}),*/

		{"Left Hotkey", {{"Keybind", {VK_XBUTTON2}}}},
		{"Right Hotkey", {{"Keybind", {VK_XBUTTON1}}}},
		{"Extra Key Hotkey", {{"Keybind", {0}}}},

		MAKE_COMBOBOX("Left Trigger Mode", "Hotkey Hold",
		{"Hotkey Toggle", "Hotkey Hold",
			//"TargetKey Toggle", "TargetKey Hold",
			//"Additional Clicks"
			}),

		MAKE_COMBOBOX("Right Trigger Mode", "Hotkey Hold",
		{"Hotkey Toggle", "Hotkey Hold",
		//"TargetKey Toggle", "TargetKey Hold",
		//"Additional Clicks"
		}),

		MAKE_COMBOBOX("Extra Key Trigger Mode", "Hotkey Hold",
		{"Hotkey Toggle", "Hotkey Hold",
		//"TargetKey Toggle", "TargetKey Hold",
		//"Additional Clicks"
		}),

		MAKE_COMBOBOX("Click Point Setting", "Manual",
			{"Manual", "Locked", "Shake", "Shake Locked"}),

		{"Click Shake Max Radius", 8},
		{"Pause Shake While Not Moving", true},

		MAKE_COMBOBOX("Click Method", "WMessage",
			{"Simulation", "WMessage"}),

		{"Window Message Cancel Left Up", false},
		{"Window Message Cancel Right Up", false},
		{"Window Message Cancel Extra Up", false},

		//{"TargetKey Hold Threshould Time", 700U},
		//{"Additional Click Duration (ms)", 1000U},


		MAKE_COMBOBOX("Notify Mode", "Notify",
			{"Off", "Chatter", "Notify"}),

		{"Stop When Menu On", true},

		{"Only Trigger While Moving", false},	// 仅在移动时触发
		{"Only Window Center", false},			// 鼠标仅在窗口中心触发
		{"Only Window Center Radius", 100.0},

		{"Interrupt Key 1", {{"Keybind", {'E'}}}},
		{"Interrupt Key 2", {{"Keybind", {'T'}}}},
		{"Interrupt Key 3", {{"Keybind", {VK_ESCAPE}}}},
		{"Interrupt Key 4", {{"Keybind", {VK_OEM_2}}}},	// 斜杠和问号

	}
},

{"Bridge Assist",
	{
		{"Check Window", true},

		MAKE_COMBOBOX("Trigger Condition", "S & D",
			{"S", "S & A", "S & D"}),

		{"BPS", 2.10f},

		MAKE_COMBOBOX("Mode", "Sneak",
		{"Simple", "Sneak"}),

		{"Sneak Key", {{"Keybind", {VK_LSHIFT}}}},
		{"Place Key", {{"Keybind", {VK_RBUTTON}}}},

		{"Sneak Reshift Gap", 50U},
		{"Right Internal Gap", 10U},
		{"Shift Internal Gap", 100U},
		{"Place Sound", true},
	}
},

{"Hex Viewer",
	{
		MAKE_COMBOBOX("Color Mode", "Simple",
			{"Off", "Simple", "Category", "Step", NAMED_COLOR_BASE_LIST}),

		{"Category Null Color", "30;30;30"},
		{"Category CR Color", "&11"},
		{"Category LF Color", "&10"},
		{"Category Control Color", "&6"},
		{"Category Space Color", "&12"},
		{"Category Punct Color", "&14"},
		{"Category Alpha Color", "&7"},
		{"Category Number Color", "&9"},
		{"Category Other Color", "&13"},

		{"Step Color Start", "30;30;30"},
		{"Step Color End", "255;255;255"}
	}
},

{"Chat Ask",
	{
		{"Async", true},
		{"Remove Markdown Format", true},
	}
},

{"Chat Translate",
	{
		MAKE_COMBOBOX("Dest Language", "Chinese-English",
			{"English", "Chinese", "Chinese-English", "Classic Chinese",
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

		MAKE_COMBOBOX("Character Obfuscation", "Off",
			{"Off", "Normal", "Advanced", "Ultimate"}),
		//{"URL Deep Scan", false},

		{"Chinese Traditionalization", false},

		MAKE_COMBOBOX("Letter Changes", "Off",
		{"Off", "Upper Case", "Lower Case", "Annoying Case", "Fancy Letters"}),

		/*MAKE_COMBOBOX("Text Shaper", "Off",
		 {"Add Spaces", "Cut Line"}),*/
		
		MAKE_COMBOBOX("Add Spaces Mode", "Off",
		{"Off", "Single", "Double", "Pair", "Wave", "Smaller Random", "Bigger Random"}),

		MAKE_COMBOBOX("Cut Line Mode", "Off",
		{"Off", "Punctuation", "Fixed Length", "Random Length",
		"Wave Left"
		//, "Wave Center"
}),

		{"Cut Line Extra Tail", "喵"},
		{"Cut Line Fixed Length", 12},
		{"Cut Line Random Length Min", 5},
		{"Cut Line Random Length Max", 16},

		MAKE_COMBOBOX("Punctuation Changes", "Off",
		{"Off", "Remove", "To English", "To Chinese", "Random"}),

		/*{"Tip URL", true},
		{"Tip Social Numbers", true},*/
	}
},

{"Chest Stealer",
	{
		{"Async", true},

		MAKE_COMBOBOX("Trigger Mode", "Hotkey",
			{"Instant", "Right Mouse Button", "Hotkey"}),

		{"Trigger Hotkey", {{"Keybind", {'B'}}}},
		
		MAKE_COMBOBOX("Trigger Hotkey Interrupt", "Close Container",
			{"Off", "Stop", "Close Container"}),

		{"Interrupt Key 1", {{"Keybind", {'E'}}}},
		{"Interrupt Key 2", {{"Keybind", {VK_ESCAPE}}}},

		MAKE_COMBOBOX("HUD", "Off",
			{"Off", "Basic"}),

		{"HUD Font Size", 30},

		MAKE_COMBOBOX("HUD Target Slot Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Mouse Easing Movement", "EaseInOutSine",
			{"Off", "Linear", "EaseInOutSine", "EaseInOutExpo", "EaseInOutBack"}),

		{"Mouse Easing Duration (ms)", 50L},

		MAKE_COMBOBOX("Notify Mode", "Notify",
			{"Off", "Notify", "Chatter", "Title"}),

		MAKE_COMBOBOX("Slot Selector", "No Empty Detect",
			{"All", "No Empty Detect"}),

		{"Slot No Empty Single Channel Threshold", 1000},

		MAKE_COMBOBOX("Slot Order", "Random",
			{"Snake", "Reverse Snake", "Sequential", "Reverse", "Random"}),

		MAKE_COMBOBOX("Item Operation", "Steal",
			{"Steal", "Drop", "Drag Steal"}),

		MAKE_COMBOBOX("Coordinate Mode", "Semi-Auto",
			{"Semi-Auto", "Manual"}),

		MAKE_COMBOBOX("Container Type", "Small Chest",
			{"Small Chest", "Large Chest", "Hopper", "Dispenser"}),

		{"Slot Size", 52},

		{"Semi-Auto Y Offset Slots (Small Chest)", 3.12f},
		{"Semi-Auto Y Offset Slots (Large Chest)", 4.60f},
		{"Semi-Auto Y Offset Slots (Hopper)", 2.00f},
		{"Semi-Auto Y Offset Slots (Dispenser)", 4.10f},

		{"Manual X Offset (Small Chest)", -240},
		{"Manual X Offset (Large Chest)", -240},
		{"Manual X Offset (Hopper)", -132},
		{"Manual X Offset (Dispenser)", -78},

		{"Manual Y Offset (Small Chest)", -198},
		{"Manual Y Offset (Large Chest)", -278},
		{"Manual Y Offset (Hopper)", -141},
		{"Manual Y Offset (Dispenser)", -198},

		{"Slot Internal Random Offset", true},

		{"Click Internal Gap (ms)", 40L},
		{"Key Internal Gap 1 (ms)", 40L},
		{"Key Internal Gap 2 (ms)", 40L},

		{"Start Delay Min (ms)", 100},
		{"Start Delay Max (ms)", 200},
		{"Operate Delay Min (ms)", 150},
		{"Operate Delay Max (ms)", 250},
		{"End Delay Min (ms)", 100},
		{"End Delay Max (ms)", 200},
		{"Auto Close", true},
		{"Not Trigger While Moving", true},
		{"Minecraft Window Check", true},
		{"Auto Close Key", {{"Keybind", {'E'}}}},
		{"Drop Items Key", {{"Keybind", {VK_LCONTROL, 'Q'}}}},
	}
},

{"Mouse Teleport",
	{
		{"Edge Teleport", true},
		{"Teleport Sound", true},
	}
},

{"Mouse Watcher",
	{
		MAKE_COMBOBOX("Movement Check", "Ignore",
			{"Ignore", "Warn", "Warn & Restore", "Restore"}),

		MAKE_COMBOBOX("Movement Check Mode", "Simple",
			{"Simple", "Strict"}),

		{"Hide HUD When Menu On", true},

		MAKE_COMBOBOX("HUD", "Fancy",
			{"Off", "Simple", "Fancy"}),

		MAKE_COMBOBOX("HUD Color", "White",
			{NAMED_COLOR_BASE_LIST}),

		{"HUD Font Size", 20},
		{"HUD Line Gap", 5},
		{"HUD X Rate", 0.01f},
		{"HUD Y Rate", 0.44f},

		{"Sample Cooldown", 10U},
		{"Acceleration Threshold", 60.0f},
	}
},

{"Mouse Disabler",
	{
		{"Allow Move", false},
		{"ALLOW NO KEYBIND", false},
	}
},

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
		{"Minecraft Window Check", false},
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
		{"HUD Font Size", 45},
		
		MAKE_COMBOBOX("HUD Progress Style", "Bottom Bar", 
		{"Off", "Bottom Bar", "Mouse Percentage", "Rainbow Giant"}),

		{"HUD Window Highlight", true},
		{"Hide HUD When Menu On", true},

		{"Keep Disabling IMC", true},

		{"Focus Window", true},
		
		{"Init/Stop Hotkey", {{"Keybind", {VK_LMENU, '1'}}}},
		{"Pause/Resume Hotkey", {{"Keybind", {VK_LMENU, '2'}}}},

		MAKE_COMBOBOX("Source", "Clipboard",
			{"Fixed", "Clipboard", "File", "AI Answer"}),

		{"Clipboard Tweaks Module Text Processor", false},
		{"Accelerate Space Typing", true},

		MAKE_COMBOBOX("Display On Send", "Off",
		{"Off", "Notify", "Chatter", "Title", "Actionbar", "Fancy", "WinToast"}),

		MAKE_COMBOBOX("Display Chatter Color", "Rainbow",
		{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Display Chatter Type", "Top",
		{"Scroll", "Top", "Bottom", "Reverse", "Horizontal", "Vertical", "Random"}),	// 弹幕类型

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

//{"Spammer",
//	{
//		MAKE_COMBOBOX("Pre Key", "None",
//			{"None", "T", "Enter", "Custom"}),
//
//		{"Custom Pre Key", ""},
//
//		MAKE_COMBOBOX("Send Key", "Ctrl + Enter",
//			{"Enter", "Ctrl + Enter", "Custom"}),
//
//		{"Custom Send Key", ""},
//
//		MAKE_COMBOBOX("Count Control", "Manual",
//			{"Manual", "List Times", "Fixed Count", "Random Count"}),
//
//		{"List Repeat Times", 1L},
//
//		MAKE_COMBOBOX("Message Source", "Database",
//			{"Database", "Fixed", "List", "Clipboard", "File"}),
//
//		MAKE_COMBOBOX("Database Combo Name", "",
//			{""}),
//
//		{"Message (Fixed)", "收到"},
//		{"Messages (List)", ""},
//
//		MAKE_COMBOBOX("Message Prefix", "Off",
//			{"Off", "Random", "Randint", "Timestamp"}),
//
//		{"Converter: Chinese Tranditionalization", false},
//		{"Converter: Letter Annoying Case", false},
//		{"Converter: Letter Fancy Letters", false},
//		{"Converter: Punctuation Removal", false},
//		{"Converter: Spaces Addition", false},
//		{"Converter: Shuffle", false},
//
//		MAKE_COMBOBOX("Obfuscator Level", "Advanced",
//			{"Normal", "Advanced", "Ultimate"}),
//
//		MAKE_COMBOBOX("Add Spaces Mode", "Single",
//		{"Single", "Double", "Pair", "Wave", "Smaller Random", "Bigger Random"}),
//
//		MAKE_COMBOBOX("Notify Messages", "Off",
//			{"Off", "Notify", "Chatter", "Actionbar"}),
//
//		MAKE_COMBOBOX("Delay Mode", "Smart",
//			{"Fixed", "Smart", "Random", "Wave"}),
//
//		{"Delay (Fixed)", 250U},
//		{"Delay Min", 150U},
//		{"Delay Max", 350U},
//
//		MAKE_COMBOBOX("HUD", "Off",
//			{"Off", ""}),
//
//		{"Init/Stop Hotkey", {{"Keybind", {VK_LMENU, '1'}}}},
//		{"Pause/Resume Hotkey", {{"Keybind", {VK_LMENU, '2'}}}},
//	}
//},

{"Key Disabler",
	{
		//{"Key Locker Mode (Press End to end)", false}
		MAKE_COMBOBOX("Mode", "Locker (Press End to escape)",
			{"Win", "LCtrl, Win, LAlt", "Locker (Press End to escape)",
			"Ctrl, Win, Alt"}),
	}
},

{"Key Logger",
	{
		{"Console Output", true},
		{"Log Output", true}
	}
},

{"Key Reaction",
	{
		//{"Auto Release List (Sep With Semicolon)"},
		{"Auto Release F22 When WeChat Running", true},

		{"Key Reaction Data Enabled", true},
		{"Key Reaction Data JSON Array", "[]"},

		MAKE_COMBOBOX("Key Notify Mode", "Notify",
			{"Off", "Notify", "Chatter", "Title"}),
	}
},

{"Key Sound",
	{
		MAKE_COMBOBOX("Alloc Mode", "All",
			{"All", "Keyboard All", "Mouse All", "Category", "Custom"}),

		MAKE_COMBOBOX("Detect Mode", "Raw Input",
			{"Raw Input", "GetKeyState"}),

		MAKE_COMBOBOX("Sound Selection", "Single File",
			{"Single File", "Folder Random Select", "Folder Map Select"}),

		{"Recursive Selection in Folder", true},

		MAKE_COMBOBOX("Debug Notification", "Off",
			{"Off", "File Path", "Key Name"}),

		{"All Mode Sound", ""},
		{"Keyboard All Mode Sound", ""},
		{"Mouse All Mode Sound", ""},

		{"Category Left Click Sound", ""},
		{"Category Right Click Sound", ""},
		{"Category Other Mouse Sound", ""},
		{"Category Control Sound", ""},
		{"Category Letter Sound", ""},
		{"Category Num Sound", ""},
		{"Category Punct Sound", ""},
		{"Category Esc Sound", ""},
		{"Category Enter Sound", ""},
		{"Category Back Sound", ""},
		{"Category Arrow Sound", ""},
		{"Category Lock Sound", ""},
		{"Category FN Sound", ""},
		{"Category Space Sound", ""},
		{"Category Other Keyboard Sound", ""},

		{"Custom Mode Config File", "config/keyCustomSounds.ini"},
	}
},

{"Macro Recorder",
	{
		//{"Mouse Pos Sample Rate (Hz)", 20},

		MAKE_COMBOBOX("Output Format", "Jackal Macro",
			{"Jackal Macro", "Jackal Batch"}),

		{"First Perspective Mouse Offset", false},
		{"First Perspective Mouse Offset Scale X", 5.0f},
		{"First Perspective Mouse Offset Scale Y", 1.0f},

		MAKE_COMBOBOX("Recording HUD", "Off",
			{"Off", "Rec", "Red Rectangle"}),

		{"Recording HUD Font Size", 50},
		{"Recording HUD X Rate", 0.05f},
		{"Recording HUD Y Rate", 0.12f},

		{"Notify File Path", true},
		{"Notify Actions (Chatter)", false},
		{"Notify Mouse Pos (Chatter)", false},
		{"Record Window Assertions", false},

		{"bind (Enable)", {{"Keybind", {0}}}},
		{"bind (Disable)", {{"Keybind", {0}}}},
	}
},

{"Macro Player",
	{
		{"Start Delay (ms)", 3000L},
		{"Close Menu", true},
		{"Macro Path", ""},
		{"Notify", true},
		{"Actionbar Display Key Press", true},
		{"Actionbar Display Mouse Move", true},
		{"Actionbar Display Mouse Wheel", true},
		{"Perform Window Assertions", true},
		{"Reset Keyboard When Disable", true},
		{"Auto Loop", false},

		MAKE_COMBOBOX("Playing HUD", "Off",
			{"Off", "Replay", "Blue Rectangle"}),

		{"Playing HUD Font Size", 50},
		{"Playing HUD X Rate", 0.05f},
		{"Playing HUD Y Rate", 0.12f},	

		{"Adjust Offset Step (ms)", 50L},
		{"adjust offset (Earlier)", {{"Keybind", {VK_LCONTROL, VK_UP}}}},
		{"adjust offset (Later)", {{"Keybind", {VK_LCONTROL, VK_DOWN}}}},
		{"bind (Disable)", {{"Keybind", {0}}}},
		{"bind (Enable)", {{"Keybind", {0}}}},
		{"bind (Disable)", {{"Keybind", {0}}}},
	}
},

{"No IMC",
	{
		{"Restore", true}
	}
},

{"Meme Trigger",
	{
		/*MAKE_COMBOBOX("Hotkey", "RCtrl + A~Z",
			{"RCtrl + A~Z",
			"RShift + A~Z",
			"RCtrl/RShift + A~Z",
			"RCtrl + RShift + A~Z"}),

		{"Disable ForceTopmost", true},
		{"Minimize Client", true},*/

		{"no_signal", {{"Keybind", {0}}}},
		{"genshin_impact", {{"Keybind", {0}}}},
		{"what", {{"Keybind", {0}}}},

		{"hyw", {{"Keybind", {0}}}},
		{"zmq", {{"Keybind", {0}}}},
		{"hyw Folder Path", ""},
		{"zmq Folder Path", ""},

		{"Notify", false},
		{"Disable Client Other HUD", true}
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

		MAKE_COMBOBOX("Auto Mute", "Off",
			{"Off", "Once On Launch", "Output Device Changed", "Output Device Name Keyword When Changed"}
			),

		{"Auto Mute Output Device Name Keyword (Include)", ""},
		{"Auto Mute Output Device Name Keyword (Exclude)", "耳机"},

		MAKE_COMBOBOX("Auto Mute Notify", "Title",
			{"Off", "Title", "Notify", "Chatter", "Actionbar", "WinToast"}),

		{"Vol+", {{"Keybind", {VK_LCONTROL, VK_LSHIFT, VK_UP}}}},
		{"Vol-", {{"Keybind", {VK_LCONTROL, VK_LSHIFT, VK_DOWN}}}},
		{"Mute", {{"Keybind", {VK_LCONTROL, VK_LSHIFT, 'M'}}}},

		{"Hide HUD When Menu On", false},

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

		MAKE_COMBOBOX("Wheel System Volume Adjust", "Mouse On Taskbar",
			{"Off", "LAlt", "RAlt", "Mouse On Taskbar"}),

		MAKE_COMBOBOX("Wheel Process Volume Adjust", "Mouse On Caption",
			{"Off", "LAlt", "RAlt", "Mouse On Caption"}),

		{"Wheel Volume Step", 5U},

		{"Step (%%)", 5U},

		{"Temp HUD Duration (ms)", 3000L},
		{"Temp HUD Animation Duration (ms)", 300L},

		{"Limit System Volume", false},
		{"System Volume Min", 1},
		{"System Volume Max", 50},
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

{"Speaker",
	{
		{"Async", true},
		{"Notify Error", true},

		MAKE_COMBOBOX("Method", "SAPI",
			{"SAPI"}),

		MAKE_COMBOBOX("Multiple Text Arrangement", "Queue",
			{"Off", "Queue", "Available"}),

		MAKE_COMBOBOX("Spoken Text Mode", "Fixed",
			{"Fixed", "List Random Element", "List Loop", "Clipboard Text"}),

		{"Fixed Spoken Text", "Hello World 你好，世界！"},
		{"Spoken Text List", "你的钢门比较松弛;但是呢,你的痔疮又弥补了这一部分;如果做痔疮手术,把痔疮切除的话;可能就会显得你的钢门就比较大;可能会有一些漏液漏气的情况;现在最好的办法就是;在做痔疮手术的同时;给你做一个钢门紧缩术"},
		{"List Current Index", 0},
	}
},

{"Auto Speak",
	{
		MAKE_COMBOBOX("Main Mode", "Off",
			{"Off", "Periodic", "Random", "Smart"}),

		{"Periodic Interval (ms)", 10000L},
		{"Random Min Interval (ms)", 20000L},
		{"Random Max Interval (ms)", 120000L},
		{"Smart Mode Gap (ms)", 1000L},

		{"Speak Actionbar", false},
		{"Speak Title", true},
		{"Speak Subtitle", false},
		{"Speak Chatter", false},
		{"Speak Dialog (Auto Detect)", true},
		{"Dialog Text Max Speak Length", 100U},
		{"Skip Speaking Dialog Text Same As Previous", true},
	},
},

{"Mute",
	{
		MAKE_COMBOBOX("Mode", "Status",
			{"Status", "Amount", "Both"}),

		{"Amount Mode Restore Volume", true}
	},
},

{"Active",
	{
		{"Cooldown", 0},
	}
},

#define GUI_STYLE_PRESETS \
		MAKE_COMBOBOX("Style Preset", "Default",	\
		   { "Default", "Vape", "LiquidBounce", "LiquidBounce NextGen", "Raven", "Meteor" })

{"GUI Styler",
	{
		GUI_STYLE_PRESETS,
	}
},

{"Force Topmost",
	{
		{"Cooldown", 25},
		{"Use SW_RESTORE", false},
		{"Not While Hidden", true},
		{"Not While Screenshot", true},
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

	{"Audio Visualizer",
		{
			{"Capture Cooldown (ms)", 50L},
			{"Menu On Alpha", 1.0f},
			{"Menu Off Alpha", 1.0f},

			{"Global HUD Pulse Effects", false},
			{"Global HUD Pulse Effects Intensity (0~1)", 0.5f},

			{"Enable Better Lyrics Module", false},

			MAKE_COMBOBOX("Visualizer Mode", "Bar Graph",
			{"Bar Graph", "Line Wave", "Circle Spectrum"}),
			
			MAKE_COMBOBOX("Bar Graph Style", "Normal",
			{"Normal", "Pixel"}),

			{"Bar Pixel Gap", 40},
			{"Bar Width", 100L},
			{"Bar Horizontal Gap", 2},
			{"Bar Max Height", 250L},
			{"Bar Opacity (0~1)", 0.3f},
			{"Bar Easing Speed (0~1)", 0.15f},

			MAKE_COMBOBOX("Bar Color", "White",
				{NAMED_COLOR_BASE_LIST}),

			MAKE_COMBOBOX("Bar Color (Top)", "Same",
				{"Same", NAMED_COLOR_BASE_LIST}),
				
			// 线形波形参数
			{"Line Y Rate", 0.8f},
			{"Line Thickness", 3L},
			{"Line Amplitude", 1.2f},
			MAKE_COMBOBOX("Line Color", "Blue", {NAMED_COLOR_BASE_LIST}),
			{"Line Opacity (0~1)", 0.6f},
			MAKE_COMBOBOX("Line Direction", "Up", {"Up", "Down", "Both"}),

			// 环形频谱参数
			{"Circle Radius", 250L},
			{"Circle Thickness", 5L},
			{"Circle Scale", 1.8f},
			MAKE_COMBOBOX("Circle Color", "Gold", {NAMED_COLOR_BASE_LIST}),
			{"Circle Opacity (0~1)", 0.8f},
		}
	},

	{"Time Manager",
		{
			{"Async", true},

			MAKE_COMBOBOX("Mode", "Offset Toggle",
				{"Freeze", "Set Once", "Offset Once", "Offset Toggle", "Online Sync Once", "Online Sync Keep",
				 "Set Accelerated", "Offset Accelerated"
				}),

			MAKE_COMBOBOX("Sync Method (Disabling Freeze)", "Memory",
				{"Off", "Memory", "Web"}),

			MAKE_COMBOBOX("Sync Method (Disabling Set)", "Memory",
				{"Off", "Memory", "Web"}),

			MAKE_COMBOBOX("Sync Method (Disabling Offset)", "Config",
				{"Off", "Config", "Web"}),

			{"Online Sync Cooldown (ms)", 30000L},
			{"Acceleration Speed", 1.0f},

			{"Set Year", 2025},
			{"Set Month", 2},
			{"Set Day", 28},
			{"Set Hour", 12},
			{"Set Minute", 0},
			{"Set Second", 0},

			{"Offset Year", 0},
			{"Offset Month", 0},
			{"Offset Day", 0},
			{"Offset Hour", 12},
			{"Offset Minute", 0},
			{"Offset Second", 0},
		}
	},

	{"Console",
		{
			{"Random Title", true},
			{"Disable Quick Edit", true},
			{"Disable Insert Mode", false},
			{"Disable Mouse Input", true},
			{"Disable Close", true},
			{"Font Size", 18},

			MAKE_COMBOBOX("Advanced Background Style",
				"Off",
				{"Off", "Mica", "Acrylic", "Test"}),

			MAKE_COMBOBOX("Dark Mode", "On",
				{"Off", "On", "Auto"}),

			{"Non-client Rendering Policy", false},
			{"Round Corner", true},

			MAKE_COMBOBOX("Font Name", "Consolas",
				{"新宋体", "宋体", "黑体", "楷体", "等线",
				"Candara", "Consolas", "Lucida Console", "Segoe UI", "Tahoma"}),

			{"Border Color", ""},
			{"Caption Color", ""},
			{"Caption Text Color", ""},

			{"bind", {{"Keybind", {VK_RMENU, 'C'}}}}
		}
	},

	{"Developer",
		{
			{"Speak", true},
			{"Web Request", false},
			{"Fancy Text", false},
			{"Execute OCR", false},
			{"Better Lyrics Lines", false},
			{"Better Lyrics AI Decide Prompt", false},
			{"Better Lyrics Result", false},
			{"RunWormwakeCommand", true},
			{"Chinese Translation", false},
		}
	},

	{"Quick Command",
		{
			{"Async", true},

			{"Single Instance", true},

			MAKE_COMBOBOX("Input Method", "Input Box",
				{"Input Box", "Chat Box"/*, "Island"*/}),

			{"Trigger Hotkey", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_OEM_3}}}}
		}
	},

	{"Shell",
		{
			MAKE_COMBOBOX("Theme", "Metasploit",
				{"Default", "Cmd", "PowerShell", "VS2022 Dev PowerShell", "Metasploit", "Kali Linux"}),

			{"Exclusive Mode", false},
			{"Input Prompt Color", "yellow"},
			MAKE_COMBOBOX("Input Prompt", "$>",
				{
					">",
					"$>",
					"$",
					">>>",
					"JC >",
					"Custom",
				}),

			{"Allow Terminate Shell Thread", false},
			{"Close Menu", true},
			{"Custom Input Prompt", ">>>"},
			{"Input Color", "white"},
			{"Command Max Length", 65535L},
			{"Echo Command", false},
			{"Using Builtin Variables", true},
			{"Using Environment Variables", true},

			MAKE_COMBOBOX("Batch File Error Level", "Only Exception",
				{"Ignore", "Only Exception", "All Errors"}),

			{"Batch File Execution Notify", true},

			MAKE_COMBOBOX("Chatter Color", "White",
				{NAMED_COLOR_BASE_LIST}),
			MAKE_COMBOBOX("Title Color", "Rainbow",
				{NAMED_COLOR_BASE_LIST}),

			/*{"Title Font Size", 400},*/
			{"bind", {{"Keybind", {VK_RMENU, 'S'}}}}
		}
	},

	{"Hidden",
		{
			{"Hide Console", true},
			{"Auto Hide Client When GUI Closed", false},
			{"Disable Client Keybind When Hidden", true},
			{"Disable Tray Tip", false},
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
				"mvp",
				"old",
				"pixelizer_time",
				"shadow_glitch",
				"sobel"}),

			{"Blur Strength", 2.0f},
			{"Blur Samples", 5},

			{"Bloom Samples", 15.0f},
			{"Bloom Quality", 0.92f},
			{"Bloom Intensity", 0.57f},
			//{"Bloom Threshold", 0.4f},

			{"Screen Mode Update Cooldown", 33U},
			{"Screen Compensation Faster", true},
		}
	},

	{"Vape",
		{
			MAKE_COMBOBOX("Color", "White",		// Rainbow++ 将会使用着色器进行染色
			{	/*"White",
				"Rainbow",*/
				NAMED_COLOR_BASE_LIST,
				"Rainbow++"
			}),

			MAKE_COMBOBOX("Logo", "Vape",
				{"Vape", "LiquidBounce", "Jackal", "Custom"}),

			{"Give Way to Mouse", true},
			{"Custom Logo Path", ""},

		}
	},

	{"Close AV",
		{
			{"Huorong", true},
			{"360", true},
		}
	},

	{"Kill 360",
		{
			MAKE_COMBOBOX("360 Process Detection Method", "Directory",
				{"Fixed List", "Directory"}),
		}
	},

	{"Kill 360 Test",
		{
			MAKE_COMBOBOX("360 Process Detection Method", "Directory",
				{"Fixed List", "Directory"}),

			MAKE_COMBOBOX("Operation When Max Process Attempts Reached", "Next Process",
				{"Next Process", "Stop"}),

			MAKE_COMBOBOX("Filter Architecture", "x64",
				{"Both", "x64", "x86"}),

			{"Max Process Attempts", 1},
		}
	},

	{"Kill AV",
		{
			MAKE_COMBOBOX("Method", "Driver",
				{"Normal", "Driver"}),
		}
	},

	{ "Kill Malware",
		{
			MAKE_COMBOBOX("Method", "Normal",
				{"Normal", "Driver"}),
		}
	},

	{ "Kill Everyone",
		{
			MAKE_COMBOBOX("Method", "Normal",
				{"Normal", "Driver"}),
		}
	},

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

					//{"Async Update", false},
					{"Single Instance",	true},
					{"Disable Log", false},
					{"Simplified Log", false},
					{"Auto Toggle As Prev Run", true},
					{"Save Module Toggle Data", true},
					{"Save Data More Frequently", false},
					{"Backup Records Cache", true},

					/*{"Disable DPI Scaling", true},*/
					{"Use Client Exception Filter", true},
					{"Exception Filter Minidump Enabled", false},
					{"Exception Filter Export Crash Log", true},
					{"Exception Filter Open Crash Log", true},
					//{"Exception Filter Auto Load Symbol", true},
					{"Display Client on Which Monitor", 0},
					{"Client Executable Name Force Check", true},

					//#ifdef APP_DEBUG_VERSION
					//			{"Block Unsafe Modules", true},
					//#else
					//			{"Block Unsafe Modules", true},
					//#endif
					MAKE_COMBOBOX("Work-in-progress Modules", "Deny",
						{"Deny", "Shift + Click", "Allow"}),

					MAKE_COMBOBOX("Unsafe Modules", "Shift + Click",
						{"Deny", "Shift + Click", "Allow"}),

					MAKE_COMBOBOX("Driver-Used Modules", "Shift + Click",
						{"Deny", "Shift + Click", "Allow"}),

					{"Force Driver Modules Admin", false},

					{"Check Module Privileges Before Turning On", true},
					MAKE_COMBOBOX("Elevate and Retry Admin Modules", "Off",
						{"Off", "Standard", "UAC Bypass"}),

					{"Disallow WMI ProcessKill", true},
					{"Disallow Driver ProcessKill (Suggest)", true},
					{"Lock Module Toggle", false},
					{"Float Options Digits", 3U},
					{"String Preview Length", 16U},
					{"Options Cross Toggle Close", false},
					{"Output Notification", true},
					{"Log Notification", true},
					{"Output Notification Debug String", false},
					{"Check Client Privileges Status", false},
					
					MAKE_COMBOBOX("Check Module Toggle", "Async",
						{"Off", "Sync", "Async"}),

					{"Check Module Toggle Cooldown (ms)", 10000U},
					{"Check Client Privileges Cooldown (ms)", 20000U},
					{"Output Configs Saving", false},
					//{"Notify Audio Device Change", true},

					{"Process List Update Async Mode", true},
					{"Process List Update Freq (Hz)", 15.0f},

					MAKE_COMBOBOX("Max FPS", "120",
						{"30", "60", "90", "120", "240", "Unlimited"}),

					MAKE_COMBOBOX("File Size Unit Base", "1000",
							{"1000", "1024"}),

					//{"Support High DPI", false},
					{"Always Run", true},
					{"Always Admin", false},

					MAKE_COMBOBOX("GetProcAddress", "Default",
					{"Default", "Manual"}),
					/*{"Esc Key Exit", false},*/
				},
			},

{
"GUI",

	{
	   /*GUI_STYLE_PRESETS,*/

	   MAKE_COMBOBOX("Window Display Mode", "Undecorated",
		   {"Undecorated", "Borderless"}),

	   MAKE_COMBOBOX("GUI Style (Restart to Apply)", "Fancy",
		   {"Fancy", "Imgui"}),

	   {"Arrow Key Move Speed", 5.0f},
	   {"Close When No Focus", false},
	   {"Better Topmost", true},
	   {"Disable DPI Scaling", false},
	   {"Black Screen Problem Fix", true},
	   {"Anti Aliasing", true},
	   
	   MAKE_COMBOBOX("Change Focus Before Open GUI", "FocusWindow",
			{"Off", "Simulated Click", "FocusWindow"}),

		{"Change Focus Simulated Click Gap Min (ms)", 30L},
		{"Change Focus Simulated Click Gap Max (ms)", 50L},

	   {"Menu Auto Focus When Open", true},
	   {"Menu Cancel Focus In Minecraft", true},

	   {"Opacity (0~1)", 1.0f},
	   {"Round Corners", false},
	   {"Round Corners of Boolean Box", true},
	   {"Rainbow GUI", false},
	   {"Outline", true},
	   {"Display Module Option Default Value", true},
	   {"Module Option Wheel Sensitivity", 36.0f},
	   {"Module Option Key Color", "255;255;255;255"},
	   {"Module Option Boolean Box Color", "205;155;29;255"},
	   {"Module Option Help Font Size", 35},
	   {"Module Option Editing Mask Alpha (0~1)", 0.6f},
	   {"Top Tab Font Size", 20},
	   {"Top Tab Text Color", "253;249;0;255"},
	   {"Module Font Size", 26},
	   {"Module Text Color", "245;245;245;255"},
	   {"Module Text Color (Enabled)", "245;245;245;255"},
	   {"Module Text Color (Unavailable)", "170;170;170;255"},
	   {"Tab Theme Color", "72;88;104;255"},
	   {"Module Hover Background Color", "65;55;45;230"},
	   {"Module Height", 25},
	   {"ClickGUI Global Scale", 100.0},
	   {"ClickGUI Ctrl+Wheel Zoom", true},
	   {"Hacked Module Names", false},
	   {"Remove Spaces in Module Names", false},
	   {"Custom Image Path", ""},
	   {"Custom Image Opacity (0~1)", 1.0f},
	   {"Custom Image Scale", 100.0f},
	   {"Custom Image Moving Speed", 0.0f},
	   {"Custom Image Clip", false},
	   {"Custom Image Clip X Start Rate", 0.0f},
	   {"Custom Image Clip X End Rate", 1.0f},
	   {"Custom Image Clip Y Start Rate", 0.25f},
	   {"Custom Image Clip Y End Rate", 0.75f},
	   {"Bottom-Left Tip", true},
	   {"Bottom-Left Tip Font Size", 24},

	   MAKE_COMBOBOX("Chat Box Animation", "Off",
		   {"Off", "Fade", "Slide (Top)", "Slide (Bottom)", "Slide (Left)", "Slide (Right)",
			"Enlarge", "Enlarge II", "Shrink", "Shrink II"
		   }),

	   {"Chat Box Animation Duration (ms)", 500L},
	   {"Chat Box Y Rate", 1.0f},
	   {"Chat Box Font Size", 50},
	   {"Chat Box Opacity (0~1)", 0.6f},
	   {"Chat Box Font Name", "Calibri"},
	   {"Chat Box Animation FPS", 30.0f},

	   {"ImGui Input Box Width", 750.0f},
	   {"ImGui Move With Arrow Keys", false},
	   {"ImGui Resize With Ctrl+Arrow Keys", false},

	   MAKE_COMBOBOX("Custom Image", "Off",
		   {"Off", "Clip", "Center", "Bottom-Left", "Bottom-Right", "Bottom-Center"}),

	   MAKE_COMBOBOX("Tab Name Case Style", "Normal",
	   {"Normal", "Upper Case", "Lower Case", "Annoying Case"/*, "Fancy Letters"*/}),

	   MAKE_COMBOBOX("Module Name Case Style", "Normal",
	   {"Normal", "Upper Case", "Lower Case", "Annoying Case"/*, "Fancy Letters"*/}),

	   MAKE_COMBOBOX("Tab Name Alignment", "Center",
	   {"Center", "Left", "Right"}),

	   MAKE_COMBOBOX("Module Name Alignment", "Left",
	   {"Center", "Left", "Right"}),

	   MAKE_COMBOBOX("Module Background Color (Enabled)", "Rainbow",
	   {"Transparent", NAMED_COLOR_BASE_LIST}),

	   MAKE_COMBOBOX("Module Background Color", "Transparent",
	   {"Transparent", NAMED_COLOR_BASE_LIST}),

	   {"Module Background Blackness (0~1)", 0.9f},

	   MAKE_COMBOBOX("Tab Width Mode", "Auto",
		   {"Auto", "Fixed"}),

		{"Tab Width Minimum (Auto)", 170},
		{"Tab Width Maximum (Auto)", 600},
		{"Tab Width Addition (Auto)", 0},
		{"Tab Width (Fixed)", 250},
		{"Tab Animation Delay Enabled", true},
		{"Tab Animation Delay", 28L},
	    {"Tab Shadows", true},
		{"Tab Shadows Thickness", 50.0f},
		{"Tab Shadows Opacity (0~1)", 0.6f},
	    {"Tab Limit Coords", false},

		MAKE_COMBOBOX("Description Position", "Bottom",
			{"Bottom", "Follow"}),

		MAKE_COMBOBOX("Description Color", "Red-Orange",
			{NAMED_COLOR_BASE_LIST}),

		/*MAKE_COMBOBOX("Tab Shadows Color", "Black",
			{NAMED_COLOR_BASE_LIST}),*/

		{"Description Opacity (0~1)", 1.0},

	   {"Description Font Size", 25},
	   // {"Modules Column Top", 40},
   //	{"Support RCtrl Toggle", true},

	   /*MAKE_COMBOBOX("Menu Toggle Key", "RCtrl/RShift",
		   {"RCtrl", "RShift", "RCtrl/RShift"}),*/

	   {"Menu Toggle Key 1", {{"Keybind", {VK_RCONTROL}}}},
	   {"Menu Toggle Key 2", {{"Keybind", {VK_RSHIFT}}}},

	   MAKE_COMBOBOX("Menu Toggle Animation", "Slide (Top)",
		   {"Off", "Fade", "Slide (Top)", "Slide (Bottom)", "Slide (Left)", "Slide (Right)",
			"Enlarge", "Enlarge II", "Shrink", "Shrink II"
		   }),

	   {"Menu Toggle Animation Duration (ms)", 400L},

	   MAKE_COMBOBOX("Requirement Icon", "On",
		   {"Off", "On"}),

	   {"Always Focused", false},
	   //{"Show FPS", true},
	   {"Show Module Description", true},
	   {"Save Tabs Status Data", true},

	   MAKE_COMBOBOX("Launcher UI Style", "Random",
	   {"Default", "Vape", "Jackal", "Neon", "Matrix", "Aurora", "Random"}),

	   {"Launcher Shaking", false},

		/*{"Font Name", "Minecraft Unpixelated.ttf"},*/
		MAKE_COMBOBOX("Font", "GoogleSans.ttf",
		{
			"Minecraft AE Pixel.ttf",
		//"crafters-delight.ttf",
		//"fs-roundcraft.ttf",
			//"msyh.ttc",
			//"DingTalk JinBuTi.ttf",
			"GoogleSans.ttf",
			"HarmonyOS_SansSC_Medium.ttf",
			"Custom"
			//"Metropolis-Medium.ttf",
			/*"Nirmala.ttf",*/
			//"ubuntu.ttf",
		/*	"STXIHEI.ttf",*/
			//"segmono_boot.ttf",
	/*		"segoeui.ttf",*/
	/*		"Tahoma.ttf",*/
			//"Unifont.ttf",
			}),

	   {"Custom Font Path", "C:\\Windows\\Fonts\\simsun.ttc"},

		MAKE_COMBOBOX("Font Reload Policy (for Non-ASCII)", "Update Record, Dynamic",
			{"Deny", "Fixed Record, Dynamic", "Update Record, Dynamic", "Dynamic",
					"Fixed Record, Deny", "Update Record, Deny"}),

		MAKE_COMBOBOX("Font Non-ASCII Character Record", "Basic",
			{"Basic", "Extended"}),

		{"Font Reload Cooldown (ms)", 400U},

		{"Font Import Size", 100},

		MAKE_COMBOBOX("Language/语言", "English",
			{"English", "简体中文", "繁體中文", "繁體中文（香港）", "繁體中文（臺灣）", "繁體中文（日本）"}),

	    {"Chinese Translation Buffer", true},
	    {"Chinese Translation Cooldown (ms)", 200L},

		MAKE_COMBOBOX("Esc Key Action", "Close Menu",
		{"None", "Close Menu", "Exit"}),

	   {"Search Wheel Sensitivity", 75.0f },
	   {"Profile List Width", 600},
	   {"Profile List Height Rate", 0.55f},
	   {"Profile Show Invalid", false},
	}
},

{"HUD",

	{
		{"HUD Enabled", true},
		
			{"Disable Notification", false},

			MAKE_COMBOBOX("FPS Display", "Menu On",
				{"Off", "Menu Off", "Menu On", "Always"}),

			{"FPS Font Size", 120},
			{"FPS Opacity (0~1)", 0.3f},
			{"FPS X Rate", 0.3},
			{"FPS Y Rate", 0.01},

			MAKE_COMBOBOX("Client Watermark Display", "Menu On",
				{"Off", "Menu Off", "Menu On", "Always"}),

			MAKE_COMBOBOX("Client Watermark Style", "Jackal",
				{"Jackal", "Jackal Ver", "JackalClient", "JackalClient Ver"}),

			MAKE_COMBOBOX("Client Watermark Case Style", "Normal",
				{"Normal", "Upper Case", "Lower Case", "Annoying Case"/*, "Fancy Letters"*/}),

			MAKE_COMBOBOX("Client Watermark Main Color", "Rainbow",
				{NAMED_COLOR_BASE_LIST}),

			{"Client Watermark Font Size", 120},
			{"Client Watermark Opacity Min (0~1)", 0.2f},
			{"Client Watermark Opacity Max (0~1)", 0.4f},
			{"Client Watermark X Rate", 0.01},
			{"Client Watermark Y Rate", 0.01},
			
			MAKE_COMBOBOX("FPS Color", "Green",
			{NAMED_COLOR_BASE_LIST}),

			MAKE_COMBOBOX("Override Notify When Hidden", "WinToast",
			{"Off", "WinToast", "MessageBox"}),

			{"Notify MessageBox Duration Coefficient", 0.2f},

			MAKE_COMBOBOX("Notify Style", "Metro",
			{"WinToast", "Metro", "Chatter", "Fancy", "MessageBox"}),

			MAKE_COMBOBOX("Notify Metro Style", "Vape",
			{"Old", "Vape", "SilenceFix", "LiquidBounce NextGen"}),

			MAKE_COMBOBOX("Notify Translator", "Off",
				{"Off", "Latency", "Ready"}),

			{"Notify MessageBox Random Position", true},
			{"Notify MessageBox Set as Foreground", true},
			{"Notify Font Size", 35},
			{"Notify Min Width", 200},
			{"Notify Height", 45},
			{"Notify Stay Time (0~1)", 0.3},
			{"Notify Opacity (0~1)", 0.9f},
			{"Notify Horizontal Margin", 80},
			{"Notify Vertical Margin", 150},
			{"Notify Line Gap", 10},

			MAKE_COMBOBOX("Notify Start Position", "Bottom-Right",
			{"Bottom-Right", "Top-Right", "Bottom-Left", "Top-Left"}),

			{"Chatter Line Gap", 10},
			{"Chatter Show Duration", 10000U},
			{"Chatter Font Size", 60},
			{"Chatter Opacity (0~1)", 0.8f},

			MAKE_COMBOBOX("Chatter Movement", "Linear",
			 {"Linear", "EaseInOutSine"}),

			MAKE_COMBOBOX("Chatter Row Decision", "Auto",
			    {"Auto", "Random"}),

			MAKE_COMBOBOX("Chatter Outline", "Shadow",
				{"Off", "Shadow", "Stroke"}),

			{"Notify WinToast Attempt to Jump Queue", false},
			{"Notify AntiSpam", false},
			{"Notify AntiSpam Min Similarity (0~1)", 0.8f},
			{"Enable Some Tray Tips", true},

			MAKE_COMBOBOX("Notify Module Toggle", "Always",
				{"Off", "Classic", "Keybind", "Always"}
				),

			{"Notify Font Reload", false},
			
			MAKE_COMBOBOX("Notify Device Changes", "Audio Device",
			{"Off", "Audio Device", "All"}),

			//{"Show Font Extra Chars", false},
			{"Rainbow Speed", 60.0f},
			/*{"Welcome Splash", false}*/
			//{"Superb Notify", false},
			/*MAKE_COMBOBOX("Startup Interface", "Classic",
				{"Off", "Zoom", "Classic", "Fade"}),*/
	}
},

{"Sound",
	{
		{"Notification Sound", true},
		{"Tray Tip Sound", true},
		{"Sound When Hidden", false},
		//{"Reinitialize When Audio Device Changed", true},

		MAKE_SOUNDITEM("Sound (Info)", "toast.wav"),
		MAKE_SOUNDITEM("Sound (Warn)", "pling_low.wav"),
		MAKE_SOUNDITEM("Sound (Error)", "bassattack.wav"),
		MAKE_SOUNDITEM("Sound (Success)", "icechime.wav"),
		MAKE_SOUNDITEM("Sound (Enable)", "enable.wav"),
		MAKE_SOUNDITEM("Sound (Disable)", "disable.wav"),
	}
},
};


json gui_style_presets
{
	/*{"Default", 
	},*/
{"Vape",
{
	{"Round Corners", false},
	{"Outline", false},
	{"Rainbow GUI", false},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Left"},
	{"Module Background Color (Enabled)", "Green"},
	{"Module Background Color", "Black"},
	{"Menu Toggle Animation", "Off"},
	{"Show Module Description", false},
	{"Show FPS", false},
	{"Remove Spaces in Module Names", true},
	{"Module Font Size", 23},
	{"Module Height", 37},
	{"Module Text Color", "200;200;200"},
	{"Module Text Color (Enabled)", "200;200;200"},
	{"Module Text Color (Unavailable)", "150;150;150"},
	{"Tab Theme Color", "10;10;10"},
	{"Tab Name Alignment", "Left"},
	{"Tab Name Case Style", "Normal"},
	{"Tab Width Mode", "Fixed"},
	{"Tab Width (Fixed)", 290},
	{"Top Tab Text Color", "230;230;230"},
}
},


{"LiquidBounce",
{
	{"Round Corners", false},
	{"Outline", false},
	{"Rainbow GUI", false},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Left"},
	{"Module Background Color (Enabled)", "Aqua"},
	{"Module Background Color", "Transparent"},
	{"Menu Toggle Animation", "Fade"},
	{"Show Module Description", true},
	{"Show FPS", false},
	{"Remove Spaces in Module Names", true},
	{"Module Font Size", 27},
	{"Module Height", 32},
	{"Module Text Color", "200;200;200"},
	{"Module Text Color (Enabled)", "200;200;200"},
	{"Module Text Color (Unavailable)", "150;150;150"},
	{"Tab Theme Color", "58;71;94"},
	{"Tab Name Alignment", "Center"},
	{"Tab Name Case Style", "Normal"},
	{"Tab Width Mode", "Auto"},
	{"Tab Width (Fixed)", 270},
	{"Top Tab Text Color", "200;200;200"},
}
},

{"LiquidBounce NextGen",
{
	{"Round Corners", false},
	{"Outline", false},
	{"Rainbow GUI", false},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Center"},
	{"Module Background Color (Enabled)", "Transparent"},
	{"Module Background Color", "Transparent"},
	{"Menu Toggle Animation", "Fade"},
	{"Show Module Description", true},
	{"Show FPS", false},
	{"Remove Spaces in Module Names", false},
	{"Module Font Size", 21},
	{"Module Height", 39},
	{"Module Text Color", "200;200;200"},
	{"Module Text Color (Enabled)", "89;118;247"},
	{"Module Text Color (Unavailable)", "150;150;150"},
	{"Tab Theme Color", "32;34;37;190"},
	{"Tab Name Alignment", "Center"},
	{"Tab Name Case Style", "Normal"},
	{"Tab Width Mode", "Auto"},
	{"Tab Width (Fixed)", 280},
	{"Top Tab Text Color", "aqua"},
}
},


{"Raven",
{
	{"Round Corners", true},
	{"Outline", true},
	{"Rainbow GUI", false},
	{"Font", "Minecraft AE Pixel.ttf"},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Center"},
	{"Module Background Color (Enabled)", "Transparent"},
	{"Module Background Color", "Transparent"},
	{"Menu Toggle Animation", "Fade"},
	{"Show Module Description", true},
	{"Show FPS", false},
	{"Remove Spaces in Module Names", true},
	{"Module Font Size", 15},
	{"Module Height", 40},
	{"Module Text Color", "200;200;200"},
	{"Module Text Color (Enabled)", "89;118;247"},
	{"Module Text Color (Unavailable)", "150;150;150"},
	{"Tab Theme Color", "32;34;37;210"},
	{"Tab Name Alignment", "Left"},
	{"Tab Name Case Style", "Lower Case"},
	{"Tab Width Mode", "Auto"},
	{"Tab Width (Fixed)", 270},
	{"Top Tab Text Color", "180;180;180"},
}
},

{"Meteor",
{
	{"Round Corners", false},
	{"Outline", false},
	{"Rainbow GUI", false},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Left"},
	{"Module Background Color (Enabled)", "Gray"},
	{"Module Background Color", "Black"},
	{"Menu Toggle Animation", "Off"},
	{"Show Module Description", true},
	{"Show FPS", false},
	{"Remove Spaces in Module Names", false},
	{"Module Font Size", 25},
	{"Module Height", 30},
	{"Module Text Color", "200;200;200"},
	{"Module Text Color (Enabled)", "200;200;200"},
	{"Module Text Color (Unavailable)", "150;150;150"},
	{"Tab Theme Color", "124;30;235"},
	{"Tab Name Alignment", "Center"},
	{"Tab Name Case Style", "Normal"},
	{"Tab Width Mode", "Auto"},
	{"Tab Width (Fixed)", 280},
	{"Top Tab Text Color", "180;180;180"},
}
},
};