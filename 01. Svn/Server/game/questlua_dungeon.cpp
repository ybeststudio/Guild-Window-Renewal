// Dosyanin uygun bir yerine ekle:
#ifdef ENABLE_GUILD_QUEST
#include "guild_quest.h"
#ifdef ENABLE_GLOBAL_RANKING
#include "global_ranking.h"
#endif
#endif


// Ara:
					GlobalRanking_Add(pChar, GLOBAL_RANK_DUNGEON);

// Altina ekle:
#ifdef ENABLE_GUILD_QUEST
					GuildQuest_AddProgress(pChar, GUILD_QUEST_DUNGEON);
#endif

