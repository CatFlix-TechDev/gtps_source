#include <cstring>

#include "../../enet/include/enet.h"
#include "player.h"

void to_json(nlohmann::json& j, const Friends& p) {
	j = nlohmann::json{
		{"name", p.name},
		{"mute", p.mute},
		{"block_trade", p.block_trade},
		{"last_seen", p.last_seen}
	};
}

void from_json(const nlohmann::json& j, Friends& p) {
	j["name"].get_to(p.name);
	j["mute"].get_to(p.mute);
	j["block_trade"].get_to(p.block_trade);
	j["last_seen"].get_to(p.last_seen);
}

void to_json(nlohmann::json& j, const PlayMods& p) {
	j = nlohmann::json{
		{"id", p.id},
		{"time", p.time},
		{"user", p.user}
	};
}

void from_json(const nlohmann::json& j, PlayMods& p) {
	j["id"].get_to(p.id);
	j["time"].get_to(p.time);
	j["user"].get_to(p.user);
}

BYTE* packBlockType(int packetType, int plantingTree, int x, int y, int state) {
	BYTE* data = new BYTE[56];
	memset(data, 0, 56);
	memcpy(data + 0, &packetType, 4);
	memcpy(data + 12, &state, 4);
	memcpy(data + 20, &plantingTree, 4);
	memcpy(data + 44, &x, 4);
	memcpy(data + 48, &y, 4);
	return data;
}

std::pair<uint32_t, uint32_t> kranken_pattern::get_pattern(const uint8_t& pattern) {
	switch (pattern) {
	case NONE:
		return { static_cast<uint32_t>(0), static_cast<uint32_t>(10962) };
	case PT1:
		return { static_cast<uint32_t>(1), static_cast<uint32_t>(10964) };
	case PT2:
		return { static_cast<uint32_t>(2), static_cast<uint32_t>(10966) };
	case PT3:
		return { static_cast<uint32_t>(3), static_cast<uint32_t>(10968) };
	case PT4:
		return { static_cast<uint32_t>(4), static_cast<uint32_t>(10970) };
	case PT5:
		return { static_cast<uint32_t>(5), static_cast<uint32_t>(10972) };
	case PT6:
		return { static_cast<uint32_t>(6), static_cast<uint32_t>(10974) };
	case PT7:
		return { static_cast<uint32_t>(7), static_cast<uint32_t>(10976) };
	case PT8:
		return { static_cast<uint32_t>(8), static_cast<uint32_t>(10978) };
	case PT9:
		return { static_cast<uint32_t>(9), static_cast<uint32_t>(10980) };
	case PT10:
		return { static_cast<uint32_t>(10), static_cast<uint32_t>(10982) };
	case PT11:
		return { static_cast<uint32_t>(11), static_cast<uint32_t>(10984) };
	case PT12:
		return { static_cast<uint32_t>(12), static_cast<uint32_t>(10986) };
	default:
		return { static_cast<uint32_t>(0), static_cast<uint32_t>(10962) };
	}
}

BYTE* PackBlockUpdate(int packetType, int characterState, float x, float y, float XSpeed, float YSpeed, float rotation, int netID, int plantingTree, int punchX, int punchY, int packet_1, int packet_2, int packet_3) {
	BYTE* data = new BYTE[56];
	memset(data, 0, 56);
	memcpy(data + 0, &packetType, 4);
	if (packet_1 != 0) memcpy(data + 1, &packet_1, 4);
	if (packet_2 != 0) memcpy(data + 2, &packet_2, 4);
	if (packet_3 != 0) memcpy(data + 3, &packet_3, 4);
	if (netID != 0) memcpy(data + 4, &netID, 4);
	if (characterState != 0) memcpy(data + 12, &characterState, 4);
	if (plantingTree != 0) memcpy(data + 20, &plantingTree, 4);
	memcpy(data + 24, &x, 4);
	memcpy(data + 28, &y, 4);
	if (XSpeed != 0) memcpy(data + 32, &XSpeed, 4);
	if (YSpeed != 0) memcpy(data + 36, &YSpeed, 4);
	memcpy(data + 40, &rotation, 4);
	if (punchX != 0) memcpy(data + 44, &punchX, 4);
	if (punchY != 0) memcpy(data + 48, &punchY, 4);
	return data;
}

BYTE* packPlayerMoving(PlayerMoving* dataStruct, int size_, int some_extra) {
	BYTE* data = new BYTE[size_];
	memset(data, 0, size_);
	memcpy(data + 0, &dataStruct->packetType, 4);
	memcpy(data + 3, &some_extra, 4);
	memcpy(data + 4, &dataStruct->netID, 4);
	memcpy(data + 12, &dataStruct->characterState, 4);
	memcpy(data + 20, &dataStruct->plantingTree, 4);
	memcpy(data + 24, &dataStruct->x, 4);
	memcpy(data + 28, &dataStruct->y, 4);
	memcpy(data + 32, &dataStruct->XSpeed, 4);
	memcpy(data + 36, &dataStruct->YSpeed, 4);
	memcpy(data + 40, &dataStruct->packet_int_40, 4);
	memcpy(data + 44, &dataStruct->punchX, 4);
	memcpy(data + 48, &dataStruct->punchY, 4);
	return data;
}

BYTE* packFishMoving(PlayerMoving* dataStruct, int size_) {
	BYTE* data = new BYTE[size_];
	memset(data, 0, size_);
	*(__int8*)(data + 0) = 31;
	*(__int8*)(data + 3) = dataStruct->packet_3;
	*(__int16*)(data + 4) = dataStruct->netID;
	*(__int16*)(data + 44) = dataStruct->x;
	*(__int16*)(data + 48) = dataStruct->y;
	return data;
}

void send_raw(ENetPeer* peer, int a1, void* packetData, int packetDataSize, int packetFlag, int delay) {
	ENetPacket* p;
	if (peer) {
		if (a1 == 4 && *((BYTE*)packetData + 12) & 8) {
			p = enet_packet_create(0, packetDataSize + *((DWORD*)packetData + 13) + 5, packetFlag);
			int four = 4;
			memcpy(p->data, &four, 4);
			memcpy((char*)p->data + 4, packetData, packetDataSize);
			memcpy((char*)p->data + packetDataSize + 4, 0, *((DWORD*)packetData + 13));
			if (delay != 0) {
				int deathFlag = 0x19;
				memcpy(p->data + 24, &delay, 4);
				memcpy(p->data + 56, &deathFlag, 4);
			}
		}
		else {
			p = enet_packet_create(0, packetDataSize + 5, packetFlag);
			memcpy(p->data, &a1, 4);
			memcpy((char*)p->data + 4, packetData, packetDataSize);
			if (delay != 0) {
				int deathFlag = 0x19;
				memcpy(p->data + 24, &delay, 4);
				memcpy(p->data + 56, &deathFlag, 4);
			}
		}
		enet_peer_send(peer, 0, p);
	}
}

void send_raw2(ENetPeer* peer, int a1, void* packetData, int packetDataSize, int packetFlag, int delay) {
	ENetPacket* p;
	if (peer) {
		if (a1 == 4 && *((BYTE*)packetData + 12) & 8) {
			p = enet_packet_create(0, packetDataSize + *((DWORD*)packetData + 13) + 5, packetFlag);
			int four = 4;
			memcpy(p->data, &four, 4);
			memcpy(p->data + 24, &delay, 4);
			memcpy((char*)p->data + 4, packetData, packetDataSize);
			memcpy((char*)p->data + packetDataSize + 4, 0, *((DWORD*)packetData + 13));
		}
		else {
			p = enet_packet_create(0, packetDataSize + 5, packetFlag);
			memcpy(p->data, &a1, 4);
			memcpy((char*)p->data + 4, packetData, packetDataSize);
		}
		enet_peer_send(peer, 0, p);
	}
}

void send_inventory(ENetPeer* peer) {
	size_t inv_size = (pInfo(peer)->inv.size() > 476 ? 476 : pInfo(peer)->inv.size());
	int packetLen = 66 + (inv_size * 4) + 4, MessageType = 0x4, PacketType = 0x9, NetID = -1, CharState = 0x8, state56 = 6 + (inv_size * 4) + 4, bruh = 1;
	BYTE* d_ = new BYTE[packetLen];
	memset(d_, 0, packetLen);
	memcpy(d_, &MessageType, 1);
	memcpy(d_ + 4, &PacketType, 4);
	memcpy(d_ + 8, &NetID, 4);
	memcpy(d_ + 16, &CharState, 4);
	memcpy(d_ + 56, &state56, 4);
	memcpy(d_ + 60, &bruh, 4);
	memcpy(d_ + 61, &inv_size, 4);
	memcpy(d_ + 65, &inv_size, 4);
	vector<pair<uint16_t, uint8_t>> send_later;
	int offset = 67;
	for (int i_ = 0; i_ < inv_size; ++i_) {
		if (pInfo(peer)->inv[i_].first == 9850 || pInfo(peer)->inv[i_].first == 9812 || pInfo(peer)->inv[i_].first == 7782 || pInfo(peer)->inv[i_].first == 9902 || pInfo(peer)->inv[i_].first == 9636 || pInfo(peer)->inv[i_].first == 9726 || pInfo(peer)->inv[i_].first == 9500 || pInfo(peer)->inv[i_].first == 9584 || pInfo(peer)->inv[i_].first == 9586 || pInfo(peer)->inv[i_].first == 9588 || pInfo(peer)->inv[i_].first == 9590 || pInfo(peer)->inv[i_].first == 9550 || pInfo(peer)->inv[i_].first == 9582 || pInfo(peer)->inv[i_].first == 9580 || pInfo(peer)->inv[i_].first == 9578 || pInfo(peer)->inv[i_].first == 9572 || pInfo(peer)->inv[i_].first == 9570 || pInfo(peer)->inv[i_].first == 9568 || pInfo(peer)->inv[i_].first == 9566 || pInfo(peer)->inv[i_].first == 9564 || pInfo(peer)->inv[i_].first == 9562 || pInfo(peer)->inv[i_].first == 9560 || pInfo(peer)->inv[i_].first == 9558 || pInfo(peer)->inv[i_].first == 9490 || pInfo(peer)->inv[i_].first == 9492 || pInfo(peer)->inv[i_].first == 9490 || pInfo(peer)->inv[i_].first == 9492 || pInfo(peer)->inv[i_].first == 9516 || pInfo(peer)->inv[i_].first == 9540) {
			send_later.push_back(std::make_pair(pInfo(peer)->inv[i_].first, pInfo(peer)->inv[i_].second));
		}
		else {
			*(__int16*)(d_ + offset) = pInfo(peer)->inv[i_].first;
			offset += 2;
			*(__int8*)(d_ + offset) = pInfo(peer)->inv[i_].second;
			offset += 2;
		}
	}
	ENetPacket* const p_ = enet_packet_create(d_, packetLen, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, p_);
	delete[] d_;
	if (send_later.size() > 0) {
		PlayerMoving data_{};
		data_.packetType = 13;
		for (int i = 0; i < send_later.size(); i++) {
			data_.plantingTree = send_later[i].first;
			BYTE* raw = packPlayerMoving(&data_);
			raw[3] = send_later[i].second;
			send_raw(peer, 4, raw, 56, ENET_PACKET_FLAG_RELIABLE);
			delete[] raw;
		}
	}
}

void send_packet(ENetPeer* peer, const void* data, uintmax_t data_size, uint32_t flags) {
	ENetPacket* packet = enet_packet_create(data, data_size, flags);
	if (!packet)
		return;

	if (enet_peer_send(peer, 0, packet) != 0)
		enet_packet_destroy(packet);
}

void send_packet(ENetPeer* peer, uint32_t type, const void* data, uintmax_t data_size, uint32_t flags) {
	ENetPacket* packet = enet_packet_create(nullptr, 5 + data_size, flags);
	if (!packet)
		return;

	memcpy(packet->data, &type, 4);
	packet->data[data_size + 4] = 0;

	if (data)
		memcpy(packet->data + 4, data, data_size);

	if (enet_peer_send(peer, 0, packet) != 0)
		enet_packet_destroy(packet);
}
