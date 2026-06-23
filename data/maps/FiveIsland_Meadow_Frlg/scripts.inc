FiveIsland_Meadow_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_Meadow_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, FiveIsland_Meadow_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_Meadow_OnTransition
	.byte 0

FiveIsland_Meadow_OnLoad::
	call_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	end

FiveIsland_Meadow_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FiveIsland_Meadow_EventScript_TryRemoveSudowoodo
	end

FiveIsland_Meadow_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	setflag FLAG_DEFEATED_FIVE_ISLAND_MEADOW_SUDOWOODO
	removeobject VAR_LAST_TALKED
	return

FiveIsland_Meadow_OnTransition:
	call_if_unset FLAG_DEFEATED_FIVE_ISLAND_MEADOW_SUDOWOODO, FiveIsland_Meadow_EventScript_ShowSudowoodo
	end

FiveIsland_Meadow_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_FIVE_ISLAND_MEADOW_SUDOWOODO
	return

FiveIsland_Meadow_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FIVE_ISLAND_MEADOW_SUDOWOODO, FiveIsland_Meadow_Movement_SudowoodoShake
	waitmovement 0
	release
	end

FiveIsland_Meadow_EventScript_HeadbuttSudowoodo::
	lockall
	checkfieldmove FIELD_MOVE_HEADBUTT
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq FiveIsland_Meadow_EventScript_Sudowoodo
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename 1, MOVE_HEADBUTT
	msgbox Text_WantToHeadbutt_Sudowoodo, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelHeadbutt
	msgbox Text_MonUsedHeadbutt, MSGBOX_DEFAULT
	closemessage
	goto FiveIsland_Meadow_EventScript_HeadbuttTree_Sudowoodo
	end

FiveIsland_Meadow_EventScript_HeadbuttTree_Sudowoodo::
	lockall
	dofieldeffect FLDEFF_USE_HEADBUTT
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeScreen
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FIVE_ISLAND_MEADOW_SUDOWOODO, FiveIsland_Meadow_Movement_SudowoodoShake
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FIVE_ISLAND_MEADOW_SUDOWOODO, FiveIsland_Meadow_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Furious, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FIVE_ISLAND_MEADOW_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FiveIsland_Meadow_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FiveIsland_Meadow_EventScript_RanFromSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FiveIsland_Meadow_EventScript_RanFromSudowoodo
	release
	end

FiveIsland_Meadow_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_FIVE_ISLAND_MEADOW_SUDOWOODO
	goto EventScript_RemoveStaticMon
	end

FiveIsland_Meadow_EventScript_RanFromSudowoodo:
	end

FiveIsland_Meadow_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

FiveIsland_Meadow_EventScript_WarehouseDoor::
	lockall
	goto_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen
	goto_if_set FLAG_LEARNED_YES_NAH_CHANSEY, FiveIsland_Meadow_EventScript_OpenWarehouseDoor
	msgbox FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded
	releaseall
	end

FiveIsland_Meadow_EventScript_OpenWarehouseDoor::
	setflag FLAG_UNLOCKED_ROCKET_WAREHOUSE
	message FiveIsland_Meadow_Text_EnteredPasswordDoorOpened
	waitmessage
	delay 60
	call FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	special DrawWholeMapView
	playse SE_PIN
	waitse
	releaseall
	end

FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen::
	msgbox FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen
	releaseall
	end

FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked::
	setmetatile 12, 21, METATILE_SeviiIslands45_RocketWarehouseDoor_Unlocked, 1
	return

FiveIsland_Meadow_EventScript_Rocket1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_49, FiveIsland_Meadow_Text_Rocket1Intro, FiveIsland_Meadow_Text_Rocket1Defeat
	msgbox FiveIsland_Meadow_Text_Rocket1PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_50, FiveIsland_Meadow_Text_Rocket2Intro, FiveIsland_Meadow_Text_Rocket2Defeat
	msgbox FiveIsland_Meadow_Text_Rocket2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_51, FiveIsland_Meadow_Text_Rocket3Intro, FiveIsland_Meadow_Text_Rocket3Defeat
	msgbox FiveIsland_Meadow_Text_Rocket3PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded::
    .string "{PLAYER} entered a password.\p"
    .string "“Goldeen need log.”\p"
    .string "… …  … …  … …\p"
    .string "Another password is needed to\n"
    .string "open the door…$"

FiveIsland_Meadow_Text_EnteredPasswordDoorOpened::
    .string "{PLAYER} entered two passwords.\p"
    .string "“Goldeen need log.”\n"
    .string "“Yes, nah, Chansey.”\p"
    .string "… …  … …  … …\p"
    .string "The Warehouse's door opened!$"

FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen::
    .string "The Warehouse's door is already\n"
    .string "open.$"

FiveIsland_Meadow_Text_Rocket1Intro::
    .string "This area's strictly off-limits!\n"
    .string "Out, out!$"

FiveIsland_Meadow_Text_Rocket1Defeat::
    .string "Is this for real?$"

FiveIsland_Meadow_Text_Rocket1PostBattle::
    .string "You don't have any business here!\n"
    .string "Go home!$"

FiveIsland_Meadow_Text_Rocket2Intro::
    .string "There's nothing past here except\n"
    .string "our Warehouse.\p"
    .string "So what brings you here?$"

FiveIsland_Meadow_Text_Rocket2Defeat::
    .string "That wasn't supposed to happen…$"

FiveIsland_Meadow_Text_Rocket2PostBattle::
    .string "You're wanting to know what's inside\n"
    .string "this Warehouse?\p"
    .string "It's better you didn't know.\n"
    .string "For your own sake, I mean.$"

FiveIsland_Meadow_Text_Rocket3Intro::
    .string "You'd be wasting time even if you\n"
    .string "were to get by me.$"

FiveIsland_Meadow_Text_Rocket3Defeat::
    .string "Oh, that makes me furious!$"

FiveIsland_Meadow_Text_Rocket3PostBattle::
    .string "You won't be able to get in without\n"
    .string "the passwords anyway.$"

gText_Sudowoodo_Furious::
	.string "The weird tree has become furious!\p"
	.string "The weird tree attacked!$"
