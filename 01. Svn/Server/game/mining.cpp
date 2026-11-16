// Dosyanin uygun bir yerine ekle:
#ifdef ENABLE_GUILD_QUEST
#include "char.h"
#include "guild_quest.h"
#ifdef ENABLE_GLOBAL_RANKING
#include "global_ranking.h"
#endif
#endif


// Dosyanin uygun bir yerine ekle:
#ifdef ENABLE_GUILD_SKILL_TREE
#include "guild.h"
#include "guild_skill.h"
#endif


// Ara:
		if (number(1, 100) <= iPct)
		{
			OreDrop(ch, load->GetRaceNum());

// Altina ekle:
#ifdef ENABLE_GUILD_SKILL_TREE
			if (ch->GetGuild() && number(1, 100) <= GuildSkill_GetValue(ch->GetGuild(), GUILD_SKILL_TREE_MINE))
				OreDrop(ch, load->GetRaceNum());
#endif
#ifdef ENABLE_GUILD_QUEST
			GuildQuest_AddProgress(ch, GUILD_QUEST_FISH);
#endif

