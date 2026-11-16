# MessengerWindow.__NotifyGuildWindow icinde ara:
			return
		interface = constInfo.GetInterfaceInstance()

# Altina ekle:
		wndGuild = interface.wndGuild if interface else None
		if wndGuild:
			wndGuild.RefreshGuildMemberPage()

