ThurnicaneIsland_MapScripts::
	.byte 0


RaikouEncounter::
	lockall
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAIKOU, 60
	special BattleSetup_StartLegendaryBattle
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq RaikouEncounter_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq RaikouEncounter_3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq RaikouEncounter_4
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq RaikouEncounter_5
RaikouEncounter_1:
	waitmessage
	releaseall
	return

RaikouEncounter_2:
	call CaughtRaikou
	goto RaikouEncounter_1

RaikouEncounter_3:
	call WonRaikou
	goto RaikouEncounter_1

RaikouEncounter_4:
	call RanAwayRaikou
	goto RaikouEncounter_1

RaikouEncounter_5:
	call RanAwayRaikou
	goto RaikouEncounter_1


CaughtRaikou::
	fadescreen FADE_TO_BLACK
	setflag FLAG_CAUGHT_RAIKOU
	removeobject 1
	fadescreen FADE_FROM_BLACK
	return


RanAwayRaikou::
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayRaikou_Text_0
	return


WonRaikou::
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayRaikou_Text_0
	return


RanAwayRaikou_Text_0:
	.string "Raikou wants to battle again!$"
