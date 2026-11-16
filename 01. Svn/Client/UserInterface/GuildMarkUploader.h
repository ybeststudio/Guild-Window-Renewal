// Ara:
		bool Connect(const CNetworkAddress& c_rkNetAddr, DWORD dwHandle, DWORD dwRandomKey, DWORD dwGuildID, const char* c_szFileName, UINT* peError);
		bool ConnectToSendSymbol(const CNetworkAddress& c_rkNetAddr, DWORD dwHandle, DWORD dwRandomKey, DWORD dwGuildID, const char* c_szFileName, UINT* peError);
		bool IsCompleteUploading();

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
		bool IsMarkSent() const { return m_isMarkSent; }
#endif


// Ara:
		void OnRemoteDisconnect();
		void OnDisconnect();
		bool __Load(const char* c_szFileName, UINT* peError);

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
		bool __LoadPng(const char* c_szFileName, UINT* peError);
#endif


// Ara:
		DWORD m_dwRandomKey;
		DWORD m_dwGuildID;
		SGuildMark m_kMark;

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
		bool m_isMarkSent;
#endif

