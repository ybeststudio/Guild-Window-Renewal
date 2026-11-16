// Dosyanin uygun bir yerine ekle:
#ifdef ENABLE_GUILD_QUEST
#include "char.h"
#include "guild_quest.h"
#ifdef ENABLE_GLOBAL_RANKING
#include "global_ranking.h"
#endif
#endif


// void Take(fishing_event_info* info, LPCHARACTER ch) icinde:
// Ara:
				if (item_vnum)
				{
					FishingSuccess(ch);

// Altina ekle:
#ifdef ENABLE_GUILD_QUEST
					GuildQuest_AddProgress(ch, GUILD_QUEST_FISH);
#endif

