#pragma once

unordered_map<ModuleID, string> module_chinese_names
{
	{AntiCapture, "反捕获"},
	{AntiClose, "反关闭"},
	{AntiDebug, "反调试"},
	{AntiInject, "反注入"},
	{AntiIntercept, "反拦截"},
	{AntiTaskkill, "反进程杀手"},
	{AntiMouseHook, "反鼠标钩子"},
	{AntiKeyHook, "反键盘钩子"},
	{AutoUAC, "自动管理员"},
	{AutoLogin, "自动登录"},
	{Admin, "管理员"},
	{System, "系统"},
	{UIAccess, "界面特权"},
	{UACBypass, "管理员绕过"},
	{Taskmgr, "任务管理器"},
	{Cmd, "命令提示符"},
	{Gpedit, "组策略"},
	{Regedit, "注册表"},
	{Perfmon, "资源监视器"},
	{Osk, "屏幕键盘"},
	{Mrt, "恶意软件删除工具"},
	{ClearPin, "清除PIN"},
	{CrackPassword, "破解密码"},
	{SetPassword, "篡改密码"},
	{Uninstaller, "一键卸载"},
	{Interceptor, "拦截器"},
	{Gatekeeper, "看门人"},
	{NoFirewall, "关闭防火墙"},
	{FreezeWinlogon, "冻结 Winlogon"},
	{MagnifyReplace, "放大镜替换"},
	{SethcBackdoor, "粘滞键后门"},
	{Privileges, "特权"},
	{Protection, "自保护"},
	{LockUser, "锁定用户"},
	{Logoff, "注销"},
	{Shutdown, "关机"},
	{Reboot, "重启"},
	{MythwareKiller, "极域杀手"},
	{Crash, "蓝屏"},

	{ListTrays, "列举托盘"},
	{WindowTags, "窗口标签"},
	{WindowHighlight, "窗口高亮"},
	{WindowESP, "窗口透视"},
	{WindowKill, "窗口击杀"},
	{WindowFreeze, "窗口冻结"},
	{WindowMaster, "窗口大师"},
	{PrivateWindow, "隐私窗口"},
	{AntiBrowser, "反浏览器"},
	{AntiPopups, "反弹窗"},
	{AntiTopmost, "反置顶"},
	{CloseEnhance, "关闭增强"},
	{DialogEscape, "对话框关闭"},
	{HideTaskbar, "隐藏任务栏"},
	{UncrossAura, "抗关闭光环"},
	{FreezeAura, "冻结光环"},
	{AimAssist, "自动瞄准"},
	{TriggerBot, "触发点击"},
	{KillAuraLegit, "合法杀戮光环"},
	{KillAura, "杀戮光环"},
	{MaxAura, "最大化光环"},
	{MinAura, "最小化光环"},
	{Ruler, "标尺"},

	{ListModules, "枚举模块"},
	{ListDrivers, "枚举驱动"},
	{ListServices, "枚举服务"},
	{Injector, "注入器"},
	{RemoteRun, "远程执行"},
	{Speedhack, "变速齿轮"},
	{GenshinImpact, "原神启动"},
	{Tasklist, "进程列表"},
	{Run, "运行"},
	{ProcessESP, "进程透视"},
	{ProcessKill, "进程击杀"},
	{ProcessKeep, "进程保持"},
	{ProcessFreeze, "进程冻结"},

	{FileDelete, "文件删除"},
	{FileCreate, "文件创建"},
	{FileMonitor, "文件监视"},
	{FolderClear, "目录清空"},
	{TempClear, "临时清空"},
	{RecyclerClear, "回收站清空"},
	{RootProgram, "根目录程序"},
	{PrivacySpy, "隐私密探"},
	{SelfBackup, "自我备份"},
	{SelfRestore, "自我还原"},
	{AutoRestore, "自动还原"},

	{RegMonitor, "注册表监视"},
	{ListHijacks, "劫持调查"},
	{KillHijacks, "清除劫持"},
	{NoCmd, "禁止命令提示符"},
	{NoPowerShell, "禁止PowerShell"},
	{NoTaskmgr, "禁止任务管理器"},
	{NoRegedit, "禁止注册表编辑器"},
	{NoDesktopIcons, "隐藏桌面图标"},
	{NoDesktopMenu, "隐藏桌面菜单"},
	{NoTaskbarMenu, "隐藏任务栏菜单"},
	{NoStartMenuChange, "禁止开始菜单改变"},
	{NoRun, "禁止运行框"},
	{NoLogOff, "隐藏注销"},
	{NoSetFolders, "禁止开始菜单文件夹"},
	{NoFolderOptions, "禁止文件夹选项"},
	{NoWinUpdate, "隐藏系统更新"},
	{NoWinKeys, "禁止Win快捷键"},
	{NoLockUser, "禁止Win+L"},
	{RestrictRun, "限制运行"},
	{NoMSDos, "禁止MSDOS"},
	{NoSmartScreen, "禁用SmartScreen"},
	{NoRemovableDev, "禁止可移动设备"},
	{NoUAC, "禁止UAC"},

	{AutoTotem, "自动图腾"},
	{HighContrast, "高对比度"},
	{BlackCapture, "黑屏捕获"},
	{ScreenSaver, "屏保程序"},
	{CloseMonitor, "关闭显示器"},
	{Crosshair, "准星"},
	{MouseTrails, "鼠标轨迹"},
	{Keystrokes, "按键显示"},
	{Keystrokes2, "按键显示II"},
	{NoAnimation, "禁用动画"},
	{NoScreenSaver, "关闭屏保"},
	{PPLESP, "保护进程透视"},
	{SecurityESP, "安全透视"},
	{ClipboardESP, "剪贴板透视"},
	{MotionBlur, "动态模糊"},
	{Background, "背景"},
	{TimeDisplay, "时间显示"},
	{Totem, "不死图腾"},
	{Watermark, "水印"},
	{WeakView, "节电模式"},
	{Lightness, "伽马覆写"},
	{Spotlight, "聚光灯"},
	{Shaders, "着色器"},
	{Night, "夜晚"},

	{IPAddress, "IP地址"},
	{IPHorror, "IP恐惧"},
	{WallCheck, "墙壁检测"},
	{Weather, "天气"},
	{LiveStream, "直播间"},
	{QQInspect, "QQ窥探"},

	{AntiAFK, "反挂机"},
	{AntiRickroll, "反诈骗"},
	{AutoClicker, "连点器"},
	{BridgeAssist, "搭路辅助"},
	{ChatAsk, "AI回答"},
	{ChatTranslate, "AI翻译"},
	{ChatBilingual, "AI双语"},
	{ChatRestruct, "AI重构"},
	{ClipboardTweaks, "剪贴板功能"},
	{MemeTrigger, "梗触发"},
	{MouseTeleport, "鼠标传送"},
	{MouseWatcher, "鼠标监视"},
	{MouseSwap, "鼠标交换"},
	{NoDoubleClick, "禁止双击"},
	{NoClipboard, "禁止复制"},
	{MouseDisabler, "禁用鼠标"},
	{SnapTap, "急停键"},
	{ToggleKey, "切换键"},
	{Typewriter, "打字机"},
	{KeyDisabler, "禁用键盘"},
	{KeyLogger, "键盘记录"},
	{NoBeep, "禁止蜂鸣"},
	{RestartExplorer, "重启资源管理器"},
	{NoIMC, "禁止输入法"},
	{Panic, "恐慌"},
	{Musics, "音乐"},
	{Volume, "音量"},
	{Mute, "静音"},
	{Active, "活动"},
	{ForceTopmost, "强制置顶"},
	{TaskbarIcon, "任务栏图标"},
	{OpenUrl, "打开链接"},
	{Screenshot, "截图工具"},
	{Console, "控制台"},
	{Hidden, "隐藏至托盘"},
	{Restart, "重新启动"},
	{Exit, "退出"},

	{Anti360Ad, "反数字广告"},
	{Anti360VT, "反数字核晶"},
	{ScaredUAC, "恐惧UAC"},
	{KillEveryone, "全员击杀"},
	{KillAV, "击杀杀软"},
	{CloseAV, "关闭杀软"},
	{KillMalware, "击杀病毒"},
	{FreezeExplorer, "冻结资源管理器"},
	{FreezeEveryone, "全员冻结"},
	{UnfreezeEveryone, "全员解冻"},
	{PPLButcher, "解除进程保护"},
	{TrustedInstaller, "受信任安装者"},
	{RemoteKillHR, "远程杀火绒"},
	{Masquerade, "伪装"},
	{MythwareKiller, "极域杀手"},
	{NoNotification, "关闭通知"},
	{NoRealtimeProtect, "禁用实时保护"},
	{RuinAura, "毁灭光环"},
	{SelfDestruct, "自我删除"},
	{SelfUninstall, "自我卸载"},
	{HideProcess, "隐藏进程"},
	{Vape, "电子烟"},
};

string GetModuleName(ModuleID mid);
