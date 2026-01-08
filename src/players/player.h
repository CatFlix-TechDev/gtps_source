#pragma once
#include <cstdint>
#include <map>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
#include "../../include/nlohmann/json.hpp"

using std::map;
using std::pair;
using std::string;
using std::unordered_set;
using std::vector;
struct Friends {
	string name = "";
	bool mute = false, block_trade = false;
	long long last_seen = 0;
};

void to_json(nlohmann::json& j, const Friends& p);
void from_json(const nlohmann::json& j, Friends& p);
struct PlayMods {
	uint16_t id = 0;
	long long time = 0;
	string user = "";
};

void to_json(nlohmann::json& j, const PlayMods& p);
void from_json(const nlohmann::json& j, PlayMods& p);
struct Player {
	bool savedd = false;
	string ip = "", fa_ip = "";//real ip 
	vector<string> last_visited_worlds, worlds_owned, trade_history, crypto_history, ignored, last_rated;
	vector<map<int, int>> trade_items{};
	string name_color = "`0";
	long long int race_flag = 0, xp = 0;
	uint32_t hair_color = 0xFFFFFFFF, eye_drop = 0xFFFFFFFF, eye_lenses = 0xFFFFFFFF, xenonite = 0, cape_t = 2402849791, cape_c = 2402849791, cape_t2 = 723421695, cape_c2 = 1059267327, wings_t = 3356909055, wings_c = 4282965247, wings_t2 = 723421695, wings_c2 = 1059267327;
	int id = 0, netID = 0, state = 0, trading_with = -1;
	bool trade_accept = false, accept_the_offer = false;
	int x = -1, y = -1;
	int gems = 0, voucher = 0;
	bool growid = false;
	bool wiped_invalid_worlds = false;
	bool usedmegaphone = 0, ownership_role = false, buy_role = false, ghost_role = false, nick_role = false, give_role = false, give_editor = false, csn_role = false;
	string custom_name_color = "";
	map<int, int> access_offers{};
	bool hit1 = false;
	int skin = 0x8295C3FF;
	uint16_t punched = 0;
	int enter_game = 0;
	int lock = 0;
	int flagmay = 256;
	vector<pair<string, int>> crypto;
	int lockeitem = 0;
	string last_online = "";
	bool ghost = false, invis = false;
	uint8_t n = 0; //newbie passed save
	string note = "";
	uint8_t supp = 0, hs = 0, dev = 0, m_h = 0;
	string real_growtopia_name = "";

	string CapeStyleColor_1 = "147,56,143", CapeCollarColor_1 = "147,56,143", CapeStyleColor_2 = "137,30,43", CapeCollarColor_2 = "34,35,36", skin_c = "0,0,0";
	string _CapeStyleColor_1 = "93,22,200", _CapeCollarColor_1 = "220,72,255", _CapeStyleColor_2 = "137,30,43", _CapeCollarColor_2 = "34,35,63";
	int autofarm_slot = 1;
	//	, _CapeStyleColor_1 = "255,255,255", _CapeCollarColor_1 = "255,255,255", _CapeStyleColor_2 = "255,255,255", _CapeCollarColor_2 = "255,255,255";
	int flags = 19451, TimeDilation = 30, _flags = 104912, _TimeDilation = 30;
	//	, _flags = 0, _TimeDilation = 30;
	float strong_punch = 200, high_jump = 1000, player_speed = 250, water_speed = 125;
	int build_range = 128, punch_range = 128;
	int state_player = 0;
	int punch_effect = 0;
	int type_player = 0;
	int guild_role = -1;
	int flag_may_form = 0;
	int punch_modifier = 0;
	bool punch_decrease = false;
	string gender = "", temp_password = "";
	uint8_t mod = 0, vip = 0, moderator = 0, vip_p = 0;
	int rr_ = rand() % 6 + 1;
	int growpass_points = 0;
	vector<string> growpass_prizes, growpass_quests;
	int rr_used = 0;
	int wls = 0;
	uint8_t csn = -1;
	bool mini_you = false;
	long long int b_t = 0, b_s = 0; // ban seconds
	bool no_body = false, no_hands = false;
	int last_infected = 0;
	string b_r = "", b_b = ""; // ban reason ir banned by
	string m_b = "";
	uint16_t hair = 0, shirt = 0, pants = 0, feet = 0, face = 0, hand = 0, back = 0, mask = 0, necklace = 0, ances = 0, hiden_clothing = 0; /*clothes*/
	string temporary_tankIDName = "";
	string tankIDName = "", tankIDPass = "", requestedName = "", world = "", email = "", country = "", home_world = "", last_wrenched = "", last_msg_wrenched = "", info_new_ = "";
	string d_name = "";
	string temporary_vault = "";

	string Carnival_GameType = "None";
	vector<pair<int, int>>Carnival_Mirror_Maze;
	long long Carnival_GameTime = 0;
	bool DeathRaceBeaten = false;
	string DeathRaceWinner = "";
	bool BrutalBeaten = false;
	bool SpikyBeaten = false;
	bool NotSame = false;
	int Shooting_Punch = 0;
	int Shooting_Point = 0;
	int BrutalX = 0;
	int BrutalY = 0;
	int SpikyX = 0;
	int SpikyY = 0;
	int XCard_1 = 0;
	int YCard_1 = 0;
	int XCard_2 = 0;
	int YCard_2 = 0;
	int CardOpened = 0;
	int Card_1 = 0;
	int Card_2 = 0;
	int TotalCardSucces = 0;
	int Carnival_Games_Won = 0;
	int FunTimeRewards = 0;

	//vector<Items> inv{};
	vector<Friends> friends;
	vector<int> last_friends_selection{};
	vector<string> pending_friends{};
	vector<string> bans{};
	string last_edit = "";

	int summer_surprise = 0, summer_total = 0;
	vector<int> summer_milestone;

	int pinata_day = 0;
	bool pinata_prize = false;
	bool pinata_claimed = false;

	bool pc_player = false;

	int pure_shadow = 0;
	int wrong2fa = 0;
	bool bypass = false, update_player = false, bypass2 = false;
	int new_packets = 0;
	//	int captcha_type = 0;
	bool hider = false, backwards = false;
	bool seeker = false;
	string world_owner = "";
	int random_geiger_time = 0;

	uint8_t i_11818_1 = 0, i_11818_2 = 0;
	int8_t random_fossil = rand() % 3 + 4;
	int page_number = 0;
	string page_item = "";

	// Crown of Season
	int Aura_Season = 2, Trail_Season = 2;
	// End
	// Banner Bandolier
	int Banner_Item = 0, CBanner_Item = 0, Banner_Flag = 0, CBanner_Flag = 0;
	// Infinity Crown
	bool Crown_Time_Change = true;
	int Crown_Cycle_Time = 15;
	// Crown 1
	int Base_R_0 = 255, Base_G_0 = 200, Base_B_0 = 37;
	int Gem_R_0 = 255, Gem_G_0 = 0, Gem_B_0 = 64;
	int Crystal_R_0 = 26, Crystal_G_0 = 45, Crystal_B_0 = 140;
	bool Crown_Floating_Effect_0 = false, Crown_Laser_Beam_0 = true, Crown_Crystals_0 = true, Crown_Rays_0 = true;

	long long World_Timed = 0;
	bool WorldTimed = false;
	// Crown 2
	int Base_R_1 = 255, Base_G_1 = 255, Base_B_1 = 255;
	int Gem_R_1 = 255, Gem_G_1 = 0, Gem_B_1 = 255;
	int Crystal_R_1 = 0, Crystal_G_1 = 45, Crystal_B_1 = 140;
	bool Crown_Floating_Effect_1 = true, Crown_Laser_Beam_1 = true, Crown_Crystals_1 = true, Crown_Rays_1 = true;
	// Total
	int Crown_Value = 1768716607;
	long long int Crown_Value_0_0 = 4294967295, Crown_Value_0_1 = 4278255615, Crown_Value_0_2 = 4190961919;
	long long int Crown_Value_1_0 = 633929727, Crown_Value_1_1 = 1073807359, Crown_Value_1_2 = 2351766271;
	// End


	/*
	int got_4292 = 0;
	int got_4286 = 0;
	int got_4288 = 0;
	int got_10500 = 0;
	int winterfest_task_day = 0;
	int winterfest_wishes = 0;
	int winterfest_quest_1 = 0;
	int winterfest_quest_2 = 0;
	int winterfest_quest_3 = 0;

	int reset_winterfest_quest_1 = 0;
	int reset_winterfest_quest_2 = 0;
	int reset_winterfest_quest_3 = 0;
	int reset_winterfest_quest_4 = 0;
	int reset_winterfest_quest_5 = 0;
	int reset_winterfest_quest_6 = 0;
	int reset_winterfest_quest_7 = 0;
	int reset_winterfest_quest_8 = 0;

	int winterfest_stuff4toys = 0;*/

	int transmute_item1 = 0, transmute_item2 = 0, remove_transmute = 0;
	string transmuted = "";
	bool temp_transmute = false;

	// Cquest
	bool C_QuestActive = false, CQ = false;
	int C_QuestStep = 1, C_QuestProgress = 0, C_ProgressNeeded = 0, C_QuestKind = 0, C_DeliverID = 0;
	//
	/*
	int halloween_task_1 = 0;
	int halloween_task_2 = 0;
	int halloween_task_3 = 0;
	int halloween_task_4 = 0;

	int halloween_ptask_1 = 0;
	int halloween_ptask_2 = 0;
	int halloween_ptask_3 = 0;
	int halloween_ptask_4 = 0;
	int halloween_ptask_5 = 0;*/

	uint16_t opc = 0;
	int cc = 0;
	bool bb = false;
	uint8_t rb = 0;
	//int halloween_dark_king = 0;
	uint8_t gp = 0, glo = 0;
	uint8_t w_w = 0;
	int offergems = 0;
	bool show_location_ = true, show_friend_notifications_ = true;
	int confirm_reset = 0;
	int carnivalgameswon = 0;
	int level = 1;
	long long playtime = 0;
	vector<int> playtime_items;
	long long int account_created = 0, seconds = 0;
	string rid = "", mac = "", meta = "", vid = "";
	map<string, int> achievements{};
	string lastmsg = "", lastmsgworld = "";
	int gtwl = 0;
	uint16_t c_x = 0, c_y = 0;
	uint8_t lavaeffect = 0;
	//cooldowns
	long long int i240 = 0, i756 = 0, i758 = 0;
	bool tmod = 0;
	//billboard
	int b_i = 0, b_w = 0, b_p = 0;

	string b_bill = "0,0";
	//
	int same_input = 0, not_same = 0, pickup_limits = 0, hack = 0;
	bool world_enter = false;
	string last_input_text = "";
	long long int pickup_time =0 , teleport_time = 0, last_inf = 0, last_spam_detection = 0, last_world_enter = 0, last_personal_update = 0, last_fish_catch = 0, respawn_time = 0, hand_torch = 0, punch_time = 0, lava_time = 0, world_time = 0, geiger_time = 0, valentine_time = 0, remind_time = 0, warp_time = 0, name_time = 0, anticheat_cooldown = 0, anticheat_cooldown2 = 0;
	//, ping_reply = 0
	int lastwrenchx = 0, lastwrenchy = 0, lastwrenchb = 0, lastchoosenitem = 0, lastchoosennr = 0;
	int spray_x = 0, spray_y = 0;
	int pps = 0;
	long long lpps = 0;
	//int pickup_limits = 0;
	long long int punch_count = 0;
	//bool sleep_afk = false;

	string personal_event = "", guild_event = "";
	int carnival_credit = 0;
	/*
	int pinged = 0;
	bool ping_replied = false;*/

	//int afk_x = -1, afk_y = -1;
	int total_credit_card = 0, credit_card = rand() % 10000000000000;

	// Magic Magnet
	int Magnet_Item = 0;
	// Ancestral
	int AncesID = 0, Upgradeto = 0, HowmuchSoulStone = 0, IDCeles = 0, JumlahCeles = 0, IDCrystalized = 0, JumlahCrystalized = 0;
	int DailyRiddles = 0;

	uint8_t  grow_air_ballon = 0;
	bool subscriber = false;
	int mailbox = 0;
	bool wiping_time = false;
	uint8_t geiger_ = 0;
	uint8_t all_in = 0;
	int fishing_used = 0, f_x = 0, f_y = 0, move_warning = 0, f_xy = 0, punch_warning = 0, fish_seconds = 0;
	vector<int> glo_p;
	int geiger_x = -1, geiger_y = -1;
	int t_xp = 0, bb_xp = 0, g_xp = 0, p_xp = 0, ff_xp = 0, s_xp = 0;
	uint8_t t_lvl = 0, bb_lvl = 0, g_lvl = 0, p_lvl = 0, ff_lvl = 0, s_lvl = 0;
	vector<uint8_t> t_p, bb_p, p_p, g_p, ff_p, surg_p;
	int booty_broken = 0;
	bool ghc = false;
	uint8_t dd = 0;
	vector<PlayMods> playmods{};

	unordered_set<int> listFindItems;
	

	bool new_pass = false;

	uint16_t b_l = 1;
	vector<pair<uint16_t, uint8_t>> bp;
	vector<pair<int, int>> inv, transmute;
	bool auth_ = true;
	int choosenitem = 0;
	uint8_t radio = 0;
	bool radio2 = false;
	bool temp_radio = false;
	int b_ra = 0, b_lvl = 1;
	int magnetron_id = 0;
	int magnetron_x = 0;
	int magnetron_y = 0;
	string growmoji = "(wl)|ā|0&(oops)|ą|0&(sleep)|Ċ|0&(punch)|ċ|0&(bheart)|Ĕ|0&(grow)|Ė|0&(gems)|ė|0&(gtoken)|ę|0&(cry)|ĝ|0&(vend)|Ğ|0&(bunny)|ě|0&(cactus)|ğ|0&(pine)|Ĥ|0&(peace)|ģ|0&(terror)|ġ|0&(troll)|Ġ|0&(evil)|Ģ|0&(fireworks)|Ħ|0&(football)|ĥ|0&(alien)|ħ|0&(party)|Ĩ|0&(pizza)|ĩ|0&(clap)|Ī|0&(song)|ī|0&(ghost)|Ĭ|0&(nuke)|ĭ|0&(halo)|Į|0&(turkey)|į|0&(gift)|İ|0&(cake)|ı|0&(heartarrow)|Ĳ|0&(lucky)|ĳ|0&(shamrock)|Ĵ|0&(grin)|ĵ|0&(ill)|Ķ|0&(eyes)|ķ|0&(weary)|ĸ|0&(moyai)|ļ|0&(plead)|Ľ|0&";
	long long int save_time = 0, basher_time = 0;
	vector<vector<long long>> completed_blarneys{
		{1, 0},
		{2, 0},
		{3, 0},
		{4, 0},
		{5, 0},
		{6, 0},
		{7, 0},
		{8, 0},
		{9, 0},
	};
	bool block_trade = false;
	int p_x = 0;
	int p_y = 0;
	int guild_id = 0;
	int pending_guild = 0;
	bool is_legend = false;
	bool ios_player = false;
	uint16_t pps23 = 0, all_packets = 0;
	int temp_x = 0, temp_y = 0;
	long long lpps2 = 0, all_packets_time = 0;
	uint8_t superdev = 0, roleIcon = 6, roleSkin = 6;

	// adminlevel
	int adminlevel = 1;
	bool valentine = false;
	long long int ban_seconds = 0;
	string ban_reason = "";

	int autofarm_x = -1, autofarm_y = -1;

	uint8_t fires = 0;

	uint32_t total_pineapple = 0;
	uint16_t stage_pineapple = 0;

	uint8_t garuda = 0;

	uint16_t eq_aura = 0;
	int balloon_faction = rand() % 3 + 1, balloon_hit = 0, hit_by = 0, balloon_donated = 0, balloon_score = 0;

	int fruit_1 = 0, fruit_2 = 0, fruit_3 = 0;
	int fruit_1_c = 0, fruit_2_c = 0, fruit_3_c = 0;

	string chat_prefix = "";
	bool disable_cheater = 0;
	//int planted = 0;
	int egg_carton = 0;
	int magic_egg = 0;
	int egg_chance = 0;
	int p_status = 0;

	int participated = 0;
	int lwiz_quest = 0, lwiz_step = 1, lwiz_notification = 0;
	vector<vector<int>> legendary_quest, set = {{}};
	string player_device = "";
	int guild_fg = 0;
	int guild_bg = 0;
	int set_guild_bg = 0, set_guild_fg = 0;
	int cheater_ = 0, cheater_settings = 0;
	int support101_ = 0;
	bool received_balloon_warz = false, black_color = false;
	string wolf_world = "";

	bool logger = 0;
	int last_used_block = 0;
	int search_page = 20;
	//surgery
	vector<uint16_t> available_surg_items;
	bool sounded = false;
	bool labworked = false;
	bool fixed = false;
	bool fixable = false;
	bool flu = false;
	int pulse = 40, site = 0, sleep = 0, dirt = 0, broken = 0, shattered = 0, incisions = 0, bleeding = 0, incneeded = 0, heart = 0;
	double temp = 98.6;
	double fever = 0.0;
	string pretext = "";
	string fixtext = "";
	string postext = "";
	string scantext = "";
	string tooltext = "The patient is prepped for surgery.";
	string endtext = "";

	bool update = true;
	bool s = true;
	uint8_t surgery_skill = 0, spongUsed = 0, scalpUsed = 0, stitcUsed = 0, antibUsed = 0, antisUsed = 0, ultraUsed = 0, labkiUsed = 0, anestUsed = 0, defibUsed = 0, splinUsed = 0, pinsUsed = 0, clampUsed = 0, transUsed = 0;
	uint16_t surgery_done = 0, su_8552_1 = 0, su_8552_2 = 0, su_8552_3 = 0;
	bool antibs = false, surgery_started = false;
	string surgery_world = "";

	string surged_person = "";
	string surged_display = "";
	string surgery_name = "";
	bool hospital_bed = false;
	int fa2 = 0;
	//surgery done
	// 
	//int egg = 0;

	uint8_t surgery_type = -1, started_type = 0, mercy = 0, drtitle = 0, drlegend = 0, drt = 0, lvl125 = 0, donor = 0, master = 0;
	bool spotlight = false;
	uint8_t minokawa_wings = 0, panda_spirit = 0, mask_dragon = 0, growformer = 0;
	int won_seeker = 0, won_hider = 0;
	bool emoji_gg = false;
	int musical_volume = 100;
	string musical_note = "C-F-G#G-F-B#A#G-F-G#G-D#G-C-";
	vector<string> growtoken_worlds;
	uint8_t grow4good_seed2 = 0, grow4good_combine = 0, grow4good_crystal = 0, grow4good_honors = 0;
	uint16_t grow4good_seed = 0;

	bool new_version = false;
	bool grow4good_email = 0;
	bool wls_participated = false;
	long long int  grow_reset_day = 0, grow_reset_week = 0, grow_reset_month = 0;

	string last_home_world = "";
	string spectate_person = "";
	int grow4good_gems = 0;
	int grow4good_surgery = 0;
	int grow4good_fish = 0;
	int grow4good_points = 0;
	uint8_t grow4good_30mins = 0;
	int grow4good_break = 0;
	int grow4good_place = 0;
	int grow4good_trade = 0;
	int grow4good_sb = 0;
	bool grow4good_enter = false;
	int grow4good_provider = 0;
	int grow4good_provider2 = rand() % 450 + 1;

	int grow4good_geiger = 0;
	int grow4good_geiger2 = 0;
	bool punch_aura = false;
	int punch_aura_id = 0;
	//int black_box_consumed = 0;

	//int temp_x = 0, temp_y = 0;

	bool halloween_prize_receive = false;
	string game_version = "";
	bool updated_clothes = false;

	/*

		int pinata_day = 0;
		bool pinata_prize = false;
		bool pinata_claimed = false;

		int carnival_punch = 0;
		int carnival_credit = 0;*/

	bool adventure_begins = false, display_age = false, display_home = false, whitelist_role = false;
	vector<int>Fav_Items;
	uint8_t sprite = 0, wild = 6, golem = 6;
	
	// Game Generator
	bool Respawning = false;
	bool ONGame = false, Carried_A_Flag = false;
	int Game_Goal_Egg = 0, Game_Player_Hits = 0, Game_Live = 0, Game_Flag = 0;
	string Game_Team = "";
	int Flag_X = 0, Flag_Y = 0;

	string login_pass = "";
	int pearl = 0, rubble = 0;
	bool received_recycle_prize = false;
	bool Staff = false;
	int last_state = 0;
	int automatic_bot = 0;
	bool collect_allowed = false;
	int collect_total = 0;
	bool onetimecollect = false;

	bool load_item2 = false;
};
#define pInfo(peer) ((Player*)(peer->data))
struct PlayerMoving {
	int32_t netID, effect_flags_check;
	int packetType, characterState, plantingTree, punchX, punchY, secondnetID;
	float x, y, XSpeed, YSpeed;
	int packet_3, packet_int_40 = 0;
};

BYTE* packBlockType(int packetType, int plantingTree, int x, int y, int state = 0);

class kranken_pattern {
public:
	enum : uint8_t {
		NONE,
		PT1,
		PT2,
		PT3,
		PT4,
		PT5,
		PT6,
		PT7,
		PT8,
		PT9,
		PT10,
		PT11,
		PT12,
	};
	static std::pair<uint32_t, uint32_t> get_pattern(const uint8_t& pattern);
};

BYTE* PackBlockUpdate(int packetType, int characterState, float x, float y, float XSpeed, float YSpeed, float rotation, int netID, int plantingTree, int punchX, int punchY, int packet_1, int packet_2, int packet_3);
BYTE* packPlayerMoving(PlayerMoving* dataStruct, int size_ = 56, int some_extra = 0);
BYTE* packFishMoving(PlayerMoving* dataStruct, int size_ = 56);
void send_raw(ENetPeer* peer, int a1, void* packetData, int packetDataSize, int packetFlag, int delay = 0);
void send_raw2(ENetPeer* peer, int a1, void* packetData, int packetDataSize, int packetFlag, int delay = 0);
void send_inventory(ENetPeer* peer);
void send_packet(ENetPeer* peer, const void* data, uintmax_t data_size, uint32_t flags);
void send_packet(ENetPeer* peer, uint32_t type, const void* data, uintmax_t data_size, uint32_t flags);
