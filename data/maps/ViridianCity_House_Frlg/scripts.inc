ViridianCity_House_Frlg_MapScripts::
	.byte 0

ViridianCity_House_EventScript_BaldingMan::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, ViridianCity_House_EventScript_BaldingMan_AlreadyGotSharpBeak
	goto_if_set FLAG_GOT_SHARP_BEAK_IN_VIRIDIAN_CITY_HOUSE, ViridianCity_House_EventScript_BaldingMan_AlreadyGotSharpBeak
	msgbox ViridianCity_House_Text_DoYouHaveSpearow, MSGBOX_NPC
	check_if_species_caught SPECIES_SPEAROW
	goto_if_eq VAR_RESULT, TRUE, ViridianCity_House_EventScript_BaldingMan_CaughtSpearow
	release
	end

ViridianCity_House_EventScript_BaldingMan_CaughtSpearow::
	msgbox ViridianCity_House_Text_YouHaveCaughtSpearow, MSGBOX_NPC
	textcolor NPC_TEXT_COLOR_NEUTRAL
	checkitemspace ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	bufferitemname STR_VAR_2, ITEM_SHARP_BEAK
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitmessage
	waitfanfare
	additem ITEM_SHARP_BEAK
	msgbox ViridianCity_House_Text_SharpBeakAway
	call EventScript_RestorePrevTextColor
	setflag FLAG_GOT_SHARP_BEAK_IN_VIRIDIAN_CITY_HOUSE
	msgbox ViridianCity_House_Text_ItMakesFlyingTypeATtacksMorePowerful, MSGBOX_NPC
	release
	end

ViridianCity_House_EventScript_BaldingMan_AlreadyGotSharpBeak::
	msgbox ViridianCity_House_Text_NicknamingIsFun, MSGBOX_NPC
	release
	end

ViridianCity_House_EventScript_LittleGirl::
	msgbox ViridianCity_House_Text_MyDaddyLovesMonsToo, MSGBOX_NPC
	end

ViridianCity_House_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House_Text_Speary
	waitmoncry
	release
	end

ViridianCity_House_EventScript_NicknameSign::
	msgbox ViridianCity_House_Text_SpearowNameSpeary, MSGBOX_SIGN
	end
	end

ViridianCity_House_Text_DoYouHaveSpearow::
    .string "You're working on a Pokédex?\n"
    .string "Have you caught a Spearow?\p"
    .string "If you catch a Spearow, would\n"
    .string "you show me its Pokédex entry?$"

ViridianCity_House_Text_YouHaveCaughtSpearow::
    .string "You've caught Spearow?\n"
    .string "Let me see the Pokédex entry!\p"
    .string "…\n"
    .string "…\p"
    .string "I see…\n"
    .string "Thank you so much!\p"
    .string "Take this, my fellow Spearow friend!$"

ViridianCity_House_Text_ItMakesFlyingTypeATtacksMorePowerful::
    .string "Give it a Pokémon to hold to make\n"
    .string "its Flying-type attacks more\l"
    .string "powerful!$"

ViridianCity_House_Text_SharpBeakAway::
    .string "{PLAYER} put the Sharp Beak away in\n"
    .string "the Bag's Items Pocket.$"

ViridianCity_House_Text_NicknamingIsFun::
    .string "Coming up with nicknames is fun,\n"
    .string "but it's not so easy to do.\p"
    .string "Clever names are nice, but simple\n"
    .string "names are easier to remember.$"

ViridianCity_House_Text_MyDaddyLovesMonsToo::
    .string "My daddy loves Pokémon, too.$"

ViridianCity_House_Text_Speary::
    .string "Speary: Tetweet!$"

ViridianCity_House_Text_SpearowNameSpeary::
    .string "Spearow\n"
    .string "Name: Speary$"
