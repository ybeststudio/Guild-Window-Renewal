# Ara:
if app.ENABLE_WHISPER_MESSENGER:
	import uiWhisperMessenger

# Altina ekle:
if app.ENABLE_GUILD_APPLICATION:
	import uiGuildApplication


# Interface.__init__ icinde ara:
		self.wndWhisperMessenger = None
		self.wndMessengerButton = None

# Altina ekle:
		self.wndGuildApplication = None
		self.wndGuildJoinNotification = None


# Interface.__init__ icinde ara:
		self.wndMessenger = None
		self.wndMiniMap = None

# Altina ekle:
		self.wndGuild = None


# Interface.__MakeMessengerWindow icinde ara:
		from _weakref import proxy
		self.wndMessenger.SetWhisperButtonEvent(lambda n,i=proxy(self):i.OpenWhisperDialog(n))

# Altina ekle:
		self.wndMessenger.SetGuildButtonEvent(ui.__mem_func__(self.ToggleGuildWindow))


# Interface icine ekle:
	def __MakeGuildWindow(self):
		if app.ENABLE_GUILD_WINDOW_RENEWAL:
			import uiGuildRenewal
			self.wndGuild = uiGuildRenewal.GuildWindow()
		else:
			self.wndGuild = uiGuild.GuildWindow()


# Interface.__MakeWindows icinde ara:
				dbg.TraceError("WhisperMessenger init failed: " + traceback.format_exc())
				self.wndWhisperMessenger = None

# Altina ekle:
		if app.ENABLE_GUILD_APPLICATION:
			try:
				self.wndGuildApplication = uiGuildApplication.GuildApplicationWindow()
				self.wndGuildJoinNotification = uiGuildApplication.GuildJoinNotification()
				uiGuildApplication.g_interface = self
			except:
				import dbg, traceback
				dbg.TraceError("GuildApplication init failed: " + traceback.format_exc())
				self.wndGuildApplication = None
				self.wndGuildJoinNotification = None


# Interface.MakeInterface icinde ara:
	def MakeInterface(self):
		self.__MakeMessengerWindow()

# Altina ekle:
		self.__MakeGuildWindow()


# Interface.MakeInterface icinde ara:
		self.wndTaskBar.SetItemToolTip(self.tooltipItem)
		self.wndTaskBar.SetSkillToolTip(self.tooltipSkill)

# Altina ekle:
		self.wndGuild.SetSkillToolTip(self.tooltipSkill)


# Interface.Close icinde ara:
		if self.wndItemFinder:
			self.wndItemFinder.Destroy()

# Altina ekle:
		if self.wndGuild:
			self.wndGuild.Destroy()


# Interface.Close icinde ara:
			self.wndMessengerButton.Hide()
			self.wndMessengerButton = None

# Altina ekle:
		if app.ENABLE_GUILD_APPLICATION:
			if self.wndGuildApplication:
				self.wndGuildApplication.Destroy()
				self.wndGuildApplication = None
			if self.wndGuildJoinNotification:
				self.wndGuildJoinNotification.Hide()
				self.wndGuildJoinNotification = None
			uiGuildApplication.g_interface = None


# Interface.Close icinde ara:
		del self.mallPageDlg
		# END_OF_ITEM_MALL

# Altina ekle:
		del self.wndGuild


# Interface.OnUseSkill icinde ara:
		self.wndCharacter.OnUseSkill(slotIndex, coolTime)
		self.wndTaskBar.OnUseSkill(slotIndex, coolTime)

# Altina ekle:
		self.wndGuild.OnUseSkill(slotIndex, coolTime)


# Interface icinde ara:
	def RefreshMessenger(self):
		self.wndMessenger.RefreshMessenger()

# Altina ekle:
	def RefreshGuildInfoPage(self):
		self.wndGuild.RefreshGuildInfoPage()

	def RefreshGuildBoardPage(self):
		self.wndGuild.RefreshGuildBoardPage()

	def RefreshGuildMemberPage(self):
		self.wndGuild.RefreshGuildMemberPage()

	def RefreshGuildMemberPageGradeComboBox(self):
		self.wndGuild.RefreshGuildMemberPageGradeComboBox()

	def RefreshGuildSkillPage(self):
		self.wndGuild.RefreshGuildSkillPage()

	def RefreshGuildGradePage(self):
		self.wndGuild.RefreshGuildGradePage()


	def DeleteGuild(self):
		self.wndMessenger.ClearGuildMember()
		self.wndGuild.DeleteGuild()


# Interface.OnStartGuildWar icinde ara:
	def OnStartGuildWar(self, guildSelf, guildOpp):

# Altina ekle:
		self.wndGuild.OnStartGuildWar(guildSelf, guildOpp)


# Interface.OnEndGuildWar icinde ara:
	def OnEndGuildWar(self, guildSelf, guildOpp):

# Altina ekle:
		self.wndGuild.OnEndGuildWar(guildSelf, guildOpp)


# Interface.HideAllWindows icinde ara:
		if self.wndMessenger:
			self.wndMessenger.Hide()

# Altina ekle:
		if self.wndGuild:
			self.wndGuild.Hide()


# Interface icinde ara:
	def GetBuffiSkillsCooldown(self):
		return self.wndCompanion.GetBuffiSkillsCooldown() if self.wndCompanion else []

# Altina ekle:
	def ToggleGuildWindow(self):

		if not self.wndGuild.IsShow():
			if self.wndGuild.CanOpen():
				self.wndGuild.Open()
			elif app.ENABLE_GUILD_APPLICATION and self.wndGuildApplication:
				self.ToggleGuildApplication()
			else:
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.GUILD_YOU_DO_NOT_JOIN)
		else:
			self.wndGuild.OverOutItem()
			self.wndGuild.Hide()

	if app.ENABLE_GUILD_APPLICATION:
		def GetGuildApplicationWnd(self):
			return self.wndGuildApplication

		def GetGuildJoinNotificationWnd(self):
			return self.wndGuildJoinNotification

		def ToggleGuildApplication(self, mode = 0):
			wnd = self.GetGuildApplicationWnd()
			if not wnd:
				return
			if wnd.IsShow():
				wnd.Close()
			else:
				wnd.Open(mode)

		def OpenGuildJoinNotification(self, guildID, guildName, description):
			import advanced_options_runtime
			wnd = self.GetGuildJoinNotificationWnd()
			if not wnd or guild.IsGuildEnable():
				return
			if not advanced_options_runtime.Get("show_guild_join_notification", True):
				return
			wnd.Open(guildID, guildName, description)


# Interface.__HideWindows icinde ara:
						self.wndExpandedMoney,\
						self.wndMiniMap,\

# Altina ekle:
						self.wndGuild,\

