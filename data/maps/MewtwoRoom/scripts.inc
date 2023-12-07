MewtwoRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MewtwoRoom_On_Tranisition
	.byte 0


MewtwoRoom_On_Tranisition::
	goto_if_unset FLAG_AIDEN_DEFEATED, MewtwoRoom_On_Tranisition_2
	goto_if_set FLAG_AIDEN_DEFEATED, MewtwoRoom_On_Tranisition_3
MewtwoRoom_On_Tranisition_1:
	end

MewtwoRoom_On_Tranisition_2:
	call HideMewtwo
	goto MewtwoRoom_On_Tranisition_1

MewtwoRoom_On_Tranisition_3:
	clearflag FLAG_HIDE_MEWTWO
	goto MewtwoRoom_On_Tranisition_1


HideMewtwo::
	removeobject 1
	setflag FLAG_HIDE_MEWTWO
	end


MewtwoEncounter::
	lockall
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MEWTWO, 80
	special BattleSetup_StartLegendaryBattle
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq MewtwoEncounter_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MewtwoEncounter_3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq MewtwoEncounter_4
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq MewtwoEncounter_5
MewtwoEncounter_1:
	waitmessage
	releaseall
	return

MewtwoEncounter_2:
	call CaughtMewtwo
	goto MewtwoEncounter_1

MewtwoEncounter_3:
	call WonMewtwo
	goto MewtwoEncounter_1

MewtwoEncounter_4:
	call RanAwayMewtwo
	goto MewtwoEncounter_1

MewtwoEncounter_5:
	call RanAwayMewtwo
	goto MewtwoEncounter_1


CaughtMewtwo::
	fadescreen FADE_TO_BLACK
	removeobject 1
	setflag FLAG_CAUGHT_MEWTWO
	fadescreen FADE_FROM_BLACK
	return


RanAwayMewtwo::
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayMewtwo_Text_0
	return


WonMewtwo::
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayMewtwo_Text_0
	return


RanAwayMewtwo_Text_0:
	.string "Mewtwo wants to battle again!$"
