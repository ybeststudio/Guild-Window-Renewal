# GameWindow.__PressGKey icinde ara:
		else:
			if self.ShowNameFlag:

# Altina ekle:
				self.interface.ToggleGuildWindow()


# GameWindow icinde ara:
	def RefreshMessenger(self):
		self.interface.RefreshMessenger()

# Altina ekle:
	def RefreshGuildInfoPage(self):
		self.interface.RefreshGuildInfoPage()

	def RefreshGuildBoardPage(self):
		self.interface.RefreshGuildBoardPage()

	def RefreshGuildMemberPage(self):
		self.interface.RefreshGuildMemberPage()

	def RefreshGuildMemberPageGradeComboBox(self):
		self.interface.RefreshGuildMemberPageGradeComboBox()

	def RefreshGuildSkillPage(self):
		self.interface.RefreshGuildSkillPage()

	def RefreshGuildGradePage(self):
		self.interface.RefreshGuildGradePage()


# GameWindow icinde ara:
		self.guildInviteQuestionDialog.Close()
		self.guildInviteQuestionDialog = None

# Altina ekle:
	def DeleteGuild(self):
		self.interface.DeleteGuild()


# GameWindow.__HideMapItemToolTip icinde ara:
		windowList = [self.interface.wndInventory, self.interface.wndSafebox, self.interface.wndMall, self.interface.wndCube,
			self.interface.dlgShop, self.interface.dlgExchange, self.interface.wndItemSelect, self.interface.wndCharacter,

# Altina ekle:
			self.interface.wndTaskBar, self.interface.wndGuild, self.interface.wndMessenger, self.interface.wndMiniMap,


# GameWindow icinde ara:
		if app.ENABLE_WHISPER_MESSENGER and self.interface:
			self.interface.RecvOfflineWhisperResult(int(result), name)

# Altina ekle:
	def __GetGuildRenewalWindow(self):
		if app.ENABLE_GUILD_WINDOW_RENEWAL and self.interface:
			return self.interface.wndGuild
		return None


# GameWindow.GuildGoldCoins icinde ara:
	def GuildGoldCoins(self, gold):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildSilverCoins icinde ara:
	def GuildSilverCoins(self, silver):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.SendDailyGuildDonation icinde ara:
	def SendDailyGuildDonation(self, scroll, premium):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildMemberDailyDonation icinde ara:
	def GuildMemberDailyDonation(self, payload):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildDonationResult icinde ara:
	def GuildDonationResult(self, result):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildQuestInfo icinde ara:
	def GuildQuestInfo(self, used1, used2, used3, used4, questType, level, cur, target, secondsLeft):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildQuestProgress icinde ara:
	def GuildQuestProgress(self, cur, target):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildQuestResult icinde ara:
	def GuildQuestResult(self, result):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildQuestRankBegin icinde ara:
	def GuildQuestRankBegin(self):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildQuestRankRow icinde ara:
	def GuildQuestRankRow(self, name, score):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildQuestRankEnd icinde ara:
	def GuildQuestRankEnd(self):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildSkillInfo icinde ara:
	def GuildSkillInfo(self, exp, points, energy, maxEnergy, activeLeft, lv0, lv1, lv2, lv3, lv4, lv5, lv6, lv7, lv8, lv9):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildSkillResult icinde ara:
	def GuildSkillResult(self, result, value):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildShopResult icinde ara:
	def GuildShopResult(self, result):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildLogBegin icinde ara:
	def GuildLogBegin(self, logType):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildLogRow icinde ara:
	def GuildLogRow(self, stamp, name, a, b, c):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow.GuildLogEnd icinde ara:
	def GuildLogEnd(self):

# Altina ekle:
		wnd = self.__GetGuildRenewalWindow()


# GameWindow icinde ara:
		if wnd:
			wnd.LogEnd()

# Altina ekle:
	def __GetGuildApplicationWnd(self):
		if app.ENABLE_GUILD_APPLICATION and self.interface:
			return self.interface.GetGuildApplicationWnd()
		return None


# GameWindow.GuildAppListBegin icinde ara:
	def GuildAppListBegin(self):

# Altina ekle:
		wnd = self.__GetGuildApplicationWnd()


# GameWindow.GuildAppRow icinde ara:
	def GuildAppRow(self, gid, status, level, members, maxMembers, minLevel, lang, empire, ladder, applied, name, desc):

# Altina ekle:
		wnd = self.__GetGuildApplicationWnd()


# GameWindow.GuildAppRow icinde ara:
		if wnd:

# Altina ekle:
			import uiGuildApplication


# GameWindow.GuildAppRow icinde ara:
			wnd.RecvGuildRow({"gid" : int(gid), "status" : int(status), "level" : int(level), "members" : int(members),
				"maxMembers" : int(maxMembers), "minLevel" : int(minLevel), "lang" : int(lang), "empire" : int(empire),

# Altina ekle:
				"ladder" : int(ladder), "applied" : int(applied), "name" : name.replace("\x1f", " "), "desc" : uiGuildApplication.Decode(desc)})


# GameWindow.GuildAppListEnd icinde ara:
	def GuildAppListEnd(self):

# Altina ekle:
		wnd = self.__GetGuildApplicationWnd()


# GameWindow.GuildAppApplied icinde ara:
	def GuildAppApplied(self, gid, applied):

# Altina ekle:
		wnd = self.__GetGuildApplicationWnd()


# GameWindow icinde ara:
		if wnd:
			wnd.RecvApplied(int(gid), int(applied))

# Altina ekle:
	def GuildAppSettings(self, gid, status, lang, minLevel, desc):
		wnd = self.__GetGuildApplicationWnd()
		if wnd:
			import uiGuildApplication
			wnd.RecvSettings(int(gid), int(status), int(lang), int(minLevel), uiGuildApplication.Decode(desc))


# GameWindow.GuildAppReqBegin icinde ara:
	def GuildAppReqBegin(self):

# Altina ekle:
		wnd = self.__GetGuildApplicationWnd()


# GameWindow.GuildAppReq icinde ara:
	def GuildAppReq(self, pid, level, job, lastPlay, name):

# Altina ekle:
		wnd = self.__GetGuildApplicationWnd()


# GameWindow.GuildAppReqEnd icinde ara:
	def GuildAppReqEnd(self):

# Altina ekle:
		wnd = self.__GetGuildApplicationWnd()


# GameWindow.GuildAppNewRequest icinde ara:
	def GuildAppNewRequest(self):

# Altina ekle:
		wnd = self.__GetGuildApplicationWnd()


# GameWindow icinde ara:
		if wnd and wnd.IsShow():
			net.SendChatPacket("/guild_app requests")

# Altina ekle:
	def ServerCommand_Guild_JoinNotify(self, GID, name, desc = ""):
		if app.ENABLE_GUILD_APPLICATION and self.interface:
			import uiGuildApplication
			self.interface.OpenGuildJoinNotification(int(GID), name.replace("\x1f", " "), uiGuildApplication.Decode(desc))


# GameWindow.__ServerCommand_Build icinde ara:
			"GuildAppListEnd" : self.GuildAppListEnd,
			"GuildAppApplied" : self.GuildAppApplied,

# Altina ekle:
			"GuildAppSettings" : self.GuildAppSettings,


# GameWindow.__ServerCommand_Build icinde ara:
			"GuildAppReqEnd" : self.GuildAppReqEnd,
			"GuildAppNewRequest" : self.GuildAppNewRequest,

# Altina ekle:
			"Guild_JoinNotify" : self.ServerCommand_Guild_JoinNotify,

