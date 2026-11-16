// Ara:
// MARK_BUG_FIX
static DWORD gs_nextDownloadMarkTime = 0;

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
static const DWORD GUILD_MARK_DOWNLOAD_DELAY = 200;
static const DWORD GUILD_MARK_UPLOAD_TIMEOUT = 5000;
static DWORD gs_downloadMarkAfterUploadTime = 0;
static bool gs_isMarkUploadPending = false;
#endif


// UINT CPythonNetworkStream::UploadMark (const char* c_szImageFileName) icinde:
// Bul:
	// MARK_BUG_FIX
	__DownloadMark();
	// END_OF_MARK_BUG_FIX

	if (CGuildMarkManager::INVALID_MARK_ID == CGuildMarkManager::Instance().GetMarkID(m_dwGuildID))
	{
		TraceError("Need reconnecting to guild mark.");
		return ERROR_MARK_CHECK_NEED_RECONNECT;
	}

// Degistir:
#ifdef ENABLE_GUILD_MARK_PNG
	gs_isMarkUploadPending = true;
	gs_downloadMarkAfterUploadTime = ELTimer_GetMSec() + GUILD_MARK_UPLOAD_TIMEOUT;
#else
	// MARK_BUG_FIX
	__DownloadMark();
	// END_OF_MARK_BUG_FIX

	if (CGuildMarkManager::INVALID_MARK_ID == CGuildMarkManager::Instance().GetMarkID(m_dwGuildID))
	{
		TraceError("Need reconnecting to guild mark.");
		return ERROR_MARK_CHECK_NEED_RECONNECT;
	}
#endif


// bool CPythonNetworkStream::OnProcess() icinde:
// Ara:
}
bool CPythonNetworkStream::OnProcess()
{

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
	if (gs_isMarkUploadPending && CGuildMarkUploader::Instance().IsMarkSent())
	{
		gs_isMarkUploadPending = false;
		gs_downloadMarkAfterUploadTime = ELTimer_GetMSec() + GUILD_MARK_DOWNLOAD_DELAY;
	}

	if (gs_downloadMarkAfterUploadTime && ELTimer_GetMSec() >= gs_downloadMarkAfterUploadTime)
	{
		gs_isMarkUploadPending = false;
		gs_downloadMarkAfterUploadTime = 0;
		gs_nextDownloadMarkTime = 0;
		__DownloadMark();
	}
#endif

