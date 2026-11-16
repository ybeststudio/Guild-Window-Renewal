// Ara:
extern void SendOfflineWhisperMessages(LPCHARACTER ch);

// Altina ekle:
#ifdef ENABLE_GUILD_QUEST
#include "guild_quest.h"
#ifdef ENABLE_DUNGEON_INFO_WINDOW
#include "dungeon_window.h"
#endif
#endif
#ifdef ENABLE_GUILD_APPLICATION
#include "guild_application.h"
#include "messenger_details.h"
#ifdef ENABLE_MOUNT_RENEWAL
#include "mount_renewal.h"
#endif
#endif


// void CInputLogin::Entergame(LPDESC d, const char * data) icinde:
// Ara:
	SendOfflineWhisperMessages(ch);

// Altina ekle:
#ifdef ENABLE_GUILD_APPLICATION
	GuildApplication_OnLogin(ch);
#endif
#ifdef ENABLE_GUILD_QUEST
	GuildQuest_OnLogin(ch);
#endif

