// Dosyanin uygun bir yerine ekle:
#ifdef ENABLE_GUILD_SKILL_TREE
#include "guild.h"
#include "guild_skill.h"
#ifdef ENABLE_MOUNT_RENEWAL
#include "mount_renewal.h"
#endif
#endif


// bool CHARACTER::DoRefineWithScroll(LPITEM item, ...) icinde:
// Ara:
			bDestroyWhenFail = bRuleKeep;
		}
	}

// Altina ekle:
#ifdef ENABLE_GUILD_SKILL_TREE
	if (GetGuild())
		success_prob += GuildSkill_GetValue(GetGuild(), GUILD_SKILL_TREE_REFINE);
#endif

