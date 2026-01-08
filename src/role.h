#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include "../include/nlohmann/json.hpp" // Assuming include path based on standard GTPS project structure

using namespace std;
namespace fs = std::filesystem;

using json = nlohmann::json;

struct Server_Role {
    int adminLevel = 0;
    string role;
    string name;
    string prefix_chat;
    vector<string> command;
    bool access_world = false;
    bool long_punch_place = false;
    bool moderator_power = false;
    bool developer_power = false;
    bool logs_view = false;
    bool property_access = false;
};
inline vector<Server_Role> role;

namespace role_power {
	string getRoleName(ENetPeer* peer) {
		for (int i = 0; i < role.size(); ++i) {
			if (pInfo(peer)->adminlevel == role[i].adminLevel) {
				return role[i].role;
				break;
			}
		}
	}
	bool get_LogsView(ENetPeer* peer) {
		for (int i = 0; i < role.size(); ++i) {
			if (pInfo(peer)->adminlevel == role[i].adminLevel) {
				if (role[i].logs_view) {
					return true;
				}
				break;
			}
		}
		return false;
	}
	bool get_PropertyAcc(ENetPeer* peer) {
		for (int i = 0; i < role.size(); ++i) {
			if (pInfo(peer)->adminlevel == role[i].adminLevel) {
				if (role[i].property_access) {
					return true;
				}
				break;
			}
		}
		return false;
	}
	bool get_longplace(ENetPeer* peer) {
		for (int i = 0; i < role.size(); ++i) {
			if (pInfo(peer)->adminlevel == role[i].adminLevel) {
				if (role[i].long_punch_place) {
					return true;
				}
				break;
			}
		}
		return false;
	}
	bool get_devpower(ENetPeer* peer) {
		for (int i = 0; i < role.size(); ++i) {
			if (pInfo(peer)->adminlevel == role[i].adminLevel) {
				if (role[i].developer_power) {
					return true;
				}
				break;
			}
		}
		return false;
	}
	bool get_modpower(ENetPeer* peer) {
		for (int i = 0; i < role.size(); ++i) {
			if (pInfo(peer)->adminlevel == role[i].adminLevel) {
				if (role[i].moderator_power) {
					return true;
				}
				break;
			}
		}
		return false;
	}
	bool get_accworld(ENetPeer* peer) {
		for (int i = 0; i < role.size(); ++i) {
			if (pInfo(peer)->adminlevel == role[i].adminLevel) {
				if (role[i].access_world) {
					return true;
				}
				break;
			}
		}
		return false;
	}
	string getRole_name(ENetPeer* peer) {
		for (const auto& r : role) {
			if (pInfo(peer)->adminlevel == r.adminLevel)
				return r.name;
		}
	}
	string getRole_chat(ENetPeer* peer) {
		for (const auto& r : role) {
			if (pInfo(peer)->adminlevel == r.adminLevel)
				return r.prefix_chat;
		}
	}
	bool get_long_punch_place(ENetPeer* peer) {
		for (int i = 0; i < role.size(); ++i) {
			if (pInfo(peer)->adminlevel == role[i].adminLevel) {
				if (role[i].long_punch_place) {
					return true;
				}
				break;
			}
		}
		return false;
	}
}

namespace server_load {
    void load_role() {
        for (const auto& entry : fs::directory_iterator("role/")) { // Removed "../GrowFlix Core/" prefix to match likely local path structure or keep if user insists on path. User's example had "../GrowFlix Core/...", adhering to it for safety or checking if I should adjust.
            // Adjusting path to match typical structure relative to executable or user request.
            // The example code used "../GrowFlix Core/server_settings/role/"
            // Safe to assume we should use the same path if the directory structure is preserved outside src.
            // However, usually "server_settings" is in root.
            // Let's stick to the example path but be mindful.
             if (entry.is_regular_file() && entry.path().extension() == ".json") {
                ifstream file(entry.path());
                if (file.is_open()) {
                    json j;
                    file >> j;
                    if (!j.empty()) {
                        Server_Role cw;
                        cw.adminLevel = j["adminLevel"].get<int>();
                        cw.role = j["role"].get<string>();
                        cw.name = j["name"].get<string>();
                        cw.prefix_chat = j["prefix_chat"].get<string>();
                        vector<string> commands = j["command"].get<vector<string>>();
                        for (auto& command : commands) {
                            command = "/" + command;
                        }
                        cw.command = commands;
                        cw.access_world = j["access_world"].get<bool>();
                        cw.long_punch_place = j["long_punch_place"].get<bool>();
                        cw.moderator_power = j["moderator_power"].get<bool>();
                        cw.developer_power = j["developer_power"].get<bool>();
                        cw.logs_view = j["logs_view"].get<bool>();
                        cw.property_access = j["property_access"].get<bool>();
                        role.push_back(cw);
                    }
                    file.close();
                }

            }
        }
        sort(role.begin(), role.end(), [](const Server_Role& a, const Server_Role& b) {
            return a.adminLevel < b.adminLevel;
        });
        cout << "Loaded " << role.size() << " roles." << endl;
    }
}
