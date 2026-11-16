// Ara:
	);
}

// Altina ekle:
#ifdef ENABLE_WHISPER_GUILD_INVITE
ACMD(do_anka_guild_invite)
{
	if (!ch || !ch->IsPC())
		return;

	char arg1[CHARACTER_NAME_MAX_LEN + 1];
	one_argument(argument, arg1, sizeof(arg1));
	if (!*arg1)
		return;

	CGuild* pGuild = ch->GetGuild();
	if (!pGuild)
		return;

	LPCHARACTER newmember = CHARACTER_MANAGER::instance().FindPC(arg1);
	if (!newmember || !newmember->IsPC())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("[Guild] The person you were searching for cannot be found."));
		return;
	}

#ifdef ENABLE_MESSENGER_BLOCK
	if (MessengerManager::instance().IsBlocked(ch->GetName(), newmember->GetName()))
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Unblock %s to continue."), newmember->GetName());
		return;
	}
	else if (MessengerManager::instance().IsBlocked(newmember->GetName(), ch->GetName()))
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s has blocked you."), newmember->GetName());
		return;
	}
#endif

	sys_log(0, "ANKA_GUILD_INVITE: %s -> %s (guild %u, target guild %u)", ch->GetName(), newmember->GetName(), pGuild->GetID(), newmember->GetGuild() ? newmember->GetGuild()->GetID() : 0);

	if (quest::CQuestManager::instance().GetPCForce(newmember->GetPlayerID())->IsRunning())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("[Guild] The person standing opposite you cannot receive the invitation."));
		return;
	}

	const bool bCanReceive = !newmember->GetGuild() && newmember->GetEmpire() == ch->GetEmpire() && !newmember->IsBlockMode(BLOCK_GUILD_INVITE);
	pGuild->Invite(ch, newmember);
	if (bCanReceive)
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("[Guild] You have invited %s to the guild."), newmember->GetName());
}
#endif


// Ara:
	std::unique_ptr<SQLMsg> pDelete(DBManager::instance().DirectQuery(
		"DELETE FROM offline_message WHERE to_name = '%s' AND id <= %u", szName, dwLastID));
}

// Altina ekle:
#ifdef ENABLE_GUILD_APPLICATION
#include "guild_application.h"
ACMD(do_guild_app)
{
	GuildApplication_Command(ch, argument);
}
#endif

#ifdef ENABLE_GUILD_DONATION
#include "guild_donation.h"
ACMD(do_guild_donate)
{
	GuildDonation_Donate(ch, argument);
}

ACMD(do_guild_donation_info)
{
	GuildDonation_Info(ch);
}

ACMD(do_guild_whisper)
{
	GuildDonation_Whisper(ch, argument);
}
#endif

#ifdef ENABLE_GUILD_QUEST
#include "guild_quest.h"
ACMD(do_guild_quest)
{
	GuildQuest_Command(ch, argument);
}

ACMD(do_guild_quest_reward)
{
	GuildQuest_Reward(ch);
}
#endif


// Ara:
{
	GlobalRanking_Command(ch, argument);
}

// Altina ekle:
#ifdef ENABLE_GUILD_SKILL_TREE
#include "guild_skill.h"
ACMD(do_guild_skill)
{
	GuildSkill_Command(ch, argument);
}
#endif

#ifdef ENABLE_GUILD_SHOP
#include "guild_shop.h"
ACMD(do_guild_shop)
{
	GuildShop_Command(ch, argument);
}
#endif

