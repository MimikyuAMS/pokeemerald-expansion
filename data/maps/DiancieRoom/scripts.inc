DiancieRoom_MapScripts::
	.byte 0


DiancieEncounter::
	lockall
	playmoncry SPECIES_DIANCIE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_DIANCIE, 30
	special BattleSetup_StartLegendaryBattle
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq DiancieEncounter_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DiancieEncounter_3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq DiancieEncounter_4
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq DiancieEncounter_5
DiancieEncounter_1:
	waitmessage
	releaseall
	return

DiancieEncounter_2:
	call CaughtDiancie
	goto DiancieEncounter_1

DiancieEncounter_3:
	call WonDiancie
	goto DiancieEncounter_1

DiancieEncounter_4:
	call RanAwayDiancie
	goto DiancieEncounter_1

DiancieEncounter_5:
	call RanAwayDiancie
	goto DiancieEncounter_1


CaughtDiancie::
	fadescreen FADE_TO_BLACK
	removeobject 1
	setflag FLAG_CAUGHT_DIANCIE
	fadescreen FADE_FROM_BLACK
	return


RanAwayDiancie::
	playmoncry SPECIES_DIANCIE, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayDiancie_Text_0
	return


WonDiancie::
	playmoncry SPECIES_DIANCIE, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayDiancie_Text_0
	return


RanAwayDiancie_Text_0:
	.string "Diancie wants to battle again!$"
