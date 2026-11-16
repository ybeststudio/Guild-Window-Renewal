CREATE TABLE IF NOT EXISTS `guild_application` (
  `guild_id` int(10) unsigned NOT NULL,
  `pid` int(10) unsigned NOT NULL,
  `apply_time` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guild_id`,`pid`),
  KEY `pid` (`pid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

CREATE TABLE IF NOT EXISTS `guild_application_setting` (
  `guild_id` int(10) unsigned NOT NULL,
  `status` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `lang` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `min_level` smallint(5) unsigned NOT NULL DEFAULT 1,
  `description` varchar(201) NOT NULL DEFAULT '',
  PRIMARY KEY (`guild_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

CREATE TABLE IF NOT EXISTS `guild_donation_coin` (
  `guild_id` int(10) unsigned NOT NULL,
  `gold` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guild_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

CREATE TABLE IF NOT EXISTS `guild_donation_member` (
  `pid` int(10) unsigned NOT NULL,
  `silver` int(10) unsigned NOT NULL DEFAULT 0,
  `day` int(11) NOT NULL DEFAULT 0,
  `scroll` int(11) NOT NULL DEFAULT 0,
  `premium` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`pid`),
  KEY `day` (`day`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

CREATE TABLE IF NOT EXISTS `guild_quest` (
  `guild_id` int(10) unsigned NOT NULL,
  `week` int(11) NOT NULL DEFAULT 0,
  `used1` int(11) NOT NULL DEFAULT 0,
  `used2` int(11) NOT NULL DEFAULT 0,
  `used3` int(11) NOT NULL DEFAULT 0,
  `used4` int(11) NOT NULL DEFAULT 0,
  `type` int(11) NOT NULL DEFAULT 0,
  `level` int(11) NOT NULL DEFAULT 0,
  `cur` int(11) NOT NULL DEFAULT 0,
  `target` int(11) NOT NULL DEFAULT 0,
  `deadline` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`guild_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

CREATE TABLE IF NOT EXISTS `guild_quest_member` (
  `guild_id` int(10) unsigned NOT NULL,
  `pid` int(10) unsigned NOT NULL,
  `score` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guild_id`,`pid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

CREATE TABLE IF NOT EXISTS `guild_skill` (
  `guild_id` int(10) unsigned NOT NULL,
  `exp` int(11) NOT NULL DEFAULT 0,
  `points` int(11) NOT NULL DEFAULT 0,
  `active_until` int(11) NOT NULL DEFAULT 0,
  `lv0` tinyint(4) NOT NULL DEFAULT 0,
  `lv1` tinyint(4) NOT NULL DEFAULT 0,
  `lv2` tinyint(4) NOT NULL DEFAULT 0,
  `lv3` tinyint(4) NOT NULL DEFAULT 0,
  `lv4` tinyint(4) NOT NULL DEFAULT 0,
  `lv5` tinyint(4) NOT NULL DEFAULT 0,
  `lv6` tinyint(4) NOT NULL DEFAULT 0,
  `lv7` tinyint(4) NOT NULL DEFAULT 0,
  `lv8` tinyint(4) NOT NULL DEFAULT 0,
  `lv9` tinyint(4) NOT NULL DEFAULT 0,
  PRIMARY KEY (`guild_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

CREATE TABLE IF NOT EXISTS `guild_log` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `guild_id` int(10) unsigned NOT NULL,
  `type` tinyint(4) NOT NULL,
  `name` varchar(24) NOT NULL,
  `a` int(11) NOT NULL DEFAULT 0,
  `b` int(11) NOT NULL DEFAULT 0,
  `c` int(11) NOT NULL DEFAULT 0,
  `ts` datetime NOT NULL,
  PRIMARY KEY (`id`),
  KEY `guild_day` (`guild_id`,`type`,`ts`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- ENABLE_GUILD_GRADE_RENEWAL: rutbe yetkileri 9 bit (WORD).
ALTER TABLE `guild_grade` MODIFY `auth` SET('ADD_MEMBER','REMOVE_MEMEBER','NOTICE','USE_SKILL','WAR','SHOP','QUEST','UP_SKILL','DUNGEON') DEFAULT NULL;
