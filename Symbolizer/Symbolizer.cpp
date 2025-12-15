// Symbolizer.cpp
// Usage: symbolizer.exe <crash_log.txt> [symbol_search_path]
// Written by GPT5 & Wormwaker

#ifdef _WIN64
#error This tool must be compile in 32-bit, same as the client executable.
#endif

#include <windows.h>
#include <dbghelp.h>
#include <shlwapi.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <regex>
#include <iomanip>

#pragma comment(lib, "dbghelp.lib")
#pragma comment(lib, "shlwapi.lib")

using namespace std;

void SetColor(UINT uFore, UINT uBack = 0)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, uFore + uBack * 0x10);
}
static string ToLower(string s) {
    for (auto& c : s) c = (char)tolower((unsigned char)c);
    return s;
}

// Find a file named 'filename' under search paths (semicolon-separated).
// Returns full path if found, else empty string.
string FindModuleOnSearchPaths(const string& filename, const string& searchPaths)
{
    // If filename is already a path and exists, return it
    if (PathFileExistsA(filename.c_str()))
        return filename;

    vector<string> paths;
    string cur;
    for (size_t i = 0; i <= searchPaths.size(); ++i) {
        if (i == searchPaths.size() || searchPaths[i] == ';') {
            if (!cur.empty()) {
                paths.push_back(cur);
                cur.clear();
            }
        }
        else {
            cur.push_back(searchPaths[i]);
        }
    }
    // also include current directory
    paths.insert(paths.begin(), ".");

    // Try each path
    for (auto& p : paths) {
        string candidate = p;
        if (!candidate.empty() && candidate.back() != '\\' && candidate.back() != '/')
            candidate += "\\";
        candidate += filename;
        if (PathFileExistsA(candidate.c_str()))
            return candidate;
    }
    return "";
}
string strip(const string& s)
{
    // 找到第一个非空白字符的位置
    auto start = find_if_not(s.begin(), s.end(), [](int c) { return isspace(c); });

    // 找到最后一个非空白字符的位置
    auto end = find_if_not(s.rbegin(), s.rend(), [](int c) { return isspace(c); }).base();

    // 返回去除空白字符后的子串
    return (start >= end ? string() : string(start, end));
}
// Parse lines like:
//   JackalClient.exe + 0x3545fd
//   kernel32.dll + 0x1A2B
//   [0x00E745FD]
//   0: [0x00E745FD]
// Returns vector of tuples (module, offset, original_line_index)
struct Entry {
    string module; // can be empty if only absolute address provided
    uint64_t offset; // if module present: offset; if only address present: absolute addr
    bool is_absolute; // true if offset is absolute address (no module)
    string rawline;
    int line_no;
};

vector<Entry> ParseCrashLog(const string& path)
{
    vector<Entry> out;
    ifstream ifs(path);
    if (!ifs) {
        SetColor(12);
        cerr << "Failed to open crashlog: " << path << "\n";
        return out;
    }

    string line;
    int lineno = 0;

    // regex patterns
    regex re_mod_off(R"(([\w\.\-@]+)\s*\+\s*0x([0-9A-Fa-f]+))"); // Module.exe + 0x123
    regex re_bracket_addr(R"(\[?\s*0x([0-9A-Fa-f]+)\s*\]?)"); // [0x123] or 0x123
    regex re_absolute_only(R"(^\s*0x([0-9A-Fa-f]+)\s*$)");

    while (std::getline(ifs, line)) {
        ++lineno;
        smatch m;
        string trimmed = line;
        // try module + offset
        if (regex_search(line, m, re_mod_off)) {
            Entry e;
            e.module = m[1].str();
            string offs = m[2].str();
            e.offset = stoull(offs, nullptr, 16);
            e.is_absolute = false;
            e.rawline = line;
            e.line_no = lineno;
            out.push_back(e);
            continue;
        }

        // try bracket or plain address
        if (regex_search(line, m, re_bracket_addr)) {
            // but ensure not to catch address inside full path; naive approach ok for crash logs
            Entry e;
            e.module = "";
            string addr = m[1].str();
            e.offset = stoull(addr, nullptr, 16);
            e.is_absolute = true;
            e.rawline = line;
            e.line_no = lineno;
            out.push_back(e);
            continue;
        }
    }

    return out;
}


// Symbolize workflow:
//  - For each unique module name encountered (non-empty), try to locate the file using searchPath.
//  - Load module with SymLoadModuleEx using a synthetic base (unique per module).
//  - For absolute addresses (no module), we will attempt to resolve by scanning loaded modules that have been loaded earlier,
//    but since we don't know original base we attempt per-module if possible.
//  - For each Entry, compute absolute address = moduleBase + offset (if module) or addr (if absolute).
//  - Call SymFromAddr and SymGetLineFromAddr64.
struct ModuleInfo {
    string name;
    string fullpath;
    uint64_t base;
    ULONG64 moduleHandle; // value returned by SymLoadModuleEx (same as base)
};

string SafeString(const char* s) { return s ? string(s) : string(); }

int main(int argc, char** argv)
{
    if (argc < 2) {
        SetColor(6);
        std::cout << "Usage: symbolizer.exe <crash_log.txt>\n";
        system("Pause");
        return 1;
    }

    std::string crashLogPath = argv[1];
    std::ifstream ifs(crashLogPath);
    if (!ifs) {
        SetColor(12);
        std::cerr << "Failed to open crashlog: " << crashLogPath << "\n";
        system("pause");
        return 1;
    }

    // --- 自动提取版本号 ---
    std::string versionStr = "unknown", baseVersion = "unknown", edition = "Free";
    std::string line;
    while (std::getline(ifs, line)) {
        //if (line.find("Version:") != std::string::npos) {
        //    size_t pos = line.find("Version:");
        //    if (pos != std::string::npos) {
        //        version = line.substr(pos + 8);
        //        // 去掉前后空格
        //        version.erase(0, version.find_first_not_of(" \t\r\n"));
        //        version.erase(version.find_last_not_of(" \t\r\n") + 1);
        //    }
        //    break;
        //}
        if (line.find("Version:") != std::string::npos) {
            size_t pos = line.find("Version:");
            versionStr = line.substr(pos + 8);
            versionStr = strip(versionStr);

            // 判断是否包含 Pro
            if (versionStr.find("Pro") != std::string::npos) {
                edition = "Pro";
            }
            else {
                edition = "Free";
            }

            // 去掉 Pro / Free，得到基础版本
            baseVersion = versionStr;
            size_t p = baseVersion.find("Pro");
            if (p != std::string::npos) {
                baseVersion = baseVersion.substr(0, p);
            }
            baseVersion = strip(baseVersion);
        }

    }
    ifs.close();

    if (baseVersion == "unknown") {
        SetColor(12);
        std::cerr << "Failed to extract version from crash log.\n";
        SetColor(15);
        std::cout << "Please input it manually (e.g. v0.7c): ";
        std::getline(std::cin, baseVersion);
        SetColor(14);
        std::cout << "Choose edition (0=Free, 1=Pro): ";

        int i{ 0 };
        std::cin >> i;
        if (i == 0) {
            edition = "Free";
        }
        else {
            edition = "Pro";
        }
    }
    else {
        SetColor(10);
        std::cout << "[*] Detected version: " << baseVersion << "\n";
    }

    SetColor(14);
    std::cout << "[*] Selected Edition: " << edition << "\n";

    // 客户端编译生成后事件：copy /Y "$(TargetPath)" "D:\JackalClientSymbols\$(ClientVersion)\$(TargetName).exe"
    // --- 构造符号搜索路径 ---
    std::string symRoot = "D:\\JackalClientSymbols\\";
    std::string symPath = symRoot + edition + "\\" + baseVersion;// +";D:\\Wormwaker\\PROGRAMS\\C、C++\\System\\JackalClient\\Release";
    SetColor(3);
    std::cout << "[*] Using symbol search path: " << symPath << "\n";

    // 调用原逻辑
    std::vector<Entry> entries = ParseCrashLog(crashLogPath);
    if (entries.empty()) {
        SetColor(12);
        std::cout << "[!] No addresses found in crash log.\n";
        system("pause");
        return 1;
    }

    HANDLE hProc = GetCurrentProcess();

    if (!SymInitialize(hProc, symPath.c_str(), FALSE)) {
        DWORD err = GetLastError();
        SetColor(12);
        std::cerr << "[!] SymInitialize failed: " << err << "\n";
        system("pause");
        return 1;
    }

    SymSetOptions(SymGetOptions() | SYMOPT_LOAD_LINES | SYMOPT_UNDNAME);

    // gather unique modules
    map<string, ModuleInfo> modules;
    set<string> moduleNamesOrder;
    for (auto& e : entries) {
        if (!e.is_absolute && !e.module.empty()) {
            string key = e.module;
            // normalize case
            string lk = ToLower(key);
            if (!modules.count(lk)) {
                ModuleInfo mi;
                mi.name = key;
                mi.fullpath = ""; mi.base = 0; mi.moduleHandle = 0;
                modules[lk] = mi;
                moduleNamesOrder.insert(lk);
            }
        }
    }

    // try to find module files for each module name
    uint64_t nextBase = 0x400000; // 典型32位映像基址
    const uint64_t baseStep = 0x01000000ULL; // 16MB step

    for (auto& kv : modules) {
        string lname = kv.first;
        ModuleInfo& mi = kv.second;
        // find file under searchPath
        string found = FindModuleOnSearchPaths(mi.name, symPath);
        if (found.empty()) {
            // try with .dll/.exe appended
            if (!PathFindExtensionA(mi.name.c_str()) || strlen(PathFindExtensionA(mi.name.c_str())) == 0) {
                string nmexe = mi.name + ".exe";
                found = FindModuleOnSearchPaths(nmexe, symPath);
                if (found.empty()) {
                    string nmdll = mi.name + ".dll";
                    found = FindModuleOnSearchPaths(nmdll, symPath);
                }
            }
        }
        if (found.empty()) {
            SetColor(12);
            cout << "[!] Module file not found for: ";
            SetColor(7);
            cout << mi.name;
            SetColor(12);
            cout << " under search paths. Symbolization may fail for its frames.\n";
            continue;
        }
        mi.fullpath = found;
        mi.base = nextBase;
        nextBase += baseStep;

        // Load module symbols
        DWORD64 hmod = SymLoadModuleEx(
            hProc,
            NULL,
            mi.fullpath.c_str(),
            NULL,
            (DWORD64)mi.base,
            0,
            NULL,
            0
        );
        if (hmod == 0) {
            DWORD err = GetLastError();
            SetColor(12);
            cout << "[!] SymLoadModuleEx failed for " << mi.fullpath << " (err=" << err << ")\n";
        }
        else {
            mi.moduleHandle = hmod;
            SetColor(10);
            cout << "[*] Loaded symbols for ";
            SetColor(14);
            cout << mi.name;
            SetColor(10);
            cout << " from ";
            SetColor(3);
            cout << mi.fullpath;
            SetColor(10);
            cout << " at base 0x" << std::hex;
            SetColor(12);
            cout << mi.base << std::dec << "\n";
        }
    }

    // For absolute addresses (no module), we might attempt to resolve them against any loaded module if the user included exception address absolute values.
    // We'll attempt: for each absolute address, check if it falls within any synthetic module range (base..base+image_size) - image_size unknown, so we'll try SymFromAddr directly.

    // Prepare buffer for SYMBOL_INFO
    const size_t symBufferSize = sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(char);
    vector<char> symBuffer(symBufferSize);
    PSYMBOL_INFO pSymbol = reinterpret_cast<PSYMBOL_INFO>(symBuffer.data());
    pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
    pSymbol->MaxNameLen = MAX_SYM_NAME;

    // Process each entry and attempt symbolization
    SetColor(15);
    cout << "\n==== Symbolized Output ====\n";
    for (auto& e : entries) {
        SetColor(9);
        cout << "[" << setw(4) << e.line_no << "] ";
        if (!e.is_absolute && !e.module.empty()) {
            string key = ToLower(e.module);
            if (modules.count(key) && modules[key].moduleHandle != 0) {
                uint64_t absolute = modules[key].base + e.offset;
                // try symbol
                DWORD64 displacement = 0;
                ZeroMemory(pSymbol, symBufferSize);
                pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
                pSymbol->MaxNameLen = MAX_SYM_NAME;

                if (SymFromAddr(hProc, absolute, &displacement, pSymbol)) {
                    // get line info
                    IMAGEHLP_LINE64 line = { 0 };
                    line.SizeOfStruct = sizeof(line);
                    DWORD linDis = 0;
                    bool haveLine = false;
                    if (SymGetLineFromAddr64(hProc, absolute, &linDis, &line)) {
                        haveLine = true;
                    }
                    SetColor(7);
                    cout << e.rawline;
                    SetColor(12);
                    cout << " -> ";
                    SetColor(6);
                    cout << pSymbol->Name;
                    SetColor(14);
                    cout << " + 0x" << std::hex << displacement << std::dec;
                    if (haveLine) {
                        SetColor(11);
                        cout << " (" << SafeString(line.FileName) << ":" << line.LineNumber << ")";
                    }
                    cout << "\n";
                }
                else {
                    DWORD err = GetLastError();
                    SetColor(7);
                    cout << e.rawline;
                    SetColor(12);
                    cout << " -> [no symbol] (absolute=0x" << hex << absolute << dec << ") err=" << err << "\n";
                }
            }
            else {
                SetColor(7);
                cout << e.rawline;
                SetColor(5);
                cout << " -> [module not loaded]\n";
            }
        }
        else {
            // absolute address case
            uint64_t absolute = e.offset;
            DWORD64 displacement = 0;
            ZeroMemory(pSymbol, symBufferSize);
            pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
            pSymbol->MaxNameLen = MAX_SYM_NAME;

            if (SymFromAddr(hProc, absolute, &displacement, pSymbol)) {
                IMAGEHLP_LINE64 line = { 0 };
                line.SizeOfStruct = sizeof(line);
                DWORD linDis = 0;
                bool haveLine = false;
                if (SymGetLineFromAddr64(hProc, absolute, &linDis, &line)) haveLine = true;
                SetColor(7);
                cout << e.rawline;
                SetColor(12);
                cout << " -> ";
                SetColor(6);
                cout << pSymbol->Name;
                SetColor(14);
                cout << " + 0x" << std::hex << displacement << std::dec;
                SetColor(13);
                if (haveLine) cout << " (" << SafeString(line.FileName) << ":" << line.LineNumber << ")";
                cout << "\n";
            }
            else {
                SetColor(7);
                cout << e.rawline;
                SetColor(12);
                cout << " -> [no symbol for absolute addr 0x" << hex << absolute << dec << "]\n";
            }
        }
    }

    // cleanup
    SymCleanup(hProc);
    SetColor(2);
    cout << "\nDone.\n";
    system("PaUse");
    return 0;
}
