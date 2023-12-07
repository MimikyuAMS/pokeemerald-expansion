EmberCaverns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, EmberCaverns_On_Tranisition
	.byte 0


EmberCaverns_On_Tranisition::
	goto_if_set FLAG_CAUGHT_MOLTRES, EmberCaverns_On_Tranisition_1
	return

EmberCaverns_On_Tranisition_1:
	removeobject 1
	end


MoltresEncounter::
	lockall
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MOLTRES, 30
	special BattleSetup_StartLegendaryBattle
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq MoltresEncounter_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MoltresEncounter_3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq MoltresEncounter_4
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq MoltresEncounter_5
MoltresEncounter_1:
	waitmessage
	releaseall
	return

MoltresEncounter_2:
	call CaughtMoltres
	goto MoltresEncounter_1

MoltresEncounter_3:
	call WonMoltres
	goto MoltresEncounter_1

MoltresEncounter_4:
	call RanAwayMoltres
	goto MoltresEncounter_1

MoltresEncounter_5:
	call RanAwayMoltres
	goto MoltresEncounter_1


CaughtMoltres::
	fadescreen FADE_TO_BLACK
	removeobject 1
	setflag FLAG_CAUGHT_MOLTRES
	fadescreen FADE_FROM_BLACK
	return


RanAwayMoltres::
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayMoltres_Text_0
	return


WonMoltres::
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayMoltres_Text_0
	return


RanAwayMoltres_Text_0:
	.string "Moltres wants to battle again!$"
