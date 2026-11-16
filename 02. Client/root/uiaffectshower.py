# AffectShower.__ArrangeImageList icinde ara:
		yPos = 0
		special = []

# Altina ekle:
		if app.ENABLE_GUILD_WINDOW_RENEWAL and guild.IsGuildEnable():
			if not self.benedictionImage:
				self.benedictionImage = BenedictionImage()
				self.benedictionImage.SetParent(self)
		elif self.benedictionImage:
			self.benedictionImage.Hide()
			self.benedictionImage = None

