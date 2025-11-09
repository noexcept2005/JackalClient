#pragma once

// 定义一个秘密密钥
const UINT64 TOKEN_SECRET_KEY = 0x1A7B7C6F5E6F9E4FUL;

// 获取当前时间戳（以分钟为单位）
UINT64 GetCurrentMinutesSinceEpoch() {
    auto now = chrono::system_clock::now();
    auto seconds_since_epoch = chrono::duration_cast<chrono::seconds>(now.time_since_epoch()).count();
    return seconds_since_epoch / 60;
}

// 根据时间戳和其他因素计算凭据
DWORD CalcDefaultSettingsToken() {
    // 获取当前分钟数
    UINT64 minutes = GetCurrentMinutesSinceEpoch();

    // 使用秘密密钥与时间戳结合
    UINT64 combined_value = minutes ^ TOKEN_SECRET_KEY;

    // 添加额外的混淆步骤，例如通过移位和进一步的异或操作
    combined_value = (combined_value << 13) | (combined_value >> 51); // 旋转
    combined_value ^= 0x6A3479C37F4E7D15UL; // 加入一个固定的常量

    // 取模操作确保结果适合放入一个 DWORD 中
    DWORD token = static_cast<DWORD>((combined_value + 1UL) % (numeric_limits<DWORD>::max() - 1UL));

    return token;
}