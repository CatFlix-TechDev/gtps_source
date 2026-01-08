#pragma once

#include <cstddef>
#include <string>

#include "../../enet/include/enet.h"

using std::string;

extern string bg_color;
extern string border_color;

struct PlayerMoving;

struct gamepacket_t {
private:
	int index = 0;
	int len = 0;
	bool isDialog = false;
	BYTE* packet_data = new BYTE[61];

public:
	gamepacket_t(int delay = 0, int NetID = -1);
	~gamepacket_t();

	void Insert(string a);
	void Insert(int a);
	void Insert(unsigned int a);
	void Insert(float a);
	void Insert(float a, float b);
	void Insert(float a, float b, float c);
	void CreatePacket(ENetPeer* peer);
};

PlayerMoving* unpackPlayerMoving(BYTE* data);
BYTE* get_struct(ENetPacket* packet);

void SendPacketRaw112(int a1, void* packetData, size_t packetDataSize, void* a4, ENetPeer* peer, int packetFlag);
void SendPacketRaw1(int a1, void* packetData, size_t packetDataSize, void* a4, ENetPeer* peer, int packetFlag, int delay);

namespace variants {
	void barrel(ENetPeer* peer, int netid, int x, int y, int delay);
	void CrashTheGameClient(ENetPeer* peer);
	void OnRequestWorldSelectMenu(ENetPeer* peer, string output);
	void OnParticleEffect(ENetPeer* peer, float x, float y, int id, bool all = false, string name = "", int delay = 0);
	void OnSetPos(ENetPeer* peer, int netID, float x, float y, int delay = 0);
	void OnSendLog(ENetPeer* enetPeer, string text, int type);
	void OnAddNotification(ENetPeer* peer, string text, string interfaces, string audio, int delay = 0);
	void OnTalkBubble(ENetPeer* peer, int netID, string text, int chatColor = 0, bool overlay = false, int delay = 0, bool overlay2 = false);
	void SetHasAccountSecured(ENetPeer* peer, bool secured = false);
	void OnDialogRequest(ENetPeer* peer, string text, int delay = 0);
	void OnTextOverlay(ENetPeer* peer, string text, int delay = 0);
	void OnSendPingRequest(ENetPeer* peer);
	void OnSendPingReply(ENetPeer* peer, PlayerMoving* datas);
	void OnSpawn(ENetPeer* peer, string name, string country, int netID, int userID, float x, float y, int invis, int mstate, int smstate, bool local, int level = 1, int delay = 0);
	void OnChangePureBeingMode(ENetPeer* peer, int netID, int mode);
	void OnPlayPositioned(ENetPeer* peer, int netID, string file, int delay = 0);
	void OnNameChanged(ENetPeer* peer, int netID, string name, bool all = false);
	void OnConsoleMessage(ENetPeer* peer, string text, bool all = false, int dly = 0);
	void OnPlaySound(ENetPeer* peer, string file, int delay = 0);
	void OnParticleEffect(ENetPeer* peer, int effect, int size, int netid, int x, int y, int delay);
}
