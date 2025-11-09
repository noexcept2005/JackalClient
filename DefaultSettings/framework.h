#pragma once

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
#define NOMINMAX
// Windows 头文件
#include <windows.h>
#include <vector>
#include <string>
#include <chrono>
#include <unordered_map>
using namespace std;

#include "nlohmann/json.hpp"
using json = nlohmann::json;

#include "../XorString.h"
