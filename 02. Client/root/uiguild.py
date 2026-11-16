# GuildWindow.Show icinde ara:
			self.isLoaded=1
			self.__LoadWindow()

# Altina ekle:
		self.RefreshGuildInfoPage()
		self.RefreshGuildBoardPage()
		self.RefreshGuildMemberPage()
		self.RefreshGuildSkillPage()
		self.RefreshGuildGradePage()


# GuildWindow icinde ara:
		self.moneyDialog = None
		self.enemyGuildNameList = []

# Altina ekle:
	def DeleteGuild(self):
		self.RefreshGuildInfoPage()
		self.RefreshGuildBoardPage()
		self.RefreshGuildMemberPage()
		self.RefreshGuildSkillPage()
		self.RefreshGuildGradePage()
		self.Hide()


# GuildWindow icinde ara:
		for key, slotList in page.memberDict.items():
			slotList[1].CloseListBox()

# Altina ekle:
	def RefreshGuildInfoPage(self):
		if self.isLoaded==0:
			return

		global DISABLE_DECLARE_WAR
		page = self.pageWindow["GUILD_INFO"]
		page.nameSlot.SetText(guild.GetGuildName())
		page.masterNameSlot.SetText(guild.GetGuildMasterName())
		page.guildLevelSlot.SetText(str(guild.GetGuildLevel()))
		if page.guildMoneySlot:
			page.guildMoneySlot.SetText(str(guild.GetGuildMoney()))

		curExp, lastExp = guild.GetGuildExperience()
		curExp *= 100
		lastExp *= 100
		page.curExpSlot.SetText(str(curExp))
		page.lastExpSlot.SetText(str(lastExp))

		curMemberCount, maxMemberCount = guild.GetGuildMemberCount()
		if maxMemberCount== 0xffff:
			page.memberCountSlot.SetText("%d / %s " % (curMemberCount, localeInfo.GUILD_MEMBER_COUNT_INFINITY))
		else:
			page.memberCountSlot.SetText("%d / %d" % (curMemberCount, maxMemberCount))

		page.levelAverageSlot.SetText(str(guild.GetGuildMemberLevelAverage()))

		mainCharacterName = player.GetMainCharacterName()
		masterName = guild.GetGuildMasterName()

		if mainCharacterName == masterName:
			page.uploadMarkButton.Show()

			if DISABLE_DECLARE_WAR:
				page.declareWarButton.Hide()
			else:
				page.declareWarButton.Show()

			if guild.HasGuildLand():
				page.uploadSymbolButton.Show()
			else:
				page.uploadSymbolButton.Hide()
		else:
			page.uploadMarkButton.Hide()
			page.declareWarButton.Hide()
			page.uploadSymbolButton.Hide()

		for i in xrange(guild.ENEMY_GUILD_SLOT_MAX_COUNT):
			name = guild.GetEnemyGuildName(i)
			nameTextLine = self.enemyGuildNameList[i]
			if name:
				nameTextLine.SetText(name)
			else:
				nameTextLine.SetText(localeInfo.GUILD_INFO_ENEMY_GUILD_EMPTY)


# GuildWindow icinde ara:
				comment=localeInfo.UI_NOCONTENTS
		return commentID, chrName, comment

# Altina ekle:
	def RefreshGuildBoardPage(self):
		if self.isLoaded==0:
			return

		page = self.pageWindow["BOARD"]

		self.BOARD_LINE_MAX_NUM = 12
		lineIndex = 0

		commentCount = guild.GetGuildBoardCommentCount()
		for i in xrange(commentCount):
			commentID, chrName, comment = self.__GetGuildBoardCommentData(i)

			if not comment:
				continue

			slotList = page.boardDict[lineIndex]

			if "!" == comment[0]:
				slotList[0].Show()
				slotList[1].SetText(chrName)
				slotList[2].SetText(comment[1:])
			else:
				slotList[0].Hide()
				slotList[1].SetText(chrName)
				slotList[2].SetText(comment)

			lineIndex += 1

		for i in xrange(self.BOARD_LINE_MAX_NUM - lineIndex):
			slotList = page.boardDict[lineIndex+i]
			slotList[0].Hide()
			slotList[1].SetText("")
			slotList[2].SetText("")

	def RefreshGuildMemberPage(self):
		if self.isLoaded==0:
			return

		page = self.pageWindow["MEMBER"]

		## ScrollBar
		count = guild.GetMemberCount()
		if count > self.MEMBER_LINE_COUNT:
			page.scrollBar.SetMiddleBarSize(float(self.MEMBER_LINE_COUNT) / float(count))
			page.scrollBar.Show()
		else:
			page.scrollBar.Hide()
		self.RefreshGuildMemberPageGradeComboBox()
		self.RefreshGuildMemberPageMemberList()


# GuildWindow icinde ara:
			if 1 != grade:
				gradeComboBox.Enable()

# Altina ekle:
	def RefreshGuildMemberPageGradeComboBox(self):
		if self.isLoaded==0:
			return

		page = self.pageWindow["MEMBER"]

		self.CAN_CHANGE_GRADE_COUNT = 15 - 1
		for key, slotList in page.memberDict.items():
			gradeComboBox = slotList[1]
			gradeComboBox.Disable()

			if not guild.IsMember(key):
				continue

			pid, name, grade, job, level, offer, general = self.GetMemberData(key)
			if pid < 0:
				continue

			gradeComboBox.ClearItem()
			for i in xrange(self.CAN_CHANGE_GRADE_COUNT):
				if app.ENABLE_MULTI_LANGUAGE_SYSTEM:
					if guild.GetGradeName(i + 2) == "Member":
						gradeComboBox.InsertItem(i + 2, uiScriptLocale.GUILD_BANKINFO_NAME)
					else:
						gradeComboBox.InsertItem(i + 2, guild.GetGradeName(i + 2))
				else:
					gradeComboBox.InsertItem(i + 2, guild.GetGradeName(i + 2))

			if app.ENABLE_MULTI_LANGUAGE_SYSTEM:
				if guild.GetGradeName(grade) == "Member":
					gradeComboBox.SetCurrentItem(uiScriptLocale.GUILD_BANKINFO_NAME)
				else:
					gradeComboBox.SetCurrentItem(guild.GetGradeName(grade))
			else:
				gradeComboBox.SetCurrentItem(guild.GetGradeName(grade))

			if 1 != grade:
				gradeComboBox.Enable()


	def RefreshGuildSkillPage(self):
		if self.isLoaded==0:
			return

		page = self.pageWindow["SKILL"]

		curPoint, maxPoint = guild.GetDragonPowerPoint()
		maxPoint = max(maxPoint, 1)
		page.gpValue.SetText(str(curPoint) + " / " + str(maxPoint))

		percentage = (float(curPoint) / float(maxPoint) * 100) * (float(173) / float(95))
		page.gpGauge.SetPercentage(int(percentage), 100)

		skillPoint = guild.GetGuildSkillPoint()
		page.skillPoint.SetText(str(skillPoint))

		page.passiveSlot.HideAllSlotButton()
		page.activeSlot.HideAllSlotButton()

		## Active
		for i in xrange(len(playerSettingModule.ACTIVE_GUILD_SKILL_INDEX_LIST)):
			slotIndex = page.activeSlot.GetStartIndex()+i
			skillIndex = playerSettingModule.ACTIVE_GUILD_SKILL_INDEX_LIST[i]
			skillLevel = guild.GetSkillLevel(slotIndex)
			skillMaxLevel = skill.GetSkillMaxLevel(skillIndex)

			page.activeSlot.SetSlotCount(slotIndex, skillLevel)

			if skillLevel <= 0:
				page.activeSlot.DisableCoverButton(slotIndex)
			else:
				page.activeSlot.EnableCoverButton(slotIndex)

			if skillPoint > 0:
				if skillLevel < skillMaxLevel:
					page.activeSlot.ShowSlotButton(slotIndex)

	def RefreshGuildGradePage(self):

		if self.isLoaded==0:
			return

		page = self.pageWindow["GRADE"]

		for key, slotList in page.gradeDict.items():
			name, authority = guild.GetGradeData(int(key))

			if app.ENABLE_MULTI_LANGUAGE_SYSTEM:
				if key > 1:
					if name == "Member":
						slotList[self.GRADE_SLOT_NAME].SetText(uiScriptLocale.GUILD_BANKINFO_NAME)
					else:
						slotList[self.GRADE_SLOT_NAME].SetText(name)
				else:
					slotList[self.GRADE_SLOT_NAME].SetText(uiScriptLocale.GUILD_INFO_MASTER_VALUE)
			else:
				slotList[self.GRADE_SLOT_NAME].SetText(name)

			slotList[self.GRADE_ADD_MEMBER_AUTHORITY].SetCheck(authority & guild.AUTH_ADD_MEMBER)
			slotList[self.GRADE_REMOVE_MEMBER_AUTHORITY].SetCheck(authority & guild.AUTH_REMOVE_MEMBER)
			slotList[self.GRADE_NOTICE_AUTHORITY].SetCheck(authority & guild.AUTH_NOTICE)
			slotList[self.GRADE_SKILL_AUTHORITY].SetCheck(authority & guild.AUTH_SKILL)


# GuildWindow.__OnSelectMark icinde, ilgili if blogunun sonuna ekle:
		elif app.ENABLE_GUILD_MARK_PNG and net.ERROR_LOAD_MARK == ret:
			self.__PopupMessage(localeInfo.GUILDMARK_UPLOADER_ERROR_FILE_FORMAT)
		elif app.ENABLE_GUILD_MARK_PNG and net.ERROR_MARK_WIDTH == ret:
			self.__PopupMessage(localeInfo.GUILDMARK_UPLOADER_ERROR_16_WIDTH)
		elif app.ENABLE_GUILD_MARK_PNG and net.ERROR_MARK_HEIGHT == ret:
			self.__PopupMessage(localeInfo.GUILDMARK_UPLOADER_ERROR_12_HEIGHT)


# GuildWindow icinde ara:
			return
		self.offerDialog.Open(curEXP, 100)

# Altina ekle:
	if app.ENABLE_GUILD_APPLICATION:
		def __OnClickGuildListButton(self):
			# "Lonca Listesi" button: guild application window, leader tab for master / generals
			import uiGuildApplication
			uiGuildApplication.Toggle(uiGuildApplication.MODE_LEADER)
	else:
		def __OnClickGuildListButton(self):
			pass

