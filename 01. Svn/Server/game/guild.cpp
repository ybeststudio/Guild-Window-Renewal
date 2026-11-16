// CGuild::CGuild(TGuildCreateParameter & cp) icinde:
// Ara:
	m_data.master_pid = cp.master->GetPlayerID();
	strlcpy(m_data.grade_array[0].grade_name, "Lider", sizeof(m_data.grade_array[0].grade_name));
	m_data.grade_array[0].auth_flag = GUILD_AUTH_ADD_MEMBER | GUILD_AUTH_REMOVE_MEMBER | GUILD_AUTH_NOTICE | GUILD_AUTH_USE_SKILL;

// Altina ekle:
#ifdef ENABLE_GUILD_GRADE_RENEWAL
	m_data.grade_array[0].auth_flag |= GUILD_AUTH_WAR | GUILD_AUTH_SHOP | GUILD_AUTH_QUEST | GUILD_AUTH_UP_SKILL | GUILD_AUTH_DUNGEON;
#endif


// CGuild::CGuild(TGuildCreateParameter & cp) icinde:
// Bul:
		strlcpy(m_data.grade_array[i].grade_name, "Üye", sizeof(m_data.grade_array[i].grade_name));

// Degistir:
		#ifdef ENABLE_GUILD_GRADE_RENEWAL
		snprintf(m_data.grade_array[i].grade_name, sizeof(m_data.grade_array[i].grade_name), "Rank%d", i + 1);
#else
		strlcpy(m_data.grade_array[i].grade_name, "Üye", sizeof(m_data.grade_array[i].grade_name));
#endif

