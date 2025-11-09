// 2024/12/10 由于两千多行的默认配置成功让编译器内存爆炸，
// Jackal Client 默认配置单独放到这个 DLL 里面

// by: Wormwaker
// All Rights Reserved.

// x86 DLL
#ifdef _WIN64
#error This dll must be compiled as x86 cuz the client will load it.
#endif

#include "pch.h"
#include "default_settings.h"
#include "calc_token.h"

extern "C" __declspec(dllexport) string GetDefaultSettings(DWORD dwToken)
{
    if (dwToken != CalcDefaultSettingsToken())  //Invalid Token
        return "{}";

    return config_default_jsons.dump();
}

extern "C" __declspec(dllexport) string GetGUIPresetSettings(const char* szPresetName, DWORD dwToken)
{
    if (dwToken != CalcDefaultSettingsToken()  //Invalid Token
        || !gui_style_presets.contains(szPresetName)
        )
        return "{}";

    return gui_style_presets[szPresetName].dump();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    DisableThreadLibraryCalls(hModule);

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

