/*********************************************************************
 * File Name : guild_application.h
 * Author    : BestStudio
 * Version   : 1.0.0
 * Date      : 09-11-2026  
 */

#pragma once

#include "../../common/service.h"

#ifdef ENABLE_GUILD_APPLICATION
void GuildApplication_Command(LPCHARACTER ch, const char* argument);
void GuildApplication_OnLogin(LPCHARACTER ch);
#endif
