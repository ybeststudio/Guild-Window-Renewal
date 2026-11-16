// Bul:
typedef BYTE TGuildAuthFlag;

// Degistir:
#ifdef ENABLE_GUILD_GRADE_RENEWAL
typedef WORD TGuildAuthFlag;
#else
typedef BYTE TGuildAuthFlag;
#endif


// Ara:
	GUILD_AUTH_REMOVE_MEMBER	= (1 << 1),
	GUILD_AUTH_NOTICE		= (1 << 2),
	GUILD_AUTH_USE_SKILL	= (1 << 3),

// Altina ekle:
#ifdef ENABLE_GUILD_GRADE_RENEWAL
	GUILD_AUTH_WAR			= (1 << 4),
	GUILD_AUTH_SHOP			= (1 << 5),
	GUILD_AUTH_QUEST		= (1 << 6),
	GUILD_AUTH_UP_SKILL		= (1 << 7),
	GUILD_AUTH_DUNGEON		= (1 << 8),
#endif


// Bul:
		int		GetMaxGeneralCount() const	{ return 1 /*+ GetSkillLevel(GUILD_SKILL_DEUNGYONG)/3*/;}

// Degistir:
#ifdef ENABLE_GUILD_GRADE_RENEWAL
		int		GetMaxGeneralCount() const	{ return 3; }
#else
		int		GetMaxGeneralCount() const	{ return 1 /*+ GetSkillLevel(GUILD_SKILL_DEUNGYONG)/3*/;}
#endif


// Ara:
			GERR_MAX
		};
		GuildJoinErrCode	VerifyGuildJoinableCondition( const LPCHARACTER pchInvitee );

// Altina ekle:
#ifdef ENABLE_GUILD_APPLICATION
	public:
		int		VerifyApplicationJoin(const LPCHARACTER ch) { return (int)VerifyGuildJoinableCondition(ch); }
	private:
#endif

