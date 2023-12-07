ShoalCave_LowTideIceRoom_MapScripts::
	.byte 0

ArticunoEncounter::
	lockall
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ARTICUNO, 30
	special BattleSetup_StartLegendaryBattle
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq ArticunoEncounter_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ArticunoEncounter_3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq ArticunoEncounter_4
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq ArticunoEncounter_5
ArticunoEncounter_1:
	waitmessage
	releaseall
	return

ArticunoEncounter_2:
	call CaughtArticuno
	goto ArticunoEncounter_1

ArticunoEncounter_3:
	call WonArticuno
	goto ArticunoEncounter_1

ArticunoEncounter_4:
	call RanAwayArticuno
	goto ArticunoEncounter_1

ArticunoEncounter_5:
	call RanAwayArticuno
	goto ArticunoEncounter_1


CaughtArticuno::
	fadescreen FADE_TO_BLACK
	removeobject 3
	setflag FLAG_CAUGHT_ARTICUNO
	fadescreen FADE_FROM_BLACK
	return


RanAwayArticuno::
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayArticuno_Text_0
	return


WonArticuno::
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayArticuno_Text_0
	return


RanAwayArticuno_Text_0:
	.string "Articuno wants to battle again!$"
