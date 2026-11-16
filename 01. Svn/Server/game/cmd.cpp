// Ara:
ACMD(do_anka_global);

// Altina ekle:
#ifdef ENABLE_WHISPER_GUILD_INVITE
ACMD(do_anka_guild_invite);
#endif


// Ara:
ACMD(do_anka_open_shop);

// Altina ekle:
#ifdef ENABLE_GUILD_APPLICATION
ACMD(do_guild_app);
#ifdef ENABLE_GUILD_SHOP
ACMD(do_guild_shop);
#endif
#ifdef ENABLE_GUILD_SKILL_TREE
ACMD(do_guild_skill);
#endif
#ifdef ENABLE_GUILD_QUEST
ACMD(do_guild_quest);
#ifdef ENABLE_COSTUME_SHOP
ACMD(do_costume_shop);
#ifdef ENABLE_WARDROBE_SYSTEM
ACMD(do_wardrobe);
#endif
#endif
#ifdef ENABLE_TELEPORT_MAP_WINDOW
ACMD(do_teleport_map);
#endif
#ifdef ENABLE_DAMAGE_TRACE
ACMD(do_damage_trace);
#endif
#ifdef ENABLE_ENERGY_CRYSTAL
ACMD(do_energy_crystal);
#endif
#ifdef ENABLE_MOKOKO_SYSTEM
ACMD(do_mokoko_info);
ACMD(do_mokoko_rewards);
ACMD(do_mokoko_claim);
ACMD(do_mokoko_reload);
#endif
#ifdef ENABLE_GLOBAL_RANKING
ACMD(do_global_rank);
#endif
ACMD(do_guild_quest_reward);
#endif
#ifdef ENABLE_GUILD_DONATION
ACMD(do_guild_donate);
ACMD(do_guild_donation_info);
ACMD(do_guild_whisper);
#endif
#endif


// Ara:
	{ "anka_global", do_anka_global, 0, POS_DEAD, GM_PLAYER },

// Altina ekle:
#ifdef ENABLE_WHISPER_GUILD_INVITE
	{ "anka_guild_invite", do_anka_guild_invite, 0, POS_DEAD, GM_PLAYER },
#endif


// Ara:
	{ "anka_open_shop", do_anka_open_shop, 0, POS_DEAD, GM_PLAYER },

// Altina ekle:
#ifdef ENABLE_GUILD_APPLICATION
	{ "guild_app", do_guild_app, 0, POS_DEAD, GM_PLAYER },
#ifdef ENABLE_GUILD_SHOP
	{ "guild_shop", do_guild_shop, 0, POS_DEAD, GM_PLAYER },
#endif
#ifdef ENABLE_GUILD_SKILL_TREE
	{ "guild_skill", do_guild_skill, 0, POS_DEAD, GM_PLAYER },
#endif
#ifdef ENABLE_GUILD_QUEST
	{ "guild_quest", do_guild_quest, 0, POS_DEAD, GM_PLAYER },
#ifdef ENABLE_COSTUME_SHOP
	{ "costume_shop", do_costume_shop, 0, POS_DEAD, GM_PLAYER },
#ifdef ENABLE_WARDROBE_SYSTEM
	{ "wardrobe", do_wardrobe, 0, POS_DEAD, GM_PLAYER },
#endif
#endif
#ifdef ENABLE_TELEPORT_MAP_WINDOW
	{ "teleport_map", do_teleport_map, 0, POS_DEAD, GM_PLAYER },
#endif
#ifdef ENABLE_DAMAGE_TRACE
	{ "damage_trace", do_damage_trace, 0, POS_DEAD, GM_PLAYER },
#endif
#ifdef ENABLE_ENERGY_CRYSTAL
	{ "energy_crystal", do_energy_crystal, 0, POS_DEAD, GM_PLAYER },
#endif
#ifdef ENABLE_MOKOKO_SYSTEM
	{ "mokoko_info", do_mokoko_info, 0, POS_DEAD, GM_PLAYER },
	{ "mokoko_rewards", do_mokoko_rewards, 0, POS_DEAD, GM_PLAYER },
	{ "mokoko_claim", do_mokoko_claim, 0, POS_DEAD, GM_PLAYER },
	{ "mokoko_reload", do_mokoko_reload, 0, POS_DEAD, GM_IMPLEMENTOR },
#endif
#ifdef ENABLE_GLOBAL_RANKING
	{ "global_rank", do_global_rank, 0, POS_DEAD, GM_PLAYER },
#endif
	{ "get_guild_quest_reward", do_guild_quest_reward, 0, POS_DEAD, GM_PLAYER },
#endif
#ifdef ENABLE_GUILD_DONATION
	{ "donate_to_guild", do_guild_donate, 0, POS_DEAD, GM_PLAYER },
	{ "guild_donation_info", do_guild_donation_info, 0, POS_DEAD, GM_PLAYER },
	{ "guild_whisper", do_guild_whisper, 0, POS_DEAD, GM_PLAYER },
#endif
#endif

