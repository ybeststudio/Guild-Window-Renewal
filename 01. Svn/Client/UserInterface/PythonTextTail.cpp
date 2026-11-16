// Bul:
const float c_fxMarkPosition = 4.0f;

// Degistir:
#ifdef ENABLE_GUILD_WINDOW_RENEWAL
const float c_fxMarkPosition = 1.0f;
#else
const float c_fxMarkPosition = 4.0f;
#endif


// static std::string BuildOptionGuildName(CPythonTextTail::TTextTail* tail, CInstanceBase* actor) icinde:
// Ara:
    auto& guild = CPythonGuild::Instance();
    CPythonGuild::TGuildMemberData* member = nullptr;
    CPythonGuild::TGuildGradeData* grade = nullptr;

// Altina ekle:
#ifndef ENABLE_GUILD_WINDOW_RENEWAL
    if (actor && tail->optionGuildID == guild.GetGuildID() &&
        guild.GetMemberDataPtrByName(actor->GetNameString(),&member) &&
        guild.GetGradeDataPtr(member->byGrade,&grade))
        return "["+grade->strName+"] "+tail->optionGuildBase;
#endif

