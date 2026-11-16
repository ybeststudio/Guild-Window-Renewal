// Dosyanin uygun bir yerine ekle:
#ifdef ENABLE_GUILD_QUEST
#include "guild_quest.h"
#ifdef ENABLE_DUNGEON_INFO_WINDOW
#include "dungeon_window.h"
#endif
#ifdef ENABLE_GLOBAL_RANKING
#include "global_ranking.h"
#include "damage_trace.h"
#endif
#endif


// void CHARACTER::Dead(LPCHARACTER pkKiller, bool bImmediateDead) icinde:
// Ara:
			}
		}
	}

// Altina ekle:
#ifdef ENABLE_GUILD_QUEST
	if (!IsPC() && pkKiller && pkKiller->IsPC())
	{
		if (IsStone())
			GuildQuest_AddProgress(pkKiller, GUILD_QUEST_METIN);
		else if (IsMonster() && GetMobRank() >= MOB_RANK_BOSS)
			GuildQuest_AddProgress(pkKiller, GUILD_QUEST_BOSS);
	}
#endif

