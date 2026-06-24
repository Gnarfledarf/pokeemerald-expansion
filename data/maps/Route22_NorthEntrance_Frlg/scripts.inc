Route22_NorthEntrance_Frlg_MapScripts::
	.byte 0

Route22_NorthEntrance_EventScript_BoulderBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 1
	bufferstdstring STR_VAR_1, STDSTRING_BOULDER_BADGE
	goto Route22_NorthEntrance_EventScript_BadgeGuard
	end

Route22_NorthEntrance_EventScript_BoulderBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_0x8009, 1
	bufferstdstring STR_VAR_1, STDSTRING_BOULDER_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route22_NorthEntrance_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM121, Route22_NorthEntrance_EventScript_ExplainTM121
	msgbox Route22_NorthEntrance_Text_CanIConfide, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route22_NorthEntrance_EventScript_Confide
	goto_if_eq VAR_RESULT, NO, Route22_NorthEntrance_EventScript_DeclineConfide
	end

Route22_NorthEntrance_EventScript_NoRoomForTM121::
	msgbox Route22_NorthEntrance_Text_DontHaveRoomForThis
	release
	end

Route22_NorthEntrance_EventScript_ExplainTM121::
	msgbox Route22_NorthEntrance_Text_ExplainTM121
	release
	end

Route22_NorthEntrance_EventScript_Confide::
	msgbox Route22_NorthEntrance_Text_Confide
	checkitemspace ITEM_TM121
	goto_if_eq VAR_RESULT, FALSE, Route22_NorthEntrance_EventScript_NoRoomForTM121
	giveitem_msg Route22_NorthEntrance_Text_ReceivedTM121FromGirl, ITEM_TM121
	msgbox Route22_NorthEntrance_Text_ExplainTM121
	setflag FLAG_GOT_TM121
	release
	end

Route22_NorthEntrance_EventScript_DeclineConfide::
	msgbox Route22_NorthEntrance_Text_OfCourseNot
	release
	end

Route22_NorthEntrance_Text_CanIConfide::
    .string "Can I confide in you?$"

Route22_NorthEntrance_Text_Confide::
    .string "I once tried to sneak behind the\n"
    .string "gates. I barely made it to the\l"
    .string "second one before I was caught.\p"
    .string "It still is humiliating to remember,\n"
    .string "but thank you for taking the time\l"
    .string "to listen to me.\p"
    .string "Please take this TM.$"

Route22_NorthEntrance_Text_OfCourseNot::
    .string "Of course not.\n"
    .string "I'm a stranger, after all.$"

Route22_NorthEntrance_Text_ReceivedTM121FromGirl::
    .string "{PLAYER} received TM121\n"
    .string "from the girl.$"

Route22_NorthEntrance_Text_ExplainTM121::
    .string "TM121 is a move called Confide.\p"
    .string "It makes the opponent lose focus\n"
    .string "and weakens its special moves.$"

Route22_NorthEntrance_Text_DontHaveRoomForThis::
    .string "You don't have room for this.$"
