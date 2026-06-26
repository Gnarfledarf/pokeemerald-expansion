EventScript_UseSurf::
	checkfieldmoveusable FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndUseSurf
	checkitem ITEM_HM03, 1
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndUseSurf
	lockall
	goto_if_set FLAG_SYS_USE_SURF, EventScript_UseSurfQuick
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	EventScript_UseSurfQuick:
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end

EventScript_CurrentTooFast::
	lockall
	checkfieldmoveusable FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, FALSE, EventScript_CurrentTooFastEndMsg
	checkitem ITEM_HM03, 1
	goto_if_eq VAR_RESULT, FALSE, EventScript_CurrentTooFastEndMsg
	playse SE_SELECT
	msgbox Text_CurrentTooFast
EventScript_CurrentTooFastEndMsg::
	releaseall
	end
