// encoding=utf-8
#pragma once

#define IS_COMBOBOX(js) (js.is_object() && js.contains("Options") && js.contains("Selected"))
//(js.size() == 2)
//(js.size() == 2 && js[0].items()[0] == "Options" && js[1].items()[0] == "Selected")

#define GET_COMBOBOX(js) (js["Selected"])

#define SET_COMBOBOX(js, value) do { js["Selected"] = value; } while(0)

#define GET_COMBOBOX_OPTIONS(js) (js["Options"])

#define IS_KEYBIND(js)	(js.is_object() && js.contains("Keybind"))

#define GET_KEYBIND_RAW(js)  (js["Keybind"].get<vector<int>>())

#define IS_KEYBIND_EMPTY(js) (js["Keybind"].get<vector<int>>().empty())

extern string GetKeyName(BYTE key, bool space_simplified/* = false*/);

string KeybindString(const vector<int>&keys);

#define GET_KEYBIND(js)	KeybindString(js["Keybind"].get<vector<int>>())

#define SET_KEYBIND(js, keys) do {	js["Keybind"] = keys;	} while (0)

extern unordered_map<ModuleID, string> module_extra_info_dict;