// Bul:
typedef BYTE TGuildAuthFlag;

// Degistir:
#ifdef ENABLE_GUILD_GRADE_RENEWAL
typedef WORD TGuildAuthFlag;
#else
typedef BYTE TGuildAuthFlag;
#endif

